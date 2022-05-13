#pragma once
#include "_struct.h"
#define MAX_LINE_ITEM_BMD		0x2000
const BYTE EXT_A_SET_OPTION = 1;
const BYTE EXT_B_SET_OPTION = 2;

#define AT_EXCELLENT_DAMAGE					93
#define AT_IMPROVE_DAMAGE_LEVEL				94
#define AT_IMPROVE_DAMAGE_PERCENT			95
#define AT_IMPROVE_MAGIC_LEVEL				96
#define AT_IMPROVE_MAGIC_PERCENT			97
#define AT_IMPROVE_ATTACK_SPEED				98
#define AT_IMPROVE_GAIN_LIFE				99
#define AT_IMPROVE_GAIN_MANA				100


#define Information_ItemConvert				((char (__cdecl*)(ITEM *ip, unsigned __int8 Attribute1, unsigned __int8 Attribute2, unsigned __int8 Attribute3)) 0x0058B910)
#define IsCepterItem						((bool (__cdecl*)(int Type)) 0x0058B8D0)

class CScriptItem
{
public:
	CScriptItem();
	virtual ~CScriptItem();
	static void OpenItemScript(char* FileName);
public:
	void Init();
};

extern CScriptItem g_ScriptItem;