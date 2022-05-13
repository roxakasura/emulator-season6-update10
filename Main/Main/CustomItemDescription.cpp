#include "stdafx.h"
#include "CustomItemDescription.h"
#include "Defines.h"
#include "Import.h"
#include "Util.h"
#include "Object.h"
#include "TMemory.h"

CCustomItemDescription gCustomItemDescription;

CCustomItemDescription::CCustomItemDescription()
{

}

CCustomItemDescription::~CCustomItemDescription()
{

}

void CCustomItemDescription::Load(CUSTOM_DESCRIPTION_INFO* info) // OK
{
	for(int n=0;n < MAX_CUSTOM_DESCRIPTION;n++)
	{
		this->SetInfo(info[n]);
	}
}

void CCustomItemDescription::SetInfo(CUSTOM_DESCRIPTION_INFO info) // OK
{
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_DESCRIPTION)
	{
		return;
	}

	this->m_Info[info.Index] = info;
}

CUSTOM_DESCRIPTION_INFO* CCustomItemDescription::GetInfo(int index) // OK
{
	if(index < 0 || index >= MAX_CUSTOM_DESCRIPTION)
	{
		return 0;
	}

	if(this->m_Info[index].Index != index)
	{
		return 0;
	}

	return &this->m_Info[index];
}

CUSTOM_DESCRIPTION_INFO* CCustomItemDescription::GetInfoByItem(int ItemIndex) // OK
{
	for(int n=0;n < MAX_CUSTOM_DESCRIPTION;n++)
	{
		CUSTOM_DESCRIPTION_INFO* lpInfo = this->GetInfo(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->ItemIndex == ItemIndex)
		{
			return lpInfo;
		}
	}
	return 0;
}

short CCustomItemDescription::CheckItemDescriptionByItem(int ItemIndex) // OK
{
	if(this->GetInfoByItem(ItemIndex) != 0)
	{
		return 1;
	}
	return 0;
}

char* CCustomItemDescription::GetDescription(int ItemIndex) // OK
{
	CUSTOM_DESCRIPTION_INFO* lpInfo = this->GetInfoByItem(26);

	if(lpInfo == 0)
	{
		return 0;
	}

	return lpInfo->Description;
}

void CCustomItemDescription::AddText(char* Text,int Color,int Weight)
{
	*(&*(DWORD*)oItemText_Color + *(DWORD*)oItemText_Line)	= Color;
	*(&*(DWORD*)oItemText_Weight + *(DWORD*)oItemText_Line)	= Weight;

	*(DWORD*)oItemText_Line += 1;

	pSetItemTextLine(100 * (*(DWORD*)oItemText_Line) + oItemText_Index,Text);

	
}

__declspec(naked) void DescriptionLevel()
{
	static DWORD ItemCode;
	static int n;
	static int j;
	static DWORD DescAddress1 = 0x009CF6AA;
	static DWORD DescAddress2 = 0x007E59F0;


	_asm
	{
			//movsx edx, word ptr ss : [EDI]
			//mov ItemCode, ecx

PUSH 0x00D45A3C
MOV ECX,DWORD PTR SS:[EBP-0x74]
IMUL ECX,ECX,64
ADD ECX,0x081C0AE0
PUSH ECX
CALL [DescAddress1]
ADD ESP,8
PUSH 0x00D45A3C
MOV ECX,DWORD PTR SS:[EBP-0x74]
IMUL ECX,ECX,64
ADD ECX,0x081C0AE0
PUSH ECX
CALL [DescAddress1]
ADD ESP,8
JMP		[DescAddress2]

	}

	//gCustomItemDescription.AddText("Teste",8,0);

	 //---
 //   if(gCustomItemDescription.CheckItemDescriptionByItem(ItemCode) == 1)
	//{
	//	for(n=0;n < MAX_CUSTOM_DESCRIPTION;n++)
	//	{
	//		if(gCustomItemDescription.m_Info[n].ItemIndex == ItemCode)
	//		{
	//			if(gCustomItemDescription.m_Info[n].Description[0])
	//			{
	//				for(j = 0;j < MAX_CUSTOM_DESCRIPTION_LINES;j++)
	//				{
	//					if(gCustomItemDescription.m_Info[n].Line == j)
	//					{
	//						gCustomItemDescription.AddText(gCustomItemDescription.m_Info[n].Description,gCustomItemDescription.m_Info[n].Color,gCustomItemDescription.m_Info[n].Border);
	//					}
	//				}
	//			}
	//		}
	//	}
	//}

	_asm
	{
		//cmp     word ptr [edi], 1C0Eh
		JMP		[DescAddress2]
	}
}

void CCustomItemDescription::SetOptionText(lpItemObj lpItem, int Line, WORD OptionID, bool Arg4, int Arg5) 
{
	//g_Console.AddMessage(5,"%d",lpItem->ItemID);
	float ch, dch;

	int ItemID = lpItem->ItemID;

	//lpItemObj ITEM = (lpItemObj)ItemID1;

	int LevelUp = GET_ITEMOPT_LEVEL(lpItem->Level);
	//pSetItemTextLine(Line, "TI ZAEBAL(");

	pSetItemOptionText(lpItem->ItemID, Line, OptionID, Arg4, Arg5);

	pSetItemTextLine(Line+1,"teste aaaa");

	//if (!g_ItemRank.IsRankItem(ItemID))
	//{
	//	return;
	//}
	//// ----
	//switch (OptionID)
	//{
	//	case eItemOption::LifeIncrease:
	//		dch = modf(g_ItemRank.GetValue(ItemID, RankOpt::MAXHP) + g_ItemRank.AddBobusOpt(LevelUp, RankOpt::MAXHP), &ch);
	//		if ( dch )
	//		{
				//pSetItemTextLine(Line, "Increase Max HP");
	//		}

}

void CCustomItemDescription::Init()
{	
	//	SetByte(0x007E57D7, 0x89);
	//SetByte(0x007E57D8, 0xCA);
	//SetByte(0x007E57D9, 0x90);
	//SetByte(0x004FA5E4, 0x89);
	//SetByte(0x004FA5E5, 0xCA);
	//SetByte(0x004FA5E6, 0x90);
	//SetCompleteHook(0xE8, 0x004FA5E8, &this->SetOptionText); 
	//SetCompleteHook(0xE8, 0x007E57DB, &this->SetOptionText);

	//SetCompleteHook(0xE9,0x007E59D6,(DWORD)&DescriptionLevel);
}