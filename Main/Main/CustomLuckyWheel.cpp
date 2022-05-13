#include "stdafx.h"
#include "CustomLuckyWheel.h"
#include "Defines.h"
#include "Interface.h"
#include "Protect.h"
#include "Central.h"
#include "CustomInterface.h"
#include "WindowsStruct.h"

CLuckyWheel gLuckyWheel;

CLuckyWheel::CLuckyWheel(){
	this->Init();
}

CLuckyWheel::~CLuckyWheel(){
}

void CLuckyWheel::LoadImages()
{
	pLoadImage1("Custom\\Interface\\LuckyWheel\\itembackpanel.tga", 0x9326, 0x2601, 0x2900, 1, 0);
	pLoadImage1("Custom\\Interface\\LuckyWheel\\topmenutabbt1.tga", 0x9327, 0x2601, 0x2900, 1, 0);
	pLoadImage1("Custom\\Interface\\LuckyWheel\\ui_dialog_e.tga", 0x9328, 0x2601, 0x2900, 1, 0);
	pLoadImage1("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 71535, GL_LINEAR, GL_CLAMP, 1, 0);
}

void CLuckyWheel::Bind(){
	gInterface.BindObject(eLuckyWheelPanel, 0x9328, 312, 292, -1, -1);
	if(gProtect.m_MainInfo.CustomInterfaceType <= 2)
	{
		gInterface.BindObject(eLuckyWheelStart, 0x9327, 82, 33, -1, -1);
		gInterface.BindObject(eCloseLuckyWheelKG, 0X7EC5, 36, 29, -1, -1);
	}
	else
	{
		gInterface.BindObject(eLuckyWheelStart, 71535, 65, 26, -1, -1);
		gInterface.BindObject(eCloseLuckyWheelKG, 71535, 65, 26, -1, -1);
	}

	LuckyWheelNumber = -1;
}

void CLuckyWheel::Init()
{
	for(int n=0;n < MAX_ITEM_LUCKY;n++)
	{
		this->m_LuckyWheelInfo[n].Index = -1;
	}
}

void CLuckyWheel::Load(LUCKYWHEEL_INFO* info)
{
	for(int n=0;n < MAX_ITEM_LUCKY;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CLuckyWheel::SetInfo(LUCKYWHEEL_INFO info)
{
	if(info.Index < 0 || info.Index >= MAX_ITEM_LUCKY)
	{
		return;
	}
	this->m_LuckyWheelInfo[info.Index] = info;
}

bool CLuckyWheel::EventDrawClose_LuckyWheelKG(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eCloseLuckyWheelKG].EventTick);
	if (!gInterface.Data[eLuckyWheelMain].OnShow || !gInterface.IsWorkZone(eCloseLuckyWheelKG))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eCloseLuckyWheelKG].OnClick = true;
		return true;
	}
	gInterface.Data[eCloseLuckyWheelKG].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	gInterface.Data[eCloseLuckyWheelKG].EventTick = GetTickCount();
	this->LuckyWheelStateclose();
	return false;
}


void CLuckyWheel::DrawLuckyWheel803()
{
	if (this->LuckyWheelActive == 0)
	{
		return;
	}

	if (!gInterface.Data[eLuckyWheelMain].OnShow)
	{
		return;
	}

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

	//Box1
	//fila de cima
	gCentral.PrintDropBox(StartX + 13, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 92, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 177, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 256, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	//fila lado esquerdo
	gCentral.PrintDropBox(StartX + 256, StartY + 111, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 256, StartY + 176, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 256, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	//fila de baixo
	gCentral.PrintDropBox(StartX + 13, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 92, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 177, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	//fila lado direito
	gCentral.PrintDropBox(StartX + 13, StartY + 111, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
	gCentral.PrintDropBox(StartX + 13, StartY + 176, MainWidth - 270.0, MainHeight - 273.0, 0, 0);

	// ----
	gInterface.DrawFormat(eGold, (int)StartX + 65, (int)StartBody + 10, 210, 3, "Lucky Wheel");

	//
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor

	if(this->LuckyWheelNumber > 0)
	{
		pSetBlend(true);
		switch (LuckyWheelNumber)
		{
		case 0:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 1:
			gCentral.PrintDropBoxTest(StartX + 92, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 2:
			gCentral.PrintDropBoxTest(StartX + 177, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 3:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 4:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 111, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 5:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 176, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 6:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 7:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 8:
			gCentral.PrintDropBoxTest(StartX + 92, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 9:
			gCentral.PrintDropBoxTest(StartX + 177, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 10:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 111, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 11:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 176, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		}
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
	}
	
	if(this->StartRoll >= 1)
	{
		pSetBlend(true);
		int roll = rand() % 12;
		switch (roll)
		{
		case 0:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 1:
			gCentral.PrintDropBoxTest(StartX + 92, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 2:
			gCentral.PrintDropBoxTest(StartX + 177, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 3:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 46, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 4:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 111, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 5:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 176, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 6:
			gCentral.PrintDropBoxTest(StartX + 256, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 7:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 8:
			gCentral.PrintDropBoxTest(StartX + 92, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 9:
			gCentral.PrintDropBoxTest(StartX + 177, StartY + 247, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 10:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 111, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		case 11:
			gCentral.PrintDropBoxTest(StartX + 13, StartY + 176, MainWidth - 270.0, MainHeight - 273.0, 0, 0);
		break;
		}
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
	}

	gInterface.DrawItem2(163,100,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[0].ItemType,gLuckyWheel.m_LuckyWheelInfo[0].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[0].Level),gLuckyWheel.m_LuckyWheelInfo[0].Exc,0,0);
	gInterface.DrawItem2(243,100,65,47,ITEM(gLuckyWheel.m_LuckyWheelInfo[1].ItemType,gLuckyWheel.m_LuckyWheelInfo[1].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[1].Level),gLuckyWheel.m_LuckyWheelInfo[1].Exc,0,0);
	gInterface.DrawItem2(327,100,65,47,ITEM(gLuckyWheel.m_LuckyWheelInfo[2].ItemType,gLuckyWheel.m_LuckyWheelInfo[2].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[2].Level),gLuckyWheel.m_LuckyWheelInfo[2].Exc,0,0);
	gInterface.DrawItem2(407,100,65,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[3].ItemType,gLuckyWheel.m_LuckyWheelInfo[3].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[3].Level),gLuckyWheel.m_LuckyWheelInfo[3].Exc,0,0);
	gInterface.DrawItem2(407,157,65,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[4].ItemType,gLuckyWheel.m_LuckyWheelInfo[4].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[4].Level),gLuckyWheel.m_LuckyWheelInfo[4].Exc,0,0);
	gInterface.DrawItem2(407,222,63,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[5].ItemType,gLuckyWheel.m_LuckyWheelInfo[5].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[5].Level),gLuckyWheel.m_LuckyWheelInfo[5].Exc,0,0);
	gInterface.DrawItem2(405,299,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[6].ItemType,gLuckyWheel.m_LuckyWheelInfo[6].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[6].Level),gLuckyWheel.m_LuckyWheelInfo[6].Exc,0,0);
	gInterface.DrawItem2(325,299,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[7].ItemType,gLuckyWheel.m_LuckyWheelInfo[7].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[7].Level),gLuckyWheel.m_LuckyWheelInfo[7].Exc,0,0);
	gInterface.DrawItem2(241,299,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[8].ItemType,gLuckyWheel.m_LuckyWheelInfo[8].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[8].Level),gLuckyWheel.m_LuckyWheelInfo[8].Exc,0,0);
	gInterface.DrawItem2(161,299,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[9].ItemType,gLuckyWheel.m_LuckyWheelInfo[9].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[9].Level),gLuckyWheel.m_LuckyWheelInfo[9].Exc,0,0);
	gInterface.DrawItem2(163,159,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[10].ItemType,gLuckyWheel.m_LuckyWheelInfo[10].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[10].Level),gLuckyWheel.m_LuckyWheelInfo[10].Exc,0,0);
	gInterface.DrawItem2(163,218,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[11].ItemType,gLuckyWheel.m_LuckyWheelInfo[11].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[11].Level),gLuckyWheel.m_LuckyWheelInfo[11].Exc,0,0);
	
	if(this->LuckyWheelNumber >= 0)
	{
	    gInterface.DrawItem2(295,190,50,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].ItemType,gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].ItemIndex),gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].Level,gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].Exc,0,0);
	}

	pSetCursorFocus = true;
	gInterface.DrawGUI(eLuckyWheelStart,StartX + 85, StartY + 209.5f);
	gInterface.DrawFormat(eWhite, StartX + 113, StartY + 217.5f, 50.0f, 1.0f, "Start");

    if( gInterface.IsWorkZone(eLuckyWheelStart) )
	{
    	DWORD Color = eGray100;
    	if( gInterface.Data[eLuckyWheelStart].OnClick )
		{
    		Color = eGray150;
    	}
    	gInterface.DrawColoredGUI(eLuckyWheelStart, gInterface.Data[eLuckyWheelStart].X, gInterface.Data[eLuckyWheelStart].Y, Color);
    }
	
    gInterface.DrawGUI(eCloseLuckyWheelKG, StartX + 180, StartY + 209.5f);
	gInterface.DrawFormat(eWhite, StartX + 207, StartY + 216.5f, 50.0f, 1.0f, "Close");
    if (gInterface.IsWorkZone(eCloseLuckyWheelKG))
	{
    	DWORD Color = eGray100;
    	if (gInterface.Data[eCloseLuckyWheelKG].OnClick)
		{
    		Color = eGray150;
    	}
    	gInterface.DrawColoredGUI(eCloseLuckyWheelKG, gInterface.Data[eCloseLuckyWheelKG].X, gInterface.Data[eCloseLuckyWheelKG].Y, Color);
    }
}


void CLuckyWheel::DrawLuckyWheel()
{
	//if (this->LuckyWheelActive == 0)
	//{
	//	return;
	//}

	if (!gInterface.Data[eLuckyWheelMain].OnShow)
	{
		return;
	}

	pDrawGUI(0x9328, 145, 55, 312, 292); //1
	pDrawGUI(0x9326, 160, 100, 70, 57); //1
	pDrawGUI(0x9326, 230, 100, 70, 57); //2
	pDrawGUI(0x9326, 300, 100, 70, 57); //3
	pDrawGUI(0x9326, 370, 100, 70, 57); //4
	pDrawGUI(0x9326, 370, 157, 70, 57); //5
	pDrawGUI(0x9326, 370, 214, 70, 57); //6
	pDrawGUI(0x9326, 370, 271, 70, 57); //7
	pDrawGUI(0x9326, 300, 271, 70, 57); //8
	pDrawGUI(0x9326, 230, 271, 70, 57); //9
	pDrawGUI(0x9326, 160, 271, 70, 57); //10
	pDrawGUI(0x9326, 160, 157, 70, 57); //11
	pDrawGUI(0x9326, 160, 214, 70, 57); //12
	if(this->LuckyWheelNumber > 0)
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, 0.3);
		switch (LuckyWheelNumber){
		case 0:
			pDrawBarForm(160, 100, 70, 57, 0, 0);
		break;
		case 1:
			pDrawBarForm(230, 100, 70, 57, 0, 0);
		break;
		case 2:
			pDrawBarForm(300, 100, 70, 57, 0, 0);
		break;
		case 3:
			pDrawBarForm(370, 100, 70, 57, 0, 0);
		break;
		case 4:
			pDrawBarForm(370, 157, 70, 57, 0, 0);
		break;
		case 5:
			pDrawBarForm(370, 214, 70, 57, 0, 0);
		break;
		case 6:
			pDrawBarForm(370, 271, 70, 57, 0, 0);
		break;
		case 7:
			pDrawBarForm(300, 271, 70, 57, 0, 0);
		break;
		case 8:
			pDrawBarForm(230, 271, 70, 57, 0, 0);
		break;
		case 9:
			pDrawBarForm(160, 271, 70, 57, 0, 0);
		break;
		case 10:
			pDrawBarForm(160, 157, 70, 57, 0, 0);
		break;
		case 11:
			pDrawBarForm(160, 214, 70, 57, 0, 0);
		break;
		}
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
	}

	if(this->StartRoll >= 1){
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, 0.3);
		int roll = rand() % 12;
		switch (roll){
		case 0:
			pDrawBarForm(160, 100, 70, 57, 0, 0);
		break;
		case 1:
			pDrawBarForm(230, 100, 70, 57, 0, 0);
		break;
		case 2:
			pDrawBarForm(300, 100, 70, 57, 0, 0);
		break;
		case 3:
			pDrawBarForm(370, 100, 70, 57, 0, 0);
		break;
		case 4:
			pDrawBarForm(370, 157, 70, 57, 0, 0);
		break;
		case 5:
			pDrawBarForm(370, 214, 70, 57, 0, 0);
		break;
		case 6:
			pDrawBarForm(370, 271, 70, 57, 0, 0);
		break;
		case 7:
			pDrawBarForm(300, 271, 70, 57, 0, 0);
		break;
		case 8:
			pDrawBarForm(230, 271, 70, 57, 0, 0);
		break;
		case 9:
			pDrawBarForm(160, 271, 70, 57, 0, 0);
		break;
		case 10:
			pDrawBarForm(160, 157, 70, 57, 0, 0);
		break;
		case 11:
			pDrawBarForm(160, 214, 70, 57, 0, 0);
		break;
		}
		pGLSwitchBlend();
		glColor3f(1.0, 1.0, 1.0);
	}
	gInterface.DrawItem2(163,100,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[0].ItemType,gLuckyWheel.m_LuckyWheelInfo[0].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[0].Level),gLuckyWheel.m_LuckyWheelInfo[0].Exc,0,0);
	gInterface.DrawItem2(237,100,65,47,ITEM(gLuckyWheel.m_LuckyWheelInfo[1].ItemType,gLuckyWheel.m_LuckyWheelInfo[1].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[1].Level),gLuckyWheel.m_LuckyWheelInfo[1].Exc,0,0);
	gInterface.DrawItem2(307,100,65,47,ITEM(gLuckyWheel.m_LuckyWheelInfo[2].ItemType,gLuckyWheel.m_LuckyWheelInfo[2].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[2].Level),gLuckyWheel.m_LuckyWheelInfo[2].Exc,0,0);
	gInterface.DrawItem2(377,100,65,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[3].ItemType,gLuckyWheel.m_LuckyWheelInfo[3].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[3].Level),gLuckyWheel.m_LuckyWheelInfo[3].Exc,0,0);
	gInterface.DrawItem2(377,157,65,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[4].ItemType,gLuckyWheel.m_LuckyWheelInfo[4].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[4].Level),gLuckyWheel.m_LuckyWheelInfo[4].Exc,0,0);
	gInterface.DrawItem2(377,214,63,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[5].ItemType,gLuckyWheel.m_LuckyWheelInfo[5].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[5].Level),gLuckyWheel.m_LuckyWheelInfo[5].Exc,0,0);
	gInterface.DrawItem2(377,271,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[6].ItemType,gLuckyWheel.m_LuckyWheelInfo[6].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[6].Level),gLuckyWheel.m_LuckyWheelInfo[6].Exc,0,0);
	gInterface.DrawItem2(307,271,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[7].ItemType,gLuckyWheel.m_LuckyWheelInfo[7].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[7].Level),gLuckyWheel.m_LuckyWheelInfo[7].Exc,0,0);
	gInterface.DrawItem2(237,271,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[8].ItemType,gLuckyWheel.m_LuckyWheelInfo[8].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[8].Level),gLuckyWheel.m_LuckyWheelInfo[8].Exc,0,0);
	gInterface.DrawItem2(167,271,70,45,ITEM(gLuckyWheel.m_LuckyWheelInfo[9].ItemType,gLuckyWheel.m_LuckyWheelInfo[9].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[9].Level),gLuckyWheel.m_LuckyWheelInfo[9].Exc,0,0);
	gInterface.DrawItem2(167,157,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[10].ItemType,gLuckyWheel.m_LuckyWheelInfo[10].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[10].Level),gLuckyWheel.m_LuckyWheelInfo[10].Exc,0,0);
	gInterface.DrawItem2(167,214,70,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[11].ItemType,gLuckyWheel.m_LuckyWheelInfo[11].ItemIndex),SET_ITEMOPT_LEVEL(gLuckyWheel.m_LuckyWheelInfo[11].Level),gLuckyWheel.m_LuckyWheelInfo[11].Exc,0,0);
	if(this->LuckyWheelNumber >= 0){
	    gInterface.DrawItem2(275,170,50,50,ITEM(gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].ItemType,gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].ItemIndex),gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].Level,gLuckyWheel.m_LuckyWheelInfo[this->LuckyWheelNumber].Exc,0,0);
	}
	pSetCursorFocus = true;
	gInterface.DrawGUI(eLuckyWheelStart,260,230.5f);
	gInterface.DrawFormat(eGold, 285, 75, 25, 5, "Lucky Wheel");
	gInterface.DrawFormat(eWhite, 299, 234, 50.0f, 1.0f, "Start");
    gInterface.DrawGUI(eCloseLuckyWheelKG, 418, 65);
    if (gInterface.IsWorkZone(eCloseLuckyWheelKG))
	{
    	DWORD Color = eGray100;
    	if (gInterface.Data[eCloseLuckyWheelKG].OnClick)
		{
    		Color = eGray150;
    	}
    	gInterface.DrawColoredGUI(eCloseLuckyWheelKG, 418, 65, Color);
    	gInterface.DrawToolTip(418, 65, "Close");
    }
    if( gInterface.IsWorkZone(eLuckyWheelStart) )
	{
    	DWORD Color = eGray100;
    	if( gInterface.Data[eLuckyWheelStart].OnClick )
		{
    		Color = eGray150;
    	}
    	gInterface.DrawColoredGUI(eLuckyWheelStart, gInterface.Data[eLuckyWheelStart].X, gInterface.Data[eLuckyWheelStart].Y, Color);
    }
}

void CLuckyWheel::EventLuckyWheel_Main(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if( !gInterface.Data[eLuckyWheelMain].OnShow ){
		return;
	}
	if (gInterface.IsWorkZone(eLuckyWheelStart))
	{
		DWORD Delay = (CurrentTick - gInterface.Data[eLuckyWheelStart].EventTick);
		if (Event == WM_LBUTTONDOWN){
			gInterface.Data[eLuckyWheelStart].OnClick = true;
			pSetCursorFocus = true;
			return;
		}
		gInterface.Data[eLuckyWheelStart].OnClick = false;
		pSetCursorFocus = false;
		if (Delay < 10000)
		{
			return;
		}
		gInterface.Data[eLuckyWheelStart].EventTick = GetTickCount();
		UP_TUCHAN_REQ pMsg;
		pMsg.h.set(0xFB, 0x16, sizeof(pMsg));
		DataSend((BYTE*)&pMsg, pMsg.h.size);
		StartRoll = 1;
	}
}