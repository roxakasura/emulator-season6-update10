#pragma once

#define sub_50D810_Addr		((int(__thiscall*)(int a1, int a2, int a3, int a4)) 0x50D810)
#define sub_512D50_Addr		((void*(__thiscall*)(void* a1)) 0x512D50)
#define sub_513C60_Addr		((char*(__thiscall*)(char *This, void *a2, int a3)) 0x513C60)
#define sub_5135F0_Addr		((char*(__thiscall*)(DWORD *This, int a2, int a3)) 0x5135F0)
#define sub_512D60_Addr		((void(*)()) 0x512D60)

#define MAX_CUSTOM_GLOVES	100

struct CUSTOM_RF_GLOVES{
	int Index;
	int ItemIndex;
	char ModelName[32];
	int TextureLeftIndex;
	char TextureLeftName[32];
	int TextureRightIndex;
	char TextureRightName[32];
	int ColorR;
	int ColorG;
	int ColorB;
};

class cCustomGloves
{
public:
	cCustomGloves();
	virtual ~cCustomGloves();
	void Init();
	void Load(CUSTOM_RF_GLOVES* info);
	void SetInfo(CUSTOM_RF_GLOVES info);
	CUSTOM_RF_GLOVES* GetInfoByID(int index);
	CUSTOM_RF_GLOVES* GetInfoByItem(int ItemIndex);
	void AssocGloves(char* This);
	bool CheckGloves(int ItemID);
public:
	CUSTOM_RF_GLOVES m_CustomGlovesInfo[MAX_CUSTOM_GLOVES];
}; extern cCustomGloves gCustomGloves;
