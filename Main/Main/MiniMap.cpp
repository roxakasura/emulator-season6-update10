#include "stdafx.h"
#include "MiniMap.h"
#include "Import.h"
#include "Util.h"
#include "Offset.h"
#include "User.h"
#include "Interface.h"
#include "Defines.h"
#include "Common.h"
#include "MiniMapInfo.h"
#include "PrintPlayer.h"
#include "Protect.h"
#include "CMacroUIEx.h"
#include "ServerSwitch.h"
#include "Camera\CameraSystem.h"
#include "MenuCustom.h"

CMinimap gRenderMap;

CMinimap::CMinimap()
{
	this->DataMap.ModelID = -1;
	this->DataMap.XSW_Minimap_Frame = 486;  //-- Minimap_FrameX
	this->DataMap.YSW_Minimap_Frame = 234;  //-- Minimap_FrameY
	this->DataMap.XSW_Minimap = 510; //-- MiniMapX
	this->DataMap.YSW_Minimap = 265; //265; //-- MiniMapY
	this->DataMap.XSW_Time_Frame = 506; //-- Time_FrameX
	this->DataMap.YSW_Time_Frame = 392; //-- Time_FrameY
	this->DataMap.This_92 = 0;
	this->DataMap.This_96 = 0;
	this->DataMap.DropMoveUserX = 0; //-- DropMoveUserX
	this->DataMap.DropMoveUserY = 0; //-- DropMoveUserY
	this->DataMap.This_108;
	this->DataMap.This_112;
	this->DataMap.CurrentMoveX = 0.0; //-- CurrentMoveX
	this->DataMap.CurrentMoveY = 0.0; //-- CurrentMoveY
	this->DataMap.Scale = 1; //-- Scale
	this->DataMap.TimerEventVK = 0; //-- Scale
	this->DataMap.Alpha = 1.0f; //-- Alpha
	this->Hoving = false;
	this->ultimoX = 510;
	this->ultimoY = 265;
}

CMinimap::~CMinimap()
{
}

//----- (0082ABA0)
char CMinimap::MapRender(int a1)
{
	float DIRPointer;
	lpViewObj ObjectPointer;

	char result; // al@2
	float blue; // ST30_4@3
	float green; // ST2C_4@3
	float v7; // ST78_4@3
	float v8; // ST74_4@3
	float v9; // ST20_4@12
	float v10; // ST1C_4@12
	float v11; // ST70_4@12
	float v12; // ST6C_4@12
	float v13; // ST10_4@12
	float v14; // ST0C_4@12
	float v15; // ST20_4@15
	float v16; // ST1C_4@15
	float v17; // ST68_4@15
	float v18; // ST64_4@15
	float v19; // ST10_4@15
	float v20; // ST0C_4@15
	int v21; // eax@17
	int v22; // eax@19
	float v23; // ST30_4@19
	float v24; // ST60_4@19
	int v25; // eax@19
	float v26; // ST5C_4@19
	float v27; // ST58_4@19
	float v28; // ST54_4@22
	float v29; // ST50_4@22
	float v30; // ST4C_4@22
	float v31; // ST48_4@22
	int v32; // eax@23
	int v33; // eax@23
	float v34; // ST2C_4@23
	float v35; // ST44_4@23
	int v36; // eax@23
	float v37; // ST30_4@23
	float v38; // ST40_4@23
	int v39; // eax@23
	float v40; // ST30_4@23
	float v41; // ST2C_4@23
	float v42; // ST3C_4@23
	float v43; // ST38_4@23
	int v44; // [sp+78h] [bp-3Ch]@1
	float v45; // [sp+7Ch] [bp-38h]@3
	float v46; // [sp+88h] [bp-2Ch]@6
	float v47; // [sp+8Ch] [bp-28h]@1
	float v48; // [sp+90h] [bp-24h]@3
	float v49; // [sp+94h] [bp-20h]@6
	float v50; // [sp+98h] [bp-1Ch]@6
	float v51; // [sp+9Ch] [bp-18h]@3
	float v52; // [sp+A4h] [bp-10h]@3
	float v53; // [sp+A8h] [bp-Ch]@3
	signed int i; // [sp+ACh] [bp-8h]@3
	int j; // [sp+ACh] [bp-8h]@17
	int k; // [sp+ACh] [bp-8h]@20
	float v57; // [sp+B0h] [bp-4h]@3

	v44 = a1;
	v47 = 45.0;

	ObjectPointer = &*(ObjectPreview*)(*(DWORD *)0x7BC4F04);
	DIRPointer = (double) 135.0f + ( 45 * abs((signed int)(ObjectPointer->m_Model.Angle.Z / 45.0)));

	if ( *(BYTE *)(a1 + 13500) )
	{
		pSetBlend(1);
		pDrawBarForm(0.0, 0.0, 640.0, 480.0, 0.45000002, 1);
		pGLSwitch();

		pSetBlend(1);
		glColor4f(1.0, 1.0, 1.0, 1.0);
		
		v53 = (double)*(signed int *)(oUserPreviewStruct + 172) / 256.0 * (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80);

		v48 = (double)*(signed int *)(oUserPreviewStruct + 176) / 256.0 * (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76);

		v52 = 0.65156251;
		v45 = 1.0;
		v57 = 35.0;
		v51 = 6.0;
		blue = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80);
		green = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76);
		v7 = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 80) - v53;
		v8 = (double)*(signed int *)(a1 + 8 * *(DWORD *)(a1 + 124) + 76) - v48;
		//-- PINTA el Mapa
		pDrawMapFull(32447, v8, v7, green, blue, v47);

		//-- CICLO PARA PINTAR LOS NPC
		for ( i = 0; i < 100 && (signed int)*(BYTE *)(v44 + 116 * i + 300) > 0; ++i )
		{
			v50 = (double)*(signed int *)(v44 + 116 * i + 304) / 256.0
				* (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
			v46 = (double)*(signed int *)(v44 + 116 * i + 308) / 256.0
				* (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
			v49 = (double)*(signed int *)(v44 + 116 * i + 312);

			if ( *(BYTE *)(v44 + 116 * i + 300) == 1 )
			{
				if ( pMapNumber != 34 || (signed int)(unsigned __int8)0x986746A <= 0 || *(DWORD *)(v44 + 116 * i + 304) == 228 && *(DWORD *)(v44 + 116 * i + 308) == 48 && pMapNumber == 34 )
				{
					//-- PINTAMOS LOS NPC
					v9 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
					v10 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
					v11 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80) - v53;
					v12 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76) - v48;
					v13 = (double)25;
					v14 = (double)25;

					pDrawMapObject(32452, v46, v50, v14, v13, v12, v11, v10, v9, v47, v49, 0.546875, 0.546875, i);
				}
			}
			else if ( *(BYTE *)(v44 + 116 * i + 300) == 2 )
			{
				//-- PINTAMOS PORTAL
				v15 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80);
				v16 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76);
				v17 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 80) - v53;
				v18 = (double)*(signed int *)(v44 + 8 * *(DWORD *)(v44 + 124) + 76) - v48;
				v19 = (double)30;
				v20 = (double)30;

				pDrawMapObject(32451, v46, v50, v20, v19, v18, v17, v16, v15, v47, v49, 0.546875, 0.546875, i + 100);
			}
		}
		//-- PINTAMOS AL PERSONAJE
		sub_637E80( 32450,
			325.0,
			230.0,
			15.0,
			15.0, 
			DIRPointer,
			0.0,
			0.0,
			0.546875,
			0.546875);
		
		//v21 = pMakeColor(255, 255, 255, 255);
		//RenderBitMapColored(32450, 325.0, 230.0, 15.0, 15.0, 0.0, 0.0, 0.546875, 0.546875, v21);

		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
		result = 1;
	}
	else
	{
		result = *(BYTE *)(a1 + 13500);
	}

	return result;
}

void DataMapLoad()
{
	int v4; // [sp+Ch] [bp-Ch]@5
	int v5; // [sp+10h] [bp-8h]@2
	int Type;
	int Multiplicador;
	int Scalado;

	Type = gRenderMap.DataMap.Scale;
	Multiplicador = (( Type == 1 ) ? 1 : Type - 1 );
	Scalado = (( Type == 1 ) ? 512 : 128 );

	gRenderMap.DataMap.This_92 = *(DWORD *)(*(DWORD *)0x7BC4F04 + 172) / ((Type == 1) ? 0.5 : Type - 1 ); //-- X
	gRenderMap.DataMap.This_96 = (256 - *(DWORD *)(*(DWORD *)0x7BC4F04 + 176)) / ((Type == 1) ? 0.5 :  Type - 1  ); //-- Y

	//-- X
	if ( gRenderMap.DataMap.This_92 - ( Multiplicador << 6 ) <= 0 )
		v5 = 0;
	else
		v5 = gRenderMap.DataMap.This_92 - ( Multiplicador << 6 );

	gRenderMap.DataMap.This_108 = ( v5 >= Scalado ) ? Scalado : (v5 <= 0) ? 0: gRenderMap.DataMap.This_92 - ( Multiplicador << 6 );

	//-- Y
	if ( gRenderMap.DataMap.This_96 - ( Multiplicador << 6 ) <= 0 )
		v4 = 0;
	else
		v4 = gRenderMap.DataMap.This_96 - ( Multiplicador << 6 );

	gRenderMap.DataMap.This_112 = ( v4 >= Scalado ) ? Scalado : (v4 <= 0) ? 0: gRenderMap.DataMap.This_96 - ( Multiplicador << 6 );

	gRenderMap.DataMap.DropMoveUserX = gRenderMap.ultimoX + gRenderMap.DataMap.This_92 - gRenderMap.DataMap.This_108; //Minimapa abajo
	gRenderMap.DataMap.DropMoveUserY = gRenderMap.ultimoY + gRenderMap.DataMap.This_96 - gRenderMap.DataMap.This_112; //Minimapa abajo

	gRenderMap.DataMap.CurrentMoveX = (double)gRenderMap.DataMap.This_108 / ((double) ((Type == 1) ? 512.0 : 256.0 ) / (double)Multiplicador );
	gRenderMap.DataMap.CurrentMoveY = (double)gRenderMap.DataMap.This_112 / ((double) ((Type == 1) ? 512.0 : 256.0 ) / (double)Multiplicador );
}

void DataViewPortMapLoad()
{
	int Model;
	int Type;
	float XNPC, YNPC;

	Type = gRenderMap.DataMap.Scale;

	for (int i = 0; i < 400; ++i )
	{
		Model = pGetPreviewStruct(pPreviewThis(), i);
		if ( Model
			&& *(BYTE *)(Model + 780)
			&& Model != *(DWORD *)0x7BC4F04
			&& (*(BYTE *)(Model + 800) == 1 || *(BYTE *)(Model + 800) == 2 || *(BYTE *)(Model + 800) == 4) )
		{
			if ( *(BYTE *)(Model + 800) == 4  &&  *(WORD *)(Model + 132) != 249 )
			{
				XNPC = (double) gRenderMap.ultimoX + *(DWORD *)(Model + 172) / ((Type == 1) ? 0.5 : Type - 1 );
				YNPC = (double) gRenderMap.ultimoY + (256 - *(DWORD *)(Model + 176)) / ((Type == 1) ? 0.5 : Type - 1 );


				XNPC = XNPC - gRenderMap.DataMap.This_108 - 5;
				YNPC = YNPC - gRenderMap.DataMap.This_112 - 5;

				if( *(WORD *)(Model + 132) == 251 )
				{
					RenderBitMapColored(31466, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				}
				else if( *(WORD *)(Model + 132) == 255 || *(WORD *)(Model + 132) == 253 )
				{
					RenderBitMapColored(31467, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				}
				else if( *(WORD *)(Model + 132) == 240 ) //-- baul
				{
					RenderBitMapColored(31468, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				}
				else if( *(WORD *)(Model + 132) == 229 || *(WORD *)(Model + 132) == 235 || *(WORD *)(Model + 132) == 233 || *(WORD *)(Model + 132) == 237 ) //-- quest
				{
					RenderBitMapColored(31469, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				}
				else
				{
					RenderBitMapColored(32452, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				}

				if( pCheckMouseOver((int) XNPC, (int) YNPC, (int) 10, (int) 10) )
				{
					pDrawToolTip((int) XNPC, (int) YNPC - 10, (char *)(Model + 56));
				}
			}
			
			if ( *(BYTE *)(Model + 800) == 1 )
			{
				XNPC = (double) gRenderMap.ultimoX + *(DWORD *)(Model + 172) / ((Type == 1) ? 0.5 : Type - 1 );
				YNPC = (double) gRenderMap.ultimoY + (256 - *(DWORD *)(Model + 176)) / ((Type == 1) ? 0.5 : Type - 1 );

				XNPC = XNPC - gRenderMap.DataMap.This_108 - 5;
				YNPC = YNPC - gRenderMap.DataMap.This_112 - 5;

			/*	if (pPartyMemberCount > 0)
				{
					RenderBitMapColored(61520, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				}
				else
				{*/
				RenderBitMapColored(32450, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));
				/*}*/

				if( pCheckMouseOver((int) XNPC, (int) YNPC, (int) 10, (int) 10) )
				{
					pDrawToolTip((int) XNPC, (int) YNPC - 10, (char *)(Model + 56));
				}
			}

			if ( *(BYTE *)(Model + 800) == 2 )
			{
				XNPC = (double) gRenderMap.ultimoX + *(DWORD *)(Model + 172) / ((Type == 1) ? 0.5 : Type - 1 );
				YNPC = (double) gRenderMap.ultimoY + (256 - *(DWORD *)(Model + 176)) / ((Type == 1) ? 0.5 : Type - 1 );

				XNPC = XNPC - gRenderMap.DataMap.This_108 - 5;
				YNPC = YNPC - gRenderMap.DataMap.This_112 - 5;

				RenderBitMapColored(61521, XNPC, YNPC, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, 255));

				if( pCheckMouseOver((int) XNPC, (int) YNPC, (int) 10, (int) 10) )
				{
					pDrawToolTip((int) XNPC, (int) YNPC - 10, (char *)(Model + 56));
				}
			}
		}
	}
}

int TimerEvent;

void Interface::DrawMiniMap()
{
	if(gRenderMap.DataMap.ModelID == -1)
	{
		return;
	}

	if (this->MiniMapCheck() || this->CheckMap() 
		|| !MiniMap || this->CheckWindow(FullMap) 
		|| this->CheckWindow(FriendList) || gInterface.CheckWindow(SkillTree) 
		|| gInterface.CheckWindow(CashShop) || gInterface.CheckWindow(FastMenu))
	{
		return;
	}

	float DIRPointer;
	lpViewObj ObjectPointer;
	char Cord[256];
	float v8; // ST34_4@1
	float v9; // ST30_4@1
	float v10; // ST08_4@1
	float v11; // ST04_4@1
	int Type;
	int Multiplicador;
	int Scalado;

	ObjectPointer = &*(ObjectPreview*)(*(DWORD *)0x7BC4F04);
	DIRPointer =  180 + ( 45 * abs((signed int)(ObjectPointer->m_Model.Angle.Z / 45.0)));

	Type = gRenderMap.DataMap.Scale;

	DataMapLoad();

	v8 = (double) (( Type == 1 ) ? 0.25f : (( Type == 2 ) ? 0.5f : 1.0));
	v9 = (double) (( Type == 1 ) ? 0.25f : (( Type == 2 ) ? 0.5f : 1.0));

	v10 = (double) gRenderMap.DataMap.YSW_Minimap;
	v11 = (double) gRenderMap.DataMap.XSW_Minimap;

	float StartX = v11;
	float StartY = v10;
	float curX = pCursorX >= MAX_WIN_WIDTH ? 0 : pCursorX;
	float curY = pCursorY >= MAX_WIN_HEIGHT ? 0 : pCursorY;

	if (gInterface.IsWorkZone2(v11, v10, 95, 100, true))
	{
		if (!gRenderMap.Hoving && GetKeyState(VK_LBUTTON) & 0x8000) 
		{
			gRenderMap.Hoving = true;
			gRenderMap.mX = curX;
			gRenderMap.mY = curY;
		}	
	}
	if (gRenderMap.Hoving) 
	{
		StartX = v11 + (curX - gRenderMap.mX);
		StartY = v10 + (curY - gRenderMap.mY);
		StartX = StartX < 20 ? 20 : StartX;
		StartX = StartX > 485 ? 485 : StartX;
		StartY = StartY < 20 ? 20 : StartY;
		StartY = StartY > 300 ? 300 : StartY;
		gRenderMap.ultimoX = StartX;
		gRenderMap.ultimoY = StartY;
	}
	if (gRenderMap.Hoving && !(GetKeyState(VK_LBUTTON) & 0x8000)) 
	{
		gRenderMap.Hoving = false;
		gRenderMap.DataMap.XSW_Minimap = StartX;
		gRenderMap.DataMap.YSW_Minimap = StartY;
		gRenderMap.ultimoX = StartX;
		gRenderMap.ultimoY = StartY;
	}
	//-- Fondo
	RenderBitmap(31464, StartX - 1, StartY + 6, 125, 125, 0.3699999452, 0.0625, 0.5779999495, 0.2889999151, 1, 1, 0.0); //Minimapa abajo
	//-- Mapa
	RenderBitmap(31462, StartX + 14, StartY + 18, 95, 100, gRenderMap.DataMap.CurrentMoveX, gRenderMap.DataMap.CurrentMoveY, v9, v8, 1, 1, 0.0); //Minimapa abajo

	gRenderMap.DataMap.DropMoveUserX = gRenderMap.ultimoX + gRenderMap.DataMap.This_92 - gRenderMap.DataMap.This_108; //Minimapa abajo
	gRenderMap.DataMap.DropMoveUserY = gRenderMap.ultimoY + gRenderMap.DataMap.This_96 - gRenderMap.DataMap.This_112; //Minimapa abajo

	//-- Usuario
	if ( gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 0.0, gRenderMap.DataMap.Alpha);
		pDrawBarForm((double)gRenderMap.ultimoX, (double)gRenderMap.DataMap.DropMoveUserY, 4.0, 4.0, 0.0, 0);
		pGLSwitch();
	}
	else
	{
		sub_637E80( 32450,
			(double)gRenderMap.DataMap.DropMoveUserX,
			(double)gRenderMap.DataMap.DropMoveUserY,
			10.0,
			10.0, 
			DIRPointer,
			0.0,
			0.0,
			0.546875,
			0.546875);
	}

	float JCPartyCoordX;
	float JCPartyCoordY;

	for(int i = 0; i < pPartyMemberCount ; i++)
	{
		if( !strcmp(pGetStrutParty( i ).Name, pGetUserName) )
		{
			continue;
		}

		JCPartyCoordX = (double) StartX + gMiniMap.gPartyInfo[ i ].x / ((Type == 1) ? 0.5 : Type - 1 );
		JCPartyCoordY = (double) StartY + (256 - gMiniMap.gPartyInfo[ i ].y ) / ((Type == 1) ? 0.5 : Type - 1 );

		JCPartyCoordX = JCPartyCoordX - gRenderMap.DataMap.This_108 - 5;
		JCPartyCoordY = JCPartyCoordY - gRenderMap.DataMap.This_112 - 5;

		RenderBitMapColored(32450, JCPartyCoordX, JCPartyCoordY, 10.0, 10.0, 0.0, 0.0, 0.546875, 0.546875, pMakeColor(255, 255, 255, gRenderMap.DataMap.Alpha * 255));
	}

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, gRenderMap.DataMap.Alpha);

	DataViewPortMapLoad();
	int textAlpha;

	if ( gProtect.m_MainInfo.CustomInterfaceType == 4 || gProtect.m_MainInfo.CustomInterfaceType == 4 )
	{
		pSetBlend(true);
		glColor4f(1.0, 1.0, 1.0, gRenderMap.DataMap.Alpha);
		pDrawGUI(31608, gRenderMap.DataMap.XSW_Minimap_Frame, gRenderMap.DataMap.YSW_Minimap_Frame, 154.0, 162.0);
		pDrawGUI(31609, gRenderMap.DataMap.XSW_Time_Frame, gRenderMap.DataMap.YSW_Time_Frame, 134.0, 37.0);
		pGLSwitch();

		if(gMiniMap.CheckButtonPressed( 618, 240, 15, 15 ))
		{
			PlayBuffer(25, 0, 0);
			
			if (GetTickCount() >= TimerEvent + 200) 
			{
				if ( gRenderMap.DataMap.Scale == 1 ) 
				{
					gRenderMap.DataMap.Scale = 2;
				}
				else if ( gRenderMap.DataMap.Scale == 2 ) 
				{
					gRenderMap.DataMap.Scale = 3;
				}
				else if ( gRenderMap.DataMap.Scale == 3 ) 
				{ 
					gRenderMap.DataMap.Scale = 1; 
				}

				TimerEvent = GetTickCount();
			}
		}

		if(gMiniMap.CheckButtonPressed( 546, 239, 35, 20 ))
		{
			PlayBuffer(25, 0, 0);
			
			if (GetTickCount() >= TimerEvent + 200) 
			{
				if ( gRenderMap.DataMap.Alpha == 1.0 ) 
				{
					gRenderMap.DataMap.Alpha = (double) 0.90f;
				}
				else if ( gRenderMap.DataMap.Alpha == 0.90f ) 
				{
					gRenderMap.DataMap.Alpha = (double)0.80;
				}
				else if ( gRenderMap.DataMap.Alpha == 0.80f ) 
				{ 
					gRenderMap.DataMap.Alpha = (double)0.70f;
				}
				else
				{
					gRenderMap.DataMap.Alpha = (double)1.0f;
				}

				TimerEvent = GetTickCount();
			}
		}

		if ( gRenderMap.DataMap.Alpha == 1.0 ) 
		{
			textAlpha = 100;
		}
		else if ( gRenderMap.DataMap.Alpha == 0.90f ) 
		{
			textAlpha = 90;
		}
		else if ( gRenderMap.DataMap.Alpha == 0.80f ) 
		{ 
			textAlpha = 80;
		}
		else
		{
			textAlpha = 70;
		}

		
	}

	pGLSwitch();
	EnableAlphaTest(0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
#if DEBUG_CURSOR == 1
		char Info[100];
		wsprintf(Info, "X: %d", pCursorX);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
		pDrawText(pTextThis(), 546, 245, Info, 35, 0, (LPINT)3, 0);

		char Info2[100];
		wsprintf(Info2, "Y: %d", pCursorY);
		pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
		pSetTextColor(pTextThis(), 240, 240, 240, 255);
		pDrawText(pTextThis(), 546, 235, Info2, 35, 0, (LPINT)3, 0);
#endif

	//-- Carcasa Mapa
	//RenderBitmap(31465, v11 + 0, v10 + 6, 120, 120, 0.01299999747, 0.02999999747, 0.3105553985, 0.6109998822, 1, 1, 0.0); //Minimapa abajo
	RenderBitmap(31463, StartX - 1, StartY + 6, 124, 124, 0.3699999452, 0.0625, 0.5779999495, 0.2889999151, 1, 1, 0.0); //Minimapa abajo

	int x1, y1, w1, h1;

	//-- Boton Alejar
	x1 = StartX + 53; //Minimapa abajo
	y1 = StartY + 113; //Minimapa abajo
	w1 = 18;
	h1 = 18;



	RenderBitmap(31463, x1 - 5, y1 - 3, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0);

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		if(pCursorX > 563 && pCursorX < 580 && pCursorY > 378 && pCursorY < 395 )
		{
			pSetCursorFocus = true;
		}

		if( *(BYTE*)0x8793386 )
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.43160009804, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			PlayBuffer(25, 0, 0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				if ( gRenderMap.DataMap.Scale == 1 ) 
				{ 
					gRenderMap.DataMap.Scale = 2; 
				}
				else if ( gRenderMap.DataMap.Scale == 2 ) 
				{ 
					gRenderMap.DataMap.Scale = 3; 
				}

				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.43160009804, 0.1219998896, 0.06599189341, 1, 1, 0.0); //0,3689999878 + 0,06260011024
		}
		
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.43160009804, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Acercar
	x1 = StartX + 90; //Minimapa abajo
	y1 = StartY + 100; //Minimapa abajo
	//-- Carcaza Boton
	RenderBitmap(31463, x1 - 5, y1 - 3, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0); 

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		if( *(BYTE*)0x8793386 )
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.3689999878, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			PlayBuffer(25, 0, 0);

			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				if ( gRenderMap.DataMap.Scale == 3 ) 
				{ 
					gRenderMap.DataMap.Scale = 2; 
				}
				else if ( gRenderMap.DataMap.Scale == 2 ) 
				{ 
					gRenderMap.DataMap.Scale = 1; 
				}

				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.3689999878, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.3689999878, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}
	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		if(pCursorX > 600 && pCursorX < 617 && pCursorY > 365 && pCursorY < 382 )
		{
			pSetCursorFocus = true;
		}

		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, !*(BYTE*)(*(DWORD*)(0x00E8CB7C) + 0x08) ? 0.3689999878 : 0.5570000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, !*(BYTE*)(*(DWORD*)(0x00E8CB7C) + 0x08) ? 0.3689999878 : 0.5570000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, !*(BYTE*)(*(DWORD*)(0x00E8CB7C) + 0x08) ? 0.3689999878 : 0.5570000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton Config
	x1 = StartX + 15; //Minimapa abajo
	y1 = StartY + 13; //Minimapa abajo
	//-- Carcaza Boton
	RenderBitmap(31463, x1 - 5, y1 - 3, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0);

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{		
		if(pCursorX > 525 && pCursorX < 542 && pCursorY > 278 && pCursorY < 295 )
		{
			pSetCursorFocus = true;
		}

		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				if (gCustomMenu.CheckTestWindow())
				{
					gCustomMenu.CloseTestWindow();
				}
				else
				{
					gCustomMenu.OpenTestWindow();
				}
				gCustomMenu.OpenTestDelay = GetTickCount();
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}	
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.682000539, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}

	//-- Boton 3D - 100% BY DENIS
	x1 = StartX + 90; //Minimapa abajo
	y1 = StartY + 15; //Minimapa abajo
	//-- Carcaza Boton
	RenderBitmap(31463, x1 - 5, y1 - 3, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0);

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{
		if(pCursorX > 600 && pCursorX < 617 && pCursorY > 280 && pCursorY < 297)
		{
			pSetCursorFocus = true;
		}

		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				if(gInterface.boolVar == true)
				{
					gCamera.Restore();
					gCamera.Toggle();
					gInterface.boolVar = false;
				}
				else
				{
					gCamera.Toggle();
					gInterface.boolVar = true;
				}
				gInterface.timeboolVar = GetTickCount();
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.61940042876, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}
	
	if(gProtect.m_MainInfo.CustomInterfaceType != 3)
	{
		//-- Boton Armadura
		x1 = StartX + 53; //Minimapa abajo
		y1 = StartY - 1; //Minimapa abajo

		//-- Carcaza Boton
		RenderBitmap(31463, x1 - 5, y1 - 3, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0);

		if(pCheckMouseOver( x1, y1, w1, h1 ))
		{
			if(pCursorX > 563 && pCursorX < 580 && pCursorY > 264 && pCursorY < 281 )
			{
				pSetCursorFocus = true;
			}
		
			if( *(BYTE*)0x8793386 )
			{
				PlayBuffer(25, 0, 0);
				RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.80720075948, 0.1219998896, 0.06599189341, 1, 1, 0.0);
				if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
				{
					if (gServerSwitch.CheckTestWindow())
					{
						gServerSwitch.Click = false;
						gServerSwitch.CloseTestWindow();
					}
					else
					{
						gServerSwitch.Click = true;
						gServerSwitch.OpenTestWindow();
					}
					gServerSwitch.OpenTestDelay = GetTickCount();
					gRenderMap.DataMap.TimerEventVK = GetTickCount();
				}		
			}
			else
			{
				RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.80720075948, 0.1219998896, 0.06599189341, 1, 1, 0.0);
			}
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.80720075948, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}

	//-- Boton Batalla
	x1 = StartX + 15; //Minimapa abajo
	y1 = StartY + 102; //Minimapa abajo
	//-- Carcaza Boton
	RenderBitmap(31463, x1 - 5, y1 - 3, 26, 26, 0.8360000253, 0.4990000129, 0.1519999206, 0.073999919, 1, 1, 0.0);

	if(pCheckMouseOver( x1, y1, w1, h1 ))
	{	
		if(pCursorX > 525 && pCursorX < 542 && pCursorY > 367 && pCursorY < 384 )
		{
			pSetCursorFocus = true;
		}

		if( *(BYTE*)0x8793386 )
		{
			PlayBuffer(25, 0, 0);
			if( GetTickCount() >= gRenderMap.DataMap.TimerEventVK + 200 )
			{
				if(gInterface.boolVar == true)
				{
					gInterface.DrawMessage(1, "Auto PVP [OFF]");
					SetByte(0x0059AF53+2,1);
					SetByte(0x0059B248+2,1);
					gInterface.boolVar = false;
				}
				else
				{
					gInterface.DrawMessage(1, "Auto PVP [ON]");
					SetByte(0x0059AF53+2,0);
					SetByte(0x0059B248+2,0);
					gInterface.boolVar = true;
				}
				gInterface.timeboolVar = GetTickCount();
				gRenderMap.DataMap.TimerEventVK = GetTickCount();
			}
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.2499999553, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
		else
		{
			RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.1239999682, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
		}
	}
	else
	{
		RenderBitmap(31463, x1, y1, 18.29999924, 18.29999924, 0.0, 0.93240097996, 0.1219998896, 0.06599189341, 1, 1, 0.0);
	}
}


bool MiniMapFileCheck1(int Map) // OK
{
	if(Map - 1 == 30){return 0;}
	
	char Path[64];

	wsprintf(Path, "Data\\Custom\\Maps\\World%d.ozj", Map);

	int File = rFileOpen(Path, "rb");

	if ( File )
	{
		rFileClose(File);
		return 1;
	}
	else
	{
		return 0;
	}
}

void MiniMapLoad() // OK
{
	if (pMapNumber < MAX_MINI_MAP && pMapNumber != 30)
	{
		char buff[32];

		wsprintf(buff, "Custom\\Maps\\World%d.jpg", ( pMapNumber + 1 ));
		
		if (MiniMapFileCheck1( pMapNumber + 1 ) != 0)
		{
			gRenderMap.DataMap.ModelID = 31462;
			pLoadImage(buff, 31462, 0x2601, 0x2900, 1, 0);
		}
		else
		{
			gRenderMap.DataMap.ModelID = -1;
		}
	}
}

__declspec(naked) void LoadTexture()
{
	static DWORD Addr2_JMP = 0x0062F8A6;
	static DWORD Addr1_JMP = 0x0062F87C;
	static DWORD Map = 0x007AA331;

	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP-0x78]
		MOV Map, EAX
	}
	if ( Map == 74 || Map == 75 )
	{
		_asm
		{
			JMP[Addr2_JMP]
		}
	}
	else
	{
		MiniMapLoad();
		_asm
		{
			JMP[Addr1_JMP]
		}
	}
}

bool pDisabledMouseMAP(int x, int y, int w, int h)
{
	return 0;
}

void CMinimap::MiniMapload()
{
	//SetCompleteHook(0xE8, 0x0082B772, &pDisabledMouseMAP); //ok

	SetCompleteHook(0xE9, 0x0062F870, &LoadTexture); //ok
	//SetCompleteHook(0xE9, 0x0082ABA0, &CMinimap::MapRender);
}