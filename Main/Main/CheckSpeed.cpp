#include "stdafx.h"
#include "CheckSpeed.h"
#include "User.h"
#include "Defines.h"
#include "Object.h"
#include "TMemory.h"
#include "Import.h"

static DWORD ATTACK_RET = 0x00550A16;
static WORD CLASS = 0;
static WORD STR_SPEED = 0;
static WORD MAG_SPEED = 0;

__declspec(naked) void FixAttackSpeed()
{
	_asm
	{
		MOV EAX,DWORD PTR DS:[0x8128AC8]
		MOVZX ECX,WORD PTR DS:[EAX+0xB]
		MOV CLASS,CX
		MOVZX ECX,WORD PTR DS:[EAX+0x54]
		MOV STR_SPEED,CX
		MOVZX ECX,WORD PTR DS:[EAX+0x60]
		MOV MAG_SPEED,CX
	}
	gObjUser.MagickAttack = gObjUser.GetActiveSkill();
	if(STR_SPEED > 3276)
	{
		STR_SPEED = 3276;
	}
	if(MAG_SPEED > 3276)
	{
		MAG_SPEED = 3276;
	}
	/////////////////////////////////////////////////
    /*=====================SM======================*/	
	/////////////////////////////////////////////////
	if(CLASS == DarkWizard || CLASS == SoulMaster || CLASS == GrandMaster ){
		if(gObjUser.MagickAttack == SKILL_EVIL_SPIRIT || gObjUser.MagickAttack == 8	|| gObjUser.MagickAttack == 13	|| gObjUser.MagickAttack == 38 || gObjUser.MagickAttack == 39 || gObjUser.MagickAttack == SKILL_FLAME){
			if(MAG_SPEED > 450 && MAG_SPEED < 480)
			{
				MAG_SPEED = 450;
			}
			else if(MAG_SPEED > 600 && MAG_SPEED < 690)
			{
				MAG_SPEED = 600;
			}
			else if(MAG_SPEED > 850 && MAG_SPEED < 1105)
			{
				MAG_SPEED = 850;
			}
			else if(MAG_SPEED > 1350 && MAG_SPEED < 2355)
			{
				MAG_SPEED = 1350;
			}
			else if(MAG_SPEED > 2850)
			{
				MAG_SPEED = 2850;
			}
		}
		else if(gObjUser.MagickAttack == SKILL_INFERNO)
		{
			if(MAG_SPEED > 3276)
			{
				MAG_SPEED = 3276;
			}
		}
	}

	/////////////////////////////////////////////////
    /*=====================ELF=====================*/	
	/////////////////////////////////////////////////

	if( CLASS == Elf || CLASS == MuseElf || CLASS == HightElf )
	{
		if(gObjUser.MagickAttack == SKILL_TRIPLE_SHOT || gObjUser.MagickAttack == 414 || gObjUser.MagickAttack == 418)
		{
			if(STR_SPEED > 508)
			{
				STR_SPEED = 500;
			}
		}
		else if(gObjUser.MagickAttack == 52	|| gObjUser.MagickAttack == 51 || gObjUser.MagickAttack == 424 || gObjUser.MagickAttack == 416){
			if(STR_SPEED > 400)
			{
				STR_SPEED = 400;
			}
		}
	}

    /////////////////////////////////////////////////
    /*=====================MG======================*/	
	/////////////////////////////////////////////////

	if( CLASS == MagicGladiator || CLASS == DuelMaster ){
		if( gObjUser.MagickAttack == 55 || gObjUser.MagickAttack == 490 )
		{
			if(STR_SPEED > 1368)
			{
				STR_SPEED = 1368;
			}
		}
		if( gObjUser.MagickAttack == SKILL_EVIL_SPIRIT || gObjUser.MagickAttack == 8	|| gObjUser.MagickAttack == 13	|| gObjUser.MagickAttack == SKILL_FLAME ){
			if(MAG_SPEED > 450 && MAG_SPEED < 480)
			{
				MAG_SPEED = 450;
			}
			else if(MAG_SPEED > 600 && MAG_SPEED < 690)
			{
				MAG_SPEED = 600;
			}
			else if(MAG_SPEED > 850 && MAG_SPEED < 1105)
			{
				MAG_SPEED = 850;
			}
			else if(MAG_SPEED > 1350 && MAG_SPEED < 2355)
			{
				MAG_SPEED = 1350;
			}
			else if(MAG_SPEED > 2850)
			{
				MAG_SPEED = 2850;
			}
		}
		if(gObjUser.MagickAttack == SKILL_INFERNO)
		{
			if(MAG_SPEED > 3276)
			{
				MAG_SPEED = 3276;
			}
		}
	}

	/////////////////////////////////////////////////
    /*=====================DL======================*/	
	/////////////////////////////////////////////////

	if( CLASS == DarkLord || CLASS == LordEmperor){
		if(gObjUser.MagickAttack == SKILL_FIRE_SCREAM || gObjUser.MagickAttack == 518 )
		{
			if(STR_SPEED > 249 && STR_SPEED < 264)
			{
				STR_SPEED = 249;
			}
			else if(STR_SPEED > 324 && STR_SPEED < 367)
			{
				STR_SPEED = 324;
			}
			else if(STR_SPEED > 449 && STR_SPEED < 575)
			{
				STR_SPEED = 449;
			}
			else if(STR_SPEED > 699 && STR_SPEED < 1200)
			{
				STR_SPEED = 699;
			}
			else if(STR_SPEED > 1449)
			{
				STR_SPEED = 1449;
			}
		}
	}
	
	/////////////////////////////////////////////////
    /*=====================RF======================*/	
	/////////////////////////////////////////////////

	if( CLASS == Monk || CLASS == FirstMaster )
	{
		//FIX RF SKILL BEAST UPPERCUT
		if(gObjUser.GetActiveSkill() == 261 || gObjUser.GetActiveSkill() == 552 || gObjUser.GetActiveSkill() == 555)
		{
			SetDouble(&pFrameSpeed1, 0.0002000);
			SetDouble(&pFrameSpeed2, 0.0001000);	
		}
		else
		{
			SetDouble(&pFrameSpeed1, 0.0040000);
			SetDouble(&pFrameSpeed2, 0.0020000);	
		}
	}

	_asm
	{
		MOVZX ECX,WORD PTR DS:[STR_SPEED]
		MOV DWORD PTR SS:[EBP-0x28],ECX
		FILD DWORD PTR SS:[EBP-0x28]
		FMUL QWORD PTR DS:[0x0D27C88]              ; FLOAT 0.0010007200189989805
		FSTP DWORD PTR SS:[EBP-0x10]
		MOVZX EAX,WORD PTR DS:[MAG_SPEED]
		MOV DWORD PTR SS:[EBP-0x2C],EAX
		FILD DWORD PTR SS:[EBP-0x2C]
		FMUL QWORD PTR DS:[0x0D27C88]              ; FLOAT 0.0010007200189989805
		FSTP DWORD PTR SS:[EBP-0x0C]
		MOVZX EDX,WORD PTR DS:[MAG_SPEED]
		MOV DWORD PTR SS:[EBP-0x30],EDX
		FILD DWORD PTR SS:[EBP-0x30]
		FMUL QWORD PTR DS:[0x0D281C0]              ; FLOAT 0.002000000094994903
		FSTP DWORD PTR SS:[EBP-0x4]
		FLD DWORD PTR SS:[EBP-0x10]
		JMP ATTACK_RET
	}
}

static DWORD RETURN_attack2 = 0x0055157D;

__declspec(naked) void FixAttackSpeed2()
{
	_asm
	{
		MOVZX EDX,WORD PTR DS:[STR_SPEED]
		JMP RETURN_attack2
	}
}

void InitAttackSpeed()
{
	SetOp3(0x005509CE, (LPVOID)FixAttackSpeed, ASM::JMP);
	SetOp3(0x00551573, (LPVOID)FixAttackSpeed2, ASM::JMP);
}