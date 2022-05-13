#include "stdafx.h"
#include "GlobalMessage.h"
#include "Offset.h"
#include "Import.h"
#include "NewFont.h"
#include "TMemory.h"
#include "Util.h"

void InitNotices()
{
	//SetCompleteHook(0xE8, 0x004D5EC3, &RenderNotices);
	SetCompleteHook(0xE9, 0x00597691, &GlobalMessagem);
}

__declspec(naked) void GlobalMessagem()
{
	static DWORD ADDS = 0x00597698;

	_asm
	{
		CMP DWORD PTR SS:[EBP-8],1200
		JMP [ADDS]
	}
}

int RenderNotices()
{
	int MoveY = 80;

	int result; // eax@1
	if ( pPlayerState == 5 )
	{
		result = (unsigned __int8)pCheckWindow((int *)GetInstance(), 65);
		if ( (unsigned __int8)result != 1 )
		{
			EnableAlphaTest(1);
			pSetTextSize(pTextThis(), (HFONT)pFontBold);
			glColor3f(1.0, 1.0, 1.0);
			for (signed int i = 0; i < 6; ++i ){
				if ( *((BYTE *)0x813DDD0 + 264 * i + 260) )
				{
					pSetTextColor(pTextThis(), 0x64u, 0xFFu, 0xC8u, 0xFFu);
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x80u);
				}
				else
				{
					pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0x80u);
					if ( NoticeInverse % 10 >= 5 )
					{
						pSetTextColor(pTextThis(), 0xFFu, 0xC8u, 0x50u, 0xFFu);
					}
					else
					{
						pSetTextColor(pTextThis(), 0xFFu, 0xC8u, 0x50u, 0x80u);
					}
				}
				pDrawText(pTextThis(), 320, 13 * i + MoveY, (LPCTSTR)0x813DDD0 + 264 * i, 0, 0, (LPINT)8, 0);
			}
			result = NoticeInverse + 1;
		}
		return result;
	}
}