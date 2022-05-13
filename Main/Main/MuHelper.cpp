#include "stdafx.h"
#include "NewInterface.h"
#include "CustomWindow.h"
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
#include "MuHelper.h"
#include "CMacroUIEx.h"
#include "OffMuHelper.h"
#include "MenuCustom.h"

CMuHelperS15 gMuHelperS15;


bool CMuHelperS15::isLockCursor()
{
	return gMuHelperS15.macroSwitchServer->data->state && gMuHelperS15.macroSwitchServerHoving;
}

void CMuHelperS15::LoadImages()
{
	pLoadImage("Interface\\GFx\\ex700\\MacroUI_I1.tga", 0xF3001, 0x2601, 0x2900, 1, 0);
}

void CMuHelperS15::RenderFrame(int *This)
{
	char Cord[256];
	float X = (double)*((DWORD *)This + 5);
	float Y = (double)*((signed int *)This + 6);
	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	nInterface.DrawFrame(0xF3001, X + 135, Y, 186, 30, 502, 0, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
	nInterface.DrawFrame(0xF3001, X, Y, 232, 37, 270, 0, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
	if (nInterface.Drawbutton(gMuHelperS15.macroLog, ""))
		if (gCustomMenu.CheckTestWindow())
		{
			gCustomMenu.CloseTestWindow();
		}
		else
		{
			gCustomMenu.OpenTestWindow();
		}

	if(pCursorX > 152 && pCursorX < 169 && pCursorY > 8 && pCursorY < 25 )
	{
		pSetCursorFocus = true;
	}

	if(pCursorX > 171 && pCursorX < 189 && pCursorY > 8 && pCursorY < 25 )
	{
		pSetCursorFocus = true;
	}

	if(pCursorX > 191 && pCursorX < 208 && pCursorY > 8 && pCursorY < 25 )
	{
		pSetCursorFocus = true;
	}

	nInterface.Drawbutton(gMuHelperS15.macroConfig, "");
	nInterface.Drawbutton(gMuHelperS15.macroAuto, "");
	gMuHelperS15.macroAuto->data->state = pMUHelperStat;
	if(CustomSwitchServerUpgrade == 1)
	{
	ConnectServer.currently_subcode = *(DWORD*)0x0986C128;
	if (nInterface.Drawbutton(gMuHelperS15.macroSwitchServer, " "))
	{
		if (gMuHelperS15.macroSwitchServer->data->state == 1)
		{
			ConnectServer.ReqServerList(true);
		}
	}
	if (ConnectServer.currently_subcode)
	{
		if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 0)
			pSetTextColor(pTextThis(), 240, 50, 50, 255);
		else if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 1)
			pSetTextColor(pTextThis(), 50, 240, 50, 255);
		else
			pSetTextColor(pTextThis(), 160, 160, 160, 255);
		wsprintf(Cord, "sub: %d", ConnectServer.currently_subcode);
		pDrawText(pTextThis(), X + 17.5, Y + 3, Cord, 30, 0, (LPINT)0, 0);
	}

	if (gMuHelperS15.macroSwitchServer->data->state == 1)
	{
		ConnectServer.ReqServerList(false);
		nInterface.DrawFrame(0xF3001, X + 7.5 , Y + 21.5, 198, 226, 1, 3, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
		if (nInterface.IsWorkZone(X + 7.5, Y + 21.5, 198 / 1.5, 226 / 1.5))
		{
			gMuHelperS15.macroSwitchServerHoving = true;
		}
		else 
		{
			gMuHelperS15.macroSwitchServerHoving = false;
		}
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 160, 160, 160, 255);
		bool showToolTip = false;
		for (char i = 0; i < ConnectServer.server_list_count; i++)
		{
			if (ConnectServer.currently_subcode - 1 != i){
				if (nInterface.Drawbutton(gMuHelperS15.macroSwitchServerHover, X + 11, Y + 21.5 + 14.65 * i, ""))
				{
					if (!gMuHelperS15.isSwitchServer && gMuHelperS15.lastSwitch + DelaySwitchServer < GetTickCount())
					{
						SwitchServer.switchServer(ConnectServer.SrvStat[i].ServerCode);
						*(DWORD*)0x0986C128 = ConnectServer.SrvStat[i].ServerCode + 1;
						gMuHelperS15.lastSwitch = GetTickCount();
						gMuHelperS15.macroSwitchServer->data->state = 0;
					}
				}
			}
			else 
			{
				if (nInterface.IsWorkZone(X + 11, Y + 21.5 + 14.65 * i, 110, 14))
				{
					showToolTip = true;
				}
			}
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			if (ConnectServer.SrvStat[i].type == 0)
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
			else if (ConnectServer.SrvStat[i].type == 1)
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
			else
				pSetTextColor(pTextThis(), 160, 160, 160, 255);
			wsprintf(Cord, "sub: %d", ConnectServer.SrvStat[i].ServerCode + 1);
			pDrawText(pTextThis(), X + 17.5, Y + 23.5 + 14.65 * i, Cord, 30, 0, (LPINT)0, 0);
			pSetTextColor(pTextThis(), 120, 120, 120, 200);
			//new
			char* ServerTypeName[] = { "[Gold]","[Gold(PvP)]", "[NoN-PvP]", "[Normal]", "[Unknow]" };
			if(ConnectServer.SrvStat[i].ServerCode >= 0 && ConnectServer.SrvStat[i].ServerCode <= 3)
			{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[0], 30, 0, (LPINT)0, 0);
			}
			else if(ConnectServer.SrvStat[i].ServerCode == 4)
			{
			    pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[1], 30, 0, (LPINT)0, 0);
			}
			else if(ConnectServer.SrvStat[i].ServerCode >= 5 && ConnectServer.SrvStat[i].ServerCode <= 8)
			{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[2], 30, 0, (LPINT)0, 0);
			}
			else if(ConnectServer.SrvStat[i].ServerCode >= 9 && ConnectServer.SrvStat[i].ServerCode <= 20)
			{
			    pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[3], 30, 0, (LPINT)0, 0);
			}
			else
			{
				pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[4], 30, 0, (LPINT)0, 0);
			}

			if (ConnectServer.SrvStat[i].UserTotal < 100)
			{
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
				wsprintf(Cord, "%d%%", ConnectServer.SrvStat[i].UserTotal);
			}
			else
			{
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
				wsprintf(Cord, "Full");
			}
			pDrawText(pTextThis(), X + 102.5, Y + 23.5 + 14.65 * i, Cord, 30, 4, (LPINT)0, 0);
		}
		nInterface.Drawbutton(gMuHelperS15.macroSwitchServerSliderUp, "");
		nInterface.Drawbutton(gMuHelperS15.macroSwitchServerSliderDown, "");
		if (showToolTip)
		{
			textSize tS = nInterface.getTextSize("El canal seleccionado actualmente");
			nInterface.DrawToolTipBG(pCursorX + 25, pCursorY, tS.resize_width + 10, tS.resize_height + 4);
			pSetTextColor(pTextThis(), 160, 160, 160, 255);

			pDrawText(pTextThis(), pCursorX + 25, pCursorY + 4, "El canal seleccionado actualmente", tS.resize_width + 10, 0, (LPINT)3, 0);
		}
	}
	}

	if (gMuHelperS15.macroAuto->data->state)
		nInterface.Drawbutton(gMuHelperS15.macroPauseAuto, "");

	//Mapa y Coordenadas

	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 240, 240, 240, 255);

	if (World >= 84 && World <= 100)
	{
		pDrawText(pTextThis(), X + 55, Y + 4, pGetTextLine(pTextLineThis, (3669 + World - 84)), 45, 0, (LPINT)3, 0);
	}
	else
	{
		pDrawText(pTextThis(), X + 55, Y + 4, pMapName(World), 45, 0, (LPINT)3, 0);
	}

	wsprintf(Cord, "%d,%d", gObjUser.CoordenadaX, gObjUser.CoordenadaY);
	pDrawText(pTextThis(), X + 97.5, Y + 4, Cord, 35, 0, (LPINT)4, 0);
	//Extra
	DWORD Color = Color4f(255, 189, 25, 255);
	if(gMuHelperS15.macroAuto->data->state == 1)
	{
		if (offhelper == 1)
		{
			gMuHelper.RunningOffHelper();
		}
	    gInterface.DrawFormat(Color, X + 205, Y + 2.5, 27.5, 3, "1");
	}
	else
	{
		gInterface.DrawFormat(Color, X + 205, Y + 2.5, 27.5, 3, "0");
	}
	pGLSwitch();
	EnableAlphaTest(0);
	//end ------------------
	return;
	
}

void CMuHelperS15::Button(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
}

char BarTime(int This)
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
__declspec(naked) void MuHelperRemake_01()  //<- ConfigHelper
{
	static DWORD Remake_Buffer = 0x007D26DA;
	static DWORD W = gMuHelperS15.macroConfig->data->Width;
	static DWORD H = gMuHelperS15.macroConfig->data->Height;
	static DWORD X = gMuHelperS15.macroConfig->data->X;
	static DWORD Y = gMuHelperS15.macroConfig->data->Y;


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
__declspec(naked) void MuHelperRemake_02()  //<- PlayHelper
{
	static DWORD Remake_Buffer = 0x007D2776;
	static DWORD W = gMuHelperS15.macroAuto->data->Width;
	static DWORD H = gMuHelperS15.macroAuto->data->Height;
	static DWORD X = gMuHelperS15.macroAuto->data->X;
	static DWORD Y = gMuHelperS15.macroAuto->data->Y;


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
__declspec(naked) void MuHelperRemake_03()  //<- PauseHelper
{
	static DWORD Remake_Buffer = 0x007D2821;
	static DWORD W = gMuHelperS15.macroPauseAuto->data->Width;
	static DWORD H = gMuHelperS15.macroPauseAuto->data->Height;
	static DWORD X = gMuHelperS15.macroPauseAuto->data->X;
	static DWORD Y = gMuHelperS15.macroPauseAuto->data->Y;

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

void CMuHelperS15::Load()
{
	//SetCompleteHook(0xE8, 0x007F76CD, &OffHelper);
	this->isSwitchServer = false;
	this->lastSwitch = GetTickCount() - DelaySwitchServer;
	this->macroSwitchServerHoving = false;
	SetCompleteHook(0xE9, 0x007D2BC0, gMuHelperS15.RenderFrame);
	SetCompleteHook(0xE9, 0x0080B8E0, &BarTime);
	SetCompleteHook(0xE9, 0x007D26B5, &MuHelperRemake_01);
	SetCompleteHook(0xE9, 0x007D2751, &MuHelperRemake_02);
	SetCompleteHook(0xE9, 0x007D27FC, &MuHelperRemake_03);
}
