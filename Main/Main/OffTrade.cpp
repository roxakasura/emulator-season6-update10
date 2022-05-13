#include "stdafx.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "OffTrade.h"
#include "Offset.h"
#include "Protect.h"
#include "Util.h"
#include "CustomMessage.h"
#include "Inter803.h"
#include "WindowsStruct.h"
#include "MiniMap.h"

cOffTrade gOffTrade;

cOffTrade::cOffTrade()
{
	this->ShopActive	= 0;
	this->TypeShop		= 0;
	this->Init();
}

cOffTrade::~cOffTrade()
{
	
}

void cOffTrade::Init()
{
	SetCompleteHook(0xFF, 0x007E4641, &this->ShowPrice);

	SetCompleteHook(0xFF, 0x007E4753, &this->ShowTwoString);

	SetCompleteHook(0xE9,0x007E46A0,&ChangePSValueColor);
}

__declspec(naked) void ChangePSValueColor()
{
	static DWORD AdressFinal = 0x007E46AB;
	_asm
	{
        MOV DWORD PTR DS:[EAX*4+0x81C0A68],0x08 //cor
		//MOV DWORD PTR DS:[EAX*4+0x7B52C30],0x02 //borda
        //INC EAX
		JMP [AdressFinal]
	}
}

void cOffTrade::ShowPrice(DWORD a1, const char *a2, char *Price)
{
	if(gOffTrade.ShopActive != 0 || gOffTrade.ShopList != 0)
	{
		if(gOffTrade.TypeShop == 0)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(61),Price);
		}
		else if(gOffTrade.TypeShop == 1)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(62),Price);
		}
		else if(gOffTrade.TypeShop == 2)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(63),Price);
		}
		else if(gOffTrade.TypeShop == 3)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(55),Price);
		}
		else if(gOffTrade.TypeShop == 4)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(56),Price);
		}
		else if(gOffTrade.TypeShop == 5)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(57),Price); 
		}
		else
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(49),Price);
		}
	}
	else
	{
		pSetItemTextLine(a1,gCustomMessage.GetMessage(64),Price);
	}
}

void cOffTrade::ShowTwoString(DWORD a1, const char *a2)
{
	if(gOffTrade.TypeShop == 0)
	{
		pSetItemTextLine(a1,"\n");
	}
	else if(gOffTrade.TypeShop == 1)
	{
		pSetItemTextLine(a1,"\n");
	}
	else if(gOffTrade.TypeShop == 2)
	{
		pSetItemTextLine(a1,"\n");		
	}
	else if(gOffTrade.TypeShop == 3)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(58));
	}
	else if(gOffTrade.TypeShop == 4)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(59));
	}
	else if(gOffTrade.TypeShop == 5)
	{
		pSetItemTextLine(a1,"\n",gCustomMessage.GetMessage(60));
	}
	else
	{
		pSetItemTextLine(a1,"You are short of Zen");
	}
}

void cOffTrade::DrawOffTradeWindow()
{

	if (gInterface.CheckWindow(ObjWindow::OtherStore) == false)
	{
		if(this->ShopList == 1)
		{
			this->ShopList = 0;
		}
	}

	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return;
	}


	int X = 0;
	if (gInterface.CheckWindow(ObjWindow::ExpandInventory))
	{
		X = 190;
	}else {
		X = 0;
	}

	gInterface.Data[eOFFTRADE_OPEN].OnShow = false;
	gInterface.Data[eOFFTRADE_JoB].OnShow = false;
	gInterface.Data[eOFFTRADE_JoS].OnShow = false;
	gInterface.Data[eOFFTRADE_JoC].OnShow = false;
	gInterface.Data[eOFFTRADE_WCC].OnShow = false;
	gInterface.Data[eOFFTRADE_WCP].OnShow = false;
	gInterface.Data[eOFFTRADE_WCG].OnShow = false;

	if(this->ShopActive != 0)
	{

		if(gProtect.m_MainInfo.CustomOffStoreEnable)
		{	
			//-- boton cerrar custom store
			if (gInterface.IsWorkZone(eSTORE_CLOSE))
			{
				if (gInterface.Data[eSTORE_CLOSE].OnClick)
				{
					//nuevo boton para cerrar custom store
					gInterface.DrawButton2(eSTORE_CLOSE, 300-X ,310, 0, 30);
					//boton para offstore
					gInterface.DrawButton2(eOFFTRADE_OPEN, 300-X ,350, 0, 0);
				}
				else
				{
					//nuevo boton para cerrar custom store
					gInterface.DrawButton2(eSTORE_CLOSE, 300-X ,310, 0, 90);
					//boton para offstore
					gInterface.DrawButton2(eOFFTRADE_OPEN, 300-X ,350, 0, 0);
				}
		
				gInterface.DrawToolTip(320-X, 300, "Close Custom-Store");
			}
			else if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
			{
				if (gInterface.Data[eOFFTRADE_OPEN].OnClick)
				{
					//nuevo boton para cerrar custom store
					gInterface.DrawButton2(eSTORE_CLOSE, 300-X ,310, 0, 0);
					//boton para offstore
					gInterface.DrawButton2(eOFFTRADE_OPEN, 300-X ,350, 0, 30);
				}
				else
				{
					//nuevo boton para cerrar custom store
					gInterface.DrawButton2(eSTORE_CLOSE, 300-X ,310, 0, 0);

					gInterface.DrawButton2(eOFFTRADE_OPEN, 300-X ,350, 0, 90);
				}
		
				gInterface.DrawToolTip(320-X, 340, "Open Off-Store");
			}
			else
			{
				//nuevo boton para cerrar custom store
				gInterface.DrawButton2(eSTORE_CLOSE, 300-X ,310, 0, 0);
				//boton para offstore
				gInterface.DrawButton2(eOFFTRADE_OPEN, 300-X ,350, 0, 0);
			}
			gInterface.DrawFormat(eYellow, 300-X, 320, 108, 3, "Close STORE");

			gInterface.DrawFormat(eYellow, 300-X, 360, 108, 3, "OFF STORE");

			gInterface.Data[eSTORE_CLOSE].OnShow = true;

			gInterface.Data[eOFFTRADE_OPEN].OnShow = true;
		}
		return;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoB)
	{
		gInterface.DrawGUI2(eOFFTRADE_JoB, 281.5-X, 341);
		gInterface.DrawFormat(eYellow, 252-X, 346, 100, 3, "Bless");
		gInterface.Data[eOFFTRADE_JoB].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoS)
	{
		gInterface.DrawGUI2(eOFFTRADE_JoS, 338-X, 341);
		gInterface.DrawFormat(eYellow, 309-X, 346, 100, 3, "Soul");
		gInterface.Data[eOFFTRADE_JoS].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableJoC)
	{
		gInterface.DrawGUI2(eOFFTRADE_JoC, 393.5-X, 341);
		gInterface.DrawFormat(eYellow, 364-X, 346, 100, 3, "Chaos");
		gInterface.Data[eOFFTRADE_JoC].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin1)
	{
		gInterface.DrawGUI2(eOFFTRADE_WCC, 281.5-X, 362);
		gInterface.DrawFormat(eYellow, 252-X, 368, 100, 3, gCustomMessage.GetMessage(58));
		gInterface.Data[eOFFTRADE_WCC].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin2)
	{
		gInterface.DrawGUI2(eOFFTRADE_WCP, 338-X, 362);
		gInterface.DrawFormat(eYellow, 309-X, 368, 100, 3, gCustomMessage.GetMessage(59));
		gInterface.Data[eOFFTRADE_WCP].OnShow = true;
	}

	if (gProtect.m_MainInfo.CustomStoreEnableCoin3)
	{
		gInterface.DrawGUI2(eOFFTRADE_WCG, 393.5-X, 362);
		gInterface.DrawFormat(eYellow, 364-X, 368, 100, 3, gCustomMessage.GetMessage(60));
		gInterface.Data[eOFFTRADE_WCG].OnShow = true;
	}
	// ----

	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i=0; i<6; i++)
	{
		if( gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Color = eGray100;
			// ----
			if( gInterface.Data[ObjectIDs[i]].OnClick )
			{
				Color = eGray150;
			}
			// ----
			gInterface.DrawColoredGUI(ObjectIDs[i], gInterface.Data[ObjectIDs[i]].X, gInterface.Data[ObjectIDs[i]].Y, Color);
		}
	}
}
// ----------------------------------------------------------------------------------------------
bool cOffTrade::EventCloseTradeWindow_Main(DWORD Event)
{	
	DWORD CurrentTick	= GetTickCount();

	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return false;
	}

	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i = 0; i<6; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Delay			= (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 500 )
			{
				return false;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			CGSendOffTrade(i);
		}
	}

	if (gInterface.IsWorkZone(eSTORE_CLOSE))
	{
		if (!gInterface.Data[eSTORE_CLOSE].OnShow)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - gInterface.Data[eSTORE_CLOSE].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[eSTORE_CLOSE].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eSTORE_CLOSE].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return false;
		}
		// ----
		gInterface.Data[eSTORE_CLOSE].EventTick = GetTickCount();
		CGSendOffTrade(7);
	}
	return false;
}

bool cOffTrade::EventOffTradeWindow_Main(DWORD Event)
{	
	DWORD CurrentTick	= GetTickCount();

	if (gInterface.CheckWindow(ObjWindow::Store) == false)
	{
		return false;
	}

	int ObjectIDs[6] = 
	{ 
		eOFFTRADE_JoB,
		eOFFTRADE_JoS,
		eOFFTRADE_JoC,
		eOFFTRADE_WCC,
		eOFFTRADE_WCP,
		eOFFTRADE_WCG
	};

	for (int i = 0; i<6; i++)
	{
		if (gInterface.IsWorkZone(ObjectIDs[i]) && gInterface.Data[ObjectIDs[i]].OnShow)
		{
			DWORD Delay			= (CurrentTick - gInterface.Data[ObjectIDs[i]].EventTick);

			if( Event == WM_LBUTTONDOWN )
			{
				gInterface.Data[ObjectIDs[i]].OnClick = true;
				return true;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].OnClick = false;
			// ----
			if( Delay < 500 )
			{
				return false;
			}
			// ----
			gInterface.Data[ObjectIDs[i]].EventTick = GetTickCount();

			CGSendOffTrade(i);
		}
	}

	if (gInterface.IsWorkZone(eOFFTRADE_OPEN))
	{
		if (!gInterface.Data[eOFFTRADE_OPEN].OnShow)
		{
			return false;
		}

		DWORD Delay			= (CurrentTick - gInterface.Data[eOFFTRADE_OPEN].EventTick);

		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[eOFFTRADE_OPEN].OnClick = true;
			return true;
		}
		// ----
		gInterface.Data[eOFFTRADE_OPEN].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return false;
		}
		// ----
		gInterface.Data[eOFFTRADE_OPEN].EventTick = GetTickCount();
		CGSendOffTrade(6);
	}
	return false;
}
// ----------------------------------------------------------------------------------------------

void cOffTrade::CGSendOffTrade(int Type)
{
	PMSG_OFFTRADE_SEND pMsg;
	pMsg.header.set(0xF3, 0xEB, sizeof(pMsg));
	pMsg.Type = Type;
	DataSend((BYTE*)&pMsg,pMsg.header.size);
}

void cOffTrade::RecvPShop(PMSG_OFFTRADE_RECV *Data)
{
		this->ShopList		= 1;
		this->TypeShop		= Data->Type;
}

void cOffTrade::PShopActiveRecv(PMSG_SHOPACTIVE_RECV *Data)
{
		this->ShopActive	= Data->Active;
		this->TypeShop		= Data->Type;
}

void cOffTrade::DrawOffTradeWindowEx700(float x, float y)
{
	int ObjectIDs[6] = { eOFFTRADE_JoB, eOFFTRADE_JoS, eOFFTRADE_JoC, eOFFTRADE_WCC, eOFFTRADE_WCP, eOFFTRADE_WCG };

	if(gOffTrade.ShopActive != 0)
	{
		gInterface.Data[eSTORE_CLOSE].OnShow = false;
		gInterface.Data[eOFFTRADE_OPEN].OnShow = false;
		gInterface.Data[eOFFTRADE_JoB].OnShow = false;
		gInterface.Data[eOFFTRADE_JoS].OnShow = false;
		gInterface.Data[eOFFTRADE_JoC].OnShow = false;
		gInterface.Data[eOFFTRADE_WCC].OnShow = false;
		gInterface.Data[eOFFTRADE_WCP].OnShow = false;
		gInterface.Data[eOFFTRADE_WCG].OnShow = false;

		if( gProtect.m_MainInfo.CustomOffStoreEnable )
		{
			gInterface.Data[eSTORE_CLOSE].OnShow = true;
			gInterface.Data[eSTORE_CLOSE].Width =  Return2X(TransForX(108));
			gInterface.DrawButtonRender(eSTORE_CLOSE, Return2X(x + TransForX(40)), y + 166, 0, 0);

			if ( pCheckMouseOver(Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30))
			{
				if( *(BYTE*)0x8793386 )
				{
					//-- Push 0.4680666625
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30, 0.0, 0.4680666625, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
				else
				{
					//-- Over 0.7010999322
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30, 0.0, 0.7010999322, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30, 0.0, 0.0, 0.8499999642, 0.2270333171, 1, 1, 0.0);
			}

			//--
			gInterface.Data[eOFFTRADE_OPEN].OnShow = true;
			gInterface.Data[eOFFTRADE_OPEN].Width = Return2X(TransForX(108));
			gInterface.DrawButtonRender(eOFFTRADE_OPEN, Return2X(x + TransForX(40)), y + 206, 0, 0);

			if ( pCheckMouseOver(Return2X(x + TransForX(40)), y + 206, Return2X(TransForX(108)), 30))
			{
				if( *(BYTE*)0x8793386 )
				{
					//-- Push 0.4680666625
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 206, Return2X(TransForX(108)), 30, 0.0, 0.4680666625, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
				else
				{
					//-- Over 0.7010999322
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 206, Return2X(TransForX(108)), 30, 0.0, 0.7010999322, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 206, Return2X(TransForX(108)), 30, 0.0, 0.0, 0.8499999642, 0.2270333171, 1, 1, 0.0);
			}
			//--
			gInterface.DrawFormat(eYellow, Return2X(x + TransForX(40)), y + 176, Return2X(TransForX(108)), 3, "Closed Store");
			gInterface.DrawFormat(eYellow, Return2X(x + TransForX(40)), y + 216, Return2X(TransForX(108)), 3, "OFF STORE");
		}
		else
		{
			gInterface.Data[eSTORE_CLOSE].OnShow = true;
			gInterface.Data[eSTORE_CLOSE].Width = Return2X(TransForX(108));
			gInterface.DrawButtonRender(eSTORE_CLOSE, Return2X(x + TransForX(40)), y + 166, 0, 0);

			if ( pCheckMouseOver(Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30))
			{
				if( *(BYTE*)0x8793386 )
				{
					//-- Push 0.4680666625
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30, 0.0, 0.4680666625, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
				else
				{
					//-- Over 0.7010999322
					RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30, 0.0, 0.7010999322, 0.8499999642, 0.2270333171, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(0x7BFD, Return2X(x + TransForX(40)), y + 166, Return2X(TransForX(108)), 30, 0.0, 0.0, 0.8499999642, 0.2270333171, 1, 1, 0.0);
			}
			gInterface.DrawFormat(eYellow, Return2X(x + TransForX(40)), y + 176, Return2X(TransForX(108)), 3, "Closed Store");
		}
		return;
	}

	char * ButtonText[ 6 ] = { "Bless", "Soul", "Chaos", gCustomMessage.GetMessage(58), gCustomMessage.GetMessage(59), gCustomMessage.GetMessage(60) };

	int ButtonEnabled[ 6 ] = { gProtect.m_MainInfo.CustomStoreEnableJoB, gProtect.m_MainInfo.CustomStoreEnableJoS,
		gProtect.m_MainInfo.CustomStoreEnableJoC, gProtect.m_MainInfo.CustomStoreEnableCoin1,
		gProtect.m_MainInfo.CustomStoreEnableCoin2, gProtect.m_MainInfo.CustomStoreEnableCoin3};


	float XButton;
	float YButton = 341;

	for(int k = 0 ; k < 2 ; k++)
	{
		XButton = x + TransForX(20);

		for(int j = 0 ; j < 3 ; j++)
		{
			DWORD Color = eWhite;

			gInterface.Data[ ObjectIDs[ j + 3 * k ] ].OnShow = true;
			gInterface.Data[ ObjectIDs[ j + 3 * k ] ].Width = Return2X(TransForX( 40 ));

			if ( !ButtonEnabled[ j + 3 * k ] )
			{
				gInterface.Data[ ObjectIDs[ j + 3 * k ] ].OnShow = false;
				continue;
			}

			gInterface.DrawButtonRender(ObjectIDs[ j + 3 * k ], Return2X(XButton), YButton, 0.0, 0.0);

			if ( pCheckMouseOver(Return2X(XButton), YButton, Return2X(TransForX( 40 )), 17))
			{
				Color = pMakeColor(220, 220, 220, 220);
			}
			RenderBitMapColored(0x7908, Return2X(XButton), YButton, Return2X(TransForX( 40 )), 17, 0.0, 0.0, 0.6235385537, 0.6235385537, Color);
		//	RenderBitmap(0x7908, Return2X(XButton), YButton, Return2X(TransForX( 40 )), 17, 0.0, 0.0, 0.6235385537, 0.6235385537, 1, 1, 0);

			pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
			pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

			pDrawText(pTextThis(), Return2X(XButton), YButton + 3, ButtonText[ j + 3 * k ], Return2X(TransForX( 40 )), 0, (LPINT) 3, 0);

			XButton += TransForX(56);
		}

		YButton += 21;
	}
}