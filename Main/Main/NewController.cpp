#include "stdafx.h"
#include "NewController.h"
#include "Minimize.h"
#include "Util.h"
#include "TMemory.h"

HHOOK           m_Keyboard1 = NULL;
HHOOK           m_Keyboard2 = NULL;
HWND            Window = NULL;
int JanelaTeste;

LRESULT CALLBACK KeyboardProc(int Code, WPARAM wParam, LPARAM lParam)
{
	if (((lParam >> 31) & 1) && (Code == HC_ACTION))
	{
#if(MAIN_UPDATE>9)
			switch(wParam)
			{
			case VK_F9:
					if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
					{
						if (JanelaTeste == 1)
						{
							MemorySet(0x0080F833,0x90,0x5);
							MemorySet(0x0080F845,0x90,0x5);
							MemorySet(0x0080F84D,0x90,0x5);
							MemorySet(0x0080F855,0x90,0x5);
							MemorySet(0x0080F85D,0x90,0x5);
							MemorySet(0x0080F865,0x90,0x5);
							MemorySet(0x0080EDC9,0x90,0x5);
							SetDword(0x0080F928+1,31461);
							SetDword(0x0080F963+1,31461);
							SetDword(0x0080F99E+1,31461);
							SetDword(0x0080F9FD+1,31461);
							SetByte(0x00813C00, 0xC3); //T/o/o/l/T/i/p S/k/i/l/l/s
							pCloseWindow(pWindowThis(),55); //P/e/t/L/i/f/e/D/i/s/p/l/a/y
							pCloseWindow(pWindowThis(),56); //B/u/f/f/L/i/s/t
							pCloseWindow(pWindowThis(),41); //C/h/a/t/M/e/s/s/a/g/e/s
							MemorySet(0x00664142,0x90,5);
							SetDword(0x004D9746+3,480);
							JanelaTeste = 0;
						}
						else
						{
							SetCompleteHook(0xE8,0x0080F833,0x813740);
							SetCompleteHook(0xE8,0x0080F845,0x80FA10);
							SetCompleteHook(0xE8,0x0080F84D,0x810420);
							SetCompleteHook(0xE8,0x0080F855,0x810150);
							SetCompleteHook(0xE8,0x0080F85D,0x8118C0);
							SetCompleteHook(0xE8,0x0080F865,0x810700);
							SetCompleteHook(0xE8,0x0080EDC9,0x895970);
							SetCompleteHook(0xE8,0x00664142,0x6403B0);
							SetDword(0x0080F928+1,31292);
							SetDword(0x0080F963+1,31293);
							SetDword(0x0080F99E+1,31294);
							SetDword(0x0080F9FD+1,31295);
							SetByte(0x00813C00, 0x55); //T/o/o/l/T/i/p S/k/i/l/l/s
							pOpenWindow(pWindowThis(),55); //P/e/t/L/i/f/e/D/i/s/p/l/a/y
							pOpenWindow(pWindowThis(),56); //B/u/f/f/L/i/s/t
							pOpenWindow(pWindowThis(),41); //C/h/a/t/M/e/s/s/a/g/e/s
							SetDword(0x004D9746+3,432);
							JanelaTeste = 1;
						}
					}
					break;
				default:
					break;
			}
#endif

		if (GetAsyncKeyState(VK_F12))
		{
			gTrayMode.Toggle();
		}

	}

	return CallNextHookEx(m_Keyboard1, Code, wParam, lParam);
}

LRESULT CALLBACK LL_KeyboardProc(int Code, WPARAM wParam, LPARAM lParam)
{
	KBDLLHOOKSTRUCT* KeyBoard = (KBDLLHOOKSTRUCT*)lParam;

	switch (wParam)
	{
	case WM_KEYUP:
	{
		switch (KeyBoard->vkCode)
		{
		case VK_F12:
		{
			gTrayMode.Toggle();
		}
		break;
		}
	}
	break;
	default:
		return CallNextHookEx(NULL, Code, wParam, lParam);
		break;
	}

	return CallNextHookEx(m_Keyboard2, Code, wParam, lParam);
}