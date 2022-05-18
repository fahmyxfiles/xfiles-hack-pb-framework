struct sFeatureStruct
{
	struct 
	{
		struct sDirect3D
		{
			int WallHack;
			int CrossHair;
			int Charms;
			int NoSmoke;
			int NoFog;
		}Direct3D;

		struct sESP
		{
			int Team;
			int Name;
			int Head;
			int HealthBar;
			int Line;
			int Bone;
		}ESP;
	}Visual;

	struct
	{
		struct
		{
			int Mode;
			int Target;
			int Hotkey;
			int HotkeyMode;
		}Assist;

		struct
		{
			int SkillUp;
			int ResetWeapon;
			int Reborn;
			int FreeMove;
			int PlantDefuse;
			int HealthAbsorber;
			int AutoHeadshot;
			int AlwaysInvicible;
		}Player;

		struct
		{
			int QuickChange;
			int AutoFillSubAmmo;
			int SkipReload;
			int NoRecoil;
			int FireSpeed;
			int RapidFire;
			int AutoFire;
		}Weapon;

		struct
		{
			int ResetAbuse;
			int BypassServerFull;
			int BypassRoomPassword;
			int AntiKick;
			int AutoInviteRoom;
			int KickAllPlayer;
		}Misc;

		struct
		{
			int AutoKiller;
			int FastKiller;
			int ExplosiveKiller;
		}Brutal;
	}GameHack;
};

sFeatureStruct* FeatureStruct = NULL;

void InitFeatureStruct()
{
	FeatureStruct = new sFeatureStruct;
	ZeroMemory(FeatureStruct, sizeof(sFeatureStruct));
}