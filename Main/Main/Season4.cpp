#include "stdafx.h"
#include "Season4.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "Util.h"
#include "zzzmathlib.h"

void LoginScreen4(int a1, DWORD* a2)
{
	if (SceneFlag == 2) //
	{
		BeginBitmap();
		glColor4f(0.6953125, 0.6953125, 0.6953125, 1.0);
		pDrawBarForm(0.0, 25.0, 640.0, 430.0, 0.0, 0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		pSetBlend(1);
		pDrawImage(531011, 0.0, 25.0, 320.0, 320.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		pDrawImage(531012, 320.0, 25.0, 320.0, 320.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EndOpengl();
		camaramove();
		SetFloat((PVOID)(0x005DB53F), -2.0140844e38);//-2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.7065288e38);//-2.70652875E38);
		*(float*)0xE61E3C = 3200.0;  //20000.0;
		*(float*)0xE61E40 = 61.0;	  //35.0;
		*(float*)0x87933D0 = -78.5;	  //-84.5;
		SetFloat((PVOID)(0xD27B9C), -78.5);
		*(float*)0x87933D4 = 0.0;	  //0.0;


	}
	if (SceneFlag == 4) //Select Character
	{
		//RotateCharacter();
		BeginBitmap();
		glColor4f(1.0, 1.0, 1.0, 1.0);
		pSetBlend(1);

		pDrawImage(531013, 0.0, 25.0, 320.0, 320.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		pDrawImage(531014, 320.0, 25.0, 320.0, 320.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EndOpengl();
		//SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		//SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 3200.0;  //20000.0;
		*(float*)0x87933D0 = -84.5;	  //-84.5;
		*(float*)0x87933D4 = 0.0;	  //0.0;
		*(float*)0x87933D8 = -30.0;	  //-80.0;
		*(float*)0x87933DC = 23566.801; //15215.08887;
		*(float*)0x87933E0 = 14085.5; //12186.53613;
		*(float*)0x87933E4 = 395.0;	  //495.500061;
		*(float*)0xE61E40 = 35.0;	  //35.0;	  
	}


}

void RenderSSCObjectVisual4(int a1, int a2)
{
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
	int v2; // ecx@6
	float v3; // ST28_4@6

  //Select Server y Selec Character
	if (World == 77 || World == 78)
	{
		switch (*(DWORD*)(a1 + 48))
		{
		case 2:
		case 53:
		case 55:
		{
			BeginRender(1.0);
			*(DWORD*)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
			float v552 = 2000;
			float v551 = ((int)(v552 + timeGetTime()) % 2001) * 0.0005000000237487257;
			RenderMesh(a2,
				0,
				66,
				*(float*)(a1 + 152),
				*(DWORD*)(a1 + 68),
				*(float*)(a1 + 100),
				*(float*)(a1 + 104),
				v551,
				-1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
		}

		break;
		}
	}
	CryingWolf2ndObjectVisual3(a1, a2);
}

__declspec(naked) void SwitchCharacterView4()
{
	static float View = 33000.0f;
	static DWORD SwitchCharacter_buff = 0x004D87D4;
	_asm
	{
		FLD DWORD PTR DS : [View]
		FSTP DWORD PTR DS : [View]
		jmp[SwitchCharacter_buff]
	}
}

__declspec(naked) void GameProcessView4()
{
	static float View = 20000.0f;
	static DWORD GameProcess_buff = 0x004D8808;
	_asm
	{
		FLD DWORD PTR DS : [View]
		FSTP DWORD PTR DS : [View]
		jmp[GameProcess_buff]
	}
}


DWORD PlayerID4_Offset = 0x005DB532;
void __declspec(naked) PlayerID4()
{
	_asm
	{
		CMP DWORD PTR DS : [0xE609E8] , 0x2
		je ReturnLoad
		CMP DWORD PTR DS : [0xE609E8] , 0x4
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp PlayerID4_Offset
	}
}

__declspec(naked) void SelectCharacterCordPJ1SS4()
{
	static float D41DCC = 22628.0f;
	static float D41DC8 = 15012.0f;
	static float D27AE0 = 100.0f;
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
		FLD DWORD PTR DS : [D41DCC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DC8]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D27AE0]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ21SS4()
{
	static float D41DCC = 22628.0f;
	static float D41DC8 = 15012.0f;
	static float D27AE0 = 100.0f;
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
		FLD DWORD PTR DS : [D41DCC]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DC8]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D27AE0]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ2SS4()
{
	static float D41DC4 = 22700.0f;
	static float D41DC0 = 15201.0f;
	static float D254C0 = 75.0f;
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D206;
	_asm
	{
		FLD DWORD PTR DS : [D41DC4]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DC0]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D254C0]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ22SS4()
{
	static float D41DC4 = 22700.0f;
	static float D41DC0 = 15201.0f;
	static float D254C0 = 75.0f;
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D447;
	_asm
	{
		FLD DWORD PTR DS : [D41DC4]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DC0]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D254C0]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ3SS4()
{
	static float D41DBC = 22840.0f;
	static float D41DB8 = 15355.0f;
	static float D2B954 = 50.0f;
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D223;
	_asm
	{
		FLD DWORD PTR DS : [D41DBC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DB8]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D2B954]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ23SS4()
{
	static float D41DBC = 22840.0f;
	static float D41DB8 = 15355.0f;
	static float D2B954 = 50.0f;
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D464;
	_asm
	{
		FLD DWORD PTR DS : [D41DBC]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DB8]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D2B954]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ4SS4()
{
	static float D41DB4 = 23019.0f;
	static float D41DB0 = 15443.0f;
	static float D2577C = 25.0f;
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D240;
	_asm
	{
		FLD DWORD PTR DS : [D41DB4]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DB0]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D2577C]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ24SS4()
{
	static float D41DB4 = 23019.0f;
	static float D41DB0 = 15443.0f;
	static float D2577C = 25.0f;
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D481;
	_asm
	{
		FLD DWORD PTR DS : [D41DB4]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DB0]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D2577C]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ5SS4()
{
	static float D41DAC = 23211.6f;
	static float D41DA8 = 15467.0f;
	static float D27BFC = 0.0f;
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D25D;
	_asm
	{
		FLD DWORD PTR DS : [D41DAC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		FLD DWORD PTR DS : [D41DA8]
		FSTP DWORD PTR SS : [EBP - 0x10]
		FLD DWORD PTR DS : [D27BFC]
		FSTP DWORD PTR SS : [EBP - 0x18]
		jmp[SelectCharacterCordPJ5_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ25SS4()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 0.0f;
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D49E;
	_asm
	{
		FLD DWORD PTR DS : [D41DAC]
		FSTP DWORD PTR SS : [EBP - 0xC]
		FLD DWORD PTR DS : [D41DA8]
		FSTP DWORD PTR SS : [EBP - 0x8]
		FLD DWORD PTR DS : [D27BFC]
		FSTP DWORD PTR SS : [EBP - 0x14]
		jmp[SelectCharacterCordPJ5_buff]
	}
}

void __declspec(naked) CWScript()
{
	static DWORD CReturn = 0x0062EC74;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) tescamaramove()
{
	static DWORD CReturn = 0x004D84F4;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) EffectSelecServer()
{
	static DWORD CReturn = 0x00910074;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) EffectSelecChar()
{
	static DWORD CReturn = 0x0091007D;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 4Ah; 'J'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 78//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) RenderWorld2()
{
	static DWORD CReturn = 0x004DA0AD;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld3()
{
	static DWORD CReturn = 0x005524E0;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld4()
{
	static DWORD CReturn = 0x005D9630;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld5()
{
	static DWORD CReturn = 0x005DB83C;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) RenderWorld6()
{
	static DWORD CReturn = 0x005DC593;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld7()
{
	static DWORD CReturn = 0x005EE0CF;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) RenderWorld8()
{
	static DWORD CReturn = 0x005EE16C;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld9()
{
	static DWORD CReturn = 0x005EE820;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) ObejtcEbeland()
{
	static DWORD CReturn = 0x0062F113;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 33h; '3'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld11()
{
	static DWORD CReturn = 0x008FCEE4;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}
void __declspec(naked) RenderWorld12()
{
	static DWORD CReturn = 0x008FE643;
	_asm
	{
		CMP DWORD PTR DS : [0xE61E18] , 49h; 'I'
		je ReturnLoad
		CMP DWORD PTR DS : [0xE61E18] , 77//ID del Mapa
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void LogoMUm4(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, int a10, int a11, float a12)
{

	if (a1 == 31019)
	{
		RenderBitmap(531019, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
	}
	else if (a1 == 31018)
	{
		RenderBitmap(531018, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
	}


}

void sub_636220()
{
	if (AlphaBlendType != 7)//( v8793258 != 7 )
	{
		AlphaBlendType = 7;//v8793258 = 7;
		glEnable(0xBE2u);
		glBlendFunc(1u, 0x301u);
	}
	sub_635EB0();
	sub_635E60();
	if (*(BYTE*)0x879325C)
	{
		*(BYTE*)0x879325C = 0;
		glDisable(0xBC0u);
	}
	if (!*(BYTE*)0x8793260)
	{
		*(BYTE*)0x8793260 = 1;
		glEnable(0xDE1u);
	}
	if (*(BYTE*)0x87933F9)
		glEnable(0xB60u);
}

void sub_4D7AF9()
{
	int v0; // eax@1
  //  double v1; // st7@1
	double v2; // st7@2
	float v3; // ST38_4@2
	float red; // ST20_4@2
	float v5; // ST38_4@2
	float v6; // ST1C_4@2
	float v7; // ST38_4@2
	float v8; // ST18_4@2
	float v9; // ST38_4@2
	float v10; // ST3C_4@2
	signed int v11; // eax@2
	float v12; // ST38_4@2
	float v13; // ST34_4@2
	float alpha; // ST2C_4@2
	float v15; // ST38_4@2
	double v16; // st6@2
	float v17; // ST34_4@2
	float v18; // ST38_4@2
	float blue; // ST28_4@3
	float green; // ST24_4@3
	float v21; // ST20_4@3

	BeginBitmap();
	v0 = sub_4DDF50();
	if (sub_4DB060(v0))
	{
		sub_636220();
		glColor4f(0.69999999, 0.69999999, 0.69999999, 1.0);
		v2 = ((sin(*(float*)0xE8CB18 * 0.00050000002) + 1.0) * 0.00011);
		v3 = 0.5859375 - v2 * 1200.0;
		red = v3;
		v5 = 0.78125 - v2 * 1600.0;
		v6 = v5;
		v7 = v2 * 600.0;
		v8 = v7;
		v9 = v2 * 800.0;
		RenderBitmap(532028, 0.0, 0.0, 640.0, 480.0, v9, v8, v6, red, 1, 1, 0.0);
		v10 = *(float*)0xE8CB18 * 0.00018;
		v11 = (1.0 - (sin(*(float*)0xE8CB18 * 0.0015) + 1.0) * 0.25);
		v12 = v11;
		v13 = v11 * 0.30000001;
		alpha = v12;
		v15 = v12 * 0.69999999;
		glColor4f(v13, v13, v15, alpha);
		v16 = ((sin(*(float*)0xE8CB18 * 0.0015) + 1.0) * 0.00021);
		v17 = 1.0 - 1024.0 * v16;
		v18 = v16 * 512.0;
		RenderBitmapLocalRotate(532029, 320.0, 240.0, 1150.0, 1150.0, v10, v18, v18, v17, v17);
		EnableAlphaTest(1);

	}

	glColor4f(0.0, 0.0, 0.0, 1.0);
	pDrawBarForm(0.0, 0.0, 640.0, 25.0, 0.0, 0);
	pDrawBarForm(0.0, 455.0, 640.0, 25.0, 0.0, 0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
}



void SCharacterS4()
{

	SetCompleteHook(0xE9, 0x0062EC6D, &CWScript);

	SetDword((LPVOID)0x004D75F0, 77);//Select Server
	SetDword((LPVOID)0x004D6C2C, 78);//Select Character

	SetCompleteHook(0xE8, 0x004D76FB, &LoginScreen4);//Select Server
	SetCompleteHook(0xE8, 0x004D79C3, &LoginScreen4);//Select Server
	SetCompleteHook(0xE8, 0x004D712A, &LoginScreen4);//Select Character

	//SetCompleteHook(0xE9, 0x004D84ED, &tescamaramove);	
	SetCompleteHook(0xE9, 0x0091006D, &EffectSelecServer);//efectos selec server
	SetCompleteHook(0xE9, 0x00910076, &EffectSelecChar);//efecto selec char

	SetCompleteHook(0xE9, 0x004DA0A6, &RenderWorld2);//mejora el rendimiento o velocidad de la camara al cargar los objetos
	SetCompleteHook(0xE9, 0x005524D9, &RenderWorld3);//mejora el rendimiento o velocidad de la camara al cargar los objetos
	SetCompleteHook(0xE9, 0x005D9629, &RenderWorld4);//mejora el rendimiento o velocidad de la camara al cargar los objetos
	SetCompleteHook(0xE9, 0x005DB835, &RenderWorld5);//mejora el rendimiento o velocidad de la camara al cargar los objetos
	SetCompleteHook(0xE9, 0x005DC58C, &RenderWorld6);//mejora el rendimiento o velocidad de la camara al cargar los objetos
	SetCompleteHook(0xE9, 0x005EE0C8, &RenderWorld7);//mejora el rendimiento o velocidad de la camara al cargar los objetos
//	SetCompleteHook(0xE9, 0x005EE165, &RenderWorld8);//mueve algo no se que putas es
//	SetCompleteHook(0xE9, 0x005EE819, &RenderWorld9);
	SetCompleteHook(0xE9, 0x0062F10C, &ObejtcEbeland);//objetos map 51
	SetCompleteHook(0xE9, 0x008FCEDD, &RenderWorld11);
	SetCompleteHook(0xE9, 0x008FE63C, &RenderWorld12);

	SetCompleteHook(0xE8, 0x4D7C98, &LogoMUm4);
	SetCompleteHook(0xE8, 0x4D7C0D, &LogoMUm4);

	SetCompleteHook(0xE8, 0x4D7AF9, &sub_4D7AF9);

	SetCompleteHook(0xE8, 0x005EDE8B, &RenderSSCObjectVisual4);

	SetOp((LPVOID)0x004D87C8, (LPVOID)SwitchCharacterView4, ASM::JMP);
	SetOp((LPVOID)0x004D87FC, (LPVOID)GameProcessView4, ASM::JMP);
	SetOp((LPVOID)0x005DB52B, (LPVOID)PlayerID4, ASM::JMP);

	//---------
	SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1SS4, ASM::JMP);
	SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21SS4, ASM::JMP);

	SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ2SS4, ASM::JMP);
	SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ22SS4, ASM::JMP);

	SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ3SS4, ASM::JMP);
	SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ23SS4, ASM::JMP);

	SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ4SS4, ASM::JMP);
	SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ24SS4, ASM::JMP);

	SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ5SS4, ASM::JMP);
	SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
	SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ25SS4, ASM::JMP);

	SetFloat((LPVOID)0xD27B0C, 61.0);
	SetFloat((LPVOID)0xD27B08, 40.0);//y+ y-
	SetFloat((LPVOID)0x503834, -21.0);

	SetDword((LPVOID)0x57F0FC, -23.0);
	SetDword((LPVOID)0x57F0FD, 74.0);
	SetDword((LPVOID)0x57F0FE, 1);
	SetDword((LPVOID)0x57F0FF, 0);
	SetDword((LPVOID)0x57F100, 0);
	SetDword((LPVOID)0x57F101, -112);
}


//#include "stdafx.h"
//#include "Season4.h"
//#include "Offset.h"
//#include "Import.h"
//#include "Util.h"
//#include "TMemory.h"
//#include "zzzMathLib.h"
//#include "Protect.h"
//
//void CLoadBitmapA(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)
//{
//	LoadBitmapA("Object8\\light01.jpg", 30356, 9729, 10497, 1, 0);
//	LoadBitmapA("Logo\\New_Login_Back01.jpg", 531011, GL_LINEAR, GL_CLAMP, 1, 0);
//	LoadBitmapA("Logo\\New_Login_Back02.jpg", 531012, GL_LINEAR, GL_CLAMP, 1, 0);
//
//	LoadBitmapA("Logo\\sos3sky01.jpg", 531013, GL_LINEAR, GL_CLAMP, 1, 0);
//	LoadBitmapA("Logo\\sos3sky02.jpg", 531014, GL_LINEAR, GL_CLAMP, 1, 0);
//
//	LoadBitmapA("World78\\bg_b_08.jpg", 532029, GL_LINEAR, GL_CLAMP, 1, 0);
//	LoadBitmapA("World78\\bg_b_05.jpg", 532028, GL_LINEAR, GL_CLAMP, 1, 0);
//	LoadBitmapA("Logo\\MU-logo.tga", 531018, GL_LINEAR, GL_REPEAT, 1, 0);	
//	LoadBitmapA("Logo\\MU-logo_g.jpg", 531019, GL_LINEAR, GL_REPEAT, 1, 0);	
//}
//
//void CMoveMainCamera(int a1, DWORD *a2)
//{
//	if (SceneFlag == 2)
//	{
//		BeginBitmap();
//		glColor4f(0.6953125, 0.6953125, 0.6953125, 1.0);
//		pDrawBarForm(0, 25, 640, 430, 0.0, 0);
//		glColor4f(1.0, 1.0, 1.0, 1.0);
//		EnableAlphaTest(1);
//		RenderBitmap(531011, 0.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//		RenderBitmap(531012, 320.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//		EndOpengl();
//
//		MoveMainCamera();
//		SetFloat(0x005DB53F, -2.014084447E38);
//		SetFloat(0x005DB55D, -2.70652875E38);
//		*(float*)0xE61E3C = 3200.0;
//		*(float*)0xE61E40 = 61.0;
//		*(float*)0x87933D0 = -78.50;
//		SetFloat(0x00D27B9C, -78.50);
//		*(float*)0x87933D4 = 0.0;
//	}
//
//	if (SceneFlag == 4)
//	{
//		BeginBitmap();
//		glColor4f(0.6953125, 0.6953125, 0.6953125, 1.0);
//		pDrawBarForm(0, 25, 640, 430, 0.0, 0);
//		glColor4f(1.0, 1.0, 1.0, 1.0);
//		EnableAlphaTest(1);
//		RenderBitmap(531011, 0.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//		RenderBitmap(531012, 320.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//
//		MoveMainCamera();
//		SetFloat(0x005DB53F, -2.014084447E38);
//		SetFloat(0x005DB55D, -2.70652875E38);
//		*(float*)0xE61E3C = 3200.0;
//		*(float*)0xE61E40 = 61.0;
//		*(float*)0x87933D0 = -78.50;
//		//SetFloat(0x00D27B9C, -78.50); //camera do select char, amplia a imagem dele hehe
//		*(float*)0x87933D4 = 0.0;
//
//		glColor4f(1.0, 1.0, 1.0, 1.0);
//		RenderBitmap(531013, 0.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//		RenderBitmap(531014, 320.0, 25.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//		EndOpengl();
//
//	  *(float*)0xE61E3C = 3200.0;
//      *(float*)0x87933D0 = -84.5;
//      *(float*)0x87933D4 = 0.0;
//      *(float*)0x87933D8 = -30.0;
//      *(float*)0x87933DC = 23566.8;
//      *(float*)0x87933E0 = 14085.5;
//      *(float*)0x87933E4 = 395;	
//	  *(float*)0xE61E40 = 35.0;	
//
//	  if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
//	  {
//		  *(float *)(((GetCharacter(GetPreview(),0)) + 776) + 252) = 22628;
//		  *(float *)(((GetCharacter(GetPreview(),0)) + 776) + 256) = 15012;
//		  *(float *)(((GetCharacter(GetPreview(),0)) + 776) + 272) = 100;
//	  
//		  *(float *)(((GetCharacter(GetPreview(),1)) + 776) + 252) = 22700;
//		  *(float *)(((GetCharacter(GetPreview(),1)) + 776) + 256) = 15201;
//		  *(float *)(((GetCharacter(GetPreview(),1)) + 776) + 272) = 75;
//	  
//		  *(float *)(((GetCharacter(GetPreview(),2)) + 776) + 252) = 22840;
//		  *(float *)(((GetCharacter(GetPreview(),2)) + 776) + 256) = 15355;
//		  *(float *)(((GetCharacter(GetPreview(),2)) + 776) + 272) = 50;
//	  
//		  *(float *)(((GetCharacter(GetPreview(),3)) + 776) + 252) = 23019;
//		  *(float *)(((GetCharacter(GetPreview(),3)) + 776) + 256) = 15443;
//		  *(float *)(((GetCharacter(GetPreview(),3)) + 776) + 272) = 25;
//	  
//		  *(float *)(((GetCharacter(GetPreview(),4)) + 776) + 252) = 23211.6;
//		  *(float *)(((GetCharacter(GetPreview(),4)) + 776) + 256) = 15467;
//		  *(float *)(((GetCharacter(GetPreview(),4)) + 776) + 272) = 0;
//	  }
//	}
//}
//
//
//void EnableAlphaBlend4()
//{
//  if ( *(DWORD*)0x8793258 != 7 )
//  {
//    *(DWORD*)0x8793258 = 7;
//    glEnable(0xBE2u);
//    //glBlendFunc(0x302u, 0x303u);
//	glBlendFunc(1u, 0x301u);
//  }
//  DisableCullFace();
//  DisableDepthMask();
//  if ( *(BYTE*)0x879325C )
//  {
//    *(BYTE*)0x879325C = 0;
//    glDisable(0xBC0u);
//  }
//  if ( !*(BYTE*)0x8793260 )
//  {
//    *(BYTE*)0x8793260 = 1;
//    glEnable(0xDE1u);
//  }
//  if ( *(BYTE*)0x87933F9 )
//    glEnable(0xB60u);
//}
//
//void CMuRenderSands()
//{
//	BeginBitmap();
//    if ( CCameraMove_IsTourMode(CCameraMove_GetInstancePtr()) )
//    {
//		int v7;
//		int v12;
//		int v14;
//		float v8;
//		float v9;
//		float v10;
//		float v11;
//		float v13;
//		float green;
//		float alpha;
//		float red;
//		EnableAlphaBlend4();
//		glColor4f(0.69999999, 0.69999999, 0.69999999, 1.0);
//		v7 = (sin(*(float*)0xE8CB18 * 0.00050000002) + 1.0) * 0.00011;
//		v8 = 0.5859375 - v7 * 1200.0;
//		v9 = 0.78125 - v7 * 1600.0;
//		v10 = v7 * 600.0;
//		v11 = v7 * 800.0;
//		RenderBitmap(532028, 0.0, 0.0, 640.0, 480.0, v11, v10, v9, v8, 1, 1, 0.0);
//		green = *(float*)0xE8CB18 * 0.00018;
//		v12 = 1.0 - (sin(*(float*)0xE8CB18 * 0.0015) + 1.0) * 0.25;
//		alpha = v12;
//		red = v12 * 0.30000001;
//		v13 = alpha * 0.69999999;
//		glColor4f(red, red, v13, alpha);
//		v14 = (sin(*(float*)0xE8CB18 * 0.0015) + 1.0) * 0.00021;
//		red = 1.0 - v14 * 1024.0;
//		alpha = v14 * 512.0;
//		RenderBitmapRotate(532029, 320.0, 240.0, 1150.0, 1150.0, green, alpha, alpha, red, red);
//		EnableAlphaTest(1);
//	}
//
//	glColor4f(0.0, 0.0, 0.0, 1.0);
//
//	pDrawBarForm(0, 0, 640, 25, 0.0, 0);
//
//	pDrawBarForm(0, 455, 640, 25, 0.0, 0);
//
//	glColor4f(1.0, 1.0, 1.0, 1.0);
//
//}
//
//void CMULogo(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)
//{
//	if(a1 == 31019)
//	RenderBitmap(531019, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
//	if(a1 == 31018)
//	RenderBitmap(531018, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
//}
//
//
//void CSEASON3B_GMNewTown_RenderObjectVisual(int a1, int a2)
//{	
//	if(*(int*)0xE61E18 == 82 || *(int*)0xE61E18 == 83)
//	{
//		switch ( *(DWORD *)(a1 + 48) )
//		{
//			case 2:
//			case 53:
//			case 55:
//			{
//			BeginRender(1.0);
//			*(DWORD *)(a1 + 60) = -2;
//			*(BYTE*)(a2 + 136) = 0;
//			RenderMesh(a2,
//			  0,
//			  66,
//			  *(float *)(a1 + 152),
//			  *(DWORD *)(a1 + 68),
//			  *(float *)(a1 + 100),
//			  *(float *)(a1 + 104),
//			  *(float *)(a1 + 108) = *(float *)(a1 + 108) + 0.015,
//			  -1);
//			*(BYTE*)(a2 + 136) = -1;
//			EndRender();
//			}
//			break;
//			}
//	}
//	SEASON3B_GMNewTown_RenderObjectVisual(a1,a2);
//}
//
//__declspec(naked) void SwitchCharacterView401()
//{
//	static float View = 7000.0;
//	static DWORD SwitchCharacter_buff = 0x004D87D4;
//	_asm
//	{
//	FLD DWORD PTR DS:[View]
//	FSTP DWORD PTR DS:[View]
//	jmp [SwitchCharacter_buff]
//	}
//}
//
//__declspec(naked) void GameProcessView401()
//{
//	static float View = 7000.0;
//	static DWORD GameProcess_buff = 0x004D8808;
//	_asm
//	{
//	FLD DWORD PTR DS:[View]
//	FSTP DWORD PTR DS:[View]
//	jmp [GameProcess_buff]
//	}
//}
//
//DWORD PlayerID_OffsetS4 = 0x005DB532; 
//void __declspec(naked) PlayerID401()
//{
//	_asm
//	{
//			CMP DWORD PTR DS:[0xE609E8],0x2
//			je ReturnLoad
//			CMP DWORD PTR DS:[0xE609E8],0x4
//			je ReturnLoad
//			// ---
//		ReturnLoad :
//		// ---
//		jmp PlayerID_OffsetS4
//	}
//}
//
//void SelectServerBarRemakeS4(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)
//{
//	float x,y;
//
//	if(pWinWidth <= 800)
//	{
//		x = -80.0;
//		y = -20.0;
//	}
//	else if(pWinWidth >= 1024 && pWinWidth <= 1279)
//	{
//		x = -37.0;
//		y = 0.0;
//	}
//	else if(pWinWidth == 1280)
//	{
//		x = -7.5;
//		y = 17.0;
//	}
//    else
//	{
//		x = 0.0;
//		y = 0.0;
//	}
//
//	if(*(int*)0x87935A4 == 0)
//	{
//		RenderBitmap(88821, 207 + x, 170.5 + y, 67.0, 95.0, 0, 0, 0.26983125, 1.0, 0.0, 1, 0.0);
//	}
//	else
//	{
//		/*	  Vazio  	*/
//	}
//
//	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
//}
//
//__declspec(naked) void SelectCharacterCordPJ1SS4()
//{
//	static float D41DCC = 22840.0f;
//	static float D41DC8 = 15355.0f;
//	static float D27AE0 = 50.0f;
//	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
//
//	_asm
//	{
//		FLD DWORD PTR DS:[D41DCC]
//		FSTP DWORD PTR SS:[EBP-0x14]
//		FLD DWORD PTR DS:[D41DC8]
//		FSTP DWORD PTR SS:[EBP-0x10]
//		FLD DWORD PTR DS:[D27AE0]
//		FSTP DWORD PTR SS:[EBP-0x18]
//		jmp [SelectCharacterCordPJ1_buff]
//	}
//}
//
//__declspec(naked) void SelectCharacterCordPJ21SS4()
//{
//	static float D41DCC = 22628.0f;
//	static float D41DC8 = 15012.0f;
//	static float D27AE0 = 100.0f;
//	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
//
//	_asm
//	{
//		FLD DWORD PTR DS:[D41DCC]
//		FSTP DWORD PTR SS:[EBP-0xC]
//		FLD DWORD PTR DS:[D41DC8]
//		FSTP DWORD PTR SS:[EBP-0x8]
//		FLD DWORD PTR DS:[D27AE0]
//		FSTP DWORD PTR SS:[EBP-0x14]
//		jmp [SelectCharacterCordPJ1_buff]
//	}
//}
//
//void sub_4D5EC02()
//{
//	sub_4D5EC0R();
//
//	float x,y;
//
//	if(pWinWidth <= 800)
//	{
//		x = -80.0;
//		y = -20.0;
//	}
//	else if(pWinWidth >= 1024 && pWinWidth <= 1279)
//	{
//		x = -37.0;
//		y = 0.0;
//	}
//	else if(pWinWidth == 1280)
//	{
//		x = -7.5;
//		y = 17.0;
//	}
//    else
//	{
//		x = 0.0;
//		y = 0.0;
//	}
//
//	if(*(int*)0x87935A4 == 0)
//	{
//		BeginBitmap();
//		RenderBitmap(88821, 207 + x, 171 + y, 67.0, 65.0, 0, 0, 0.26983125, 0.72983125, 0.0, 1, 0.0);
//		EndOpengl();
//	}
//	else
//	{
//		/*	  Vazio  	*/
//	}
//}
//
//void CSceneS4()
//{
//	if(gProtect.m_MainInfo.SelectCharacterType == 4)
//	{
//		if(gProtect.m_MainInfo.SelectCharacterSystem == 1)
//		{	
//			SetRange((LPVOID)0x0063D1CE, 5, 0x90);
//			SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1SS4, 0xE9);
//			SetRange((LPVOID)0x0063D40F, 5, 0x90);
//			SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21SS4, 0xE9);
//		}
//
//		SetCompleteHook(0xE8, 0x004D712A, &CMoveMainCamera);
//		SetCompleteHook(0xE8, 0x0062DF68, &CLoadBitmapA);
//		SetCompleteHook(0xE8, 0x005EDE8B, &CSEASON3B_GMNewTown_RenderObjectVisual);
//		SetCompleteHook(0xE9, 0x004D87C8, &SwitchCharacterView401);
//		SetCompleteHook(0xE9, 0x004D87FC, &GameProcessView401);
//		SetCompleteHook(0xE9, 0x005DB52B, &PlayerID401);
//
//		SetByte(0x004D6C26+6, 82);
//		SetByte(0x00910076+6, 82);
//
//		SetFloat(0x00D41DCC, 22628);
//		SetFloat(0x00D41DC8, 15012);
//
//		SetFloat(0x00D41DC4, 22700);
//		SetFloat(0x00D41DC0, 15201);
//
//		SetFloat(0x00D41DBC, 22840);
//		SetFloat(0x00D41DB8, 15355);
//
//		SetFloat(0x00D41DB4, 23019);
//		SetFloat(0x00D41DB0, 15443);
//
//		SetFloat(0x00D41DAC, 23211.6);
//		SetFloat(0x00D41DA8, 15467);
//
//		SetFloat(0x00D27B0C, 075);
//		SetFloat(0x00D27B08, 050);
//
//		SetByte(0x00503834, 0xEB);
//		SetByte(0x0057F0FC, 0xE9);
//		SetByte(0x0057F0FD, 0x4A);
//		SetByte(0x0057F0FE, 0x01);
//		SetByte(0x0057F0FF, 0x00);
//		SetByte(0x0057F100, 0x00);
//		SetByte(0x0057F101, 0x90);
//	}
//
//	if(gProtect.m_MainInfo.SelectServerType == 4)
//	{
//		SetCompleteHook(0xE8, 0x005EDE8B, &CSEASON3B_GMNewTown_RenderObjectVisual);
//		SetCompleteHook(0xE8, 0x004D76FB, &CMoveMainCamera);//Select Server
//		SetCompleteHook(0xE8, 0x004D79C3, &CMoveMainCamera);//Select Server
//		SetCompleteHook(0xE8, 0x0062DF68, &CLoadBitmapA);
//		//SetCompleteHook(0xE8, 0x004D7D13, &SelectServerBarRemakeS4); 
//		SetCompleteHook(0xE8, 0x004D7EB1, &sub_4D5EC02);
//		SetCompleteHook(0xE8, 0x004D7AF9, &CMuRenderSands);
//		SetCompleteHook(0xE8, 0x004D7C98, &CMULogo);
//		SetCompleteHook(0xE8, 0x004D7C0D, &CMULogo);
//		SetByte(0x0062EC6D+6, 83);
//		SetByte(0x004D75EA+6, 83);
//		SetByte(0x0091006D+6, 83);
//	}
//
//}