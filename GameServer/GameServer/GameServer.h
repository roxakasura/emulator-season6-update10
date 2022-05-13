#pragma once
#include "IpManager.h"

#define MAX_LOADSTRING 100

#define WM_TIMER_1000 100
#define WM_TIMER_2000 101
#define WM_TIMER_10000 102

#define WM_JOIN_SERVER_MSG_PROC (WM_USER+1)
#define WM_DATA_SERVER_MSG_PROC (WM_USER+2)

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE hInstance,int nCmdShow);
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK About(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK UserOnline(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK IPBanned(HWND hDlg,UINT message,WPARAM wParam,LPARAM lParam);

std::map<std::string,IP_ADDRESS_INFO>::iterator it;
std::map<std::string,IP_ADDRESS_INFO>::iterator buscador;

HWND hWndComboBox;