#include "stdafx.h"
#include "NewInfo.h"
#include "NewInterface.h"
#include "Central.h"
#include "Defines.h"
#include "Interface.h"
#include "CustomLuckyWheel.h"

int Result;
int ItemIndex[12];
int ItemLevel[12];
int ItemNewOption[12];
int ItemSetOption[12];
int Level;
int Resets;
char Name[10];

void GCInfoChar(PMSG_INFOCHARVIEW_RECV* lpMsg)
{	
	Result = lpMsg->result;

	Level = lpMsg->Level;

	Resets = lpMsg->Resets;

	for (int n = 0; n < INVENTORY_WEAR_SIZE; n++)
	{
		ItemIndex[n] = lpMsg->ItemIndex[n];
		ItemLevel[n] = lpMsg->ItemLevel[n];
		ItemNewOption[n] = lpMsg->ItemNewOption[n];
		ItemSetOption[n] = lpMsg->ItemSetOption[n];
	}

	memcpy(Name, lpMsg->name, sizeof(Name));
}

void DrawNewWindow()
{
	int This; // ST24_4@1
	int v24;
	float MainWidth			= 330.0;
	float MainHeight		= 320.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	DWORD Color = eGray100;
	
	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

	// ----
	if(Result == 0)
	{
		gInterface.DrawFormat(eGold, (int)StartX + 65, (int)StartBody + 10, 210, 3, "Informações do Personagem");
	}
	else
	{
		gInterface.DrawFormat(eGold, (int)StartX + 65, (int)StartBody + 10, 210, 3, "Informações do Personagem: %s",Name);
	}

	RenderBitmap(41022, StartX+30, StartY+80, 157, 158, 0.0, 0.00249, 0.626646347, 0.5912757, 1, 1, 1.0);
		
	if(Result == 1)
	{
		DrawItemImage(152,200,70,30,ItemIndex[0], SET_ITEMOPT_LEVEL(ItemLevel[0]), 0, ItemNewOption[0], 0); //ESPADA 1

		DrawItemImage(291,188,65,47,ItemIndex[1], SET_ITEMOPT_LEVEL(ItemLevel[1]), 0, ItemNewOption[1], 0); //ESPADA 2

		DrawItemImage(230,130,65,47,ItemIndex[2], SET_ITEMOPT_LEVEL(ItemLevel[2]), 0, ItemNewOption[2], 0); //HELM

		DrawItemImage(233,180,65,50,ItemIndex[3], SET_ITEMOPT_LEVEL(ItemLevel[3]), 0, ItemNewOption[3], 0); //ARMOR

		DrawItemImage(233,243,65,50,ItemIndex[4], SET_ITEMOPT_LEVEL(ItemLevel[4]), 0, ItemNewOption[4], 0); //PANTS

		DrawItemImage(175,243,63,50,ItemIndex[5], SET_ITEMOPT_LEVEL(ItemLevel[5]), 0, ItemNewOption[5], 0); //GLOVES

		DrawItemImage(288,247,70,45,ItemIndex[6], SET_ITEMOPT_LEVEL(ItemLevel[6]), 0, ItemNewOption[6], 0); //BOOTS

		DrawItemImage(278,138,70,30,ItemIndex[7], SET_ITEMOPT_LEVEL(ItemLevel[7]), 0, ItemNewOption[7], 0); //WINGS

		DrawItemImage(169,128,70,45,ItemIndex[8], SET_ITEMOPT_LEVEL(ItemLevel[8]), 0, ItemNewOption[8], 0);

		DrawItemImage(161,299,70,45,ItemIndex[9], SET_ITEMOPT_LEVEL(ItemLevel[9]), 0, ItemNewOption[9], 0);
		DrawItemImage(163,159,70,50,ItemIndex[10],SET_ITEMOPT_LEVEL(ItemLevel[10]),0,ItemNewOption[10],0);
		DrawItemImage(163,218,70,50,ItemIndex[11],SET_ITEMOPT_LEVEL(ItemLevel[11]),0,ItemNewOption[11],0);

		
		gInterface.DrawFormat(eGold, (int)StartX + 200, (int)StartBody + 120, 0, 3, "Nome: %s",Name);
		gInterface.DrawFormat(eGold, (int)StartX + 200, (int)StartBody + 140, 0, 3, "Level: %d",Level);
		gInterface.DrawFormat(eGold, (int)StartX + 200, (int)StartBody + 160, 0, 3, "Resets: %d",Resets);
	}
	//
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor
}

void DrawItemImage(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Anc, int Excl, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	CRenderItem3D(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	glColor3f(1, 1, 1);
	pSetBlend(false);
}
