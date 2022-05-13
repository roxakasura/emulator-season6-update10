#pragma once
#include "_struct.h"
#include "Protocol.h"

#define MAX_BUFF_SLOT_INDEX					16
#define MAX_ID_SIZE							10
#define EQUIPMENT_LENGTH					17
#define MODEL_FENRIR_BLACK					384
#define MODEL_FENRIR_RED					385
#define MODEL_FENRIR_BLUE					386
#define MODEL_FENRIR_GOLD					387
#define MODEL_DARK_HORSE					226
#define MODEL_PEGASUS						323
#define MODEL_UNICON						233
#define MODEL_BUTTERFLY01					176

typedef struct
{
	char    Name[11];
	BYTE    Number;
	BYTE    Map;
	BYTE    x;
	BYTE    y;
	int     currHP;
	int     maxHP;
	BYTE    stepHP;
	int     index;
} PARTY_t;

typedef struct
{
	char				byClass[12];
	DWORD* m_pNewUIMng;      //-- 12
	POINT				m_Pos;            //-- 16
	char				m_BtnExit[172];   //-- 24
	char				m_BtnPartyExit[5][172]; //-- 196
	int					m_iSelectedCharID; //-- 1056
	char				m_bParty;          //-- 1060
} PartyInfoWindow;
//--
typedef struct //-- GetItem
{
	PSBMSG_HEAD   Header;
	BYTE          Result;
	BYTE          Item[MAX_ITEM_INFO];
} PRECEIVE_GET_ITEM, * LPPRECEIVE_GET_ITEM;

typedef struct //-- itemlist
{
	PSWMSG_HEAD  Header;
	BYTE         Value;
} PHEADER_DEFAULT_SUBCODE_WORD, * LPPHEADER_DEFAULT_SUBCODE_WORD;

typedef struct //-- GetList Item
{
	BYTE          Index;
	BYTE          Item[MAX_ITEM_INFO];
} PRECEIVE_INVENTORY, * LPPRECEIVE_INVENTORY;

typedef struct //-- Get Item Modify
{
	PSBMSG_HEAD   Header;
	BYTE          SubCode;
	BYTE          Index;
	BYTE          Item[MAX_ITEM_INFO];
} PHEADER_DEFAULT_SUBCODE_ITEM, * LPPHEADER_DEFAULT_SUBCODE_ITEM;

typedef struct //-- Get Item Modify
{
	PBMSG_HEAD    Header;
	BYTE          SubCode;
	BYTE          Index;
	BYTE          Item[MAX_ITEM_INFO];
} PHEADER_SUBCODE_ITEM, * LPPHEADER_SUBCODE_ITEM;

typedef struct //-- Item Drop
{
	PSBMSG_HEAD  Header;
	BYTE         KeyH;
	BYTE         KeyL;
} PHEADER_DEFAULT_KEY, * LPPHEADER_DEFAULT_KEY;

typedef struct
{
	PSBMSG_HEAD  Header;
	BYTE         SubCode;
	BYTE         Value;
} PHEADER_DEFAULT_SUBCODE, * LPPHEADER_DEFAULT_SUBCODE;

typedef struct //-- Durabilidad
{
	PSBMSG_HEAD  Header;
	BYTE         Key;
	BYTE         Value;
} PHEADER_DEFAULT_VALUE_DUR, * LPPHEADER_DEFAULT_VALUE_DUR;

typedef struct {
	PWMSG_HEAD   Header;
	BYTE         Value;
} PWHEADER_DEFAULT_WORD, * LPPWHEADER_DEFAULT_WORD;

//receive other map character
typedef struct {
	BYTE         KeyH;
	BYTE         KeyL;
	BYTE         PositionX;
	BYTE         PositionY;
	BYTE         Class;
	BYTE         Equipment[EQUIPMENT_LENGTH];
	BYTE         ID[MAX_ID_SIZE];
	BYTE         Target_X;
	BYTE         Target_Y;
	BYTE         Path;
	BYTE         MuunItem[2];
	BYTE         s_BuffCount;
	BYTE         s_BuffEffectState[MAX_BUFF_SLOT_INDEX];
} PCREATE_CHARACTER, * LPPCREATE_CHARACTER;

typedef struct
{
	BYTE         KeyH;
	BYTE         KeyL;
	BYTE         PositionX;
	BYTE         PositionY;
	BYTE         TypeH;
	BYTE         TypeL;
	BYTE         ID[MAX_ID_SIZE];
	BYTE         Target_X;
	BYTE         Target_Y;
	BYTE         Path;
	BYTE         Class;
	BYTE         Equipment[EQUIPMENT_LENGTH];
	BYTE         MuunItem[2];
	BYTE         s_BuffCount;
	BYTE		 s_BuffEffectState[MAX_BUFF_SLOT_INDEX];
} PCREATE_TRANSFORM, * LPPCREATE_TRANSFORM;
//--
struct PMSG_MUUN_ITEM_CHANGE_RECV
{
	PSBMSG_HEAD header; // C1:4E:06
	BYTE index[2];
	BYTE ItemInfo[MAX_ITEM_INFO];
};

struct PMSG_MUUN_ITEM_STATUS_SEND
{
	PSBMSG_HEAD header; // C1:4E:07
	BYTE slot;
	BYTE status;
};

struct PMSG_MUUN_ITEM_SELL_RECV
{
	PSBMSG_HEAD header; // C1:4E:09
	BYTE result;
	DWORD money;
};

struct PMSG_MUUN_ITEM_SELL_SEND
{
	PSBMSG_HEAD header; // C3:4E:09
	BYTE slot;
};
//--
struct PMSG_MUUN_ITEM_USE_SEND
{
	PSBMSG_HEAD header; // C1:4E:08
	BYTE SourceSlot;
	BYTE TargetSlot;
	BYTE type;
};

struct PMSG_MUUN_ITEM_DROP_SEND
{
	PSBMSG_HEAD header; // C1:4E:08
	BYTE x;
	BYTE y;
	BYTE slot;
};
#define CharacterMachineEquip( x )					*(WORD *) ( *(DWORD*)0x8128AC4 + 107 * x + 4672 )
//--
#define CNewUIPartyInfoWindow_New					((char *(__thiscall*)(char *thisa)) 0x00849F10)
#define CNewUIPartyInfoWindow_Create				((bool(__thiscall*)(char *thisa, int pNewUIMng, int x, int y)) 0x0084A040)
#define CNewUIPartyInfoWindow_SetPos				((void(__thiscall*)(PartyInfoWindow* thisa, int x, int y)) 0x0084B180)
#define CNewUIPartyInfoWindow_InitButtons			((void(__thiscall*)(PartyInfoWindow* thisa)) 0x0084A0E0)
#define CNewUIPartyInfoWindow_BtnProcess			((bool(__thiscall*)(PartyInfoWindow* thisa)) 0x0084A270)
#define RenderMemberStatue							((void(__thiscall*)(PartyInfoWindow* thisa, int iIndex, PARTY_t* pMember, bool bExitBtnRender)) 0x84AD10)
#define CreatePlayerViewport						((void(__cdecl*)(BYTE *ReceiveBuffer)) 0x00641A50)
#define CreateTransformViewport						((void(__cdecl*)(BYTE *ReceiveBuffer)) 0x00642130)
//--
#define CNewUIInventoryCtrl_New						((char *(__thiscall*)(char *thisa)) 0x007D9740)
#define CNewUI3DCamera_Add3DRenderObj				((void  (__thiscall*)(char *thisa, char* pObj, float fZOrder)) 0x00772C00)
#define CNewUIInventoryCtrl_Create					((void  (__thiscall*)(char *thisa, char* pNew3DRenderMng, char* pNewItemMng, char* pOwner, int x, int y, int nColumn, int nRow)) 0x007D9ED0)
#define CNewUIInventoryCtrl_AddItem					((bool  (__thiscall*)(char *thisa, int iColumnX, int iRowY, void* pbyItemPacket)) 0x007DA0C0)
#define CNewUIMyShopInventory_MyShopProcess			((bool(__thiscall*)(int thisa)) 0x00841430)
#define IsPersonalShopBan							((bool(__cdecl*)(ITEM* iTemp)) 0x005C8780)
#define CNewUIMyShopInventory_ChangeTargetIndex		((void(__thiscall*)(int thisa, int tIndex)) 0x00842600)
#define CNewUIMyShopInventory_SetInputValueTextBox	((void(__thiscall*)(int thisa, bool blsEnable)) 0x00842590)
//--
#define CNewUIManager_AddUIObj						((void(__stdcall*)(DWORD thisa, BYTE dwKey, int pUIObj)) 0x00815700)
#define CReceiveEquipmentItem						((BOOL  (__cdecl*)(BYTE *ReceiveBuffer, BOOL bEncrypted)) 0x0064B860)
#define RenderTerrain								((void(__cdecl*)(bool EditFlag))0x005DC820)
#define RenderTerrainTile							((bool(__cdecl*)(float xf, float yf, int xi, int yi, float lodf, int lodi, bool Flag))0x005DA250)
#define SelectXF									*(float*)0x82C6A9C
#define SelectYF									*(float*)0x82C6A98
#define CollisionPosition_1							*(float*)0x8793248
#define CollisionPosition_2							*(float*)0x879324C
//--
#define InvCtrl_GetSquareIndexAtPt					((int(__thiscall*)(DWORD* thisa, int x, int y)) 0x007DC450)
#define InvCtrl_GetSquarePosAtPt					((bool(__thiscall*)(void* thisa, int x, int y, int *col, int *fil)) 0x007DC490)
#define InvCtrl_FindItemAtPt						((ITEM* (__thiscall*)(void* thisa, int mousex, int mousey, signed int *temporal)) 0x0083CAB0)
#define InvCtrl_FindEmptySlot						((int(__thiscall*)(int This, ITEM * iTemp, BYTE Type)) 0x008359C0)
#define GetSlotIndexAtPt							((int(__stdcall*)(unsigned __int8 col, unsigned __int8 fil, int temporal)) 0x0083C770)
#define FindBaseIndexByITEM							((int(__thiscall*)(void* thisa, ITEM* iTemp)) 0x007DAB80)
#define CheckEquipItem								((bool(__stdcall*)(int Slot, ITEM* iTemp)) 0x00833CB0)
#define CInventoryProcess							((bool(__thiscall*)(int thisa)) 0x00838240)
#define sub_587C00									((bool(*)( )) 0x587C00)
#define UnequipItem									((void(__thiscall*)(void *thisa, int iIndex)) 0x00833B20)
//--
#define RenderBitmapRotate							((void (__cdecl*)(int Texture,float x,float y,float Width,float Height,float Angle, float u, float v, float uWidth,float vHeight)) 0x00637E80)
#define ReceiveSetPriceResult						((void (__cdecl*)(BYTE* ReceiveBuffer)) 0x00656230)
#define IsInvenItem									((INT(__stdcall*)(short sType)) 0x0083C0C0)
//--
#define pCreateEquippingEffect						((void(__stdcall*)(ITEM* pItem)) 0x00835E40)
#define pDeleteEquippingEffect						((void(__stdcall*)(ITEM* pItem)) 0x008363D0)
#define CheckIsPetBug								((bool(__cdecl*)(ITEM* pItem)) 0x00501330)
#define InChaosCastle								((bool(__cdecl*)(int a1)) 0x004E65A0)
#define SetCharacterClass							((void(__cdecl*)(int pHero)) 0x0057F410)
#define GOBoid_CreateBug							((void(__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x00501700)
#define DisableAlphaBlend							((void(__cdecl*)( )) 0x00635F50)
#define EndRenderColor								((void(__cdecl*)())0x00637A30)
#define RenderColor									((void(__cdecl*)(float x,float y,float Width,float Height, float Alpha, int Flag)) 0x006378A0)
#define LoadBitmapA									((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define pCheckInMouse								((bool(__cdecl*)(int x, int y, int w, int h)) 0x00790B10)
#define CGetScreenWidth2							((int(*)()) 0x005C6E80)

#define World										*(DWORD*)0xE61E18
#define Hero										*(DWORD*)0x007BC4F04
#define new_Class									((int(__cdecl*)(int Type)) 0x009D00C5)
#define CharactersClient							((int   (__thiscall*)(int List, int num)) 0x0096A4C0)
#define CList										((int   (*)( )) 0x00402BC0)
#define FindCharacterIndex							((int   (__cdecl*)(int Key)) 0x0057D9A0)
#define EnableAlphaTest								((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define CreateItemConvertByte						((ITEM* (__thiscall*)(int a1, void *lp)) 0x007E1B10)
//-- Utilidad PickUp
#define EquipmentItem									*(bool*)0x81F6BEF
#define SendDropItem									*(DWORD*)0xE61FCC
#define SendGetItem										*(DWORD*)0xE61FC8
#define ms_pPickedItem									*(DWORD*)0x9816F7C
#define GetPickedItem									((int   (*)( )) 0x007DD0F0)
#define DeletePickedItem								((void  (*)( )) 0x007DD1B0)
#define GetOwnerInventory								((int (__thiscall*)(int Picket)) 0x007D9410)
#define PickedItem_CanMove								((bool (__thiscall*)(int m_pNewInventoryCtrl, int iTargetIndex, ITEM* pItemObj)) 0x007DC670)
//#define GetTargetLinealPos								((bool (__stdcall*)(int m_pNewInventoryCtrl)) 0x007D95E0)
#define HidePickedItem									((void (__stdcall*)(int pPickedItem)) 0x007D9660)
#define BackupPickedItem								((void  (__thiscall*)( )) 0x007DD230)

#define GetInventSourceLinealPos						((int(__stdcall*)(int thisa, int a2))0x0083C480)
#define GetInventSTargetLinealPos						((int(__thiscall*)(int thisa, int a2, int a3))0x0083C440)

#define GetTargetLinealPos								((int(__thiscall*)(WORD **thisa, void *a2))0x007D95E0)
#define GetSourceLinealPos								((int(__thiscall*)(int thisa))0x007D94E0)
#define GetMouseItem									((ITEM* (__thiscall*)(int thisa)) 0x007D9430)
#define CreateItemPick									((ITEM* (__stdcall*)(ITEM*)) 0x007E1E50)
#define SetPickItem										((bool  (__cdecl*)(int a4, const void *a5)) 0x007DD100)
#define CreatePickedItem								((bool(__cdecl*)(int a4, const void *a5)) 0x007DD100)
#define RenderItemInfo								((void(__thiscall*)(int thisa, int sx,int sy,ITEM *ip,bool Sell, int Inventype, bool bItemTextListBoxUse)) 0x007E3E30)

#define SendRequestEquipmentItem					((char  (__cdecl*)(BYTE SourceFlag, BYTE SourceSlot, ITEM* pItem, BYTE TargetFlag, BYTE TargetSlot)) 0x005BD850)

#define RenderNumArrow								((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E02B0)
#define RenderEquipedHelperLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007DFDB0)
#define RenderEquipedPetLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0180)
#define RenderSummonMonsterLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0220)
#define	CreateBarHP									((int(__stdcall*)(int PosX, int PosY, char * name, int currentLife, int MaxLife, bool a6)) 0x007DFA60)
#define GetBaseClass								((BYTE(__cdecl*)(BYTE iClass)) 0x00405230)
#define GetStepClass								((BYTE(__cdecl*)(BYTE byClass)) 0x005875C0)
#define EnableAlphaBlend							((void(__cdecl*)()) 0x00636070)
#define RenderImageB								((void(__cdecl*)(GLuint uiImageType, float x, float y, float width, float height)) 0x00790B50)
#define CRenderBitmaps								((void(__cdecl*)(int Texture,float x,float y,float Width,float Height,float u,float v,float uWidth,float vHeight,bool Scale,bool StartScale,float Alpha)) 0x00637C60)
#define g_WindowWidth								0xE61E58
#define g_WindowHeight								0xE61E5C
#define CharacterMachine							*(DWORD*)0x8128AC4
//-- Modelos
#define CameraViewNear								*(float*)0xE61E38
#define CameraViewFar								*(float*)0xE61E3C
#define glViewport2									((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x006363D0)
#define gluPerspective_2							((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x006358A0)
#define GetOpenGLMatrixF							((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define EnableDepthTestF							((void(*)()) 0x00635DE0)
#define EnableDepthMaskF							((void(*)()) 0x00635E40)
#define CameraMatrixF								(LPVOID)0x87933A0
#define CRenderItem3D								((int(__cdecl*)(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp)) 0x005CF310)
#define pItem_Attribute								*(DWORD*)0x8128AC0
#define sub_58AA80								   ((int   (__cdecl*)(DWORD)) 0x58AA80)

void DelectIndexPetBug(OBJECT* Owner, int Index);
void g_DeleteMuunBug(OBJECT *Owner, int Index);

class CNewUIPetInfoWindow
{
public:
	CNewUIPetInfoWindow();
	virtual ~CNewUIPetInfoWindow();
	//-- pet muun
	static void CreateEquippingEffect(ITEM* pItem);
	static void DeleteEquippingEffect(ITEM* pItem);

	//-- Protocolo
	void ReceiveGetItem(BYTE* ReceiveBuffer);
	void ReceiveInventory(BYTE* ReceiveBuffer);
	void ReceiveModifyItem(BYTE* ReceiveBuffer);
	void ReceiveDropItem(BYTE* ReceiveBuffer);
	void ReceiveUseStateItem(BYTE* ReceiveBuffer);
	void ReceiveDeleteInventory(BYTE* ReceiveBuffer);
	void ReceiveDurability(BYTE* ReceiveBuffer);
	void ItemChangeRecv(PMSG_MUUN_ITEM_CHANGE_RECV *lpMsg);

	void ReceiveItemChange(BYTE* ReceiveBuffer);
	//--
	ITEM* FindbySlot(int iIndex);
	int FindbySlotEmpty(int ExiIndex);
	void DeleteItem(int iIndex);
	bool InsertItem(BYTE iIndex, ITEM* pbyItemPacket);
	//-- InterfaceLeft
	BYTE PetEquipedHPBar(int iX, int iY);
	BYTE RenderEquipedMuunLife(int sx, int sy, int Slot);
	static void __thiscall RenderInterfaceLeft(int thisa);
	//--
	bool Create(int pNewUIMng);
	static void LoadImages();
	static bool __thiscall Render(PartyInfoWindow* thisa);
	static bool __thiscall BtnProcess(PartyInfoWindow* thisa);
	static void __thiscall InitButtons(PartyInfoWindow* thisa);
	static bool __thiscall CheckOpenWindows(int thisa, DWORD dwKey);
	static void __thiscall HideWindows(int thisa, DWORD dwKey);
	//--
	static bool __thiscall InventoryProcess(int thisa);
	static void UI_2DEffectCallback(bool dwParamA);
	static void RenderTipTextList(int sx, int sy, int TextNum, int Tab, int iSort, int iRenderPoint, BOOL bUseBG);
	static int __thiscall Storage_GetSourceLinePos(int thisa);

public:
	void Init();
	int Wnd_Pag;
	ITEM* byItem;
	POINT m_ptPos;
	bool m_byState;
	int m_iMixEffectTimer;
	type_vec_item m_vecItem;
	DWORD* m_pdwItemCheckBox;
	char* m_pNewPetInfoWindow;
};

extern CNewUIPetInfoWindow g_pMuunInventory;
extern int bPicked;
extern int SlotPickBackup;
extern int PickSelect;
extern int PickTooltip;
extern int IndexEffect;

extern int m_bySendSlot;
extern int m_byTypeSend;
extern int m_byTypeRecv;