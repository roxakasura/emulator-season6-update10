#include "stdafx.h"
#include "Util.h"
#include "Import.h"
#include "Object.h"
#include "Defines.h"
#include "RenderExcGlow.h"

JCRemoveGLow JCRemoveGlow;

JCRemoveGLow::JCRemoveGLow() // OK
{
	this->m_JCRemoveGlow.clear();
}

JCRemoveGLow::~JCRemoveGLow() // OK
{

}

void JCRemoveGLow::Load(JCItemnoGlow* info) // OK
{
	for (int n = 0; n < MAX_NOGLOW; n++)
	{
		if ( info[n].ItemIndex < 0 )
		{
			return;
		}

		this->m_JCRemoveGlow.insert(std::pair<int, JCItemnoGlow>(info[n].ItemIndex,info[n]));
	}
}

int JCRemoveGLow::GetInfoType(int ItemIndex) // OK
{
	std::map<int, JCItemnoGlow>::iterator it = this->m_JCRemoveGlow.find(ItemIndex);

	if(it != this->m_JCRemoveGlow.end())
	{
		return it->second.IndexTexture;
	}
	return -1;
}

int TypeDefinition(int ItemIndex)
{
	int t = -1;
	t = JCRemoveGlow.GetInfoType(ItemIndex - 1171);

	return t;
}

__declspec(naked) void JCGetPartGlowObject_1()
{
	static int Type;
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;

	_asm
	{
		//--
		MOV EAX, DWORD PTR SS:[EBP+0x10]
		MOV JCItemID, EAX
		//--
		MOV EDX,DWORD PTR SS:[EBP+0x8]
		MOV JCThis, EDX
		//--
		MOV EAX,DWORD PTR SS:[EBP+0x18]
		MOV JCModel, EAX
		//--
		MOV ECX,DWORD PTR SS:[EBP+0xC]
		MOV JCStructEffect, ECX
	}

	Type = TypeDefinition(JCItemID);

	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00608CB5;
	}
	else if( Type == 1 || Type == 3 )
	{
		main_addr = 0x00608F8F;
	}
	else
	{
		main_addr = 0x00608CFC;
	}
	_asm
	{
		JMP[ main_addr ]
	}
}

__declspec(naked) void JCGetPartOptionObject_3()
{
	static int Type;
	static DWORD JCItemID;
	static DWORD JCThis;
	static DWORD JCModel;
	static DWORD JCStructEffect;
	static DWORD main_addr;
	static DWORD JCANALYZER_ITEM;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP + 0xC]
		MOV JCItemID,EDX
		//--
		MOV ECX,DWORD PTR SS:[EBP - 0x8]
		MOV JCThis,ECX
		//--
		MOV ECX,DWORD PTR SS:[EBP + 0x14]
		MOV JCModel,ECX
		//--
		MOV EAX,DWORD PTR SS:[EBP + 0x8]
		MOV JCStructEffect,EAX
	}

	Type = TypeDefinition(JCItemID);
	
	if ( JCItemID == 0x12E6 )
	{
		main_addr = 0x0060F055;
	}
	else if( Type == 2 || Type == 3 )
	{
		main_addr = 0x0060F320;
	}
	else
	{
		main_addr = 0x0060F094;
	}

	_asm
	{
		JMP[ main_addr ]
	}
}

void JCRemoveGLow::Init( ) // OK
{
	SetRange(0x00608CAC , 7, 0x90);
	SetOp(0x00608CAC, (LPVOID)JCGetPartGlowObject_1, 0xE9);

//	SetRange(0x0060954D , 7, 0x90);
//	SetOp(0x0060954D, (LPVOID)JCGetPartBrightnessObject_2, 0xE9);

	SetRange(0x0060F04C , 7, 0x90);
	SetOp(0x0060F04C, (LPVOID)JCGetPartOptionObject_3, 0xE9);
}