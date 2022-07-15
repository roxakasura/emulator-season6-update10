#include "stdafx.h"
#include "CustomServerInfo.h"
#include "Util.h"
#include "TMemory.h"
#include "Defines.h"
#include "Import.h"
#include "ReadScript.h"
#include "CustomMessage.h"
#include "Protect.h"

CServerInfo g_ServerInfo;

CServerInfo::CServerInfo()
{
	this->m_data.clear();
}

CServerInfo::~CServerInfo()
{
}

void CServerInfo::Init(SERVERINFO_DATA * info)
{
	for( int n = 0; n < MAX_SERVER_CLASS; n++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_SERVER_CLASS)
		{
			return;
		}
		this->m_data.push_back(info[n]);
	}
}

void CServerInfo::Load()
{

    SetOp((LPVOID)0x009540B8, this->ServerDrawTextHook, ASM::CALL); //1.04E
    SetOp((LPVOID)0x009540EE, this->ServerDrawTextHook, ASM::CALL); //1.04E
    SetOp((LPVOID)0x00954121, this->ServerDrawTextHook, ASM::CALL); //1.04E
    SetOp((LPVOID)0x00954154, this->ServerDrawTextHook, ASM::CALL); //1.04E
	if(gProtect.m_MainInfo.SelectServerType != 1)
	{
		SetOp((LPVOID)0x0040B738, this->ServerDrawTextHook, ASM::CALL); //1.04E
	}
	SetOp((LPVOID)0x0077F861, this->ServerDrawTextHook, ASM::CALL); //1.04E
	SetOp((LPVOID)0x0077F98B, this->ServerDrawTextHook, ASM::CALL); //1.04E
}

void CServerInfo::ServerDrawTextHook(int a1, char *a2, char* ServerName, int SubServerNum, char* TextConnect)
{
	for(std::vector<SERVERINFO_DATA>::iterator it = g_ServerInfo.m_data.begin();it != g_ServerInfo.m_data.end();it++)	
	{
		if(!strcmp(ServerName, it->ServerName))
		{
			if(SubServerNum == it->SubServerNum)
			{
				pSetItemTextLine(a1, it->ServerText);
				return;
			}	
		}
	}

	pSetItemTextLine(a1, a2, ServerName, SubServerNum, TextConnect);
}