#include "StdAfx.h"
#include "Util.h"
#include "UIControl.h"

CTextFont g_pRenderText;

CTextFont::CTextFont()
{
}

CTextFont::~CTextFont()
{
}

HDC CTextFont::GetFontHDC()
{
	return hFontDC(g_Fontthis());
}

DWORD CTextFont::GetTextColor() const
{
	return pRender_GetTextColor(g_Fontthis());
}
DWORD CTextFont::GetBgColor() const
{
	return pRender_GetBGColor(g_Fontthis());
}

void CTextFont::SetTextColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)
{
	pRender_SetTextColor1(g_Fontthis(), byRed, byGreen, byBlue, byAlpha);
}

void CTextFont::SetTextColor(DWORD dwColor)
{
	pRender_SetTextColor2(g_Fontthis(), dwColor);
}

void CTextFont::SetBgColor(BYTE byRed, BYTE byGreen, BYTE byBlue, BYTE byAlpha)
{
	pRender_SetBGColor1(g_Fontthis(), byRed, byGreen, byBlue, byAlpha);
}

void CTextFont::SetBgColor(DWORD dwColor)
{
	pRender_SetBGColor2(g_Fontthis(), dwColor);
}

void CTextFont::SetFont(HFONT hFont)
{
	SelectObject(this->GetFontHDC(), hFont);
}

void CTextFont::RenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
}

void CTextFont::WRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	//pRender_rendertext(g_Fontthis(), (int)WConvertX(iPos_x), iPos_y, pszText, (int)WConvertX(iBoxWidth), iBoxHeight, iSort, lpTextSize);
}

void CTextFont::CRenderText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	this->ShadowFlower = true;
	this->typeshadow = 1;
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	this->ShadowFlower = false;
}

void CTextFont::CRenderBoldText(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{
	this->ShadowFlower = true;
	this->typeshadow = 2;
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
	this->ShadowFlower = false;
}


void CTextFont::Init()
{
	/*SetCompleteHook(0xE8, 0x00420814, &WriteTextShadow);
	//- NOTICE
	SetDword(0x005978F5 + 1, 0);
	SetDword(0x00597871 + 1, 0);
	SetDword(0x0059789A + 1, 0xFF); //-- alpha
	SetByte(0x0059789F  + 1, 0); //-- Blue
	SetDword(0x005978A1 + 1, 160); //-- gren
	SetDword(0x005978A6 + 1, 233); //-- red
	SetCompleteHook(0xE8, 0x00597965, &CRenderTextNotice);
	SetCompleteHook(0xE8, 0x00597939, &CRenderTextNotice);*/
}