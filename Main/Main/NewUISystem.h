#pragma once
#define TW_SAFEZONE									( 0x0001)
#define TW_SAFEZONE									( 0x0001)
#define TW_CHARACTER								( 0x0002)
#define TW_NOMOVE									( 0x0004)
#define TW_NOGROUND									( 0x0008)
#define TW_WATER									( 0x0010)
#define TW_ACTION									( 0x0020)
#define TW_HEIGHT									( 0x0040)
#define TW_CAMERA_UP								( 0x0080)
#define TW_NOATTACKZONE								( 0x0100)
#define TW_ATT1										( 0x0200)
#define TW_ATT2										( 0x0400)
#define TW_ATT3										( 0x0800)
#define TW_ATT4										( 0x1000)
#define TW_ATT5										( 0x2000)
#define TW_ATT6										( 0x4000)
#define TW_ATT7										( 0x8000)
#define TERRAIN_SCALE								100.f
#define TERRAIN_SIZE								256
#define TERRAIN_SIZE_MASK							255
#define EQUIPMENT_WEAPON_RIGHT 0
#define EQUIPMENT_WEAPON_LEFT  1
#define EQUIPMENT_HELM         2
#define EQUIPMENT_ARMOR        3
#define EQUIPMENT_PANTS        4
#define EQUIPMENT_GLOVES       5
#define EQUIPMENT_BOOTS        6
#define EQUIPMENT_WING         7
#define EQUIPMENT_HELPER       8
#define EQUIPMENT_AMULET       9
#define EQUIPMENT_RING_RIGHT   10
#define EQUIPMENT_RING_LEFT    11
#define MAX_EQUIPMENT_INDEX			12

typedef struct tagEQUIPMENT_ITEM
{
	int x, y;
	int width, height;
	DWORD dwBgImage;
} EQUIPMENT_ITEM;

typedef struct
{
	char			byClass[16];
	DWORD* m_pNewUIMng;
	DWORD* m_pNewUI3DRenderMng;
	DWORD* m_pNewInventoryCtrl1;
	DWORD* m_pNewInventoryCtrl2;
	DWORD* m_pNewInventoryCtrl3;
	POINT			m_Pos;
	EQUIPMENT_ITEM	m_EquipmentSlots[MAX_EQUIPMENT_INDEX];
	int				m_iPointedSlot;
	char			m_BtnRepair[172];
	char			m_BtnExit[172];
	char			m_BtnMyShop[172];
	DWORD			m_MyShopMode;
	DWORD			m_RepairMode;
	DWORD			m_dwStandbyItemKey;
	bool			m_bRepairEnableLevel;
	bool			m_bMyShopOpen;
} UIMyInventory;

typedef struct
{
	BYTE    byClass[12];
	DWORD* m_pNewUIMng;
	POINT   m_Pos;
	char    m_BtnClose[172];
	bool    m_bAutoAttack;
	bool    m_bWhisperSound;
	bool    m_bSlideHelp;
	int     m_iVolumeLevel;
	int     m_iRenderLevel;
} NewUIOption;

#define GetInstance												((int(*)()) 0x00861110)
#define GetNewUIManager											((int(__thiscall*)(void* thisa)) 0x00860B50)
#define GetNewUI3DRenderMng										((int(__thiscall*)(int thisa)) 0x00860B60)
#define GetNewUIHotKey											((int(__thiscall*)(int thisa)) 0x00860B80)

#define IsImpossibleHideInterface									((bool(__stdcall*)(int dwKey)) 0x00860CE0)

#define CNewUISystem_IsVisible									((bool(__thiscall*)(int thisa, int dwKey)) 0x0085EC20)
#define CNewUISystem_HideSystem									((void(__thiscall*)(int thisa, int dwKey)) 0x0085F9A0)
#define CNewUISystem_ShowSystem									((void(__thiscall*)(int thisa, int dwKey)) 0x0085EC50)
#define CNewUISystem_ToggleSystem								((void(__thiscall*)(int thisa, int dwKey)) 0x00860660)
#define CNewUISystem_HideAll									((void(__thiscall*)(int thisa)) 0x008606B0)
#define CNewUISystem_LoadMainSceneInterface						((bool(__thiscall*)(int *thisa)) 0x0085A330)
#define PetInfoWindow_OpenningProcess							((void(__thiscall*)(int thisa)) 0x0084EAE0)
#define CNewUIManager_ShowInterface								((void(__thiscall*)(int thisa, DWORD dwKey, bool bShow)) 0x00815F50)

#define sub_83CBE0												((int   (__thiscall*)(void *thisa)) 0x0083CBE0)
#define CNewUISystem_GetUI_NewItemMng							((int(__thiscall*)(int thisa))0x00861240)
#define CNewUISystem_GetUI_NewMyInventory						((int(__thiscall*)(int thisa))0x00861260)
#define CNewUISystem_GetUI_NewMyShopInventory					((int(__thiscall*)(int thisa))0x00861400)
#define CNewUISystem_GetInventoryCtrl							((int(__thiscall*)(void *thisa, int a2))0x0083C710)
#define CNewUISystem_GetTargetInventoryCtrl						((signed int(__thiscall*)(void *thisa, WORD **a2))0x0083C6B0)
#define MyShop_pNewInventoryCtrl								((int(__thiscall*)(int thisa))0x00668850)
#define MyMix_pNewInventoryCtrl									((int(__thiscall*)(int thisa))0x0082C780)
#define PlayBuffer												((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)
#define IsPress													((bool  (__cdecl*)(int iVirtKey))0x00791070)
#define pGetUIChaosMachine							((int(__thiscall*)(int a1)) 0x008612C0)
#define pGetTradeWindow								((int(__thiscall*)(int thisa)) 0x00861540)
#define InventoryCtrl_FindItemAtPt					((ITEM*(__thiscall*)(void* thisa, int x, int y)) 0x007DAC10)
#define InventoryCtrl_FindEmptySlot					((int(__thiscall*)(void* thisa, IN int cx, IN int cy)) 0x007DACA0)
#define InventoryCtrl_RemoveItem					((void(__thiscall*)(int thisa, ITEM* pItem)) 0x007DA480)
#define InventoryCtrl_FindItem						((ITEM*(__thiscall*)(int thisa, int LinealPos)) 0x007DA760)
#define GetMixInventoryEquipmentIndex				((int(__thiscall*)(void *thisa)) 0x0050B840)
#define RemoveItemForSlot							((void(__thiscall*)(int thisa, int slot)) 0x00834320)
#define g_MixRecipeMgr								&*(LPVOID*)0xEBB848
#define BeginBitmap									((void(*)()) 0x637770)
#define EndOpengl									((void(*)()) 0x6366F0)
#define EndBitmap									((void(*)()) 0x00637870)
#define MouseUpdateTime								*(DWORD*)0x81C03B4
#define MouseUpdateTimeMax							*(DWORD*)0xE616D0
#define ResetMouseLButton							((void(__cdecl*)()) 0x0083C080)
#define MouseOnWindow								*(BYTE*)0x813DDCE
#define GetUI3D										((int(__thiscall*)(int thisa))0x00861AA0)

#define MouseLButton								*(bool*)0x8793386
#define MouseLButtonPop								*(bool*)0x8793385
#define MouseLButtonPush							*(bool*)0x8793384
#define MouseRButton								*(bool*)0x8793383
#define MouseRButtonPop								*(bool*)0x8793382
#define MouseRButtonPush							*(bool*)0x8793381
#define MouseLButtonDBClick							*(bool*)0x8793380
#define MouseWheel									*(int*)0x879337C
#define MouseRButtonPress							*(DWORD*)0x8793400
#define MouseX										*(int*)0x879340C
#define MouseY										*(int*)0x8793410

#define RButtonPressTime							*(float*)0x81C03E4
#define WorldTime									*(float*)0x5EF5A1C
#define RButtonPopTime								*(float*)0x81C03E0

namespace SEASON6B
{
	enum INTERFACE_LIST
	{
		INTERFACE_BEGIN = 0x00,

		INTERFACE_FRIEND,
		INTERFACE_MOVEMAP,
		INTERFACE_PARTY,
		INTERFACE_MYQUEST,
		INTERFACE_NPCQUEST,
		INTERFACE_GUILDINFO,
		INTERFACE_TRADE,
		INTERFACE_STORAGE,
		INTERFACE_MIXINVENTORY,
		INTERFACE_COMMAND,
		INTERFACE_PET,
		INTERFACE_NPCSHOP,
		INTERFACE_INVENTORY,
		INTERFACE_MYSHOP_INVENTORY,
		INTERFACE_PURCHASESHOP_INVENTORY,
		INTERFACE_CHARACTER,
		INTERFACE_NPCBREEDER,
		INTERFACE_SERVERDIVISION,
		INTERFACE_DEVILSQUARE,
		INTERFACE_BLOODCASTLE,

		INTERFACE_NPCGUILDMASTER,
		INTERFACE_GUARDSMAN,
		INTERFACE_SENATUS,
		INTERFACE_GATEKEEPER,
		INTERFACE_GATESWITCH,
		INTERFACE_CATAPULT,
		INTERFACE_REFINERY,
		INTERFACE_REFINERYINFO,
		INTERFACE_KANTURU2ND_ENTERNPC,
		INTERFACE_CURSEDTEMPLE_NPC,
		INTERFACE_CURSEDTEMPLE_GAMESYSTEM,
		INTERFACE_CURSEDTEMPLE_RESULT,
		INTERFACE_CHATINPUTBOX,
		INTERFACE_WINDOW_MENU,
		INTERFACE_OPTION,
		INTERFACE_HELP,
		INTERFACE_ITEM_EXPLANATION,
		INTERFACE_SETITEM_EXPLANATION,
		INTERFACE_QUICK_COMMAND,
		INTERFACE_KANTURU_INFO,
		INTERFACE_CHATLOGWINDOW,
		INTERFACE_PARTY_INFO_WINDOW,
		INTERFACE_BLOODCASTLE_TIME,
		INTERFACE_CHAOSCASTLE_TIME,
		INTERFACE_BATTLE_SOCCER_SCORE,
		INTERFACE_SLIDEWINDOW,
		INTERFACE_HERO_POSITION_INFO,
		INTERFACE_MESSAGEBOX,
		INTERFACE_DUEL_WINDOW,
		INTERFACE_CRYWOLF,
		INTERFACE_NAME_WINDOW,
		INTERFACE_SIEGEWARFARE,
		INTERFACE_MAINFRAME,
		INTERFACE_SKILL_LIST,
		INTERFACE_ITEM_ENDURANCE_INFO,
		INTERFACE_BUFF_WINDOW,
		INTERFACE_PARTCHARGE_SHOP,
		INTERFACE_MASTER_LEVEL,
		INTERFACE_GOLD_BOWMAN,
		INTERFACE_GOLD_BOWMAN_LENA,
		INTERFACE_LUCKYCOIN_REGISTRATION,
		INTERFACE_EXCHANGE_LUCKYCOIN,
		INTERFACE_DUELWATCH,
		INTERFACE_DUELWATCH_MAINFRAME,
		INTERFACE_DUELWATCH_USERLIST,
		INTERFACE_INGAMESHOP,
		INTERFACE_DOPPELGANGER_NPC,
		INTERFACE_DOPPELGANGER_FRAME,
		INTERFACE_QUEST_PROGRESS,
		INTERFACE_NPC_MENU,
		INTERFACE_QUEST_PROGRESS_ETC,
		INTERFACE_EMPIREGUARDIAN_NPC,
		INTERFACE_EMPIREGUARDIAN_TIMER,
		INTERFACE_MINI_MAP,
		INTERFACE_NPC_DIALOGUE,
		INTERFACE_STAMINA_GAUGE,
		INTERFACE_GENSRANKING,
		INTERFACE_UNITEDMARKETPLACE_NPC_JULIA,
		INTERFACE_LUCKYITEMWND,
		INTERFACE_HOTKEY,
		INTERFACE_3DRENDERING_CAMERA_BEGIN,
		INTERFACE_3DRENDERING_CAMERA_END = INTERFACE_3DRENDERING_CAMERA_BEGIN + 24,
		INTERFACE_ITEM_TOOLTIP,
		INTERFACE_END,
		INTERFACE_COUNT = INTERFACE_END - 2,
		INTERFACE_PETMUUN = 110,
		INTERFACE_CMENU,
	};
}

#define AccessModel									((void(__cdecl*)(int Type, char *Dir, char *FileName,int i)) 0x00614D10)
#define OpenTexture									((void(__cdecl*)(int Model,char *SubFolder,int Wrap, int Type,bool Check)) 0x00614710)

void VerifyWindow();
class CNewUISystem
{
public:
	CNewUISystem();
	virtual ~CNewUISystem();
	void ShowInterface(DWORD dwKey, bool bShow = true);
	bool IsVisible(DWORD dwKey);
	void Show(DWORD dwKey);
	void Hide(DWORD dwKey);
	void Toggle(DWORD dwKey);
	void HideAll();

	int GetUI_NewMyInventory();
	int GetOwnerMyInventory();
	int GetTargetOwnerMyInventory();

	int GetOwnerShopInventory();
	int GetOwnerMixInventory();
	void Init();
	static bool __thiscall LoadMainSceneInterface(int* thisa);

};

extern CNewUISystem g_pNewUISystem;