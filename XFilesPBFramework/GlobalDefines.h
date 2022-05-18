#define FUNC_NOINLINE _declspec(noinline)

class pSetEndVector
{
public:
	D3DXVECTOR3 TargetVector;
	bool State;

	void SetTargetVector(D3DXVECTOR3 VecIn)
	{
		TargetVector = VecIn;
		State = true;
	}

	void Disable()
	{
		State = false;
	}

	DWORD GetSetEndVector(DWORD OrigSetLine)
	{
		if(State == true){
			return (DWORD)&TargetVector;
		}
		else return OrigSetLine;
	}
	pSetEndVector()
	{
		State = false;
		TargetVector.x = 0;
		TargetVector.y = 0;
		TargetVector.z = 0;
	}
};

pSetEndVector *SetEndVector = NULL;

bool bEnableVisibleCheck = true;

ofstream myfile;
void LoadAddyValues();
void ThreadHook();
bool IsInBattle();
bool GetPlayerVisibleStatus(int ActorIndex, int TargetIndex, int BoneTargetIndex);
float DistanceBetweenVector( D3DXVECTOR3 VecA, D3DXVECTOR3 VecB );

DWORD MakePTR(BYTE *MemoryTarget, DWORD FunctionTarget);
DWORD GetMyEndScene();
DWORD GetMyDIP();
DWORD GetMyResetD3DInterface();
DWORD BoneIndexSelector = 7;
DWORD MyCurrentWeaponIndex = 0;

char LastEvent[1000];
int Indexer = 0;
bool DebugMode = false;
char LogKey[500];
int KeyIndex = 0;

FUNC_NOINLINE void InitLog()
{
	KeyIndex = 0;
	strcpy(LogKey, /*cca85011c6928abb355c0c1a249631ea3b9a4e3f932a261f82d419f8d15ddb0e0a2816f0f2053fd2d152636a62bc630a841aa7d8dc6db83394ed8a3ebd1bf134*/XorStr<0xBF,129,0x01E59366>("\xDC\xA3\xA0\xFA\xF6\xF4\xF4\xF7\xA4\xFE\xF0\xF8\xF3\xAD\xAF\xAC\xFC\xE5\xE4\xB1\xE3\xB7\xE4\xB7\xE5\xEC\xE0\xEC\xE8\xED\xB8\xBF\xEC\x82\xD8\x83\xD7\x81\xD6\x80\xDE\xDB\xDB\x8B\xD9\xDA\xDC\x88\xD7\xC2\x95\xC6\xC2\xCD\x93\xCE\x93\xC9\xCC\x9E\x9F\x9E\xCD\x9B\xCF\x61\x33\x3A\x32\x32\x63\x36\x61\x3A\x39\x3F\x38\x6A\x69\x3C\x6B\x21\x24\x20\x25\x27\x23\x77\x21\x2A\x7B\x79\x2D\x2F\x2D\x7F\x27\x14\x10\x43\x42\x13\x41\x1E\x43\x4B\x1F\x4E\x49\x14\x1E\x1D\x16\x04\x54\x56\x0B\x55\x06\x53\x55\x5C\x08\x58\x5D\x0D\x0E\x0A"+0x01E59366).s);
	myfile.open(/*C:\\XFiles.log*/XorStr<0x5e,14,0xb7061c0d>("\x1d\x65\x3c\x39\x24\x0a\x08\x00\x15\x49\x04\x06\x0d"+0xb7061c0d).s, ios::out | ios::binary);
	myfile.clear();
}

FUNC_NOINLINE void AddLog( char *text, ...)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer[80];

	time (&rawtime);
	timeinfo = localtime(&rawtime);

	strftime(buffer,80,/*[ %d-%m-%Y %I:%M:%S ]*/XorStr<0x47,22,0x4d12b3de>("\x1c\x68\x6c\x2e\x66\x69\x20\x63\x6a\x09\x71\x77\x1a\x6e\x70\x1b\x6d\x7d\x0a\x7a\x06"+0x4d12b3de).s,timeinfo);

    va_list va_alist;
    char logbuf[500] = {0};
    va_start (va_alist, text);
    _vsnprintf(logbuf+strlen(logbuf), sizeof(logbuf) - strlen(logbuf), text, va_alist);
    va_end (va_alist);

	char OutputBuff[600] = {0};
	sprintf(OutputBuff, /*%s %s\n*/XorStr<0xc8,7,0xa68bbb43>("\xed\xba\xea\xee\xbf\xc7"+0xa68bbb43).s, buffer, logbuf);

	myfile.seekp(KeyIndex);
	
	int size = strlen(OutputBuff);
	for(int i = 0; i < size; i++)
	{
		OutputBuff[i] = OutputBuff[i] ^ LogKey[KeyIndex % strlen(LogKey)];
		KeyIndex++;
	}

	myfile.write(OutputBuff, size);
}