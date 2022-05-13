#include "stdafx.h"
#include "WindowsD.h"
#include "Defines.h"
#include "TMemory.h"
#include "User.h"
#include "Offset.h"
#include "Import.h"
#include "Util.h"
#include "Protect.h"
#include "PrintPlayer.h"
#include "Object.h"
#include "Interface.h"
#include "CustomInterface.h"
#include "OffTrade.h"

cOptionsWindow gOptionsWindow;

int checkbox = 0;
int checkclick = 0;
int Y = 0;

void cOptionsWindow::Load()
{
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 60 && pCursorY < 88 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 1; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 90 && pCursorY < 118 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 2; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 120 && pCursorY < 148 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 3; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 150 && pCursorY < 178 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 4; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 180 && pCursorY < 208 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 5; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 210 && pCursorY < 238 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 6; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 240 && pCursorY < 268 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 7; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 270 && pCursorY < 298 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 8; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 300 && pCursorY < 328 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 9; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 330 && pCursorY < 358 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 10; }
	if (pCursorX > 498 && pCursorX < 605 && pCursorY > 360 && pCursorY < 388 && (GetKeyState(VK_LBUTTON) & 0x100) != 0)
	{ checkclick = 11; }

	if (gInterface.CheckWindow(10))
	{
		checkbox = 1;
	}
	else
	{
		checkbox = 0;
		checkclick = 0;
	}
	
	if (checkbox == 1)
		{
			gInterface.DrawGUI(eCheckBoxCommand, 478, 68);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 98);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 128);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 158);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 188);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 218);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 248);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 278);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 308);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 338);
			gInterface.DrawGUI(eCheckBoxCommand, 478, 368);
		}

	if (checkclick == 1)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 71); }
	if (checkclick == 2)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 101); }
	if (checkclick == 3)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 131); }
	if (checkclick == 4)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 161); }
	if (checkclick == 5)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 191); }
	if (checkclick == 6)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 221); }
	if (checkclick == 7)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 251); }
	if (checkclick == 8)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 281); }
	if (checkclick == 9)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 311); }
	if (checkclick == 10)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 341); }
	if (checkclick == 11)
	{ gInterface.DrawGUI(eWhinCkeck, 481, 371); }
}