#pragma once 
#include "stdafx.h"
#include "Performance.h"
#include "Util.h"


__declspec(naked) void DelectlpViewPlayerOn()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_lpViewPlayer]
	}
}

__declspec(naked) void DelectlpViewPlayerOff()
{
	static DWORD Buff_lpViewPlayer = 0x0057D27F;

		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],400
			JMP [Buff_lpViewPlayer]
		}
}

void DelectlpViewPlayerOff_Hook()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayerOff);
}

void DelectlpViewPlayerOn_Hook()
{
	SetCompleteHook(0xE9, 0x0057D278, &DelectlpViewPlayerOn);
}
//		FINAL INVISIBILIDADE

//		INICIO EFFECT DYNAMIC

__declspec(naked) void DelectEffectDynamicOn()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectDynamic]
	}
}

__declspec(naked) void DelectEffectDynamicOff()
{
	static DWORD Buff_EffectDynamic = 0x0074CD57;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0x0BB8
		JMP [Buff_EffectDynamic]
	}
}

void DelectEffectDynamicOff_Hook()
{
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamicOff);
}

void DelectEffectDynamicOn_Hook()
{
	SetCompleteHook(0xE9, 0x0074CD50, &DelectEffectDynamicOn);
}

//		FINAL EFFECT DYNAMIC

//		INICIO EFFECT STATIC

__declspec(naked) void DelectEffectStaticOn()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectStatic]
	}

}

__declspec(naked) void DelectEffectStaticOff()
{
	static DWORD Buff_EffectStatic = 0x0077132F;

		_asm
		{
			CMP DWORD PTR SS:[EBP-0x4],0x3E8
			JMP [Buff_EffectStatic]
		}
}

void DelectEffectStaticOn_Hook()
{
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStaticOn);
}

void DelectEffectStaticOff_Hook()
{
	SetCompleteHook(0xE9, 0x00771328, &DelectEffectStaticOff);
}

//testes
__declspec(naked) void DelectEffectSkillOn()
{
	static DWORD Buff_EffectSkill = 0x0072D1D3;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0
		JMP [Buff_EffectSkill]
	}

}

__declspec(naked) void DelectEffectSkillOff()
{
	static DWORD Buff_EffectSkill = 0x0072D1D3;

	_asm
	{
		CMP DWORD PTR SS:[EBP-0x4],0x1F4
		JMP [Buff_EffectSkill]
	}

}

void DelectEffectSkillOn_Hook()
{
	SetCompleteHook(0xE9, 0x0072D1CC, &DelectEffectSkillOn);
}

void DelectEffectSkillOff_Hook()
{
	SetCompleteHook(0xE9, 0x0072D1CC, &DelectEffectSkillOff);
}
//new options 21/05/2021

__declspec(naked) void DisableExcellentGlow001_off()
{
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

	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00608CB5;
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

__declspec(naked) void DisableExcellentGlow002_off()
{
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
	
	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00609556;
	}
	else
	{
		main_addr = 0x0060959D;
	}

	_asm
	{
		JMP[ main_addr ]
	}
}

__declspec(naked) void DisableExcellentGlow003_off()
{
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
	
	if ( JCItemID == 0x12E6 )
	{
		main_addr = 0x0060F055;
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


__declspec(naked) void DisableExcellentGlow001_on()
{
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

	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00608CB5;
	}
	else if( JCItemID >= 1171 )
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

__declspec(naked) void DisableExcellentGlow002_on()
{
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
	
	if ( JCItemID == 0x14CF )
	{
		main_addr = 0x00609556;
	}
	else if( JCItemID >= 1171)
	{
		main_addr = 0x006097AC;
	}
	else
	{
		main_addr = 0x0060959D;
	}

	_asm
	{
		JMP[ main_addr ]
	}
}

__declspec(naked) void DisableExcellentGlow003_on()
{
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
	
	if ( JCItemID == 0x12E6 )
	{
		main_addr = 0x0060F055;
	}
	else if( JCItemID >= 1171 )
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