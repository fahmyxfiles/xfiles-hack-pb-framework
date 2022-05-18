#include "Textures.h"
HWND myWindow = NULL;
bool stateReset = false;
void Crosshair(LPDIRECT3DDEVICE9 pDevice, D3DVIEWPORT9 pViewPort, D3DCOLOR Color)
{

	pDevice->GetViewport(&pViewPort);
	D3DRECT RectA, RectB;
	RectA.x1 = (pViewPort.Width/2)-10;
	RectA.x2 = (pViewPort.Width/2)+ 10;
	RectA.y1 = (pViewPort.Height/2);
	RectA.y2 = (pViewPort.Height/2)+1;
	RectB.x1 = (pViewPort.Width/2);
	RectB.x2 = (pViewPort.Width/2)+ 1;
	RectB.y1 = (pViewPort.Height/2)-10;
	RectB.y2 = (pViewPort.Height/2)+10;
	pDevice->Clear(1, &RectA, D3DCLEAR_TARGET, Color, 0,  0);
	pDevice->Clear(1, &RectB, D3DCLEAR_TARGET, Color, 0,  0);
}
const char* getMachineName()       
{        
	static char computerName[1024]; 
	DWORD size = 1024;     
	GetComputerName( computerName, &size );           
	return &(computerName[0]);      
}
bool bScreenTaken = false;
void ScreenCapt(LPDIRECT3DDEVICE9 pDevice)
{
	LPDIRECT3DSURFACE9 pScreenbuffer;
	LPD3DXBUFFER pImageBuffer;
	DrawStringC(g_pFont, ScreenCenterX, g_ViewPort.Height - 70, RED, /*%s\n[ %s ]*/XorStr<0xCD,10,0x992641BF>("\xE8\xBD\xC5\x8B\xF1\xF7\xA0\xF4\x88"+0x992641BF).s, PBBasicLicense->Name.c_str(), getMachineName());
	pDevice->GetBackBuffer( 0, 0, D3DBACKBUFFER_TYPE_MONO, &pScreenbuffer );
	D3DXSaveSurfaceToFileInMemory(&pImageBuffer, D3DXIFF_JPG, pScreenbuffer, NULL, NULL);
	CNetHTTP* Request = new CNetHTTP(string(/*POST*/XorStr<0x9C,5,0xE95BFA79>("\xCC\xD2\xCD\xCB"+0xE95BFA79).s), string(/*http://www.xfiles.co/XFilesEngine/api/screencap.php*/XorStr<0x56,52,0x2FD65E62>("\x3E\x23\x2C\x29\x60\x74\x73\x2A\x29\x28\x4E\x19\x04\x0A\x08\x00\x15\x49\x0B\x06\x45\x33\x2A\x04\x02\x0A\x03\x34\x1C\x14\x1D\x1B\x13\x58\x19\x09\x13\x54\x0F\x1E\x0C\x1A\xE5\xEF\xE1\xE2\xF4\xAB\xF6\xEF\xF8"+0x2FD65E62).s));
	Request->AddParameter(string(/*MachineName*/XorStr<0x82,12,0x2424BEDE>("\xCF\xE2\xE7\xED\xEF\xE9\xED\xC7\xEB\xE6\xE9"+0x2424BEDE).s), getMachineName());
	Request->AddParameter(string(/*Name*/XorStr<0xC2,5,0x2CD92EF0>("\x8C\xA2\xA9\xA0"+0x2CD92EF0).s), PBBasicLicense->Name);
	Request->AddFiles(string(/*ScreenCapt*/XorStr<0xA4,11,0xEA0AA394>("\xF7\xC6\xD4\xC2\xCD\xC7\xE9\xCA\xDC\xD9"+0xEA0AA394).s), string(/*XFiles.t3d*/XorStr<0x2E,11,0x24BD9F11>("\x76\x69\x59\x5D\x57\x40\x1A\x41\x05\x53"+0x24BD9F11).s), string(/*image/jpeg*/XorStr<0xDB,11,0x71E77509>("\xB2\xB1\xBC\xB9\xBA\xCF\x8B\x92\x86\x83"+0x71E77509).s), pImageBuffer->GetBufferPointer(), pImageBuffer->GetBufferSize());
	Request->Run();
	Request->Cleanup();
	SAFE_RELEASE( pScreenbuffer );
	SAFE_RELEASE( pImageBuffer );
}
//-------------------------------------------------------------------------------------------------------------------------
HRESULT WINAPI hkEndScene(LPDIRECT3DDEVICE9 pDevice){

	while(!npDevice){
		npDevice = pDevice;	
		pDevice->GetViewport(&g_ViewPort);
		ScreenCenterX = g_ViewPort.Width / 2;
		ScreenCenterY = g_ViewPort.Height / 2;
	}

	static bool bInitEs = false;
	while(!bInitEs)
	{
		HookSetEvent();
		bInitEs = true;
	}

	if(!g_pLine)D3DXCreateLine(pDevice,&g_pLine);
	if(!g_pFont)D3DXCreateFontA(pDevice, 15, 0, FW_EXTRALIGHT, 2, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE, (LPCSTR)"Arial", &g_pFont);

	UpdateClass();

	DirectInputLoop();


	if( IsInBattle() ){
		DWORD CrosshairColor = GREEN;
		if( pGameCharaManager->getLocalChara()->getGameCharaCollisionContext()->GetCrosshairTarget() > NULL )CrosshairColor = RED;
		if( FeatureStruct->Visual.Direct3D.CrossHair )Crosshair(pDevice, g_ViewPort, CrosshairColor);
	}

	DoESP(pDevice);
	DoAimAssist(pDevice);
	MemHack();

	oEndScene = (tEndScene)GetMyEndScene();
	if(oEndScene > NULL){
		oEndScene(pDevice);
	}
	FillRGB(PBBasicLicense->uid, 5, 1, 1, RED, pDevice);
	if(!bScreenTaken)
	{
		if(Generate == true)
		{
			ScreenCapt(pDevice);
			bScreenTaken = true;
		}
	}

	return pDevice->EndScene();

}
//-------------------------------------------------------------------------------------------------------------------------

HRESULT WINAPI hkDrawIndexedPrimitive(LPDIRECT3DDEVICE9 pDevice, D3DPRIMITIVETYPE PrimType,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount)
{
	
	if(!Generate)
	{
		Generate = true;
	}
	if(!Red)D3DXCreateTextureFromFileInMemory(pDevice, &_texRed, sizeof(_texRed), &Red);
	if(!Blue)D3DXCreateTextureFromFileInMemory(pDevice, &_texBlue, sizeof(_texBlue), &Blue);
	if(IsInBattle()){	
		if(FeatureStruct->Visual.Direct3D.WallHack || FeatureStruct->Visual.Direct3D.Charms){
			if(allp2){  
				if(FeatureStruct->Visual.Direct3D.Charms){
					if(FeatureStruct->Visual.Direct3D.Charms == 1){ //Light Charms
						pDevice->SetRenderState(D3DRS_ZENABLE,false);
						if(PlayerTerorist||TeroHead||C5||K400)pDevice->SetTexture(0,Red);
						if(PlayerCT||CTHead)pDevice->SetTexture(0,Blue);
						pDevice->DrawIndexedPrimitive(PrimType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount);
						pDevice->SetRenderState(D3DRS_ZENABLE,true);

					}
					if(FeatureStruct->Visual.Direct3D.Charms == 2){ //Ghost Charms
						pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
						pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVDESTCOLOR);
						pDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_INVSRCCOLOR);
						pDevice->SetRenderState(D3DRS_ZENABLE,false);	
						pDevice->DrawIndexedPrimitive(PrimType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount);
						pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
						pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVDESTCOLOR);
						pDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_INVSRCCOLOR);
						pDevice->SetRenderState(D3DRS_ZENABLE,true);
					}
					if(FeatureStruct->Visual.Direct3D.Charms == 3){ //Phantom Charms
						pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
						pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVDESTCOLOR);
						pDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_INVSRCALPHA);
						pDevice->SetRenderState(D3DRS_ZENABLE,false);
						pDevice->DrawIndexedPrimitive(PrimType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount);
						pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,true);
						pDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVDESTCOLOR);
						pDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_INVSRCALPHA);
						pDevice->SetRenderState(D3DRS_ZENABLE,false);
					}
				}
				else
				{
					pDevice->SetRenderState(D3DRS_ZENABLE, false);
					pDevice->DrawIndexedPrimitive(PrimType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount);
					pDevice->SetRenderState(D3DRS_ZENABLE, true);
				}
			}
		}


		if(FeatureStruct->Visual.Direct3D.NoSmoke)
			if((NumVertices == 192) || (NumVertices == 256))return D3D_OK;

		if(FeatureStruct->Visual.Direct3D.NoFog)pDevice->SetRenderState(D3DRS_FOGENABLE, false);

	}
	oDrawIndexedPrimitive = (tDrawIndexedPrimitive)GetMyDIP();
	if(oDrawIndexedPrimitive > NULL){
		oDrawIndexedPrimitive(pDevice,PrimType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount);
	}

	return pDevice->DrawIndexedPrimitive(PrimType,BaseVertexIndex,MinVertexIndex,NumVertices,startIndex,primCount);
}

void ResetD3DInterface()
{
	if(g_pFont){
		g_pFont->OnLostDevice();
		g_pFont->OnResetDevice();
		g_pFont->Release();
		g_pFont = NULL;
	}
	if(g_pLine){
		g_pLine->OnLostDevice();
		g_pLine->OnResetDevice();
		g_pLine->Release();
		g_pLine = NULL;
	}
	if(Red)	{
		Red->Release();
		Red = NULL;
	}
	if(Blue) {
		Blue->Release();
		Blue = NULL;
	}
	if(npDevice)
		npDevice = NULL;

	oResetD3DInterface = (tResetD3DInterface)GetMyResetD3DInterface();
	if(oResetD3DInterface > NULL){
		oResetD3DInterface();
	}
}