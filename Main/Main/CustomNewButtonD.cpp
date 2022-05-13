#include "stdafx.h"
#include "CustomNewButtonD.h"
#include "CustomJewelBank.h"
#include "Interface.h"
#include "Defines.h"
#include "Protect.h"

CSCustomMenuD gCustomMenuD;

CSCustomMenuD::CSCustomMenuD()
{

}

void CSCustomMenuD::Bind()
{
	    gInterface.BindObject(eButtonDButton, 0x7A5E, 108, 29, -1, -1);
}

void CSCustomMenuD::DrawD()
{
	if (!gInterface.CheckWindow(ObjWindow::CommandWindow))
	{
		return;
	}

	if (gInterface.IsWorkZone(eButtonDButton))
	{
		if (gInterface.Data[eButtonDButton].OnClick)
			gInterface.DrawButton(eButtonDButton, 491, 363, 0, 58);
		else
			gInterface.DrawButton(eButtonDButton, 491, 363, 0, 29);
	}
	else
		gInterface.DrawButton(eButtonDButton, 491, 363, 0, 0);

	gInterface.DrawFormat(eWhite, 493, 373, 108, 3, "Jewel Bank");
}

bool CSCustomMenuD::Button(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eButtonDButton].EventTick);
	if (!gInterface.IsWorkZone(eButtonDButton))
	{
		return false;
	}

	if (Event == WM_LBUTTONDOWN)
	{
		pSetCursorFocus = true;
		gInterface.Data[eButtonDButton].OnClick = true;
		return true;
	}
	gInterface.Data[eButtonDButton].OnClick = false;
	if (Delay < 500){
		return false;
	}
	gInterface.Data[eButtonDButton].EventTick = GetTickCount();

	if (gJewelBank.CheckJewelWindow())
	{
		gJewelBank.CloseJewelWindow();
		pSetCursorFocus = false;
	}
	else
	{
		gJewelBank.OpenJewelWindow();
		pSetCursorFocus = true;
	}
}