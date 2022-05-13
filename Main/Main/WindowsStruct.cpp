#include "stdafx.h"
#include "WindowsStruct.h"
#include "Interface.h"
#include "CustomInterface.h"
#include "NewInterface.h"
#include "Import.h"
#include "Util.h"
#include "TMemory.h"
#include "Offset.h"
#include "Object.h"
#include "Defines.h"
#include "PrintPlayer.h"
#include "User.h"
#include "ItemSetOption.h"
#include "Common.h"
#include "WinBase.h"

void RenderWindowsCharacter(int, float, float);
void RenderWindowsChaosMachine(int, float, float);

#define sub_409A50     ((void*(__thiscall*)(void *This)) 0x409A50)
#define sub_7794B0     ((int(__thiscall*)(int This)) 0x7794B0)
#define sub_779440     ((int(__thiscall*)(int This, int a2, DWORD a3, int a4)) 0x779440)
#define sub_7794D0     ((int(__thiscall*)(int This, DWORD a3, int a4)) 0x7794D0)
//----- (0083BB70) --------------------------------------------------------
BYTE sub_83BB70(int This){
  char *v4; // eax@1
  char v6; // [sp-20h] [bp-2Ch]@1
  int v7; // [sp-1Ch] [bp-28h]@1
  int v8; // [sp-18h] [bp-24h]@1
  int v9; // [sp-14h] [bp-20h]@1
  int v10; // [sp-10h] [bp-1Ch]@1
  int v11; // [sp-Ch] [bp-18h]@1
  signed int v13; // [sp-4h] [bp-10h]@1
  void *v14; // [sp+0h] [bp-Ch]@1
  char *v16; // [sp+8h] [bp-4h]@1

  *(DWORD *)(This + 1016) = 1;
  sub_7794B0(This + 632);
  sub_779440(This + 632, 0, 31376, 0);
  sub_779440(This + 632, 1, 31376, 1);
  sub_7794D0(This + 632, 31376, 0);
  v13 = 1;
  v4 = (char *)pGetTextLine(pTextLineThis, (103));
  v16 = &v6;
  v14 = sub_409A50(&v6);
  return sub_7853F0(This + 632, v6, v7, v8, v9, v10, v11, v13);
}

void RenedrBarFormat(float x, float y, float w, float h, float R, float G, float B, float Alpha)
{
	pSetBlend(true);
	glColor4f(R, G, B, Alpha);
	pDrawBarForm(x, y, w, h, 0, 0); //central
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);

	//gInterface.DrawFormat(eBlue, x + w - 10, y + 2, 10, 1, "-");
}

unsigned int sub_83CBE0(int This)
{
	unsigned int result; // eax@2
	unsigned int v2; // [sp+4h] [bp-4h]@1

	v2 = CheckInventoryExt((int)This + 992);
	if ( v2 <= 3 )
		result = v2;
	else
		result = 0;
	return result;
}

bool CheckButtonPressed(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, w, h) && *(BYTE*)0x8793386;
}

float TransForX(float num)
{
	return (float) ( pWinWidthReal <= 1.25 ) ? num * pWinWidthReal : num * pWinHeightReal;
}

float TransForY(float num)
{
	return (float) num * pWinHeightReal;
}

float TransFor2X(float num)
{
	return (float) num * pWinWidthReal;
}

float ReturnX(float num)
{
	return (float) ( pWinWidthReal <= 1.25 ) ? num / pWinWidthReal : num / pWinHeightReal;
}

float Return2X(float num)
{
	return (float) num / pWinWidthReal;
}

float ReturnY(float num)
{
	return (float) num / pWinHeightReal;
}

void SetPrintf(char * DrawText, int x, int y, int nCount, int Aling)
{
	pDrawText(pTextThis(), x, y, DrawText, nCount, 0, (LPINT)Aling, 0);
}

void RebuildInformationRate(int Info, int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0)
		wsprintf(v10, "%d%%", Info);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void RebuildInformationRate(int Info, int Info2, int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0 || Info2 > 0)
		wsprintf(v10, "%d%% - %d%%", Info, Info2);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void RebuildInformation(int Info, int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0)
		wsprintf(v10, "%d", Info);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

void RebuildInformation(int Info, int Info2,int x, int v5)
{
	char v10[50]; // ST08_4@6
	ZeroMemory(v10, sizeof(v10));
	if( Info > 0 || Info2 > 0)
		wsprintf(v10, "%d - %d", Info, Info2);
	else
		wsprintf(v10, "-");
	pDrawText(pTextThis(), x, v5, v10, 50, 0, (LPINT)4, 0);
}

signed int __cdecl ColorMoney(unsigned int a1){
	signed int color1 = eWhite; // eax@2
	if(a1 >= 1000 && a1 < 1000000){
		color1 = eShinyGreen;
	}else if(a1 >= 1000000 && a1 < 10000000){
		color1 = eGold;
	}else if(a1 >= 1000000 && a1 < 100000000){
		color1 = eOrange;
	}else if(a1 >= 100000000){
		color1 = eRed;
	}
	return color1;
}

void pDrawZenAndRud(int a1){
	float Y;
	float X;
	DWORD v23;
	Y = *(DWORD*)(a1 + 40);
	X = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width
	char MoneyBuff1[50], MoneyBuff2[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin1, MoneyBuff2, 0);
	DWORD color1 = eWhite;
	DWORD color2 = eWhite;
	if(v23 > 0){
		color1 = ColorMoney(v23);
	}
	if(Coin1 > 0){
		color2 = ColorMoney(Coin1);
	}
	//-- Texto del Inventario
	gInterface.DrawFormat(eGold, X, Y + 27, 190, 3, pGetTextLine(pTextLineThis, 223));
	//-- Texto Money
	pDrawGUI(61528, X + 11, Y + 398, 81.0, 16.0);
	gInterface.DrawFormat(color1, X + 32, Y + 400, 55, 4, "%s", MoneyBuff1);
	//-- Texto Ruud
	//pDrawGUI(61528, X + 10, Y + 396, 81.0, 16.0);
	//gInterface.DrawFormat(color2, X + 32, Y + 398, 55, 4, "%s", MoneyBuff2);
}

#pragma optimize("t",on)

__declspec (naked) void RenderMoveSlotInventory()
{
	static DWORD Addr_Jmp = 0x0083445D;
	static DWORD CallMe = 0x007DC240;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP + 0xC]
		ADD ECX,225//215
		PUSH ECX                                 ; /Arg2
		MOV EDX,DWORD PTR SS:[EBP + 0x8]         ; |
		ADD EDX,15//22                               ; |
		PUSH EDX                                 ; |Arg1
		MOV EAX,DWORD PTR SS:[EBP - 0x4]         ; |
		MOV ECX,DWORD PTR DS:[EAX + 0x18]        ; |
		CALL [CallMe]                            ; \main1.007DC240
		JMP[Addr_Jmp]
	}
}

__declspec(naked) void RenderSlotEquip()  //-- ok
{
	static DWORD This; // ST00_4@1
	static DWORD Addrs = 0x00836871;
	_asm
	{
		MOV DWORD PTR SS:[EBP-4],ECX
		MOV EAX,DWORD PTR SS:[EBP-4]
		MOV This,EAX
	}
	//-- pet
	*(DWORD *)(This + 204) = *(DWORD *)(This + 36) + 14;//-- X
	*(DWORD *)(This + 208) = *(DWORD *)(This + 40) + 54;//-- Y
	*(DWORD *)(This + 212) = 35;//-- W
	*(DWORD *)(This + 216) = 40;//-- H
	*(DWORD *)(This + 220) = 61537;//-- Texture
	//-- weapon(L)
	*(DWORD *)(This + 44) = *(DWORD *)(This + 36) + 14;
	*(DWORD *)(This + 48) = *(DWORD *)(This + 40) + 97;
	*(DWORD *)(This + 52) = 35;
	*(DWORD *)(This + 56) = 56;
	*(DWORD *)(This + 60) = 61536;
	//-- Gloves
	*(DWORD *)(This + 144) = *(DWORD *)(This + 36) + 14;
	*(DWORD *)(This + 148) = *(DWORD *)(This + 40) + 155;
	*(DWORD *)(This + 152) = 35;
	*(DWORD *)(This + 156) = 40;
	*(DWORD *)(This + 160) = 61535;
	//-- helm
	*(DWORD *)(This + 84) = *(DWORD *)(This + 36) + 78;
	*(DWORD *)(This + 88) = *(DWORD *)(This + 40) + 54;
	*(DWORD *)(This + 92) = 35;
	*(DWORD *)(This + 96) = 40;
	*(DWORD *)(This + 100) = 61533;
	//-- Armor
	*(DWORD *)(This + 104) = *(DWORD *)(This + 36) + 78;
	*(DWORD *)(This + 108) = *(DWORD *)(This + 40) + 97;
	*(DWORD *)(This + 112) = 36;
	*(DWORD *)(This + 116) = 56;
	*(DWORD *)(This + 120) = 61534;
	//-- Pants
	*(DWORD *)(This + 124) = *(DWORD *)(This + 36) + 78;
	*(DWORD *)(This + 128) = *(DWORD *)(This + 40) + 155;
	*(DWORD *)(This + 132) = 36;
	*(DWORD *)(This + 136) = 40;
	*(DWORD *)(This + 140) = 61532;
	//-- wings
	*(DWORD *)(This + 184) = *(DWORD *)(This + 36) + 122;
	*(DWORD *)(This + 188) = *(DWORD *)(This + 40) + 54;
	*(DWORD *)(This + 192) = 55;
	*(DWORD *)(This + 196) = 40;
	*(DWORD *)(This + 200) = 61538;
	//-- weapon(R)
	*(DWORD *)(This + 64) = *(DWORD *)(This + 36) + 142;
	*(DWORD *)(This + 68) = *(DWORD *)(This + 40) + 97;
	*(DWORD *)(This + 72) = 35;
	*(DWORD *)(This + 76) = 56;
	*(DWORD *)(This + 80) = 61539;
	//-- Bootas
	*(DWORD *)(This + 164) = *(DWORD *)(This + 36) + 142;
	*(DWORD *)(This + 168) = *(DWORD *)(This + 40) + 155;
	*(DWORD *)(This + 172) = 35;
	*(DWORD *)(This + 176) = 40;
	*(DWORD *)(This + 180) = 61540;
	//-- anillo 2
	*(DWORD *)(This + 264) = *(DWORD *)(This + 36) + 117;
	*(DWORD *)(This + 268) = *(DWORD *)(This + 40) + 169;
	*(DWORD *)(This + 272) = 22;
	*(DWORD *)(This + 276) = 25;
	*(DWORD *)(This + 280) = 61541;
	//-- pendiente
	*(DWORD *)(This + 224) = *(DWORD *)(This + 36) + 52;
	*(DWORD *)(This + 228) = *(DWORD *)(This + 40) + 68;
	*(DWORD *)(This + 232) = 22;
	*(DWORD *)(This + 236) = 25;
	*(DWORD *)(This + 240) = 61542;
	// anillo 1
	*(DWORD *)(This + 244) = *(DWORD *)(This + 36) + 52;
	*(DWORD *)(This + 248) = *(DWORD *)(This + 40) + 169;
	*(DWORD *)(This + 252) = 22;
	*(DWORD *)(This + 256) = 25;
	*(DWORD *)(This + 260) = 61541;

	_asm
	{
		JMP [Addrs]
	}
}

__declspec(naked) void RenderSlotFix()  //-- ok
{
	static DWORD Addrs = 0x007DBA76;
	
	_asm
	{
		JMP [Addrs]
	}
}

__declspec (naked) void RemoveButton()  //-- ok
{
	static DWORD Addrs = 0x00836A58;
	
	_asm
	{
		JMP [Addrs]
	}
}
#pragma optimize("t",off)
void RenderWindowsCharacter(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	gInterface.DrawFormat(-1, a2, a3 + 24, *(float*)(0x00D24E88), 3, "%s", oUserObjectStruct);

	sub_635F50();
	return;
}

void RenderWindowsUNKNOWN(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	sub_635F50();
	return;
}


int SetTextSocket(int a1)
{
	return 1;
}

char SetTextAncestral(int This)
{
	HGDIOBJ v4; // ST18_4@1
	void *v5; // eax@1
	void *v6; // eax@1
	int v7; // eax@1
	int v8; // eax@2
	void *v9; // eax@3
	void *v10; // eax@4
	char v11; // al@5
	int v12; // ST04_4@5
	int v13; // ST00_4@5
	void *v14; // eax@5
	int v15; // eax@5
	char result; // al@5
	int v17; // [sp+14h] [bp-84h]@1
	char v18; // [sp+18h] [bp-80h]@5

	result = sub_4EC9B0(0xE8CDE8);
	if( result == 1)
		RenderTooltipAncestral_772EA0(This);

	return result;
}

__declspec (naked) void RenderDrawTitleShop()
{
	static DWORD Addr_JMP = 0x0084723D;
	static DWORD Addr1 = 0x00420150;
	static DWORD Addr2 = 0x0041FE10;

	_asm
	{
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x104]
		MOV EDX,DWORD PTR DS:[ECX+0x18]
		ADD EDX,28
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x104]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		PUSH ECX
		CALL [Addr2]
		MOV ECX,EAX                              ; |
		CALL [Addr1]
		JMP[Addr_JMP]
	}
}

__declspec (naked) void RenderSlotGeneral1()
{
	static DWORD Addr_JMP = 0x007DB5D0;
	static float witdh = 21.0f;
	_asm
	{
		PUSH ECX
		FLD DWORD PTR DS:[witdh]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[witdh]
		FSTP DWORD PTR SS:[ESP]
		MOV EAX,DWORD PTR SS:[EBP - 0x4]
		IMUL EAX,EAX, 0x14
		MOV ECX,DWORD PTR SS:[EBP - 0xB0]
		MOV EDX,DWORD PTR DS:[ECX + 0x2C]
		ADD EDX,EAX
		MOV DWORD PTR SS:[EBP - 0xBC],EDX
		FILD DWORD PTR SS:[EBP - 0xBC]
		PUSH ECX
		FSTP DWORD PTR SS:[ESP]
		MOV EAX,DWORD PTR SS:[EBP - 0x8]
		IMUL EAX,EAX, 0x14
		MOV ECX,DWORD PTR SS:[EBP - 0xB0]
		MOV EDX,DWORD PTR DS:[ECX + 0x28]
		ADD EDX,EAX
		MOV DWORD PTR SS:[EBP - 0xC0],EDX
		FILD DWORD PTR SS:[EBP - 0xC0]
		PUSH ECX
		FSTP DWORD PTR SS:[ESP]
		PUSH 61527
		JMP [Addr_JMP]
	}
}

//=======================================
//-- Render Windows Shop
//=======================================
signed int __cdecl sub_5C1130(unsigned int a1)
{
	signed int result; // eax@2

	if ( a1 < 0x989680 )
	{
		if ( a1 < 0xF4240 )
		{
			if ( a1 < 0x186A0 )
				result = -6890241;
			else
				result = -15152896;
		}
		else
		{
			result = -16738561;
		}
	}
	else
	{
		result = -16776961;
	}
	return result;
}

//=======================================
//-- Render Windows Inv. Ext.
//=======================================
__declspec (naked) void RenderMoveSlotExt()
{
	static DWORD Addr_JMP = 0x0083C5F1;
	static DWORD Addr_Call = 0x009CEBF0;

	_asm
	{
		FILD DWORD PTR DS:[EAX + 0x4]
		FSTP DWORD PTR SS:[EBP - 0x4]
		FLD DWORD PTR SS:[EBP - 0x4]
		CALL [Addr_Call]
		ADD EAX, 15//-- 20
		PUSH EAX
		FLD DWORD PTR SS:[EBP-0x8]
		CALL [Addr_Call]
		PUSH EAX                                  ; |Arg1
		MOV EAX,DWORD PTR SS:[EBP-0xC]            ; |
		MOV ECX,DWORD PTR SS:[EBP-0x10]           ; |
		MOV ECX,DWORD PTR DS:[ECX+EAX*0x4+0x18]   ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderSlotMove()  //-- ok
{
	static DWORD Addrs = 0x007DC259;
	static DWORD This;
	static DWORD a2;
	static DWORD a3;

	_asm
	{
		PUSH EBP
		MOV EBP,ESP
		PUSH ECX
		MOV DWORD PTR SS:[EBP-0x4],ECX
		MOV EAX,DWORD PTR SS:[EBP-0x4]
		MOV This, EAX
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOV a2, ECX
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		MOV a3, EAX
	}

	*(DWORD *)(This + 40) = a2;
	*(DWORD *)(This + 44) = a3 + 5;

	_asm
	{
		JMP [Addrs]
	}
}

void pDrawRenderImg(DWORD id, float X, float Y,float W, float H)
{
	Y += 20;

	pDrawGUI(id, X, Y, W, H);
}

void RenderWindowsInventoryExt(int a1){
	sub_635FD0(1);
	static float v1;
	static float v2;
	v1 = *(DWORD*)(a1 + 20);
	v2 = *(DWORD*)(a1 + 24);
	nInterface.DrawWindowBG(v1, v2);
	gInterface.DrawFormat(eGold, v1, v2 + 24, *(float*)(0x00D24E88), 3, pGetTextLine(pTextLineThis, 3323));

	sub_635F50();
}

__declspec (naked) void RenderWindowsExt()
{
	static DWORD Addr_JMP = 0x007D56A4;
	static DWORD This;

	_asm
	{
		MOV DWORD PTR SS:[EBP-4],ECX
		MOV EAX, DWORD PTR SS:[EBP-4]
		MOV This, EAX
	}

	RenderWindowsInventoryExt(This);

	_asm
	{
		JMP[Addr_JMP]
	}
}

void RenderWindowsGensBattle(int a1){
	float y; // ST08_4@1
	float x; // ST04_4@1
	y = (double)*(signed int *)(a1 + 20);
	x = (double)*(signed int *)(a1 + 16);
	nInterface.DrawWindowBG(x, y);
}

__declspec (naked) void InitWindowsChaos()
{
	static DWORD Addr_JMP = 0x0082CB50;
	_asm
	{
		JMP [Addr_JMP]
	}
}

__declspec(naked) void RenderWindowsGuildMaker()
{
	static DWORD Addrs = 0x007D1884;
	static DWORD RenderBits = 0x00790B50;
	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[0xD24E88]                ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV EAX,DWORD PTR SS:[EBP-0x6C]            ; |
		FILD DWORD PTR DS:[EAX+0x14]               ; |
		PUSH ECX                                 ; |Arg3
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x6C]            ; |
		FILD DWORD PTR DS:[ECX+0x10]               ; |
		PUSH ECX                                 ; |Arg2
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH 61526                                ; |Arg1 = 00007A5A
		CALL RenderBits                      ; \main1.00790B50
		JMP[Addrs]
	}
}


#define ho						*(HGDIOBJ*)0x00E8C588
#define pGetTextLine			((LPCSTR(__thiscall*)(LPVOID This, int LineNumber)) 0x402320)
#define sub_9CF630  	        ((char(__cdecl*)(char *a1, int a2, int a3)) 0x009CF630)
#define pSetItemTextLine1		((void(__cdecl*)(int Line, LPCSTR Text, ...)) 0x9CF6AA)
#define sub_840410              ((int(__thiscall*)(int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11)) 0x00840410)
//----- (00841E10) --------------------------------------------------------
int sub_841E10(int a1)
{
  int v4; // ST3C_4@1
  float v5; // ST18_4@1
  float v6; // ST14_4@1
  float v7; // ST18_4@1
  float v8; // ST14_4@1
  float v9; // ST18_4@1
  float v10; // ST14_4@1
  float v11; // ST18_4@1
  float v12; // ST14_4@1
  float v13; // ST18_4@1
  float v14; // ST14_4@1
  float v15; // ST18_4@1
  int v16; // ST24_4@1
  float v17; // ST14_4@1
  LPCSTR v18;
  char v20; // [sp+2Ch] [bp-68h]@1

  v4 = a1;
  v5 = (double)*(signed int *)(a1 + 24);
  v6 = (double)*(signed int *)(a1 + 20);
  pDrawGUI(31322, v6, v5, 190.0, 429.0);
  v7 = (double)*(signed int *)(v4 + 24);
  v8 = (double)*(signed int *)(v4 + 20);
  pDrawGUI(31353, v8, v7, 190.0, 64.0);
  v9 = (double)(*(DWORD *)(v4 + 24) + 64);
  v10 = (double)*(signed int *)(v4 + 20);
  pDrawGUI(31355, v10, v9, 21.0, 320.0);
  v11 = (double)(*(DWORD *)(v4 + 24) + 64);
  v12 = (double)(*(DWORD *)(v4 + 20) + 169);
  pDrawGUI(31356, v12, v11, 21.0, 320.0);
  v13 = (double)(*(DWORD *)(v4 + 24) + 384);
  v14 = (double)*(signed int *)(v4 + 20);
  pDrawGUI(31357, v14, v13, 190.0, 45.0);
  v15 = (double)(*(DWORD *)(v4 + 24) + 49);
  v16 = *(DWORD *)(v4 + 20) + 12;
  v17 = (double)v16;
  pDrawGUI(31374, v17, v15, 169.0, 26.0);
  sub_9CF630(&v20, 0, 100);
  v18 = pGetTextLine(pTextLineThis, 1623);
  pSetItemTextLine1(v16, v18);
  return sub_840410((int)&v20,*(DWORD *)(v4 + 20),*(DWORD *)(v4 + 24) + 15,190, 0,-11947777,0,3,(int)ho);
}

void RenderWindowsParty(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	sub_635F50();
	return;
}

__declspec(naked) void RenderWindowsStore()
{
	static DWORD Addr_JMP = 0x00841F47;
	static DWORD RenderBits = 0x00790B50;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[0xD24E88]              ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV EAX,DWORD PTR SS:[EBP-0x6C]          ; |
		FILD DWORD PTR DS:[EAX+0x18]             ; |
		PUSH ECX                                 ; |Arg3
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x6C]          ; |
		FILD DWORD PTR DS:[ECX+0x14]             ; |
		PUSH ECX                                 ; |Arg2
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH 61526                               ; |Arg1 = 00007A5A
		CALL RenderBits                          ; \main1.00790B50
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderTittleCommand()
{
	static DWORD Addr_JMP = 0x0078E4CA;
	static DWORD Addr1_Call = 0x00402320;
	static DWORD Addr2_Call = 0x0041FE10;

	_asm
	{
		PUSH 0
		PUSH 3
		PUSH 0
		PUSH 0x48
		PUSH 0x3AA                                 ; /Arg1 = 000003AA
		MOV ECX,0x08128ADC                   ; |
		CALL Addr1_Call                      ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x1C]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 27
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x1C]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 0x3C
		PUSH ECX
		CALL Addr2_Call
		MOV ECX,EAX
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderTittleQuestGlobal()
{
	static DWORD Addr_JMP = 0x00843B37;
	static DWORD Addr1_Call = 0x00521FE0;
	static DWORD Addr2_Call = 0x0041FE10;

	_asm
	{
		PUSH 0
		PUSH 3
		PUSH 0
		PUSH 0x0BE
		MOV ECX,0x00EBCF60                   ; |
		CALL Addr1_Call                      ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0xC]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 27
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0xC]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		PUSH ECX
		CALL Addr2_Call
		MOV ECX,EAX
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderGensPointText()
{
	static DWORD Addr_JMP = 0x00843DC4;
	static DWORD Addr_Call = 0x0041FE10;

	_asm
	{
		PUSH 0
		PUSH 3
		PUSH 0
		PUSH 0xBE
		LEA EDX,DWORD PTR SS:[EBP-0x20]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x24]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,51
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x24]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderGensPointInfo()
{
	static DWORD Addr_JMP = 0x00843BCE;
	static DWORD Addr_Call = 0x0041FE10;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		MOV ECX,DWORD PTR SS:[EBP-0xC]
		MOV EDX,DWORD PTR DS:[ECX+0xC34]
		IMUL EDX,EDX,0x7
		ADD EDX,DWORD PTR SS:[EBP-0x4]
		SHL EDX,0x6
		MOV EAX,DWORD PTR SS:[EBP-0xC]
		LEA ECX,DWORD PTR DS:[EAX+EDX+0x374]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0xC]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		IMUL ECX,ECX,0xF
		LEA EDX,DWORD PTR DS:[EAX+ECX+0x50]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0xC]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,0xD
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                             ; |
		JMP[Addr_JMP]
	}
}

void RenderGensPointTexture(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y + 21, w, h);
}

__declspec(naked) void StoreButtonsTest()
{
	static DWORD Addr_JMP = 0x0078E485;
	static DWORD Addr_Call = 0x0041FE10;

	_asm
	{
		JMP[Addr_JMP]
	}
}

void RenderTooltipAncestral_772EA0(int ThisR)
{
	static DWORD Addr = 0x00835C70;
	static DWORD Addr_Call = 0x00772EA0;
	static DWORD This = 0x00772EA0;

	This = ThisR;

	_asm
	{
		PUSH 1                              ; /Arg5 = 00000000
		PUSH 0                              ; |Arg4 = 00000000
		MOV EAX,This                        ; |
		PUSH EAX                            ; |Arg3
		PUSH Addr                           ; |Arg2 = 00815040
		PUSH ECX                            ; |Arg1
		FLD DWORD PTR DS:[0xD2CA40]         ; |
		FSTP DWORD PTR SS:[ESP]             ; |
		MOV ECX, This                       ; |
		MOV ECX, DWORD PTR DS:[ECX + 0x14]  ; |
		CALL Addr_Call                      ; \main1.00772EA0
	}
}

__declspec(naked) void RenderHelperTittle()
{
	static DWORD Addr_JMP = 0x007F673B;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x2D8]
		MOV EDX,DWORD PTR DS:[ECX+0xCC]
		ADD EDX,27
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderQuestPlayerTittle()
{
	static DWORD Addr_JMP = 0x0083EBB0;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-4]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,27
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderButtonImg()
{
	static DWORD Addr_JMP = 0x0083F37C;

	_asm
	{
		PUSH 0                                   ; /Arg5 = 00000000
		PUSH 0                                   ; |Arg4 = 00000000
		PUSH 0                                   ; |Arg3 = 00000000
		PUSH 31295                                ; |Arg2 = 00007A8A
		PUSH 1                                   ; |Arg1 = 00000001
		MOV ECX,DWORD PTR SS:[EBP-0x10]            ; |
		ADD ECX,0x18                               ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderButtonInfo()
{
	static DWORD Addr_JMP = 0x0083F3A2;

	_asm
	{
		PUSH 0x1D                                  ; /Arg4 = 0000001D
		PUSH 0x24                                  ; |Arg3 = 00000024
		MOV EAX,DWORD PTR SS:[EBP-0x10]            ; |
		MOV ECX,DWORD PTR DS:[EAX+0x14]            ; |
		ADD ECX,27                              ; |
		PUSH ECX                                 ; |Arg2
		MOV EDX,DWORD PTR SS:[EBP-0x10]            ; |
		MOV EAX,DWORD PTR DS:[EDX+0x10]            ; |
		ADD EAX,160                               ; |
		PUSH EAX                                 ; |Arg1
		MOV ECX,DWORD PTR SS:[EBP-0x10]            ; |
		ADD ECX,0x18                               ; |
		JMP[Addr_JMP]
	}
}

void ImprimirTitulo(int x, int y, int LineText)
{
	gInterface.DrawFormat(eGold, x, y + 27, 190, 3, pGetTextLine(pTextLineThis, LineText));
}

void PrintButtonClose(int This, int x, int y){
	//-- Cerrar
	pDrawPuntero(This, 1, 31295, 0, 0, 0);
	ChangeButtonInfo((char *)(This), x + 160, y + 27, 11, 12);
}

void RenderWindowsStoreUP(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	ImprimirTitulo(a2, a3, 1102);
	sub_635F50();
	return;
}

void RenderWindowsCreateGuildUP(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	ImprimirTitulo(a2, a3, 180);
	sub_635F50();
	return;
}

void RenderWindowsOffGuildUP(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	ImprimirTitulo(a2, a3, 180);
	sub_635F50();
	return;
}

void RenderWindowsGuildUP(int a1, float a2, float a3){
	sub_635FD0(1);
	nInterface.DrawWindowBG(a2, a3);
	ImprimirTitulo(a2, a3, 180);
	sub_635F50();
	return;
}

__declspec(naked) void SetTittleParty()
{
	static DWORD Addr_JMP = 0x0084A6B2;
	static DWORD x;
	static DWORD y;
	static DWORD This;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x18]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		MOV y, ECX
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		MOV x, EAX
	}
	
	ImprimirTitulo(x, y, 190);

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void SetCloseParty()
{
	static DWORD Addr_JMP = 0x0084A127;
	static DWORD Addr1_Call = 0x00779350;
	static DWORD Addr2_Call = 0x00779410;

	_asm
	{
		PUSH 0                                   ; /Arg5 = 00000000
		PUSH 0                                   ; |Arg4 = 00000000
		PUSH 0                                   ; |Arg3 = 00000000
		PUSH 31295                               ; |Arg2 = 00007A8A
		PUSH 1                                   ; |Arg1 = 00000001
		MOV ECX,DWORD PTR SS:[EBP-0x10]          ; |
		ADD ECX,0x18                             ; |
		CALL Addr1_Call                      ; \main1.00779350
		PUSH 12                                  ; /Arg4 = 0000001D
		PUSH 11                                  ; |Arg3 = 00000024
		MOV EAX,DWORD PTR SS:[EBP-0x10]          ; |
		MOV ECX,DWORD PTR DS:[EAX+0x14]          ; |
		ADD ECX,27                               ; |
		PUSH ECX                                 ; |Arg2
		MOV EDX,DWORD PTR SS:[EBP-0x10]          ; |
		MOV EAX,DWORD PTR DS:[EDX+0x10]          ; |
		ADD EAX,160                              ; |
		PUSH EAX                                 ; |Arg1
		MOV ECX,DWORD PTR SS:[EBP-0x10]            ; |
		ADD ECX,0x18                               ; |
		CALL Addr2_Call                      ; \main1.00779410
		JMP[Addr_JMP]
	}
}

__declspec(naked) void SetTittlePet()
{
	static DWORD Addr_JMP = 0x0084D1CD;
	static DWORD x;
	static DWORD y;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x10C]
		MOV ECX,DWORD PTR DS:[EAX+0xE8]
		MOV y, ECX
		MOV EDX,DWORD PTR SS:[EBP-0x10C]
		MOV EAX,DWORD PTR DS:[EDX+0xE4]
		MOV x, EAX
	}
	
	ImprimirTitulo(x, y, 1217);

	_asm
	{
		JMP[Addr_JMP]
	}
}

void LoadTextureImg(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id, x, y + 15, w, h);
}

void LoadTextureMoney(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(61528, x + 97, y + 10, 81.0, 16.0);
}

void OpenWindowsTrade(int This)
{
	float x;
	float y;
	y = (double)*(signed int *)(This + 20);
	x = (double)*(signed int *)(This + 16);

	//LoadWindows(1, x, y, 190, 429);
	nInterface.DrawWindowBG(x, y);
		
	ImprimirTitulo(x, y, 226);
	//-- Nombre de PJ1
	pDrawGUI(31563, x + 11, y + 52.0, 170.0, 26.0);
	//-- Nombre de PJ2
	pDrawGUI(31563, x + 11, y + 243, 171.0, 26.0);

	if ( *(DWORD *)(This + 376) )
	{
		*(DWORD *)(*(DWORD *)(This + 376) + 44) = 81;
	}

	if ( *(DWORD *)(This + 380) )
	{
		*(DWORD *)(*(DWORD *)(This + 380) + 44) = 273;
	}
	char bufferZen1[64];
	char bufferZen2[64];
	pGetMoneyFormat((double)*(signed int *)(This + 3828), bufferZen1, 0);
	pGetMoneyFormat((double)*(signed int *)(This + 3832), bufferZen2, 0);
	pDrawGUI(61528, x + 97, y + 165, 81.0, 16.0);
	gInterface.DrawFormat(ColorMoney((double)*(signed int *)(This + 3828)), x + 117, y + 167, 55,4,bufferZen1);
	pDrawGUI(61528, x + 97, y + 356, 81.0, 16.0);
	gInterface.DrawFormat(ColorMoney((double)*(signed int *)(This + 3832)), x + 117, y + 358, 55,4,bufferZen2);

	pDrawButton(61525, x + 136, y + 186, 43.0f, 17.0f, 0, ((*(BYTE *)(This + 3840) != 0 ) ? 17.0f : 34.0f ));
	gInterface.DrawFormat(eWhite, x + 138, y + 188, 43, 3, "Ok");
	pDrawButton(61525, x + 136, y + 390, 43.0f, 17.0f, 0, ((*(BYTE *)(This + 3841) != 0 ) ? 17.0f : 34.0f ));
	gInterface.DrawFormat(eWhite, x + 138, y + 392, 43, 3, "Ok");

	//-- Cerrar
	pDrawPuntero(This + 24, 1, 31295, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 24), x + 500000, y + 500000, 11, 12);
	//
	pDrawPuntero(This + 196, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 196), x + 64, y + 390, 43, 17);
	if (gInterface.IsWorkZone(eButton5))
		gInterface.DrawButtonRender(eButton5, x + 64, y + 390, 0, 17.0f);
	else
		gInterface.DrawButtonRender(eButton5, x + 64, y + 390, 0, 34.0);
	gInterface.DrawFormat(eWhite, x + 64, y + 392, 43, 3, pGetTextLine(pTextThis(), 227));
}

__declspec(naked) void RenderTrade()
{
	static DWORD Addr_JMP = 0x00864766;
	static DWORD This;

	_asm
	{
		MOV DWORD PTR SS:[EBP-0xC],ECX
		MOV This, ECX

	}

	OpenWindowsTrade(This);

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderTextTrade()
{
	static DWORD Addr_JMP = 0x00864988;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x94]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,60
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText1Trade()
{
	static DWORD Addr_JMP = 0x00864A42;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x94]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,60
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText2Trade()
{
	static DWORD Addr_JMP = 0x00864A7A;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x94]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,60
		JMP[Addr_JMP]
	}
}


void OpenWindowsCommand(int This)
{
	float x;
	float y;
	y = (double)*(signed int *)(This + 20);
	x = (double)*(signed int *)(This + 16);

	nInterface.DrawWindowBG(x, y);

	for (int i = 0; i < 11; ++i )
	{
		ChangeButtonInfo((char *)(This + 172 * i + 24), x + (190 / 2) - (110 / 2), y + 55 + (31 * i), 110, 30);
	}
}

__declspec(naked) void RenderWindowsComand()
{
	static DWORD Addr_JMP = 0x0078E7E7;
	static DWORD This;
	//
	_asm
	{
		MOV DWORD PTR SS:[EBP-4],ECX
		MOV EDX, DWORD PTR SS:[EBP-4]
		MOV This,EDX 
	}

	OpenWindowsCommand(This);

	_asm
	{
		JMP[Addr_JMP]
	}
}

void RenderWindowsChaosMachine(int a1, float a2, float a3)
{
	nInterface.DrawWindowBG(a2, a3);


	int Text_Title;

	switch (sub_50B820((int)&*(BYTE*)0xEBB848))
	{
	case 0:
		Text_Title = 735;
		break;
	case 1:
		Text_Title = 736;
		break;
	case 2:
		Text_Title = 2193;
		break;
	case 3:
		Text_Title = 1640;
		break;
	case 4:
		Text_Title = 1205;
		break;
	case 5:
		Text_Title = 2061;
		break;
	case 6:
		Text_Title = 2062;
		break;
	case 7:
		Text_Title = 2063;
		break;
	case 8:
		Text_Title = 2265;
		break;
	case 9:
		Text_Title = 2563;
	case 10:
		Text_Title = 2660;
		break;
	case 11:
		Text_Title = 2661;
		break;
	case 12:
		Text_Title = 2662;
		break;
	case 13:
		Text_Title = 2663;
		break;
	default:
		Text_Title = 583;
		break;
	}

	switch (sub_50B820((int)&*(BYTE*)0xEBB848))
	{
	case 0:
	case 1:
	case 2:
	case 4:
	case 6:
	case 10:
	case 11:
	case 12:
	case 13:
		gInterface.DrawFormat(-1, a2, a3 + 24 + 6, *(float*)(0x00D24E88), 3, pGetTextLine(pTextLineThis, 1623), *(float*)0x81F6B58); //VAT 


	default:
		break;
	}

	gInterface.DrawFormat(-1, a2, a3 + 23, *(float*)(0x00D24E88), 3, pGetTextLine(pTextLineThis, Text_Title)); // Mix Type

	return;
}

//----- (00823DA0) --------------------------------------------------------
int sub_823DA0(char *This){
    return (int)(This + 4);
}

//----- (00823DC0) --------------------------------------------------------
int sub_823DC0(char *This){
    return (int)(This + 12);
}

//----- (007A8330) --------------------------------------------------------
void RenderMenuESCAPE(char *This){
    float v1; // ST2C_4@1
    float v2; // ST30_4@1
    float v3; // ST24_4@1
    float v4; // ST28_4@1
    float v5; // ST2C_4@1
    float v6; // ST30_4@1
    float v7; // ST2C_4@4
    float v8; // [sp+24h] [bp-Ch]@1
    float v9; // [sp+28h] [bp-8h]@1
    float v10; // [sp+2Ch] [bp-4h]@1
	signed int i; // [sp+1Ch] [bp-14h]@1
    v1 = (double)*(signed int *)sub_823DA0(This);
    v2 = (double)*(signed int *)(sub_823DA0(This) + 4) + 2.0;
    v3 = (double)(*(DWORD *)sub_823DC0(This) - 8);
    v4 = (double)(*(DWORD *)(sub_823DC0(This) + 4) - 10);
    pDrawGUI(31322, v1, v2, v3, v4);
    v5 = (double)*(signed int *)sub_823DA0(This);
    v6 = (double)*(signed int *)(sub_823DA0(This) + 4);
    pDrawGUI(31319, v5, v6, 230.0, 67.0);
    v9 = (double)*(signed int *)sub_823DA0(This);
    v10 = v6 + 67.0;
    v8 = 15.0;
    for ( i = 0; i < 5; ++i ){
        pDrawGUI(31320, v9, v10, 230.0, v8);
        v10 = v10 + v8;
    }
    v7 = (double)*(signed int *)sub_823DA0(This);
    pDrawGUI(31321, v7, v10, 230.0, 50.0);
}

//----- (00848CD0) --------------------------------------------------------
int sub_848CD0(int This){
  int v1; // eax@1
  int v2; // eax@1
  int v3; // eax@1
  v1 = pMakeColor(0xFFu, 0xFFu, 0xFFu, 0);
  sub_7C1C80(This + 24, v1);
  pDrawPuntero(This + 24, 1, 31325, 1, 0, 0);
  ChangeButtonInfo((char *)(This + 24), *(DWORD *)(This + 16) + 68, *(DWORD *)(This + 20) + 209, 43.0, 17.0);
  v2 = pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu);
  sub_779740(This + 24, 0, v2);
  v3 = pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu);
  return sub_779740(This + 24, 1, v3);
}

void DropBox(float X, float Y, float W, float H, float arg5, float arg6)
{
	int v170; // [sp+60h] [bp-2D8h]@1
	float xWindow; // ST08_4@1
	int Width;

	glColor4f(0.0, 0.0, 0.0, 0.50000001);

	v170 = *(DWORD *)(GetInstance() + 312);

	xWindow = (double) *(signed int *)(v170 + 200);

	X = xWindow + Return2X(TransForX( X - xWindow ));

	Width = Return2X(TransForX( W ));

	pDrawBarForm(X, Y, Width, H, arg5, arg6);
}

void DropBoxCornet(int ModelId, float X, float Y, float W, float H)
{
	pDrawGUI(51522, X, Y, W, H);
}

void DropTextureHelper(int ModelId, float X, float Y, float W, float H)
{
	int v170; // [sp+60h] [bp-2D8h]@1
	float xWindow; // ST08_4@1
	int Width;

	v170 = *(DWORD *)(GetInstance() + 312);

	xWindow = (double)*(signed int *)(v170 + 200) + (X - 450);

	if( ModelId == 31759 )
	{
		xWindow = (double)*(signed int *)(v170 + 200) + ((double) X - *(signed int *)(v170 + 200));
	}

	//EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	RenderBitmap(ModelId, TransFor2X( xWindow ), TransForY( Y ), TransForX( W ), TransForY( H ), 0.0, 0.0, 1.0, 0.5949999094, 0, 0, 0);

	pGLSwitch();
	//EnableAlphaTest(0);
}


int RetangleInventory(int num)
{
	float Test = 0;

	if( pWinWidthReal <= 1.6 )
	{
		return num;
	}
	else
	{
		Test = num * pWinHeightReal;
		num = Test / pWinWidthReal;
		return num;
	}
}