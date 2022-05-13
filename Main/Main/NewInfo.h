#pragma once

#include "Protocol.h"
#include "Object.h"

#define CRenderItem3D							((int(__cdecl*)(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp)) 0x005CF310)
#define GetInstance								((int(__cdecl*)()) 0x00861110)
#define GetUI3D									((int(__thiscall*)(int thisa))0x00861AA0)
#define RenderItemInfo_							((void(__thiscall*)(int thisa, int sx,int sy,int ip,bool Sell, int Inventype, bool bItemTextListBoxUse)) 0x007E3E30)
#define CharacterMachine_Equipment( x )			*(DWORD*)0x8128AC4 + 107 * x + 4672
#define GetInventory							((int(__thiscall*)(int This))0x00861260)
#define SetEquipmentSlotInfo					((void (__thiscall*)( )) 0x00836510)


struct PMSG_INFOCHARVIEW_RECV
{
	PSBMSG_HEAD header;
	char name[10];
	int result;
	int Level;
	int Resets;
	int ItemIndex[12];
	int ItemLevel[12];
	int ItemNewOption[12];
	int ItemSetOption[12];
};

void ReceiveInventoryTwo(BYTE *ReceiveBuffer);
void GCInfoChar(PMSG_INFOCHARVIEW_RECV* lpMsg);
BOOL ReceiveInventory(BYTE *ReceiveBuffer);
void DrawItemImage(float PosX, float PosY, float Width, float Height, int ItemID, int Level, int Anc, int Excl,  bool OnMouse);
void DrawNewWindow();
extern int ItemIndex[12];
extern int ItemLevel[12];
extern int ItemNewOption[12];
extern int ItemSetOption[12];