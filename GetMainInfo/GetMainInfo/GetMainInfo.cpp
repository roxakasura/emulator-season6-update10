#include "stdafx.h"
#include "..\..\Util\CCRC32.H"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomCloak.h"
#include "CustomEventTimeText.h"
#include "CustomGloves.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomItemPosition.h"
#include "CustomJewel.h"
#include "CustomLuckyWheel.h"
#include "CustomMessage.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomServerInfo.h"
#include "CustomPet.h"
#include "CustomPetEffect.h"
#include "CustomWing.h"
#include "CustomWIngEffect.h"
#include "CustomEffectDynamic.h"
#include "CustomEarthQuakeSkill.h"
#include "SmokeEffect.h"
#include "ThemidaSDK.h"
#include "Fog.h" 
#include "CustomCrossBow.h"
#include "CustomJewelBank.h"
#include "ItemToolTip.h"
#include "PetGlow.h"
#include "RemoveExcGlow.h"
#include "SceneControl.h"
#include "PetEffectDynamic.h"
#include "direct.h"
#include "TooltipBuff.h"
#include "ModelEffect.h"

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
	char CameraName[32];
	char PluginName1[32];
	char PluginName2[32];
	char PluginName3[32];
	char PluginName4[32];
	char PluginName5[32];
	DWORD ClientCRC32;
	DWORD CameraCRC32;
	DWORD Plugin1CRC32;
	DWORD Plugin2CRC32;
	DWORD Plugin3CRC32;
	DWORD Plugin4CRC32;
	DWORD Plugin5CRC32;
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
	DWORD DisablePartyHpBar;
	DWORD LimitTransferZen;
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
//	CUSTOM_DESCRIPTION_INFO CustomDescriptionInfo[MAX_DESCRIPTION_ITEM];
	CUSTOM_SMOKEEFFECT CustomSmokeEffect[MAX_SMOKE_ITEMS];
	CUSTOM_FOG CustomFog[MAX_FOG];
    CUSTOMMONSTER_DATA CustomMonsters[MAX_CUSTOMMONSTER];
	NPCNAME_DATA CustomNPCName[MAX_CUSTOM_NPCNAME];
	CUSTOM_PET_INFO CustomPetInfo[MAX_PET_ITEM];
	PET_EFFECT_CUSTOM m_CustomPetCEffect[max_ceffect];
	CUSTOM_RF_GLOVES m_CustomGlovesInfo[MAX_CUSTOM_GLOVES];
	CUSTOM_BOW_INFO CustomBowInfo[MAX_CUSTOM_BOW];
	CUSTOMCLOAK_DATA m_CustomCloak[MAX_CUSTOMCLOAK];
	CUSTOM_POSITION_INFO CustomPositionInfo[MAX_POSITION_ITEM];
	LUCKYWHEEL_INFO CustomLuckyWheel[MAX_ITEM_LUCKY];
	HORSE_EARTH_QUAKE m_EarthQuake[MAX_EARTH_QUAKE];
	nInformation m_TRSTooltipData[MaxLine];
	nText m_TRSTooltipText[MaxLine];
	RENDER_MESH RenderMeshPet[MAX_RENDER_MESH];
//	JEWEL_BANK m_JewelBank [MAX_JEWELBANK];
	JCItemnoGlow m_JCWRemoveGlow[ MAX_NOGLOW ];
	SelectChar m_RenderSelect[MAX_WORLD_SETTINGS];
	SelectSrv m_RenderSelectSrv[MAX_WORLD_SETTINGS];
	SERVERINFO_DATA m_ServerInfo[MAX_SERVER_CLASS];
	PET_DYNAMIC_CUSTOM m_DynamicPetEffect[max_ceffectdin];
	RenderTooltipBuff m_TooltipTRSDataEng[256];
	RenderTooltipBuff m_TooltipTRSDataSpn[256];
	RenderTooltipBuff m_TooltipTRSDataPor[256];
	CUSTOM_MODEL_EFFECT_INFO m_CustomModelInfo[MAX_MODEL_EFFECT];
};

int _tmain(int argc,_TCHAR* argv[]) // OK
{
	CLEAR_START

	ENCODE_START

	MAIN_FILE_INFO info;

	memset(&info,0,sizeof(info));

	info.LauncherType = GetPrivateProfileInt("MainInfo","LauncherType",0,".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","LauncherName","XTLauncherExecutable",info.LauncherName,sizeof(info.LauncherName),".\\MainInfo.ini");

	info.gMaxGameInstances = GetPrivateProfileInt("MainInfo", "MaxGameInstances", 0, ".\\MainInfo.ini");

	info.IpAddressPort = GetPrivateProfileInt("MainInfo","IpAddressPort",44405,".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","CustomerName","",info.CustomerName,sizeof(info.CustomerName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","IpAddress","",info.IpAddress,sizeof(info.IpAddress),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientVersion","",info.ClientVersion,sizeof(info.ClientVersion),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientSerial","",info.ClientSerial,sizeof(info.ClientSerial),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","WindowName","",info.WindowName,sizeof(info.WindowName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ScreenShotPath","",info.ScreenShotPath,sizeof(info.ScreenShotPath),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","ClientName","",info.ClientName,sizeof(info.ClientName),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName1","",info.PluginName1,sizeof(info.PluginName1),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName2","",info.PluginName2,sizeof(info.PluginName2),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName3","",info.PluginName3,sizeof(info.PluginName3),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName4","",info.PluginName4,sizeof(info.PluginName4),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","PluginName5","",info.PluginName5,sizeof(info.PluginName5),".\\MainInfo.ini");

	GetPrivateProfileString("MainInfo","CameraName","",info.CameraName,sizeof(info.CameraName),".\\MainInfo.ini");

	info.HelperActive = GetPrivateProfileInt("HelperInfo","HelperActive",0,".\\MainInfo.ini");

	info.HelperInterface = GetPrivateProfileInt("HelperInfo","HelperInterfaceActive",0,".\\MainInfo.ini");

	info.HelperActiveAlert = GetPrivateProfileInt("HelperInfo","HelperActiveAlert",0,".\\MainInfo.ini");

	info.HelperActiveLevel = GetPrivateProfileInt("HelperInfo","HelperActiveLevel",80,".\\MainInfo.ini");

	info.DWMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DWMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.DKMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DKMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.FEMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","FEMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.MGMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","MGMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.DLMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","DLMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.SUMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","SUMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.RFMaxAttackSpeed = GetPrivateProfileInt("CharacterInfo","RFMaxAttackSpeed",65535,".\\MainInfo.ini");

	info.ReconnectTime = GetPrivateProfileInt("ReconnectInfo","ReconnectTime",0,".\\MainInfo.ini");

	info.ItemLevel_15 = GetPrivateProfileInt("Fix","ItemLevel_15",0,".\\MainInfo.ini");
	
	info.CustomInterfaceType = GetPrivateProfileInt("Custom","InterfaceType",0,".\\MainInfo.ini");

	info.CustomInterfaceType = GetPrivateProfileInt("Custom","InterfaceType",0,".\\MainInfo.ini");

	info.SelectCharacterType = GetPrivateProfileInt("Custom","SelectCharacterType",0,".\\MainInfo.ini");

	info.SelectServerType = GetPrivateProfileInt("Custom","SelectServerType",0,".\\MainInfo.ini");

	info.MoveClassic = GetPrivateProfileInt("Custom","MoveClassicSwitch",0,".\\MainInfo.ini");

	info.MasterSkillTree = GetPrivateProfileInt("Custom","MasterSkillTreeSwitch",0,".\\MainInfo.ini");

	info.RemoveClickEffect = GetPrivateProfileInt("Custom","RemoveClickEffectSwitch",0,".\\MainInfo.ini");

	info.MenuFastAltClick = GetPrivateProfileInt("Custom","MenuFastAltClickSwitch",0,".\\MainInfo.ini");

	info.InventoryExpanded = GetPrivateProfileInt("Custom","InventoryExpandedSwitch",0,".\\MainInfo.ini");

	info.WarehouseExpanded = GetPrivateProfileInt("Custom","WarehouseExpandedSwitch",0,".\\MainInfo.ini");

	info.GensBattleWindow = GetPrivateProfileInt("Custom","GensBattleWindowSwitch",0,".\\MainInfo.ini");

	info.FastMenuKeyU = GetPrivateProfileInt("Custom","FastMenuKeyUSwitch",0,".\\MainInfo.ini");

	info.ChaosMachineItem380Switch = GetPrivateProfileInt("Custom","ChaosMachineItem380Switch",0,".\\MainInfo.ini");

	info.OptionsEventsMasterSwitch = GetPrivateProfileInt("Custom","OptionsEventsMasterSwitch",0,".\\MainInfo.ini");

	info.ButtonsSelectServer = GetPrivateProfileInt("Custom","ButtonsSelectServerSwitch",0,".\\MainInfo.ini");

	info.SelectServerOld = GetPrivateProfileInt("Custom","SelectServerBarRemakeSwitch",0,".\\MainInfo.ini");

	info.DisableKeyM = GetPrivateProfileInt("Custom","DisableKeyMSwitch",0,".\\MainInfo.ini");

	info.DisableKeyS = GetPrivateProfileInt("Custom","DisableKeySSwitch",0,".\\MainInfo.ini");

	info.DisableKeyD = GetPrivateProfileInt("Custom","DisableKeyDSwitch",0,".\\MainInfo.ini");
	
	info.DisableKeyF = GetPrivateProfileInt("Custom","DisableKeyFSwitch",0,".\\MainInfo.ini");
	
	info.DisableKeyX = GetPrivateProfileInt("Custom","DisableKeyXSwitch",0,".\\MainInfo.ini");

	info.GuildMasterButtonsPosition = GetPrivateProfileInt("Custom","GuildMasterButtonsPositionSwitch",0,".\\MainInfo.ini");

	info.SelectBarExp = GetPrivateProfileInt("Custom","SelectBarExpType",0,".\\MainInfo.ini");

	info.RemoveClass = GetPrivateProfileInt("Custom","DisableCreateClassType",0,".\\MainInfo.ini");

	info.RankUserType = GetPrivateProfileInt("Custom","RankUserType",0,".\\MainInfo.ini");

	info.LevelDelete = GetPrivateProfileInt("Custom","CharacterDeleteLevel",0,".\\MainInfo.ini");

	info.CustomSCharAnimate = GetPrivateProfileInt("Custom","CustomSelectCharAnimateEnable",0,".\\MainInfo.ini");

	info.HelperAndInventory = GetPrivateProfileInt("Custom","CustomHelperAndInventory",0,".\\MainInfo.ini");

	info.InventoryAdvanced = GetPrivateProfileInt("Custom","CustomInventoryAdvanced",0,".\\MainInfo.ini");

	info.CsSkill = GetPrivateProfileInt("Custom","EnableCsSkillsAllMaps",0,".\\MainInfo.ini");

	info.DisableReflectEffect = GetPrivateProfileInt("Custom","DisableReflectEffect",0,".\\MainInfo.ini");

	info.RankUserShowOverHead = GetPrivateProfileInt("Custom","RankUserShowOverHead",0,".\\MainInfo.ini");

	info.RankUserOnlyOnSafeZone = GetPrivateProfileInt("Custom","RankUserOnlyOnSafeZone",1,".\\MainInfo.ini");

	info.RankUserShowReset = GetPrivateProfileInt("Custom","RankUserShowReset",1,".\\MainInfo.ini");

	info.RankUserShowMasterReset = GetPrivateProfileInt("Custom","RankUserShowMasterReset",1,".\\MainInfo.ini");

	info.RankUserNeedAltKey = GetPrivateProfileInt("Custom","RankUserNeedAltKey",0,".\\MainInfo.ini");

	info.EnableVipShop = GetPrivateProfileInt("Custom","EnableVipShop",0,".\\MainInfo.ini");

	info.VipTypes = GetPrivateProfileInt("Custom","VipTypes",3,".\\MainInfo.ini");

	info.PrintLogo = GetPrivateProfileInt("Custom","PrinsdasdtLogo",0,".\\MainInfo.ini");

	info.CustomMenuSwitch = GetPrivateProfileInt("Custom","CustomMenuSwitch",0,".\\MainInfo.ini");

	info.CustomMenuType = GetPrivateProfileInt("Custom","CustomMenuType",0,".\\MainInfo.ini");

	info.EnableEventTimeButton = GetPrivateProfileInt("Custom","EnableEventTimeButton",0,".\\MainInfo.ini");

	info.EnableVipShopButton = GetPrivateProfileInt("Custom","EnableVipShopButton",0,".\\MainInfo.ini");

	info.EnableRankingButton = GetPrivateProfileInt("Custom","EnableRankingButton",0,".\\MainInfo.ini");

	info.EnableCommandButton = GetPrivateProfileInt("Custom","EnableCommandButton",0,".\\MainInfo.ini");

	info.EnableOptionButton = GetPrivateProfileInt("Custom","EnableOptionButton",0,".\\MainInfo.ini");

	info.EnableShopValueSystem  = GetPrivateProfileInt("Custom","EnableShopValueSystem",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoB  = GetPrivateProfileInt("Custom","EnableStoreBlessButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoS  = GetPrivateProfileInt("Custom","EnableStoreSoulButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableJoC  = GetPrivateProfileInt("Custom","EnableStoreChaosButtom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin1  = GetPrivateProfileInt("Custom","EnableStoreCoin1Buttom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin2  = GetPrivateProfileInt("Custom","EnableStoreCoin2Buttom",0,".\\MainInfo.ini");

	info.CustomStoreEnableCoin3  = GetPrivateProfileInt("Custom","EnableStoreCoin3Buttom",0,".\\MainInfo.ini");

	info.CustomOffStoreEnable  = GetPrivateProfileInt("Custom","EnableOffStoreButtom",0,".\\MainInfo.ini");

	info.CustomMonsterEnable  = GetPrivateProfileInt("Custom","CustomMonsterEnable",0,".\\MainInfo.ini");
	
	info.DisablePartyHpBar  = GetPrivateProfileInt("Custom","DisablePartyHpBar",0,".\\MainInfo.ini");

	info.LimitTransferZen  = GetPrivateProfileInt("Custom","LimitTransferZen",0,".\\MainInfo.ini");

	info.SelectCharacterSystem  = GetPrivateProfileInt("Custom","SelectCharacterUpgrade",0,".\\MainInfo.ini");

	info.HelperUpgradeSystem = GetPrivateProfileInt("Custom","ItemToolTipUpgrade",0,".\\MainInfo.ini");

	info.StatsAdvanced = GetPrivateProfileInt("Custom","StatsAdvancedSwitch",0,".\\MainInfo.ini");

	info.JewelBankSwitch = GetPrivateProfileInt("Custom","JewelBankSwitch",0,".\\MainInfo.ini");
	
	info.LuckyWheelSwitch = GetPrivateProfileInt("Custom","LuckyWheelSwitch",0,".\\MainInfo.ini");
	
	info.PlayerShowName = GetPrivateProfileInt("Custom","PlayerShowName",0,".\\MainInfo.ini");

	info.MultiCharacterEnable = GetPrivateProfileInt("Custom","MultiCharacterEnable",0,".\\MainInfo.ini");

	info.PlayerShowGuildLogo = GetPrivateProfileInt("Custom", "PlayerShowGuildLogo", 0, ".\\MainInfo.ini");

	info.SceneCharacterDowngradeType = GetPrivateProfileInt("Custom", "SceneCharacterDowngradeType", 0, ".\\MainInfo.ini");
	
	info.MessageChatRemakeType = GetPrivateProfileInt("Custom", "MessageChatRemakeType", 0, ".\\MainInfo.ini");

	info.m_MuunInventorySystem = GetPrivateProfileInt("Custom", "MuunInventorySystem", 0, ".\\MainInfo.ini");

	info.m_HelperActiveOfflineSystem = GetPrivateProfileInt("HelperInfo", "HelperActiveOfflineSystem", 0, ".\\MainInfo.ini");

	info.m_CustomCapeSystem = GetPrivateProfileInt("Custom", "CapeCustomSystem", 0, ".\\MainInfo.ini");

	info.m_CustomBowsSystem  = GetPrivateProfileInt("Custom", "BowCustomSystem", 0, ".\\MainInfo.ini");

	info.m_CustomFogSystem = GetPrivateProfileInt("Custom", "FogSystem", 0, ".\\MainInfo.ini");

	info.m_RemoveGlowSystem = GetPrivateProfileInt("Custom", "RemoveGlowSystem", 0, ".\\MainInfo.ini"); 

	info.m_ItemPositionSystem = GetPrivateProfileInt("Custom", "StoreSearchSystem", 0, ".\\MainInfo.ini"); 

	info.m_GlovesRFSystem = GetPrivateProfileInt("Custom", "GlovesRFSystem", 0, ".\\MainInfo.ini"); 

	info.m_PetCustomSystem = GetPrivateProfileInt("Custom", "PetCustomSystem", 0, ".\\MainInfo.ini"); 
	
	info.m_PetEffectSystem = GetPrivateProfileInt("Custom", "PetEffectSystem", 0, ".\\MainInfo.ini"); 

	info.m_EarthQuakeSystem = GetPrivateProfileInt("Custom", "EarthQuakeSystem", 0, ".\\MainInfo.ini"); 

	info.m_CashShopSafezone = GetPrivateProfileInt("Custom", "CashShopSafezone", 0, ".\\MainInfo.ini"); 

	info.m_StatusRealView = GetPrivateProfileInt("Custom", "StatusRealView", 0, ".\\MainInfo.ini"); 

	info.m_FpsMonitor = GetPrivateProfileInt("Custom", "FpsMonitor", 0, ".\\MainInfo.ini"); 

	info.m_LimitFPS = GetPrivateProfileInt("Custom", "FpsLimit", 0, ".\\MainInfo.ini"); 

	gCustomMessage.Load("CommonManager/CustomMessage.txt");

	gCustomJewel.Load("ItemManager/CustomJewel.txt");

	gCustomWing.Load("ItemManager/CustomWing.txt");

	gCustomItem.Load("ItemManager/CustomItem.txt");

	gCustomBuyVip.Load("CommonManager/CustomBuyVip.txt");

	gCustomCommandInfo.Load("CommonManager/CustomCommandInfo.txt");

	gCustomEventTimeText.Load("CommonManager/CustomEventTimeText.txt");

	gCustomWingEffect.Load("EffectManager/CustomEffectStatic.txt");

	gDynamicWingEffect.Load("EffectManager/CustomEffectDynamic.txt");

	gSmokeEffect.Load("EffectManager/CustomSmokeEffect.txt");

	gFog.Load("EffectManager/CustomFog.txt");

	gMonsters.Load("CustomManager/CustomMonster.txt");

	gNPCName.Load("CustomManager/CustomNPCName.txt");

	gCustomPet2.Load("PetManager/CustomPet.txt"); //CustomPets

	gCustomCEffectPet.Load("PetManager/CustomPetEffectStatic.txt");

	gCustomGloves.Load("ItemManager/CustomClaws.txt");

	gCustomCrossBow.Load("ItemManager/CustomCrossbow.txt");
	
	gCloak.Load("ItemManager/CustomCape.txt");
	
	gCustomPosition.Load("ItemManager/CustomItemPosition.txt");

	gLuckyWheel.Load("CustomManager/CustomLuckyWheel.txt");

	gCustomEarthQuake.Load("CustomManager/CustomEarthQuakeSkill.txt");

	GInfo.Load("ItemManager/CustomItemToolTip.txt");

	GInfo.Load2("ItemManager/CustomTextTooltip.txt");

	cRender.Load("PetManager/CustomPetGlow.txt");

	JCRemoveGlow.Load("ItemManager/CustomRemoveGlowItem.txt");

	gSelectCharRamdon.Load("CommonManager/CustomSceneControl.txt");

	g_ServerInfo.Load("CommonManager/CustomServerInfo.txt");

	gCustomCEffectDynamicPet.Load("PetManager/CustomPetEffectDynamic.txt");

	gCBuffIcon.Load("CommonManager/CustomBuffEffect_ENG.txt", 0);

	gCBuffIcon.Load("CommonManager/CustomBuffEffect_SPN.txt", 1);
	
	gCBuffIcon.Load("CommonManager/CustomBuffEffect_POR.txt", 2);

	gCustomModelEffect.Load("EffectManager/CustomModelEffect.txt");

//	gJewelBank.Load("CustomBank.txt");

	memcpy(info.m_CustomCloak, gCloak.m_Cloak, sizeof(info.m_CustomCloak));

	memcpy(info.CustomBowInfo, gCustomCrossBow.m_CustomBowInfo, sizeof(info.CustomBowInfo));

	memcpy(info.EngCustomMessageInfo,gCustomMessage.m_EngCustomMessageInfo,sizeof(info.EngCustomMessageInfo));

	memcpy(info.PorCustomMessageInfo,gCustomMessage.m_PorCustomMessageInfo,sizeof(info.PorCustomMessageInfo));

	memcpy(info.SpnCustomMessageInfo,gCustomMessage.m_SpnCustomMessageInfo,sizeof(info.SpnCustomMessageInfo));

	memcpy(info.CustomJewelInfo,gCustomJewel.m_CustomJewelInfo,sizeof(info.CustomJewelInfo));

	memcpy(info.CustomWingInfo,gCustomWing.m_CustomWingInfo,sizeof(info.CustomWingInfo));

	memcpy(info.CustomItemInfo,gCustomItem.m_CustomItemInfo,sizeof(info.CustomItemInfo));

	memcpy(info.CustomWingEffectInfo,gCustomWingEffect.m_CustomWingEffectInfo,sizeof(info.CustomWingEffectInfo));

	memcpy(info.DynamicWingEffectInfo,gDynamicWingEffect.m_DynamicWingEffectInfo,sizeof(info.DynamicWingEffectInfo));

	memcpy(info.CustomBuyVipInfo,gCustomBuyVip.m_CustomBuyVipInfo,sizeof(info.CustomBuyVipInfo));

	memcpy(info.CustomCommandInfo,gCustomCommandInfo.m_CustomCommandInfo,sizeof(info.CustomCommandInfo));

	memcpy(info.CustomEventInfo,gCustomEventTimeText.m_CustomEventInfo,sizeof(info.CustomEventInfo));

//	memcpy(info.CustomDescriptionInfo,gCustomItemDescription.m_Info,sizeof(info.CustomDescriptionInfo));

	memcpy(info.CustomSmokeEffect, gSmokeEffect.m_CustomSmokeEffect, sizeof(info.CustomSmokeEffect));

	memcpy(info.CustomFog, gFog.m_CustomFog, sizeof(info.CustomFog));

	memcpy(info.CustomMonsters, gMonsters.m_Monsters, sizeof(info.CustomMonsters));

	memcpy(info.CustomNPCName, gNPCName.m_CustomNpcName, sizeof(info.CustomNPCName));

	memcpy(info.CustomPetInfo, gCustomPet2.m_CustomPetInfo, sizeof(info.CustomPetInfo)); //Custom Pets
	
	memcpy(info.m_CustomPetCEffect, gCustomCEffectPet.m_PetCEffect, sizeof(info.m_CustomPetCEffect));
	
	memcpy(info.m_CustomGlovesInfo, gCustomGloves.m_CustomGlovesInfo, sizeof(info.m_CustomGlovesInfo));

	memcpy(info.CustomPositionInfo, gCustomPosition.m_CustomPositionInfo, sizeof(info.CustomPositionInfo));

	memcpy(info.CustomLuckyWheel, gLuckyWheel.m_LuckyWheelInfo, sizeof(info.CustomLuckyWheel));	

	memcpy(info.m_EarthQuake, gCustomEarthQuake.m_EarthQuake, sizeof(info.m_EarthQuake));

	memcpy(info.m_TRSTooltipData, GInfo.n_TRSTooltipData, sizeof(info.m_TRSTooltipData));

	memcpy(info.m_TRSTooltipText, GInfo.n_TRSTooltipText, sizeof(info.m_TRSTooltipText));

	memcpy(info.RenderMeshPet, cRender.m_RenderMeshPet, sizeof(info.RenderMeshPet));
	
	memcpy(info.m_JCWRemoveGlow, JCRemoveGlow.m_JCRemoveGlow, sizeof(info.m_JCWRemoveGlow));
	
	memcpy(info.m_RenderSelect, gSelectCharRamdon.RenderSelect, sizeof(info.m_RenderSelect));
	
	memcpy(info.m_RenderSelectSrv, gSelectCharRamdon.RenderSelectSrv, sizeof(info.m_RenderSelectSrv));

	memcpy(info.m_ServerInfo, g_ServerInfo.m_data, sizeof(info.m_ServerInfo));

	memcpy(info.m_TooltipTRSDataEng, gCBuffIcon.m_TooltipENG, sizeof(info.m_TooltipTRSDataEng));
	memcpy(info.m_TooltipTRSDataSpn, gCBuffIcon.m_TooltipSPN, sizeof(info.m_TooltipTRSDataSpn));
	memcpy(info.m_TooltipTRSDataPor, gCBuffIcon.m_TooltipPOR, sizeof(info.m_TooltipTRSDataPor));
	memcpy(info.m_CustomModelInfo, gCustomModelEffect.m_CustomModelEffectInfo, sizeof(info.m_CustomModelInfo));

	memcpy(info.m_DynamicPetEffect, gCustomCEffectDynamicPet.m_PetDynamicCEffect, sizeof(info.m_DynamicPetEffect));

	CCRC32 CRC32;

	if(CRC32.FileCRC(info.ClientName,&info.ClientCRC32,1024) == 0)
	{
		info.ClientCRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName1,&info.Plugin1CRC32,1024) == 0)
	{
		info.Plugin1CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName2,&info.Plugin2CRC32,1024) == 0)
	{
		info.Plugin2CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName3,&info.Plugin3CRC32,1024) == 0)
	{
		info.Plugin3CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName4,&info.Plugin4CRC32,1024) == 0)
	{
		info.Plugin4CRC32 = 0;
	}

	if(CRC32.FileCRC(info.PluginName5,&info.Plugin5CRC32,1024) == 0)
	{
		info.Plugin5CRC32 = 0;
	}

	if(CRC32.FileCRC(info.CameraName,&info.CameraCRC32,1024) == 0)
	{
		info.CameraCRC32 = 0;
	}

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&info)[n] ^= (BYTE)(0xDA^LOBYTE(n));
		((BYTE*)&info)[n] -= (BYTE)(0x95^HIBYTE(n));
	}

#if(GAMESERVER_PREMIUM==1)
	system("mkdir \"Data\\Local\\\"");
	HANDLE file = CreateFile("Data/Local/Server.bmd",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#else
	HANDLE file = CreateFile("free/main.free",GENERIC_WRITE,FILE_SHARE_READ,0,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,0);
#endif

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	DWORD OutSize = 0;

	if(WriteFile(file,&info,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	CloseHandle(file);

	ENCODE_END

	CLEAR_END

	return 0;
}
