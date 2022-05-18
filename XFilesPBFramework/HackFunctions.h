
//--------------------------------- Get Battle State -----------------------
/*
Fungsi : Mendapatkan informasi apakah user sedang bertanding di dalam pertandingan atau tidak
Dengan memanfaatkan Base CGameCharaBase, apabila Base Pointer valid, maka Pemain sedang di dalam pertandingan
Class yang digunakan : CGameCharaBase
*/
bool IsInBattle()
{
	if(pGameCharaManager->getLocalChara() > NULL)return true;
	return false;
}

void _patchPTR(unsigned long adr, unsigned long Ofset1, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
void _patchPTR(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}

void _patchPTR(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}
void _patchPTR(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, DWORD dwValue)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return;
	A=*(PDWORD)((DWORD)(A))+Ofset4;
	if(IsBadReadPtr((PDWORD)A,4))return;
	if(*(PDWORD)A!=dwValue)*(PDWORD)A=dwValue;
}

DWORD _readPTR(unsigned long adr, unsigned long Ofset1, unsigned int dwSize)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return NULL;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	switch(dwSize)
	{
	case 1:
		return *(BYTE*)(A);
		break;
	case 2:
		return *(WORD*)(A);
		break;
	case 4:
		return *(DWORD*)(A);
		break;
	}
	return NULL;
}
DWORD _readPTR(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned int dwSize)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return NULL;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	switch(dwSize)
	{
	case 1:
		return *(BYTE*)(A);
		break;
	case 2:
		return *(WORD*)(A);
		break;
	case 4:
		return *(DWORD*)(A);
		break;
	}
	return NULL;
}

DWORD _readPTR(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned int dwSize)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return NULL;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	switch(dwSize)
	{
	case 1:
		return *(BYTE*)(A);
		break;
	case 2:
		return *(WORD*)(A);
		break;
	case 4:
		return *(DWORD*)(A);
		break;
	}
	return NULL;
}
DWORD _readPTR(unsigned long adr, unsigned long Ofset1, unsigned long Ofset2, unsigned long Ofset3, unsigned long Ofset4, unsigned int dwSize)
{ 
	DWORD A=0;
	if(IsBadReadPtr((PDWORD)adr,4))return NULL;
	A=*(PDWORD)((DWORD)(adr))+Ofset1;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	A=*(PDWORD)((DWORD)(A))+Ofset2;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	A=*(PDWORD)((DWORD)(A))+Ofset3;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	A=*(PDWORD)((DWORD)(A))+Ofset4;
	if(IsBadReadPtr((PDWORD)A,4))return NULL;
	switch(dwSize)
	{
	case 1:
		return *(BYTE*)(A);
		break;
	case 2:
		return *(WORD*)(A);
		break;
	case 4:
		return *(DWORD*)(A);
		break;
	}
	return NULL;
}
void _patchMEM(void* MemoryTarget, char* Value,int len)
{
	DWORD dwOldProtect, dwBkup;
    VirtualProtect(MemoryTarget, len, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	memcpy((void*)MemoryTarget,(void*)Value,len);
    VirtualProtect(MemoryTarget, len, dwOldProtect, &dwBkup);
}
DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget)
{
	//XFiles make PTR
	//2014 FahmyXFiles
	DWORD dwOldProtect,dwBkup;
	DWORD dwRetn = *(DWORD*)(MemoryTarget);

	VirtualProtect(MemoryTarget, 4, PAGE_EXECUTE_READWRITE, &dwOldProtect);
	*((DWORD *)(MemoryTarget)) = FunctionTarget;
	VirtualProtect(MemoryTarget, 4, dwOldProtect, &dwBkup);
	return dwRetn;
}
DWORD hook(PDWORD target, PDWORD myFunction)
{
	DWORD Jmpto=((DWORD)(myFunction)-(DWORD)target)-5;
	DWORD a;
	VirtualProtect(target, 5, PAGE_EXECUTE_READWRITE, &a);
	*(PBYTE)((DWORD)(target))=0xE9;
	*(PDWORD)((DWORD)(target)+1)=Jmpto;
	VirtualProtect(target, 5, a, &a);
	return false;
}
DWORD virtualProtect_Back = NULL;
__declspec ( naked ) void codeCave_virtualProtectEx()
{
	__asm
	{
		mov edi, edi
		push ebp
		mov ebp, esp
		jmp [virtualProtect_Back];
	}
}

DWORD DetourB8( DWORD SrcVA, DWORD DstVA, DWORD Size )
{
	DWORD DetourVA, dwProtect, i;
	#define SIZEOF_MOVEAX_JMPEAX 7
	DWORD dwVirtualProtectEx = (DWORD)GetProcAddress(LoadLibrary("KERNELBASE.dll"), "VirtualProtectEx");
	virtualProtect_Back = dwVirtualProtectEx + 5;
	if ( SrcVA && DstVA && Size >= SIZEOF_MOVEAX_JMPEAX )
	{
		
		DetourVA = (DWORD) VirtualAlloc( 
		NULL, Size + SIZEOF_MOVEAX_JMPEAX, 
		MEM_COMMIT, PAGE_EXECUTE_READWRITE ); 
		typedef BOOL (WINAPI* tVirtualProtectEx)(_In_  HANDLE hProcess, _In_  LPVOID lpAddress, _In_  SIZE_T dwSize, _In_  DWORD  flNewProtect, _Out_ PDWORD lpflOldProtect);
		tVirtualProtectEx oVirtualProtectEx = (tVirtualProtectEx)codeCave_virtualProtectEx;
		if ( DetourVA && oVirtualProtectEx((HANDLE)-1, (VOID*)SrcVA, Size, PAGE_READWRITE, &dwProtect ) )
		{
			for ( i=0; i < Size; i++ ) {
			*(BYTE*)( DetourVA + i ) = *(BYTE*)( SrcVA + i );
			}
			*(BYTE*)( DetourVA + Size + 0 ) = 0xB8;
			*(DWORD*)( DetourVA + Size + 1 ) = ( SrcVA + Size );
			*(WORD*)( DetourVA + Size + 5 ) = 0xE0FF;
			*(BYTE*)( SrcVA + 0 ) = 0xB8;
			*(DWORD*)( SrcVA + 1 ) = ( DstVA );
			*(WORD*)( SrcVA + 5 ) = 0xE0FF;
			VirtualProtect( (VOID*)SrcVA, Size, dwProtect, &dwProtect );
			VirtualProtect( (VOID*)DetourVA, Size + 
			SIZEOF_MOVEAX_JMPEAX, PAGE_EXECUTE_READ, &dwProtect );
			return DetourVA;
		}
	}
return (0);
}

void hexDump (char *desc, void *addr, int len, FILE* pFile) {
    int i;
    unsigned char buff[17];       // stores the ASCII data
    unsigned char *pc = (unsigned char*)addr;     // cast to make the code cleaner.

    // Output description if given.

    if (desc != NULL)
        fprintf (pFile, "%s:\n", desc);

    // Process every byte in the data.

    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.

            if (i != 0)
                fprintf (pFile, "  %s\n", buff);

            // Output the offset.

            fprintf (pFile, "  %04x ", i);
        }

        // Now the hex code for the specific character.

        fprintf (pFile, " %02x", pc[i]);

        // And store a printable ASCII character for later.

        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.

    while ((i % 16) != 0) {
        fprintf (pFile, "   ");
        i++;
    }

    // And print the final ASCII bit.

    fprintf (pFile, "  %s\n", buff);
}
string hexDump (char *desc, void *addr, int len) {
    int i;
    unsigned char buff[17];
    unsigned char *pc = (unsigned char*)addr;
	char szPrntBuffer[100];
	string output;

	if(IsBadReadPtr((void*)addr,4))
	{
		sprintf (szPrntBuffer,"%s: 0x0", desc);
		output += szPrntBuffer;
		return output;
	}
    // Output description if given.
    if (desc != NULL){
        sprintf (szPrntBuffer,"%s:\n", desc);
		output += szPrntBuffer;
	}

    // Process every byte in the data.
    for (i = 0; i < len; i++) {
        // Multiple of 16 means new line (with line offset).

        if ((i % 16) == 0) {
            // Just don't print ASCII for the zeroth line.
            if (i != 0){
                sprintf (szPrntBuffer,"  %s\n", buff);
				output += szPrntBuffer;
			}

            // Output the offset.
            sprintf (szPrntBuffer,"  %08X ", (int)addr + i);
			output += szPrntBuffer;
        }

        // Now the hex code for the specific character.
        sprintf (szPrntBuffer," %02x", pc[i]);
		output += szPrntBuffer;

        // And store a printable ASCII character for later.
        if ((pc[i] < 0x20) || (pc[i] > 0x7e))
            buff[i % 16] = '.';
        else
            buff[i % 16] = pc[i];
        buff[(i % 16) + 1] = '\0';
    }

    // Pad out last line if not exactly 16 characters.
    while ((i % 16) != 0) {
        sprintf (szPrntBuffer,"   ");
		output += szPrntBuffer;
        i++;
    }

    // And print the final ASCII bit.
    sprintf (szPrntBuffer,"  %s", buff);
	output += szPrntBuffer;
	return output;
}
DWORD GenerateRandomNumber(int min, int max)
{
	
	SYSTEMTIME pTime = {0};
	GetSystemTime(&pTime);
	
	int randNum = pTime.wMilliseconds * rand()%(max-min + 1) + min;
	return randNum;
}
char* GenerateRandomString(const int len) {
	char* s = new char[len];
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < len; ++i) {
        s[i] = alphanum[GenerateRandomNumber(20,50) % (sizeof(alphanum) - 1)];
    }

    s[len] = 0;
	return s;
}
void FireBulletOnTarget(CGameCharaBase* Target)
{	
	CGameCharaBase* LocalChara = pGameCharaManager->getLocalChara();

	DWORD CurrentWeaponIdx = LocalChara->getGameCharaWeaponContext()->getCurrentWeaponIndex();
	//if(CurrentWeaponIdx == 2)return;

	CWeaponBase* CurrentWeapon = LocalChara->getGameCharaWeaponContext()->getCurrentWeapon();

	D3DXVECTOR3 SourcePos = LocalChara->getGameCharaBoneContext()->getBonePosition(5);
	D3DXVECTOR3 TargetPos = Target->getGameCharaBoneContext()->getBonePosition(BoneIndexSelector);
	TargetPos.y += 0.1f;
	
	DWORD OptTeam = 2;
	if(pGameContext->isRedTeam(Target->getCharaNetIndex()))OptTeam = 1;
	
	
	SetEndVector->SetTargetVector(TargetPos);
	CurrentWeapon->doFire();
	SetEndVector->Disable();
	//pGameUDPHandler->WriteGameEvent_Fire(LocalChara, &TargetPos, CurrentWeapon);
	//CurrentWeapon->doLineCollision(&SourcePos, &TargetPos, OptTeam);

}
