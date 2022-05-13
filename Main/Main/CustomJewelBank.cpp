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
#include "BankUpgrade.h"

JewelBank gJewelBank;

JewelBank::JewelBank()
{
	this->Pagina = 0;
	this->ItemJewelry[0] = ITEM(12, 15);//-- CHAOS
	this->ItemJewelry[1] = ITEM(14, 13);//-- BLESS
	this->ItemJewelry[2] = ITEM(14, 14);//-- SOUL
	this->ItemJewelry[3] = ITEM(14, 16);//-- LIFE
	this->ItemJewelry[4] = ITEM(14, 22);//-- CREATION

	this->ItemJewelry[5] = ITEM(14, 41);//-- GEMS
	this->ItemJewelry[6] = ITEM(14, 31);//-- GUARDYAN
	this->ItemJewelry[7] = ITEM(14, 42);//-- HARMONY
	this->ItemJewelry[8] = ITEM(14, 43);//-- LOWER
	this->ItemJewelry[9] = ITEM(14, 44);//-- HIGHER

	this->BankJewelry[0] = 0;//-- CHAOS
	this->BankJewelry[1] = 0;//-- BLESS
	this->BankJewelry[2] = 0;//-- SOUL
	this->BankJewelry[3] = 0;//-- LIFE
	this->BankJewelry[4] = 0;//-- CREATION

	this->BankJewelry[5] = 0;//-- GEMS
	this->BankJewelry[6] = 0;//-- GUARDYAN
	this->BankJewelry[7] = 0;//-- HARMONY
	this->BankJewelry[8] = 0;//-- LOWER
	this->BankJewelry[9] = 0;//-- HIGHER
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

DWORD EventPush;

void JewelBank::DrawJewelBank803()
{
	float v4; 
	int v8; 
	float v9; 
	float v10;
	float v11;
	float v12;
	float v13;
	float v14;
	float v16;
	int v20; 
	signed int i; 
	int JCItemStruct; 
	char count[256]; 

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

	int JCWinWidth;

	v20 = *(DWORD *)(GetInstance() + 160);

	JCWinWidth = pWinWidth / pWinHeightReal / 2;

    if(pWinWidth >= 1280)
	{
		*(DWORD *)(v20 + 16) = JCWinWidth - 218;
	}
	else
	{
		*(DWORD *)(v20 + 16) = JCWinWidth - 115;
	}


	v4 = (double)*(signed int *)(v20 + 20);
	v8 = *(DWORD *)(GetInstance() + 160);
	v11 = (double)*(signed int *)(v8 + 16);
	v10 = (double)*(signed int *)(v8 + 20);
	v16 = (double)*(signed int *)(v20 + 16);

	int Item;

	pSetCursorFocus = true;

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
	gInterface.DrawFormat(eGold, (int)StartX + 10, (int)StartBody + 10, 210, 3, gCustomMessage.GetMessage(73));


	if (pCheckMouseOver((int)v16 + 20,(int) v4 + 250, 20, 23))
	{
		if ( *(BYTE*)0x8793386 && GetTickCount( ) >= EventPush + 300 )
		{
			gJewelBank.Pagina = 0;
			pDrawButton(32342, v16 + 20, v4 + 250, 20, 23, 0.0, 46.0);
			EventPush = GetTickCount( );
		}
		else
		{
			pDrawButton(32342, v16 + 20, v4 + 250, 20, 23, 0.0, 23.0);
		}
	}
	else
	{
		pDrawButton(32342, v16 + 20, v4 + 250, 20, 23, 0.0, 0.0);
	}

	if (pCheckMouseOver((int)v16 + 180,(int) v4 + 250, 20, 23))
	{
		if ( *(BYTE*)0x8793386 && GetTickCount( ) >= EventPush + 300 )
		{
			gJewelBank.Pagina = 1;
			pDrawButton(32343, v16 + 180, v4 + 250, 20, 23, 0.0, 46.0);
			EventPush = GetTickCount( );
		}
		else
		{
			pDrawButton(32343, v16 + 180, v4 + 250, 20, 23, 0.0, 23.0);
		}
	}
	else
	{
		pDrawButton(32343, v16 + 180, v4 + 250, 20, 23, 0.0, 0.0);
	}

	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 255, 189, 25, 255);

	for ( int i = 0 ; i < MAX_JEWEL_SHOW ; i++ )
	{
		Item = gJewelBank.ItemJewelry[ i + 5 * gJewelBank.Pagina ];

		JCItemStruct = sub_4E10D0( Item );

		v9 = (double)(20 * 1);
		v14 = (double)(20 * 1) + 20;

		v12 = (double)((v11 + 25) - v9 / 2);
		v13 = (double)((v10 + ( i * v14 ) + 65) - v14 / 2);

		ZeroMemory(count, sizeof(count));

		wsprintf(count, "%d", gJewelBank.BankJewelry[ i + 5 * gJewelBank.Pagina ]);
		JCLineBack(i, Item, v12, v13, v9, v14, count);
	}

	JCImagesBack(Item, v12, v13, v9, v14, count);

	pSetTextColor(pTextThis( ), 36, 242, 252, 250);
	pSetBackgroundTextColor(pTextThis( ), 0, 0, 0, 0);
	pDrawText(pTextThis( ), v16, v4 + 258,gCustomMessage.GetMessage(74), 223, 0, (LPINT)3, 0);
	pSetFont(pTextThis( ), (int)pFontNormal);
	gInterface.DrawFormat(eBlue250, v16 + 79, v4 + 258, 230, 0, "");

}

void JewelBank::DrawJewelBank()
{
	float v4; 
	int v8; 
	float v9; 
	float v10;
	float v11;
	float v12;
	float v13;
	float v14;
	float v16;
	int v20; 
	signed int i; 
	int JCItemStruct; 
	char count[256]; 

	//--

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

	if (!gInterface.Data[eJEWELBANK_MAIN].OnShow)
	{
		return;
	}

	if( gInterface.Data[eLuckyWheelMain].OnShow )
	{
		gInterface.Data[eJEWELBANK_CLOSE].OnClick = true;
		return;
	}

	int JCWinWidth;
	int PosX = 0;

	pSetCursorFocus = true;

	v20 = *(DWORD *)(GetInstance() + 160);

	JCWinWidth = pWinWidth / pWinHeightReal / 2;

    if(pWinWidth >= 1280)
	{
		if (pWinWidth == 1280)
		{
			PosX += 125;
		}
		
		*(DWORD *)(v20 + 16) = JCWinWidth - 218;
	}
	else
	{
		*(DWORD *)(v20 + 16) = JCWinWidth - 115;
	}


	v4 = (double)*(signed int *)(v20 + 20);
	v8 = *(DWORD *)(GetInstance() + 160);
	v11 = (double)*(signed int *)(v8 + 16);
	v10 = (double)*(signed int *)(v8 + 20);
	v16 = (double)*(signed int *)(v20 + 16);

	int Item;

	DWORD Color = eGray100;
	float MainWidth = 230.0;
	float MainHeight = 290.0;
	float StartBody	= 80.0;
	float StartY = 60;
	float StartX = (MAX_WIN_WIDTH / 2) - (MainWidth / 2);

	gInterface.DrawWindow(eJEWELBANK_MAIN, eJEWELBANK_TITLE, eJEWELBANK_FRAME, eJEWELBANK_FOOTER, 14, StartX, StartY, gCustomMessage.GetMessage(73));

	gInterface.DrawGUI(eJEWELBANK_CLOSE, StartX + MainWidth - gInterface.Data[eJEWELBANK_CLOSE].Width - 7.0, StartBody - 14);
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

	if (pCheckMouseOver((int)v16 + 20 + PosX,(int) v4 + 250, 20, 23))
	{
		if ( *(BYTE*)0x8793386 && GetTickCount( ) >= EventPush + 300 )
		{
			gJewelBank.Pagina = 0;
			pDrawButton(32342, v16 + 20 + PosX, v4 + 250, 20, 23, 0.0, 46.0);
			EventPush = GetTickCount( );
		}
		else
		{
			pDrawButton(32342, v16 + 20 + PosX, v4 + 250, 20, 23, 0.0, 23.0);
		}
	}
	else
	{
		pDrawButton(32342, v16 + 20 + PosX, v4 + 250, 20, 23, 0.0, 0.0);
	}

	if (pCheckMouseOver((int)v16 + 180 + PosX,(int) v4 + 250, 20, 23))
	{
		if ( *(BYTE*)0x8793386 && GetTickCount( ) >= EventPush + 300 )
		{
			gJewelBank.Pagina = 1;
			pDrawButton(32343, v16 + 180 + PosX, v4 + 250, 20, 23, 0.0, 46.0);
			EventPush = GetTickCount( );
		}
		else
		{
			pDrawButton(32343, v16 + 180 + PosX, v4 + 250, 20, 23, 0.0, 23.0);
		}
	}
	else
	{
		pDrawButton(32343, v16 + 180 + PosX, v4 + 250, 20, 23, 0.0, 0.0);
	}

	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 255, 189, 25, 255);

	for ( int i = 0 ; i < MAX_JEWEL_SHOW ; i++ )
	{
		Item = gJewelBank.ItemJewelry[ i + 5 * gJewelBank.Pagina ];

		JCItemStruct = sub_4E10D0( Item );

		v9 = (double)(20 * 1);
		v14 = (double)(20 * 1) + 20;

		v12 = (double)((v11 + 25) - v9 / 2);
		v13 = (double)((v10 + ( i * v14 ) + 65) - v14 / 2);

		ZeroMemory(count, sizeof(count));

		wsprintf(count, "%d", gJewelBank.BankJewelry[ i + 5 * gJewelBank.Pagina ]);
		JCLineBack(i, Item, v12 + PosX, v13, v9, v14, count);
	}

	JCImagesBack(Item, v12 + PosX, v13, v9, v14, count);

	pSetTextColor(pTextThis( ), 36, 242, 252, 250);
	pSetBackgroundTextColor(pTextThis( ), 0, 0, 0, 0);
	pDrawText(pTextThis( ), v16 + PosX, v4 + 258,gCustomMessage.GetMessage(74), 223, 0, (LPINT)3, 0);
	pSetFont(pTextThis( ), (int)pFontNormal);
	gInterface.DrawFormat(eBlue250, v16 + 79, v4 + 258, 230, 0, "");
	//sub_7798F0(v20 + 24, 0);
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

//--------------------------------------------

void JewelBank::LoadInfoBank(PMSG_JEWELSBANK * aRecv)
{
	if (aRecv == NULL)
	{
		return;
	}
	this->BankJewelry[0] = aRecv->Chaos;//-- CHAOS
	this->BankJewelry[1] = aRecv->Bless;//-- BLESS
	this->BankJewelry[2] = aRecv->Soul;//-- SOUL
	this->BankJewelry[3] = aRecv->Life;//-- LIFE
	this->BankJewelry[4] = aRecv->CreateonBank;//-- CREATION

	this->BankJewelry[5] = aRecv->GemStoneBank;//-- GEMS
	this->BankJewelry[6] = aRecv->GuardianBank;//-- GUARDYAN
	this->BankJewelry[7] = aRecv->HarmonyBank;//-- HARMONY
	this->BankJewelry[8] = aRecv->LowStoneBank;//-- LOWER
	this->BankJewelry[9] = aRecv->HighStoneBank;//-- HIGHER
}

int EvtSubJewel;

void JCLineBack(int m, int Item, float x, float y, float w, float h, char * count)
{
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
	
	glMatrixMode(0x1700u);
	glPopMatrix();
	glMatrixMode(0x1701u);
	glPopMatrix();
	glColor4f((GLfloat) 1.0, (GLfloat) 1.0, (GLfloat) 1.0,(GLfloat) 1.0);
	pSetBlend(false);

	pDrawText(pTextThis(), x, y + 10, (const char*)pGetItemAtt(Item, 0), 0, 0, (LPINT) 1, 0);
	pDrawText(pTextThis(), x + w + 5, y + 25, count, 0, 0, (LPINT) 1, 0);

	pGLSwitch( );

	for(int k = 0 ; k < 7 ; k ++)
	{
		pDrawGUI(31743, x + (k * 18) + 75, y + 10, 16, 32);
		pGLSwitch( );

		if ( pCheckMouseOver((int)(x + (k * 18) + 75), (int)(y + 26), 16, 16) )
		{
			if ( *(BYTE*)0x8793386 && GetTickCount( ) >= EvtSubJewel + 400 )
			{
				if( gJewelBank.BankJewelry[ m + 5 * gJewelBank.Pagina ] > 0 )
				{
					PMSG_JEWELBANK_SUB pMsg;
					pMsg.h.set(0xF3, 0xF1, sizeof(pMsg));

					pMsg.Type = (int) ( m + 5 * gJewelBank.Pagina );
					pMsg.Mode = k;

					DataSend((LPBYTE)&pMsg, pMsg.h.size);
					EvtSubJewel = GetTickCount( );
				}
			}
		}

		if( k == 0 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "01", 17, 0, (LPINT) 3, 0);
		}
		else if( k == 1 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "10", 17, 0, (LPINT) 3, 0);
		}
		else if( k == 2 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "20", 17, 0, (LPINT) 3, 0);
		}
		else if( k == 3 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "30", 17, 0, (LPINT) 3, 0);
		}
		else if( k == 4 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "40", 17, 0, (LPINT) 3, 0);
		}
		else if( k == 5 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "50", 17, 0, (LPINT) 3, 0);
		}
		else if( k == 6 )
		{
			pDrawText(pTextThis(), x + (k * 18) + 75, y + 14, "60", 17, 0, (LPINT) 3, 0);
		}
	}
}

void JCImagesBack(int Item, float x, float y, float w, float h, char * count)
{
	if(gJewelBank.Pagina == 1)
	{
		gJewelBank.Pagina = 1;
		gJewelBank.DrawItemIMG( x, y-160, w, h, GET_ITEM(14, 41), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-112, w, h, GET_ITEM(14, 31), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-80, w, h, GET_ITEM(14, 42), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-42, w, h, GET_ITEM(14, 43), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y, w, h, GET_ITEM(14, 44), 0, 0, 0, 0);
	}
	else
	{
		gJewelBank.Pagina = 0;
		gJewelBank.DrawItemIMG( x, y-155, w, h, GET_ITEM(12, 15), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-122, w, h, GET_ITEM(14, 13), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-82, w, h, GET_ITEM(14, 14), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-44, w, h, GET_ITEM(14, 16), 0, 0, 0, 0);
		gJewelBank.DrawItemIMG( x, y-3, w, h, GET_ITEM(14, 22), 0, 0, 0, 0);
	}
}

void JewelBank::DrawItemIMG(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
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
