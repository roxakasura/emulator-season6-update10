#pragma once

void RegeditData(BYTE data);
void ChangeSize(int a1, int a2);
void ItemSizeFixLoad();
//
void FenrirLoad();
void ValorFenrir001();
void ValorFenrir002();
//

#define sub_630BC0			((bool(*)()) 0x630BC0)
#define sub_596AC0			((void(__thiscall*)(int a1)) 0x00596AC0) //1
#define sub_482B70          ((int(*)()) 0x00482B70)
#define sub_407B20			((int(*)()) 0x00407B20)
#define sub_785870			((void(__thiscall*)(DWORD , int a2, int a3, int a4, int a5)) 0x00785870)
#define sub_861AC0          ((int(__thiscall*) (DWORD)) 0x00861AC0)
#define sub_7F0D40          ((void(__thiscall*) (DWORD)) 0x007F0D40)
#define sub_7F0C80			((void(__thiscall*)(DWORD , int a2, int a3, int a4)) 0x007F0C80)
#define sub_830B70			((void(__thiscall*)(DWORD , int a2, int a3, int a4)) 0x00830B70)
#define dword_81C0380           *(DWORD*)0x81C0380
#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pFontBold				*(HGDIOBJ*)0x00E8C58C
#define pFontBigBold			*(HGDIOBJ*)0x00E8C590
#define pFontNormal2			*(HGDIOBJ*)0x00E8C594

extern DWORD RESOLUTION;
extern int FontHeight;
extern int MountSize;