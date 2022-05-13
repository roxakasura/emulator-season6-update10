#pragma once

#define pCloseWindow			((int(__thiscall*)(LPVOID This, int Code)) 0x0085F9A0)
#define MAIN_WINDOW					0x00E8C578
#define pWindowThis				((LPVOID(*)()) 0x861110)
#define pOpenWindow				((int(__thiscall*)(LPVOID This, int Code)) 0x0085EC50)

LRESULT CALLBACK KeyboardProc(int Code, WPARAM wParam, LPARAM lParam);
LRESULT CALLBACK LL_KeyboardProc(int Code, WPARAM wParam, LPARAM lParam);

extern HWND         Window;
extern HHOOK        m_Keyboard1;
extern HHOOK        m_Keyboard2;