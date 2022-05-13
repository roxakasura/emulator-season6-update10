#include "stdafx.h"
#include "PetProtocol.h"


NEW_PET_STRUCT gNewPetCharSet[400];
PMSG_NEW_CHARACTER_CHARSET_RECV gNewPetCharSetSelectChar[5];

void ClearNewPetCharSet() // OK
{
	for (int n = 0; n < 400; n++)
	{
		gNewPetCharSet[n].index = 0xFFFF;
		memset(gNewPetCharSet[n].PetCharSet, 0, sizeof(gNewPetCharSet[n].PetCharSet));
	}
}


void InsertNewPetCharSet(WORD index, BYTE *CharSet) // OK
{
	for (int n = 0; n < 400; n++)
	{
		if (gNewPetCharSet[n].index == 0xFFFF)
		{
			gNewPetCharSet[n].index = index;
			memcpy(gNewPetCharSet[n].PetCharSet, CharSet, sizeof(gNewPetCharSet[n].PetCharSet));
			return;
		}
	}
}


NEW_PET_STRUCT* GetNewPetCharSet(WORD index) // OK
{
	for (int n = 0; n < 400; n++)
	{
		if (gNewPetCharSet[n].index != 0xFFFF)
		{
			if (gNewPetCharSet[n].index == index)
			{
				return &gNewPetCharSet[n];
			}
		}
	}

	return 0;
}


void ClearNewPetCharSetSelectCharacter() // OK
{
	for (int n = 0; n < 5; n++)
	{
		memset(gNewPetCharSetSelectChar[n].Name, 0, sizeof(gNewPetCharSetSelectChar[n].Name));
		memset(gNewPetCharSetSelectChar[n].PetCharSet, 0, sizeof(gNewPetCharSetSelectChar[n].PetCharSet));
	}
}


void InsertNewPetCharSetSelectCharacter(char * Name, BYTE *CharSet) // OK
{
	for (int n = 0; n < 5; n++)
	{
		if (gNewPetCharSetSelectChar[n].Name[0] == '\0')
		{
			memcpy(gNewPetCharSetSelectChar[n].Name, Name, sizeof(gNewPetCharSetSelectChar[n].Name));
			memcpy(gNewPetCharSetSelectChar[n].PetCharSet, CharSet, sizeof(gNewPetCharSetSelectChar[n].PetCharSet));
			return;
		}
	}
}


PMSG_NEW_CHARACTER_CHARSET_RECV* GetNewCharSetSelectCharacter(char *Name) // OK
{
	for (int n = 0; n < 5; n++)
	{
		if (gNewPetCharSetSelectChar[n].Name[0] != '\0')
		{
			if (strncmp(gNewPetCharSetSelectChar[n].Name, Name, sizeof(gNewPetCharSetSelectChar[n].Name)) == 0)
			{
				return &gNewPetCharSetSelectChar[n];
			}
		}
	}

	return 0;
}