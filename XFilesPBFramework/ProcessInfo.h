//***********************************************************************/
// Header definitions to access NtQueryInformationProcess in NTDLL.DLL
//
// Copyright © 2007 Steven Moore (OrionScorpion).  All Rights Reserved.
//
// NOTES: PEB_LDR_DATA, RTL_USER_PROCESS_PARAMETERS and PEB struct are
//        defined in Winternl.h and Ntddk.h.  The specs below are from
//        Microsoft MSDN web site as of Jul 2007.  I locally specified
//        them below since they can change in future versions and may
//        not reflect current winternl.h or ntddk.h
//***********************************************************************/
#ifndef _ORIONSCORPION_NTPROCESSINFO_H_
#define _ORIONSCORPION_NTPROCESSINFO_H_

#pragma once

#include <winternl.h>
#include <psapi.h>


#pragma comment(lib, "rpcrt4.lib")
#pragma comment(lib, "psapi.lib")

#ifndef NTSTATUS
#define LONG NTSTATUS
#endif

// Unicode path usually prefix with '\\?\'
#define MAX_UNICODE_PATH	32767L

// Used in PEB struct
typedef ULONG smPPS_POST_PROCESS_INIT_ROUTINE;

// Used in PEB struct
typedef struct _smPEB_LDR_DATA {
	BYTE Reserved1[8];
	PVOID Reserved2[3];
	LIST_ENTRY InMemoryOrderModuleList;
} smPEB_LDR_DATA, *smPPEB_LDR_DATA;

// Used in PEB struct
typedef struct _smRTL_USER_PROCESS_PARAMETERS {
	BYTE Reserved1[16];
	PVOID Reserved2[10];
	UNICODE_STRING ImagePathName;
	UNICODE_STRING CommandLine;
} smRTL_USER_PROCESS_PARAMETERS, *smPRTL_USER_PROCESS_PARAMETERS;

// Used in PROCESS_BASIC_INFORMATION struct
typedef struct _smPEB {
	BYTE Reserved1[2];
	BYTE BeingDebugged;
	BYTE Reserved2[1];
	PVOID Reserved3[2];
	smPPEB_LDR_DATA Ldr;
	smPRTL_USER_PROCESS_PARAMETERS ProcessParameters;
	BYTE Reserved4[104];
	PVOID Reserved5[52];
	smPPS_POST_PROCESS_INIT_ROUTINE PostProcessInitRoutine;
	BYTE Reserved6[128];
	PVOID Reserved7[1];
	ULONG SessionId;
} smPEB, *smPPEB;

// Used with NtQueryInformationProcess
typedef struct _smPROCESS_BASIC_INFORMATION {
    LONG ExitStatus;
    smPPEB PebBaseAddress;
    ULONG_PTR AffinityMask;
    LONG BasePriority;
    ULONG_PTR UniqueProcessId;
    ULONG_PTR InheritedFromUniqueProcessId;
} smPROCESS_BASIC_INFORMATION, *smPPROCESS_BASIC_INFORMATION;

// NtQueryInformationProcess in NTDLL.DLL
typedef NTSTATUS (NTAPI *pfnNtQueryInformationProcess)(
	IN	HANDLE ProcessHandle,
    IN	PROCESSINFOCLASS ProcessInformationClass,
    OUT	PVOID ProcessInformation,
    IN	ULONG ProcessInformationLength,
    OUT	PULONG ReturnLength	OPTIONAL
    );

pfnNtQueryInformationProcess gNtQueryInformationProcess;

typedef struct _smPROCESSINFO
{
	HANDLE	hProcHandle;
	DWORD	dwPID;
	DWORD	dwParentPID;
	DWORD	dwSessionID;
	DWORD	dwPEBBaseAddress;
	DWORD	dwAffinityMask;
	LONG	dwBasePriority;
	LONG	dwExitStatus;
	BYTE	cBeingDebugged;
	TCHAR	szImgPath[MAX_UNICODE_PATH];
	TCHAR	szCmdLine[MAX_UNICODE_PATH];
} smPROCESSINFO;

HMODULE sm_LoadNTDLLFunctions(void);
void sm_FreeNTDLLFunctions(IN HMODULE hNtDll);
BOOL sm_EnableTokenPrivilege(IN LPCTSTR pszPrivilege);
BOOL sm_GetNtProcessInfo(IN const DWORD dwPID, OUT smPROCESSINFO *ppi);

#endif	// _ORIONSCORPION_NTPROCESSINFO_H_

//***********************************************************************/
// Functions to access NtQueryInformationProcess in NTDLL.DLL
//
// Copyright © 2007 Steven Moore (OrionScorpion).  All Rights Reserved.
//
//***********************************************************************/

// Enable a privilege for a process token
// The privilege must already be assigned
// This function only enables not assigns
BOOL sm_EnableTokenPrivilege(LPCTSTR pszPrivilege)
{
	HANDLE hToken		 = 0;
	TOKEN_PRIVILEGES tkp = {0}; 

	// Get a token for this process. 
	if (!OpenProcessToken(GetCurrentProcess(),
						  TOKEN_ADJUST_PRIVILEGES |
						  TOKEN_QUERY, &hToken))
	{
        return FALSE;
	}

	// Get the LUID for the privilege. 
	if(LookupPrivilegeValue(NULL, pszPrivilege,
						    &tkp.Privileges[0].Luid)) 
	{
        tkp.PrivilegeCount = 1;  // one privilege to set    
		tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

		// Set the privilege for this process. 
		AdjustTokenPrivileges(hToken, FALSE, &tkp, 0,
							  (PTOKEN_PRIVILEGES)NULL, 0); 

		if (GetLastError() != ERROR_SUCCESS)
			return FALSE;
		
		return TRUE;
	}

	return FALSE;
}

// Load NTDLL Library and get entry address
// for NtQueryInformationProcess
HMODULE sm_LoadNTDLLFunctions()
{
	HMODULE hNtDll = LoadLibrary(_T("ntdll.dll"));
	if(hNtDll == NULL) return NULL;

	gNtQueryInformationProcess = (pfnNtQueryInformationProcess)GetProcAddress(hNtDll,
														"NtQueryInformationProcess");
	if(gNtQueryInformationProcess == NULL) {
		FreeLibrary(hNtDll);
		return NULL;
	}
	return hNtDll;
}

// Unloads the NTDLL.DLL and resets the
// global gNtQueryInformationProcess variable
void sm_FreeNTDLLFunctions(HMODULE hNtDll)
{
	if(hNtDll)
		FreeLibrary(hNtDll);
	gNtQueryInformationProcess = NULL;
}

// Gets information on process with NtQueryInformationProcess
BOOL sm_GetNtProcessInfo(const DWORD dwPID, smPROCESSINFO *ppi)
{
	BOOL  bReturnStatus						= TRUE;
	DWORD dwSize							= 0;
	DWORD dwSizeNeeded						= 0;
	DWORD dwBytesRead						= 0;
	DWORD dwBufferSize						= 0;
	HANDLE hHeap							= 0;
	WCHAR *pwszBuffer						= NULL;

	smPROCESSINFO spi						= {0};
	smPPROCESS_BASIC_INFORMATION pbi		= NULL;

	smPEB peb								= {0};
	smPEB_LDR_DATA peb_ldr					= {0};
	smRTL_USER_PROCESS_PARAMETERS peb_upp	= {0};

	ZeroMemory(&spi, sizeof(spi));
	ZeroMemory(&peb, sizeof(peb));
	ZeroMemory(&peb_ldr, sizeof(peb_ldr));
	ZeroMemory(&peb_upp, sizeof(peb_upp));

	spi.dwPID = dwPID;

	// Attempt to access process
	HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | 
								  PROCESS_VM_READ | PROCESS_TERMINATE, FALSE, dwPID);
	if(hProcess == INVALID_HANDLE_VALUE) {
		return FALSE;
	}

	// Try to allocate buffer 
	hHeap = GetProcessHeap();

	dwSize = sizeof(smPROCESS_BASIC_INFORMATION);

	pbi = (smPPROCESS_BASIC_INFORMATION)HeapAlloc(hHeap,
												  HEAP_ZERO_MEMORY,
												  dwSize);
	// Did we successfully allocate memory
	if(!pbi) {
		CloseHandle(hProcess);
		return FALSE;
	}

	// Attempt to get basic info on process
	NTSTATUS dwStatus = gNtQueryInformationProcess(hProcess,
												  ProcessBasicInformation,
												  pbi,
												  dwSize,
												  &dwSizeNeeded);

	// If we had error and buffer was too small, try again
	// with larger buffer size (dwSizeNeeded)
	if(dwStatus >= 0 && dwSize < dwSizeNeeded)
	{
		if(pbi)
			HeapFree(hHeap, 0, pbi);
		pbi = (smPPROCESS_BASIC_INFORMATION)HeapAlloc(hHeap,
													  HEAP_ZERO_MEMORY,
                                                      dwSizeNeeded);
		if(!pbi) {
			CloseHandle(hProcess);
			return FALSE;
		}

		dwStatus = gNtQueryInformationProcess(hProcess,
											 ProcessBasicInformation,
											 pbi, dwSizeNeeded, &dwSizeNeeded);
	}

	// Did we successfully get basic info on process
	if(dwStatus >= 0)
	{
		// Basic Info
//        spi.dwPID			 = (DWORD)pbi->UniqueProcessId;
		spi.dwParentPID		 = (DWORD)pbi->InheritedFromUniqueProcessId;
		spi.dwBasePriority	 = (LONG)pbi->BasePriority;
		spi.dwExitStatus	 = (NTSTATUS)pbi->ExitStatus;
		spi.dwPEBBaseAddress = (DWORD)pbi->PebBaseAddress;
		spi.dwAffinityMask	 = (DWORD)pbi->AffinityMask;
		spi.hProcHandle		 = hProcess;

		// Read Process Environment Block (PEB)
		if(pbi->PebBaseAddress)
		{
			if(ReadProcessMemory(hProcess, pbi->PebBaseAddress, &peb, sizeof(peb), &dwBytesRead))
			{
				spi.dwSessionID	   = (DWORD)peb.SessionId;
				spi.cBeingDebugged = (BYTE)peb.BeingDebugged;

				// Here we could access PEB_LDR_DATA, i.e., module list for process
//				dwBytesRead = 0;
//				if(ReadProcessMemory(hProcess,
//									 pbi->PebBaseAddress->Ldr,
//									 &peb_ldr,
//									 sizeof(peb_ldr),
//									 &dwBytesRead))
//				{
					// get ldr
//				}

				// if PEB read, try to read Process Parameters
				dwBytesRead = 0;
				if(ReadProcessMemory(hProcess,
									 peb.ProcessParameters,
									 &peb_upp,
									 sizeof(smRTL_USER_PROCESS_PARAMETERS),
									 &dwBytesRead))
				{
					// We got Process Parameters, is CommandLine filled in
					if(peb_upp.CommandLine.Length > 0) {
						// Yes, try to read CommandLine
						pwszBuffer = (WCHAR *)HeapAlloc(hHeap,
														HEAP_ZERO_MEMORY,
														peb_upp.CommandLine.Length);
						// If memory was allocated, continue
						if(pwszBuffer)
						{
							if(ReadProcessMemory(hProcess,
												 peb_upp.CommandLine.Buffer,
												 pwszBuffer,
												 peb_upp.CommandLine.Length,
												 &dwBytesRead))
							{
								// if commandline is larger than our variable, truncate
								if(peb_upp.CommandLine.Length >= sizeof(spi.szCmdLine)) 
									dwBufferSize = sizeof(spi.szCmdLine) - sizeof(TCHAR);
								else
									dwBufferSize = peb_upp.CommandLine.Length;
							
								// Copy CommandLine to our structure variable
#if defined(UNICODE) || (_UNICODE)
								// Since core NT functions operate in Unicode
								// there is no conversion if application is
								// compiled for Unicode
								StringCbCopyN(spi.szCmdLine, sizeof(spi.szCmdLine),
											  pwszBuffer, dwBufferSize);
#else
								// Since core NT functions operate in Unicode
								// we must convert to Ansi since our application
								// is not compiled for Unicode
								WideCharToMultiByte(CP_ACP, 0, pwszBuffer,
													(int)(dwBufferSize / sizeof(WCHAR)),
													spi.szCmdLine, sizeof(spi.szCmdLine),
													NULL, NULL);
#endif
							}
							if(!HeapFree(hHeap, 0, pwszBuffer)) {
								// failed to free memory
								bReturnStatus = FALSE;
								goto gnpiFreeMemFailed;
							}
						}
					}	// Read CommandLine in Process Parameters

					// We got Process Parameters, is ImagePath filled in
					if(peb_upp.ImagePathName.Length > 0) {
						// Yes, try to read ImagePath
						dwBytesRead = 0;
						pwszBuffer = (WCHAR *)HeapAlloc(hHeap,
														HEAP_ZERO_MEMORY,
														peb_upp.ImagePathName.Length);
						if(pwszBuffer)
						{
                            if(ReadProcessMemory(hProcess,
												 peb_upp.ImagePathName.Buffer,
												 pwszBuffer,
												 peb_upp.ImagePathName.Length,
												 &dwBytesRead))
							{
								// if ImagePath is larger than our variable, truncate
								if(peb_upp.ImagePathName.Length >= sizeof(spi.szImgPath)) 
									dwBufferSize = sizeof(spi.szImgPath) - sizeof(TCHAR);
								else
									dwBufferSize = peb_upp.ImagePathName.Length;

								// Copy ImagePath to our structure
#if defined(UNICODE) || (_UNICODE)
								StringCbCopyN(spi.szImgPath, sizeof(spi.szImgPath),
											  pwszBuffer, dwBufferSize);
#else
								WideCharToMultiByte(CP_ACP, 0, pwszBuffer,
													(int)(dwBufferSize / sizeof(WCHAR)),
													spi.szImgPath, sizeof(spi.szImgPath),
													NULL, NULL);
#endif
							}
							if(!HeapFree(hHeap, 0, pwszBuffer)) {
								// failed to free memory
								bReturnStatus = FALSE;
								goto gnpiFreeMemFailed;
							}
						}
					}	// Read ImagePath in Process Parameters
				}	// Read Process Parameters
			}	// Read PEB 
		}	// Check for PEB

		// System process for WinXP and later is PID 4 and we cannot access
		// PEB, but we know it is aka ntoskrnl.exe so we will manually define it.
		// ntkrnlpa.exe if Physical Address Extension (PAE)
		// ntkrnlmp.exe if Symmetric MultiProcessing (SMP)
		// Actual filename is ntoskrnl.exe, but other name will be in
		// Original Filename field of version block.
		if(spi.dwPID == 4) {
			ExpandEnvironmentStrings(_T("%SystemRoot%\\System32\\ntoskrnl.exe"),
									 spi.szImgPath, sizeof(spi.szImgPath));
		}
	}	// Read Basic Info

gnpiFreeMemFailed:

	// Free memory if allocated
	if(pbi != NULL)
		if(!HeapFree(hHeap, 0, pbi)) {
			// failed to free memory
		}


	// Return filled in structure to caller
	*ppi = spi;

	return bReturnStatus;
} 
DWORD GetPID(LPSTR ProcName)
{
	PROCESSENTRY32 pe32;
	HANDLE hProcessSnap = INVALID_HANDLE_VALUE;

	//Tangkap beberapa proses yang sedang running
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	if( hProcessSnap == INVALID_HANDLE_VALUE )return (0);

	pe32.dwSize = sizeof(PROCESSENTRY32);
	if( Process32First(hProcessSnap, &pe32) == 0 ) {
		CloseHandle( hProcessSnap ); 
		return (0);
	}
	do {//Loop untuk mencari apakah process yang akan diinject telah ditemukan ?
		if(lstrcmp(ProcName,pe32.szExeFile)== 0){
			return pe32.th32ProcessID;
		}
	}while(Process32Next(hProcessSnap,&pe32) );

	CloseHandle( hProcessSnap );
	SetLastError(0);
	return (0);
}

void killProcessByName(const char *filename)
{
	HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
	PROCESSENTRY32 pEntry;
	pEntry.dwSize = sizeof (pEntry);
	BOOL hRes = Process32First(hSnapShot, &pEntry);
	while (hRes)
	{
		if (strcmp(pEntry.szExeFile, filename) == 0)
		{
			HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
				(DWORD) pEntry.th32ProcessID);
			if (hProcess != NULL)
			{
				TerminateProcess(hProcess, 9);
				CloseHandle(hProcess);
			}
		}
		hRes = Process32Next(hSnapShot, &pEntry);
	}
	CloseHandle(hSnapShot);
}