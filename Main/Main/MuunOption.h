#pragma once
#include "_struct.h"

#define MAX_MUUN_DATA						0x12C
#define OPEN_MUUN_SCRIPT					0x3BB2
#define MAX_OPT_MUUN						5
/*
typedef char textlist[100];
typedef char * String;

#define g_hWnd											*(HWND*)0xE8C578
#define ITEMDEF(x,y)									((x * 512) + y)
#define MODELITEM(x,y)									((x * 512) + y + 1171)
#define g_WindowWidth									0xE61E58
#define g_WindowHeight									0xE61E5C
#define ForSocketItem									((int (__thiscall*)(LPVOID thisa, ITEM* ip, int num)) 0x00968880)
#define BuxConvert										((int(__cdecl*)(BYTE * Buffer, int Size)) 0x004071A0)
//-- text
#define g_hFont											*(HGDIOBJ*)0x00E8C588
#define g_hFontBold										*(HGDIOBJ*)0x00E8C58C
#define g_pRenderText									((int(__thiscall*)( )) 0x0041FE10)
#define GetFontDC										((HDC (__thiscall*)(int thisa)) 0x0041FF80)
#define pRenderSetFont									((int(__thiscall*)(int thisa, int a2)) 0x00420120)
#define pRenderText										((int(__thiscall*)(int thisa,int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)) 0x00420150)
#define pRender_SetTextColor							((void(__thiscall*)(int thisa, DWORD dwColor)) 0x00420080)
#define pRender_SetBgColor								((int(__thiscall*)(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)) 0x4200B0)
#define pRender_SetBgColorFn							((int (__thiscall*)(int thisa, DWORD dwColor)) 0x004200F0)
#define GlobalText										((String(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)
#define GlobalLine										((LPVOID(*)()) 0x008128ADC)
#define GetPoint32										((int(*)()) 0x00401C10)
#define g_TextExtentPoint32W							((BOOL(__thiscall*)(int thisa, HDC hdc, LPCSTR lpMultiByteStr, int c, LPSIZE psizl)) 0x009593B0)

//-- texturas
#define CEnableAlphaTest								((void(__cdecl*)(bool DepthMake)) 0x00635FD0)
//-- Modelos
#define BeginBitmap										((void(*)()) 0x00637770)
#define EndBitmap										((void(*)()) 0x00637870)
#define CameraViewNear									*(float*)0xE61E38
#define CameraViewFar									*(float*)0xE61E3C
#define glViewport2										((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x006363D0)
#define gluPerspective_2								((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x006358A0)
#define GetOpenGLMatrixF								((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define EnableDepthTestF								((void(*)()) 0x00635DE0)
#define EnableDepthMaskF								((void(*)()) 0x00635E40)
#define CameraMatrixF									(LPVOID)0x87933A0
#define PetProcessData									((void(__thiscall*)(int thisa)) 0x00924D80)
#define tooltitextScriptLoader							((void(__thiscall*)(BYTE * thisa, int pchFileName)) 0x007E39B0)

#define RenderNumArrow								((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E02B0)
#define RenderEquipedHelperLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007DFDB0)
#define RenderEquipedPetLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0180)
#define RenderSummonMonsterLife						((bool(__thiscall*)(int thisa, int iX, int iY)) 0x007E0220)
#define	CreateBarHP									((int(__stdcall*)(signed int PosX, signed int PosY, int a3, signed int a4, signed int a5, char a6)) 0x007DFA60)

inline DWORD GenerateCheckSum2( BYTE *pbyBuffer, DWORD dwSize, WORD wKey);
*/
typedef struct
{
	WORD Type;
	BYTE MuunType;
	BYTE Rank;
	BYTE OptionIndex;
} MUUN_ATTRIBUTE;

typedef struct
{
	WORD Type;
	BYTE Optio[MAX_OPT_MUUN];
	WORD Val[MAX_OPT_MUUN];
	BYTE SpecialOpt;
	short Specialval;
	BYTE Map;
	BYTE DayOfWeek;
	BYTE MinHor;
	BYTE MaxHor;
	WORD MinLvl;
	WORD MaxLvl;
} MUUN_OPTION;

typedef struct
{
	WORD Type;
	BYTE Optio;
	char text[100];
} MUUN_TOOLTIP_TEXT;

#define PetProcessData							((void(__thiscall*)(int thisa)) 0x00924D80)
#define ForSocketItem							((int (__thiscall*)(LPVOID thisa, ITEM* ip, int num)) 0x00968880)
#define g_fScreenRate_x							*(float*)0x00E7C3D4
#define g_fScreenRate_y							*(float*)0x00E7C3D8

class MuunOption
{
public:
	enum FontType
	{
		Font_Normal = 0,
		Font_Bold = 1,
	};
	enum MuunType
	{
		TypeNormal = 0,
		TypeUtil = 1,
		TypeMount = 2,
	};
	enum MuunOptionC
	{
		ADD_HP = 1,
		ADD_MP,
		DMG_RATE,
		ATTK_SPEED,
		DOUBLE_DMG_RATE,
		TRIPLE_DMG_RATE,
		INC_EXP_RATE,
		RES_DOUBLE_DMG,
		RES_IGNORE_DEF,
		RES_IGNORE_SD,
		RES_CRITICAL_DMG,
		RES_EXE_DMG,
		BLOCKSTUCK,
		REFLECT_RATE,
	};
	enum ColorLine
	{
		TEXT_COLOR_WHITE = 0,
		TEXT_COLOR_BLUE,
		TEXT_COLOR_RED,
		TEXT_COLOR_YELLOW,
		TEXT_COLOR_GREEN,
		TEXT_COLOR_DARKRED,
		TEXT_COLOR_PURPLE,
		TEXT_COLOR_DARKBLUE,
		TEXT_COLOR_DARKYELLOW,
		TEXT_COLOR_GREEN_BLUE,
		TEXT_COLOR_GRAY,
		TEXT_COLOR_REDPURPLE,
		TEXT_COLOR_VIOLET,
		TEXT_COLOR_ORANGE = 13,
	};
	MuunOption();
	virtual ~MuunOption();

	void Init();
	//--
	int AttachToolTipForMuun(ITEM* Temp, int TextNum);
	static void ScreenItem3D(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse);
	static void RenderTipTextList(int sx, int sy, int TextNum, int Tab, int iSort, int iRenderPoint, BOOL bUseBG);
	static void OpenPetProcess(int thisa);
	static void OpenMuunScript(char* FileName);
	static void OpenMuunOptScript(char* FileName);
	static void OpenMuunTextScript(char* FileName);
	//--
	char* GetGlobalMuunText(int Line);
	static MUUN_OPTION* GetMuunInfo(WORD Index);
	//--
	static MUUN_ATTRIBUTE* GetAttribute(WORD Index);
	static int __thiscall AttachToolTipForSocketItem(LPVOID thisa, ITEM* Temp, int TextNum);
public:
	int ITEM_SELECT;
	//--
	MUUN_ATTRIBUTE MuunAttribute[MAX_MUUN_DATA];
	MUUN_OPTION MuunOPT[MAX_MUUN_DATA];
	MUUN_TOOLTIP_TEXT MuunText[MAX_MUUN_DATA];
};

extern MuunOption g_Option;