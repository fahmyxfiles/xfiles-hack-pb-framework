class CRenderContext;
class CGameCharaMissionManager;
class CGameUDPHandler;
class CGameContext;
class i3AIContext;
class CWeaponBase;
class CGameCharaWeaponContext;
class CGameCharaBoneContext;
class CWeaponProperty;
class CGameCharaCollisionContext;
class CGameCharaBase;
class CGameCharaManager;
class i3InputMouse;
class i3InputKeyboard;
class i3PhysixResult;
class CGameFramework;
enum eEventCode;


struct sEventCode{
	enum Values
	{
		Respawn = 0x97,
		GetLobbyUserList = 0x87,
		SendInviteUser = 0x88,
		JoinRoom = 0x76,
		Whisper = 0x66,
		GlobalChat = 0x1FD,
	};
};
sEventCode EventCode;

enum CharaState
{
	Idle = 1,
	Running = 2,
	Firing = 3,
	Throwing = 4,
	SubFiring = 5,
	Reloading = 6,
	ChangeWeapon = 9,
	Jumping = 10,
	EquipExtension = 11,
	RemoveExtension = 12,
};

class CRenderContext
{
public:
	D3DXMATRIX* GetProjectMatrix(void)
	{
		typedef D3DXMATRIX* (__thiscall * tGetProjectMatrix)(CRenderContext* Base);
		tGetProjectMatrix GetProjectMatrix = (tGetProjectMatrix)(AddyStruct->RenderContext.Function.GetProjectMatrix);
		return GetProjectMatrix(this);
	}
	D3DXMATRIX* GetViewMatrix(void)
	{
		typedef D3DXMATRIX* (__thiscall * tGetViewMatrix)(CRenderContext* Base);
		tGetViewMatrix GetViewMatrix = (tGetViewMatrix)(AddyStruct->RenderContext.Function.GetViewMatrix);
		return GetViewMatrix(this);
	}
	D3DXMATRIX* GetWorldMatrix(void)
	{
		typedef D3DXMATRIX* (__thiscall * tGetWorldMatrix)(CRenderContext* Base);
		tGetWorldMatrix GetWorldMatrix = (tGetWorldMatrix)(AddyStruct->RenderContext.Function.GetWorldMatrix);
		return GetWorldMatrix(this);
	}
	bool WorldToScreen(D3DXVECTOR3 PlayerPos,D3DXVECTOR3 &Output,LPDIRECT3DDEVICE9 pDevice)
	{
		D3DXVECTOR3 vScreen;
		g_ViewPort.X = g_ViewPort.Y = 0;
		g_ViewPort.MinZ = 0;
		g_ViewPort.MaxZ = 1;
		D3DXVec3Project(&vScreen, &PlayerPos, &g_ViewPort, this->GetProjectMatrix(), this->GetViewMatrix(), this->GetWorldMatrix());

		if (vScreen.z < 1.0f && vScreen.x > 0.0f && vScreen.y > 0.0f && vScreen.x < g_ViewPort.Width && vScreen.y < g_ViewPort.Height)
		{
			Output.x = vScreen.x;
			Output.y = vScreen.y;
			Output.z = vScreen.z;
			return true; 
		}
		return false;
	}
};
CRenderContext* pRenderContext = NULL;
//==================================================================================================================================
class i3InputMouse
{
public:
	float GetDeltaX()
	{
		typedef float (__thiscall * tGetDeltaX)(i3InputMouse* Base);
		tGetDeltaX GetDeltaX = (tGetDeltaX)( AddyStruct->i3InputMouse.Function.GetDeltaX );
		return GetDeltaX(this);
	}
	float GetDeltaY()
	{
		typedef float (__thiscall * tGetDeltaY)(i3InputMouse* Base);
		tGetDeltaY GetDeltaY = (tGetDeltaY)( AddyStruct->i3InputMouse.Function.GetDeltaY );
		return GetDeltaY(this);
	}
	float GetDeltaZ()
	{
		typedef float (__thiscall * tGetDeltaZ)(i3InputMouse* Base);
		tGetDeltaZ GetDeltaZ = (tGetDeltaZ)( AddyStruct->i3InputMouse.Function.GetDeltaZ );
		return GetDeltaZ(this);
	}


	DWORD GetButtonState()
	{
		typedef DWORD (__thiscall * tGetButtonState)(i3InputMouse* Base);
		tGetButtonState GetButtonState = (tGetButtonState)( AddyStruct->i3InputMouse.Function.GetButtonState );
		return GetButtonState(this);
	}
	DWORD GetStrokeButtonState()
	{
		typedef DWORD (__thiscall * tGetStrokeButtonState)(i3InputMouse* Base);
		tGetStrokeButtonState GetStrokeButtonState = (tGetStrokeButtonState)( AddyStruct->i3InputMouse.Function.GetStrokeButtonState );
		return GetStrokeButtonState(this);
	}

	float GetX()
	{
		typedef float (__thiscall * tGetX)(i3InputMouse* Base);
		tGetX GetX = (tGetX)( AddyStruct->i3InputMouse.Function.GetX );
		return GetX(this);
	}
	float GetY()
	{
		typedef float (__thiscall * tGetY)(i3InputMouse* Base);
		tGetY GetY = (tGetY)( AddyStruct->i3InputMouse.Function.GetY );
		return GetY(this);
	}
	float GetZ()
	{
		typedef float (__thiscall * tGetZ)(i3InputMouse* Base);
		tGetZ GetZ = (tGetZ)( AddyStruct->i3InputMouse.Function.GetZ );
		return GetZ(this);
	}

};
//==================================================================================================================================
class i3InputKeyboard
{
public:
	DWORD GetPressState(int I3I_KEY)
	{
		typedef DWORD (__thiscall * tGetPressState)(i3InputKeyboard* Base, int I3I_KEY);
		tGetPressState GetPressState = (tGetPressState)( AddyStruct->i3InputKeyboard.Function.GetPressState );
		return GetPressState(this, I3I_KEY);
	}
	DWORD GetRepeatState(int I3I_KEY)
	{
		typedef DWORD (__thiscall * tGetRepeatState)(i3InputKeyboard* Base, int I3I_KEY);
		tGetRepeatState GetRepeatState = (tGetRepeatState)( AddyStruct->i3InputKeyboard.Function.GetRepeatState );
		return GetRepeatState(this, I3I_KEY);
	}

	DWORD GetStrokeState(int I3I_KEY)
	{
		typedef DWORD (__thiscall * tGetStrokeState)(i3InputKeyboard* Base, int I3I_KEY);
		tGetStrokeState GetStrokeState = (tGetStrokeState)( AddyStruct->i3InputKeyboard.Function.GetStrokeState );
		return GetStrokeState(this, I3I_KEY);
	}

	DWORD SetPressState(int I3I_KEY, int Value)
	{
		typedef DWORD (__thiscall * tSetPressState)(i3InputKeyboard* Base, int I3I_KEY, int Value);
		tSetPressState SetPressState = (tSetPressState)( AddyStruct->i3InputKeyboard.Function.SetPressState );
		return SetPressState(this, I3I_KEY, Value);
	}
	DWORD SetStrokeState(int I3I_KEY, int Value)
	{
		typedef DWORD (__thiscall * tSetStrokeState)(i3InputKeyboard* Base, int I3I_KEY, int Value);
		tSetStrokeState SetStrokeState = (tSetStrokeState)( AddyStruct->i3InputKeyboard.Function.SetStrokeState );
		return SetStrokeState(this, I3I_KEY, Value);
	}
};
//==================================================================================================================================
class i3PhysixResult
{
public:
	float GetDistanceResult()
	{
		typedef float (__thiscall * tReadData)(DWORD BaseData);
		tReadData ReadData = (tReadData)(AddyStruct->PhysixResult.Function.ReadData);
		return ReadData((DWORD)this + AddyStruct->PhysixResult.Pointer.Distance);
	}
};
//==================================================================================================================================
class CGameFramework
{
public:
	// diatas Gui/Hud/NightVisionTex.i3i
	i3InputKeyboard* geti3InputKeyboard(void)
	{
		return (i3InputKeyboard*)*(DWORD*)(this + AddyStruct->GameFramework.Pointer.I3InputKeyboard);
	}
	i3InputMouse* geti3InputMouse(void)
	{
		return (i3InputMouse*)*(DWORD*)(this + AddyStruct->GameFramework.Pointer.I3InputMouse);
	}
	i3PhysixResult* RaycastClosest(i3CollideeLine* pLine, DWORD dwOption){
		typedef i3PhysixResult* (__thiscall * tRaycastClosest)(CGameFramework* Base, i3CollideeLine* pLine, DWORD dwOption);
		tRaycastClosest RaycastClosest = (tRaycastClosest)(AddyStruct->GameFramework.Function.RaycastClosest);
		return RaycastClosest(this, pLine, dwOption);
	}
};

CGameFramework* pGameFramework = NULL;
//==================================================================================================================================
struct _WeaponValue
{
	DWORD Value;
	_WeaponValue(DWORD dwValue)
	{
		this->Value = dwValue;
	}
	signed int WeaponSlot()
	{
		return (this->Value % 100000000 / 1000000);
	}
	signed int WeaponType()
	{
		return (this->Value % 1000000 / 1000);
	}
	signed int WeaponIndex()
	{
		return (this->Value % 1000);
	}
};
struct _NetCharaInfo
{
	_WeaponValue getWeaponValue(int EquipIndex)
	{
		DWORD FinalValue = *(DWORD*)(this + AddyStruct->_NetCharaInfo.Pointer.Weapon + (EquipIndex*4));
		return _WeaponValue( FinalValue );
	}
	void setWeaponValue(int EquipIndex, DWORD* Value)
	{
		typedef void (__thiscall * tsetWeaponValue)(_NetCharaInfo* Base, int EquipIndex, DWORD* Value);
		tsetWeaponValue setWeaponValue = (tsetWeaponValue)(AddyStruct->_NetCharaInfo.Function.setWeaponValue);
		return setWeaponValue(this, EquipIndex, Value);
	}
};
//==================================================================================================================================
class CGameCharaMissionManager
{
public:
	void InstallBomb(bool State)
	{
		typedef void (__thiscall* tInstallBomb)(CGameCharaMissionManager* Base, bool State);
		tInstallBomb InstallBomb = (tInstallBomb)(AddyStruct->GameCharaMissionManager.Function.InstallBomb);
		return InstallBomb(this, State);
	}
	void UnInstallBomb(bool State)
	{
		typedef void (__thiscall* tUnInstallBomb)(CGameCharaMissionManager* Base, bool State);
		tUnInstallBomb UnInstallBomb = (tUnInstallBomb)(AddyStruct->GameCharaMissionManager.Function.UnInstallBomb);
		return UnInstallBomb(this, State);
	}
};
//==================================================================================================================================
class CGameUDPHandler
{
public:
	void WriteGameEvent_Fire (CGameCharaBase* Chara, D3DXVECTOR3* vTarget, CWeaponBase* WeaponBase)
	{
		typedef void (__thiscall* tWriteGameEvent_Fire) (CGameUDPHandler* Base, CGameCharaBase* Chara, D3DXVECTOR3* vTarget, CWeaponBase* WeaponBase);
		tWriteGameEvent_Fire WriteGameEvent_Fire = (tWriteGameEvent_Fire)(AddyStruct->GameUDPHandler.Function.WriteGameEvent_Fire);
		return WriteGameEvent_Fire(this, Chara, vTarget, WeaponBase);
	}
};
CGameUDPHandler* pGameUDPHandler = NULL;
//==================================================================================================================================
class CGameContext
{
public:

	CGameCharaMissionManager* getGameCharaMissionManager(void)
	{
		typedef CGameCharaMissionManager* (__thiscall* tgetGameCharaMissionManager)(CGameContext* Base);
		tgetGameCharaMissionManager getGameCharaMissionManager = (tgetGameCharaMissionManager)(AddyStruct->GameContext.Function.getGameCharaMissionManager);
		return getGameCharaMissionManager(this);
	}
	DWORD getMySlotIdx(void)
	{
		typedef DWORD (__thiscall * tgetMySlotIdx)(CGameContext* Base);
		tgetMySlotIdx getMySlotIdx = (tgetMySlotIdx)(AddyStruct->GameContext.Function.getMySlotIdx);
		return getMySlotIdx(this);
	}
	const char* getNickForSlot(int CharaIndex)
	{

		typedef const char* (__thiscall * tgetNickForSlot)(CGameContext* Base, int Index);
		tgetNickForSlot getNickForSlot = (tgetNickForSlot)(AddyStruct->GameContext.Function.getNickForSlot);
		return getNickForSlot(this,CharaIndex);
	}
	_NetCharaInfo* getNetCharaInfo(int CharaIndex)
	{
		typedef _NetCharaInfo* (__thiscall * tgetNetCharaInfo)(CGameContext* Base, int Index);
		tgetNetCharaInfo getNetCharaInfo = (tgetNetCharaInfo)(AddyStruct->GameContext.Function.getNetCharaInfo);
		return getNetCharaInfo(this,CharaIndex);
	}
	bool isRedTeam(int CharaIndex)
	{
		if(CharaIndex % 2 == 0)return true;
		else return false;
	}
	void setRankValue(int Index, BYTE RankValue)
	{
		*(BYTE*)(this + AddyStruct->GameContext.Pointer.Rank + (Index*AddyStruct->GameContext.Size.Rank)) = RankValue;
	}
	void setEvent (int EventIndex, const void* pArg, const void* a3,const void* a4, const char* a5, int a6)
	{
		typedef void (__thiscall* tsetEvent)(CGameContext* Base, int EventIndex, const void* pArg, const void* a3,const void* a4, const char* a5, int a6);
		tsetEvent setEvent = (tsetEvent)(AddyStruct->GameContext.Function.setEvent);
		return setEvent(this, EventIndex, pArg, a3, a4, a5, a6);
	}
	void SetAbuseCounter(bool bEnable, int Duration)
	{
		typedef void (__thiscall * tSetAbuseCounter)(CGameContext* Base, bool bEnable, int Duration);
		tSetAbuseCounter SetAbuseCounter = (tSetAbuseCounter)( AddyStruct->GameContext.Function.SetAbuseCounter );
		return SetAbuseCounter(this, bEnable, Duration);
	}
	void ResetAbuseCounter()
	{
		typedef void (__thiscall * tResetAbuseCounter)(CGameContext* Base);
		tResetAbuseCounter ResetAbuseCounter = (tResetAbuseCounter)( AddyStruct->GameContext.Function.ResetAbuseCounter );
		return ResetAbuseCounter(this);
	}
	void SetInviteUser(int Index)
	{
		typedef void (__thiscall * tSetInviteUser)(CGameContext* Base, int Index);
		tSetInviteUser SetInviteUser = (tSetInviteUser)( AddyStruct->GameContext.Function.SetInviteUser );
		return SetInviteUser(this, Index);
	}
	int GetChannelUserCount(int idxChannel)
	{
		typedef int (__thiscall * tGetChannelUserCount)(CGameContext* Base, int idxChannel);
		tGetChannelUserCount GetChannelUserCount = (tGetChannelUserCount)( AddyStruct->GameContext.Function.GetChannelUserCount );
		return GetChannelUserCount(this, idxChannel);
	}
	void SetChannelUserCount(int idxChannel, DWORD Count)
	{
		*(DWORD*)( this + AddyStruct->GameContext.Pointer.ChannelUserCount + (idxChannel * 4) ) = Count;
	}
	int GetMaxChannelUserCount()
	{
		typedef int (__thiscall * tGetMaxChannelUserCount)(CGameContext* Base);
		tGetMaxChannelUserCount GetMaxChannelUserCount = (tGetMaxChannelUserCount)( AddyStruct->GameContext.Function.GetMaxChannelUserCount );
		return GetMaxChannelUserCount(this);
	}
	void SetMaxChannelUserCount(DWORD Count)
	{
		*(DWORD*)( this + AddyStruct->GameContext.Pointer.MaxChannelUserCount ) = Count;
	}
};
CGameContext* pGameContext = NULL;
//==================================================================================================================================
class i3AIContext
{
public:

};
class CGameCharaAnimContext
{
public:
	i3AIContext* geti3AIContext(void)
	{
		return (i3AIContext*)*(DWORD*)(this + AddyStruct->XFHPB.Pointer.QuickChange);
	}
};
//==================================================================================================================================
class CWeaponBase
{
public:
	i3AIContext* geti3AIContext(void)
	{
		return (i3AIContext*)*(DWORD*)(this + AddyStruct->XFHPB.Pointer.NoReload);
	}

	void Reset()
	{
		typedef void (__thiscall * tReset)(CWeaponBase* Base);
		tReset Reset = (tReset)(AddyStruct->WeaponBase.Function.Reset);
		return Reset(this);
	}

	void doFire()
	{
		typedef void (__thiscall * tdoFire)(CWeaponBase* Base, int a1, int a2);
		tdoFire doFire = (tdoFire)(AddyStruct->WeaponBase.Function.DoFire);
		return doFire(this,false,false);
	}

	void doLineCollision(D3DXVECTOR3* Start, D3DXVECTOR3* End, DWORD a1)
	{
		typedef void (__thiscall * tdoLineCollision)(CWeaponBase* Base, D3DXVECTOR3* Start, D3DXVECTOR3* End, DWORD a1);
		tdoLineCollision doLineCollision = (tdoLineCollision)(AddyStruct->WeaponBase.Function.DoLineCollision);
		return doLineCollision(this,Start,End,a1);
	}

	DWORD getSubAmmoCount(void)
	{
		typedef DWORD (__thiscall * tgetSubAmmoCount)(CWeaponBase* Base);
		tgetSubAmmoCount getSubAmmoCount = (tgetSubAmmoCount)(AddyStruct->WeaponBase.Function.GetSubAmmoCount);
		return getSubAmmoCount(this);
	}

	void setSubAmmoCount(int Count)
	{
		typedef void (__thiscall * tsetSubAmmoCount)(CWeaponBase* Base, int Count);
		tsetSubAmmoCount setSubAmmoCount = (tsetSubAmmoCount)(AddyStruct->WeaponBase.Function.SetSubAmmoCount);
		return setSubAmmoCount(this,Count);
	}


};
//==================================================================================================================================
class CWeaponGrenade : public CWeaponBase
{
public:
	DWORD GetVirtualFunction(DWORD dwVFIndex)
	{
		return *(DWORD*)(*(DWORD*)(this) + dwVFIndex*4);
	}
	void _actionThrowGrenade()
	{

		typedef void (__thiscall * tAction001)(CWeaponGrenade* Base, D3DXVECTOR3* pOut, bool a2);
		typedef void (__thiscall * tAction002)(CWeaponGrenade* Base, int a1, D3DXVECTOR3* pOut, int a3);
		tAction001 Action001 = (tAction001)(this->GetVirtualFunction(100));
		tAction002 Action002 = (tAction002)(this->GetVirtualFunction(127));
		D3DXVECTOR3 pOut;
		Action001(this, &pOut, false);
		Action002(this, 0, &pOut, -1);
	}
	void onHitCharaByExplosion(CGameCharaBase* pHitUser, int CHARA_HIT_PART, D3DXVECTOR3* DirPos, D3DXVECTOR3* SrcPos)
	{
		typedef void (__thiscall * tonHitCharaByExplosion)(CWeaponBase* Base, CGameCharaBase* pHitUser, int CHARA_HIT_PART, D3DXVECTOR3* DirPos, D3DXVECTOR3* DstPos);
		tonHitCharaByExplosion onHitCharaByExplosion = (tonHitCharaByExplosion)(GetVirtualFunction(67));
		return onHitCharaByExplosion(this, pHitUser, CHARA_HIT_PART, DirPos, SrcPos);
	}
};
//==================================================================================================================================
class CGameCharaWeaponContext
{
public:
	CWeaponBase* getWeapon(int WeaponIndex)
	{
		typedef CWeaponBase* (__thiscall * tSafeGetWeapon)(CGameCharaWeaponContext* Base, int WeaponIndex);
		tSafeGetWeapon SafeGetWeapon = (tSafeGetWeapon)(AddyStruct->GameCharaWeaponContext.Function.SafeGetWeapon);
		return SafeGetWeapon(this,WeaponIndex);
	}
	CWeaponBase* getCurrentWeapon(void)
	{
		typedef CWeaponBase* (__thiscall * tgetCurrentWeapon)(CGameCharaWeaponContext* Base);
		tgetCurrentWeapon getCurrentWeapon = (tgetCurrentWeapon)(AddyStruct->GameCharaWeaponContext.Function.getCurrent);
		return getCurrentWeapon(this);
	}

	DWORD getCurrentWeaponIndex(void)
	{
		if(AddyStruct->GameCharaWeaponContext.Function.DecryptWeaponIndex > NULL){
			typedef DWORD (__thiscall * tDecryptWeaponIndex)(CGameCharaWeaponContext* Base);
			tDecryptWeaponIndex DecryptWeaponIndex = (tDecryptWeaponIndex)AddyStruct->GameCharaWeaponContext.Function.DecryptWeaponIndex;
			return DecryptWeaponIndex(this + AddyStruct->GameCharaWeaponContext.Pointer.CurrentWeaponIndex);
		}
		else return *(DWORD*)(this + AddyStruct->GameCharaWeaponContext.Pointer.CurrentWeaponIndex);
	}
};
//==================================================================================================================================
class CGameCharaBoneContext
{
public:
	CWeaponProperty* getWeaponProperty()
	{
		return (CWeaponProperty*)(this + 0x74);
	}

	void setCrosshairPitch(float value)
	{
		typedef void (__thiscall * tEncryptWrite)(CGameCharaBoneContext* Base,float value);
		tEncryptWrite EncryptWrite = (tEncryptWrite)(AddyStruct->GameCharaBoneContext.Function.writePitch);
		return EncryptWrite(this,value);
	}
	void setCrosshairYaw(float value)
	{
		typedef void (__thiscall * tEncryptWrite)(CGameCharaBoneContext* Base,float value);
		tEncryptWrite EncryptWrite = (tEncryptWrite)(AddyStruct->GameCharaBoneContext.Function.writeYaw);
		return EncryptWrite(this,value);
	}

	DWORD getBones()
	{
		typedef DWORD (__thiscall * tgetBones)(CGameCharaBoneContext* Base);
		tgetBones getBones = (tgetBones)(AddyStruct->GameCharaBoneContext.Function.getBones);
		return (getBones(this) - AddyStruct->GameCharaBoneContext.Size.BonesAlign);
	}
	D3DXVECTOR3 getBonePosition(int BoneIndex)
	{
		D3DXMATRIX *pBone = (D3DXMATRIX*)(this->getBones());
		return D3DXVECTOR3(pBone[ BoneIndex ]._41, pBone[ BoneIndex ]._42, pBone[ BoneIndex ]._43);
	}

};
class CWeaponProperty
{
public:
	DWORD RecoilV1; // 0x74
	DWORD RecoilV2; // 0x78
	DWORD RecoilH1; // 0x7C
	DWORD RecoilH2; // 0x80 << freeze
	DWORD RecoilH3; // 0x84 << freeze
	char pad2[0x20]; // 0x88
	DWORD Deviation1; // 0xA8
	DWORD Deviation2; // 0xAC
	DWORD Deviation3; // 0xB0
};
//==================================================================================================================================
class CGameCharaCollisionContext
{
public:
	CGameCharaBase* GetCrosshairTarget()
	{
		typedef DWORD (__thiscall * tReadData)(DWORD BaseData);
		tReadData ReadData = (tReadData)(AddyStruct->GameCharaCollisionContext.Function.ReadData);

		return (CGameCharaBase*)ReadData((DWORD)this + AddyStruct->GameCharaCollisionContext.Pointer.CrosshairTarget);
	}
};
//==================================================================================================================================
class CGameCharaBase
{
public:
	CGameCharaBase* getLocalChara()
	{
		return (CGameCharaBase*)(oReadBaseValue(AddyStruct->GameCharaBase.Base));
	}
	CGameCharaBoneContext* getGameCharaBoneContext(void)
	{
		typedef CGameCharaBoneContext* (__thiscall * tgetGameCharaBoneContext)(CGameCharaBase* Base);
		tgetGameCharaBoneContext getGameCharaBoneContext = (tgetGameCharaBoneContext)(AddyStruct->GameCharaBase.Function.getGameCharaBoneContext);
		return getGameCharaBoneContext(this);
	}
	CGameCharaWeaponContext* getGameCharaWeaponContext(void)
	{
		typedef CGameCharaWeaponContext* (__thiscall * tgetGameCharaWeaponContext)(CGameCharaBase* Base);
		tgetGameCharaWeaponContext getGameCharaWeaponContext = (tgetGameCharaWeaponContext)(AddyStruct->GameCharaBase.Function.getGameCharaWeaponContext);
		return getGameCharaWeaponContext(this);
	}
	CGameCharaCollisionContext* getGameCharaCollisionContext(void)
	{
		typedef CGameCharaCollisionContext* (__thiscall * tgetGameCharaCollisionContext)(CGameCharaBase* Base);
		tgetGameCharaCollisionContext getGameCharaCollisionContext = (tgetGameCharaCollisionContext)(AddyStruct->GameCharaBase.Function.getGameCharaCollisionContext);
		return getGameCharaCollisionContext(this);
	}
	CGameCharaAnimContext* getGameCharaAnimContext(void)
	{
		typedef CGameCharaAnimContext* (__thiscall * tgetGameCharaAnimContext)(CGameCharaBase* Base);
		tgetGameCharaAnimContext getGameCharaAnimContext = (tgetGameCharaAnimContext)(AddyStruct->GameCharaBase.Function.getGameCharaAnimContext);
		return getGameCharaAnimContext(this);
	}

	void ShowCharacterNick(bool a1)
	{
		typedef void (__thiscall * tShowCharacterNick)(CGameCharaBase* Base, bool a1);
		tShowCharacterNick ShowCharacterNick = (tShowCharacterNick)(AddyStruct->GameCharaBase.Function.ShowCharacterNick);
		return ShowCharacterNick(this, a1);
	}

	void setCharaWeapon(unsigned int WeaponSlot, unsigned int WeaponType, unsigned int WeaponIndex)
	{
		typedef void (__thiscall * tsetCharaWeapon)(CGameCharaBase* Base, unsigned int WeaponSlot, unsigned int WeaponType, unsigned int WeaponIndex);
		tsetCharaWeapon setCharaWeapon = (tsetCharaWeapon)(AddyStruct->GameCharaBase.Function.setCharaWeapon);
		return setCharaWeapon(this, WeaponSlot, WeaponType, WeaponIndex);
	}
	void Cmd_Respawn(D3DXVECTOR3* RespawnPos)
	{
		typedef void (__thiscall * tCmd_Respawn)(CGameCharaBase* Base, D3DXVECTOR3* RespawnPos);
		tCmd_Respawn Cmd_Respawn = (tCmd_Respawn)(AddyStruct->GameCharaBase.Function.Cmd_Respawn);
		return Cmd_Respawn(this, RespawnPos);
	}

	void eventFall(int numDmg)
	{
		typedef void (__thiscall * teventFall)(CGameCharaBase* Base, int a1, int a2, bool a3);
		teventFall eventFall = (teventFall)(AddyStruct->GameCharaBase.Function.eventFall);
		return eventFall(this, numDmg, numDmg, false);
	}
	float getInvicibleTime()
	{
		typedef float (__thiscall * tReadData)(DWORD BaseData);
		tReadData ReadData = (tReadData)(AddyStruct->GameCharaBase.Function.readData);
		return ReadData((DWORD)this + AddyStruct->GameCharaBase.Pointer.invicibleTime);
	}
	void setInvicibleTime(float invicibleTime)
	{
		typedef void (__thiscall * tWriteData)(DWORD BaseData, float InputValue);
		tWriteData WriteData = (tWriteData)(AddyStruct->GameCharaBase.Function.writeData);
		WriteData((DWORD)this + AddyStruct->GameCharaBase.Pointer.invicibleTime, invicibleTime);
	}
	int getCharaNetIndex(void)
	{
		typedef int (__thiscall * tgetCharaNetIndex)(CGameCharaBase* Base);
		tgetCharaNetIndex getCharaNetIndex = (tgetCharaNetIndex)(AddyStruct->GameCharaBase.Function.getCharaNetIdx);
		if(this == NULL)return -1;
		return getCharaNetIndex(this);
	}
	const char* getNickname(void)
	{
		return pGameContext->getNickForSlot(this->getCharaNetIndex());	
	}
	int getCurHP(void)
	{
		typedef int (__thiscall * tgetCurHP)(CGameCharaBase* Base);
		tgetCurHP getCurHP = (tgetCurHP)(AddyStruct->GameCharaBase.Function.getCurHP);
		return getCurHP(this);
	}
	bool isAlive(void)
	{
		return( this->getCurHP() > 0 );
	}
	bool isLocal(void)
	{
		return ( this->getCharaNetIndex() == pGameContext->getMySlotIdx() );
	}
	bool isEnemy(void)
	{
		return (pGameContext->isRedTeam(this->getCharaNetIndex()) != pGameContext->isRedTeam(pGameContext->getMySlotIdx()));
	}
	bool isVisible(int BoneTargetIndex)
	{
		D3DXVECTOR3 vLocal = this->getLocalChara()->getGameCharaBoneContext()->getBonePosition(5);
		D3DXVECTOR3 vTarget = this->getGameCharaBoneContext()->getBonePosition(BoneTargetIndex);

		vLocal.y += 0.1f;

		i3CollideeLine Line;
		i3CollideeLine_Initialize(&Line);
		i3CollideeLine_SetStart(&Line,&vLocal);
		i3CollideeLine_SetEnd(&Line,&vTarget);

		i3PhysixResult* pResult = pGameFramework->RaycastClosest(&Line,NULL);
		if(!pResult)return false;

		return(pResult->GetDistanceResult() >= DistanceBetweenVector(vTarget,vLocal));
	}
	DWORD GetTeamColor()
	{
		if(this->isEnemy())return RED;
		return SKYBLUE;
	}
	DWORD GetPlayerColor()
	{
		if(this->isEnemy())return GREEN;
		return WHITE;
	}
};
//==================================================================================================================================
class CGameCharaManager 
{
public:
	CGameCharaBase* getCharaByNetIdx(int CharaIndex)
	{
		typedef CGameCharaBase* (__thiscall * tgetCharaByNetIdx)(CGameCharaManager* Base, int Index);
		tgetCharaByNetIdx getCharaByNetIdx = (tgetCharaByNetIdx)(AddyStruct->GameCharaManager.Function.getCharaByNetIdx);
		return getCharaByNetIdx(this, CharaIndex);
	}
	CGameCharaBase* getCharaByNickname(char* szNickname)
	{
		for(int i = 0; i <= 15; i++)
		{
			CGameCharaBase* Chara = getCharaByNetIdx(i);
			if(!strcmp(Chara->getNickname(), szNickname))
			{
				return Chara;
			}
		}
		return NULL;
	}
	void SetCharaWeaponSet(CGameCharaBase* Chara, _NetCharaInfo* CharaInfo)
	{
		typedef void (__thiscall * tSetCharaWeaponSet)(CGameCharaManager* Base, CGameCharaBase* Chara, _NetCharaInfo* CharaInfo);
		tSetCharaWeaponSet SetCharaWeaponSet = (tSetCharaWeaponSet)(AddyStruct->GameCharaManager.Function.SetCharaWeaponSet);
		return SetCharaWeaponSet(this, Chara, CharaInfo);
	}
	void SetCharaWeaponSetWithoutLock(CGameCharaBase* Chara, _NetCharaInfo* CharaInfo)
	{
		for(int i = 0; i < 5; i++)
			Chara->setCharaWeapon(i, CharaInfo->getWeaponValue(i).WeaponType(), CharaInfo->getWeaponValue(i).WeaponIndex());
	}
	void RespawnChara(int Index, bool State)
	{
		typedef void (__thiscall * tRespawnChara)(CGameCharaManager* Base, int Index, bool State);
		tRespawnChara RespawnChara = (tRespawnChara)(AddyStruct->GameCharaManager.Function.RespawnChara);
		return RespawnChara(this, Index, State);
	}
	CGameCharaBase* getLocalChara(void)
	{
		return (CGameCharaBase*)(oReadBaseValue(AddyStruct->GameCharaBase.Base));
	}
	CGameCharaBase* getCharaToAim(void)
	{
		CGameCharaBase* Result = NULL;
		float Farthest = 1000.0f;
		for(int i = 0; i <= 15; i++)
		{
			CGameCharaBase* Chara = this->getCharaByNetIdx(i);
			if(Chara)
			{
				if(Chara->isEnemy() == false)continue;
				if(Chara->isAlive() == false)continue;
				if(Chara->isVisible(BoneIndexSelector) == false)continue;
				float PawnDistanceFromLocalPawn = DistanceBetweenVector( Chara->getGameCharaBoneContext()->getBonePosition(0), this->getLocalChara()->getGameCharaBoneContext()->getBonePosition(0) );
				if(PawnDistanceFromLocalPawn < Farthest)
				{
					Farthest = PawnDistanceFromLocalPawn;
					Result = Chara;
				}
			}
		}
		return Result;
	}
	bool isValidChara(int CharaIndex)
	{
		return( this->getCharaByNetIdx(CharaIndex) > NULL );
	}
	bool allPlayerAlive(void){
		for(int i = 0; i<=15; i++)
		{
			if(this->isValidChara(i) && !this->getCharaByNetIdx(i)->isAlive())
			{
				return false;
			}
		}
		return true;
	}
	bool allEnemyAlive(void)
	{
		for(int i = 0; i<=15; i++)
		{
			if(this->isValidChara(i) && !this->getCharaByNetIdx(i)->isAlive() && this->getCharaByNetIdx(i)->isEnemy())
			{
				return false;
			}
		}
		return true;
	}
	bool allPlayerDead(void){
		for(int i = 0; i<=15; i++)
		{
			if(this->isValidChara(i) && this->getCharaByNetIdx(i)->isAlive())
			{
				return false;
			}
		}
		return true;
	}
	bool allEnemyDead(void)
	{
		for(int i = 0; i<=15; i++)
		{
			if(this->isValidChara(i) && this->getCharaByNetIdx(i)->isAlive() && this->getCharaByNetIdx(i)->isEnemy())
			{
				return false;
			}
		}
		return true;
	}
};
CGameCharaManager* pGameCharaManager = NULL;
//==================================================================================================================================
class sReplaceWeapon
{
public:
	char* Name;
	DWORD Value;
	sReplaceWeapon(char* Name, DWORD Value)
	{
		this->Name = Name;
		this->Value = Value;
	}
};

class cReplaceWeapon
{
public:
	vector<sReplaceWeapon> ReplaceList;
	void AddData(char* Name, DWORD Value)
	{
		sReplaceWeapon NewWeapon(Name, Value);
		ReplaceList.push_back(NewWeapon);
	}
	char* GetNameByIndex(int Index)
	{
		return ReplaceList[Index].Name;
	}
	DWORD GetValueByIndex(int Index)
	{
		return ReplaceList[Index].Value;
	}
};
cReplaceWeapon* ReplaceWeapon;
char* ReplaceCallback(int Index)
{
	return ReplaceWeapon->GetNameByIndex(Index);
}
//==================================================================================================================================
CWeaponBase* LocalCharaWeapon = NULL;
CGameCharaBase* LocalChara = NULL;
//==================================================================================================================================
bool ClassReady = false;
//==================================================================================================================================
void UpdateClass()
{

	// Read Render Context
	if(IsBadReadPtr((void*)pRenderContext,4)) pRenderContext = (CRenderContext*)( *(DWORD*)(AddyStruct->RenderContext.Base) );
	// Read CGameContext
	if(IsBadReadPtr((void*)pGameContext,4)) pGameContext = (CGameContext*)( oReadBaseValue(AddyStruct->GameContext.Base) );
	// Read CGameCharaManager
	if(IsBadReadPtr((void*)pGameCharaManager,4))pGameCharaManager = (CGameCharaManager*)( oReadBaseValue(AddyStruct->GameCharaManager.Base) );
	// Read CGameFramework
	if(IsBadReadPtr((void*)pGameFramework,4))pGameFramework = (CGameFramework*)( oReadBaseValue(AddyStruct->GameFramework.Base) );
	// Read CGameUDPHandler
	if(IsBadReadPtr((void*)pGameUDPHandler,4)){
		typedef CGameUDPHandler* (__stdcall * tgetGameUDPHandler)();
		tgetGameUDPHandler getGameUDPHandler = (tgetGameUDPHandler)(AddyStruct->GameUDPHandler.Function.GetBase);
		pGameUDPHandler = (CGameUDPHandler*)(getGameUDPHandler());
	}
	// Read LocalChara & LocalCharaWeapon
	LocalChara = (CGameCharaBase*)( oReadBaseValue(AddyStruct->GameCharaBase.Base) );
	if(!IsBadReadPtr((void*)LocalChara,4)){
		LocalCharaWeapon = LocalChara->getGameCharaWeaponContext()->getCurrentWeapon();
	}

	if(!ClassReady){
		ReplaceWeapon = new cReplaceWeapon;
		ClassReady = true;
	}
	

}
