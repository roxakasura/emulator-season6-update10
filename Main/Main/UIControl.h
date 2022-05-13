#pragma once
#define RT3_SORT_LEFT									1
#define RT3_SORT_LEFT_CLIP								2
#define RT3_SORT_CENTER									3
#define RT3_SORT_RIGHT									4
#define RT3_WRITE_RIGHT_TO_LEFT							7
#define RT3_WRITE_CENTER								8

#define MAX_CHARS										256
#define g_hFont											*(HFONT*)0xE8C588
#define g_hFontBold										*(HFONT*)0xE8C58C
#define g_hFontBig										*(HFONT*)0xE8C590
#define g_hFixFont										*(HFONT*)0xE8C594
#define OpenFont										((void(__cdecl*)( )) 0x00630BC0)

#define	ARGB(a,r,g,b)									(((DWORD)(a))<<24 | (DWORD)(r) | ((DWORD)(g))<<8 | ((DWORD)(b))<<16)
#define	CLRDW_WHITE										ARGB(255, 255, 255, 255)
#define CLRDW_BR_GRAY									ARGB(255, 226, 226, 226)
#define CLRDW_GRAY										ARGB(255, 119, 119, 119)
#define CLRDW_YELLOW									ARGB(255, 255, 255, 121)
#define CLRDW_BR_YELLOW									ARGB(255, 255, 238, 193)
#define CLRDW_BR_ORANGE									ARGB(255, 255, 217, 39)
#define CLRDW_ORANGE									ARGB(255, 255, 180, 0)
#define CLRDW_DARKYELLOW								ARGB(255, 255, 255, 0)
#define	CLRDW_GREEN										ARGB(255, 33, 194, 28)
#define	CLRDW_RED										ARGB(255, 252,  60,  60)

// COLORREF Å¸ÀÙ.
#define	CLRREF_WHITE									RGB(240, 240, 240)
#define	CLRREF_BR_GRAY									RGB(210, 210, 210)
#define	CLRREF_GRAY										RGB(127, 127, 127)
#define	CLRREF_BLACK									RGB(  0,   0,   0)
#define	CLRREF_RED										RGB(252,  60,  60)
#define	CLRREF_BR_RED									RGB(252, 128, 128)
#define	CLRREF_ORANGE									RGB(220, 170, 100)
#define	CLRREF_YELLOW									RGB(210, 210, 100)
#define	CLRREF_BR_YELLOW								RGB(240, 240, 170)
#define	CLRREF_GREEN									RGB(100, 230, 100)
#define	CLRREF_DK_BLUE									RGB( 50,  40, 255)
#define	CLRREF_BLUE										RGB(101,  89, 255)
#define	CLRREF_BR_BLUE									RGB(168, 148, 255)
#define	CLRREF_VIOLET									RGB(210, 100, 210)
#define	CLRREF_BR_OCHER									RGB(250, 225, 200)

#define GetPoint32										((int(*)()) 0x00401C10)
#define hFontDC											((HDC (__thiscall*)(int thisa)) 0x0041FF80)
#define g_Fontthis										((int(__thiscall*)( )) 0x0041FE10)
#define g_TextExtentPoint32W							((BOOL(__thiscall*)(int thisa, HDC hdc, LPCSTR lpMultiByteStr, int c, LPSIZE psizl)) 0x009593B0)
#define g_TextOut										((BOOL(__thiscall*)(int Point32, HDC hdc, int nXStart, int nYStart, LPCSTR lpString, int cbString)) 0x00959470)
//#define WriteText										((void(__stdcall*)(int thisa, int iOffset, int iWidth, int iHeight)) 0x00420520)
#define UploadText										((void(__cdecl*)(int sx,int sy,int Width,int Height)) 0x00420650)
#define GlobalText										((char*(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)
#define GlobalLine										(LPVOID)0x008128ADC
#define StrCmp											((int(__cdecl*)( BYTE *a1, BYTE *a2)) 0x009D09B0)
//--
#define pRender_rendertext								((int(__thiscall*)(int thisa, int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)) 0x00420150)
#define pRender_SetTextSetFon							((void (__thiscall*)(int thisa, HFONT hFont)) 0x00420120)
#define pRender_SetTextColor1							((void(__thiscall*)(int thisa, BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)) 0x00420040)
#define pRender_SetTextColor2							((void(__thiscall*)(int thisa, DWORD dwColor)) 0x00420080)
#define pRender_SetBGColor1								((void(__thiscall*)(int thisa, BYTE red, BYTE green, BYTE blue, BYTE alpha)) 0x004200B0)
#define pRender_SetBGColor2								((int (__thiscall*)(int thisa, DWORD dwColor)) 0x004200F0)
#define pRender_GetTextColor							((DWORD(__thiscall*)(int thisa)) 0x0041FFE0)
#define pRender_GetBGColor								((DWORD(__thiscall*)(int thisa)) 0x00420010)
#define iFontSize										*(DWORD*)0x81C0380

inline unsigned long RGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	return (r)+(g << 8) + (b << 16) + (a << 24);
}
inline unsigned char GetAlpha(unsigned long rgba)
{
	return ((rgba) >> 24);
}
inline unsigned char GetRed(unsigned long rgba)
{
	return ((rgba) & 0xff);
}
inline unsigned char GetGreen(unsigned long rgba)
{
	return (((rgba) >> 8) & 0xff);
}
inline unsigned char GetBlue(unsigned long rgba)
{
	return (((rgba) >> 16) & 0xff);
}


extern HFONT m_hFont;
extern HFONT m_hFontBold;
extern HFONT m_hFontBig;
extern HFONT m_hFontNum;

typedef struct tagPOINTF
{
	float x;
	float y;
} POINTF;

typedef struct tagSIZEF
{
	float cx;
	float cy;
} SIZEF;

class CTextFont
{
public:
	CTextFont();
	virtual ~CTextFont();
	void Init();
	//--
	HDC GetFontHDC();
	void glCreateFont();
	DWORD GetTextColor() const;
	DWORD GetBgColor() const;
	void SetFont(HFONT hFont);
	void SetTextColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha);
	void SetTextColor(DWORD dwColor);
	void SetBgColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha);
	void SetBgColor(DWORD dwColor);
	DWORD ConvertColorToDword(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha);
	//--
	void RenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth = 0, int iBoxHeight = 0, int iSort = RT3_SORT_LEFT, OUT SIZE* lpTextSize = NULL);
	void WRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth = 0, int iBoxHeight = 0, int iSort = RT3_SORT_LEFT, OUT SIZE* lpTextSize = NULL);
	void CRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth = 0, int iBoxHeight = 0, int iSort = RT3_SORT_LEFT, OUT SIZE* lpTextSize = NULL);
	void CRenderBoldText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth = 0, int iBoxHeight = 0, int iSort = RT3_SORT_LEFT, OUT SIZE* lpTextSize = NULL);

public:
	bool ShadowFlower;
	int typeshadow;
};

extern CTextFont g_pRenderText;