#include "stdafx.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "User.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Protect.h"
#include "Season0.h"
#include "CSCharacterS13.h"
#include "InfoLog.h"
#include "Console.h"
#include "LoginRemake.h"

void LoginScreenS0(int a1, DWORD *a2)
{
	if (World == 94) /*Select Server*/
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 33000.0;
		*(float*)0x87933D0 = -84.0;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -45.0;
		*(float*)0x87933DC = 24475.79687;
		*(float*)0x87933E0 = 7581.581055;
		*(float*)0x87933E4 = 1834.539917;
		*(float*)0xE61E40 = 35.0;
	}
}

void RenderSSCObjectVisualS0(int a1, int a2)
{
	//Select Server
	if (*(int*)0x0E61E18 == 94)
	{
		switch (*(DWORD *)(a1 + 48))
		{
		case 1:
		{
			BeginRender(1.0);
			*(DWORD *)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
			float v552 = 4000;
			float v551 = ((int)(v552 - timeGetTime() * 0.75f) % 4001) * 0.0002500000118743628;
			RenderMesh(a2,
				0,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				v551,
				-1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
		}
		break;

		case 5:
		{
			BeginRender(1.0);
			*(BYTE*)(a2 + 136) = 0;
			*(float *)(a2 + 72) = 0.80000001;
			*(float *)(a2 + 76) = 0.69999999;
			*(float *)(a2 + 80) = 0.30000001;
			RenderMesh(a2,
				0,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			RenderMesh(a2,
				23,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				-1);
			RenderMesh(a2,
				23,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			RenderMesh(a2,
				24,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				-1);
			RenderMesh(a2,
				24,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			RenderMesh(a2,
				25,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				-1);
			RenderMesh(a2,
				25,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			RenderMesh(a2,
				26,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				-1);
			RenderMesh(a2,
				26,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			RenderMesh(a2,
				27,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				-1);
			RenderMesh(a2,
				27,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			RenderMesh(a2,
				28,
				66,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				-1);
			RenderMesh(a2,
				28,
				68,
				*(float *)(a1 + 152),
				*(DWORD *)(a1 + 68),
				*(float *)(a1 + 100),
				*(float *)(a1 + 104),
				*(float *)(a1 + 108),
				32042);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
		}
		break;
		}
	}
	RenderCryingWolf2ndObjectVisual(a1, a2);
}

__declspec(naked) void SelectCharacterSize1S0()
{
	static float D27AF0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D27AF0 = 0.93f;
	}
	else
	{
		D27AF0 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F165;
	_asm
	{
		FLD DWORD PTR DS : [D27AF0]
		FSTP DWORD PTR DS : [ECX + 0x368]
		JMP[Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize2S0()
{
	static float D27AF0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D27AF0 = 0.93f;
	}
	else
	{
		D27AF0 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F154;
	_asm
	{
		FLD DWORD PTR DS : [D27AF0]
		FSTP DWORD PTR DS : [EAX + 0x368]
		JMP[Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize3S0()
{
	static float D27AF0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D27AF0 = 0.86f;
	}
	else
	{
		D27AF0 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F176;
	_asm
	{
		FLD DWORD PTR DS : [D27AF0]
		FSTP DWORD PTR DS : [EDX + 0x368]
		JMP[Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize4S0()
{
	static float D27AF0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D27AF0 = 0.94f;
	}
	else
	{
		D27AF0 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F143;
	_asm
	{
		FLD DWORD PTR DS : [D27AF0]
		FSTP DWORD PTR DS : [EDX + 0x368]
		JMP[Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize5S0()
{
	static float D27AF0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D27AF0 = 0.92f;
	}
	else
	{
		D27AF0 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F187;
	_asm
	{
		FLD DWORD PTR DS : [D27AF0]
		FSTP DWORD PTR DS : [EAX + 0x368]
		JMP[Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize6S0()
{
	static float D27AF0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D27AF0 = 0.89f;
	}
	else
	{
		D27AF0 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F198;
	_asm
	{
		FLD DWORD PTR DS : [D27AF0]
		FSTP DWORD PTR DS : [ECX + 0x368]
		JMP[Bufferx]

	}
}
__declspec(naked) void SelectCharacterSize7S0()
{
	static float D2B994;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		D2B994 = 1.03f;
	}
	else
	{
		D2B994 = 1.4f;
	}

	static DWORD Bufferx = 0x0057F198;
	_asm
	{
		FLD DWORD PTR DS : [D2B994]
		FSTP DWORD PTR DS : [EDX + 0x368]
		JMP[Bufferx]

	}
}

float MaoOKPosX = 0;
int PointX11 = -180;
int PointX12 = 50;
int PointY1 = -180;
int VerificarCriacao = 1;
int NewChar = -300;

void SelectCharInterfaceDowngrade()
{
	float x;
	float X;
	int CharCreate = 0;

	if(SceneFlag == 4)
	{
		if (PointSY1 <= 220)
		{
			PointSY1 += 20;		
		}	
	}

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0) //97d
	{
		if (pWinWidth <= 1024)
		{
			x = pWinWidth / pWinHeightReal / 2 - 128;
			X = pWinWidth / pWinHeightReal;
		}
		if (pWinWidth >= 1360 && pWinWidth <= 1366)
		{
			x = pWinWidth / pWinHeightReal / 2 - 231;
			X = pWinWidth / pWinHeightReal / 2 + 228;
			MaoOKPosX = 13;
		}
		if (pWinWidth == 1280)
		{
			x = pWinWidth / pWinHeightReal / 2 - 108;
			X = pWinWidth / pWinHeightReal + 39;
			MaoOKPosX = -1;
		}

		if ((GetKeyState(VK_RETURN) & 0x100) != 0)
		{
			VerificarCriacao = 1;
			keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		}

		if ((GetKeyState(VK_ESCAPE) & 0x100) != 0)
		{
			VerificarCriacao = 1;
			keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
		}

		if (!*(BYTE *)((int)sub_482B70() + 33948))
		{
			for (int i = 0; i < 5; ++i)
			{
				if (!*(BYTE *)(sub_96A4C0(sub_402BC0(), i) + 780))
				{
					CharCreate = 1;
					break;
				}
			}

			//-- Check Character Image
			if (CharCreate == 1)
			{
				if (PointY1 < 0)
				{
					PlayBuffer(27, 0, 0);
					PointY1 += 20;
				}
			}
			else
			{
				if (PointY1 >= -180)
				{
					PlayBuffer(27, 0, 0);
					PointY1 -= 20;
				}
			}

			RenderBitmap(88014, 221.0, PointY1 + 4, 199.0, 109.0, 0, 0, 0.77734375, 0.8515625, 1, 1, 0);

			//-- Create Character
			if (CharCreate == 1)
			{
				if (pCheckMouseOver((int)288, (int)80, (int)70, (int)25))
				{
					if (*(BYTE*)0x8793386)
					{
						VerificarCriacao = 1;
						PointY1 -= 180;
						PlayBuffer(25, 0, 0);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}

					RenderBitmap(88015, 286.0, PointY1 + 78.6999969, 70.0, 25.0, 0, 0, 0.546875, 0.78125, 1, 1, 0);
				}
			}
		}

		if (SelectedHero == 0 ||
			SelectedHero == 1 ||
			SelectedHero == 2 ||
			SelectedHero == 3 ||
			SelectedHero == 4 ||
			SelectedHero == 5)
		{
			if (PointX11 < -10)
			{
				PlayBuffer(27, 0, 0);
				PointX11 += 20;
			}
			if (PointX12 < 193)
			{
				PlayBuffer(27, 0, 0);
				PointX12 += 20;
			}
		}
		else
		{
			if (PointX11 > -180)
			{
				PlayBuffer(27, 0, 0);
				PointX11 -= 20;
			}
			if (PointX12 > 10)
			{
				PlayBuffer(27, 0, 0);
				PointX12 -= 20;
			}
		}

		//Maos
		RenderBitmap(88000, PointX11, 115, 205.0, 88.0, 0, 0, 0.80078125, 0.6875, 1, 1, 0);
		RenderBitmap(88016, X - PointX12 + 4, 115, 205.0, 88.0, 0, 0, 0.80078125, 0.6875, 1, 1, 0);

		if (VerificarCriacao == 0)
		{
			if (NewChar < 0)
			{
				PlayBuffer(27, 0, 0);
				NewChar += 50;
			}
		}
		else
		{
			if (NewChar > -300)
			{
				PlayBuffer(27, 0, 0);
				NewChar -= 50;
			}
		}

		for (int i = 0; i < 5; ++i)
		{
			if (SelectedHero == i)
			{
				if (pCheckMouseOver((int)130.0, (int)148.0, (int)70.0, (int)19.0))
				{
					SelectedCharacter = i;
					SelectedHero = i;
					if (*(BYTE*)0x8793386)
					{
						PlayBuffer(25, 0, 0);
						DelectPlayerSend();
					}

					RenderBitmap(88001, PointX11 + 128.0, 147.0, 70.0, 19.0, 0.0, 0.0, 0.546875, 0.59375, 1, 1, 0);
				}

				if (pCheckMouseOver((int)443, (int)148.0, (int)70.0, (int)19.0))
				{
					SelectedCharacter = i;
					SelectedHero = i;
					if (*(BYTE*)0x8793386)
					{
						PlayBuffer(25, 0, 0);
						ConnectPlayerSend(0);
					}
					RenderBitmap(88017, PointX12 + 231.0 + MaoOKPosX, 147.0, 70.0, 19.0, 0.0, 0.0, 0.546875, 0.59375, 1, 1, 0);
				}
			}
		}

		BeginBitmap();
		pDrawImage(51523, 0, 0, 1024.0, 512.0, 0, 0, 1.0, 1.0, 1, 1, 0.0); //fundo
		EndOpengl();
	}

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 1)
	{
		if (pWinWidth <= 1024)
		{
			x = pWinWidth / pWinHeightReal / 2 - 128;
			X = pWinWidth / pWinHeightReal;
		}
		if (pWinWidth >= 1360 && pWinWidth <= 1366)
		{
			x = pWinWidth / pWinHeightReal / 2 - 231;
			X = pWinWidth / pWinHeightReal / 2 + 228;
			MaoOKPosX = 13;
		}
		if (pWinWidth == 1280)
		{
			x = pWinWidth / pWinHeightReal / 2 - 108;
			X = pWinWidth / pWinHeightReal + 39;
			MaoOKPosX = -1;
		}
		
		if ((GetKeyState(VK_RETURN) & 0x100) != 0)
		{
			VerificarCriacao = 1;
			keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
		}
		
		if ((GetKeyState(VK_ESCAPE) & 0x100) != 0)
		{
			VerificarCriacao = 1;
			keybd_event(VK_ESCAPE, 0, KEYEVENTF_KEYUP, 0);
		}
		
		if (!*(BYTE *)((int)sub_482B70() + 33948))
		{
			for (int i = 0; i < 5; ++i)
			{
				if (!*(BYTE *)(sub_96A4C0(sub_402BC0(), i) + 780))
				{
					CharCreate = 1;
					break;
				}
			}
		
			//-- Check Character Image
			if (CharCreate == 1)
			{
				if (PointY1 < 40)
				{
					PlayBuffer(27, 0, 0);
					PointY1 += 20;
				}
			}
			else
			{
				if (PointY1 >= -180)
				{
					PlayBuffer(27, 0, 0);
					PointY1 -= 20;		
				}
			}
		
			RenderBitmap(88014, x + 47.0, PointY1, 160.0, 138.0, 0.0, 0.0, 0.6719999909, 0.5799999833, 1, 1, 0);
		
			//-- Create Character
			if (CharCreate == 1)
			{
				if (pCheckMouseOver((int)x + 75.0, (int)138.6999969, (int)104.0, (int)20.5))
				{
					if (*(BYTE*)0x8793386)
					{
						VerificarCriacao = 1;
						PointY1 -= 180;
						PlayBuffer(25, 0, 0);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
		
					RenderBitmap(88015, x + 75.0, PointY1 + 98.6999969, 104.0, 20.5, 0.0, 0.0, 0.8729991317, 0.6959990859, 1, 1, 0);
				}
			}
		}
		
		if (SelectedHero == 0 || 
			SelectedHero == 1 || 
			SelectedHero == 2 || 
			SelectedHero == 3 ||
			SelectedHero == 4 ||
			SelectedHero == 5)
		{
			if (PointX11 < 10)
			{
				PlayBuffer(27, 0, 0);
				PointX11 += 20;
			}
			if (PointX12 < 180)
			{
				PlayBuffer(27, 0, 0);
				PointX12 += 20;
			}
		}
		else
		{
			if (PointX11 > -180)
			{
				PlayBuffer(27, 0, 0);
				PointX11 -= 20;
			}
			if (PointX12 > 10)
			{
				PlayBuffer(27, 0, 0);
				PointX12 -= 20;
			}
		}
		
		//Maos
		RenderBitmap(88000, PointX11, 135, 179.0, 61.0, 0.0, 0.0, 0.6979999542, 0.9459997416, 1, 1, 0);
		RenderBitmap(88016, X - PointX12, 135, 179.0, 61.0, 0.0, 0.0, 0.6979999542, 0.9459997416, 1, 1, 0);
		
		if (VerificarCriacao == 0)
		{
			if (NewChar < 20)
			{
				PlayBuffer(27, 0, 0);
				NewChar += 50;
			}
		}
		else
		{
			if (NewChar > -300)
			{
				PlayBuffer(27, 0, 0);
				NewChar -= 50;
			}
		}
		
		for (int i = 0; i < 5; ++i)
		{
			if (SelectedHero == i)
			{
				if (pCheckMouseOver((int)123.0, (int)149.0, (int)60.0, (int)18.0))
				{
					SelectedCharacter = i;
					SelectedHero = i;
					if (*(BYTE*)0x8793386)
					{
						PlayBuffer(25, 0, 0);
						DelectPlayerSend();
					}
					RenderBitmap(88001, PointX11 + 103.0, 149.0, 60.0, 18.0, 0.0, 0.0, 0.9319999814, 0.5559997559, 1, 1, 0);
				}
		
				if (pCheckMouseOver((int)X - 174.0, (int)149.0, (int)60.0, (int)18.0))
				{
					SelectedCharacter = i;
					SelectedHero = i;
					if (*(BYTE*)0x8793386)
					{
						PlayBuffer(25, 0, 0);
						ConnectPlayerSend(0);
					}
					RenderBitmap(88017, PointX12 + 276.0 + MaoOKPosX, 149.0, 60.0, 18.0, 0.0, 0.0, 0.9319999814, 0.5559997559, 1, 1, 0);
				}
			}
		}
		
		//-- barra cima
		RenderBitmap(88005, x, -1, 256.0, 71.0, 0.0, 0.0, 1.0, 0.5489999652, 1, 1, 0); //centro
		RenderBitmap(88002, x + 254.0, 0, 192, 37, 0.0, 0.0, 0.5, 0.5809999108, 1, 1, 0); //lado ultimo
		RenderBitmap(88002, x - 190, 0, 192, 37, 0.5, 0.0, -0.5, 0.5809999108, 1, 1, 0); //lado inicial
		//-- guarda direito
		RenderBitmap(88003, X - 105.0, 3.0, 106.0, 256.0, 0.0, 0.0, 0.8300000429, 1.0, 1, 1, 0); //cima
		RenderBitmap(88004, X - 105.0, 258.0, 106.0, 256.0, 0.0, 0.0, 0.8300000429, 1.0, 1, 1, 0); //baixo
		//-- guarda esquerdo
		RenderBitmap(88003, -1.0, 3.0, 106.0, 256.0, 0.8300000429, 0.0, -0.8300000429, 1.0, 1, 1, 0); //cima
		RenderBitmap(88004, -1.0, 258.0, 106.0, 256.0, 0.8300000429, 0.0, -0.8300000429, 1.0, 1, 1, 0); //baixo
	}
}

signed int sub_9CEBF0(double a1)
{
	return (signed int)a1;
}

int DEvent;
int SlectPJ;

//----- (00403FA0) --------------------------------------------------------
void DisplayCreateCharacter(BYTE JCByte)
{
	float x;
	float y = 51;
	float w = 150;
	float h = 35;
	float currentx;
	int v9; // [sp+0h] [bp-4h]@1
	int GetCharactername[8] = { 20, 21, 22, 23, 24, 1687, 3150, 3175 };
	signed int v5; // eax@8
	int v6; // ST08_4@8
	signed int v7; // eax@8
	int v8; // eax@8
	int v11; // ST04_4@11
	int v17; // ST00_4@11
	int v25; // [sp+101Ch] [bp-1Ch]@32
	int v26; // [sp+1020h] [bp-18h]@26
	char v24; // [sp+814h] [bp-824h]@33
	int v29; // [sp+1034h] [bp-4h]@33
	int v48; // [sp+2Ch] [bp-7Ch]@7
	int Personage;

	VerificarCriacao = 0;

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		glDisable(GL_TEXTURE_2D);
		glColor4f(0.0, 0.0, 0.0, 1.0);
		pDrawBarForm((640 / 2) - 60, NewChar + 110, 120, 109, 0.0, 0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);

		v9 = (int)sub_482B70() + 33936;
		sub_404570(v9);

		EnableAlphaTest(1);
		glColor3f(1.0, 1.0, 1.0);

		if (pWinWidth <= 1024)
		{
			x = pWinWidth / pWinHeightReal / 2 - 128;
		}
		if (pWinWidth >= 1360 && pWinWidth <= 1366)
		{
			x = pWinWidth / pWinHeightReal / 2 - 233;
		}
		if (pWinWidth == 1280)
		{
			x = pWinWidth / pWinHeightReal / 2 - 108;
		}

		//-- Tela de criação
		RenderBitmap(88009, 214.0, NewChar + 10, 213.0, 375, 0, 0, 0.83203125, 0.73203125, 1, 1, 0);
		//-- Nome da classe
		pSetFont(pTextThis(), (int)pFontNormal2);
		pSetTextColor(pTextThis(), 168, 136, 49, 0xFFu);
		pDrawText(pTextThis(), (int)(x + 92.0), (int)(NewChar + 212), pGetTextLine(pTextLineThis, GetCharactername[*(BYTE*)0x7BD0483]), 70, 0, (PINT)3, 0);
		pSetFont(pTextThis(), *(DWORD*)0xE8C588);

		SlectPJ = *(BYTE*)0x7BD0483;

#if(BRUNO_97D == 0)
		Personage = 3;
#else
		Personage = 6;
#endif

		if (pCheckMouseOver((int)386, (int)208, (int)20.0, (int)22.0) && *(BYTE*)0x8793386 && GetTickCount() > DEvent + 600 && SlectPJ < Personage)
		{
			SlectPJ++;
			*(DWORD *)(v9 + 2640) = SlectPJ;
			JCButtonShow(v9);
			*(BYTE*)0x7BD0483 = SlectPJ;
			DEvent = GetTickCount();
			PlayBuffer(25, 0, 0);
			RenderBitmap(88010, 386.0, NewChar + 208.0, 19.0, 20.0, 0, 0, 0.59375, 0.625, 1, 1, 0);
		}

		if (SlectPJ == Personage)
		{
			glDisable(GL_TEXTURE_2D);
			glColor4f(0.0, 0.0, 0.0, 0.7);
			pDrawBarForm(385.0, NewChar + 207.0, 19, 19, 0.0, 0);
			glColor4f(1.0, 1.0, 1.0, 1.0);
			glEnable(GL_TEXTURE_2D);
		}

		if (pCheckMouseOver((int)366, (int)208, (int)20.0, (int)22.0) && *(BYTE*)0x8793386 && GetTickCount() > DEvent + 600 && SlectPJ > CLASS_WIZARD)
		{
			SlectPJ--;
			*(DWORD *)(v9 + 2640) = SlectPJ;
			JCButtonShow(v9);
			*(BYTE*)0x7BD0483 = SlectPJ;
			DEvent = GetTickCount();
			PlayBuffer(25, 0, 0);
			RenderBitmap(88008, 366.0, NewChar + 208.0, 19.0, 20.0, 0, 0, 0.59375, 0.625, 1, 1, 0);
		}

		if (SlectPJ == CLASS_WIZARD)
		{
			glDisable(GL_TEXTURE_2D);
			glColor4f(0.0, 0.0, 0.0, 0.7);
			pDrawBarForm(365.0, NewChar + 207.0, 19, 19, 0.0, 0);
			glColor4f(1.0, 1.0, 1.0, 1.0);
			glEnable(GL_TEXTURE_2D);
		}

		//-- Botão Cancel
		if (pCheckMouseOver((int)237, (int)361, 72, 21))
		{
			if (*(BYTE*)0x8793386 && GetTickCount() > DEvent + 300)
			{
				VerificarCriacao = 1;
				JGCloseChar((int)sub_482B70(), v9);
				PlayBuffer(25, 0, 0);
			}
			RenderBitmap(88006, 235.0, NewChar + 359, 72.0, 21.0, 0, 0, 0.5625, 0.65625, 1, 1, 0);
		}

		//-- Botão OK - Criar char
		if (pCheckMouseOver((int)338, (int)363, 72, 21))
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				VerificarCriacao = 1;
				keybd_event(VK_RETURN, 1, 0, 0);
				PlayBuffer(25, 0, 0);
			}
			else
			{
				keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
			}
			RenderBitmap(88007, 335.0, NewChar + 359, 72.0, 21.0, 0, 0, 0.5625, 0.65625, 1, 1, 0);
		}

		//-- Campo de Nome do Personagem
		if (*(DWORD*)0xE60960 == 1)
		{
			(*(void(__thiscall **)(int))(*(DWORD *)*(DWORD *)0xE8C544 + 20))(*(DWORD *)0xE8C544);
			SetBoundInputField(*(DWORD*)0xE8C544, x + 108.0, y + NewChar + 140.0);
		}
		else if (!*(DWORD *)0xE60960)
		{
			v8 = SpiriteGetInfoY(v9 + 120) + 21;
			v11 = sub_9CEBF0((double)v8 / *(float*)0xE7C3D8);
			v48 = SpiriteGetInfoX(v9 + 120);
			v17 = sub_9CEBF0((double)(v48 + 78) / *(float*)0xE7C3D4);
			sub_596EF0(v17, v11, 0);
		}
	}
	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 1)
	{
		glDisable(GL_TEXTURE_2D);
		glColor4f(0.0, 0.0, 0.0, 1.0);
		pDrawBarForm((640 / 2) - 60, NewChar + 110, 120, 109, 0.0, 0);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);

		v9 = (int)sub_482B70() + 33936;
		sub_404570(v9);

		
		EnableAlphaTest(1);
		glColor3f(1.0, 1.0, 1.0);
		
		if (pWinWidth <= 1024)
		{
			x = pWinWidth / pWinHeightReal / 2 - 128;
		}
		if (pWinWidth >= 1360 && pWinWidth <= 1366)
		{
			x = pWinWidth / pWinHeightReal / 2 - 233;
		}
		if (pWinWidth == 1280)
		{
			x = pWinWidth / pWinHeightReal / 2 - 108;
		}
		
		//-- Tela de criação
		RenderBitmap(88009, x + 8, NewChar, 240.0, 256.0, 0.0, 0.0, 0.9399999976, 1.0, 1, 1, 0);
		RenderBitmap(88011, x + 8, 255 + NewChar, 240.0, 35.0, 0.0, 0.0, 0.9399999976, 0.54, 1, 1, 0);
		//-- Nome da classe
		pSetFont(pTextThis(), (int)pFontNormal2);
		pSetTextColor(pTextThis(), 168, 136, 49, 0xFFu);
		pDrawText(pTextThis(), (int)(x + 92.0), (int)(NewChar + 234.0), pGetTextLine(pTextLineThis, GetCharactername[*(BYTE*)0x7BD0483]), 70, 0, (LPINT)3, 0);
		pSetFont(pTextThis(), *(DWORD*)0xE8C588);
		
		SlectPJ = *(BYTE*)0x7BD0483;
		
		if (pCheckMouseOver((int)360, (int)278, (int)20.0, (int)22.0) && *(BYTE*)0x8793386 && GetTickCount() > DEvent + 600 && SlectPJ < CLASS_MONK)
		{
			SlectPJ++;
			*(DWORD *)(v9 + 2640) = SlectPJ;
			JCButtonShow(v9);
			*(BYTE*)0x7BD0483 = SlectPJ;
			DEvent = GetTickCount();
			PlayBuffer(25, 0, 0);
			RenderBitmap(88010, 359.0, NewChar + 225.5, 19.0, 20.0, 0, 0, 0.59375, 0.625, 1, 1, 0);
		}
		
		if (SlectPJ == CLASS_MONK)
		{
			glDisable(GL_TEXTURE_2D);
			glColor4f(0.0, 0.0, 0.0, 0.7);
			pDrawBarForm(358.0, NewChar + 226, 20, 22, 0.0, 0);
			glColor4f(1.0, 1.0, 1.0, 1.0);
			glEnable(GL_TEXTURE_2D);
		}
		
		if (pCheckMouseOver((int)263, (int)278, (int)20.0, (int)22.0) && *(BYTE*)0x8793386 && GetTickCount() > DEvent + 600 && SlectPJ > CLASS_WIZARD)
		{
			SlectPJ--;
			*(DWORD *)(v9 + 2640) = SlectPJ;
			JCButtonShow(v9);
			*(BYTE*)0x7BD0483 = SlectPJ;
			DEvent = GetTickCount();
			PlayBuffer(25, 0, 0);
			RenderBitmap(88008, 262.0, NewChar + 225.5, 19.0, 20.0, 0, 0, 0.59375, 0.625, 1, 1, 0);
		}
		
		if (SlectPJ == CLASS_WIZARD)
		{
			glDisable(GL_TEXTURE_2D);
			glColor4f(0.0, 0.0, 0.0, 0.7);
			pDrawBarForm(261.0, NewChar + 226, 20, 22, 0.0, 0);
			glColor4f(1.0, 1.0, 1.0, 1.0);
			glEnable(GL_TEXTURE_2D);
		}
		
		//-- Botão Cancel
		if (pCheckMouseOver((int)260, (int)304, 57, 22))
		{
			if (*(BYTE*)0x8793386 && GetTickCount() > DEvent + 300)
			{
				VerificarCriacao = 1;
				JGCloseChar((int)sub_482B70(), v9);
				PlayBuffer(25, 0, 0);
			}
			RenderBitmap(88006, 259.5, NewChar+252.5, 57.0, 22.0, 0, 0, 0.89625, 0.69875, 1, 1, 0);
		}
		
		//-- Botão OK - Criar char
		if (pCheckMouseOver((int)324, (int)304, 57, 22))
		{
			if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
			{
				VerificarCriacao = 1;
				keybd_event(VK_RETURN, 1, 0, 0);
				PlayBuffer(25, 0, 0);
			}
			else
			{
				keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
			}
			RenderBitmap(88007, 323, NewChar + 252.5, 57.0, 22.0, 0, 0, 0.89625, 0.69875, 1, 1, 0);
		}
		
		//-- Campo de Nome do Personagem
		if (*(DWORD*)0xE60960 == 1)
		{
			(*(void(__thiscall **)(int))(*(DWORD *)*(DWORD *)0xE8C544 + 20))(*(DWORD *)0xE8C544);
			SetBoundInputField(*(DWORD*)0xE8C544, x + 108.0, y + NewChar + 152.0);
		}
		else if (!*(DWORD *)0xE60960)
		{
			v8 = SpiriteGetInfoY(v9 + 120) + 21;
			v11 = sub_9CEBF0((double)v8 / *(float*)0xE7C3D8);
			v48 = SpiriteGetInfoX(v9 + 120);
			v17 = sub_9CEBF0((double)(v48 + 78) / *(float*)0xE7C3D4);
			sub_596EF0(v17, v11, 0);
		}
	}
}

__declspec(naked) void SelectCharacterS0CordPJ1()
{
	static float D41DCC = 8008.0f; //8008.000
	static float D41DC8 = 19010.0f; //18885.00
	static float D27AE0 = 35.0f; //115.0000
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

__declspec(naked) void SelectCharacterS0CordPJ21()
{
	static float D41DCC = 8008.0f; //8008.000
	static float D41DC8 = 19010.0f; //18885.00
	static float D27AE0 = 35.0f; //115.0000
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

__declspec(naked) void SelectCharacterS0CordPJ2()
{
	static float D41DC4 = 7986.0f; //7986.000
	static float D41DC0 = 19160.0f; //19145.00
	static float D254C0 = 50.0f; //90.00000
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

__declspec(naked) void SelectCharacterS0CordPJ22()
{
	static float D41DC4 = 7986.0f; //7986.000
	static float D41DC0 = 19160.0f; //19145.00
	static float D254C0 = 50.0f; //90.00000
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

__declspec(naked) void SelectCharacterS0CordPJ3()
{
	static float D41DBC = 8046.0f; //8046.000
	static float D41DB8 = 19360.0f; //19400.00
	static float D2B954 = 75.0f; //75.00000
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

__declspec(naked) void SelectCharacterS0CordPJ23()
{
	static float D41DBC = 8046.0f; //8046.000
	static float D41DB8 = 19360.0f; //19400.00
	static float D2B954 = 75.0f; //75.00000
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

__declspec(naked) void SelectCharacterS0CordPJ4()
{
	static float D41DB4 = 8133.0f; //8133.000
	static float D41DB0 = 19560.0f; //19645.00
	static float D2577C = 100.0f; //60.00000
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

__declspec(naked) void SelectCharacterS0CordPJ24()
{
	static float D41DB4 = 8133.0f; //8133.000
	static float D41DB0 = 19560.0f; //19645.00
	static float D2577C = 100.0f; //60.00000
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

__declspec(naked) void SelectCharacterS0CordPJ5()
{
	static float D41DAC = 8153.0f; //8282.000
	static float D41DA8 = 19760.0f; //19845.00
	static float D27BFC = 110.0f; //35.00000
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

__declspec(naked) void SelectCharacterS0CordPJ25()
{
	static float D41DAC = 8153.0f; //8282.000
	static float D41DA8 = 19760.0f; //19845.00
	static float D27BFC = 110.0f; //35.00000
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

void LoginScreen97D(int a1, DWORD *a2)
{
	if (SceneFlag == 4) /*Select Character*/
	{
		//SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		//SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 3500.0;
		*(float*)0x87933D0 = -82.0; //meu Y
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -90.0;
		*(float*)0x87933DC = 9758.9297;
		*(float*)0x87933E0 = 18913.109;
		*(float*)0x87933E4 = 500.0;
		*(float*)0xE61E40 = 35.0;

		*(float *)(((GetCharacter(GetPreview(), 0)) + 776) + 252) = 8570;
		*(float *)(((GetCharacter(GetPreview(), 0)) + 776) + 256) = 18685;
		*(float *)(((GetCharacter(GetPreview(), 0)) + 776) + 272) = 60;

		*(float *)(((GetCharacter(GetPreview(), 1)) + 776) + 252) = 8590;
		*(float *)(((GetCharacter(GetPreview(), 1)) + 776) + 256) = 18785;
		*(float *)(((GetCharacter(GetPreview(), 1)) + 776) + 272) = 75;

		*(float *)(((GetCharacter(GetPreview(), 2)) + 776) + 252) = 8610;
		*(float *)(((GetCharacter(GetPreview(), 2)) + 776) + 256) = 18915;
		*(float *)(((GetCharacter(GetPreview(), 2)) + 776) + 272) = 90;

		*(float *)(((GetCharacter(GetPreview(), 3)) + 776) + 252) = 8580;
		*(float *)(((GetCharacter(GetPreview(), 3)) + 776) + 256) = 19020;
		*(float *)(((GetCharacter(GetPreview(), 3)) + 776) + 272) = 105;

		*(float *)(((GetCharacter(GetPreview(), 4)) + 776) + 252) = 8560;
		*(float *)(((GetCharacter(GetPreview(), 4)) + 776) + 256) = 19140;
		*(float *)(((GetCharacter(GetPreview(), 4)) + 776) + 272) = 120;
	}
}

void ClassFaceDimension(GLint x, int y, GLsizei width, GLsizei height)
{
	int PosX = 0;
	int PosY = 0;
	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		if (pWinWidth == 1280)
		{
			PosY += 20;
			PosX += -8;
		}
		else if (pWinWidth == 1024)
		{
			PosX += -38;
		}
		else if (pWinWidth < 1024)
		{
			PosY += -36;
			PosX += -76;
		}

		BeginOpengl(x + 72 - PosX, y + NewChar - 8 - PosY, 75, 75);
	}

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 1)
	{
		if (pWinWidth == 1280)
		{
			PosY += 20;
			PosX += -5;
		}
		else if (pWinWidth == 1024)
		{
			PosX += -33;
			PosY += -15;
		}
		else if (pWinWidth >= 1360 && pWinWidth <= 1366)
		{
			//PosX += -33;
			PosY += -15;
		}
		else if (pWinWidth < 1024)
		{
			PosY += -52;
			PosX += -72;
		}

		BeginOpengl(x + 72 - PosX, y + NewChar - 8 - PosY, 75, 75);
	}
}

int __fastcall DisplayInfoBarCharacterPosition(int a1, int a2, signed int a3, signed int a4, char a5)
{
	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
	{
		int PosY = 0;
		if (pWinWidth == 1280)
		{
			PosY += 23;
		}
		else if (pWinWidth < 1024)
		{
			PosY += -26;
		}
		return DisplayInfoBarCharacter(a1, a2, a3, a4 + 150 + PosY, a5);
	}

	if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 1)
	{
		return DisplayInfoBarCharacter(a1, a2, a3, a4, a5);
	}
}

void EffectSystem(int a1, int a2, int a3, int color, int a5, float a6, int a7)
{
	EnableAlphaBlend();
	float v66 = (double)(WorldTime % 3600);
	RenderCircle(32142, a2, 50.0, 70.0, 200.0, v66, 0.0, 0.0);
}


void CMULogoDown(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)
{
	if(a1 == 31019)
	RenderBitmap(531019, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
	if(a1 == 31018)
	RenderBitmap(531018, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

#define sub_4D5EC0R			((int(*)()) 0x4D5EC0)

void MULOGOS22()
{
  if ( pPlayerState == 2 )
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		*(float*)0xE8CB18 = *(float*)0xE8CB18 + 0.01999999955296516;
		if ( *(float*)0xE8CB18 > 10.0 )
		*(float*)0xE8CB18 = 10.0;
		pGLSwitchBlend();
		float v25 = *(float*)0xE8CB18 - 0.300000011920929;
		float v24 = *(float*)0xE8CB18 - 0.300000011920929;
		float v23 = *(float*)0xE8CB18 - 0.300000011920929;
		float v22 = *(float*)0xE8CB18 - 0.300000011920929;
		glColor4f(v22, v23, v24, v25);
		pDrawImage(531019, 217.60001, 38.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		pSetBlend(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		pDrawImage(531018, 217.60001, 38.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		//
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);
		//gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 460, 150, 3, "RoxGaming © 2021");
	//	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 470, 763, 3, "RazeMU");
	//	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 378, 470, 150, 3, gCustomMessage.GetMessageB(456));
	//	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 470, 150, 3, gCustomMessage.GetMessageB(454));
	}
}

void sub_4D5EC022()
{
	MULOGOS22();
	sub_4D5EC0R();
}

void MoveCharacterListName(int iPos_x, int iPos_y, LPCSTR pszText, int iBoxWidth, int iBoxHeight, int iSort, OUT SIZE* lpTextSize)
{	
	pSetFont(pTextThis(), (int)pFontBold);
	pRender_rendertext(g_Fontthis(), iPos_x, iPos_y + 12, pszText, iBoxWidth, iBoxHeight, iSort, lpTextSize);
}

void ColorCharacterListLevel(LPVOID a1, int color)
{
	pSetFont(pTextThis(), (int)pFontNormal2);
	SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
}

void CSceneS0()
{
	if (gProtect.m_MainInfo.SelectServerType == 1)
	{
		SetCompleteHook(0xE8, 0x005EDDA9, &RenderSSCObjectVisualS0);
		/*Select Server*/
		SetDword((LPVOID)0x004D75F0, 94);//Select Server
		SetCompleteHook(0xE8, 0x004D76FB, &LoginScreenS0);//Select Server
		SetCompleteHook(0xE8, 0x004D79C3, &LoginScreenS0);//Select Server
		SetDword((PVOID)(0x004D7A0E), 480);//Select Server
		SetByte((PVOID)(0x004D7A18), 0);//Select Server
		//SetCompleteHook(0xE8, 0x004D7EB1, &sub_4D5EC022);
		//SetCompleteHook(0xE9, 0x0040B1C0, &CLoginWinCreate);				//Tela de criação de personagem
		//SetCompleteHook(0xE8, 0x004D7C98, &CMULogoDown);
		//SetCompleteHook(0xE8, 0x004D7C0D, &CMULogoDown);
	}

	if (gProtect.m_MainInfo.SelectCharacterType == 1)
	{
		SetCompleteHook(0xE8,0x00401F67,&ColorCharacterListLevel);				//Modificação da cor do nome do personagem
		SetCompleteHook(0xE8,0x00401EF1,&MoveCharacterListName);				//Deslocamento em Y do nome do Personagem
		SetCompleteHook(0xE8, 0x004D7534, &EffectSystem);						//Efeito ao selecionar o Personagem
		SetCompleteHook(0xE8, 0x004D7568, &EffectSystem);						//Efeito ao selecionar o Personagem
		SetCompleteHook(0xE8,0x401DA0+0xA9,&DisplayInfoBarCharacterPosition);	//Posicionamento das informações dos personagens
		SetCompleteHook(0xE8, 0x0040464E, &ClassFaceDimension);					//Posicionamento dos avatares das classes
		SetCompleteHook(0xE9, 0x00403126, 0x00403243);							//Destaca o ESC sobre o Menu Create Char
		SetCompleteHook(0xE9, 0x00403FA0, &DisplayCreateCharacter);				//Tela de criação de personagem

		MemorySet(0x00401F56,0x90,0x5);											//Remoção dos status do personagem
		
		if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
		{
		//	SetDword((LPVOID)0x004D6C2C, 75);									//World Number Scene 97d
			SetCompleteHook(0xE8, 0x004D712A, &LoginScreen97D);					//Coordenadas para o Mapa e Personagens
		}

		if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 1)
		{
			SetDword((LPVOID)0x004D6C2C, 76);									//World Number Scene 99b
			SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterS0CordPJ1, ASM::JMP);
			SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterS0CordPJ21, ASM::JMP);

			SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterS0CordPJ2, ASM::JMP);
			SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterS0CordPJ22, ASM::JMP);

			SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterS0CordPJ3, ASM::JMP);
			SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterS0CordPJ23, ASM::JMP);

			SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterS0CordPJ4, ASM::JMP);
			SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterS0CordPJ24, ASM::JMP);

			SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterS0CordPJ5, ASM::JMP);
			SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterS0CordPJ25, ASM::JMP);
		}

		MemorySet(0x00405380, 0x90, 0x20D);										//Remoção dos botões
		MemorySet(0x004D74CE, 0x90, 0x5);										//Remoção dos Efeitos em Bolas
		MemorySet(0x004D7568, 0x90, 0x5);										//Remoção dos Efeitos em Bolas
		MemorySet(0x004D7465, 0x90, 0x5);										//Remoção dos Efeitos no Chão

		SetByte((PVOID)(0x004D7183), 0);										//Resolução da Tela de Personagem
		SetDword((PVOID)(0x00401D2F + 1), 51522);								//Removido CharacterEx.tga
		SetDword((PVOID)(0x004D7179), 480);										//Resolução da Tela de Personagem

		SetOp((LPVOID)0x0057F159, (LPVOID)SelectCharacterSize1S0, ASM::JMP);	//Tamanho do Personagem PJ1
		SetOp((LPVOID)0x0057F148, (LPVOID)SelectCharacterSize2S0, ASM::JMP);	//Tamanho do Personagem PJ2
		SetOp((LPVOID)0x0057F16A, (LPVOID)SelectCharacterSize3S0, ASM::JMP);	//Tamanho do Personagem PJ3
		SetOp((LPVOID)0x0057F137, (LPVOID)SelectCharacterSize4S0, ASM::JMP);	//Tamanho do Personagem PJ4
		SetOp((LPVOID)0x0057F17B, (LPVOID)SelectCharacterSize5S0, ASM::JMP);	//Tamanho do Personagem PJ5
		SetOp((LPVOID)0x0057F18C, (LPVOID)SelectCharacterSize6S0, ASM::JMP);	//Tamanho do Personagem PJ6
		SetOp((LPVOID)0x0057F19D, (LPVOID)SelectCharacterSize7S0, ASM::JMP);	//Tamanho do Personagem PJ7	
	}

}