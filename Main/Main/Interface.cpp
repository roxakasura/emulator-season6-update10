#include "stdafx.h"
#include "Main.h"
#include "Common.h"
#include "Camera\CameraSystem.h"
#include "CustomInterface.h"
#include "CustomCommandInfo.h"
#include "CustomEventTime.h"
#include "CustomRanking.h"
#include "CustomJewelBank.h"
#include "CustomLuckyWheel.h"
#include "CustomGloves.h"
#include "Interface.h"
#include "Import.h"
#include "Reconnect.h"
#include "TMemory.h"
#include "Defines.h"
#include "OffTrade.h"
#include "Protect.h"
#include "Protocol.h"
#include "PrintPlayer.h"
#include "User.h"
#include "Util.h"
#include "PostItem.h"
#include "WingInvisible.h"
#include "CMacroUIEx.h"
#include "CustomNewButtonD.h"
#include "Performance.h"
#include "StatsAdvanced.h"
#include "WindowsD.h"
#include "Inter803.h"
#include "LoadImages803.h"
#include "MuHelper.h"
#include "Central.h"
#include "MiniMap.h"
#include "MultiCharacter.h"
#include "BankUpgrade.h"
#include "StoreSearch.h"
#include "CustomMessage.h"
#include "Antilag.h"
#include "ChangeSystem.h"
#include "ServerSwitch.h"
#include "BuyVip.h"
#include "MenuCustom.h"
#include "MuunOption.h"
#include "NewUIButton.h"
#include "NewUIPetInfoWindow.h"
#include "SEASON3B.h"
#include "UIControl.h"
#include "NewInfo.h"
#include "NewUISystem.h"

Interface	gInterface;
int ItemOverInfo;
int TesteJanela;

static const char* StoreName = "Teste";

#if (SLOT_PET == 1)
void NewModelRender3D(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix( );
	glLoadIdentity( );

	glViewport2( 0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y );
	float v2 = *(float*) MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	gluPerspective2(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C );
	glMatrixMode(0x1700u);
	glPushMatrix( );
	glLoadIdentity( );
	GetOpenGLMatrix(0x87933A0);
	EnableDepthTest( );
	EnableDepthMask( );

	RenderItem3D(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	glMatrixMode(0x1700u);
	glPopMatrix( );
	glMatrixMode(0x1701u);
	glPopMatrix( );

	glColor4f((GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0,(GLfloat) 1.0);
	pSetBlend(false);
}

signed int __thiscall Interface::PaintItemTooltip(int thisa, int DirPathX, int DirPathY, int lpItemInfo, int a7, int a8, int a9)
{

	ItemOverInfo = *(WORD *)lpItemInfo;
	return ExecuteTooltip(thisa, DirPathX, DirPathY, lpItemInfo, a7, a8, a9);
}

int __thiscall Interface::NewSlotInventory( int thisa)
{
	int result;

	result = sub_837000(thisa);

	gInterface.PetSlot.DirTexture = *(DWORD *)(thisa + 240);
	gInterface.PetSlot.DirPathX = *(DWORD *)(thisa + 224);
	gInterface.PetSlot.DirPathY = *(DWORD *)(thisa + 228) - *(DWORD *)(thisa + 236) - 4;
	gInterface.PetSlot.DirPathW = *(DWORD *)(thisa + 232);
	gInterface.PetSlot.DirPathH = *(DWORD *)(thisa + 236);

	EnableAlphaTest( 1 );
	pDrawGUI(gInterface.PetSlot.DirTexture, 
		gInterface.PetSlot.DirPathX, 
		gInterface.PetSlot.DirPathY, 
		gInterface.PetSlot.DirPathW, gInterface.PetSlot.DirPathH);
	pGLSwitch( );

	if(pCheckMouseOver(gInterface.PetSlot.DirPathX, 
		gInterface.PetSlot.DirPathY, 
		gInterface.PetSlot.DirPathW, gInterface.PetSlot.DirPathH) )
	{
		gInterface.PetSlot.Target = 1;

		if ( gInterface.PetSlot.ItemStrl )
		{
			if( sub_7DD0F0( ) )
			{
				glColor4f(0.89999998, 0.1, 0.1, 0.40000001);
				EnableAlphaTest(1);
				pDrawBarForm(gInterface.PetSlot.DirPathX + 1.0, gInterface.PetSlot.DirPathY, gInterface.PetSlot.DirPathW - 4.0, gInterface.PetSlot.DirPathH - 4.0, 0.0, 0);
				pGLSwitch( );
			}
			else
			{
			}
		}
	}
	else
	{
		gInterface.PetSlot.Target = 0;
	}

	if ( gInterface.PetSlot.ItemStrl != nullptr)
	{
		ObjectItem * lItem = (ObjectItem*)gInterface.PetSlot.ItemStrl;

		NewModelRender3D(
			gInterface.PetSlot.DirPathX + 1.0,
			gInterface.PetSlot.DirPathY,
			gInterface.PetSlot.DirPathW - 4.0,
			gInterface.PetSlot.DirPathH - 4.0,
			lItem->ItemID,
			lItem->Level,
			lItem->ExcellentOption,
			lItem->AncientOption,
			0);

		if( gInterface.PetSlot.Target == 1 )
		{
			gInterface.PaintItemTooltip(*(DWORD *)(GetInstance( ) + 308), gInterface.PetSlot.DirPathX + 1.0,
				gInterface.PetSlot.DirPathY, (int)lItem, 0, 0, 0);
		}
	}

	return result;
}

BYTE __thiscall Interface::PickItem(int thisa)
{
	int v74; // [sp+10D4h] [bp-18h]@4
	int v76; // [sp+10DCh] [bp-10h]@3

	v76 = sub_7DD0F0( );
	if( v76 )
	{
		if( gInterface.PetSlot.Target == 1 && GetInKeyState( 1 ))
		{
			if ( !gInterface.PetSlot.ItemStrl )
			{
				v74 = sub_7D9430( v76 );
				//if ( *(BYTE *)(v74 + 97) && *(BYTE *)(v74 + 98) )
				//{
					gInterface.PetSlot.ItemStrl = (void*)sub_7D9430( v76 );

					sub_7DD1B0( );
					return 1;
				//}
			}
			else
			{
				sub_7DD100(0, gInterface.PetSlot.ItemStrl);
				gInterface.PetSlot.ItemStrl = nullptr;
				return 1;
			}
		}
	}
	return sub_837A30(thisa);
}
#endif

void Interface::Load()
{
	this->BindObject(eFlag01, 0x7880, 78, 78, -1, -1);
	this->BindObject(eFlag02, 0x7881, 78, 78, -1, -1);
	this->BindObject(eFlag03, 0x7882, 78, 78, -1, -1);
	this->BindObject(eFlag04, 0x7883, 78, 78, -1, -1);
	this->BindObject(eFlag05, 0x7884, 78, 78, -1, -1);
	this->BindObject(eFlag06, 0x7885, 78, 78, -1, -1);
	this->BindObject(eFlag07, 0x7886, 78, 78, -1, -1);
	this->BindObject(eFlag08, 0x7887, 78, 78, -1, -1);
	this->BindObject(eFlag09, 0x7888, 78, 78, -1, -1);
	this->BindObject(eFlag10, 0x7889, 78, 78, -1, -1);
	this->BindObject(eFlag11, 0x7890, 78, 78, -1, -1);
	this->BindObject(eFlag12, 0x7891, 78, 78, -1, -1);
	this->BindObject(eFlag13, 0x7892, 78, 78, -1, -1);
	this->BindObject(eFlag14, 0x7893, 78, 78, -1, -1);
	this->BindObject(eFlag15, 0x7894, 78, 78, -1, -1);
	this->BindObject(eFlag16, 0x7895, 78, 78, -1, -1);
	this->BindObject(eFlag17, 0x7896, 78, 78, -1, -1);
	this->BindObject(eFlag18, 0x7897, 78, 78, -1, -1);
	this->BindObject(eFlag19, 0x7898, 78, 78, -1, -1);
	this->BindObject(eFlag20, 0x7899, 78, 78, -1, -1);
	this->BindObject(eFlag21, 0x7900, 78, 78, -1, -1);
	this->BindObject(eFlag22, 0x7901, 78, 78, -1, -1);

	//gCustomMenuD.Bind();
	gJewelBank.Bind();
	//LuckyWheel
	gLuckyWheel.Bind();
	//Store Search
	g_PersonalShopEx.BindImages();
	//panel
	this->BindObject(eMoney1, 0x6860, 75, 14, -1, -1);
	this->BindObject(eMoney2, 0x6861, 75, 14, -1, -1);
	this->BindObject(eTIME, 0x787F, 80, 20, 174, 0);
	this->BindObject(eRanking, 0x7902, 179, 27, -1, -1);
	this->BindObject(eSAMPLEBUTTON, 0x7903, 25, 40, -1, -1);
	this->BindObject(eSAMPLEBUTTON2, 0x7904, 25, 40, -1, -1);

	//Premium system
	this->BindObject(eVip_MAIN, 0x7A5A, 222, 250, -1, -1);
	this->BindObject(eVip_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eVip_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eVip_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eVip_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eVip_CLOSE, 0x7EC5, 36, 29, -1, -1);
	this->BindObject(eVip_STATUS, 0x7A5E, 108, 29, -1, -1);

	if(gProtect.m_MainInfo.CustomInterfaceType <=2 || gProtect.m_MainInfo.CustomInterfaceType == 4)
	{
		//Menu
		this->BindObject(eMenu_MAIN, 0x7A5A, 222, 240, -1, -1);
		this->BindObject(eMenu_TITLE, 0x7A63, 230, 67, -1, -1);
		this->BindObject(eMenu_FRAME, 0x7A58, 230, 15, -1, -1);
		this->BindObject(eMenu_FOOTER, 0x7A59, 230, 50, -1, -1);
		this->BindObject(eMenu_DIV, 0x7A62, 223, 21, -1, -1);
		this->BindObject(eMenu_CLOSE, 0x7EC5, 36, 29, -1, -1);
		this->BindObject(eMenu_OPT1, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT2, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT3, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT4, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eMenu_OPT20, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eVip_BRONZE, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eVip_SILVER, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eVip_GOLD, 0x7A5E, 108, 29, -1, -1);
		this->BindObject(eVip_PLATINUM, 0x7A5E, 108, 29, -1, -1);

	}

	//Command info
	this->BindObject(eCommand_MAIN, 0x7A5A, 222, 300, -1, -1);
	this->BindObject(eCommand_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCommand_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCommand_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCommand_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCommand_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eRanking_MAIN, 0x7A5A, 222, 195, -1, -1);
	this->BindObject(eRanking_CLOSE, 0x7EC5, 36, 29, -1, -1);

	this->BindObject(eCONFIRM_MAIN, 0x7A5A, 222, 120, -1, -1);
	this->BindObject(eCONFIRM_TITLE, 0x7A63, 230, 67, -1, -1);
	this->BindObject(eCONFIRM_FRAME, 0x7A58, 230, 15, -1, -1);
	this->BindObject(eCONFIRM_FOOTER, 0x7A59, 230, 50, -1, -1);
	this->BindObject(eCONFIRM_DIV, 0x7A62, 223, 21, -1, -1);
	this->BindObject(eCONFIRM_BTN_OK, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_BTN_CANCEL, 0x7A5C, 54, 30, -1, -1);
	
	this->BindObject(eLogo, 0x7905, 150, 114, -1, -1);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->BindObject(eMenu, 0x7906, 102, 29, -1, -1);
	}
	else
	{
		this->BindObject(eMenu, 0x7906, 16, 12, -1, -1);
		this->BindObject(eMenuBG, 0x7907, 36, 18, 174, 0);
	}

	//Custom Store
	this->BindObject(eOFFTRADE_JoB, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoS, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_JoC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCC, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCP, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_WCG, 0x7908, 40, 19, -1, -1);
	this->BindObject(eOFFTRADE_OPEN, 0x7BFD, 108, 30, -1, -1);
	this->BindObject(eSTORE_CLOSE, 0x7BFD, 108, 30, -1, -1);

	this->BindObject(eNextCommand, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevCommand, 0x7904, 25, 40, -1, -1);

	this->BindObject(eNextEvent, 0x7903, 25, 40, -1, -1);
	this->BindObject(ePrevEvent, 0x7904, 25, 40, -1, -1);

	//downgrade options
	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		this->BindObject(eDragonLeft, 2337, 108.0, 45.0, 0.0, 384.1);
		this->BindObject(eDragonRight, 2336, 108.0, 45.0, 532.0, 384.1);
		this->BindObject(eParty, iNewParty, 25, 25, 348, 449);
		this->BindObject(eCharacter, iNewCharacter, 25, 25, 379, 449);
		this->BindObject(eInventory, iNewInventory, 25, 25, 409, 449);
		this->BindObject(eFriend, iNewWinpush, 52, 18, 581, 432);
		this->BindObject(eShop, iNewCashShop, 25, 25, 440, 449);

		this->BindObject(eOrelhinha, 0x700021, 16, 16, -10, 359);
		this->BindObject(eJanelinha, 0x700022, 16, 16, -10, 359);
		this->BindObject(eLuizinha, 0x700023, 16, 16, -10, 359);
		this->BindObject(ebtnWisper, 0x7A34, 15, 15, -10, 359);

		this->BindObject(eWhinCkeck, 31223, 5, 5, -10, 359);
		this->BindObject(eCheckBoxCommand, 0x700035, 11, 11, -10, 359);

		if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			this->BindObject(eCommandWindow, iNewFastMenu, 53, 19, 5, 432);
		}
		this->BindObject(eGuild, iNewGuild, 52, 18, 581, 454);
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		this->BindObject(eMainEx700Exp,      59000, 960, 160, 50, 394);
		this->BindObject(eMainEx700,      31293, 960, 165, 50, 415);
		this->BindObject(eShop1,          0x901, 17, 17, 76.5, 452);
		this->BindObject(eShop2,          0x902, 17, 17, 76.5, 452);
		this->BindObject(eCharacter1,     0x903, 17, 17, 98.5, 452);
		this->BindObject(eCharacter2,     0x904, 17, 17, 98.5, 452);
		this->BindObject(eInventory1,     0x905, 17, 17, 120.5, 452);
		this->BindObject(eInventory2,     0x906, 17, 17, 120.5, 452);
		this->BindObject(eQuest1,         0x907, 17, 17, 503.5, 452);
		this->BindObject(eQuest2,         0x908, 17, 17, 503.5, 452);
		this->BindObject(eCommunity1,     0x909, 17, 17, 525.5, 452);
		this->BindObject(eCommunity2,     0x910, 17, 17, 525.5, 452);
		this->BindObject(eSystem1,        0x911, 17, 17, 547.5, 452);
		this->BindObject(eSystem2,        0x912, 17, 17, 547.5, 452);
	    this->BindObject(ePetInvFrame, 0xF1003, 329.0f / resizeGuiRate, 640.0f / resizeGuiRate, 250, 50);
    	this->BindObject(eToolTip_ID, 0xF1004, 128 / resizeGuiRate, 8 / resizeGuiRate, 250, 50);
	    this->BindObject(eOption_I3, 0xF1005, 512 / resizeGuiRate, 128 / resizeGuiRate, 250, 50);
	    this->BindObject(eInventoryFrame_I4, 0xF1006, 1024, 512, 0, 0);
	    this->BindObject(ePopup_bg_big01, 0xF1007, 1024, 1024, 0, 0);
    	this->BindObject(eHuntRecord_I1, 0xF1008, 1024, 1024, 0, 0);
		this->BindObject(eMenu_MAIN, 0x7A5A, 222, 300, 205, -1);
		this->BindObject(eMenu_CLOSE, 81521, 59, 28, -1, -1);
		this->BindObject(eMenu_OPT1, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT2, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT3, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT4, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eMenu_OPT20, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eVip_SILVER, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eVip_GOLD, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eVip_BRONZE, 81522, 108, 30.5f, -1, -1);
		this->BindObject(eVip_PLATINUM, 81522, 108, 30.5f, -1, -1);
	}

	this->BindObject(eJEWELBANK_CLOSE, 71555, 19, 19, -1, -1);

	this->BindObject(eSELECTCHAR_LEFT, 32342, 20, 23, -1, -1);
	this->BindObject(eSELECTCHAR_RIGHT, 32343, 20, 23, -1, -1);

	this->BindObject(eADVANCE_STAT_INFO, ex_INFO_2, 35, 30, -1, -1);

	this->BindObject(ButtonStartAttack, 31593, 15, 15, -15, -15);
	this->BindObject(ButtonSettings, 31761, 18, 13.3, -1, -1);
	this->BindObject(ButtonStart, 31762, 18, 13.3, -1, -1);
	this->BindObject(ButtonStop, 31763, 18, 13.3, -1, -1);

///MuunSystem
	this->BindObject(eCONFIRM_MUUNBTN_OK, 0x7A5B, 54, 30, -1, -1);
	//this->BindObject(eCONFIRM_MUUN, 0x7A5B, 54, 30, -1, -1);
	this->BindObject(eCONFIRM_MUUNBTN_CANCEL, 0x7A5C, 54, 30, -1, -1);

	gAntiLagSystem.BindImage();
	gServerSwitch.BindImage();
	this->Data[eTIME].OnShow = false;

	teste=0;

	SetCompleteHook(0xFF, 0x00633FFB, &this->LoadModels);

	//==========================================
	// - Remove Texts PShop
	//==========================================
	//SetRange((LPVOID)0x00842086, 5, ASM::NOP);
	//SetRange((LPVOID)0x0084234F, 5, ASM::NOP);
	//SetRange((LPVOID)0x008423C3, 5, ASM::NOP);

	if(gProtect.m_MainInfo.InventoryAdvanced == 1 && gProtect.m_MainInfo.CustomInterfaceType <= 2)
	{
		SetRange((LPVOID)0x00835116, 5, ASM::NOP); // Main 1.04e
		SetOp((LPVOID)0x00835116, (LPVOID)DrawZenAndRud, ASM::CALL); // Main 1.04e
	}

	//SetDword(0x0D47384,(DWORD)40);
	//--
	//SetCompleteHook(0xE8, 0x00834682, this->PickItem);
	//SetCompleteHook(0xE8, 0x0083514C, this->NewSlotInventory);
	//--
	SetOp((LPVOID)oLoadSomeForm_Call, this->LoadImages, ASM::CALL);
	SetOp((LPVOID)oDrawInterface2_Call, this->Work2, ASM::CALL);
	SetOp((LPVOID)oDrawInterface_Call, this->Work, ASM::CALL);
	this->item_post_ = nullptr;

	if(gProtect.m_MainInfo.MultiCharacterEnable == 1)
	{
		SetCompleteHook(0xFF, 0x004D5EE6, &gSelectCharMulti.SelectChar);
		gSelectCharMulti.m_CharacterPage = 1;
	}

	SetCompleteHook(0xE8, 0x00772460, this->PopUpErrorCheckMsgBoxFunctionLoadImage); //	MessageBox Fix LoadBitMap
}

void Interface::PopUpErrorCheckMsgBoxFunctionLoadImage(const char* szErrorMsg, bool bForceDestroy)
{
	MessageBox(0, szErrorMsg, "", MB_OK);
	ExitProcess(0);
	PopUpErrorCheckMsg_Box(szErrorMsg, bForceDestroy);
}

void Interface::LoadModels()
{
	pLoadModel(406, "Data\\Custom\\Bmd\\VIP1\\", "musign", -1);
	pLoadTexture(406, "Custom\\Bmd\\VIP1\\", 0x2901, 0x2600, 1);
	pLoadModel(407, "Data\\Custom\\Bmd\\VIP2\\", "musign", -1);
	pLoadTexture(407, "Custom\\Bmd\\VIP2\\", 0x2901, 0x2600, 1);
	pLoadModel(408, "Data\\Custom\\Bmd\\VIP3\\", "musign", -1);
	pLoadTexture(408, "Custom\\Bmd\\VIP3\\", 0x2901, 0x2600, 1);
	// ----
	pInitModelData2();
}

void Interface::LoadImages()
{
	pLoadImage("Interface\\Rank01.tga", 0x7880, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank02.tga", 0x7881, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank03.tga", 0x7882, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank04.tga", 0x7883, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank05.tga", 0x7884, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank06.tga", 0x7885, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank07.tga", 0x7886, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank08.tga", 0x7887, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank09.tga", 0x7888, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank10.tga", 0x7889, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank11.tga", 0x7890, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank12.tga", 0x7891, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank13.tga", 0x7892, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank14.tga", 0x7893, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank15.tga", 0x7894, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank16.tga", 0x7895, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank17.tga", 0x7896, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank18.tga", 0x7897, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank19.tga", 0x7898, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank20.tga", 0x7899, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank21.tga", 0x7900, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Rank22.tga", 0x7901, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Ranking.tga", 0x7902, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Next.tga", 0x7903, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\Previous.tga", 0x7904, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\MU-logo.tga", 0x7905, 0x2601, 0x2901, 1, 0);
	
	pLoadImage("Logo\\MU-logo.tga", 31018, 0x2601, 0x2901, 1, 0);
	pLoadImage("Logo\\MU-logo_g.jpg", 31019, 0x2601, 0x2901, 1, 0);
	gLuckyWheel.LoadImages();
	//gCMacroUIEx.LoadImages();
	//-- itemtooltip
	pLoadImage("Interface\\GFx\\tooltip_bg01.tga", 61511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
	pLoadImage("Interface\\GFx\\tooltip_bg02.tga", 61512, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\tooltip_bg03.tga", 61513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
	pLoadImage("Interface\\GFx\\tooltip_bg04.tga", 61514, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\tooltip_bg06.tga", 61515, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\tooltip_bg07.tga", 61516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
	pLoadImage("Interface\\GFx\\tooltip_bg08.tga", 61517, 0x2601, 0x2901, 1, 0);
	pLoadImage("Interface\\GFx\\tooltip_bg09.tga", 61518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	pLoadImage("Interface\\item_money1.tga", 0x6860, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Interface\\item_money2.tga", 0x6861, GL_LINEAR, GL_REPEAT, 1, 0);
	pLoadImage("Interface\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);


	//pLoadImage("Custom\\Interface\\new_ui_lifebar.jpg", 0x787C, GL_LINEAR, GL_REPEAT, 1, 0);
	//pLoadImage("Custom\\Interface\\new_ui_lifebar_bg.jpg", 0x787D, GL_LINEAR, GL_REPEAT, 1, 0);

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		//gInterface.CLoadBitmapA("Interface\\Menu1.tga", 30982, 9729, 10497, 1, 0);
		pLoadImage("Interface\\Menu1.tga", 0x7906, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		//gInterface.CLoadBitmapA("Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		//gInterface.CLoadBitmapA("Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\Menu2.tga", 0x7906, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\Menu_BG.tga", 0x7907, 0x2601, 0x2901, 1, 0);
	}

	pLoadImage("Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);

	pLoadImage("Interface\\server_deco_all.tga", 88821, 9728, 10496,1,0);
	
	LoadBitmapA("Custom\\Interface\\button_ui_cancel.tga", 71555, GL_LINEAR, GL_CLAMP, 1, 0);
	//MiniMap
	pLoadImage("Custom\\Maps\\PlayerPoint.jpg", 31460, 0x2600, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\none.tga", 31461, 0x2601, 0x2900, 1, 0);
	//Downgrade
	pLoadImage("Logo\\0Account_new.tga", 35124, 0x2601, 0x2900, 1, 0);
	pLoadImage("Logo\\0On_Botton.jpg", 35125, 0x2601, 0x2900, 1, 0);
	pLoadImage("Logo\\0On_Botton2.jpg", 35126, 0x2601, 0x2900, 1, 0);
	//--
	pLoadImage("Custom\\Maps\\edBtUcx.tga", 31463, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\edBtUcx_1.tga", 31464, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\YYB6BUk.tga", 31465, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_blacksmith.tga", 31466, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Potion.tga", 31467, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_baul.tga", 31468, 0x2601, 0x2900, 1, 0); //-- Dungeon
	pLoadImage("Custom\\Maps\\mini_map_ui_Que.tga", 31469, 0x2601, 0x2900, 1, 0); //-- Dungeon

	pLoadImage("Interface\\mini_map_ui_party.tga", 61520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	pLoadImage("Interface\\mini_map_ui_mob.tga", 61521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha

	//newmenu
	pLoadImage("Custom\\Interface\\check.jpg", 0x9991, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\uncheck.jpg", 0x9992, 0x2601, 0x2900, 1, 0);
	pLoadImage("Custom\\Interface\\Button.tga", 0x7908, 0x2601, 0x2900,1,0);


	if(gProtect.m_MainInfo.SelectServerType == 0)
	{	
		pLoadImage("Logo\\New_Login_Back01.jpg", 500021, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Logo\\New_Login_Back02.jpg", 500022, GL_LINEAR, GL_REPEAT, 1, 0);
	}
	
	if(gProtect.m_MainInfo.SelectServerType == 1)
	{		
		LoadBitmapA("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);	
		LoadBitmapA("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);	
	}

	if(gProtect.m_MainInfo.SelectServerType == 2)
	{
		pLoadImage("Custom\\InterfaceS2\\Login_Back01.jpg", 500021, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Custom\\InterfaceS2\\Login_Back02.jpg", 500022, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Custom\\InterfaceS2\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Custom\\InterfaceS2\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	if(gProtect.m_MainInfo.SelectServerType == 3 || gProtect.m_MainInfo.SelectServerType == 5)
	{
		pLoadImage("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);	
		pLoadImage("Effect\\magic_ground1_3.jpg", 32779, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	
	if(gProtect.m_MainInfo.SelectCharacterType == 2)
	{
		pLoadImage("Custom\\InterfaceS2\\character_back01.jpg", 0x700025, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\character_back02.jpg", 0x700026, GL_LINEAR, GL_REPEAT, 1, 0);
	}

	if(gProtect.m_MainInfo.SelectCharacterType == 1)
	{
		pLoadImage("Custom\\InterfaceS2\\character_back01.jpg", 0x700025, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\character_back02.jpg", 0x700026, GL_LINEAR, GL_REPEAT, 1, 0);
		
		if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 1)
		{
			//-- Select Char button delete
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Delete01.tga", 88000, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Delete02.jpg", 88001, GL_LINEAR, GL_CLAMP, 1, 0);
			//-- interface
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Interface01.tga", 88002, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Interface02.tga", 88003, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Interface03.tga", 88004, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Interface04.tga", 88005, GL_LINEAR, GL_CLAMP, 1, 0);
			pLoadImage("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
			//--
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character_Cancel.jpg", 88006, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character_Ok.jpg", 88007, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character001.jpg", 88008, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character01.tga", 88009, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character002.jpg", 88010, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character02.tga", 88011, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character003.jpg", 88012, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character004.jpg", 88013, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character201.tga", 88014, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character202.jpg", 88015, GL_LINEAR, GL_CLAMP, 1, 0);
			//--
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Ok01.tga", 88016, GL_LINEAR, GL_CLAMP, 1, 0); //-- SD
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Ok02.jpg", 88017, GL_LINEAR, GL_CLAMP, 1, 0); //-- SD
		}
		if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
		{
			//pra 97d
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Delete011.tga", 88000, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Ok011.tga", 88016, GL_LINEAR, GL_CLAMP, 1, 0); //-- SD
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character211.tga", 88014, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character212.jpg", 88015, GL_LINEAR, GL_CLAMP, 1, 0);
			pLoadImage("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Interface012.tga", 88003, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Interface013.tga", 88004, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character97_Cancel.jpg", 88006, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character97_Ok.jpg", 88007, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Delete021.jpg", 88001, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\Ok021.jpg", 88017, GL_LINEAR, GL_CLAMP, 1, 0); //-- SD
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character001.jpg", 88008, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character011.tga", 88009, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character002.jpg", 88010, GL_LINEAR, GL_CLAMP, 1, 0);
			LoadBitmapA("Custom\\InterfaceS2\\Logo\\New_Character021.tga", 88011, GL_LINEAR, GL_CLAMP, 1, 0);
			pLoadImage("Custom\\InterfaceS2\\Layout.tga", 51523, 0x2601, 0x2901, 1, 0);
		}
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		pLoadImage("Custom\\Message_box.jpg", 79324, 0x2601, 0x2901, 1, 0);	//lateral party
	}

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		pLoadImage("Custom\\PartyLat.jpg", 79124, 0x2601, 0x2901, 1, 0);	//lateral party
		pLoadImage("Custom\\PartyFrame.jpg", 79125, 0x2601, 0x2901, 1, 0);	//cima baixo party
		pLoadImage("Custom\\PartyProgress.tga", 79126, 0x2601, 0x2901, 1, 0);	//barra de trás
		pLoadImage("Custom\\InterfaceS2\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Item_Back01.tga", 51533, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\nis_vframe.jpg", 51551, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\nis_rsframe.tga", 51552, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\nis_rsframe_up.jpg", 51553, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\nis_rsframe_m.jpg", 51554, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\nis_rsframe_down.jpg", 51555, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\nis_hframe.jpg", 31275, 9729, 10496, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\dialogue1.tga", 51530, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\dialogue2.tga", 51531, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\dialogue2_1.jpg", 51532, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\btnChatOn.jpg", 0x700021, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\btnWinSize.jpg", 0x700022, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\chat\\btnAlpha.jpg", 0x700023, GL_LINEAR, GL_CLAMP, 1, 0);
		//downgrade options season 2
		pLoadImage("Custom\\InterfaceS2\\TimeBar.tga", 0x787F, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\DragonRight.tga", 2336, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\DragonLeft.tga", 2337, GL_LINEAR, GL_CLAMP, 1, 0);

		pLoadImage("Custom\\InterfaceS2\\CheckBoxCommand.jpg", 0x700035, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Interface\\win_check.tga", 31223, GL_LINEAR, GL_CLAMP, 1, 0);
			
		//----------------------------------------------------------------
		if(gProtect.m_MainInfo.CustomInterfaceType == 1)
		{
			pLoadImage("Custom\\InterfaceS2\\Menu_left97.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			pLoadImage("Custom\\InterfaceS2\\none.tga", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
			pLoadImage("Custom\\InterfaceS2\\Menu_right97.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		}
		else if(gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			pLoadImage("Custom\\InterfaceS2\\Menu_left.jpg", 31292, GL_LINEAR, GL_CLAMP, 1, 0); //replace
			pLoadImage("Custom\\InterfaceS2\\Menu_SD.jpg", 31300, GL_LINEAR, GL_CLAMP, 1, 0);
			pLoadImage("Custom\\InterfaceS2\\Menu_right.jpg", 31294, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		}
	
		pLoadImage("Custom\\InterfaceS2\\Menu_middle.jpg", 31293, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		//--
		pLoadImage("Custom\\InterfaceS2\\Menu_AG.jpg", 31299, GL_LINEAR, GL_CLAMP, 1, 0);
		//--
		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_fastmenu.jpg", iNewFastMenu, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\none.tga", 31295, GL_LINEAR, GL_CLAMP, 1, 0); //replace
		pLoadImage("Custom\\InterfaceS2\\Menu_Red.jpg", 0x7A42, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		pLoadImage("Custom\\InterfaceS2\\Menu_Green.jpg", 0x7A41, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		pLoadImage("Custom\\InterfaceS2\\Menu_Blue.jpg", 0x7A40, GL_LINEAR, GL_CLAMP, 1, 0);//replace
		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_Inventory.jpg", iNewInventory, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_Character.jpg", iNewCharacter, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_Party.jpg", iNewParty, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_friend.jpg", iNewWinpush, GL_LINEAR, GL_CLAMP, 1, 0);	
		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_CashShop.jpg", iNewCashShop, GL_LINEAR, GL_CLAMP, 1, 0);

		pLoadImage("Custom\\InterfaceS2\\Boton\\Menu_guild.jpg", iNewGuild, GL_LINEAR, GL_CLAMP, 1, 0);
		//-------------------------------------
		pLoadImage("Custom\\InterfaceS2\\newui_skill.jpg", 31308, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\newui_skill2.jpg", 31309, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\newui_skill3.jpg", 31311, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\newui_command.jpg", 31310, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\newui_non_skill.jpg", 31314, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\newui_non_skill2.jpg", 31315, GL_LINEAR, GL_CLAMP, 1, 0); 
		pLoadImage("Custom\\InterfaceS2\\newui_non_skill3.jpg", 31317, GL_LINEAR, GL_CLAMP, 1, 0); 
		//-------------------------------------
		pLoadImage("Custom\\InterfaceS2\\newui_skillbox.jpg", 31312, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\newui_skillbox2.jpg", 31313, GL_LINEAR, GL_CLAMP, 1, 0);
		//-------------------------------------
		//InterfaceMenu S3
		pLoadImage("Custom\\InterfaceS2\\Menu\\ePointback.jpg", 0x700020, 0x2601, 0x2901, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Menu\\Stats.jpg", 31352, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Menu\\StatsDL.jpg", 51291, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Menu\\Stats2.jpg", 51292, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Menu\\Level_box.jpg", 35353, GL_LINEAR, GL_CLAMP, 1, 0);
		pLoadImage("Custom\\InterfaceS2\\Menu\\Level_button.jpg", 51290, GL_LINEAR, GL_CLAMP, 1, 0);
	}
		//pLoadImage("Custom\\ViewItem_Back.tga", 41022, 0x2601, 0x2901, 1, 0);
	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		pLoadImage("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
		LoadBitmapA("Interface\\GFx\\skill_render.tga", 61546, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\item_pbtnbg.tga", 61547, GL_LINEAR, GL_CLAMP, 1, 0);
		gMuHelperS15.LoadImages();
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I1.tga", 71532, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_chainfo_btn_level.tga", 71533, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\CharacterInfoFrame_I2.tga", 71538, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Frame_I3.tga", 71526, GL_LINEAR, GL_CLAMP, 1, 0); //-- All Window
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I4.tga", 71527, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I1.tga", 71522, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I2.tga", 71523, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\InventoryFrame_I3.tga", 71524, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\button_close.tga", 71529, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo.tga", 71535, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo_Small.tga", 81535, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ButtonCharacterInfo_VerySmall.tga", 81536, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newSytemButton.tga", 71542, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I1.tga", 71539, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\BaulFrame_I2.tga", 71540, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I1.tga", 71541, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\ShopFrame_I2.tga", 71543, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\StoreFrame_I1.tga", 71544, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I4.jpg", 71300, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_I5.jpg", 71299, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Exp.tga", 79000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\newui_number1.tga", 81337, 9729, 10496, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_1.tga", 71502, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp_green.tga", 71297, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_hp.tga", 71298, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp.tga", 71296, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\guege_mp_1.tga", 71501, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE.tga", 71293, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Main_IE_Buttons.tga", 81000, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("Interface\\GFx\\ex700\\Draw_money.tga", 81528, GL_LINEAR, GL_CLAMP, 1, 0);

		//jcbox
		pLoadImage("Interface\\GFx\\ex700\\Render_buttom_1.tga", 81521, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
		pLoadImage("Interface\\GFx\\ex700\\Render_buttom_2.tga", 81522, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
		pLoadImage("Interface\\GFx\\ex700\\Render_buttom_3.tga", 81524, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
		pLoadImage("Interface\\GFx\\ex700\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
		pLoadImage("Interface\\GFx\\ex700\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\ex700\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\ex700\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\ex700\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
		
		gGFxLoadImages.LoadImages();
	}
		pLoadImage("Interface\\GFx\\ex700\\popup_line_s.tga", 71520, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
		pLoadImage("Interface\\GFx\\ex700\\popupbg01.tga", 71511, 0x2601, 0x2901, 1, 0); //esquina arriba izquierda
		pLoadImage("Interface\\GFx\\ex700\\popupbg02.tga", 71512, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg03.tga", 71513, 0x2601, 0x2901, 1, 0); //esquina arriba derecha
		pLoadImage("Interface\\GFx\\ex700\\popupbg04.tga", 71514, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg06.tga", 71515, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg07.tga", 71516, 0x2601, 0x2901, 1, 0); //esquina abajo izquierda
		pLoadImage("Interface\\GFx\\ex700\\popupbg08.tga", 71517, 0x2601, 0x2901, 1, 0);
		pLoadImage("Interface\\GFx\\ex700\\popupbg09.tga", 71518, 0x2601, 0x2901, 1, 0); //esquina abajo derecha
	if (gProtect.m_MainInfo.SelectCharacterType == 4 && gProtect.m_MainInfo.SelectServerType == 4)
	{
		pLoadImage("Logo\\sos3sky01.jpg", 531013, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\sos3sky02.jpg", 531014, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\New_Login_Back01.jpg", 531011, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\New_Login_Back02.jpg", 531012, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);
		pLoadImage("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);
		LoadBitmapA("World78\\bg_b_08.jpg", 532029, GL_LINEAR, GL_CLAMP, 1, 0);
		LoadBitmapA("World78\\bg_b_05.jpg", 532028, GL_LINEAR, GL_CLAMP, 1, 0);
	}

	gCloak.LoadTexture();

	pLoadSomeForm();
}

void Interface::BindObject(short MonsterID, DWORD ModelID, float Width, float Height, float X, float Y)
{
	this->Data[MonsterID].EventTick	= 0;
	this->Data[MonsterID].OnClick	= false;
	this->Data[MonsterID].OnShow	= false;
	this->Data[MonsterID].ModelID	= ModelID;
	this->Data[MonsterID].Width		= Width;
	this->Data[MonsterID].Height	= Height;
	this->Data[MonsterID].X			= X;
	this->Data[MonsterID].Y			= Y;
	this->Data[MonsterID].MaxX		= X + Width;
	this->Data[MonsterID].MaxY		= Y + Height;
	this->Data[MonsterID].Attribute	= 0;
}

void Interface::DrawGUI(short ObjectID, float PosX, float PosY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawIMG(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= PosX;
		this->Data[ObjectID].Y		= PosY;
		this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;
	}

	pDrawImage(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height,0,0,ScaleX,ScaleY,1,1,0);
}

void Interface::ResetDrawIMG(short ObjectID)
{
	if( this->Data[ObjectID].X != -1 || this->Data[ObjectID].Y != -1 )
	{
		this->Data[ObjectID].X		= -1;
		this->Data[ObjectID].Y		= -1;
		this->Data[ObjectID].MaxX	= -1;
		this->Data[ObjectID].MaxY	= -1;
	}
}

void DebugCamera()
{
		char Info[100];
		wsprintf(Info, "X: %d", pCursorX);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
		pDrawText(pTextThis(), 100, 245, Info, 35, 0, (LPINT)3, 0);

		char Info2[100];
		wsprintf(Info2, "Y: %d", pCursorY);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
		pDrawText(pTextThis(), 100, 235, Info2, 35, 0, (LPINT)3, 0);
}

void Interface::Work()
{
	gObjUser.Refresh();

	//DebugCamera();

	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		if(gObjUser.lpViewPlayer->WeaponFirstSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponFirstSlot <= ITEM2(4,255)
		||gObjUser.lpViewPlayer->WeaponSecondSlot >= ITEM2(4,0) && gObjUser.lpViewPlayer->WeaponSecondSlot <= ITEM2(4,255))
		{
			gInterface.PetY = 38.0f;
		
		}
		else
		{
			gInterface.PetY = 26.0f;	
		}

		if(gObjUser.lpViewPlayer->PetSlot!= -1)
		{
			gInterface.PetX = 61.0f;
		}
		else
		{	
			gInterface.PetX = 0;
		}
	}

	//Close Cliente Force Fix
	if (*(int*)0x0E609E8 == 5 && (char*)*(DWORD*)(0x8128AC4)== NULL)
	{
		ExitProcess(0);
	}

	ReconnectMainProc();
	gInterface.DrawMenu();
	gInterface.CursorFocusWindows();
	VerifyWindow();
	gInterface.FixChaosMachine();
	g_PersonalShopEx.Draw();
	gInterface.DrawMiniMap();
	gAntiLagSystem.Draw();
	gServerSwitch.Draw();
	gBuyVip.Draw();
	gCustomEventTime.DrawEventTimePanelWindow();
	gCustomRanking.DrawRankPanelWindow();
	gCustomMenu.Draw();
	gCustomCommandInfo.DrawCommandWindow();
	gOffTrade.DrawOffTradeWindow();
	gInterface.DrawConfirmOpen();
	//DrawNewWindow();
	pDrawInterface();
	
	switch(gProtect.m_MainInfo.CustomInterfaceType)
	{
		case 1:
			gOptionsWindow.Load();
			gInterface.DrawInterfaceDragonLS3();
			gInterface.DrawInterfaceDragonRS3();
			gInterface.DrawInterface97Menu();
			gInterface.DrawInterfaceCustomS2();
			gOptionsWindow.Load();
			break;
		case 2:
			gInterface.DrawInterfaceDragonLS3();
			gInterface.DrawInterfaceDragonRS3();
			gInterface.DrawInterfaceS2Menu();
			gInterface.DrawInterfaceCustomS2();
			gOptionsWindow.Load();
			break;
		case 3:
			gInterface.DrawInterfaceCustom();
			gInterface.DrawTextX803();
			break;
	}


	if(gProtect.m_MainInfo.StatsAdvanced == 1 && gProtect.m_MainInfo.CustomInterfaceType <= 2)
	{
		g_StatsAdvance.DrawInfo();
	}

	if(gProtect.m_MainInfo.JewelBankSwitch == 1)
	{	
		if(gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			gJewelBank.DrawJewelBank803();
		}
		else
		{
			gJewelBank.DrawJewelBank();
		}
	}

	if(gProtect.m_MainInfo.LuckyWheelSwitch == 0)
	{
		if(gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			gLuckyWheel.DrawLuckyWheel803();
		}
		else
		{
			gLuckyWheel.DrawLuckyWheel();
		}
	}

	if( GetForegroundWindow() == pGameWindow )
	{
		if (GetKeyState(VK_SNAPSHOT) < 0) 
		{
			//gInterface.DrawLogo(1); 
		}

		//if(MountSize == 1)// Iury
		//{	
		//	//Horse SafeZone (Struct +14)
		//	SetByte(0x00502269+2,0);
		//	MemorySet(0x0054ECA3,0x90,0x6);
		//	MemorySet(0x0054FCEC,0x90,0x6);
		//
		//	//Dinorant e Uniria (Struct +14)
		//	SetByte(0x00502C4B+2,0);
		//	MemorySet(0x0054ED6D,0x90,0x6);
		//	MemorySet(0x0054FD5F,0x90,0x6);
		//	MemorySet(0x0054FE3E,0x90,0x6);
		//
		//	//Fenrir (Struct +14)
		//	SetByte(0x00501955+2,0);
		//	MemorySet(0x0054EAE1, 0x90, 0x06);//SetPlayerStop
		//	MemorySet(0x0054FC92, 0x90, 0x06);//SetPlayerWalk
		//}
		//
		//if(MountSize == 0)
		//{	
		//	//Horse 
		//	SetByte(0x00502269+2,1);
		//	//Fenrir
		//	SetByte(0x00501955+2,1);
		//	//Dinorant e Uniria
		//	SetByte(0x00502C4B+2,1);
		//	//All
		//	FenrirLoad();
		//}

		if (GetKeyState(VK_END) & 0x4000 && GetTickCount() >= gBuyVip.OpenTestDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gBuyVip.CheckTestWindow())
				{
					gBuyVip.Click = false;
					gBuyVip.CloseTestWindow();
				}
				else
				{
					gBuyVip.Click = true;
					gBuyVip.OpenTestWindow();
				}
				gBuyVip.OpenTestDelay = GetTickCount();
			}
		}

		//if (GetKeyState('S') & 0x4000 && GetTickCount() >= gStoreSearch.OpenStoreSearchDelay + 250)
		//{
		//	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
		//	{
		//		RegeditData(1);
		//		RESOLUTION = 800;
		//		FontHeight = 12;
		//		ChangeSize(0x320u, 600);
		//	}
		//}
		//
		//if (GetKeyState('K') & 0x4000 && GetTickCount() >= gStoreSearch.OpenStoreSearchDelay + 250)
		//{
		//	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
		//	{
		//		RegeditData(2);
		//		RESOLUTION = 1024;
		//		FontHeight = 14;
		//		ChangeSize(0x400u, 768);
		//	}
		//}
		//
		//if (GetKeyState('Y') & 0x4000 && GetTickCount() >= gStoreSearch.OpenStoreSearchDelay + 250)
		//{
		//	if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
		//	{
		//		RegeditData(3);
		//		RESOLUTION = 1360;
		//		FontHeight = 14;
		//		ChangeSize(0x550u, 768);
		//	}
		//}
		if(gProtect.m_MainInfo.m_ItemPositionSystem == 1)
		{
			if (GetKeyState('S') & 0x4000  && GetTickCount() >= g_PersonalShopEx.OpenStoreSearchDelay + 250)
			{
				if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
				{
					if (g_PersonalShopEx.CheckStoreWindow())
					{
						g_PersonalShopEx.CloseStoreWindow();
						pSetCursorFocus = false;
					}
					else
					{
						g_PersonalShopEx.OpenStoreWindow();
						pSetCursorFocus = true;
					}
					g_PersonalShopEx.OpenStoreSearchDelay = GetTickCount();
				}
			}
		}

		if (GetKeyState(VK_F6) & 0x4000 && GetTickCount() >= gAntiLagSystem.OpenTestDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gAntiLagSystem.CheckTestWindow())
				{
					gAntiLagSystem.Click = false;
					gAntiLagSystem.CloseTestWindow();
				}
				else
				{
					gAntiLagSystem.Click = true;
					gAntiLagSystem.OpenTestWindow();
				}
				gAntiLagSystem.OpenTestDelay = GetTickCount();
			}
		}

		if (GetKeyState('H') & 0x4000 && GetTickCount() >= gCustomEventTime.OpenTestDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gCustomEventTime.CheckTestWindow())
				{
					gCustomEventTime.CloseTestWindow();
				}
				else
				{
					gCustomEventTime.ClearCustomEventTime();

					PMSG_CUSTOM_EVENTTIME_SEND pMsg;

					pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));

					DataSend((BYTE*)&pMsg, pMsg.header.size);

					gCustomEventTime.OpenTestWindow();
				}
				gCustomEventTime.OpenTestDelay = GetTickCount();
			}
		}

	
		if (GetKeyState(VK_UP) & 0x4000) 
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				gInterface.OpenConfig(1);
			}
		}
		else if (GetKeyState(VK_DOWN) & 0x4000) 
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				gInterface.OpenConfig(1);
			}
		}
		if (gLuckyWheel.LuckyWheelActive == 1)
		{
			if (GetKeyState('L') & 0x4000 && GetTickCount() >= gLuckyWheel.OpenTestDelay + 250)
			{

				if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
				{
					if (gLuckyWheel.CheckTestWindow())
					{
						gLuckyWheel.CloseTestWindow();
					}
					else
					{
						gLuckyWheel.LuckyWheelState();
					}
					gLuckyWheel.OpenTestDelay = GetTickCount();
				}
			}
		}

		if(gProtect.m_MainInfo.CustomMenuType == 3)
		{
			if (GetKeyState('O') & 0x4000 && GetTickCount() >= gCustomMenu.OpenTestDelay + 250)
			{
				if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
				{
					if (gCustomMenu.CheckTestWindow())
					{
						gCustomMenu.CloseTestWindow();
					}
					else
					{
						gCustomMenu.OpenTestWindow();
					}
					gCustomMenu.OpenTestDelay = GetTickCount();
				}
			}
		}

		if (GetKeyState(VK_F8) & 0x4000 && GetTickCount() >= gCustomRanking.OpenTestDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gCustomRanking.CheckTestWindow())
				{
					gCustomRanking.CloseTestWindow();
				}
				else
				{
					gCustomRanking.ClearCustomRanking();

					gCustomRanking.RankingCount = 0;

					PMSG_CUSTOM_RANKING_COUNT_SEND pMsg1;

					pMsg1.header.set(0xF3, 0xE7, sizeof(pMsg1));

					DataSend((BYTE*)&pMsg1, pMsg1.header.size);

					PMSG_CUSTOM_RANKING_SEND pMsg;

					pMsg.header.set(0xF3, 0xE6, sizeof(pMsg));

					gCustomRanking.RankingType = 0;

					pMsg.type = 0;

					DataSend((BYTE*)&pMsg, pMsg.header.size);

					gCustomRanking.OpenTestWindow();
				}
				gCustomRanking.OpenTestDelay = GetTickCount();
			}
		}
		if (GetKeyState('J') & 0x4000  && GetTickCount() >= gJewelBank.OpenJewelBankDelay + 250)
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				if (gJewelBank.CheckJewelWindow())
				{
					gJewelBank.CloseJewelWindow();
					pSetCursorFocus = false;
				}
				else
				{
					gInterface.OpenWindow(ObjWindow::Inventory);
					gJewelBank.OpenJewelWindow();
					pSetCursorFocus = true;
				}
				gJewelBank.OpenJewelBankDelay = GetTickCount();
			}
		}

		if (gProtect.m_MainInfo.CustomInterfaceType <= 2)
		{
			if (GetKeyState('N') & 0x4000 && GetTickCount() >= gServerSwitch.OpenTestDelay + 250)
			{
				if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
				{
					if (gServerSwitch.CheckTestWindow())
					{
						gServerSwitch.Click = false;
						gServerSwitch.CloseTestWindow();
					}
					else
					{
						gServerSwitch.Click = true;
						gServerSwitch.OpenTestWindow();
					}
					gServerSwitch.OpenTestDelay = GetTickCount();
				}
			}
		}

		if (GetKeyState(VK_F7) & 0x4000) 
		{
			if (GetForegroundWindow() == pGameWindow && !gInterface.CheckWindow(ObjWindow::ChatWindow))
			{
				gInterface.SwitchMiniMap();
			}
		}

	if (GetKeyState(VK_F10) & 0x4000) 
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.Toggle();
		}

	if (GetKeyState(VK_F11) & 0x4000) 
		if(GetForegroundWindow() == *(HWND*)(MAIN_WINDOW))
		{
			gCamera.Restore();
		}

		if (GetKeyState(VK_ESCAPE) < 0) 
		{
			if (gCustomMenu.CheckTestWindow())
			{
				gCustomMenu.CloseTestWindow();
			}
			if (gCustomRanking.CheckTestWindow())
			{
				gCustomRanking.CloseTestWindow();
			}
			if (gBuyVip.CheckTestWindow())
			{
				gBuyVip.CloseTestWindow();
			}
			if (gCustomEventTime.CheckTestWindow())
			{
				gCustomEventTime.CloseTestWindow();
			}
			if (gServerSwitch.CheckTestWindow())
			{
				gServerSwitch.CloseTestWindow();
			}
			if (gJewelBank.CheckJewelWindow())
			{
				gJewelBank.CloseJewelWindow();
			}
			if (gCustomCommandInfo.CheckTestWindow())
			{
				gCustomCommandInfo.CloseTestWindow();
			}
			if (g_PersonalShopEx.CheckStoreWindow())
			{
				g_PersonalShopEx.CloseStoreWindow();
			}
			if(SEASON3B::setStatusDetails)
			{
				SEASON3B::setStatusDetails(false);
			}
			if (gAntiLagSystem.CheckTestWindow())
			{
				gAntiLagSystem.CloseTestWindow();
			}
		}
	}

}

void Interface::DrawTimeUI()
{
	if (!this->Data[eTIME].OnShow)
	{
		return;
	}
	// ----
	if (this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree)
		|| this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::ChatWindow) || this->CheckWindow(FullMap))
	{
		return;
	}
	// ----
	this->DrawGUI(eTIME, 0.0f, 412.0f);
	// -----
	time_t TimeLocal;
	struct tm * LocalT;
	time(&TimeLocal);
	LocalT = localtime(&TimeLocal);
	char LocalTime[30];
	sprintf(LocalTime, "%2d:%02d:%02d", LocalT->tm_hour, LocalT->tm_min, LocalT->tm_sec);
	this->DrawFormat(eWhite, 27.0f, 418.0f, 100.0f, 1.0f, LocalTime);
}

int Interface::DrawFormat(DWORD Color, int PosX, int PosY, int Width, int Align, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff)-1;
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	int LineCount = 0;
	
	char * Line = strtok(Buff, "\n");
	
	while( Line != NULL )
	{
		pDrawColorText(Line, PosX, PosY, Width, 0, Color, 0, Align);
		PosY += 10;
		Line = strtok(NULL, "\n");
	}
	
	return PosY;
}

bool Interface::CheckWindow(int WindowID)
{
	return pCheckWindow(pWindowThis(), WindowID);
}
int Interface::CloseWindow(int WindowID)
{
	return pCloseWindow(pWindowThis(), WindowID);
}
int Interface::OpenWindow(int WindowID)
{
	return pOpenWindow(pWindowThis(), WindowID);
}

bool Interface::IsWorkZone(short ObjectID)
{
	if( (gObjUser.m_CursorX < this->Data[ObjectID].X || gObjUser.m_CursorX > this->Data[ObjectID].MaxX) || (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY) )
		return false;

	return true;
}

bool Interface::IsWorkZone2(float X, float Y, float MaxX, float MaxY, bool a5)
{
	if (a5) 
	{
		if ((pCursorX < X || pCursorX > X + MaxX) || (pCursorY < Y || pCursorY > Y + MaxY))
			return false;
		return true;
	}
	if ((pCursorX < X || pCursorX > MaxX) || (pCursorY < Y || pCursorY > MaxY))
		return false;
	return true;
}

bool Interface::IsWorkZone3(short ObjectID)
{
	float PosX = this->Data[ObjectID].X;
	float MaxX = PosX + this->Data[ObjectID].Width;
	// ----
	if( (gObjUser.m_CursorX < PosX || gObjUser.m_CursorX > MaxX) 
		|| (gObjUser.m_CursorY < this->Data[ObjectID].Y || gObjUser.m_CursorY > this->Data[ObjectID].MaxY) )
	{
		return false;
	}
	// ----
	return true;
}

float Interface::GetResizeX(short ObjectID)
{
	if( pWinWidth == 800 )
	{
		return this->Data[ObjectID].X + 16.0;
	}
	else if( pWinWidth != 1024 )
	{
		return this->Data[ObjectID].X - 16.0;
	}
	
	return this->Data[ObjectID].X;
}

int Interface::DrawToolTip(int X, int Y, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	
	return pDrawToolTip(X, Y, Buff);
}

int Interface::DrawMessage(int Mode, LPCSTR Text, ...)
{
	char Buff[2048];
	int BuffLen	= sizeof(Buff);
	ZeroMemory(Buff, BuffLen);
	// ----
	va_list args;
	va_start(args, Text);
	int Len	= vsprintf_s(Buff, BuffLen, Text, args);
	va_end(args);
	// ----
	return pDrawMessage(Buff, Mode);
}

float Interface::DrawRepeatGUI(short MonsterID, float X, float Y, int Count)
{
	float StartY = Y;
	// ----
	for( int i = 0; i < Count; i++ )
	{
		pDrawGUI(this->Data[MonsterID].ModelID, X, StartY,
			this->Data[MonsterID].Width, this->Data[MonsterID].Height);
		// ----
		StartY += this->Data[MonsterID].Height;
	}
	// ----
	return StartY;
}

void Interface::DrawButton(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	if (this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1)
	{
		this->Data[ObjectID].X = PosX;
		this->Data[ObjectID].Y = PosY;
		this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	}
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}


void Interface::DrawColoredGUI(short ObjectID, float X, float Y, DWORD Color)
{
	if( this->Data[ObjectID].X == -1 || this->Data[ObjectID].Y == -1 )
	{
		this->Data[ObjectID].X		= X;
		this->Data[ObjectID].Y		= Y;
		this->Data[ObjectID].MaxX	= X + this->Data[ObjectID].Width;
		this->Data[ObjectID].MaxY	= Y + this->Data[ObjectID].Height;
	}
	// ----
	pDrawColorButton(this->Data[ObjectID].ModelID, X, Y, 
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, 0, 0, Color);
}

void Interface::DrawLogo(bool active)
{
	if (gProtect.m_MainInfo.PrintLogo != 0)
	{

		if (active == 1)
		{
			this->Data[eLogo].EventTick = GetTickCount()+1500;
		}

		if (gInterface.Data[eLogo].EventTick > GetTickCount())
		{
			if (gProtect.m_MainInfo.PrintLogo == 1)
			{
				this->DrawGUI(eLogo, 10, 10);
			}

			if (gProtect.m_MainInfo.PrintLogo == 2)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, 10);

			}

			if (gProtect.m_MainInfo.PrintLogo == 3)
			{
				this->DrawGUI(eLogo, 10, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 4)
			{
				this->DrawGUI(eLogo, MAX_WIN_WIDTH - 160, MAX_WIN_HEIGHT - 144);
			}

			if (gProtect.m_MainInfo.PrintLogo == 5)
			{
				this->DrawGUI(eLogo, (MAX_WIN_WIDTH/2)-(150/2), (MAX_WIN_HEIGHT/2)-(114/2));
			}
		}
	}
}

void Interface::DrawMenu()
{
	if (gProtect.m_MainInfo.CustomMenuSwitch != 1)
	{
		return;
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 3)
	{
		return;
	}

	//if (this->Data[eMenu].OnShow)
	//{
	//	this->Data[eMenu].OnShow = false;
	//}

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}
	
	this->Data[eMenu].OnShow = true;

	if (gProtect.m_MainInfo.CustomMenuType == 1)
	{
		this->DrawGUI(eMenu, 3, 72);
	}
	else if(gProtect.m_MainInfo.CustomMenuType == 2)
	{
		float PosX = this->GetResizeX(eMenuBG);

		this->DrawGUI(eMenuBG, PosX, 0);

		this->DrawGUI(eMenu, PosX + 1, 2);

		if (IsWorkZone(eMenu))
		{
			this->DrawToolTip(PosX + 1 - 5, 25, "Especial Menu");
			// ----
			if (this->Data[eMenu].OnClick)
			{
				this->DrawColoredGUI(eMenu, PosX + 1, 2, pMakeColor(40, 20, 3, 130));
				return;
			}
			// ----
			this->DrawColoredGUI(eMenu, PosX + 1, 2, pMakeColor(255, 204, 20, 200));
		}
	}

}

bool Interface::EventDrawMenu_Open(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu].EventTick);
	// ----
	if (!this->Data[eMenu].OnShow || !IsWorkZone(eMenu))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		pSetCursorFocus = true;
		this->Data[eMenu].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	
	// ----
	this->Data[eMenu].EventTick = GetTickCount();
	
	if (gCustomMenu.CheckTestWindow())
	{
		gCustomMenu.CloseTestWindow();
	}
	else
	{
		gCustomMenu.OpenTestWindow();
	}
	// ----
	return false;
}
// ----------------------------------------------------------------------------------------------
bool Interface::EventDrawMenu_Op1(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT1].EventTick);
	// ----
	if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_OPT1))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT1].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT1].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT1].EventTick = GetTickCount();

	gCustomMenu.CloseTestWindow();

	if (gCustomEventTime.CheckTestWindow())
	{
		gCustomEventTime.CloseTestWindow();
	}
	else
	{
		gCustomEventTime.ClearCustomEventTime();

		PMSG_CUSTOM_EVENTTIME_SEND pMsg;

		pMsg.header.set(0xF3, 0xE8, sizeof(pMsg));

		DataSend((BYTE*)&pMsg, pMsg.header.size);

		gCustomEventTime.OpenTestWindow();
	}
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op2(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT2].EventTick);
	// ----
	if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_OPT2))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT2].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT2].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT2].EventTick = GetTickCount();

	gCustomMenu.CloseTestWindow();

	gBuyVip.OpenTestWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op3(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT3].EventTick);
	// ----
	if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_OPT3))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT3].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT3].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT3].EventTick = GetTickCount();

	gCustomMenu.CloseTestWindow();

	gCustomRanking.OpenWindow();
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op4(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT4].EventTick);
	// ----
	if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_OPT4))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT4].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT4].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT4].EventTick = GetTickCount();

	gCustomMenu.CloseTestWindow();

	if (gCustomCommandInfo.CheckTestWindow())
	{
		gCustomCommandInfo.CloseTestWindow();
	}
	else
	{
		gCustomCommandInfo.OpenTestWindow();
	}
	// ----
	return false;
}

bool Interface::EventDrawMenu_Op6(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT6].EventTick);
	if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_OPT6)){
		return false;
	}
	if (Event == WM_LBUTTONDOWN){
		this->Data[eMenu_OPT6].OnClick = true;
		return true;
	}
	this->Data[eMenu_OPT6].OnClick = false;;
	if (Delay < 500){
		return false;
	}
	this->Data[eMenu_OPT6].EventTick = GetTickCount();
	gCustomMenu.CloseTestWindow();
	gLuckyWheel.LuckyWheelState();
	return false;
}

bool Interface::EventDrawMenu_Op20(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eMenu_OPT20].EventTick);
	// ----
	if (!this->Data[eADDPOINT5_MAIN].OnShow || !IsWorkZone(eMenu_OPT20))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eMenu_OPT20].OnClick = true;
		return true;
	}
	// ----
	this->Data[eMenu_OPT20].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eMenu_OPT20].EventTick = GetTickCount();

	gCustomMenu.CloseTestWindow();

	this->OpenWindow(ObjWindow::Options);
	// ----
	return false;
}

bool Interface::MiniMapCheck()
{
	if (this->CheckWindow(Inventory) ||
		this->CheckWindow(CashShop) ||
		this->CheckWindow(ChaosBox) ||
		this->CheckWindow(CommandWindow) ||
		this->CheckWindow(ExpandInventory) ||
		this->CheckWindow(ExpandWarehouse) ||
		this->CheckWindow(FullMap) ||
		this->CheckWindow(GensInfo) ||
		this->CheckWindow(Guild) ||
		this->CheckWindow(NPC_Dialog) ||
		this->CheckWindow(NPC_Julia) ||
		this->CheckWindow(NPC_Titus) ||
		this->CheckWindow(OtherStore) ||
		this->CheckWindow(Party) ||
		this->CheckWindow(PetInfo) ||
		this->CheckWindow(Shop) ||
		this->CheckWindow(SkillTree) ||
		this->CheckWindow(Store) ||
		this->CheckWindow(Trade) ||
		this->CheckWindow(FriendList) ||
		this->CheckWindow(FastMenu) ||
		this->CheckWindow(MuHelper) ||
		this->CheckWindow(Quest) ||
		this->CheckWindow(Lugard) ||
		this->CheckWindow(Jerint) ||
		this->CheckWindow(GoldenArcher1) ||
		this->CheckWindow(GoldenArcher2) ||
		this->CheckWindow(LuckyCoin1) ||
		this->CheckWindow(LuckyCoin2) ||
		this->CheckWindow(NPC_Duel) ||
		this->CheckWindow(NPC_Devin) ||
		this->CheckWindow(GuardNPC) ||
		this->CheckWindow(SeniorNPC) ||
		this->CheckWindow(GuardNPC2) ||
		this->CheckWindow(CastleGateSwitch) ||
		this->CheckWindow(CatapultNPC) ||
		this->CheckWindow(CreateGuild) ||
		this->CheckWindow(Warehouse))
		return true;
	return false;
}

bool Interface::CombinedChecks()
{
	if ((this->CheckWindow(Inventory)
		&& this->CheckWindow(ExpandInventory)
		&& this->CheckWindow(Store)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Warehouse)
		&& this->CheckWindow(ExpandWarehouse)) ||
		(this->CheckWindow(Inventory)
		&& this->CheckWindow(Character)
		&& this->CheckWindow(Store)))
		return true;
	return false;
}

bool Interface::CheckMap()
{
	switch(gObjUser.m_MapNumber)
	{
		case eMapNumber::Lorencia:
			return false;
			break;
		case eMapNumber::Dungeon:
			return false;
			break;
		case eMapNumber::Devias:
			return false;
			break;
		case eMapNumber::Noria:
			return false;
			break;
		case eMapNumber::LostTower:
			return false;
			break;
		case eMapNumber::Atlans:
			return false;
			break;
		case eMapNumber::Tarkan:
			return false;
			break;
		case eMapNumber::Elbeland:
			return false;
			break;
		case eMapNumber::Icarus:
			return false;
			break;
		case eMapNumber::Trials:
			return false;
			break;
		case eMapNumber::Aida:
			return false;
			break;
		case eMapNumber::Crywolf:
			return false;
			break;
		case eMapNumber::Kanturu1:
			return false;
			break;
		case eMapNumber::Kanturu3:
			return false;
			break;
		case eMapNumber::Barracks:
			return false;
			break;
		case eMapNumber::Calmness:
			return false;
			break;
		case eMapNumber::Raklion:
			return false;
			break;
		case eMapNumber::Vulcanus:
			return false;
			break;
		case eMapNumber::Karutan1:
			return false;
			break;
		case eMapNumber::Karutan2:
			return false;
			break;
		default:
			return true;
			break;
	}
}

void Interface::CloseCustomWindow()
{
	gCustomMenu.CloseTestWindow();
	gBuyVip.CloseTestWindow();
	this->Data[eADDPOINT3_MAIN].OnShow		= false;
	this->Data[eCommand_MAIN].OnShow		= false;
	pSetCursorFocus = false;
}

void Interface::DrawItem(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse)
{

	if (this->CheckWindow(ObjWindow::MoveList) || this->CheckWindow(ObjWindow::CashShop) || this->CheckWindow(ObjWindow::SkillTree) || this->CheckWindow(ObjWindow::FullMap)
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(ExpandInventory) 
		&& this->CheckWindow(Store)) 
		||  (this->CheckWindow(Inventory) 
		&& this->CheckWindow(Warehouse) 
		&& this->CheckWindow(ExpandWarehouse)) )
	{
		return;
	}

	pSetBlend(true);
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);

	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	if (ItemID == 406)
	{
		sub_6358A0_Addr(0.4, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else if (ItemID == 407)
	{
		sub_6358A0_Addr(0.5, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}
	else
	{
		sub_6358A0_Addr(0.7, v2, *(float*)0xE61E38, *(float*)0xE61E3C); //tamanho do bmd
	}

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0); 
	sub_635DE0_Addr();
	sub_635E40_Addr();

	//posX 
	//posY
	//Width
	//Height
	//unk
	// 1 - Excellent Effect
	// 1 - Aura +7
	// 1 - original size
	glClear(0x100);

	//pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	 // int v31 = pTest((double)PosY);
	  //int v32 = pTest((double)PosX);

	VAngle v45;

	unsigned __int8 v44 = 1; //0 = parado / 1 = girando

	sub_6359B0_Addr(PosX, PosY, (int)&v45, 0); //posição do bmd
	sub_5CA0D0_Addr(ItemID, Level, Excl, Anc, (int)&v45, v44, 0); //funão que mostra o BMD
	
	sub_636720_Addr();

	glMatrixMode(0x1700);
	glPopMatrix();
	glMatrixMode(0x1701);
	glPopMatrix();

	sub_637770_Addr();

	glColor3f(1,1,1);
	pSetBlend(false);
}

void Interface::DrawItem2(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse){
    glMatrixMode(0x1701);
    glPushMatrix();
    glLoadIdentity();
    sub_6363D0_Addr(0, 0, *(GLsizei*)0x00E61E58, *(GLsizei*)0x00E61E5C);
	float v2 = *(float*)0x00E61E58 / *(float*)0x00E61E5C;
    sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);
    glMatrixMode(0x1700);
    glPushMatrix();
    glLoadIdentity();
    sub_635830_Addr((LPVOID)0x87933A0);
    sub_635DE0_Addr();
    sub_635E40_Addr();
    pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
    testfunc();
    glColor3f(1,1,1);
    pSetBlend(false);
}

void Interface::DrawConfirmOpen()
{
	if (gProtect.m_MainInfo.CustomInterfaceType != 3)
	{
		if (!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
		{
			this->Data[eCONFIRM_MAIN].OnShow = false;
			pSetCursorFocus = false;
		}

		if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
		{
			this->Data[eCONFIRM_MAIN].OnShow = false;
			pSetCursorFocus = false;
		}

		if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
		{
			this->Data[eCONFIRM_MAIN].OnShow = false;
			pSetCursorFocus = false;
		}

		if (!this->Data[eCONFIRM_MAIN].OnShow)
		{
			return;
		}

		pSetCursorFocus = true;
		//this->Data[eCONFIRM_MAIN].EventTick = GetTickCount();

		float MainWidth = 230.0;
		float MainHeight = 130.0;
		float StartBody = 90.0;
		float StartY = 90.0;
		float StartX = 25;
		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);

		gInterface.DrawGUI(eCONFIRM_MAIN, StartX, StartY + (float)2.0);
		gInterface.DrawGUI(eVip_TITLE, StartX, StartY);
		StartY = gInterface.DrawRepeatGUI(eVip_FRAME, StartX, StartY + (float)5.0, 5);
		gInterface.DrawGUI(eVip_FOOTER, StartX, StartY);

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, 0);

		if (this->IsWorkZone(eCONFIRM_BTN_OK))
		{
			int ScaleY = 30;
			// ----
			if (this->Data[eCONFIRM_BTN_OK].OnClick)
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, ScaleY);
		}

		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, 0);

		if (this->IsWorkZone(eCONFIRM_BTN_CANCEL))
		{
			int ScaleY = 30;
			// ----
			if (this->Data[eCONFIRM_BTN_CANCEL].OnClick)
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, ScaleY);
		}
	}
	else
	{
		if (!this->CheckWindow(Shop) && this->Data[eCONFIRM_MAIN].OnShow == true)
		{
			this->Data[eCONFIRM_MAIN].OnShow = false;
		}

		if ((GetTickCount() - this->Data[eCONFIRM_BTN_OK].EventTick) < 100)
		{
			this->Data[eCONFIRM_MAIN].OnShow = false;
		}

		if ((GetTickCount() - this->Data[eCONFIRM_BTN_CANCEL].EventTick) < 100)
		{
			this->Data[eCONFIRM_MAIN].OnShow = false;
		}

		if (!this->Data[eCONFIRM_MAIN].OnShow)
		{
			return;
		}

		float StartX;
		if (gProtect.m_MainInfo.CustomInterfaceType == 3)
		{
			StartX = 205.0f;
		}
		else
		{
			StartX = 25.0f;
		}

		float MainWidth = 230.0;
		float MainHeight = 130.0;
		float StartBody = 90.0;
		float StartY = 90.0;

		float MainCenter = StartX + (MainWidth / 3);
		float ButtonX = MainCenter - (float)(29.0 / 2);

		gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(66));

		this->DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 40, 210, 3, gCustomMessage.GetMessage(67));

		this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, 0);

		if (this->IsWorkZone(eCONFIRM_BTN_OK))
		{
			int ScaleY = 30;
			// ----
			if (this->Data[eCONFIRM_BTN_OK].OnClick)
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_OK, (int)StartX + 40, (int)StartBody + 70, 0, ScaleY);
		}

		this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, 0);

		if (this->IsWorkZone(eCONFIRM_BTN_CANCEL))
		{
			int ScaleY = 30;
			// ----
			if (this->Data[eCONFIRM_BTN_CANCEL].OnClick)
			{
				ScaleY = 60;
			}
			// ----
			this->DrawButton(eCONFIRM_BTN_CANCEL, (int)StartX + 140, (int)StartBody + 70, 0, ScaleY);
		}
	}
}

bool Interface::EventConfirm_OK(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_OK].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_OK))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_OK].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_OK].EventTick = GetTickCount();

	PMSG_ITEM_BUY_RECV pMsg;

	pMsg.header.set(0xF3, 0xED,sizeof(pMsg));

	pMsg.slot = this->ConfirmSlot;

	DataSend((BYTE*)&pMsg,pMsg.header.size);

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

bool Interface::EventConfirm_CANCEL(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - this->Data[eCONFIRM_BTN_CANCEL].EventTick);
	// ----
	if (!this->Data[eCONFIRM_MAIN].OnShow || !IsWorkZone(eCONFIRM_BTN_CANCEL))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		this->Data[eCONFIRM_BTN_CANCEL].OnClick = true;
		return true;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].OnClick = false;;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	this->Data[eCONFIRM_BTN_CANCEL].EventTick = GetTickCount();

	this->Data[eCONFIRM_MAIN].OnShow = false;
	pSetCursorFocus = false;
	// ----
	return false;
}

//FUNÇÃO POSTITEM
void testfunc()
{
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
}

void Interface::DrawItemIMG(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	float x = PosX;
	float y = PosY;

	if(ItemID >= ITEM(0,0) && ItemID < ITEM(1,0))
	{
		x = PosX - 5;
		if(ItemID == ITEM(0,16) || ItemID == ITEM(0,19)) { y = PosY + 30; }
		else if((ItemID >= ITEM(0,32) && ItemID <= ITEM(0,35)) || gCustomGloves.CheckGloves(ItemID) == true) { y = PosY + 15; }
		else if(ItemID >= ITEM(0,15) && ItemID < ITEM(0,32)) { y = PosY + 25; }
		else if(ItemID > ITEM(0,35)) { y = PosY + 20; }
		else if(ItemID == ITEM(0,0)) { y = PosY + 30; }
		else { y = PosY + 20; }
	}
	else if(ItemID >= ITEM(3,0) && ItemID < ITEM(4,0))
	{ y = PosY + 30; }
	else if(ItemID >= ITEM(7,0) && ItemID < ITEM(8,0)) { y = PosY + 25; }
	else if(ItemID >= ITEM(8,0) && ItemID < ITEM(9,0))
	{
		if((ItemID >= ITEM(8,2) && ItemID <= ITEM(8,4)) 
			|| ItemID == ITEM(8,7) || ItemID == ITEM(8,8)
			|| ItemID == ITEM(8,15))
		{
			y = PosY + 20;
		}
		else if(ItemID == ITEM(8,34) || ItemID == ITEM(8,35)) { y = PosY + 25; }
		else if(ItemID <= ITEM(8,73)) { y = PosY + 25; }
		else if(ItemID > ITEM(8,73)) { y = PosY + 35;}
	}
	else if(ItemID >= ITEM(9,0) && ItemID < ITEM(12,0)){ y = PosY + 25; }
	else if(ItemID >= 2048)
	{
		y = PosY + 25;

		if(ItemID ==ITEM(12,40)) { y = PosY + 10; }
	}
	else { y = PosY + 20; }

	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr( 0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y );
	float v2 = *(float*) MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;

	sub_6358A0_Addr( 1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C );
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	sub_635830_Addr((LPVOID) 0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();
	pDrawItemModel(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse); 
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
	glColor4f((GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0,(GLfloat) 1.0);
	pSetBlend(false);
}

void Interface::DrawItemIMGBank(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();

	sub_6363D0_Addr(0, 0, *(GLsizei*)MAIN_RESOLUTION_X, *(GLsizei*)MAIN_RESOLUTION_Y);
	float v2 = *(float*)MAIN_RESOLUTION_X / *(float*)MAIN_RESOLUTION_Y;
	sub_6358A0_Addr(1.0, v2, *(float*)0xE61E38, *(float*)0xE61E3C);

	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();

	sub_635830_Addr((LPVOID)0x87933A0);
	sub_635DE0_Addr();
	sub_635E40_Addr();

	pDrawItemModel(PosX, PosY, Width, Height, ItemID, Level, Excl, Anc, OnMouse);

	testfunc();
	glColor3f(1, 1, 1);
	pSetBlend(false);
}

void Interface::Work2() 
{

	if(gProtect.m_MainInfo.HelperUpgradeSystem == 0){if (gInterface.item_post_ && pCursorX < 150){}}

	if(gProtect.m_MainInfo.m_FpsMonitor == 1)
	{
		gInterface.guiMonitore();
		gInterface.UPDATE_FPS();
	}

   pDrawInterface2();
}

void Interface::guiMonitore()
{
	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop))
	{
		return;
	}
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(590.0, 0.0, 180.0, 15.0, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

void Interface::UPDATE_FPS()
{
	gInterface.frameCount++;
	if (GetTickCount() - gInterface.lastReport >= 1000)
	{
		gInterface.frameRate = gInterface.frameCount / ((GetTickCount() - gInterface.lastReport) / 1000);
		sprintf(gInterface.FPS_REAL, "FPS: %d", gInterface.frameRate);
		gInterface.lastReport = GetTickCount();
		gInterface.frameCount = 0;
	}

	if (this->MiniMapCheck() || this->CombinedChecks() || this->CheckWindow(FullMap) || this->CheckWindow(FriendList) || this->CheckWindow(SkillTree) || this->CheckWindow(CashShop) )
	{
		return;
	}

	this->DrawFormat(eGold, 600, 3, 80, 1, gInterface.FPS_REAL);
}

void Interface::DrawChat ( int mode, char* character, char* message ) 
{
    PBMSG_CHATPOSTITEM chat;
    memset ( &chat.character_[0], 0, 10 );
    memset ( &chat.message_[0], 0, 89 );
    memcpy ( &chat.character_[0], &character[0], 10 );
    memcpy ( &chat.message_[0], &message[0], strlen ( message ) );
    pHandlePacketChatData ( &chat );

	if (mode >= 1 && mode <= 9 && ChatBoxMuObjectChatDataPtrArrayLength) 
	{
		int index = ChatBoxMuObjectChatDataPtrArrayLength - 1;
		ChatBoxMuObjectChatDataPtrArray[index]->chat_type_ = mode;
	}
}

void Interface::DrawItemToolTipText ( void * item, int x, int y ) {
		static DWORD mem = 0;
		//static DWORD ItemToolTipAdress1 = 0x00861110; //1.04D-> 0x00860FC0
		//static DWORD ItemToolTipAdress2 = 0x00861AA0; //1.04D-> 0x00861950
		//static DWORD ItemToolTipAdress3 = 0x007E3E30; //1.04D-> 0x007E3CE0
		_asm {
		    PUSH 0
		    PUSH 0
		    PUSH 0
		    PUSH item
		    PUSH y
		    PUSH x
			MOV mem,0x00861110
		    CALL mem
		    MOV ECX, EAX
			MOV mem,0x00861AA0
		    CALL mem
		    MOV ECX, EAX
			MOV mem,0x007E3E30
		    CALL mem
		}

}

void Interface::DrawZenAndRud(int a1, int a2, int a3, int a4)
{
	int v10; 
	int v11;
	DWORD v23;
	v10 = *(DWORD*)(a1 + 40);
	v11 = *(DWORD*)(a1 + 36);
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	*(float*)(0x00D24E88); //Width

	char MoneyBuff1[50], MoneyBuff2[50],MoneyBuff3[50], MoneyBuff4[50], test[50];
	ZeroMemory(MoneyBuff1, sizeof(MoneyBuff1));
	ZeroMemory(MoneyBuff2, sizeof(MoneyBuff2));
	ZeroMemory(MoneyBuff3, sizeof(MoneyBuff3));
	ZeroMemory(MoneyBuff4, sizeof(MoneyBuff4));

	pGetMoneyFormat(v23, MoneyBuff1, 0);
	pGetMoneyFormat(Coin3, MoneyBuff2, 0);
	pGetMoneyFormat(Coin1, MoneyBuff3, 0);
	pGetMoneyFormat(Coin2, MoneyBuff4, 0);

	gInterface.DrawFormat(eWhite190, v11, v10 + 12, 190, 3, pGetTextLine(pTextLineThis, 223));
        
		gInterface.DrawGUI(eMoney1, v11 + 14, v10 + 365);
		gInterface.DrawFormat(eBlack, v11 + 17, v10 + 369, 16, 1, gCustomMessage.GetMessage(50));
		gInterface.DrawFormat(eRed, v11 + 40, v10 + 368, 45, 3, "%s", MoneyBuff1);
		
		gInterface.DrawGUI(eMoney2, v11 + 103, v10 + 365);
		gInterface.DrawFormat(eBlack, v11 + 106, v10 + 368, 16, 1, gCustomMessage.GetMessage(53));
		gInterface.DrawFormat(eGold, v11 + 128, v10 + 368, 45, 4, "%s", MoneyBuff2);

		gInterface.DrawGUI(eMoney2, v11 + 14, v10 + 378);
		gInterface.DrawFormat(eBlack, v11 + 16, v10 + 381, 16, 1, gCustomMessage.GetMessage(51));
        gInterface.DrawFormat(eBlue, v11 + 38, v10 + 381, 45, 4, "%s", MoneyBuff3);

		gInterface.DrawGUI(eMoney2, v11 + 103, v10 + 378);
		gInterface.DrawFormat(eBlack, v11 + 105, v10 + 381, 16, 1, gCustomMessage.GetMessage(52));
        gInterface.DrawFormat(eWhite, v11 + 128, v10 + 381, 45, 4, "%s", MoneyBuff4);
		

	return;
}

void Interface::DrawGUI2(short ObjectID, float PosX, float PosY)
{
	this->Data[ObjectID].X		= PosX;
	this->Data[ObjectID].Y		= PosY;
	this->Data[ObjectID].MaxX	= PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY	= PosY + this->Data[ObjectID].Height;

	pDrawGUI(this->Data[ObjectID].ModelID, PosX, PosY,this->Data[ObjectID].Width, this->Data[ObjectID].Height);
}

void Interface::DrawButton2(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::DrawWindow(int ObjMain, int ObjTitle, int ObjFrame, int ObjFooter, int Repeat, float X, float Y, char* Text)
{
	float StartY = Y;
	float StartX = X;

	gInterface.DrawGUI(ObjMain, StartX, StartY + 2);
	gInterface.DrawGUI(ObjTitle, StartX, StartY);
	StartY = gInterface.DrawRepeatGUI(ObjFrame, StartX, StartY + 40.0, Repeat);
	gInterface.DrawGUI(ObjFooter, StartX, StartY);
	gInterface.DrawFormat(eGold, StartX + 10, Y + 10, 210, 3, Text);
}

void Interface::SwitchMiniMap()
{
	if((GetTickCount() - gInterface.Data[eNULL_MAP].EventTick) < 1000 ||this->CheckWindow(ChatWindow))
    {
        return;
    }

	gInterface.Data[eNULL_MAP].EventTick = GetTickCount();

	if (MiniMap != 0)
    {
        MiniMap = 0;
    }
    else 
    {
        MiniMap = 1;
    }
}

void Interface::DrawBarForm(float PosX, float PosY, float Width, float Height, GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
	pDrawBarForm(PosX, PosY, Width, Height, 0.0f, 0);
	pGLSwitchBlend();
	pGLSwitch();
	glColor3f(1.0, 1.0, 1.0);
	pSetBlend(false);
}

//downgrade
void Interface::DrawInterfaceDragonLS3()
{
	if(this->CheckWindow(ObjWindow::CashShop)|| this->CheckWindow(ObjWindow::FullMap) || this->CheckWindow(ObjWindow::SkillTree))
	{
		return;
	}
		this->DrawGUI(eDragonLeft, this->Data[eDragonLeft].X, this->Data[eDragonLeft].Y);
}

void Interface::DrawInterfaceDragonRS3()
{	
	if (this->CheckWindow(ObjWindow::FriendList) || this->CheckWindow(ObjWindow::Party) || this->CheckWindow(ObjWindow::Quest) || this->CheckWindow(ObjWindow::Guild)
	||  (this->CheckWindow(CommandWindow) || this->CheckWindow(Inventory) || this->CheckWindow(Character) || this->CheckWindow(FastMenu) || this->CheckWindow(SkillTree)
	|| this->CheckWindow(CashShop) || this->CheckWindow(FullMap) || this->CheckWindow(MuHelper)) || pMapNumber == 39 //Kanturu
		|| pMapNumber == 58 //Selupam
		|| pMapNumber == 64 //Duel Arena
		|| pMapNumber == 65 //Doppelganger
		|| pMapNumber == 66 //Doppelganger
		|| pMapNumber == 67 //Doppelganger
		|| pMapNumber == 68 //Doppelganger
		|| pMapNumber == 69 //Imperial Guardian
		|| pMapNumber == 70 //Imperial Guardian
		|| pMapNumber == 71 //Imperial Guardian
		|| pMapNumber == 72 //Imperial Guardian
		|| pMapNumber == 11	//Blood Castle
		|| pMapNumber == 12	//Blood Castle
		|| pMapNumber == 13	//Blood Castle
		|| pMapNumber == 14	//Blood Castle
		|| pMapNumber == 15	//Blood Castle
		|| pMapNumber == 16	//Blood Castle
		|| pMapNumber == 17	//Blood Castle
		|| pMapNumber == 52	//Blood Castle
		|| pMapNumber == 9	//Devil Square
		|| pMapNumber == 32	//Devil Square
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 45	//Illusion Temple
		|| pMapNumber == 46	//Illusion Temple
		|| pMapNumber == 47	//Illusion Temple
		|| pMapNumber == 48	//Illusion Temple
		|| pMapNumber == 49	//Illusion Temple
		|| pMapNumber == 50	//Illusion Temple
		|| pMapNumber == 18	//Chaos Castle
		|| pMapNumber == 19	//Chaos Castle
		|| pMapNumber == 20	//Chaos Castle
		|| pMapNumber == 21	//Chaos Castle
		|| pMapNumber == 22	//Chaos Castle
		|| pMapNumber == 23	//Chaos Castle
		|| pMapNumber == 53	//Chaos Castle
		|| pMapNumber == 34 //Crywolf
		|| pMapNumber == 30 //Valley/CastleSiege
		|| pMapNumber == 65 /*DuelArena*/)
	{
		return;
	}

	if (MiniMap == 1)
	{
		return;
	}

		this->DrawGUI(eDragonRight, this->Data[eDragonRight].X, this->Data[eDragonRight].Y);
}

void Interface::DrawCoord()
{
	gObjUser.Refresh();

	if (*(DWORD*)MAIN_SCREEN_STATE == 5)
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		pDrawInterfaceNumBer(22, 461, gObjUser.lpViewPlayer->MapPosX, 1);
		pDrawInterfaceNumBer(46, 461, gObjUser.lpViewPlayer->MapPosY, 1);

	}
}

void Interface::DrawInterfaceCustomS2()
{
	  //gInterface.DrawIMG(eMainS2left, 0, 452, 1.0, 1.0);
	  //gInterface.DrawIMG(eMainS2middle, 256, 452, 1.0, 1.0);
	  //gInterface.DrawIMG(eMainS2right, 384, 452, 1.0, 1.0);
}

void Interface::DrawInterfaceS2Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party (P)");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character (C)");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory (I,V)");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eShop))
	{
		this->DrawToolTip(430, 420, "CashShop (X)");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop, 439.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eFriend))
	{
		this->DrawToolTip(580, 420, "Friends (F)");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eFriend, 581, 433, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild (G)");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
	if (IsWorkZone(eCommandWindow))
	{
		this->DrawToolTip(13, 420, "Comandos (D)");
	}
	if (this->CheckWindow(CommandWindow))
	{
		gInterface.DrawButton(eCommandWindow, 6, 433, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::DrawInterface97Menu()
{
	if (IsWorkZone(eParty))
	{
		this->DrawToolTip(345, 420, "Party");
	}
	if (this->CheckWindow(Party))
	{
		gInterface.DrawButton(eParty, 348, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter))
	{
		this->DrawToolTip(375, 420, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter, 378.5f, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory))
	{
		this->DrawToolTip(405, 420, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory, 409, 451, 0.0, 0.0);
	}
	if (IsWorkZone(eGuild))
	{
		this->DrawToolTip(580, 444, "Guild");
	}
	if (this->CheckWindow(Guild))
	{
		gInterface.DrawButton(eGuild, 581, 457, 0.0, 0.0);
	}
}
//--------------------------------------
void Interface::EventNewInterface_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eCommandWindow))
	{
		DWORD Delay = (CurrentTick - this->Data[eCommandWindow].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCommandWindow].OnClick = true;
			return;
		}
		this->Data[eCommandWindow].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCommandWindow].EventTick = GetTickCount();
		if (this->CheckWindow(CommandWindow)) {
				this->CloseWindow(CommandWindow);
		}
		else {
			this->OpenWindow(CommandWindow);
		}
	}
	else if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eFriend))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eFriend].OnClick = true;
			return;
		}
		this->Data[eFriend].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eFriend].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
	else if (IsWorkZone(eShop))
	{
		DWORD Delay = (CurrentTick - this->Data[eFriend].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eShop].OnClick = true;
			return;
		}
		this->Data[eShop].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eShop].EventTick = GetTickCount();
		if (this->CheckWindow(CashShop)) {
			this->CloseWindow(CashShop);
		}
		else {
			CashShopSwitchState();
		}
	}
}
void Interface::EventNewInterface97_All(DWORD Event){
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}
	
	if (IsWorkZone(eParty))
	{
		DWORD Delay = (CurrentTick - this->Data[eParty].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eParty].OnClick = true;
			return;
		}
		this->Data[eParty].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eParty].EventTick = GetTickCount();
		if (this->CheckWindow(Party)) {
			this->CloseWindow(Party);
		}
		else {
			this->OpenWindow(Party);
		}
	}
	
	else if (IsWorkZone(eCharacter))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter].OnClick = true;
			return;
		}
		this->Data[eCharacter].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	else if (IsWorkZone(eInventory))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory].OnClick = true;
			return;
		}
		this->Data[eInventory].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	else if (IsWorkZone(eGuild))
	{
		DWORD Delay = (CurrentTick - this->Data[eGuild].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eGuild].OnClick = true;
			return;
		}
		this->Data[eGuild].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eGuild].EventTick = GetTickCount();
		if (this->CheckWindow(Guild)) {
			this->CloseWindow(Guild);
		}
		else {
			this->OpenWindow(Guild);
		}
	}
}

void Interface::DrawButtonRender(short ObjectID, float PosX, float PosY, float ScaleX, float ScaleY)
{
	this->Data[ObjectID].X = PosX;
	this->Data[ObjectID].Y = PosY;
	this->Data[ObjectID].MaxX = PosX + this->Data[ObjectID].Width;
	this->Data[ObjectID].MaxY = PosY + this->Data[ObjectID].Height;
	// ----
	pDrawButton(this->Data[ObjectID].ModelID, PosX, PosY,
		this->Data[ObjectID].Width, this->Data[ObjectID].Height, ScaleX, ScaleY);
}

void Interface::OpenConfig(int type)
{
	if(type = 1 )
	{
		if( (GetTickCount() - gInterface.Data[ePLAYER_POINT].EventTick) < 400 || OpenSwicthSkill == 0)
		{
			return;
		}

		gInterface.Data[ePLAYER_POINT].EventTick = GetTickCount();

		if (SkillPage == 1)
		{
			SkillPage = 2;
		}
		else
		{
			SkillPage = 1;
		}
	}

	PlayBuffer(25, 0, 0);
}

void Interface::DrawInterfaceCustom(){
	gInterface.DrawIMG(eMainEx700, 36, 413, 1.5, 2.0);
	gInterface.DrawGUI(eShop1,   76.5, 452);
	gInterface.DrawGUI(eCharacter1,  98.5, 452);
	gInterface.DrawGUI(eInventory1,  120.5, 452);
	gInterface.DrawGUI(eQuest1, 503.5, 452);
	gInterface.DrawGUI(eCommunity1,   525.5, 452);
	gInterface.DrawGUI(eSystem1,   547.5, 452);
	float v3; // ST58_4@49
	float v4; // ST54_4@49
	float v5; // ST50_4@49
	float v41; // [sp+A8h] [bp-130h]@48
	float RenderFillY; // [sp+B4h] [bp-124h]@48
	float Height; // [sp+1B8h] [bp-20h]@48
	float Widht; // [sp+1BCh] [bp-1Ch]@48
	float HPFill; // [sp+1C8h] [bp-10h]@44
	float MPFill; // [sp+1C8h] [bp-10h]@44
	float RenderX_HP; // [sp+1CCh] [bp-Ch]@48
	float RenderX_MP; // [sp+1CCh] [bp-Ch]@48
	float RenderY_HP; // [sp+1D0h] [bp-8h]@48
	float RenderY_MP; // [sp+1D0h] [bp-8h]@48

	RenderX_HP = 135.0f;//-- x
	RenderY_HP = 414.0f;//-- y
	RenderX_MP = 448.0f;
	RenderY_MP = 415.0f;//-- y
	Widht = 52.0f; //-- W
	Height = 51.0f; //-- H 
	HPFill = 0.0;
	MPFill = 0.0;

	if ( (signed int)ViewMaxHP > 0 && (signed int)ViewCurHP > 0 && (double)ViewCurHP / (double)ViewMaxHP < 0.2000000029802322 )
		pChatReserveLine(34, 0, 0);
	if ( (signed int)ViewMaxHP > 0 )
		HPFill = (double)(ViewMaxHP - ViewCurHP) / (double)ViewMaxHP;
	if ( (signed int)ViewMaxMP > 0 )
		MPFill = (double)(ViewMaxMP - ViewCurMP) / (double)ViewMaxMP;
	RenderFillY = HPFill * (float)Widht + (float)RenderY_HP;
	v41 = (float)Widht - HPFill * (float)Widht;

	v3 = (1.0 - HPFill) * Widht / 64.0;
	v4 = Height / 64.0;
	v5 = HPFill * Widht / 64.0;

	if ( sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 55) )
	{
		RenderBitmap(31297, RenderX_HP, RenderFillY, Height, v41, 0.0, v5, v4, v3, 1, 1, 0.0);
	}
	else
	{
		RenderBitmap(31298, RenderX_HP, RenderFillY, Height, v41, 0.0, v5, v4, v3, 1, 1, 0.0);
	}
	
	RenderFillY = MPFill * (float)Widht + (float)RenderY_MP;
	v41 = (float)Widht - MPFill * (float)Widht;

	v3 = (1.0 - MPFill) * Widht / 64.0;
	v4 = Height / 64.0;
	v5 = MPFill * Widht / 64.0;

	RenderBitmap(31296, RenderX_MP, RenderFillY, Height, v41, 0.0, v5, v4, v3, 1, 1, 0.0);

	gInterface.DrawFormat(eWhite, RenderX_HP + ( Widht / 2 ) - 40 , RenderY_HP + 25, 80, 3, "%d / %d", ViewCurHP, ViewMaxHP);//-- HEALT
	gInterface.DrawFormat(eWhite, RenderX_MP + ( Widht / 2 ) - 40 , RenderY_MP + 25, 80, 3, "%d / %d", ViewCurMP, ViewMaxMP);//-- MANA
	//---
	float CurrentScale; // ST38_4@18
	float CurrentWidth; // [sp+158h] [bp-28h]@18
	DWORD MaxSD; // [sp+168h] [bp-18h]@5
	float SDFill; // [sp+16Ch] [bp-14h]@16
	DWORD CurrentSD; // [sp+17Ch] [bp-4h]@8
	MaxSD = ViewMaxSD;
	CurrentSD = ViewCurSD;

	SDFill = 0.0;
	if ( MaxSD > 0 )
		SDFill = (double)(MaxSD - CurrentSD) / (double)MaxSD;

	CurrentWidth = (float)64.0 - SDFill * (float)64.0;
	CurrentScale = ( 1.0 - SDFill ) * 61.0f / 64.0f;

	if (IsWorkZone(eShop2))
	{
		this->DrawToolTip(74, 441, "In-Game Shop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop2,   76.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter2))
	{
		this->DrawToolTip(96.5, 441, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter2,  98.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory2))
	{
		this->DrawToolTip(103, 441, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory2,  120.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eQuest2))
	{
		this->DrawToolTip(501, 441, "Quest");
	}
	if (this->CheckWindow(Quest))
	{
		gInterface.DrawButton(eQuest2, 503.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eCommunity2))
	{
		this->DrawToolTip(523, 441, "Community");
	}
	if (this->CheckWindow(FriendList))
	{
		gInterface.DrawButton(eCommunity2,   525.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eSystem2))
	{
		this->DrawToolTip(545, 441, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
		gInterface.DrawButton(eSystem2,   547.5, 452, 0.0, 0.0);
	}

	RenderBitmap(31300, 194.0, 431.0f, CurrentWidth, 8.0f, 0.0, 0.0, CurrentScale, 1.0, 1, 1, 0.0);

	gInterface.DrawFormat(eWhite, 194.0, 431.0f, 64.0, 3, "%d / %d", CurrentSD, MaxSD);
	//--
	float AGFill; // [sp+15Ch] [bp-24h]@16
	DWORD CurrentAG; // [sp+160h] [bp-20h]@8
	DWORD MaxAG; // [sp+17Ch] [bp-4h]@5
	//float CurrentWidth; // [sp+158h] [bp-28h]@18
	float CurrentX; // [sp+164h] [bp-1Ch]@18
	float CurrentMove; // ST34_4@18
	//float CurrentScale; // ST38_4@18

	MaxAG = ViewMaxBP;
	CurrentAG = ViewCurBP;
	AGFill = 0.0;
	if ( MaxAG > 0 )
		AGFill = (double)(MaxAG - CurrentAG) / (double)MaxAG;

	CurrentX = AGFill * (float) 64.0 + (float) 383.0;
	CurrentWidth = (float) 64.0 - AGFill * (float) 64.0;
	CurrentScale = ( 1.0 - AGFill ) * 61.0f / 64.0f;
	CurrentMove = AGFill * (63.0f) / 64.0f;

	RenderBitmap(31299, CurrentX, 431, CurrentWidth, 8.0f, CurrentMove, 0.0, CurrentScale, 1.0, 1, 1, 0.0);
	//--
	gInterface.DrawFormat(eWhite, 383.0, 431, 64.0, 3, "%d / %d", CurrentAG, MaxAG);


	//--SD TOOLTIP
	if ( pCheckMouseOver((float) 194.0, (float) 431.0, (float) 64.0, (float) 8.0) == 1 )
	{
		gInterface.DrawToolTip(194.0, 415.0f, pGetTextLine(pTextThis(),2037), ViewCurSD, ViewMaxSD);
	}
	//-- BP TOOLTIP
	if ( pCheckMouseOver((float) 383.0, (float) 431.0, (float) 64.0, (float) 8.0) == 1 )
	{
		gInterface.DrawToolTip(383.0, 431 - 16, pGetTextLine(pTextThis(),214), ViewCurBP, ViewMaxBP);
	}
	//-- HP TOOLTIP
	if ( pCheckMouseOver((float) 135.0, (float) 414.0, (float) 52.0, (float) 51.0) == 1 )
	{
		gInterface.DrawToolTip(135.0f, 400.0, pGetTextLine(pTextThis(),358), ViewCurHP, ViewMaxHP);
	}
	//-- MP TOOLTIP
	if ( pCheckMouseOver((float) 448.0, (float) 414.0, (float) 52.0, (float) 51.0) == 1 )
	{
		gInterface.DrawToolTip(448, 400, pGetTextLine(pTextThis(),359), ViewCurMP, ViewMaxMP);
	}
}

void Interface::DrawMenuButton()
{
	if (IsWorkZone(eShop2))
	{
		this->DrawToolTip(74, 441, "In-Game Shop");
	}
	if (this->CheckWindow(CashShop))
	{
		gInterface.DrawButton(eShop2,   76.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eCharacter2))
	{
		this->DrawToolTip(96.5, 441, "Character");
	}
	if (this->CheckWindow(Character))
	{
		gInterface.DrawButton(eCharacter2,  98.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eInventory2))
	{
		this->DrawToolTip(103, 441, "Inventory");
	}
	if (this->CheckWindow(Inventory))
	{
		gInterface.DrawButton(eInventory2,  120.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eQuest2))
	{
		this->DrawToolTip(501, 441, "Quest");
	}
	if (this->CheckWindow(Quest))
	{
	gInterface.DrawButton(eQuest2, 503.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eCommunity2))
	{
		this->DrawToolTip(523, 441, "Community");
	}
	if (this->CheckWindow(FriendList))
	{
	gInterface.DrawButton(eCommunity2,   525.5, 452, 0.0, 0.0);
	}
	if (IsWorkZone(eSystem2))
	{
		this->DrawToolTip(545, 441, "System");
	}
	if (this->CheckWindow(FastMenu))
	{
	gInterface.DrawButton(eSystem2,   547.5, 452, 0.0, 0.0);
	}

}

void Interface::DrawTextX803()
{
	this->DrawFormat(eGray100, 68, 472,15, 5, "%d",(gObjUser.lpPlayer->Level/4));
}

void Interface::EventMenuButton(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	if (this->CheckWindow(ChaosBox))
	{
		return;
	}

	if (IsWorkZone(eShop1))
	{
		DWORD Delay = (CurrentTick - this->Data[eShop1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eShop1].OnClick = true;
			return;
		}
		this->Data[eShop1].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eShop1].EventTick = GetTickCount();
		CashShopSwitchState();
	}

	else if (IsWorkZone(eCharacter1))
	{
		DWORD Delay = (CurrentTick - this->Data[eCharacter1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCharacter1].OnClick = true;
			return;
		}
		this->Data[eCharacter1].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCharacter1].EventTick = GetTickCount();
		if (this->CheckWindow(Character)) {
			this->CloseWindow(Character);
		}
		else {
			this->OpenWindow(Character);
		}
	}
	
	else if (IsWorkZone(eInventory1))
	{
		DWORD Delay = (CurrentTick - this->Data[eInventory1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eInventory1].OnClick = true;
			return;
		}
		this->Data[eInventory1].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eInventory1].EventTick = GetTickCount();
		if (this->CheckWindow(Inventory)) {
			this->CloseWindow(Inventory);
		}
		else {
			this->OpenWindow(Inventory);
		}
	}
	
	else if (IsWorkZone(eQuest1))
	{
		DWORD Delay = (CurrentTick - this->Data[eQuest1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eQuest1].OnClick = true;
			return;
		}
		this->Data[eQuest1].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eQuest1].EventTick = GetTickCount();
		if (this->CheckWindow(Quest)) {
			this->CloseWindow(Quest);
		}
		else {
			this->OpenWindow(Quest);
		}
	}
	
	else if (IsWorkZone(eCommunity1))
	{
		DWORD Delay = (CurrentTick - this->Data[eCommunity1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eCommunity1].OnClick = true;
			return;
		}
		this->Data[eCommunity1].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eCommunity1].EventTick = GetTickCount();
		if (this->CheckWindow(FriendList)) {
			this->CloseWindow(FriendList);
		}
		else {
			this->OpenWindow(FriendList);
		}
	}

	else if (IsWorkZone(eSystem1))
	{
		DWORD Delay = (CurrentTick - this->Data[eSystem1].EventTick);
		if (Event == WM_LBUTTONDOWN) {
			this->Data[eSystem1].OnClick = true;
			return;
		}
		this->Data[eSystem1].OnClick = false;
		if (Delay < 500) {
			return;
		}
		this->Data[eSystem1].EventTick = GetTickCount();
		if (this->CheckWindow(FastMenu)) {
			this->CloseWindow(FastMenu);
		}
		else {
			this->OpenWindow(FastMenu);
		}
	}
}

void Interface::FixChaosMachine()
{
	if (this->CheckWindow(ChaosBox))
	{
		this->OpenWindow(ExpandInventory);
	}
}

bool Interface::ButtonEx(DWORD Event, int ButtonID, bool Type)
{
	if( !this->IsWorkZone3(ButtonID) )
	{
		return false;
	}

	if( Type == true )
	{
		if( !this->Data[ButtonID].Attribute )
		{
			return false;
		}
	}

	// ----
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay			= (CurrentTick - this->Data[ButtonID].EventTick);
	// ----

	if( Event == WM_LBUTTONDOWN  && this->Data[ButtonID].OnClick == false)
	{
		this->Data[ButtonID].OnClick = true;
		//return false;
	}

	if(Event == WM_LBUTTONUP && this->Data[ButtonID].OnClick == true)
	{
		this->Data[ButtonID].OnClick = false;
		return true;
	}
	// ----
	if( Delay < 500 )
	{
		return false;
	}
	// ----
	this->Data[ButtonID].OnClick = false;
	// ----
	this->Data[ButtonID].EventTick = GetTickCount();
	// ----
	return false;
}

void Interface::CursorFocusWindows()
{
	if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
	{
		if (pCheckMouseOver(gRenderMap.ultimoX, gRenderMap.ultimoY, 128, 128))
		{
			pSetCursorFocus = true;
		}
	}
}

double sub_636450(float a1)
{
	return (float)((double)(unsigned int)pWinHeight * a1 / 480.0);
}

GLvoid GetDrawCircle(int ID, float X, float Y, float W, float CurrenX, float CurrenY, float SetScale, int ScaleSize, int ScalePosicion, float Alpha)
{
	float v14; // ST1C_4@1
	float v15; // ST18_4@1
	GLuint vertexcount; // ST1C_4@5
	float v33; // ST1C_4@5
	GLfloat angle; // ST1C_4@5
	GLfloat texturecoord[2]; // [sp+2Ch] [bp-40h]@5
	GLfloat VertexCoord[4]; // [sp+4Ch] [bp-20h]@5

	SetScale = SetScale / 2;
	//--
	W = W / 2;
	X = X + W;
	Y = Y + W;

	if ( ScalePosicion )
	{
		X = sub_636420( X );
		Y = sub_636450( Y );
	}

	if ( ScaleSize )
	{
		W = sub_636420( W );
	}

	v33 = (double)pWinHeight - Y;

	vertexcount = 20;

	GetBindTexture( ID );

	glBegin( GL_TRIANGLE_FAN );

	angle = 2.0 * 3.1415926 / vertexcount;
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, Alpha);
	texturecoord[0] = CurrenX;
	texturecoord[1] = CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = X;
	VertexCoord[1] = v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);

	for(int i = 0; i < vertexcount ; i++) 
	{
		texturecoord[0] = (std::cos(angle * i) * SetScale) + CurrenX;
		texturecoord[1] = (std::sin(angle * i) * SetScale) + CurrenY;
		glTexCoord2fv(texturecoord);
		VertexCoord[0] = (std::cos(angle * i) * W) + X;
		VertexCoord[1] = (std::sin(angle * i) * -W) + v33;
		VertexCoord[2] = 0.0;
		VertexCoord[3] = 1.0;
		glVertex4fv(VertexCoord);
	}
	//--
	texturecoord[0] = ( 1.0 * SetScale ) + CurrenX;
	texturecoord[1] = ( 0.0 * SetScale ) + CurrenY;
	glTexCoord2fv(texturecoord);
	//--
	VertexCoord[0] = (1.0 * W) + X;
	VertexCoord[1] = (0.0 * -W) + v33;
	VertexCoord[2] = 0.0;
	VertexCoord[3] = 1.0;
	glVertex4fv(VertexCoord);
	//--
	if ( Alpha > 0.0 )
		glColor4f(1.0, 1.0, 1.0, 1.0);
	//--
	glEnd();
}