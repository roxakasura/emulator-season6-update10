#include "stdafx.h"
#include "Fix.h"
#include "Util.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"
#include "User.h"
#include "Interface.h"

cFix gFix;

void cFix::Load()
{
	SetOp((LPVOID)0x00559539, (LPVOID)this->CalculateAttackSpeed, ASM::CALL);
}

void cFix::CalculateAttackSpeed(lpCharObj lpUser, LPVOID EDX)
{
		//pGetAttackSpeed();

		//if (lpUser->AttackSpeed > 3000)
		//{
		////lpUser->MagicSpeed = (WORD)800 + *(DWORD*)0x986C1CC;
		////gVisualFix.AttackSpeed = lpUser->AttackSpeed;
		//lpUser->AttackSpeed = (WORD)3000 + *(DWORD*)0x986C1CC;
		//
		//}

	switch (lpUser->Class)
	{
		//gInterface.DrawFormat(eWhite180,  80, 80, 45, 1, "%f %f", pFrameSpeed1, pFrameSpeed2);
		
		case eClassCode::Monk:
		case eClassCode::FirstMaster:
		{			
			//FIX RF SKILL BEAST UPPERCUT
			if(gObjUser.GetActiveSkill() == 261 || gObjUser.GetActiveSkill() == 552 || gObjUser.GetActiveSkill() == 555)
			{
				SetDouble(&pFrameSpeed1, 0.0002000);
				SetDouble(&pFrameSpeed2, 0.0001000);

				//lpUser->AttackSpeed = 10;

				//SetOp((LPVOID)0x00559539, (LPVOID)lpUser->AttackSpeed, ASM::CALL);
				
			}
			else
			{
				SetDouble(&pFrameSpeed1, 0.0040000);
				SetDouble(&pFrameSpeed2, 0.0020000);
				
			}	
		}

	}
	

}

