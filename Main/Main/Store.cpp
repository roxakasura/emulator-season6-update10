#include "stdafx.h"
#include "Store.h"
#include "Util.h"
#include "TMemory.h"
#include "Import.h"
#include "Offset.h"
#include "Season0.h"
#include "User.h"
#include "StoreSearch.h"

char StoreName[36];

signed int sub_9CEBF02(double a1)
{
	return (signed int)a1;
}

void StoreFix(int iPkLevel)
{
	int v5; // ST5C_4@29
	int v6; // ST40_4@29
	HGDIOBJ v7; // ST18_4@29
	void *v8; // eax@29
	void *v9; // eax@29
	void *v10; // eax@29
	int v11; // ST08_4@29
	void *v12; // eax@29
	void *v13; // eax@29
	void *v14; // eax@29
	int v15; // ST08_4@29
	void *v16; // eax@29
	HGDIOBJ v17; // ST18_4@29
	void *v18; // eax@29
	void *v19; // eax@30
	void *v20; // eax@30
	int v21; // ST08_4@30
	void *v22; // eax@30
	int v23; // ST08_4@30
	void *v24; // eax@30
	char result; // al@30
	void *v26; // eax@32
	void *v27; // eax@32
	int v28; // ST08_4@32
	void *v29; // eax@32
	int v30; // [sp+0h] [bp-50h]@26
	int v31; // [sp+4h] [bp-4Ch]@22
	int v32; // [sp+8h] [bp-48h]@18
	int v33; // [sp+10h] [bp-40h]@11
	int v34; // [sp+14h] [bp-3Ch]@8
	int v35; // [sp+18h] [bp-38h]@5
	int v36; // [sp+1Ch] [bp-34h]@2
	int v37; // [sp+20h] [bp-30h]@1
	int v38; // [sp+2Ch] [bp-24h]@7
	int v39; // [sp+30h] [bp-20h]@13
	int v40; // [sp+34h] [bp-1Ch]@29
	int v41; // [sp+3Ch] [bp-14h]@29
	int v42; // [sp+40h] [bp-10h]@29
	int v43; // [sp+44h] [bp-Ch]@29
	int v44; // [sp+48h] [bp-8h]@10
	int v45; // [sp+4Ch] [bp-4h]@4

	// Render who's shop
	int iIconBkColor = pMakeColor(108, 57, 41, 128);
	int iIconTextColor = pMakeColor(250, 150, 0, 255);
	int iNameBkColor = pMakeColor(108, 57, 41, 128);
	int iNameTextColor = pMakeColor(230, 230, 0, 255);

	switch (iPkLevel)
	{
	case PVP_CAUTION:
	{
		iIconBkColor = iNameBkColor = pMakeColor(108, 57, 41, 128);
		iIconTextColor = iNameTextColor = pMakeColor(230, 180, 0, 255);
	}
	break;
	case PVP_MURDERER1:
	{
		iIconBkColor = iNameBkColor = pMakeColor(108, 57, 41, 128);
		iIconTextColor = iNameTextColor = pMakeColor(230, 110, 0, 255);
	}
	break;
	case PVP_MURDERER2:
	{
		iIconBkColor = iNameBkColor = pMakeColor(108, 57, 41, 128);
		iIconTextColor = iNameTextColor = pMakeColor(240, 20, 0, 255);
	}
	break;
	}

	v5 = sub_9CEBF02((double)(iPkLevel + 124) / *(float*)0xE7C3D8);
	v6 = sub_9CEBF02((double)(iPkLevel + 136) / *(float*)0xE7C3D4);
	v40 = sub_9CEBF02((double)(v37 + 128) / *(float*)0xE7C3D4);
	v41 = sub_9CEBF02((double)(iPkLevel + 120) / *(float*)0xE7C3D4);
	v43 = sub_9CEBF02((double)*(DWORD*)0x81C0380 / *(float*)0xE7C3D8);
	//
	pSetFont(pTextThis(), (int)pFontBold);
	sub_4200F0_Addr(pTextThis(), iIconBkColor);
	SetTextColorByHDC(pTextThis(), iIconTextColor);

	pDrawText(pTextThis(), v41, v5, pGetTextLine(pTextLineThis, 1104), v6, v43, (PINT)1, 0);
	//
	sub_4200F0_Addr(pTextThis(), iIconBkColor);
	SetTextColorByHDC(pTextThis(), iIconTextColor);
	//
	//v16 = sub_41FE10(a2, a3);
	//sub_420150((int)v16, v6 + v41, v5, v15, v40 - v6, v43, 1, 0);
	//
	//pDrawText(pTextThis(), v6 + v41, v5, gObjUser.lpViewPlayer->Name, v40 - v6, v43, (PINT)1, 0);
}

int FixStore(LPVOID This, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)
{
	return pDrawText(pTextThis(), 100, 100, StoreName, 500, 120, (LPINT)1, 0);
}


void StoreFixload()
{
	// MemorySet(0x00410268, 0x90, 0x5);
	//MemorySet(0x40F120, 0x90, 0x14C); //ALL MSGS STORE

	//SetDword(0x0041001C + 1, 1104); //Texto Store

	//MemorySet(0x00410154, 0x90, 0x5);
	//SetOp((LPVOID)0x0041011F, (LPVOID)&FixStore, 0xE8);
	//SetOp((LPVOID)0x00410154, (LPVOID)&FixStore, 0xE8);
	//SetCompleteHook(0xE8, 0x00410154, &FixStore);
	SetCompleteHook(0xE9, 0x40FCA0, &StoreFix);

	//MemorySet(0x0041011F, 0x90, 0x5);
}
