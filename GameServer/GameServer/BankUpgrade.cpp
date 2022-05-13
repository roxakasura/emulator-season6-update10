#include "StdAfx.h"
#include "BankUpgrade.h"
#include "DSProtocol.h"
#include "User.h"
#include "ItemManager.h"
#include "Util.h"
#include "Notice.h"
#include "Message.h"

JewelryBank JCBankJewelry;

JewelryBank::JewelryBank( )
{
//--
	this->JCModeJewells[0].ItemID[0] = 6159;
	this->JCModeJewells[0].ItemLevel[0] = 0;
	this->JCModeJewells[0].ItemID[1] = 6285;
	this->JCModeJewells[0].ItemLevel[1] = 0;
	this->JCModeJewells[0].ItemID[2] = 6285;
	this->JCModeJewells[0].ItemLevel[2] = 1;
	this->JCModeJewells[0].ItemID[3] = 6285;
	this->JCModeJewells[0].ItemLevel[3] = 2;
	this->JCModeJewells[0].ItemID[4] = 6285;
	this->JCModeJewells[0].ItemLevel[4] = 3;
	this->JCModeJewells[0].ItemID[5] = 6285;
	this->JCModeJewells[0].ItemLevel[5] = 4;
	this->JCModeJewells[0].ItemID[6] = 6285;
	this->JCModeJewells[0].ItemLevel[6] = 5;
	this->JCModeJewells[0].ItemID[7] = -1;
	this->JCModeJewells[0].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[1].ItemID[0] = 7181;
	this->JCModeJewells[1].ItemLevel[0] = 0;
	this->JCModeJewells[1].ItemID[1] = 6174;
	this->JCModeJewells[1].ItemLevel[1] = 0;
	this->JCModeJewells[1].ItemID[2] = 6174;
	this->JCModeJewells[1].ItemLevel[2] = 1;
	this->JCModeJewells[1].ItemID[3] = 6174;
	this->JCModeJewells[1].ItemLevel[3] = 2;
	this->JCModeJewells[1].ItemID[4] = 6174;
	this->JCModeJewells[1].ItemLevel[4] = 3;
	this->JCModeJewells[1].ItemID[5] = 6174;
	this->JCModeJewells[1].ItemLevel[5] = 4;
	this->JCModeJewells[1].ItemID[6] = 6174;
	this->JCModeJewells[1].ItemLevel[6] = 5;
	this->JCModeJewells[1].ItemID[7] = -1;
	this->JCModeJewells[1].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[2].ItemID[0] = 512 * 14 + 14;
	this->JCModeJewells[2].ItemLevel[0] = 0;
	this->JCModeJewells[2].ItemID[1] = 6175;
	this->JCModeJewells[2].ItemLevel[1] = 0;
	this->JCModeJewells[2].ItemID[2] = 6175;
	this->JCModeJewells[2].ItemLevel[2] = 1;
	this->JCModeJewells[2].ItemID[3] = 6175;
	this->JCModeJewells[2].ItemLevel[3] = 2;
	this->JCModeJewells[2].ItemID[4] = 6175;
	this->JCModeJewells[2].ItemLevel[4] = 3;
	this->JCModeJewells[2].ItemID[5] = 6175;
	this->JCModeJewells[2].ItemLevel[5] = 4;
	this->JCModeJewells[2].ItemID[6] = 6175;
	this->JCModeJewells[2].ItemLevel[6] = 5;
	this->JCModeJewells[2].ItemID[7] = -1;
	this->JCModeJewells[2].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_LIFE].ItemID[0] = 512 * 14 + 16;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[1] = 512 * 12 + 136;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[2] = 512 * 12 + 136;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[3] = 512 * 12 + 136;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[4] = 512 * 12 + 136;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[5] = 512 * 12 + 136;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[6] = 512 * 12 + 136;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_LIFE].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_LIFE].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_CREATION].ItemID[0] = 512 * 14 + 22;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[1] = 512 * 12 + 137;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[2] = 512 * 12 + 137;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[3] = 512 * 12 + 137;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[4] = 512 * 12 + 137;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[5] = 512 * 12 + 137;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[6] = 512 * 12 + 137;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_CREATION].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_CREATION].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_STONE].ItemID[0] = 512 * 14 + 41;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_STONE].ItemID[1] = 512 * 12 + 139;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_STONE].ItemID[2] = 512 * 12 + 139;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_STONE].ItemID[3] = 512 * 12 + 139;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_STONE].ItemID[4] = 512 * 12 + 139;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_STONE].ItemID[5] = 512 * 12 + 139;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_STONE].ItemID[6] = 512 * 12 + 139;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_STONE].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_STONE].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[0] = 512 * 14 + 31;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[1] = 512 * 12 + 138;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[2] = 512 * 12 + 138;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[3] = 512 * 12 + 138;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[4] = 512 * 12 + 138;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[5] = 512 * 12 + 138;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[6] = 512 * 12 + 138;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_GUARDYAN].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[0] = 512 * 14 + 42;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[1] = 512 * 12 + 140;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[2] = 512 * 12 + 140;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[3] = 512 * 12 + 140;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[4] = 512 * 12 + 140;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[5] = 512 * 12 + 140;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[6] = 512 * 12 + 140;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_HARMONY].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_HARMONY].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_LOWER].ItemID[0] = 512 * 14 + 43;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[1] = 512 * 12 + 142;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[2] = 512 * 12 + 142;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[3] = 512 * 12 + 142;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[4] = 512 * 12 + 142;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[5] = 512 * 12 + 142;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[6] = 512 * 12 + 142;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_LOWER].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_LOWER].ItemLevel[7] = -1;
	//--
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[0] = 512 * 14 + 44;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[0] = 0;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[1] = 512 * 12 + 143;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[1] = 0;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[2] = 512 * 12 + 143;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[2] = 1;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[3] = 512 * 12 + 143;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[3] = 2;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[4] = 512 * 12 + 143;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[4] = 3;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[5] = 512 * 12 + 143;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[5] = 4;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[6] = 512 * 12 + 143;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[6] = 5;
	this->JCModeJewells[JEWELRY_HIGHER].ItemID[7] = -1;
	this->JCModeJewells[JEWELRY_HIGHER].ItemLevel[7] = -1;
	//--
}

JewelryBank::~JewelryBank( )
{
}

void JewelryBank::InitUserBank(LPOBJ lpObj)
{
	for (int Joya = 0; Joya < 15; Joya++)
	{
		lpObj->BankJewelry[Joya] = 0;
	}
}

void JewelryBank::SendMeJewelry(int aIndex)
{
	if (gObjIsConnected(aIndex) == false)
	{
		return;
	}
	// ---
	LPOBJ lpObj = &gObj[aIndex];
	// ---
	PMSG_JEWELSBANK pMsg = { 0 };
	// ---
	pMsg.h.set(0xFB, 0xE5, sizeof(pMsg));
	// ---
	pMsg.Chaos = lpObj->BankJewelry[0];
	pMsg.Bless = lpObj->BankJewelry[1];
	pMsg.Soul = lpObj->BankJewelry[2];
	pMsg.Life = lpObj->BankJewelry[3];
	pMsg.CreateonBank = lpObj->BankJewelry[4];
	pMsg.GemStoneBank = lpObj->BankJewelry[5];
	pMsg.GuardianBank = lpObj->BankJewelry[6];
	pMsg.HarmonyBank = lpObj->BankJewelry[7];
	pMsg.LowStoneBank = lpObj->BankJewelry[8];
	pMsg.HighStoneBank = lpObj->BankJewelry[9];
	// ---
	DataSend(aIndex, (LPBYTE)&pMsg, pMsg.h.size);
}

void ChargeJewelSlot(LPOBJ lpObj, int Joya, int cantidad, int slot)
{
	lpObj->BankJewelry[Joya] += cantidad;
	gItemManager.InventoryDelItem(lpObj->Index, slot);
	gItemManager.GCItemDeleteSend(lpObj->Index, slot, 1);
	GDCharacterInfoSaveSend(lpObj->Index);
	JCBankJewelry.SendMeJewelry(lpObj->Index);
}

void SubJewelSlot(LPOBJ lpObj, int Joya, int cantidad)
{
	lpObj->BankJewelry[Joya] -= cantidad;
	GDCharacterInfoSaveSend(lpObj->Index);
	JCBankJewelry.SendMeJewelry(lpObj->Index);
}

ITEM_JEWEL_BANK * ConsultItem( int type )
{
	return &JCBankJewelry.JCModeJewells[type];
}

void JewelryBank::RecvSubPacket(int aIndex, PMSG_JEWELBANK_SUB * aRecv)
{
	if (OBJMAX_RANGE(aIndex) == 0) { return; }

	LPOBJ lpObj = &gObj[aIndex];

	if(lpObj->Interface.use != 0)
	{
		return;
	}

	if( lpObj->BankJewelry[aRecv->Type] <= 0 )
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
		return;
	}

	int cantidad_existente = lpObj->BankJewelry[aRecv->Type];
	int cantidad_a_sacar = 0;

	switch( aRecv->Mode )
	{
	case 0:
		if( lpObj->BankJewelry[aRecv->Type] < 1 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 1;
		break;
	case 1:
		if( lpObj->BankJewelry[aRecv->Type] < 10 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 10;
		break;
	case 2:
		if( lpObj->BankJewelry[aRecv->Type] < 20 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 20;
		break;
	case 3:
		if( lpObj->BankJewelry[aRecv->Type] < 30 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 30;
		break;
	case 4:
		if( lpObj->BankJewelry[aRecv->Type] < 40 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 40;
		break;
	case 5:
		if( lpObj->BankJewelry[aRecv->Type] < 50 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 50;
		break;
	case 6:
		if( lpObj->BankJewelry[aRecv->Type] < 60 )
		{
			gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
			return;
		}
		cantidad_a_sacar = 60;
		break;
	case 7:
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
		return;
		break;
	}

	if((cantidad_existente - cantidad_a_sacar) < 0 )
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
		return;
	}

	ITEM_JEWEL_BANK * ItemInfoSub;
	ITEM_INFO ItemInfo;

	ItemInfoSub = ConsultItem(aRecv->Type);

	if( gItemManager.GetInfo( ItemInfoSub->ItemID[aRecv->Mode], &ItemInfo) == 0 )
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(874));
		return;
	}

	int crear = 0;

	int MaxY = ( gItemManager.GetInventoryMaxValue( lpObj )-INVENTORY_WEAR_SIZE ) / 8;

	for( int y = 0 ; y < MaxY; y++ )
	{
		for( int x = 0 ; x < 8; x++ )
		{
			if( lpObj->InventoryMap[((y*8)+x)] == 0xFF )
			{
				BYTE slot = gItemManager.InventoryRectCheck(lpObj->Index, x, y, ItemInfo.Width, ItemInfo.Height);

				if(slot != 0xFF)
				{
					if( crear == 0 )
					{
						BYTE ItemSocketOption[MAX_SOCKET_OPTION] = { 0xFF,0xFF,0xFF,0xFF,0xFF };

					GDCreateItemSend(lpObj->Index,
						0xEB,
						0,
						0,
						ItemInfoSub->ItemID[aRecv->Mode],
						(BYTE)ItemInfoSub->ItemLevel[aRecv->Mode],
						0,
						0,
						0,
						0,
						lpObj->Index,
						0,
						0,
						0,
						0,
						ItemSocketOption,
						0,
						0);
						//--
						crear = 1;

						SubJewelSlot(lpObj, aRecv->Type, cantidad_a_sacar );
					}
				}
			}
		}
	}
			
	if ( crear == 0 )
	{
		gNotice.GCNoticeSend(lpObj->Index, 1, 0, 0, 0, 0, 0, gMessage.GetMessage(876));
		return;
	}
}

void JewelryBank::RecvPacket(int aIndex, PMSG_JEWEL_BANK* aRecv)
{
	if (OBJMAX_RANGE(aIndex) == 0) { return; }

	LPOBJ lpObj = &gObj[aIndex];

	if(lpObj->Interface.use != 0)
	{
		return;
	}
	
	//-- Chaos
	if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 15))
	{
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 141))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 10, aRecv->Source );
			break;
		case 1:
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 20, aRecv->Source );
			break;
		case 2:
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 30, aRecv->Source );
			break;
		case 3:
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 40, aRecv->Source );
			break;
		case 4:
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 50, aRecv->Source );
			break;
		case 5:
		ChargeJewelSlot(lpObj, JEWELRY_CHAOS, 60, aRecv->Source );
			break;
		}
	}
	//-- bless
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 13))
	{
		ChargeJewelSlot(lpObj, JEWELRY_BLESS, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 30))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_BLESS, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_BLESS, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_BLESS, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_BLESS, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_BLESS, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_BLESS, 60, aRecv->Source );
			break;
		}
	}
	//-- soul
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 14))
	{
		ChargeJewelSlot(lpObj, JEWELRY_SOUL, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 31))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_SOUL, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_SOUL, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_SOUL, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_SOUL, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_SOUL, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_SOUL, 60, aRecv->Source );
			break;
		}
	}
	//-- lifes
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 16))
	{
		ChargeJewelSlot(lpObj, JEWELRY_LIFE, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 136))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_LIFE, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_LIFE, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_LIFE, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_LIFE, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_LIFE, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_LIFE, 60, aRecv->Source );
			break;
		}
	}
	//-- creation
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 22))
	{
		ChargeJewelSlot(lpObj, JEWELRY_CREATION, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 137))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_CREATION, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_CREATION, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_CREATION, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_CREATION, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_CREATION, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_CREATION, 60, aRecv->Source );
			break;
		}
	}
	//-- Genstone
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 41))
	{
		ChargeJewelSlot(lpObj, JEWELRY_STONE, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 139))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_STONE, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_STONE, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_STONE, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_STONE, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_STONE, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_STONE, 60, aRecv->Source );
			break;
		}
	}
	//-- guardian
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 31))
	{
		ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 138))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_GUARDYAN, 60, aRecv->Source );
			break;
		}
	}
	//-- Harmony
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 42))
	{
		ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 140))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_HARMONY, 60, aRecv->Source );
			break;
		}
	}
	//-- lower
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 43))
	{
		ChargeJewelSlot(lpObj, JEWELRY_LOWER, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 142))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_LOWER, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_LOWER, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_LOWER, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_LOWER, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_LOWER, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_LOWER, 60, aRecv->Source );
			break;
		}
	}
	//-- higgher
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(14, 44))
	{
		ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 1, aRecv->Source );
	}
	else if( lpObj->Inventory[ aRecv->Source ].m_Index == GET_ITEM(12, 143))
	{
		switch( lpObj->Inventory[ aRecv->Source ].m_Level )
		{
		case 0:
			ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 10, aRecv->Source );
			break;
		case 1:
			ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 20, aRecv->Source );
			break;
		case 2:
			ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 30, aRecv->Source );
			break;
		case 3:
			ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 40, aRecv->Source );
			break;
		case 4:
			ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 50, aRecv->Source );
			break;
		case 5:
			ChargeJewelSlot(lpObj, JEWELRY_HIGHER, 60, aRecv->Source );
			break;
		}
	}
}