#include "stdafx.h"
#include "Interface.h"
#include "CustomJewelBank.h"
#include "Item.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Defines.h"
#include "Central.h"
#include "Protect.h"

JewelBank gJewelBank;

JewelBank::JewelBank()
{

}
JewelBank::~JewelBank()
{

}

void JewelBank::Bind()
{
	gInterface.BindObject(eJEWELBANK_MAIN, 0x7A5A, 222, 290, -1, -1);
	gInterface.BindObject(eJEWELBANK_TITLE, 0x7A63, 230, 67, -1, -1);
	gInterface.BindObject(eJEWELBANK_FRAME, 0x7A58, 230, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_FOOTER, 0x7A59, 230, 50, -1, -1);
	gInterface.BindObject(eJEWELBANK_POINT, 0x7B68, 10, 10, -1, -1);
	gInterface.BindObject(eJEWELBANK_LINE, 0x7B67, 154, 3, -1, -1);
	gInterface.BindObject(eJEWELBANK_DIV, 0x7A62, 223, 21, -1, -1);
	gInterface.BindObject(eJEWELBANK_CLOSE, 0x0, 19, 19, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP1, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP2, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP3, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP4, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP5, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP6, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP7, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP8, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP9, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP10, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEUP11, 0x7AA4, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN1, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN2, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN3, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN4, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN5, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN6, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN7, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN8, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN9, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN10, 0x7C0D, 15, 15, -1, -1);
	gInterface.BindObject(eJEWELBANK_PAGEDN11, 0x7C0D, 15, 15, -1, -1);
	//
	gInterface.BindObject(eJEWELBANK_NEXTWIN, 0x7903, 25, 40, -1, -1);
	gInterface.BindObject(eJEWELBANK_PREVWIN, 0x7904, 25, 40, -1, -1);
}


bool JewelBank::EventJewelWindows_Close(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		return false;
	}
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return true;
	}
	gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;
	if (Delay < 500)
	{
		return false;
	}
	gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();
	this->CloseJewelWindow();
	return false;
}

void JewelBank::DrawJewelBank803()
{
	if( !gInterface.Data[eJEWELBANK_MAIN].OnShow )
	{
		return;
	}


	if( gInterface.Data[eLuckyWheelMain].OnShow )
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return;
	}

	if (gInterface.CheckWindow(FriendList) || 
		gInterface.CheckWindow(SkillTree) || 
		gInterface.CheckWindow(CashShop) || 
		gInterface.CheckWindow(FastMenu) ||
		gInterface.CheckWindow(Warehouse) ||
		gInterface.CheckWindow(MoveList) ||
		gInterface.CheckWindow(Shop) ||
		gInterface.CheckWindow(Store) ||
		gInterface.CheckWindow(OtherStore) ||
		gInterface.CheckWindow(SeniorNPC) ||
		gInterface.CheckWindow(CashShop) ||
		gInterface.CheckWindow(ExpandWarehouse) ||
		gInterface.CheckWindow(GoldenArcher1) ||
		gInterface.CheckWindow(Quest) ||
		gInterface.CheckWindow(Trade))
	{
		return;
	}

	// ----
	float MainWidth			= 230.0;
	float MainHeight		= 320.0;
	float StartBody			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartY			= ((MAX_WIN_HEIGHT - 51) / 2) - (MainHeight / 2);
	float StartX			= (MAX_WIN_WIDTH / 2) - (MainWidth / 2);
	float MainCenter		= StartX + (MainWidth / 3);
	float ButtonX			= MainCenter - (float)(29.0 / 2);
	// ----
	DWORD Color = eGray100;

	gCentral.PrintDropBox(StartX, StartY, MainWidth, MainHeight, 0, 0);
	// ----
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, "Jewel Bank System");

	//
	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 35, 200, 1); //-- Divisor


	float flDrawX = StartX + 20;
	float flDrawY = StartY + 30;

	// -----------
	// -> jewel
	// -----------	

/*		if(Page == 1)
		{	
			for(std::vector<JEWEL_BANK>::iterator it = gJewelBank.m_JewelBank.begin();it != gJewelBank.m_JewelBank.end();it++)	
			{
				if(it->Index == 0)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ1);
				}
				else if(it->Index == 1)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ2);
				}
				else if(it->Index == 2)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ3);
				}
				else if(it->Index == 3)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ4);
				}
				else if(it->Index == 4)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ5);
				}
				else if(it->Index == 5)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ6);
				}
				else if(it->Index == 6)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ7);
				}
				else if(it->Index == 7)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ8);
				}
				else if(it->Index == 8)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ9);
				}
				else if(it->Index == 9)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ10);
				}
				else if(it->Index == 10)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ11);
				}
			}
		}
		else
		{*/
		flDrawY += 20;
		this->DrawInfo(flDrawX, flDrawY, "Zen", true, gObjUser.BankEx.Money);

		flDrawY += 20;
		this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Jewel Of Chaos", gObjUser.BankEx.Chaos);

		flDrawY += 20;
		this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Jewel Of Bless", gObjUser.BankEx.Bless);

		flDrawY += 20;
		this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Jewel Of Soul", gObjUser.BankEx.Soul);

		flDrawY += 20;
		this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Jewel Of Life", gObjUser.BankEx.Life);

		flDrawY += 20;
		this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Jewel Of Creation", gObjUser.BankEx.Creation);

		flDrawY += 20;
		this->DrawLine(14, 42, 6, flDrawX, flDrawY, "Jewel Of Harmony", gObjUser.BankEx.Harmony);

		flDrawY += 20;
		this->DrawLine(14, 31, 7, flDrawX, flDrawY, "Jewel Of Guardian", gObjUser.BankEx.Guardian);

		flDrawY += 20;
		this->DrawLine(14, 41, 8, flDrawX, flDrawY, "Gemstone", gObjUser.BankEx.Gemstone);
	
		flDrawY += 20;
		this->DrawLine(14, 43, 9, flDrawX, flDrawY, "Lower refining stone", gObjUser.BankEx.LowRefine);

		flDrawY += 20;
		this->DrawLine(14, 44, 10, flDrawX, flDrawY, "Higher refining stone", gObjUser.BankEx.HigRefine);

		/*}*/

	pDrawGUI(71520, StartX + (MainWidth / 2) - (200 / 2), StartBody + 285, 200, 1); //-- Divisor

}

void JewelBank::DrawJewelBank()
{

	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	if( gInterface.Data[eLuckyWheelMain].OnShow )
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return;
	}

	if (gInterface.CheckWindow(FriendList) || 
		gInterface.CheckWindow(SkillTree) || 
		gInterface.CheckWindow(CashShop) || 
		gInterface.CheckWindow(FastMenu) ||
		gInterface.CheckWindow(Warehouse) ||
		gInterface.CheckWindow(MoveList) ||
		gInterface.CheckWindow(Shop) ||
		gInterface.CheckWindow(Store) ||
		gInterface.CheckWindow(OtherStore) ||
		gInterface.CheckWindow(SeniorNPC) ||
		gInterface.CheckWindow(CashShop) ||
		gInterface.CheckWindow(ExpandWarehouse) ||
		gInterface.CheckWindow(GoldenArcher1) ||
		gInterface.CheckWindow(Quest) ||
		gInterface.CheckWindow(Trade))
	{
		return;
	}

	pSetCursorFocus = true;

	DWORD Color = eGray100;
	float MainWidth = 230.0;
	float MainHeight = 290.0;
	float StartBody	= 80.0;
	float StartY = 60;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	gInterface.DrawWindow(eJEWELBANK_MAIN, eJEWELBANK_TITLE, eJEWELBANK_FRAME, eJEWELBANK_FOOTER, 14, StartX, StartY, "Jewel Bank System");

//	gInterface.DrawGUI(eJEWELBANK_CLOSE, StartX + MainWidth - gInterface.Data[eJEWELBANK_CLOSE].Width, gInterface.Data[eJEWELBANK_CLOSE].Height + gInterface.Data[eJEWELBANK_CLOSE].Height - 32);
	gInterface.DrawGUI(eJEWELBANK_CLOSE, StartX + MainWidth - gInterface.Data[eJEWELBANK_CLOSE].Width, StartBody);
	// ----
	if (gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		DWORD Color = eGray100;
		// ----
		if (gInterface.Data[eJEWELBANK_CLOSE].OnClick)
		{
			Color = eGray150;
		}
		// ----
		gInterface.DrawColoredGUI(eJEWELBANK_CLOSE, gInterface.Data[eJEWELBANK_CLOSE].X, gInterface.Data[eJEWELBANK_CLOSE].Y, Color);
		gInterface.DrawToolTip(gInterface.Data[eJEWELBANK_CLOSE].X + 5, gInterface.Data[eJEWELBANK_CLOSE].Y + 25, "Close");
	}

/*	if ((this->Page == 0))
	{
		gInterface.DrawGUI(eJEWELBANK_NEXTWIN, StartX + MainWidth - 38, 150);
	}
	else 
	{
		gInterface.ResetDrawIMG(eJEWELBANK_NEXTWIN);
	}

	if (this->Page == 1)
	{
		gInterface.DrawGUI(eJEWELBANK_PREVWIN, StartX + 10, 150);
	}
	else
	{
		gInterface.ResetDrawIMG(eJEWELBANK_PREVWIN);
	}*/

	float flDrawX = StartX + 20;
	float flDrawY = StartY + 30;

	// -----------
	// -> jewel
	// -----------	

/*		if(Page == 1)
		{	
			for(std::vector<JEWEL_BANK>::iterator it = gJewelBank.m_JewelBank.begin();it != gJewelBank.m_JewelBank.end();it++)	
			{
				if(it->Index == 0)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ1);
				}
				else if(it->Index == 1)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ2);
				}
				else if(it->Index == 2)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ3);
				}
				else if(it->Index == 3)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ4);
				}
				else if(it->Index == 4)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ5);
				}
				else if(it->Index == 5)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ6);
				}
				else if(it->Index == 6)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ7);
				}
				else if(it->Index == 7)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ8);
				}
				else if(it->Index == 8)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ9);
				}
				else if(it->Index == 9)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ10);
				}
				else if(it->Index == 10)
				{
					flDrawY += 20;
					this->DrawLine(it->ID, it->ItemID, 0, flDrawX, flDrawY, it->ItemName, gObjUser.BankEx.JCustomJ11);
				}
			}
		}
		else
		{*/
		flDrawY += 20;
		this->DrawInfo(flDrawX, flDrawY, "Zen", true, gObjUser.BankEx.Money);

		flDrawY += 20;
		this->DrawLine(12, 15, 1, flDrawX, flDrawY, "Jewel Of Chaos", gObjUser.BankEx.Chaos);

		flDrawY += 20;
		this->DrawLine(14, 13, 2, flDrawX, flDrawY, "Jewel Of Bless", gObjUser.BankEx.Bless);

		flDrawY += 20;
		this->DrawLine(14, 14, 3, flDrawX, flDrawY, "Jewel Of Soul", gObjUser.BankEx.Soul);

		flDrawY += 20;
		this->DrawLine(14, 16, 4, flDrawX, flDrawY, "Jewel Of Life", gObjUser.BankEx.Life);

		flDrawY += 20;
		this->DrawLine(14, 22, 5, flDrawX, flDrawY, "Jewel Of Creation", gObjUser.BankEx.Creation);

		flDrawY += 20;
		this->DrawLine(14, 42, 6, flDrawX, flDrawY, "Jewel Of Harmony", gObjUser.BankEx.Harmony);

		flDrawY += 20;
		this->DrawLine(14, 31, 7, flDrawX, flDrawY, "Jewel Of Guardian", gObjUser.BankEx.Guardian);

		flDrawY += 20;
		this->DrawLine(14, 41, 8, flDrawX, flDrawY, "Gemstone", gObjUser.BankEx.Gemstone);
	
		flDrawY += 20;
		this->DrawLine(14, 43, 9, flDrawX, flDrawY, "Lower refining stone", gObjUser.BankEx.LowRefine);

		flDrawY += 20;
		this->DrawLine(14, 44, 10, flDrawX, flDrawY, "Higher refining stone", gObjUser.BankEx.HigRefine);

		/*}*/
}

void JewelBank::DrawLine(int ItemType, int ItemIndex, int ItemLevel, float ItemDrawX, float ItemDrawY, char * ItemName, int Count)
{
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(ITEM(ItemType, ItemIndex));
	const int WidthValue = 24;
	const int HeightValue = 26;
	float barWidth = WidthValue * ItemInfo->ItemWidth;
	float barHeight = HeightValue * ItemInfo->ItemHeight;
	float flX = ItemDrawX + 10;
	float flX2 = ItemDrawX + 10;
	float flY = ItemDrawY;
	int iLevel = 0;
	gInterface.DrawItemIMGBank(flX, flY, barWidth, barHeight, GET_ITEM(ItemType, ItemIndex), SET_ITEMOPT_LEVEL(iLevel), 1, 0, 0);
	
	flX += 30;
	flY += 10;
	gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s x %d", ItemName, Count);

	flX += 95;
	gInterface.DrawGUI(eJEWELBANK_PAGEDN1 + ItemLevel, flX, flY);

	if(gInterface.IsWorkZone(eJEWELBANK_PAGEDN1 + ItemLevel))
	{
		if(gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].OnClick)
		{
			gInterface.DrawColoredGUI(eJEWELBANK_PAGEDN1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEDN1 + ItemLevel].Y, eGray150);
		}	
	}

	flX += 20;
	gInterface.DrawGUI(eJEWELBANK_PAGEUP1 + ItemLevel, flX, flY);

	if(gInterface.IsWorkZone(eJEWELBANK_PAGEUP1 + ItemLevel))
	{
		if(gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].OnClick)
		{
			gInterface.DrawColoredGUI(eJEWELBANK_PAGEUP1 + ItemLevel, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].X, gInterface.Data[eJEWELBANK_PAGEUP1 + ItemLevel].Y, eGray150);
		}
	}



	if(gProtect.m_MainInfo.CustomInterfaceType <= 2)
	{
		gInterface.DrawGUI(eJEWELBANK_LINE, ItemDrawX + 15, flY + 15);
	}
	else
	{
		gInterface.DrawGUI(71520, ItemDrawX + 15, flY + 15);
	}
}

void JewelBank::DrawInfo(float InfoDrawX, float InfoDrawY, char* Text, bool Type, int Count)
{
	float flX = InfoDrawX + 10;
	float flY = InfoDrawY;

	gInterface.DrawGUI(eJEWELBANK_POINT, flX + 8, flY + 10);

	flX += 30;
	flY += 10;


	if(Type)
	{
		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d 000 000", Text, Count);

		flX += 95;
		gInterface.DrawGUI(eJEWELBANK_PAGEDN1, flX, flY);
	
		if(gInterface.IsWorkZone(eJEWELBANK_PAGEDN1))
		{
			if(gInterface.Data[eJEWELBANK_PAGEDN1].OnClick)
			{
				gInterface.DrawColoredGUI(eJEWELBANK_PAGEDN1, gInterface.Data[eJEWELBANK_PAGEDN1].X, gInterface.Data[eJEWELBANK_PAGEDN1].Y, eGray150);
			}
		}

		flX += 20;
		gInterface.DrawGUI(eJEWELBANK_PAGEUP1, flX, flY);

		if(gInterface.IsWorkZone(eJEWELBANK_PAGEUP1))
		{
			if(gInterface.Data[eJEWELBANK_PAGEUP1].OnClick)
			{
				gInterface.DrawColoredGUI(eJEWELBANK_PAGEUP1, gInterface.Data[eJEWELBANK_PAGEUP1].X, gInterface.Data[eJEWELBANK_PAGEUP1].Y, eGray150);
			}
			
		}
	}
	else
	{
		gInterface.DrawFormat(eYellow, flX, flY + 2, 100, 1, "%s: %d", Text, Count);
	}

	flX += 95;

		
	if(gProtect.m_MainInfo.CustomInterfaceType <= 2)
	{
		gInterface.DrawGUI(eJEWELBANK_LINE, InfoDrawX + 15, flY + 15);
	}
	else
	{
		gInterface.DrawGUI(71520, InfoDrawX + 15, flY + 15);
	}

}

bool JewelBank::JewelBankEvent(DWORD Event)
{
	DWORD CurrentTick = GetTickCount();
	DWORD Delay = (CurrentTick - gInterface.Data[eJEWELBANK_CLOSE].EventTick);
	// ----
	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow || !gInterface.IsWorkZone(eJEWELBANK_CLOSE))
	{
		return false;
	}
	// ----
	if (Event == WM_LBUTTONDOWN)
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return true;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].OnClick = false;
	// ----
	if (Delay < 500)
	{
		return false;
	}
	// ----
	gInterface.Data[eJEWELBANK_CLOSE].EventTick = GetTickCount();
	gInterface.Data[eJEWELBANK_MAIN].Close();
	// ----
	return false;
}

bool JewelBank::JewelBankNext(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay		= (CurrentTick - gInterface.Data[eJEWELBANK_NEXTWIN].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eJEWELBANK_PREVWIN].EventTick);

	if( !gInterface.Data[eJEWELBANK_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eJEWELBANK_NEXTWIN) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eJEWELBANK_NEXTWIN].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eJEWELBANK_NEXTWIN].OnClick = false;
	
	this->Page++;
	
	gInterface.Data[eJEWELBANK_NEXTWIN].EventTick = GetTickCount();
	

	return true;
}

bool JewelBank::JewelBankPrev(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	DWORD Delay		= (CurrentTick - gInterface.Data[eJEWELBANK_PREVWIN].EventTick);
	DWORD Delay2		= (CurrentTick - gInterface.Data[eJEWELBANK_NEXTWIN].EventTick);

	if( !gInterface.Data[eJEWELBANK_MAIN].OnShow )
	{
		return false;
	}
	
	if( !gInterface.IsWorkZone(eJEWELBANK_PREVWIN) )
	{
		return false;
	}

	if( Event == WM_LBUTTONDOWN )
	{
		gInterface.Data[eJEWELBANK_PREVWIN].OnClick = true;
		return true;
	}

	if( Delay < 100 || Delay2 < 100 )
	{
		return false;
	}
	
	gInterface.Data[eJEWELBANK_PREVWIN].OnClick = false;
	
	gInterface.Data[eJEWELBANK_PREVWIN].EventTick = GetTickCount();

	this->Page--;
	
	return true;
}

//-----------
void JewelBank::JewelBankButton(DWORD key)
{
	for(int i = 0; i < 11; i++)
	{
		if(gInterface.ButtonEx(key, eJEWELBANK_PAGEUP1 + i, false))
		{
			this->JewelBankPacket(i);
			return;
		}
		else if(gInterface.ButtonEx(key, eJEWELBANK_PAGEDN1 + i, false))
		{
			this->JewelBankPacket(i+11);
			return;
		}
	}

}

void JewelBank::JewelBankPacket(int number)
{
	PMSG_JEWELBANK pMsg;
	pMsg.h.set((LPBYTE)&pMsg, 0xFB, 0xDA, sizeof(pMsg));
	pMsg.Result = number;
	DataSend((LPBYTE)&pMsg, pMsg.h.size);
}