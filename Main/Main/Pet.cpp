#include "stdafx.h"
#include "Pet.h"
#include "Import.h"
#include "User.h"
#include "PetProtocol.h"
#include "TMemory.h"
#include "Protect.h"
#include "Interface.h"
#include "Util.h"
#include "CustomInterface.h"


CustomPet gCustomPet;

CustomPet::CustomPet() //OK
{
	this->PetTickCount = 0;
}

CustomPet::~CustomPet()
{

}
//----- (00959FA0) --------------------------------------------------------
int sub_959FA0(int a1, int a2, int a3)
{
  int result; // eax@1

  lpViewObj Object = &*(ObjectPreview*)oUserPreviewStruct;

	int DL = pGetCharClass(*(BYTE *)(oUserPreviewStruct + 19));
	if ( DL == 4 )
	{
		if (!CC_MAP_RANGE(pMapNumber))
		{
			if (Object->WeaponSecondSlot == 7832)
			{
			  *(float *)a3 = 0;
			  *(float *)(a3 + 4) = 0;
			  *(float *)(a3 + 8) = 0;
			  *(float *)(a3 + 12) = 0;
			  *(float *)(a3 + 16) = 0;
			  *(float *)(a3 + 20) = 0;
			  *(float *)(a3 + 24) = 0;
			  *(float *)(a3 + 28) = 0;
			  *(float *)(a3 + 32) = 0;
			  *(float *)(a3 + 36) = 0;
			  *(float *)(a3 + 40) = 0;
			  result = a2;
			  *(float *)(a3 + 44) = 0;
			  return result;
			}
		}
	}

  *(float *)a3 = *(float *)a1 * *(float *)a2
               + *(float *)(a1 + 4) * *(float *)(a2 + 16)
               + *(float *)(a1 + 8) * *(float *)(a2 + 32);
  *(float *)(a3 + 4) = *(float *)a1 * *(float *)(a2 + 4)
                     + *(float *)(a1 + 4) * *(float *)(a2 + 20)
                     + *(float *)(a1 + 8) * *(float *)(a2 + 36);
  *(float *)(a3 + 8) = *(float *)a1 * *(float *)(a2 + 8)
                     + *(float *)(a1 + 4) * *(float *)(a2 + 24)
                     + *(float *)(a1 + 8) * *(float *)(a2 + 40);
  *(float *)(a3 + 12) = *(float *)a1 * *(float *)(a2 + 12)
                      + *(float *)(a1 + 4) * *(float *)(a2 + 28)
                      + *(float *)(a1 + 8) * *(float *)(a2 + 44)
                      + *(float *)(a1 + 12);
  *(float *)(a3 + 16) = *(float *)(a1 + 16) * *(float *)a2
                      + *(float *)(a1 + 20) * *(float *)(a2 + 16)
                      + *(float *)(a1 + 24) * *(float *)(a2 + 32);
  *(float *)(a3 + 20) = *(float *)(a1 + 16) * *(float *)(a2 + 4)
                      + *(float *)(a1 + 20) * *(float *)(a2 + 20)
                      + *(float *)(a1 + 24) * *(float *)(a2 + 36);
  *(float *)(a3 + 24) = *(float *)(a1 + 16) * *(float *)(a2 + 8)
                      + *(float *)(a1 + 20) * *(float *)(a2 + 24)
                      + *(float *)(a1 + 24) * *(float *)(a2 + 40);
  *(float *)(a3 + 28) = *(float *)(a1 + 16) * *(float *)(a2 + 12)
                      + *(float *)(a1 + 20) * *(float *)(a2 + 28)
                      + *(float *)(a1 + 24) * *(float *)(a2 + 44)
                      + *(float *)(a1 + 28);
  *(float *)(a3 + 32) = *(float *)(a1 + 32) * *(float *)a2
                      + *(float *)(a1 + 36) * *(float *)(a2 + 16)
                      + *(float *)(a1 + 40) * *(float *)(a2 + 32);
  *(float *)(a3 + 36) = *(float *)(a1 + 32) * *(float *)(a2 + 4)
                      + *(float *)(a1 + 36) * *(float *)(a2 + 20)
                      + *(float *)(a1 + 40) * *(float *)(a2 + 36);
  *(float *)(a3 + 40) = *(float *)(a1 + 32) * *(float *)(a2 + 8)
                      + *(float *)(a1 + 36) * *(float *)(a2 + 24)
                      + *(float *)(a1 + 40) * *(float *)(a2 + 40);
  result = a2;
  *(float *)(a3 + 44) = *(float *)(a1 + 32) * *(float *)(a2 + 12)
                      + *(float *)(a1 + 36) * *(float *)(a2 + 28)
                      + *(float *)(a1 + 40) * *(float *)(a2 + 44)
                      + *(float *)(a1 + 44);
  return result;
}

char CustomPet::PetHPBar(int a1, int a2)
{
	lpViewObj Object = &*(ObjectPreview*)oUserPreviewStruct;

	char result;
	char PetName[255];
	int PetHP;

	if ((Object->PetSlot < 7827 || Object->PetSlot > 7831)
		&& Object->PetSlot != 7891
		&& Object->PetSlot != 7892
		&& Object->PetSlot != 7894
		&& Object->PetSlot != 7907
		&& Object->PetSlot != 7933
		&& Object->PetSlot != 7950
		&& Object->PetSlot != 7864
		&& (Object->PetSlot < ITEM2(13, 200) || Object->PetSlot > ITEM2(13, 512)))
	{
		result = 0;
	}
	else
	{
		memset(&PetHP, 0, 255);
		PetName[0] = 0;
		switch (Object->PetSlot)
		{
		case 7827:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 353));
			break;
		case 7828:
			wsprintf(PetName, (char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		case 7829:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 355));
			break;
		case 7830:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 354));
			break;
		case 7831:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 1187));
			break;
		case 7864:
			wsprintf(PetName, pGetTextLine_(pTextLineThis, 1916));
			break;
		case 7891:
			wsprintf(PetName, (char *)(oUserTextObject + 564480));
			break;
		case 7892:
			wsprintf(PetName, (char *)(oUserTextObject + 564564));
			break;
		case 7894:
			wsprintf(PetName, (char *)(oUserTextObject + 564732));
			break;
		case 7907:
			wsprintf(PetName, (char *)(oUserTextObject + 565824));
			break;
		case 7933:
			wsprintf(PetName, (char *)(oUserTextObject + 568008));
			break;
		case 7950:
			wsprintf(PetName, (char *)(oUserTextObject + 569436));
			break;
		default:
			wsprintf(PetName, (char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		}

		PetHP = *(BYTE*)(oUserObjectStruct_ + 5550);
		lpCharObj test		= &*(ObjectCharacter*)oUserObjectStruct_;
		
		//if(gProtect.m_MainInfo.CustomInterfaceType == 1 | gProtect.m_MainInfo.CustomInterfaceType == 2)
		//{
		//	PetHPBarRemake(1, 50, (int)&PetName, PetHP, 255, 0);
		//}
		//else
		//{
			sub_7DFA60(2, 26, (int)&PetName, PetHP, 255, 0);
		//}
		result = 1;
	}

	return result;
}

bool IsCharacterMove(int a1)
{

	if ((*(WORD *)(*(DWORD *)(a1 + 472) + 18) >= 15
		&& *(WORD *)(*(DWORD *)(a1 + 472) + 18) <= 37)
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 74
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 75
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 259
		|| *(WORD *)(*(DWORD *)(a1 + 472) + 18) == 260)
	{
		return true;
	}
	return false;
}

void CustomPet::PetFollowCharacter(int a1, float MaxPos)
{
	float v22;
	vec3_t MUFLOAT;
	vec3_t PetPos;
	vec3_t OwnerPos;
	vec3_t CurrentPos;
	int LootPosition = 1000;

	OwnerPos[0] = *(float *)(*(DWORD *)(a1 + 472) + 252);
	OwnerPos[1] = *(float *)(*(DWORD *)(a1 + 472) + 256);
	OwnerPos[2] = *(float *)(*(DWORD *)(a1 + 472) + 260);

	PetPos[0] = OwnerPos[0] - *(float *)(a1 + 252);
	PetPos[1] = OwnerPos[1] - *(float *)(a1 + 256);
	PetPos[2] = OwnerPos[2] - *(float *)(a1 + 260);

	CurrentPos[0] = *(float *)(a1 + 252);
	CurrentPos[1] = *(float *)(a1 + 256);
	CurrentPos[2] = *(float *)(a1 + 260);

	float PetMapPos = PetPos[0] * PetPos[0] + PetPos[1] * PetPos[1];

	float diff1 = ((OwnerPos[0] > CurrentPos[0]) ? OwnerPos[0] - CurrentPos[0] : CurrentPos[0] - OwnerPos[0]);
	float diff2 = ((OwnerPos[1] > CurrentPos[1]) ? OwnerPos[1] - CurrentPos[1] : CurrentPos[1] - OwnerPos[1]);

	float angle = atan(diff2 / diff1) * 180 / PI;
	float angle2 = atan2(diff1, diff2) * 180 / PI; //

	if (PetMapPos >= MaxPos * MaxPos)
	{
		float speed;
		if (PetMapPos >= (MaxPos * 2) * (MaxPos * 2))
		{
			speed = 14.0f;
			speed += 1.0f;
			*(float *)(a1 + 120) = 0.89000002f;
		}
		else if (PetMapPos >= (MaxPos + (MaxPos / 2)) * (MaxPos + (MaxPos / 2)))
		{
			speed = 13.0f;
			*(float *)(a1 + 120) = 0.69000002f;
		}
		else
		{
			speed = 10.0f;
			*(float *)(a1 + 120) = 0.40000001f;
		}

		double MoveX = speed *(cos(angle * PI / 180));
		double MoveY = speed *(sin(angle * PI / 180));

		if (CurrentPos[0] < OwnerPos[0] && CurrentPos[1] < OwnerPos[1])
		{
			*(float *)(a1 + 252) += (float)MoveX;
			*(float *)(a1 + 256) += (float)MoveY;
			*(float *)(a1 + 272) = 180;
			*(float *)(a1 + 272) -= angle2;
		}
		else if (CurrentPos[0] < OwnerPos[0] && CurrentPos[1] > OwnerPos[1])
		{
			*(float *)(a1 + 252) += (float)MoveX;
			*(float *)(a1 + 256) -= (float)MoveY;
			*(float *)(a1 + 272) = angle2;
		}
		else if (CurrentPos[0] > OwnerPos[0] && CurrentPos[1] > OwnerPos[1])
		{
			*(float *)(a1 + 252) -= (float)MoveX;
			*(float *)(a1 + 256) -= (float)MoveY;
			*(float *)(a1 + 272) = 360;
			*(float *)(a1 + 272) -= angle2;
		}
		else if (CurrentPos[0] > OwnerPos[0] && CurrentPos[1] < OwnerPos[1])
		{
			*(float *)(a1 + 252) -= (float)MoveX;
			*(float *)(a1 + 256) += (float)MoveY;
			*(float *)(a1 + 272) = 180;
			*(float *)(a1 + 272) += angle2;
		}
		//else
		//{
		//	*(float *)(a1 + 252) += abs(MoveX);
		//	*(float *)(a1 + 256) += abs(MoveY);
		//	*(float *)(a1 + 272) = *(float *)(*(DWORD *)(a1 + 472) + 272);
		//}
		*(WORD*)(a1 + 18) = 2;
	}
	else if (PetMapPos < 70 * 70)
	{
		if ((*(WORD *)(*(DWORD *)(a1 + 472) + 18) < 15 || *(WORD *)(*(DWORD *)(a1 + 472) + 18) > 37))
		{
			*(WORD*)(a1 + 18) = 2;
			sub_959CE0(a1 + 264, a1 + 372);
			sub_95A1E0(a1 + 168, a1 + 372, MUFLOAT);
			*(float *)(a1 + 252) = *(float *)(a1 + 252) + MUFLOAT[0];
			*(float *)(a1 + 256) = *(float *)(a1 + 256) + MUFLOAT[1];
			//*(float *)(a1 + 260) = *(float *)(a1 + 260);
		}
	}
	else
	{
		if (GetTickCount() <= gCustomPet.PetTickCount + 800)
		{
			*(WORD*)(a1 + 18) = 1;
		}
		else if (GetTickCount() <= gCustomPet.PetTickCount + 12000)
		{
			*(WORD*)(a1 + 18) = 0;
		}
		else
		{
			gCustomPet.PetTickCount = GetTickCount();
		}
	}

	if (PetMapPos >= LootPosition * LootPosition)
	{
		if (*(float *)(a1 + 252) < *(float *)(*(DWORD *)(a1 + 472) + 252))
		{
			*(float *)(a1 + 252) = *(float *)(a1 + 252) + PetPos[0] + rand() % 360;
		}
		if (*(float *)(a1 + 252) > *(float *)(*(DWORD *)(a1 + 472) + 252))
		{
			*(float *)(a1 + 252) = *(float *)(a1 + 252) + PetPos[0] - rand() % 360;
		}
		if (*(float *)(a1 + 256) < *(float *)(*(DWORD *)(a1 + 472) + 256))
		{
			*(float *)(a1 + 256) = *(float *)(a1 + 256) + PetPos[1] + rand() % 360;
		}
		if (*(float *)(a1 + 256) > *(float *)(*(DWORD *)(a1 + 472) + 256))
		{
			*(float *)(a1 + 256) = *(float *)(a1 + 256) + PetPos[1] - rand() % 360;
		}
	}

	*(float *)(a1 + 260) = *(float *)(*(DWORD *)(a1 + 472) + 260);

	if (!(rand() % 100))
	{
		if (PetMapPos < MaxPos * MaxPos)
		{
			v22 = -(float)(rand() % 64 + 16) * 0.1000000014901161f;
			*(float *)(a1 + 272) = (float)(rand() % 360);
		}
		else
		{
			v22 = -(float)(rand() % 64 + 128) * 0.1000000014901161f;
		}
		*(float *)(a1 + 168) = 0.0f;
		*(float *)(a1 + 172) = v22;
		*(float *)(a1 + 176) = (float)(rand() % 64 - 32) * 0.1000000014901161f;
	}

	if (*(float *)(a1 + 260) < *(float *)(*(DWORD *)(a1 + 472) + 260) + 100.0f)
		*(float *)(a1 + 176) = *(float *)(a1 + 176) + 1.5f;
	if (*(float *)(a1 + 260) > *(float *)(*(DWORD *)(a1 + 472) + 260) + 200.0f)
		*(float *)(a1 + 176) = *(float *)(a1 + 176) - 1.5f;
}

void CustomPet::PetsMovement(int a1, char a2)
{
	int v86; // [sp+19Ch] [bp-Ch]@76
	float v87; // [sp+1A0h] [bp-8h]@76
	float v88; // [sp+1A4h] [bp-4h]@76

	if (*(BYTE *)(a1 + 4))
	{
		lpViewObj lpObj = &*(ObjectPreview*)*(DWORD*)0x07BC4F04;

		if (*(DWORD*)0xE609E8 == 5
			&& (*(DWORD*)0xE61E18 < 65 || *(DWORD*)0xE61E18 > 68)
			&& (!*(BYTE *)(*(DWORD *)(a1 + 472) + 4) || *(BYTE *)(*(DWORD *)(a1 + 472) + 24) != 1))
		{
			*(BYTE *)(a1 + 4) = 0;
			sub_501790(a1, a2);
			return;
		}

		DWORD SkinID = *(DWORD *)(a1 + 48);
		DWORD Model = sub_969C50(sub_4CDA10(), SLODWORD(SkinID));

		if (Model)
		{
			if ((SkinID >= ITEM2(13, 200) && SkinID <= ITEM2(13, 512)) && gCustomPet2.GetInfoPetType( SkinID - 1171 ) == 4)
			{
				gCustomPet.PetFollowCharacter(a1, 150);

				switch (SkinID)
				{
				case ITEM2(13, 226): //King
				case ITEM2(13, 281): //Prince
				case ITEM2(13, 388): //Prince =)) lazy
					*(float*)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 40.0f;
					break;
				case ITEM2(13, 214): //Hawk
				case ITEM2(13, 215): //Hawk Evo
				case ITEM2(13, 174): //CherryBlossom
				case ITEM2(13, 175): //CherryBlossom Evo
				case ITEM2(13, 178): //Chrysanthemum
				case ITEM2(13, 179): //Chrysanthemum Evo
				case ITEM2(13, 200): //Ghost
					*(float*)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 30.0f;
					break;
				case ITEM2(13, 201): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 202): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 203): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 204): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 205): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 206): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 207): //Ghost Evo
					//*(DWORD *)(a1 + 68) = 1;
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				case ITEM2(13, 218): //Ghost Evo
					*(float *)(a1 + 260) = *(float*)(*(DWORD*)(a1 + 472) + 260) + 200.0f;
					break;
				}
			}
		}
	}

	((void(*)(int, char)) 0x501790)(a1, a2);
}

void CustomPet::PreviewCharSet(int ObjectIndex, BYTE * CharSet, lpViewObj Object, int Mode)
{
	pPreviewCharSet(ObjectIndex, CharSet, Object, Mode);

	lpViewObj lpObj;

	if (Object == 0)
	{
		lpObj = &*(lpViewObj)pGetPreviewStruct(pPreviewThis(), ObjectIndex);
	}
	else
	{
		lpObj = Object;
	}

		short v25 = CharSet[1] | (unsigned short)(16 * (CharSet[12] & 0xF0));
//Fix Dark Raven Shield kkk
	if (v25 == 4095)
	{
		lpObj->WeaponSecondSlot = -1;
		lpObj->WeaponSecondExcellent = 0;
		lpObj->WeaponSecondAncient = 0;
	}
	else if (pGetCharClass(lpObj->Class) != 4 || v25 != 2565)
	{
		lpObj->WeaponSecondSlot = v25 + 1171;
	}
	else
	{
		sub_4F8B80((int)lpObj);

		if (!CC_MAP_RANGE(pMapNumber))
		{
			lpCharObj Character = &*(ObjectCharacter*)oUserObjectStruct_;
			sub_4FA780(lpObj->Unknown676, (int)pGetPetInfo((int)&Character->pEquipment[1].ItemID));
			lpObj ->WeaponSecondSlot = 7832;
		}
	}

	short PetWing = (signed int)CharSet[16];

	int WingCode = CharSet[8] & 7;

	//*** final

	PMSG_NEW_CHARACTER_CHARSET_RECV* SelectCharSet = GetNewCharSetSelectCharacter(lpObj->Name);

	if (pPlayerState == 4)
	{
		if (SelectCharSet > 0)
		{
			BYTE sNewCharSet0 = SelectCharSet->PetCharSet[0] >> 1;
			BYTE sNewCharSet1 = SelectCharSet->PetCharSet[1] >> 1;
			BYTE sNewCharSet2 = SelectCharSet->PetCharSet[2] >> 1;
			BYTE sNewCharSet3 = SelectCharSet->PetCharSet[3] >> 1;

			if (sNewCharSet0 > 0 && sNewCharSet0 < 112)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 147) + (sNewCharSet0 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}

			if (sNewCharSet1 > 0 && sNewCharSet1 < 94)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 258) + (sNewCharSet1 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}

			if (sNewCharSet2 > 0 && sNewCharSet2 < 100)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 351) + (sNewCharSet2 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}

			if (sNewCharSet3 > 0 && sNewCharSet3 < 100)
			{
				if (Mode)
				{
					*(BYTE *)(Mode + 4) = 0;
				}
				else
				{
					sub_5012D0((int)&lpObj->m_Model);
					sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
				}

				lpObj->PetSlot = ITEM2(13, 451) + (sNewCharSet3 - 1);

				if (Mode)
					sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
				else
					sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
			}
		}
	}

	NEW_PET_STRUCT* lpCharSet = GetNewPetCharSet(lpObj->aIndex);

	if (lpCharSet > 0)
	{
		BYTE NewCharSet0 = lpCharSet->PetCharSet[0] >> 1;
		BYTE NewCharSet1 = lpCharSet->PetCharSet[1] >> 1;
		BYTE NewCharSet2 = lpCharSet->PetCharSet[2] >> 1;
		BYTE NewCharSet3 = lpCharSet->PetCharSet[3] >> 1;

		if (NewCharSet0 > 0 && NewCharSet0 < 112)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 147) + (NewCharSet0 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

		if (NewCharSet1 > 0 && NewCharSet1 < 94)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 258) + (NewCharSet1 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

		if (NewCharSet2 > 0 && NewCharSet2 < 100)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 351) + (NewCharSet2 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

		if (NewCharSet3 > 0 && NewCharSet3 < 100)
		{
			if (Mode)
			{
				*(BYTE *)(Mode + 4) = 0;
			}
			else
			{
				sub_5012D0((int)&lpObj->m_Model);
				sub_9253D0(sub_4DB230(), (int)&lpObj->m_Model, (int)&lpObj->PetSlot);
			}

			lpObj->PetSlot = ITEM2(13, 451) + (NewCharSet3 - 1);

			if (Mode)
				sub_5013B0(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
			else
				sub_501700(lpObj->PetSlot, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
		}

	}

	BYTE CustomPets = CharSet[15] >> 1;

	if (CharSet[11] & 1) // == 1 
	{
		lpObj->PetSlot = 7831;
		if (Mode)
			sub_5013B0(226, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, Mode, 0);
		else
			sub_501700(226, (int)&lpObj->m_Model + 252, (int)&lpObj->m_Model, 0, 0);
	}
}

void CustomPet::RefreshViewPortItem(int a1)
{
	signed int v1; // ST14_4@1
	int result; // eax@1
	int v6; // [sp+Ch] [bp-14h]@2
	int v7; // [sp+10h] [bp-10h]@1
	int v8; // [sp+14h] [bp-Ch]@2
	BYTE v9; // [sp+1Dh] [bp-3h]@2
	BYTE v10; // [sp+1Eh] [bp-2h]@2
	BYTE v11; // [sp+1Fh] [bp-1h]@2

	v1 = sub_57D9A0(*(BYTE *)(a1 + 4) + (*(BYTE *)(a1 + 3) << 8));
	result = sub_96A4C0(sub_402BC0(), v1);
	v7 = result;
	if (result)
	{
		v6 = result + 776;
		v8 = sub_58AA80(a1 + 5);
		v11 = *(BYTE *)(a1 + 6) & 0xF;
		v10 = *(BYTE *)(a1 + 8) & 0x3F;
		v9 = *(BYTE *)(a1 + 9);
		switch ((signed int)*(BYTE *)(a1 + 6) >> 4)
		{
		case 7:
			if (v8 == 0x1FFF)
			{
				if (*(WORD*)(v7 + 520) == ITEM2(12,40)
					|| *(WORD*)(v7 + 520) == ITEM2(12,49)
					|| *(WORD*)(v7 + 520) == ITEM2(12,50)
					|| *(WORD*)(v7 + 520) == ITEM2(13,30)
					|| gCloak.isCloak((*(WORD*)(v7 + 520) - 1171)))
				{
					sub_558630(v7, v6, 0);
				}
				*(WORD *)(v7 + 520) = -1;
			}
			else
			{
				*(WORD *)(v7 + 520) = v8 + 1171;
				*(BYTE *)(v7 + 522) = 0;
				if (*(WORD*)(v7 + 520) == ITEM2(12, 40)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 49)
					|| *(WORD*)(v7 + 520) == ITEM2(12, 50)
					|| *(WORD*)(v7 + 520) == ITEM2(13, 30)
					|| gCloak.isCloak((*(WORD*)(v7 + 520) - 1171)))
				{
					sub_558630(v7, v6, 0);
				}
			}
			break;
		case 8:
			if (v8 == 0x1FFF)
			{
				*(WORD *)(v7 + 556) = -1;
				sub_5012D0(v6);
				sub_9253D0(sub_4DB230(), v7, -1);
			}
			else
			{
				*(WORD *)(v7 + 556) = v8 + 1171;
				*(BYTE *)(v7 + 558) = 0;
				if (v8 >= ITEM(13, 147) && v8 <= ITEM(13, 410))
				{
					sub_501700(v8 + 1171, v6 + 252, v6, 0, 0);
				}
			}
			break;
		default:
			break;
		}
	}
	((void(*)(int))0x6411A0)(a1);
}
//--

int recargaNuevoPet(int NuevoPet)
{
	int t = -1;
	t = gCustomPet2.GetInfoPetType(NuevoPet - 1171);

	return t;
}

#pragma optimize("t",on)

__declspec(naked) void SetPlayerAnimation1()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x00551B25;
	static DWORD Addrss2 = 0x00551B3F;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || Type == 2)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation2()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x0054ECA0;
	static DWORD Addrss2 = 0x0054ECFC;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || Type == 2)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation3()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x0054FCE9;
	static DWORD Addrss2 = 0x0054FCE7;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || Type == 2)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation4()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005506D4;
	static DWORD Addrss2 = 0x00550701;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX,WORD PTR DS:[EAX + 0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || Type == 2)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation5()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x0055D1F5;
	static DWORD Addrss2 = 0x0055D207;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX,WORD PTR DS:[EAX + 0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || horse == 0x1E95 || horse == 0x1E96 || Type == 3 || Type == 2 || Type == 1 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation6()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AE224;
	static DWORD Addrss2 = 0x005AE236;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E97 || horse == 0x1E95 || horse == 0x1E96 || Type == 3 || Type == 2 || Type == 1 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation7()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF200;
	static DWORD Addrss2 = 0x005AF212;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1E95 || horse == 0x1E96 || horse == 0x1E97 || Type == 3 || Type == 2 || Type == 1 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation8()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF28A;
	static DWORD Addrss2 = 0x005AFF59;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97  || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation10()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AFF59;
	static DWORD Addrss2 = 0x005ADB46;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EDX,WORD PTR DS:[ECX + 0x22C]
		MOV horse, EDX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 7829 || horse == 7830 || horse == 7831 ||horse == 7864 || Type == 3 || Type == 2 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation11()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005B3891;
	static DWORD Addrss2 = 0x005B38A6;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation12()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005B3BAC;
	static DWORD Addrss2 = 0x005B3BC1;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX,WORD PTR DS:[EAX + 0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation13()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005B3ECC;
	static DWORD Addrss2 = 0x005B3EE1;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EDX,WORD PTR DS:[ECX + 0x22C]
		MOV horse, EDX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetHorsePlayer5()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x00552CD8;
	static DWORD Addrss2 = 0x005528F5;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOVSX ECX,WORD PTR DS:[EAX + 0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse2()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x0055D1F5;
	static DWORD Addrss2 = 0x0055D207;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse3()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x00564C2D;
	static DWORD Addrss2 = 0x00564C55;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse4()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005964E8;
	static DWORD Addrss2 = 0x005964F4;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetMontDarkHorse5()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005A3976;
	static DWORD Addrss2 = 0x005A3863;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV horse, ECX
	}

	Type = recargaNuevoPet(horse);

	if(horse == 0x1EB8 ||horse == 0x1E95 ||horse == 0x1E96 ||horse == 0x1E97 || Type == 3 || Type == 2 || Type == 1 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void MoveHorse()
{
	static DWORD NuevoPet;
	static int Type;
	static DWORD MoveUniria = 0x00502C05;
	static DWORD MoveHorse = 0x005018A2;
	static DWORD Addrss2 = 0x005031C9;
	static DWORD MoveAngel = 0x00503232;
	static DWORD MoveSatan = 0x00503391;
	static DWORD MoveFenrrir = 0x0050190F;

	static DWORD Addr_Buffer = 0x0050339A;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOV ECX,DWORD PTR DS:[EAX + 0x30]
		MOV DWORD PTR SS:[EBP-0x124],ECX
		MOV EDX, DWORD PTR SS:[EBP-0x124]
		MOV NuevoPet, EDX
	}

	Type = recargaNuevoPet(NuevoPet);

	if( NuevoPet == 0x143 || NuevoPet == 0x0E9 || Type == 3 ) //-- Uniria || Dinorant
	{
		_asm
		{
			JMP [MoveUniria]
		}
	}
	else if( NuevoPet == 0x0B0 ) //-- Algun Pet Extraño
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
	else if( NuevoPet == 0x1E93 || Type == 0) //-- PetAngel
	{
		_asm
		{
			JMP [MoveAngel]
		}
	}
	else if( NuevoPet == 0x1E94) //-- PetSatan
	{
		_asm
		{
			JMP [MoveSatan]
		}
	}
	else if( NuevoPet == 0x180 ||  NuevoPet == 0x181 ||  NuevoPet == 0x182 || NuevoPet == 0x183 || Type == 1 ) //-- Pet Fenrrir
	{
		_asm
		{
			JMP [MoveFenrrir]
		}
	}
	else if( Type == 2 || NuevoPet == 0x0E2 ) //-- MonturaGhost || DarkHorse
	{
		_asm
		{
			JMP [MoveHorse]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr_Buffer]
		}
	}
}

__declspec(naked) void SetPlayerAnimation2_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x0054EADE;
	static DWORD Addrss2 = 0x0054EC8F;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV Fenrrir, ECX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation3_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x0054F6C0;
	static DWORD Addrss2 = 0x0054F6F6;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV Fenrrir, EDX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation4_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x0054F91A;
	static DWORD Addrss2 = 0x0054F928;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV Fenrrir, EDX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Fenrrir == 0x100 || Fenrrir == 0x101 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation5_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x0054FC8F;
	static DWORD Addrss2 = 0x0054FCD8;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV Fenrrir, EDX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation6_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x00550717;
	static DWORD Addrss2 = 0x00550767;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV Fenrrir, EAX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation7_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x00550778;
	static DWORD Addrss2 = 0x005507CD;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV Fenrrir, EAX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation8_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x005507DE;
	static DWORD Addrss2 = 0x00550833;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOVSX EDX,WORD PTR DS:[ECX + 0x22C]
		MOV Fenrrir, EDX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetPlayerAnimation9_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x00550844;
	static DWORD Addrss2 = 0x0055089C;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV Fenrrir, EAX
	}

	Type = recargaNuevoPet(Fenrrir);

	if(Fenrrir == 0x1EB8 || Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

#pragma optimize("t",off)

char PetPreviewScale(int a4, char a5)
{
	if(*(BYTE*)(a4 + 4))
	{
		char v8 = 0;

		if(a5)
		{
			v8 = 1;
		}
		else
		{
			float v5 = *(float*)(a4 + 256) * 0.009999999776482582;
			float v6 = *(float*)(a4 + 252) * 0.009999999776482582;
			v8 = sub_5DBA10(v6, v5, -20.0);
		}

		*(BYTE*)(a4 + 12) = v8;

		if(*(BYTE*)(a4 + 12))
		{
			DWORD dwItemNumber = *(DWORD*)(a4 + 48);

			if(*(DWORD *)(*(DWORD*)(a4 + 472) + 48) != 1163 && *(DWORD*)(a4 + 48) != 7827)
			{
				return 1;
			}

			if(a5)
			{
				*(float*)(a4 + 96) = *(float*)(a4 + 96);
			}
			else if(pPlayerState == 4)
			{
				if(gCustomPet2.CheckCustomPetByItem(dwItemNumber - 1171))
				{	
					if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
					{	
						if(gProtect.m_MainInfo.SelectCharacterType == 2)
						{
							*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171);
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
						{
							if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
							{
								*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171);
							}
							else
							{
								*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.5;
							}
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 4)
						{
							*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.0;
						}
						else
						{
							*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.3;
						}

					}
					else
					{
						if(gProtect.m_MainInfo.SelectCharacterType == 2)
						{
							*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.2;
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
						{
							if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
							{
								*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171);
							}
							else
							{
								*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.5;
							}
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 4)
						{
							*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.0;
						}
						else
						{
							*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171) + 0.2;
						}
					}
				}
				else
				{
					if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
					{							
						if(gProtect.m_MainInfo.SelectCharacterType == 2)
						{
							*(float*)(a4 + 96) = 1.0;
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 1)
						{
							if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
							{
								*(float*)(a4 + 96) = 1.0;
							}
							else
							{
								*(float*)(a4 + 96) = 1.0 + 0.5;
							}
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 4)
						{
							*(float*)(a4 + 96) = 1.0;
						}
						else
						{
							*(float*)(a4 + 96) = 1.3;
						}
					}
					else
					{	
						if(gProtect.m_MainInfo.SelectCharacterType == 1)
						{
							if (gProtect.m_MainInfo.SceneCharacterDowngradeType == 0)
							{
								*(float*)(a4 + 96) = 1.0;
							}
							else
							{
								*(float*)(a4 + 96) = 1.0 + 0.5;
							}
						}
						else if(gProtect.m_MainInfo.SelectCharacterType == 4)
						{
							*(float*)(a4 + 96) = 1.0;
						}
						else
						{
							*(float*)(a4 + 96) = 1.2;
						}
					}
				}
			}
			else if(dwItemNumber != 384 && dwItemNumber != 386 && dwItemNumber != 385 && dwItemNumber != 387)
			{
				*(float*)(a4 + 96) = 1.0;
			}

			if (pPlayerState > 4)
			{
				if(gCustomPet2.CheckCustomPetByItem(dwItemNumber - 1171))
				{
					*(float*)(a4 + 96) = gCustomPet2.GetScaleView(dwItemNumber - 1171);
				}
				else
				{
					*(float*)(a4 + 96) = 1.0;
				}
			}
			
			int v9 = 0;

			if(sub_4C8640((LPVOID)(*(DWORD*)(a4 + 472) + 484), 18))
			{
				v9 = 10;
			}
			
			pObjectMaxBug(a4, 0, 0, v9);
	
			float v10 = (double)((signed int)sub_9CFB8D() % 30 + 70) * 0.009999999776482582;

			if(dwItemNumber == 7827)
			{
				float v11[3];

				v11[0] = v10 * 0.5;
				v11[1] = v10 * 0.800000011920929;
				v11[2] = v10 * 0.6000000238418579;

				pPlayStaticEffect(32002, (DWORD*)(a4 + 252), 1.0, v11, a4, 0.0, 0);
			}
		}
	}

	return 1;
}

int __cdecl DrawObjectDropOnViewport(int a1) // 100%
{
  int result; // eax@301
  char v3; // [sp+7h] [bp-1h]@1

  DWORD dwItemNumber = *(DWORD *)(a1 + 48);
  
  *(float *)(a1 + 264) = 0.0;
  *(float *)(a1 + 268) = 0.0;
  *(float *)(a1 + 272) = -45.0;

  if ( dwItemNumber < 1171 || dwItemNumber >= 2195 )
  {
	if(gCustomPet2.CheckCustomPetByItem(dwItemNumber - 1171))
	{
		*(float *)(a1 + 264) = 270.0;
		*(float *)(a1 + 268) = 180.0;
		*(float *)(a1 + 272) = 45.0;
		*(float *)(a1 + 96) = gCustomPet2.GetScaleDrop(dwItemNumber - 1171);
	}
	
    if ( dwItemNumber != 3239 && dwItemNumber != 3240 && dwItemNumber != 3241 )
    {
      if ( (dwItemNumber < 3227 || dwItemNumber >= 3236)
        && (dwItemNumber < 3237 || dwItemNumber >= 3239) )
      {
        if ( dwItemNumber < 2195 || dwItemNumber >= 4243 )
        {
          if ( dwItemNumber < 4243 || dwItemNumber >= 4755 )
          {
            if ( (dwItemNumber < 4794 || dwItemNumber > 4799) && dwItemNumber != 4837 )
            {
              if ( (dwItemNumber < 5267 || dwItemNumber >= 6803) && dwItemNumber != 8494 )
              {
                if ( dwItemNumber < 7347 || dwItemNumber > 7349 )
                {
                  if ( dwItemNumber < 7375 || dwItemNumber > 7380 )
                  {
                    if ( dwItemNumber < 7385 || dwItemNumber > 7389 )
                    {
                      if ( dwItemNumber < 7415 || dwItemNumber > 7444 )
                      {
                        switch ( dwItemNumber )
                        {
                          case 0x1CC4:
                            *(float *)(a1 + 264) = 270.0;
                            *(float *)(a1 + 268) = 180.0;
                            *(float *)(a1 + 272) = 45.0;
                            *(float *)(a1 + 96) = 0.69999999;
                            break;
                          case 0x1CC5:
                            *(float *)(a1 + 264) = 250.0;
                            *(float *)(a1 + 268) = 180.0;
                            *(float *)(a1 + 272) = 45.0;
                            break;
                          case 0x20C0:
                            *(float *)(a1 + 96) = 0.89999998;
                            *(float *)(a1 + 264) = 0.0;
                            *(float *)(a1 + 272) = 90.0;
                            break;
                          default:
                            if ( dwItemNumber < 8385 || dwItemNumber > 8387 )
                            {
                              if ( dwItemNumber == 8388 )
                              {
                                *(float *)(a1 + 96) = 0.89999998;
                                *(float *)(a1 + 264) = 0.0;
                                *(float *)(a1 + 272) = 90.0;
                              }
                              else if ( dwItemNumber == 8389 )
                              {
                                *(float *)(a1 + 96) = 0.25999999;
                                *(float *)(a1 + 264) = 0.0;
                                *(float *)(a1 + 272) = 90.0;
                              }
                              else if ( dwItemNumber < 8371 || dwItemNumber > 8373 )
                              {
                                if ( dwItemNumber < 9530 || dwItemNumber > 9532 )
                                {
                                  if ( dwItemNumber < 7873 || dwItemNumber > 7875 )
                                  {
                                    if ( dwItemNumber == 8393 )
                                    {
                                      *(float *)(a1 + 96) = 0.5;
                                      *(float *)(a1 + 264) = 90.0;
                                    }
                                    else if ( dwItemNumber == 8397 )
                                    {
                                      *(float *)(a1 + 96) = 0.30000001;
                                      *(float *)(a1 + 272) = 90.0;
                                    }
                                    else if ( dwItemNumber != 8398 && dwItemNumber != 8399 )
                                    {
                                      if ( dwItemNumber != 8400 && dwItemNumber != 8401 )
                                      {
                                        if ( dwItemNumber == 8392 )
                                        {
                                          *(float *)(a1 + 96) = 0.2;
                                          *(float *)(a1 + 272) = 90.0;
                                        }
                                        else if ( dwItemNumber != 7870
                                               && dwItemNumber != 7871
                                               && dwItemNumber != 7872 )
                                        {
                                          if ( dwItemNumber < 8409 || dwItemNumber > 8410 )
                                          {
                                            if ( dwItemNumber < 8411 || dwItemNumber > 8416 )
                                            {
                                              if ( dwItemNumber == 7886 )
                                              {
                                                *(float *)(a1 + 96) = 0.2;
                                                *(float *)(a1 + 272) = 90.0;
                                              }
                                              else if ( dwItemNumber < 7881 || dwItemNumber > 7885 )
                                              {
                                                if ( dwItemNumber < 8417 || dwItemNumber > 8421 )
                                                {
                                                  switch ( dwItemNumber )
                                                  {
                                                    case 0x1ECF:
                                                      *(float *)(a1 + 96) = 1.5;
                                                      *(float *)(a1 + 272) = 90.0;
                                                      break;
                                                    case 0x1ED0:
                                                      *(float *)(a1 + 96) = 0.5;
                                                      *(float *)(a1 + 264) = 90.0;
                                                      break;
                                                    case 0x20E6:
                                                      *(float *)(a1 + 96) = 0.30000001;
                                                      *(float *)(a1 + 264) = 90.0;
                                                      break;
                                                    default:
                                                      if ( dwItemNumber < 8484 || dwItemNumber > 8489 )
                                                      {
                                                        if ( dwItemNumber < 7952 || dwItemNumber > 7954 )
                                                        {
                                                          switch ( dwItemNumber )
                                                          {
                                                            case 0x20EF:
                                                              *(float *)(a1 + 96) = 0.5;
                                                              *(float *)(a1 + 264) = 90.0;
                                                              break;
                                                            case 0x20F0:
                                                              *(float *)(a1 + 96) = 0.5;
                                                              *(float *)(a1 + 264) = 90.0;
                                                              break;
                                                            case 0x20F2:
                                                              *(float *)(a1 + 96) = 0.5;
                                                              *(float *)(a1 + 264) = 90.0;
                                                              break;
                                                            case 0x20F1:
                                                              *(float *)(a1 + 96) = 0.60000002;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            case 0x20E7:
                                                              *(float *)(a1 + 96) = 0.80000001;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            case 0x20E8:
                                                              *(float *)(a1 + 96) = 0.89999998;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            case 0x20E9:
                                                              *(float *)(a1 + 96) = 0.69999999;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            case 0x20EA:
                                                              *(float *)(a1 + 96) = 1.3;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            case 0x20EB:
                                                              *(float *)(a1 + 96) = 0.69999999;
                                                              *(float *)(a1 + 264) = 180.0;
                                                              *(float *)(a1 + 268) = 180.0;
                                                              break;
                                                            case 0x20EC:
                                                              *(float *)(a1 + 96) = 0.69999999;
                                                              *(float *)(a1 + 264) = 30.0;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            case 0x20ED:
                                                              *(float *)(a1 + 96) = 0.69999999;
                                                              *(float *)(a1 + 264) = 30.0;
                                                              *(float *)(a1 + 272) = 90.0;
                                                              break;
                                                            default:
                                                              if ( dwItemNumber < 7889
                                                                || dwItemNumber > 7890 )
                                                              {
                                                                if ( dwItemNumber < 8436
                                                                  || dwItemNumber > 8437 )
                                                                {
                                                                  if ( dwItemNumber == 8479 )
                                                                  {
                                                                    *(float *)(a1 + 96) = 0.5;
                                                                    *(float *)(a1 + 272) = 90.0;
                                                                  }
                                                                  else if ( dwItemNumber == 8435 )
                                                                  {
                                                                    *(float *)(a1 + 96) = 0.2;
                                                                    *(float *)(a1 + 272) = 90.0;
                                                                  }
                                                                  else if ( dwItemNumber < 7891
                                                                         || dwItemNumber > 7892 )
                                                                  {
                                                                    if ( (dwItemNumber < 8394
                                                                       || dwItemNumber > 8396)
                                                                      && (dwItemNumber < 8496
                                                                       || dwItemNumber > 8498) )
                                                                    {
                                                                      switch ( dwItemNumber )
                                                                      {
                                                                        case 0x1EC4:
                                                                          *(float *)(a1 + 264) = 90.0;
                                                                          *(float *)(a1 + 268) = 0.0;
                                                                          *(float *)(a1 + 96) = 0.30000001;
                                                                          break;
                                                                        case 0x1EC5:
                                                                          *(float *)(a1 + 264) = 0.0;
                                                                          *(float *)(a1 + 96) = 0.60000002;
                                                                          break;
                                                                        case 0x1EC6:
                                                                          *(float *)(a1 + 264) = 90.0;
                                                                          *(float *)(a1 + 96) = 0.44999999;
                                                                          break;
                                                                        default:
                                                                          if ( dwItemNumber != 8403
                                                                            && dwItemNumber != 8492 )
                                                                          {
                                                                            switch ( dwItemNumber )
                                                                            {
                                                                              case 0x1EC7:
                                                                                *(float *)(a1 + 264) = 0.0;
                                                                                *(float *)(a1 + 96) = 1.2;
                                                                                break;
                                                                              case 0x1EC8:
                                                                                *(float *)(a1 + 264) = 0.0;
                                                                                *(float *)(a1 + 96) = 1.2;
                                                                                break;
                                                                              case 0x20D4:
                                                                                *(float *)(a1 + 264) = 90.0;
                                                                                *(float *)(a1 + 96) = 0.60000002;
                                                                                break;
                                                                              case 0x20D5:
                                                                                *(float *)(a1 + 264) = 90.0;
                                                                                *(float *)(a1 + 96) = 0.80000001;
                                                                                break;
                                                                              case 0x20D6:
                                                                                *(float *)(a1 + 264) = 270.0;
                                                                                *(float *)(a1 + 96) = 0.80000001;
                                                                                break;
                                                                              case 0x20D7:
                                                                                *(float *)(a1 + 272) = -135.0;
                                                                                *(float *)(a1 + 96) = 0.60000002;
                                                                                break;
                                                                              case 0x2529:
                                                                                *(float *)(a1 + 264) = 90.0;
                                                                                break;
                                                                              default:
                                                                                if ( dwItemNumber != 9517
                                                                                  && dwItemNumber != 9518 )
                                                                                {
                                                                                  switch ( dwItemNumber )
                                                                                  {
                                                                                    case 0x252F:
                                                                                      *(float *)(a1 + 96) = 0.2;
                                                                                      break;
                                                                                    case 0x252A:
                                                                                      *(float *)(a1 + 264) = 90.0;
                                                                                      break;
                                                                                    case 0x20AA:
                                                                                      *(float *)(a1 + 268) = 45.0;
                                                                                      *(float *)(a1 + 272) = 45.0;
                                                                                      break;
                                                                                    case 0x20AB:
                                                                                      *(float *)(a1 + 272) = 45.0;
                                                                                      break;
                                                                                    default:
                                                                                      if ( (dwItemNumber < 8364
                                                                                         || dwItemNumber >= 8366)
                                                                                        && dwItemNumber != 7841 )
                                                                                      {
                                                                                        switch ( dwItemNumber )
                                                                                        {
                                                                                          case 0x20A4:
                                                                                            *(float *)(a1 + 264) = 90.0;
                                                                                            break;
                                                                                          case 0x20D2:
                                                                                            *(float *)(a1 + 264) = 70.0;
                                                                                            *(float *)(a1 + 96) = 1.5;
                                                                                            break;
                                                                                          case 0x20F6:
                                                                                            *(float *)(a1 + 264) = 70.0;
                                                                                            *(float *)(a1 + 272) = 0.0;
                                                                                            *(float *)(a1 + 96) = 1.0;
                                                                                            break;
                                                                                          case 0x20C7:
                                                                                            *(float *)(a1 + 272) = -10.0;
                                                                                            *(float *)(a1 + 96) = 0.40000001;
                                                                                            break;
                                                                                          case 0x20A5:
                                                                                            *(float *)(a1 + 272) = 270.0;
                                                                                            *(float *)(a1 + 264) = 270.0;
                                                                                            break;
                                                                                          case 0x20A6:
                                                                                            *(float *)(a1 + 264) = 270.0;
                                                                                            *(float *)(a1 + 272) = 90.0;
                                                                                            break;
                                                                                          case 0x20B0:
                                                                                            *(float *)(a1 + 264) = 90.0;
                                                                                            *(float *)(a1 + 272) = 70.0;
                                                                                            break;
                                                                                          case 0x2530:
                                                                                            *(float *)(a1 + 264) = 115.0;
                                                                                            *(float *)(a1 + 268) = 75.0;
                                                                                            *(float *)(a1 + 272) = 8.0;
                                                                                            *(float *)(a1 + 96) = 0.40000001;
                                                                                            break;
                                                                                          default:
                                                                                            if ( dwItemNumber != 7843
                                                                                              && dwItemNumber != 7844 )
                                                                                            {
                                                                                              switch ( dwItemNumber )
                                                                                              {
                                                                                                case 0x1EA5:
                                                                                                  *(float *)(a1 + 264) = 165.0;
                                                                                                  *(float *)(a1 + 268) = -168.0;
                                                                                                  *(float *)(a1 + 272) = 198.0;
                                                                                                  *(float *)(a1 + 96) = 0.47999999;
                                                                                                  break;
                                                                                                case 0x1EB1:
                                                                                                  *(float *)(a1 + 264) = -45.0;
                                                                                                  *(float *)(a1 + 268) = 0.0;
                                                                                                  *(float *)(a1 + 272) = 45.0;
                                                                                                  *(float *)(a1 + 96) = 0.5;
                                                                                                  break;
                                                                                                case 0x2535:
                                                                                                  *(float *)(a1 + 272) = 45.0;
                                                                                                  *(float *)(a1 + 96) = 0.5;
                                                                                                  break;
                                                                                                case 0x2531:
                                                                                                  *(float *)(a1 + 264) = 160.0;
                                                                                                  *(float *)(a1 + 268) = -183.0;
                                                                                                  *(float *)(a1 + 272) = 198.0;
                                                                                                  *(float *)(a1 + 96) = 0.38;
                                                                                                  break;
                                                                                                case 0x2532:
                                                                                                  *(float *)(a1 + 264) = 160.0;
                                                                                                  *(float *)(a1 + 268) = -183.0;
                                                                                                  *(float *)(a1 + 272) = 198.0;
                                                                                                  *(float *)(a1 + 96) = 0.54000002;
                                                                                                  break;
                                                                                                case 0x20A8:
                                                                                                  *(float *)(a1 + 264) = 270.0;
                                                                                                  *(float *)(a1 + 272) = 90.0;
                                                                                                  break;
                                                                                                case 0x252C:
                                                                                                  *(float *)(a1 + 272) = 45.0;
                                                                                                  break;
                                                                                                case 0x20A7:
                                                                                                  *(float *)(a1 + 272) = 45.0;
                                                                                                  break;
                                                                                                default:
                                                                                                  if ( dwItemNumber < 7848 || dwItemNumber > 7851 )
                                                                                                  {
                                                                                                    switch ( dwItemNumber )
                                                                                                    {
                                                                                                      case 0x1EB4:
                                                                                                        *(float *)(a1 + 272) = 45.0;
                                                                                                        *(float *)(a1 + 96) = 1.2;
                                                                                                        break;
                                                                                                      case 0x1EB5:
                                                                                                        *(float *)(a1 + 264) = 90.0;
                                                                                                        break;
                                                                                                      case 0x1EB6:
                                                                                                        *(float *)(a1 + 272) = 90.0;
                                                                                                        break;
                                                                                                      case 0x1EB7:
                                                                                                        *(float *)(a1 + 272) = 90.0;
                                                                                                        *(float *)(a1 + 96) = 1.3;
                                                                                                        break;
                                                                                                      case 0x1EB8:
                                                                                                        *(float *)(a1 + 272) = 180.0;
                                                                                                        break;
                                                                                                      case 0x20A3:
                                                                                                        *(float *)(a1 + 264) = 270.0;
                                                                                                        *(float *)(a1 + 272) = 45.0;
                                                                                                        break;
                                                                                                      case 0x20BD:
                                                                                                        *(float *)(a1 + 264) = 270.0;
                                                                                                        *(float *)(a1 + 272) = -15.0;
                                                                                                        *(float *)(a1 + 96) = 1.3;
                                                                                                        break;
                                                                                                      default:
                                                                                                        if ( dwItemNumber != 8382 && dwItemNumber != 8383 )
                                                                                                        {
                                                                                                          if ( (dwItemNumber < 8870 || dwItemNumber > 8878) && dwItemNumber != 8490 && dwItemNumber != 8491 )
                                                                                                          {
                                                                                                            if ( dwItemNumber == 7893 )
                                                                                                            {
                                                                                                              *(float *)(a1 + 264) = 270.0;
                                                                                                              *(float *)(a1 + 96) = 1.0;
                                                                                                            }
                                                                                                            else if ( dwItemNumber == 8439 )
                                                                                                            {
                                                                                                              *(float *)(a1 + 264) = 180.0;
                                                                                                              *(float *)(a1 + 96) = 1.0;
                                                                                                            }
                                                                                                            else if ( dwItemNumber < 7910 || dwItemNumber > 7920 )
                                                                                                            {
                                                                                                              if ( dwItemNumber != 7924 && dwItemNumber != 7925 && dwItemNumber != 8430 && dwItemNumber != 8508 )
                                                                                                              {
                                                                                                                if ( dwItemNumber != 8449 && dwItemNumber != 8450 )
                                                                                                                {
                                                                                                                  switch ( dwItemNumber )
                                                                                                                  {
                                                                                                                    case 0x1EFE:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1EFB:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1EFC:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1EFA:
                                                                                                                      *(float *)(a1 + 264) = 0.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x2118:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F00:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F01:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F02:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F03:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F04:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F05:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F06:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x2103:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x2104:
                                                                                                                      *(float *)(a1 + 264) = 270.0;
                                                                                                                      *(float *)(a1 + 96) = 1.0;
                                                                                                                      break;
                                                                                                                    case 0x1F07:
                                                                                                                      *(float *)(a1 + 96) = 0.5;
                                                                                                                      *(float *)(a1 + 264) = 90.0;
                                                                                                                      break;
                                                                                                                    case 0x1F0C:
                                                                                                                      *(float *)(a1 + 96) = 0.5;
                                                                                                                      *(float *)(a1 + 264) = 90.0;
                                                                                                                      break;
                                                                                                                    case 0x1F0E:
                                                                                                                      *(float *)(a1 + 96) = 0.40000001;
                                                                                                                      *(float *)(a1 + 264) = 30.0;
                                                                                                                      break;
                                                                                                                    default:
                                                                                                                      if ( dwItemNumber < 7315 || dwItemNumber >= 7827 )
                                                                                                                      {
                                                                                                                        v3 = 0;
                                                                                                                      }
                                                                                                                      else
                                                                                                                      {
                                                                                                                        *(float *)(a1 + 264) = 270.0;
                                                                                                                        *(float *)(a1 + 272) = 45.0;
                                                                                                                      }
                                                                                                                      break;
                                                                                                                  }
                                                                                                                }
                                                                                                                else
                                                                                                                {
                                                                                                                  *(float *)(a1 + 264) = 270.0;
                                                                                                                  *(float *)(a1 + 96) = 1.0;
                                                                                                                }
                                                                                                              }
                                                                                                              else
                                                                                                              {
                                                                                                                *(float *)(a1 + 264) = 270.0;
                                                                                                                *(float *)(a1 + 96) = 1.0;
                                                                                                              }
                                                                                                            }
                                                                                                            else
                                                                                                            {
                                                                                                              *(float *)(a1 + 96) = 0.5;
                                                                                                              *(float *)(a1 + 272) = 90.0;
                                                                                                            }
                                                                                                          }
                                                                                                          else
                                                                                                          {
                                                                                                            *(float *)(a1 + 264) = 270.0;
                                                                                                            *(float *)(a1 + 96) = 0.80000001;
                                                                                                          }
                                                                                                        }
                                                                                                        else
                                                                                                        {
                                                                                                          *(float *)(a1 + 264) = 270.0;
                                                                                                          *(float *)(a1 + 272) = -15.0;
                                                                                                          *(float *)(a1 + 96) = 1.0;
                                                                                                        }
                                                                                                        break;
                                                                                                    }
                                                                                                  }
                                                                                                  else
                                                                                                  {
                                                                                                    *(float *)(a1 + 272) = 20.0;
                                                                                                  }
                                                                                                  break;
                                                                                              }
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                              *(float *)(a1 + 264) = -45.0;
                                                                                              *(float *)(a1 + 268) = -5.0;
                                                                                              *(float *)(a1 + 272) = 18.0;
                                                                                              *(float *)(a1 + 96) = 0.47999999;
                                                                                            }
                                                                                            break;
                                                                                        }
                                                                                      }
                                                                                      else
                                                                                      {
                                                                                        *(float *)(a1 + 272) = 45.0;
                                                                                      }
                                                                                      break;
                                                                                  }
                                                                                }
                                                                                else
                                                                                {
                                                                                  *(float *)(a1 + 264) = 270.0;
                                                                                  *(float *)(a1 + 272) = 45.0;
                                                                                }
                                                                                break;
                                                                            }
                                                                          }
                                                                          else
                                                                          {
                                                                            *(float *)(a1 + 264) = 0.0;
                                                                            *(float *)(a1 + 96) = 0.80000001;
                                                                          }
                                                                          break;
                                                                      }
                                                                    }
                                                                    else
                                                                    {
                                                                      *(float *)(a1 + 264) = 0.0;
                                                                      *(float *)(a1 + 96) = 0.30000001;
                                                                    }
                                                                  }
                                                                  else
                                                                  {
                                                                    if ( dwItemNumber == 7891 )
                                                                    {
                                                                      *(float *)(a1 + 96) = 0.20999999;
                                                                    }
                                                                    else if ( dwItemNumber == 7892 )
                                                                    {
                                                                      *(float *)(a1 + 96) = 0.5;
                                                                    }
                                                                    *(float *)(dwItemNumber + 272) = 70.0;
                                                                  }
                                                                }
                                                                else
                                                                {
                                                                  *(float *)(a1 + 96) = 0.5;
                                                                  *(float *)(a1 + 272) = 90.0;
                                                                }
                                                              }
                                                              else
                                                              {
                                                                *(float *)(a1 + 96) = 0.5;
                                                                *(float *)(a1 + 264) = 90.0;
                                                              }
                                                              break;
                                                          }
                                                        }
                                                        else
                                                        {
                                                          *(float *)(a1 + 96) = 0.5;
                                                          *(float *)(a1 + 264) = 90.0;
                                                        }
                                                      }
                                                      else
                                                      {
                                                        *(float *)(a1 + 96) = 0.30000001;
                                                        *(float *)(a1 + 264) = 90.0;
                                                      }
                                                      break;
                                                  }
                                                }
                                                else
                                                {
                                                  *(float *)(a1 + 96) = 0.5;
                                                  *(float *)(a1 + 272) = 90.0;
                                                }
                                              }
                                              else
                                              {
                                                *(float *)(a1 + 96) = 0.69999999;
                                                *(float *)(a1 + 272) = 90.0;
                                              }
                                            }
                                            else
                                            {
                                              *(float *)(a1 + 96) = 0.5;
                                              *(float *)(a1 + 272) = 90.0;
                                            }
                                          }
                                          else
                                          {
                                            *(float *)(a1 + 96) = 0.60000002;
                                            *(float *)(a1 + 272) = 90.0;
                                          }
                                        }
                                        else
                                        {
                                          *(float *)(a1 + 96) = 0.5;
                                          *(float *)(a1 + 264) = 90.0;
                                        }
                                      }
                                      else
                                      {
                                        *(float *)(a1 + 96) = 0.30000001;
                                        *(float *)(a1 + 264) = 90.0;
                                      }
                                    }
                                    else
                                    {
                                      *(float *)(a1 + 96) = 0.30000001;
                                      *(float *)(a1 + 264) = 90.0;
                                      *(float *)(a1 + 268) = 90.0;
                                    }
                                  }
                                  else
                                  {
                                    *(float *)(a1 + 96) = 0.5;
                                    *(float *)(a1 + 264) = 90.0;
                                  }
                                }
                                else
                                {
                                  *(float *)(a1 + 96) = 0.69999999;
                                  *(float *)(a1 + 264) = 0.0;
                                  *(float *)(a1 + 272) = 90.0;
                                }
                              }
                              else
                              {
                                *(float *)(a1 + 96) = 0.69999999;
                                *(float *)(a1 + 264) = 0.0;
                                *(float *)(a1 + 272) = 90.0;
                              }
                            }
                            else
                            {
                              *(float *)(a1 + 96) = 0.69999999;
                              *(float *)(a1 + 264) = 90.0;
                            }
                            break;
                        }
                      }
                      else
                      {
                        *(float *)(a1 + 264) = 0.0;
                        *(float *)(a1 + 96) = 0.60000002;
                      }
                    }
                    else
                    {
                      *(float *)(a1 + 264) = 0.0;
                      *(float *)(a1 + 96) = 0.60000002;
                    }
                  }
                  else
                  {
                    *(float *)(a1 + 264) = 0.0;
                    *(float *)(a1 + 96) = 0.60000002;
                  }
                }
                else
                {
                  *(float *)(a1 + 96) = 0.30000001;
                  *(float *)(a1 + 264) = 0.0;
                  *(float *)(a1 + 272) = 90.0;
                }
              }
              else
              {
                *(float *)(a1 + 264) = 270.0;
              }
            }
            else
            {
              *(float *)(a1 + 96) = 1.5;
              *(float *)(a1 + 272) = 45.0;
            }
          }
          else
          {
            *(float *)(a1 + 268) = 270.0;
            *(float *)(a1 + 272) = 225.0;
          }
        }
        else
        {
          *(float *)(a1 + 264) = 0.0;
          *(float *)(a1 + 268) = 270.0;
        }
      }
      else
      {
        *(float *)(a1 + 264) = 90.0;
        *(float *)(a1 + 268) = 0.0;
      }
    }
    else
    {
      *(float *)(a1 + 264) = 0.0;
      *(float *)(a1 + 268) = 0.0;
    }
  }
  else
  {
    *(float *)(a1 + 264) = 60.0;
    if ( dwItemNumber == 1190 )
      *(float *)(a1 + 96) = 0.69999999;
  }
  result = (unsigned __int8)v3;
  if ( v3 != 1 )
  {
    if ( dwItemNumber < 7962 || dwItemNumber > 7972 )
    {
      if ( dwItemNumber != 8499 && (result = a1, dwItemNumber != 8500) )
      {
        if ( sub_5C9370_Addr(dwItemNumber - 1171, 0) )
        {
          result = a1;
          *(float *)(a1 + 264) = 250.0;
          *(float *)(a1 + 268) = 180.0;
          *(float *)(a1 + 272) = 45.0;
        }
        else if ( (dwItemNumber < 4814 || dwItemNumber > 4816) && dwItemNumber != 4838 )
        {
          if ( dwItemNumber < 8881 || (result = a1, dwItemNumber > 8887) )
          {
            result = a1;
            if ( dwItemNumber < 8501 || dwItemNumber > 8502 )
            {
              *(float *)(a1 + 264) = 0.0;
            }
            else
            {
              *(float *)(a1 + 264) = 270.0;
              result = a1;
              *(float *)(a1 + 272) = 45.0;
              *(float *)(a1 + 96) = 0.89999998;
            }
          }
          else
          {
            *(float *)(a1 + 264) = 270.0;
            *(float *)(a1 + 96) = 0.80000001;
          }
        }
        else
        {
          result = a1;
          *(float *)(a1 + 96) = 1.0;
          *(float *)(a1 + 272) = 45.0;
        }
      }
      else
      {
        *(float *)(a1 + 96) = 0.2;
        *(float *)(a1 + 264) = 90.0;
      }
    }
    else
    {
      result = a1;
      *(float *)(a1 + 96) = 0.2;
      *(float *)(a1 + 264) = 90.0;
    }
  }
  return result;
}

int recargaNuevoFenrir(int NuevoPet)
{
	int t = 0;
	t = gCustomPet2.GetInfoPetEffect(NuevoPet - 1171);

	return t;
}

#pragma optimize("t",on)

__declspec(naked) void SetEffect_Fenrir()
{
	static DWORD Fenrrir;
	static int Type;
	static DWORD Addrss1 = 0x005E03E3;
	static DWORD Addrss2 = 0x005E05A4;
	static DWORD Addrss3 = 0x005E10AE;

	static DWORD CallMe1 = 0x004DB0C0;
	static DWORD CallMe2 = 0x00546860;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+8]
		MOV EAX, DWORD PTR DS:[ECX + 0x30]
		MOV Fenrrir, EAX
	}

	Type = recargaNuevoFenrir(Fenrrir);

	if(Fenrrir == 0x180 || Fenrrir == 0x181 || Fenrrir == 0x182 || Fenrrir == 0x183 ||Type != 0)
	{
		_asm
		{
			FLD DWORD PTR DS:[0x5EF5A1C]
			FMUL QWORD PTR DS:[0xD281C0]
			FSTP DWORD PTR SS:[EBP-0x55C]
			FLD DWORD PTR SS:[EBP-0x55C]
			PUSH ECX                                 ; /Arg1
			FSTP DWORD PTR SS:[ESP]                  ; |
			CALL CallMe1                      ; \main1.004DB0C0
			ADD ESP,0x4
			FMUL QWORD PTR DS:[0xD27C28]
			FSTP DWORD PTR SS:[EBP-0xAC]
			PUSH ECX                                 ; /Arg1
			FLD1                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x14]            ; |
			CALL CallMe2                      ; \main1.00546860
			MOV EDX,DWORD PTR SS:[EBP-0x14]
			FLD1
			FSTP DWORD PTR DS:[EDX+0x48]
			MOV EAX,DWORD PTR SS:[EBP-0x14]
			FLD1
			FSTP DWORD PTR DS:[EAX+0x4C]
			MOV ECX,DWORD PTR SS:[EBP-0x14]
			FLD1
			FSTP DWORD PTR DS:[ECX+0x50]
		}

		if(Fenrrir == 0x183 ||Type == 2)
		{
			_asm
			{
				JMP [Addrss1]
			}
		}
		else
		{
			_asm
			{
				JMP [Addrss2]
			}
		}
		
	}
	else
	{
		_asm
		{
			JMP [Addrss3]
		}
	}
}

#pragma optimize("t",off)

/*char CustomPet::CreateEffect(int a4, char a5)
{
	if(*(BYTE*)(a4 + 4))
	{
		char v8 = 0;

		if(a5)
		{
			v8 = 1;
		}
		else
		{
			float v5 = *(float*)(a4 + 256) * 0.009999999776482582;
			float v6 = *(float*)(a4 + 252) * 0.009999999776482582;
			v8 = sub_5DBA10(v6, v5, -20.0);
		}
	*(BYTE*)(a4 + 12) = v8;

		if(*(BYTE*)(a4 + 12))
		{
			DWORD dwItemNumber = *(DWORD*)(a4 + 48);
		
			/*for(int n = 0; n < MAX_PETEX_EFFECT; n++)
			{

			if(gPetEffect.m_Effect[n].ItemIndex+1171 == dwItemNumber)
				{
					float ItemColor[3];

					ItemColor[0] = gPetEffect.m_Effect[n].ColorR;

					ItemColor[1] = gPetEffect.m_Effect[n].ColorG;

					ItemColor[2] = gPetEffect.m_Effect[n].ColorB;
					((void(__thiscall*)(void*,DWORD,DWORD,DWORD,DWORD))0x00544E60)((void*)(DWORD*)(a4 + 252),a5,(DWORD)pGetModel(pModelThis(), dwItemNumber),gPetEffect.m_Effect[n].EffectValue,gPetEffect.m_Effect[n].EffectLevel);

					((void(*)(DWORD,DWORD*,DWORD,float*,DWORD,float,DWORD))0x0074CD30)(gPetEffect.m_Effect[n].EffectIndex, (DWORD*)(a4 + 252), (DWORD)pGetModel(pModelThis(), dwItemNumber), ItemColor,gPetEffect.m_Effect[n].ColorSize,gPetEffect.m_Effect[n].ColorMain,gPetEffect.m_Effect[n].ColorSide);
		
				}

			if(ITEM2(gPetEffect.m_Effect2[n].ItemType, gPetEffect.m_Effect2[n].ItemIndex) == dwItemNumber)

				{
					float ItemColor[3];
					ItemColor[0] = gPetEffect.m_Effect2[n].ColorR;

					ItemColor[1] = gPetEffect.m_Effect2[n].ColorG;

					ItemColor[2] = gPetEffect.m_Effect2[n].ColorB;

					pPlayStaticEffect(gPetEffect.m_Effect2[n].EffectIndex, (DWORD*)(a4 + 252), gPetEffect.m_Effect2[n].ColorSize, ItemColor, a4, gPetEffect.m_Effect2[n].ColorMain, (DWORD)gPetEffect.m_Effect2[n].ColorSide);
				}
			}*//*

			if(*(DWORD *)(*(DWORD*)(a4 + 472) + 48) != 1163 && *(DWORD*)(a4 + 48) != 7827)
			{
				return 1;
			}

			if(a5)
			{
				*(float*)(a4 + 96) = *(float*)(a4 + 96);
			}
			else if(pPlayerState == 4)
			{
				*(float*)(a4 + 96) = 1.2;
			}
			else if(dwItemNumber != 384 && dwItemNumber != 386 && dwItemNumber != 385 && dwItemNumber != 387)
			{
				*(float*)(a4 + 96) = 1.0;
			}	
			   
			int ItemGroup = (dwItemNumber - 1171) / 512;
			int ItemID = (dwItemNumber - 1171) % 512;
			if(gCustomPet2.CheckCustomPetByItem(ItemGroup, ItemID))
			{
				CUSTOM_PET_INFO* lpInfo = gCustomPet2.GetInfoByItem(ItemGroup, ItemID);

				if(lpInfo)
				{
					*(float*)(a4 + 96) = lpInfo->PetSize;
				}
			}
			int v9 = 0;

			if(pet_4C8640((LPVOID)(*(DWORD*)(a4 + 472) + 484), 18))
			{
				v9 = 10;
			}
			
			pObjectMaxBug(a4, 0, 0, v9);
	
			float v10 = (double)((signed int)sub_9CFB8D() % 30 + 70) * 0.009999999776482582;

			if(dwItemNumber == 7827)
			{
				float v11[3];

				v11[0] = v10 * 0.5;
				v11[1] = v10 * 0.800000011920929;
				v11[2] = v10 * 0.6000000238418579;

				pPlayStaticEffect(32002, (DWORD*)(a4 + 252), 1.0, v11, a4, 0.0, 0);		
			}
		}
	}

	return 1;
}*/

__declspec(naked) void SetHorseSkill()
{
	static DWORD Horse;
	static int Type;
	static DWORD Addrss1 = 0x00814116;
	static DWORD Addrss2 = 0x0081413A;
	_asm
	{
		MOV EAX,DWORD PTR DS:[0x7BC4F04]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV Horse, ECX
	}

	Type = recargaNuevoPet(Horse);

	if(Horse == 0x1E97 || Type == 2)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}

}

__declspec(naked) void SetDinoAnimation1()
{
	static int Type;
	static DWORD dino;
	static DWORD Addrss1 = 	0x0054ED6A;		//dark horse 0x0054ECA0;
	static DWORD Addrss2 = 	0x0054ED64;		//dark horse 0x0054ECFC;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV dino, EAX
	}

	Type = recargaNuevoPet(dino);

	if(dino == 0x1E95 || dino == 0x1E96 || Type == 3 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetDinoAnimation2()
{
	static int Type;
	static DWORD dino;
	static DWORD Addrss1 = 	0x0054FD5C;		//dark horse 0x0054ECA0;
	static DWORD Addrss2 = 	0x0054FD56;		//dark horse 0x0054ECFC;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV dino, ECX
	}

	Type = recargaNuevoPet(dino);

	if(dino == 0x1EB8 ||dino == 0x1E95 || dino == 0x1E96 || Type == 3 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void SetGuardian1()
{
	static DWORD NuevoPet;
	static int Type;
	static DWORD MoveUniria = 0x00501597; //OK
	static DWORD MoveHorse = 0x00501545; //OK
	static DWORD MoveAngel = 0x00501565; //OK
	static DWORD MoveSatan = 0x0050156E; //OK
	static DWORD MoveFenrrir = 0x0050153C; //OK

	static DWORD Bufferx = 0x00501637;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0x14]
		MOV EAX,DWORD PTR DS:[EDX+0x30]
		MOV DWORD PTR SS:[EBP-0x4],EAX
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV NuevoPet, ECX
	}

	Type = recargaNuevoPet(NuevoPet);

	if( NuevoPet == 0x180 ||  NuevoPet == 0x181 ||  NuevoPet == 0x182 || NuevoPet == 0x183 || Type == 1 ) //-- Pet Fenrrir
	{
		_asm
		{
			JMP [MoveFenrrir]
		}
	}
	else if( Type == 2 || NuevoPet == 0x0E2 ) //-- MonturaGhost || DarkHorse
	{
		_asm
		{
			JMP [MoveHorse]
		}
	}
	if( NuevoPet == 0x143 || NuevoPet == 0x0E9 || Type == 3 ) //-- Uniria || Dinorant
	{
		_asm
		{
			JMP [MoveUniria]
		}
	}
	else if( NuevoPet == 0x1E93 || Type == 0) //-- PetAngel
	{
		_asm
		{
			JMP [MoveAngel]
		}
	}
	else if( NuevoPet == 0x1E94) //-- PetSatan
	{
		_asm
		{
			JMP [MoveSatan]
		}
	}
	else
	{
		_asm
		{
			JMP [Bufferx]
		}
	}
}

__declspec(naked) void SetGuardian2()
{
	static DWORD Addrs_JMP1 = 0x00503407;
	static DWORD Addrs_JMP2 = 0x00503712;
	static DWORD a4;
	static int Type;

	_asm
	{
		MOV ECX, DWORD PTR SS:[EBP + 0x8]
		MOV EDX, DWORD PTR DS:[ECX + 0x30]
		MOV a4,EDX
	}

	Type = recargaNuevoPet(a4);

	if(a4 == ITEM2(13,0) || a4 == ITEM2(13,1) || Type == 0)
	{
		_asm
		{
			JMP[Addrs_JMP1]
		}
	}
	else
	{
		_asm
		{
			JMP[Addrs_JMP2]
		}
	}
}

__declspec(naked) void ItemTooltipMontura()
{
	static DWORD Addrs_JMP1 = 0x007E4275;
	static DWORD Addrs_JMP2 = 0x007E4311;
	static DWORD Addrs_JMP3 = 0x007E43C3;
	static DWORD Addrs_JMP4 = 0x007E4294;
	static DWORD ItemID;
	static DWORD Type;

	_asm
	{
		MOV ECX, DWORD PTR SS:[EBP + 0x10]
		MOVSX EDX, WORD PTR DS:[ECX]
		MOV ItemID, EDX
	}

	Type = recargaNuevoPet(ItemID + 1171);

	if( ItemID == 6660 || Type == 2 || ItemID == 6661 )
	{
		_asm
		{
			MOV BYTE PTR SS:[EBP-0x81], 0
		}

		if(ItemID == 6660)
		{
			_asm
			{
				JMP[Addrs_JMP1]
			}
		}
		else if( Type == 2 )
		{
			_asm
			{
				MOV BYTE PTR SS:[EBP-0x81], 1
				JMP[Addrs_JMP4]
			}
		}
		else
		{
			_asm
			{
				JMP[Addrs_JMP2]
			}
		}
	}
	else
	{
		_asm
		{
			JMP[Addrs_JMP3]
		}
	}
}

__declspec(naked) void ItemTooltipMontura2()
{
	static DWORD Addrs_JMP1 = 0x004FA07A;
	static DWORD Addrs_JMP2 = 0x004FA0CB;
	//static DWORD Addrs_JMP3 = 0x007E43A1;
	static DWORD ItemID;
	static DWORD Type;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x10]
		MOVSX ECX,WORD PTR DS:[EAX]
		MOV ItemID, ECX
	}

	Type = recargaNuevoPet(ItemID + 1171);

	if(ItemID == 6660 || Type == 2)
	{
		_asm
		{
			JMP [Addrs_JMP1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrs_JMP2]
		}
	}
}

__declspec(naked) void ItemTooltipMontura3()
{
	static DWORD Addrs_JMP1 = 0x004FA2FA;
	static DWORD Addrs_JMP2 = 0x004FA3D7;
	//static DWORD Addrs_JMP3 = 0x007E43A1;
	static DWORD ItemID;
	static DWORD Type;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		MOVSX EDX,WORD PTR DS:[ECX]
		MOV ItemID, EDX
	}

	Type = recargaNuevoPet(ItemID + 1171);

	if(ItemID == 6660 || Type == 2)
	{
		_asm
		{
			JMP [Addrs_JMP1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrs_JMP2]
		}
	}
}

__declspec(naked) void ItemTooltipMontura4()
{
	static DWORD Addrs_JMP1 = 0x004FA635;
	static DWORD Addrs_JMP2 = 0x004FA6D6;
	//static DWORD Addrs_JMP3 = 0x007E43A1;
	static DWORD ItemID;
	static DWORD Type;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP+0x10]
		MOVSX EDX,WORD PTR DS:[ECX]
		MOV ItemID, EDX
	}

	Type = recargaNuevoPet(ItemID + 1171);

	if(ItemID == 6660 || Type == 2)
	{
		_asm
		{
			JMP [Addrs_JMP1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrs_JMP2]
		}
	}
}

__declspec(naked) void SetMontariasMove()
{
	static int Type;
	static DWORD mode;
	static DWORD Montaria;
	static DWORD Addrss1 = 	0x005BD045;		//dark horse 0x0054ECA0;
	static DWORD Addrss2 = 	0x005BD04E;		//dark horse 0x0054ECFC;
	
	_asm
	{
		MOVSX EDX,WORD PTR SS:[EBP-0x110]
		MOV Montaria, EDX
	}

	Type = recargaNuevoPet(Montaria);

	if(Montaria = -1 && Montaria == 6659 && Montaria == 6693 && Montaria == 6660 && Montaria == 6658 && Type == 2 && Type == 3 && Type == 1)
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}

}

__declspec(naked) void SetTestinho()
{
	static DWORD Buffer = 0x00834278;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+0xC]
		MOVSX EAX,WORD PTR DS:[EDX]
		CMP EAX,0x1AC9
		JMP [Buffer]

	}
}

__int16 PlayerAnimationMonturaSkill (int a3)
{
	__int16 result; // ax@5
	int v4; // eax@11
	int v5; // [sp+0h] [bp-4h]@1
	int Type;

	v5 = a3 + 776;
	
	Type = recargaNuevoPet(*(WORD *)(a3 + 556));

	if ( *(DWORD *)(a3 + 824) == 1163 )
	{
		sub_5509C0();
		if ( Type != 2 /*dark horse*/ && Type != 3 /*dinorant*/ && Type != 11 && *(WORD *)(a3 + 556) != 7829 && *(WORD *)(a3 + 556) != 7830 || *(BYTE *)(a3 + 14) )
		{
			if (Type != 1 /*fenrir*/ && *(WORD *)(a3 + 556) != 7864 || *(BYTE *)(a3 + 14) )
			{
				if ( pGetCharClass(*(BYTE *)(a3 + 19)) == CLASS_ELF || pGetCharClass(*(BYTE *)(a3 + 19)) == CLASS_SUMMONER)
				{
					result = pActionPlayerSend(v5, 150, 1);
				}
				else
				{
					v4 = (signed int)sub_9CFB8D() % 2;
					result = pActionPlayerSend(v5, v4 + 146, 1);
				}
			}
			else
			{
				result = pActionPlayerSend(v5, 97, 1);
			}
		}
		else
		{
			if(Type == 2)
			{
				result = pActionPlayerSend(v5, 86, 1);
			}
			else
			{
				result = pActionPlayerSend(v5, 155, 1);
			}
		}
	}
	else
	{
		if ( *(BYTE *)(a3 + 40) % 3 )
			pActionPlayerSend(a3 + 776, 4, 1);
		else
			pActionPlayerSend(a3 + 776, 3, 1);
		result = a3;
		++*(BYTE *)(a3 + 40);
	}
	return result;
}

__declspec(naked) void PlayerAnimation1_MoveSpeed()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00564BB4;
	static DWORD Addr2_JMP = 0x00564C1C;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if(PET == 0x1EB8 || Type == 1 ) //-- fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation2_MoveSpeed()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00564C2D;
	static DWORD Addr2_JMP = 0x00564C55;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if(PET == 0x1E97 || Type == 2 ) //-- Horse
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation3_MoveSpeed()
{
	static DWORD PET;
	static int Type;
	static DWORD Addr1_JMP = 0x00564C9C;
	static DWORD Addr2_JMP = 0x00564D08;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PET, ECX
	}

	Type = recargaNuevoPet(PET);

	if( PET == 7829 || PET == 7830 || Type == 3 ) //dinorant uniria
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void SetPlayerAnimation9()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF553;
	static DWORD Addrss2 = 0x005AF565;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EDX,WORD PTR DS:[ECX + 0x22C]
		MOV horse, EDX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void Enabled_SKILL_EARTHQUAKE()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr_Call = 0x7BC4F04;
	static DWORD Addr1_JMP = 0x008140D7;
	static DWORD Addr2_JMP = 0x008140DB;

	_asm
	{
		MOV EAX,DWORD PTR DS:[Addr_Call]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_BIRDS1()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005ADE58;
	static DWORD Addr2_JMP = 0x005ADE75;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP+8]
		MOVSX EAX,WORD PTR DS:[EDX+0x22C]
		MOV PetRender, EAX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1EB8 || Type == 1 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_BIRDS2()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005AE1EF;
	static DWORD Addr2_JMP = 0x005AE224;
	static DWORD Addr3_JMP = 0x005AE236;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1EB8 || Type == 1 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if(PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 2 || Type == 3 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_FIRE_SCREAM()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x005AF1F5;
	static DWORD Addr2_JMP = 0x005AF212;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+8]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if(PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 3 || Type == 2 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_EARTHQUAKE()
{
	static int Type;
	static DWORD horse;
	static DWORD Addrss1 = 0x005AF28A;
	static DWORD Addrss2 = 0x005AFF59;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0x8]
		MOVSX EAX,WORD PTR DS:[EDX + 0x22C]
		MOV horse, EAX
	}

	Type = recargaNuevoPet(horse);

	if( horse == 0x1E97  || Type == 2 )
	{
		_asm
		{
			JMP [Addrss1]
		}
	}
	else
	{
		_asm
		{
			JMP [Addrss2]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_FORCE()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x006466AE;
	static DWORD Addr2_JMP = 0x006466DD;
	static DWORD Addr3_JMP = 0x006466FA;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x30]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 2 || Type == 3 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PetRender == 0x1EB8 || Type == 1 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_FIRE_BURST()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x00646747;
	static DWORD Addr2_JMP = 0x00646776;
	static DWORD Addr3_JMP = 0x00646793;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x30]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PetRender, EDX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E97 || PetRender == 0x1E95 || PetRender == 0x1E96 || Type == 2 || Type == 3 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PetRender == 0x1EB8 || Type == 1 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_BUFF_SUM()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x00647B2B;
	static DWORD Addr2_JMP = 0x00647B40;
	static DWORD Addr3_JMP = 0x00647B55;
	static DWORD Addr4_JMP = 0x00647B6A;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x30]
		MOVSX EDX,WORD PTR DS:[ECX+0x22C]
		MOV PetRender, EDX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender == 0x1E95 || Type == 11 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else if( PetRender == 0x1E96 || Type == 3 )
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
	else if( PetRender == 0x1E97 || Type == 2 )
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
	else if( PetRender == 0x1EB8 || Type == 1 )
	{
		_asm
		{
			JMP [Addr3_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr4_JMP]
		}
	}
}

__declspec(naked) void PlayerAnimation_SKILL_CRITICAL_DAMAGE()
{
	static int Type;
	static DWORD PetRender;
	static DWORD Addr1_JMP = 0x00647656;
	static DWORD Addr2_JMP = 0x0064767A;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0x30]
		MOVSX ECX,WORD PTR DS:[EAX+0x22C]
		MOV PetRender, ECX
	}

	Type = recargaNuevoPet(PetRender);

	if( PetRender > 0x1E95 || PetRender > 1E97 || Type > 3 || Type < 2 )
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void aceptarbless()
{
	static DWORD ItemIndex;
	static DWORD TargetItem;
	static int Type;
	static DWORD Addr1_JMP = 0x007DBFAE;
	static DWORD Addr2_JMP = 0x007DBFC1;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x70]
		MOVSX EDX,WORD PTR DS:[ECX]
		MOV ItemIndex, EDX
		MOV ECX,DWORD PTR SS:[EBP-0xA8]
		MOV TargetItem, ECX
	}

	Type = recargaNuevoPet(TargetItem + 1171);

	if( ItemIndex == 7181 && TargetItem == 6693 || ItemIndex == 7181 && TargetItem == 6858 || ItemIndex == 7412 && TargetItem == 6856 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void aceptarbless2()
{
	static DWORD ItemIndex;
	static DWORD TargetItem;
	static int Type;
	static DWORD Addr1_JMP = 0x00838515;
	static DWORD Addr2_JMP = 0x008385C7;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x20]
		MOVSX EDX,WORD PTR DS:[ECX]
		MOV ItemIndex, EDX
		MOV ECX,DWORD PTR SS:[EBP-0x3C]
		MOV TargetItem, ECX
	}

	Type = recargaNuevoPet( TargetItem + 1171 );

	if( ItemIndex == 7181 && TargetItem == 6693 || ItemIndex == 7181 && TargetItem == 6858 || ItemIndex == 7412 && TargetItem == 6856 ) // Fenrir
	{
		_asm
		{
			JMP [Addr1_JMP]
		}
	}
	else
	{
		_asm
		{
			JMP [Addr2_JMP]
		}
	}
}

__declspec(naked) void EmPeComAguia(int a1)
{
	static DWORD Return_Adress = 0x0054F220;

	int Action;

	if (pMapNumber == 1000)
	{

	}
	else
	{
	
	lpViewObj lpObj = &*(lpViewObj)a1;

		if(lpObj->WeaponSecondSlot == 7832)
		{
			Action = 0x4C; 
		}
		else
		{
			Action = 0x1; 
		}
	}

	_asm
	{
	PUSH 0x1                                  
	PUSH Action                                 
	MOV EDX,DWORD PTR SS:[EBP+0x8]
	ADD EDX,0x308                            
	PUSH EDX                                 
	JMP [Return_Adress]
	}
}

#pragma optimize("t",off)

void CustomPet::Load()
{
	if(gProtect.m_MainInfo.m_PetCustomSystem == 1)
	{
		SetCompleteHook(0xE9, 0x0054F212, &EmPeComAguia); //Fix Aguia
	//	SetCompleteHook(0xE9, 0x008384F6, &aceptarbless2); //-- Player Animation Fenrrir 123 Montar
	//	SetCompleteHook(0xE9, 0x007DBF94, &aceptarbless); //-- Player Animation Fenrrir 123 Montar
	//	SetDword(0x00838515+3,258);
	
	//	SetCompleteHook(0xE9, 0x0083426D, &SetTestinho); // modifica as tarja vermelhan
		SetCompleteHook(0xE9, 0x005BD001, &SetMontariasMove); //Montarias ao ir para Icarus
	
		//Level of Pets horse
		SetCompleteHook(0xE9, 0x004FA623, &ItemTooltipMontura4); //- Opciones
	//	SetCompleteHook(0xE9, 0x004FA2E8, &ItemTooltipMontura3); //- Requiere Nivel
	//	SetCompleteHook(0xE9, 0x004FA06C, &ItemTooltipMontura2); //- Nombre
	//	SetCompleteHook(0xE9, 0x007E423D, &ItemTooltipMontura);  //- show level and exp
	
		//Pets Guardian 100%
		SetCompleteHook(0xE9,0x00501523, &SetGuardian1); //Animação da Guardian - Em cima da cabeça
		SetCompleteHook(0xE9,0x005033EB, &SetGuardian2); //Animação da Guardian - Ao andar
	
		//Dinorant 100%
		SetCompleteHook(0xE9,0x0054ED43,&SetDinoAnimation1); //dinorant montado OK
		SetCompleteHook(0xE9,0x0054FD46,&SetDinoAnimation2); //dinorant correndo OK
	
		//-- Fenrir Effect
		SetCompleteHook(0xE9, 0x005E0349, &SetEffect_Fenrir);
		//-- PetScale View
		SetOp((LPVOID)0x005F820C, DrawObjectDropOnViewport, ASM::CALL);
		
		SetCompleteHook(0xE8, 0x0048E504, &PetPreviewScale);
		SetCompleteHook(0xE8, 0x00503986, &PetPreviewScale);
		//-- PetHorse
		SetCompleteHook(0xE9,0x00551B09,&SetPlayerAnimation1); //-- Player Animation Horse 84
		SetCompleteHook(0xE9,0x0054EC8F,&SetPlayerAnimation2); //-- Player Animation Horse 78 Montar
		//-- Pet Fenrir
		SetCompleteHook(0xE9,0x0054EAC8,&SetPlayerAnimation2_Fenrir); //-- Player Animation Fenrrir 123 Montar
		SetCompleteHook(0xE9,0x0054F6AE,&SetPlayerAnimation3_Fenrir); //-- Player Animation Fenrrir 123 Montar
		//-- PetHorse
		SetCompleteHook(0xE9,0x0054FCD8,&SetPlayerAnimation3); //-- Player Animation Horse 79
		SetCompleteHook(0xE9,0x005506C2,&SetPlayerAnimation4); //-- Increase Speed
		//-- Pet Fenrir
		SetCompleteHook(0xE9,0x0054F8EA,&SetPlayerAnimation4_Fenrir); //-- Player Animation Fenrrir 123 Montar
		SetCompleteHook(0xE9,0x0054FC7D,&SetPlayerAnimation5_Fenrir); //-- Player Animation Fenrrir 123 Correr
		SetCompleteHook(0xE9,0x00550706,&SetPlayerAnimation6_Fenrir); //-- Player Animation Fenrrir 123 Correr
		SetCompleteHook(0xE9,0x00550767,&SetPlayerAnimation7_Fenrir); //-- Player Animation Fenrrir 123 Correr
		SetCompleteHook(0xE9,0x005507CD,&SetPlayerAnimation8_Fenrir); //-- Player Animation Fenrrir 123 Correr
		SetCompleteHook(0xE9,0x00550833,&SetPlayerAnimation9_Fenrir); //-- Player Animation Fenrrir 123 Correr
		//-- Pet Horse
		SetCompleteHook(0xE9,0x0055D1C7,&SetPlayerAnimation5); //-- Player Animation Horse 82 Skill Fire Scream
		SetCompleteHook(0xE9,0x005AE213,&SetPlayerAnimation6); //-- Player Animation Horse 82 Skill Chaotic Diseier
		SetCompleteHook(0xE9,0x005AF1D2,&SetPlayerAnimation7); //-- Player Animation Horse 82 Skill Chaotic Diseier
		SetCompleteHook(0xE9,0x005AF269,&SetPlayerAnimation8); //-- Player Animation Horse 82 Skill Chaotic Diseier
		//--
		SetCompleteHook(0xE9,0x005ADB09,&SetPlayerAnimation10); //-- Player Animation Horse DONE
		//--
		SetCompleteHook(0xE9,0x005B3875,&SetPlayerAnimation11); //-- Player Animation Horse 85 Skill Increase Critical
		SetCompleteHook(0xE9,0x005B3B8F,&SetPlayerAnimation12); //-- Player Animation Horse 85 Skill Increase Critical
		SetCompleteHook(0xE9,0x005B3EAF,&SetPlayerAnimation13); //-- Player Animation Horse 85 Skill Increase Critical
		//--
		SetCompleteHook(0xE9,0x005528DE,&SetHorsePlayer5); //-- HORSE	ok
		//--
		SetCompleteHook(0xE9,0x0055D1E3,&SetMontDarkHorse2); //HORSE
		SetCompleteHook(0xE9,0x00564C1C,&SetMontDarkHorse3); //HORSE
		SetCompleteHook(0xE9,0x005964D6,&SetMontDarkHorse4); //HORSE	ok
		SetCompleteHook(0xE9,0x005A3817,&SetMontDarkHorse5); //HORSE	ok
		//-- Follow Pet Character
		SetCompleteHook(0xE9,0x00501860,&MoveHorse); //Personaje se mueva con el pet
		//-- PetMuun
		SetOp((LPVOID)0x0048E17D, CustomPet::PetsMovement, ASM::CALL);
		SetOp((LPVOID)0x00503756, CustomPet::PetsMovement, ASM::CALL);
	
		//Skills Monturas
		SetCompleteHook(0xE9, 0x008140C3, &SetHorseSkill);
	
		SetOp((LPVOID)0x007DF8BB, CustomPet::PetHPBar, ASM::CALL);
		
		SetOp((LPVOID)0x48FB8C, CustomPet::PreviewCharSet, ASM::CALL);
		SetOp((LPVOID)0x63D2D8, CustomPet::PreviewCharSet, ASM::CALL);
		SetOp((LPVOID)0x641189, CustomPet::PreviewCharSet, ASM::CALL);
		SetOp((LPVOID)0x641F42, CustomPet::PreviewCharSet, ASM::CALL);
		SetOp((LPVOID)0x642598, CustomPet::PreviewCharSet, ASM::CALL);
		SetOp((LPVOID)0x65EA2D, CustomPet::PreviewCharSet, ASM::CALL);
	
		SetOp((LPVOID)0x664267, CustomPet::RefreshViewPortItem, ASM::CALL);
	//	SetOp((LPVOID)0x0048E504, this->CreateEffect, ASM::CALL); //SOURCE EFECTOS PET
	//	SetOp((LPVOID)0x00503986, this->CreateEffect, ASM::CALL); //SOURCE EFECTOS PET
		SetCompleteHook(0xE8, 0x00566237, &sub_959FA0); //reorganiza o pet custom 
		//SetCompleteHook(0xE9, 0x00552710, &PlayerAnimationMonturaSkill); //-- Player Animation All Skill [SM], [BUFF ELF]
		//-- Increase Speed Move
		SetCompleteHook(0xE9, 0x00564BA2, &PlayerAnimation1_MoveSpeed); //-- Player Animation Fenrir
		SetCompleteHook(0xE9, 0x00564C1C, &PlayerAnimation2_MoveSpeed); //-- Player Animation Horse
		SetCompleteHook(0xE9, 0x00564C8A, &PlayerAnimation3_MoveSpeed); //-- Player Animation Uniria/Dinorant
		SetCompleteHook(0xE9, 0x005AF536, &SetPlayerAnimation9); //-- Player Animation Horse 85 Skill Increase Critical
		
		SetCompleteHook(0xE9, 0x008140C3, &Enabled_SKILL_EARTHQUAKE); //-- Player Animation Skill 238 [Earthquake]
		SetCompleteHook(0xE9, 0x005ADE47, &PlayerAnimation_SKILL_BIRDS1); //-- Player Animation Skill 238 [Birs][Fenrir]
		SetCompleteHook(0xE9, 0x005AE1DD, &PlayerAnimation_SKILL_BIRDS2); //-- Player Animation Skill 238 [Birs]
		SetCompleteHook(0xE9, 0x005AF1D2, &PlayerAnimation_SKILL_FIRE_SCREAM); //-- Player Animation Skill 78 [Fire Screem]
		SetCompleteHook(0xE9, 0x005AF269, &PlayerAnimation_SKILL_EARTHQUAKE); //-- Player Animation Skill 238 [Earthquake]
		SetCompleteHook(0xE9, 0x0064668B, &PlayerAnimation_SKILL_FORCE); //-- Player Animation Skill 60 [Force]
		SetCompleteHook(0xE9, 0x00646724, &PlayerAnimation_SKILL_FIRE_BURST); //-- Player Animation Skill 60 [Force]
		SetCompleteHook(0xE9, 0x00647AF5, &PlayerAnimation_SKILL_BUFF_SUM); //-- Player Animation Skill 217,218,219 [SUM]
		SetCompleteHook(0xE9, 0x00647628, &PlayerAnimation_SKILL_CRITICAL_DAMAGE); //fixed by denis
	
	//		//Fenrir SafeZone (Struct +14)
	//		SetByte(0x00501955+2,0);
	//		MemorySet(0x0054EAE1, 0x90, 0x06);//SetPlayerStop
	//		MemorySet(0x0054FC92, 0x90, 0x06);//SetPlayerWalk
	//		
	//		//Horse SafeZone (Struct +14)
	//		SetByte(0x00502269+2,0);
	//		MemorySet(0x0054ECA3,0x90,0x6);
	//		MemorySet(0x0054FCEC,0x90,0x6);
	//	
	//		//Dinorant e Uniria (Struct +14)
	//		SetByte(0x00502C4B+2,0);
	//		MemorySet(0x0054ED6D,0x90,0x6);
	//		MemorySet(0x0054FD5F,0x90,0x6);
	//		MemorySet(0x0054FE3E,0x90,0x6);
	//	
	//		//Raven (Struct +14)
	//		MemorySet(0x0054FD23,0x90,0x6);
	}
	else
	{
		SetCompleteHook(0xE8, 0x0048E504, &PetPreviewScale);
		SetCompleteHook(0xE8, 0x00503986, &PetPreviewScale);		
	}
}