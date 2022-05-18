#include "ESPFunctions.h"
#include "ESPTools.h"


void DoESP(LPDIRECT3DDEVICE9 pDevice)
{
	if(IsInBattle()){
		for(int i = 0; i <= 15; i++){
			CGameCharaBase* Chara = pGameCharaManager->getCharaByNetIdx(i);
			if(Chara){
				if(Chara->isEnemy() == false && FeatureStruct->Visual.ESP.Team == 0)continue;
				if(Chara->isAlive() == false)continue;

				D3DXVECTOR3 Head = Chara->getGameCharaBoneContext()->getBonePosition(7);
				D3DXVECTOR3 ScreenHead;
				D3DXVECTOR3 ScreenHeadNames;
				D3DXVECTOR3 ScreenHeadHealth;
				if( pRenderContext->WorldToScreen(D3DXVECTOR3(Head.x, Head.y + 0.1f, Head.z),ScreenHead,pDevice) &&
					pRenderContext->WorldToScreen(D3DXVECTOR3(Head.x, Head.y + 0.5f, Head.z),ScreenHeadNames,pDevice) &&
					pRenderContext->WorldToScreen(D3DXVECTOR3(Head.x, Head.y + 0.3f, Head.z),ScreenHeadHealth,pDevice))
				{
					if(FeatureStruct->Visual.ESP.Name)DrawStringC(g_pFont,ScreenHeadNames.x,ScreenHeadNames.y-15,Chara->GetTeamColor(),/*%s - %dHP*/XorStr<0xCD,10,0xF438969D>("\xE8\xBD\xEF\xFD\xF1\xF7\xB7\x9C\x85"+0xF438969D).s, Chara->getNickname(), Chara->getCurHP());	
					if(FeatureStruct->Visual.ESP.Head)FillRGB((float)ScreenHead.x, (float)ScreenHead.y, 4, 4,Chara->GetTeamColor(), pDevice);
					if(FeatureStruct->Visual.ESP.HealthBar)HealthBar((int)ScreenHeadHealth.x - 25,(int)ScreenHeadHealth.y,Chara->getCurHP(),pDevice);
					if(FeatureStruct->Visual.ESP.Line)DrawESPLine((float)ScreenCenterX,(float)ScreenCenterY,(float)ScreenHead.x,(float)ScreenHead.y,1,Chara->GetPlayerColor());
					if(FeatureStruct->Visual.ESP.Bone)DrawPlayerBone(i,Chara->GetPlayerColor());
				}
			}
		}
	}
}

bool bIsAimTargetValid = false;
void DisableAimAssist()
{
	if(bIsAimTargetValid == true){
		SetEndVector->Disable();
		bIsAimTargetValid = false;
	}
}

void DoAimAssist(LPDIRECT3DDEVICE9 pDevice)
{
	if(IsInBattle()){
		
		switch(FeatureStruct->GameHack.Assist.Target)
		{
		case 0:
			BoneIndexSelector = 7;
			break;
		case 1:
			BoneIndexSelector = 5;
			break;
		}
		CGameCharaBase* LocalChara = pGameCharaManager->getLocalChara();
		if(LocalChara && LocalChara->isAlive()){
			if(FeatureStruct->GameHack.Assist.Mode){
				if(GetAimAssistState()){
					CGameCharaBase* Target = pGameCharaManager->getCharaToAim();
					if(Target){
						bIsAimTargetValid = true;
						D3DXVECTOR3 AimTarget = Target->getGameCharaBoneContext()->getBonePosition(BoneIndexSelector);
						AimTarget.y += 0.1f;
						if(FeatureStruct->GameHack.Assist.Mode == 1)SetLocalPawnAimTarget(AimTarget);
						if(FeatureStruct->GameHack.Assist.Mode == 2)SetEndVector->SetTargetVector(AimTarget);
					} else DisableAimAssist();
				} else DisableAimAssist();
			} else DisableAimAssist();
		} else DisableAimAssist();
	} else DisableAimAssist();

}