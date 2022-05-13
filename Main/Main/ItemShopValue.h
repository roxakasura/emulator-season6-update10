#pragma once

#define MAX_ITEMPRICE	2000
#define MAX_ITEMSTACK	41
#include "Object.h"
#include "Protocol.h"

struct PMSG_ITEM_VALUE_RECV
{
	PSWMSG_HEAD h;
	int count;
};

struct ITEM_VALUE_DATA
{
	int index;
	int level;
	int newopt;
	int type;
	int value;
	int buysell;
	int sellvalue;
};

struct CUSTOM_ITEMPRICE
{
	int ItemIndex;
	int Level;
	int Newopt;
	int Type;
	int BuyPrice;
	int SellPrice;
	int BuySell;
	int SellValue;
};

class ItemPrice
{
public:
	ItemPrice();
	virtual ~ItemPrice();
	void Init();
	void Load(CUSTOM_ITEMPRICE* info);
	void SetInfo(int index, int level, int newopt, int lucky, int value, int buysell, int sellvalue);
	int GetInfo(int index);
	int GetPrice(int index,int level,int newopt,int dur,int buysell);
	int GetItemStack(int index);
	bool CheckItem(ObjectItem * lpItem, __int64 * Price, int * Divisor);
	static void ShowBuyPrice(DWORD a1, const char *a2, char *Price);
	static void ShowSellPrice(DWORD a1, const char *a2, char *Price);
	static int SetPriceRecv(int a1,int a2);
	void GCItemValueRecv(PMSG_ITEM_VALUE_RECV* lpMsg);
	CUSTOM_ITEMPRICE m_ItemPrice[MAX_ITEMPRICE];
	int		showtype;
	int		showsellprice;
	int		showbuyprice;
	int		load;
	int		type;
	int		sellprice;
}; extern ItemPrice gItemPrice;

void ChangeValueColor();