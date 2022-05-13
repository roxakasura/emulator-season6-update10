#include "stdafx.h"
#include "Import.h"
#include "Util.h"
#include "TMemory.h"
#include "Defines.h"
#include "Central.h"
#include "Interface.h"
#include "Protect.h"
#include "PrintPlayer.h"
#include "MiniMap.h"
#include "Common.h"
#include "NewFont.h"
#include "WindowsStruct.h"
#include "CSCharacterS13.h"
#include "ExpandedCharacters.h"
#include "Season0.h"
#include "Console.h"
#include "Performance.h"

Centralizado gCentral;

Centralizado::Centralizado()
{
}

Centralizado::~Centralizado()
{
}

int Centralizado::MoveRenderCameraDefault()
{
	pSetCursorFocus = false;
	int Width = TransForX( 190 );
	int a3 = 640;
	int t;

	if( gProtect.m_MainInfo.CustomInterfaceType >= 0 )
	{
		if(gInterface.Data[eJEWELBANK_MAIN].OnShow)
		{
			pSetCursorFocus = true;
		}

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
	
		if ( gInterface.CheckWindow(Shop) )
		{
				t = Return2X( Width);

			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			if( pCursorX <= t ||  pCursorX >= a3 )
			{
				pSetCursorFocus = true;
			}
		}
		else if ( gInterface.CheckWindow(Warehouse) )
		{
				t = Return2X( Width);

			if( gInterface.CheckWindow(ExpandWarehouse) )
			{
				t = Return2X(Width * 2);
			}
			if( gInterface.CheckWindow(ExpandInventory) )
			{
				a3 = Return2X(TransFor2X(640) - (Width * 2));
			}
			else
			{
				a3 = Return2X(TransFor2X(640) - Width);
			}
			if( pCursorX <= t ||  pCursorX >= a3 )
			{
				pSetCursorFocus = true;
			}
		}
		else if(pCursorX >= a3)
		{
			pSetCursorFocus = true;
		}

		if ( gInterface.CheckWindow(33) )
		{
			if( pCheckMouseOver(0, *(signed int *)(*(DWORD *)(GetInstance() + 12) + 24) + 10,(int) Return2X(TransForX( 15.625 )),(int) ReturnY(TransForY( 15.625 ))))
			{
				pSetCursorFocus = true;
			}
		}

		if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
		{
			if (!pCheckMouseOver(gRenderMap.ultimoX, gRenderMap.ultimoY, 128, 128))
			{
				pSetCursorFocus = true;
			}
			else
			{
				pSetCursorFocus = true;
			}
		}

		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 )
		{
			if( pCheckMouseOver(2, 31, Return2X(TransForX(74)), 20) )
			{
				pSetCursorFocus = true;
			}
		}
	}
	else
	{
	 if ( gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Character) //-- 13 & 16
		|| gInterface.CheckWindow(Warehouse) //-- 8
		|| gInterface.CheckWindow(Shop) //-- 12
		|| gInterface.CheckWindow(ChaosBox) //-- 9
		|| gInterface.CheckWindow(Trade) //-- 7
		|| gInterface.CheckWindow(Store) //-- 14
		|| gInterface.CheckWindow(OtherStore) //-- 15
		|| gInterface.CheckWindow(LuckyCoin1) //-- 60
		|| gInterface.CheckWindow(NPC_ChaosMix) ) //-- 76
		{
			gInterface.Data[eVip_MAIN].OnShow = false;
			gInterface.Data[eCommand_MAIN].OnShow = false;

			if(pCursorX >= 260)
			{
				pSetCursorFocus = true;
			}
		}
		else
		{
			if ( gInterface.CheckWindow(16) && (gInterface.CheckWindow(4)||gInterface.CheckWindow(69)) )
			{
				if(pCursorX >= 260)
				{
					pSetCursorFocus = true;
				}
			}
			else
			{
				if ( gInterface.CheckWindow(16) && gInterface.CheckWindow(11) )
				{	
					if(pCursorX >= 260)
					{
						pSetCursorFocus = true;
					}
				}
				else
				{
					if ( gInterface.CheckWindow(27) )
					{						
						if(pCursorX >= 260)
						{
							pSetCursorFocus = true;
						}
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
							if(pCursorX >= 450)
							{
									pSetCursorFocus = true;
							
							}
						}
						else
						{
							if ( gInterface.CheckWindow(79) )
							{
								if ( gInterface.CheckWindow(80) )
								{
									if(pCursorX >= 260)
									{
										pSetCursorFocus = true;
									}
								}
								else
								{
									if(pCursorX >= 450)
									{
										pSetCursorFocus = true;
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
					gInterface.CheckWindow(Character) ||
					gInterface.CheckWindow(Shop))
				{
					if(pCursorX >= 70)
					{
						pSetCursorFocus = true;
					}
				}
				else
				{
					if(pCursorX >= 260)
					{
						pSetCursorFocus = true;
					}
				}
			}
			else if ( gInterface.CheckWindow(78) )
			{
				pSetCursorFocus = true;
			}
		}

		if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
		{
			if (!pCheckMouseOver(gRenderMap.ultimoX, gRenderMap.ultimoY, 128, 128))
			{
				pSetCursorFocus = true;
			}
			else
			{
				pSetCursorFocus = true;
			}
		}

		if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) != 0 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 556) != 65535 )
		{
			if( pCheckMouseOver(2, 31, Return2X(TransForX(74)), 20) )
			{
				pSetCursorFocus = true;
			}
		}

	}
	return 640;
}

__declspec(naked) void RenderEsc_Button01()
{
	static DWORD Addr_JMP = 0x007A8678;

	_asm
	{
		PUSH 81524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0x4C                            ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button02()
{
	static DWORD Addr_JMP = 0x007A86D2;

	_asm
	{
		PUSH 81524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0xA0                            ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button03()
{
	static DWORD Addr_JMP = 0x007A872F;

	_asm
	{
		PUSH 81524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0xF4                            ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button04()
{
	static DWORD Addr_JMP = 0x007A878C;

	_asm
	{
		PUSH 81524                               ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]          ; |
		ADD ECX, 0x148                           ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderEsc_Button05()
{
	static DWORD Addr_JMP = 0x007A87E9;

	_asm
	{
		PUSH 81524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x19C                              ; |
		JMP[Addr_JMP]
	}
}

void Centralizado::PrintDropBoxTest(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	EnableAlphaTest(1);

	glColor4f(1.0, 1.0, 0.0, 0.3);
	pDrawBarForm(PosX, PosY, Width, Height, Arg5, Arg6); //central

	float RightX = PosX - 8.0f;
	float LeftX = (PosX + Width) - 8.0f;
	float TopY = PosY - 8.0f;
	float DownY = (PosY + Height) - 8.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 8.0f;
	float w = 16.0f;
	//--
	float IniciarY = PosY - 8.0f;
	float H = 16.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while(vertical || horizontal)
	{
		if(vertical)
		{
			IniciarX += 16.0f;

			if((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(71512, IniciarX, TopY, w, 16.0f); //arriba

			pDrawGUI(71517, IniciarX, DownY, w, 16.0f); //abajo
		}
		//-- abajo
		if(horizontal)
		{
			IniciarY += 16.0f;

			if((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(71514, RightX, IniciarY, 16.0f, H); // Lado Izquierdo

			pDrawGUI(71515, LeftX, IniciarY, 16.0f, H); //Lado Derecho
		}
	}

	pDrawGUI(71511, RightX, TopY, 16.0f, 16.0f); //esquina arriba izquierda

	pDrawGUI(71513, LeftX, TopY, 16.0f, 16.0f); //esquina arriba derecha

	pDrawGUI(71516, RightX, DownY, 16.0f, 16.0f);  //esquina abajo izquierda

	pDrawGUI(71518, LeftX, DownY, 16.0f, 16.0f);  //esquina abajo derecha

	pGLSwitch();
	EnableAlphaTest(0);
}

void Centralizado::PrintDropBox(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	EnableAlphaTest(1);
	
	pSetCursorFocus = true;
	glColor4f(0.0, 0.0, 0.0, 0.80000001);
	pDrawBarForm(PosX, PosY, Width, Height, Arg5, Arg6); //central

	float RightX = PosX - 8.0f;
	float LeftX = (PosX + Width) - 8.0f;
	float TopY = PosY - 8.0f;
	float DownY = (PosY + Height) - 8.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 8.0f;
	float w = 16.0f;
	//--
	float IniciarY = PosY - 8.0f;
	float H = 16.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while(vertical || horizontal)
	{
		if(vertical)
		{
			IniciarX += 16.0f;

			if((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(71512, IniciarX, TopY, w, 16.0f); //arriba

			pDrawGUI(71517, IniciarX, DownY, w, 16.0f); //abajo
		}
		//-- abajo
		if(horizontal)
		{
			IniciarY += 16.0f;

			if((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(71514, RightX, IniciarY, 16.0f, H); // Lado Izquierdo

			pDrawGUI(71515, LeftX, IniciarY, 16.0f, H); //Lado Derecho
		}
	}

	pDrawGUI(71511, RightX, TopY, 16.0f, 16.0f); //esquina arriba izquierda

	pDrawGUI(71513, LeftX, TopY, 16.0f, 16.0f); //esquina arriba derecha

	pDrawGUI(71516, RightX, DownY, 16.0f, 16.0f);  //esquina abajo izquierda

	pDrawGUI(71518, LeftX, DownY, 16.0f, 16.0f);  //esquina abajo derecha

	pGLSwitch();
	EnableAlphaTest(0);
}

void RenderPane_Esc(DWORD id, float x, float y, float w, float h)
{
	//char buffer[255]; // [sp+74h] [bp-4h]@1

	h = 250.0;
	w = 230.0;
	x = (MAX_WIN_WIDTH / 2) - (w / 2);
	y = (MAX_WIN_HEIGHT / 2) - (h / 2) - 45;

	gCentral.PrintDropBox(x, y, w, h, 0, 0);
	pSetFont(pTextThis(), (int)pFontBold);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu); //-- eShinyGreen
	pDrawText(pTextThis(), x , y + 15, "Game System", 230, 0, (LPINT) 3, 0);

	pDrawGUI(71520, x + (w / 2) - (200 / 2), y + 40, 200, 1); //-- Divisor

	pDrawGUI(71520, x + (w / 2) - (200 / 2), y + 209.5, 200, 1); //-- Divisor
}

void RenderPane_none(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(31461, x, y, w, h);
}


__declspec(naked) void RenderMix_Button03()
{
	static DWORD Addr_JMP = 0x007AA39C;

	_asm
	{
		PUSH 81524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x0F4                              ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderMix_Button02()
{
	static DWORD Addr_JMP = 0x007AA331;

	_asm
	{
		PUSH 81524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x0A0                              ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderMix_Button01()
{
	static DWORD Addr_JMP = 0x007AA2C9;

	_asm
	{
		PUSH 81524                                 ; |Arg1 = 00007A5E
		MOV ECX,DWORD PTR SS:[EBP-0x1C]            ; |
		ADD ECX,0x4C                               ; |
		JMP[Addr_JMP]
	}
}

void RenderPane_OptionMix(DWORD id, float x, float y, float w, float h)
{
	float v1;
	float v2;
	float v3;
	float v4;
	float v5;
	float v6;
	signed int i;
	//gCentral.PrintDropBox(x, y, w, h, 0, 0);

	v1 = (double)60;	//Posição Y das Janelas
	v2 = (double)169;	//Largura das Janelase
	v4 = (double)235;	//Posição X das Janelas

	v3 = (double)(12); //Y barra de cima
	RenderBitmap(79324, v4, v3 + v1, v2, 280.0, 0, 0, 0.83203125, 0.605, 1, 1, 0.0);

	//for (i = 0; i < 7; ++i)
	//{
	//	v5 = (double)12 + (double)(40 * i + 5); //Y do fundo
	//	RenderBitmap(79324, v4, v5 + v1, v2, 40.0, 0, 0, 0.83203125, 0.625, 1, 1, 0.0);
	//}
	//
	//v6 = (double)(12) + 280.0; //Y barra de baixo
	//RenderBitmap(79325, v4, v6 + v1, v2, 5.0, 0, 0, 0.83203125, 0.625, 1, 1, 0.0);

	//pDrawGUI(71520, x + (w / 2) - (200 / 2), y + 30, 200, 1); //-- Divisor
}

int ChaosMixTextTitle00(int X, int Y, LPCTSTR Text)
{
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	return pDrawText(pTextThis(), X - 20, Y + 14, Text, 160, 0, (LPINT)3, 0);
}

int ChaosMixTextTitle01(int X, int Y, LPCTSTR Text)
{
	pSetTextColor(pTextThis(), 0xDCu, 0xDCu, 0xDCu, 0xFFu);
	return pDrawText(pTextThis(), X - 35, Y + 28, Text, 160, 0, (LPINT)3, 0);
}

int ChaosMixTextTitle02(int X, int Y, LPCTSTR Text)
{
	return pDrawText(pTextThis(), X + 1, Y + 12, Text, 0, 0, (LPINT)1, 0);
}

int ChaosMixTextTitle03(int X, int Y, LPCTSTR Text)
{
	pSetTextColor(pTextThis(), 0xDCu, 0xDCu, 0xDCu, 0xFFu);
	return pDrawText(pTextThis(), X, Y - 12, Text, 0, 0, (LPINT)1, 0);
}

int ChaosMixTextTitle04(int X, int Y, LPCTSTR Text)
{
	pSetTextColor(pTextThis(), 0xDCu, 0xDCu, 0xDCu, 0xFFu);
	return pDrawText(pTextThis(), X, Y, Text, 0, 0, (LPINT)1, 0);
}

int MuHelperTextTitle00(int X, int Y, LPCTSTR Text)
{
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	return pDrawText(pTextThis(), X, Y + 15, Text, 70, 0, (LPINT)3, 0);
}

int MuHelperTextTitle01(int X, int Y, LPCTSTR Text)
{	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	return pDrawText(pTextThis(), X, Y, Text, 0, 0, (LPINT)3, 0);
}

int GensTextTitle00(int X, int Y, LPCTSTR Text)
{
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	return pDrawText(pTextThis(), X, Y + 15, Text, 190, 0, (LPINT)3, 0);
}

int GensTextTitle01(int X, int Y, LPCTSTR Text)
{	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	return pDrawText(pTextThis(), X, Y, Text, 190, 0, (LPINT)1, 0);
}

int OptionBuffer;
int CtrlAtivo;
int EffectAtivo;
int FlagAtivo;
DWORD TimerEventVK;
DWORD TimerEventVK2;
DWORD TimerEventVK3;

void RenderOptionPanelOrigin(int a1)
{
	float v4; // ST08_4@2
	float v5; // ST04_4@2
	float v6; // ST08_4@3
	float v7; // ST04_4@3
	float v8; // ST08_4@5
	float v9; // ST04_4@5
	float v10; // ST08_4@6
	float v11; // ST04_4@6
	float v12; // ST08_4@8
	float v13; // ST04_4@8
	float v14; // ST08_4@9
	float v15; // ST04_4@9
	float v16; // ST10_4@10
	float v17; // ST0C_4@10
	float v18; // ST3C_4@11
	float v19; // ST10_4@11
	float v20; // ST0C_4@11
	float v21; // ST10_4@12
	float v22; // ST0C_4@12
	float v23; // ST24_4@13
	float v24; // ST10_4@13
	float v25; // ST0C_4@13
	int v26; // [sp+74h] [bp-4h]@1
	//
	float v122; // ST08_4@8
	float v132; // ST04_4@8
	float v142; // ST08_4@9
	float v152; // ST04_4@9
	float v162; // ST08_4@9
	float v172; // ST04_4@9
	float PosY;

	PosY -= 28;

	v26 = a1;
	sub_7798F0(a1 + 24, 0);
	float X = 0.0;
	if (*(BYTE *)(v26 + 196))
	{
		v4 = (double)(*(DWORD *)(v26 + 20) + 43 + PosY);
		v5 = (double)(*(DWORD *)(v26 + 16) + 150 + X);
		pDrawButton(31593, v5, v4, 15.0, 15.0, 0.0, 0.0);  //click attack
	}
	else
	{
		v6 = (double)(*(DWORD *)(v26 + 20) + 43 + PosY);
		v7 = (double)(*(DWORD *)(v26 + 16) + 150 + X);
		pDrawButton(31593, v7, v6, 15.0, 15.0, 0.0, 15.0);  //click attack
	}
	if (*(BYTE *)(v26 + 197))
	{
		v8 = (double)(*(DWORD *)(v26 + 20) + 65 + PosY);
		v9 = (double)(*(DWORD *)(v26 + 16) + 150) + X;
		pDrawButton(31593, v9, v8, 15.0, 15.0, 0.0, 0.0);  //click som
	}
	else
	{
		v10 = (double)(*(DWORD *)(v26 + 20) + 65 + PosY);
		v11 = (double)(*(DWORD *)(v26 + 16) + 150 + X);
		pDrawButton(31593, v11, v10, 15.0, 15.0, 0.0, 15.0);  //click som
	}

	if (*(BYTE *)(v26 + 198)) //slide helper
	{
		v12 = (double)(*(DWORD *)(v26 + 20) + 127 + PosY);
		v13 = (double)(*(DWORD *)(v26 + 16) + 150);
		pDrawButton(31593, v13, v12, 15.0, 15.0, 0.0, 0.0);
	}
	else
	{
		v14 = (double)(*(DWORD *)(v26 + 20) + 127 + PosY);
		v15 = (double)(*(DWORD *)(v26 + 16) + 150);
		pDrawButton(31593, v15, v14, 15.0, 15.0, 0.0, 15.0);
	}

//Novos
	char Testando[200];
	wsprintf(Testando,"vl %d / vl2 %d", CtrlAtivo,EffectAtivo);
	Console.Write(Testando, 0, 0);
	
	v122 = (double)(*(DWORD *)(v26 + 20) + 205 + PosY);
	v132 = (double)(*(DWORD *)(v26 + 16) + 150);

	if(pCheckMouseOver( v132, v122, 15, 15 ) && (*(BYTE*)0x8793386) && GetTickCount() >= TimerEventVK + 250 )
	{
		if(CtrlAtivo !=0)
		{	
			gInterface.DrawMessage(1, "Auto PVP [OFF]");
			SetByte(0x0059AF53+2,1);
			SetByte(0x0059B248+2,1);
			CtrlAtivo = 0;
		}
		else
		{
			gInterface.DrawMessage(1, "Auto PVP [ON]");
			SetByte(0x0059AF53+2,0);
			SetByte(0x0059B248+2,0);			
			CtrlAtivo = 1;
		}
		TimerEventVK = GetTickCount();
	}

	if(CtrlAtivo == 0)
	{
		pDrawButton(31593, v132, v122, 15.0, 15.0, 0.0, 15.0);
	}
	if(CtrlAtivo == 1)
	{
		pDrawButton(31593, v132, v122, 15.0, 15.0, 0.0, 0.0);
	}
//	---------------------------------
	v142 = (double)(*(DWORD *)(v26 + 20) + 227 + PosY);
	v152 = (double)(*(DWORD *)(v26 + 16) + 150);

	if(pCheckMouseOver( v152, v142, 15, 15 ) && (*(BYTE*)0x8793386) && GetTickCount() >= TimerEventVK2 + 250 )
	{
		if(EffectAtivo !=0)
		{	
			//gInterface.DrawMessage(1, "Teste [OFF]");
			DelectEffectDynamicOff_Hook();
			SetByte(0x00608FB0, 0xC3); //Disable Skill Effects
			DelectEffectStaticOff_Hook();
			EffectAtivo = 0;
		}
		else
		{
			//gInterface.DrawMessage(1, "Teste [ON]");
			DelectEffectDynamicOn_Hook();
			SetByte(0x00608FB0, 0x55); //Disable Skill Effects	
			DelectEffectStaticOn_Hook();
			EffectAtivo = 1;
		}
		TimerEventVK2 = GetTickCount();
	}

	if(EffectAtivo == 0)
	{
		pDrawButton(31593, v152, v142, 15.0, 15.0, 0.0, 15.0);
	}
	if(EffectAtivo == 1)
	{
		pDrawButton(31593, v152, v142, 15.0, 15.0, 0.0, 0.0);
	}
//
//	---------------------------------
	v162 = (double)(*(DWORD *)(v26 + 20) + 249 + PosY);
	v172 = (double)(*(DWORD *)(v26 + 16) + 150);

	if(pCheckMouseOver( v172, v162, 15, 15 ) && (*(BYTE*)0x8793386) && GetTickCount() >= TimerEventVK3 + 250 )
	{
		if(FlagAtivo !=0)
		{	
		//	gInterface.DrawMessage(1, "Teste [OFF]");
			SetOp((LPVOID)0x00588661, (LPVOID)0x005655C0, ASM::CALL);
			SetByte(0x0051EC90, 0x55);
			SetByte(0x0051EE20, 0x55); //Disable Cloaks
			FlagAtivo = 0;
		}
		else
		{
			//gInterface.DrawMessage(1, "Teste [ON]");
			MemorySet(0x588661, 0x90, 0x5);
			SetByte(0x0051EC90, 0xC3);
			SetByte(0x0051EE20, 0xC3); //Disable Cloaks
			FlagAtivo = 1;
		}
		TimerEventVK3 = GetTickCount();
	}

	if(FlagAtivo == 0)
	{
		pDrawButton(31593, v172, v162, 15.0, 15.0, 0.0, 15.0);
	}
	if(FlagAtivo == 1)
	{
		pDrawButton(31593, v172, v162, 15.0, 15.0, 0.0, 0.0);
	}
//

	//volume click and image
	v16 = (double)(*(DWORD *)(v26 + 20) + 104 + PosY);
	v17 = (double)(*(DWORD *)(v26 + 16) + 33);
	pDrawGUI(31596, v17, v16, 124.0, 16.0);

	if (*(DWORD *)(v26 + 200) > 0)
	{
		//volume click and image
		v18 = (double)*(signed int *)(v26 + 200) * 12.40000057220459;
		v19 = (double)(*(DWORD *)(v26 + 20) + 104 + PosY);
		v20 = (double)(*(DWORD *)(v26 + 16) + 33);
		pDrawGUI(31597, v20, v19, v18, 16.0);
	}

	//effect limitation
	v21 = (double)(*(DWORD *)(v26 + 20) + 168 + PosY);
	v22 = (double)(*(DWORD *)(v26 + 16) + 25);
	pDrawGUI(31594, v22, v21, 141.0, 29.0);
	if (*(DWORD *)(v26 + 204) >= 0)
	{	
		//effect limitation
		v23 = (double)(*(DWORD *)(v26 + 204) + 1) * 28.20000076293945;
		v24 = (double)(*(DWORD *)(v26 + 20) + 168 + PosY);
		v25 = (double)(*(DWORD *)(v26 + 16) + 25);
		pDrawGUI(31595, v25, v24, v23, 29.0);
	}
}

int RenderOptionTextOrigin(int a1)
{
	int v4; // ST1C_4@1
	float v5; // ST20_4@1
	float v6; // ST24_4@1
	float v7; // ST24_4@1
	float v8; // ST24_4@1
	float v9; // ST24_4@1
	float v10; // ST24_4@1
	HGDIOBJ v11; // ST18_4@1
	void *v12; // eax@1
	void *v13; // eax@1
	void *v14; // eax@1
	int v15; // ST08_4@1
	int v16; // ST04_4@1
	int v17; // ST00_4@1
	void *v18; // eax@1
	int v19; // ST08_4@1
	int v20; // ST04_4@1
	int v21; // ST00_4@1
	void *v22; // eax@1
	int v23; // ST08_4@1
	int v24; // ST04_4@1
	int v25; // ST00_4@1
	void *v26; // eax@1
	int v27; // ST08_4@1
	int v28; // ST04_4@1
	int v29; // ST00_4@1
	void *v30; // eax@1
	int v31; // ST08_4@1
	int v32; // ST04_4@1
	int v33; // ST00_4@1
	void *v34; // eax@1
	int v35; // ST04_4@1
	int v36; // ST00_4@1
	float prox;
	float prox1;
	float prox2;
	float PosY;

	v4 = *(DWORD *)(GetInstance() + 160);
	PosY -= 28;

	v5 = (double)*(signed int *)(v4 + 16) + 20.0;
	v6 = (double)*(signed int *)(v4 + 20) + 46.0 + PosY;
	pDrawGUI(31592, v5, v6, 10.0, 10.0);
	v7 = v6 + 22.0;
	pDrawGUI(31592, v5, v7, 10.0, 10.0);
	v8 = v7 + 22.0;
	pDrawGUI(31592, v5, v8, 10.0, 10.0);
	v9 = v8 + 40.0;
	pDrawGUI(31592, v5, v9, 10.0, 10.0);
	v10 = v9 + 22.0;
	pDrawGUI(31592, v5, v10, 10.0, 10.0);
	prox = v10 + 58.0;
	pDrawGUI(31592, v5, prox, 10.0, 10.0);
	prox1 = prox + 22.0;
	pDrawGUI(31592, v5, prox1, 10.0, 10.0);
	prox2 = prox1 + 22.0;
	pDrawGUI(31592, v5, prox2, 10.0, 10.0);

	pSetFont(pTextThis(), (int)pFontNormal);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	sub_4200F0_Addr(pTextThis(), 0);
		
	v16 = *(DWORD *)(v4 + 20) + 48 + PosY;
	v17 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v17, v16, pGetTextLine(pTextLineThis, 386), 0, 0, (PINT)1, 0); //-- Attack Automatic

	v20 = *(DWORD *)(v4 + 20) + 70 + PosY;
	v21 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v21, v20, pGetTextLine(pTextLineThis, 387), 0, 0, (PINT)1, 0); //-- Beep Sound

	v24 = *(DWORD *)(v4 + 20) + 92 + PosY;
	v25 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v25, v24, pGetTextLine(pTextLineThis, 389), 0, 0, (PINT)1, 0); //-- Volumen

	v28 = *(DWORD *)(v4 + 20) + 132 + PosY;
	v29 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v29, v28, pGetTextLine(pTextLineThis, 919), 0, 0, (PINT)1, 0); //-- Slide Help
	
	v35 = *(DWORD *)(v4 + 20) + 211 + PosY;
	v36 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v36, v35, "Ctrl Ativo", 0, 0, (PINT)1, 0); //-- Ctrl Ativo
	
	v35 = *(DWORD *)(v4 + 20) + 233 + PosY;
	v36 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v36, v35, "Remove Effects", 0, 0, (PINT)1, 0); //-- Effects
	
	v35 = *(DWORD *)(v4 + 20) + 255 + PosY;
	v36 = *(DWORD *)(v4 + 16) + 40;
	pDrawText(pTextThis(), v36, v35, "Remove Flags", 0, 0, (PINT)1, 0); //-- Wings

	v32 = *(DWORD *)(v4 + 20) + 154 + PosY;
	v33 = *(DWORD *)(v4 + 16) + 40;
	return pDrawText(pTextThis(), v33, v32, pGetTextLine(pTextLineThis, 1840), 0, 0, (PINT)1, 0); //-- Effect Limit
}

void RenderWindowsOptionOrigin(int a1)
{
	float v1; 
	float v2; 
	float v3; 
	float v4; 
	float v5; 
	float v6; 
	float v7; 
	float v8; 
	float v9; 
	float v10; 
	float v11; 
	float v12; 
	float v13; 
	int v14; 
	signed int i; 
	float v16;
	float v17;

	v1 = (double)60;	//Posição Y das Janelas
	v2 = (double)169;	//Largura das Janelase
	v4 = (double)235;	//Posição X das Janelas

	v3 = (double)(12); //Y barra de cima
	RenderBitmap(79324, v4, v3 + v1, v2, 247.0, 0, 0, 0.83203125, 0.605, 1, 1, 0.0);
	//gCentral.PrintDropBox(v16-170, v4, 530, 310, 0, 0);

	//pDrawGUI(31322, v16, v4, 190.0, 249.0);
	//pDrawGUI(31588, v16, v4, 190.0, 64.0);

	//v17 = v4 + 64.0;
	////for ( i = 0; i < 14; ++i )
	////{
	////	pDrawGUI(31589, v16, v17, 21.0, 10.0);
	////	v5 = v16 + 190.0 - 21.0;
	////	pDrawGUI(31590, v5, v17, 21.0, 10.0);
	////	v17 = v17 + 10.0;
	////}
	//
	////pDrawGUI(31357, v16, v17, 190.0, 45.0);
	//
	//v6 = (double)*(signed int *)(v14 + 20) + 60.0;
	//v7 = v16 + 18.0;
	////pDrawGUI(31591, v7, v6, 154.0, 2.0);
	//
	//v8 = v6 + 22.0;
	//v9 = v16 + 18.0;
	//pDrawGUI(31591, v9, v8, 154.0, 2.0);
}

__declspec(naked) void CheckAutoPote() 
{
	static DWORD Pointer;
	static DWORD main_addr = 0x0095E1C4;

	_asm
	{
		MOV ECX, DWORD PTR SS : [EBP - 0x1874]
		MOV Pointer, ECX
	}

	if (*(BYTE *)(Pointer + 176))
	{
		if (ViewCurHP < (ViewMaxHP * *(BYTE *)(Pointer + 177) / 100) && *(BYTE *)(*(DWORD *)(Pointer + 4) + 780) == 1 && ViewCurHP > 0)
		{
			main_addr = 0x0095E1B9;
		}
	}

	_asm
	{
		JMP[main_addr]
	}
}

void SelectChar()
{
	float v3; // STD0_4@11
	float v4; // STCC_4@11
	float v5; // STD0_4@11
	float v6; // STCC_4@11
	int v31; // eax@46
	int v32; // eax@46
	int v36; // eax@50
	int v39; // eax@52
	float v44; // ST60_4@58
	DWORD *v51; // eax@63
	int v60; // [sp+D0h] [bp-Ch]@1
	float v61; // [sp+D4h] [bp-8h]@1
	float v62; // [sp+D8h] [bp-4h]@1

	if (pPlayerState == 4)
	{
		if (gProtect.m_MainInfo.SelectCharacterType == 1)
		{
			SelectCharInterfaceDowngrade();
		}
	}

	if (gRenderMap.DataMap.ModelID != -1 && MiniMap)
	{
		if (pCheckMouseOver(gRenderMap.ultimoX, gRenderMap.ultimoY, 128, 128))
		{
			pSetCursorFocus = true;
		}
	}

	pSetBlend(1);
	glColor3f(1.0, 1.0, 1.0);

	v61 = 0.0;
	v62 = 0.0;

	v3 = (double)CursorY - 2.0;
	v4 = (double)CursorX - 2.0;
	v5 = (double)CursorY + 18.0;
	v6 = (double)CursorX + 5.0;

	if (*(DWORD*)0x81F6BE8 || *(DWORD*)0xE8CB3C)	//-- bloquear cursor
	{
		v31 = sub_8615E0((int)pWindowThis());
		v32 = sub_78ECE0(v31);
		if (pCheckWindow(pWindowThis(), 10))
		{
			if (v32)
			{
				if (v32 == 1)
				{
					RenderBitmap(30013, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
			else
			{
				RenderBitmap(30012, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
		}
		else
		{
			if (pCheckWindow(pWindowThis(), 13)
				&& (v36 = sub_861260((int)pWindowThis()), sub_834550(v36) == 1)
				|| pCheckWindow(pWindowThis(), 12)
				&& (v39 = sub_861280((int)pWindowThis()), sub_847EF0(v39) == 2))
			{
				if (*(BYTE*)0x8793386)
				{
					sub_637E80(30017, v6, v5, 24.0, 24.0, 45.0, 0.0, 0.0, 1.0, 1.0);
				}
				else
				{
					RenderBitmap(30017, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
			else if (*(DWORD*)0x81F6BE0 == 2)
			{
				v44 = *(float*)0x5EF5A1C * 0.01999999955296516;
				sub_4F6170(v44);
				if (v44 <= 0.0)
				{
					sub_637E80(30017, v6, v5, 24.0, 24.0, 45.0, 0.0, 0.0, 1.0, 1.0);
				}
				else
				{
					sub_637E80(30017, (double)*(DWORD*)0x879340C + 10.0, (double)*(DWORD*)0x8793410 + 10.0, 24.0, 24.0, 0.0, 0.0, 0.0, 1.0, 1.0);
				}
			}
			else
			{
				if (*(BYTE*)0x8793386)
				{
					if (!*(BYTE*)0x81C03AA)//-- clic
					{
						RenderBitmap(30013, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
					}
				}
				else
				{
					RenderBitmap(30012, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
			}
		}
	}
	else if (ItemTarget == -1)	//-- recoger item
	{
		if (NpcTarget == -1) //-- NPC TARGET
		{
			if (*(DWORD*)0xE61734 == -1)
			{
				if (*(BYTE *)(0x7BC4F04 + 14) || PlayerTarget == -1) //-- PLAYER TARGET
				{
					v31 = sub_8615E0((int)pWindowThis());
					v32 = sub_78ECE0(v31);
					if (pCheckWindow(pWindowThis(), 10))
					{
						if (v32 == 9)
						{
							RenderBitmap(31239, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
						}
						else
						{
							if (v32)
							{
								if (v32 == 1)
								{
									RenderBitmap(30013, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
								}
							}
							else
							{
								RenderBitmap(30012, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
						}
					}
					else
					{
						if (pCheckWindow(pWindowThis(), 13)
							&& (v36 = sub_861260((int)pWindowThis()), sub_834550(v36) == 1)
							|| pCheckWindow(pWindowThis(), 12)
							&& (v39 = sub_861280((int)pWindowThis()), sub_847EF0(v39) == 2))
						{
							if (*(BYTE*)0x8793386)
							{
								sub_637E80(30017, v6, v5, 24.0, 24.0, 45.0, 0.0, 0.0, 1.0, 1.0);
							}
							else
							{
								RenderBitmap(30017, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
						}
						else if (*(DWORD*)0x81F6BE0 == 2)
						{
							v44 = *(float*)0x5EF5A1C * 0.01999999955296516;
							sub_4F6170(v44);
							if (v44 <= 0.0)
							{
								sub_637E80(30017, v6, v5, 24.0, 24.0, 45.0, 0.0, 0.0, 1.0, 1.0);
							}
							else
							{
								sub_637E80(30017, (double)*(DWORD*)0x879340C + 10.0, (double)*(DWORD*)0x8793410 + 10.0, 24.0, 24.0, 0.0, 0.0, 0.0, 1.0, 1.0);
							}
						}
						else
						{
							if (pCheckWindow(pWindowThis(), 13)
								&& (v51 = (DWORD *)sub_861280((int)pWindowThis()), sub_83C310(v51)))
							{
								RenderBitmap(30021, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
							else if (*(BYTE*)0x8793386)
							{
								if (*(BYTE*)0x81C03AA)
								{
									RenderBitmap(30020, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
								}
								else
								{
									RenderBitmap(30013, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
								}
							}
							else
							{
								RenderBitmap(30012, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
							}
						}
					}
				}
				else if (!sub_59A8B0() || *(BYTE*)0x813DDCE)
				{
					RenderBitmap(30012, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else if ((unsigned __int8)sub_4DB0E0(*(DWORD *)0xE61E18))
				{
					RenderBitmap(30011, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				else
				{
					RenderBitmap(30014, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				}
				//-- finaliza la carroña
			}
			/*else if (
				(*(DWORD *)0xE61E18 || *(DWORD *)(*(DWORD *)0x8787D58[3 * *(DWORD *)0xE61734] + 48) != 133)
			&& (*(DWORD *)0xE61E18 != 1 || *(DWORD *)(*(DWORD *)0x8787D58[3 * *(DWORD *)0xE61734] + 48) != 60)
			&& (*(DWORD *)0xE61E18 != 2 || *(DWORD *)(*(DWORD *)0x8787D58[3 * *(DWORD *)0xE61734] + 48) != 91)
			&& (*(DWORD *)0xE61E18 != 3 || *(DWORD *)(*(DWORD *)0x8787D58[3 * *(DWORD *)0xE61734] + 48) != 38) )
			{
				RenderBitmap(30019, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}*/
			else
			{
				RenderBitmap(30018, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
			}
		}
		else if (*(DWORD *)0xE61E18 == 38)//-- ATACAR UN MONSTER
		{
			RenderBitmap(30011, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		}
		else//-- HABLAR CON NPC
		{
			v60 = (int)(timeGetTime() * 0.009999999776482582) % 6;
			if (v60 == 1 || v60 == 3 || v60 == 5)
			{
				v61 = 0.5;
			}
			if (v60 == 2 || v60 == 3 || v60 == 4)
			{
				v62 = 0.5;
			}

			RenderBitmap(30016, v4, v3, 24.0, 24.0, v61, v62, 0.5, 0.5, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(30015, v4, v3, 24.0, 24.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}

	if (gInterface.item_post_ && pCursorX < 180)
	{
		gInterface.DrawItemToolTipText(gInterface.item_post_, 320, 150);
		if (gInterface.last_tickcount_view_ + 100 < GetTickCount())
		{
			gInterface.item_post_ = nullptr;
		}
	}
}

bool CheckAttackMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	y = (double)(*(DWORD *)(This + 20) + 43 - 28);
	x = (double)(*(DWORD *)(This + 16) + 150);

	return pCheckMouseOver(x, y, 15, 15);
}

bool CheckBeepMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	y = (double)(*(DWORD *)(This + 20) + 65 - 28);
	x = (double)(*(DWORD *)(This + 16) + 150);

	return pCheckMouseOver( x, y, 15, 15);
}

bool CheckSlideMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = *(DWORD *)(GetInstance() + 160);

	y = (double)(*(DWORD *)(This + 20) + 127 - 28);
	x = (double)(*(DWORD *)(This + 16) + 150);

	return pCheckMouseOver(x, y, 15, 15);
}

bool CheckSoundMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = getWindowConfig_35((int)pWindowThis());

	y = *(DWORD *)(This + 20) + 104 - 28;

	return pCheckMouseOver(x, y, w, h);
}

bool CheckEffectMouseOver(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = getWindowConfig_35((int)pWindowThis());

	y = *(DWORD *)(This + 20) + 168 - 28;

	return pCheckMouseOver( x, y, w, h);
}

int TitleChasoBoxMove(int X, int Y, LPCTSTR Text)
{
	return pDrawText(pTextThis(), X, Y + 14, Text,  210, 0, (PINT)3, 0);
}

void Centralizado::InitCentral()
{
	SetCompleteHook(0xE9, 0x005BB0B0, &SelectChar);
	SetCompleteHook(0xE9, 0x0095E1AB, &CheckAutoPote); //Fix AutoPot en Helper

	//--- Panel Option
	if(gProtect.m_MainInfo.CustomInterfaceType == 1 || gProtect.m_MainInfo.CustomInterfaceType == 2)
	{
		SetCompleteHook(0xE9, 0x008499E0, &RenderOptionPanelOrigin); //opções do painel
		SetCompleteHook(0xE9, 0x00849730, &RenderOptionTextOrigin);  //textos do painel
		SetCompleteHook(0xE9, 0x008494B0, &RenderWindowsOptionOrigin); //fundo do painel
		MemorySet(0x00848CB6,0x90,0x5); //REMOVE CLOSE BUTTON
		//Movendo Botões
		SetCompleteHook(0xE8, 0x00848E5D, &CheckAttackMouseOver);	// - attack
		SetCompleteHook(0xE8, 0x00848EB2, &CheckBeepMouseOver);		// - sound
		SetCompleteHook(0xE8, 0x00848F07, &CheckSlideMouseOver);	// - slide
		SetCompleteHook(0xE8, 0x00848F4B, &CheckSoundMouseOver);	// - sound slide
		SetCompleteHook(0xE8, 0x00849087, &CheckEffectMouseOver);	// - effect*/

		////-- Boton OptionMix
		//SetCompleteHook(0xE9, 0x007AA38E, &RenderMix_Button03);
		//SetCompleteHook(0xE9, 0x007AA323, &RenderMix_Button02);
		//SetCompleteHook(0xE9, 0x007AA2BE, &RenderMix_Button01);
		//-- Ventana OptionMix
		SetCompleteHook(0xE8, 0x007AA4E8, &RenderPane_OptionMix);
		SetCompleteHook(0xE8, 0x007AA53E, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007AA5AA, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007AA5FD, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007AA70E, &TitleChasoBoxMove);
	}
	
	if(gProtect.m_MainInfo.CustomInterfaceType == 3)
	{

		//Gens
		SetCompleteHook(0xE8,0x007C4DD6 ,&GensTextTitle00);
		SetCompleteHook(0xE8,0x007C4E5D ,&GensTextTitle01);
		//MuHelper
		SetCompleteHook(0xE8,0x007F6753 ,&MuHelperTextTitle00);
		SetCompleteHook(0xE8,0x007F67F8 ,&MuHelperTextTitle01);

		//ChaosMix
		SetCompleteHook(0xE8, 0x0082CF1C ,&ChaosMixTextTitle00);
		SetCompleteHook(0xE8, 0x0082CFB1 ,&ChaosMixTextTitle01);
		MemorySet(0x0082D03E,0x90,0x5);
		SetCompleteHook(0xE8, 0x0082D084 ,&ChaosMixTextTitle02);
		MemorySet(0x0082D27E,0x90,0x5);
		SetCompleteHook(0xE8, 0x0082D507 ,&ChaosMixTextTitle03);
		SetCompleteHook(0xE8, 0x0082D3D3 ,&ChaosMixTextTitle04);
		SetDword(0x007AA42D,71535);
		//Render Esc
		SetCompleteHook(0xE9, 0x007A87DB, &RenderEsc_Button05);
		SetCompleteHook(0xE9, 0x007A877E, &RenderEsc_Button04);
		SetCompleteHook(0xE9, 0x007A8721, &RenderEsc_Button03);
		SetCompleteHook(0xE9, 0x007A86C4, &RenderEsc_Button02);
		SetCompleteHook(0xE9, 0x007A866D, &RenderEsc_Button01);
		//-- Ventana Esc
		SetCompleteHook(0xE8, 0x007A83A8, &RenderPane_Esc);
		SetCompleteHook(0xE8, 0x007A83FE, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007A846A, &RenderPane_none);
		SetCompleteHook(0xE8, 0x007A84BD, &RenderPane_none);
		SetCompleteHook(0xE9, 0x005C6E80, &this->MoveRenderCameraDefault);
	}
}