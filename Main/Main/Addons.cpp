#include "StdAfx.h"
#include "Addons.h"
#include "ChatExpanded.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"
#include "Interface.h"
#include "Util.h"
#include "User.h"
#include "Protect.h"

CAddons gAddons;

void CAddons::Load()
{
	SetOp((LPVOID)0x00425472,(LPVOID)this->SetPosition,ASM::CALL);
	SetOp((LPVOID)0x00425484,(LPVOID)this->SetPosition,ASM::CALL);

	if(gProtect.m_MainInfo.SelectBarExp == 1)
	{	
		gLevelExperience[0] = 0;

		int over = 1;

		for(int n=1;n <= 1000;n++)
		{
			this->gLevelExperience[n] = (((n+9)*n)*n)*10;

			if(n > 255)
			{
				gLevelExperience[n] += (((over + 9)*over)*over) * 2 + (over + 9)*over*over * 1;
				over++;
			}
		}
			this->m_MasterLevelExperienceTable[0] = 0;

		QWORD var1 = 0;
		QWORD var2 = 0;
		QWORD var3 = 0;

		for(int n=1;n < (1001);n++)
		{
			var1 = n+400;

			var3 = ((((var1+9)*var1)*var1)*10);

			var2 = var1-255;

			var3 += ((((var2+9)*var2)*var2)*1000);

			var3 = (var3-3892250000)/2;

			this->m_MasterLevelExperienceTable[n] = var3;

		}
		SetOp((LPVOID)0x0080F865,(LPVOID)this->DrawExpBar,ASM::CALL);
	}
//	SetOp((LPVOID)0x007E049E,(LPVOID)this->BowsText,ASM::CALL);
}

int CAddons::SetPosition(DWORD This,int X,int Y) // ok
{
	Y = 429;

	return pSliderSetPosition(This,X,Y);
}

int CAddons::BowsText(int X, int Y, LPCTSTR Text)
{
	X = 0;
	Y = 18;
	return pDrawText(pTextThis(), X, Y, Text, 0, 0, (LPINT)1, 0);
}

void CAddons::DrawExpBar()
{
	if (!gObjUser.lpPlayer || !gObjUser.lpViewPlayer)
		return;

	glColor3f(0.91000003, 0.81, 0.60000002);

	float ReduceRate	= 0.0;

	if(pIsMaster(*(BYTE*)(0x008128AC8 + 11)) == 1)
	{
		long double PreviousExp = pMasterExp - (__int64)gAddons.m_MasterLevelExperienceTable[pMasterLevel];
		long double TotalExp    = pMasterNextExp - (__int64)gAddons.m_MasterLevelExperienceTable[pMasterLevel];

		if ( TotalExp > 0 )
			ReduceRate = (TotalExp - PreviousExp) / TotalExp;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

		float Width		= 198.0;
		float Height	= 4.0;
		float PosX		= 221.0;
		float PosY		= 439.0;

		float FinalW	= Width - ReduceRate * Width;

		pDrawBarForm(PosX, PosY, FinalW, Height, 0.0, 0);

		sub_791000(426.0, 436.0, (int)pMasterLevel, 0.9);

		glColor3f(1.0, 1.0, 1.0);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX+100,(int)PosY-15, "Experience: %I64u/%I64u %I64u",pMasterExp,pMasterNextExp,gAddons.m_MasterLevelExperienceTable[pMasterLevel]);
		}
	}
	else
	{
		double PreviousExp = gObjUser.lpPlayer->Experience - gAddons.gLevelExperience[gObjUser.lpPlayer->Level-1];
		double TotalExp    = gObjUser.lpPlayer->NextExperience - gAddons.gLevelExperience[gObjUser.lpPlayer->Level-1];

		if ( TotalExp > 0 )
			ReduceRate = (TotalExp - PreviousExp) / TotalExp;

		if (ReduceRate < 0)
			ReduceRate = 1.0;

		float Width		= 198.0;
		float Height	= 4.0;
		float PosX		= 221.0;
		float PosY		= 436.0;

		float FinalW	= Width - ReduceRate * Width;

		pDrawBarForm(PosX, PosY, FinalW, Height, 0.0, 0);

		sub_791000(426.0, 433.0, (int)gObjUser.lpPlayer->Level, 0.9);

		glColor3f(1.0, 1.0, 1.0);

		if ( sub_790B10(PosX, PosY, Width, Height) == 1 )
		{
			gInterface.DrawToolTip((int)PosX+100,(int)PosY-15, "Experience: %d/%d",gObjUser.lpPlayer->Experience,gObjUser.lpPlayer->NextExperience);
		}
	}


}