#include "stdafx.h"
#include "ItemShopValue.h" 

#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "HealthBar.h"
#include "Protect.h"
#include "Util.h"
#include "Item.h"
#include "TMemory.h"

ItemPrice gItemPrice;

ItemPrice::ItemPrice()
{
	
}

ItemPrice::~ItemPrice()
{
	
}

void ItemPrice::Init()
{
	for (int n = 0; n < MAX_ITEMPRICE; n++)
	{
		this->m_ItemPrice[n].ItemIndex = -1;
	}
	this->showtype = 0;
	this->showbuyprice = 0;
	this->showsellprice = 0;
	SetCompleteHook(0xFF, 0x007E44D3, &this->ShowBuyPrice);
	SetCompleteHook(0xFF, 0x007E452F, &this->ShowSellPrice);

	SetCompleteHook(0xE8,0x07E4497,&this->SetPriceRecv);
	SetCompleteHook(0xE8,0x07E44EC,&this->SetPriceRecv);

	//SetCompleteHook(0xE9,0x007E453D,&ChangeValueColor);
	
}

__declspec(naked) void ChangeValueColor()
{
	static DWORD AdressFinal = 0x007E4544;

	static int valor;
	_asm
	{
		//MOV DWORD PTR SS:[EBP-0x6C],0x05
		//mov     ecx, [ebp-0x6C]
        MOV DWORD PTR DS:[0x81C0A68],2 //cor
		//movzx   edx, byte ptr [eax+0x47]
		//movzx valor,[ebp+0x64]
		//movzx edx,valor
	}
	//gInterface.DrawFormat(eGold, 5, 391, 50, 1, "%d",valor);

	_asm
	{
		JMP [AdressFinal] 
	}
}

int StackItems[MAX_ITEMSTACK] = 
{6688, 6689, 6690, 6288, 6290, 6801, 6803, 7168, 7169, 7170, 7171, 7172, 7173, 7174, 7175, 7176, 7197, 7203, 7204, 7205, 
7206, 7207, 7008, 7214, 7215, 7216, 7217, 7218, 7238, 7239, 7253, 7254, 7255, 7256, 7257, 7258, 7268, 7269, 7278, 7301, 7389};



void ItemPrice::SetInfo(int index, int level,int newopt, int type, int value, int buysell, int sellvalue)
{
	if(index < 0)
	{
		return;
	}

	for(int n=0;n < MAX_ITEMPRICE;n++)
	{
		if (this->m_ItemPrice[n].ItemIndex == index && this->m_ItemPrice[n].Level == level && this->m_ItemPrice[n].Newopt == newopt && this->m_ItemPrice[n].BuySell == buysell)
		{
			if (this->m_ItemPrice[n].BuyPrice != value)
			{
				this->m_ItemPrice[n].BuyPrice	= value;
			}
			if (this->m_ItemPrice[n].Type != type)
			{
				this->m_ItemPrice[n].Type	= type;
			}
			if (this->m_ItemPrice[n].SellPrice != (value/3))
			{
				this->m_ItemPrice[n].SellPrice	= value/3;
			}
			if (this->m_ItemPrice[n].SellValue != sellvalue)
			{
				this->m_ItemPrice[n].SellValue	= sellvalue;
			}
			return;
		}
		if (this->m_ItemPrice[n].ItemIndex == -1)
		{
			this->m_ItemPrice[n].ItemIndex	= index;
			this->m_ItemPrice[n].Level		= level;
			this->m_ItemPrice[n].Newopt		= newopt;
			this->m_ItemPrice[n].Type		= type;
			this->m_ItemPrice[n].BuyPrice	= value;
			this->m_ItemPrice[n].SellPrice	= value/3;
			this->m_ItemPrice[n].BuySell	= buysell;
			this->m_ItemPrice[n].SellValue	= sellvalue;

			return;
		}
	}
}

int ItemPrice::GetInfo(int index)
{
	if(index < 0)
	{
		return -1;
	}

	for(int n=0;n < MAX_ITEMPRICE;n++)
	{
		if (this->m_ItemPrice[n].ItemIndex < 0)
		{
			continue;
		}

		if (this->m_ItemPrice[n].ItemIndex == index)
		{
			return n;
		}
	}
	return -1;
}

int ItemPrice::GetPrice(int index,int level,int newopt,int dur,int buysell)
{
	if(index < 0)
	{
		return 0;
	}

	level = GET_ITEMOPT_LEVEL(level);

	newopt = (newopt - GET_ITEMOPT16(newopt));

	dur = (dur<0)?(dur+256):dur;

		//		char log[1024];

		//sprintf(log,"%d %d %d %d %d",index,level,newopt,dur,buysell);

		//MessageBox(NULL,log,"Warning!",NULL);
	this->sellprice = 0;

	for(int n=0;n < MAX_ITEMPRICE;n++)
	{
		if (this->m_ItemPrice[n].ItemIndex < 0)
		{
			continue;
		}

		if (this->m_ItemPrice[n].ItemIndex == index && this->m_ItemPrice[n].Level == level && this->m_ItemPrice[n].Newopt == newopt && this->m_ItemPrice[n].BuySell == buysell)
		{

		//		char log[1024];

		//sprintf(log,"%d %d %d %d %d",index,level,newopt,dur,this->m_ItemPrice[n].SellValue);

		//MessageBox(NULL,log,"Warning!",NULL);

			this->type = this->m_ItemPrice[n].Type;

			if (this->GetItemStack(index) == 1)
			{
				if(buysell == 1 && this->m_ItemPrice[n].SellValue > 0)
				{
					this->sellprice = 1;
					return (this->m_ItemPrice[n].SellValue*dur);
				}
				return (this->m_ItemPrice[n].BuyPrice*dur);
			}
			else
			{
				if(buysell == 1 && this->m_ItemPrice[n].SellValue > 0)
				{
					this->sellprice = 1;
					return this->m_ItemPrice[n].SellValue;
				}
				return this->m_ItemPrice[n].BuyPrice;
			}
		}
	}
	return 0;
}

int ItemPrice::GetItemStack(int index)
{
	for (int n=0; n<MAX_ITEMSTACK; n++)
	{
		if (index == StackItems[n])
		{
			return 1;
		}
	}
	return 0;
}

bool ItemPrice::CheckItem(ObjectItem * lpItem, __int64 * Price, int * Divisor)
{
	//for (int i=0; i < MAX_ITEMPRICE; i++)
	//{
	//	if (this->m_ItemPrice[i].Index == -1 || this->m_ItemPrice[i].ItemIndex == -1)
	//	{
	//		this->showbuyprice = 0;
	//		this->showsellprice = 0;
	//		continue;
	//	}

	//	if (lpItem->ItemID != this->m_ItemPrice[i].ItemIndex)
	//	{
	//		this->showbuyprice = 0;
	//		this->showsellprice = 0;
	//		continue;
	//	}

	//	if (GET_ITEMOPT_LEVEL(lpItem->Level) != this->m_ItemPrice[i].Level && this->m_ItemPrice[i].Level != -1)
	//	{
	//		this->showbuyprice = 0;
	//		this->showsellprice = 0;
	//		continue;
	//	}

	//	int ExcellentOpt = lpItem->ExcellentOption;

	//	if (ExcellentOpt > 63)
	//	{
	//		ExcellentOpt -= 64;
	//	}

	//	if (ExcellentOpt != this->m_ItemPrice[i].Grade && this->m_ItemPrice[i].Grade != -1)
	//	{
	//		this->showbuyprice = 0;
	//		this->showsellprice = 0;
	//		continue;
	//	}

	//	////console.Log("", "Anc [%d %d] OptionEx [%d %d] Grade [%d]", this->m_ItemPrice[i].AncOption, lpItem->AncientOption, this->m_ItemPrice[i].OptionEx, lpItem->Is380Item, this->m_ItemPrice[i].Grade);

	//	if (this->m_ItemPrice[i].AncOption != lpItem->AncientOption && this->m_ItemPrice[i].AncOption != -1)
	//	{
	//		this->showbuyprice = 0;
	//		this->showsellprice = 0;
	//		continue;
	//	}

	//	if (this->m_ItemPrice[i].OptionEx != lpItem->Is380Item && this->m_ItemPrice[i].OptionEx != -1)
	//	{
	//		this->showbuyprice = 0;
	//		this->showsellprice = 0;
	//		continue;
	//	}

	//	for (int n=0; n<MAX_ITEMSTACK; n++)
	//	{
	//		if (lpItem->ItemID == StackItems[n])
	//		{
	//			int SellPrice = 0;

	//			if (this->m_ItemPrice[i].SellPrice == -1)
	//			{
	//				SellPrice = (this->m_ItemPrice[i].BuyPrice*lpItem->Durability) / 3;
	//			}
	//			else
	//			{
	//				SellPrice = (this->m_ItemPrice[i].SellPrice*lpItem->Durability);
	//			}
	//			////console.Log(FUNC, "%d durability [%d] total price [%d]", lpItem->ItemID, lpItem->Durability, this->m_ItemPrice[i].Value*lpItem->Durability);
	//			*Price		= this->m_ItemPrice[i].BuyPrice*lpItem->Durability;
	//			*Divisor	= SellPrice;
	//			this->showtype		=	this->m_ItemPrice[i].Type;
	//			this->showbuyprice = this->m_ItemPrice[i].BuyPrice*lpItem->Durability;
	//			this->showsellprice = SellPrice;
	//			return true;
	//		}
	//	}
	//	int SellPrice = 0;

	//	if (this->m_ItemPrice[i].SellPrice == -1)
	//	{
	//		SellPrice = this->m_ItemPrice[i].BuyPrice / 3;
	//	}
	//	else
	//	{
	//		SellPrice = this->m_ItemPrice[i].SellPrice;
	//	}

	//	*Price		= this->m_ItemPrice[i].BuyPrice;
	//	*Divisor	= SellPrice;
	//	this->showtype		=	this->m_ItemPrice[i].Type;
	//	this->showbuyprice = this->m_ItemPrice[i].BuyPrice;
	//	this->showsellprice = SellPrice;
	//	return true;
	//}
	//return false;

	return 0;
}

void ItemPrice::ShowBuyPrice(DWORD a1, const char *a2, char *Price)
{

	if(strcmp("0",Price) == 0)
	{
		if (gItemPrice.load == 1)
		{
			pSetItemTextLine(a1,"Loading ..");
			gItemPrice.load = 2;
		}
		else if(gItemPrice.load == 2)
		{
			pSetItemTextLine(a1,"Loading ...");
			gItemPrice.load = 3;
		}
		else if(gItemPrice.load == 3)
		{
			pSetItemTextLine(a1,"Loading ....");
			gItemPrice.load = 4;
		}
		else if(gItemPrice.load == 4)
		{
			pSetItemTextLine(a1,"Loading .....");
			gItemPrice.load = 0;
		}
		else
		{
			pSetItemTextLine(a1,"Loading .");
			gItemPrice.load = 1;
		}
	}
	else
	{
		if (gItemPrice.type == 1)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(46),Price);
		}
		else if (gItemPrice.type == 2)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(47),Price);
		}
		else if (gItemPrice.type == 3)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(48),Price);
		}
		else
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(45),Price);
		}
	}

}

void ItemPrice::ShowSellPrice(DWORD a1, const char *a2, char *Price)
{
	if(strcmp("0",Price) == 0)
	{
		if (gItemPrice.load == 1)
		{
			pSetItemTextLine(a1,"Loading ..");
			gItemPrice.load = 2;
		}
		else if(gItemPrice.load == 2)
		{
			pSetItemTextLine(a1,"Loading ...");
			gItemPrice.load = 3;
		}
		else if(gItemPrice.load == 3)
		{
			pSetItemTextLine(a1,"Loading ....");
			gItemPrice.load = 4;
		}
		else if(gItemPrice.load == 4)
		{
			pSetItemTextLine(a1,"Loading .....");
			gItemPrice.load = 0;
		}
		else
		{
			pSetItemTextLine(a1,"Loading .");
			gItemPrice.load = 1;
		}
	}
	else
	{
		if (gItemPrice.type == 1 && gItemPrice.sellprice > 0)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(55),Price);
		}
		else if (gItemPrice.type == 2 && gItemPrice.sellprice > 0)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(56),Price);
		}
		else if (gItemPrice.type == 3 && gItemPrice.sellprice > 0)
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(57),Price);
		}
		else
		{
			pSetItemTextLine(a1,gCustomMessage.GetMessage(49),Price);
		}
	}
}

int ItemPrice::SetPriceRecv(int a1,int a2)
{
    int ItemId		= *(WORD*)a1;
    int ItemLvl		= *(int*)(a1+2);
	int ItemDur		= *(char*)(a1+22);
	int ItemNewOpt	= *(char*)(a1+23);

	if(a2 == 1)
	{
		if(gItemPrice.sellprice != 0)
			return (gItemPrice.GetPrice(ItemId,ItemLvl,ItemNewOpt,ItemDur,1));
		else
			return (gItemPrice.GetPrice(ItemId,ItemLvl,ItemNewOpt,ItemDur,1)/3);
	}
	else
	{
		return gItemPrice.GetPrice(ItemId,ItemLvl,ItemNewOpt,ItemDur,0);
	}
}


void ItemPrice::GCItemValueRecv(PMSG_ITEM_VALUE_RECV* lpMsg) // OK
{
	for(int n=0;n < lpMsg->count;n++)
	{
		ITEM_VALUE_DATA* lpInfo = (ITEM_VALUE_DATA*)(((BYTE*)lpMsg)+sizeof(PMSG_ITEM_VALUE_RECV)+(sizeof(ITEM_VALUE_DATA)*n));

		this->SetInfo(lpInfo->index,lpInfo->level,lpInfo->newopt,lpInfo->type,lpInfo->value,lpInfo->buysell,lpInfo->sellvalue);
	}
}