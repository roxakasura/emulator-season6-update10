#include "stdafx.h"
#include "CustomPvPForCoord.h"
#include "DefaultClassInfo.h"
#include "Map.h"
#include "MemScript.h"
#include "Util.h"

cCPvPCoord gPvPCoord;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

cCPvPCoord::cCPvPCoord() // OK
{
	this->m_PvPCoordInfo.clear();
}

cCPvPCoord::~cCPvPCoord() // OK
{

}

void cCPvPCoord::Load(char* path) // OK
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	this->m_PvPCoordInfo.clear();

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			if(strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			MOVE_PVPCOORD_INFO info;

			info.Map = lpMemScript->GetNumber();

			info.X = lpMemScript->GetAsNumber();

			info.Y = lpMemScript->GetAsNumber();

			info.TX = lpMemScript->GetAsNumber();
			
			info.TY = lpMemScript->GetAsNumber();

			info.Mode = lpMemScript->GetAsNumber();

			this->m_PvPCoordInfo.push_back(info);
		}
	}
	catch(...)
	{
		ErrorMessageBox(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

bool cCPvPCoord::CheckPvPCoord(int map,int x,int y, int Mode) // OK
{
	for(std::vector<MOVE_PVPCOORD_INFO>::iterator it=this->m_PvPCoordInfo.begin();it != this->m_PvPCoordInfo.end();it++)
	{
		if(it->Map != map)
		{
			continue;
		}
		else if((it->X > x || it->TX < x) || (it->Y > y || it->TY < y))
		{
			continue;
		}
		else if(it->Mode != Mode)
		{
			continue;
		}
		else
		{
			return 1;
		}
	}

	return 0;
}
