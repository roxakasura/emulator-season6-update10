#include "stdafx.h"
#include "Import.h"
#include "Offset.h"
#include "Defines.h"
#include "CSCharacterS13.h"
#include "MultiCharacter.h"
#include "ChangeSystem.h"
#include "Util.h"
#include "TMemory.h"
#include "Protect.h"

int MountSize;

__declspec(naked) void ValorFenrir001() // OK
{
	static DWORD LevelAddress1 = 0x0054EAE7;

	_asm
	{
		movzx   eax, byte ptr [edx+0x0E]
		test    eax, eax
		JMP [LevelAddress1]
	}

}

__declspec(naked) void ValorFenrir002() // OK
{
	static DWORD LevelAddress2 = 0x0054FC98;

	_asm
	{
		movzx   ecx, byte ptr [eax+0x0E]
		test    ecx, ecx
		JMP [LevelAddress2]
	}

}

__declspec(naked) void ValorFenrir003() // OK
{
	static DWORD LevelAddress2 = 0x0054ED73;

	_asm
	{
		movzx   edx, byte ptr [ecx+0x0E]
		test    edx, edx
		JMP [LevelAddress2]
	}

}

__declspec(naked) void ValorFenrir004() // OK
{
	static DWORD LevelAddress1 = 0x0054FD65;

	_asm
	{
		movzx   eax, byte ptr [edx+0x0E]
		test    eax, eax
		JMP [LevelAddress1]
	}

}

__declspec(naked) void ValorFenrir005() // OK
{
	static DWORD LevelAddress1 = 0x0054FE44;

	_asm
	{
		movzx   eax, byte ptr [edx+0x0E]
		test    eax, eax
		JMP [LevelAddress1]
	}

}

__declspec(naked) void ValorFenrir006() // OK
{
	static DWORD LevelAddress2 = 0x0054ECA9;

	_asm
	{
		movzx   edx, byte ptr [ecx+0x0E]
		test    edx, edx
		JMP [LevelAddress2]
	}

}

__declspec(naked) void ValorFenrir007() // OK
{
	static DWORD LevelAddress2 = 0x0054FCF2;

	_asm
	{
		movzx   edx, byte ptr [ecx+0x0E]
		test    edx, edx
		JMP [LevelAddress2]
	}

}

void FenrirLoad()
{	
	SetCompleteHook(0xE9,0x0054EAE1,&ValorFenrir001);
	SetCompleteHook(0xE9,0x0054FC92,&ValorFenrir002);
	SetCompleteHook(0xE9,0x0054ED6D,&ValorFenrir003);
	SetCompleteHook(0xE9,0x0054FD5F,&ValorFenrir004);
	SetCompleteHook(0xE9,0x0054FE3E,&ValorFenrir005);
	SetCompleteHook(0xE9,0x0054ECA3,&ValorFenrir006);
	SetCompleteHook(0xE9,0x0054FCEC,&ValorFenrir007);
}


DWORD RESOLUTION = pWinWidth;
int FontHeight;

void ChangeSize(int a1, int a2)
{
	int v2; // esi@1
	DWORD v3; // edi@1
	int v4; // eax@2
	int v5; // eax@2
  //  DWORD v5; // edi@1
	DWORD *v6; // esi@2
	int v8; // eax@2
	int v7; // eax@2

	v2 = a2;
	v3 = a1;
	// v4= x;
	// v5= y;
	if (pMUIsLoaded)
	{
		pWinWidth = a1;
		pWinHeight = a2;
		pWinWidthReal = (double)(signed int)a1 / 640.0;
		pWinHeightReal = (double)a2 / 480.0;
		SetWindowPos(pGameWindow, 0, 0, 0, a1, a2 + 30, 0x116u);
		sub_630BC0();
		sub_596AC0(1);
		v4 = sub_482B70();
		*(DWORD *)(v4 + 40) = v3;
		*(DWORD *)(v4 + 44) = v2;
		v5 = sub_407B20();
		*(DWORD *)(v5 + 40) = v3;
		*(DWORD *)(v5 + 44) = v2;
		v6 = (DWORD *)pWindowThis();
		if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
		{
			sub_785870(v6[3], *v6, v6[4], 179, 405);
		}
		else if(gProtect.m_MainInfo.CustomInterfaceType == 0)
		{
			sub_785870(v6[3], *v6, v6[4], 0, 382);
		}
		v7 = GetInstance();
		v8 = sub_861AC0(v7);
		sub_7F0D40(v8);
		sub_7F0C80(v6[78], *v6, 450, 0);
		//*(DWORD*)0x81C0380 = FontHeight;// fuente 
		sub_830B70(v6[45], *v6, 1, 1);
		SetFloat((PVOID)(0x00D2C848), 2000.0);
		SetFloat((PVOID)(0x00D2C898), 1000.0);
	}
}

int ChangeResolution = 0;

void RegeditData(BYTE data)
{

	HKEY hKey;
	DWORD dwType, dwSize;
	DWORD buffer;
	LONG result;

	RegOpenKeyA(HKEY_CURRENT_USER, "SOFTWARE\\Webzen\\Mu\\Config", &hKey);
	DWORD value = data;
	ChangeResolution = data;
	RegSetValueExA(hKey, TEXT("Resolution"), 0, REG_DWORD, (const BYTE*)&value, REG_DWORD);
	RegCloseKey(hKey);
	switch (data)
	{
	case 0:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 0", ".\\Settings.ini");
		break;
	case 1:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 1", ".\\Settings.ini");
		break;
	case 2:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 2", ".\\Settings.ini");
		break;
	case 3:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 3", ".\\Settings.ini");
		break;
	case 4:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 4", ".\\Settings.ini");
		break;
	case 5:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 5", ".\\Settings.ini");
		break;
	case 6:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 6", ".\\Settings.ini");
		break;
	case 7:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 7", ".\\Settings.ini");
		break;
	case 8:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 8", ".\\Settings.ini");
		break;
	case 9:
		WritePrivateProfileStringA("Interface", "ChangeResolution", " 9", ".\\Settings.ini");
		break;
	}
}

// code:
void fix_resolution_items_size_1()
{
	return sub_6363D0_Addr(0, 0, pWinWidth, pWinHeight);
}

int fix_resolution_items_size_2()
{
	float v2 = (float)pWinWidth / (float)pWinHeight;
	return sub_6358A0_Addr(1.0, v2, 20.0, 2000.0);
}

void ItemSizeFixLoad()
{
	SetCompleteHook(0xE8, 0x00772960, &fix_resolution_items_size_1);
	SetCompleteHook(0xE8, 0x007729B3, &fix_resolution_items_size_2);
}