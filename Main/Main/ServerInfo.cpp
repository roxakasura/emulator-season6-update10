#include "stdafx.h"
#include "ServerInfo.h"
#include "Interface.h"
#include "TMemory.h"
#include "Defines.h"
#include "ConnectServer.h"
/*
CServerInfo g_ServerInfo;

CServerInfo::CServerInfo()
{
	
}

CServerInfo::~CServerInfo()
{
}

Naked(DynamicTypeServer)
{
	static DWORD Address1 = 0x08128ADC;
	static DWORD Address2 = 0x00402320;
	static DWORD Address3 = 0x00D4F798;
	static DWORD Address4 = 0x009CF6AA;
	static DWORD Address5 = 0x0095415C;
	static DWORD SubCode = 0;
	static char * formatText;
	_asm{
		mov edx, [ebp + 0x0C]
		mov SubCode, edx
	}
	switch (ConnectServer.getServerType(SubCode))
	{
	case 0:
		formatText = "%s-%d(PvP) %s";
		break;
	case 1:
		formatText = "%s-%d(Non-PvP) %s";
		break;
	default:
		formatText = "%s-%d %s";
		break;
	}
		
	_asm{
		mov edx, [ebp - 0x10]
		push edx
		mov ecx, Address1
		call Address2
		push eax
		mov eax, [ebp - 0x14]
		mov ecx, [eax + 0x08]
		push ecx
		mov edx, [ebp + 0x08]
		add edx, 0x2D
		push edx
		push formatText
		mov eax, [ebp - 0x14]
		add eax, 0x15
		push eax
		call Address4
		add esp, 0x14
		jmp Address5

	}
}
void CServerInfo::Load()
{
//	SetRange((LPVOID)0x00954071, 10, ASM::NOP);
//	SetOp((LPVOID)0x00954071, DynamicTypeServer, ASM::JMP);
}*/