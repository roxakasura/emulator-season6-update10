#pragma once

#define MAX_PET_ITEM		300

struct CUSTOM_PET_INFO
{
    int Index;
    int ItemIndex;
	int IndexInventory;
    int PetType;
    float Scale_View;
    float Scale_Drop;
    float Scale_Inve;
    float Scale_X;
    float Scale_Y;
    float Scale_Angle;
    int FenrrirEffect;
    char ModelName[50];
};


class cCustomPet
{
public:
	cCustomPet();
	virtual ~cCustomPet();
	void Init();
	void Load(CUSTOM_PET_INFO* info);
	int GetInfoByItem(int ItemIndex);
	int GetInfoByItemInventory(int ItemIndex);
	CUSTOM_PET_INFO* GetInfoByItem2(int ItemIndex);
	int GetInfoPetType(int ItemIndex); // OK
	int GetInfoPetEffect(int ItemIndex); // OK
	float GetScaleInv(int ItemIndex);
	float GetScaleDrop(int ItemIndex);
	float GetScaleView(int ItemIndex);
	float GetScalePosX(int ItemIndex);
	float GetScalePosY(int ItemIndex);
	float GetScaleAngle(int ItemIndex);
	bool CheckCustomPetByItem(int ItemIndex);
public:
	std::map<int, CUSTOM_PET_INFO> m_CustomPetInfo;
};

extern cCustomPet gCustomPet2;