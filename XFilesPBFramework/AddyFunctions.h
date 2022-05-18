
enum AddyType
{
	ADDY_NORMAL = 0,
	ADDY_STRING = 1,
	ADDY_FUNCTION_GETCALL = 2,
	ADDY_FUNCTION_GETJMP = 3,
	ADDY_FUNCTION_FINDSTART = 4,
	ADDY_FUNCTION_FINDEND = 5,
	ADDY_FUNCTION_FINDNEXT = 6,
	ADDY_FUNCTION_FINDPREV = 7,
	ADDY_GET_VALUE = 8

};

class cAddyEngine
{
private:
	MODULEINFO GetModuleInfo ( LPCTSTR lpModuleName );
	DWORD FindPattern( DWORD rangeStart, DWORD rangeEnd, const char* pattern );
public:
	virtual DWORD FindOffsetByPattern(char* ModuleName, char* Pattern);
	virtual DWORD ParseAddyByOption(DWORD Addy, enum AddyType, DWORD Align, DWORD AlignSize);
	
	virtual void SetAddyByPattern(DWORD &Storage, AddyType eAddyType, DWORD Align, DWORD AlignSize, char* ModuleName, char* Pattern);
};
MODULEINFO cAddyEngine::GetModuleInfo ( LPCTSTR lpModuleName )
{
	MODULEINFO miInfos = { NULL };
    HMODULE hPSAPI_module;

    if(!GetModuleHandleA(/*psapi.dll*/XorStr<0x7F,10,0x2D6771B8>("\x0F\xF3\xE0\xF2\xEA\xAA\xE1\xEA\xEB"+0x2D6771B8).s))
    {
        
        char szSystemPath[MAX_PATH];
        GetWindowsDirectory(szSystemPath, MAX_PATH);
        char szPSAPIDLLPath[MAX_PATH];
        sprintf(szPSAPIDLLPath, /*%s\\system32\\psapi.dll*/XorStr<0xD3,22,0x817F5100>("\xF6\xA7\x89\xA5\xAE\xAB\xAD\xBF\xB6\xEF\xEF\x82\xAF\x93\x80\x92\x8A\xCA\x81\x8A\x8B"+0x817F5100).s, szSystemPath);
		hPSAPI_module =  LoadLibrary(szPSAPIDLLPath);
        
    }
    else
        hPSAPI_module = GetModuleHandleA(/*psapi.dll*/XorStr<0x7F,10,0x2D6771B8>("\x0F\xF3\xE0\xF2\xEA\xAA\xE1\xEA\xEB"+0x2D6771B8).s);

    if (!hPSAPI_module)
        return miInfos;

	HMODULE hmModule = GetModuleHandle(lpModuleName); 
 
    typedef DWORD ( __stdcall *tGetModuleInformation)( HANDLE, HMODULE, LPMODULEINFO, DWORD );
    tGetModuleInformation oGetModuleInformation = (tGetModuleInformation) (GetProcAddress(hPSAPI_module, /*GetModuleInformation*/XorStr<0x35,21,0x3BDB8E31>("\x72\x53\x43\x75\x56\x5E\x4E\x50\x58\x77\x51\x26\x2E\x30\x2E\x25\x31\x2F\x28\x26"+0x3BDB8E31).s));
    oGetModuleInformation(GetCurrentProcess(), hmModule, &miInfos, sizeof ( MODULEINFO ));

    return miInfos;
}

#define INRANGE(x,a,b)  (x >= a && x <= b) 
#define getBits( x )    (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))
#define getByte( x )    (getBits(x[0]) << 4 | getBits(x[1]))
DWORD cAddyEngine::FindPattern( DWORD rangeStart, DWORD rangeEnd, const char* pattern )
{
    const char* pat = pattern;
    DWORD firstMatch = 0;
    for( DWORD pCur = rangeStart; pCur < rangeEnd; pCur++ )
    {
        if( !*pat ) return firstMatch;
        if( *(PBYTE)pat == '\?' || *(BYTE*)pCur == getByte( pat ) ) {
            if( !firstMatch ) firstMatch = pCur;
            if( !pat[2] ) return firstMatch;
            if( *(PWORD)pat == '\?\?' || *(PBYTE)pat != '\?' ) pat += 3;
            else pat += 2;  

        } else {
            pat = pattern;
            firstMatch = 0;
        }
    }
    return NULL;
}
DWORD cAddyEngine::FindOffsetByPattern(char* ModuleName, char* Pattern)
{
	MODULEINFO mTarget = this->GetModuleInfo(ModuleName);
	if(mTarget.SizeOfImage == NULL){
		AddLog(/*--> [ERROR] FindOffsetByPattern => mTarget.SizeOfImage == NULL*/XorStr<0x67,63,0x7F9422DC>("\x4A\x45\x57\x4A\x30\x29\x3F\x3C\x20\x22\x2C\x52\x35\x1D\x1B\x12\x38\x1E\x1F\x09\x1E\x08\x3F\x07\x2F\xE1\xF5\xF6\xE6\xF6\xEB\xA6\xBA\xB6\xA9\xE7\xDF\xED\xFF\xE9\xEA\xE4\xBF\xC1\xFA\xEE\xF0\xD9\xF1\xD1\xF4\xFB\xFC\xF9\xBD\xA3\xA2\x80\xEF\xF7\xEF\xE8"+0x7F9422DC).s);
		return NULL;
	}

	DWORD Search = this->FindPattern((DWORD)mTarget.lpBaseOfDll, (DWORD)mTarget.lpBaseOfDll + (DWORD)mTarget.SizeOfImage, Pattern);
	if(Search == NULL){
		AddLog(/*--> [ERROR] FindOffsetByPattern => Search == NULL*/XorStr<0x6C,50,0x608C898F>("\x41\x40\x50\x4F\x2B\x34\x20\x21\x3B\x27\x2B\x57\x3E\x10\x14\x1F\x33\x1B\x18\x0C\xE5\xF5\xC0\xFA\xD4\xE4\xF2\xF3\xED\xFB\xE4\xAB\xB1\xB3\xAE\xDC\xF5\xF0\xE0\xF0\xFC\xB5\xAB\xAA\xB8\xD7\xCF\xD7\xD0"+0x608C898F).s);
		return NULL;
	}
	AddLog(/*--> [SUCCESS] FindOffsetByPattern => 0x%X*/XorStr<0xB7,42,0xD5D376FC>("\x9A\x95\x87\x9A\xE0\xEF\xE8\xFD\xFC\x85\x92\x91\x9E\xE4\x83\xAF\xA9\xAC\x86\xAC\xAD\xBF\xA8\xBA\x8D\xA9\x81\xB3\xA7\xA0\xB0\xA4\xB9\xF8\xE4\xE4\xFB\xEC\xA5\xFB\x87"+0xD5D376FC).s, Search);
	return Search;
}
DWORD cAddyEngine::ParseAddyByOption(DWORD Addy, AddyType eAddyType, DWORD Align, DWORD AlignSize)
{ 
	DWORD retVal = NULL;
	DWORD Search = Addy;
	DWORD CallPosition, CallDifference, JumpPosition, JumpDifference = NULL;
	if(Search == NULL){
		AddLog(/*--> [ERROR] ParseAddyByOption => Search == NULL*/XorStr<0x6C,48,0x217176F8>("\x41\x40\x50\x4F\x2B\x34\x20\x21\x3B\x27\x2B\x57\x28\x18\x08\x08\x19\x3C\x1A\x1B\xF9\xC3\xFB\xCC\xF4\xF1\xEF\xE8\xE6\xA9\xB7\xB5\xAC\xDE\xEB\xEE\xE2\xF2\xFA\xB3\xA9\xA8\xB6\xD9\xCD\xD5\xD6"+0x217176F8).s);
		return retVal;
	}
	switch(eAddyType)
	{
	case ADDY_NORMAL:
		retVal = Search + Align;
		break;
	case ADDY_FUNCTION_GETCALL:
		CallPosition = Search + Align;
		CallDifference = *(DWORD*)(CallPosition + 1);
		if(*(BYTE*)(CallPosition) != 0xE8){
			AddLog(/*--> [ERROR] ParseAddyByOption => INVALID_ALIGN_TO_CALL*/XorStr<0xCF,55,0xE157BB35>("\xE2\xFD\xEF\xF2\x88\x91\x87\x84\x98\x8A\x84\xFA\x8B\xBD\xAF\xAD\xBA\xA1\x85\x86\x9A\xA6\x9C\xA9\x97\x9C\x80\x85\x85\xCC\xD0\xD0\xCF\xB9\xBF\xA4\xB2\xB8\xBC\xB2\xA8\xB9\xB5\xB3\xBC\xB2\xA2\xAA\xB0\x5F\x42\x43\x4F\x48"+0xE157BB35).s);
			break;
		}
		retVal = CallPosition + CallDifference + 5;
		break;
	case ADDY_FUNCTION_GETJMP:
		JumpPosition = Search + Align;
		JumpDifference = *(DWORD*)(JumpPosition + 1);
		if(*(BYTE*)(JumpPosition) != 0xE9){
			AddLog(/*--> [ERROR] ParseAddyByOption => INVALID_ALIGN_TO_JMP*/XorStr<0xB8,54,0xCB5A0E6E>("\x95\x94\x84\x9B\xE7\xF8\xEC\xED\x8F\x93\x9F\xE3\x94\xA4\xB4\xB4\xAD\x88\xAE\xAF\xB5\x8F\xB7\x80\xA0\xA5\xBB\xBC\xBA\xF5\xEB\xE9\xF8\x90\x94\x8D\x9D\x91\x97\x9B\xBF\xA0\xAE\xAA\xA3\xAB\xB9\xB3\xA7\xB6\xA0\xA6\xBC"+0xCB5A0E6E).s);
			break;
		}
		retVal = JumpPosition + JumpDifference + 5;
		break;
	case ADDY_FUNCTION_FINDSTART:
		while(true)
		{
			if(*(BYTE*)(Search + 0) == 0x55 &&
			   *(BYTE*)(Search + 1) == 0x8B &&
			   *(BYTE*)(Search + 2) == 0xEC)break;
			Search--;
		}
		if(Align > NULL && AlignSize > NULL && AlignSize <= 4){
			switch(AlignSize)
			{
			case 1:
				retVal = *(BYTE*)(Search + Align);
				break;
			case 2:
				retVal = *(WORD*)(Search + Align);
				break;
			case 4:
				retVal = *(DWORD*)(Search + Align);
				break;
			}
		}
		else retVal = Search;
		break;
	case ADDY_FUNCTION_FINDEND:
		while(true)
		{
			if(*(BYTE*)(Search + 0) == 0x55 &&
			   *(BYTE*)(Search + 1) == 0x8B &&
			   *(BYTE*)(Search + 2) == 0xEC)break;
			Search++;
		}
		if(Align > NULL && AlignSize > NULL && AlignSize <= 4){
			switch(AlignSize)
			{
			case 1:
				retVal = *(BYTE*)(Search + Align);
				break;
			case 2:
				retVal = *(WORD*)(Search + Align);
				break;
			case 4:
				retVal = *(DWORD*)(Search + Align);
				break;
			}
		}
		else retVal = Search;
		break;
	case ADDY_FUNCTION_FINDNEXT:
		Search += 1;
		while(true)
		{
			if(*(BYTE*)(Search + 0) == 0x55 &&
			   *(BYTE*)(Search + 1) == 0x8B &&
			   *(BYTE*)(Search + 2) == 0xEC)break;
			Search++;
		}
		if(Align > NULL && AlignSize > NULL && AlignSize <= 4){
			switch(AlignSize)
			{
			case 1:
				retVal = *(BYTE*)(Search + Align);
				break;
			case 2:
				retVal = *(WORD*)(Search + Align);
				break;
			case 4:
				retVal = *(DWORD*)(Search + Align);
				break;
			}
		}
		else retVal = Search;
		break;
	case ADDY_FUNCTION_FINDPREV:
		Search -= 1;
		while(true)
		{
			if(*(BYTE*)(Search + 0) == 0x55 &&
			   *(BYTE*)(Search + 1) == 0x8B &&
			   *(BYTE*)(Search + 2) == 0xEC)break;
			Search--;
		}
		if(Align > NULL && AlignSize > NULL && AlignSize <= 4){
			switch(AlignSize)
			{
			case 1:
				retVal = *(BYTE*)(Search + Align);
				break;
			case 2:
				retVal = *(WORD*)(Search + Align);
				break;
			case 4:
				retVal = *(DWORD*)(Search + Align);
				break;
			}
		}
		else retVal = Search;
		break;
	case ADDY_GET_VALUE:
		if(Align > NULL && AlignSize > NULL && AlignSize <= 4){
			switch(AlignSize)
			{
			case 1:
				retVal = *(BYTE*)(Search + Align);
				break;
			case 2:
				retVal = *(WORD*)(Search + Align);
				break;
			case 4:
				retVal = *(DWORD*)(Search + Align);
				break;
			}
		}
	}
	AddLog(/*--> [SUCCESS] ParseAddyByOption => 0x%X*/XorStr<0xDF,40,0xA2C27442>("\xF2\xCD\xDF\xC2\xB8\xB7\xB0\xA5\xA4\xAD\xBA\xB9\xB6\xCC\xBD\x8F\x9D\x83\x94\xB3\x97\x90\x8C\xB4\x8E\xB7\x89\x8E\x92\x93\x93\xDE\xC2\x3E\x21\x32\x7B\x21\x5D"+0xA2C27442).s, retVal);
	return retVal;
}
void cAddyEngine::SetAddyByPattern(DWORD &Storage, AddyType eAddyType, DWORD Align, DWORD AlignSize, char* ModuleName, char* Pattern)
{
	AddLog(/*SetAddyByPattern => ("%s". "%s". 0x%X. 0x%X. 0x%X)*/XorStr<0xC0,51,0x8C4206AC>("\x93\xA4\xB6\x82\xA0\xA1\xBF\x85\xB1\x99\xAB\xBF\xB8\xA8\xBC\xA1\xF0\xEC\xEC\xF3\xFC\xF7\xF3\xA4\xFA\xF7\xFA\xF9\xF9\xAE\xFC\xF1\xC0\xD1\x9A\xC6\xBC\xCB\xC6\xD7\x90\xCC\xB2\xC5\xCC\xDD\x96\xCA\xA8\xD8"+0x8C4206AC).s, ModuleName, Pattern, eAddyType, Align, AlignSize);
	DWORD Result = this->FindOffsetByPattern(ModuleName, Pattern);
	if(Result > NULL)
		Result = this->ParseAddyByOption(Result, eAddyType, Align, AlignSize);
	Storage = Result;
}


cAddyEngine* AddyEngine = NULL;