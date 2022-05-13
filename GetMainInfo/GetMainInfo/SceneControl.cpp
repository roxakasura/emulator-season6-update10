#include "stdafx.h"
#include "SceneControl.h"
#include "MemScript.h"

MultiSelect gSelectCharRamdon;

void MultiSelect::Load(char* path) // OK
{
CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR,path);
		return;
	}

	if(lpMemScript->SetBuffer(path) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}
	
	SelectChar info;
	SelectSrv lpInfo;

	memset(&info, 0, sizeof(info));

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int Secction = lpMemScript->GetNumber();

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

				if(Secction == 0)
				{
					static int CustomItemIndexCount = 0;

					lpInfo.Index = CustomItemIndexCount++;

					lpInfo.MapServ = lpMemScript->GetNumber();
			
					lpInfo.flt_87933D0 = lpMemScript->GetAsFloatNumber();
			
					lpInfo.flt_87933D4 = lpMemScript->GetAsFloatNumber();

					lpInfo.flt_87933D8 = lpMemScript->GetAsFloatNumber();

					lpInfo.flt_87933DC = lpMemScript->GetAsFloatNumber();

					lpInfo.flt_87933E0 = lpMemScript->GetAsFloatNumber();

					lpInfo.flt_87933E4 = lpMemScript->GetAsFloatNumber();
					
					this->SetInfoSrv(lpInfo);
				}

				if(Secction == 1)
				{
					static int CustomItemIndexCount = 0;

					info.Index = CustomItemIndexCount++;

					info.MapChar = lpMemScript->GetNumber();
			
					info.flt_87933D0 = lpMemScript->GetAsFloatNumber();
			
					info.flt_87933D4 = lpMemScript->GetAsFloatNumber();

					info.flt_87933D8 = lpMemScript->GetAsFloatNumber();

					info.flt_87933DC = lpMemScript->GetAsFloatNumber();

					info.flt_87933E0 = lpMemScript->GetAsFloatNumber();

					info.flt_87933E4 = lpMemScript->GetAsFloatNumber();
				}

				if(Secction == 2)
				{
					static int CustomIndexCount = 0;

					if(CustomIndexCount >= MAX_WORLD_SELECT_CHAR)
					{
						break;
					}

					info.PJ[CustomIndexCount].Index = lpMemScript->GetNumber();

					info.PJ[CustomIndexCount].Coordenada1.CoordX =  lpMemScript->GetAsFloatNumber();

					info.PJ[CustomIndexCount].Coordenada1.CoordY =  lpMemScript->GetAsFloatNumber();

					info.PJ[CustomIndexCount++].Coordenada1.Rotate =  lpMemScript->GetAsFloatNumber();
				}

				if(Secction == 3)
				{
					static int CustomIndexCount2 = 0;

					if(CustomIndexCount2 >= MAX_PJ_SELECT_CHAR)
					{
						break;
					}

					info.Size[CustomIndexCount2].Index = lpMemScript->GetNumber();

					info.Size[CustomIndexCount2++].Option1.CoordA =  lpMemScript->GetAsFloatNumber();
				}
			}
		}
		this->SetInfo(info);
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}

void MultiSelect::SetInfo(SelectChar info)
{
	if(info.Index < 0 || info.Index >= MAX_WORLD_SETTINGS)
	{
		return;
	}

	this->RenderSelect[info.Index] = info;
}

void MultiSelect::SetInfoSrv(SelectSrv lpInfo)
{
	if(lpInfo.Index < 0 || lpInfo.Index >= MAX_WORLD_SETTINGS)
	{
		return;
	}

	this->RenderSelectSrv[lpInfo.Index] = lpInfo;
}