#include "HackFunctions.h"
#include "HackDefines.h"

//#define FastKillerWeapon 904007001
#define FastKillerWeapon 904007026

#define WeaponGrenade_Dmg 0x648
bool pGrenadeKeyer = false;
void MemHack()
{	 
	if(IsInBattle()){
		CGameCharaBase* LocalChara = pGameCharaManager->getLocalChara();
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Player.Reborn && !LocalChara->isAlive() && IsKeyboardKeyDownOnce(DIK_C))pGameContext->setEvent(EventCode.Respawn, NULL, NULL, NULL, NULL, NULL);
		//==============================================================================================================================================
		if(HackFlags->bBrutal){
			static bool bSavePosFastKiller = false;
			if(FeatureStruct->GameHack.Brutal.FastKiller){
				*(DWORD*)(LocalChara->getGameCharaWeaponContext()->getCurrentWeapon() + WeaponGrenade_Dmg) = 100;


				if(LocalChara->isAlive() ){
					LocalChara->eventFall(200);
					bSavePosFastKiller = false;
				}
				else {

					static D3DXVECTOR3 pMySavePos;
					if(bSavePosFastKiller == false){
						LocalChara->setCharaWeapon(0, _WeaponValue(FastKillerWeapon).WeaponType(), _WeaponValue(FastKillerWeapon).WeaponIndex());
						pMySavePos = LocalChara->getGameCharaBoneContext()->getBonePosition(5);
						bSavePosFastKiller = true;
					}
					CWeaponGrenade* pGrenade = (CWeaponGrenade*)(LocalChara->getGameCharaWeaponContext()->getCurrentWeapon());
					for(int i = 0; i <= 15; i++){
						CGameCharaBase* Target = pGameCharaManager->getCharaByNetIdx(i);
						if(Target == NULL || Target->isAlive() == false || Target->isEnemy() == false || Target->isLocal() == true)continue;
						Target->setInvicibleTime(0.0f);
						DWORD OptTeam = 2;
						D3DXVECTOR3 AimTarget = Target->getGameCharaBoneContext()->getBonePosition(5);
						if(pGameContext->isRedTeam(Target->getCharaNetIndex()))OptTeam = 1;

						i3CollideeLine GrenadeLine;
						i3CollideeLine_Initialize(&GrenadeLine);
						i3CollideeLine_SetStart(&GrenadeLine,&LocalChara->getGameCharaBoneContext()->getBonePosition(5));
						i3CollideeLine_SetEnd(&GrenadeLine,&Target->getGameCharaBoneContext()->getBonePosition(5));

						pGrenade->onHitCharaByExplosion(Target, 0x22, &GrenadeLine.vDir, &GrenadeLine.vStart);
						pGrenade->doLineCollision(&AimTarget, &pMySavePos, OptTeam);
						pGameUDPHandler->WriteGameEvent_Fire(LocalChara, &AimTarget, pGrenade);

						pGrenade->onHitCharaByExplosion(Target, 0x22, &GrenadeLine.vDir, &GrenadeLine.vStart);
						pGrenade->doLineCollision(&AimTarget, &pMySavePos, OptTeam);
						pGameUDPHandler->WriteGameEvent_Fire(LocalChara, &AimTarget, pGrenade);



					}

				}
			} else bSavePosFastKiller = false;
		}
		//==============================================================================================================================================
		static bool bSavePosHealthAbsorber = false;
		if(FeatureStruct->GameHack.Player.HealthAbsorber)
		{
			*(DWORD*)(LocalChara->getGameCharaWeaponContext()->getCurrentWeapon() + WeaponGrenade_Dmg) = 10;


			if(LocalChara->isAlive()){
				bSavePosHealthAbsorber = false;
			}
			else {

				static D3DXVECTOR3 pMySavePos;
				if(bSavePosHealthAbsorber == false){
					LocalChara->setCharaWeapon(0, _WeaponValue(FastKillerWeapon).WeaponType(), _WeaponValue(FastKillerWeapon).WeaponIndex());
					pMySavePos = LocalChara->getGameCharaBoneContext()->getBonePosition(5);
					bSavePosHealthAbsorber = true;
				}
				CWeaponGrenade* pGrenade = (CWeaponGrenade*)(LocalChara->getGameCharaWeaponContext()->getCurrentWeapon());
				static DWORD dwTick = NULL;
				if(dwTick <= GetTickCount()){
					for(int i = 0; i <= 15; i++){
						CGameCharaBase* Target = pGameCharaManager->getCharaByNetIdx(i);
						if(Target == NULL || Target->isAlive() == false || Target->isEnemy() == false || Target->isLocal() == true)continue;
						if(Target->getCurHP() < 10)continue;
						Target->setInvicibleTime(0.0f);
						DWORD OptTeam = 2;
						D3DXVECTOR3 AimTarget = Target->getGameCharaBoneContext()->getBonePosition(5);
						if(pGameContext->isRedTeam(Target->getCharaNetIndex()))OptTeam = 1;

						i3CollideeLine GrenadeLine;
						i3CollideeLine_Initialize(&GrenadeLine);
						i3CollideeLine_SetStart(&GrenadeLine,&LocalChara->getGameCharaBoneContext()->getBonePosition(5));
						i3CollideeLine_SetEnd(&GrenadeLine,&Target->getGameCharaBoneContext()->getBonePosition(5));

						pGrenade->onHitCharaByExplosion(Target, 0x22, &GrenadeLine.vDir, &GrenadeLine.vStart);
						pGrenade->doLineCollision(&AimTarget, &pMySavePos, OptTeam);
						pGameUDPHandler->WriteGameEvent_Fire(LocalChara, &AimTarget, pGrenade);

					}
					dwTick = GetTickCount() + 75;
				}
			}
		} else bSavePosHealthAbsorber = false;


		//==============================================================================================================================================
	} 
	else {
		FeatureStruct->GameHack.Player.FreeMove = 0;
		FeatureStruct->GameHack.Misc.KickAllPlayer = 0;
	}
	//==============================================================================================================================================
	if(IsInBattle() && pGameCharaManager->getLocalChara() && pGameCharaManager->getLocalChara()->isAlive()){
		//==============================================================================================================================================
		CGameCharaBase* LocalChara = pGameCharaManager->getLocalChara();
		MyCurrentWeaponIndex = LocalChara->getGameCharaWeaponContext()->getCurrentWeaponIndex();
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Weapon.QuickChange){
			CGameCharaAnimContext* pMyCharaAnimContext = LocalChara->getGameCharaAnimContext();
			if(pMyCharaAnimContext > NULL){
				i3AIContext* pMyCharai3AIContext = pMyCharaAnimContext->geti3AIContext();
				if(pMyCharai3AIContext > NULL){
					ModifyTargetBase[0] = (DWORD)pMyCharai3AIContext;
				} else ModifyTargetBase[0] = NULL;
			}else ModifyTargetBase[0] = NULL;
		}else ModifyTargetBase[0] = NULL;

		if(FeatureStruct->GameHack.Weapon.NoRecoil)
		{
			CGameCharaBoneContext* pMyCharaBoneContext = LocalChara->getGameCharaBoneContext();
			if(pMyCharaBoneContext > NULL){
				CWeaponProperty* pMyWeaponProperty = pMyCharaBoneContext->getWeaponProperty();
				if(pMyWeaponProperty > NULL){

					static DWORD dwFreezeH1, dwFreezeH2, dwFreezeH3 = NULL;
					if(!dwFreezeH1)dwFreezeH1 = pMyWeaponProperty->RecoilH1;
					if(!dwFreezeH2)dwFreezeH2 = pMyWeaponProperty->RecoilH2;
					if(!dwFreezeH3)dwFreezeH3 = pMyWeaponProperty->RecoilH3;

					pMyWeaponProperty->RecoilV1 = 0;
					pMyWeaponProperty->RecoilV2 = 0;
					pMyWeaponProperty->RecoilH1 = dwFreezeH1;
					pMyWeaponProperty->RecoilH2 = dwFreezeH2;
					pMyWeaponProperty->RecoilH3 = dwFreezeH3;
					pMyWeaponProperty->Deviation1 = 0;
					pMyWeaponProperty->Deviation2 = 0;
					pMyWeaponProperty->Deviation3 = 0;
				}
			}
		}
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Player.SkillUp){
			pGameContext->setRankValue(pGameContext->getMySlotIdx(), 0x35);
		}
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Player.ResetWeapon)
		{
			if(IsKeyboardKeyDownOnce(DIK_V)){
				if(FeatureStruct->GameHack.Player.ResetWeapon == 1){
					pGameCharaManager->SetCharaWeaponSet(LocalChara, pGameContext->getNetCharaInfo(LocalChara->getCharaNetIndex()));
				}
				if(FeatureStruct->GameHack.Player.ResetWeapon == 2){
					pGameCharaManager->SetCharaWeaponSetWithoutLock(LocalChara, pGameContext->getNetCharaInfo(LocalChara->getCharaNetIndex()));
				}
				if(FeatureStruct->GameHack.Player.ResetWeapon == 3){
					LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->Reset();
				}
			}
		}
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Player.PlantDefuse && pGameContext->isRedTeam(pGameContext->getMySlotIdx()) == false){
			if(GetKeyboardPressState(DIK_E))
				pGameContext->getGameCharaMissionManager()->InstallBomb(true);
			else
				pGameContext->getGameCharaMissionManager()->UnInstallBomb(true);
		}
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Player.AutoHeadshot){
			FeatureStruct->GameHack.Assist.Mode = 0;
			CGameCharaBase* MyTarget = LocalChara->getGameCharaCollisionContext()->GetCrosshairTarget();
			if(MyTarget > NULL)
				SetEndVector->SetTargetVector(MyTarget->getGameCharaBoneContext()->getBonePosition(BoneIndexSelector));
			else 
				SetEndVector->Disable();
		}
		if(FeatureStruct->GameHack.Player.AlwaysInvicible){
			static DWORD dwTick = NULL;
			if(dwTick <= GetTickCount()){
				LocalChara->setInvicibleTime(4.0f);
				dwTick = GetTickCount() + 2000;
			}

		}

		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Weapon.AutoFillSubAmmo){
			CGameCharaWeaponContext* pMyCharaWeaponContext = LocalChara->getGameCharaWeaponContext();
			if(pMyCharaWeaponContext){
				CWeaponBase* pMyWeaponBase = pMyCharaWeaponContext->getCurrentWeapon();
				if(pMyWeaponBase && pMyCharaWeaponContext->getCurrentWeaponIndex() >= 0 && pMyCharaWeaponContext->getCurrentWeaponIndex() <= 1){
					if(pMyWeaponBase->getSubAmmoCount() < 5)
					{
						pMyWeaponBase->Reset();
					}
				}
			}
		}
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Weapon.SkipReload){
			CGameCharaWeaponContext* pMyCharaWeaponContext = LocalChara->getGameCharaWeaponContext();
			if(pMyCharaWeaponContext > NULL){
				CWeaponBase* CurrentWeapon = pMyCharaWeaponContext->getCurrentWeapon(); 
				if(CurrentWeapon){
					i3AIContext* pMyCharai3AIContext = CurrentWeapon->geti3AIContext();
					if(pMyCharai3AIContext > NULL){
						ModifyTargetBase[1] = (DWORD)pMyCharai3AIContext;
					} else ModifyTargetBase[1] = NULL;
				} else ModifyTargetBase[1] = NULL;
			}else ModifyTargetBase[1] = NULL;
		}else ModifyTargetBase[1] = NULL;
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Weapon.RapidFire)
		{
			if(pGameFramework->geti3InputMouse()->GetButtonState() == 1){
				DWORD dwDelay = 0;
				switch(FeatureStruct->GameHack.Weapon.RapidFire)
				{
				case 1:
					dwDelay = 500;
					break;
				case 2:
					dwDelay = 300;
					break;
				case 3:
					dwDelay = 100;
					break;
				case 4:
					dwDelay = 10;
					break;
				}
				static DWORD dwTick = 0;
				if(dwTick <= GetTickCount())
				{
					LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->Reset();
					LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->doFire();
					dwTick = GetTickCount() + dwDelay;
				}
			}
		}
		//==============================================================================================================================================
		if(FeatureStruct->GameHack.Weapon.AutoFire)
		{
			CGameCharaBase* MyTarget = LocalChara->getGameCharaCollisionContext()->GetCrosshairTarget();
			if(MyTarget > NULL)
				LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->doFire();
		}
		if(HackFlags->bBrutal){
			//==============================================================================================================================================
			if(FeatureStruct->GameHack.Brutal.AutoKiller){
				FeatureStruct->GameHack.Assist.Mode = 0;
				for(int i = 0; i <= 15; i++){
					CGameCharaBase* Target = pGameCharaManager->getCharaByNetIdx(i);
					if(Target == NULL || Target->isAlive() == false || Target->isEnemy() == false || Target->isLocal() == true || Target->isVisible(BoneIndexSelector) == false)continue;
					DWORD OptTeam = 2;
					D3DXVECTOR3 AimTarget = Target->getGameCharaBoneContext()->getBonePosition(BoneIndexSelector);
					AimTarget.y += 0.1f;
					if(pGameContext->isRedTeam(Target->getCharaNetIndex()))OptTeam = 1;
					if(LocalChara->getGameCharaWeaponContext()->getCurrentWeaponIndex() == 2){
						SetEndVector->SetTargetVector(AimTarget);
						LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->doFire();
						SetEndVector->Disable();
					}
					else {
						LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->doLineCollision(&LocalChara->getGameCharaBoneContext()->getBonePosition(5), &AimTarget, OptTeam);
						LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->doFire();
					}

				}
			}
			//==============================================================================================================================================
			if(FeatureStruct->GameHack.Brutal.ExplosiveKiller){
				if(LocalChara->getGameCharaWeaponContext()->getCurrentWeaponIndex() == 3){
					CWeaponGrenade* pGrenade = (CWeaponGrenade*)(LocalChara->getGameCharaWeaponContext()->getCurrentWeapon());
					for(int i = 0; i <= 15; i++){
						CGameCharaBase* Target = pGameCharaManager->getCharaByNetIdx(i);
						if(Target == NULL || Target->isAlive() == false || Target->isEnemy() == false || Target->isLocal() == true)continue;
						Target->setInvicibleTime(0.0f);
						for(int x = 0; x < 8; x++){
							i3CollideeLine GrenadeLine;
							i3CollideeLine_Initialize(&GrenadeLine);
							i3CollideeLine_SetStart(&GrenadeLine,&LocalChara->getGameCharaBoneContext()->getBonePosition(5));
							i3CollideeLine_SetEnd(&GrenadeLine,&Target->getGameCharaBoneContext()->getBonePosition(5));
							pGrenade->onHitCharaByExplosion(Target, 0x22, &GrenadeLine.vDir, &GrenadeLine.vStart);
						}
					}

					if(pGameFramework->geti3InputMouse()->GetButtonState() == 2){
						if(pGrenadeKeyer == false){
							LocalChara->getGameCharaWeaponContext()->getCurrentWeapon()->Reset();
							pGrenadeKeyer = true;
						}
					}
					else {
						if(pGrenadeKeyer == true){
							pGrenadeKeyer = false;
						}
					}
				}
			}
		}

	}

	if(FeatureStruct->GameHack.Misc.ResetAbuse && !IsInBattle())
	{

		if(!IsInBattle()){
			static bool setAbuse = false;

			if(*(PDWORD)(pGameContext+ 0x4A570 + 0x8) != NULL) 
				setAbuse = true;
			else
				setAbuse = false;

			static DWORD dwTick = NULL;
			if(setAbuse == true)
			{
				if(dwTick == NULL)
				{
					pGameContext->SetAbuseCounter(true, 1);
					dwTick =  GetTickCount() + 2000;
				}
				if(dwTick <= GetTickCount())
				{
					pGameContext->ResetAbuseCounter();
					setAbuse = false;
					dwTick = NULL;
				}
			}
		}
	}

	if(FeatureStruct->GameHack.Misc.AutoInviteRoom && !IsInBattle())
	{
		static DWORD dwTick = NULL;
		if(dwTick <= GetTickCount()){

			pGameContext->setEvent(EventCode.GetLobbyUserList, NULL, NULL, NULL, NULL, NULL);
			for(int i = 0; i < 8; i++){
				pGameContext->SetInviteUser(i);
			}
			pGameContext->setEvent(EventCode.SendInviteUser, NULL, NULL, NULL, NULL, NULL);

			dwTick = GetTickCount() + 500;
		}
	}

	if(FeatureStruct->GameHack.Misc.BypassServerFull && !IsInBattle())
	{
		pGameContext->SetMaxChannelUserCount(1000);
		for(int i = 0; i < 10; i++)
		{
			pGameContext->SetChannelUserCount(i, 0);
		}
		_patchMEM((void*)(AddyStruct->XFHPB.Address.Values.GaugeMultiplier), (char*)"\x00\x00\x00\x00\x00\x00\x00\x00", 8);
	}
	else
	{
		_patchMEM((void*)(AddyStruct->XFHPB.Address.Values.GaugeMultiplier), (char*)"\x00\x00\x00\x00\x00\x00\x59\x40", 8);
	}


	if(FeatureStruct->GameHack.Misc.KickAllPlayer)
	{
		static DWORD dwTick = NULL;
		if(dwTick <= GetTickCount()){
			pGameContext->setEvent(EventCode.GlobalChat, "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@BY XFILES@@@@@@@@@@@@@@", NULL, NULL, NULL, NULL);
			dwTick = GetTickCount() + 2000;
		}
	}

	if(FeatureStruct->GameHack.Misc.AntiKick)
	{
		_patchMEM((void*)(AddyStruct->PhaseReadyRoom.Function.SelfRemoveFromRoom), (char*)"\xC3", 1);
	}
	else 
	{
		_patchMEM((void*)(AddyStruct->PhaseReadyRoom.Function.SelfRemoveFromRoom), (char*)"\x55", 1);
	}


}