#include "stdafx.h"
#include "CSCharacterS13.h"
#include "PrintPlayer.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Offset.h"
#include "User.h"
#include "CustomRankUser.h"
#include "Protect.h"
#include "MiniMap.h"
#include "MultiCharacter.h"

CSCharacterS13 gCSCharacterS13;

void CSCharacterS13::Load()
{
	gInterface.BindObject(CharacterSelect, 51522, 85, 150, 219, 178);
	gInterface.BindObject(CharacterSelect_Button1, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_Button2, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_Button3, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_Button4, 51519, 150, 35, -1, -1);
	gInterface.BindObject(CharacterSelect_Button5, 51519, 150, 35, -1, -1);
	gInterface.BindObject(SelectCharacterS0_02, 51523, 640, 480, -1, -1);

	SetCompleteHook(0xE8, 0x004D5EE6,this->SelectChar);

	SetDword((PVOID)(0x004D752F+1), 51522);
	SetDword((PVOID)(0x004D7563+1), 51522);
	
	SetDword((PVOID)(0x004053A2+1), 51522); //remove deco.tga
	SetDword((PVOID)(0x00401D2F+1), 51522);	//remove characterex

	SetByte((PVOID)(0x004053D3+1),0); //REMOVE BARRA CINZA
	SetCompleteHook(0xE8, 0x004D6C3E,this->OpenCharacterSceneData);

	SetDword((PVOID)(0x004D6C73), 0);
	SetByte((PVOID)(0x00402106), 0);
}

void CSCharacterS13::OpenCharacterSceneData()
{
	if(gProtect.m_MainInfo.SelectCharacterType == 1 || gProtect.m_MainInfo.SelectCharacterType == 2)
	{
		pLoadImage("Custom\\InterfaceS2\\Upgrade\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
	}
	else if(gProtect.m_MainInfo.SelectCharacterType == 3)
	{
		pLoadImage("Interface\\GFx\\ex700\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
	}
	else
	{
		pLoadImage("Interface\\GFx\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
	}

	if(gProtect.m_MainInfo.SelectCharacterType == 1)
	{
		pLoadImage("Custom\\InterfaceS2\\Layout.tga", 51523, 0x2601, 0x2901, 1, 0);
	}

	pLoadImage("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
	pLoadImage("Effect\\magic_ground1_3.jpg", 32779, GL_LINEAR, GL_REPEAT, 1, 0);
//
	((void(__cdecl*)())0x006312E0)();
}

void CharacterSelect360()
{
	for (int i = 0; i < 5; i++)
	{	
		int v5 = pGetPreviewStruct(pPreviewThis(),i);
		int v8 = v5 + 776;
		if (gInterface.IsWorkZone(CharacterSelect))
		{	
			*(float *)(v8 + 272) = *(float *)(v8 + 272) + 5.0;  //AQUI É A VELOCIDADE DO GIRO DA 360
		}
		else
		{
			*(float *)(v8 + 272) = 70;
		}
	}
}

void CharacterCharacteristics(int a1,float a2)
{
	char* Name;
	char* Status;
	int Class;
	char Reset[256];
	char Level[256];
	float X = 471;
	float Y = 51;
	int This = (int)sub_482B70() + 36744;
	int Hero00 = This;
	Hero00 = *(DWORD *)(This + 4) + 368 * a1;
//
	Name = strcpy((char *)Hero00 + 176, (const char *)(*((DWORD *)Hero00 + 42) + 56));
	Status = (char *)Hero00 + 240;
	Class = sub_587620(*(BYTE *)(*(DWORD *)(Hero00 + 168) + 19));
	gInterface.DrawFormat(eGold, X + 35, Y + 20 + a2, 190, 2, (const char *)Name);
	gInterface.DrawFormat(eWhite180, X + 11, Y + 7 + a2, 190, 0, (const char *)Class);
	gInterface.DrawFormat(eWhite180, X - 50, Y + 7 + a2, 190, 4, (const char *)Status);
	wsprintf(Level, "Level: %d", *(WORD *)(*(DWORD *)(Hero00 + 168) + 130));
	pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
	pDrawText(pTextThis(), X - 50, Y + 20 + a2, Level, 190, 0, (LPINT)4, 0);
}

void CharacterTeleport(int a1,float a2,float a3,float a4)
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{	
		int v5 = pGetPreviewStruct(pPreviewThis(),a1);
		int v8 = v5 + 776;	  
		if ( v5 )  
		{    
			*(float *)(v8 + 156) = 0.30000001;	
			*(float *)(v8 + 160) = 0.30000001;
			*(float *)(v8 + 164) = 0.30000001;
			*(float *)(v8 + 252) = a2;
			*(float *)(v8 + 256) = a3;
			*(float *)(v8 + 272) = a4;
		}
	}
}

void CSCharacterS13::SelectChar()
{
	gObjUser.Refresh();
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{
		float X = 471;
		float Y = 51;

		if (*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
		{
			if(gProtect.m_MainInfo.MultiCharacterEnable == 1)
			{
				gInterface.DrawFormat(eWhite, 309, 432, 20, 3, gCustomMessage.GetMessage(72), gSelectCharMulti.m_CharacterPage);

				if (gSelectCharMulti.m_CharacterPage > 1)
				{
					gInterface.DrawButton(eSELECTCHAR_LEFT,  283, 425, 0, 0);
					gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 425, 0, 0);

					if (gInterface.IsWorkZone(eSELECTCHAR_LEFT))
					{
						DWORD Color = eAncient;
						// ----
						if (gInterface.Data[eSELECTCHAR_LEFT].OnClick)
						{
							Color = eAncient;
						}
						// ----
						gInterface.DrawColoredGUI(eSELECTCHAR_LEFT, gInterface.Data[eSELECTCHAR_LEFT].X, gInterface.Data[eSELECTCHAR_LEFT].Y, Color);
					}
				}
				if (gSelectCharMulti.m_CharacterPage < 2)
				{
					gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 425, 0, 0);
					gInterface.DrawButton(eSELECTCHAR_LEFT,  283, 425, 0, 0);

					if (gInterface.IsWorkZone(eSELECTCHAR_RIGHT))
					{
						DWORD Color = eAncient;
						// ----
						if (gInterface.Data[eSELECTCHAR_RIGHT].OnClick)
						{
							Color = eAncient;
						}
						// ----
						gInterface.DrawColoredGUI(eSELECTCHAR_RIGHT, gInterface.Data[eSELECTCHAR_RIGHT].X, gInterface.Data[eSELECTCHAR_RIGHT].Y, Color);
					}
				}
			}
		}
//
		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
		{
//Create Select
//0
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, Y + 13, 210, 3, "Empty Character Slot");
			}
//1
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 88 + 13, 210, 3, "Empty Character Slot");
			}
//2
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 125 + 13, 210, 3, "Empty Character Slot");
			}

//3
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 162 +13, 210, 3, "Empty Character Slot");
			}
//4
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Empty Character Slot");
			}
//4
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Empty Character Slot");
			}

//Character Select
			CharacterSelect360();

			if(gProtect.m_MainInfo.SelectCharacterType == 5)
			{
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button1))
					{
					
						if (gInterface.Data[CharacterSelect_Button1].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 0;
							CharacterTeleport(0, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							CharacterTeleport(1, 0.0, 0.0, 0.0);
							CharacterTeleport(2, 0.0, 0.0, 0.0);
							CharacterTeleport(3, 0.0, 0.0, 0.0);
							CharacterTeleport(4, 0.0, 0.0, 0.0);
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							if(SelectedHero == 0)
							{
								gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 35);
							}
						}

						if(SelectedHero == 0)
						{
							SelectedCharacter = 0;
						}
					}
					else
					{
						if(SelectedHero == 0)
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 0);
						}
					}
					CharacterCharacteristics(0,0);
				}
	//1
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button2))
					{
					
						if (gInterface.Data[CharacterSelect_Button2].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 1;
							CharacterTeleport(1, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							CharacterTeleport(0, 0.0, 0.0, 0.0);
							CharacterTeleport(2, 0.0, 0.0, 0.0);
							CharacterTeleport(3, 0.0, 0.0, 0.0);
							CharacterTeleport(4, 0.0, 0.0, 0.0);
							gInterface.DrawButton(CharacterSelect_Button2, 471,  Y+37, 0, 70);
						}
						else
						{
							if(SelectedHero == 1)
							{
								gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 35);
							}
						}
						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 1)
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 0);
						}
					}
					CharacterCharacteristics(1,37);				
				}
	//2
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button3))
					{
					
						if (gInterface.Data[CharacterSelect_Button3].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 2;
							CharacterTeleport(2, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							CharacterTeleport(0, 0.0, 0.0, 0.0);
							CharacterTeleport(1, 0.0, 0.0, 0.0);
							CharacterTeleport(3, 0.0, 0.0, 0.0);
							CharacterTeleport(4, 0.0, 0.0, 0.0);
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							if(SelectedHero == 2)
							{
								gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 35);
							}
						}

						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 2)
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 0);
						}
					}
					CharacterCharacteristics(2,74);
				}
	//3
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button4))
					{
					
						if (gInterface.Data[CharacterSelect_Button4].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 3;
							CharacterTeleport(3, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							CharacterTeleport(0, 0.0, 0.0, 0.0);
							CharacterTeleport(1, 0.0, 0.0, 0.0);
							CharacterTeleport(2, 0.0, 0.0, 0.0);
							CharacterTeleport(4, 0.0, 0.0, 0.0);
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							if(SelectedHero == 3)
							{
								gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 35);
							}
						}
						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 3)
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 0);
						}
					}

					CharacterCharacteristics(3,111);
				}
	//4
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button5))
					{
					
						if (gInterface.Data[CharacterSelect_Button5].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 4;
							CharacterTeleport(4, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY, gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate);
							CharacterTeleport(0, 0.0, 0.0, 0.0);
							CharacterTeleport(1, 0.0, 0.0, 0.0);
							CharacterTeleport(2, 0.0, 0.0, 0.0);
							CharacterTeleport(3, 0.0, 0.0, 0.0);
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							if(SelectedHero == 4)
							{
								gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 35);
							}
						}

						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 4)
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 0);
						}
					}

					CharacterCharacteristics(4,148);
				}
			}
			else //a baixo de ID 4
			{	
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button1))
					{
					
						if (gInterface.Data[CharacterSelect_Button1].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 0;
							if(gProtect.m_MainInfo.SelectCharacterType == 3)
							{
								CharacterTeleport(0, 13629.0, 12339.0, 90.0);
								CharacterTeleport(1, 0.0, 13539.0, 90.0);
								CharacterTeleport(2, 0.0, 13539.0, 90.0);
								CharacterTeleport(3, 0.0, 13539.0, 90.0);
								CharacterTeleport(4, 0.0, 13539.0, 90.0);
							}
							else if(gProtect.m_MainInfo.SelectCharacterType == 2)
							{
								CharacterTeleport(0, 7900.000, 19400.00, 75.0);
								CharacterTeleport(1, 0.0, 7900.000, 75.0);
								CharacterTeleport(2, 0.0, 7900.000, 75.0);
								CharacterTeleport(3, 0.0, 7900.000, 75.0);
								CharacterTeleport(4, 0.0, 7900.000, 75.0);
							}
							//else if(gProtect.m_MainInfo.SelectCharacterType == 1)
							//{
							//	CharacterTeleport(0, 8172.84083, 19265.57287, 90.0);
							//	CharacterTeleport(1, 0.0, 8171.84083, 90.0);
							//	CharacterTeleport(2, 0.0, 8171.84083, 90.0);
							//	CharacterTeleport(3, 0.0, 8171.84083, 90.0);
							//	CharacterTeleport(4, 0.0, 8171.84083, 90.0);
							//}
							else if(gProtect.m_MainInfo.SelectCharacterType == 4)
							{
								CharacterTeleport(0, 22840.0, 15355.0, 50.0);
								CharacterTeleport(1, 1000.0, 5145.0, 50.0);
								CharacterTeleport(2, 1000.0, 5145.0, 50.0);
								CharacterTeleport(3, 1000.0, 5145.0, 50.0);
								CharacterTeleport(4, 1000.0, 5145.0, 50.0);
							}
							else
							{
								CharacterTeleport(0, 8172.84083, 19265.57287, 90.0);
								CharacterTeleport(1, 0.0, 8171.84083, 90.0);
								CharacterTeleport(2, 0.0, 8171.84083, 90.0);
								CharacterTeleport(3, 0.0, 8171.84083, 90.0);
								CharacterTeleport(4, 0.0, 8171.84083, 90.0);
							}
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							if(SelectedHero == 0)
							{
								gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 35);
							}
						}

						if(SelectedHero == 0)
						{
							SelectedCharacter = 0;
						}
					}
					else
					{
						if(SelectedHero == 0)
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 0);
						}
					}
					CharacterCharacteristics(0,0);
				}
	//1
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button2))
					{
					
						if (gInterface.Data[CharacterSelect_Button2].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 1;
							if(gProtect.m_MainInfo.SelectCharacterType == 3)
							{
								CharacterTeleport(1, 13629.0, 12339.0, 90.0);
								CharacterTeleport(0, 0.0, 13539.0, 90.0);
								CharacterTeleport(2, 0.0, 13539.0, 90.0);
								CharacterTeleport(3, 0.0, 13539.0, 90.0);
								CharacterTeleport(4, 0.0, 13539.0, 90.0);
							}
							else if(gProtect.m_MainInfo.SelectCharacterType == 2)
							{
								CharacterTeleport(1, 7900.000, 19400.00, 75.0);
								CharacterTeleport(0, 0.0, 7900.000, 75.0);
								CharacterTeleport(2, 0.0, 7900.000, 75.0);
								CharacterTeleport(3, 0.0, 7900.000, 75.0);
								CharacterTeleport(4, 0.0, 7900.000, 75.0);
							}
/*							else if(gProtect.m_MainInfo.SelectCharacterType == 1)
							{
								CharacterTeleport(1, 8172.84083, 19265.57287, 90.0);
								CharacterTeleport(0, 0.0, 8171.94083, 90.0);
								CharacterTeleport(2, 0.0, 8171.94083, 90.0);
								CharacterTeleport(3, 0.0, 8171.94083, 90.0);
								CharacterTeleport(4, 0.0, 8171.94083, 90.0);
							}			*/				
							else if(gProtect.m_MainInfo.SelectCharacterType == 4)
							{
								CharacterTeleport(1, 22840.0, 15355.0, 50.0);
								CharacterTeleport(0, 1000.0, 5145.0, 50.0);
								CharacterTeleport(2, 1000.0, 5145.0, 50.0);
								CharacterTeleport(3, 1000.0, 5145.0, 50.0);
								CharacterTeleport(4, 1000.0, 5145.0, 50.0);
							}
							else
							{
								CharacterTeleport(1, 8172.84083, 19265.57287, 90.0);
								CharacterTeleport(0, 0.0, 8171.94083, 90.0);
								CharacterTeleport(2, 0.0, 8171.94083, 90.0);
								CharacterTeleport(3, 0.0, 8171.94083, 90.0);
								CharacterTeleport(4, 0.0, 8171.94083, 90.0);
							}
							gInterface.DrawButton(CharacterSelect_Button2, 471,  Y+37, 0, 70);
						}
						else
						{
							if(SelectedHero == 1)
							{
								gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 35);
							}
						}
						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 1)
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 0);
						}
					}
					CharacterCharacteristics(1,37);				
				}
	//2
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button3))
					{
					
						if (gInterface.Data[CharacterSelect_Button3].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 2;
							if(gProtect.m_MainInfo.SelectCharacterType == 3)
							{
								CharacterTeleport(2, 13629.0, 12339.0, 90.0);
								CharacterTeleport(0, 0.0, 13539.0, 90.0);
								CharacterTeleport(1, 0.0, 13539.0, 90.0);
								CharacterTeleport(3, 0.0, 13539.0, 90.0);
								CharacterTeleport(4, 0.0, 13539.0, 90.0);
							}
							else if(gProtect.m_MainInfo.SelectCharacterType == 2)
							{
								CharacterTeleport(2, 7900.000, 19400.00, 75.0);
								CharacterTeleport(0, 0.0, 7900.000, 75.0);
								CharacterTeleport(1, 0.0, 7900.000, 75.0);
								CharacterTeleport(3, 0.0, 7900.000, 75.0);
								CharacterTeleport(4, 0.0, 7900.000, 75.0);
							}
							//else if(gProtect.m_MainInfo.SelectCharacterType == 1)
							//{
							//	CharacterTeleport(2, 8172.84083, 19265.57287, 90.0);
							//	CharacterTeleport(0, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(1, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(3, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(4, 0.0, 8171.94083, 90.0);
							//}
							else if(gProtect.m_MainInfo.SelectCharacterType == 4)
							{
								CharacterTeleport(2, 22840.0, 15355.0, 50.0);
								CharacterTeleport(0, 1000.0, 5145.0, 50.0);
								CharacterTeleport(1, 1000.0, 5145.0, 50.0);
								CharacterTeleport(3, 1000.0, 5145.0, 50.0);
								CharacterTeleport(4, 1000.0, 5145.0, 50.0);
							}
							else
							{
								CharacterTeleport(2, 8172.84083, 19265.57287, 90.0);
								CharacterTeleport(0, 0.0, 8171.94083, 90.0);
								CharacterTeleport(1, 0.0, 8171.94083, 90.0);
								CharacterTeleport(3, 0.0, 8171.94083, 90.0);
								CharacterTeleport(4, 0.0, 8171.94083, 90.0);
							}
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							if(SelectedHero == 2)
							{
								gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 35);
							}
						}

						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 2)
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 0);
						}
					}
					CharacterCharacteristics(2,74);
				}
	//3
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button4))
					{
					
						if (gInterface.Data[CharacterSelect_Button4].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 3;
							if(gProtect.m_MainInfo.SelectCharacterType == 3)
							{
								CharacterTeleport(3, 13629.0, 12339.0, 90.0);
								CharacterTeleport(0, 0.0, 13539.0, 90.0);
								CharacterTeleport(1, 0.0, 13539.0, 90.0);
								CharacterTeleport(2, 0.0, 13539.0, 90.0);
								CharacterTeleport(4, 0.0, 13539.0, 90.0);
							}
							else if(gProtect.m_MainInfo.SelectCharacterType == 2)
							{
								CharacterTeleport(3, 7900.000, 19400.00, 75.0);
								CharacterTeleport(0, 0.0, 7900.000, 75.0);
								CharacterTeleport(1, 0.0, 7900.000, 75.0);
								CharacterTeleport(2, 0.0, 7900.000, 75.0);
								CharacterTeleport(4, 0.0, 7900.000, 75.0);
							}
							//else if(gProtect.m_MainInfo.SelectCharacterType == 1)
							//{
							//	CharacterTeleport(3, 8172.84083, 19265.57287, 90.0);
							//	CharacterTeleport(0, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(1, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(2, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(4, 0.0, 8171.94083, 90.0);
							//}
							else if(gProtect.m_MainInfo.SelectCharacterType == 4)
							{
								CharacterTeleport(3, 22840.0, 15355.0, 50.0);
								CharacterTeleport(0, 1000.0, 5145.0, 50.0);
								CharacterTeleport(1, 1000.0, 5145.0, 50.0);
								CharacterTeleport(2, 1000.0, 5145.0, 50.0);
								CharacterTeleport(4, 1000.0, 5145.0, 50.0);
							}
							else
							{
								CharacterTeleport(3, 8172.84083, 19265.57287, 90.0);
								CharacterTeleport(0, 0.0, 8171.94083, 90.0);
								CharacterTeleport(1, 0.0, 8171.94083, 90.0);
								CharacterTeleport(2, 0.0, 8171.94083, 90.0);
								CharacterTeleport(4, 0.0, 8171.94083, 90.0);
							}
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							if(SelectedHero == 3)
							{
								gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 35);
							}
						}
						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 3)
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 0);
						}
					}

					CharacterCharacteristics(3,111);
				}
	//4
				if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
				{
					if (gInterface.IsWorkZone(CharacterSelect_Button5))
					{
					
						if (gInterface.Data[CharacterSelect_Button5].OnClick)
						{
							PlayBuffer(25, 0, 0);
							SelectedHero = 4;
							if(gProtect.m_MainInfo.SelectCharacterType == 3)
							{		
								CharacterTeleport(4, 13629.0, 12339.0, 90.0);
								CharacterTeleport(0, 0.0, 13539.0, 90.0);
								CharacterTeleport(1, 0.0, 13539.0, 90.0);
								CharacterTeleport(2, 0.0, 13539.0, 90.0);
								CharacterTeleport(3, 0.0, 13539.0, 90.0);
							}
							else if(gProtect.m_MainInfo.SelectCharacterType == 2)
							{
								CharacterTeleport(4, 7900.000, 19400.00, 75.0);
								CharacterTeleport(0, 0.0, 7900.000, 75.0);
								CharacterTeleport(1, 0.0, 7900.000, 75.0);
								CharacterTeleport(2, 0.0, 7900.000, 75.0);
								CharacterTeleport(3, 0.0, 7900.000, 75.0);
							}
							//else if(gProtect.m_MainInfo.SelectCharacterType == 1)
							//{
							//	CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
							//	CharacterTeleport(0, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(1, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(2, 0.0, 8171.94083, 90.0);
							//	CharacterTeleport(3, 0.0, 8171.94083, 90.0);
							//}
							else if(gProtect.m_MainInfo.SelectCharacterType == 4)
							{
								CharacterTeleport(4, 22840.0, 15355.0, 50.0);
								CharacterTeleport(0, 1000.0, 5145.0, 50.0);
								CharacterTeleport(1, 1000.0, 5145.0, 50.0);
								CharacterTeleport(2, 1000.0, 5145.0, 50.0);
								CharacterTeleport(3, 1000.0, 5145.0, 50.0);
							}
							else
							{
								CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
								CharacterTeleport(0, 0.0, 8171.94083, 90.0);
								CharacterTeleport(1, 0.0, 8171.94083, 90.0);
								CharacterTeleport(2, 0.0, 8171.94083, 90.0);
								CharacterTeleport(3, 0.0, 8171.94083, 90.0);
							}
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							if(SelectedHero == 4)
							{
								gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
							}
							else
							{
								gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 35);
							}
						}

						SelectedCharacter = SelectedHero;
					}
					else
					{
						if(SelectedHero == 4)
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 0);
						}
					}
					CharacterCharacteristics(4,148);
				}
			}
		}
	}
	((void(__cdecl*)())0x005BB0B0)();
}

void CSCharacterS13::SelectCharButton(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	// ----
	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
	{
		return;
	}
	// ----
	if( gInterface.IsWorkZone(CharacterSelect_Button1) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button1].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button1].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button1].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button1].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button2) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button2].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button2].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button2].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button2].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button3) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button3].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button3].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button3].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button3].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button4) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button4].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button4].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button4].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button4].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button5) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button5].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button5].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button5].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button5].EventTick = GetTickCount();
		// ----
	}
}

//CSCharacterS13 gCSCharacterS13;
//
//void CSCharacterS13::LoadS0()
//{
//	gInterface.BindObject(SelectCharacterS0_01, 51522, 85, 150, 219, 178);
//	gInterface.BindObject(SelectCharacterS0_02, 51523, 640, 480, -1, -1);
//
//	SetCompleteHook(0xE8, 0x004D5EE6,this->SelectCharS0);
//	SetCompleteHook(0xE8, 0x004D6C3E,this->OpenCharacterSceneDataS0);
//
//	SetDword((PVOID)(0x004D752F+1), 51522);
//	SetDword((PVOID)(0x004D7563+1), 51522);
//	SetDword((PVOID)(0x004053A2+1), 51522); //remove deco.tga
//	SetDword((PVOID)(0x00401D2F+1), 51522);	//remove characterex
//
//	SetByte((PVOID)(0x004053D3+1),0); //REMOVE BARRA CINZA
//}
//
//void CSCharacterS13::OpenCharacterSceneDataS0()
//{	
//	pLoadImage("Custom\\InterfaceS2\\Layout.tga", 51523, 0x2601, 0x2901, 1, 0);
//	pLoadImage("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
//
////
//((void(__cdecl*)())0x006312E0)();
//}
//
//void CSCharacterS13::SelectCharS0()
//{	
//	gObjUser.Refresh();
//	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
//	{
///*	gInterface.DrawFormat(eWhite, 309, 432, 20, 3, gCustomMessage.GetMessage(72), gSelectCharMulti.m_CharacterPage);
//
//		if (gSelectCharMulti.m_CharacterPage > 1)
//		{
//			gInterface.DrawButton(eSELECTCHAR_LEFT,  283, 425, 0, 0);
//			gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 425, 0, 0);
//
//			if (gInterface.IsWorkZone(eSELECTCHAR_LEFT))
//			{
//				DWORD Color = eAncient;
//				// ----
//				if (gInterface.Data[eSELECTCHAR_LEFT].OnClick)
//				{
//					Color = eAncient;
//				}
//				// ----
//				gInterface.DrawColoredGUI(eSELECTCHAR_LEFT, gInterface.Data[eSELECTCHAR_LEFT].X, gInterface.Data[eSELECTCHAR_LEFT].Y, Color);
//			}
//		}
//		if (gSelectCharMulti.m_CharacterPage < 2)
//		{
//			gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 425, 0, 0);
//			gInterface.DrawButton(eSELECTCHAR_LEFT,  283, 425, 0, 0);
//
//			if (gInterface.IsWorkZone(eSELECTCHAR_RIGHT))
//			{
//				DWORD Color = eAncient;
//				// ----
//				if (gInterface.Data[eSELECTCHAR_RIGHT].OnClick)
//				{
//					Color = eAncient;
//				}
//				// ----
//				gInterface.DrawColoredGUI(eSELECTCHAR_RIGHT, gInterface.Data[eSELECTCHAR_RIGHT].X, gInterface.Data[eSELECTCHAR_RIGHT].Y, Color);
//			}
//		}*/
//		BeginBitmap();
//		pDrawImage(51523, 0, 0, 1024.0, 512.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//		EndOpengl();
//		float X = 471;
//		float Y = 51;
//	}
//((void(__cdecl*)())0x005BB0B0)();
//}
//
///*      Sistema original      */
//
//void CSCharacterS13::Load()
//{
//	gInterface.BindObject(CharacterSelect, 51522, 85, 150, 219, 178);
//	gInterface.BindObject(CharacterSelect_Button1, 51519, 150, 35, -1, -1);
//	gInterface.BindObject(CharacterSelect_Button2, 51519, 150, 35, -1, -1);
//	gInterface.BindObject(CharacterSelect_Button3, 51519, 150, 35, -1, -1);
//	gInterface.BindObject(CharacterSelect_Button4, 51519, 150, 35, -1, -1);
//	gInterface.BindObject(CharacterSelect_Button5, 51519, 150, 35, -1, -1);
//	gInterface.BindObject(CharacterSelect_Button6, 51519, 150, 35, -1, -1);
//	gInterface.BindObject(SelectCharacterS0_02, 51523, 640, 480, -1, -1);
//
//	SetCompleteHook(0xE8, 0x004D5EE6,this->SelectChar);
//	
//	//SetCompleteHook(0xE8, 0x004D712A, &CameraChar);
//	SetCompleteHook(0xE8, 0x00663E9D, &FrameCharacterRecv);
//
//	SetDword((PVOID)(0x004D752F+1), 51522);
//	SetDword((PVOID)(0x004D7563+1), 51522);
//	
//	SetDword((PVOID)(0x004053A2+1), 51522); //remove deco.tga
//	SetDword((PVOID)(0x00401D2F+1), 51522);	//remove characterex
//
//	SetByte((PVOID)(0x004053D3+1),0); //REMOVE BARRA CINZA
//	SetCompleteHook(0xE8, 0x004D6C3E,this->OpenCharacterSceneData);
//
//	SetDword((PVOID)(0x004D6C73), 0);
//	SetByte((PVOID)(0x00402106), 0);
//}
//
//void CSCharacterS13::OpenCharacterSceneData()
//{
//	if(gProtect.m_MainInfo.SelectCharacterType == 1 || gProtect.m_MainInfo.SelectCharacterType == 2)
//	{
//		pLoadImage("Custom\\InterfaceS2\\Upgrade\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
//	}
//	else if(gProtect.m_MainInfo.SelectCharacterType == 3)
//	{
//		pLoadImage("Interface\\GFx\\ex700\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
//	}
//	else
//	{
//		pLoadImage("Interface\\GFx\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);
//	}
//
//	if(gProtect.m_MainInfo.SelectCharacterType == 1)
//	{
//		pLoadImage("Custom\\InterfaceS2\\Layout.tga", 51523, 0x2601, 0x2901, 1, 0);
//	}
//
//	pLoadImage("Interface\\GFx\\none.tga", 51522, 0x2601, 0x2901, 1, 0);
//	pLoadImage("Effect\\magic_ground1_3.jpg", 32779, GL_LINEAR, GL_REPEAT, 1, 0);
////
//	((void(__cdecl*)())0x006312E0)();
//}
//
//void CharacterSelect360()
//{
//	for (int i = 0; i < 6; i++)
//	{	
//		int v5 = pGetPreviewStruct(pPreviewThis(),i);
//		int v8 = v5 + 776;
//		if (gInterface.IsWorkZone(CharacterSelect))
//		{	
//			*(float *)(v8 + 272) = *(float *)(v8 + 272) + 5.0;  //AQUI É A VELOCIDADE DO GIRO DA 360
//		}
//		else
//		{
//			*(float *)(v8 + 272) = 70;
//		}
//	}
//}
//
//void CharacterCharacteristics(int a1,float a2)
//{
//	char* Name;
//	char* Status;
//	int Class;
//	char Reset[256];
//	char Level[256];
//	float X = 471;
//	float Y = 51;
//	int This = (int)sub_482B70() + 36744;
//	int Hero00 = This;
//	Hero00 = *(DWORD *)(This + 4) + 368 * a1;
////
//	Name = strcpy((char *)Hero00 + 176, (const char *)(*((DWORD *)Hero00 + 42) + 56));
//	Status = (char *)Hero00 + 240;
//	Class = sub_587620(*(BYTE *)(*(DWORD *)(Hero00 + 168) + 19));
//	gInterface.DrawFormat(eGold, X + 35, Y + 20 + a2, 190, 2, (const char *)Name);
//	gInterface.DrawFormat(eWhite180, X + 11, Y + 7 + a2, 190, 0, (const char *)Class);
//	gInterface.DrawFormat(eWhite180, X - 50, Y + 7 + a2, 190, 4, (const char *)Status);
//	wsprintf(Level, "Level: %d", *(WORD *)(*(DWORD *)(Hero00 + 168) + 130));
//	pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
//	pDrawText(pTextThis(), X - 50, Y + 20 + a2, Level, 190, 0, (LPINT)4, 0);
//}
//
//void CharacterTeleport(int a1,float a2,float a3,float a4)
//{
//	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
//	{	
//		int v5 = pGetPreviewStruct(pPreviewThis(),a1);
//		int v8 = v5 + 776;	  
//		if ( v5 )  
//		{    
//			*(float *)(v8 + 156) = 0.30000001;	
//			*(float *)(v8 + 160) = 0.30000001;
//			*(float *)(v8 + 164) = 0.30000001;
//			*(float *)(v8 + 252) = a2;
//			*(float *)(v8 + 256) = a3;
//			*(float *)(v8 + 272) = a4;
//		}
//	}
//}
//
//void CSCharacterS13::SelectChar()
//{
//	gObjUser.Refresh();
//	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
//	{
///*		gInterface.DrawFormat(eWhite, 309, 432, 20, 3, gCustomMessage.GetMessage(72), gSelectCharMulti.m_CharacterPage);
//
//		if (gSelectCharMulti.m_CharacterPage > 1)
//		{
//			gInterface.DrawButton(eSELECTCHAR_LEFT,  283, 425, 0, 0);
//			gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 425, 0, 0);
//
//			if (gInterface.IsWorkZone(eSELECTCHAR_LEFT))
//			{
//				DWORD Color = eAncient;
//				// ----
//				if (gInterface.Data[eSELECTCHAR_LEFT].OnClick)
//				{
//					Color = eAncient;
//				}
//				// ----
//				gInterface.DrawColoredGUI(eSELECTCHAR_LEFT, gInterface.Data[eSELECTCHAR_LEFT].X, gInterface.Data[eSELECTCHAR_LEFT].Y, Color);
//			}
//		}
//		if (gSelectCharMulti.m_CharacterPage < 2)
//		{
//			gInterface.DrawButton(eSELECTCHAR_RIGHT, 333, 425, 0, 0);
//			gInterface.DrawButton(eSELECTCHAR_LEFT,  283, 425, 0, 0);
//
//			if (gInterface.IsWorkZone(eSELECTCHAR_RIGHT))
//			{
//				DWORD Color = eAncient;
//				// ----
//				if (gInterface.Data[eSELECTCHAR_RIGHT].OnClick)
//				{
//					Color = eAncient;
//				}
//				// ----
//				gInterface.DrawColoredGUI(eSELECTCHAR_RIGHT, gInterface.Data[eSELECTCHAR_RIGHT].X, gInterface.Data[eSELECTCHAR_RIGHT].Y, Color);
//			}
//		}*/
//
//		if(gProtect.m_MainInfo.SelectCharacterType == 1)
//		{
//			BeginBitmap();
//			pDrawImage(51523, 0, 0, 1024.0, 512.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
//			EndOpengl();
//		}
//
//		float X = 471;
//		float Y = 51;
////
//		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
//		{
////Create Select
////0
//			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button1))
//				{
//					if (gInterface.Data[CharacterSelect_Button1].OnClick)
//					{
//						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 70);
//						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 35);
//					}
//				}
//				else
//				{
//					gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 0);
//				}
//				gInterface.DrawFormat(eWhite180, X-29, Y + 13, 210, 3, "Empty Character Slot");
//			}
////1
//			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button2))
//				{
//					if (gInterface.Data[CharacterSelect_Button2].OnClick)
//					{
//						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 70);
//						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 35);
//					}
//				}
//				else
//				{
//					gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 0);
//				}
//				gInterface.DrawFormat(eWhite180, X-29, 88 + 13, 210, 3, "Empty Character Slot");
//			}
////2
//			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button3))
//				{
//					if (gInterface.Data[CharacterSelect_Button3].OnClick)
//					{
//						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 70);
//						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 35);
//					}
//				}
//				else
//				{
//					gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 0);
//				}
//				gInterface.DrawFormat(eWhite180, X-29, 125 + 13, 210, 3, "Empty Character Slot");
//			}
//
////3
//			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button4))
//				{
//					if (gInterface.Data[CharacterSelect_Button4].OnClick)
//					{
//						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 70);
//						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 35);
//					}
//				}
//				else
//				{
//					gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 0);
//				}
//				gInterface.DrawFormat(eWhite180, X-29, 162 +13, 210, 3, "Empty Character Slot");
//			}
////4
//			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button5))
//				{
//					if (gInterface.Data[CharacterSelect_Button5].OnClick)
//					{
//						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 70);
//						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 35);
//					}
//				}
//				else
//				{
//					gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 0);
//				}
//				gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Empty Character Slot");
//			}
//
////5
//			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),5) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button6))
//				{
//					if (gInterface.Data[CharacterSelect_Button6].OnClick)
//					{
//						gInterface.DrawButton(CharacterSelect_Button6, 471, 236, 0, 70);
//						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button6, 471, 236, 0, 35);
//					}
//				}
//				else
//				{
//					gInterface.DrawButton(CharacterSelect_Button6, 471, 236, 0, 0);
//				}
//				gInterface.DrawFormat(eWhite180, X-29, 236 + 13, 210, 3, "Empty Character Slot");
//			}
//
////Character Select
//			CharacterSelect360();
////0
//			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button1))
//				{
//					
//					if (gInterface.Data[CharacterSelect_Button1].OnClick)
//					{
//						PlayBuffer(25, 0, 0);
//						SelectedHero = 0;
//						if(gProtect.m_MainInfo.SelectCharacterType == 3)
//						{
//							CharacterTeleport(0, 13629.0, 12339.0, 90.0);
//							CharacterTeleport(1, 0.0, 13539.0, 90.0);
//							CharacterTeleport(2, 0.0, 13539.0, 90.0);
//							CharacterTeleport(3, 0.0, 13539.0, 90.0);
//							CharacterTeleport(4, 0.0, 13539.0, 90.0);
//							CharacterTeleport(5, 0.0, 13539.0, 90.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 2)
//						{
//							CharacterTeleport(0, 7900.000, 19400.00, 75.0);
//							CharacterTeleport(1, 0.0, 7900.000, 75.0);
//							CharacterTeleport(2, 0.0, 7900.000, 75.0);
//							CharacterTeleport(3, 0.0, 7900.000, 75.0);
//							CharacterTeleport(4, 0.0, 7900.000, 75.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
//						{
//							CharacterTeleport(0, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(1, 0.0, 8171.84083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.84083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.84083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.84083, 90.0);
//						}
//						else
//						{
//							CharacterTeleport(0, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(1, 0.0, 8171.84083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.84083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.84083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.84083, 90.0);
//						}
//						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
//					}
//					else
//					{
//						if(SelectedHero == 0)
//						{
//							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
//						}
//						else
//						{
//							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 35);
//						}
//					}
//
//					if(SelectedHero == 0)
//					{
//						SelectedCharacter = 0;
//					}
//				}
//				else
//				{
//					if(SelectedHero == 0)
//					{
//						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 0);
//					}
//				}
//				CharacterCharacteristics(0,0);
//			}
////1
//			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button2))
//				{
//					
//					if (gInterface.Data[CharacterSelect_Button2].OnClick)
//					{
//						PlayBuffer(25, 0, 0);
//						SelectedHero = 1;
//						if(gProtect.m_MainInfo.SelectCharacterType == 3)
//						{
//							CharacterTeleport(1, 13629.0, 12339.0, 90.0);
//							CharacterTeleport(0, 0.0, 13539.0, 90.0);
//							CharacterTeleport(2, 0.0, 13539.0, 90.0);
//							CharacterTeleport(3, 0.0, 13539.0, 90.0);
//							CharacterTeleport(4, 0.0, 13539.0, 90.0);
//							CharacterTeleport(5, 0.0, 13539.0, 90.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 2)
//						{
//							CharacterTeleport(1, 7900.000, 19400.00, 75.0);
//							CharacterTeleport(0, 0.0, 7900.000, 75.0);
//							CharacterTeleport(2, 0.0, 7900.000, 75.0);
//							CharacterTeleport(3, 0.0, 7900.000, 75.0);
//							CharacterTeleport(4, 0.0, 7900.000, 75.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
//						{
//							CharacterTeleport(1, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.94083, 90.0);
//						}
//						else
//						{
//							CharacterTeleport(1, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.94083, 90.0);
//						}
//						gInterface.DrawButton(CharacterSelect_Button2, 471,  Y+37, 0, 70);
//					}
//					else
//					{
//						if(SelectedHero == 1)
//						{
//							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
//						}
//						else
//						{
//							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 35);
//						}
//					}
//					SelectedCharacter = SelectedHero;
//				}
//				else
//				{
//					if(SelectedHero == 1)
//					{
//						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 0);
//					}
//				}
//				CharacterCharacteristics(1,37);				
//			}
////2
//			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button3))
//				{
//					
//					if (gInterface.Data[CharacterSelect_Button3].OnClick)
//					{
//						PlayBuffer(25, 0, 0);
//						SelectedHero = 2;
//						if(gProtect.m_MainInfo.SelectCharacterType == 3)
//						{
//							CharacterTeleport(2, 13629.0, 12339.0, 90.0);
//							CharacterTeleport(0, 0.0, 13539.0, 90.0);
//							CharacterTeleport(1, 0.0, 13539.0, 90.0);
//							CharacterTeleport(3, 0.0, 13539.0, 90.0);
//							CharacterTeleport(4, 0.0, 13539.0, 90.0);
//							CharacterTeleport(5, 0.0, 13539.0, 90.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 2)
//						{
//							CharacterTeleport(2, 7900.000, 19400.00, 75.0);
//							CharacterTeleport(0, 0.0, 7900.000, 75.0);
//							CharacterTeleport(1, 0.0, 7900.000, 75.0);
//							CharacterTeleport(3, 0.0, 7900.000, 75.0);
//							CharacterTeleport(4, 0.0, 7900.000, 75.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
//						{
//							CharacterTeleport(2, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.94083, 90.0);
//						}
//						else
//						{
//							CharacterTeleport(2, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.94083, 90.0);
//						}
//						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
//					}
//					else
//					{
//						if(SelectedHero == 2)
//						{
//							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
//						}
//						else
//						{
//							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 35);
//						}
//					}
//
//					SelectedCharacter = SelectedHero;
//				}
//				else
//				{
//					if(SelectedHero == 2)
//					{
//						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 0);
//					}
//				}
//				CharacterCharacteristics(2,74);
//			}
////3
//			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button4))
//				{
//					
//					if (gInterface.Data[CharacterSelect_Button4].OnClick)
//					{
//						PlayBuffer(25, 0, 0);
//						SelectedHero = 3;
//						if(gProtect.m_MainInfo.SelectCharacterType == 3)
//						{
//							CharacterTeleport(3, 13629.0, 12339.0, 90.0);
//							CharacterTeleport(0, 0.0, 13539.0, 90.0);
//							CharacterTeleport(1, 0.0, 13539.0, 90.0);
//							CharacterTeleport(2, 0.0, 13539.0, 90.0);
//							CharacterTeleport(4, 0.0, 13539.0, 90.0);
//							CharacterTeleport(5, 0.0, 13539.0, 90.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 2)
//						{
//							CharacterTeleport(3, 7900.000, 19400.00, 75.0);
//							CharacterTeleport(0, 0.0, 7900.000, 75.0);
//							CharacterTeleport(1, 0.0, 7900.000, 75.0);
//							CharacterTeleport(2, 0.0, 7900.000, 75.0);
//							CharacterTeleport(4, 0.0, 7900.000, 75.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
//						{
//							CharacterTeleport(3, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.94083, 90.0);
//						}
//						else
//						{
//							CharacterTeleport(3, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(4, 0.0, 8171.94083, 90.0);
//						}
//						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
//					}
//					else
//					{
//						if(SelectedHero == 3)
//						{
//							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
//						}
//						else
//						{
//							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 35);
//						}
//					}
//					SelectedCharacter = SelectedHero;
//				}
//				else
//				{
//					if(SelectedHero == 3)
//					{
//						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 0);
//					}
//				}
//
//				CharacterCharacteristics(3,111);
//			}
////4
//			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button5))
//				{
//					
//					if (gInterface.Data[CharacterSelect_Button5].OnClick)
//					{
//						PlayBuffer(25, 0, 0);
//						SelectedHero = 4;
//						if(gProtect.m_MainInfo.SelectCharacterType == 3)
//						{		
//							CharacterTeleport(4, 13629.0, 12339.0, 90.0);
//							CharacterTeleport(0, 0.0, 13539.0, 90.0);
//							CharacterTeleport(1, 0.0, 13539.0, 90.0);
//							CharacterTeleport(2, 0.0, 13539.0, 90.0);
//							CharacterTeleport(3, 0.0, 13539.0, 90.0);
//							CharacterTeleport(5, 0.0, 13539.0, 90.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 2)
//						{
//							CharacterTeleport(4, 7900.000, 19400.00, 75.0);
//							CharacterTeleport(0, 0.0, 7900.000, 75.0);
//							CharacterTeleport(1, 0.0, 7900.000, 75.0);
//							CharacterTeleport(2, 0.0, 7900.000, 75.0);
//							CharacterTeleport(3, 0.0, 7900.000, 75.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
//						{
//							CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//						}
//						else
//						{
//							CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//						}
//						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
//					}
//					else
//					{
//						if(SelectedHero == 4)
//						{
//							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
//						}
//						else
//						{
//							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 35);
//						}
//					}
//
//					SelectedCharacter = SelectedHero;
//				}
//				else
//				{
//					if(SelectedHero == 4)
//					{
//						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 0);
//					}
//				}
//
//				CharacterCharacteristics(4,148);
//			}
//
////5
//			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),5) + 780) )
//			{
//				if (gInterface.IsWorkZone(CharacterSelect_Button6))
//				{
//					
//					if (gInterface.Data[CharacterSelect_Button6].OnClick)
//					{
//						PlayBuffer(25, 0, 0);
//						SelectedHero = 5;
//						if(gProtect.m_MainInfo.SelectCharacterType == 3)
//						{	
//							CharacterTeleport(5, 13629.0, 12339.0, 90.0);
//							CharacterTeleport(0, 0.0, 13539.0, 90.0);
//							CharacterTeleport(1, 0.0, 13539.0, 90.0);
//							CharacterTeleport(2, 0.0, 13539.0, 90.0);
//							CharacterTeleport(3, 0.0, 13539.0, 90.0);
//							CharacterTeleport(4, 0.0, 13539.0, 90.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 2)
//						{
//							CharacterTeleport(4, 7900.000, 19400.00, 75.0);
//							CharacterTeleport(0, 0.0, 7900.000, 75.0);
//							CharacterTeleport(1, 0.0, 7900.000, 75.0);
//							CharacterTeleport(2, 0.0, 7900.000, 75.0);
//							CharacterTeleport(3, 0.0, 7900.000, 75.0);
//						}
//						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
//						{
//							CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//						}
//						else
//						{
//							CharacterTeleport(4, 8172.84083, 19265.57287, 90.0);
//							CharacterTeleport(0, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(1, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(2, 0.0, 8171.94083, 90.0);
//							CharacterTeleport(3, 0.0, 8171.94083, 90.0);
//						}
//						gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 70);
//					}
//					else
//					{
//						if(SelectedHero ==5)
//						{
//							gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 70);
//						}
//						else
//						{
//							gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 35);
//						}
//					}
//
//					SelectedCharacter = SelectedHero;
//				}
//				else
//				{
//					if(SelectedHero == 5)
//					{
//						gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 70);
//					}
//					else
//					{
//						gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 0);
//					}
//				}
//
//				CharacterCharacteristics(5,185);
//			}
//		}
//	}
//	((void(__cdecl*)())0x005BB0B0)();
//}
//
//void CSCharacterS13::SelectCharButton(DWORD Event)
//{
//	DWORD CurrentTick	= GetTickCount();
//	// ----
//	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
//	{
//		return;
//	}
//	// ----
//	if( gInterface.IsWorkZone(CharacterSelect_Button1) )
//	{
//		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button1].EventTick);
//		// ----
//		if( Event == WM_LBUTTONDOWN )
//		{
//			gInterface.Data[CharacterSelect_Button1].OnClick = true;
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button1].OnClick = false;
//		// ----
//		if( Delay < 500 )
//		{
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button1].EventTick = GetTickCount();
//		// ----
//		}
//	else if( gInterface.IsWorkZone(CharacterSelect_Button2) )
//	{
//		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button2].EventTick);
//		// ----
//		if( Event == WM_LBUTTONDOWN )
//		{
//			gInterface.Data[CharacterSelect_Button2].OnClick = true;
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button2].OnClick = false;
//		// ----
//		if( Delay < 500 )
//		{
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button2].EventTick = GetTickCount();
//		// ----
//		}
//	else if( gInterface.IsWorkZone(CharacterSelect_Button3) )
//	{
//		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button3].EventTick);
//		// ----
//		if( Event == WM_LBUTTONDOWN )
//		{
//			gInterface.Data[CharacterSelect_Button3].OnClick = true;
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button3].OnClick = false;
//		// ----
//		if( Delay < 500 )
//		{
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button3].EventTick = GetTickCount();
//		// ----
//		}
//	else if( gInterface.IsWorkZone(CharacterSelect_Button4) )
//	{
//		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button4].EventTick);
//		// ----
//		if( Event == WM_LBUTTONDOWN )
//		{
//			gInterface.Data[CharacterSelect_Button4].OnClick = true;
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button4].OnClick = false;
//		// ----
//		if( Delay < 500 )
//		{
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button4].EventTick = GetTickCount();
//		// ----
//		}
//	else if( gInterface.IsWorkZone(CharacterSelect_Button5) )
//	{
//		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button5].EventTick);
//		// ----
//		if( Event == WM_LBUTTONDOWN )
//		{
//			gInterface.Data[CharacterSelect_Button5].OnClick = true;
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button5].OnClick = false;
//		// ----
//		if( Delay < 500 )
//		{
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button5].EventTick = GetTickCount();
//		// ----
//	}
//	else if( gInterface.IsWorkZone(CharacterSelect_Button6) )
//	{
//		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button6].EventTick);
//		// ----
//		if( Event == WM_LBUTTONDOWN )
//		{
//			gInterface.Data[CharacterSelect_Button6].OnClick = true;
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button6].OnClick = false;
//		// ----
//		if( Delay < 500 )
//		{
//			return;
//		}
//		// ----
//		gInterface.Data[CharacterSelect_Button6].EventTick = GetTickCount();
//		// ----
//	}
//
//}
//
//void CSCharacterS13::JGPlayerHide( )
//{
//	int JCGetModelP;
//	char Level[256];
//	char Status[256];
//	float x;
//	float y = 51;
//	float w = 150;
//	float h = 35;
//	float currentx;
//	int ActiveCreateChar = 0;
//	//--
//		x = 447 + pWinWidth / pWinHeightReal - 640;
//
//		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
//		{
//			EnableAlphaTest( 1 );
//			glColor3f(1.0, 1.0, 1.0);
//
//			for ( int i = 0 ; i < 6 ; i ++ )
//			{
//				ZeroMemory(Level, sizeof(Level));
//
//				y = ((h + 5) * i) + 51;
//
//				JCGetModelP = pGetPreviewStruct(pPreviewThis(), i);
//
//				if( SelectedHero == i )
//				{
//					currentx = (double)0.4489941001;
//				}
//				else
//				{
//					currentx = (double)0.0012999833;
//				}
//
//				if ( pCheckMouseOver((int) x,(int) y,(int) w,(int) h) )
//				{
//					currentx = (double)0.6719940305;
//
//					if ( *(BYTE *)(JCGetModelP + 780) )
//					{
//						SelectedCharacter = i;
//					}
//
//					if ( *(BYTE*)0x8793386 )
//					{
//						currentx = (double)0.4489941001;
//						PlayBuffer(25, 0, 0);
//
//						if ( *(BYTE *)(JCGetModelP + 780) )
//						{
//							CharacterTeleport(i, 13629.0, 12339.0, 90.0);
//							SelectedHero = i;
//							*(BYTE*)0x8793386 = 0;
//						}
//						else
//						{
//							sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
//						}
//					}
//				}
//
//				if ( !*(BYTE *)(JCGetModelP + 780) )
//				{
//					RenderBitmap(98000, x, y, w, h, currentx, 0.9330000877, 0.2199999839, 0.05000000075, 1, 1, 0);
//
//					pSetFont(pTextThis( ), (int)pFontBold);
//					pSetTextColor(pTextThis(), 255, 255, 255, 180);
//				}
//				else
//				{
//					RenderBitmap(98000, x, y, w, h, currentx, 0.9330000877, 0.2199999839, 0.05000000075, 1, 1, 0);
//					pSetFont(pTextThis( ), (int)pFontNormal2);
//
//					std::map<int, PMSG_CHARACTER_LIST>::iterator it = this->lpInfoPlayer.find( i );
//
//					if(it != this->lpInfoPlayer.end())
//					{
//						pSetTextColor(pTextThis(), 255, 255, 255, 180);
//
//						pDrawText(pTextThis(), x + 11, y + 7, (char *)sub_587620((unsigned __int8)sub_587380( it->second.CharSetClass )), 150, 0, (LPINT)0, 0);
//		
//					}
//				}
//			}
//	}
////}
//}
//
//int CSCharacterS13::JPlayerAddList( PMSG_CHARACTER_CREATE_RECV * lpMsg ) //protocolo de criação do personagem de recebimento
//{
//	signed int result;
//	DWORD v10; 
//	float v11; 
//	float v12;
//	float v13;
//
//	PMSG_CHARACTER_LIST * lpInfo;
//
//	std::map<int, PMSG_CHARACTER_LIST>::iterator it;
//
//	if ( lpMsg->result == 1 )
//	{
//		if( lpMsg->slot >= 0 && lpMsg->slot < 6)
//		{
//			lpInfo = new PMSG_CHARACTER_LIST;
//			lpInfo->slot = lpMsg->slot;
//			memcpy(lpInfo->Name, lpMsg->name,sizeof(lpInfo->Name));
//			lpInfo->Level = lpMsg->level;
//			lpInfo->CtlCode = 0;
//			lpInfo->CharSet[0] = lpMsg->Class;
//
//			for(int o = 1 ; o < 18 ; o++)
//			{
//				lpInfo->CharSet[o] = 0xFF;
//			}
//
//			it = this->lpInfoPlayer.find (lpMsg->slot);
//
//			if(it != this->lpInfoPlayer.end())
//			{
//				this->lpInfoPlayer.erase ( it );
//			}
//			this->lpInfoPlayer.insert(std::pair<int, PMSG_CHARACTER_LIST >(lpMsg->slot, *(PMSG_CHARACTER_LIST*)lpInfo));
//		}
//	}
//	return 1;
//}
//
//int CSCharacterS13::FrameListCharacter( PMSG_CHARACTER_LIST_RECV * lpMsg ) //protocolo de recebimento de listagem do que é recebido pelo GS pelo DS
//{
//	int v4; 
//	DWORD result; 
//	int v10; 
//	float v11;
//	float v12; 
//	float v13;
//	int PlayerSlot;
//	int PlayerSelect;
//
//	sub_63CB40( );
//	sub_4D5130( lpMsg->ClassCode );
//	
//	if ( pPlayerState == 4 )
//		*(DWORD*)0xE61E18 = 93;
//
//	this->lpInfoPlayer.clear( );
//	PlayerSlot = 0;
//	PlayerSelect = 1;
//
//	for ( int n = 0 ; n < lpMsg->count ; n++ )
//	{
//		PMSG_CHARACTER_LIST * lpInfo = (PMSG_CHARACTER_LIST *) (((BYTE*)lpMsg) + sizeof(PMSG_CHARACTER_LIST_RECV) + (sizeof(PMSG_CHARACTER_LIST) * n));
//
//		if(lpInfo->slot >= 0 && lpInfo->slot < 6)
//		{
//			this->lpInfoPlayer.insert(std::pair<int, PMSG_CHARACTER_LIST >(lpInfo->slot, *(PMSG_CHARACTER_LIST*)lpInfo));
//		}
//
//		v10 = (unsigned __int8)sub_587380(lpInfo->CharSetClass);
//
//		v11 = 0.0;
//
//		switch ( lpInfo->slot )
//		{
//			case 0:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 1:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 2:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 3:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 4:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 5:
//				v12 = 8133.0;
//				v13 = 19645.0;
//				v11 = 60.0;
//				break;
//			case 6:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 7:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			default:
//			break;
//		}
//
//		v4 = CreateModelCharacter(lpInfo->slot, v10, 0, v12, v13, v11);
//
//		*(WORD *)(v4 + 130) = lpInfo->Level;
//
//		*(BYTE *)(v4 + 21) = lpInfo->CtlCode;
//
//		sub_9CF1C0B	((char *)(v4 + 56), lpInfo->Name, sizeof(lpInfo->Name));
//
//		*(BYTE *)(v4 + 66) = 0;
//	}
//
//	*(DWORD*)0x87935A4 = 51;
//
//	pWarehouseExSet(pWarehouseExThis(pWindowThis()), lpMsg->ExtWarehouse);
//
//	result = GetTickCount();
//	*(DWORD*)0xE8CB30 = result;
//	return result;
//}
//
//signed int FrameCharacterRecv( int CharacterRecv )
//{
//	signed int result; 
//	DWORD v10; 
//	float v11; 
//	float v12; 
//	float v13;
//	BYTE Slot;
//
//
//	if ( *(BYTE *)(CharacterRecv + 4) == 1 )
//	{
//		v11 = 0.0;
//		Slot = *(BYTE *)(CharacterRecv + 15);
//		switch ( Slot )
//		{
//			case 0:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 1:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 2:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 3:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 4:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 5:
//				v12 = 8133.0;
//				v13 = 19645.0;
//				v11 = 60.0;
//				break;
//			case 6:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			case 7:
//				v12 = 0.0;
//				v13 = 0.0;
//				v11 = 0.0;
//				break;
//			default:
//			break;
//		}
//
//		sub_57D760(*(BYTE *)(CharacterRecv + 15));
//		CreateModelCharacter(*(BYTE *)(CharacterRecv + 15), (unsigned __int8)*(BYTE*)0x7BD0483, *(BYTE*)0x7BD0484, v12, v13, v11);
//
//		v10 = pGetPreviewStruct(pPreviewThis(), *(BYTE *)(CharacterRecv + 15));
//
//		if ( v10 )
//		{
//			*(WORD *)(v10 + 130) = *(WORD *)(CharacterRecv + 16);
//			*(BYTE *)(v10 + 19) = sub_587380(*(BYTE *)(CharacterRecv + 18));
//			sub_9CF1C0B((char *)(v10 + 56), (const void *)(CharacterRecv + 5), 0xAu);
//			*(BYTE *)(v10 + 66) = 0;
//		}
//
//		*(DWORD*)0x87935A4 = 53;
//
//		sub_668520((char *)sub_482B70( ));
//		sub_4057B0((char *)sub_482B70( ) + 32632);
//		result = sub_402AD0((char *)sub_482B70() + 36744);
//	}
//	else
//	{
//		result = *(BYTE *)(CharacterRecv + 4);
//		if ( *(BYTE *)(CharacterRecv + 4) )
//		{
//			if ( *(BYTE *)(CharacterRecv + 4) == 2 )
//			{
//				result = sub_484A10(sub_482B70( ), 55, 0);
//			}
//		}
//		else
//		{
//			result = sub_484A10(sub_482B70(), 54, 0);
//		}
//	}
//	return result;
//}