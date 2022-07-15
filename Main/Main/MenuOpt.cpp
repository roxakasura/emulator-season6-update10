#include "stdafx.h"
#include "MenuOpt.h"
#include "Import.h"
#include "LoginBox.h"
#include "Antilag.h"
#include "Interface.h"
#include "SEASON3B.h"
#include "Util.h"
#include "BuffIcon.h"
#include "ModelEffect.h"
#include "QuickCommandWindow.h"

int MenuOpt = 0;
int OptStatus;
int OptionBuff;
int CtrlAtive;
int EffectAtive;
int FlagAtive;
DWORD TimeEventVK;
DWORD TimeEventVK2;
DWORD TimeEventVK3;

void RenderWindowsOptionOriginal(int a1)
{
	int v4; // ST24_4@1
	float v5; // ST08_4@1
	float v6; // ST04_4@1
	float v7; // ST08_4@1
	float v8; // ST04_4@1
	float v9; // ST20_4@1
	float v10; // ST04_4@1
	float v11; // ST1C_4@1
	float v12; // ST18_4@1
	float v13; // ST14_4@1
	float v14; // ST04_4@1
	
	float MainWidth = 230.0;
	float StartX = (640 / 2) - (MainWidth / 2);
	
	v4 = *(DWORD*)(GetInstance() + 160);

	v5 = (double)*(signed int *)(v4 + 20);
	v6 = (double)*(signed int *)(v4 + 16);
	RenderImageB(31322, v6, v5, 190.0, 260.0);
	v7 = (double)*(signed int *)(v4 + 20);
	v8 = (double)*(signed int *)(v4 + 16);
	RenderImageB(31353, v8, v7, 190.0, 64.0);
	v9 = (double)*(signed int *)(v4 + 20) + 64.0;
	v10 = (double)*(signed int *)(v4 + 16);
	RenderImageB(31355, v10, v9, 21.0, 190.0);
	v11 = (double)*(signed int *)(v4 + 20) + 64.0;
	v12 = (double)*(signed int *)(v4 + 16) + 190.0 - 21.0;
	RenderImageB(31356, v12, v11, 21.0, 190.0);
	v13 = (double)*(signed int *)(v4 + 20) + 220.0;
	v14 = (double)*(signed int *)(v4 + 16);
	RenderImageB(31357, v14, v13, 190.0, 45.0);

	//if (MenuOpt == 0) { pDrawGUI(0x7903, StartX + MainWidth - 38, 150, 25, 40); }
	//if (MenuOpt == 1) { pDrawGUI(0x7904, StartX + 10, 150, 25, 40); }
	//
	//if (IsCursorInZone(StartX + MainWidth - 38, 150, 25, 40))
	//{
	//	if (pIsKeyRelease(VK_LBUTTON) && MenuOpt == 0) {gAntiLagSystem.OpenTestWindow(); PlayBuffer(25, 0, 0); }
	//}
	//
	//if (IsCursorInZone(StartX + 10, 150, 25, 40))
	//{
	//	if (pIsKeyRelease(VK_LBUTTON) && MenuOpt == 1) { MenuOpt = 0; PlayBuffer(25, 0, 0); }
	//}
}

int RenderOptionTextOriginal(int a1)
{
	int v4; // ST1C_4@1
	float v5; // ST20_4@1
	float v6; // ST24_4@1
	float v7; // ST24_4@1
	float v8; // ST24_4@1
	float v9; // ST24_4@1
	float v10; // ST24_4@1
	HGDIOBJ v11; // ST18_4@1
	void* v12; // eax@1
	void* v13; // eax@1
	void* v14; // eax@1
	int v15; // ST08_4@1
	int v16; // ST04_4@1
	int v17; // ST00_4@1
	void* v18; // eax@1
	int v19; // ST08_4@1
	int v20; // ST04_4@1
	int v21; // ST00_4@1
	void* v22; // eax@1
	int v23; // ST08_4@1
	int v24; // ST04_4@1
	int v25; // ST00_4@1
	void* v26; // eax@1
	int v27; // ST08_4@1
	int v28; // ST04_4@1
	int v29; // ST00_4@1
	void* v30; // eax@1
	int v31; // ST08_4@1
	int v32; // ST04_4@1
	int v33; // ST00_4@1
	void* v34; // eax@1
	int v35; // ST04_4@1
	int v36; // ST00_4@1
	float prox;
	float prox1;
	float prox2;
	float PosY;

	v4 = *(DWORD*)(GetInstance() + 160);

	PosY = 0;
	v5 = (double)*(signed int*)(v4 + 16) + 20.0;
	v6 = (double)*(signed int*)(v4 + 20) + 46.0;
	pDrawGUI(31592, v5, v6, 10.0, 10.0);
	v7 = v6 + 22.0;
	pDrawGUI(31592, v5, v7, 10.0, 10.0);
	v8 = v7 + 22.0;
	pDrawGUI(31592, v5, v8, 10.0, 10.0);
	v9 = v8 + 40.0;
	pDrawGUI(31592, v5, v9, 10.0, 10.0);
	v10 = v9 + 22.0;
	pDrawGUI(31592, v5, v10, 10.0, 10.0);
	prox = v10 + 58.0;
	pDrawGUI(31592, v5, prox, 10.0, 10.0);
	prox1 = prox + 22.0;
	pDrawGUI(31592, v5, prox1, 10.0, 10.0);

	pSetFont(pTextThis(), (int)pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	sub_4200F0_Addr(pTextThis(), 0);

	v16 = *(DWORD*)(v4 + 20) + 48 + PosY;
	v17 = *(DWORD*)(v4 + 16) + 40;
	pDrawText(pTextThis(), v17, v16, pGetTextLine(pTextLineThis, 386), 0, 0, (PINT)1, 0); //-- Attack Automatic

	v20 = *(DWORD*)(v4 + 20) + 70 + PosY;
	v21 = *(DWORD*)(v4 + 16) + 40;
	pDrawText(pTextThis(), v21, v20, pGetTextLine(pTextLineThis, 387), 0, 0, (PINT)1, 0); //-- Beep Sound

	v24 = *(DWORD*)(v4 + 20) + 92 + PosY;
	v25 = *(DWORD*)(v4 + 16) + 40;
	pDrawText(pTextThis(), v25, v24, pGetTextLine(pTextLineThis, 389), 0, 0, (PINT)1, 0); //-- Volumen

	v28 = *(DWORD*)(v4 + 20) + 132 + PosY;
	v29 = *(DWORD*)(v4 + 16) + 40;
	pDrawText(pTextThis(), v29, v28, pGetTextLine(pTextLineThis, 919), 0, 0, (PINT)1, 0); //-- Slide Help

	v35 = *(DWORD *)(v4 + 20) + 211 + PosY;
	v36 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v36, v35, "CTRL Automatic", 0, 0, (PINT)1, 0); //-- Ctrl Ativo
	
	v35 = *(DWORD *)(v4 + 20) + 233 + PosY;
	v36 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v36, v35, "View Item Equipped", 0, 0, (PINT)1, 0); //-- Effects

	v32 = *(DWORD*)(v4 + 20) + 154 + PosY;
	v33 = *(DWORD*)(v4 + 16) + 40;
	return pDrawText(pTextThis(), v33, v32, pGetTextLine(pTextLineThis, 1840), 0, 0, (PINT)1, 0); //-- Effect Limit
}

void RenderOptionPanelOriginal(int a1)
{
	float v4; // ST08_4@2
	float v5; // ST04_4@2
	float v6; // ST08_4@3
	float v7; // ST04_4@3
	float v8; // ST08_4@5
	float v9; // ST04_4@5
	float v10; // ST08_4@6
	float v11; // ST04_4@6
	float v12; // ST08_4@8
	float v13; // ST04_4@8
	float v14; // ST08_4@9
	float v15; // ST04_4@9
	float v16; // ST10_4@10
	float v17; // ST0C_4@10
	float v18; // ST3C_4@11
	float v19; // ST10_4@11
	float v20; // ST0C_4@11
	float v21; // ST10_4@12
	float v22; // ST0C_4@12
	float v23; // ST24_4@13
	float v24; // ST10_4@13
	float v25; // ST0C_4@13
	int v26; // [sp+74h] [bp-4h]@1
	float v122; // ST08_4@8
	float v132; // ST04_4@8
	float v142; // ST08_4@9
	float v152; // ST04_4@9
	float v162; // ST08_4@9
	float v172; // ST04_4@9
	float PosY;

	v26 = a1;
	sub_7798F0(a1 + 24, 0);
	float X = 0.0;
	if (*(BYTE*)(v26 + 196))
	{
		v4 = (double)(*(DWORD*)(v26 + 20) + 43);
		v5 = (double)(*(DWORD*)(v26 + 16) + 150 + X);
		pDrawButton(31593, v5, v4, 15.0, 15.0, 0.0, 0.0);  //click attack
	}
	else
	{
		v6 = (double)(*(DWORD*)(v26 + 20) + 43);
		v7 = (double)(*(DWORD*)(v26 + 16) + 150 + X);
		pDrawButton(31593, v7, v6, 15.0, 15.0, 0.0, 15.0);  //click attack
	}
	if (*(BYTE*)(v26 + 197))
	{
		v8 = (double)(*(DWORD*)(v26 + 20) + 65);
		v9 = (double)(*(DWORD*)(v26 + 16) + 150) + X;
		pDrawButton(31593, v9, v8, 15.0, 15.0, 0.0, 0.0);  //click som
	}
	else
	{
		v10 = (double)(*(DWORD*)(v26 + 20) + 65);
		v11 = (double)(*(DWORD*)(v26 + 16) + 150 + X);
		pDrawButton(31593, v11, v10, 15.0, 15.0, 0.0, 15.0);  //click som
	}

	if (*(BYTE*)(v26 + 198)) //slide helper
	{
		v12 = (double)(*(DWORD*)(v26 + 20) + 127);
		v13 = (double)(*(DWORD*)(v26 + 16) + 150);
		pDrawButton(31593, v13, v12, 15.0, 15.0, 0.0, 0.0);
	}
	else
	{
		v14 = (double)(*(DWORD*)(v26 + 20) + 127);
		v15 = (double)(*(DWORD*)(v26 + 16) + 150);
		pDrawButton(31593, v15, v14, 15.0, 15.0, 0.0, 15.0);
	}

//Novos
	v122 = (double)(*(DWORD *)(v26 + 20) + 205 + PosY);
	v132 = (double)(*(DWORD *)(v26 + 16) + 150);

	if(pCheckMouseOver( v132, v122, 15, 15 ) && (*(BYTE*)0x8793386) && GetTickCount() >= TimeEventVK + 250 )
	{
		if(CtrlAtive !=0)
		{	
			//gInterface.DrawMessage(1, "Auto PVP [OFF]");
			SetByte(0x0059AF53+2,1);
			SetByte(0x0059B248+2,1);
			CtrlAtive = 0;
		}
		else
		{
			//gInterface.DrawMessage(1, "Auto PVP [ON]");
			SetByte(0x0059AF53+2,0);
			SetByte(0x0059B248+2,0);			
			CtrlAtive = 1;
		}
		TimeEventVK = GetTickCount();
	}

	if(CtrlAtive == 0)
	{
		pDrawButton(31593, v132, v122, 15.0, 15.0, 0.0, 15.0);
	}
	if(CtrlAtive == 1)
	{
		pDrawButton(31593, v132, v122, 15.0, 15.0, 0.0, 0.0);
	}
//	---------------------------------
	v142 = (double)(*(DWORD *)(v26 + 20) + 227 + PosY);
	v152 = (double)(*(DWORD *)(v26 + 16) + 150);

	if(pCheckMouseOver( v152, v142, 15, 15 ) && (*(BYTE*)0x8793386) && GetTickCount() >= TimeEventVK2 + 250 )
	{
		if(OptStatus !=0)
		{	
			//gInterface.DrawMessage(1, "Teste [OFF 2]");
			ItemEquippedStatus(0);
			OptStatus = 0;
		}
		else
		{
			//gInterface.DrawMessage(1, "Teste [ON 2]");
			ItemEquippedStatus(1);
			OptStatus = 1;
		}
		TimeEventVK2 = GetTickCount();
	}

	if(OptStatus == 0)
	{
		pDrawButton(31593, v152, v142, 15.0, 15.0, 0.0, 15.0);
	}
	if(OptStatus == 1)
	{
		pDrawButton(31593, v152, v142, 15.0, 15.0, 0.0, 0.0);
	}

	//volume click and image
	v16 = (double)(*(DWORD*)(v26 + 20) + 104);
	v17 = (double)(*(DWORD*)(v26 + 16) + 33);
	pDrawGUI(31596, v17, v16, 124.0, 16.0);

	if (*(DWORD*)(v26 + 200) > 0)
	{
		//volume click and image
		v18 = (double)*(signed int*)(v26 + 200) * 12.40000057220459;
		v19 = (double)(*(DWORD*)(v26 + 20) + 104);
		v20 = (double)(*(DWORD*)(v26 + 16) + 33);
		pDrawGUI(31597, v20, v19, v18, 16.0);
	}

	//effect limitation
	v21 = (double)(*(DWORD*)(v26 + 20) + 168);
	v22 = (double)(*(DWORD*)(v26 + 16) + 25);
	pDrawGUI(31594, v22, v21, 141.0, 29.0);
	if (*(DWORD*)(v26 + 204) >= 0)
	{
		//effect limitation
		v23 = (double)(*(DWORD*)(v26 + 204) + 1) * 28.20000076293945;
		v24 = (double)(*(DWORD*)(v26 + 20) + 168);
		v25 = (double)(*(DWORD*)(v26 + 16) + 25);
		pDrawGUI(31595, v25, v24, v23, 29.0);
	}
}

void ItemEquippedStatus(int Status)
{
	PMSG_ITEMVIEW_SEND pMsg;
	pMsg.h.set(0xF3, 0xF2, sizeof(pMsg));
	pMsg.Status = Status;
	DataSend((LPBYTE)&pMsg, pMsg.h.size);
}

void MenuLoad()
{
	//SetCompleteHook(0xE9, 0x008494B0, &RenderWindowsOptionOriginal); //fundo do painel
	//SetCompleteHook(0xE9, 0x00849730, &RenderOptionTextOriginal);  //textos do painel
	//SetCompleteHook(0xE9, 0x008499E0, &RenderOptionPanelOriginal); //opções do painel
	//MemorySet(0x00848CB6,0x90,0x5); //REMOVE CLOSE BUTTON
}