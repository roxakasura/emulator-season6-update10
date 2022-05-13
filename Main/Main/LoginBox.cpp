#include "stdafx.h"
#include "LoginBox.h"
#include "Util.h"
#include "Interface.h"
#include "Object.h"
#include "Offset.h"
#include "Defines.h"
#include "NewFont.h"

int AutomaticLogin;

cAutoLogin AutoLogin;


cAutoLogin::cAutoLogin()
{
}

cAutoLogin::~cAutoLogin()
{
}

float getX(float x) 
{
	return x / g_fScreenRate_x;
}
float getY(float y) 
{
	float fixResu = ((float)pWinWidth) / (((float)pWinHeight)*(640.0f / 480.0f)); //fix custom res
	return y / g_fScreenRate_x * fixResu;
}

bool IsCursorInZone(short x, short y, short x2, short y2)
{
	return pCursorX >= x && pCursorX <= x + x2 && pCursorY >= y && pCursorY <= y + y2;
}

bool WriteString(const std::string& name, const std::string& value) {
	HKEY	hKey = NULL;
	DWORD	dwDisp;
	DWORD	dwSize = value.size();

	if (ERROR_SUCCESS != RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
		return false;

	RegSetValueEx(hKey, name.c_str(), 0L, REG_SZ, (CONST BYTE*)value.c_str(), dwSize);
	RegCloseKey(hKey);
	return true;
}

bool WriteDword(const std::string& name, DWORD value) {
	HKEY	hKey = NULL;
	DWORD	dwDisp;
	DWORD	dwSize = sizeof(DWORD);

	if (ERROR_SUCCESS != RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
		return false;

	RegSetValueEx(hKey, name.c_str(), 0L, REG_DWORD, (BYTE*)&value, dwSize);
	RegCloseKey(hKey);
	return true;
}

void DoRequestLogin()
{
	int Struct = _Instance() + 16968;

	InputBox_GetText(*(DWORD *)(Struct + 848), AutoLogin.iUser, 11);
	InputBox_GetText(*(DWORD *)(Struct + 852), AutoLogin.iPassword, 11);
	if (AutoLogin.savePass) 
	{
		WriteString("ID", AutoLogin.iUser);
		WriteString("PW", AutoLogin.iPassword);
		WriteDword("SavePass", 1);
	}
	else 
	{
		WriteDword("SavePass", 0);
	}
	//do it
	RequestLogin(_Instance() + 16968);
}

void CButtonAutoLogin(int This, int a2)
{
	CUIRenderText_SetFont((int)pTextThis(), *(int*)0xE8C594);

	AutomaticLogin = GetPrivateProfileIntA("LoginConfig", "AutoLogin", 0, "./Settings.ini");

	float startX = (640.0 - getX(329)) / 2,
	startY = (480.0 - getY(245)) * 2.0 / 3.0;

	int Struct = _Instance() + 16968;

	if (IsCursorInZone(startX + getX(246.0), startY + getY(156), 15, 15)) 
	{
		if (pIsKeyRelease(VK_LBUTTON))
		{
			RenderBitmap(0x7B69, startX + getX(246.0), startY + getY(156), 15 / g_fScreenRate_x, 15 / g_fScreenRate_y, 0.01, 0.02999999747, 0.5799999952, 0.3700000346, 1, 1, 0);
			AutoLogin.savePass = !AutoLogin.savePass;
			PlayBuffer(25, 0, 0);
		}
	}

	if (AutoLogin.savePass) 
	{
		RenderBitmap(0x7B69, startX + getX(246.0), startY + getY(156), 15 / g_fScreenRate_x, 15 / g_fScreenRate_y, 0.01, 0.02999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	else 
	{
		RenderBitmap(0x7B69, startX + getX(246.0), startY + getY(156), 15 / g_fScreenRate_x, 15 / g_fScreenRate_y, 0.01, 0.49999999747, 0.8799999952, 0.3700000346, 1, 1, 0);
	}
	if(AutoLogin.savePass && AutomaticLogin == 1)
	{
		RequestLogin(Struct);
	}
}

void DoLoginWinCreate(int)
{
	int Struct = _Instance() + 16968;
	LoginWinCreate(Struct);
	if (AutoLogin.savePass) 
	{
		InputBox_SetText(*(DWORD *)(Struct + 848), AutoLogin.iUser);
		InputBox_SetText(*(DWORD *)(Struct + 852), AutoLogin.iPassword);
	}
}

void TextLogin(int X, int Y, LPCTSTR Text)
{
	float startX = (640.0 - getX(329)) / 2,
	startY = (480.0 - getY(245)) * 2.0 / 3.0;

	pDrawText(pTextThis(), X, Y, Text, 0, 0, (PINT)1, 0);
	pDrawText(pTextThis(), startX + getX(124), startY + getY(158), "Save password", getX(120), 0, (PINT)4, 0);
}

void cAutoLogin::Load()
{
	//read data
	HKEY hKey;
	DWORD dwDisp;
	DWORD dwSize;
	if (ERROR_SUCCESS == RegCreateKeyEx(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, &dwDisp))
	{
		dwSize = 11;
		if (RegQueryValueEx(hKey, "ID", 0, NULL, (LPBYTE)AutoLogin.iUser, &dwSize) != ERROR_SUCCESS)
		{
			ZeroMemory(AutoLogin.iUser, sizeof(AutoLogin.iUser));
		}
		dwSize = 11;
		if (RegQueryValueEx(hKey, "PW", 0, NULL, (LPBYTE)AutoLogin.iPassword, &dwSize) != ERROR_SUCCESS)
		{
			ZeroMemory(AutoLogin.iPassword, sizeof(AutoLogin.iPassword));
		}
		dwSize = sizeof (int);
		if (RegQueryValueEx(hKey, "SavePass", 0, NULL, (LPBYTE)&AutoLogin.savePass, &dwSize) != ERROR_SUCCESS)
		{
			AutoLogin.savePass = false;
		}
	}
	
	//end

	SetCompleteHook(0xE8, 0x0040B635, &TextLogin);
	SetCompleteHook(0xE8, 0x0040B5A9, &CButtonAutoLogin);
	SetCompleteHook(0xE8, 0x0040B400, &DoRequestLogin);
	SetCompleteHook(0xE8, 0x0040B44F, &DoRequestLogin);
	SetCompleteHook(0xE8, 0x00483711, &DoLoginWinCreate);
}	

//#include "stdafx.h"
//#include "LoginBox.h"
//#include "Import.h"
//#include "Defines.h"
//#include "Object.h"
//#include "Offset.h"
//#include "Util.h"
//#include "TMemory.h"
//#include "Inter803.h"
//#include "Main.h"
//#include "Season0.h"
//#include "Addons.h"
//
//CLoginWin gCLoginWin;
//
//signed int sub_9CEBF022(double a1)
//{
//	return (signed int)a1;
//}
//
//void __fastcall LoadNewBoxLogin(signed int a2)
//{
//	TextPositionLoginBox(a2);
//	RenderBitmap(531020, 195.0, 100, 250.0, 216.0, 0, 0, 0.9765625, 0.84375, 1, 1, 0);
//}
//
//
//float CLoginWin_x, CLoginWin_y;
//
//void CLoginWin::cSetPosition(BYTE* This, int nXCoord, int nYCoord, int eChangedPram)
//{
//	CLoginWin_x = nXCoord;
//	CLoginWin_y = nYCoord;
//	Sprite_SetPosition(This, nXCoord, nYCoord, eChangedPram);
//}
//
//char iUser[32], iPassword[32];
//void CButtonAutoLogin(int This, int a2)
//{
//	CUIRenderText_SetFont((int)pTextThis(), *(int*)0xE8C594);
//
//	GetPrivateProfileString("AutoLogin", "User", "", iUser, 32, ".\\Settings.ini");
//	GetPrivateProfileString("AutoLogin", "Password", "", iPassword, 32, ".\\Settings.ini");
//
//	int Struct = GetInstance() + 16968;
//	float v = 0.0, vHeight = 0.235;
//
//	v = vHeight;
//	v = vHeight + vHeight;
//	PlayBuffer(25, 0, 0);
//	InputBox_SetText(*(DWORD*)(Struct + 848), iUser);
//	InputBox_SetText(*(DWORD*)(Struct + 852), iPassword);
//	RequestLogin(Struct);
//}
//
//void LoadBoxLogin()
//{
//	//SetCompleteHook(0xE8, 0x0040B306, &CLoginWin::cSetPosition);
//	//SetCompleteHook(0xE8, 0x0040B5A9, &CButtonAutoLogin);
//	//SetDword(0x0040AD90+1,531020);
//}