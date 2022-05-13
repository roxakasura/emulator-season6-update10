#include "stdafx.h"
#include "NewInterface.h"
#include "CustomWindow.h"
#include "NewFont.h"
#include "Interface.h"
#include "Defines.h"
#include "CMacroUIEx.h"
#include "CustomEventTime.h"
#include "CustomBuyVip.h"
#include "CustomRanking.h"
#include "CustomCommandInfo.h"
#include "Common.h"
#include "CustomFog.h"
#include "ChatExpanded.h"
#include "CustomMessage.h"
#include "Protect.h"
#include "User.h"
#include "MuHelper.h"
cCustomWindow CustomWindow;

cCustomWindow::cCustomWindow()
{
	char i;
	//Reset System
	this->ResetWindow	= new GUIObj(200, 20, 150, 350, true);
	this->ResetOK		= new GUIButton(220, 300, 60, 30, 150);
	this->ResetCANCEL	= new GUIButton(310, 300, 60, 30, 150);

	for (i = 0; i < 5; i++) {
		this->AddPoint[i] = new GUICheckbox(0, 0, 10, 12, 150);
		this->ResetAddPoint[i] = new uintInput(0, 1999999999, 0);
	}
	this->bufferUint	= new uintInput(0, 4000000000, 50);
	
	this->ResetTypeNOR	= new GUICheckbox(0, 0, 10, 12, 150);
	this->ResetTypeVIP	= new GUICheckbox(0, 0, 10, 12, 150);
	//END Reset System
	this->XulieFlowResource = new GUItga(0xF2000, 256, 128, 768, 384);
	this->shandianCosredResource = new GUItga(0xF2001, 64, 64, 256, 256);
	this->XulieFlow = new GUIAnimation(this->XulieFlowResource, 200, 100, 256, 128, 9, 3, 3, 125);
	this->shandianCosred = new GUIAnimation(this->shandianCosredResource, 200, 100, 64, 64, 15, 4, 4, 125);

	gCMacroUIEx.macroSwitchServer = new GUIbutton;
	gCMacroUIEx.macroSwitchServer->data = new GUIButton(269, 141, 35, 10, 150);
	gCMacroUIEx.macroSwitchServer->normalFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->hoverFrame = new GUIresource(0xF3001, 59, 20, 720, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->clickedFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gCMacroUIEx.macroSwitchServer->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gCMacroUIEx.macroSwitchServerHover = new GUIbutton;
	gCMacroUIEx.macroSwitchServerHover->data = new GUIButton(12.5, 3, 166 / 1.5, 24 / scale_ratio, 0);
	gCMacroUIEx.macroSwitchServerHover->normalFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gCMacroUIEx.macroSwitchServerHover->hoverFrame = new GUIresource(0xF3001, 166, 20, 385, 45, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerHover->clickedFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gCMacroUIEx.macroSwitchServerHover->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gCMacroUIEx.macroSwitchServerSliderUp = new GUIbutton;
	gCMacroUIEx.macroSwitchServerSliderUp->data = new GUIButton(121, 21.5, 24 / 1.5, 16 / 1.5, 150);
	gCMacroUIEx.macroSwitchServerSliderUp->normalFrame = new GUIresource(0xF3001, 24, 16, 547 - 24, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->hoverFrame = new GUIresource(0xF3001, 24, 16, 523 - 24, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->clickedFrame = new GUIresource(0xF3001, 24, 16, 403, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderUp->disabledFrame = new GUIresource(0xF3001, 24, 16, 499 - 24, 73, 1024, 256, 1.5, 1.5);

	gCMacroUIEx.macroSwitchServerSliderDown = new GUIbutton;
	gCMacroUIEx.macroSwitchServerSliderDown->data = new GUIButton(121, 158.5, 24 / 1.5, 16 / 1.5, 150);
	gCMacroUIEx.macroSwitchServerSliderDown->normalFrame = new GUIresource(0xF3001, 24, 16, 451, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->hoverFrame = new GUIresource(0xF3001, 24, 16, 427, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->clickedFrame = new GUIresource(0xF3001, 24, 16, 571, 73, 1024, 256, 1.5, 1.5);
	gCMacroUIEx.macroSwitchServerSliderDown->disabledFrame = new GUIresource(0xF3001, 24, 16, 547, 73, 1024, 256, 1.5, 1.5);

	gCMacroUIEx.macroLog = new GUIbutton;
	gCMacroUIEx.macroLog->data = new GUIButton(151.5, 7.5, 18, 18, 150);
	gCMacroUIEx.macroLog->normalFrame = new GUIresource(0xF3001, 28, 28, 752, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroLog->hoverFrame = new GUIresource(0xF3001, 28, 28, 783, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroLog->clickedFrame = new GUIresource(0xF3001, 28, 28, 814, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroLog->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroConfig = new GUIbutton;
	gCMacroUIEx.macroConfig->data = new GUIButton(151.5 + 19.5, 7.5, 18, 18, 150);
	gCMacroUIEx.macroConfig->normalFrame = new GUIresource(0xF3001, 28, 28, 877, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroConfig->hoverFrame = new GUIresource(0xF3001, 28, 28, 970, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroConfig->clickedFrame = new GUIresource(0xF3001, 28, 28, 355, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroConfig->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroAuto = new GUIbutton;
	gCMacroUIEx.macroAuto->data = new GUIButton(151.5 + 19.5 * 2, 7.5, 18, 18, 150);
	gCMacroUIEx.macroAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 231, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 262, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 293, 44, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gCMacroUIEx.macroPauseAuto = new GUIbutton;
	gCMacroUIEx.macroPauseAuto->data = new GUIButton(151.5 + 19.5 * 2, 7.5, 18, 18, 150);
	gCMacroUIEx.macroPauseAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 691, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroPauseAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 722, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroPauseAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 908, 1, 1024, 256, 1.6, 1.6);
	gCMacroUIEx.macroPauseAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gMuHelperS15.macroSwitchServer = new GUIbutton;
	gMuHelperS15.macroSwitchServer->data = new GUIButton(12.5, 3, 35, 10, 150);
	gMuHelperS15.macroSwitchServer->normalFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gMuHelperS15.macroSwitchServer->hoverFrame = new GUIresource(0xF3001, 59, 20, 720, 42, 1024, 256, 1.5, 1.75);
	gMuHelperS15.macroSwitchServer->clickedFrame = new GUIresource(0xF3001, 59, 20, 779, 42, 1024, 256, 1.5, 1.75);
	gMuHelperS15.macroSwitchServer->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gMuHelperS15.macroSwitchServerHover = new GUIbutton;
	gMuHelperS15.macroSwitchServerHover->data = new GUIButton(12.5, 3, 166 / 1.5, 24 / scale_ratio, 0);
	gMuHelperS15.macroSwitchServerHover->normalFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gMuHelperS15.macroSwitchServerHover->hoverFrame = new GUIresource(0xF3001, 166, 20, 385, 45, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerHover->clickedFrame = new GUIresource(0xF3001, 0, 0, 385, 44, 1024, 256, 2, 2);
	gMuHelperS15.macroSwitchServerHover->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	gMuHelperS15.macroSwitchServerSliderUp = new GUIbutton;
	gMuHelperS15.macroSwitchServerSliderUp->data = new GUIButton(121, 21.5, 24 / 1.5, 16 / 1.5, 150);
	gMuHelperS15.macroSwitchServerSliderUp->normalFrame = new GUIresource(0xF3001, 24, 16, 547 - 24, 73, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerSliderUp->hoverFrame = new GUIresource(0xF3001, 24, 16, 523 - 24, 73, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerSliderUp->clickedFrame = new GUIresource(0xF3001, 24, 16, 403, 73, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerSliderUp->disabledFrame = new GUIresource(0xF3001, 24, 16, 499 - 24, 73, 1024, 256, 1.5, 1.5);

	gMuHelperS15.macroSwitchServerSliderDown = new GUIbutton;
	gMuHelperS15.macroSwitchServerSliderDown->data = new GUIButton(121, 158.5, 24 / 1.5, 16 / 1.5, 150);
	gMuHelperS15.macroSwitchServerSliderDown->normalFrame = new GUIresource(0xF3001, 24, 16, 451, 73, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerSliderDown->hoverFrame = new GUIresource(0xF3001, 24, 16, 427, 73, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerSliderDown->clickedFrame = new GUIresource(0xF3001, 24, 16, 571, 73, 1024, 256, 1.5, 1.5);
	gMuHelperS15.macroSwitchServerSliderDown->disabledFrame = new GUIresource(0xF3001, 24, 16, 547, 73, 1024, 256, 1.5, 1.5);

	gMuHelperS15.macroLog = new GUIbutton;
	gMuHelperS15.macroLog->data = new GUIButton(151.5, 7.5, 18, 18, 150);
	gMuHelperS15.macroLog->normalFrame = new GUIresource(0xF3001, 28, 28, 752, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroLog->hoverFrame = new GUIresource(0xF3001, 28, 28, 783, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroLog->clickedFrame = new GUIresource(0xF3001, 28, 28, 814, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroLog->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gMuHelperS15.macroConfig = new GUIbutton;
	gMuHelperS15.macroConfig->data = new GUIButton(151.5 + 19.5, 7.5, 18, 18, 150);
	gMuHelperS15.macroConfig->normalFrame = new GUIresource(0xF3001, 28, 28, 877, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroConfig->hoverFrame = new GUIresource(0xF3001, 28, 28, 970, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroConfig->clickedFrame = new GUIresource(0xF3001, 28, 28, 355, 44, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroConfig->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gMuHelperS15.macroAuto = new GUIbutton;
	gMuHelperS15.macroAuto->data = new GUIButton(151.5 + 19.5 * 2, 7.5, 18, 18, 150);
	gMuHelperS15.macroAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 231, 44, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 262, 44, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 293, 44, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);

	gMuHelperS15.macroPauseAuto = new GUIbutton;
	gMuHelperS15.macroPauseAuto->data = new GUIButton(151.5 + 19.5 * 2, 7.5, 18, 18, 150);
	gMuHelperS15.macroPauseAuto->normalFrame = new GUIresource(0xF3001, 28, 28, 691, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroPauseAuto->hoverFrame = new GUIresource(0xF3001, 28, 28, 722, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroPauseAuto->clickedFrame = new GUIresource(0xF3001, 28, 28, 908, 1, 1024, 256, 1.6, 1.6);
	gMuHelperS15.macroPauseAuto->disabledFrame = new GUIresource(0x0, 0, 0, 0, 0, 0, 0, 0, 0);


	//custom window

	this->CustomList = new GUIObj(200, 20, 190, 340, true);

	for (i = 0; i < 9; i++){
		this->CustomButton[i] = new GUIbutton;
		this->CustomButton[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomButton[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButton[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButton[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButton[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}


	this->CustomClose = new GUIbutton;
	this->CustomClose->data = new GUIButton(190 + 190 / 1.5, 30, 20 / 1.5, 20 / 1.5, 150);
	this->CustomClose->normalFrame = new GUIresource(0xF1009, 20, 19, 1002, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CustomClose->hoverFrame = new GUIresource(0xF1009, 20, 19, 981, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CustomClose->clickedFrame = new GUIresource(0xF1009, 20, 19, 1002, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CustomClose->disabledFrame = new GUIresource(0xF1009, 20, 19, 981, 0, 1024, 512, pWinWidthReal, pWinHeightReal);

	//new menu op
    this->CustomMenuOP = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 6; i++) {
		this->MenuOPKG[i] = new GUICheckbox(0, 0, 10, 12, 150);
	}
	for (i = 0; i < 2; i++){
		this->MenuOPKGButton[i] = new GUIbutton;
		this->MenuOPKGButton[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->MenuOPKGButton[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->MenuOPKGButton[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->MenuOPKGButton[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->MenuOPKGButton[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Buy VIP*/
	this->CustomBuyVIP = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 3; i++){
		this->CustomButtonVIP[i] = new GUIbutton;
		this->CustomButtonVIP[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomButtonVIP[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonVIP[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonVIP[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonVIP[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Event Time*/
	this->CustomEventTime = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomButtonEvent[i] = new GUIbutton;
		this->CustomButtonEvent[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomButtonEvent[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonEvent[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonEvent[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomButtonEvent[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Ranking*/
	this->CustomRanking = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomRankingBTN[i] = new GUIbutton;
		this->CustomRankingBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomRankingBTN[i]->normalFrame = new GUIresource(0x7A5A, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomRankingBTN[i]->hoverFrame = new GUIresource(0x7EC5, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomRankingBTN[i]->clickedFrame = new GUIresource(0x7EC5, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomRankingBTN[i]->disabledFrame = new GUIresource(0x7EC5, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Command Info*/
	this->CustomCommandInfo = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomCommandInfoBTN[i] = new GUIbutton;
		this->CustomCommandInfoBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomCommandInfoBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomCommandInfoBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomCommandInfoBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomCommandInfoBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*LuckyWheel*/
	this->CustomLuckyWheel = new GUIObj(200, 20, 340, 340, true);
	for (i = 0; i < 2; i++){
		this->CustomLuckyWheelBTN[i] = new GUIbutton;
		this->CustomLuckyWheelBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomLuckyWheelBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomLuckyWheelBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomLuckyWheelBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomLuckyWheelBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}

	/*Smith Item*/
	this->CustomSmithItem = new GUIObj(200, 20, 190, 420, true);
	for (i = 0; i < 5; i++) {
	    this->nextButton[i] = new GUIbutton;
	    this->nextButton[i]->data = new GUIButton(0, 0, 17, 17, 150);
	    this->nextButton[i]->normalFrame = new GUIresource(0xF1003, 17, 17, 372, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->nextButton[i]->hoverFrame = new GUIresource(0xF1003, 17, 17, 351, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->nextButton[i]->clickedFrame = new GUIresource(0xF1003, 17, 17, 330, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->nextButton[i]->disabledFrame = new GUIresource(0xF1003, 17, 17, 727, 298, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}
	for (i = 0; i < 5; i++) {
	    this->prevButton[i] = new GUIbutton;
	    this->prevButton[i]->data = new GUIButton(0, 0, 17, 17, 150);
	    this->prevButton[i]->normalFrame = new GUIresource(0xF1003, 17, 17, 434, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->prevButton[i]->hoverFrame = new GUIresource(0xF1003, 17, 17, 413, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->prevButton[i]->clickedFrame = new GUIresource(0xF1003, 17, 17, 392, 328, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	    this->prevButton[i]->disabledFrame = new GUIresource(0xF1003, 17, 17, 685, 298, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}
	for (i = 0; i < 14; i++) {
        this->CustomCheckBox[i] = new GUICheckbox(0, 0, 10, 12, 150);
	}
	for (i = 0; i < 2; i++){
		this->CustomSmithBTN[i] = new GUIbutton;
		this->CustomSmithBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomSmithBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomSmithBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomSmithBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
		this->CustomSmithBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal2, pWinHeightReal2);
	}
#if(CHANGE_CLASS_SYSTEM==1)
	/*Change Class System*/
	this->CustomChangeClass = new GUIObj(200, 20, 190, 340, true);
	for (i = 0; i < 7; i++){
		this->CustomChangeClassBTN[i] = new GUIbutton;
		this->CustomChangeClassBTN[i]->data = new GUIButton(210 + (i % 2) * 60, 50 + i / 2 * 35, 124 / 1.5, 35 / 1.5, 150);
		this->CustomChangeClassBTN[i]->normalFrame = new GUIresource(0xF1009, 124, 35, 653, 75, 1024, 512, pWinWidthReal, pWinHeightReal);
		this->CustomChangeClassBTN[i]->hoverFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75, 1024, 512, pWinWidthReal, pWinHeightReal);
		this->CustomChangeClassBTN[i]->clickedFrame = new GUIresource(0xF1009, 124, 35, 653, 75 + 37, 1024, 512, pWinWidthReal, pWinHeightReal);
		this->CustomChangeClassBTN[i]->disabledFrame = new GUIresource(0xF1009, 124, 35, 653 + 124 + 3, 75 + 37, 1024, 512, pWinWidthReal, pWinHeightReal);
	}
#endif
	/*Windows Struct x803*/
	this->CloseWindowsUP= new GUIbutton;
	this->CloseWindowsUP->data = new GUIButton(190 + 190 / 1.5, 30, 20 / 1.5, 20 / 1.5, 150);
	this->CloseWindowsUP->normalFrame = new GUIresource(0xF1009, 20, 19, 1002, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->hoverFrame = new GUIresource(0xF1009, 20, 19, 981, 20, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->clickedFrame = new GUIresource(0xF1009, 20, 19, 1002, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
	this->CloseWindowsUP->disabledFrame = new GUIresource(0xF1009, 20, 19, 981, 0, 1024, 512, pWinWidthReal, pWinHeightReal);
}

cCustomWindow::~cCustomWindow()
{
}

bool cCustomWindow::DrawCustomList(){
	if (gInterface.CheckWindow(ObjWindow::FullMap)){
		CustomWindow.CustomList->onShow = false;
	}
	if (!CustomWindow.CustomList->onShow)
		return false;
	bool res = nInterface.DrawWindowBG(CustomWindow.CustomList, "Menu System");
	if(nInterface.Drawbutton(this->CustomClose, CustomWindow.CustomList->X + 168.5, CustomWindow.CustomList->Y + 24, ""))
		CustomWindow.CustomList->onShow = false;
	char* buttonName[] = {"Eventos","Comprar VIP","Ranking","Comandos","Item System","LuckyWheel","Opciones", "Reset System"};
	for (char i = 0; i < 7; i++){
		if (nInterface.Drawbutton(this->CustomButton[i], CustomWindow.CustomList->X + 10 + (i % 2) * (124 / 1.5 + 10), CustomWindow.CustomList->Y + 60 + i / 2 * (35 / 1.5 + 10), buttonName[i])){
			if(i == 0){/*Event Info*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomSmithItem->onShow = false;
			}else if(i == 1){/*Buy Vip*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomSmithItem->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = true;
			}else if(i == 2){/*Custom Ranking*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomSmithItem->onShow = false;
				gCustomRanking.OpenWindow();
			}else if(i == 3){/*Command Info*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomSmithItem->onShow = false;
				//gCustomCommandInfo.OpenCommandWindow();
			}else if(i == 4){
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.CustomSmithItem->onShow = true;
			}else if(i == 5){/*Lucky Wheel*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = true;
			}else if(i == 6){/*Menu Options*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.ResetWindow->onShow = false;
				CustomWindow.CustomSmithItem->onShow = false;
				CustomWindow.CustomMenuOP->onShow = true;
			}else if(i==7){/*Rank System*/
				CustomWindow.CustomList->onShow = false;
				CustomWindow.CustomBuyVIP->onShow = false;
				CustomWindow.CustomCommandInfo->onShow = false;
				CustomWindow.CustomEventTime->onShow = false;
				CustomWindow.CustomRanking->onShow = false;
				CustomWindow.CustomLuckyWheel->onShow = false;
				CustomWindow.CustomMenuOP->onShow = false;
				CustomWindow.CustomSmithItem->onShow = false;
				CustomWindow.ResetWindow->onShow = true;
			}
		}
	}
	return res;
}

bool cCustomWindow::DrawMenuBUYVIP(){
	if (gInterface.CheckWindow(ObjWindow::FullMap)){
		CustomWindow.CustomBuyVIP->onShow = false;
	}
	if (!CustomWindow.CustomBuyVIP->onShow)
		return false;
	bool res = nInterface.DrawWindowBG(CustomWindow.CustomBuyVIP, "VIP System");
	if(nInterface.Drawbutton(this->CustomClose, CustomWindow.CustomBuyVIP->X + 168.5, CustomWindow.CustomBuyVIP->Y + 24, ""))
		CustomWindow.CustomBuyVIP->onShow = false;
	int LineY = gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 10, CustomWindow.CustomBuyVIP->Y + 50, 190, 1, gCustomMessage.GetMessage(6), gObjUser.lpPlayer->Name);
	LineY = gInterface.DrawFormat(eGold, CustomWindow.CustomBuyVIP->X + 10, (int)LineY, 175, 1, gCustomMessage.GetMessage(14));
	LineY = gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 10, (int)LineY, 175, 1, gCustomMessage.GetMessage(7));
	LineY = gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 10, (int)LineY, 175, 1, gCustomMessage.GetMessage(8));
	gInterface.DrawFormat(eGold, CustomWindow.CustomBuyVIP->X + 10, CustomWindow.CustomBuyVIP->Y + 110 - 2, 210, 1, "Plan");
	gInterface.DrawFormat(eGold, CustomWindow.CustomBuyVIP->X + 60, CustomWindow.CustomBuyVIP->Y + 110 - 2 , 210,1, "Exp");
	gInterface.DrawFormat(eGold, CustomWindow.CustomBuyVIP->X + 110, CustomWindow.CustomBuyVIP->Y + 110 - 2, 210, 1, "Drop");
	gInterface.DrawFormat(eGold, CustomWindow.CustomBuyVIP->X + 150,  CustomWindow.CustomBuyVIP->Y + 110 - 2, 210, 1, "Time");
	if (gProtect.m_MainInfo.VipTypes < 1 || gProtect.m_MainInfo.VipTypes > 3){
		gProtect.m_MainInfo.VipTypes = 3;
	}
	for( int i = 0; i < gProtect.m_MainInfo.VipTypes; i++ ){
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 10, CustomWindow.CustomBuyVIP->Y + 125 + (12 * i) - 5, 175, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 60, CustomWindow.CustomBuyVIP->Y + 125 + (12 * i) - 5, 175, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Exp);
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 110, CustomWindow.CustomBuyVIP->Y + 125 + (12 * i) - 5, 175, 1, "+%d%%", gCustomBuyVip.m_CustomBuyVipInfo[i].Drop);
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 150, CustomWindow.CustomBuyVIP->Y + 125 + (12 * i) - 5, 175, 1, "%d day(s)", gCustomBuyVip.m_CustomBuyVipInfo[i].Days);
		pDrawGUI(0x7B5E, CustomWindow.CustomBuyVIP->X + 10, CustomWindow.CustomBuyVIP->Y + 125 + (12 * i) + 9 - 5, 82.0f, 2.0);
		pDrawGUI(0x7B5E, CustomWindow.CustomBuyVIP->X + 10 + 82, CustomWindow.CustomBuyVIP->Y + 125 + (12 * i) + 9 - 5, 82.0f, 2.0);
		//--
		gInterface.DrawFormat(eGold, CustomWindow.CustomBuyVIP->X + 10,  CustomWindow.CustomBuyVIP->Y + 160 - 2, 210, 1, "Value:");
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 10, CustomWindow.CustomBuyVIP->Y + 175 + (12 * i) - 5, 175, 1, gCustomBuyVip.m_CustomBuyVipInfo[i].VipName);
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 60, CustomWindow.CustomBuyVIP->Y + 175 + (12 * i) - 5, 175, 1, gCustomMessage.GetMessage(11), gCustomBuyVip.m_CustomBuyVipInfo[i].Coin1);
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 110, CustomWindow.CustomBuyVIP->Y + 175 + (12 * i) - 5, 175, 1, gCustomMessage.GetMessage(12), gCustomBuyVip.m_CustomBuyVipInfo[i].Coin2);
		gInterface.DrawFormat(eWhite, CustomWindow.CustomBuyVIP->X + 150, CustomWindow.CustomBuyVIP->Y + 175 + (12 * i) - 5, 175, 1, gCustomMessage.GetMessage(13), gCustomBuyVip.m_CustomBuyVipInfo[i].Coin3);
		pDrawGUI(0x7B5E, CustomWindow.CustomBuyVIP->X + 10, CustomWindow.CustomBuyVIP->Y + 175 + (12 * i) + 9 - 5, 82.0f, 2.0);
		pDrawGUI(0x7B5E, CustomWindow.CustomBuyVIP->X + 10 + 82, CustomWindow.CustomBuyVIP->Y + 175 + (12 * i) + 9 - 5, 82.0f, 2.0);
	}
	char* buttonName[] = {gCustomBuyVip.m_CustomBuyVipInfo[0].VipName,gCustomBuyVip.m_CustomBuyVipInfo[1].VipName,gCustomBuyVip.m_CustomBuyVipInfo[2].VipName};
	for (char i = 0; i < 3; i++){
		if (nInterface.Drawbutton(this->CustomButtonVIP[i], CustomWindow.CustomBuyVIP->X + 5 + (i % 2) * (124 / 1.5 + 10), CustomWindow.CustomBuyVIP->Y + 210 + i / 2 * (35 / 1.5 + 10), buttonName[i])){
			if(i == 0){
	            gCustomBuyVip.BuyStatus(1);
			}else if(i == 1){
	            gCustomBuyVip.BuyStatus(2);
			}else if(i == 2){
	            gCustomBuyVip.BuyStatus(3);
			}
		}
	}
	return res;
}

bool cCustomWindow::DrawMenuOP(){
	if (gInterface.CheckWindow(ObjWindow::FullMap)){
		CustomWindow.CustomMenuOP->onShow = false;
	}
	if (!CustomWindow.CustomMenuOP->onShow)
		return false;
	bool res = nInterface.DrawWindowBG(CustomWindow.CustomMenuOP, "System");
	if(nInterface.Drawbutton(this->CustomClose, CustomWindow.CustomMenuOP->X + 168.5, CustomWindow.CustomMenuOP->Y + 24, ""))
		CustomWindow.CustomMenuOP->onShow = false;
	char* text[] = { 
		"                 Fog", 
		"                 MiniMap" , 
		"                 TimeServer", 
		"                 GlowEffect", 
		"                 FpsPlayer"}; 
		//"                 ChatExpand"};
	bool clickTransparency;
	for (char i = 0; i < 5; i++) {
		if (nInterface.DrawCheckbox(CustomWindow.MenuOPKG[i], CustomWindow.CustomMenuOP->X + 20, CustomWindow.CustomMenuOP->Y + 55 + 20 * i, text[i])){
			if(i==0){
                if(gFog.EnableFog){
		            gFog.EnableFog = false;
	            }else{
		            gFog.EnableFog = true;
	            }
			}else if(i==1){
	            if (MiniMap!=0){
		            MiniMap = 0;
	            }else{
		            MiniMap = 1;
	            }
			}else if(i==2){
	            if (gInterface.Data[eTIME].OnShow!=true){
		            gInterface.Data[eTIME].OnShow = true;
				}else{
		            gInterface.Data[eTIME].OnShow = false;
	            }
			}else if(i==3){
	            if (DisableGlowEffect!=0){
		            DisableGlowEffect = 0;
	            }else{
		            DisableGlowEffect = 1;
	            }
			}//else if(i==5){
			//	gChatExpanded.Switch();
			//}
		}
	}
	return res;
}

bool cCustomWindow::DrawResetWindow(){
	if (gInterface.CheckWindow(ObjWindow::FullMap)){
		CustomWindow.ResetWindow->onShow = false;
	}
	if (!CustomWindow.ResetWindow->onShow)
		return false;
	bool res = nInterface.DrawWindowBG(CustomWindow.ResetWindow, "Reset System");
	bool ok = nInterface.DrawButton(CustomWindow.ResetOK, CustomWindow.ResetWindow->X + 10, CustomWindow.ResetWindow->Max_Y - 20 - CustomWindow.ResetOK->Height, "Start");
	bool cancel = nInterface.DrawButton(CustomWindow.ResetCANCEL, CustomWindow.ResetWindow->X + 80, CustomWindow.ResetWindow->Max_Y - 20 - CustomWindow.ResetCANCEL->Height, "Close");
	if (cancel) {
		CustomWindow.ResetWindow->onShow = false;
	}
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 20, CustomWindow.ResetWindow->Y + 65, 0xffffffff, 0xff00055, 50, 0, 0, " ");
	nInterface.DrawAnimation(this->XulieFlow, CustomWindow.ResetWindow->X + 5, CustomWindow.ResetWindow->Y + 45);
	nInterface.DrawAnimation(this->XulieFlow, CustomWindow.ResetWindow->X + 5, CustomWindow.ResetWindow->Y + 70);
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 20, CustomWindow.ResetWindow->Y + 65, 0xffffffff, 0x0, 50, 0, 0, "Estado:");
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 75, CustomWindow.ResetWindow->Y + 65, 0xffffffff, 0x0, 50, 0, 0, "Apagar");
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 20, CustomWindow.ResetWindow->Y + 90, 0xffffffff, 0x0, 50, 0, 0, "Reset:");
	if (nInterface.DrawCheckbox(CustomWindow.ResetTypeNOR, CustomWindow.ResetWindow->X + 75, CustomWindow.ResetWindow->Y + 90, "Normal"))
		CustomWindow.ResetTypeVIP->state = 0;
	if (nInterface.DrawCheckbox(CustomWindow.ResetTypeVIP, CustomWindow.ResetWindow->X + 75, CustomWindow.ResetWindow->Y + 105, "VIP"))
		CustomWindow.ResetTypeNOR->state = 0;
	if (CustomWindow.ResetTypeVIP->state == 0 && CustomWindow.ResetTypeNOR->state == 0)
		CustomWindow.ResetTypeNOR->state = 1;

	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 20, CustomWindow.ResetWindow->Y + 125, 0xffffffff, 0x0, 50, 0, 0, "Puntos:");
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 75, CustomWindow.ResetWindow->Y + 125, 0xffffffff, 0x0, 50, 0, 0, "%s", nInterface.NumberFormat(99999999));
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 20, CustomWindow.ResetWindow->Y + 140, 0xffffffff, 0x0, 50, 0, 0, "Valor Reset:");
	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 75, CustomWindow.ResetWindow->Y + 140, 0xffffffff, 0x0, 50, 0, 0, "%s %s", nInterface.NumberFormat(1234), "Zen");

	CustomFont.Draw(CustomFont.FontNormal, CustomWindow.ResetWindow->X + 10, CustomWindow.ResetWindow->Y + 180, 0xffffffff, 0x0, 50, 0, 0, "Sistema AutoReset");

	char* text[] = { " Str", " Agi" , " Vit", " Ene", " Cmd" };


	return res;
}


void cCustomWindow::keyPressed(DWORD a1){
	if (!this->bufferUint->selected)
	{
		return;
	}
	char lastValue = this->bufferUint->value % 10;
	unsigned int calVal = this->bufferUint->value;
	switch (a1)
	{
	case VK_BACK:
	{
		if (calVal && this->bufferUint->lastActionTime < GetTickCount()) {
			calVal = (calVal - lastValue) / 10;
			this->bufferUint->lastActionTime = GetTickCount() + this->bufferUint->delay;
		}
	} break;
	case 0x30:
	case 0x31:
	case 0x32:
	case 0x33:
	case 0x34:
	case 0x35:
	case 0x36:
	case 0x37:
	case 0x38:
	case 0x39:
	{
		if (calVal || (a1 - 0x30))
		{
			if (this->bufferUint->lastActionTime < GetTickCount()) {
				calVal = calVal * 10 + (a1 - 0x30);
				this->bufferUint->lastActionTime = GetTickCount() + this->bufferUint->delay;
			}
		}
	} break;
	case 0x60:
	case 0x61:
	case 0x62:
	case 0x63:
	case 0x64:
	case 0x65:
	case 0x66:
	case 0x67:
	case 0x68:
	case 0x69:
	{
		if (calVal || (a1 - 0x60))
		{
			if (this->bufferUint->lastActionTime < GetTickCount()) {
				calVal = calVal * 10 + (a1 - 0x60);
				this->bufferUint->lastActionTime = GetTickCount() + this->bufferUint->delay;
			}
		}
	} break;
	default:
		break;
	}
	if (calVal > this->bufferUint->max)
	{
		this->bufferUint->value = this->bufferUint->max;
	}
	else
		this->bufferUint->value = calVal;
}