#pragma once
#define DEBUG_CURSOR 0
//--/TAP FULLMAP
//----- (00790DF0) --------------------------------------------------------
//----- (00638130) --------------------------------------------------------
#define pDrawMapFull ((void(__cdecl*)(int ModelID, float x, float y, float Width, float Heigth, float Rotacion))0x00638130)
#define sub_82B7A0 ((char(__thiscall*)(signed int a4, signed int a5))0x0082B7A0)
#define sub_8875E0 ((char(__cdecl*)(DWORD a1))0x008875E0)
#define sub_635CF0 ((void (__stdcall*)(signed int a4))0X00635CF0)
#define sub_637E80					((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)
#define rFileOpen ((int(__cdecl*)(char* FileName, char* Mode)) 0x9D0040) //1.04E
#define rFileClose ((signed int(__cdecl*)(int a1))0x9CFC26) //1.04E 
#define pCheckEffectPlayer			((bool(__thiscall*)(void * This,char a2)) 0x004C8640)
#define GetBoneTransform			((int(__thiscall*)(int This, signed int a2)) 0x004CD7F0)
#define ppMousePress				((int(__cdecl*)(int VKBUTTON)) 0x00791070)
#define pCheckMouseOver				((bool(__cdecl*)(int a1, int a2, int a3, int a4)) 0x00790B10)
#define RenderBitMapColored ((void(__cdecl*)(int a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12, int a13))0x00790DF0)
//-- Recovery Info User
#define pGetUserCoorX				*(DWORD *)(*(DWORD *)0x7BC4F04 + 0xAC)
#define pGetUserCoorY				*(DWORD *)(*(DWORD *)0x7BC4F04 + 0xB0)
#define pGetUserName				(const char *)(*(DWORD *)0x7BC4F04 + 56)
#define pGetStrutParty( x )			(*(PartyList*)(0x81CB4E8 + 32 * x))
#define pGetLifeMemberParty( x )	((unsigned __int8)((BYTE*) 0x81CB500)[32 * x

#define pCameraAngleX			*(float*)0x87933D0
#define pCameraAngleY			*(float*)0x87933D4
#define pCameraAngleZ			*(float*)0x87933D8
#define pCameraPosX				*(float*)0x87933DC
#define pCameraPosY				*(float*)0x87933E0
#define pCameraPosZ				*(float*)0x87933E4

#define MAX_MINI_MAP 100

struct LoadTypeMap
{
	/*+0*/   DWORD ModelID;
	/*+4*/   DWORD XSW_Minimap_Frame;
	/*+8*/   DWORD YSW_Minimap_Frame;
	/*+12*/  DWORD XSW_Minimap;
	/*+16*/  DWORD YSW_Minimap;
	/*+20*/  DWORD XSW_Time_Frame;
	/*+24*/  DWORD YSW_Time_Frame;
	/*+92*/  DWORD This_92;
	/*+96*/  DWORD This_96;
	/*+100*/ DWORD DropMoveUserX;
	/*+104*/ DWORD DropMoveUserY;
	/*+108*/ DWORD This_108;
	/*+112*/ DWORD This_112;
	/*+116*/ float CurrentMoveX;
	/*+120*/ float CurrentMoveY;
	/*+124*/ DWORD Scale;
	/*+126*/ DWORD TimerEventVK;
	/*+128*/ float Alpha;
};

class CMinimap
{
public:
	CMinimap();
	virtual ~CMinimap();
	void MiniMapload();
	char MapRender(int a1);
public:
	LoadTypeMap DataMap;
	bool Hoving;
	short mX;
	short mY;
	DWORD ultimoX;
	DWORD ultimoY;
}; extern CMinimap gRenderMap;