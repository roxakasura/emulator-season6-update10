#include "stdafx.h"
#include "SelectServerS2.h"
#include "Import.h"
#include "Interface.h"
#include "TMemory.h"
#include "Util.h"
#include "Offset.h"
#include "Interface.h"
#include "Defines.h"
#include "CustomMessage.h"

void SelectCharS2(int a1, DWORD *a2)
{
	  if ( pMapNumber == 55)
	  {
		  glColor3f(1.0, 1.0, 1.0);
		  BeginBitmap();
		  pDrawImage(500021, 1.0, 24.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		  pDrawImage(500022, 320.0, 24.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
		  EndOpengl();
		  SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		  SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		  *(float*)0xE61E3C = 330000.0;
		  *(float*)0x87933D0 = -96.5;
		  *(float*)0x87933D4 = 0.0;
		  *(float*)0x87933D8 = -36.0;
		  *(float*)0x87933DC = 12778.0;
		  *(float*)0x87933E0 = 12678.0;
		  *(float*)0x87933E4 = 579.0;	
		  *(float*)0xE61E40 = 35.0;
	  }
}

void MULOGOS2()
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
		pDrawImage(531019, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		pSetBlend(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		pDrawImage(531018, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		//
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);
	//	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 460, 150, 3, "RoxGaming © 2021");
	//	gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 470, 763, 3, "RazeMU");
		gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 378, 470, 150, 3, gCustomMessage.GetMessageB(456));
		gInterface.DrawFormat(eWhite, (MAX_WIN_WIDTH / 2) - 74, 470, 150, 3, gCustomMessage.GetMessageB(454));
	}
}

void sub_4D5EC0()
{
	MULOGOS2();	
	sub_4D5EC0R();

	float x,y;

	if(pWinWidth <= 800)
	{
		x = -80.0;
		y = -20.0;
	}
	else if(pWinWidth >= 1024 && pWinWidth <= 1279)
	{
		x = -37.0;
		y = 0.0;
	}
	else if(pWinWidth == 1280)
	{
		x = -7.5;
		y = 17.0;
	}
    else
	{
		x = 0.0;
		y = 0.0;
	}

	if(*(int*)0x87935A4 == 0)
	{
		BeginBitmap();
		RenderBitmap(88821, 207 + x, 171 + y, 67.0, 65.0, 0, 0, 0.26983125, 0.72983125, 0.0, 1, 0.0);
		EndOpengl();
	}
	else
	{
		/*	  Vazio  	*/
	}
}

void SelectServerBarRemakeS2(LPVOID This, BYTE r, BYTE g, BYTE b, BYTE h)
{
	float x,y;

	if(pWinWidth <= 800)
	{
		x = -80.0;
		y = -20.0;
	}
	else if(pWinWidth >= 1024 && pWinWidth <= 1279)
	{
		x = -37.0;
		y = 0.0;
	}
	else if(pWinWidth == 1280)
	{
		x = -7.5;
		y = 17.0;
	}
    else
	{
		x = 0.0;
		y = 0.0;
	}

	if(*(int*)0x87935A4 == 0)
	{
		RenderBitmap(88821, 207 + x, 170.5 + y, 67.0, 95.0, 0, 0, 0.26983125, 1.0, 0.0, 1, 0.0);
	}
	else
	{
		/*	  Vazio  	*/
	}

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
}

void InitSelectServerS2()
{
	SetCompleteHook(0xE8, 0x004D7EB1, &sub_4D5EC0);
	SetCompleteHook(0xE8, 0x004D76FB, &SelectCharS2);//Select Server
	SetCompleteHook(0xE8, 0x004D79C3, &SelectCharS2);//Select Server
	//SetCompleteHook(0xE8, 0x004D7D13, &SelectServerBarRemakeS2); 
	SetDword((LPVOID)0x004D75F0, 55);
	SetDword((PVOID)(0x004D7E33+1),30000); //remove principais texto do select server
	SetDword((PVOID)(0x004D7DAD+1),30000); //remove principais texto do select server
	SetDword((PVOID)(0x004D7D18+1),30000); //remove principais texto do select server
}