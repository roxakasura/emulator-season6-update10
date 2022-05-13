#include "stdafx.h"
#include "Protect.h"
#include "PetHook.h"
#include "CustomCape.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "TMemory.h"
#include "Pet.h"

ObjCreateBug gObjCreateBug = (ObjCreateBug)0x00501700;
ObjCreatePet gObjCreatePet = (ObjCreatePet)0x00835E40;

void gObjCreatePetEx(int ItemId)
{
	int ItemSwitch = *(WORD*)ItemId;

	int PetPreview = LODWORD(pPreviewPetThis) + 776;

	//if (gCustomPet2.CheckCustomPetByItem(ItemSwitch))
	if (ItemSwitch >= ITEM(13, 147) && ItemSwitch <= ITEM(13, 410))
	{
		gObjCreateBug(ItemSwitch + 1171, PetPreview + 252, PetPreview, 0, 0);

	} 
		else if (gCloak.isCloak(ItemSwitch))
	{
		pRefreshViewport(oUserPreviewStruct, oUserPreviewStruct + 776, 0);
	}

	gObjCreatePet(ItemId);
}


bool ResetPetPreviewEx(int ItemId)
{

	bool Result;
	// ----

	if (ItemId)
		Result = *(WORD*)ItemId == 0x1A00    //Angel
		|| *(WORD*)ItemId == 0x1A01        //Satan
		|| *(WORD*)ItemId == 0x1A02        //Unicorn
		|| *(WORD*)ItemId == 0x1A03        //Dinorant
		|| *(WORD*)ItemId == 0x1A04        //Dark Horse
		|| *(WORD*)ItemId == 0x1A05        //Dark Raven
		|| *(WORD*)ItemId == 0x1A25        //Fenrir     //
		|| *(WORD*)ItemId == ITEM(13, 64)
		|| *(WORD*)ItemId == ITEM(13, 65)
		|| *(WORD*)ItemId == ITEM(13, 67)
		|| *(WORD*)ItemId == ITEM(13, 80)
		|| *(WORD*)ItemId == ITEM(13, 106)
		|| *(WORD*)ItemId == ITEM(13, 123)
		|| *(WORD*)ItemId >= ITEM(13, 200)
		&& *(WORD*)ItemId <= ITEM(13, 410)
		|| gCloak.isCloak(*(WORD*)ItemId)
		||	*(WORD*)ItemId == ITEM(13,30)
		||	*(WORD*)ItemId == ITEM(12,130)
		||	*(WORD*)ItemId == ITEM(12,135);
	else
		Result = 0;
	return Result;
}


void gObjCreatePetExHook()
{	
	if(gProtect.m_MainInfo.m_PetCustomSystem == 1)
	{
		SetOp((LPVOID)0x00836481, (LPVOID)ResetPetPreviewEx, ASM::CALL);
		SetOp((LPVOID)0x007DD304, (LPVOID)gObjCreatePetEx, ASM::CALL);
		SetOp((LPVOID)0x00833B08, (LPVOID)gObjCreatePetEx, ASM::CALL);
	}

	//SetCompleteHook(0xE8, 0x007DD304, &gObjCreatePetEx); // new tipo
	//SetCompleteHook(0xE8, 0x00833B08, &gObjCreatePetEx); // new tipo
}