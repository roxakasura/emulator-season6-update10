#pragma once
//-- dibujar


#define sub_772EA0		((int(__stdcall*)(float a5, int a6, int a7, int a8, int a9)) 0x00772EA0)
#define sub_813DC0		((int(__thiscall*)(DWORD * This, int Skill, float X, float Y, float W, float H)) 0x00813DC0)
//#define sub_813CA0		((void(__thiscall*)(DWORD * This)) 0x00813CA0)
//----- (00772EA0) --------------------------------------------------------
#define sub_4AD0E0		((signed int(__cdecl*)(unsigned __int16 a1)) 0x004AD0E0)
#define sub_4E65A0		((bool(__cdecl*)(signed int a1)) 0x004E65A0)
#define sub_4E8D80		((bool(__stdcall*)(signed int a1, signed int a2, signed int a3)) 0x004E8D80)
#define sub_4EAC90		((char(__stdcall*)(int a3)) 0x004EAC90)
#define sub_511110		((char(__stdcall*)(signed int a1, __int16 a2)) 0x00511110)
#define sub_5111D0		((char(__stdcall*)( signed int a4)) 0x005111D0)
#define sub_511290		((bool(__stdcall*)(__int16 a1, __int16 a2, int a3, int a4)) 0x00511290)
#define sub_587A80		((signed int(*)()) 0x00587A80)
#define sub_5B89C0		((bool(__cdecl*)(int a1)) 0x005B89C0)
#define sub_814F30		((void(__stdcall*)(int a1, float a2, float a3, float a4, float a5)) 0x00814F30)
#define sub_8DE4E0		((bool(*)()) 0x008DE4E0)
#define pBarExpDraw		((void(__cdecl*)()) 0x00810700)

//00815040
#define sub_815040		((int(__stdcall*)()) 0x00815040)

//--

void DrawCircle			(DWORD ModelID, float Arg2, float Arg3, float Arg4, float Arg5, float Arg6, float Arg7, float Arg8, float Arg9, int Arg10, int Arg11, int Arg12);

#define RenderNumber		((void(__cdecl*)(float a4, float a5, int a6, float a7)) 0x00791000)

#define World				*(int*)0x0E61E18

#define RenderBitmapUV				((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9)) 0x00638E90)

static char* MasterIconEx700	= "Interface\\GFx\\new_Master_Icon.tga";
static char* NonMasterIconEx700	= "Interface\\GFx\\new_Master_non_Icon.tga";



#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pFontBold				*(HGDIOBJ*)0x00E8C58C
#define pFontBigBold			*(HGDIOBJ*)0x00E8C590
#define pFontNormal2			*(HGDIOBJ*)0x00E8C594
#define sub_4C8640			((bool(__thiscall*)(void * This,char a2)) 0x4C8640)


#define RenderBitmap						((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)

#define pCheckMouseOver		((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)

#define PlayBuffer			((signed int(__cdecl*)(int a1, int a2, int a3)) 0x006D6C20)

#define sub_861200		((int(__thiscall*)(int This)) 0x861200)
#define pCheckEffectPlayer			((bool(__thiscall*)(void * This,char a2)) 0x004C8640)

void Render_772EA0(int ThisR);
char SkillSwitchBar(int This);
void SkillRavenSwitchBar(DWORD * a1);

#define pDrawInterfaceNumBer   ((double(__stdcall*)(float X, float Y, int num, float size)) 0x854FE0)

void InitInterEx();