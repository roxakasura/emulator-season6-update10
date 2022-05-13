// TrayMode.cpp: implementation of the CTrayMode class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <ShellAPI.h>
#include "Minimize.h"
#include "NewController.h"
#include "Protect.h"
#include "PrintPlayer.h"
#include "User.h"
#include "resource.h"

CTrayMode gTrayMode;


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTrayMode::CTrayMode() // OK
{
}

void CTrayMode::Init(HINSTANCE hins) // OK
{
	this->m_TrayIcon = (HICON)LoadImage(hins, MAKEINTRESOURCE(IDI_ICON2), IMAGE_ICON, GetSystemMetrics(SM_CXSMICON), GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);

	this->m_MainWndProc = 0;
}

void CTrayMode::Toggle() // OK
{
	Window = FindWindow(gProtect.m_MainInfo.WindowName, NULL);

	if (this->GetMainWndProc() != 0)
	{
		if (IsWindowVisible(Window) == 0)
		{
			ShowWindow(Window, SW_SHOW);

			this->ShowNotify(0);
		}
		else
		{
			ShowWindow(Window, SW_HIDE);

			this->ShowNotify(1);
		}
	}
}

LONG CTrayMode::GetMainWndProc() // OK
{
	Window = FindWindow(gProtect.m_MainInfo.WindowName, NULL);

	return ((this->m_MainWndProc == 0) ? ((LONG)(this->m_MainWndProc = (WNDPROC)SetWindowLong(Window, GWL_WNDPROC, (LONG)CTrayMode::TrayModeWndProc))) : ((LONG)this->m_MainWndProc));
}

void CTrayMode::ShowNotify(bool mode) // OK
{
	Window = FindWindow(gProtect.m_MainInfo.WindowName, NULL);

	NOTIFYICONDATA nid;

	memset(&nid, 0, sizeof(nid));

	nid.cbSize = sizeof(NOTIFYICONDATA);

	nid.hWnd = Window;

	nid.uID = WM_TRAY_MODE_ICON;

	nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;

	nid.uCallbackMessage = WM_TRAY_MODE_MESSAGE;

	nid.hIcon = this->m_TrayIcon;

	if (*(DWORD*)(MAIN_SCREEN_STATE) == 5)
	{
		wsprintf(nid.szTip, "Char: (%s)\nResets: (%d)\nLevel: (%d)", (char*)(*(DWORD*)(MAIN_CHARACTER_STRUCT)+0x00), ViewReset,gObjUser.lpPlayer->Level);
	}
	else
	{
		wsprintf(nid.szTip, "MuOnline");
	}

	Shell_NotifyIcon(((mode == 0) ? NIM_DELETE : NIM_ADD), &nid);
}

LRESULT CALLBACK CTrayMode::TrayModeWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) // OK
{
	switch (message)
	{
	case WM_TRAY_MODE_MESSAGE:
		switch (lParam)
		{
		case WM_LBUTTONDBLCLK:
			gTrayMode.Toggle();
			break;
		default:
			break;
		}
	default:
		break;
	}

	return CallWindowProc((WNDPROC)gTrayMode.GetMainWndProc(), hWnd, message, wParam, lParam);
}
