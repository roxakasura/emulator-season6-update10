#include "stdafx.h"
#include "Controller.h"
#include "Camera\CameraSystem.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "CustomJewelBank.h"
#include "CustomLuckyWheel.h"
#include "CustomNewButtonD.h"
#include "Defines.h"
#include "CustomInterface.h"
#include "OffTrade.h"
#include "Protocol.h"
#include "Protect.h"
#include "Import.h"
#include "Interface.h"
#include "CMacroUIEx.h"
#include "NewInterface.h"
#include "CSCharacterS13.h"
#include "MultiCharacter.h"
#include "SceneControl.h"
#include "ExpandedCharacters.h"
#include "BankUpgrade.h"
#include "StoreSearch.h"
#include "OffMuHelper.h"
#include "Antilag.h"
#include "BuyVip.h"
#include "MenuCustom.h"
// ----------------------------------------------------------------------------------------------

Controller	gController;
// ----------------------------------------------------------------------------------------------

bool Controller::Load()
{
	if( !this->MouseHook )
	{
		this->MouseHook = SetWindowsHookEx(WH_MOUSE, this->Mouse, gController.Instance, GetCurrentThreadId());
		// ----
		if( !this->MouseHook )
		{
			return false;
		}
	}
	// ----
	if( !this->KeyboardHook )
	{
		//this->KeyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, this->Keyboard, NULL, NULL);
		//// ----
		//if( !this->KeyboardHook )
		//{
		//	return false;
		//}
	}
	// ----
	return true;
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Mouse(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
	}
	// ----
	MOUSEHOOKSTRUCTEX * Mouse	= (MOUSEHOOKSTRUCTEX*)lParam;
	// ----
	// ----
	switch(wParam)
	{
	case WM_MOUSEMOVE:
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.Move(Mouse);
		}
		break;
	case WM_MBUTTONDOWN:
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.SetIsMove(1);
			gCamera.SetCursorX(Mouse->pt.x);
			gCamera.SetCursorY(Mouse->pt.y);
		}
		break;
	case WM_MBUTTONUP:
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.SetIsMove(0);
		}
		break;
	case WM_MOUSEWHEEL:
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.Zoom(Mouse);
		}
		break;
	case WM_LBUTTONUP:
	case WM_LBUTTONDOWN:
		{
			gCustomRanking.EventRankingNext(wParam);
			gCustomRanking.EventRankingBack(wParam);
			gBuyVip.EventVipWindow_Main(wParam);
			gCustomRanking.EventVipWindow_Close(wParam);
			gCustomCommandInfo.EventCommandWindow_Close(wParam);
			gCustomCommandInfo.CommandNext(wParam);
			gCustomCommandInfo.CommandPrev(wParam);
			gCustomEventTime.EventEventTimeWindow_Close(wParam);
			gCustomEventTime.EventNext(wParam); //passa pra proxima pag
			gCustomEventTime.EventPrev(wParam); //volta uma pagina
			gInterface.EventDrawMenu_Open(wParam);
			gInterface.EventDrawMenu_Op1(wParam);
			gInterface.EventDrawMenu_Op2(wParam);
			gInterface.EventDrawMenu_Op3(wParam);
			gInterface.EventDrawMenu_Op4(wParam);
			gInterface.EventDrawMenu_Op20(wParam);
			gInterface.EventConfirm_CANCEL(wParam);
			gInterface.EventConfirm_OK(wParam);
			gOffTrade.EventOffTradeWindow_Main(wParam);
			gOffTrade.EventCloseTradeWindow_Main(wParam);
			gJewelBank.EventJewelWindows_Close(wParam);
			gLuckyWheel.EventLuckyWheel_Main(wParam);
			gLuckyWheel.EventDrawClose_LuckyWheelKG(wParam);				    
			gCMacroUIEx.Button(wParam);
			gMuHelper.EventMuOffhelper(wParam);
			gCustomMenu.EventMenuCustomWindow_Close(wParam);
			g_PersonalShopEx.Button(wParam);

			if(gProtect.m_MainInfo.SelectCharacterSystem == 1)
			{
				JGetPlayer.SelectCharButton(wParam);
			}

			gAntiLagSystem.EventUsersPanelAntiLag(wParam);
			gAntiLagSystem.EventUsersPanelAntiLag_CLOSE(wParam);
			gSelectCharMulti.EventSelectChar(wParam);

			if(gProtect.m_MainInfo.MultiCharacterEnable == 1)
			{
				gSelectCharMulti.EventSelectChar(wParam);
			}

			switch(gProtect.m_MainInfo.CustomInterfaceType)
			{
			case 1:
				gInterface.EventNewInterface97_All(wParam);
				break;
			case 2:
				gInterface.EventNewInterface_All(wParam);
				break;
			case 3:
				gInterface.EventMenuButton(wParam);
				break;
			}
		}
		
		break;
	}
	// ----
	return CallNextHookEx(gController.MouseHook, Code, wParam, lParam);
}
// ----------------------------------------------------------------------------------------------

LRESULT Controller::Keyboard(int Code, WPARAM wParam, LPARAM lParam)
{
	if( GetForegroundWindow() != pGameWindow )
	{
		return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	}

	if (Code < 0) return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
	
	if( (Code == HC_ACTION) && (wParam == WM_KEYDOWN))
	{
		KBDLLHOOKSTRUCT Hook = *((KBDLLHOOKSTRUCT*)lParam);
		nInterface.keyPressed(Hook.vkCode);
		switch(Hook.vkCode)
		{
			// --
	case VK_F8:
		{
			gCustomRanking.OpenWindow();
		}
		break;	

	case VK_F10:
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.Toggle();
		}
		break;

	case VK_F11:
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.Restore();
		}
		break;
		case VK_ESCAPE:
		{

			if (gInterface.Data[eCommand_MAIN].OnShow == true)
			{
				gInterface.Data[eCommand_MAIN].OnShow = false;
				pSetCursorFocus = false;
				return -1;
			}
		}
		break;
		case VK_SNAPSHOT:
		{
			gInterface.Data[eLogo].EventTick = GetTickCount()+1500;
			//gInterface.Data[eLogo].OnShow = true;
			//gInterface.DrawLogo();
			return CallNextHookEx(gController.KeyboardHook, Code, wParam, lParam);
		}
		break;
		default:
		break;
		}
	} 
	return (LRESULT) NULL;
	
}
// ----------------------------------------------------------------------------------------------
