// CashShop.cpp: implementation of the CCashShop class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CashShop.h"
#include "QueryManager.h"
#include "SocketManager.h"
#include "Util.h"

CCashShop gCashShop;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCashShop::CCashShop() // OK
{

}

CCashShop::~CCashShop() // OK
{

}

void CCashShop::GDCashShopPointRecv(SDHP_CASH_SHOP_POINT_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	SDHP_CASH_SHOP_POINT_SEND pMsg;

	pMsg.header.set(0x18,0x00,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.result = 0;

	if(gQueryManager.ExecQuery("SELECT * FROM CashShopData WHERE AccountID='%s'",lpMsg->account) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		if(gQueryManager.ExecQuery("INSERT INTO CashShopData (AccountID,WCoinC,WCoinP,GoblinPoint) VALUES ('%s',0,0,0)",lpMsg->account) == 0)
		{
			gQueryManager.Close();

			pMsg.result = 1;
		}
		else
		{
			gQueryManager.Close();

			pMsg.WCoinC = 0;

			pMsg.WCoinP = 0;

			pMsg.GoblinPoint = 0;
		}
	}
	else
	{
		pMsg.WCoinC = gQueryManager.GetAsInteger("WCoinC");

		pMsg.WCoinP = gQueryManager.GetAsInteger("WCoinP");

		pMsg.GoblinPoint = gQueryManager.GetAsInteger("GoblinPoint");

		gQueryManager.Close();
	}

	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#else

	SDHP_CASH_SHOP_POINT_SEND pMsg;

	pMsg.header.set(0x18,0x00,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.result = 1;

	if(gQueryManager.ExecQuery("EXEC WZ_GetCoin '%s'",lpMsg->account) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		pMsg.WCoinC = 0;
		pMsg.WCoinP = 0;
		pMsg.GoblinPoint = 0;
		gQueryManager.Close();
	}
	else
	{
		pMsg.WCoinC = gQueryManager.GetResult(0);
		pMsg.WCoinP = gQueryManager.GetResult(1);
		pMsg.GoblinPoint = gQueryManager.GetResult(2);
		gQueryManager.Close();
	}
	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#endif
}

void CCashShop::GDCashShopItemBuyRecv(SDHP_CASH_SHOP_ITEM_BUY_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	SDHP_CASH_SHOP_ITEM_BUY_SEND pMsg;

	pMsg.header.set(0x18,0x01,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.result = 0;

	pMsg.PackageMainIndex = lpMsg->PackageMainIndex;

	pMsg.Category = lpMsg->Category;

	pMsg.ProductMainIndex = lpMsg->ProductMainIndex;

	pMsg.ItemIndex = lpMsg->ItemIndex;

	pMsg.CoinIndex = lpMsg->CoinIndex;

	pMsg.MileageFlag = lpMsg->MileageFlag;

	if(gQueryManager.ExecQuery("SELECT * FROM CashShopData WHERE AccountID='%s'",lpMsg->account) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		pMsg.result = 1;
	}
	else
	{
		pMsg.WCoinC = gQueryManager.GetAsInteger("WCoinC");

		pMsg.WCoinP = gQueryManager.GetAsInteger("WCoinP");

		pMsg.GoblinPoint = gQueryManager.GetAsInteger("GoblinPoint");

		gQueryManager.Close();

		if(gQueryManager.ExecQuery("SELECT count(*) FROM CashShopInventory WHERE AccountID='%s' AND InventoryType=%d",lpMsg->account,83) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
		{
			gQueryManager.Close();

			pMsg.result = 1;
		}
		else
		{
			pMsg.ItemCount = gQueryManager.GetResult(0);

			gQueryManager.Close();
		}
	}

	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#endif
}

void CCashShop::GDCashShopItemGifRecv(SDHP_CASH_SHOP_ITEM_GIF_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	SDHP_CASH_SHOP_ITEM_GIF_SEND pMsg;

	pMsg.header.set(0x18,0x02,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.result = 0;

	pMsg.PackageMainIndex = lpMsg->PackageMainIndex;

	pMsg.Category = lpMsg->Category;

	pMsg.ProductMainIndex = lpMsg->ProductMainIndex;

	pMsg.SaleZone = lpMsg->SaleZone;

	pMsg.ItemIndex = lpMsg->ItemIndex;

	pMsg.CoinIndex = lpMsg->CoinIndex;

	pMsg.MileageFlag = lpMsg->MileageFlag;

	memcpy(pMsg.GiftName,lpMsg->GiftName,sizeof(pMsg.GiftName));

	memcpy(pMsg.GiftText,lpMsg->GiftText,sizeof(pMsg.GiftText));

	gQueryManager.BindParameterAsString(1,lpMsg->GiftName,sizeof(lpMsg->GiftName));

	if(gQueryManager.ExecQuery("SELECT AccountID FROM Character WHERE Name=?") == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		pMsg.result = 1;
	}
	else
	{
		gQueryManager.GetAsString("AccountID",pMsg.GiftAccount,sizeof(pMsg.GiftAccount));

		gQueryManager.Close();

		if(gQueryManager.ExecQuery("SELECT * FROM CashShopData WHERE AccountID='%s'",lpMsg->account) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
		{
			gQueryManager.Close();

			pMsg.result = 1;
		}
		else
		{
			pMsg.WCoinC = gQueryManager.GetAsInteger("WCoinC");

			pMsg.WCoinP = gQueryManager.GetAsInteger("WCoinP");

			pMsg.GoblinPoint = gQueryManager.GetAsInteger("GoblinPoint");

			gQueryManager.Close();

			if(gQueryManager.ExecQuery("SELECT count(*) FROM CashShopInventory WHERE AccountID='%s' AND InventoryType=%d",pMsg.GiftAccount,71) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
			{
				gQueryManager.Close();

				pMsg.result = 1;
			}
			else
			{
				pMsg.ItemCount = gQueryManager.GetResult(0);

				gQueryManager.Close();
			}
		}
	}

	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#endif
}

void CCashShop::GDCashShopItemNumRecv(SDHP_CASH_SHOP_ITEM_NUM_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	SDHP_CASH_SHOP_ITEM_NUM_SEND pMsg;

	pMsg.header.set(0x18,0x03,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.result = 0;

	pMsg.InventoryPage = lpMsg->InventoryPage;

	pMsg.InventoryType = lpMsg->InventoryType;

	pMsg.ItemCount = 0;

	pMsg.PageCount = 0;

	if(gQueryManager.ExecQuery("SELECT * FROM CashShopInventory WHERE AccountID='%s' AND InventoryType=%d",lpMsg->account,lpMsg->InventoryType) == 0)
	{
		gQueryManager.Close();

		pMsg.result = 1;
	}
	else
	{
		while(gQueryManager.Fetch() != SQL_NO_DATA)
		{
			if((((pMsg.ItemCount++)/MAX_CASH_SHOP_PAGE_ITEM)+1) == lpMsg->InventoryPage)
			{
				pMsg.ProductInfo[pMsg.PageCount].BaseItemCode = gQueryManager.GetAsInteger("BaseItemCode");

				pMsg.ProductInfo[pMsg.PageCount].MainItemCode = gQueryManager.GetAsInteger("MainItemCode");

				pMsg.ProductInfo[pMsg.PageCount].PackageMainIndex = gQueryManager.GetAsInteger("PackageMainIndex");

				pMsg.ProductInfo[pMsg.PageCount].ProductBaseIndex = gQueryManager.GetAsInteger("ProductBaseIndex");

				pMsg.ProductInfo[pMsg.PageCount].ProductMainIndex = gQueryManager.GetAsInteger("ProductMainIndex");

				pMsg.ProductInfo[pMsg.PageCount].CoinValue = gQueryManager.GetAsFloat("CoinValue");

				pMsg.ProductInfo[pMsg.PageCount].ProductType = gQueryManager.GetAsInteger("ProductType");

				gQueryManager.GetAsString("GiftName",pMsg.ProductInfo[pMsg.PageCount].GiftName,sizeof(pMsg.ProductInfo[pMsg.PageCount].GiftName));

				gQueryManager.GetAsString("GiftText",pMsg.ProductInfo[pMsg.PageCount].GiftText,sizeof(pMsg.ProductInfo[pMsg.PageCount].GiftText));

				pMsg.PageCount++;
			}
		}

		gQueryManager.Close();
	}

	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#endif
}

void CCashShop::GDCashShopItemUseRecv(SDHP_CASH_SHOP_ITEM_USE_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	SDHP_CASH_SHOP_ITEM_USE_SEND pMsg;

	pMsg.header.set(0x18,0x04,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.result = 0;

	pMsg.BaseItemCode = lpMsg->BaseItemCode;

	pMsg.MainItemCode = lpMsg->MainItemCode;

	pMsg.ItemIndex = lpMsg->ItemIndex;

	pMsg.ProductType = lpMsg->ProductType;

	if(gQueryManager.ExecQuery("SELECT * FROM CashShopInventory WHERE BaseItemCode=%d",lpMsg->BaseItemCode) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		pMsg.result = 1;
	}
	else
	{
		pMsg.ProductInfo.BaseItemCode = gQueryManager.GetAsInteger("BaseItemCode");

		pMsg.ProductInfo.MainItemCode = gQueryManager.GetAsInteger("MainItemCode");

		pMsg.ProductInfo.PackageMainIndex = gQueryManager.GetAsInteger("PackageMainIndex");

		pMsg.ProductInfo.ProductBaseIndex = gQueryManager.GetAsInteger("ProductBaseIndex");

		pMsg.ProductInfo.ProductMainIndex = gQueryManager.GetAsInteger("ProductMainIndex");

		pMsg.ProductInfo.CoinValue = gQueryManager.GetAsFloat("CoinValue");

		pMsg.ProductInfo.ProductType = gQueryManager.GetAsInteger("ProductType");

		gQueryManager.GetAsString("GiftName",pMsg.ProductInfo.GiftName,sizeof(pMsg.ProductInfo.GiftName));

		gQueryManager.GetAsString("GiftText",pMsg.ProductInfo.GiftText,sizeof(pMsg.ProductInfo.GiftText));

		gQueryManager.Close();
	}

	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#endif
}

void CCashShop::GDCashShopPeriodicItemRecv(SDHP_CASH_SHOP_PERIODIC_ITEM_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	BYTE send[4096];

	SDHP_CASH_SHOP_PERIODIC_ITEM_SEND pMsg;

	pMsg.header.set(0x18,0x05,0);

	int size = sizeof(pMsg);

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.count = 0;

	SDHP_CASH_SHOP_PERIODIC_ITEM2 info;

	for(int n=0;n < lpMsg->count;n++)
	{
		SDHP_CASH_SHOP_PERIODIC_ITEM1* lpInfo = (SDHP_CASH_SHOP_PERIODIC_ITEM1*)(((BYTE*)lpMsg)+sizeof(SDHP_CASH_SHOP_PERIODIC_ITEM_RECV)+(sizeof(SDHP_CASH_SHOP_PERIODIC_ITEM1)*n));

		if(gQueryManager.ExecQuery("SELECT Time FROM CashShopPeriodicItem WHERE ItemSerial=%d",lpInfo->serial) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
		{
			gQueryManager.Close();
			gQueryManager.ExecQuery("INSERT INTO CashShopPeriodicItem (ItemSerial,Time) VALUES (%d,%d)",lpInfo->serial,0);
			gQueryManager.Close();

			info.slot = lpInfo->slot;
			info.serial = lpInfo->serial;
			info.time = 0;
		}
		else
		{
			info.slot = lpInfo->slot;
			info.serial = lpInfo->serial;
			info.time = gQueryManager.GetAsInteger("Time");

			gQueryManager.Close();
		}

		memcpy(&send[size],&info,sizeof(info));
		size += sizeof(info);

		pMsg.count++;
	}

	pMsg.header.size[0] = SET_NUMBERHB(size);
	pMsg.header.size[1] = SET_NUMBERLB(size);

	memcpy(send,&pMsg,sizeof(pMsg));

	gSocketManager.DataSend(index,send,size);

	#endif
}

void CCashShop::GDCashShopRecievePointRecv(SDHP_CASH_SHOP_RECIEVE_POINT_RECV* lpMsg,int index) // OK
{
	#if(DATASERVER_UPDATE>=501)

	SDHP_CASH_SHOP_RECIEVE_POINT_SEND pMsg;

	pMsg.header.set(0x18,0x06,sizeof(pMsg));

	pMsg.index = lpMsg->index;

	memcpy(pMsg.account,lpMsg->account,sizeof(pMsg.account));

	pMsg.CallbackFunc = lpMsg->CallbackFunc;

	pMsg.CallbackArg1 = lpMsg->CallbackArg1;

	pMsg.CallbackArg2 = lpMsg->CallbackArg2;

	if(gQueryManager.ExecQuery("SELECT * FROM CashShopData WHERE AccountID='%s'",lpMsg->account) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		pMsg.WCoinC = 0;

		pMsg.WCoinP = 0;

		pMsg.GoblinPoint = 0;
	}
	else
	{
		pMsg.WCoinC = gQueryManager.GetAsInteger("WCoinC");

		pMsg.WCoinP = gQueryManager.GetAsInteger("WCoinP");

		pMsg.GoblinPoint = gQueryManager.GetAsInteger("GoblinPoint");

		gQueryManager.Close();
	}

	gSocketManager.DataSend(index,(BYTE*)&pMsg,sizeof(pMsg));

	#endif
}

void CCashShop::GDCashShopAddPointSaveRecv(SDHP_CASH_SHOP_ADD_POINT_SAVE_RECV* lpMsg) // OK
{
	#if(DATASERVER_UPDATE>=501)

	char TargetAccount[11];

	memcpy(TargetAccount,((lpMsg->GiftAccount[0]==0)?lpMsg->account:lpMsg->GiftAccount),sizeof(TargetAccount));

	if(gQueryManager.ExecQuery("SELECT WCoinC,WCoinP,GoblinPoint FROM CashShopData WHERE AccountID='%s'",TargetAccount) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		gQueryManager.ExecQuery("INSERT INTO CashShopData (AccountID,WCoinC,WCoinP,GoblinPoint) VALUES ('%s',%d,%d,%d)",TargetAccount,lpMsg->AddWCoinC,lpMsg->AddWCoinP,lpMsg->AddGoblinPoint);

		gQueryManager.Close();
	}
	else
	{
		DWORD WCoinC = gQueryManager.GetAsInteger("WCoinC");

		DWORD WCoinP = gQueryManager.GetAsInteger("WCoinP");

		DWORD GoblinPoint = gQueryManager.GetAsInteger("GoblinPoint");

		gQueryManager.Close();

		gQueryManager.ExecQuery("UPDATE CashShopData SET WCoinC=%d,WCoinP=%d,GoblinPoint=%d WHERE AccountID='%s'",(((WCoinC+lpMsg->AddWCoinC)>0x7FFFFFFF)?0x7FFFFFFF:(WCoinC+lpMsg->AddWCoinC)),(((WCoinP+lpMsg->AddWCoinP)>0x7FFFFFFF)?0x7FFFFFFF:(WCoinP+lpMsg->AddWCoinP)),(((GoblinPoint+lpMsg->AddGoblinPoint)>0x7FFFFFFF)?0x7FFFFFFF:(GoblinPoint+lpMsg->AddGoblinPoint)),TargetAccount);

		gQueryManager.Close();
	}

	#endif
}

void CCashShop::GDCashShopSubPointSaveRecv(SDHP_CASH_SHOP_SUB_POINT_SAVE_RECV* lpMsg) // OK
{
	#if(DATASERVER_UPDATE>=501)

	char TargetAccount[11];

	memcpy(TargetAccount,((lpMsg->GiftAccount[0]==0)?lpMsg->account:lpMsg->GiftAccount),sizeof(TargetAccount));

	if(gQueryManager.ExecQuery("SELECT WCoinC,WCoinP,GoblinPoint FROM CashShopData WHERE AccountID='%s'",TargetAccount) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
	{
		gQueryManager.Close();

		gQueryManager.ExecQuery("INSERT INTO CashShopData (AccountID,WCoinC,WCoinP,GoblinPoint) VALUES ('%s',%d,%d,%d)",TargetAccount,0,0,0);

		gQueryManager.Close();
	}
	else
	{
		DWORD WCoinC = gQueryManager.GetAsInteger("WCoinC");

		DWORD WCoinP = gQueryManager.GetAsInteger("WCoinP");

		DWORD GoblinPoint = gQueryManager.GetAsInteger("GoblinPoint");

		gQueryManager.Close();

		gQueryManager.ExecQuery("UPDATE CashShopData SET WCoinC=%d,WCoinP=%d,GoblinPoint=%d WHERE AccountID='%s'",((lpMsg->SubWCoinC>WCoinC)?0:(WCoinC-lpMsg->SubWCoinC)),((lpMsg->SubWCoinP>WCoinP)?0:(WCoinP-lpMsg->SubWCoinP)),((lpMsg->SubGoblinPoint>GoblinPoint)?0:(GoblinPoint-lpMsg->SubGoblinPoint)),TargetAccount);

		gQueryManager.Close();

		if (lpMsg->SubWCoinC > 0 )
		{
		gQueryManager.ExecQuery("INSERT INTO LOG_CREDITOS (login,valor,tipo) VALUES ('%s',%d,%d)",TargetAccount,((lpMsg->SubWCoinC>WCoinC)?0:(-lpMsg->SubWCoinC)),4);

		gQueryManager.Close();
		}
	}

	#endif
}

void CCashShop::GDCashShopInsertItemSaveRecv(SDHP_CASH_SHOP_INSERT_ITEM_SAVE_RECV* lpMsg) // OK
{
	#if(DATASERVER_UPDATE>=501)

	char TargetAccount[11];

	memcpy(TargetAccount,((lpMsg->GiftAccount[0]==0)?lpMsg->account:lpMsg->GiftAccount),sizeof(TargetAccount));

	gQueryManager.BindParameterAsString(1,lpMsg->GiftName,sizeof(lpMsg->GiftName));

	gQueryManager.BindParameterAsString(2,lpMsg->GiftText,sizeof(lpMsg->GiftText));

	gQueryManager.ExecQuery("INSERT INTO CashShopInventory (MainItemCode,AccountID,InventoryType,PackageMainIndex,ProductBaseIndex,ProductMainIndex,CoinValue,ProductType,GiftName,GiftText) VALUES (%d,'%s',%d,%d,%d,%d,%f,%d,?,?)",0,TargetAccount,lpMsg->InventoryType,lpMsg->PackageMainIndex,lpMsg->ProductBaseIndex,lpMsg->ProductMainIndex,lpMsg->CoinValue,lpMsg->ProductType);

	gQueryManager.Close();

	#endif
}

void CCashShop::GDCashShopDeleteItemSaveRecv(SDHP_CASH_SHOP_DELETE_ITEM_SAVE_RECV* lpMsg) // OK
{
	#if(DATASERVER_UPDATE>=501)

	char TargetAccount[11];

	memcpy(TargetAccount,((lpMsg->GiftAccount[0]==0)?lpMsg->account:lpMsg->GiftAccount),sizeof(TargetAccount));

	gQueryManager.ExecQuery("DELETE FROM CashShopInventory WHERE BaseItemCode=%d",lpMsg->BaseItemCode);
	gQueryManager.Close();

	#endif
}

void CCashShop::GDCashShopPeriodicItemSaveRecv(SDHP_CASH_SHOP_PERIODIC_ITEM_SAVE_RECV* lpMsg) // OK
{
	#if(DATASERVER_UPDATE>=501)

	for(int n=0;n < lpMsg->count;n++)
	{
		SDHP_CASH_SHOP_PERIODIC_ITEM_SAVE* lpInfo = (SDHP_CASH_SHOP_PERIODIC_ITEM_SAVE*)(((BYTE*)lpMsg)+sizeof(SDHP_CASH_SHOP_PERIODIC_ITEM_SAVE_RECV)+(sizeof(SDHP_CASH_SHOP_PERIODIC_ITEM_SAVE)*n));

		if(gQueryManager.ExecQuery("SELECT ItemSerial FROM CashShopPeriodicItem WHERE ItemSerial=%d",lpInfo->serial) == 0 || gQueryManager.Fetch() == SQL_NO_DATA)
		{
			gQueryManager.Close();
			gQueryManager.ExecQuery("INSERT INTO CashShopPeriodicItem (ItemSerial,Time) VALUES (%d,%d)",lpInfo->serial,lpInfo->time);
			gQueryManager.Close();
		}
		else
		{
			gQueryManager.Close();
			gQueryManager.ExecQuery("UPDATE CashShopPeriodicItem SET Time=%d WHERE ItemSerial=%d",lpInfo->time,lpInfo->serial);
			gQueryManager.Close();
		}
	}

	#endif
}

//JewelBank
void CCashShop::GDBankExReqPoint(BANKEX_GD_REQ_POINT * aRecv, int aIndex)
{
	BANKEX_DG_GET_POINT pAnswer;
	pAnswer.h.set(0xFB, 0x01, sizeof(pAnswer));
	// ----
	if( !this->BankExReqPoint(aRecv->AccountID, &pAnswer) )
	{
		return;
	}
	// ----
	if( !this->BankExReq(aRecv->AccountID, &pAnswer) )
	{
		return;
	}
	// ----
	pAnswer.UserIndex = aRecv->UserIndex;
	gSocketManager.DataSend(aIndex,(BYTE*)&pAnswer,sizeof(pAnswer));

}

bool CCashShop::BankExReqPoint(char * AccountID, BANKEX_DG_GET_POINT * Result)
{
	// ----
	if( gQueryManager.ExecQuery("SELECT * FROM CustomJewelBank WHERE AccountID = '%s'", AccountID) == 0 || gQueryManager.Fetch() == SQL_NO_DATA )
	{
		gQueryManager.Close();
		// ----

		Result->Bless		= 0;
		Result->Soul		= 0;
		Result->Chaos		= 0;
		Result->Creation	= 0;
		Result->Life		= 0;
		Result->Harmony		= 0;
		Result->Guardian	= 0;
		Result->Gemstone	= 0;
		Result->LowRefine	= 0;
		Result->HigRefine	= 0;
		Result->Money		= 0;
/*		Result->Custom001	= 0;
		Result->Custom002	= 0;
		Result->Custom003	= 0;
		Result->Custom004	= 0;
		Result->Custom005	= 0;
		Result->Custom006	= 0;
		Result->Custom007	= 0;
		Result->Custom008	= 0;
		Result->Custom009	= 0;
		Result->Custom010	= 0;
		Result->Custom011	= 0;*/
		// ----
		//if( gQueryManager.ExecQuery("INSERT INTO %s (%s, %s) VALUES ('%s',%d)", this->BankExTable, this->BankExAccount , this->BankExColumn ,AccountID, 0) == 0 ) //d
		//{
		//	return false;
		//}
		// ----
		gQueryManager.Close();
	}
	else
	{
		Result->Bless		= 0;//gQueryManager.GetAsInteger("Bless");
		Result->Soul		= 0;//gQueryManager.GetAsInteger("Soul");
		Result->Chaos		= 0;//gQueryManager.GetAsInteger("Chaos");
		Result->Creation	= 0;//gQueryManager.GetAsInteger("Creation");
		Result->Life		= 0;//gQueryManager.GetAsInteger("Life");
		Result->Harmony		= 0;
		Result->Guardian	= 0;
		Result->Gemstone	= 0;
		Result->LowRefine	= 0;
		Result->HigRefine	= 0;
		Result->Money		= 0;
/*		Result->Custom001	= 0;
		Result->Custom002	= 0;
		Result->Custom003	= 0;
		Result->Custom004	= 0;
		Result->Custom005	= 0;
		Result->Custom006	= 0;
		Result->Custom007	= 0;
		Result->Custom008	= 0;
		Result->Custom009	= 0;
		Result->Custom010	= 0;
		Result->Custom011	= 0;*/
		gQueryManager.Close();
	}
	return true;
}
// -------------------------------------------------------------------------------

bool CCashShop::BankExReq(char * AccountID, BANKEX_DG_GET_POINT * Result)
{
	// ----
	if( gQueryManager.ExecQuery("SELECT * FROM CustomJewelBank WHERE AccountID = '%s'", AccountID) == 0 || gQueryManager.Fetch() == SQL_NO_DATA )
	{
		gQueryManager.Close();
		// ----
		Result->Bless		= 0;
		Result->Soul		= 0;
		Result->Chaos		= 0;
		Result->Creation	= 0;
		Result->Life		= 0;
		Result->Harmony		= 0;
		Result->Guardian	= 0;
		Result->Gemstone	= 0;
		Result->LowRefine	= 0;
		Result->HigRefine	= 0;
		Result->Money		= 0;
		//novas
/*		Result->Custom001	= 0;
		Result->Custom002	= 0;
		Result->Custom003	= 0;
		Result->Custom004	= 0;
		Result->Custom005	= 0;
		Result->Custom006	= 0;
		Result->Custom007	= 0;
		Result->Custom008	= 0;
		Result->Custom009	= 0;
		Result->Custom010	= 0;
		Result->Custom011	= 0;*/
		// ----
	if( gQueryManager.ExecQuery("INSERT INTO CustomJewelBank (AccountID,Bless,Soul,Chaos,Creation,Life,Harmony,Guardian,Gemstone,LowRefine,HigRefine,Money) VALUES ('%s',0,0,0,0,0,0,0,0,0,0,0)",AccountID) == 0 )
		{
			return false;
		}
		// ----
		gQueryManager.Close();
	}
	else
	{
		Result->Bless		= gQueryManager.GetAsInteger("Bless");
		Result->Soul		= gQueryManager.GetAsInteger("Soul");
		Result->Chaos		= gQueryManager.GetAsInteger("Chaos");
		Result->Creation	= gQueryManager.GetAsInteger("Creation");
		Result->Life		= gQueryManager.GetAsInteger("Life");
		Result->Harmony		= gQueryManager.GetAsInteger("Harmony");
		Result->Guardian	= gQueryManager.GetAsInteger("Guardian");
		Result->Gemstone	= gQueryManager.GetAsInteger("Gemstone");
		Result->LowRefine	= gQueryManager.GetAsInteger("LowRefine");
		Result->HigRefine	= gQueryManager.GetAsInteger("HigRefine");
		Result->Money		= gQueryManager.GetAsInteger("Money");

		
/*		Result->Custom001	= gQueryManager.GetAsInteger("Custom001");
		Result->Custom002	= gQueryManager.GetAsInteger("Custom002");
		Result->Custom003	= gQueryManager.GetAsInteger("Custom003");
		Result->Custom004	= gQueryManager.GetAsInteger("Custom004");
		Result->Custom005	= gQueryManager.GetAsInteger("Custom005");
		Result->Custom006	= gQueryManager.GetAsInteger("Custom006");
		Result->Custom007	= gQueryManager.GetAsInteger("Custom007");
		Result->Custom008	= gQueryManager.GetAsInteger("Custom008");
		Result->Custom009	= gQueryManager.GetAsInteger("Custom009");
		Result->Custom010	= gQueryManager.GetAsInteger("Custom010");
		Result->Custom011	= gQueryManager.GetAsInteger("Custom011");*/
		gQueryManager.Close();
	}
	return true;
}
// -------------------------------------------------------------------------------

void CCashShop::BankExSavePoint(BANKEX_GD_SAVE_POINT * aRecv)
{
	// ----
if (gQueryManager.ExecQuery("UPDATE CustomJewelBank SET Bless = %d, Soul = %d, Chaos = %d, Creation = %d, Life = %d, Harmony = %d, Guardian = %d, Gemstone = %d, LowRefine = %d, HigRefine =%d, Money = %d WHERE AccountID = '%s'",aRecv->Bless,
	aRecv->Soul,aRecv->Chaos,aRecv->Creation,aRecv->Life,aRecv->Harmony,aRecv->Guardian,aRecv->Gemstone,aRecv->LowRefine,aRecv->HigRefine,aRecv->Money,aRecv->AccountID) == 0)
	{
		LogAdd(LOG_RED, "[%s] Can't save CustomJewelBank! Account: %s", __FUNCTION__, aRecv->AccountID);
	}
	gQueryManager.Close();
}
// -------------------------------------------------------------------------------
