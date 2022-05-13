#pragma once

#include "stdafx.h"
#include "import.h"
#define SLOT_PET          0
#define MAX_OBJECT			500
#define MAX_WIN_WIDTH		640
#define MAX_WIN_HEIGHT		480
#define LUCKYWHELLATCTIVE	1
#define ITEMSMIT			0
#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)
void testfunc();

//item index
#define MAX_ITEM_INDEX     512
#define ITEM_SWORD		 (0)   //pal,etc
#define ITEM_AXE		 (1*MAX_ITEM_INDEX)  //ran,dru
#define ITEM_MACE		 (2*MAX_ITEM_INDEX)  //ran,nec
#define ITEM_SPEAR		 (3*MAX_ITEM_INDEX)  //ama
#define ITEM_BOW		 (4*MAX_ITEM_INDEX)  //ama
#define ITEM_STAFF		 (5*MAX_ITEM_INDEX)  //soc
#define ITEM_SHIELD		 (6*MAX_ITEM_INDEX) 
#define ITEM_HELM		 (7*MAX_ITEM_INDEX)
#define ITEM_ARMOR		 (8*MAX_ITEM_INDEX)
#define ITEM_PANTS		 (9*MAX_ITEM_INDEX)
#define ITEM_GLOVES		 (10*MAX_ITEM_INDEX)
#define ITEM_BOOTS		 (11*MAX_ITEM_INDEX)
#define ITEM_WING		 (12*MAX_ITEM_INDEX)
#define ITEM_HELPER		 (13*MAX_ITEM_INDEX)
#define ITEM_POTION  	 (14*MAX_ITEM_INDEX)
#define ITEM_ETC 		 (15*MAX_ITEM_INDEX)

enum ObjectID
{
		eFlag01=1,
		eFlag02,
		eFlag03,
		eFlag04,
		eFlag05,
		eFlag06,
		eFlag07,
		eFlag08,
		eFlag09,
		eFlag10,
		eFlag11,
		eFlag12,
		eFlag13,
		eFlag14,
		eFlag15,
		eFlag16,
		eFlag17,
		eFlag18,
		eFlag19,
		eFlag20,
		eFlag21,
		eFlag22,
		eTIME,
		eRankPANEL_MAIN,
		eRanking,
		eSAMPLEBUTTON,
		eSAMPLEBUTTON2,
		eVip_MAIN,
		eVip_TITLE,
		eVip_FRAME,
		eVip_FOOTER,
		eVip_DIV,
		eVip_CLOSE,
		eVip_BRONZE,
		eVip_SILVER,
		eVip_GOLD,
		eVip_PLATINUM,
		
		eSELECTCHAR_LEFT,
		eSELECTCHAR_RIGHT,
		eVip_STATUS,
		eRanking_MAIN,
		eRanking_CLOSE,
		eLogo,
		eMenu,
		eMenuBG,
		eMenu_MAIN,
		eMenu_TITLE,
		eMenu_FRAME,
		eMenu_FOOTER,
		eMenu_DIV,
		eMenu_CLOSE,
		eMenu_OPT1,
		eMenu_OPT2,
		eMenu_OPT3,
		eMenu_OPT4,
		eMenu_OPT6,
		eMenu_OPT20,
		eCommand_MAIN,
		eCommand_TITLE,
		eCommand_FRAME,
		eCommand_FOOTER,
		eCommand_DIV,
		eCommand_CLOSE,
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG,
		eOFFTRADE_OPEN,
		eSTORE_CLOSE,

		//Minimap
		ePLAYER_POINT,
		eNULL_MAP,
		eLORENCIA_MAP,
		eDUNGEON_MAP,
		eDEVIAS_MAP,
		eNORIA_MAP,
		eLOSTTOWER_MAP,
		eATLANS_MAP,
		eTarkan_MAP,
		eElbeland_MAP,
		eICARUS_MAP,
		eLANDOFTRIALS_MAP,
		eAIDA_MAP,
		eCRYWOLF_MAP,
		eKANTRU_MAP,
		eKANTRU3_MAP,
		eBARRACKS_MAP,
		eCALMNESS_MAP,
		eRAKLION_MAP,
		eVULCANUS_MAP,
		eKALRUTAN_MAP,
		eKALRUTAN2_MAP,

		eCONFIRM_MAIN,
		eCONFIRM_BTN_OK,
		eCONFIRM_BTN_CANCEL,
		eCONFIRM_TITLE,
		eCONFIRM_FRAME,
		eCONFIRM_FOOTER,
		eCONFIRM_DIV,

		eNextCommand,
		ePrevCommand,

		eNextEvent,
		ePrevEvent,
		eNewInterfaceParty,
		eNewInterfaceCharacter,
		eNewInterfaceInventory,

		//Interface ZenRud
		eMoney1,
		eMoney2,
		eButtonDButton,
		eMenuR,
		eMenuSobre,
		eMenuClick,
		eLOGO,
		//jewelbank
		eJEWELBANK_CLOSE,
		eJEWELBANK_MAIN,
		eJEWELBANK_TITLE,
		eJEWELBANK_FRAME,
		eJEWELBANK_FOOTER,
		eJEWELBANK_POINT,
		eJEWELBANK_LINE,
		eJEWELBANK_DIV,
		eJEWELBANK_PAGEUP1,
		eJEWELBANK_PAGEUP2,
		eJEWELBANK_PAGEUP3,
		eJEWELBANK_PAGEUP4,
		eJEWELBANK_PAGEUP5,
		eJEWELBANK_PAGEUP6,
		eJEWELBANK_PAGEUP7,
		eJEWELBANK_PAGEUP8,
		eJEWELBANK_PAGEUP9,
		eJEWELBANK_PAGEUP10,
		eJEWELBANK_PAGEUP11,
		eJEWELBANK_PAGEDN1,
		eJEWELBANK_PAGEDN2,
		eJEWELBANK_PAGEDN3,
		eJEWELBANK_PAGEDN4,
		eJEWELBANK_PAGEDN5,
		eJEWELBANK_PAGEDN6,
		eJEWELBANK_PAGEDN7,
		eJEWELBANK_PAGEDN8,
		eJEWELBANK_PAGEDN9,
		eJEWELBANK_PAGEDN10,
		eJEWELBANK_PAGEDN11,
		eJEWELBANK_NEXTWIN,
		eJEWELBANK_PREVWIN,
		//luckywheel
		eLuckyWheelMain,
		eLuckyWheelStart,
		eLuckyWheelStart2,
		eLuckyWheelPanel,
		eBXH,
		eQuaMocRSMain,
		eQuaMocRSNhan,
		eQuaMocRSPanel,
		eCloseLuckyWheelKG,

		//test
		eToolTip_ID,
		CharacterSelect,
		CharacterSelect_Button1,
		CharacterSelect_Button2,
		CharacterSelect_Button3,
		CharacterSelect_Button4,
		CharacterSelect_Button5,	
		CharacterSelect_Button6,	
		CharacterSelect_Button7,	
		CharacterSelect_Button8,	
		CharacterSelect_Button9,	
		CharacterSelect_Button10,
		CharacterSelect_Button11,
		//news
		SelectCharacterS0_01,
		SelectCharacterS0_02,

		//antilag
		eCheck,
		eUnCheck,
		//new menu ops
		eUSERSPANEL_FOG,
		eUSERSPANEL_MINIMAP,
		eUSERSPANEL_TIME,
		eUSERSPANEL_GLOW,
		eUSERSPANEL_FPS,
		eUSERSPANEL_CHAT,
		eUSERSPANEL_DRAGON,
		eUSERSPANEL_OPTION,
		eUSERSPANEL_LINE,
		//PANEL ANTILAG
		eUSERSPANEL_INVIS1,
		eUSERSPANEL_INVIS2,
		eUSERSPANEL_INVIS3,
		eUSERSPANEL_INVIS4,
		eUSERSPANEL_INVIS5,
		eUSERSPANEL_INVIS6,
		eUSERSPANEL_INVIS7,
		ePanelSelectServerMain,
		ePanelSelectServerClose,
		//stats advanced
		ex_INFO_2,
		eADVANCE_STAT_INFO,
		//downgrade options interface
		eMainS2right,
		eMainS2middle,
		eMainS2left,
		eSkillBox,
		eDragonLeft,
		eDragonRight,
		eCharacter,
		eInventory,
		eParty,
		eFriend,
		eFastMenu,
		eShop,
		eGuild,
		eCommandWindow,
		ebtnWisper,
		eWhinCkeck,
		eCheckBoxCommand,
		eOrelhinha,
		eJanelinha,
		eLuizinha,

		//ex803
		eMainEx700Exp,
		eMainEx700,
		eShop1,
		eShop2,
		eCharacter1,
		eCharacter2,
		eInventory1,
		eInventory2,
		eQuest1,
		eQuest2,
		eCommunity1,
		eCommunity2,
		eSystem1,
		eSystem2,
		ePetInvFrame,
		eOption_I3,
		eInventoryFrame_I4,
		ePopup_bg_big01,
		eHuntRecord_I1,
		eButton1,
		eButton2,
		eButton3,
		eButton4,
		eButton5,
		ePT_PERSONAL_SEARCH_MAIN,
		ePT_PERSONAL_SEARCH_TITLE,
		ePT_PERSONAL_SEARCH_FRAME,
		ePT_PERSONAL_SEARCH_FOOTER,
		ePT_PERSONAL_SEARCH_DIV,
		ePT_PERSONAL_SEARCH_CLOSE,
		ePT_PERSONAL_SEARCH_L,
		ePT_PERSONAL_SEARCH_R,
		ePT_PERSONAL_SEARCH_INFO,
		ePT_PERSONAL_SEARCH_INFOBG,
		ePT_PERSONAL_SEARCH_PAGEUP1,
		ePT_PERSONAL_SEARCH_PAGEUP2,
		ePT_PERSONAL_SEARCH_PAGEUP3,
		ePT_PERSONAL_SEARCH_PAGEUP4,
		ePT_PERSONAL_SEARCH_PAGEUP5,
		ePT_PERSONAL_SEARCH_PAGEUP6,
		ePT_PERSONAL_SEARCH_PAGEUP7,
		ePT_PERSONAL_SEARCH_PAGEUP8,
		ePT_PERSONAL_SEARCH_PAGEUP9,
		ePT_PERSONAL_SEARCH_PAGEUP10,
		//
		eADDPOINT_MAIN,
		eADDPOINT_TITLE,
		eADDPOINT_FRAME,
		eADDPOINT_FOOTER,
		eADDPOINT_DIV,
		eADDPOINT_OK,
		eADDPOINT_CLOSE,
		eADDPOINT_INFOBG,
		eADDPOINT_INFOBG1,
		eADDPOINT_INFOBG2,
		eADDPOINT_INFOBG3,
		eADDPOINT_INFOBG4,
		eADDPOINT_INFOBG5,
		eADDPOINT_POINTUP,
		eADDPOINT_RESET,
		eADDPOINT_TABLE,
		eADDPOINT_TABLE2,
		eADDPOINT_TABLE3,
		ButtonStartAttack,
		ButtonSettings,
		ButtonStart,
		ButtonStop,
///MuunSystem
		eCONFIRM_MUUNBTN_OK,
		eCONFIRM_MUUN,
		eCONFIRM_MUUNBTN_CANCEL,
//
		eADDPOINT2_MAIN,
		eADDPOINT2_TITLE,
		eADDPOINT2_FRAME,
		eADDPOINT2_FOOTER,
		eADDPOINT2_DIV,
		eADDPOINT2_OK,
		eADDPOINT2_CLOSE,
//
		eADDPOINT3_MAIN,
		eADDPOINT3_TITLE,
		eADDPOINT3_FRAME,
		eADDPOINT3_FOOTER,
		eADDPOINT3_DIV,
		eADDPOINT3_OK,
		eADDPOINT3_CLOSE,
		//
		eADDPOINT4_MAIN,
		eADDPOINT4_TITLE,
		eADDPOINT4_FRAME,
		eADDPOINT4_FOOTER,
		eADDPOINT4_DIV,
		eADDPOINT4_OK,
		eADDPOINT4_CLOSE,
		//
		eADDPOINT5_MAIN,
		eADDPOINT5_TITLE,
		eADDPOINT5_FRAME,
		eADDPOINT5_FOOTER,
		eADDPOINT5_DIV,
		eADDPOINT5_OK,
		eADDPOINT5_CLOSE,
		//
		eADDPOINT6_MAIN,
		eADDPOINT6_TITLE,
		eADDPOINT6_FRAME,
		eADDPOINT6_FOOTER,
		eADDPOINT6_DIV,
		eADDPOINT6_OK,
		eADDPOINT6_CLOSE,
};


struct InterfaceObject
{
	DWORD	ModelID;
	float	Width;
	float	Height;
	float	X;
	float	Y;
	float	MaxX;
	float	MaxY;
	DWORD	EventTick;
	bool	OnClick;
	bool	OnShow;
	BYTE	Attribute;
	bool	ByClose;
	long	OpenedValue;
	BYTE	Speed;
	char	StatValue[20];
	int		Type;
	//
	bool	FirstLoad;
	void Close()
	{
		this->OnShow = false;
		pSetCursorFocus = false;
		this->ByClose = false;
	};

	void Open()
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->ByClose = false;
	};

	void Open(int Value, int Speed)
	{
		this->OnShow = true; pSetCursorFocus = true;
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
		this->FirstLoad = true;
	};

		void Close(int Value, int Speed)
	{
		this->OnShow = false; pSetCursorFocus = false; 
		this->OpenedValue = Value;
		this->Speed = Speed;
		this->ByClose = false;
	}

	void CloseAnimated(int Speed)
	{
		pSetCursorFocus = false;
		this->Speed = Speed;
		this->ByClose = true;
	}


};

GLvoid GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha);

struct NewUISlot
{
	int DirTexture;
	int DirPathX;
	int DirPathY;
	int DirPathW;
	int DirPathH;
	int Target;
	int draggable;
	void * ItemStrl;
};

class Interface
{
public:
	//Interface();


	void	Load();
	static void	LoadImages();
	static void	LoadModels();
	static void PopUpErrorCheckMsgBoxFunctionLoadImage(const char* szErrorMsg, bool bForceDestroy);
	static void	Work();
	static void DrawItemIMG(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void DrawItemIMGBank(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse); // code hien thi item
	static void Work2();
    static void DrawChat ( int mode, char* character, char* message );
    static void DrawItemToolTipText ( void * item, int x, int y );
	static void DrawZenAndRud(int a1, int a2, int a3, int a4);	//zen e rud
    void * item_post_;
    DWORD last_tickcount_view_;
	int teste;

	void		BindObject(short ObjectID, DWORD ModelID, float Width, float Height, float X, float Y);
	void		DrawGUI(short ObjectID, float PosX, float PosY);
	void		DrawTimeUI();
	int			DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...);
	void		DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		ResetDrawIMG(short ObjectID);
	int			DrawMessage(int Mode, LPCSTR Text, ...);
	void		DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	void	    DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);

	bool		CheckWindow(int WindowID);
	int			CloseWindow(int WindowID);
	int			OpenWindow(int WindowID);
	void		FixChaosMachine();
	bool		ButtonEx(DWORD Event, int ButtonID, bool Type);
	void		CursorFocusWindows();
	bool		IsWorkZone(short ObjectID);
	bool		IsWorkZone3(short ObjectID);
	bool		IsWorkZone2(float X, float Y, float MaxX, float MaxY, bool a5);
	float		GetResizeX(short ObjectID);
	int			DrawToolTip(int X, int Y, LPCSTR Text, ...);
	float		DrawRepeatGUI(short MonsterID, float X, float Y, int Count);
	void		DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color);
	void		DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void		DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	//Menu
	void		DrawMenu();
	bool		EventDrawMenu_Open(DWORD Event);
	bool		EventDrawMenu_Op1(DWORD Event);
	bool		EventDrawMenu_Op2(DWORD Event);
	bool		EventDrawMenu_Op3(DWORD Event);
	bool		EventDrawMenu_Op4(DWORD Event);
	bool		EventDrawMenu_Op6(DWORD Event);
	bool		EventDrawMenu_Op20(DWORD Event);
	void		DrawConfirmOpen();
	bool		EventConfirm_OK(DWORD Event);
	bool		EventConfirm_CANCEL(DWORD Event);
	void		DrawLogo(bool active);
	void		CloseCustomWindow();
	void		DrawGUI2(short ObjectID, float PosX, float PosY);
	void		DrawButton2(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY);
	void	    DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text);
	//Mini Map
	void		DrawMiniMap();
	bool		MiniMapCheck();
	bool		CombinedChecks();
	bool		CheckMap();
	int			ConfirmSlot;
	//Interface FPS
	void		guiMonitore();
	void		UPDATE_FPS();
	int			lastReport;
	int			frameCount;
	int			frameRate;
	char		FPS_REAL[30];

	//
	InterfaceObject Data[MAX_OBJECT];
	bool boolVar; //Aquí variabel on,off
	bool boolVart; //Aquí variabel on,off
	DWORD timeboolVar; //Aqui fazemos o tempo para uso delas
	DWORD timeboolVart; //Aqui fazemos o tempo para uso delas
	//antilag
	DWORD       MenuAntlagDelayClick;	
	void		SwitchMiniMap();
	void	    DrawBarForm(float PosX,float PosY,float Width,float Height,GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
	void		DrawInterfaceCustomS2();
	void		DrawInterfaceS2Menu();
	void		DrawInterface97Menu();
	void		EventNewInterface_All(DWORD Event);
	void		EventNewInterface97_All(DWORD Event);
	void		DrawCoord();
	void		DrawInterfaceDragonLS3();
	void		DrawInterfaceDragonRS3();
		// ex700
	void		DrawMenuButton();
	void		EventMenuButton(DWORD Event);
	void		DrawInterfaceCustom();
	void        DrawTextX803();
	void		OpenConfig(int type);
	//
	float PetY;
	float PetX;
	static BYTE __thiscall PickItem(int thisa);
	static int __thiscall NewSlotInventory( int thisa);
	signed int __thiscall PaintItemTooltip(int thisa, int DirPathX, int DirPathY, int Item, int a7, int a8, int a9);
	NewUISlot PetSlot;
private:
	
};
extern Interface gInterface;
