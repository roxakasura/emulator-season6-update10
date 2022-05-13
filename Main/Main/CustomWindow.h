#pragma once
#include "stdafx.h"

class cCustomWindow
{
public:
	cCustomWindow();
	~cCustomWindow();
	bool		DrawCustomList();
	bool		DrawResetWindow();
	bool        DrawMenuOP();
	bool        DrawMenuBUYVIP();
	void		keyPressed(DWORD);
	uintInput	*bufferUint;

	uintInput	*ResetAddStr;
	uintInput	*ResetAddAgi;
	uintInput	*ResetAddVit;
	uintInput	*ResetAddEne;
	uintInput	*ResetAddCmd;

	GUIObj		*ResetWindow;
	GUIButton	*ResetOK;
	GUIButton	*ResetCANCEL;

	GUICheckbox *ResetTypeNOR;
	GUICheckbox *ResetTypeVIP;


	uintInput	*ResetAddPoint[5];
	GUICheckbox *AddPoint[5];

	GUICheckbox *AddStr;
	GUICheckbox *AddAgi;
	GUICheckbox *AddVit;
	GUICheckbox *AddEne;
	GUICheckbox *AddCmd;

	GUItga		*XulieFlowResource;
	GUItga		*shandianCosredResource;
	GUIAnimation *XulieFlow;
	GUIAnimation *shandianCosred;

	//custom list
	GUIObj		*CustomList;
	GUIbutton	*CustomButton[8];
	GUIbutton	*CustomClose;
	//new menu op
	GUIObj		*CustomMenuOP;
	GUICheckbox *MenuOPKG[6];
	GUIbutton	*MenuOPKGButton[2];
	/*Buy Vip*/
    GUIObj      *CustomBuyVIP;
	GUIbutton	*CustomButtonVIP[3];
	/*Event Time*/
	GUIObj      *CustomEventTime;
	GUIbutton   *CustomButtonEvent[2];
	/*Ranking*/
	GUIObj      *CustomRanking;
	GUIbutton   *CustomRankingBTN[2];
	/*CommandInfo*/
	GUIObj      *CustomCommandInfo;
	GUIbutton   *CustomCommandInfoBTN[2];
	/*LuckyWheel*/
	GUIObj      *CustomLuckyWheel;
	GUIbutton   *CustomLuckyWheelBTN[2];
	/*SmithItem*/
	GUIObj      *CustomSmithItem;
	GUICheckbox *CustomCheckBox[14];
	GUIbutton   *CustomSmithBTN[2];
	GUIbutton   *prevButton[5];
	GUIbutton   *nextButton[5];
	/*Windows X803*/
	GUIbutton   *CloseWindowsUP;
private:

};extern cCustomWindow CustomWindow;