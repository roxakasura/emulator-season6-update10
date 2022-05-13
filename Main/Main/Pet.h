#pragma once

#include "Object.h"
#include "Defines.h"
#include "zzzmathlib.h"
#define PI 3.14159265
//Pet
#define pMaybeDrawPetHP				((char(__stdcall*)(int a1, int a2)) 0x7DFDB0)
#define sub_50D100					((size_t(__cdecl*)(char * a1, char * a2, ...)) 0x50D100)
#define	sub_7DFA60					((int(__stdcall*)(signed int PosX, signed int PosY, int a3, signed int a4, signed int a5, char a6)) 0x7DFA60)
#define sub_501790					((char(__cdecl*)(int a1, char a2)) 0x501790)
#define sub_540C30					((int(__cdecl*)(float, float, float, float)) 0x540C30)
#define sub_540EA0					((int(__cdecl*)(float, float a2, float)) 0x540EA0)
#define sub_959CE0					((int(__cdecl*)(DWORD, DWORD)) 0x959CE0)
#define sub_95A1E0					((int(__cdecl*)(DWORD a1, DWORD a2, float *a3)) 0x95A1E0)
#define sub_541460					((void(__cdecl*)(int a1)) 0x541460)
#define sub_4CDA10					((LPVOID(*)())0x4CDA10)
#define sub_969C50					((int(__thiscall*)(LPVOID This, signed int a2)) 0x969C50)
#define sub_5D6700					((int(__cdecl*)(unsigned __int8 a1, unsigned __int8 a2)) 0x5D6700)
#define sub_5422E0					((bool(__cdecl*)(__int16 a1)) 0x5422E0)
#define sub_542310					((__int16(__cdecl*)(int a1, int a2, char a3)) 0x542310)
#define sub_545030					((int(__thiscall*)(LPVOID This, int a2, DWORD *a3, DWORD *BMD, char a5)) 0x545030)

#define sub_4DB1C0					((bool(__cdecl*)(signed int a1))0x4DB1C0)
#define sub_4C8640					((bool(__thiscall*)(void * This,char a2)) 0x4C8640)
#define sub_4DB250					((int(__cdecl*)()) 0x4DB250)
#define sub_4E44A0					((bool(__thiscall*)(int This)) 0x4E44A0)
#define sub_7293F0					((char*(__cdecl*)(int a1, int a2, int a3, int a4, int a5, char a6, int a7)) 0x7293F0)
#define sub_5039A0					((void(__cdecl*)(int a1, int a2)) 0x5039A0)
#define sub_72D1B0					((void(__cdecl*)(int a1, int a2, int a3, int a4, int a5, int a6, float a7, __int16 a8, __int16 a9, char a10, int a11, int a12, __int16 a13)) 0x72D1B0)
#define sub_542280					((bool(__cdecl*)(__int16 a1)) 0x542280)
#define sub_545180					((char(__thiscall*)(void * This, int a2, int a3, int a4, float a5, int a6, int a7)) 0x545180)
#define sub_5CA0D0					((void(__cdecl*)( int a1,  int a2, int a3, int a4, int a5, int a6, char a7)) 0x5CA0D0)
#define sub_9250E0					((int(__thiscall*)(int This, int a1, int a2, int a3, int a4, int a5, int a6)) 0x9250E0)
#define sub_501700					((DWORD(__cdecl*)(DWORD, DWORD, DWORD, DWORD, DWORD)) 0x501700)
#define sub_57D9A0					((DWORD(__cdecl*)(DWORD)) 0x57D9A0)
#define sub_58AA80					((DWORD(__cdecl*)(DWORD)) 0x58AA80)
#define sub_4E6670					((DWORD(__cdecl*)(DWORD)) 0x4E6670)
#define sub_57F020					((DWORD(__cdecl*)(DWORD)) 0x57F020)

#define sub_4F8C30					((DWORD(__cdecl*)(DWORD)) 0x4F8C30)
#define sub_534B40					((DWORD(__cdecl*)(DWORD)) 0x534B40)
#define sub_4F94A0					((DWORD(__cdecl*)(DWORD)) 0x4F94A0)
#define sub_57FC30					((int(__cdecl*)(BYTE CharSet)) 0x57FC30)
#define sub_587500					((DWORD(__cdecl*)(char)) 0x587500)
#define sub_402BC0					((int(*)())0x402BC0)

#define sub_405230					((int(__cdecl*)(char a1)) 0x405230)
#define sub_4F9930					((int(__cdecl*)(char *a1)) 0x4F9930)
#define sub_4F8B80					((int(__cdecl*)(int a1)) 0x4F8B80)
#define sub_4E65A0					((bool(__cdecl*)(signed int a1)) 0x4E65A0)
#define sub_4FA780					((int(__thiscall*)(int This, int a2)) 0x4FA780)
#define sub_5013B0					((char(__cdecl*)(int a1, int a2, int a3, int a4, int a5)) 0x5013B0)
#define sub_4EFF70					((void(__cdecl*)(LPVOID This,int a1)) 0x4EFF70)
#define sub_96A4C0					((int(__thiscall*)(int This, signed int a2)) 0x96A4C0)
#define sub_57FD90					((void(__cdecl*)(int a1, BYTE * a2, int a3, int a4)) 0x57FD90)
#define sub_558630					((void(__cdecl*)(int a1, int a2, int a3)) 0x558630)
#define SLODWORD(x)					(*((DWORD*)&(x)))
#define sub_771310					((int(__cdecl*)(int a1, int a2, float a3, vec3_t a4, int a5, float a6, int a7)) 0x771310)
#define sub_771310_					((int(__cdecl*)(int a1, vec3_t a2, float a3, vec3_t a4, int a5, float a6, int a7)) 0x771310)
#define sub_95A340					((int(__cdecl*)(int a1, int a2, int a3)) 0x95A340)
#define sub_5440B0					((int(__fastcall*)(int a1, int a2, int a3, float a4, float a5, __int16 a6, int a7, int a8, char a9, char a10)) 0x5440B0)
#define sub_922D50					((signed int(__thiscall*)(int This, unsigned int a2)) 0x922D50);
#define sub_580BB0					((int(__cdecl*)(DWORD, DWORD)) 0x580BB0)
#define sub_4CD7F0					((int(__stdcall*)(DWORD,DWORD)) 0x4CD7F0)
#define pDrawMonsterEffect			((char(__cdecl*)(int a1, int a2, int a3)) 0x8C7790)
#define sub_5D81B0					((int(__cdecl*)(float, float)) 0x5D81B0)
#define sub_544E60					((void(__thiscall*)(LPVOID This, vec3_t a2, int a3, signed int a4, int a5)) 0x544E60)
#define sub_9593B0					((int(__stdcall*)(HDC This, LPCSTR lpMultiByteStr, int, LPSIZE psizl)) 0x9593B0)
#define pSetTextSize				((int(__thiscall*)(LPVOID This, HFONT a2)) 0x420120)
#define pFontBold					*(DWORD*)0xE8C58C
#define sub_8CBA40					((int(__cdecl*)(int, int, float, float, float, float, GLfloat *v)) 0x8CBA40) //Effect? 32141
#define sub_5DAD80					((int(__cdecl*)(int, float, float, float, float, GLfloat *v, float, float, float, char)) 0x5DAD80) //effect ?32313
#define sub_56EFC0					((int(__cdecl*)(int, int, float, int, float, float, float)) 0x56EFC0)
#define sub_4E65C0					((bool(__cdecl*)(signed int MapNumber)) 0x4E65C0)
#define sub_89CB00					((LPVOID(*)())0x89CB00)
#define sub_89CB90					((int(__thiscall*)(LPVOID This)) 0x89CB90)
#define pPreviewPetThis				*(DWORD*)0x007BC4F04
#define LODWORD(h)					((DWORD)(__int64(h) & __int64(0xffffffff)))

#define sub_9CFA0D				((int(*)()) 0x9CFA0D)
#define sub_5DBA10				((char(__cdecl*)(float a1, float a2, float a3)) 0x5DBA10)
#define pObjectMaxBug			((int(__cdecl*)(int a1, unsigned __int8 a2, int a3, int a4)) 0x5EBBB0)
#define sub_9CFB8D            ((int(*)()) 0x009CFB8D)

#define pGetModel	((LPVOID(__thiscall*)(LPVOID This, signed int a2)) 0x00969C50)
#define pModelThis	((LPVOID(*)())0x004CDA10)

//-- custompet
#define CC_MAP_RANGE(x)				(((x)<18)?0:((x)>23)?(((x)==53)?1:0):1)
#define pGetPetInfo					((int(__cdecl*)(char a1)) 0x4F9930)
#define sub_4DB230					((int(*)())0x4DB230)
#define sub_9253D0					((int(__thiscall*)(int This,int a1, short a2)) 0x9253D0)
#define sub_5012D0					((DWORD(__cdecl*)(DWORD)) 0x5012D0)
#define pActionPlayerSend			((char(__cdecl*)(int ViewPortId,int ActionId,bool Some)) 0x00542310)
#define sub_5509C0					((int(__cdecl*)()) 0x005509C0)

//chamadas
int sub_959FA0(int a1, int a2, int a3);
__int16 PlayerAnimationMonturaSkill (int a3);

#define MAX_LOOTOBJECT	1024 // 1000

class CustomPet
{
public:
	CustomPet();
	virtual ~CustomPet();
	void Load();
	static void		PreviewCharSet(int ObjectIndex, BYTE * CharSet, lpViewObj Object, int Mode);
	static void		PetsMovement(int a1, char a2);
	static char		PetHPBar(int a1, int a2);
	static void		RefreshViewPortItem(int a1);
	static void		PetFollowCharacter(int a1, float MaxPos);
	static void		SetPosition(int a1, int a2, int a3, int a4, VAngle* a5, int a6, char a7);
//	static char		CreateEffect(int a4, char a5);

	DWORD PetTickCount;
};

extern CustomPet gCustomPet;

