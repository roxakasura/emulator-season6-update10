#include "stdafx.h"
#include "NewInterface.h"
#include "CustomWindow.h"
#include "CMacroUIEx.h"
#include "Util.h"
#include "Offset.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "NewFont.h"
#include "Protocol.h"
#include "ConnectServer.h"
#include "SwitchServer.h"
#include "Protect.h"
#include "Common.h"

CMacroUIEx gCMacroUIEx;


bool CMacroUIEx::isLockCursor(){
	return gCMacroUIEx.macroSwitchServer->data->state && gCMacroUIEx.macroSwitchServerHoving;
}

void CMacroUIEx::LoadImages(){
	pLoadImage("Interface\\GFx\\ex700\\MacroUI_I1.tga", 0xF3001, 0x2601, 0x2900, 1, 0);
}

void CMacroUIEx::RenderFrame(int *This)
{
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	return;
}

void CMacroUIEx::Button(DWORD Event){
	DWORD CurrentTick = GetTickCount();
}

char BarTime2(int This)
{
	float v1; // ST10_4@2
	float v2; // ST0C_4@2
	float v3; // ST30_4@3
	float v4; // ST08_4@3
	float v5; // ST04_4@3
	float v6; // ST10_4@5
	float v7; // ST0C_4@5
	float v8; // ST1C_4@5
	float v9; // ST08_4@5
	float v10; // ST04_4@5
	const CHAR *v11; // eax@7
	int v13; // [sp+30h] [bp-4h]@1

	v13 = This;

	return 1;
	if (*(BYTE *)(This + 72) == 1)
	{
		v1 = (double)*(signed int *)(This + 20);
		v2 = (double)*(signed int *)(This + 16);
		RenderImage2(51522, v2, v1);//Textura "none.tga"
		if (*(DWORD *)(v13 + 88) == 1)
		{
			v3 = *(float *)(v13 + 92) * 50.0;
			v4 = (double)(*(DWORD *)(v13 + 20) + 2);
			v5 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(51549, v5 + 108.0, v4 - 16.0, v3, 3.0);
		}
		else if (*(DWORD *)(v13 + 88) > 1)
		{
			v6 = (double)(*(DWORD *)(v13 + 20) + 2);
			v7 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage2(*(DWORD *)(v13 + 88) + 31763, v7, v6);
			v8 = *(float *)(v13 + 92) * 152.0;
			v9 = (double)(*(DWORD *)(v13 + 20) + 2);
			v10 = (double)(*(DWORD *)(v13 + 16) + 2);
			RenderImage(*(DWORD *)(v13 + 88) + 51522, v10, v9, v8, 4.0);//Textura "none.tga"
		}
		//DrawToolTip
		/*
		if ( *(_BYTE *)(v13 + 128) == 1 )
		{
		v11 = (const CHAR *)sub_402880(v13 + 100);
		sub_597220(*(_DWORD *)(v13 + 132), *(_DWORD *)(v13 + 136), v11);
		}
		*/
	}
	return 1;
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_012()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = gCMacroUIEx.macroConfig->data->Width;
	static DWORD H = gCMacroUIEx.macroConfig->data->Height;
	static DWORD X = gCMacroUIEx.macroConfig->data->X;
	static DWORD Y = gCMacroUIEx.macroConfig->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x18]; |
			PUSH Y; | Arg4
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0x14]; |
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0xC]; |
			LEA EDX, DWORD PTR DS : [EDX + ECX + 0x29]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_022()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = gCMacroUIEx.macroAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroAuto->data->Y;


	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}
//-- (007D25C0)
__declspec(naked) void MuHelperRemake_032()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = gCMacroUIEx.macroPauseAuto->data->Width;
	static DWORD H = gCMacroUIEx.macroPauseAuto->data->Height;
	static DWORD X = gCMacroUIEx.macroPauseAuto->data->X;
	static DWORD Y = gCMacroUIEx.macroPauseAuto->data->Y;

	_asm
	{
		PUSH H; | Arg6 = 0000000D
			PUSH W; | Arg5 = 00000012
			MOV EAX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV ECX, DWORD PTR DS : [EAX + 0x18]; |
			PUSH Y; | Arg4
			MOV EDX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EAX, DWORD PTR DS : [EDX + 0x14]; |
			MOV ECX, DWORD PTR SS : [EBP - 0xB8]; |
			MOV EDX, DWORD PTR DS : [ECX + 0xC]; |
			LEA EAX, DWORD PTR DS : [EAX + EDX + 0x3B]; |
			PUSH X; | Arg3
			JMP[Remake_Buffer]
	}
}

void CMacroUIEx::Load()
{
	if(gProtect.m_MainInfo.HelperInterface == 0)
	{
		SetCompleteHook(0xE9, 0x007D2BC0, gCMacroUIEx.RenderFrame);
		SetCompleteHook(0xE9, 0x0080B8E0, &BarTime2);
		SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_012);
		SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_022);
		SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_032);
		}
}