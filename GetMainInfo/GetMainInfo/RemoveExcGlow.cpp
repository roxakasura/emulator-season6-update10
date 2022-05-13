#include "stdafx.h"
#include "RemoveExcGlow.h"
#include "MemScript.h"

JCRemoveGLow JCRemoveGlow;

JCRemoveGLow::JCRemoveGLow()
{
	for ( int k = 0 ; k < MAX_NOGLOW ; ++k )
	{
		this->m_JCRemoveGlow[k].ItemIndex = -1;
	}
}

JCRemoveGLow::~JCRemoveGLow()
{

}

void JCRemoveGLow::Load( char* Path )
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == 0)
	{
		printf(MEM_SCRIPT_ALLOC_ERROR, Path);
		return;
	}

	if(lpMemScript->SetBuffer( Path ) == 0)
	{
		printf(lpMemScript->GetLastError());
		delete lpMemScript;
		return;
	}

	static int CustomItemIndexCount = 0;

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

			JCItemnoGlow info;

			memset(&info, 0, sizeof( info ));

			

			info.ItemIndex = lpMemScript->GetNumber();
			
			info.IndexTexture = lpMemScript->GetAsNumber();

			if( CustomItemIndexCount < MAX_NOGLOW )
			{
				this->m_JCRemoveGlow[CustomItemIndexCount] = info;
			}
			CustomItemIndexCount++;
		}
	}
	catch(...)
	{
		printf(lpMemScript->GetLastError());
	}

	delete lpMemScript;
}