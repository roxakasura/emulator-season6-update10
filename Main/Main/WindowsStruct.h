#pragma once
struct flotantes
{
	int x;
	int y;
};

#define sub_7D9C50 ((bool(__stdcall*)(int a5))0x007D9C50)
#define sub_7DC2C0 ((int(__stdcall*)(int This, int a2))0x007DC2C0)
#define sub_7D9B50 ((void(__stdcall*)(int a4, int a5))0x007D9B50)
#define sub_7853F0 ((BYTE(__cdecl*)(char a4, int a5, int a6, int a7, int a8, int a9, int a10, char a11))0x007853F0)
#define sub_7DA7E0					((int(__stdcall *)(int a4, int a5))0x007DA7E0)
#define pDrawPuntero				((int(__thiscall*)(int This, char a5, int a6, char a7, char a8, char a9))0x00779350)
#define ChangeButtonInfo			((int(__thiscall*)(char *This, int X, int Y, int Width, int Height)) 0x00779410)//sub_779410
#define GetInstance					((int(__cdecl*)()) 0x00861110)
#define SetOption1					((char(__thiscall*)(int This))0x004EC950)
#define SetOption2					((char(__thiscall*)(int This))0x004EC970)
#define sub_7C1C80                  ((int(__thiscall *)(int This, int a2)) 0x007C1C80)
#define sub_779740                  ((int(__thiscall *)(int This, int a2, float a3)) 0x00779740)

#define sub_969000					((BOOL(__thiscall*)(void * This))0x00969000)

#define sub_4EC9B0					((char(__thiscall*)(int This))0x004EC9B0)

#define sub_7DC240 ((int(__cdecl*)(int This, flotantes a2))0x007DC240)

#define GetInventory ((int(__thiscall*)(int This))0x00861260)

void RenderTooltipAncestral_772EA0(int ThisR);
void MoverSlotItem(int This);
#define GetUIBaulExt ((int(__thiscall*)(int This))0x00861A80)
#define CheckRepairInv				((int(__thiscall*)(int This))0x00834550)
#define GetInventoryExt ((int(__thiscall*)(int This))0x00861A60)
#define CheckInventoryExt ((int(__thiscall*)(int This))0x00513050)
#define GetChaosBox ((int(__thiscall*)(int a1)) 0x008612C0)
#define GetWindowShop				((int(__thiscall*)(int This))0x00861280)
#define CheckRepairShop				((int(__thiscall*)(int This))0x00847EF0)
#define pWindowStore ((int(__thiscall*)(int a1)) 0x00861400)
#define sub_7798F0 ((char(__thiscall*)(int This, char a9))0x007798F0)

#define GetUIBaul		((int(__thiscall*)(int This))0x00861360)
void EventMuOffhelper(DWORD Event);

float TransForX(float num);
float TransForY(float num);
float TransFor2X(float num);
float ReturnX(float num);
float Return2X(float num);
float ReturnY(float num);
bool CheckButtonPressed(int x, int y, int w, int h);
void RenedrBarFormat(float x, float y, float w, float h, float R, float G, float B, float Alpha);
void SetPrintf(char * DrawText, int x, int y, int nCount, int Aling);
void RebuildInformationRate(int Info, int x, int v5);
void RebuildInformationRate(int Info, int Info2, int x, int v5);
void RebuildInformation(int Info, int x, int v5);
void RebuildInformation(int Info, int Info2,int x, int v5);
int RetangleInventory(int num);
signed int __cdecl ColorMoney(unsigned int a1);
unsigned int sub_83CBE0(int This);