#include "stdafx.h"
#include "Interface.h"
#include "ServerSwitch.h"
#include "Item.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Defines.h"
#include "ConnectServer.h"
#include "SwitchServer.h"
#include "NewFont.h"
#include "NewInterface.h"
#include "CustomWindow.h"
#include "CMacroUIEx.h"
#include "CustomMessage.h"
#include "Protect.h"

cServerSwitch gServerSwitch;

cServerSwitch::cServerSwitch()
{
	this->Init();
}

cServerSwitch::~cServerSwitch()
{
}

void cServerSwitch::Init()
{
	this->Click = false;
}

void cServerSwitch::Load()
{

}

void cServerSwitch::BindImage()
{	
	// ServerSwitch
	gInterface.BindObject(eADDPOINT2_MAIN, 0x7A5A, 222, 333, -1, -1);
	gInterface.BindObject(eADDPOINT2_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eADDPOINT2_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eADDPOINT2_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eADDPOINT2_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eADDPOINT2_CLOSE, 0x7EC5, 36, 29, -1, -1);
	// EventTime
	gInterface.BindObject(eADDPOINT3_MAIN, 0x7A5A, 222, 225, -1, -1);
	gInterface.BindObject(eADDPOINT3_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eADDPOINT3_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eADDPOINT3_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eADDPOINT3_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eADDPOINT3_CLOSE, 0x7EC5, 36, 29, -1, -1);
	// RankingUser
	gInterface.BindObject(eADDPOINT4_MAIN, 0x7A5A, 222, 225, -1, -1);
	gInterface.BindObject(eADDPOINT4_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eADDPOINT4_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eADDPOINT4_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eADDPOINT4_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eADDPOINT4_CLOSE, 0x7EC5, 36, 29, -1, -1);
	// MenuCustom
	if (gProtect.m_MainInfo.CustomInterfaceType <= 2)
	{
		gInterface.BindObject(eADDPOINT5_MAIN, 0x7A5A, 222, 240, -1, -1);
		gInterface.BindObject(eADDPOINT5_TITLE, 0x7A63, 230, 67, -1, -1);
		gInterface.BindObject(eADDPOINT5_FRAME, 0x7A58, 230, 15, -1, -1);
		gInterface.BindObject(eADDPOINT5_FOOTER, 0x7A59, 230, 50, -1, -1);
		gInterface.BindObject(eADDPOINT5_DIV, 0x7A62, 223, 21, -1, -1);
		gInterface.BindObject(eADDPOINT5_CLOSE, 0x7EC5, 36, 29, -1, -1);
	}
	gInterface.BindObject(eADDPOINT6_MAIN, 0x7A5A, 222, 225, -1, -1);
	gInterface.BindObject(eADDPOINT6_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eADDPOINT6_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eADDPOINT6_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eADDPOINT6_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eADDPOINT6_CLOSE, 0x7EC5, 36, 29, -1, -1);
}

void cServerSwitch::Draw()
{
	if (!gInterface.Data[eADDPOINT2_MAIN].OnShow)
	{
		return;
	}

	pSetCursorFocus = true;

	float MainWidth, MainHeight;
	MainWidth = 230.0;
	MainHeight = 283.0;
	float StartBody = 30.0;
	float StartY = 30.0;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter = StartX + (MainWidth / 3);
	float ButtonX = MainCenter - (float)(29.0 / 2);

	gInterface.DrawGUI(eADDPOINT2_MAIN, StartX, StartY + (float)2.0);
	gInterface.DrawGUI(eADDPOINT2_TITLE, StartX, StartY);
	gInterface.DrawFormat(eGold, (int)StartX + 9, (int)StartBody + 10, 210, 3, "Select Server Painel");
	StartY = gInterface.DrawRepeatGUI(eADDPOINT2_FRAME, StartX, StartY + (float)40.0, 17);
	gInterface.DrawGUI(eADDPOINT2_FOOTER, StartX, StartY);
	gInterface.DrawGUI(eADDPOINT2_CLOSE, StartX + MainWidth - gInterface.Data[eVip_CLOSE].Width, StartBody);

	if (gInterface.IsWorkZone(eADDPOINT2_CLOSE)) 
	{
		DWORD Color = eGray100;

		if (gInterface.Data[eADDPOINT2_CLOSE].OnClick) 
		{
			Color = eGray150;
		}

		gInterface.DrawColoredGUI(eADDPOINT2_CLOSE, gInterface.Data[eADDPOINT2_CLOSE].X, StartBody, Color);
		gInterface.DrawToolTip((int)gInterface.Data[eADDPOINT2_CLOSE].X + 5, StartBody + 25, "Close");
	}

	char Cord[256];
	float X = 259;
	float Y = 140;

	if (CustomSwitchServerUpgrade == 1) {
		ConnectServer.currently_subcode = *(DWORD*)0x0986C128;
		if (nInterface.Drawbutton(gCMacroUIEx.macroSwitchServer, " "))
		{
			if (gCMacroUIEx.macroSwitchServer->data->state == 1) {
				ConnectServer.ReqServerList(true);
			}
		}
		if (ConnectServer.currently_subcode) {
			if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 0)
				pSetTextColor(pTextThis(), 240, 50, 50, 255);
			else if (ConnectServer.SrvStat[ConnectServer.currently_subcode - 1].type == 1)
				pSetTextColor(pTextThis(), 50, 240, 50, 255);
			else
				pSetTextColor(pTextThis(), 160, 160, 160, 255);
			wsprintf(Cord, gCustomMessage.GetMessage(71), ConnectServer.currently_subcode);
			pDrawText(pTextThis(), X + 17.5, Y + 3, Cord, 30, 0, (LPINT)0, 0);
		}
		if (gCMacroUIEx.macroSwitchServer->data->state == 1) {
			ConnectServer.ReqServerList(false);
			//nInterface.DrawFrame(0xF3001, X + 7.5 , Y + 21.5, 198, 226, 1, 3, 1024, 256, 1.5 / pWinWidthReal, 1.5 / pWinHeightReal);
			if (nInterface.IsWorkZone(X + 7.5, Y + 21.5, 198 / 1.5, 226 / 1.5)) {
				gCMacroUIEx.macroSwitchServerHoving = true;
			}
			else {
				gCMacroUIEx.macroSwitchServerHoving = false;
			}
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pSetTextColor(pTextThis(), 160, 160, 160, 255);
			bool showToolTip = false;
			for (char i = 0; i < ConnectServer.server_list_count; i++) {
				if (ConnectServer.currently_subcode - 1 != i) {
					if (nInterface.Drawbutton(gCMacroUIEx.macroSwitchServerHover, X + 11, Y + 21.5 + 14.65 * i, "")) {
						if (!gCMacroUIEx.isSwitchServer && gCMacroUIEx.lastSwitch + DelaySwitchServer < GetTickCount()) {
							SwitchServer.switchServer(ConnectServer.SrvStat[i].ServerCode);
							*(DWORD*)0x0986C128 = ConnectServer.SrvStat[i].ServerCode + 1;
							gCMacroUIEx.lastSwitch = GetTickCount();
							gCMacroUIEx.macroSwitchServer->data->state = 0;
						}
					}
				}
				else {
					if (nInterface.IsWorkZone(X + 11, Y + 21.5 + 14.65 * i, 110, 14)) {
						showToolTip = true;
					}
				}
				pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
				if (ConnectServer.SrvStat[i].type == 0)
					pSetTextColor(pTextThis(), 240, 50, 50, 255);
				else if (ConnectServer.SrvStat[i].type == 1)
					pSetTextColor(pTextThis(), 50, 240, 50, 255);
				else
					pSetTextColor(pTextThis(), 255, 255, 0, 255);
				wsprintf(Cord, gCustomMessage.GetMessage(71), ConnectServer.SrvStat[i].ServerCode + 1);
				pDrawText(pTextThis(), X + 17.5, Y + 23.5 + 14.65 * i, Cord, 30, 0, (LPINT)0, 0);
				pSetTextColor(pTextThis(), 255, 255, 0, 255);
				//new
				char* ServerTypeName[] = { "[Gold]","[Gold(PvP)]", "[NoN-PvP]", "[Normal]", "[Unknow]" };
				if (ConnectServer.SrvStat[i].ServerCode >= 0 && ConnectServer.SrvStat[i].ServerCode <= 3) {
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[0], 30, 0, (LPINT)0, 0);
				}
				else if (ConnectServer.SrvStat[i].ServerCode == 4) {
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[1], 30, 0, (LPINT)0, 0);
				}
				else if (ConnectServer.SrvStat[i].ServerCode >= 5 && ConnectServer.SrvStat[i].ServerCode <= 8) {
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[2], 30, 0, (LPINT)0, 0);
				}
				else if (ConnectServer.SrvStat[i].ServerCode >= 9 && ConnectServer.SrvStat[i].ServerCode <= 20) {
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[3], 30, 0, (LPINT)0, 0);
				}
				else {
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[4], 30, 0, (LPINT)0, 0);
				}
				/*
				if (ConnectServer.SrvStat[i].type < 3)
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, ServerTypeName[ConnectServer.SrvStat[i].type], 30, 0, (LPINT)0, 0);
				else
					pDrawText(pTextThis(), X + 50, Y + 23.5 + 14.65 * i, "[Unknow]", 30, 0, (LPINT)0, 0);
				*/
				if (ConnectServer.SrvStat[i].UserTotal < 100) {
					pSetTextColor(pTextThis(), 50, 240, 50, 255);
					wsprintf(Cord, "%d%%", ConnectServer.SrvStat[i].UserTotal);
				}
				else {
					pSetTextColor(pTextThis(), 240, 50, 50, 255);
					wsprintf(Cord, gCustomMessage.GetMessage(70));
				}
				pDrawText(pTextThis(), X + 102.5, Y + 23.5 + 14.65 * i, Cord, 30, 4, (LPINT)0, 0);
			}
			//nInterface.Drawbutton(gCMacroUIEx.macroSwitchServerSliderUp, "");
			//nInterface.Drawbutton(gCMacroUIEx.macroSwitchServerSliderDown, "");
			if (showToolTip) {
				textSize tS = nInterface.getTextSize(gCustomMessage.GetMessage(69));
				nInterface.DrawToolTipBG(pCursorX + 25, pCursorY, tS.resize_width + 10, tS.resize_height + 4);
				pSetTextColor(pTextThis(), 160, 160, 160, 255);

				pDrawText(pTextThis(), pCursorX + 25, pCursorY + 4, gCustomMessage.GetMessage(69), tS.resize_width + 10, 0, (LPINT)3, 0);
			}
		}
	}
}
