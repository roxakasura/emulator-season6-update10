#include "StdAfx.h"
#include "NewUIButton.h"

CNewUIButton::CNewUIButton()
{
	this->isCreate = false;
	memset(&this->thisa, 0, sizeof(this->thisa));
	Constructor_Btn(this->thisa, 172, 1, InitializeButton, DestroyButton);
}


CNewUIButton::~CNewUIButton()
{
	delete[]this->thisa;
}

void CNewUIButton::Construct()
{
	if (!this->isCreate)
	{
		this->isCreate = true;
	}
}

void CNewUIButton::ChangeText(char* btname)
{
	int std_String[7];
	ChartoString(&std_String, btname);
	ButtonChangeText(this->thisa, std_String[0], std_String[1], std_String[2], std_String[3], std_String[4], std_String[5], std_String[6]);
}

void CNewUIButton::SetTooltipText(char* btname)
{
	int std_String[7];
	ChartoString(&std_String, btname);
	ButtonSetTooltip(this->thisa, std_String[0], std_String[1], std_String[2], std_String[3], std_String[4], std_String[5], std_String[6], 1);
}

void CNewUIButton::ChangeButtonImgState(bool imgregister, int imgindex, bool overflg, bool isimgwidth, bool bClickEffect)
{
	Button_ChangeButtonImgState(this->thisa, imgregister, imgindex, overflg, isimgwidth, bClickEffect);
}

void CNewUIButton::CButtonInfo(int x, int y, int sx, int sy)
{
	Button_ChangeButtonInfo(this->thisa, x, y, sx, sy);
}

void CNewUIButton::ChangeImgColor(DWORD eventstate, unsigned int color)
{
	Button_ChangeImgColor(this->thisa, eventstate, color);
}

int CNewUIButton::GetBTState()
{
	return 1;//NewUIButtonGetBTState(this->thisa);
}

bool CNewUIButton::UpdateMouseEvent()
{
	return Button_UpdateMouseEvent(this->thisa);
}

bool CNewUIButton::Render(bool RendOption)
{
	return Button_Render(this->thisa, RendOption);
}