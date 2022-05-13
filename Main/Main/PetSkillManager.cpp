#include "stdafx.h"
#include "CustomEarthQuakeSkill.h"
#include "CustomSCharAnimate.h"
#include "PetSkillManager.h"
#include "Object.h"
#include "Offset.h"
#include "zzzmathlib.h"
#include "Util.h"
#include "CustomPet.h"
#include "Import.h"
#include "User.h"

#define pAngleMatrix2			((int(__cdecl*)(vec3_t a1, vec34_t a2)) 0x959CE0)
#define pVectorRotate2			((int(__cdecl*)(vec3_t a1, vec34_t a2, vec3_t a3)) 0x95A1E0)
#define pMoveSceneFrame			*(int*)0x00E8CB20
#define pEarthQuake				*(float*)0x08787D48
#define pCreateEffect			((int(__cdecl*)(int a4, vec3_t Bone1, float* a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)

void LoadSkillFenrir()
{
	//MemorySet(0x005E0BE0, 0x90, 0x5); //raios ao entorno
	//MemorySet(0x005E0C1D, 0x90, 0x5); //raios ao entorno

	//SetCompleteHook(0xE8, 0x005E0BE0, &FenrirLight);
	//SetCompleteHook(0xE8, 0x005E0C1D, &FenrirLight);

	MemorySet(0x005E0B0C, 0x90, 60); //raios ao redor
	MemorySet(0x0072FF28, 0x90, 56); //plasma
	SetCompleteHook(0xE9, 0x005E0B0C, &FenrirPurpleSkill);
	SetCompleteHook(0xE9, 0x0072FF28, &FenrirPurpleSkill2);
}

__declspec(naked) void FenrirPurpleSkill2()
{
	static float D23788 = (94.0 / 255.0);
	static float D237882 = (255.0 / 255.0);
	//static float D23510 = (255.0 / 255.0);

	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP - 8]
		CMP DWORD PTR DS : [EAX + 0xC], 2
		JNZ Next
		MOV ECX, DWORD PTR SS : [EBP - 8]
		MOV DWORD PTR DS : [ECX + 8], 0x7D86
		MOV EDX, DWORD PTR SS : [EBP - 8]
		FLD DWORD PTR DS : [0xD23788]
		FSTP DWORD PTR DS : [EDX + 0x48]
		MOV EAX, DWORD PTR SS : [EBP - 8]
		FLD DWORD PTR DS : [0xD23788]
		FSTP DWORD PTR DS : [EAX + 0x4C]
		MOV ECX, DWORD PTR SS : [EBP - 8]
		FLD1
		FSTP DWORD PTR DS : [ECX + 0x50]
		MOV EDI, 0x00730079
		JMP EDI

	Next :
		MOV EAX, DWORD PTR SS : [EBP - 8]
		CMP DWORD PTR DS : [EAX + 0xC], 8
		JNZ Exit
		MOV ECX, DWORD PTR SS : [EBP - 8]
		MOV DWORD PTR DS : [ECX + 8], 0x7D86
		MOV EDX, DWORD PTR SS : [EBP - 8]
		FLD DWORD PTR DS : [D23788]
		FSTP DWORD PTR DS : [EDX + 0x48]
		MOV EAX, DWORD PTR SS : [EBP - 8]
		FLD DWORD PTR DS : [D237882]
		FSTP DWORD PTR DS : [EAX + 0x4C]
		MOV ECX, DWORD PTR SS : [EBP - 8]
		FLD1
		FSTP DWORD PTR DS : [ECX + 0x50]
		MOV EDI, 0x00730079
		JMP EDI
	Exit :
		MOV EDI, 0x0072FF60
		JMP EDI
	}
}


__declspec(naked) void FenrirPurpleSkill()
{
	static float D27CA4 = (94.0/255.0);
	static float D27CA42 = (255.0 / 255.0);
	static float D23510 = (0.0 / 255.0);

	_asm
	{
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		CMP DWORD PTR DS : [EAX + 0x30], 0x182
		JNZ Next
		FLD DWORD PTR DS : [0xD27CA4]
		FSTP DWORD PTR SS : [EBP - 0xA8]
		FLD DWORD PTR DS : [0xD27CA4]
		FSTP DWORD PTR SS : [EBP - 0xA4]
		FLD DWORD PTR DS : [0xD23510]
		FSTP DWORD PTR SS : [EBP - 0xA0]
		MOV DWORD PTR SS : [EBP - 0x9C], 0x2
		MOV EDI, 0x005E0BAA
		JMP EDI

	Next :
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		CMP DWORD PTR DS : [EAX + 0x30], 0x1F8B
		JNZ Next1
		FLD DWORD PTR DS : [D27CA4]
		FSTP DWORD PTR SS : [EBP - 0xA8]
		FLD DWORD PTR DS : [D27CA42]
		FSTP DWORD PTR SS : [EBP - 0xA4]
		FLD DWORD PTR DS : [D23510]
		FSTP DWORD PTR SS : [EBP - 0xA0]
		MOV DWORD PTR SS : [EBP - 0x9C], 0x8
		MOV EDI, 0x005E0BAA
		JMP EDI

	Next1 :
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		CMP DWORD PTR DS : [EAX + 0x30], 0x1F8A
		JNZ Exit
		FLD DWORD PTR DS : [D27CA4]
		FSTP DWORD PTR SS : [EBP - 0xA8]
		FLD DWORD PTR DS : [D27CA42]
		FSTP DWORD PTR SS : [EBP - 0xA4]
		FLD DWORD PTR DS : [D23510]
		FSTP DWORD PTR SS : [EBP - 0xA0]
		MOV DWORD PTR SS : [EBP - 0x9C], 0x8
		MOV EDI, 0x005E0BAA
		JMP EDI

	Exit :
		MOV EDI, 0x005E0B48
		JMP EDI
	}
}


void FenrirLight(int a4, vec3_t Bone1, float* a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)
{
	vec3_t Color;

	Color[0] = 255;
	Color[1] = 0;
	Color[2] = 162;

	pCreateEffect(a4, Bone1, a6, Color, a8, a9, a10, a11, a12, a13, a14, a1); //retorna ao valor original

}