#pragma once

#include "Protocol.h"

struct PMSG_ITEMVIEW_SEND
{
	PSBMSG_HEAD h;
	int	Status;
};

#define GetInstance				((int(__cdecl*)()) 0x00861110)
#define	pFontNormal				*(HGDIOBJ*)0x00E8C588
#define pSetFont				((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define sub_7798F0				((char(__thiscall*)(int This, char a9))0x007798F0)

void ItemEquippedStatus(int Status);
void MenuLoad();
extern int MenuOpt;
extern int OptStatus;