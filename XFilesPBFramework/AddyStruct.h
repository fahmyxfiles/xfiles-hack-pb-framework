struct sAddyStruct
{
	//=======================================================================================================
	struct
	{
		struct 
		{
			DWORD ReadBaseValue;
			DWORD ReadConfig;
			DWORD USGBypassMD5Check;
			DWORD USGBypassFileSizeCheck;
			DWORD ShowMessageBox;
		}Function;

		struct
		{
			DWORD i3CollideeLine_SetEnd;
			DWORD i3AiContext_getLocalTime;
			DWORD i3RenderContext_EndRender;
			DWORD i3RenderContext_DrawIndexedPrim;
		}Import;

		struct
		{
			struct {
				DWORD GaugeMultiplier;
			}Values;

			struct
			{
				DWORD Burst;
			}Hook;
		
			struct
			{
				DWORD Burst;
			}Modify;

		}Address;

		struct
		{
			DWORD QuickChange;
			DWORD NoReload;
			DWORD FireSpeed;
		}Pointer;
	
	}XFHPB;
	//=======================================================================================================
	struct
	{
		DWORD Base;

		struct
		{
			DWORD GetProjectMatrix;
			DWORD GetViewMatrix;
			DWORD GetWorldMatrix;
		}Function;

	}RenderContext;
	//=======================================================================================================
	struct
	{

		DWORD Base;
		
		struct
		{
			DWORD getNickForSlot;
			DWORD getNetCharaInfo;
			DWORD getGameInfo_Chara;
			DWORD getMySlotIdx;
			DWORD setEvent;
			DWORD getGameCharaMissionManager;
			DWORD ResetAbuseCounter;
			DWORD SetAbuseCounter;
			DWORD SetInviteUser;
			DWORD GetChannelUserCount;
			DWORD GetMaxChannelUserCount;
		}Function;
		
		struct
		{
			DWORD Rank;
			DWORD ChannelUserCount;
			DWORD MaxChannelUserCount;
		}Pointer;
		
		struct
		{
			DWORD Rank;
		}Size;

	}GameContext;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD SelfRemoveFromRoom;
		}Function;

	}PhaseReadyRoom;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD InstallBomb;
			DWORD UnInstallBomb;
		}Function;

	}GameCharaMissionManager;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD getWeaponValue;
			DWORD setWeaponValue;
		}Function;

		struct
		{
			DWORD Weapon;
		}Pointer;

	}_NetCharaInfo;
	//=======================================================================================================
	struct
	{
		struct
		{
			DWORD GetTranslatedName;
		}Function;
	}WeaponInfo;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD GetBase;
			DWORD WriteGameEvent_Fire;
		}Function;

	}GameUDPHandler;
	//=======================================================================================================
	struct
	{

		DWORD Base;

		struct
		{
			DWORD getCharaByNetIdx;
			DWORD SetCharaWeaponSet;
			DWORD RespawnChara;
		}Function;

	}GameCharaManager;
	//=======================================================================================================
	struct
	{
		
		DWORD Base;

		struct
		{
			DWORD RaycastClosest;
		}Function;

		struct
		{
			DWORD I3InputMouse;
			DWORD I3InputKeyboard;
		}Pointer;

		struct
		{
			struct
			{
			}Function;
		}I3InputMouse;

		struct
		{
			struct
			{
			}Function;
		}I3InputKeyboard;

	}GameFramework;
	//=======================================================================================================
	struct 
	{
		struct
		{
			DWORD GetX;
			DWORD GetY;
			DWORD GetZ;
			DWORD GetDeltaX;
			DWORD GetDeltaY;
			DWORD GetDeltaZ;
			DWORD GetButtonState;
			DWORD GetStrokeButtonState;
		}Function;
	}i3InputMouse;
	//=======================================================================================================
	struct
	{
		struct
		{
			DWORD GetPressState;
			DWORD GetRepeatState;
			DWORD GetStrokeState;
			DWORD SetPressState;
			DWORD SetStrokeState;
		}Function;
	}i3InputKeyboard;
	//=======================================================================================================
	struct
	{
		DWORD Base;
		struct
		{
			DWORD getWeaponInfo;
		}Function;
	}WeaponInfoDatabase;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD ReadData;
		}Function;

		struct
		{
			DWORD Distance;
		}Pointer;

	}PhysixResult;
	struct
	{
		struct
		{
			DWORD Initialize;
			DWORD SetStart;
			DWORD SetEnd;
		}Function;
	}i3CollideeLine;
	//=======================================================================================================
	struct
	{

		DWORD Base;

		struct
		{
			DWORD getGameCharaBoneContext;
			DWORD getGameCharaWeaponContext;
			DWORD getGameCharaCollisionContext;
			DWORD getGameCharaHUDContext;
			DWORD getGameCharaAnimContext;
			DWORD getCharaNetIdx;
			DWORD ShowCharacterNick;
			DWORD setCharaWeapon;
			DWORD Cmd_Respawn;
			DWORD eventFall;
			DWORD getCurHP;
			DWORD writeData;
			DWORD readData;
		}Function;

		struct
		{
			DWORD invicibleTime;
		}Pointer;

	}GameCharaBase;
	//=======================================================================================================
	struct
	{
		
		struct
		{
			DWORD ReadData;
		}Function;

		struct
		{
			DWORD CrosshairTarget;
		}Pointer;

	}GameCharaCollisionContext;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD writeYaw;
			DWORD writePitch;
			DWORD getBones;
		}Function;

		struct
		{
			DWORD BonesAlign;
		}Size;

	}GameCharaBoneContext;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD getCurrent;
			DWORD DecryptWeaponIndex;
			DWORD SafeGetWeapon;
		}Function;

		struct
		{
			DWORD CurrentWeaponIndex;
		}Pointer;

	}GameCharaWeaponContext;
	//=======================================================================================================
	struct
	{

		struct
		{
			DWORD Reset;
			DWORD GetSubAmmoCount;
			DWORD SetSubAmmoCount;
			DWORD DoFire;
			DWORD DoLineCollision;
		}Function;

	}WeaponBase;
};




sAddyStruct* AddyStruct = NULL;

void InitAddyStruct()
{
	AddyStruct = new sAddyStruct;
	ZeroMemory(AddyStruct, sizeof(sAddyStruct));
}