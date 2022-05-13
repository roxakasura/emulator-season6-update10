#pragma once
#include "Protocol.h"

struct PMSG_NEW_PET_CHARSET_RECV
{
	PSWMSG_HEAD header; // C2:F3:E6
	BYTE count;
};

struct NEW_PET_STRUCT
{
	WORD index;
	BYTE PetCharSet[18];
};

struct PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV
{
	PSWMSG_HEAD header; // C2:F3:E8
	BYTE count;
};

struct PMSG_NEW_CHARACTER_CHARSET_RECV
{
	char Name[10];
	BYTE PetCharSet[18];
};


void ClearNewPetCharSet();
void InsertNewPetCharSet(WORD index, BYTE *CharSet);
NEW_PET_STRUCT* GetNewPetCharSet(WORD index);

void ClearNewPetCharSetSelectCharacter();
void InsertNewPetCharSetSelectCharacter(char * Name, BYTE *CharSet);
PMSG_NEW_CHARACTER_CHARSET_RECV* GetNewCharSetSelectCharacter(char *Name);

void GCPetCharSetRecv(PMSG_NEW_PET_CHARSET_RECV* lpMsg);
void GCPetCharSetSelectCharacterRecv(PMSG_NEW_SELECT_CHARACTER_CHARSET_RECV* lpMsg);