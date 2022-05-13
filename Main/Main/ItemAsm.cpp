#include "stdafx.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "ItemAsm.h"
#include "Object.h"
#include "Import.h"
#include "Defines.h"
#include "CustomBow.h"

DWORD IsBowItem = 0;
DWORD IsCrossItem = 0;
DWORD BowValue = 0x09C;
DWORD MaxBoneCount = 0x108;
DWORD WorldPosition = 0x0FC;

DWORD oCreateEffect = 0x006D9070; // 1.04D ENG
DWORD ReturnBowCode = 0x0074A12E; // 1.04D ENG
DWORD BowPosition = 0x005CC8ED; // 1.04D ENG
DWORD NextBowPosition = 0x005CC92E; // 1.04D ENG
DWORD BowAddPlayerDimension_Offset = 0x0056617F; // 1.04D ENG
DWORD ReturnCrossCode	= 0x00749DD2;

void __declspec(naked) cBowAddSkillEffect()
{
	_asm
	{
			mov ecx, dword ptr ss : [ebp - 0x04]
			mov dword ptr ss : [ebp - 0x14], ecx
			mov IsBowItem, ecx
	}
	// ---
	
    if(gCustomBow.CheckCustomBow(IsBowItem - ITEM_INTER))
	{
		CUSTOM_BOW_INFO* bow = gCustomBow.GetInfoByItem(IsBowItem - ITEM_INTER);
		int SkillShot;
		if(bow != 0){
			SkillShot = bow->SkillShot;
			_asm
			{
				push - 1
				push 0
				push 0
				mov dx, word ptr ss : [ebp + 0x18]
				push edx
				mov ax, word ptr ss : [ebp + 0x14]
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				mov dx, word ptr ds : [ecx + 0x2C]
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				push eax
				mov ecx, dword ptr ss : [ebp - 0x8]
				push ecx
				mov edx, dword ptr ss : [ebp + 0x0C]
				add edx, BowValue
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				add eax, MaxBoneCount
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				add ecx, WorldPosition
				push ecx
				push SkillShot
				call oCreateEffect
			}
		}
	}
	_asm
	{
		jmp ReturnBowCode
	}
}

void __declspec(naked) cCrossAddSkillEffect()
{
    _asm
    {
		mov ecx, dword ptr ss : [ebp - 0x0C]
		mov dword ptr ss : [ebp - 0x10], ecx
		mov IsCrossItem, ecx
    }
    // ---
    if(gCustomBow.CheckCustomCross(IsCrossItem - ITEM_INTER))
	{
		CUSTOM_BOW_INFO* cross = gCustomBow.GetInfoByItem(IsCrossItem - ITEM_INTER);

		int SkillShot;

		if(cross != 0){

			SkillShot = cross->SkillShot;
			_asm
			{
				push - 1
				push 0
				push 0
				mov dx, word ptr ss : [ebp + 0x18]
				push edx
				mov ax, word ptr ss : [ebp + 0x14]
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				mov dx, word ptr ds : [ecx + 0x2C]
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				push eax
				mov ecx, dword ptr ss : [ebp - 0x8]
				push ecx
				mov edx, dword ptr ss : [ebp + 0x0C]
				add edx, BowValue
				push edx
				mov eax, dword ptr ss : [ebp + 0x0C]
				add eax, MaxBoneCount
				push eax
				mov ecx, dword ptr ss : [ebp + 0x0C]
				add ecx, WorldPosition
				push ecx
				push SkillShot
				call oCreateEffect
			}
		}
    }
    _asm
    {
        jmp ReturnCrossCode
    }
}


void __declspec(naked) cBowAddInventoryPos()
{
	_asm
	{
		mov ecx, dword ptr ss : [ebp + 0x8]
			mov dword ptr ss : [ebp + 0x8], ecx
			mov IsBowItem, ecx
	}
	// ---
	if (IsBowItem == 0x0CAB)
	{
		_asm{jmp BowPosition}
	}
	else if (IsBowItem > ITEM2(4,24) && IsBowItem < ITEM2(4,250) && !gCustomBow.CheckCustomCross(IsBowItem - 1171))
	{
		_asm{jmp BowPosition}
	}
	//CUSTOMPETS

	else if (IsBowItem >= ITEM2(13, 147) && IsBowItem <= ITEM2(13, 512))
	{
		_asm
		{
			Mov Ecx, 0x005CC597
				Jmp Ecx
		}
	}

//------------------
	else
	{
		_asm{jmp NextBowPosition}
	}
}


void __declspec(naked) cBowAddPlayerDimension()
{
	_asm
	{
			cmp dword ptr ss : [ebp + 0x1c], 0x0CA7
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 25)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 26)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 27)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 28)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 29)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 30)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 31)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 32)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 33)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 34)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 35)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 36)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 37)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 38)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 39)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 40)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 41)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 42)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 43)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 44)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 45)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 46)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 47)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 48)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 49)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 50)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 51)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 52)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 53)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 54)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 55)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 56)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 57)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 58)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 59)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 60)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 61)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 62)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 63)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 64)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 65)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 66)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 67)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 68)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 69)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 70)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 71)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 72)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 73)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 74)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 75)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 76)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 77)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 78)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 79)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 80)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 81)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 82)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 83)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 84)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 85)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 86)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 87)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 88)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 89)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 90)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 91)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 92)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 93)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 94)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 95)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 96)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 97)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 98)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 99)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 100)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 101)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 102)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 103)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 104)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 105)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 106)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 107)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 108)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 109)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 110)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 111)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 112)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 113)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 114)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 115)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 116)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 117)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 118)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 119)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 120)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 121)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 122)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 123)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 124)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 125)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 126)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 127)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 128)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 129)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 130)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 131)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 132)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 133)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 134)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 135)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 136)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 137)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 138)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 139)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 140)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 141)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 142)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 143)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 144)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 145)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 146)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 147)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 148)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 149)
			je ReturnLoad
			cmp dword ptr ss : [ebp + 0x1c], ITEM2(4, 150)
			ReturnLoad :
		// ---
		jmp BowAddPlayerDimension_Offset
	}
}

void __declspec(naked) cCrossBowAddPlayerDimension()
{
    static DWORD Address1 = 0x00565994;
    static DWORD Address2 = 0x005659E7;  

	_asm
	{
	   Mov Ecx, Dword ptr ss : [ebp + 0x1C]
	   Mov Dword ptr ss : [ebp + 0x1C],Ecx
	   Mov IsCrossItem, Ecx
	}

    if(IsCrossItem >= ITEM2(4,8) && IsCrossItem <= ITEM2(4,14)||IsCrossItem == ITEM2(4,16)||IsCrossItem == ITEM2(4,18)||IsCrossItem == ITEM2(4,19) || gCustomBow.CheckCustomCross(IsCrossItem - 1171)) // Devil Crossbow
    {
		_asm{jmp Address1}
	}
	else
	{
		_asm{jmp Address2}
	}
}

#define sub_599F10_Addr			((signed int(*)()) 0x599F10)

signed int __cdecl FixBowArrow(WORD *a1)
{
	signed int result;
	if ((int)(*a1/512) != 4 || *a1 == 2055 || *a1 == 2063)
	{
		return 0;
	}
	ItemBmdStruct* ItemInfo = pGetItemBmdStruct(*a1);
	if (ItemInfo == 0 || (*a1/512) != 4)
	{
		return 0;
	}
	if (ItemInfo->Slot == 0)
	{
		return 2;
	}
	if (ItemInfo->Slot == 1)
	{
		return 1;
	}
	return 0;
}

void InitBows()
{
	//FIX recarga de flechas
	SetCompleteHook(0xE8,0x5913D0+0xDB ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5913D0+0xF7 ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5A05C0+0x92 ,&FixBowArrow);
	SetCompleteHook(0xE8,0x5A05C0+0x1B5,&FixBowArrow);
	SetCompleteHook(0xE8,0x5B5FC0+0xD34,&FixBowArrow);
	SetCompleteHook(0xE8,0x7E04B0+0xF8 ,&FixBowArrow);
	//--
	SetRange((LPVOID)iBowAddSkillEffect, 6, ASM::NOP);
	SetJmp((LPVOID)iBowAddSkillEffect, cBowAddSkillEffect);
	// ----
	SetCompleteHook(0xE9, iBowAddInventoryPos, cBowAddInventoryPos);
	// ----
	for (int i = 0; i < 6; i++)
	{
		SetByte(0x0056595E + i, 0x90);
	}
	// ----
	SetRange((LPVOID)iBowAddPlayerDimension, 7, ASM::NOP);
	SetJmp((LPVOID)iBowAddPlayerDimension, cBowAddPlayerDimension);
	// ----
    SetRange((LPVOID)iCrossAddSkillEffect, 6, ASM::NOP);
    SetJmp((LPVOID)iCrossAddSkillEffect, cCrossAddSkillEffect);
	// ----
	SetRange((LPVOID)iCrossBowAddPlayerDimension, 6, ASM::NOP);
	SetJmp((LPVOID)iCrossBowAddPlayerDimension, cCrossBowAddPlayerDimension);
	// ----
}