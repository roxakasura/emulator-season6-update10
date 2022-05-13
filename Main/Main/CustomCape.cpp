#include "stdafx.h"
#include "CustomCape.h"
#include "Defines.h"
#include "Object.h"
#include "Interface.h"
#include "TMemory.h"
#include "Util.h"
#include "Item.h"
#include "CustomCloak.h"
#include "ModelEffect.h"
#include "Defines.h"
#include "User.h"

CCapeAnimation gCapeAnimation;

CCapeAnimation::CCapeAnimation()
{

}
CCapeAnimation::~CCapeAnimation()
{

}

DWORD CapeRegister;
DWORD CapeEffectPointer;
DWORD CapeEffectBuff;

void CCapeAnimation::DrawViewPort(DWORD ObjectPointer, DWORD ObjectModel, DWORD a3)
{
	lpViewObj Object = &*(ObjectPreview*)(ObjectPointer);

	switch(Object->WingsSlot)
	{
		case ITEM2(12,40):

			Object->WingsSlot = ITEM2(12,40);
			//-
			SetDword((0x0057491A + 1), 0x7758);
			SetDword((0x0057491F + 1), 0x7758);
			//
			SetDword((0x00574F2E + 1), 0x7759);
			SetDword((0x00574F33 + 1), 0x7759);
			//
			SetDword((0x00574FFC + 1), 0x7759);
			SetDword((0x00575001 + 1), 0x7759);
			//-
		break;
		case ITEM2(12,49):
		case ITEM2(12,135):
			Object->WingsSlot = ITEM2(12,49);	//capa rage fighter

			SetDword((0x0057491A + 1), 0x07EE0);
			SetDword((0x0057491F + 1), 0x07EE0);

			break;
		case ITEM2(12,50):						//capa 2da rage fighter
			
			Object->WingsSlot = ITEM2(12,50);
			//-
			SetDword((0x0057491A + 1), 0x07EE2);
			SetDword((0x0057491F + 1), 0x07EE2);
			//
			SetDword((0x00574F2E + 1), 0x07EE1);
			SetDword((0x00574F33 + 1), 0x07EE1);
			//
			SetDword((0x00574FFC + 1), 0x07EE1);
			SetDword((0x00575001 + 1), 0x07EE1);
			//-
		break;
	}

	CUSTOMCLOAK_DATA* CapeModel = gCloak.GetInfoByItem(Object->WingsSlot - 1171);

	if(CapeModel){

		Object->WingsSlot = ITEM2((CapeModel->ItemIndex / 512), (CapeModel->ItemIndex % 512));

		SetDword((0x0057491A + 1), CapeModel->IndexCloak);
		SetDword((0x0057491F + 1), CapeModel->IndexCloak);

		if(CapeModel->Mode == 1){
			//-- Tira1
			SetDword((0x00574F2E + 1), CapeModel->IndexStrip);
			SetDword((0x00574F33 + 1), CapeModel->IndexStrip);
			//-- Tira2
			SetDword((0x00574FFC + 1), CapeModel->IndexStrip);
			SetDword((0x00575001 + 1), CapeModel->IndexStrip);
		}
	}
	
	gCustomModelEffect.ModelEffectRender(ObjectPointer, ObjectModel,  a3);

	pDrawViewPort(ObjectPointer, ObjectModel,  a3);

//	RenderMonsterEffectMesh(ObjectPointer, ObjectModel, a3);
}

DWORD getPictureStrip(DWORD CapePointer)
{
	DWORD texture = -1;
	switch(CapePointer)
	{
	case ITEM2(12,40):
		texture = 0x7759;
		break;
	case ITEM2(12,50):
		texture = 0x7EE1;
		break;
	default:
		int code = 0x16305;

		for(int n=0;n < MAX_CUSTOMCLOAK;n++)
		{
			if(gCloak.m_Cloak[n].Index != -1){

				code ++;

				if(gCloak.m_Cloak[n].Mode == 1)
				{
					if((CapePointer-1171) == gCloak.m_Cloak[n].ItemIndex)
					{
						texture = code;
						break;
					}
					code ++;
				}
			}
		}
		break;
	}

	return texture;
}

DWORD getPictureCape(DWORD CapePointer)
{
	DWORD texture = -1;
	switch(CapePointer)
	{
	case ITEM2(12,40):
		texture = 0x07758;
		break;
	case ITEM2(12,49):
	case ITEM2(12,135):
		texture = 0x07EE0;
		break;
	case ITEM2(12,50):
		texture = 0x07EE2;
		break;
	default:
		int code = 0x16305;

		for(int n=0;n < MAX_CUSTOMCLOAK;n++)
		{
			if(gCloak.m_Cloak[n].Index != -1){

				if((CapePointer-1171) == gCloak.m_Cloak[n].ItemIndex)
				{
					texture = code;
					break;
				}
				code ++;
			
				if(gCloak.m_Cloak[n].Mode == 1){

					code ++;
				}
			}
		}
		break;
	}

	return texture;
}
//--- carga tiras de las capas
__declspec(naked) void LoadStrip() // 0x7759 //-> 03 Main
{
	static DWORD Address1 = 0x005750C5;
	static DWORD Address2 = 0x005750C5;
	static DWORD CallRender = 0x0051EEF0;
	static DWORD PictureStrip;

	_asm
	{
		Mov CapeEffectBuff, ecx
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOVSX ECX,WORD PTR DS:[EAX+0x208]
		Mov CapeEffectPointer, ECX
		Mov ecx, CapeEffectBuff
	}

	if( CapeEffectPointer == ITEM2(12,40) || gCloak.isCloakStrip(CapeEffectPointer - 1171) )
	{
		PictureStrip = getPictureStrip(CapeEffectPointer);
		_asm
		{
			PUSH 0x1000
			PUSH PictureStrip
			PUSH PictureStrip
			PUSH ECX
			FLD DWORD PTR DS:[0xD27BE0]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD23608]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x5
			PUSH 0x2
			PUSH ECX
			FLD DWORD PTR DS:[0xD22C14]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD24384]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD24380]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x13
			MOV EDX,DWORD PTR SS:[EBP + 0xC]
			PUSH EDX
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]
			ADD ECX,0x180
			MOV EAX,DWORD PTR SS:[EBP - 0x2DC]
			MOV EDX,DWORD PTR DS:[EAX + 0x180]
			MOV EAX,DWORD PTR DS:[EDX + 0x4]
			CALL EAX
			PUSH 0x2                                 ; /Arg5 = 00000002
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD24380]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD25780]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28150]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x180                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27BFC]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x180                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			PUSH 0x1000
			PUSH PictureStrip
			PUSH PictureStrip
			PUSH ECX
			FLD DWORD PTR DS:[0xD27BE0]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD23608]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x5
			PUSH 0x2
			PUSH ECX
			FLD DWORD PTR DS:[0xD22C14]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD23F68]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD28D20]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x13
			MOV ECX,DWORD PTR SS:[EBP + 0xC]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]
			ADD ECX,0x1E0
			MOV EDX,DWORD PTR SS:[EBP - 0x2DC]
			MOV EAX,DWORD PTR DS:[EDX + 0x1E0]
			MOV EDX,DWORD PTR DS:[EAX + 0x4]
			CALL EDX
			PUSH 0x2                                 ; /Arg5 = 00000002
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD24380]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD25780]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28150]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x1E0                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27BFC]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x1E0                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			JMP [Address1]
		}
	}
	else if( CapeEffectPointer == ITEM2(12,50) )
	{
		_asm
		{
			PUSH 0x9000
			PUSH 0x7EE1
			PUSH 0x7EE1
			PUSH ECX
			FLD DWORD PTR DS:[0xD2AF5C]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD23608]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x5
			PUSH 0x2
			PUSH ECX
			FLD DWORD PTR DS:[0xD22BB8]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD24384]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD25B94]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x13
			MOV EDX,DWORD PTR SS:[EBP + 0xC]
			PUSH EDX
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]
			ADD ECX,0x180
			MOV EAX,DWORD PTR SS:[EBP - 0x2DC]
			MOV EDX,DWORD PTR DS:[EAX + 0x180]
			MOV EAX,DWORD PTR DS:[EDX + 0x4]
			CALL EAX
			PUSH 0x2                                 ; /Arg5 = 00000002
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27BFC]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD25780]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28150]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x180                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27AE4]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x180                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			PUSH 0x0D000
			PUSH 0x7EE1
			PUSH 0x7EE1
			PUSH ECX
			FLD DWORD PTR DS:[0xD2AF5C]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD23608]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x5
			PUSH 0x2
			PUSH ECX
			FLD DWORD PTR DS:[0xD22BB8]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD24384]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD2B910]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x13
			MOV ECX,DWORD PTR SS:[EBP + 0xC]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]
			ADD ECX,0x1E0
			MOV EDX,DWORD PTR SS:[EBP - 0x2DC]
			MOV EAX,DWORD PTR DS:[EDX + 0x1E0]
			MOV EDX,DWORD PTR DS:[EAX + 0x4]
			CALL EDX
			PUSH 0x2                                 ; /Arg5 = 00000002
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27BFC]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD25780]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28150]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x1E0                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD28108]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLDZ                                     ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP - 0x2DC]       ; |
			ADD ECX,0x1E0                            ; |
			CALL CallRender                          ; \main1.0051EEF0
			JMP [Address1]
		}
	}
	else
	{
		_asm
		{
			Jmp Address2
		}
	}
}

__declspec(naked) void LoadCape() //7758
{
	static DWORD Address_Buffer = 0x00574A65;
	static DWORD Address_Next = 0x00574A6A;
	static DWORD Call_render = 0x0051EEF0;
	static DWORD PictureCape;

	_asm
	{
		mov CapeEffectBuff, ecx
		MOV EAX, DWORD PTR SS : [EBP + 0x8]
		MOVSX ECX, WORD PTR DS : [EAX + 0x208]
		MOV CapeEffectPointer, ecx
		MOV ecx, CapeEffectBuff
	}

	PictureCape = getPictureCape(CapeEffectPointer);

	if(CapeEffectPointer == ITEM2(12,40)) //-- 2da Cape DL
	{
		_asm
		{
			PUSH 0x1405
			PUSH PictureCape
			PUSH PictureCape
			PUSH ECX
			FLD DWORD PTR DS:[0xD2AF5C]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD2AF5C]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x0A
			PUSH 0x0A
			PUSH ECX
			FLD DWORD PTR DS:[0xD22C14]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD22BE0]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLDZ
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x13
			MOV EDX,DWORD PTR SS:[EBP + 0xC]
			PUSH EDX
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]
			ADD ECX,0x0C0
			MOV EAX,DWORD PTR SS:[EBP - 0x2DC]
			MOV EDX,DWORD PTR DS:[EAX + 0xC0]
			MOV EAX,DWORD PTR DS:[EDX + 0x4]
			CALL EAX
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD25B94]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD25B94]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD22C14]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD2436C]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD23F68]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD2436C]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD23F68]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD22C14]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			JMP [Address_Buffer]
		}
	}
	else if( CapeEffectPointer == ITEM2(12,50)//2da Cape RF
		|| CapeEffectPointer == ITEM2(12,49) //-- 1er Cape RF|
		|| CapeEffectPointer == ITEM2(12,135) //-- MiniCape RF
		|| gCloak.isCloak(CapeEffectPointer-1171))
	{
		_asm
		{
			PUSH 0x1405
			PUSH PictureCape
			PUSH PictureCape
			PUSH ECX
			FLD DWORD PTR DS:[0xD2AF5C]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD2AF5C]
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x0A
			PUSH 0x0A
			PUSH ECX
			FLD DWORD PTR DS:[0xD22C14]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLD DWORD PTR DS:[0xD22BE0]
			FSTP DWORD PTR SS:[ESP]
			PUSH ECX
			FLDZ
			FSTP DWORD PTR SS:[ESP]
			PUSH 0x13
			MOV EDX,DWORD PTR SS:[EBP + 0xC]
			PUSH EDX
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]
			ADD ECX,0x0C0
			MOV EAX,DWORD PTR SS:[EBP - 0x2DC]
			MOV EDX,DWORD PTR DS:[EAX + 0xC0]
			MOV EAX,DWORD PTR DS:[EDX + 0x4]
			CALL EAX
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27BFC]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD27BFC]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD22C14]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD2B950]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD23F68]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			PUSH 0x11                                ; /Arg5 = 00000011
			PUSH ECX                                 ; |Arg4
			FLD DWORD PTR DS:[0xD2B950]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg3
			FLD DWORD PTR DS:[0xD23F68]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg2
			FLD DWORD PTR DS:[0xD28140]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			PUSH ECX                                 ; |Arg1
			FLD DWORD PTR DS:[0xD22C14]              ; |
			FSTP DWORD PTR SS:[ESP]                  ; |
			MOV ECX,DWORD PTR SS:[EBP-0x2DC]         ; |
			ADD ECX,0x0C0                            ; |
			CALL Call_render                         ; \main1.0051EEF0
			JMP [Address_Buffer]
		}
	}
	else
	{
		_asm{
			JMP [Address_Next]
		}
	}	
}

__declspec(naked) void LoadCapeRender()
{
	static DWORD Address1 = 0x005760C2;
	static DWORD Address2 = 0x00576014;

	_asm{
		Mov CapeEffectBuff, ecx
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOVSX ECX,WORD PTR DS:[EAX+0x208]
		Mov CapeEffectPointer,Ecx
		Mov Ecx, CapeEffectBuff
	}
	if(CapeEffectPointer == ITEM2(12,40) //-- 2da Caep DL
		||	CapeEffectPointer == ITEM2(12,130) //-- Mini Cape DL
		||	CapeEffectPointer == ITEM2(13,30) //-- 1er Cape DL
		||	gCloak.isCloak(CapeEffectPointer - 1171))
	{
		_asm{jmp Address1}
	}
	else
	{
		_asm{jmp Address2}
	}	
}

__declspec(naked) void LoadAnimationPlay() //allow play
{
	static DWORD Address1 = 0x00574683;
	static DWORD Address2 = 0x0057468F;

	_asm{
		Mov CapeEffectBuff, Ecx
		MOV DWORD PTR SS:[EBP-0x2D8],4
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		MOVSX ECX,WORD PTR DS:[EAX+0x208]
		mov CapeEffectPointer,ecx
		mov ecx, CapeEffectBuff
	}

	if(CapeEffectPointer == ITEM2(12,40)
		||	CapeEffectPointer == ITEM2(12,49)
		||	CapeEffectPointer == ITEM2(12,50)
		||	CapeEffectPointer == ITEM2(12,135)
		||	gCloak.isCloak(CapeEffectPointer - 1171))
	{
		_asm{jmp Address1}
	}
	else
	{
		_asm{jmp Address2}
	}
	
}

__declspec(naked) void HideCape()
{
	static DWORD Address1 = 0x005FAD7D;//0x005FAD70
	static DWORD Address2 = 0x005FAE90;

	_asm
	{
		Mov Ecx, dword ptr ss : [ebp +0x10]
		Mov Dword ptr ss : [ebp +0x10], Ecx
		Mov CapeEffectPointer, Ecx
	}
		
	if (CapeEffectPointer == ITEM2(12,40)
		||	CapeEffectPointer == ITEM2(12,49)
		||	CapeEffectPointer == ITEM2(12,50)
		||	CapeEffectPointer == ITEM2(12,135)
		||	gCloak.isCloak(CapeEffectPointer - 1171) == true)
	{
		_asm
		{
			JMP [Address1]
		}
	}
	else
	{
		_asm
		{
			JMP [Address2]
		}
	}
}

__declspec(naked) void AllowMGCape() //?
{
	static DWORD Address1 = 0x00574D4C;
	static DWORD Address2 = 0x00574DAC;
	_asm
	{
		Mov CapeEffectBuff,Ecx
		Mov Eax,Dword Ptr Ss : [Ebp + 0x8]
		MOVZX ECX,BYTE Ptr Ds : [Eax + 0x13]
		Mov CapeEffectPointer,Ecx
		Mov Ecx, CapeEffectBuff
	}

	if (CapeEffectPointer == 3)
	{
		_asm
		{
			jmp Address1
		}
	}
	else
	{
		_asm
		{
			jmp Address2
		}
	}
}

//----- (008363D0) --------------------------------------------------------
void RefreshCapeUnEquip1(ObjectItem * lpItem)
{
	if( gCloak.isCloak(lpItem->ItemID) || lpItem->ItemID == 6183 || lpItem->ItemID == 6184 ||lpItem->ItemID == 6193 || lpItem->ItemID == 6194 ){
		pRefreshViewport(oUserPreviewStruct, oUserPreviewStruct + 776, 0);
		return;
	}
	pRefreshCape1(lpItem);
}

void RefreshCapeUnEquip2(ObjectItem * lpItem)
{
	if( gCloak.isCloak(lpItem->ItemID) || lpItem->ItemID == ITEM(12,135) ){
		pRefreshViewport(oUserPreviewStruct, oUserPreviewStruct + 776, 0);
		return;
	}
	pRefreshCape2(lpItem);
}

__declspec(naked) void RemoveDarklordHair()
{
	static DWORD Address1 = 0x00574755;
	static DWORD Address2 = 0x005748FF;

	_asm
	{
		Mov Eax, Dword Ptr Ss : [Ebp + 0x8]
		Movzx Edx, Byte Ptr Ds : [Eax + 0x13]
		And Edx, 0x7
		Cmp Edx, 0x4
		Jne EXIT
		Push 0xC0000205
		Jmp Address1
		EXIT:
		Jmp Address2
	}
}

void CCapeAnimation::Load()
{
	//-- Carga de Tira
	SetRange((LPVOID)0x00574F13,10,ASM::NOP);
	SetOp((LPVOID)0x00574F13,(LPVOID)LoadStrip,ASM::JMP);
	//-- Carga de Manta
	SetRange((LPVOID)0x005748FF,10,ASM::NOP);
	SetOp((LPVOID)0x005748FF,(LPVOID)LoadCape,ASM::JMP);
	//--
	SetRange((LPVOID)0x00576058,10,ASM::NOP);
	SetOp((LPVOID)0x00576058,(LPVOID)LoadCapeRender,ASM::JMP);
	//--
	SetRange((LPVOID)0x00574667,20,ASM::NOP);
	SetOp((LPVOID)0x00574667,(LPVOID)LoadAnimationPlay,ASM::JMP);
	//--
	SetRange((LPVOID)0x005FAD70,7,ASM::NOP);
	SetOp((LPVOID)0x005FAD70,(LPVOID)HideCape,ASM::JMP);
	//--
	SetCompleteHook(0xE8,0x00833BE7,&RefreshCapeUnEquip1);
	SetCompleteHook(0xE8,0x007DD304,&RefreshCapeUnEquip2);
	SetCompleteHook(0xE8,0x00833B08,&RefreshCapeUnEquip2);
	//--
	SetCompleteHook(0xFF,0x0040487D, &this->DrawViewPort);
	SetCompleteHook(0xFF,0x0048E56C, &this->DrawViewPort);
	SetCompleteHook(0xFF,0x0057D4FF, &this->DrawViewPort);
	SetCompleteHook(0xFF,0x0057D513, &this->DrawViewPort);
	//-
	SetCompleteHook(0xE9, 0x00572346, 0x00572370); //Apply
	
	SetCompleteHook(0xE9, 0x0057464E, 0x00574667); //Apply

	SetCompleteHook(0xE9, 0x00574750, &RemoveDarklordHair);
	//-
	SetRange((LPVOID)0x00574D3D,13,ASM::NOP);
	SetOp((LPVOID)0x00574D3D,(LPVOID)AllowMGCape,ASM::JMP);
}