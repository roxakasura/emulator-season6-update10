#include "stdafx.h"
#include "CustomRankUser.h"
#include "Defines.h"
#include "HealthBar.h"
#include "Interface.h"
#include "User.h"
#include "Util.h"
#include "Object.h"
#include "Protect.h"
#include "Import.h"

NEW_HEALTH_BAR gNewHealthBar[MAX_MAIN_VIEWPORT];

void ClearNewHealthBar() // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		gNewHealthBar[n].index = 0xFFFF;
		gNewHealthBar[n].type = 0;
		gNewHealthBar[n].rate = 0;
		gNewHealthBar[n].rate2 = 0;
	}
}

void InsertNewHealthBar(WORD index,BYTE type,BYTE rate,BYTE rate2) // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index == 0xFFFF)
		{
			gNewHealthBar[n].index = index;
			gNewHealthBar[n].type = type;
			gNewHealthBar[n].rate = rate;
			gNewHealthBar[n].rate2 = rate2;
			return;
		}
	}
}

NEW_HEALTH_BAR* GetNewHealthBar(WORD index,BYTE type) // OK
{
	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		if(gNewHealthBar[n].index != 0xFFFF)
		{
			if(gNewHealthBar[n].index == index && gNewHealthBar[n].type == type)
			{
				return &gNewHealthBar[n];
			}
		}
	}

	return 0;
}

void DrawNewHealthBar() // OK
{

	int PosX, PosY, LifeProgress, ShieldProgress;
	float LifeBarWidth = 80.0f;
	VAngle Angle;

	if (gProtect.m_MainInfo.DisablePartyHpBar == 1)
	{
		if (pPartyMemberCount > 0)
		{
			for (int j = 0; j < pPartyMemberCount; j++)
			{

				signed int PartyNummber = *((DWORD*)&pPartyListStruct + 8 * j + 7);

				DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),PartyNummber);

				if (ViewportAddress)
				{
					Angle.X = *(float*)(ViewportAddress+0x404);

					Angle.Y = *(float*)(ViewportAddress+0x408);

					Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

					pGetPosFromAngle(&Angle, &PosX, &PosY);

					pDrawImage(30019, (float)(PosX - 8), (float)(PosY - 32), 24.0f, 24.0f,0.0, 0.40000001f, 1.4f, 1.4f, 1, 1, 0.0);

				}
			}
		}
	}
	else if (gProtect.m_MainInfo.DisablePartyHpBar == 2)
	{

	}
	else
	{
		((void(*)())0x005BA770)();
	}
	

	for(int n=0;n < MAX_MAIN_VIEWPORT;n++)
	{
		DWORD ViewportAddress = ((DWORD(__thiscall*)(void*,DWORD))0x0096A4C0)(((void*(*)())0x00402BC0)(),n);

		gObjUser.m_Logo[n].Active = 0;

		if(!ViewportAddress)
		{
			continue;
		}

		if(*(BYTE*)(ViewportAddress+0x30C) == 0)
		{
			continue;
		}

		Angle.X = *(float*)(ViewportAddress+0x404);

		Angle.Y = *(float*)(ViewportAddress+0x408);

		Angle.Z = *(float*)(ViewportAddress+0x40C) + *(float*)(ViewportAddress+0x3E8) + 100.0f;

		pGetPosFromAngle(&Angle, &PosX, &PosY);

		if (*(BYTE*)(ViewportAddress+0x320) == 1) //Check User Type
        {
           	gObjUser.m_Logo[n].Active = 1;
			gObjUser.m_Logo[n].X = PosX;
			gObjUser.m_Logo[n].Y = PosY;
        }

		PosX -= (int)floor(LifeBarWidth / (double)2.0);

		PosY -= 16;

		NEW_HEALTH_BAR* lpNewHealthBar = GetNewHealthBar(*(WORD*)(ViewportAddress+0x7E),*(BYTE*)(ViewportAddress+0x320));
		char* name = (char*)(ViewportAddress+0x38);

		if(lpNewHealthBar == 0)
		{
			continue;
		}

		int LifePercent = lpNewHealthBar->rate / 10;
		int PercentualMonster = lpNewHealthBar->rate / 1;
		int ShieldPercent	= lpNewHealthBar->rate2/10;

		

		if (*(BYTE*)(ViewportAddress+0x320) == 1) //Check User Type
        {
			pSetBlend(true);
			glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)0.8);
			//pDrawBarForm((float)(PosX + 8), (float)(PosY), 60 + 2.0f, 10.0f, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);

			glColor3f(0.2f, 0.0, 0.0);
			pDrawBarForm((float)PosX + 10, (float)PosY + 6, 60, 2.0f, 0.0, 0);
		}
		else
		{
			pSetBlend(true);
			glColor4f(0.0f, 0.0f, 0.0f, 0.40f);
			pDrawBarForm((float)(PosX - 5), (float)(PosY - 10), LifeBarWidth + 10.0f, 15.0f, 0.0f, 0);
			pGLSwitchBlend();
			pGLSwitch();
			glColor3f(1.0, 1.0, 1.0);
			pSetBlend(false);

			gCustomRankUser.DrawFormat(eColorHealth, PosX, PosY - 8, (int)LifeBarWidth, 20, "%s [%d%%]", name, PercentualMonster);
		}

		pSetBlend(true);

		float Tamanho = (ShieldPercent>0)?Tamanho=10.0f:Tamanho=5.0f;

		glColor3f(0.2f, 0.0, 0.0);
		pDrawBarForm((float)PosX + 10, (float)PosY + 2, 60, 2.0f, 0.0, 0);

		if(LifePercent > 10)
		{
			LifeProgress = 10;
		}
		else
		{
			LifeProgress = LifePercent;
		}

		if(ShieldPercent > 10)
		{
			ShieldProgress = 10;
		}
		else
		{
			ShieldProgress = ShieldPercent;
		}

		glColor3f(0.98039216f, 0.039215688f, 0.0);

		for(int i = 0; i < LifeProgress; i++)
		{
			pDrawBarForm((float)(i * 6 + PosX + 10), (float)(PosY + 2), 6.0, 2.0, 0.0, 0);
		}

		if (ShieldPercent>0) 
		{
			glColor3f(0.98039216f, 5.039215688f, 0.0);

			for(int i = 0; i < ShieldProgress; i++)
			{
				pDrawBarForm((float)(i * 6 + PosX + 10), (float)(PosY + 6), 6.0, 2.0, 0.0, 0);
			}
		}

		pGLSwitch();
	}

	gCustomRankUser.DrawInfo();

	pGLSwitch();

	glColor3f(1.0, 1.0, 1.0);
}