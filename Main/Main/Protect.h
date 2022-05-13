// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomCloak.h"
#include "CustomEventTime.h"
#include "CustomEarthQuakeSkill.h"
#include "CustomFog.h"
#include "CustomGloves.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomItemPosition.h"
#include "CustomJewel.h"
#include "CustomLuckyWheel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomPet.h"
#include "CustomPetEffect.h"
#include "CustomServerInfo.h"
#include "CustomWing.h"
#include "ItemSmoke.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "CustomBow.h"
#include "ItemAsm.h"
#include "CustomJewelBank.h"
#include "ItemTooltip.h"
#include "PetGlow.h"
#include "RenderExcGlow.h"
#include "SceneControl.h"
#include "CustomServerInfo.h"
#include "PetEffectDynamic.h"
#include "BuffIcon.h"
#include "ModelEffect.h"
#include "QuickCommandWindow.h"

struct MAIN_FILE_INFO
{
	BYTE LauncherType; 
	char LauncherName[32];
	char CustomerName[32];
	char IpAddress[32];
	WORD IpAddressPort;
	char ClientVersion[8];
	char ClientSerial[17];
	char WindowName[32];
	char ScreenShotPath[50];
	char ClientName[32];
	char PluginName1[32];
	char PluginName2[32];
	char PluginName3[32];
	char PluginName4[32];
	char PluginName5[32];
	char CameraName[32];
	DWORD ClientCRC32;
	DWORD Plugin1CRC32;
	DWORD Plugin2CRC32;
	DWORD Plugin3CRC32;
	DWORD Plugin4CRC32;
	DWORD Plugin5CRC32;
	DWORD CameraCRC32;
	DWORD HelperActiveAlert;
	DWORD HelperActiveLevel;
	DWORD DWMaxAttackSpeed;
	DWORD DKMaxAttackSpeed;
	DWORD FEMaxAttackSpeed;
	DWORD MGMaxAttackSpeed;
	DWORD DLMaxAttackSpeed;
	DWORD SUMaxAttackSpeed;
	DWORD RFMaxAttackSpeed;
	DWORD ReconnectTime;
	DWORD ItemLevel_15;
	DWORD ReduceMemory;
	DWORD RankUserType;
	DWORD LevelDelete;
	DWORD CustomSCharAnimate;
	DWORD HelperAndInventory;
	DWORD InventoryAdvanced;
	DWORD PostItem;
	DWORD CsSkill; 
	DWORD DisableReflectEffect;
	DWORD EnableVipShop;
	DWORD VipTypes;
	DWORD PrintLogo;
	DWORD CustomMenuSwitch;
	DWORD CustomMenuType;
	DWORD EnableEventTimeButton;
	DWORD EnableVipShopButton;
	DWORD EnableRankingButton;
	DWORD EnableCommandButton;
	DWORD EnableOptionButton;
	DWORD EnableCoinStatus;
	DWORD EnableShopValueSystem;
	DWORD CustomStoreEnableJoB;
	DWORD CustomStoreEnableJoS;
	DWORD CustomStoreEnableJoC;
	DWORD CustomStoreEnableCoin1;
	DWORD CustomStoreEnableCoin2;
	DWORD CustomStoreEnableCoin3;
	DWORD CustomOffStoreEnable;
	DWORD CustomMonsterEnable;
	DWORD LimitTransferZen;
	DWORD DisablePartyHpBar;
	DWORD RankUserShowOverHead;
	DWORD RankUserOnlyOnSafeZone;
	DWORD RankUserShowReset;
	DWORD RankUserShowMasterReset;
	DWORD RankUserNeedAltKey;
	DWORD HelperUpgradeSystem;
	DWORD SelectCharacterSystem;
	DWORD StatsAdvanced;
	DWORD JewelBankSwitch;
	DWORD LuckyWheelSwitch;
	DWORD CustomInterfaceType;
	DWORD SelectCharacterType;
	DWORD SelectServerType;
	DWORD MoveClassic;
	DWORD MasterSkillTree;
	DWORD RemoveClickEffect;
	DWORD MenuFastAltClick;
	DWORD InventoryExpanded;
	DWORD WarehouseExpanded;
	DWORD GensBattleWindow;
	DWORD FastMenuKeyU;
	DWORD SelectBarExp;
	DWORD HelperActive;
	DWORD HelperInterface;
	DWORD ChaosMachineItem380Switch;//
	DWORD OptionsEventsMasterSwitch;
	DWORD ButtonsSelectServer;
	DWORD SelectServerOld;
	DWORD DisableKeyM;
	DWORD DisableKeyS;
	DWORD DisableKeyD;
	DWORD DisableKeyF;
	DWORD DisableKeyX;
	DWORD RemoveClass;
	DWORD GuildMasterButtonsPosition;
	DWORD PlayerShowName;
	DWORD PlayerShowGuildLogo;
	DWORD MultiCharacterEnable;
	WORD gMaxGameInstances;
	DWORD SceneCharacterDowngradeType;
	DWORD MessageChatRemakeType;
	DWORD m_MuunInventorySystem;
	DWORD m_HelperActiveOfflineSystem;
	DWORD m_CustomCapeSystem; 
	DWORD m_CustomBowsSystem; 
	DWORD m_CustomFogSystem;
	DWORD m_RemoveGlowSystem;
	DWORD m_ItemPositionSystem;
	DWORD m_GlovesRFSystem;
	DWORD m_PetCustomSystem;
	DWORD m_PetEffectSystem;
	DWORD m_EarthQuakeSystem;
	DWORD m_CashShopSafezone;
	DWORD m_StatusRealView;
	DWORD m_FpsMonitor;
	DWORD m_LimitFPS;
	CUSTOM_MESSAGE_INFO EngCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO PorCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_MESSAGE_INFO SpnCustomMessageInfo[MAX_CUSTOM_MESSAGE];
	CUSTOM_JEWEL_INFO CustomJewelInfo[MAX_CUSTOM_JEWEL];
	CUSTOM_WING_INFO CustomWingInfo[MAX_CUSTOM_WING];
	CUSTOM_ITEM_INFO CustomItemInfo[MAX_CUSTOM_ITEM];
	CUSTOM_WING_EFFECT_INFO CustomWingEffectInfo[MAX_CUSTOM_WING_EFFECT];
	DYNAMIC_WING_EFFECT_INFO DynamicWingEffectInfo[MAX_DYNAMIC_WING_EFFECT];
	CUSTOM_BUYVIP_INFO CustomBuyVipInfo[MAX_CUSTOM_BUYVIP];
	CUSTOM_COMMAND_INFO CustomCommandInfo[MAX_CUSTOM_COMMAND];
	CUSTOM_EVENT_INFO CustomEventInfo[MAX_EVENTTIME];
//	CUSTOM_DESCRIPTION_INFO CustomDescriptionInfo[MAX_CUSTOM_DESCRIPTION];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];	
	//NEW CUSTOM MONSTER
    CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	//PETS
	CUSTOM_PET_INFO CustomPetInfo[MAX_PET_ITEM];
	PET_EFFECT_CUSTOM m_CustomPetCEffect[max_ceffect]; //PETEFFECT
	//PETS F
	CUSTOM_RF_GLOVES m_CustomGlovesInfo[MAX_CUSTOM_GLOVES];
	CUSTOM_BOW_INFO CustomBowInfo[MAX_CUSTOM_BOW];
	CUSTOMCLOAK_DATA m_CustomCloak[MAX_CUSTOMCLOAK];
	CUSTOM_POSITION_INFO CustomPositionInfo[MAX_POSITION_ITEM];
	//LUCKY WHEEL
	LUCKYWHEEL_INFO CustomLuckyWheel[MAX_ITEM_LUCKY];
	//HORSE
	HORSE_EARTH_QUAKE m_EarthQuakeLoad[MAX_EARTH_QUAKE];
	//JEWEL_BANK m_JewelBank [MAX_JEWELBANK];
	nInformation m_TRSTooltipData[MaxLine];
	nText m_TRSTooltipText[MaxLine];
	RENDER_MESH RenderMeshPet[MAX_RENDER_MESH];
	JCItemnoGlow m_JCWRemoveGlow[ MAX_NOGLOW ]; //excellent glow
	SelectChar m_RenderSelect[MAX_WORLD_SETTINGS];
	SelectSrv m_RenderSelectSrv[MAX_WORLD_SETTINGS];
	SERVERINFO_DATA m_ServerInfo[MAX_SERVER_CLASS];
	PET_DYNAMIC_CUSTOM m_DynamicPetEffect[max_ceffectdin];
	//
	RenderTooltipBuff m_TooltipTRSDataEng[256];
	RenderTooltipBuff m_TooltipTRSDataSpn[256];
	RenderTooltipBuff m_TooltipTRSDataPor[256];
	CUSTOM_MODEL_EFFECT_INFO m_CustomModelInfo[MAX_MODEL_EFFECT];
};

class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool ReadMainFile(char* name);
	void CheckLauncher();
	void CheckInstance();
	void CheckClientFile();
	void CheckPlugin1File();
	void CheckPlugin2File();
	void CheckPlugin3File();
	void CheckPlugin4File();
	void CheckPlugin5File();
	void CheckCameraFile();
	bool IsProcessRunning(const char *ProcessName, int maxProcess);
public:
	MAIN_FILE_INFO m_MainInfo;
	DWORD m_ClientFileCRC;
};

extern CProtect gProtect;