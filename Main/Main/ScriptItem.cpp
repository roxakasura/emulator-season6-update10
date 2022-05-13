#include "StdAfx.h"
#include "Util.h"
#include "ScriptItem.h"
#include "UIControl.h"
#include "NewUISystem.h"
#include "NewUIPetInfoWindow.h"

CScriptItem g_ScriptItem;
ITEM_ATTRIBUTE* ItemAttribute;

CScriptItem::CScriptItem()
{
}

CScriptItem::~CScriptItem()
{
}

void CScriptItem::OpenItemScript(char* FileName)
{
	ItemAttribute = new ITEM_ATTRIBUTE[MAX_LINE_ITEM_BMD];
	memset(ItemAttribute, 0, sizeof(ITEM_ATTRIBUTE) * (MAX_LINE_ITEM_BMD));

	FILE* fp = fopen(FileName, "rb");
	if (fp != NULL)
	{
		int Size = sizeof(ITEM_ATTRIBUTE);

		BYTE* Buffer = new BYTE[Size * MAX_LINE_ITEM_BMD];
		fread(Buffer, Size * MAX_LINE_ITEM_BMD, 1u, fp);
		DWORD dwCheckSum;
		fread(&dwCheckSum, sizeof(DWORD), 1u, fp);
		fclose(fp);
		if (dwCheckSum != GenerateCheckSum2(Buffer, Size * MAX_LINE_ITEM_BMD, 0xE2F1))
		{
			char Text[256];
			sprintf(Text, "%s - File corrupted.", FileName);
			MessageBox(g_hWnd, Text, NULL, MB_OK);
			SendMessage(g_hWnd, WM_DESTROY, 0, 0);
		}
		else
		{
			BYTE* pSeek = Buffer;
			for (int i = 0; i < MAX_LINE_ITEM_BMD; i++)
			{
				BuxConvert(pSeek, Size);
				memcpy(&ItemAttribute[i], pSeek, Size);
				pSeek += Size;
			}
		}
		delete[] Buffer;
	}
	else
	{
		char Text[256];
		sprintf(Text, "%s - File not exist.", FileName);
		MessageBox(g_hWnd, Text, NULL, MB_OK);
		SendMessage(g_hWnd, WM_DESTROY, 0, 0);
	}
}

__declspec(naked) void data_changedmg()
{
	static DWORD var_addr = 0x0058BAC5;

	_asm
	{
		mov     ecx, dword ptr ss : [ebp - 4]
		movsx   dx, word ptr ds : [ecx + 0x28]
		mov     eax, dword ptr ss : [ebp + 8]
		mov     word ptr ds : [eax + 9] , dx
		mov     ecx, dword ptr ss : [ebp - 4]
		movsx   dx, word ptr ds : [ecx + 0x2A]
		mov     eax, dword ptr ss : [ebp + 8]
		mov     word ptr ds : [eax + 0xB] , dx
		JMP[var_addr]
	}
}

__declspec(naked) void data_change_dmgmin()
{
	static DWORD var_addr = 0x0058BB60;

	_asm
	{
		mov     eax, dword ptr ss : [ebp - 4]
		movsx   ecx, word ptr ds : [eax + 0x28]
		JMP[var_addr]
	}
}

__declspec(naked) void data_change_dmgmax()
{
	static DWORD var_addr = 0x0058BC97;

	_asm
	{
		mov     eax, dword ptr ss : [ebp - 4]
		movsx   ecx, word ptr ds : [eax + 0x2A]
		JMP[var_addr]
	}
}

__declspec(naked) void data_changedef_1()
{
	static DWORD var_addr = 0x0058BAE0;

	_asm
	{
		mov     ecx, dword ptr ss : [ebp - 4]
		movsx   edx, word ptr ds : [ecx + 0x2E]
		mov     eax, dword ptr ss : [ebp + 8]
		mov[eax + 0xE], edx
		JMP[var_addr]
	}
}

__declspec(naked) void data_changedef_2()
{
	static DWORD var_addr = 0x0058C0C2;

	_asm
	{
		mov     ecx, dword ptr ss : [ebp - 4]
		movsx   eax, word ptr ds : [ecx + 0x2E]
		JMP[var_addr]
	}
}

void __stdcall EquipClassTooltip(ITEM_ATTRIBUTE* Attribute, DWORD* NextLine, DWORD* a6)
{
	char v6[254];
	unsigned __int8 v24; // [sp+Bh] [bp-19h]@11
	signed int j; // [sp+Ch] [bp-18h]@8
	signed int i; // [sp+10h] [bp-14h]@2
	unsigned __int8 v27; // [sp+17h] [bp-Dh]@2
	int v28; // [sp+18h] [bp-Ch]@2
	char v29; // [sp+1Fh] [bp-5h]@2
	int v30; // [sp+20h] [bp-4h]@14

	int* dword_81C0A74 = (int*)0x81C0A74;
	int* dword_81C0A70 = (int*)0x81C0A70;

	int* TextBold = (int*)0x81C09F0;
	int* TextListColor = (int*)0x81C0A68;
	textlist* TextList = (textlist*)0x81C0AE0;

	if (Attribute)
	{
		v27 = GetBaseClass(*(BYTE*)(Hero + 19));
		v29 = GetStepClass(*(BYTE*)(Hero + 19));

		dword_81C0A74[*NextLine] = 0;
		dword_81C0A70[*NextLine] = 0;

		wsprintf(TextList[*NextLine], "\n");
		++* NextLine;
		++* a6;

		v28 = 0;

		for (i = 0; i < 8; ++i)
		{
			if (Attribute->RequireClass[i] == 1)
				++v28;
		}

		if (v28 != 8)
		{
			for (j = 0; j < 8; ++j)
			{
				v24 = Attribute->RequireClass[j];

				if (v24)
				{
					if (j != v27 || v24 > (signed int)(unsigned __int8)v29)
						v30 = 5;
					else
						v30 = 0;
					switch (j)
					{
					case 0:
						switch (v24)
						{
						case 1u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 20));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 2u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 25));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 3u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1669));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 1:
						switch (v24)
						{
						case 1u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 21));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 2u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 26));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 3u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1668));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 2:
						switch (v24)
						{
						case 1u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 22));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 2u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 27));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 3u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1670));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 3:
						if (v24 == 1)
						{
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 23));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
						}
						else if (v24 == 3)
						{
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1671));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 4:
						if (v24 == 1)
						{
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 24));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
						}
						else if (v24 == 3)
						{
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1672));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 5:
						switch (v24)
						{
						case 1u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1672));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 2u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1687));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 3u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 1689));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 6:
						if (v24 == 1)
						{
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 3150));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
						}
						else if (v24 == 3)
						{
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 3151));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					case 7:
						switch (v24)
						{
						case 1u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 3175));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						case 3u:
							sprintf_s(v6, GlobalText(GlobalLine, 0x3D), GlobalText(GlobalLine, 3176));
							wsprintf(TextList[*NextLine], v6);
							TextListColor[*NextLine] = v30;
							break;
						}
						TextBold[(*NextLine)++] = 0;
						break;
					default:
						continue;
					}
				}
			}
		}
	}
}

void CScriptItem::Init()
{
	BYTE SIZE_ITEM_BMD = sizeof(ITEM_ATTRIBUTE);
	BYTE AttackSpeed = 49;
	BYTE durabilidad = 51;
	BYTE Magicdurabilidad = 52;
	BYTE Strength = 54;
	BYTE Dexterity = 56;
	BYTE Energy = 58;
	BYTE Vitality = 60;
	BYTE Leadership = 62;
	BYTE ReqLevel = 64;
	//--
	SetCompleteHook(0xE8, 0x006340C5, &OpenItemScript);
	SetCompleteHook(0xE9, 0x007E7060, &EquipClassTooltip);
	//-- Damage
	SetCompleteHook(0xE9, 0x0058BAA7, &data_changedmg);		//-- Change Memory byte to word
	SetCompleteHook(0xE9, 0x0058BB59, &data_change_dmgmin);	//-- Change Memory byte to word
	SetCompleteHook(0xE9, 0x0058BC90, &data_change_dmgmax);	//-- Change Memory byte to word
	//-- Defense
	SetByte(0x0058C031 + 2, 46); //-- Defense
	SetByte(0x0058C044 + 3, 46); //-- Defense
	SetByte(0x0058C0BE + 3, 46); //-- Defense
	SetCompleteHook(0xE9, 0x0058BAD1, &data_changedef_1);	//-- Change Memory byte to word
	SetCompleteHook(0xE9, 0x0058C0BB, &data_changedef_2);	//-- Change Memory byte to word
	//--
	SetByte(0x0042809C + 2, SIZE_ITEM_BMD);
	SetDword(0x0042809F + 2, (DWORD)&ItemAttribute);
	SetByte(0x004E1161 + 2, SIZE_ITEM_BMD);
	SetDword(0x004E1164 + 2, (DWORD)&ItemAttribute);
	SetByte(0x004EAB0C + 2, SIZE_ITEM_BMD);
	SetDword(0x004EAB0F + 2, (DWORD)&ItemAttribute);
	SetByte(0x004EAB61 + 2, SIZE_ITEM_BMD);
	SetDword(0x004EAB64 + 2, (DWORD)&ItemAttribute); //-- SetType
	SetByte(0x004EAD13 + 2, SIZE_ITEM_BMD);
	SetDword(0x004EAD16 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0051BC7E + 2, SIZE_ITEM_BMD);
	SetDword(0x0051BC81 + 2, (DWORD)&ItemAttribute);
	//-- animacion
	SetByte(0x0054F268 + 2, SIZE_ITEM_BMD);
	SetDword(0x0054F26B + 2, (DWORD)&ItemAttribute);
	SetByte(0x0054F37F + 2, SIZE_ITEM_BMD);
	SetDword(0x0054F382 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0054F435 + 2, SIZE_ITEM_BMD);
	SetDword(0x0054F438 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0055015E + 2, SIZE_ITEM_BMD);
	SetDword(0x00550161 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00550273 + 2, SIZE_ITEM_BMD);
	SetDword(0x00550276 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0055046E + 2, SIZE_ITEM_BMD);
	SetDword(0x00550471 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00550583 + 2, SIZE_ITEM_BMD);
	SetDword(0x00550586 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00551CC8 + 2, SIZE_ITEM_BMD);
	SetDword(0x00551CCB + 2, (DWORD)&ItemAttribute);
	SetByte(0x00551D1E + 2, SIZE_ITEM_BMD);
	SetDword(0x00551D21 + 2, (DWORD)&ItemAttribute);
	//--
	SetByte(0x00551DD5 + 2, SIZE_ITEM_BMD);
	SetDword(0x00551DD8 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00551FE1 + 2, SIZE_ITEM_BMD);
	SetDword(0x00551FE4 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0058AB5B + 2, SIZE_ITEM_BMD);
	SetDword(0x0058AB5E + 2, (DWORD)&ItemAttribute);
	SetByte(0x0058B161 + 2, SIZE_ITEM_BMD);
	SetDword(0x0058B164 + 2, (DWORD)&ItemAttribute);
	//--
	SetByte(0x0058BA83 + 2, sizeof(ITEM_ATTRIBUTE));
	SetDword(0x0058BA86 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0058E2CE + 2, sizeof(ITEM_ATTRIBUTE));
	SetDword(0x0058E2D4 + 2, (DWORD)&ItemAttribute);
	//
	SetByte(0x0058E3D1 + 2, SIZE_ITEM_BMD);
	SetDword(0x0058E3D4 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005906F9 + 2, SIZE_ITEM_BMD);
	SetDword(0x005906FC + 2, (DWORD)&ItemAttribute);
	SetByte(0x0059197C + 2, SIZE_ITEM_BMD);
	SetDword(0x0059197F + 2, (DWORD)&ItemAttribute);
	SetByte(0x00591B33 + 2, SIZE_ITEM_BMD);
	SetDword(0x00591B36 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00591D54 + 2, SIZE_ITEM_BMD);
	SetDword(0x00591D57 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00592B6A + 2, SIZE_ITEM_BMD);
	SetDword(0x00592B6D + 2, (DWORD)&ItemAttribute);
	SetByte(0x00592CAA + 2, SIZE_ITEM_BMD);
	SetDword(0x00592CAD + 2, (DWORD)&ItemAttribute);
	SetByte(0x00592EBE + 2, SIZE_ITEM_BMD);
	SetDword(0x00592EC1 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0059358F + 2, SIZE_ITEM_BMD);
	SetDword(0x00593592 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005936AE + 2, SIZE_ITEM_BMD);
	SetDword(0x005936B1 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0059496A + 2, SIZE_ITEM_BMD);
	SetDword(0x0059496D + 2, (DWORD)&ItemAttribute);
	SetByte(0x00594CDC + 2, SIZE_ITEM_BMD);
	SetDword(0x00594CDF + 2, (DWORD)&ItemAttribute);
	SetByte(0x005A843C + 2, SIZE_ITEM_BMD);
	SetDword(0x005A843F + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C0956 + 2, SIZE_ITEM_BMD);
	SetDword(0x005C0959 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C1A08 + 2, SIZE_ITEM_BMD);
	SetDword(0x005C1A0B + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C1B3D + 2, SIZE_ITEM_BMD);
	SetDword(0x005C1B40 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C2439 + 2, SIZE_ITEM_BMD);
	SetDword(0x005C243C + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C3FCF + 2, SIZE_ITEM_BMD);
	SetDword(0x005C3FD2 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C7413 + 2, SIZE_ITEM_BMD);
	SetDword(0x005C7416 + 1, (DWORD)&ItemAttribute);
	SetByte(0x005C7430 + 2, SIZE_ITEM_BMD);
	SetDword(0x005C7433 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C7C2A + 2, SIZE_ITEM_BMD);
	SetDword(0x005C7C2D + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C7DCF + 2, SIZE_ITEM_BMD);
	SetDword(0x005C7DD2 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005C7F75 + 2, SIZE_ITEM_BMD);
	SetDword(0x005C7F78 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005CA8AC + 2, SIZE_ITEM_BMD);
	SetDword(0x005CA8AF + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4B9B + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4B9E + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4BFC + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4BFF + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4C33 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4C36 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4D4F + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4D52 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4D91 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4D94 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4DD3 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4DD6 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4E12 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4E15 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4E51 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4E54 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4EC6 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4EC9 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F4F04 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F4F07 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F56D1 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F56D4 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F5702 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F5705 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F5773 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F5776 + 2, (DWORD)&ItemAttribute);
	SetByte(0x005F5797 + 2, SIZE_ITEM_BMD);
	SetDword(0x005F579A + 2, (DWORD)&ItemAttribute);
	SetByte(0x00783E3B + 2, SIZE_ITEM_BMD);
	SetDword(0x00783E3E + 2, (DWORD)&ItemAttribute);
	SetByte(0x00784748 + 2, SIZE_ITEM_BMD);
	SetDword(0x0078474B + 2, (DWORD)&ItemAttribute);
	SetByte(0x007A796C + 2, SIZE_ITEM_BMD);
	SetDword(0x007A796F + 2, (DWORD)&ItemAttribute);
	SetByte(0x007C7141 + 2, SIZE_ITEM_BMD);
	SetDword(0x007C7144 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007C7161 + 2, SIZE_ITEM_BMD);
	SetDword(0x007C7164 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007D933D + 2, SIZE_ITEM_BMD);
	SetDword(0x007D9340 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007D9574 + 2, SIZE_ITEM_BMD);
	SetDword(0x007D9577 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007D9B7B + 2, SIZE_ITEM_BMD);
	SetDword(0x007D9B7E + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DA148 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DA14B + 2, (DWORD)&ItemAttribute);	//-- Recv Object Item Save in Inventory
	SetByte(0x007DA278 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DA27B + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DA3CE + 2, SIZE_ITEM_BMD);
	SetDword(0x007DA3D1 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DA507 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DA50A + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DB0F3 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DB0F6 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DB533 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DB536 + 1, (DWORD)&ItemAttribute);
	SetByte(0x007DBAF0 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DBAF3 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DC69B + 2, SIZE_ITEM_BMD);
	SetDword(0x007DC69E + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DC6DF + 2, SIZE_ITEM_BMD);
	SetDword(0x007DC6E2 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DC90F + 2, SIZE_ITEM_BMD);
	SetDword(0x007DC912 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DCF3F + 2, SIZE_ITEM_BMD);
	SetDword(0x007DCF42 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DD4FE + 2, SIZE_ITEM_BMD);
	SetDword(0x007DD501 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DF5EA + 2, SIZE_ITEM_BMD);
	SetDword(0x007DF5ED + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DFC26 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DFC29 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007DFF17 + 2, SIZE_ITEM_BMD);
	SetDword(0x007DFF1A + 2, (DWORD)&ItemAttribute);
	//--
	SetByte(0x007E0611 + 2, SIZE_ITEM_BMD);
	SetDword(0x007E0614 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007E093A + 2, SIZE_ITEM_BMD);
	SetDword(0x007E093D + 2, (DWORD)&ItemAttribute);
	SetByte(0x007E115A + 2, SIZE_ITEM_BMD);
	SetDword(0x007E115D + 2, (DWORD)&ItemAttribute);
	SetByte(0x007E3EDD + 2, SIZE_ITEM_BMD);
	SetDword(0x007E3EE0 + 2, (DWORD)&ItemAttribute);
	SetByte(0x007EED7F + 2, SIZE_ITEM_BMD);
	SetDword(0x007EED82 + 1, (DWORD)&ItemAttribute);
	SetByte(0x007EEDA1 + 2, SIZE_ITEM_BMD);
	SetDword(0x007EEDA4 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0082FA1F + 2, SIZE_ITEM_BMD);
	SetDword(0x0082FA22 + 1, (DWORD)&ItemAttribute);
	SetByte(0x0082FA41 + 2, SIZE_ITEM_BMD);
	SetDword(0x0082FA44 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00833CD2 + 2, SIZE_ITEM_BMD);
	SetDword(0x00833CD5 + 2, (DWORD)&ItemAttribute);
	SetByte(0x008359EA + 2, SIZE_ITEM_BMD);
	SetDword(0x008359ED + 2, (DWORD)&ItemAttribute);
	SetByte(0x00837126 + 2, SIZE_ITEM_BMD);
	SetDword(0x00837129 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0083A7DA + 2, SIZE_ITEM_BMD);
	SetDword(0x0083A7DD + 2, (DWORD)&ItemAttribute);
	SetByte(0x00858BB8 + 2, SIZE_ITEM_BMD);
	SetDword(0x00858BBB + 2, (DWORD)&ItemAttribute);
	SetByte(0x00864F83 + 2, SIZE_ITEM_BMD);
	SetDword(0x00864F86 + 2, (DWORD)&ItemAttribute);
	SetByte(0x008669DA + 2, SIZE_ITEM_BMD);
	SetDword(0x008669DD + 2, (DWORD)&ItemAttribute);
	SetByte(0x00943ABD + 2, SIZE_ITEM_BMD);
	SetDword(0x00943AC0 + 2, (DWORD)&ItemAttribute);
	SetByte(0x0095F756 + 2, SIZE_ITEM_BMD);
	SetDword(0x0095F759 + 2, (DWORD)&ItemAttribute);
	SetByte(0x00943BB5 + 2, SIZE_ITEM_BMD);
	SetDword(0x00943BB8 + 2, (DWORD)&ItemAttribute);
	//-- RequireStrength
	SetByte(0x0058C5DB + 3, Strength); //-- RequireStrength
	SetByte(0x0058C5E6 + 3, Strength); //-- RequireStrength
	SetByte(0x005C0CCE + 3, Strength); //-- 
	SetByte(0x005C0CD9 + 3, Strength); //-- 
	//-- RequireDexterity
	SetByte(0x005C0D0C + 3, Dexterity); //-- 
	SetByte(0x005C0D17 + 3, Dexterity); //-- 
	SetByte(0x0058C619 + 3, Dexterity); //-- 
	SetByte(0x0058C624 + 3, Dexterity); //-- 
	//-- RequireEnergy
	SetByte(0x005C0D88 + 3, Energy); //-- 
	SetByte(0x005C0DBB + 3, Energy); //-- 
	SetByte(0x005C0E05 + 3, Energy); //-- 
	SetByte(0x005C0E29 + 3, Energy); //-- 
	SetByte(0x0058C695 + 3, Energy); //-- 
	SetByte(0x0058C6CD + 3, Energy); //-- RequireEnergy
	SetByte(0x0058C71A + 3, Energy); //-- RequireEnergy
	SetByte(0x0058C742 + 3, Energy); //-- RequireEnergy
	//--
	SetByte(0x005C0D4A + 3, Vitality); //-- 
	SetByte(0x005C0D55 + 3, Vitality); //-- 
	SetByte(0x0058C657 + 3, Vitality); //-- RequireVitality
	SetByte(0x0058C662 + 3, Vitality); //-- RequireVitality
	//--
	SetByte(0x0058C775 + 3, Leadership); //-- RequireLeadership
	SetByte(0x0058C780 + 3, Leadership); //-- RequireLeadership
	SetByte(0x0058C832 + 3, Leadership); //-- RequireLeadership
	SetByte(0x0058C84B + 3, Leadership); //-- RequireLeadership
	SetByte(0x0058C866 + 3, Leadership); //-- RequireLeadership
	SetByte(0x005C0E5C + 3, Leadership); //-- 
	SetByte(0x005C0E67 + 3, Leadership); //-- 
	//--
	SetByte(0x0058C6F4 + 3, ReqLevel); //-- RequireLevel
	SetByte(0x0058C721 + 3, ReqLevel); //-- RequireLevel
	SetByte(0x0058C4D7 + 3, ReqLevel); //-- RequireLevel
	SetByte(0x0058C54F + 3, ReqLevel); //-- RequireLevel
	SetByte(0x0058C55C + 3, ReqLevel); //-- RequireLevel
	SetByte(0x0058C5B9 + 3, ReqLevel); //-- RequireLevel
	SetByte(0x005C0DE2 + 3, ReqLevel); //-- 
	SetByte(0x005C0E0C + 3, ReqLevel); //-- 
	SetByte(0x0083A7E3 + 4, ReqLevel); //-- 

	SetByte(0x005C09B5 + 3, 42); //-- 
	//--SuccessRate
	SetByte(0x005C09D3 + 3, 44); //-- 
	SetByte(0x005C0CB0 + 3, 44); //-- 
	SetByte(0x005C0CBB + 3, 44); //-- 
	SetByte(0x0058BACB + 2, 44); //-- SuccessRate
	SetByte(0x0058BE02 + 3, 53); //-- Magic Power

	SetByte(0x0058BF32 + 3, 44); //-- SuccessRate
	SetByte(0x0058BF52 + 3, 44); //-- SuccessRate
	//--
	SetByte(0x005C09BF + 3, 45); //-- 
	//--MagicDefense
	SetByte(0x0058BAE3 + 4, 48); //-- MagicDefense
	SetByte(0x0058C3AA + 3, 48); //-- MagicDefense
	//--AttackSpeed
	SetByte(0x007E6390 + 3, AttackSpeed); //-- AttackSpeed
	SetByte(0x0058BAA1 + 2, AttackSpeed); //-- AttackSpeed
	//--WalkSpeed
	SetByte(0x0058BAF2 + 4, AttackSpeed + 1); //-- WalkSpeed
	SetByte(0x007E63B0 + 3, AttackSpeed + 1); //-- WalkSpeed
	//--Durability
	SetByte(0x0059198B + 3, durabilidad); //-- Durability
	SetByte(0x005919AB + 3, durabilidad); //-- Durability
	SetByte(0x00591B59 + 3, durabilidad); //-- Durability
	SetByte(0x00591D7A + 3, durabilidad); //-- Durability
	SetByte(0x00592B90 + 3, durabilidad); //-- Durability
	SetByte(0x00592CD0 + 3, durabilidad); //-- Durability
	SetByte(0x00592EE4 + 3, durabilidad); //-- Durability
	SetByte(0x0058E57B + 3, durabilidad); //-- Durability
	SetByte(0x0058E591 + 3, durabilidad); //-- Durability
	SetByte(0x0058E5FC + 3, durabilidad); //-- Durability
	SetByte(0x0058E612 + 3, durabilidad); //-- Durability
	SetByte(0x005C2179 + 4, durabilidad); //-- Durability
	SetByte(0x005C2591 + 3, durabilidad); //-- Durability
	SetByte(0x00594D62 + 3, durabilidad); //-- Durability
	SetByte(0x00594D06 + 3, durabilidad); //-- Durability
	SetByte(0x00594990 + 3, durabilidad); //-- Durability
	SetByte(0x00593704 + 3, durabilidad); //-- Durability
	SetByte(0x005935D9 + 3, durabilidad); //-- Durability
	SetByte(0x005935D9 + 3, durabilidad); //-- Durability
	//--MagicDurability
	SetByte(0x00784774 + 3, Magicdurabilidad); //-- 
	SetByte(0x00783E70 + 3, Magicdurabilidad); //-- MagicDurability
	SetByte(0x005C21A0 + 4, Magicdurabilidad); //-- MagicDurability
	//--MagicDamageRate
	SetByte(0x005C09C9 + 3, 53); //--
	SetByte(0x0058BB04 + 2, 53); //-- 
	SetByte(0x0058BDCA + 3, 53); //-- MagicDamageRate
	SetByte(0x0058BE02 + 3, 53); //-- MagicDamageRate
	//--
	SetByte(0x0058E3EE + 2, 68); //-- iZen
	SetByte(0x0058E3FB + 2, 68); //-- iZen
	//--
	SetByte(0x0058F234 + 3, 67); //-- iZen
	SetByte(0x0058F243 + 3, 67); //-- iZen
	SetByte(0x0058F24A + 3, 67); //-- iZen
	//--
	SetByte(0x004EAB1B + 3, 71); //-- AttType
	SetByte(0x004EAB6A + 4, 71); //-- AttType
	//-- ok
	SetByte(0x0059071F + 4, 73); //-- check class equip
	SetByte(0x00590748 + 3, 73); //-- check class equip
	SetByte(0x00590753 + 3, 74); //-- check class equip
	SetByte(0x00590791 + 4, 73); //-- check class equip

	SetByte(0x00833CF8 + 4, 73); //-- check class equip
	SetByte(0x00833D21 + 3, 73); //-- check class equip
	SetByte(0x00833D2C + 3, 74); //-- check class equip
	SetByte(0x00833D6A + 4, 73); //-- check class equip
	//--
	//SetByte(0x007E7120 + 3, 73); //-- check class equip
	//SetByte(0x007E7161 + 2, 73); //-- check class equip
}