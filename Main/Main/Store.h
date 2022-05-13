#pragma once

void StoreFixload();

extern char StoreName[36];

#define sub_40FC80		((char(__thiscall*)(int a1)) 0x40FC80)
#define pDrawText_P		((int(__thiscall*)(int This, int a2, int a3, int a4, int a5, int a6, int a7, int a8)) 0x00420150)

#define sub_9CEBF0                  ((signed int(__thiscall*)(double a1)) 0x009CEBF0)

// PvP·¹º§
#define PVP_HERO2		1
#define PVP_HERO1		2
#define PVP_NEUTRAL		3
#define PVP_CAUTION		4
#define PVP_MURDERER1	5
#define PVP_MURDERER2	6