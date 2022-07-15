#include "stdafx.h"
#include "LoginRemake.h"
#include "LoginBox.h"
#include "Util.h"
#include "Interface.h"
#include "Object.h"
#include "Offset.h"
#include "Defines.h"
#include "NewFont.h"
#include "CSCharacterS13.h"
#include "Season0.h"
#include "CustomMessage.h"
#include "Console.h"

int PointSY1 = 220;

void LoginBoxRemake()
{	
	int v8; // eax@8
	int v11; // ST04_4@11
	int v17; // ST00_4@11
	int v25; // [sp+101Ch] [bp-1Ch]@32
	int v26; // [sp+1020h] [bp-18h]@26
	char v24; // [sp+814h] [bp-824h]@33
	int v29; // [sp+1034h] [bp-4h]@33
	int v48; // [sp+2Ch] [bp-7Ch]@7	

	//Complementação para resoluções
	int PosXLoginAndSenha = 0;
	int PosXLoginAndSenha2 = 0;
	int PosYLoginAndSenha = 0;
	int PosXConnect = 0;
	int PosYConnect = 0;
	int PosXExit = 0;
	int PosYExit = 0;
	//1280x1024
	int PosPart1Y = 0;
	
	int Baixar = 53;
	int Struct = _Instance() + 16968;
	float startX = (640.0 - getX(329)) / 2, startY = (480.0 - getY(245)) * 2.0 / 3.0;

	if(pWinWidth <= 800)
	{
		PosXLoginAndSenha = 17;
		PosXLoginAndSenha2 = 40;
		PosYLoginAndSenha = 16;
		PosXConnect = -25;
		PosYConnect = 5;
		PosXExit = -2;
		PosYExit = -19;
	}
	if(pWinWidth == 1024)
	{
		PosXLoginAndSenha = 8;
		PosXLoginAndSenha2 = 12;
		PosXConnect = -12;
	}
	if(pWinWidth == 1280 && pWinHeight == 1024)
	{
		PosXLoginAndSenha = 3;
		PosYLoginAndSenha = -15;
		PosPart1Y = 7;
		PosXConnect = -3;
		PosYConnect = -3;
		PosYExit = -22;
	}
	if(pWinWidth == 1440 && pWinHeight == 900)
	{
		PosXLoginAndSenha = -2;
		PosYLoginAndSenha = -10;
		PosPart1Y = 7;
		PosYExit = 12;
		PosXConnect = 3;
		PosYConnect = -3;
	}
	if(pWinWidth == 1680 && pWinHeight == 1050)
	{
		PosXLoginAndSenha2 = -9;
		PosXLoginAndSenha = -5;
		PosYLoginAndSenha = -18;
		PosPart1Y = 7;
		PosYExit = 19;
		PosXConnect = 8;
		PosYConnect = -3;
	}
	if(pWinWidth >= 1920)
	{
		PosXLoginAndSenha2 = -15;
		PosXLoginAndSenha = -7;
		PosYLoginAndSenha = -18;
		PosPart1Y = 7;
		PosYExit = 22;
		PosXConnect = 10;
		PosYConnect = -3;
	}

// - Campo de Login e Senha
	if (*(DWORD*)0xE60960 == 1)
	{
		SetBoundInputField(*(DWORD *)(Struct + 848),startX + getX(114) + PosXLoginAndSenha, startY + getY(56) + Baixar + PointSY1 + PosYLoginAndSenha);
		SetBoundInputField(*(DWORD *)(Struct + 852),startX + getX(114) + PosXLoginAndSenha, startY + getY(88) + Baixar + PointSY1 + PosYLoginAndSenha + PosPart1Y);
	}

	char Testando[200];
	wsprintf(Testando,"v1 %d",PointSY1);
	Console.Write(Testando, 0, 0);

	char Testando2[200];
	wsprintf(Testando,"posx %d / posy %d",pCursorX,pCursorY);

	if(*(int*)0x87935A4 == 2) //Tela de Login
	{	
		if (SEASON3B_CheckMouseIn(326, 351, 67, 15))	
		{
			if (IsPress(1))
			{	
				PlayBuffer(27, 0, 0);
				RequestLogin(Struct);
			}
		}
		if (SEASON3B_CheckMouseIn(287, 436, 67, 15))	
		{
			if (IsPress(1))
			{	
				PlayBuffer(27, 0, 0);
				CancelLogin(Struct);
			}
		}

		if (PointSY1 >= 20)
		{
			PlayBuffer(27, 0, 0);
			PointSY1 -= 20;
		}
	}
	else
	{
		if(SceneFlag == 4)
		{
			if (PointSY1 <= 220)
			{
				PointSY1 += 20;		
			}	
		}
		else
		{
			if (PointSY1 <= 220)
			{
				PointSY1 += 20;		
			}
		}
	}
	//	
	
	// - Imagem LoginBox
	BeginBitmap();
	glColor4f(1.0, 1.0, 1.0, 1.0); //Bota isso antes da imagem
	RenderBitmap(35124, 195.0, 200.5 + Baixar + PointSY1, 250.0, 216.0, 0, 0, 0.9765625, 0.84375, 1, 1, 0.0); //LoginBox

	if(*(int*)0x87935A4 == 2) //Tela de Login
	{	
		if (SEASON3B_CheckMouseIn(326, 351, 67, 15))	
		{
			RenderBitmap(35125, 324.0, 295.0 + Baixar + PointSY1, 70.0, 19.0, 0, 0, 0.546875, 0.59375, 1, 1, 0.0); //Connect
		}

		if (SEASON3B_CheckMouseIn(287, 436, 67, 15))	
		{
			RenderBitmap(35126, 285.0, 380.5 + Baixar, 70.0, 20.0, 0, 0, 0.546875, 0.625, 1, 1, 0.0);
		}
	}

	glColor4f(1.0, 1.0, 1.0, 1.0); //Bota isso depois da imagem
	EndOpengl();

	// - Variáveis de texto
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetFont(pTextThis(), (int)pFontNormal2);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	//pDrawText(pTextThis(), startX + getX(124), startY + getY(158) + Baixar, "Save password", getX(120), 0, (PINT)4, 0);
	pDrawText(pTextThis(), startX + getX(142) + PosXConnect, startY + getY(134) + Baixar + PointSY1 + PosYConnect, gCustomMessage.GetMessageB(452)/*Connect*/, getX(120), 0, (PINT)4, 0);
	pDrawText(pTextThis(), startX - getX(93) + PosXLoginAndSenha2, startY + getY(50) + Baixar + PointSY1 + PosYLoginAndSenha, gCustomMessage.GetMessageB(450)/*Login*/, getX(120), 0, (PINT)4, 0);
	pDrawText(pTextThis(), startX - getX(90) + PosXLoginAndSenha2, startY + getY(85) + Baixar + PointSY1 + PosYLoginAndSenha + PosPart1Y, gCustomMessage.GetMessageB(451)/*Senha*/, getX(120), 0, (PINT)4, 0);
	pDrawText(pTextThis(), startX + getX(55) + PosXExit, startY + getY(270) + Baixar + PointSY1 + PosYExit, gCustomMessage.GetMessageB(453)/*Exit*/, getX(120), 0, (PINT)4, 0);
		
	//pDrawText(pTextThis(), startX - getX(102), startY - getY(50) + Baixar + PointSY1, Testando, getX(120), 0, (PINT)4, 0);pSetFont(pTextThis(), *(DWORD*)0xE8C588);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
}

int __fastcall LoginBoxText(int a1, int a2, signed int a3, signed int a4, char a5)
{
	return DisplayInfoBarCharacter(a1, a2, a3, a4 - 56 + PointSY1, a5);
}

int __fastcall PasswordBoxText(int a1, int a2, signed int a3, signed int a4, char a5)
{
	return DisplayInfoBarCharacter(a1, a2, a3, a4 - 45 + PointSY1, a5);
}

void CentralTextLoginBox(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{	
	pRender_rendertext(g_Fontthis(), iPos_x - 25, iPos_y - 32, "", iBoxWidth, iBoxHeight, iSort, lpTextSize);
}

void RemakeLoginLoad()
{
	SetDword(0x006311B6+1, (DWORD)"Custom\\InterfaceS2\\none.tga");		//Remoção Interface LoginBox
	SetDword(0x006311D6+1, (DWORD)"Custom\\InterfaceS2\\none.tga");		//Remoção Interface LoginBox

	SetCompleteHook(0xE8, 0x004D7D13, &LoginBoxRemake);					//Adição de nova Login_back.tga
	SetCompleteHook(0xE8, 0x0040B1EF, &LoginBoxText);					//Deslocamento do campo de Login
	SetCompleteHook(0xE8, 0x0040B210, &PasswordBoxText);				//Deslocamento do campo de Senha
	SetCompleteHook(0xE8, 0x0040B6A7, &CentralTextLoginBox);			//Deslocamento do texto de Login e Senha - Fazendo sua remoção
	SetCompleteHook(0xE8, 0x0040B635, &CentralTextLoginBox);			//Deslocamento do texto de Login e Senha - Fazendo sua remoção
	
	MemorySet(0x0040B7A2,0x90,0x5);										//Remoção Room Name
	MemorySet(0x0040B2E2,0x90,0x5);										//Remoção Botão OK e Cancelar
	MemorySet(0x0040B306,0x90,0x5);										//Remoção Botão OK e Cancelar
	MemorySet(0x0040B380,0x90,0x5);										//Remoção Botão OK e Cancelar

	MemorySet(0x00401F56,0x90,0x5);
}