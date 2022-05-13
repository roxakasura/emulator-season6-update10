#include "stdafx.h"
#include "Inter803.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "ItemSetOption.h"
#include "Util.h"
#include "NewFont.h"
#include "Offset.h"
#include "Protect.h"
#include "WindowsStruct.h"
#include "Season15.h"
#include "ExperienceSystem.h"

//EXP
__declspec(naked) void EXP1()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXP1_buff = 0x0081122F;
	_asm
	{
		FLD QWORD PTR DS:[RenderX]
		FSTP QWORD PTR SS:[EBP-0x10]
		FLD QWORD PTR DS:[RenderY]
		FSTP QWORD PTR SS:[EBP-0x8]
		FLD DWORD PTR SS:[EBP-0x1B0]
		FMUL QWORD PTR DS:[MaxWidth]
		FSTP QWORD PTR SS:[EBP-0x28]
		FLD QWORD PTR DS:[Height]
		FSTP QWORD PTR SS:[EBP-0x20]
		jmp [EXP1_buff]
	}
}

__declspec(naked) void EXP2()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXP2_buff = 0x00811408;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR SS:[EBP-0x1B0]
	FMUL QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXP2_buff]
	}
}

__declspec(naked) void EXP3()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXP3_buff = 0x00811552;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR SS:[EBP-0x1C4]
	FMUL QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXP3_buff]
	}
}

__declspec(naked) void EXP4()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXP4_buff = 0x00811719;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR SS:[EBP-0x1B0]
	FMUL QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXP4_buff]
	}
}
//EXP MASTER
__declspec(naked) void EXPMASTER1()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXPMASTER1_buff = 0x00810B6E;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR SS:[EBP-0x58]
	FMUL QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER1_buff]
	}
}

__declspec(naked) void EXPMASTER2()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXPMASTER2_buff = 0x00810CB5;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR SS:[EBP-0x88]
	FMUL QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER2_buff]
	}
}

__declspec(naked) void EXPMASTER3()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXPMASTER3_buff = 0x00810E79;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR SS:[EBP-0x58]
	FMUL QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER3_buff]
	}
}

__declspec(naked) void EXPMASTER4()
{
	static double RenderX = 92.0f;
	static double RenderY = 473.0f;
	static double MaxWidth = 454.0f;
	static double Height = 4.0f;
	static DWORD EXPMASTER4_buff = 0x00810F73;
	_asm
	{
	FLD QWORD PTR DS:[RenderX]
	FSTP QWORD PTR SS:[EBP-0x10]
	FLD QWORD PTR DS:[RenderY]
	FSTP QWORD PTR SS:[EBP-0x8]
	FLD QWORD PTR DS:[MaxWidth]
	FSTP QWORD PTR SS:[EBP-0x28]
	FLD QWORD PTR DS:[Height]
	FSTP QWORD PTR SS:[EBP-0x20]
	jmp [EXPMASTER4_buff]
	}
}

bool MouseClickRender(int a1, int a2, int a3, int a4)
{
	if( gProtect.m_MainInfo.CustomInterfaceType == 3 )
	{
		int Width = TransForX( 190 );

		if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
			|| gInterface.CheckWindow(8)
			|| gInterface.CheckWindow(12)
			|| gInterface.CheckWindow(9)
			|| gInterface.CheckWindow(7)
			|| gInterface.CheckWindow(14)
			|| gInterface.CheckWindow(15)
			|| gInterface.CheckWindow(60)
			|| gInterface.CheckWindow(76) )
		{
			a3 = Return2X(TransFor2X(640) - (Width * 2));
		}
		else
		{
			if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
			{
				a3 = Return2X(TransFor2X(640) - (Width*2));
			}
			else
			{
				if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
				{
					a3 = Return2X(TransFor2X(640) - (Width*2));
				}
				else
				{
					if ( gInterface.CheckWindow(27) )
					{
						a3 = Return2X(TransFor2X(640) - (Width*2));
					}
					else
					{
						if ( gInterface.CheckWindow(13)
						|| gInterface.CheckWindow(16)
						|| gInterface.CheckWindow(3)
						|| gInterface.CheckWindow(21)
						|| gInterface.CheckWindow(6)
						|| gInterface.CheckWindow(22)
						|| gInterface.CheckWindow(23)
						|| gInterface.CheckWindow(24)
						|| gInterface.CheckWindow(4)
						|| gInterface.CheckWindow(18)
						|| gInterface.CheckWindow(10)
						|| gInterface.CheckWindow(5)
						|| gInterface.CheckWindow(25)
						|| gInterface.CheckWindow(26)
						|| gInterface.CheckWindow(19)
						|| gInterface.CheckWindow(20)
						|| gInterface.CheckWindow(58)
						|| gInterface.CheckWindow(59)
						|| gInterface.CheckWindow(62)
						|| gInterface.CheckWindow(73)
						|| gInterface.CheckWindow(68)
						|| gInterface.CheckWindow(69)
						|| gInterface.CheckWindow(70)
						|| gInterface.CheckWindow(66)
						|| gInterface.CheckWindow(75)
						|| gInterface.CheckWindow(74) )
						{
							a3 = Return2X(TransFor2X(640) - Width);
						}
						else
						{
							if ( gInterface.CheckWindow(79) )
							{
								if ( gInterface.CheckWindow(80) )
								{
									a3 = Return2X(TransFor2X(640) - (Width*2));
								}
								else
								{
									a3 = Return2X(TransFor2X(640) - Width);
								}	
							}
							else
							{
								a3 = Return2X(TransFor2X(640));
							}
						}
					}
				}
			}
		}
  
		if ( gInterface.CheckWindow(77) )
		{
			if ( gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore) ||
				gInterface.CheckWindow(Character))
			{
				a3 = Return2X(TransFor2X(640) - (Width * 3));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
		}
		else if ( gInterface.CheckWindow(78) )
		{
				a3 = Return2X(TransFor2X(640) - (Width * 3));
		}

		if ( gInterface.CheckWindow( Shop ) )
		{
			int t = Return2X( Width );

			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			return pCursorX > t && pCursorX < a3 && pCursorY < a4;
		}
		else if ( gInterface.CheckWindow(Warehouse) )
		{
			int t = Return2X( Width );

			if( gInterface.CheckWindow(ExpandWarehouse) )
			{
				t = Return2X( Width * 2 );
			}
			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			return pCursorX > t && pCursorX < a3 && pCursorY < a4;
		}
		else
		{
			return pCursorX < a3 && pCursorY < a4;
		}
	}
	else
	{
		if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(8)
		|| gInterface.CheckWindow(12)
		|| gInterface.CheckWindow(9)
		|| gInterface.CheckWindow(7)
		|| gInterface.CheckWindow(14)
		|| gInterface.CheckWindow(15)
		|| gInterface.CheckWindow(60)
		|| gInterface.CheckWindow(76) )
		{
			a3 = 260;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
			{
				a3 = 260;
			}
			else
			{
				if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
				{
					a3 = 260;
				}
				else
				{
					if ( gInterface.CheckWindow(27) )
					{
						a3 = 260;
					}
					else
					{
						if ( gInterface.CheckWindow(13)
						|| gInterface.CheckWindow(16)
						|| gInterface.CheckWindow(3)
						|| gInterface.CheckWindow(21)
						|| gInterface.CheckWindow(6)
						|| gInterface.CheckWindow(22)
						|| gInterface.CheckWindow(23)
						|| gInterface.CheckWindow(24)
						|| gInterface.CheckWindow(4)
						|| gInterface.CheckWindow(18)
						|| gInterface.CheckWindow(10)
						|| gInterface.CheckWindow(5)
						|| gInterface.CheckWindow(25)
						|| gInterface.CheckWindow(26)
						|| gInterface.CheckWindow(19)
						|| gInterface.CheckWindow(20)
						|| gInterface.CheckWindow(58)
						|| gInterface.CheckWindow(59)
						|| gInterface.CheckWindow(62)
						|| gInterface.CheckWindow(73)
						|| gInterface.CheckWindow(68)
						|| gInterface.CheckWindow(69)
						|| gInterface.CheckWindow(70)
						|| gInterface.CheckWindow(66)
						|| gInterface.CheckWindow(75)
						|| gInterface.CheckWindow(74) )
						{
							a3 = 450;
						}
						else
						{
							if ( gInterface.CheckWindow(79) )
							{
								if ( gInterface.CheckWindow(80) )
								{
									a3 = 260;
								}
								else
								{
									a3 = 450;
								}	
							}
							else
							{
								a3 = 640;
							}
						}
					}
				}
			}
		}
  
		if ( gInterface.CheckWindow(77) )
		{
			if ( gInterface.CheckWindow(Warehouse) ||
				gInterface.CheckWindow(ChaosBox) ||
				gInterface.CheckWindow(Store) ||
				gInterface.CheckWindow(OtherStore) ||
				gInterface.CheckWindow(Character))
			{
				a3 = 70;
			}
			else
			{
				a3 = 260;
			}
		}
		else if ( gInterface.CheckWindow(78) )
		{
				a3 = 70;
		}
		//-----------------------
		return pCursorX < a3 && pCursorY < a4;
	}
}

#define LoadBitmapA			((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)

void LoadSkill2Ex700(){
	LoadBitmapA("Interface\\GFx\\newui_skill2.tga", 0x7A4D, GL_LINEAR, GL_CLAMP, 1, 0);
}

void RenderSands(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)
{
	if (World == 8)//Tarkan
	{
		if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
	if (World == 34)//LaCleon
	{
		if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
	if (World == 56)//LaCleon
	{
		if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
	if (World == 57)//LaCleon
	{
		if (a1 == 32045)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
		else if (a1 == 32044)
		{
		RenderBitmapUV(a1, a2, a3, a4, a5 + 45.0, a6, a7, a8, a9);
		}
	}
}

__declspec(naked) void PartyWindowsMove()
{
	static DWORD PartyWindows_Buff = 0x0084B965;
	static DWORD X;
	X = 79;//<<Cord Base

   if ( gInterface.CheckWindow(13) && gInterface.CheckWindow(Character)
    || gInterface.CheckWindow(8)
    || gInterface.CheckWindow(12)
    || gInterface.CheckWindow(9)
    || gInterface.CheckWindow(7)
    || gInterface.CheckWindow(14)
    || gInterface.CheckWindow(15)
    || gInterface.CheckWindow(60)
    || gInterface.CheckWindow(76) )
	{
		X = 459;
	}
	else
	{
		if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
		{
			X = 459;
		}
		else
		{
			if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
			{
				X = 459;
			}
			else
			{
				if ( gInterface.CheckWindow(27) )
				{
					X = 459;
				}
				else
				{
					if ( gInterface.CheckWindow(13)
					|| gInterface.CheckWindow(16)
					|| gInterface.CheckWindow(3)
					|| gInterface.CheckWindow(21)
					|| gInterface.CheckWindow(6)
					|| gInterface.CheckWindow(22)
					|| gInterface.CheckWindow(23)
					|| gInterface.CheckWindow(24)
					|| gInterface.CheckWindow(4)
					|| gInterface.CheckWindow(18)
					|| gInterface.CheckWindow(10)
					|| gInterface.CheckWindow(5)
					|| gInterface.CheckWindow(25)
					|| gInterface.CheckWindow(26)
					|| gInterface.CheckWindow(19)
					|| gInterface.CheckWindow(20)
					|| gInterface.CheckWindow(58)
					|| gInterface.CheckWindow(59)
					|| gInterface.CheckWindow(62)
					|| gInterface.CheckWindow(73)
					|| gInterface.CheckWindow(68)
					|| gInterface.CheckWindow(69)
					|| gInterface.CheckWindow(70)
					|| gInterface.CheckWindow(66)
					|| gInterface.CheckWindow(75)
					|| gInterface.CheckWindow(74) )
					{
						X = 269;
					}
					else
					{
						if ( gInterface.CheckWindow(79) )
						{
							if ( gInterface.CheckWindow(80) )
							{
								X = 459;
							}
							else
							{
								X = 269;
							}	
						}
					}
				}
			}
		}
	}
  
	if ( gInterface.CheckWindow(77) )
	{
		if ( gInterface.CheckWindow(Warehouse) ||
			gInterface.CheckWindow(ChaosBox) ||
			gInterface.CheckWindow(Store) ||
			gInterface.CheckWindow(OtherStore) ||
			gInterface.CheckWindow(Character))
		{
			
		}
		else
		{
			X = 459;
		}
	}
	else if ( gInterface.CheckWindow(78) )
	{
			X = 459;
	}

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x8]           ; |
		SUB EDX,X                                ; |
		PUSH EDX                                 ; |Arg1
		JMP PartyWindows_Buff                    ; |
	}
}

//==================================================================================
//-- Slot [Q],[W],[E],[R]
//==================================================================================
__declspec(naked) void RenderSlotQ()
{
	static DWORD Addr_JMP = 0x00895A73;
	static float RenderPotionY = 448.0f;
	static float RenderPotionX = 204.0f;
	static float RenderNumberY = 455.0f;
	static float RenderNumberX= 215.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x18]          ; |
		JMP [Addr_JMP]                           ; \main1.008977D0
	}
}

__declspec(naked) void RenderSlotW()
{
	static DWORD Addr_JMP = 0x00895AE8;
	static float RenderPotionY = 448.0f;
	static float RenderPotionX = 231.0f;
	static float RenderNumberY = 455.0f;
	static float RenderNumberX = 242.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x20]          ; |
		JMP [Addr_JMP]                           ; \main1.00897BD0
	}
}

__declspec(naked) void RenderSlotE()
{
	static DWORD Addr_JMP = 0x00895B5D;
	static float RenderPotionY = 448.0f;
	static float RenderPotionX = 257.0f;
	static float RenderNumberY = 455.0f;
	static float RenderNumberX = 268.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x28]          ; |
		JMP [Addr_JMP]                           ; \main1.00895760
	}
}

__declspec(naked) void RenderSlotR()
{
	static DWORD Addr_JMP = 0x00895BD2;
	static float RenderPotionY = 448.0f;
	static float RenderPotionX = 283.0f;
	static float RenderNumberY = 455.0f;
	static float RenderNumberX = 294.0f;

	_asm
	{
		PUSH ECX                                 ; /Arg4
		FLD DWORD PTR DS:[RenderNumberY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg3
		FLD DWORD PTR DS:[RenderNumberX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg2
		FLD DWORD PTR DS:[RenderPotionY]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		PUSH ECX                                 ; |Arg1
		FLD DWORD PTR DS:[RenderPotionX]         ; |
		FSTP DWORD PTR SS:[ESP]                  ; |
		MOV ECX,DWORD PTR SS:[EBP-0x30]          ; |
		JMP [Addr_JMP]                           ; \main1.008979C0
	}
}
//==================================================================================
//-- Skill General
//==================================================================================
void SkillView(int This, int a5, float a6, float a7, float a8, float a9)
{
	int v9; // edx@35
	int v10; // ecx@35
	signed int green; // ST28_4@35
	signed int blue; // ST2C_4@106
	float v13; // STE0_4@195
	float v14; // STFC_4@195
	float v15; // ST44_4@195
	float v16; // ST40_4@195
	float v17; // ST3C_4@196
	float v18; // ST38_4@196
	float v19; // ST34_4@203
	float v20; // ST30_4@203
	int v21; // [sp+8Ch] [bp-78h]@1
	signed int i; // [sp+90h] [bp-74h]@197
	signed int v23; // [sp+94h] [bp-70h]@152
	signed int v24; // [sp+98h] [bp-6Ch]@152
	signed int v25; // [sp+A0h] [bp-64h]@84
	signed int v26; // [sp+A4h] [bp-60h]@84
	signed int v27; // [sp+B0h] [bp-54h]@70
	signed int v28; // [sp+B4h] [bp-50h]@70
	signed int v29; // [sp+C4h] [bp-40h]@18
	signed int v30; // [sp+C8h] [bp-3Ch]@18
	unsigned __int16 v31; // [sp+CCh] [bp-38h]@1
	char v32; // [sp+D3h] [bp-31h]@2
	int v33; // [sp+D4h] [bp-30h]@174
	float v34; // [sp+DCh] [bp-28h]@115
	signed int v35; // [sp+E0h] [bp-24h]@35
	signed int v36; // [sp+E4h] [bp-20h]@2
	signed int v37; // [sp+ECh] [bp-18h]@115
	char v38; // [sp+F3h] [bp-11h]@2
	float v39; // [sp+F8h] [bp-Ch]@115
	signed int v40; // [sp+FCh] [bp-8h]@177
	signed int v41; // [sp+100h] [bp-4h]@197

	float RSkill = 256.0f;


	//v21 = *(DWORD *)a1;
	v31 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * a5 + 120);
	if ( v31 )
	{
		v32 = 0;
		v38 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v31 + 55);
		v36 = *(WORD *)(*(DWORD *)0x8128ABC + 88 * v31 + 72);
		if ( !sub_4AD0E0(v31) )
			v32 = 1;
		if ( !sub_5B89C0(v31) )
			v32 = 1;
		if ( sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 19) && v38 == 2 )
			v32 = 1;
		if ( v31 == 47
			&& ((signed int)*(WORD *)(*(DWORD *)0x7BC4F04 + 556) < 7829 || (signed int)*(WORD *)(*(DWORD *)0x7BC4F04 + 556) > 7830)
			&& *(WORD *)(*(DWORD *)0x7BC4F04 + 556) != 7864 )
		{
			v32 = 1;
		}
		if ( v31 == 47
			&& (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v30 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
			v29 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
			if ( (v30 < 1536 || v30 >= 2048) && (v29 < 1536 || v29 >= 2048) )
			v32 = 1;
		}
		if ( (signed int)v31 >= 18
			&& (signed int)v31 <= 23
			&& (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v32 = 1;
		}
		if ( (v31 == 56 || v31 == 482)
			&& (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v32 = 1;
		}
		v9 = *(WORD *)(*(DWORD *)0x8128AC8 + 30);
		v10 = *(WORD *)(*(DWORD *)0x8128AC8 + 56);
		v35 = v10 + v9;
		green = v10 + v9;
		pUserStat();
		if ( sub_4E8D80(v31, green, 0) )
			v32 = 1;
		if ( v31 == 63 && *(DWORD *)0x81F6B6C <= 0 )
			v32 = 1;
		if ( v31 == 63 && (*(DWORD *)0xE61E18 == 65 || *(DWORD *)0xE61E18 == 66 || *(DWORD *)0xE61E18 == 67 || *(DWORD *)0xE61E18 == 68) )
			v32 = 1;
		if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512)
			&& (!*(BYTE *)(*(DWORD *)0x8128AC4 + 5550) || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) != 7831) )
		{
			v32 = 1;
		}
		if ( v31 == 77 || v31 == 233 || v31 == 380 || v31 == 383 || v31 == 441 )
		{
			pUserStat();
			if ( sub_4E8D80(v31, v35, 0) )
				v32 = 1;
			if ( sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 6)
			|| sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 143)
			|| sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 82)
			|| sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 138)
			|| sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 139) )
			{
				v32 = 1;
			}
		}
		if ( v31 == 55 || v31 == 490 )
		{
			if ( (signed int)(unsigned __int16)(*(WORD *)(*(DWORD *)0x8128AC8 + 50) + *(WORD *)(*(DWORD *)0x8128AC8 + 24)) < 596 )
				v32 = 1;
			v28 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
			v27 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
			if ( v27 == -1 || v27 >= 2560 && v27 < 3072 || v28 >= 2560 && v28 < 3072 )
				v32 = 1;
		}
		if ( (v31 == 51 || v31 == 424)
			&& (signed int)(unsigned __int16)(*(WORD *)(*(DWORD *)0x8128AC8 + 52) + *(WORD *)(*(DWORD *)0x8128AC8 + 26)) < 646 )
		{
			v32 = 1;
		}
		if ( v31 == 41 || v31 == 330 || v31 == 481 || v31 == 332 )
		{
			if ( (v26 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779), v25 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672), v25 == -1)
			|| v25 >= 2560 && v25 < 3072
			|| v26 >= 2560 && v26 < 3072 )
			{
				v32 = 1;
			}
		}
		if ( sub_4E65A0(*(DWORD *)0xE61E18) == 1 )
		{
			if ( v31 == 62
			|| v31 == 49
			|| v31 == 510
			|| v31 == 516
			|| (signed int)v31 >= 120 && (signed int)v31 <= 123
			|| v31 == 512 )
			{
				v32 = 1;
			}
		}
		else if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512) && !*(BYTE *)(*(DWORD *)0x8128AC4 + 5550) )
		{
			v32 = 1;
		}
		blue = *(WORD *)(*(DWORD *)0x8128AC8 + 62) + *(WORD *)(*(DWORD *)0x8128AC8 + 32);
		pUserStat();
		if ( sub_4E8D80(v31, v35, blue) )
			v32 = 1;
		if ( !sub_5111D0(v31) )
			v32 = 1;
		if ( sub_511110(v31, *(WORD *)(*(DWORD *)0x7BC4F04 + 556)) )
			v32 = 1;
		if ( sub_511290(
				*(WORD *)(*(DWORD *)0x8128AC4 + 5849),
				*(WORD *)(*(DWORD *)0x8128AC4 + 5742),
				*(DWORD *)(*(DWORD *)0x8128AC4 + 5851),
				*(DWORD *)(*(DWORD *)0x8128AC4 + 5744))
			&& pGetCharClass(*(BYTE *)(*(DWORD *)0x7BC4F04 + 19)) == 6 )
		{
			v32 = 1;
		}
		v34 = 0.0;
		v39 = 0.0;
		v37 = 0;
		pUserStat();
		if ( !sub_4EAC90( v31) )
			v32 = 1;
		pUserStat();
		if ( !sub_4EAC90( v31) )
			v32 = 1;
		if ( (signed int)v31 < 120 || (signed int)v31 > 124 )
		{
			if ( v31 == 76 )
			{
				v34 = a8 * 4.0 / RSkill;
				v39 = 0.0;
				v37 = 1;
			}
			else if ( (signed int)v31 < 214 || (signed int)v31 > 217 )
			{
				if ( (signed int)v31 < 219 || (signed int)v31 > 220 )
				{
					if ( v31 == 218 )
					{
						v34 = a8 * 10.0 / RSkill;
						v39 = a9 * 3.0 / RSkill;
						v37 = 3;
					}
					else if ( (signed int)v31 < 221 || (signed int)v31 > 222 )
					{
						if ( (signed int)v31 < 223 || (signed int)v31 > 224 )
						{
							if ( v31 == 225 )
							{
								v34 = a8 * 11.0 / RSkill;
								v39 = a9 * 3.0 / RSkill;
								v37 = 3;
							}
							else if ( v31 == 232 )
							{
								v34 = a8 * 7.0 / RSkill;
								v39 = a9 * 2.0 / RSkill;
								v37 = 3;
							}
							else if ( v31 != 523 )
							{
								switch ( v31 )
								{
								case 0xEEu:
									v34 = a8 * 3.0 / RSkill;
									v39 = a9 * 8.0 / RSkill;
									v37 = 3;
									break;
								case 0xEAu:
									v34 = a8 * 9.0 / RSkill;
									v39 = a9 * 2.0 / RSkill;
									v37 = 3;
									break;
								case 0xEBu:
									if ( !sub_587A80() )
										v32 = 1;
									v34 = a8 * 0.0 / RSkill;
									v39 = a9 * 8.0 / RSkill;
									v37 = 3;
									break;
								case 0xECu:
									v24 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
									v23 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
									if ( v23 == -1 || v23 >= 2560 && v23 < 3072 || v24 >= 2560 && v24 < 3072 )
										v32 = 1;
									v34 = a8 * 1.0 / RSkill;
									v39 = a9 * 8.0 / RSkill;
									v37 = 3;
									break;
								case 0xEDu:
									v34 = a8 * 2.0 / RSkill;
									v39 = a9 * 8.0 / RSkill;
									v37 = 3;
									break;
								case 0xE6u:
									v34 = a8 * 2.0 / RSkill;
									v39 = a9 * 3.0 / RSkill;
									v37 = 3;
									break;
								case 0x1C8u:
									v34 = a8 * 6.0 / RSkill;
									v39 = a9 * 8.0 / RSkill;
									v37 = 3;
									break;
								case 0xE9u:
									v34 = a8 * 8.0 / RSkill;
									v39 = a9 * 2.0 / RSkill;
									v37 = 3;
									break;
								default:
									if ( v38 == 4 )
									{
										v34 = a8 / RSkill * (double)(v36 % 12);
										v39 = a9 / RSkill * (double)(v36 / 12 + 4);
										v37 = 3;
									}
									else if ( (signed int)v31 < 260 )
									{
										if ( (signed int)v31 < 57 )
										{
											v34 = (double)((v31 - 1) % 8) * a8 / RSkill;
											v39 = (double)((v31 - 1) / 8) * a9 / RSkill;
											v37 = 2;
										}
										else
										{
											v34 = (double)((v31 - 57) % 8) * a8 / RSkill;
											v39 = (double)((v31 - 57) / 8) * a9 / RSkill;
											v37 = 3;
										}
									}
									else
									{
										v34 = (double)((v31 - 260) % 12) * a8 / RSkill;
										v39 = (double)((v31 - 260) / 12) * a9 / RSkill;
										v37 = 4;
									}
									break;
								}
							}
						}
						else
						{
							v34 = (double)((v31 - 217) % 8) * a8 / RSkill;
							v39 = a9 * 3.0 / RSkill;
							v37 = 3;
						}
					}
					else
					{
						v34 = (double)(v31 - 213) * a8 / RSkill;
						v39 = a9 * 3.0 / RSkill;
						v37 = 3;
					}
				}
				else
				{
					v34 = (double)((v31 - 215) % 8) * a8 / RSkill;
					v39 = a9 * 3.0 / RSkill;
					v37 = 3;
				}
			}
			else
			{
				v34 = (double)((v31 - 214) % 8) * a8 / RSkill;
				v39 = a9 * 3.0 / RSkill;
				v37 = 3;
			}
		}
		else
		{
			v34 = (double)((v31 - 120) % 8) * a8 / RSkill;
			v39 = (double)((v31 - 120) / 8) * a9 / RSkill;
			v37 = 1;
		}
		v33 = *(DWORD *)0x8128ABC + 88 * v31;
		if ( v33 && *(BYTE *)(v33 + 55) == 4 )
			v37 = 5;
		v40 = 0;
		switch ( v37 )
		{
			case 1:
				v40 = 31310;
				if ( v32 == 1 )
					v40 = 31316;
			break;
			case 2:
				v40 = 31308;
				if ( v32 == 1 )
					v40 = 31314;
			break;
			case 3:
				v40 = 31309;
				if ( v32 == 1 )
					v40 = 31315;
			break;
			case 4:
				v40 = 31311;
				if ( v32 == 1 )
					v40 = 31317;
			break;
			case 5:
				v40 = 31534;
				if ( v32 == 1 )
					v40 = 31535;
			break;
			default:
			break;
		}
		if ( v40 )
		{
			if ( v33 && *(BYTE *)(v33 + 55) == 4 )
			{
				v13 = a8 / 512.0 * (double)(*(WORD *)(v33 + 72) % 25);
				v14 = a9 / 512.0 * (double)(*(WORD *)(v33 + 72) / 25);
				v15 = a9 / 512.0;
				v16 = a8 / 512.0;
				RenderBitmap(v40, a6, a7, a8, a9, v13, v14, v16, v15, 1, 1, 0.0);
			}
			else
			{
				v17 = a9 / RSkill;
				v18 = a8 / RSkill;
				RenderBitmap(v40, a6, a7, a8, a9, v34, v39, v18, v17, 1, 1, 0.0);
			}
		}
		v41 = -1;
		for ( i = 0; i < 10; ++i )
		{
			if ( *(DWORD *)(*(DWORD *)This + 4 * i + 24) == a5 )
			{
				v41 = i;
				break;
			}
		}

		if ( v41 != -1 )
		{
			glColor3f(1.0, 0.89999998, 0.80000001);
			v19 = a7 + 20.0;
			v20 = a6 + 20.0;
			pDrawInterfaceNumBer(v20, v19, v41, 1.0);
		}
		
		/*if ( (v31 != 262 && v31 != 265 && v31 != 264 && v31 != 558 && v31 != 560 || !v32)
			&& v31 != 77
			&& v31 != 233
			&& v31 != 380
			&& v31 != 383
			&& v31 != 441 )
		{
			sub_814F30(a5, a6, a7, a8, a9);
		}*/
	}
}

bool SkillFullGM(DWORD a1)
{
	bool result; // al@2
	unsigned __int8 v5; // ST4F_1@3
	int v62; // [sp+Ch] [bp-54h]@1
	int v64; // [sp+18h] [bp-48h]@84
	unsigned __int16 v66; // [sp+24h] [bp-3Ch]@53
	signed int v67; // [sp+2Ch] [bp-34h]@40
	signed int v68; // [sp+30h] [bp-30h]@40
	unsigned __int16 v69; // [sp+38h] [bp-28h]@76
	float v70; // [sp+40h] [bp-20h]@5
	float v71; // [sp+40h] [bp-20h]@28
	float v72; // [sp+40h] [bp-20h]@40
	float v73; // [sp+40h] [bp-20h]@73
	float v74; // [sp+40h] [bp-20h]@116
	float v75; // [sp+44h] [bp-1Ch]@5
	float v76; // [sp+44h] [bp-1Ch]@28
	float v77; // [sp+44h] [bp-1Ch]@73
	char v78; // [sp+4Bh] [bp-15h]@73
	float v79; // [sp+4Ch] [bp-14h]@73
	signed int v80; // [sp+50h] [bp-10h]@73
	int v81; // [sp+54h] [bp-Ch]@73
	float v82; // [sp+58h] [bp-8h]@5
	float v83; // [sp+58h] [bp-8h]@28
	float v84; // [sp+58h] [bp-8h]@40
	float v85; // [sp+58h] [bp-8h]@85
	float v86; // [sp+58h] [bp-8h]@116
	float v87; // [sp+5Ch] [bp-4h]@5
	float v88; // [sp+5Ch] [bp-4h]@28
	float v89; // [sp+5Ch] [bp-4h]@40
	float v90; // [sp+5Ch] [bp-4h]@73
	float v91; // [sp+5Ch] [bp-4h]@116*/
	signed int j; // [sp+10h] [bp-50h]@116
	signed int i; // [sp+20h] [bp-40h]@73

	v62 = a1;
	if ( sub_4C8640((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 98) )
	{
		*(BYTE *)(v62 + 64) = 0;
		result = 1;
	}
	else
	{
		v5 = *(BYTE *)(*(DWORD *)0x8128AC8 + 118);
		*(BYTE *)(v62 + 65) = 0;
		if ( (signed int)v5 > 0 )
		{
			//-- skill en uso
			v82 = 310.0;
			v87 = 443.0;
			v70 = 20.0;
			v75 = 27.0;
			if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
			{
				if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) )
				{
					if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 != 1 && *(BYTE *)0x8793380 != 1 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
					{
						if ( *(DWORD *)(v62 + 80) != 2 || *(BYTE *)0x8793384 || *(BYTE *)0x8793380 )
						{
							if ( *(DWORD *)(v62 + 80) == 1 )
							{
								*(BYTE *)(v62 + 65) = 1;
								*(DWORD *)(v62 + 68) = *(BYTE *)(*(DWORD *)0x7BC4F04 + 50);
								*(DWORD *)(v62 + 72) = v82 - 5.0;
								*(DWORD *)(v62 + 76) = v87;
								result = 0;
							}
							else if ( *(DWORD *)(v62 + 80) == 2 )
							{
								result = 0;
							}
							else
							{
								//-- DrawSkill Bar
								v83 = 330.0;
								v88 = 442.0;
								v71 = 100.0;
								v76 = 20.0;
								if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
								{
									if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) )
									{
										if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 != 1 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
										{
										//-- DrawSkill Bar Slot 5
											v84 = 315.0;
											v89 = 442.0;
											v72 = 20.0;
											v68 = 0;
											v67 = *(BYTE *)(v62 + 20) != 1 ? 1 : 6;
											while ( v68 < 5 )
											{
												v84 = v84 + v72;
												if ( v67 == 10 )
													v67 = 0;
												if ( pCheckMouseOver(v84, v89, v72, (float)32.0) == 1 )
												{
													if ( *(DWORD *)(v62 + 4 * v67 + 24) == -1 )
													{
														if ( *(DWORD *)(v62 + 80) == 3 )
														{
															*(BYTE *)(v62 + 65) = 0;
															*(DWORD *)(v62 + 68) = -1;
														}
														if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															*(DWORD *)(v62 + 80) = 0;
													}
													else
													{
														v66 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(DWORD *)(v62 + 4 * v67 + 24) + 120);
														if ( v66 && ((signed int)v66 < 67 || (signed int)v66 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v66 + 55) != 3 )
														{
															if ( *(DWORD *)(v62 + 80) == 3 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = *(DWORD *)(v62 + 4 * v67 + 24);
																*(DWORD *)(v62 + 72) = v84 - 5.0;
																*(DWORD *)(v62 + 76) = v89;
																return 1;
															}
															if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															{
																if ( *(DWORD *)(v62 + 68) == *(DWORD *)(v62 + 4 * v67 + 24) )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = *(BYTE *)(v62 + 4 * v67 + 24);
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
																*(DWORD *)(v62 + 80) = 0;
															}
														}
													}
												}
												++v68;
												++v67;
											}
											if ( *(DWORD *)(v62 + 80) == 4 )
											{
												//-- DrawSkill Bar
												if ( *(BYTE *)0x8793384 || pCheckMouseOver((float)330.0, (float)442.0, (float)100.0, (float)32.0))
												{
													result = 0;
												}
												else
												{
													*(DWORD *)(v62 + 80) = 0;
													result = 1;
												}
											}
											else if ( *(BYTE *)(v62 + 64) )
											{
												//-- SkillBarSwitch
												v80 = 0;
												v78 = 0;
												v90 = 370.0;//-- y
												v73 = 32.0;//-- w
												v77 = 38.0;//-- h
												v79 = 302.0;//-- x
												v81 = *(DWORD *)(v62 + 80);
												for ( i = 0; i < 150; ++i )
												{
													v69 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);
													if ( v69 && ((signed int)v69 < 67 || (signed int)v69 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v69 + 55) != 3 )
													{
														if ( v80 == 11 )
															v90 = v90 - v77;
														if ( v80 >= 11 )
														{
															if ( v80 < 11 || v80 > 21 )
																v85 = v79 - v73 * 11.0 + (double)(v80 - 21) * v73;
															else
																v85 = v79 - v73 * 6.0 + (double)(v80 - 10) * v73;
														}
														else
														{
															v64 = v80 / 2;
															if ( v80 % 2 )
																v85 = v79 - (double)(v64 + 1) * v73;
															else
																v85 = (double)v64 * v73 + v79;
														}
														++v80;
														if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
														{
															v78 = 1;
															if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
															{
																*(DWORD *)(v62 + 80) = 5;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(DWORD *)(v62 + 80) = 6;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && !*(BYTE *)0x8793384 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = i;
																*(DWORD *)(v62 + 72) = v85;
																*(DWORD *)(v62 + 76) = v90;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == i )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(DWORD *)(v62 + 80) = 0;
																*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = i;
																*(BYTE *)(v62 + 64) = 0;
																PlayBuffer(25, 0, 0);
																return 0;
															}
														}
													}
												}
												if ( v81 == *(DWORD *)(v62 + 80) )
												{
													if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
													{
														//-- SkillFixRaven
														v86 = 270.0;
														v91 = 330.0;
														v74 = 32.0;
														for ( j = 150; j < 154; ++j )
														{
															if ( pCheckMouseOver(v86, v91, v74, (float)38.0) == 1 )
															{
																v78 = 1;
																if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
																{
																	*(DWORD *)(v62 + 80) = 5;
																	return 1;
																}
																if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
																{
																	*(DWORD *)(v62 + 80) = 6;
																	return 0;
																}
																if ( *(DWORD *)(v62 + 80) == 5 )
																{
																	*(BYTE *)(v62 + 65) = 1;
																	*(DWORD *)(v62 + 68) = j;
																	*(DWORD *)(v62 + 72) = v86;
																	*(DWORD *)(v62 + 76) = v91;
																}
																if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == j )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = j;
																	*(BYTE *)(v62 + 64) = 0;
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
															}
															v86 = v86 + v74;
														}
													}
													if ( v78 || *(DWORD *)(v62 + 80) != 5 )
													{
														if ( v78 || *(BYTE *)0x8793384 || *(DWORD *)(v62 + 80) != 6 )
														{
															if ( *(DWORD *)(v62 + 80) == 6 )
															{
																if ( *(BYTE *)0x8793384 )
																{
																	result = 0;
																}
																else
																{
																	*(DWORD *)(v62 + 80) = 0;
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
															*(DWORD *)(v62 + 80) = 0;
															result = 0;
														}
													}
													else
													{
														*(DWORD *)(v62 + 80) = 0;
														result = 1;
													}
												}
												else
												{
													result = !*(DWORD *)(v62 + 80) || *(DWORD *)(v62 + 80) == 5;
												}
											}
											else
											{
												result = 1;
											}
										}
										else
										{
											*(DWORD *)(v62 + 80) = 4;
											result = 0;
										}
									}
									else
									{
										*(DWORD *)(v62 + 80) = 0;
										result = 1;
									}
								}
								else
								{
									*(DWORD *)(v62 + 80) = 3;
									result = 1;
								}
							}
						}
						else
						{
							if ( pCheckMouseOver(v82, v87, v70, v75) == 1 )
							{
								*(BYTE *)(v62 + 64) = *(BYTE *)(v62 + 64) == 0;
								PlayBuffer(25, 0, 0);
								*(DWORD *)(v62 + 80) = 0;
								result = 0;
							}
							else
							{
								*(DWORD *)(v62 + 80) = 0;
								result = 1;
							}
						}
					}
					else
					{
						*(DWORD *)(v62 + 80) = 2;
						result = 0;
					}
				}
				else
				{
					*(DWORD *)(v62 + 80) = 0;
					result = 1;
				}
			}
			else
			{
				*(DWORD *)(v62 + 80) = 1;
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}
	return result;
}
//----- (00813CA0)
void sub_813CA0(DWORD *a1)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	int v6; // [sp+18h] [bp-18h]@1
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2

	v6 = *(DWORD *)a1;
	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
	{
		v10 = 270.0;
		v11 = 330.0;
		v8 = 32.0;
		v9 = 38.0;
		for ( i = 150; i < 154; ++i )
		{
			if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )
				pDrawGUI(31313, v10, v11, v8, v9);
			else
				pDrawGUI(31312, v10, v11, v8, v9);
			v4 = v11 + 6.0;
			v5 = v10 + 6.0;
			sub_813DC0(a1, i, v5, v4, 20.0, 28.0);
			v10 = v10 + v8;
		}
	}
}

char SkillBarSwitch(int This)
{
	float v4; // ST18_4@26
	float v5; // ST14_4@26
	int v7; // [sp+28h] [bp-34h]@1
	int v8; // [sp+30h] [bp-2Ch]@15
	char v9; // [sp+37h] [bp-25h]@9
	float v10; // [sp+38h] [bp-24h]@3
	signed int v11; // [sp+3Ch] [bp-20h]@3
	signed int v12; // [sp+40h] [bp-1Ch]@6
	float v13; // [sp+44h] [bp-18h]@3
	float v14; // [sp+48h] [bp-14h]@3
	signed int i; // [sp+50h] [bp-Ch]@3
	float v16; // [sp+54h] [bp-8h]@16
	float v17; // [sp+58h] [bp-4h]@3

	v7 = This;

	if ( (signed int)*(BYTE *)(*(DWORD *)0x8128AC8 + 118) > 0 && *(BYTE *)(v7 + 64) == 1 )
	{
		v17 = 370.0;
		v13 = 32.0;
		v14 = 38.0;
		v10 = 302.0;
		v11 = 0;

		for ( i = 0; i < 150; ++i )
		{
			v12 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);

			if ( *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72) )
			{
				v9 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v12 + 55);
				if ( v9 != 1 && v9 != 3 )
				{
					if ( v11 == 11 )
					{
						v17 = v17 - v14;
					}
					if ( v11 >= 11 )
					{
						if ( v11 < 11 || v11 > 21 )
						{
							v16 = v10 - v13 * 11.0 + (double)(v11 - 21) * v13;
						}
						else
						{
							v16 = v10 - v13 * 6 + (double)(v11 - 10) * v13;
						}
					}
					else
					{
						v8 = v11 / 2;
						if ( v11 % 2 )
						{
							v16 = v10 - (double)(v8 + 1) * v13;
						}
						else
						{
							v16 = (double)v8 * v13 + v10;
						}
					}
					
					++v11;

					if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )//-- Seleccionado
					{
						pDrawGUI(31313, v16, v17, v13, v14);
					}
					else
					{
						pDrawGUI(31312, v16, v17, v13, v14);
					}
					v4 = v17 + 6.0;
					v5 = v16 + 6.0;
					sub_813DC0((DWORD *)This, i, v5, v4, 20.0, 28.0);
				}
			}
		}
		sub_813CA0((DWORD *)This);
	}

	if ( *(BYTE *)(This + 65) == 1 && *(DWORD *)(This + 16) )
	{
		Render_772EA0(This);
		*(BYTE *)(This + 65) = 0;
	}
	return 1;
}

void Render_772EA0(int ThisR)
{
	static DWORD Addr1 = 0x00815040;
	static DWORD Addr2_Call = 0x00772EA0;
	static DWORD This = 0x00772EA0;

	This = ThisR;

	_asm
	{
		PUSH 0                              ; /Arg5 = 00000000
		PUSH 0                              ; |Arg4 = 00000000
		MOV ECX,This                        ; |
		PUSH ECX                            ; |Arg3
		PUSH Addr1                          ; |Arg2 = 00815040
		PUSH ECX                            ; |Arg1
		FLD DWORD PTR DS:[0xD2CA40]         ; |
		FSTP DWORD PTR SS:[ESP]             ; |
		MOV EDX,This                        ; |
		MOV ECX,DWORD PTR DS:[EDX + 0x10]   ; |
		CALL Addr2_Call                     ; \main1.00772EA0
	}
}

void RenderMasterSkill(DWORD texture, float x, float y, float w, float h) {
	pDrawGUI(texture, x, y, w, 428);
}

void SkillNumberPositionEx(float a4, float a5, int a6, float a7)
{
	return RenderNumber(a4 - 4.5f, a5 - 3.5f, a6, a7);
}

__declspec(naked) void ToolTipSkill55()
{
	static DWORD SkillRavenClicDraw_buff = 0x00813C25;

	_asm
	{
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x04]
		MOV EAX,DWORD PTR DS:[EDX+0x4C]
		SUB EAX,0x1B
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x04]
		MOV EDX,DWORD PTR DS:[ECX+0x48]
		ADD EDX,0x0F
		jmp [SkillRavenClicDraw_buff]
	}
}

__declspec(naked) void SkillBarra()
{
	static float SkillBarraX = 307.0f;
	static float SkillBarraY = 436.5f;
	static float SkillBarraW = 20.0f;
	static float SkillBarraH = 32.0f;
	static DWORD SkillBarra_buff = 0x0081379A;
	_asm
	{	
	FLD DWORD PTR DS:[SkillBarraX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[SkillBarraY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[SkillBarraW]
	FSTP DWORD PTR SS:[EBP-0x18]
	FLD DWORD PTR DS:[SkillBarraH]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SkillBarra_buff]
	}
}

__declspec(naked) void UsingSkillPosition()
{
	static float UsingSkillPositionX = 309.8f;
	static float UsingSkillPositionY = 442.5f;
	static float UsingSkillPositionW = 20.0f;
	static float UsingSkillPositionH = 28.0f;
	static DWORD UsingSkillPosition_buff = 0x00813900;
	_asm
	{
	FLD DWORD PTR DS:[UsingSkillPositionX]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[UsingSkillPositionY]
	FSTP DWORD PTR SS:[EBP-0x4]
	FLD DWORD PTR DS:[UsingSkillPositionW]
	FSTP DWORD PTR SS:[EBP-0x18]
	FLD DWORD PTR DS:[UsingSkillPositionH]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [UsingSkillPosition_buff]
	}
}

void SkillBoxInBar(DWORD ModelId, float PosX, float PosY, float Height, float Width)
{
	pDrawGUI(51500, PosX, PosY + 0.8, 32.0, 32.0);
}
//==================================================================================
//-- Print Player
//==================================================================================
void RenderBarAG()
{
}

void RenderBarSD(){
}

void RenderCircleMH(){
}

void RenderExpBar(int a1){
	DWORD ReadExp;
	DWORD ReadNextExp;
	QWORD CurrentMasterExp;
	QWORD NextMasterExp;
	pBarExpDraw();
	gInterface.DrawIMG(eMainEx700Exp, 36, 414, 1.5, 2.0);
	if ( pIsMaster(*(BYTE *)(*(DWORD *)0x7BC4F04 + 19)) == 1 ){
		NextMasterExp = *(QWORD *)0x87935E8;
		CurrentMasterExp = *(QWORD *)0x87935E0;	
		gInterface.DrawFormat(eWhite150, 92.0f , 471, 454, 3, "%I64u / %I64u", CurrentMasterExp, NextMasterExp);
	}else{
		ReadExp = *(WORD *)(*(DWORD *)0x8128AC8 + 0x10);
		ReadNextExp = *(DWORD *)(*(DWORD *)0x8128AC8 + 0x14);
		gInterface.DrawFormat(eWhite150, 92.0f , 471, 454, 3, "%d / %d", ReadExp, ReadNextExp);
	}
}


void pDrawRenderParty(DWORD id, float X, float Y,float W, float H)
{
	Y += 11;
	pDrawGUI(id, X, Y, W, H);
}

void InitInterEx(){
	SetCompleteHook(0xE8, 0x0084C172, &pDrawRenderParty);
	SetCompleteHook(0xE8, 0x00813BB2, &sub_813CA0);
	//-- SlotPotion
	SetCompleteHook(0xE9, 0x00895A48, &RenderSlotQ);
	SetCompleteHook(0xE9, 0x00895ABD, &RenderSlotW);
	SetCompleteHook(0xE9, 0x00895B32, &RenderSlotE);
	SetCompleteHook(0xE9, 0x00895BA7, &RenderSlotR);
	//-- Print Player
	SetCompleteHook(0xE8, 0x0080F865, &RenderExpBar);
	SetCompleteHook(0xE9, 0x0080FA10, &RenderCircleMH);
	SetCompleteHook(0xE9, 0x00810420, &RenderBarSD);
	SetCompleteHook(0xE9, 0x00810150, &RenderBarAG);
	//-- FULL SKILL
	SetCompleteHook(0xE8, 0x0081A146, &RenderMasterSkill);
	SetCompleteHook(0xE8, 0x0081A199, &RenderMasterSkill);
	SetCompleteHook(0xE9, 0x008126C0, &SkillFullGM);
	//--
	SetCompleteHook(0xE9, 0x00813970, &SkillBarSwitch);

//	SetCompleteHook(0xE8, 0x004F9477, &Render_SkillTooltip);//-- Tooltip Skill Raven
//	SetCompleteHook(0xE8, 0x005C6680, &Render_SkillTooltip);//-- Tooltip Skill
	//--
	SetRange((LPVOID)0x008138DF, 0x24, ASM::NOP);
	SetOp((LPVOID)0x008138DF, (LPVOID)UsingSkillPosition, ASM::JMP);
	//--
	SetRange((LPVOID)0x00813779, 0x24, ASM::NOP);
	SetOp((LPVOID)0x00813779, (LPVOID)SkillBarra, ASM::JMP);
	//--
	SetOp((LPVOID)0x00813885, (LPVOID) SkillBoxInBar, ASM::CALL);
	SetOp((LPVOID)0x00814E63, (LPVOID) SkillNumberPositionEx, ASM::CALL);
	//-- PartyBar
	SetByte(0x0085AF21, 25); //<-
	SetRange((LPVOID)0x0084B95E, 5, ASM::NOP);
	SetJmp((LPVOID)0x0084B95E, PartyWindowsMove);
	//--
	SetOp((LPVOID)0x00834700, (LPVOID)MouseClickRender, ASM::CALL);
	//--
	//EXP
	SetDouble((PVOID)(0x00D461C0), 572);
	SetRange((LPVOID)0x00811205, 5, ASM::NOP);
	SetOp((LPVOID)0x00811205, (LPVOID)EXP1, ASM::JMP);
	SetRange((LPVOID)0x008113DE, 5, ASM::NOP);
	SetOp((LPVOID)0x008113DE, (LPVOID)EXP2, ASM::JMP);
	SetRange((LPVOID)0x00811528, 5, ASM::NOP);
	SetOp((LPVOID)0x00811528, (LPVOID)EXP3, ASM::JMP);
	SetRange((LPVOID)0x008116EF, 5, ASM::NOP);
	SetOp((LPVOID)0x008116EF, (LPVOID)EXP4, ASM::JMP);
	//EXPMASTER
	SetRange((LPVOID)0x00810B47, 5, ASM::NOP);
	SetOp((LPVOID)0x00810B47, (LPVOID)EXPMASTER1, ASM::JMP);
	SetRange((LPVOID)0x00810C8B, 5, ASM::NOP);
	SetOp((LPVOID)0x00810C8B, (LPVOID)EXPMASTER2, ASM::JMP);
	SetRange((LPVOID)0x00810E52, 5, ASM::NOP);
	SetOp((LPVOID)0x00810E52, (LPVOID)EXPMASTER3, ASM::JMP);
	SetRange((LPVOID)0x00810F4F, 5, ASM::NOP);
	SetOp((LPVOID)0x00810F4F, (LPVOID)EXPMASTER4, ASM::JMP);
	SetRange((LPVOID)0x00810B7F, 5, ASM::NOP);
	//==============================================================
	//-- Fix
	//==============================================================
	SetDword(0x004D9746 + 3, 480); //Size Background
	SetRange((LPVOID)0x0080F270, 0x4D1, ASM::NOP); //-- Disable Buttons
	SetDouble((PVOID)(0x00D27AF8), 0.400000011920929); //-- Tamaño Numeros
	SetDword(0x008124F5 + 1, 0x9000);
	SetDword(0x0086D107 + 1, 0x9000);
	SetDword(0x0081A40F + 1, 0x9001);	//hace miniatura los skill
	SetRange((LPVOID)(0x0086D111), 0x5, ASM::NOP); //recarga ui skill2
	SetRange((LPVOID)(0x0086D131), 0x5, ASM::NOP); //recarga none skill2
	SetRange((LPVOID)(0x00888E7F), 0x5, ASM::NOP); //desconozco que hace xD
	//-- soluciona bug de master skill
	SetDword((PVOID)(0x0081A3F4+1), (DWORD)MasterIconEx700); //1.04E-> 0081A3F4 || 1.04D->0x0081A2A4
	SetDword((PVOID)(0x0081A414+1), (DWORD)NonMasterIconEx700); //1.04E-> 0081A414 || 1.04D->0x0081A2C4
	SetOp((LPVOID)(0x00888E7F), (LPVOID)LoadSkill2Ex700, ASM::CALL); //recarga la textura skill2
	SetCompleteHook(0xE8, 0x005B97DC,&RenderSands);
	SetCompleteHook(0xE8, 0x005B984C,&RenderSands);
	SetCompleteHook(0xE8, 0x008C2E0F,&RenderSands);
	SetCompleteHook(0xE8, 0x008C2E7F,&RenderSands);
			//-- Local calls from , , 005B9904, , , 008CC713, 008CC788, 008D99B8, 008D9A2D, , , , , , 
	SetCompleteHook(0xE8, 0x008EF65A,&RenderSands);
	SetCompleteHook(0xE8, 0x008EF5C5,&RenderSands);
	SetCompleteHook(0xE8, 0x00914FC9,&RenderSands);
	SetCompleteHook(0xE8, 0x0091503E,&RenderSands);
}