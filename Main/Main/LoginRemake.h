#pragma once

#define DisplayInfoBarCharacter							((int(__fastcall*)(int a1, int a2, signed int a3, signed int a4, char a5)) 0x416640)
#define pRender_rendertext								((int(__thiscall*)(int thisa, int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth , int iBoxHeight , int iSort, OUT SIZE * lpTextSize)) 0x00420150)
#define g_Fontthis										((int(__thiscall*)( )) 0x0041FE10)
#define SceneFlag										*(int*)0x0E609E8

extern int PointSY1;

void RemakeLoginLoad();