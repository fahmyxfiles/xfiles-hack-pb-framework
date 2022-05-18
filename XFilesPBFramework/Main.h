#include <windows.h>
#include < stdio.h>
#include <fstream>
#include <d3dx9.h>
#include <Psapi.h>
#include <ctime>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <tchar.h>
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
#include <vector>
#include <string>
#include <string.h>
#include <assert.h>
#pragma comment(lib, "Ws2_32.lib")
#pragma warning(disable: 4244 4996)
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma warning (disable : 4996 4244)
using namespace std;
#define CDllExport extern "C" __declspec( dllexport )
#define DllExport __declspec( dllexport )
#define SAFE_RELEASE(p)          { if (p) { (p)->Release(); (p)=NULL; } }
//-------------------------------------------------------------------------------------------------------------------------
int Create;
DWORD dwDIP, dwES;
LPDIRECT3DVERTEXBUFFER9 Stream_Data;
LPDIRECT3DDEVICE9 npDevice;
D3DVIEWPORT9 g_ViewPort;
LPDIRECT3DTEXTURE9 Red;
LPDIRECT3DTEXTURE9 Blue;
LPD3DXLINE g_pLine  = NULL; //D3D Line
LPD3DXFONT g_pFont = NULL; //D3D Font
UINT Offset, Stride = 0;

float ScreenCenterX, ScreenCenterY = 0;
bool Generate = false;
bool hooked = false;
typedef HRESULT (WINAPI* tEndScene)(LPDIRECT3DDEVICE9 pDevice);
tEndScene oEndScene = NULL;
typedef HRESULT (WINAPI* tDrawIndexedPrimitive)(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount);
tDrawIndexedPrimitive oDrawIndexedPrimitive = NULL;
typedef HRESULT (WINAPI* tReset)(IDirect3DDevice9* pDevice, D3DPRESENT_PARAMETERS* pPresentationParameters);
tReset oReset = NULL;
typedef void (__cdecl* tResetD3DInterface)(void);
tResetD3DInterface oResetD3DInterface = NULL;
bool IsKeyboardKeyDownOnce(int Index);

class cPBBasicLicense
{
public:
	int uid;
	string Name;
	string OwnerName;
	string Flags;
};
cPBBasicLicense* PBBasicLicense = NULL;

struct sHackFlags
{
	bool bBrutal;
	bool bSpecial;
	bool bReplace;
	bool bCustomMenu;
	bool Misc1006;
	bool USGBypass;
	bool DeleteBypass;
};
sHackFlags* HackFlags = NULL;
char *MoptVote [] = {"xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx", 
					 "xxxxxxxxxxxxxxxx",
					 "xxxxxxxxxxxxxxxx" };
int VoteMenuIdx = 0;