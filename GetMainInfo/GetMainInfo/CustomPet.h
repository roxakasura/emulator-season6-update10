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
	void Load(char* path);
	void SetInfo(CUSTOM_PET_INFO info);
public:
	CUSTOM_PET_INFO m_CustomPetInfo[MAX_PET_ITEM];
};

extern cCustomPet gCustomPet2;
