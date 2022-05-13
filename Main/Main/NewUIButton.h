#pragma once
//-- Constructor
#define InitializeButton					((void(__thiscall*)(void* thisa)) 0x00779150)
#define DestroyButton						((void(__thiscall*)(void* thisa)) 0x00779250)
#define Constructor_Btn						((void(__stdcall*)(char *thisa,int ObjSize, int ObjCount, void (__thiscall *)(void *) , void (__thiscall *)(void *) )) 0x009CFA13)
//--
#define Button_ChangeButtonInfo				((void(__thiscall*)(char* thisa, int x, int y, int sx, int sy)) 0x00779410)
#define Button_ChangeButtonImgState			((void(__thiscall*)(char* thisa, bool imgregister, int imgindex, bool overflg, bool isimgwidth, bool bClickEffect)) 0x00779350)
#define Button_UpdateMouseEvent				((bool(__thiscall*)(char* thisa)) 0x00779860)
#define Button_ChangeColor					((int(__thiscall*)(char* thisa, DWORD Color)) 0x007C1C80)
#define Button_ChangeImgColor				((void(__thiscall*)(char *thisa, int eventstate, unsigned int color))0x00779740)

#define Button_Render						((bool(__thiscall*)(char * thisa, BYTE Mode )) 0x007798F0)
#define Button_SetText						((void(__thiscall*)(char *thisa, char *Text, DWORD ImageCapeStateColor)) 0x00401AE0)
#define ChartoString						((void*(__thiscall*)(void *thisa, char *a4))0x00409A50)
#define ButtonChangeText					((void(__thiscall*)(char * thisa, int a1, int a2, int a3, int a4, int a5, int a6, int a7))0x00790970)
#define ButtonSetTooltip					((void(__thiscall*)(char * thisa, int a1, int a2, int a3, int a4, int a5, int a6, int a7, bool a8))0x007853F0)


class CNewUIButton
{
public:
	CNewUIButton(void);
	virtual ~CNewUIButton(void);
	void Construct();
	bool UpdateMouseEvent();
	void ChangeText(char* btname);
	void SetTooltipText(char* btname);
	bool Render(bool RendOption = false);
	void CButtonInfo(int x, int y, int sx, int sy);
	void ChangeImgColor(DWORD eventstate, unsigned int color);
	void ChangeButtonImgState(bool imgregister, int imgindex, bool overflg = false, bool isimgwidth = false, bool bClickEffect = false);
	int GetBTState();
private:
	bool isCreate;
	char thisa[172];
};

