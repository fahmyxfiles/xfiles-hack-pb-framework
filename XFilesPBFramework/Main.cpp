#include "Main.h"
#include "XorStr.h"
#include "NetHTTP.h"

#include "GlobalDefines.h"
#include "FeatureStruct.h"
#include "D3D9Include.h"

#include "DrawingFunctions.h"

#include "AddyLogger.h"
#include "GameClasses.h"
#include "ESPLoop.h"
#include "HackLoop.h"

#include "D3DHack.h" 
#include "Hook.h"
#include "XFilesFrameworkSdk.h"
BOOL WINAPI DllMain (HMODULE hModule, DWORD dwReason, LPVOID lpvReserved)
{
	if(dwReason == DLL_PROCESS_ATTACH){
		XFilesFramework = new cXFilesFramework;
		//XFilesFramework->Initialize(hModule, hModule);
	}
return TRUE;
} 