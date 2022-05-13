#include "stdafx.h"
#include "ExperienceSystem.h"
#include "PartySystem.h"
#include "Import.h"
#include "Defines.h"
#include "Object.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "Inter803.h"
#include "Protect.h"

void ExpLoad()
{
	//SetCompleteHook(0xE9, 0x00810700, &sub_810700);
}

//----- (00810700) --------------------------------------------------------
void sub_810700(int a1)
{
	__int64 v4; // rax@5
	__int64 v5; // rax@5
	unsigned __int64 v6; // kr00_8@5
	__int64 v7; // rax@5
	__int64 v8; // rax@5
	unsigned __int64 v9; // kr08_8@5
	unsigned __int64 ST20_8_5; // ST20_8@5
	unsigned int blue; // ST28_4@5
	signed __int64 v12; // rax@5
	signed __int64 v13; // rax@10
	float v14; // ST170_4@12
	float v15; // ST160_4@12
	signed __int64 v16; // rax@15
	float v17; // ST148_4@17
	float v18; // ST138_4@17
	float v19; // ST128_4@18
	float v20; // ST118_4@18
	float v21; // ST110_4@18
	float v22; // ST108_4@18
	float v23; // ST100_4@18
	float v24; // STF8_4@20
	int blue_4; // ST2C_4@21
	int v26; // ST28_4@21
	int red_4; // ST24_4@21
	int v28; // eax@21
	FARPROC(__stdcall *v29)(HMODULE, LPCSTR); // eax@22
	float v30; // STBC_4@34
	float v31; // STAC_4@34
	float v32; // ST98_4@39
	float v33; // ST88_4@39
	float v34; // ST78_4@40
	float v35; // ST68_4@40
	float v36; // ST60_4@40
	float v37; // ST58_4@40
	float v38; // ST50_4@40
	float v39; // ST48_4@42
	int v40; // ST2C_4@43
	int v41; // ST28_4@43
	int v42; // ST24_4@43
	int v43; // eax@43
	FARPROC(__stdcall *v44)(HMODULE, LPCSTR); // eax@44
	int v45; // [sp+180h] [bp-2D4h]@1
	CHAR v46; // [sp+184h] [bp-2D0h]@44
	float v47; // [sp+284h] [bp-1D0h]@40
	int v48; // [sp+288h] [bp-1CCh]@35
	int v49; // [sp+28Ch] [bp-1C8h]@35
	float v50; // [sp+290h] [bp-1C4h]@33
	int v51; // [sp+294h] [bp-1C0h]@26
	int v52; // [sp+298h] [bp-1BCh]@43
	int v53; // [sp+29Ch] [bp-1B8h]@24
	float v54; // [sp+2A0h] [bp-1B4h]@27
	float v55; // [sp+2A4h] [bp-1B0h]@32
	unsigned __int16 v56; // [sp+2A8h] [bp-1ACh]@24
	float v57; // [sp+2ACh] [bp-1A8h]@27
	float v58; // [sp+2B0h] [bp-1A4h]@29
	CHAR String; // [sp+2B4h] [bp-1A0h]@22
	double v60; // [sp+3B4h] [bp-A0h]@18
	int v61; // [sp+3BCh] [bp-98h]@13
	int v62; // [sp+3C0h] [bp-94h]@13
	double v63; // [sp+3C4h] [bp-90h]@11
	double v64; // [sp+3CCh] [bp-88h]@11
	int v65; // [sp+3D8h] [bp-7Ch]@21
	__int64 v66; // [sp+3DCh] [bp-78h]@5
	double v67; // [sp+3E4h] [bp-70h]@5
	__int64 v68; // [sp+3ECh] [bp-68h]@5
	unsigned __int64 v69; // [sp+3F4h] [bp-60h]@5
	double v70; // [sp+3FCh] [bp-58h]@10
	__int64 v71; // [sp+404h] [bp-50h]@5
	double v72; // [sp+40Ch] [bp-48h]@5
	double v73; // [sp+414h] [bp-40h]@7
	__int64 v74; // [sp+41Ch] [bp-38h]@2
	__int64 v75; // [sp+424h] [bp-30h]@2
	double v76; // [sp+42Ch] [bp-28h]@5
	double v77; // [sp+434h] [bp-20h]@5
	__int64 v78; // [sp+43Ch] [bp-18h]@2
	double v79; // [sp+444h] [bp-10h]@5
	double v80; // [sp+44Ch] [bp-8h]@5
	__int64 wLevel;				// 현재 레벨
	__int64 dwNexExperience;	// 다음 레벨업 경험치
	__int64 dwExperience;		// 현재 경험치
	double x, y, width, height;

	v45 = a1;
	if (pIsMaster(*(BYTE *)(*(DWORD*)0x8128AC8 + 11)) == 1)
	{
		wLevel			= *(WORD*)0x87935D8;
		dwNexExperience = *(QWORD*)0x87935E8;
		dwExperience	= *(QWORD*)0x87935E0;
	}
	else
	{
		wLevel			= *(WORD *)(*(DWORD*)0x8128AC8 + 14);
		dwNexExperience = *(DWORD *)(*(DWORD*)0x8128AC8 + 20);
		dwExperience	= *(DWORD *)(*(DWORD*)0x8128AC8 + 16);
	}

	if (pIsMaster(*(BYTE *)(*(DWORD*)0x8128AC8 + 11)) == 1)
	{
		x = 0; y = 470; width = 6; height = 4;

		__int64 iTotalLevel = wLevel + 400;				// 종합레벨 - 400렙이 만렙이기 때문에 더해준다.
		__int64 iTOverLevel = iTotalLevel - 255;		// 255레벨 이상 기준 레벨
		__int64 iBaseExperience = 0;					// 레벨 초기 경험치


		__int64 iData_Master =	// A
			(((__int64)9 + (__int64)iTotalLevel)* (__int64)iTotalLevel* (__int64)iTotalLevel* (__int64)10)
			+
			(((__int64)9 + (__int64)iTOverLevel)* (__int64)iTOverLevel* (__int64)iTOverLevel* (__int64)1000);

		iBaseExperience = (iData_Master - (__int64)3892250000) / (__int64)2;	// B
		// Next Experience
		double fNeedExp = (double)dwNexExperience - (double)iBaseExperience;
		// Experience
		double fExp = (double)dwExperience - (double)iBaseExperience;
		
		if(dwExperience < iBaseExperience)
		{
			fExp = 0.f;
		}

		double fExpBarNum = 0.f;	// 경험치바 단계(0 ~ 9) -> 오른쪽 숫자
		if(fExp > 0.f && fNeedExp > 0)
		{
			fExpBarNum = ((double)fExp / (double)fNeedExp) * (double)10.f;
		}

		double fProgress = fExpBarNum - __int64(fExpBarNum);	// 0.0 ~ 1.0까지 게이지바 한줄에서의 길이

		if (*(BYTE *)(v45 + 40) == 1)
		{
			double fPreProgress = 0.f;	// 원래 있어서 이펙트 안칠해도 되는 부분
			double fPreExp = (double)v45 - (double)iBaseExperience;	// 이전 경험�
			
			if(v45 < iBaseExperience)	// 경험치바 한줄 넘어감
			{
				x = 2.f; y = 473.f; width = fProgress * 629.f; height = 4.f;

				RenderBitmap(31302, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
				glColor4f(1.f, 1.f, 1.f, 0.6f);
				pDrawBarForm(x, y, width, height, 0.0, 0);
				pGLSupremo();
			}
			else	// 경험치바 넘어가지 않음
			{
				int iPreExpBarNum = 0;	// 이전 경험치바 길이 (0.0 ~ 1.0)
				int iExpBarNum = 0;		// 새 경험치바 길이 (0.0 ~ 1.0)

				if(fPreExp > 0.f && fNeedExp > 0.f)
				{
					fPreProgress = ((double)fPreExp / (double)fNeedExp) * (double)10.f;
					iPreExpBarNum = (int)fPreProgress;
					fPreProgress = (double)fPreProgress - __int64(fPreProgress);	// 0.0 ~ 1.0까지 게이지바 한줄에서의 길이
				}
								
				iExpBarNum = (int)fExpBarNum;

				if(iExpBarNum > iPreExpBarNum)
				{
					x = 2.f; y = 473.f; width = fProgress * 629.f; height = 4.f;

					RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
					glColor4f(1.f, 1.f, 1.f, 0.6f);
					pDrawBarForm(x, y, width, height, 0.0, 0);
					pGLSupremo();
				}
				else
				{
					double fGapProgress = 0.f;
					fGapProgress = (double)fProgress - (double)fPreProgress;

					x = 2.f; y = 473.f; width = (double)fPreProgress * (double)629.f; height = 4.f;
					
					RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);

					x += width; width = (double)fGapProgress * (double)629.f;
					RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
					glColor4f(1.f, 1.f, 1.f, 0.6f);
					pDrawBarForm(x, y, width, height, 0.0, 0);
					pGLSupremo();
				}
			}
		}
		else
		{
			x = 2.f; y = 473.f; width = fProgress * 629.f; height = 4.f;

			RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
		}

		int iExp = (int)fExpBarNum;

		x = 635.f; y = 469.f;

		RenderNumber(x, y, iExp, 1.0);

		x = 2.f; y = 473.f; width = 629.f; height = 4.f;

		if(sub_790B10(x, y, width, height) == true)
		{	
			// Line: EXP:%I64d / %I64d
			char strTipText[256];	
			sprintf(strTipText, pGetTextLine(pTextLineThis, 1748), dwExperience, dwNexExperience);
			pDrawToolTip(280, 418, strTipText);
		}
	}
	else
	{
		x = 0; y = 470; width = 6; height = 4;

		WORD wPriorLevel = wLevel - 1;
		DWORD dwPriorExperience = 0;

		if(wPriorLevel > 0)
		{
			dwPriorExperience = (9 + wPriorLevel) * wPriorLevel * wPriorLevel * 10;

			if(wPriorLevel > 255)
			{
				int iLevelOverN = wPriorLevel - 255;
				dwPriorExperience += (9 + iLevelOverN) * iLevelOverN * iLevelOverN * 1000;
			}
		}

		// Next Experience
		float fNeedExp = dwNexExperience - dwPriorExperience;

		// Experience
		float fExp = dwExperience - dwPriorExperience;

		if(dwExperience < dwPriorExperience)
		{
			fExp = 0.f;
		}

		// 경험치바 단계(0 ~ 9)
		float fExpBarNum = 0.f;
		if(fExp > 0.f && fNeedExp > 0)
		{
			fExpBarNum = (fExp / fNeedExp) * 10.f;
		}

		float fProgress = fExpBarNum;
		fProgress = fProgress - (int)fProgress;

		if (*(BYTE *)(v45 + 40) == 1)
		{
			float fPreProgress = 0.f;
			fExp = (v45 + 12) - dwPriorExperience;
			if((v45 + 12) < dwPriorExperience)
			{
				x = 2.f; y = 473.f; width = fProgress * 629.f; height = 4.f;

				RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
				//만렙해제
				glColor4f(1.f, 1.f, 1.f, 0.4f);
				pDrawBarForm(x, y, width, height, 0.0, 0);
				pGLSupremo();
			}
			else
			{
				int iPreExpBarNum = 0;
				int iExpBarNum = 0;
				if(fExp > 0.f && fNeedExp > 0.f)
				{
					fPreProgress = (fExp / fNeedExp) * 10.f;
					iPreExpBarNum = (int)fPreProgress;
					fPreProgress = fPreProgress - (int)fPreProgress;
				}
				iExpBarNum = (int)fExpBarNum;

				if(iExpBarNum > iPreExpBarNum)
				{
					x = 2.f; y = 473.f; width = fProgress * 629.f; height = 4.f;

					RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
					glColor4f(1.f, 1.f, 1.f, 0.4f);
					pDrawBarForm(x, y, width, height, 0.0, 0);
					pGLSupremo();
				}
				else
				{
					float fGapProgress = 0.f;
					fGapProgress = fProgress - fPreProgress;

					x = 2.f; y = 473.f; width = fPreProgress * 629.f; height = 4.f;

					RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
					x += width; width = fGapProgress * 629.f;
					RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
					glColor4f(1.f, 1.f, 1.f, 0.4f);
					pDrawBarForm(x, y, width, height, 0.0, 0);
					pGLSupremo();
				}
			}
		}
		else
		{
			x = 2.f; y = 473.f; width = fProgress * 629.f; height = 4.f;

			RenderBitmap(31301, x, y, width, height, 0.0, 0.0, 0.75, 1.0, 1, 1, 0.0);
		}

		int iExp = (int)fExpBarNum;

		x = 635.f; y = 469.f;

		RenderNumber(x, y, iExp, 1.0);

		x = 2.f; y = 473.f; width = 629.f; height = 4.f;

		if(sub_790B10(x, y, width, height) == true)
		{				
			// Line: EXP:%I64d / %I64d
			char strTipText[256];	
			sprintf(strTipText, pGetTextLine(pTextLineThis, 1748), dwExperience, dwNexExperience);
			pDrawToolTip(280, 418, strTipText);
		}
	}

}