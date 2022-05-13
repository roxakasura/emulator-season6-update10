#include "stdafx.h"
#include "resource.h"
#include "Main.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Common.h"
#include "ConnectServer.h"
#include "ServerInfo.h"
#include "Controller.h"
#include "CustomCape.h"
#include "CustomCloak.h"
#include "CustomBuyVip.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomServerInfo.h"
#include "CustomGloves.h"
#include "CustomInterface.h"
#include "CustomItem.h"
#include "CustomItemDescription.h"
#include "CustomItemPosition.h"
#include "CustomJewel.h"
#include "CustomLuckyWheel.h"
#include "CustomMap.h"
#include "CustomMonster.h"
#include "CustomNpcName.h"
#include "CustomWing.h"
#include "CheckSpeed.h"
#include "ChatExpanded.h"
#include "CustomServerInfo.h"
#include "Pet.h"
#include "PetHook.h"
#include "CustomPet.h"
#include "Fix.h"
#include "StaticEffect.h"
#include "DynamicEffect.h"
#include "HackCheck.h"
#include "HealthBar.h"
#include "Item.h"
#include "ItemPosition.h"
#include "ItemShopValue.h" 
#include "ItemSmoke.h"
#include "Interface.h"
#include "OffTrade.h"
#include "PacketManager.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "Protocol.h"
#include "Reconnect.h"
#include "Resolution.h"
#include "TMemory.h"
#include "User.h"
#include "Util.h"
#include "ItemAsm.h"
#include "CustomBow.h"
#include "ItemSetOption.h"
#include "CustomSCharAnimate.h"
#include "NewFont.h"
#include "CustomClickNPC.h"
#include "BattleGloves.h"
#include "WingInvisible.h"
#include "NewInterface.h"
#include "CustomWindow.h"
#include "CMacroUIEx.h"
#include "CustomEarthQuakeSkill.h"
#include "CSCharacterS13.h"
#include "StatsAdvanced.h"
#include "ChatSystem.h"
#include "Addons.h"
#include "PetGlow.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Inter803.h"
#include "Central.h"
#include "Season15.h"
#include "MuHelper.h"
#include "ChatCore.h"
#include "MultiCharacter.h"
#include "SceneControl.h"
#include "ExpandedCharacters.h"
#include "InfoLog.h"
#include "BankUpgrade.h"
#include "Season0.h"
#include "SelectCharacterS2.h"
#include "SelectServerS2.h"
#include "CScene.h"
#include "Season4.h"
#include "GlobalMessage.h"
#include "StoreSearch.h"
#include "PlayerSystem.h"
#include "PartySystem.h"
#include "PetSkillManager.h"
#include "ExperienceSystem.h"
#include "PetEffectDynamic.h"
#include "Minimize.h"
#include "NewController.h"
#include "Antilag.h"
#include "Console.h"
#include "OffMuHelper.h"
#include "ChangeSystem.h"
#include "Store.h"
#include "MuunOption.h"
#include "NewUIButton.h"
#include "NewUIPetInfoWindow.h"
#include "NewUISystem.h"
#include "SEASON3B.h"
#include "UIControl.h"
#include "LoginBox.h"
#include "Antilag.h"
#include "MenuOpt.h"
#include "SocketItem.h"
#include "BuffIcon.h"
#include "ModelEffect.h"
#include "QuickCommandWindow.h"
#include "TerrainSystem.h"
//#include "WingEffect.h"

HINSTANCE hins;

void StartAddress(LPVOID lpThreadParameter)
{
HANDLE v1;
HANDLE v2;

	while ( TRUE )
	{
		Sleep(5000);

		v1 = GetCurrentProcess();
		SetProcessWorkingSetSize(v1, 0xFFFFFFFF, 0xFFFFFFFF);

		v2 = GetCurrentProcess();
		SetThreadPriority(v2, -2);
	}
}

HICON WINAPI IconProc(HINSTANCE hInstance,LPCSTR lpIconName) // OK
{
	gTrayMode.m_TrayIcon = (HICON)LoadImage(hins,".\\Data\\Logo\\main.ico",IMAGE_ICON,GetSystemMetrics(SM_CXSMICON),GetSystemMetrics(SM_CYSMICON),LR_LOADFROMFILE | LR_DEFAULTCOLOR);

	return gTrayMode.m_TrayIcon;
}

BOOL __stdcall IsExcellentNoName(__int16 IsExcNoName)
{
  return IsExcNoName == 19 || IsExcNoName == 2066 || IsExcNoName == 2570 || IsExcNoName == 1037 || IsExcNoName == 2596;
}

extern "C" _declspec(dllexport) void EntryProc() // OK
{
	_mkdir("ScreenShots");

	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)StartAddress, 0, 0, 0);

	if(gProtect.ReadMainFile("Data//Local//Server.bmd") == 0)
	{
		MessageBox(0,"Main not found or invalid!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
	
	//Console.Write(Testando, 0, 0);

	m_Keyboard1 = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, NULL, GetCurrentThreadId());
	m_Keyboard2 = SetWindowsHookEx(WH_KEYBOARD_LL, LL_KeyboardProc, NULL, 0);

#if(MAIN_UPDATE>9)
	//MemorySet(0x00835CDB,0x90,0x5);
	AutoLogin.Load();
	gSocketItem.Load();
	InitTerrain();
#endif
	// - 
	//SetCompleteHook(0xE9,0x007E7820,&IsExcellentNoName);

	InitNotices();
	PlayerLoad();

	if(gProtect.m_MainInfo.m_HelperActiveOfflineSystem == 1)
	{
		gMuHelper.HelperOffline(); 
	}

	//StoreFixload();
	ItemSizeFixLoad();
	MenuLoad();
	
	/////MuunSystem
	if(gProtect.m_MainInfo.m_MuunInventorySystem == 1 && gProtect.m_MainInfo.m_PetCustomSystem == 1)
	{
		g_pRenderText.Init();
		g_pMuunInventory.Init();
		g_pNewUISystem.Init();
		//g_Option.Init();
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		LoadPartySystem();
		MemorySet(0x0057655B, 0x90, 0x5); //remove +15
	}

	//LoginWinLoad();
	 
	//ExpLoad();
	//gInfoLog.Load( ); 
	//Console.Init();
	//g_AddPoints.Load();

	//LoadSkillFenrir();

	MemorySet(0x82AC07,0x90,0x5);
	MemorySet(0x82B03D,0x90,0x5);
	MemorySet(0x82B0A7,0x90,0x5);
	MemorySet(0x82B18B,0x90,0x5);
	MemorySet(0x82B1FA,0x90,0x5);
	MemorySet(0x82B21B,0x90,0x5);
	MemorySet(0x82B2CB,0x90,0x5);
	MemorySet(0x82B339,0x90,0x5);
	MemorySet(0x82B3B7,0x90,0x5);
	MemorySet(0x82B3CA,0x90,0x5);
	MemorySet(0x82B772,0x90,0x5);

	SetByte(0x00E61144,0xA0); // Accent
	SetByte(0x004D1E69,0xEB); // Crack (mu.exe)
	SetByte(0x004D228D,0xE9); // Crack (GameGuard)
	SetByte(0x004D228E,0x8B); // Crack (GameGuard)
	SetByte(0x004D228F,0x00); // Crack (GameGuard)
	SetByte(0x004D2290,0x00); // Crack (GameGuard)
	SetByte(0x004D2291,0x00); // Crack (GameGuard)
	SetByte(0x004D559C,0xEB); // Crack (ResourceGuard)
	SetByte(0x00633F7A,0xEB); // Crack (ResourceGuard)
	SetByte(0x00634403,0xEB); // Crack (ResourceGuard)
	SetByte(0x0063E6C4,0xEB); // Crack (ResourceGuard)
	SetByte(0x004D2246,0xEB); // Crack (ResourceGuard)'
	SetByte(0x00501163,0xEB); // Crack (ResourceGuard)
	SetByte(0x0040AF0A,0x00); // Crack (ResourceGuard)
	SetByte(0x0040B4BC,0x50); // Login Screen
	SetByte(0x0040B4C5,0x50); // Login Screen
	SetByte(0x0040B4CF,0x18); // Login Screen
	SetByte(0x0040AF0A,0x00); // Login Screen
	SetByte(0x0040AFD5,0xEB); // Login Screen
	SetByte(0x00777FD6,0x70); // Item Text Limit
	SetByte(0x00777FD7,0x17); // Item Text Limit
	SetByte(0x004EBEC7,0x3C); // Item Text Limit
	SetByte(0x005C4004,0x3C); // Item Text Limit
	SetByte(0x007E40BB,0x3C); // Item Text Limit
	SetByte(0x0081B546,0x3C); // Item Text Limit
	SetByte(0x0081B58D,0x3C); // Item Text Limit
	SetByte(0x0086E284,0x3C); // Item Text Limit
	SetByte(0x0086E44C,0x3C); // Item Text Limit
	SetByte(0x0086E573,0x3C); // Item Text Limit
	SetByte(0x0086F8FC,0x3C); // Item Text Limit
	SetByte(0x007DA373,0xB7); // Item Type Limit
	SetByte(0x007E1C44,0xB7); // Item Type Limit
	SetByte(0x0052100D,0xEB); // Ctrl Fix
	SetByte(0x009543C4,0x00); // Move Vulcanus
	SetByte(0x0064CBD1,((gProtect.m_MainInfo.HelperActiveAlert==0)?0xEB:0x75)); // Helper Message Box
	SetByte(0x0064CBD0,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x0095CEEF,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x0095CF14,(BYTE)gProtect.m_MainInfo.HelperActiveLevel); // Helper Active Level
	SetByte(0x00E61F68,(gProtect.m_MainInfo.ClientVersion[0]+1)); // Version
	SetByte(0x00E61F69,(gProtect.m_MainInfo.ClientVersion[2]+2)); // Version
	SetByte(0x00E61F6A,(gProtect.m_MainInfo.ClientVersion[3]+3)); // Version
	SetByte(0x00E61F6B,(gProtect.m_MainInfo.ClientVersion[5]+4)); // Version
	SetByte(0x00E61F6C,(gProtect.m_MainInfo.ClientVersion[6]+5)); // Version
	SetWord(0x00E609E4,(gProtect.m_MainInfo.IpAddressPort)); // IpAddressPort
	SetDword(0x004D9D3B,(DWORD)&FrameValue);
	SetDword(0x004DAC60,(DWORD)&FrameValue);
	SetDword(0x7B55338,(DWORD)10);
	SetDword(0x004D597B,(DWORD)&MainTickCount);
	SetDword(0x004DA289,(DWORD)&MainTickCount);
	SetDword(0x004DA297,(DWORD)&MainTickCount);
	SetDword(0x004DA3A2,(DWORD)&MainTickCount);
	SetDword(0x004DA3CE,(DWORD)&MainTickCount);
	SetDword(0x004DA3D9,(DWORD)&MainTickCount);
	SetDword(0x0063D326,(DWORD)&MainTickCount);
	SetDword(0x00642112,(DWORD)&MainTickCount);
	SetDword(0x004D0E09,(DWORD)gProtect.m_MainInfo.WindowName);
	SetDword(0x004D9F55,(DWORD)gProtect.m_MainInfo.ScreenShotPath);
	SetDword(0x00D2265C,(DWORD)&IconProc);

	SetByte(0x005C914B+3,0x00); // LuckItemmove

	//SetByte(0x71E70C, 16);

	MemorySet(0x0063E908,0x90,20); // C1:F3:04

	MemoryCpy(0x00E611B2,gProtect.m_MainInfo.IpAddress,sizeof(gProtect.m_MainInfo.IpAddress)); // IpAddress

	MemoryCpy(0x00E61F70,gProtect.m_MainInfo.ClientSerial,sizeof(gProtect.m_MainInfo.ClientSerial)); // ClientSerial

	SetCompleteHook(0xFF,0x0065FD79,&ProtocolCoreEx);
	   
	SetCompleteHook(0xE9,0x004DA280,&CheckTickCount1);

	SetCompleteHook(0xE9,0x004DA3A1,&CheckTickCount2);

	SetCompleteHook(0xE8,0x005B96E8,&DrawNewHealthBar);

	VirtualizeOffset(0x004D9D39,12);

	VirtualizeOffset(0x004D9D45,7);

	VirtualizeOffset(0x004D9EFC,15);

	VirtualizeOffset(0x004DAC5C,8);

	VirtualizeOffset(0x005451F7,5);

	VirtualizeOffset(0x00545230,8);

	VirtualizeOffset(0x005A52E9,8);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN1),(DWORD)&NewAddressData1);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN2),(DWORD)&NewAddressData2);

	LoadReferenceAddressTable((HMODULE)hins,MAKEINTRESOURCE(IDR_BIN3),(DWORD)&NewAddressData3);

	gCustomMessage.LoadEng(gProtect.m_MainInfo.EngCustomMessageInfo);

	gCustomMessage.LoadPor(gProtect.m_MainInfo.PorCustomMessageInfo);

	gCustomMessage.LoadSpn(gProtect.m_MainInfo.SpnCustomMessageInfo);

	gCustomJewel.Load(gProtect.m_MainInfo.CustomJewelInfo);

	gCustomWing.Load(gProtect.m_MainInfo.CustomWingInfo);

	gCustomItem.Load(gProtect.m_MainInfo.CustomItemInfo);

	gCustomBuyVip.Load(gProtect.m_MainInfo.CustomBuyVipInfo);

	gCustomCommandInfo.Load(gProtect.m_MainInfo.CustomCommandInfo);

//	gCustomItemDescription.Load(gProtect.m_MainInfo.CustomDescriptionInfo);

	gCustomEventTime.Load(gProtect.m_MainInfo.CustomEventInfo);

	gCustomWingEffect.Load(gProtect.m_MainInfo.CustomWingEffectInfo);

	gDynamicWingEffect.Load(gProtect.m_MainInfo.DynamicWingEffectInfo);

	gFog.Load(gProtect.m_MainInfo.CustomFog);

	gSmokeEffect.Load(gProtect.m_MainInfo.CustomSmokeEffect);

	gCustomMonster.Load(gProtect.m_MainInfo.CustomMonsters);

	gNPCName.Load(gProtect.m_MainInfo.CustomNPCName);

	gCustomPet2.Load(gProtect.m_MainInfo.CustomPetInfo);

	gCustomBow.Load(gProtect.m_MainInfo.CustomBowInfo);
	
	gCloak.Load(gProtect.m_MainInfo.m_CustomCloak);
	
	gCustomPosition.Load(gProtect.m_MainInfo.CustomPositionInfo);
	
	gCustomGloves.Load(gProtect.m_MainInfo.m_CustomGlovesInfo);
	
	gLuckyWheel.Load(gProtect.m_MainInfo.CustomLuckyWheel);
	
	gCustomCEffectPet.Load(gProtect.m_MainInfo.m_CustomPetCEffect);  //PET EFFECT ANTIGO!

	gCustomEarthQuake.Load(gProtect.m_MainInfo.m_EarthQuakeLoad);

	GInfo.loadnInformation( gProtect.m_MainInfo.m_TRSTooltipData );

	GInfo.loadnText( gProtect.m_MainInfo.m_TRSTooltipText );

	cRender.Load(gProtect.m_MainInfo.RenderMeshPet);

	JCRemoveGlow.Load(gProtect.m_MainInfo.m_JCWRemoveGlow);
		
	gSelectCharRamdon.LoadMultiChar(gProtect.m_MainInfo.m_RenderSelect);

	gSelectCharRamdon.LoadMultiSrv(gProtect.m_MainInfo.m_RenderSelectSrv);

	g_ServerInfo.Init(gProtect.m_MainInfo.m_ServerInfo);

	gCustomCEffectDynamicPet.Load(gProtect.m_MainInfo.m_DynamicPetEffect);

	gIconBuff.LoadEng(gProtect.m_MainInfo.m_TooltipTRSDataEng);
	
	gIconBuff.LoadSpn(gProtect.m_MainInfo.m_TooltipTRSDataSpn);
	
	gIconBuff.LoadPor(gProtect.m_MainInfo.m_TooltipTRSDataPor);

	gCustomModelEffect.Load(gProtect.m_MainInfo.m_CustomModelInfo);

//	gJewelBank.Load(gProtect.m_MainInfo.m_JewelBank);

	gPacketManager.LoadEncryptionKey("Data\\Enc1.dat");

	gPacketManager.LoadDecryptionKey("Data\\Dec2.dat");
	
	if(gProtect.m_MainInfo.m_CashShopSafezone == 1)
	{
		MemorySet(0x00811ECD,0x90,0x5); //cash shop interface
		MemorySet(0x007D3D7A,0x90,0x5);
	}

	SetWord(0x00405B7C, 1);
	SetWord(0x0040CC40, 1);
	MemorySet(0x00792B7F, 0x90, 0x05);	// Fix Button Crywolf Gatekeeper (Third Quest)

	if(gProtect.m_MainInfo.m_CustomCapeSystem == 1)
	{
		gCapeAnimation.Load();
	}

	InitCommon();

	InitHackCheck();

	InitItem();
	
	InitJewel();

	InitPrintPlayer();

	InitReconnect();

	InitResolution();

	gController.Load();

	CustomFont.load();

	InitWing();

	gObjUser.Load();

	gInterface.Load();

	//gWinApiHook.Load(); refazer

	InvisibleItemX();

	gOffTrade.Init();

	if(gProtect.m_MainInfo.m_CustomBowsSystem == 1)
	{
		InitBows();
	}

	if(gProtect.m_MainInfo.m_CustomFogSystem == 1)
	{
		gFog.Init();
	}

	if(gProtect.m_MainInfo.CustomInterfaceType < 1 || gProtect.m_MainInfo.CustomInterfaceType > 2)
	{
		gChatExpanded.Load();

		gChatExpanded.Switch();
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 1 && gProtect.m_MainInfo.MessageChatRemakeType == 0 || 
		gProtect.m_MainInfo.CustomInterfaceType == 2 && gProtect.m_MainInfo.MessageChatRemakeType == 0)
	{
		gChatExpanded.Load();

		gChatExpanded.Switch();
	}

	if(gProtect.m_MainInfo.m_RemoveGlowSystem == 1)
	{
		JCRemoveGlow.Init();
	}

	if(gProtect.m_MainInfo.CustomMonsterEnable == 1)
	{
		gCustomMonster.InitMonster();
	}

	SetFloat(0xD477AC,0.0); //Fix ItemStack in Itemtoolip/Shop

	//MemorySet(0x00401E49,0x90,0x5); //remove position do infochar select server

	//Fix DL evoluir branco kk
	SetDword(0x0057F9FA + 3, 304); //-- slot armor
	SetDword(0x0057FA3D + 3, 340); //-- slot pants
	SetDword(0x0057FA7F + 3, 376); //-- slot glove
	SetDword(0x0057FAC1 + 3, 412); //-- slot boot

	//-- Gate.bmd + 1024 Lineas
	SetDword(0x005B57EA + 3, 0x400); //-- MaxData GateBMD
	SetDword(0x00589DBB + 3, 0x400); //-- MaxData GateBMD
	SetDword(0x004D2CB1 + 1, 0x3800); //-- MaxData GateBMD
	SetDword(0x004D2D9B + 1, 0x3800); //-- MaxData GateBMD

	//SetByte(0x004EF9F6+2,0);
	
	if(gProtect.m_MainInfo.LimitTransferZen == 1)
	{
		SetByte((PVOID)(0x007AF175 + 1), 9);
		SetByte((PVOID)(0x007AF415 + 1), 9);
		SetByte((PVOID)(0x007AF795 + 1), 9);
		SetByte((PVOID)(0x007B0315 + 1), 9);
	}
	
	//WingInvisible();

	gProtect.CheckLauncher();
	gProtect.CheckInstance();
	gProtect.CheckClientFile();
	gProtect.CheckPlugin1File();
	gProtect.CheckPlugin2File();
	gProtect.CheckPlugin3File();
	gProtect.CheckPlugin4File();
	gProtect.CheckPlugin5File();
	gProtect.CheckCameraFile();

	//gFix.Load();

	gCustomMap.Load();

	gCustomPet.Load(); //CustomPets

	gObjCreatePetExHook(); //CustomPets

	gCItemSetOption.Load();

	if(gProtect.m_MainInfo.EnableShopValueSystem == 1)
	{
		gItemPrice.Init();
	}

	if(gProtect.m_MainInfo.CsSkill == 1)
	{
		//Liberar CS Skills
		SetByte((0x005B89C3+3), 0x00);
		SetByte((0x005B89C9+3), 0x00);
		SetByte((0x005B89CF+3), 0x00);
		SetByte((0x005B89D5+3), 0x00);
		SetByte((0x005B89DB+3), 0x00);
		SetByte((0x005B89E1+3), 0x00);
		SetWord((0x005B89E7+3), 0x00);

		SetByte((0x005C6314+2), 0x00);
		SetByte((0x005C6327+2), 0x00);
		SetByte((0x005C633A+2), 0x00);
		SetByte((0x005C634D+2), 0x00);
		SetByte((0x005C6360+2), 0x00);
		SetByte((0x005C6373+2), 0x00);
		SetWord((0x005C6386+2), 0x00);
	}

	//==============================================================================
	// [Fix] Remover Recuo PVP
	//==============================================================================
	if(gProtect.m_MainInfo.DisableReflectEffect == 1)
	{
		SetByte(0x005528A0,0xC3);
	}

	SetCompleteHook(0xE8, 0x0059AFFA, 0x0059B00E); //Fix Monstro travando

//	MemorySet(0x00552A04,0x90,0x5); ERROR DO CHAR ANIMATE
	//SetByte((PVOID)(0x005529F4+1),0);
//	SetCompleteHook(0xE9,0x0055299F,0x005529A6);

//	SetByte((PVOID)(0x005DE2B2), 0); //RESTAURA
//	SetByte((PVOID)(0x005DE2B2), 1); //REMOVE OBJETOS
	
//	MemorySet(0x00626190,0x90,0x2FE2);
//	MemorySet(0x0072D1B0,0x90,0x87A2);

	if(gProtect.m_MainInfo.CustomSCharAnimate == 1)
	{
		gSelectChar.Load();
	}

	SetWord(0x00405B7A+2,(WORD)gProtect.m_MainInfo.LevelDelete);
	SetWord(0x0040CC3F+1,(WORD)gProtect.m_MainInfo.LevelDelete);

	//Fix Dark horse look around
	SetCompleteHook(0xE9,0x0064452A,0x00644537);

	//Change credits 
	if(gProtect.m_MainInfo.SelectServerType == 0)
	{
	//	MemorySet(0x004D7DAD,0x90,0x0F);
	//	MemorySet(0x004D7E33,0x90,0x0F);
	//	SetCompleteHook(0xE9,0x004D7D13,&Copyright);
	}

	SetByte((LPVOID)0x0052101B,0x02); //Fix CTRL Freeze
	//--
	SetCompleteHook(0xE9, 0x0071AE92, 0x00720894); //Fix RF Skill
	SetCompleteHook(0xE9, 0x0071B1A3, 0x00720894); //Fix RF Skill
	//--
	//CUSTOM MUHELPER + INVETORY
	if(gProtect.m_MainInfo.HelperAndInventory == 1)
	{
		SetCompleteHook(0xE9, 0x0095DFBE, 0x0095DFD3); //Fix MU Helper + Inventory
	}
	//MemorySet(0x005AF55B,0x90,0x5);
	//UPDATE 4 - INICIADO 13/08
	InitAttackSpeed();
		
	gItemPosition.Load();

	if(gProtect.m_MainInfo.m_GlovesRFSystem == 1)
	{
		InitBattleGloves();
	}

    ConnectServer.Load();

	g_ServerInfo.Load(); //ATIVANDO...SEM SEGREDO ALGUM XD

	if(gProtect.m_MainInfo.m_PetEffectSystem == 1)
	{
		gCustomCEffectPet.Init(); 
	}

	if(gProtect.m_MainInfo.m_EarthQuakeSystem == 1)
	{
		gCustomEarthQuake.LoadRenderSkill();
	}

	if(gProtect.m_MainInfo.SelectCharacterSystem == 1)
	{
		if (gProtect.m_MainInfo.SelectCharacterType == 0 || gProtect.m_MainInfo.SelectCharacterType == 2 || gProtect.m_MainInfo.SelectCharacterType == 3 || gProtect.m_MainInfo.SelectCharacterType == 4 || gProtect.m_MainInfo.SelectCharacterType == 5)
		{
			gCSCharacterS13.Load();
			CScene();
		}
	}

	if(gProtect.m_MainInfo.SelectCharacterType == 2) //select char season 2
	{	
		SCharacterS3();
	}

	if(gProtect.m_MainInfo.SelectServerType == 2) //select server season 2
	{	
		InitSelectServerS2();
	}

	if(gProtect.m_MainInfo.SelectServerType == 3) //select server season 8
	{	
		CScene803();
	}

	if(gProtect.m_MainInfo.SelectCharacterType == 3) //select char season 8
	{	
		SScene803();
	}

	if(gProtect.m_MainInfo.SelectServerType == 1)
	{
		SetDword((0x004D568C+1),(DWORD)"Interface\\GFx\\none.tga");
	}

	if(gProtect.m_MainInfo.SelectCharacterType == 1 || gProtect.m_MainInfo.SelectServerType == 1)
	{
		CSceneS0();
	}

	if (gProtect.m_MainInfo.SelectCharacterType == 4 && gProtect.m_MainInfo.SelectServerType == 4)
	{
		SCharacterS4();
	}

	gSelectCharRamdon.InitMultiChar();

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2) //interface
	{
		gCChatClassic.Load();
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2) //interface
	{
		InitInter3();
	}

	if(gProtect.m_MainInfo.SelectServerOld == 1)
	{	
		//SetByte((PVOID)(0x00414239),0); //POSIÇÃO X DA SEGUNDA BARRA
		SetCompleteHook(0xE8,0x00414086,&SelectServerBarPosition); //MOV
		SetCompleteHook(0xE8,0x004140D9,&SelectServerBarPosition); //MOV
		SetCompleteHook(0xE8,0x0041412E,&SelectServerBarPosition); //MOV
		SetCompleteHook(0xE8,0x004141BA,&SelectServerBarPosition); //MOV
		SetCompleteHook(0xE8,0x004141EB,&SelectServerBarPosition); //MOV
	}
	
	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2) //interface
	{
		gAddons.Load();
	}

	gCentral.InitCentral();

	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{			
		//InitSeason15();
		InitInterEx(); //interface de baixo
		gCRenderEx700.Init(); //interface takumi 100%
		gMuHelperS15.Load();
		gCChatEx.Load();
	}

	//new addons
	if(gProtect.m_MainInfo.HelperInterface == 0)
	{
		gCMacroUIEx.Load();
	}

	if(gProtect.m_MainInfo.HelperActive == 0)
	{
		SetByte((PVOID)(0x007D4000+1),0xFF); //REMOVE HOME KEY
		SetByte((PVOID)(0x007D410F+1),0xFF); //REMOVE Z KEY
	}

	nInterface.Load();

	if(gProtect.m_MainInfo.FastMenuKeyU == 1)
	{
		MemorySet(0x008684F0, 0x90, 0x52);				// Disable FastMenu (Key U)
	}

	if(gProtect.m_MainInfo.GensBattleWindow == 1)
	{
		MemorySet(0x007C5A68, 0x90, 0x25);
		MemorySet(0x007C4430, 0x90,0x159);				// Disable Gems
		MemorySet(0x007C5AD2, 0x90, 0x05);				// Disable Gens (Key B)
	}

	if(gProtect.m_MainInfo.InventoryExpanded == 1)
	{
		SetCompleteHook(0xE9, 0x008369FA, 0x00836A23);	//Remove botão (K)
		SetCompleteHook(0xE9, 0x007D36B8, 0x007D36BF);	//Função (K) Inventário aberto
		SetCompleteHook(0xE9, 0x007D3F9C, 0x007D3FA3);	//Função (K) Baú Aberto
	}

	if(gProtect.m_MainInfo.WarehouseExpanded == 1)
	{
		SetCompleteHook(0xE9, 0x00856FAA, 0x00856FD2);	//Remove (H) Baú Aberto
		SetCompleteHook(0xE9, 0x007D371E, 0x007D3725);	//Remove botão (H)
	}

	if(gProtect.m_MainInfo.MenuFastAltClick == 0)
	{
		MemorySet(0x00853770,0x90,0x1DB);				//desativa imagens - TELA RÁPIDA (AO CLICAR COM SHIFT)
		MemorySet(0x00853710,0x90,0x5A);				//apaga texto - TELA RÁPIDA (AO CLICAR COM SHIFT)
		MemorySet(0x007D31F0,0x90,0x273);				//desativa tela rápida - TELA RÁPIDA (AO CLICAR COM SHIFT)
	}

	if(gProtect.m_MainInfo.RemoveClickEffect == 1)
	{
		SetRange((LPVOID)0x006E899D, 5, ASM::NOP);		//CLICK EFFECT CURSOR
		SetRange((LPVOID)0x007126FA, 5, ASM::NOP);		//CLICK EFFECT CURSOR
		SetRange((LPVOID)0x005B768F, 5, ASM::NOP);		//CLICK EFFECT CURSOR
		SetRange((LPVOID)0x005B770C, 5, ASM::NOP);		//CLICK EFFECT CURSOR
	}

	if(gProtect.m_MainInfo.MasterSkillTree == 1)
	{
		MemorySet(0x008193F0,0x90,0xC8);				//REMOVE JANELA MASTER SKILL TREE
		SetByte((PVOID)(0x007D3A4A+1),0xFF);			//REMOVE TECLA MASTER SKILL TREE
	}

	if(gProtect.m_MainInfo.MoveClassic == 1)
	{
		/*			NEW MOVE DOWNGRADE SYSTEM			*/
		SetCompleteHook(0xE9,0x00832862, 0x00832897);	//DISABLE GENS BATTLE (BATTLE ZONE MOVE (M))
		MemorySet(0x00832CF2,0x90,0x5);
		SetByte((PVOID)(0x00832C44+2),5);				//BARRA AMARELA REDIMENSIONADA
		//TELA M EM RESOLUÇÃO 800
		SetByte((PVOID)(0x00830C77+2),34);
		SetByte((PVOID)(0x00830C86+2),94);
		SetByte((PVOID)(0x00830C98+2),139);
		SetByte((PVOID)(0x00830C6A+3),148);				//LARGURA
		//TELA M EM RESOLUÇÃO 1024
		SetByte((PVOID)(0x00830CB6+2),29);
		SetByte((PVOID)(0x00830CC5+2),84);
		SetByte((PVOID)(0x00830CD4+2),124);
		SetByte((PVOID)(0x00830CA9+3),128);				//LARGURA
		SetByte((PVOID)(0x00830C31+2),30);
		//TELA M EM RESOLUÇÃO 1280 OK
		SetByte((PVOID)(0x00830CF2+2),25);
		SetByte((PVOID)(0x00830D01+2),69);
		SetByte((PVOID)(0x00830D10+1),104);
		SetByte((PVOID)(0x00830CE5+3),108);				//LARGURA
		SetDword((PVOID)(0x00830D49),500);				//DIMENSIONAMENTO DO MOVE
		SetDword((PVOID)(0x00832443+2),220);			//COMPRIMENTO DO MOVE
		//TAMANHO DO MOVE - OTIMIZAÇÃO DE TAMANHO
		SetByte((0x00830D64+2),33);
		SetByte((0x00830D67+2),55);						//REGULA O TAMANHO DO MOVE
		SetByte((0x00830E55+2),33);
		SetByte((0x0083245B+2),33);
		SetByte((0x00830ED3+2),33);
		SetByte((0X00830FD6+2),33);
		//RETIRA IMAGENS DO MOVE
		MemorySet(0x008325D4, 0x90, 0x05);
		MemorySet(0x00832639, 0x90, 0x05); 
		MemorySet(0x0083268F, 0x90, 0x05);
		MemorySet(0x008326D7, 0x90, 0x05);
		MemorySet(0x00832757, 0x90, 0x05);
		MemorySet(0x00832794, 0x90, 0x05);  
		/*			NEW MOVE DOWNGRADE SYSTEM			*/
	}

	if(gProtect.m_MainInfo.ChaosMachineItem380Switch == 1)
	{
	//CM 380
		MemorySet(0x007AA3BA,0x90,0x5);
		MemorySet(0x007AA39C,0x90,0x5);
		MemorySet(0x007AA9B3,0x90,0x5);

		SetDword((PVOID)(0x007AA2F4+2),190);//  BOTÃO CHAOS WEAPON POSITION Y
		SetByte((PVOID)(0x007AA292+2),120); //BOTÃO REGULAR COMBINATION POSITION Y
		SetByte((PVOID)(0x007AA669+2),50); //TEXTS CM POSITION Y
	}

	if(gProtect.m_MainInfo.OptionsEventsMasterSwitch == 1)
	{
		SetCompleteHook(0xE9,0x007E4CA4,0x007E4D16); ///Remover ChaosCastle Master/
		SetByte((PVOID)(0x007E4CB9+1),0); //Cambia el número del chaos/
		MemorySet(0x00878B5F,0x90,0x5);	//Remover DevilScare Master/
		MemorySet(0x0087500F,0x90,0x5);     //Remover Blood Text/
		SetByte((PVOID)(0x008743FC+3),7);	//Retirar Blood Button Master/
		SetByte((PVOID)(0x00874D54+6),7);	//Retirar Blood Button Master/
		SetByte((PVOID)(0x00877EDC+3),6); //Remover DevilScare Master/
	}

	if(gProtect.m_MainInfo.ButtonsSelectServer == 1)
	{
		MemorySet(0x0040A7EF,0x90,0x5); //Remover Button Menu SelectServer/
		MemorySet(0x0040A87E,0x90,0x5); //Remover Button Crédits SelectServer/
	}

	if(gProtect.m_MainInfo.DisableKeyM == 1)
	{	
		SetByte((PVOID)(0x007D3C6B+1),0xFF); //DESATIVA O M MOVE
	}

	if(gProtect.m_MainInfo.DisableKeyS == 1)
	{
		SetByte((PVOID)(0x00834E12+1),0xFF); //DESATIVA O S STORE
	}

	if(gProtect.m_MainInfo.DisableKeyD == 1)
	{	
		SetByte((PVOID)(0x007D3AF1+1),0xFF); //DESATIVA O D TELA
	}

	if(gProtect.m_MainInfo.DisableKeyF == 1)
	{	
		SetByte((PVOID)(0x007D37A1+1),0xFF); //DESATIVA O F TECLA
	}

	if(gProtect.m_MainInfo.DisableKeyX == 1)
	{	
		SetByte((PVOID)(0x007D3D56+1),0xFF);	//-> Remove Key X CASH SHOP
	}

	switch(gProtect.m_MainInfo.RemoveClass)
	{
		case 1:
			SetByte(0x004030D1+3,4);	
			break;
		case 2:
			SetByte(0x004030D1+3,5);
			break;
		case 3:
			SetByte(0x004030D1+3,6);
			break;
	}

	SetCompleteHook(0xE9,0x005880F0,0x0058811F); //Fix gm wing on Blood castle
	SetDword(0x00588444+3,4095);
	
//	MemorySet(0x00405559, 0x90, 0x05); Rafhael

//	MemorySet(0x007D2BC0,0x90,0x280);
//	MemorySet(0x007D26EF,0x90,0x5);	//RETIRA A ENGRENAGEM (CONFIG)
//	MemorySet(0x007D278E,0x90,0x5);	//RETIRA O BOTÃO PLAY
//-->>procurando no offset do call acima
//	MemorySet(0x007D3011,0x90,0x5);	//RETIRA IMAGEM DA ENGRENAGEM E PLAY
//	MemorySet(0x007D3029,0x90,0x5);	//RETIRA A FUNÇÃO + TEXTO DOS BOTÕES
//	MemorySet(0x007D2920,0x90,0x1D1); //DESATIVA TODAS AS FUNÇÕES DO MUHELPER PORÉM CONTINUA TEXTO E IMAGENS

//	MemorySet(0x00786347,0x90,0x5);	//DESATIVA O BOTÃO WHISPER
//	MemorySet(0x00790B10,0x90,0x5);
//	MemorySet(0x007863A8,0x90,0x5); //esse desativa o $
//	MemorySet(0x0078641E, 0x90, 0x05); //Remove Button Off esse a nuvenzinha do lado do $
//	MemorySet(0x007864B3, 0x90, 0x05); // Esse o controle de janela
//	MemorySet(0x007862E2,0x90,0x5); //desativa ativações de Chat/Guild/Gens/Party
//	SetByte((PVOID)(0x00786343+2),125);
//	MemorySet(0x0078653E, 0x90, 0x05); //Remove Button Off
//	MemorySet(0x00786574, 0x90, 0x05); //Remove Button Off
	
//	SetCompleteHook(0xE9,0x00832862, 0x00832897); //battle zone
//	MemorySet(0x00832CF2,0x90,0x5); //remove battle

	//MAIOR DOS MAIORES
//	MemorySet(0x7E3E30,0x90,0x1EA2); //ITEMTOOLTIP ITEM
//	SetByte((PVOID)(0x007E3EDD+2),120); //RETIRA TODAS AS OPÇÕES DOS ITENS
//	SetByte((PVOID)(0x007E3F4A+3),100); //APAGA O TOOLTIP DOS ITENS COM POUCOS ADDS  |. 0FBF50 4C      MOVSX EDX,WORD PTR DS:[EAX+4C]
//	MemorySet(0x007E5D00,0x90,0xFF5);  //AO COLOCAR O MOUSE NO ITEM FECHA

	//MuHelper Dimensionamento
//	MemorySet(0x007D2DEE,0x90,0x5);
//	MemorySet(0x007D2E31,0x90,0x5);
//	MemorySet(0x007D2C8A,0x90,0x5);
//	MemorySet(0x007D2D18,0x90,0x5);
//	MemorySet(0x007D2D6B,0x90,0x5);
//	SetByte((PVOID)(0x007D2D52+3),-120); //INTERFACE MINIMAPC
//	SetByte((PVOID)(0x007D2771+3),-83);  //START MUHELPER
//	SetByte((PVOID)(0x007D281C+3),-83);	 //STOP MUHELPER
//	SetByte((PVOID)(0x007D26D5+3),-100); //CONFIG MUHELPER

	//SetByte((PVOID)(0x00786794+1),0x59); //F5 KEY

//	MemorySet(0x5039A0,0x90,0x252); //REMOVE EFFECT TERREMOTO
//	MemorySet(0x501790,0x90,0x1F87); //REMOVE PETS TEXTURES
//	MemorySet(0x007E5909,0x90,0x5); //MSG DO CAVALO
//	SetDword((PVOID)(0x007E58FF+1),1202);
//	MemorySet(0x007E591C,0x90,0x5); //RETIRA TEXTO 1201
//	MemorySet(0x005FBB48,0x90,0x5); //EFFECT no Dark Horse inventory
//	MemorySet(0x5964B0,0x90,0x4A); //DESATIVA O USO DA EARTHQUAKE
//	MemorySet(0x0048F9B1,0x90,0x5); //Fez nada
//	MemorySet(0x0064681C,0x90,0x5);
//	MemorySet(0x008123D7,0x90,0x5); //Retira as skills em parte
//	MemorySet(0x00813DC0,0x90,0x1155); //Desativa todas as skills
//	SetByte((PVOID)(0x00814081+2),0xFF); //Skill DL no bug
//	SetDword((PVOID)(0x005BD34B+1),264); msg de icarus
//	MemorySet(0x005BD09D,0x90,0x5); remove a verificação do comando move para atlans com equips
//	MemorySet(0x0077FB34,0x90,0x5); //info chars
//	SetByte((PVOID)(0x0077FCEB+2),25);

	//g_StatsAdvance.Load();

	gRenderMap.MiniMapload();

	/*008648E8
		007D16AC
		007CC4B0*/

	/*Duelo, mexer depois*/
	//MemorySet(0x007C1EA4, 0x90, 0x5);
	/*MemorySet(0x007C1E56, 0x90, 0x5);*/
		
	if(gProtect.m_MainInfo.m_ItemPositionSystem == 1)
	{
		g_PersonalShopEx.Load();
	}

	g_pQuickCommandWindow.szInit();
	
	//SetCompleteHook(0xE9,0x005DB2D5,&MagoTeste);

	//MemorySet(0x007A82E0,0x90,0x45); remove o menu
	//MemorySet(0x007A8316,0x90,0x5); some tudo
	//MemorySet(0x007A830E,0x90,0x5);
	
/*	SetByte(0x004D72C4+3,0x6); //100%
	SetByte(0x004D71DD+3,0x6); //100%
	SetByte(0x004057E2+3,0x6);
	SetByte(0x0040587E+3,0x6);
	SetByte(0x004D7075, 0x6);
	SetByte(0x004D70AA+6, 0x6);
	SetByte(0x004D6F66, 0x6);*/

/*	MemorySet(0x0040CD8C,0x90,0x5); //call 4020C0
	MemorySet(0x00483A0C,0x90,0x5); //call 4020C0
	MemorySet(0x0063D582,0x90,0x5); //call 4020C0*/

	//SetByte((PVOID)0x005D6F46, 0x8);
    //SetByte((PVOID)0x005D5035, 0x7);
    //SetByte((PVOID)0x005D73B0, 0x7);

	//SetCompleteHook(0xE8,0x401DA0+0xA9,&DisplayInfoBarCharacterPosition); //MOV
	//MemorySet(0x00552710,0x90,0xE0E); //função remmove a render do fenrir skill

	SetByte((0x00958D56 + 0x3),0x01); //aumento da quantidade de caracteres
	SetByte((0x00958D8F + 0x3),0x01); //aumento da quantidade de caracteres
	SetByte((0x00958DE1 + 0x3),0x01); //aumento da quantidade de caracteres

	//SetByte((0x00958D4C + 3), 0x6A);    //1 Codepage utf ÀÒÉÒä·Â  26c 36A
	//SetByte((0x00958D4C + 4), 0x03);    //2  Codepage utf ÀÒÉÒä·

	//MemorySet(0x788A80,0x90,0x68B); //all msgs
//	SetRange((LPVOID)0x007E7827,4,ASM::NOP);
//	SetOp((LPVOID)0x007E7827,(LPVOID)DivineWeapon,ASM::JMP);
//	//--
//	SetRange((LPVOID)0x005F479E,10,ASM::NOP);
//	SetOp((LPVOID)0x005F479E,(LPVOID)DropColor,ASM::JMP);

	//JGetPlayer.initCharacter(); //Slot 10 chars
	
	//Remake + 15 itens 97d
	//SetCompleteHook(0xE9, 0x0060EA3C, 0x0060EA58);
	//SetCompleteHook(0xE9, 0x0060EA88, 0x0060EAE9);
	//SetByte(0x0060E8CA + 3, 12);
}

//--
DWORD DivineWeapon_Buff=0;
DWORD DivineWeapon_Pointer=0;
//--
__declspec(naked)void DivineWeapon()
{
	static DWORD DivineWeaponAdress1=0x007E785F;
	static DWORD DivineWeaponAdress2=0x007E7866;
	_asm
	{
		Mov DivineWeapon_Buff,Edx
		MOVSX EDX,WORD PTR SS:[EBP+0x8]
		mov DWORD PTR SS:[EBP+0x8],Edx
		mov DivineWeapon_Pointer,Edx
		Mov Edx,DivineWeapon_Buff
	}
	if(DivineWeapon_Pointer==0x13
		||DivineWeapon_Pointer==0x812
		||DivineWeapon_Pointer==0x0A0A
		||DivineWeapon_Pointer==0x40D
		||DivineWeapon_Pointer==0x0A24
		//--
		||DivineWeapon_Pointer==ITEM(0,28)	//-> Blessed Divine Sword of Archangel
		||DivineWeapon_Pointer==ITEM(0,60)	//-> Divine Claw of Archangel
		||DivineWeapon_Pointer==ITEM(0,61)	//-> Blessed Divine Claw of Archangel
		||DivineWeapon_Pointer==ITEM(0,76)	//-> Divine Short Sword of Archangel
		||DivineWeapon_Pointer==ITEM(0,77)	//-> Blessed Divine Short Sword of Archangel
		||DivineWeapon_Pointer==ITEM(2,25)	//-> Blessed Divine Scepter of Archangel
		||DivineWeapon_Pointer==ITEM(2,34)	//-> Divine Mace of Archangel
		||DivineWeapon_Pointer==ITEM(2,35)	//-> Blessed Divine Mace of Archangel
		||DivineWeapon_Pointer==ITEM(3,26)	//-> Divine Lance of Archangel
		||DivineWeapon_Pointer==ITEM(3,27)	//-> Blessed Divine Lance of Archangel
		||DivineWeapon_Pointer==ITEM(4,30)	//-> Blessed Divine Crossbow
		||DivineWeapon_Pointer==ITEM(5,49)	//-> Blessed Divine Staff
		||DivineWeapon_Pointer==ITEM(5,50)	//-> Blessed Divine Stick
		)
	{
		_asm{Jmp DivineWeaponAdress1}
	}
	else
	{
		_asm{Jmp DivineWeaponAdress2}
	}
}
//--
DWORD DropColorProtect;
DWORD DropColorPointer;
//--
__declspec(naked)void DropColor()
{
	_asm
	{
		Mov DropColorProtect,Eax
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		Mov Eax,DWORD PTR DS:[EDX+0x30]
		Mov DropColorPointer,Eax
		Mov Eax,DropColorProtect
	}
	if(DropColorPointer==0x253B || DropColorPointer==ITEM2(0,28))
	{
		_asm{
			Mov DropColorPointer,0x005F47AA // Orange
			Jmp DropColorPointer
		}
	}
	else if(DropColorPointer==ITEM2(0,51))
	{
		_asm
		{
			Mov DropColorPointer,0x005F4918 // Purple
			Jmp DropColorPointer
		}
	}
	else if
		(DropColorPointer==ITEM2(14,14))
	{
		_asm
		{
			mov DropColorPointer,0x005F439E//Yellow
			jmp DropColorPointer
		}
	}
	else
		{
		_asm{
			Mov DropColorPointer,0x005F47BC//Next
			Jmp DropColorPointer
		}
	}
}

int __fastcall SelectServerBarPosition(int a1, int a2, signed int a3, signed int a4, char a5)
{
	return DisplayInfoBarCharacter(a1,a2,a3+170,a4+45,a5);
}

BOOL APIENTRY DllMain(HMODULE hModule,DWORD ul_reason_for_call,LPVOID lpReserved) // OK
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
		{
			hins = (HINSTANCE)hModule;
			gController.Instance = hModule;
			gTrayMode.Init(hModule);
		}
			break;
		case DLL_PROCESS_DETACH:
		{
			UnhookWindowsHookEx(m_Keyboard1);
			UnhookWindowsHookEx(m_Keyboard2);
		}
			break;
		case DLL_THREAD_ATTACH:
			break;
			case DLL_THREAD_DETACH:
			break;
	}

	return 1;
}
