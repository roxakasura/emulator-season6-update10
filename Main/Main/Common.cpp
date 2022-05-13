#include "stdafx.h"
#include "Common.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "CustomMessage.h"
#include "Offset.h"
#include "Util.h"
#include "Camera\RotateDamage.h"
#include "Protect.h"

BYTE GensBattleMapCount = 0;
BYTE GensMoveIndexCount = 0;
BYTE GensBattleMap[120];
BYTE GensMoveIndex[120];

int DisableStaticEffect;
int DisableDynamicEffect;
int DisableSkillEffect;
int DisableGlowEffect;
int Anisotropy;
int MaxAnisotropy;
int Linear;
int GMT;
int Tron;
int MiniMap;
int Fog;
int OpenSwicthSkill;
int SkillPage;
int upgradeActiveChat;
int offhelper;
char Main_Font_Name[100];
int Main_Font_Bold;
int Main_Font_Height;
int Main_Font_Italic;
int Main_Font_Unicode;
int Main_Font_Width;
int Main_Font_Underline;
int Main_Font_Quality;
int Main_Font_StrikeOut;

HFONT LoadNewFont()
{
	HFONT MyFont;
	int bold = 400;
	int unicode = 0x0;
	//--
	if (Main_Font_Bold == 1)
	{
		bold = 700;

		if (Main_Font_Unicode == 1)
		{
			unicode = 0x1;
            
		}
	}
	else
	{
		bold = 400;

		if (Main_Font_Unicode == 1)
		{
			unicode = 0x1;
		}
	}

	 return CreateFontA(Main_Font_Height, Main_Font_Width, 0, 0, bold, Main_Font_Italic, Main_Font_Underline, Main_Font_StrikeOut, unicode, 0, 0, Main_Font_Quality, 0, Main_Font_Name);
}

void InitCommon() // OK
{
	SetCompleteHook(0xE9,0x0040B154,&LoginTab);

	SetCompleteHook(0xFF,0x0064A79A,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x0064A85F,&CheckMasterLevel); // C1:16

	SetCompleteHook(0xFF,0x00656E03,&CheckMasterLevel); // C1:48

	SetCompleteHook(0xFF,0x0064AB3D,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0064AC02,&CheckMasterLevel); // C1:9C

	SetCompleteHook(0xFF,0x0063DDF2,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0063DF89,&CheckMasterLevel); // C1:F3:03

	SetCompleteHook(0xFF,0x0063EA4C,&CheckMasterLevel); // C1:F3:04

	SetCompleteHook(0xFF,0x0064CA0C,&CheckMasterLevel); // LevelUp

	SetCompleteHook(0xFF,0x0077FAF9,&CheckMasterLevel); // Print Level

	SetCompleteHook(0xFF,0x0081071B,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0081079B,&CheckMasterLevel); // Experience Bar

	SetCompleteHook(0xFF,0x0047FE31,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059890D,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059A399,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059A93C,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0059B13B,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005A4261,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005A4D52,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x005B6117,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x0065A6CE,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x00727987,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007861F1,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007D32FA,&CheckGensBattleMap);

	SetCompleteHook(0xFF,0x007D3B0D,&CheckGensBattleMap);

	SetCompleteHook(0xE9,0x008317BD,&CompareGensMoveIndex);
	
	SetCompleteHook(0xE9,0x0063764C,&RotateDamageIndex);

	SetCompleteHook(0xE8,0x007D2B0C,&FixHelperMouseClick); // Fix MuEMU CashShop & Chaos Machine DUP

	//SetCompleteHook(0xFF,0x00777DC8,&DrawEffectsPic); //??

	//SetByte(0x004ADD59+3, 180); //Efeito Lite

	//SetCompleteHook(0xFF,0x007EFC93,&CheckIsLuckyItem);
		//--
	GetPrivateProfileStringA("MainConfig", "Main_Font_Name", "Arial", Main_Font_Name, 100, ".\\Settings.ini");
	Main_Font_Bold = GetPrivateProfileIntA("MainConfig", "Main_Font_Bold", 1, "./Settings.ini");
	Main_Font_Height = GetPrivateProfileIntA("MainConfig", "Main_Font_Height", 11, "./Settings.ini");
	Main_Font_Italic = GetPrivateProfileIntA("MainConfig", "Main_Font_Italic", 0, "./Settings.ini");
	Main_Font_Unicode = GetPrivateProfileIntA("MainConfig", "Main_Font_Unicode", 1, "./Settings.ini");
	Main_Font_Width = GetPrivateProfileIntA("MainConfig", "Main_Font_Width", 0, "./Settings.ini");
	Main_Font_Underline = GetPrivateProfileIntA("MainConfig", "Main_Font_Underline", 0, "./Settings.ini");
	Main_Font_Quality = GetPrivateProfileIntA("MainConfig", "Main_Font_Quality", 3, "./Settings.ini");
	Main_Font_StrikeOut = GetPrivateProfileIntA("MainConfig", "Main_Font_StrikeOut", 0, "./Settings.ini");

	DisableStaticEffect		= GetPrivateProfileIntA("AntiLag", "DisableStatasdasdicEffect", 0, "./Settings.ini");
	DisableDynamicEffect	= GetPrivateProfileIntA("AntiLag", "DisableDynasdasdamicEffect", 0, "./Settings.ini");
	DisableSkillEffect		= GetPrivateProfileIntA("AntiLag", "DisableSkillasdasdEffect", 0, "./Settings.ini");
	DisableGlowEffect		= GetPrivateProfileIntA("AntiLag", "DisableGasdasdlowEffect", 0, "./Settings.ini");
	Anisotropy				= GetPrivateProfileIntA("Graphics","Anisotropy",1,"./Settings.ini");
	MaxAnisotropy			= GetPrivateProfileIntA("Graphics","MaxAnisotropy",1,"./Settings.ini");
	Linear					= GetPrivateProfileIntA("Graphics","Linear",1,"./Settings.ini");
	Tron					= GetPrivateProfileIntA("Graphics","TronEffects", 0, "./Settings.ini");
	MiniMap					= GetPrivateProfileIntA("Gradasdaphics","MiniadadasdMap", 0, "./Settings.ini");
	Fog						= GetPrivateProfileIntA("Graphics","Fog",1,"./Settings.ini");
	upgradeActiveChat       = GetPrivateProfileIntA("124124", "ActiveChatUp512515grade", 1, "./Settings.ini");
	SkillPage = 1;
	offhelper = 0;

	
	if( pWinWidth == 1024 )
	{
		Main_Font_Height += 2;
	}
	else if( pWinWidth > 1024)
	{
		Main_Font_Height += 6;
	}

	if (gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2 )
	{
		////-- FONT GLOBAL PARA EL JUEGO
		//SetCompleteHook(0xE8, Offset_CreateFontA1, &LoadNewFont);
		//SetCompleteHook(0xE8, Offset_CreateFontA2, &LoadNewFont);
		//SetCompleteHook(0xE8, Offset_CreateFontA3, &LoadNewFont);
		//SetCompleteHook(0xE8, Offset_CreateFontA4, &LoadNewFont);
		//SetCompleteHook(0xE8, Offset_CreateFontA5, &LoadNewFont);
		////--
		//SetByte((Offset_CreateFontA1 + 5), 0x90);
		//SetByte((Offset_CreateFontA2 + 5), 0x90);
		//SetByte((Offset_CreateFontA3 + 5), 0x90);
		//SetByte((Offset_CreateFontA4 + 5), 0x90);
		//SetByte((Offset_CreateFontA5 + 5), 0x90);
	}
}

BOOL CheckIsLuckyItem(int ItemID) // OK
{
  bool result;

  if ( ItemID < 4158 || ItemID > 4168 )
  {
    if ( ItemID < 3646 || ItemID > 3656 )
    {
      if ( ItemID < 5694 || ItemID > 5704 )
      {
        if ( ItemID < 5182 || ItemID > 5192 )
          result = ItemID >= 4670 && ItemID <= 4680;
        else
          result = 1;
      }
      else
      {
        result = 1;
      }
    }
    else
    {
      result = 1;
    }
  }
  else
  {
    result = 1;
  }
  return result;
}

BOOL CheckGensBattleMap(int map) // OK
{
	for(int n=0;n < GensBattleMapCount;n++)
	{
		if(GensBattleMap[n] == map)
		{
			return 1;
		}
	}

	return 0;
}

BOOL CheckGensMoveIndex(int idx) // OK
{
	for(int n=0;n < GensMoveIndexCount;n++)
	{
		if(GensMoveIndex[n] == idx)
		{
			return 1;
		}
	}

	return 0;
}

void DrawEffectsPic(int &EffectID, float StartX, float StartY, float StartWidth, float StartHeight )
{
	////console.Log("", "%d | %f | %f | %f | %f", EffectID, StartX, StartY, StartWidth, StartHeight);
	
	if ( EffectID > 0 && EffectID < 180 )
	{
		int EffectValue = (EffectID - 1) % 80;
		float SourceX = (double)(EffectValue % 10) * StartWidth / 256.0;
		float SourceY = (double)(EffectValue / 10) * StartHeight / 256.0;
		float SourceWidth = StartWidth / 256.0;
		float SourceHeight = StartHeight / 256.0;
		pDrawImage((EffectID - 1) / 80 + 31725, StartX, StartY, StartWidth, StartHeight, SourceX, SourceY, SourceWidth, SourceHeight, 1, 1, 0);
	}
}

char FixHelperMouseClick(int a1) // Agregar al final del archivo
{
	if (gInterface.CheckWindow(ChaosBox) || gInterface.CheckWindow(Warehouse))
		return 0;

	return pHelperMouseClick(a1);
}

__declspec(naked) void LoginTab() // OK
{
	static DWORD LoginTabAddress1 = 0x0040B16F;

	__asm
	{
		Push 0
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x350]
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Eax,Dword Ptr Ds:[Edx+0x350]
		Mov Edx,Dword Ptr Ds:[Eax]
		Call Dword Ptr Ds:[Edx+0x30]
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x354]
		Push Ecx
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Edx+0x350]
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Edx,Dword Ptr Ds:[Eax+0x350]
		Mov Eax,Dword Ptr Ds:[Edx]
		Call Dword Ptr Ds:[Eax+0x58]
		Mov Ecx,Dword Ptr Ss:[Ebp-0x38]
		Mov Edx,Dword Ptr Ds:[Ecx+0x350]
		Push Edx
		Mov Eax,Dword Ptr Ss:[Ebp-0x38]
		Mov Ecx,Dword Ptr Ds:[Eax+0x354]
		Mov Edx,Dword Ptr Ss:[Ebp-0x38]
		Mov Eax,Dword Ptr Ds:[Edx+0x354]
		Mov Edx,Dword Ptr Ds:[Eax]
		Call Dword Ptr Ds:[Edx+0x58]
		Jmp [LoginTabAddress1]
	}
}

__declspec(naked) void CheckMasterLevel() // OK
{
	static DWORD CheckMasterLevelAddress1 = 0x005875A0;

	_asm
	{
		Push Ebp
		Mov Ebp,Esp
		Mov Eax,Dword Ptr Ds:[MAIN_CHARACTER_STRUCT]
		Xor Ecx,Ecx
		Mov Cx,Word Ptr Ds:[Eax+0x0E]
		Cmp Ecx,0x190
		Je NEXT
		Xor Eax,Eax
		Jmp EXIT
		NEXT:
		Xor Edx,Edx
		Mov Dl,Byte Ptr Ss:[Ebp+0x08]
		Push Edx
		Call [CheckMasterLevelAddress1]
		Add Esp,0x04
		EXIT:
		Pop Ebp
		Retn
	}
}

__declspec(naked) void CompareGensMoveIndex() // OK
{
	static DWORD CheckGensMoveIndexAddress1 = 0x0051B090;
	static DWORD CheckGensMoveIndexAddress2 = 0x008317FC;
	static DWORD CheckGensMoveIndexAddress3 = 0x008317EA;

	__asm
	{
		Lea Ecx,Dword Ptr Ss:[Ebp-0x08]
		Call [CheckGensMoveIndexAddress1]
		Mov Ecx,Dword Ptr Ds:[Eax]
		Mov Edx,Dword Ptr Ds:[Ecx]
		Push Edx
		Call [CheckGensMoveIndex]
		Add Esp,0x04
		Test Eax,Eax
		Jnz EXIT
		Jmp [CheckGensMoveIndexAddress2]
		EXIT:
		Jmp [CheckGensMoveIndexAddress3]
	}
}

__declspec(naked) void RotateDamageIndex()
{
	static DWORD RotateDamageOffset = 0x0063752D;

	_asm
	{
		Lea Eax, [Ebp - 0x38];
		Lea Ecx, [Ebp - 0x3C];
		Push Dword Ptr[Ebp + 0x18];
		Push Eax;
		Push Ecx;
		Call RotateDamage::CalculateRotation;
		Add Esp, 0xC;
		jmp[RotateDamageOffset];
	}
}