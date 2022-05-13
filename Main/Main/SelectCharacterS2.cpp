#include "stdafx.h"
#include "SelectCharacterS2.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"
#include "Protect.h"

__declspec(naked) void SelectCharacterMap()
{
	static DWORD SelectCharacterMap_buff = 0x004D6C35;
	_asm
	{
	MOV DWORD PTR DS:[0xE61E18],0x36 //0x4A
	MOV EAX,DWORD PTR DS:[0xE61E18]
	jmp [SelectCharacterMap_buff]
	}
}

__declspec(naked) void SelectCharacterCord()
{
	BeginBitmap(); //ceu estrelado
	pDrawImage(0x700025, 1.0, 24.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
	pDrawImage(0x700026, 320.0, 24.0, 320.0, 320.0, 0, 0, 1.0, 1.0, 1, 1, 0.0);
	EndOpengl();

	static float D27B98 = -84.50000f;
	static float D25708 = -45.00000f;
	static float D27B94 = 8898.929687f;
	static float D27B90 = 18513.10938f;
	static float D27B8C = 550.5000f;
	static float D27B88 = -48.50000;
	static DWORD SelectCharacterCord_buff = 0x004D8B57;
	static DWORD SCCordJMP    = 0x004D8B42;
	_asm
	{
	//CMP DWORD PTR DS:[0xE609E8],0x4
	//JNZ SCCordJNZ
	FLD DWORD PTR DS:[D27B98]
	FSTP DWORD PTR DS:[0x87933D0]
	FLDZ
	FSTP DWORD PTR DS:[0x87933D4]
	FLD DWORD PTR DS:[D25708]
	FSTP DWORD PTR DS:[0x87933D8]
	FLD DWORD PTR DS:[D27B94]
	FSTP DWORD PTR DS:[0x87933DC]
	FLD DWORD PTR DS:[D27B90]
	FSTP DWORD PTR DS:[0x87933E0]
	FLD DWORD PTR DS:[D27B8C]
	FSTP DWORD PTR DS:[0x87933E4]
	JMP SCCordJMP
	FLD DWORD PTR DS:[D27B88]
	FSTP DWORD PTR DS:[0x87933D0]
	FLD DWORD PTR DS:[0x87933D0]
	FADD DWORD PTR DS:[0x8787D48]
	FSTP DWORD PTR DS:[0x87933D0]
	MOV EDX,DWORD PTR SS:[EBP-0x68]
	jmp [SelectCharacterCord_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ1()
{
	static float D41DCC = 7900.000f; //8008.000
	static float D41DC8 = 19100.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ21()
{
	static float D41DCC = 7900.000f; //8008.000
	static float D41DC8 = 19100.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ2()
{
	static float D41DC4 = 7900.000f; //7986.000
	static float D41DC0 = 19300.00f; //19145.00
	static float D254C0 = 75.00000f; //90.00000
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D206;
	_asm
	{
	FLD DWORD PTR DS:[D41DC4]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC0]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D254C0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ22()
{
	static float D41DC4 = 7900.000f; //7986.000
	static float D41DC0 = 19300.00f; //19145.00
	static float D254C0 = 75.00000f; //90.00000
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D447;
	_asm
	{
	FLD DWORD PTR DS:[D41DC4]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC0]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D254C0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ3()
{
	static float D41DBC = 8000.000f; //8046.000
	static float D41DB8 = 19450.00f; //19400.00
	static float D2B954 = 45.00000f; //75.00000
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D223;
	_asm
	{
	FLD DWORD PTR DS:[D41DBC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DB8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D2B954]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ23()
{
	static float D41DBC = 8000.000f; //8046.000
	static float D41DB8 = 19450.00f; //19400.00
	static float D2B954 = 45.00000f; //75.00000
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D464;
	_asm
	{
	FLD DWORD PTR DS:[D41DBC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DB8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D2B954]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ4()
{
	static float D41DB4 = 8150.00f; //8133.000
	static float D41DB0 = 19550.00f; //19645.00
	static float D2577C = 25.00000f; //60.00000
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D240;
	_asm
	{
	FLD DWORD PTR DS:[D41DB4]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DB0]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D2577C]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ24()
{
	static float D41DB4 = 8150.00f; //8133.000
	static float D41DB0 = 19550.00f; //19645.00
	static float D2577C = 25.00000f; //60.00000
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D481;
	_asm
	{
	FLD DWORD PTR DS:[D41DB4]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DB0]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D2577C]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ5()
{
	static float D41DAC = 8300.000f; //8282.000
	static float D41DA8 = 19600.00f; //19845.00
	static float D27BFC = 0.00000f; //35.00000
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D25D;
	_asm
	{
	FLD DWORD PTR DS:[D41DAC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DA8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27BFC]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ5_buff]
	}
}

__declspec(naked) void SelectCharacterS3CordPJ25()
{
	static float D41DAC = 8300.000f; //8282.000
	static float D41DA8 = 19600.00f; //19845.00
	static float D27BFC = 0.00000f; //35.00000
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D49E;
	_asm
	{
	FLD DWORD PTR DS:[D41DAC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DA8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27BFC]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ5_buff]
	}
}


void SCharacterS3()
{
	SetRange((LPVOID)0x004D6C26, 5, ASM::NOP);
    SetOp((LPVOID)0x004D6C26, (LPVOID)SelectCharacterMap, ASM::JMP);
	
	SetRange((LPVOID)0x004D8AF0, 5, ASM::NOP);//0x004D8AE7
    SetOp((LPVOID)0x004D8AF0, (LPVOID)SelectCharacterCord, ASM::JMP);

	//Posição Select Server
	if(gProtect.m_MainInfo.SelectCharacterType == 2 && gProtect.m_MainInfo.SelectCharacterSystem == 0)
	{	
		SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterS3CordPJ1, ASM::JMP);
		SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterS3CordPJ21, ASM::JMP);
	
		SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterS3CordPJ2, ASM::JMP);
		SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterS3CordPJ22, ASM::JMP);
	
		SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterS3CordPJ3, ASM::JMP);
		SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterS3CordPJ23, ASM::JMP);
	
		SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterS3CordPJ4, ASM::JMP);
		SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterS3CordPJ24, ASM::JMP);
	
		SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterS3CordPJ5, ASM::JMP);
		SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterS3CordPJ25, ASM::JMP);

		if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
		{
			SetByte((LPVOID)0x0057F0FC, 0xE9);
			SetByte((LPVOID)0x0057F0FD, 0x4A);
			SetByte((LPVOID)0x0057F0FE, 0x01);
			SetByte((LPVOID)0x0057F0FF, 0x00);
			SetByte((LPVOID)0x0057F100, 0x00);
			SetByte((LPVOID)0x0057F101, 0x90);
		}
	}
}