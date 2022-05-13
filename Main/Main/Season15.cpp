#include "stdafx.h"
#include "Season15.h"
#include "Defines.h"
#include "TMemory.h"
#include "import.h"
#include "PrintPlayer.h"
#include "Interface.h"
#include "Protect.h"
#include "Util.h"
#include "User.h"
#include "ItemSetOption.h"
#include "CustomPet.h"
#include "MiniMap.h"
#include "WindowsStruct.h"
#include "Common.h"
#include "CustomInterface.h"
#include "CMacroUIEx.h"
#include "CSCharacterS13.h"
#include "StatsAdvanced.h"
#include "OffTrade.h"
#include "CustomWindow.h"

CEx700 gCRenderEx700;


void sub_813740(int This)
{
	float v4; // ST18_4@17
	float v5; // ST14_4@17
	int v6; // [sp+18h] [bp-34h]@1
	int v7; // [sp+20h] [bp-2Ch]@13
	int v8; // [sp+24h] [bp-28h]@7
	int v9; // [sp+2Ch] [bp-20h]@18
	signed int v10; // [sp+30h] [bp-1Ch]@2
	float w; // [sp+34h] [bp-18h]@4
	signed int i; // [sp+40h] [bp-Ch]@4
	float x; // [sp+44h] [bp-8h]@4
	float y; // [sp+48h] [bp-4h]@4

	int TypeSlot = gProtect.m_MainInfo.CustomInterfaceType;

	float xInterface = TransFor2X( 320 ) - TransForX( 320 );

	float wSkillSelect = (double) (TypeSlot == 4) ? (( 20.0f / 100) * 112.5) : 20 ;
	float hSkillSelect = (double) (TypeSlot == 4) ? (( 28.0f / 100) * 99.99998639285714) : 25;

	float Skill_Height = (double) (TypeSlot == 4) ? (( 28.0f / 100) *  89.28571428571429) : 21;
	float Skill_Width = (double) (TypeSlot == 4) ? (( 20.0f / 100) * 90) : 15;

	v6 = This;

	if ( (signed int)*(BYTE *)(oUserObjectStruct + 118) > 0 )
	{
		v10 = 1;
		if ( *(BYTE *)(This + 20) )
			v10 = 6;
		y = 441.0;
		w = 20.0;

		for ( i = 0; i < 5; ++i )
		{
			v8 = i + v10;
			if ( i + v10 == 10 )
				v8 = 0;
			switch( i )
			{
			case 0:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 333.2999878 : 335));
				break;
			case 1:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 355.6000061 : 357));
				break;
			case 2:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 379 : 381));
				break;
			case 3:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 400.5 : 402));
				break;
			case 4:
				x = Return2X(xInterface + TransForX( (TypeSlot == 4) ? 422.5 : 424));
				break;
			}

			/*if(*(DWORD *)(v6 + 4 * v8 + 24) > 150 && *(DWORD *)(v6 + 4 * v8 + 24) <= 154 && *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) == 0)
			{
				continue;
			}*/

			if ( *(DWORD *)(v6 + 4 * v8 + 24) != -1 && (*(DWORD *)(v6 + 4 * v8 + 24) < 120 || *(DWORD *)(v6 + 4 * v8 + 24) >= 124 || *(DWORD *)(*(DWORD *)0x7BC4F04 + 676)) )
			{
				v7 = *(DWORD *)0x8128ABC + 88 * *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(DWORD *)(v6 + 4 * v8 + 24) + 120);
				
				if ( !v7 || *(BYTE *)(v7 + 55) != 3 )
				{
					SkillView(This, *(DWORD *)(v6 + 4 * v8 + 24), x, (TypeSlot == 4) ? 442.2999878: y + 4.5, Skill_Width, Skill_Height, 1, (TypeSlot == 4) ? 90 : 75, (TypeSlot == 4) ? 89.28571428571429 : 75);

					if ( *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) == *(DWORD *)(v6 + 4 * v8 + 24) )
					{
						RenderBitmap(51500, x - Return2X(TransForX( 6 )), y - 2.5, Return2X(TransForX(28)), ReturnY(TransForY(58)), 0, 0, 1.0, 1.0, 1, 1, 0.0); //-- Slot en Uso
					}
				}
			}
			CRenderNumberEx(x + 6, y - 1.5, v8, 1.02,6829);
		}

		v9 = *(DWORD *)0x8128ABC + 88 * *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);

		if ( v9 && *(BYTE *)(v9 + 55) != 3 )
		{
				SkillView(This, *(BYTE *)(*(DWORD *)0x7BC4F04 + 50), 
					Return2X(xInterface + TransForX((TypeSlot == 4) ? 305.35 : 306 )), 
					(TypeSlot == 4) ? 440.5 : 444, wSkillSelect, hSkillSelect, 0, (TypeSlot == 4) ? 112.5 : 100, (TypeSlot == 4) ? 99.99998639285714 : 89.2857); //-- Slot en Uso
		}
	}
}

void SkillView(int This, int Skill, float a6, float a7, float a8, float a9,int Type, float scaleX1, float scaleY1)
{
	signed int v8; // [sp+30h] [bp-4h]@1
	float v5; // ST24_4@2
	float v6; // ST20_4@2
	float v7; // ST18_4@2
	int v9; // edx@35
	int v10; // ecx@35
	signed int green; // ST28_4@35
	signed int blue; // ST2C_4@106
	float v13; // STE0_4@195
	float v14; // STFC_4@195
	float v15; // ST44_4@195
	float v16; // ST40_4@195
	float v17; // ST3C_4@196
	float v18; // ST38_4@196
	float y; // ST34_4@203
	float x; // ST30_4@203
	int v21; // [sp+8Ch] [bp-78h]@1
	signed int i; // [sp+90h] [bp-74h]@197
	signed int v23; // [sp+94h] [bp-70h]@152
	signed int v24; // [sp+98h] [bp-6Ch]@152
	signed int v25; // [sp+A0h] [bp-64h]@84
	signed int v26; // [sp+A4h] [bp-60h]@84
	signed int v27; // [sp+B0h] [bp-54h]@70
	signed int v28; // [sp+B4h] [bp-50h]@70
	signed int v29; // [sp+C4h] [bp-40h]@18
	signed int v30; // [sp+C8h] [bp-3Ch]@18
	unsigned __int16 v31; // [sp+CCh] [bp-38h]@1
	char v32; // [sp+D3h] [bp-31h]@2
	int v33; // [sp+D4h] [bp-30h]@174
	float v34; // [sp+DCh] [bp-28h]@115
	signed int v35; // [sp+E0h] [bp-24h]@35
	signed int v36; // [sp+E4h] [bp-20h]@2
	signed int v37; // [sp+ECh] [bp-18h]@115
	char v38; // [sp+F3h] [bp-11h]@2
	float v39; // [sp+F8h] [bp-Ch]@115
	signed int v40; // [sp+FCh] [bp-8h]@177
	signed int v41; // [sp+100h] [bp-4h]@197

	float RSkillX = (double) (( 256.0f / 100) * scaleX1);
	float RSkillY = (double) (( 256.0f / 100) * scaleY1);
	float MRSkillX = (double) (( 512.0f / 100) * scaleX1);
	float MRSkillY = (double) (( 512.0f / 100) * scaleY1);

	v31 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * Skill + 120);
	
	v31 = gCRenderEx700.findMasterSkill(v31);

	if ( v31 )
	{
		v32 = 0;
		v38 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v31 + 55);
		v36 = *(WORD *)(*(DWORD *)0x8128ABC + 88 * v31 + 72);
		if ( !sub_4AD0E0(v31) )
			v32 = 1;
		if ( !sub_5B89C0(v31) )
			v32 = 1;
		if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 19) && v38 == 2 )
			v32 = 1;
		if ( v31 == 47
			&& ((signed int)*(WORD *)(*(DWORD *)0x7BC4F04 + 556) < 7829 || (signed int)*(WORD *)(*(DWORD *)0x7BC4F04 + 556) > 7830)
			&& *(WORD *)(*(DWORD *)0x7BC4F04 + 556) != 7864 )
		{
			v32 = 1;
		}
		if ( v31 == 47 && (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v30 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
			v29 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
			if ( (v30 < 1536 || v30 >= 2048) && (v29 < 1536 || v29 >= 2048) )
			v32 = 1;
		}
		if ( (signed int)v31 >= 18 && (signed int)v31 <= 23 && (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830 || *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v32 = 1;
		}
		if ( (v31 == 56 || v31 == 482)
			&& (*(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7829
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7830
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) == 7864) )
		{
			v32 = 1;
		}
		v9 = *(WORD *)(*(DWORD *)0x8128AC8 + 30);
		v10 = *(WORD *)(*(DWORD *)0x8128AC8 + 56);
		v35 = v10 + v9;
		green = v10 + v9;
		pUserStat();
		if ( sub_4E8D80(v31, green, 0) )
			v32 = 1;
		if ( v31 == 63 && *(DWORD *)0x81F6B6C <= 0 )
			v32 = 1;
		if ( v31 == 63 && (*(DWORD *)0xE61E18 == 65 || *(DWORD *)0xE61E18 == 66 || *(DWORD *)0xE61E18 == 67 || *(DWORD *)0xE61E18 == 68) )
			v32 = 1;
		if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512)
			&& (!*(BYTE *)(*(DWORD *)0x8128AC4 + 5550) 
			|| *(WORD *)(*(DWORD *)0x7BC4F04 + 556) != 7831 
			&& gCustomPet2.GetInfoPetType(*(WORD *)(*(DWORD *)0x7BC4F04 + 556) - 1171) != 6) )
		{
			v32 = 1;
		}

		if ( v31 == 77 || v31 == 233 || v31 == 380 || v31 == 383 || v31 == 441 )
		{
			pUserStat();
			if ( sub_4E8D80(v31, v35, 0) )
				v32 = 1;
			if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 6)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 143)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 82)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 138)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 139) )
			{
				v32 = 1;
			}
		}
		if ( v31 == 55 || v31 == 490 )
		{
			if ( (signed int)(unsigned __int16)(*(WORD *)(*(DWORD *)0x8128AC8 + 50) + *(WORD *)(*(DWORD *)0x8128AC8 + 24)) < 596 )
				v32 = 1;
			v28 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
			v27 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
			if ( v27 == -1 || v27 >= 2560 && v27 < 3072 || v28 >= 2560 && v28 < 3072 )
				v32 = 1;
		}
		if ( (v31 == 51 || v31 == 424) && (signed int)(unsigned __int16)(*(WORD *)(*(DWORD *)0x8128AC8 + 52) + *(WORD *)(*(DWORD *)0x8128AC8 + 26)) < 646 )
		{
			v32 = 1;
		}
		//-- Twisting Slash
		if ( v31 == 41 || v31 == 330 || v31 == 481 || v31 == 332 )
		{
			if(*(WORD *)(*(DWORD *)0x7BC4F04 + 448) < 1171 || *(WORD *)(*(DWORD *)0x7BC4F04 + 448) > 3072)
			{
				v32 = 1;
			}
		}
		if ( sub_4E65A0(*(DWORD *)0xE61E18) == 1 )
		{
			if ( v31 == 62
			|| v31 == 49
			|| v31 == 510
			|| v31 == 516
			|| (signed int)v31 >= 120 && (signed int)v31 <= 123
			|| v31 == 512 )
			{
				v32 = 1;
			}
		}
		else if ( (v31 == 62 || v31 == 510 || v31 == 516 || v31 == 512) && !*(BYTE *)(*(DWORD *)0x8128AC4 + 5550) )
		{
			v32 = 1;
		}
		blue = *(WORD *)(*(DWORD *)0x8128AC8 + 62) + *(WORD *)(*(DWORD *)0x8128AC8 + 32);
		pUserStat();
		if ( sub_4E8D80(v31, v35, blue) )
			v32 = 1;
		if ( !sub_5111D0(v31) )
			v32 = 1;
		if ( sub_511110(v31, *(WORD *)(*(DWORD *)0x7BC4F04 + 556)) )
			v32 = 1;
		if ( sub_511290(
				*(WORD *)(*(DWORD *)0x8128AC4 + 5849),
				*(WORD *)(*(DWORD *)0x8128AC4 + 5742),
				*(DWORD *)(*(DWORD *)0x8128AC4 + 5851),
				*(DWORD *)(*(DWORD *)0x8128AC4 + 5744))
			&& pGetCharClass(*(BYTE *)(*(DWORD *)0x7BC4F04 + 19)) == 6 )
		{
			v32 = 1;
		}
		v34 = 0.0;
		v39 = 0.0;
		v37 = 0;
		pUserStat();
		if ( !sub_4EAC90( v31) )
			v32 = 1;
		pUserStat();
		if ( !sub_4EAC90( v31) )
			v32 = 1;
		if ( (signed int)v31 < 120 || (signed int)v31 > 124 )
		{
			if ( v31 == 76 )
			{
				v34 = a8 * 4.0 / RSkillX;
				v39 = 0.0;
				v37 = 1;
			}
			else if ( (signed int)v31 < 214 || (signed int)v31 > 217 )
			{
				if ( (signed int)v31 < 219 || (signed int)v31 > 220 )
				{
					if ( v31 == 218 )
					{
						v34 = a8 * 10.0 / RSkillX;
						v39 = a9 * 3.0 / RSkillY;
						v37 = 3;
					}
					else if ( (signed int)v31 < 221 || (signed int)v31 > 222 )
					{
						if ( (signed int)v31 < 223 || (signed int)v31 > 224 )
						{
							if ( v31 == 225 )
							{
								v34 = a8 * 11.0 / RSkillX;
								v39 = a9 * 3.0 / RSkillY;
								v37 = 3;
							}
							else if ( v31 == 232 )
							{
								v34 = a8 * 7.0 / RSkillX;
								v39 = a9 * 2.0 / RSkillY;
								v37 = 3;
							}
							else if ( v31 != 523 )
							{
								switch ( v31 )
								{
								case 0xEEu:
									v34 = a8 * 3.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xEAu:
									v34 = a8 * 9.0 / RSkillX;
									v39 = a9 * 2.0 / RSkillY;
									v37 = 3;
									break;
								case 0xEBu:
									if ( !sub_587A80() )
										v32 = 1;
									v34 = a8 * 0.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xECu:
									v24 = *(WORD *)(*(DWORD *)0x8128AC4 + 4779);
									v23 = *(WORD *)(*(DWORD *)0x8128AC4 + 4672);
									if ( v23 == -1 || v23 >= 2560 && v23 < 3072 || v24 >= 2560 && v24 < 3072 )
										v32 = 1;
									v34 = a8 * 1.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xEDu:
									v34 = a8 * 2.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xE6u:
									v34 = a8 * 2.0 / RSkillX;
									v39 = a9 * 3.0 / RSkillY;
									v37 = 3;
									break;
								case 0x1C8u:
									v34 = a8 * 6.0 / RSkillX;
									v39 = a9 * 8.0 / RSkillY;
									v37 = 3;
									break;
								case 0xE9u:
									v34 = a8 * 8.0 / RSkillX;
									v39 = a9 * 2.0 / RSkillY;
									v37 = 3;
									break;
								default:
									if ( v38 == 4 )
									{
										v34 = a8 / RSkillX * (double)(v36 % 12);
										v39 = a9 / RSkillY * (double)(v36 / 12 + 4);
										v37 = 3;
									}
									else if ( (signed int)v31 < 260 )
									{
										if ( (signed int)v31 < 57 )
										{
											v34 = (double)((v31 - 1) % 8) * a8 / RSkillX;
											v39 = (double)((v31 - 1) / 8) * a9 / RSkillY;
											v37 = 2;
										}
										else
										{
											v34 = (double)((v31 - 57) % 8) * a8 / RSkillX;
											v39 = (double)((v31 - 57) / 8) * a9 / RSkillY;
											v37 = 3;
										}
									}
									else
									{
										v34 = (double)((v31 - 260) % 12) * a8 / RSkillX;
										v39 = (double)((v31 - 260) / 12) * a9 / RSkillY;
										v37 = 4;
									}
									break;
								}
							}
						}
						else
						{
							v34 = (double)((v31 - 217) % 8) * a8 / RSkillX;
							v39 = a9 * 3.0 / RSkillY;
							v37 = 3;
						}
					}
					else
					{
						v34 = (double)(v31 - 213) * a8 / RSkillX;
						v39 = a9 * 3.0 / RSkillY;
						v37 = 3;
					}
				}
				else
				{
					v34 = (double)((v31 - 215) % 8) * a8 / RSkillX;
					v39 = a9 * 3.0 / RSkillY;
					v37 = 3;
				}
			}
			else
			{
				v34 = (double)((v31 - 214) % 8) * a8 / RSkillX;
				v39 = a9 * 3.0 / RSkillY;
				v37 = 3;
			}
		}
		else
		{
			v34 = (double)((v31 - 120) % 8) * a8 / RSkillX;
			v39 = (double)((v31 - 120) / 8) * a9 / RSkillY;
			( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) ) ? v32 = 0 : v32 = 1;
			v37 = 1;
		}
		
		v33 = *(DWORD *)0x8128ABC + 88 * v31;

		if ( v33 && *(BYTE *)(v33 + 55) == 4 )
			v37 = 5;

		v40 = 0;

		switch ( v37 )
		{
			case 1:
				v40 = 31310;
				if ( v32 == 1 )
					v40 = 31316;
			break;
			case 2:
				v40 = 31308;
				if ( v32 == 1 )
					v40 = 31314;
			break;
			case 3:
				v40 = 31309;
				if ( v32 == 1 )
					v40 = 31315;
			break;
			case 4:
				v40 = 31311;
				if ( v32 == 1 )
					v40 = 31317;
			break;
			case 5:
				v40 = 31534;
				if ( v32 == 1 )
					v40 = 31535;
			break;
			default:
			break;
		}
		if ( v40 )
		{
			if ( v33 && *(BYTE *)(v33 + 55) == 4 )
			{
				v13 = a8 / MRSkillX * (double)(*(WORD *)(v33 + 72) % 25);
				v14 = a9 / MRSkillY * (double)(*(WORD *)(v33 + 72) / 25);
				v16 = a8 / MRSkillX;
				v15 = a9 / MRSkillY;
				RenderBitmap(v40, a6, a7, Return2X(TransForX(a8)), ReturnY(TransForY(a9)), v13, v14, v16, v15, 1, 1, 0.0);
			}
			else
			{
				v17 = a9 / RSkillY;
				v18 = a8 / RSkillX;
				RenderBitmap(v40, a6, a7, Return2X(TransForX(a8)), ReturnY(TransForY(a9)), v34, v39, v18, v17, 1, 1, 0.0);
			}
		}

		if ( (v31 != 262 && v31 != 265 && v31 != 264 && v31 != 558 && v31 != 560 || !v32) 
			&& v31 != 77 && v31 != 233 && v31 != 380 && v31 != 383 && v31 != 441 )
		{
			v8 = *(DWORD *)(*(DWORD *)0x8128AC8 + 4 * Skill + 2072);
			if ( v8 > 0 )
			{
				v5 = (double)v8 / (double)*(signed int *)(*(DWORD *)0x8128ABC + 88 * *(WORD *)(*(DWORD *)0x8128AC8 + 2 * Skill + 120) + 44);
				EnableAlphaTest(1);
				glColor4f(1.0, 0.5, 0.5, 0.5);
				v6 = a9 * v5;
				v7 = a7 + a9 - v6;
				pDrawBarForm(a6, v7, Return2X(TransForX(a8)), ReturnY(TransForY(v6)), 0.0, 0);
				pGLSupremo();
			}
		}
	}
}

int ReturnSkillX(int number, int type)
{
	float xInterface = TransFor2X( 320 ) - TransForX( 320 / 2 );
	int x;

	switch(number)
	{
	case 1:
		x = Return2X(xInterface + TransForX( (type == 2) ? 11 : 2));
		break;
	case 2:
		x = Return2X(xInterface + TransForX( (type == 2) ? 42 : 33));
		break;
	case 3:
		x = Return2X(xInterface + TransForX( (type == 2) ? 74 : 65 ));
		break;
	case 4:
		x = Return2X(xInterface + TransForX( (type == 2) ? 105 : 96 ));
		break;
	case 5:
		x = Return2X(xInterface + TransForX( (type == 2) ? 137 : 128 ));
		break;
	case 6:
		x = Return2X(xInterface + TransForX( (type == 2) ? 168 : 159 ));
		break;
	case 7:
		x = Return2X(xInterface + TransForX( (type == 2) ? 199 : 190 ));
		break;
	case 8:
		x = Return2X(xInterface + TransForX( (type == 2) ? 231 : 222 ));
		break;
	case 9:
		x = Return2X(xInterface + TransForX( (type == 2) ? 263 : 254 ));
		break;
	case 10:
		x = Return2X(xInterface + TransForX( (type == 2) ? 295 : 286 ));
		break;
	}
	return x;
}

void Render_SkillTooltip(int x, int y, int nCount, int witd, int height,int type, int Align)
{
	tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
	int * ColorTexto = (int*)NewAddressData1;
	int * LineWeight = (int*)NewAddressData2;
	
	HDC hDC = GetDC(*(HWND*)(0x00E8C578));
	HGDIOBJ font = pFontNormal;
	//--
	SIZE psizl; // [sp+90h] [bp-1Ch]@1
	int counter1; // [sp+88h] [bp-24h]@1
	int counter2; // [sp+A8h] [bp-4h]@1
	float cRenderW; // [sp+8Ch] [bp-20h]@1
	float cRenderH; // [sp+98h] [bp-14h]@1
	float cRenderX; // [sp+A0h] [bp-Ch]@22
	float cRenderY; // [sp+9Ch] [bp-10h]@26
	float SaltoLine;
	//--
	float v64; // [sp+68h] [bp-44h]@53
	float v71; // [sp+84h] [bp-28h]@1
	float v76; // [sp+9Ch] [bp-10h]@26

	v71 = (( pCheckWindow(pWindowThis(), 57) == true ) ? 1.3 : 1.1 );
	//-- principal
	counter1 = 0;
	counter2 = 0;
	cRenderX = (double) (signed int) x;
	cRenderW = 0.0;
	cRenderH = 0.0;
	psizl.cx = 0;
	psizl.cy = 0;
	
	for(int n = 0; n < nCount; ++n)
	{
		if(!TooltipLine[n]) { nCount = n; break; }

		if( LineWeight[n] == 1 )
			font = pFontBold;
		else
			font = pFontNormal;

		SelectObject(hDC, font);
		
		GetTextExtentPoint32(hDC, TooltipLine[n], strlen(TooltipLine[n]), &psizl);

		if ( cRenderW < (double)(signed int)psizl.cx )
			cRenderW = (double)(signed int)psizl.cx;
		if (lstrlenA(TooltipLine[n]) < 2 )
			++counter2;
		else
			++counter1;
	}
	cRenderH = (double) ( counter1 * psizl.cy ) + (double) (signed int) psizl.cy / 2.0 * (double) counter2;
	
	cRenderH = (double) ( cRenderH / ( pWinHeightReal / v71 ));

	cRenderY = (double) (signed int) (( y + cRenderH > 420 ) ? 420 - cRenderH : y - 10 );

	pSetBlend(true);

	cRenderW = (double) (( witd > 0 ) ? ( (double)witd / pWinWidthReal + (double)witd / pWinWidthReal ) : ( ( cRenderW / pWinWidthReal ) + 4.0 ));

	cRenderX = (double) (cRenderX - cRenderW / 2.0 );

	cRenderX = (( cRenderX < 0 ) ? 1.0 : cRenderX);

	cRenderX = (((double) pWinWidth / pWinWidthReal < (double) cRenderX + cRenderW ) ? ((double) pWinWidth / pWinWidthReal - cRenderW - 1.0 ) : cRenderX );

	v76 = (double) (( type == 8 ) ? ( cRenderY - cRenderH) : cRenderY );

	SaltoLine = (double) (( type == 8 ) ? ( cRenderY - cRenderH) : cRenderY );

	if ( Align == 1 && nCount > 0 )
	{
		gCItemSetOption.ItemTooltipS15(cRenderX, cRenderY, cRenderW, cRenderH, 0.0, 0);
	}
	//-- Escritura
	for( int k = 0; k < nCount; ++k )
	{
		//-- Texto Principal
		if( LineWeight[k] )
			font = pFontBold;
		else
			font = pFontNormal;

		pSetFont(pTextThis(), (int)font);
		
		v64 = 0.0;
		if( ((DWORD) TooltipLine[k] != 10 && ( DWORD) TooltipLine[k] != 32 || (DWORD) TooltipLine[k] ) && lstrlenA(TooltipLine[k]) > 2 )
		{
			gCItemSetOption.RenderColor( ColorTexto[k] );

			pDrawText( pTextThis(), (double)(cRenderX + 1), v76, TooltipLine[k], ( cRenderW - 1.0f ), 0, (LPINT)height, 0 );
			
			SelectObject(hDC, font);
			GetTextExtentPoint32(hDC, TooltipLine[k], strlen(TooltipLine[k]), &psizl);
			v64 = (double)(signed int)psizl.cy / pWinHeightReal / 1.0;
		}
		else
		{
			SelectObject(hDC, font);
			GetTextExtentPoint32(hDC, TooltipLine[k], strlen(TooltipLine[k]), &psizl);

			if ( lstrlenA(TooltipLine[k]) > 2 )
				v64 = (double)(signed int)psizl.cy / pWinHeightReal / 1.0;
			else
				v64 = (double)(signed int)psizl.cy / pWinHeightReal / 2.0;
		}

		v76 = v64 * v71 + v76;
	}

	glColor4f(1.0, 1.0, 1.0, 1.0);
	pGLSwitch();
}

bool CEx700::SkillMouseOver(DWORD a1)
{
	bool result; // al@2
	unsigned __int8 v5; // ST4F_1@3
	int v62; // [sp+Ch] [bp-54h]@1
	int v64; // [sp+18h] [bp-48h]@84
	unsigned __int16 v66; // [sp+24h] [bp-3Ch]@53
	signed int v67; // [sp+2Ch] [bp-34h]@40
	signed int v68; // [sp+30h] [bp-30h]@40
	unsigned __int16 v69; // [sp+38h] [bp-28h]@76
	float v70; // [sp+40h] [bp-20h]@5
	float v71; // [sp+40h] [bp-20h]@28
	float v72; // [sp+40h] [bp-20h]@40
	float v73; // [sp+40h] [bp-20h]@73
	float v74; // [sp+40h] [bp-20h]@116
	float v75; // [sp+44h] [bp-1Ch]@5
	float v76; // [sp+44h] [bp-1Ch]@28
	float v77; // [sp+44h] [bp-1Ch]@73
	char v78; // [sp+4Bh] [bp-15h]@73
	float v79; // [sp+4Ch] [bp-14h]@73
	signed int v80; // [sp+50h] [bp-10h]@73
	int v81; // [sp+54h] [bp-Ch]@73
	float v82; // [sp+58h] [bp-8h]@5
	float v83; // [sp+58h] [bp-8h]@28
	float v84; // [sp+58h] [bp-8h]@40
	float v85; // [sp+58h] [bp-8h]@85
	float v86; // [sp+58h] [bp-8h]@116
	float v87; // [sp+5Ch] [bp-4h]@5
	float v88; // [sp+5Ch] [bp-4h]@28
	float v89; // [sp+5Ch] [bp-4h]@40
	float v90; // [sp+5Ch] [bp-4h]@73
	float v91; // [sp+5Ch] [bp-4h]@116*/
	signed int j; // [sp+10h] [bp-50h]@116
	signed int i; // [sp+20h] [bp-40h]@73

	float xInterface = TransFor2X( 320 ) - TransForX( 320 );

	float xSwitch = TransFor2X( 320 ) - TransForX( 320 / 2 );
	float ySwitch = TransForY( 480 ) - TransForY( 160 );
	int ContadorSkill = 0;

	float wSkillSelect = (double) 20;
	float hSkillSelect = (double) (( 28.0f / 100) * 89.2857);

	float Skill_Height = (double) (( 28.0f / 100) * 75);
	float Skill_Width = (double) (( 20.0f / 100) * 75);

	v62 = a1;
	if ( pCheckEffectPlayer((DWORD *)(*(DWORD *)0x7BC4F04 + 1260), 98) )
	{
		*(BYTE *)(v62 + 64) = 0;
		result = 1;
	}
	else
	{
		v5 = *(BYTE *)(*(DWORD *)0x8128AC8 + 118);
		*(BYTE *)(v62 + 65) = 0;
		if ( (signed int)v5 > 0 )
		{
			//308.0, 447.5, (double) (( 20.0f / 100) * 83.00001145), (double) (( 28.0f / 100) * 75)
			//-- skill en uso
			v82 = Return2X(xInterface + TransForX( 306 )); //-- x
			v87 = ReturnY(TransForY(444)); //-- y
			v70 = Return2X(TransForX(wSkillSelect)); //-- w
			v75 = ReturnY(TransForY(hSkillSelect)); //-- h

			if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
			{
				if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 || pCheckMouseOver(v82, v87, v70, v75) )
				{
					if ( *(DWORD *)(v62 + 80) != 1 || *(BYTE *)0x8793384 != 1 && *(BYTE *)0x8793380 != 1 || pCheckMouseOver(v82, v87, v70, v75) != 1 )
					{
						if ( *(DWORD *)(v62 + 80) != 2 || *(BYTE *)0x8793384 || *(BYTE *)0x8793380 )
						{
							if ( *(DWORD *)(v62 + 80) == 1 )
							{
								*(BYTE *)(v62 + 65) = 1;
								*(DWORD *)(v62 + 68) = *(BYTE *)(*(DWORD *)0x7BC4F04 + 50);
								*(DWORD *)(v62 + 72) = v82 - 5.0;
								*(DWORD *)(v62 + 76) = v87;
								result = 0;
							}
							else if ( *(DWORD *)(v62 + 80) == 2 )
							{
								result = 0;
							}
							else
							{
								//-- DrawSkill Bar
								v83 = Return2X(xInterface + TransForX( 335 ));
								v88 = 445.5;
								v71 = Return2X(TransForX( Skill_Width )) + Return2X(xInterface + TransForX( 424 )) - Return2X(xInterface + TransForX( 335 ));
								v76 = ReturnY(TransForY(Skill_Height));
								if ( *(DWORD *)(v62 + 80) || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
								{
									if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 || pCheckMouseOver(v83, v88, v71, v76) )
									{
										if ( *(DWORD *)(v62 + 80) != 3 || *(BYTE *)0x8793384 != 1 || pCheckMouseOver(v83, v88, v71, v76) != 1 )
										{
										//-- DrawSkill Bar Slot 5
											v84 = 315.0;
											v89 = 445.5;
											v72 = Return2X(TransForX( Skill_Width ));
											v68 = 0;
											v67 = *(BYTE *)(v62 + 20) != 1 ? 1 : 6;
											while ( v68 < 5 )
											{
												v84 = v84 + v72;
												if ( v67 == 10 )
													v67 = 0;

												switch(v68)
												{
												case 0:
													v84 = Return2X(xInterface + TransForX( 335 ));
													break;
												case 1:
													v84 = Return2X(xInterface + TransForX( 357 ));
													break;
												case 2:
													v84 = Return2X(xInterface + TransForX( 381 ));
													break;
												case 3:
													v84 = Return2X(xInterface + TransForX( 402 ));
													break;
												case 4:
													v84 = Return2X(xInterface + TransForX( 424 ));
													break;
												}
												if ( pCheckMouseOver(v84, v89, v72, ReturnY(TransForY(Skill_Height))) == 1 )
												{
													if ( *(DWORD *)(v62 + 4 * v67 + 24) == -1 )
													{
														if ( *(DWORD *)(v62 + 80) == 3 )
														{
															*(BYTE *)(v62 + 65) = 0;
															*(DWORD *)(v62 + 68) = -1;
														}
														if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															*(DWORD *)(v62 + 80) = 0;
													}
													else
													{
														v66 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(DWORD *)(v62 + 4 * v67 + 24) + 120);
														if ( v66 && ((signed int)v66 < 67 || (signed int)v66 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v66 + 55) != 3 )
														{
															if ( *(DWORD *)(v62 + 80) == 3 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = *(DWORD *)(v62 + 4 * v67 + 24);
																*(DWORD *)(v62 + 72) = v84 - 5.0;
																*(DWORD *)(v62 + 76) = v89;
																return 1;
															}
															if ( *(DWORD *)(v62 + 80) == 4 && !*(BYTE *)0x8793384 )
															{
																if ( *(DWORD *)(v62 + 68) == *(DWORD *)(v62 + 4 * v67 + 24) )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = *(BYTE *)(v62 + 4 * v67 + 24);
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
																*(DWORD *)(v62 + 80) = 0;
															}
														}
													}
												}
												++v68;
												++v67;
											}
											if ( *(DWORD *)(v62 + 80) == 4 )
											{
												//-- DrawSkill Bar
												if ( *(BYTE *)0x8793384 || pCheckMouseOver((int)330.0, (int)447.5, (int)100.0, (int)32.0))
												{
													result = 0;
												}
												else
												{
													*(DWORD *)(v62 + 80) = 0;
													result = 1;
												}
											}
											else if ( *(BYTE *)(v62 + 64) )
											{
												//-- SkillBarSwitch
												v80 = 0;
												v78 = 0;
												v90 = 370.0;//-- y
												v73 = 32.0;//-- w
												v77 = 38.0;//-- h
												v79 = 302.0;//-- x
												v81 = *(DWORD *)(v62 + 80);
												for ( i = 0; i < 150; ++i )
												{
													v69 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);
													if ( v69 && ((signed int)v69 < 67 || (signed int)v69 > 72) && *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v69 + 55) != 3 )
													{
														++v80;

					if( SkillPage == 1 && v80 > 20)
					{
						continue;
					}
					else if( SkillPage == 2 && v80 <= 20)
					{
						continue;
					}

					if( v80 <= 10 || v80 > 20  &&  v80 <= 30 )
					{
						ContadorSkill = ( v80 <= 10 ) ? v80 : v80 - 20;
						v90 = ReturnY(ySwitch );
					}
					else
					{
						ContadorSkill = ( v80 > 10 && v80 <= 20|| v80 > 30 ) ? v80 - 10 : v80 - 30;
						v90 = ReturnY(ySwitch + TransForY(39));
					}

					v85 = ReturnSkillX(ContadorSkill, 1);
														
														if ( pCheckMouseOver(v85, v90, Return2X(TransForX(v73)), ReturnY(TransForY(v77))) == 1 )
														{
															v78 = 1;
															if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
															{
																*(DWORD *)(v62 + 80) = 5;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(DWORD *)(v62 + 80) = 6;
																break;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 5 && !*(BYTE *)0x8793384 )
														{
															if ( pCheckMouseOver(v85, v90, v73, v77) == 1 )
															{
																*(BYTE *)(v62 + 65) = 1;
																*(DWORD *)(v62 + 68) = i;
																*(DWORD *)(v62 + 72) = v85;
																*(DWORD *)(v62 + 76) = v90;
															}
														}
														if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == i )
														{
															if ( pCheckMouseOver(v85, v90, Return2X(TransForX(v73)), ReturnY(TransForY(v77))) == 1 )
															{
																*(DWORD *)(v62 + 80) = 0;
																*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = i;
																*(BYTE *)(v62 + 64) = 0;
																PlayBuffer(25, 0, 0);
																return 0;
															}
														}
													}
												}
												if ( v81 == *(DWORD *)(v62 + 80) )
												{
													if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
													{
														//-- SkillFixRaven
														v86 = 270.0;
														v91 = 356.0;
														v74 = 32.0;
														float v1259;
														int contadorsito = 0;
														for ( j = 150; j < 154; ++j )
														{
															contadorsito++;
															v1259 = ReturnSkillX(contadorsito, 1);
															if ( pCheckMouseOver(v1259, v91, v74, (float)38.0) == 1 )
															{
																v78 = 1;
																if ( !*(DWORD *)(v62 + 80) && !*(BYTE *)0x8793384 )
																{
																	*(DWORD *)(v62 + 80) = 5;
																	return 1;
																}
																if ( *(DWORD *)(v62 + 80) == 5 && *(BYTE *)0x8793384 == 1 )
																{
																	*(DWORD *)(v62 + 80) = 6;
																	return 0;
																}
																if ( *(DWORD *)(v62 + 80) == 5 )
																{
																	*(BYTE *)(v62 + 65) = 1;
																	*(DWORD *)(v62 + 68) = j;
																	*(DWORD *)(v62 + 72) = v86;
																	*(DWORD *)(v62 + 76) = v91;
																}
																if ( *(DWORD *)(v62 + 80) == 6 && !*(BYTE *)0x8793384 && *(DWORD *)(v62 + 68) == j )
																{
																	*(DWORD *)(v62 + 80) = 0;
																	*(WORD *)(v62 + 84) = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) + 120);
																	*(BYTE *)(*(DWORD *)0x7BC4F04 + 50) = j;
																	*(BYTE *)(v62 + 64) = 0;
																	PlayBuffer(25, 0, 0);
																	return 0;
																}
															}
															v86 = v86 + v74;
														}
													}
													if ( v78 || *(DWORD *)(v62 + 80) != 5 )
													{
														if ( v78 || *(BYTE *)0x8793384 || *(DWORD *)(v62 + 80) != 6 )
														{
															if ( *(DWORD *)(v62 + 80) == 6 )
															{
																if ( *(BYTE *)0x8793384 )
																{
																	result = 0;
																}
																else
																{
																	*(DWORD *)(v62 + 80) = 0;
																	result = 1;
																}
															}
															else
															{
																result = 1;
															}
														}
														else
														{
															*(DWORD *)(v62 + 80) = 0;
															result = 0;
														}
													}
													else
													{
														*(DWORD *)(v62 + 80) = 0;
														result = 1;
													}
												}
												else
												{
													result = !*(DWORD *)(v62 + 80) || *(DWORD *)(v62 + 80) == 5;
												}
											}
											else
											{
												result = 1;
											}
										}
										else
										{
											*(DWORD *)(v62 + 80) = 4;
											result = 0;
										}
									}
									else
									{
										*(DWORD *)(v62 + 80) = 0;
										result = 1;
									}
								}
								else
								{
									*(DWORD *)(v62 + 80) = 3;
									result = 1;
								}
							}
						}
						else
						{
							if ( pCheckMouseOver(v82, v87, v70, v75) == 1 )
							{
								*(BYTE *)(v62 + 64) = *(BYTE *)(v62 + 64) == 0;
								PlayBuffer(25, 0, 0);
								*(DWORD *)(v62 + 80) = 0;
								result = 0;
							}
							else
							{
								*(DWORD *)(v62 + 80) = 0;
								result = 1;
							}
						}
					}
					else
					{
						*(DWORD *)(v62 + 80) = 2;
						result = 0;
					}
				}
				else
				{
					*(DWORD *)(v62 + 80) = 0;
					result = 1;
				}
			}
			else
			{
				*(DWORD *)(v62 + 80) = 1;
				result = 1;
			}
		}
		else
		{
			result = 1;
		}
	}
	return result;
}

void CEx700::SkillRavenSwitchBar(DWORD * a1)
{
	float v4; // ST18_4@7
	float v5; // ST14_4@7
	int v6; // [sp+18h] [bp-18h]@1
	signed int i; // [sp+1Ch] [bp-14h]@2
	float v8; // [sp+20h] [bp-10h]@2
	float v9; // [sp+24h] [bp-Ch]@2
	float v10; // [sp+28h] [bp-8h]@2
	float v11; // [sp+2Ch] [bp-4h]@2
	float Height = (double) (( 28.0f / 100) * 75);
	float Width = (double) (( 20.0f / 100) * 75);

	v6 = *(DWORD *)a1;
	if ( *(DWORD *)(*(DWORD *)0x7BC4F04 + 676) )
	{
		v10 = 270.0;
		v11 = 356.0;
		v8 = 32.0;
		v9 = 38.0;

		int contador = 0;

		for ( i = 150; i < 154; ++i )
		{
			//if ( i == *(BYTE *)(*(DWORD *)0x7BC4F04 + 50) )
			//	pDrawGUI(31313, v10, v11, v8, v9);
			//else
			//	pDrawGUI(31312, v10, v11, v8, v9);

			v4 = v11 + 9.0;
			contador++;
			v5 = ReturnSkillX(contador, 2);
			//v5 = v10 + 8.0;

			for (int k = 0; k < 10; ++k )
			{
				if ( *(DWORD *)(a1 + 4 * k + 24) == i )
				{
					CRenderNumberEx(v5 + Return2X(TransForX(Width)), v4 + ReturnY(TransForY(Height- 5)), k, 1.00, 31337);
					break;
				}
			}

			SkillView(*(DWORD*)a1, i, v5, v4, (double) (( 20.0f / 100) * 83.00001145), (double) (( 28.0f / 100) * 75), 2, 83.00001145, 75);
		}
	}
}

int CEx700::findMasterSkill(int Skill)
{
	for(int n = 0; n < this->MasterSkillCount; n++)
	{
//-- Blade Master
		//-- Skill Death Stab
		if( (Skill == MASTER_SKILL_ADD_DEATH_STAB_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DEATH_STAB_ENHANCED) 
			|| (Skill == MASTER_SKILL_ADD_DEATH_STAB_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DEATH_STAB_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Frozen Stab
		if( (Skill == MASTER_SKILL_ADD_FROZEN_STAB_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FROZEN_STAB_ENHANCED) 
			|| (Skill == MASTER_SKILL_ADD_FROZEN_STAB_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FROZEN_STAB_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Five Shot
		if( (Skill == MASTER_SKILL_ADD_FIVE_SHOT_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIVE_SHOT_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Greater Life
		if( (Skill == MASTER_SKILL_ADD_GREATER_LIFE_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_GREATER_LIFE_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
//-- Soul Master
		//-- Skill Mana Shield
		if( (Skill == MASTER_SKILL_ADD_MANA_SHIELD_ENHANCED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_MANA_SHIELD_MASTERED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Ice Storm
		if( (Skill == 39 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_ICE_STORM_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_ICE_STORM_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_ICE_STORM_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill Meteorite
		if( (Skill == 2 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_METEORITE_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_METEORITE_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_METEORITE_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
//-- Fist Master
		//-- Skill CHAIN_DRIVER
		if( (Skill == MASTER_SKILL_ADD_CHAIN_DRIVER_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_CHAIN_DRIVER_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill DARK_SIDE
		if( (Skill == MASTER_SKILL_ADD_DARK_SIDE_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DARK_SIDE_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill DRAGON_LORE
		if( (Skill == MASTER_SKILL_ADD_DRAGON_LORE_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DRAGON_LORE_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- Skill DRAGON_SLAYER
		if( (Skill == 265 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DRAGON_SLAYER_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_DRAGON_SLAYER_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_DRAGON_SLAYER_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		
		//-- Skill SWORD_SLASH
		if( (Skill == 236 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_SWORD_SLASH_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_SWORD_SLASH_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_SWORD_SLASH_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
		//-- FIRE_SLASH
		if((Skill == 55 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIRE_SLASH_IMPROVED) 
			|| (Skill == MASTER_SKILL_ADD_FIRE_SLASH_IMPROVED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIRE_SLASH_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- LIGHTNING_STORM
		if( (Skill == 237 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_LIGHTNING_STORM_IMPROVED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == 65 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_ELECTRIC_SPARK_IMPROVED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == MASTER_SKILL_ADD_FIRE_SCREAM_IMPROVED && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_FIRE_SCREAM_ENHANCED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == 238 && this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_BIRDS_IMPROVED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}

		//-- ELECTRIC_SPARK
		if( (Skill == MASTER_SKILL_ADD_GREATER_CRITICAL_DAMAGE_MASTERED 
			&& this->m_MasterSkillInfo[n].skill == MASTER_SKILL_ADD_GREATER_CRITICAL_DAMAGE_EXTENDED) )
		{
			Skill = this->m_MasterSkillInfo[n].skill;
		}
	}

	return Skill;
}


double CRenderNumberEx(float a1, float a2, int a3, float a4, DWORD ModelID)
{
	double result; // st7@2
	float v5; // ST44_4@5
	float v6; // ST38_4@5
	signed int i; // [sp+38h] [bp-30h]@3
	float v8; // [sp+3Ch] [bp-2Ch]@3
	signed int v9; // [sp+44h] [bp-24h]@3
	char v10[32]; // [sp+48h] [bp-20h]@3
	float v11; // [sp+70h] [bp+8h]@3

	EnableAlphaTest(1);
	glColor4f(50, 50, 50, 190);
				
	if ( a4 >= 0.300000011920929 )
	{
		v8 = (a4 - 0.4800000119209290) * 12.0;
		itoa(a3, v10, 10);
		v9 = strlen(v10);
		v11 = a1 - (double)v9 * v8 / 2.0;
		for ( i = 0; i < v9; ++i )
		{
			v6 = (double)(v10[i] - 48) * 12.0 / 128.0;
			v5 = (a4 - 0.400000011920929) * 16.0;
			RenderBitmap(ModelID, v11, a2, v8, v5, v6, 0.0, 0.09375, 0.875, 1, 1, 0.0);
			v11 = v8 * 0.800000011920929 + v11;
		}
		result = v11;
	}
	else
	{
		result = a1;
	}
	pGLSupremo();
	return result;
}


char CEx700::SkillSwitchBar(int This)
{
	float v4; // ST18_4@26
	float v5; // ST14_4@26
	int v7; // [sp+28h] [bp-34h]@1
	int v8; // [sp+30h] [bp-2Ch]@15
	char v9; // [sp+37h] [bp-25h]@9
	float v10; // [sp+38h] [bp-24h]@3
	signed int v11; // [sp+3Ch] [bp-20h]@3
	signed int v12; // [sp+40h] [bp-1Ch]@6
	float v13; // [sp+44h] [bp-18h]@3
	float v14; // [sp+48h] [bp-14h]@3
	signed int i; // [sp+50h] [bp-Ch]@3
	float v16; // [sp+54h] [bp-8h]@16
	float v17; // [sp+58h] [bp-4h]@3
	float Height = (double) (( 28.0f / 100) * 75);
	float Width = (double) (( 20.0f / 100) * 75);

	float xInterface = TransFor2X( 320 ) - TransForX( 320 / 2 );
	float yInterface = TransForY( 480 ) - TransForY( 160 );

	v7 = This;
	int ContadorSkill;

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);

	if ( (signed int)*(BYTE *)(*(DWORD *)0x8128AC8 + 118) > 0 && *(BYTE *)(v7 + 64) == 1 )
	{
		OpenSwicthSkill = 1;
		RenderBitmap(61546, xInterface, yInterface, TransForX( 320 ), TransForY( 76 ), 0.0, 0.0, 1.0, 1.0, 0, 0, 0);

		v17 = 370.0;
		v13 = 32.0;
		v14 = 38.0;
		v10 = 302.0;
		v11 = 0;

		for ( i = 0; i < 150; ++i )
		{
			v12 = *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120);

			if ( *(WORD *)(*(DWORD *)0x8128AC8 + 2 * i + 120) && (v12 < 67 || v12 > 72) )
			{
				v9 = *(BYTE *)(*(DWORD *)0x8128ABC + 88 * v12 + 55);
				
				if ( v9 != 1 && v9 != 3 )
				{
					++v11;

					if( SkillPage == 1 && v11 > 20)
					{
						continue;
					}
					else if( SkillPage == 2 && v11 <= 20)
					{
						continue;
					}

					if( v11 <= 10 || v11 > 20  &&  v11 <= 30 )
					{
						ContadorSkill = ( v11 <= 10 ) ? v11 : v11 - 20;
						v4 = ReturnY(yInterface + TransForY(10));
					}
					else
					{
						ContadorSkill = ( v11 > 10 && v11 <= 20|| v11 > 30 ) ? v11 - 10 : v11 - 30;
						v4 = ReturnY(yInterface + TransForY(47));
					}

					v5 = ReturnSkillX(ContadorSkill, 2);
					
					SkillView(This, i, v5, v4, (double) (( 20.0f / 100) * 83.00001145), (double) (( 28.0f / 100) * 75), 2, 83.00001145, 75);

					for (int k = 0; k < 10; ++k )
					{
						if ( *(DWORD *)(This + 4 * k + 24) == i )
						{
							CRenderNumberEx(v5 + Return2X(TransForX(Width)), v4 + ReturnY(TransForY(Height- 5)), k, 1.00, 31337);
							break;
						}
					}
				}
			}
		}
		this->SkillRavenSwitchBar((DWORD *)This);
	}
	else
	{
		OpenSwicthSkill = 0;
	}

	if(OpenSwicthSkill == 1)
	{
		RenderBitmap(61547, xInterface + TransForX( 323 ), yInterface + TransForY( 17 ), TransForX( 17 ), TransForY( 42 ), 0.0, 0.0, 0.2399999946, 1.0, 0, 0, 0);
		
		if(v11 > 20)
		{	
			if(pCursorX > 485 && pCursorX < 497 && pCursorY > 339 && pCursorY < 351 )
			{
				pSetCursorFocus = true;
			}
			//-- Boton Arriba
			if(CheckButtonPressed(Return2X(xInterface + TransForX( 325 )), ReturnY(yInterface + TransForY( 19 )), Return2X(TransForX( 13 )), ReturnY(TransForY( 13 ))))
			{
				gInterface.OpenConfig(1);
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 19 ), TransForX( 13 ), TransForY( 13 ), 0.3870000243, 0.4429999888, 0.1380000114, 0.2490001172, 0, 0, 0);
				PlayBuffer(25, 0, 0);
			}
			else
			{
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 19 ), TransForX( 13 ), TransForY( 13 ), 0.3870000243, 0.7100000381, 0.1380000114, 0.2490001172, 0, 0, 0);
			}

			if(pCursorX > 485 && pCursorX < 497 && pCursorY > 363 && pCursorY < 375 )
			{
				pSetCursorFocus = true;
			}
			//-- Boton Abajo
			if(CheckButtonPressed(Return2X(xInterface + TransForX( 325 )), ReturnY(yInterface + TransForY( 43 )), Return2X(TransForX( 13 )), ReturnY(TransForY( 13 ))))
			{
				gInterface.OpenConfig(2);
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 43 ), TransForX( 13 ), TransForY( 13 ), 0.2470000237, 0.4429999888, 0.1380000114, 0.2490001172, 0, 0, 0);
				PlayBuffer(25, 0, 0);
			}
			else
			{	
				RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 43 ), TransForX( 13 ), TransForY( 13 ), 0.2470000237, 0.7100000381, 0.1380000114, 0.2490001172, 0, 0, 0);
			}
		}
		else
		{
			//-- Arriba
			RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 19 ), TransForX( 13 ), TransForY( 13 ), 0.3870000243, 0.1729999632, 0.1380000114, 0.2490001172, 0, 0, 0);
			//-- Abajo
			RenderBitmap(61547, xInterface + TransForX( 325 ), yInterface + TransForY( 43 ), TransForX( 13 ), TransForY( 13 ), 0.2470000237, 0.1729999632, 0.1380000114, 0.2490001172, 0, 0, 0);
		}
	}

	if ( *(BYTE *)(This + 65) == 1 && *(DWORD *)(This + 16) )
	{
		Render_772EA0( This );
		*(BYTE *)(This + 65) = 0;
	}

	pGLSwitch();
	EnableAlphaTest(0);

	return 1;
}

__declspec(naked) void CEx700::SkillSelectBar()
{
	static DWORD This;
	static DWORD Addr_JMP = 0x00813968;

	_asm
	{
		MOV DWORD PTR SS:[EBP-0x34],ECX
		MOV EDX, DWORD PTR SS:[EBP-0x34]
		MOV This, EDX
	}

	sub_813740(This);
	
	_asm
	{
		JMP[Addr_JMP]
	}
}

void PrintAdvanceStatus(int x, int y)
{
	int v5; // al@1
	int v6; // al@1
	int Width; // al@1
	char v10[50]; // ST08_4@6
	
	v6 = 11;
	Width = 115;
	gInterface.DrawFormat(eShinyGreen, x + 8, 56, 170, 1, "ADVANCED STATUS");

	pSetFont(pTextThis(), (int)pFontBold);
	sub_4200F0_Addr(pTextThis(), 0);
	//-- Lado Izquierdo
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	v5 = y + 80; //-- 1
	SetPrintf("· Total Dmg Reflect", x, v5, Width, 1);
	v5+= v6; //-- 2
	SetPrintf("· Full Dmg Reflect Rate", x, v5, Width, 1);
	v5+= v6; //-- 3
	SetPrintf("· Crit Dmg Rate", x, v5, Width, 1);
	v5+= v6; //-- 4
	SetPrintf("· Crit Dmg (PVM)", x, v5, Width, 1);
	v5+= v6; //-- 5
	SetPrintf("· Crit Dmg (PVP)", x, v5, Width, 1);
	v5+= v6; //-- 6
	SetPrintf("· Exellent Dmg Rate", x, v5, Width, 1);
	v5+= v6; //-- 7
	pDrawText(pTextThis(), x, v5, "· Exellent Dmg (PVM)", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 8
	pDrawText(pTextThis(), x, v5, "· Exellent Dmg (PVP)", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 9
	pDrawText(pTextThis(), x, v5, "· Double Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 10
	pDrawText(pTextThis(), x, v5, "· Triple Dmg Rate:", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 11
	pDrawText(pTextThis(), x, v5, "· Dmg Reduction Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 12
	pDrawText(pTextThis(), x, v5, "· Shield Skill Dmg Redc Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 13
	pDrawText(pTextThis(), x, v5, "· SD Dmg Reduction Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 14
	pDrawText(pTextThis(), x, v5, "· SD Decrease Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 15
	pDrawText(pTextThis(), x, v5, "· Ignore Def Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 16
	pDrawText(pTextThis(), x, v5, "· Ignore SD Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 17
	pDrawText(pTextThis(), x, v5, "· Inc Dmg PvP", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 18
	pDrawText(pTextThis(), x, v5, "· Inc Def PvP", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 19
	pDrawText(pTextThis(), x, v5, "· Resist Double Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 20
	pDrawText(pTextThis(), x, v5, "· Resist Ignore Def Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 21
	pDrawText(pTextThis(), x, v5, "· Resist Ignore SD Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 22
	pDrawText(pTextThis(), x, v5, "· Resist Crit Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 23
	pDrawText(pTextThis(), x, v5, "· Resist Exellent Dmg Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 24
	pDrawText(pTextThis(), x, v5, "· Resist Stum Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 25
	pDrawText(pTextThis(), x, v5, "· Ice Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 26
	pDrawText(pTextThis(), x, v5, "· Poison Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 27
	pDrawText(pTextThis(), x, v5, "· Lighting Ince / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 28
	pDrawText(pTextThis(), x, v5, "· Fire Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	v5+= v6; //-- 29
	pDrawText(pTextThis(), x, v5, "· Earth Inc / Resist Rate", Width, 0, (LPINT)1, 0);
	/*v5+= v6; //-- 30
	pDrawText(pTextThis(), x, v5, "· Wind Inc / Resist Rate", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 31
	pDrawText(pTextThis(), x, v5, "· Water Inc / Resist Rate", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 32
	pDrawText(pTextThis(), x, v5, "· HP Restore Rate (Def, Att)", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 33
	pDrawText(pTextThis(), x, v5, "· MP Rest Rate (Def, Att)", 100, 0, (LPINT)1, 0);
	v5+= v6; //-- 34
	pDrawText(pTextThis(), x, v5, "· SD Rest Rate (Def, Att)", 100, 0, (LPINT)1, 0);*/
	
	//-- Lado Derecho
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	v5 = y + 80; //-- 1
	int xN = x + 120;
	RebuildInformationRate(g_StatsAdvance.m_Data.TotalDamageReflect, xN, v5);
	v5+= v6; //-- 2
	RebuildInformationRate(g_StatsAdvance.m_Data.FullDamageReflectRate, xN, v5);
	v5+= v6; //-- 3
	RebuildInformationRate(g_StatsAdvance.m_Data.CriticalDamageRate, xN, v5);
	v5+= v6; //-- 4
	RebuildInformation(g_StatsAdvance.m_Data.CriticalDamagePVM, xN, v5);
	v5+= v6; //-- 5
	RebuildInformation(g_StatsAdvance.m_Data.CriticalDamagePVP, xN, v5);
	v5+= v6; //-- 6
	RebuildInformationRate(g_StatsAdvance.m_Data.ExellentDamageRate, xN, v5);
	v5+= v6; //-- 7
	RebuildInformation(g_StatsAdvance.m_Data.ExellentDamagePVM, xN, v5);
	v5+= v6; //-- 8
	RebuildInformation(g_StatsAdvance.m_Data.ExellentDamagePVP, xN, v5);
	v5+= v6; //-- 9
	RebuildInformationRate(g_StatsAdvance.m_Data.DoubleDamageRate, xN, v5);
	v5+= v6; //-- 10
	RebuildInformationRate(g_StatsAdvance.m_Data.TripleDamageRate, xN, v5);
	v5+= v6; //-- 11
	RebuildInformationRate(g_StatsAdvance.m_Data.DamageReductionRate, xN, v5);
	v5+= v6; //-- 12
	RebuildInformationRate(g_StatsAdvance.m_Data.ShieldSkillDamageReductionRate, xN, v5);
	v5+= v6; //-- 13
	RebuildInformationRate(g_StatsAdvance.m_Data.SDDamageReductionRate, xN, v5);
	v5+= v6; //-- 14
	RebuildInformationRate(g_StatsAdvance.m_Data.SDDecreaseDamageRate, xN, v5);
	v5+= v6; //-- 15
	RebuildInformationRate(g_StatsAdvance.m_Data.IgnoreDefenceRate, xN, v5);
	v5+= v6; //-- 16
	RebuildInformationRate(g_StatsAdvance.m_Data.IgnoreSDRate, xN, v5);
	v5+= v6; //-- 17
	RebuildInformation(g_StatsAdvance.m_Data.IncreaseDamagePvP, xN, v5);
	v5+= v6; //-- 18
	RebuildInformation(g_StatsAdvance.m_Data.IncreaseDefencePvP, xN, v5);
	v5+= v6; //-- 19
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistDoubleDamageRate, xN, v5);
	v5+= v6; //-- 20
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistIgnoreDefenceRate, xN, v5);
	v5+= v6; //-- 21
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistIgnoreSDRate, xN, v5);
	v5+= v6; //-- 22
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistCriticalDamageRate, xN, v5);
	v5+= v6; //-- 23
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistExellentDamageRate, xN, v5);
	v5+= v6; //-- 24
	RebuildInformationRate(g_StatsAdvance.m_Data.ResistStumRate, xN, v5);
	v5+= v6; //-- 25
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseIce, g_StatsAdvance.m_Data.ResistIce, xN, v5);
	v5+= v6; //-- 26
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreasePoison, g_StatsAdvance.m_Data.ResistPoison, xN, v5);
	v5+= v6; //-- 27
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseLighting, g_StatsAdvance.m_Data.ResistLighting, xN, v5);
	v5+= v6; //-- 28
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseFire, g_StatsAdvance.m_Data.ResistFire, xN, v5);
	v5+= v6; //-- 29
	RebuildInformationRate(g_StatsAdvance.m_Data.IncreaseEarth, g_StatsAdvance.m_Data.ResistEarth, xN, v5);
	/*
	this->DrawLine(flDrawX, flDrawY, flWidth, "Wind Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseWind, this->m_Data.ResistWind);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Water Increase / Resist Rate:");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d - %d%%", this->m_Data.IncreaseWater, this->m_Data.ResistWater);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full HP Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullHPRestoreRateDef, this->m_Data.FullHPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full MP Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullMPRestoreRateDef, this->m_Data.FullMPRestoreRate);
	
	this->DrawLine(flDrawX, flDrawY, flWidth, "Full SD Restore Rate (Def, Att):");
	flDrawY = this->DrawLineR(flDrawX, flDrawY, flWidth, eGold, "%d%% - %d%%", this->m_Data.FullSDRestoreRateDef, this->m_Data.FullSDRestoreRate);*/
}

void CharacterInfoWindow(int a1)
{
	float y; // ST0C_4@1
	float RenderY; // ST0C_4@1
	float x; // ST08_4@1
	int This; // [sp+8Ch] [bp-10h]@1
	HGDIOBJ v4; // ST18_4@1
	int v5; // al@1
	char v10[256]; // ST08_4@6
	int v56; // [sp+8h] [bp-23Ch]@18
	int v65; // [sp+240h] [bp-4h]@16
	char v587; // [sp+3E2h] [bp-5D6h]@6
	int v602; // [sp+458h] [bp-560h]@6
	int v607; // [sp+56Ch] [bp-44Ch]@6
	int v614; // [sp+6A4h] [bp-314h]@6
	char v626; // [sp+82Fh] [bp-189h]@6
	int v639; // [sp+984h] [bp-34h]@46
	int v640; // [sp+988h] [bp-30h]@157
	char *v644; // [sp+998h] [bp-20h]@6
	int v650; // [sp+9B0h] [bp-8h]@6
	float v16; // ST34_4@1
	unsigned __int8 v17; // ST18_1@1
	unsigned __int8 v22; // ST18_1@1
	float v35; // [sp+338h] [bp-4h]@1
	
	This = getCharacterInfo((int)pWindowThis());
	
	*(signed int *)(This + 16) = 1;

	x = (double)*(signed int *)(This + 16);
	y = (double)*(signed int *)(This + 20);
	int widht;

	if(pCursorX > 411 && pCursorX < 425 && pCursorY > 206 && pCursorY < 215 )
	{
		pSetCursorFocus = true;
	}

	if(pCursorX > 211 && pCursorX < 220 && pCursorY > 206 && pCursorY < 215 )
	{
		pSetCursorFocus = true;
	}

	if( g_StatsAdvance.m_Enable )
	{	
		if( CheckButtonPressed(x + 410, y + 206, 15, 10) )
		{		
			g_StatsAdvance.m_Enable = false;
		}
	}
	else
	{
		if( CheckButtonPressed(x + 210, y + 206, 15, 10) )
		{
			g_StatsAdvance.m_Enable = true;
		}
	}

	if( g_StatsAdvance.m_Enable )
	{
		widht = 423;
		pDrawGUI(71538, x, y, 426.0f, 422.0f);
		PrintAdvanceStatus(x + 222, y);
	}
	else
	{
		widht = 213;
		pDrawGUI(71532, x, y, 225, 422.0);
	}

	pSetFont(pTextThis(), (int)pFontBold);
	sub_4200F0_Addr(pTextThis(), 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 45));
	pDrawText(pTextThis(), x + 15, y + 60, v10, 50, 0, (LPINT)3, 0);


	v16 = *(float*)0x5EF5A1C * 0.001000000047497451;
	v35 = Convert(v16) + 1.0;
	v17 = (signed int)((2.0 - v35) * 127.0);

	//-- TitleName 1
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, v17);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s", (const char *)(*(DWORD*)0x8128AC8));
	pDrawText(pTextThis(), x, y + 27, v10, widht, 0, (LPINT)3, 0);
	//-- TitleName 2
	v22 = (signed int)(v35 * 127.0);
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, v22);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10,  pGetTextLine(pTextLineThis, 126));
	pDrawText(pTextThis(), x, y + 27, v10, widht, 0, (LPINT)3, 0);

	//-- Button Pet
	sub_779410((char *)(This + 1228), x + 85, y + 53, 43, 17);
	if( CheckButtonPressed(x + 85, y + 53, 43, 17) || pCheckWindow(pWindowThis(), PetInfo))
	{
		RenderBitmap(71535, x + 85, y + 53, 43, 17, 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, x + 85, y + 53, 43, 17, 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}//-- over 0.4460069239
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1217));// Pet
	pDrawText(pTextThis(), x + 85, y + 56, v10, 43, 0, (LPINT)3, 0);

	//-- Button MasterSkill
	sub_779410((char *)(This + 1400), x + 135, y + 53, 43, 17);
	if( CheckButtonPressed(x + 135, y + 53, 43, 17) )
	{
		RenderBitmap(71535, x + 135, y + 53, 43, 17, 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, x + 135, y + 53, 43, 17, 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}//-- Click 0.2235384732
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1300));
	pDrawText(pTextThis(), x + 135, y + 56, v10, 43, 0, (LPINT)3, 0);

	//-- Class
	RenderY = y + 80;
	v5 = sub_587620(*(BYTE *)(*(DWORD*)0x8128AC8 + 11));
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1973));
	pDrawText(pTextThis(), x + 20, RenderY, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s", (const char *) v5);
	pDrawText(pTextThis(), x + 100, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Reset
	RenderY += 11;
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pDrawText(pTextThis(), x + 20, RenderY, "Reset", 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d", ViewReset);
	pDrawText(pTextThis(), x + 100, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Level
	RenderY += 11;
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 368));
	pDrawText(pTextThis(), x + 20, RenderY, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	//wsprintf(v10, "%d", *(WORD *)(*(DWORD*)0x8128AC8 + 14) + pMasterLevel);
	wsprintf(v10, "%d", *(WORD *)(*(DWORD*)0x8128AC8 + 14));
	pDrawText(pTextThis(), x + 100, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Server Name
	RenderY += 11;
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1022));
	pDrawText(pTextThis(), x + 20, RenderY, v10, 90, 0, (LPINT)1, 0);

	//-- Divisor
	pSetBlend(1);
	RenderBitmap(71520, x + 8, y + 127, 195, 1, 0, 0, 0.7600000501, 1.0, 1, 1, 0);
	glEnable(0xDE1u);
	pGLSwitch();

	//-- Point Stats
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 682));
	pDrawText(pTextThis(), x + 20, y + 132, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d", ViewPoint);
	pDrawText(pTextThis(), x + 100, y + 132, v10, 90, 0, (LPINT)1, 0);
	//-- Fruit Create
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s %s", pGetTextLine(pTextLineThis, 1901), pGetTextLine(pTextLineThis, 1412));
	pDrawText(pTextThis(), x + 20, y + 143, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d/%d", *(WORD *)(*(DWORD*)0x8128AC8 + 76), *(WORD *)(*(DWORD*)0x8128AC8 + 78));
	pDrawText(pTextThis(), x + 100, y + 143, v10, 90, 0, (LPINT)1, 0);

	if ( (signed int)*(WORD *)(*(DWORD*)0x8128AC8 + 76) > 10 )
	{
		v56 = 0;
		if ( *(WORD *)(*(DWORD*)0x8128AC8 + 78) )
			v56 = 100 * *(WORD *)(*(DWORD*)0x8128AC8 + 76) / *(WORD *)(*(DWORD*)0x8128AC8 + 78);
		if ( v56 > 10 )
		{
			if ( v56 <= 10 || v56 > 30 )
			{
				if ( v56 <= 30 || v56 > 50 )
				{
					if ( v56 > 50 )
					v65 = 40;
				}
				else
				{
					v65 = 50;
				}
			}
			else
			{
				v65 = 60;
			}
		}
		else
		{
			v65 = 70;
		}
	}
	else
	{
		v65 = 100;
	}
	pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "(%d%%)", v65);
	pDrawText(pTextThis(), x + 157, y + 143, v10, 35, 0, (LPINT)4, 0);
	//-- Fruis Decrease
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%s %s", pGetTextLine(pTextLineThis, 1901), pGetTextLine(pTextLineThis, 1903));
	pDrawText(pTextThis(), x + 20, y + 154, v10, 90, 0, (LPINT)1, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "%d/%d", *(WORD *)(*(DWORD*)0x8128AC8 + 80), *(WORD *)(*(DWORD*)0x8128AC8 + 82));
	pDrawText(pTextThis(), x + 100, y + 154, v10, 90, 0, (LPINT)1, 0);
	
	if ( (signed int)*(WORD *)(*(DWORD*)0x8128AC8 + 80) > 10 )
	{
		v56 = 0;
		if ( *(WORD *)(*(DWORD*)0x8128AC8 + 82) )
			v56 = 100 * *(WORD *)(*(DWORD*)0x8128AC8 + 80) / *(WORD *)(*(DWORD*)0x8128AC8 + 82);
		if ( v56 > 10 )
		{
			if ( v56 <= 10 || v56 > 30 )
			{
				if ( v56 <= 30 || v56 > 50 )
				{
					if ( v56 > 50 )
					v65 = 40;
				}
				else
				{
					v65 = 50;
				}
			}
			else
			{
				v65 = 60;
			}
		}
		else
		{
			v65 = 70;
		}
	}
	else
	{
		v65 = 100;
	}
	pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, "(%d%%)", v65);
	pDrawText(pTextThis(), x + 157, y + 154, v10, 35, 0, (LPINT)4, 0);

	v639 = pGetCharClass(*(BYTE *)(*(DWORD*)0x7BC4F04 + 19));
	v640 =  x + 90;
int v6400 = x + 23;
//-- STR
	RenedrBarFormat(v6400, y + 185 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 24), v640, y + 185, 10, 10);
	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 185, 10, 10) )
		{
			RenderBitmap(71533, v640, y + 185, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71533, v640, y + 185, 10, 10, 0, 0.0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- AGI
	RenedrBarFormat(v6400, y + 230 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 196), v640, y + 230, 10, 10);
	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 230, 10, 10) )
		{
			RenderBitmap(71533, v640, y + 230, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71533, v640, y + 230, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- Tercer TomO VIT
	RenedrBarFormat(v6400, y + 290 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 368), v640, y + 290, 10, 10);
	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 290, 10, 10) )
		{
			RenderBitmap(71533, v640, y + 290, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71533, v640, y + 290, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- CUARTO TomO ENE
	RenedrBarFormat(v6400, y + 335 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
	//-- Botton Subir Punto
	sub_779410((char *)(This + 540), v640, y + 335, 10, 10);

	if ( ViewPoint > 0 )
	{
		if( CheckButtonPressed( v640, y + 335, 10, 10) )
		{
			RenderBitmap(71533, v640, y + 335, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71533, v640, y + 335, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
		}
	}
//-- QUINTO TomO COMMAND
	if ( v639 == 4 )
	{
		RenedrBarFormat(v6400, y + 380 - 2, 154, 14, 0.1176f, 0.1176f, 0.1176f, 1.0);
		//-- Botton Subir Punto
		sub_779410((char *)(This + 712), v640, y + 380, 10, 10);
		if ( ViewPoint > 0 )
		{
			if( CheckButtonPressed( v640, y + 380, 10, 10) )
			{
				RenderBitmap(71533, v640, y + 380, 10, 10, 0, 0.2899999917, 0.555, 0.277, 1, 1, 0);
			}
			else
			{
				RenderBitmap(71533, v640, y + 380, 10, 10, 0, 0, 0.555, 0.277, 1, 1, 0);
			}
		}
	}
}

__declspec(naked) void InformationServer1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0077F8FF;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InformationServer2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0077FA51;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InformationServer3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0077FAD7;

	pSetTextColor(pTextThis(), 0xACu, 0xFFu, 0x38u, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 4
		PUSH 0
		PUSH 130
		LEA EDX,DWORD PTR SS:[EBP-0x108]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x31C]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX, 113
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x31C]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX, 62
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP[Addr_JMP]
	}
}


__declspec(naked) void InformationSTR1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00780210;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0xA6                                 ; /Arg1 = 000000A6
		MOV ECX,0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 185 //--Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 29 //--X
		PUSH ECX
		CALL Addr_Call
		MOV ECX, EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationSTR2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00780245;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 50) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 50) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 56
		LEA EDX,DWORD PTR SS:[EBP-0x334]
		PUSH EDX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 185 //--Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 105 //--X
		PUSH ECX
		CALL Addr_Call
		MOV ECX, EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationSTR3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0078178A;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x138]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,200 //--Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25 //--X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX 
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationSTR4()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00781833;

	_asm
	{
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x138]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 213
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00781947;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0x6A6                                 ; /Arg1 = 000006A6
		MOV ECX, 0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,230 //-- Y
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX,29 //-- X
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX  
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0078197E;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 51) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 52) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA ECX,DWORD PTR SS:[EBP-0x5D0]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 230 //-- Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 105 //-- X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782882;

	_asm
	{
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x290]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 246 //-- Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25
		PUSH EDX
		CALL Addr_Call //-- X
		MOV ECX,EAX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI4()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782A60;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x290]
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 259 //--Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25 //--X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX 
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationAGI5()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_Call2 = 0x00420150;
	static DWORD Addr_JMP = 0x00782BC5;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x290]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 272 //-- Y
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25 //-- X
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                          ; |
		CALL Addr_Call2                      ; \main1.00420150
		MOV EAX,DWORD PTR DS:[0xE8C58C]
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                          ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00782D4F;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0xA9                                 ; /Arg1 = 000000A9
		MOV ECX, 0x08128ADC                   ; |
		CALL Addr_STR                            ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 290 //-- Y
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX, 29 //-- X
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX    
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782D87;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 52) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 130)
			|| pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 155) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 54) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA EDX,DWORD PTR SS:[EBP-0x558]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX, 290 //-- Y
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX, 105 //-- X
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00782F99;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x558]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 305
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationVIT4()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x0078300F;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA EAX,DWORD PTR SS:[EBP-0x558]
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 318
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationENE1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00783129;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0xA8                                 ; /Arg1 = 000000A8
		MOV ECX,0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX, 335
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX, 29
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationENE2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00783160;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 53) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 56) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA ECX,DWORD PTR SS:[EBP-0x438]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,335
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 105
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationENE3()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00783305;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x438]
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX, 350
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX, 25
		PUSH EDX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoMagicDMG1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00784043;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,363
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25
		PUSH EDX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoMagicDMG2()
{
	static DWORD Addr_JMP = 0x00784847;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,376
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25
		PUSH EDX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG1()
{
	static DWORD Addr_JMP = 0x007848BF;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX, 363
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG2()
{
	static DWORD Addr_JMP = 0x0078491E;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,376
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG3()
{
	static DWORD Addr_JMP = 0x0078498D;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,363
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG4()
{
	static DWORD Addr_JMP = 0x007849FE;

	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,363
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InfoSkillDMG5()
{
	static DWORD Addr_JMP = 0x00784A7E;

	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,376
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECX+0x10]
		ADD EDX,25
		PUSH EDX
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationCMD1()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_STR = 0x00402320;
	static DWORD Addr_JMP = 0x00784BA7;

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x4A
		PUSH 0x76C                                 ; /Arg1 = 0000076C
		MOV ECX, 0x08128ADC                   ; |
		CALL Addr_STR                      ; \main1.00402320
		PUSH EAX
		MOV ECX,DWORD PTR SS:[EBP-0x8A8]
		MOV EDX,DWORD PTR DS:[ECx+0X14]
		ADD EDX,380
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x10]
		ADD ECX,25
		PUSH ECX
		CALL Addr_Call
		MOV ECX,EAX                              ; |
		JMP [Addr_JMP]
	}
}

__declspec(naked) void InformationCMD2()
{
	static DWORD Addr_Call = 0x0041FE10;
	static DWORD Addr_JMP = 0x00784BDF;

	if ( pCheckEffectPlayer((DWORD *)(*(DWORD*)0x7BC4F04 + 1260), 54) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0x78u, 0, 0xFFu);
	}
	else if ( *(WORD *)(*(DWORD*)0x8128AC8 + 62) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x96u, 0xFFu, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xE6u, 0xE6u, 0, 0xFFu);
	}

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0x56
		LEA EDX,DWORD PTR SS:[EBP-0x8A0]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x8A8]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,380
		PUSH ECX
		MOV EDX,DWORD PTR SS:[EBP-0x8A8]
		MOV EAX,DWORD PTR DS:[EDX+0x10]
		ADD EAX,105
		PUSH EAX
		CALL Addr_Call
		MOV ECX,EAX                              ; 
		JMP [Addr_JMP]
	}
}

void LoadWindows(DWORD id, float x, float y, float w, float h)
{
	x = TransFor2X( x );
	w = TransFor2X( w );
	y = TransForY( y );
	h = TransForY( h );
	
	RenderBitmap(71526, x, y, w, h, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
}

void LoadWindowsNone(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(51522, x, y, w, h);
}

__declspec (naked) void RemoveButtonStore1()  //-- ok
{
	static DWORD Addrs = 0x0083BB67;
	
	_asm
	{
		JMP [Addrs]
	}
}

__declspec (naked) void RemoveButtonStore2()  //-- ok
{
	static DWORD Addrs = 0x0083BC07;
	
	_asm
	{
		JMP [Addrs]
	}
}

bool CheckMouseAncestral(int x, int y, int w, int h) //-- ataque automatico
{
	int This; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	x = TransFor2X((double)*(signed int *)(This + 36));
	y = TransForY((double)*(signed int *)(This + 40));

	return pCheckMouseOver(Return2X(x + TransForX(18)), ReturnY(TransForY(198)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
}

bool CheckMouseSocket(int x, int y, int w, int h) 
{
	int This; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	x = TransFor2X((double)*(signed int *)(This + 36));
	y = TransForY((double)*(signed int *)(This + 40));

	return pCheckMouseOver( Return2X(x + TransForX(18)), ReturnY(y + TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
}

__declspec(naked) void RemoveTextAncestral()
{
	static DWORD Addr_JMP = 0x0083524C;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RemoveTextSocket()
{
	static DWORD Addr_JMP = 0x00835364;

	_asm
	{
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InfoTooltipAncestral()
{
	static DWORD Addr_JMP = 0x00835C92;
	static DWORD This; // [sp+74h] [bp-4h]@1
	static DWORD RenderY; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	RenderY = *(signed int *)(This + 40) + 175;

	_asm
	{
		PUSH RenderY
		JMP[Addr_JMP]
	}
}

__declspec(naked) void InfoTooltipSocket()
{
	static DWORD Addr_JMP = 0x00835CBD;
	static DWORD This; // [sp+74h] [bp-4h]@1
	static DWORD RenderY; // [sp+74h] [bp-4h]@1

	This = GetInventory(GetInstance());

	RenderY = *(signed int *)(This + 40) + 195;

	_asm
	{
		PUSH RenderY
		JMP[Addr_JMP]
	}
}

void RenderInvExtSlot(DWORD id, float x, float y, float w, float h)
{
	pSetBlend(1);
	glColor4f(0.0, 0.0, 0.0, 0.55000002);
	pDrawBarForm(x, y, Return2X(TransForX(w)), h, 0.0, 0);
	glEnable(0xDE1u);
	pGLSwitch();
	pSetBlend(0);
	glColor4f(1.0, 1.0, 1.0, 1.0);
}

void WindowsInfoInventory(int a1)
{
//-- NPC RUUD
//=============================
//	jCRenderRuud.OpenRuud();
//=============================
	float x; // ST08_4@1
	float y; // ST04_4@1
	int This; // ST24_4@1
	char v10[255]; // ST24_4@1
	unsigned int v23; // [sp+128h] [bp-4h]@1
	char v22[260]; // [sp+24h] [bp-108h]@1
	int v15; // ST18_4@1
	int v639; // ST18_4@1

	This = GetInventory(GetInstance());
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	if ( pCheckWindow(pWindowThis(), Character) )
	{
		*(signed int *)(This + 36) = Return2X(TransFor2X(640) - Width);
	}
	else
	{
		*(signed int *)(This + 36) = Return2X(TransFor2X(640) - Width);
	}
	x = TransFor2X((double)*(signed int *)(This + 36));
	y = TransForY((double)*(signed int *)(This + 40));

	//--
	int ModelId = 71522;

	v639 = pGetCharClass(*(BYTE *)(*(DWORD*)0x7BC4F04 + 19));

	if ( v639 == 6 )
	{
		ModelId = 71524;
	}
	else if ( v639 == 3 )
	{
		ModelId = 71523;
	}

	RenderBitmap(ModelId, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 223));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v10, Return2X(Width), 0, (LPINT)3, 0);
	//-- Cerrar
	ChangeButtonInfo((char *)(This + 460), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	if( CheckButtonPressed(Return2X(x + TransForX(158)), Return2X(y + TransForX(28)), Return2X(TransForX(11)), Return2X(TransForX(11))) )
	{
		RenderBitmap(71529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	else
	{
		RenderBitmap(71529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	//-- pet
	*(DWORD *)(This + 204) = Return2X(x + TransForX(19)); //-- X
	*(DWORD *)(This + 208) = ReturnY(y + TransForY(56));//-- Y
	*(DWORD *)(This + 212) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 216) = ReturnY(TransForY(40)); //-- H
	*(DWORD *)(This + 220) = 51522;//-- Texture
	//-- weapon(L)
	*(DWORD *)(This + 44) = Return2X(x + TransForX(19)); //-- X
	*(DWORD *)(This + 48) = ReturnY(y + TransForY(97)); //-- Y
	*(DWORD *)(This + 52) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 56) = ReturnY(TransForY(56)); //-- H
	*(DWORD *)(This + 60) = 51522;
	//-- Gloves
	*(DWORD *)(This + 144) = Return2X(x + TransForX(19)); //-- X
	*(DWORD *)(This + 148) = ReturnY(y + TransForY(154));
	*(DWORD *)(This + 152) = Return2X(TransForX(35));
	*(DWORD *)(This + 156) = ReturnY(TransForY(40));
	*(DWORD *)(This + 160) = 51522;
	//-- helm
	*(DWORD *)(This + 84) = Return2X(x + TransForX(79));
	*(DWORD *)(This + 88) = ReturnY(y + TransForY(56));
	*(DWORD *)(This + 92) = Return2X(TransForX(35));
	*(DWORD *)(This + 96) = ReturnY(TransForY(40));
	*(DWORD *)(This + 100) = 51522;
	//-- Armor
	*(DWORD *)(This + 104) = Return2X(x + TransForX(79));
	*(DWORD *)(This + 108) = ReturnY(y + TransForY(97)); //-- Y
	*(DWORD *)(This + 112) = Return2X(TransForX(35));
	*(DWORD *)(This + 116) = ReturnY(TransForY(56)); //-- H
	*(DWORD *)(This + 120) = 51522;
	//-- Pants
	*(DWORD *)(This + 124) = Return2X(x + TransForX(79));
	*(DWORD *)(This + 128) = ReturnY(y + TransForY(154));
	*(DWORD *)(This + 132) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 136) = ReturnY(TransForY(40)); //-- H
	*(DWORD *)(This + 140) = 51522;
	//-- wings
	*(DWORD *)(This + 184) = Return2X(x + TransForX(117));
	*(DWORD *)(This + 188) = ReturnY(y + TransForY(56));
	*(DWORD *)(This + 192) = Return2X(TransForX(56)); //-- W;
	*(DWORD *)(This + 196) = ReturnY(TransForY(40)); //-- H;
	*(DWORD *)(This + 200) = 51522;
	//-- weapon(R)
	*(DWORD *)(This + 64) = Return2X(x + TransForX(139));
	*(DWORD *)(This + 68) = ReturnY(y + TransForY(97));
	*(DWORD *)(This + 72) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 76) = ReturnY(TransForY(56)); //-- H
	*(DWORD *)(This + 80) = 51522;
	//-- Bootas
	*(DWORD *)(This + 164) = Return2X(x + TransForX(139));
	*(DWORD *)(This + 168) = ReturnY(TransForY(154)); //-- Y
	*(DWORD *)(This + 172) = Return2X(TransForX(35)); //-- W
	*(DWORD *)(This + 176) = ReturnY(TransForY(40)); //-- H
	*(DWORD *)(This + 180) = 51522;
	//-- pendiente
	*(DWORD *)(This + 224) = Return2X(x + TransForX(55));
	*(DWORD *)(This + 228) = ReturnY(TransForY(67)); //-- Y
	*(DWORD *)(This + 232) = Return2X(TransForX(24)); //-- W
	*(DWORD *)(This + 236) = ReturnY(TransForY(24)); //-- H
	*(DWORD *)(This + 240) = 51522;
	// anillo 1
	*(DWORD *)(This + 244) = Return2X(x + TransForX(55));
	*(DWORD *)(This + 248) = ReturnY(TransForY(165)); //-- Y
	*(DWORD *)(This + 252) = Return2X(TransForX(24)); //-- W
	*(DWORD *)(This + 256) = ReturnY(TransForY(24)); //-- H
	*(DWORD *)(This + 260) = 51522;
	//-- anillo 2
	*(DWORD *)(This + 264) = Return2X(x + TransForX(116));
	*(DWORD *)(This + 268) = ReturnY(TransForY(165)); //-- Y
	*(DWORD *)(This + 272) = Return2X(TransForX(24)); //-- W
	*(DWORD *)(This + 276) = ReturnY(TransForY(24)); //-- H
	*(DWORD *)(This + 280) = 51522;
	//-- Pentagrama
//	gPostInterface.DrawItemIMG(Return2X(x + TransForX(135)), ReturnY(TransForY(164)), Return2X(TransForX(35)), ReturnY(TransForY(40)), ITEM(14, 173), 0, 0, 0, 0);
	//--
	int MainSlot = *(DWORD *)(This + 24);
	//-- Inventory
	*(DWORD *)(MainSlot + 44) = 243;
	int t = *(DWORD *)(MainSlot + 56) * RetangleInventory( 17 );
	*(DWORD *)(MainSlot + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	
	if((signed int)(unsigned __int8)SetOption1((int) pUserStat()) <= 0 
		&& (signed int)(unsigned __int8)SetOption2((int) pUserStat()) <= 0 )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
		RenderBitmap(71535, Return2X(x + TransForX(18)), ReturnY(TransForY(194)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		RenderBitmap(71535, Return2X(x + TransForX(18)), ReturnY(TransForY(194)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 385)); //-- Ancestral
	pDrawText(pTextThis(), Return2X(x + TransForX(18)), ReturnY(y + TransForY(198)), v10, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	
	//-- socket
	if ( !sub_969000((void *)0x986C1B8) )
	{
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
		RenderBitmap(71535, Return2X(x + TransForX(18)), ReturnY(y + TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		RenderBitmap(71535, Return2X(x + TransForX(18)), ReturnY(y + TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 2650)); //-- Socket
	pDrawText(pTextThis(), Return2X(x + TransForX(18)), ReturnY(y + TransForY(218)), v10, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	
	//-- Repair
	ChangeButtonInfo((char *)(This + 288), Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( *(WORD *)(*(DWORD*)0x8128AC8 + 14) >= 50 && !pCheckWindow(pWindowThis(), Warehouse) )
	{
		if( CheckButtonPressed(Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
		{
			RenderBitmap(71535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			if( CheckRepairInv(This) == 1 )
			{
				RenderBitmap(71535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
			else
			{
				RenderBitmap(71535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
			}
		}
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	}//-- over 0.4460069239
	else
	{
		RenderBitmap(71535, Return2X(x + TransForX(65)), ReturnY(TransForY(215)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.6706154196, 0.5035384717, 0.2215384692, 1, 1, 0);
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1559));//
	pDrawText(pTextThis(), Return2X(x + TransForX(65)), ReturnY(TransForY(218)), v10, Return2X(TransForX(43)), 0, (LPINT)3, 0);

	//-- store
	ChangeButtonInfo((char *)(This + 632), Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( pCheckWindow(pWindowThis(), Trade)
		|| pCheckWindow(pWindowThis(), Warehouse)
		|| pCheckWindow(pWindowThis(), ChaosBox)
		|| pCheckWindow(pWindowThis(), Shop)
		|| pCheckWindow(pWindowThis(), OtherStore) )
	{
		RenderBitmap(71535, Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.6706154196, 0.5035384717, 0.2215384692, 1, 1, 0);
		pSetTextColor(pTextThis(), 0x64u, 0x64u, 0x64u, 0xFFu);
	}
	else
	{
		if( CheckButtonPressed(Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) || pCheckWindow(pWindowThis(), Store) )
		{
			RenderBitmap(71535, Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71535, Return2X(x + TransForX(90)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}//-- over 0.4460069239
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	}
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 1640));
	pDrawText(pTextThis(), Return2X(x + TransForX(90)), ReturnY(TransForY(390)), v10, Return2X(TransForX(43)), 0, (LPINT)3, 0);

	//-- Inv Ext
	ChangeButtonInfo((char *)(This + 804), Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

	if( CheckButtonPressed(Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) || pCheckWindow(pWindowThis(), ExpandInventory) )
	{
		RenderBitmap(71535, Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, Return2X(x + TransForX(135)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}//-- over 0.4460069239
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 875));
	pDrawText(pTextThis(), Return2X(x + TransForX(135)), ReturnY(TransForY(390)), v10, Return2X(TransForX(43)), 0, (LPINT)3, 0);

	//-- Zen
	//pDrawGUI(81528, Return2X(x + TransForX(10)), ReturnY(TransForY(389)), ReturnY(TransForY(59)), Return2X(TransForX(21)));
	v23 = *(DWORD*)(*(DWORD*)0x8128AC4 + 5956);
	ZeroMemory(v22, sizeof(v22));
	pGetMoneyFormat(v23, v22, 0);
	v15 = ColorMoney(v23);
	SetTextColorByHDC(pTextThis(), v15);
	pDrawText(pTextThis(), Return2X(x + TransForX(23)), ReturnY(TransForY(393)), v22, Return2X(TransForX(60)), 0, (LPINT)4, 0);

/*	//-- Ruud Coin
	ZeroMemory(v22, sizeof(v22));
	pGetMoneyFormat(Coin1, v22, 0);
	v15 = ColorMoney(Coin1);
	SetTextColorByHDC(pTextThis(), v15);
	pDrawText(pTextThis(), Return2X(x + TransForX(27)), ReturnY(TransForY(399)), v22, Return2X(TransForX(60)), 0, (LPINT)4, 0);
*/}


void WindowsInfoInventoryExt(int a1)
{
	float x; // ST08_4@1
	float y; // ST04_4@1
	int This; // ST24_4@1
	char v10[255]; // ST24_4@1
	float v7; // ST08_4@3
	float v8; // ST04_4@3
	signed int v13; // [sp+4h] [bp-Ch]@1
	signed int result; // eax@1
	int Inventory; // [sp+0h] [bp-10h]@1

	This = GetInventoryExt(GetInstance());
	//*(signed int *)(This + 24) = 151;
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	if( pCheckWindow(pWindowThis(), Character) )
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}
	else
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));
	

	RenderBitmap(71526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 3323));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v10, Return2X(Width), 0, (LPINT)3, 0);
	//-- Cerrar
	pDrawPuntero(This + 52, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 52), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	
	if( CheckButtonPressed(Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11))) )
	{
		RenderBitmap(71529, Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)), 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71529, Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 1, 1, 0);
	}

	Inventory = GetInventory(GetInstance());
	v13 = 1;
	int t;

	for( result = sub_83CBE0(Inventory); v13 < result; result = sub_83CBE0(Inventory) )
	{
		*(DWORD *)((*((DWORD *)Inventory + v13 + 6)) + 44) = ReturnY(y + TransForY(60 + ( (v13-1) * 105)));

		t = *(DWORD *)((*((DWORD *)Inventory + v13 + 6)) + 56) * RetangleInventory( 17 );

		*(DWORD *)((*((DWORD *)Inventory + v13 + 6)) + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
		v13++;
	}

	for ( int i = 0; i < 2; ++i )
	{
		*(DWORD *)(This + 8 * i + 32) = ReturnY(y + TransForY(60 + ( i * 105 ))); //-- Y
		*(DWORD *)(This + 8 * i + 28) = Return2X(x + TransForX( 17 )); //-- X
	}
}

DWORD main; // [sp+78h] [bp-B0h]@1

void ItemSlotDurability(float x, float y, float w, float h, float Arg5, int Arg6)
{
	float v5; // ST04_4@23
	float v6; // ST00_4@23
	int j; // [sp+120h] [bp-8h]@3
	int i; // [sp+124h] [bp-4h]@1

	i = (y - *(DWORD *)(main + 44)) / 20;
	j = (x - *(DWORD *)(main + 40)) / 20;

	v5 = (double)(17 * i + *(DWORD *)(main + 44)); //-- Y
	v6 = (double)(RetangleInventory( 17 ) * j + *(DWORD *)(main + 40)); //-- X

	pDrawBarForm(v6, v5, RetangleInventory( 17 ), 17, Arg5, Arg6);
}

void ItemSlotEmpty(DWORD id, float x, float y, float w, float h)
{
	float v5; // ST04_4@23
	float v6; // ST00_4@23
	int j; // [sp+120h] [bp-8h]@3
	int i; // [sp+124h] [bp-4h]@1

	i = (y - *(DWORD *)(main + 44)) / 20;
	j = (x - *(DWORD *)(main + 40)) / 20;

	v5 = (double)(17 * i + *(DWORD *)(main + 44));//-- y
	v6 = (double)(RetangleInventory( 17 ) * j + *(DWORD *)(main + 40));//-- x

	id = (id == 31339) ? 71527 : id;

	pDrawGUI(id, v6, v5, RetangleInventory( 17 ), 17);
}

DWORD xMouser;

void UpdatexMouse()
{
	xMouser = RetangleInventory( 17 );
}

__declspec (naked) void RenderMouseRECT()
{
	static DWORD main_Addr = 0x007DC4F1;
	static DWORD renderx;
	static DWORD rendery;

	UpdatexMouse();

	renderx = ( xMouser != 0 ) ? xMouser : 0;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0x8]
		SUB EAX,DWORD PTR SS:[EBP-0x10]
		CDQ
		MOV ECX, renderx
		IDIV ECX
		MOV EDX,DWORD PTR SS:[EBP+0x10]
		MOV DWORD PTR DS:[EDX],EAX
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		SUB EAX,DWORD PTR SS:[EBP-0xC]
		CDQ
		MOV ECX, 17
		IDIV ECX
		MOV EDX,DWORD PTR SS:[EBP+0x14]
		MOV DWORD PTR DS:[EDX],EAX
		MOV AL,1
		JMP [main_Addr]
	}
}

DWORD ObjectModelInfo; // [sp+50h] [bp-18h]@3
DWORD ObjectModelTRS; // [sp+5Ch] [bp-Ch]@3
DWORD vMain; // [sp+34h] [bp-34h]@1

__declspec (naked) void GetInfoModelSlot()
{
	static DWORD main_Addr = 0x007DD50A;

	_asm
	{
		MOV ECX,DWORD PTR DS:[EAX]
		MOV DWORD PTR SS:[EBP-0x18],ECX
		MOV EDX,DWORD PTR SS:[EBP-0x18]
		MOV ObjectModelInfo, EDX
		MOVSX EAX,WORD PTR DS:[EDX]
		IMUL EAX,EAX,0x54
		ADD EAX,DWORD PTR DS:[0x8128AC0]
		MOV DWORD PTR SS:[EBP-0xC],EAX
		MOV ObjectModelTRS, EAX
		MOV EAX, DWORD PTR SS:[EBP-0x34]
		MOV vMain, EAX
		JMP [main_Addr]
	}
}

__declspec (naked) void RenderRect()
{
	static DWORD main_Addr = 0x007DB23F;

	_asm
	{
		MOV DWORD PTR SS:[EBP-0xB0],ECX
		MOV ECX, DWORD PTR SS:[EBP-0xB0]
		MOV main, ECX
	}

	*(DWORD *)(main + 48) = *(DWORD *)(main + 56) * RetangleInventory( 17 ); // W
	*(DWORD *)(main + 52) = (int)*(DWORD *)(main + 60) * 17; // H
	
	*(float *)(main + 88) = 0.32f;
	*(float *)(main + 92) = 0.201;
	*(float *)(main + 96) = 0.5f;

	_asm
	{
		JMP [main_Addr]
	}
}

void ObjectModelScaleSlot(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, float Anc, bool OnMouse) // code hien thi item
{
	if( vMain )
	{
		x = (double)(RetangleInventory( 17 ) * *(BYTE *)(ObjectModelInfo + 67) + *(DWORD *)(vMain + 40));
		y = (double)(17 * *(BYTE *)(ObjectModelInfo + 68) + *(DWORD *)(vMain + 44));

		Width = (double)(RetangleInventory( 17 ) * *(BYTE *)(ObjectModelTRS + 38));
		Height = (double)(17 * *(BYTE *)(ObjectModelTRS + 39));
	}

	pDrawItemModel(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
}

void WindowsChaosBox(int index, float x, float y, float w, float h)
{
	int This; // [sp+84h] [bp-25Ch]@1
	int v6; // eax@1
	char v7[256]; // al@4
	int Color; // ST18_4@2
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );
	This = GetChaosBox(GetInstance());

	if( pCheckWindow(pWindowThis(), 77) )
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 3));
	}
	else
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));

	RenderBitmap(71526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	if ( *(DWORD *)(This + 16) )
	{
		int MainSlot = *(DWORD *)(This + 16);
		//-- Inventory
		//*(DWORD *)(MainSlot + 44) = ReturnY(TransForY(242));
		int t = *(DWORD *)(MainSlot + 56) * RetangleInventory( 17 );
		*(DWORD *)(MainSlot + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	}

	//This + 276
	pDrawPuntero(This + 28, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 28), Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

	if( CheckButtonPressed(Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
	{
		RenderBitmap(71542, Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71542, Return2X(x + TransForX(74)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
	}
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 591)); //-- Combining
	pDrawText(pTextThis(), Return2X(x + TransForX(74)), ReturnY(TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
}

void WindowsInfoWareHouse(int a1)
{
	int This; // ST2C_4@1
	float y; // ST08_4@1
	float x; // ST04_4@1
	char v7[256]; // al@1
	int Color; // [sp+24h] [bp-88h]@1
	int Zen; // [sp+A8h] [bp-4h]@4
	signed __int64 v23; // ST28_8@4
	signed int v29; // [sp+10h] [bp-9Ch]@8
	int v30; // [sp+14h] [bp-98h]@5
	int v33; // [sp+A8h] [bp-4h]@4
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	pSetCursorFocus = true;
	
	This = GetUIBaul(GetInstance());
	
	*(signed int *)(This + 16) = 1;

	x = TransFor2X((double)*(signed int *)(This + 16));
	y = TransForY((double)*(signed int *)(This + 20));

	RenderBitmap(71539, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	if ( *(DWORD *)(This + 540) )
	{
		int t = ( 8 * 17 ) / 2;
		*(DWORD *)((*(DWORD *)(This + 540)) + 44) = 73;
		*(DWORD *)((*(DWORD *)(This + 540)) + 40) = x + Return2X(( Width / 2 ) - TransForX( t ));
	}

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	if ( *(BYTE *)(This + 548) )
	{
		pSetTextColor(pTextThis(), 0xF0u, 0x20u, 0x20u, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xD8u, 0xD8u, 0xD8u, 0xFFu);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, "%s (%s)",pGetTextLine(pTextLineThis, 234), pGetTextLine(pTextLineThis, (*(BYTE *)(This + 548) != 0) + 240)); //-- Socket
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0,(LPINT) 3, 0);
	//-- Zen
	Zen = *(DWORD *)(*(DWORD*)0x8128AC4 + 5960);
	pGetMoneyFormat(Zen, v7, 0);

	if(Zen > 0)
	{
		Color = ColorMoney(Zen);
	}
	SetTextColorByHDC(pTextThis(), Color);
	pDrawText(pTextThis(), Return2X(x + TransForX(158)), ReturnY(y + TransForY(353)), v7, 0, 0,(LPINT) 7, 0);
	//-- Storage Free
	pSetTextColor(pTextThis(), 0xF0u, 0x40u, 0x40u, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 224)); //-- Zen
	pDrawText(pTextThis(), Return2X(x + TransForX(35)), ReturnY(y + TransForY(353)), v7, 0, 0,(LPINT) 1, 0);
	
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 266)); //-- StorageFree
	pDrawText(pTextThis(), Return2X(x + TransForX(35)), ReturnY(y + TransForY(368)), v7, 0, 0,(LPINT) 1, 0);

	v23 = *(WORD *)0x87935D8 + *(WORD *)(*(DWORD *)0x8128AC8 + 14);
	v33 = (double)v23 * (double)v23 * 0.04;

	if ( *(BYTE *)(This + 548) )
		v30 = 2 * *(WORD *)(*(DWORD *)0x8128AC8 + 14);
	else
		v30 = 0;
	v33 += v30;
	if ( v33 >= 1 )
		v29 = v33;
	else
		v29 = 1;
	v33 = v29;
	if ( v29 < 1000 )
	{
		if ( v33 >= 100 )
			v33 = 10 * (v33 / 10);
	}
	else
	{
		v33 = 100 * (v33 / 100);
	}
	pGetMoneyFormat((double)v33, v7, 0);
	if(v33 > 0)
	{
		Color = ColorMoney(v33);
	}
	SetTextColorByHDC(pTextThis(), Color);
	pDrawText(pTextThis(), Return2X(x + TransForX(158)), ReturnY(y + TransForY(368)), v7, 0, 0,(LPINT) 7, 0);
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	for (int i = 0; i < 3; ++i )
	{
		pDrawPuntero(This + 172 * i + 24, 1, 51522, 0, 0, 0);
		ChangeButtonInfo((char *)(This + 172 * i + 24), Return2X(x + TransForX(10 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
		if( CheckButtonPressed(Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
		{
			RenderBitmap(71535, Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71535, Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, ( i == 0) ? 235 : ( i == 1) ? 236 : 451));
		pDrawText(pTextThis(), Return2X(x + TransForX(5 + (i * 45))), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0, (LPINT)3, 0);
	}
	//-- Expaned WareHouse
	pDrawPuntero(This + 572, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 572), Return2X(x + TransForX(140)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( CheckButtonPressed(x + 153, y + 387, 43, 17) )
	{
		RenderBitmap(71535, Return2X(x + TransForX(140)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, Return2X(x + TransForX(140)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 234));
	pDrawText(pTextThis(), Return2X(x + TransForX(140)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0, (LPINT)3, 0);
}

void WindowsInfoWareHouseExt(int a1)
{
	int This; // ST24_4@1
	float x; // ST08_4@1
	float y; // ST04_4@1
	int v6; // eax@1
	char v7[256]; // al@4

	This = GetUIBaulExt(GetInstance());

	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	*(signed int *)(This + 16) = Return2X(TransForX( 190 ) );

	x = TransFor2X((double)*(signed int *)(This + 16));
	y = TransForY((double)*(signed int *)(This + 20));

	RenderBitmap(71540, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	v6 = GetUIBaul(GetInstance());

	if ( *(DWORD *)(v6 + 544) )
	{
		int t = ( 8 * 17 ) / 2;
		*(DWORD *)((*(DWORD *)(v6 + 544)) + 44) = 73;
		*(DWORD *)((*(DWORD *)(v6 + 544)) + 40) = Return2X(x + ( Width / 2 ) - TransForX( t ));
	}

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

	if ( *(BYTE *)(v6 + 548) )
	{
		pSetTextColor(pTextThis(), 0xF0u, 0x20u, 0x20u, 0xFFu);
	}
	else
	{
		pSetTextColor(pTextThis(), 0xD8u, 0xD8u, 0xD8u, 0xFFu);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, "%s (%s)",pGetTextLine(pTextLineThis, 3339), pGetTextLine(pTextLineThis, (*(BYTE *)(v6 + 548) != 0) + 240)); //-- Socket
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0, (LPINT)3, 0);

	//-- Cerrar
	pDrawPuntero(This + 24, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 24), x + 180, y + 28, 11, 11);
	if( CheckButtonPressed(x + 180, y + 28, 11, 11) )
	{
		RenderBitmap(71529, x + 178, y + 27, 11, 11, 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71529, x + 178, y + 27, 11, 11, 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
}

void WindowsInfoShop(int a1)
{
	int This; // ST24_4@1
	float x; // ST08_4@1
	float y; // ST04_4@1
	int v6; // eax@1
	char v7[256]; // al@4
	int Color; // ST18_4@2

	This = GetWindowShop(GetInstance());
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	*(signed int *)(This + 20) = 1;

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));

	if ( *(BYTE *)(This + 36) )
	{
		RenderBitmap(71541, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
	}
	else
	{
		RenderBitmap(71543, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);
	}

	if ( *(DWORD *)(This + 16) )
	{
		*(DWORD *)((*(DWORD *)(This + 16)) + 44) = ReturnY(y + TransForY(75));
		int t = *(DWORD *)((*(DWORD *)(This + 16)) + 56) * RetangleInventory( 17 );
		*(DWORD *)((*(DWORD *)(This + 16)) + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	}
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 230));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0, (LPINT)3, 0);
	//-- Tax Rate
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1623), *(DWORD *)(This + 32));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(350)), v7, Return2X(Width), 0, (LPINT)3, 0);
	//--
	if ( *(BYTE *)(This + 36) )
	{
		pSetTextColor(pTextThis(), 0xFFu, 0xDCu, 0x96u, 0xFFu);
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, 239)); //-- Repair All
		pDrawText(pTextThis(), Return2X(x + TransForX(45)), ReturnY(y + TransForY(363)), v7, 0, 0,(LPINT) 1, 0);

		pGetMoneyFormat(*(DWORD *)0x81F6BC8, v7, 0);
		Color = ColorMoney(*(DWORD *)0x81F6BC8);
		SetTextColorByHDC(pTextThis(), Color);
		pDrawText(pTextThis(), Return2X(x + TransForX(140)), ReturnY(y + TransForY(363)), v7, 0, 0,(LPINT) 7, 0);
		//--
		pDrawPuntero(This + 40, 1, 51522, 0, 0, 0);
		ChangeButtonInfo((char *)(This + 40), Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

		if( CheckButtonPressed(Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) || CheckRepairShop(GetWindowShop((int)pWindowThis())) == 2 )
		{
			RenderBitmap(71542, Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71542, Return2X(x + TransForX(31)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, 1559)); //-- Repair
		pDrawText(pTextThis(), Return2X(x + TransForX(31)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
		//--
		pDrawPuntero(This + 212, 1, 51522, 0, 0, 0);
		ChangeButtonInfo((char *)(This + 212), Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));

		if( CheckButtonPressed(Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))) )
		{
			RenderBitmap(71542, Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.268338412, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71542, Return2X(x + TransForX(116)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.02, 0.7135385275, 0.2283384204, 1, 1, 0);
		}
		pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
		ZeroMemory(v7, sizeof(v7));
		wsprintf(v7, pGetTextLine(pTextLineThis, 239)); //-- Repair All
		pDrawText(pTextThis(), Return2X(x + TransForX(116)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	}
}

int WindowsInfoStore(int a1)
{
	int This; // ST3C_4@1
	float y; // ST18_4@1
	float x; // ST14_4@1
	char v7[256]; // eax@1
	int Width;
	int Heigth;

	This = pWindowStore(GetInstance());
	Width = TransForX( 190 );
	Heigth = TransForY( 429 );

	if( pCheckWindow(pWindowThis(), ExpandInventory) )
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 3));
	}
	else
	{
		*(signed int *)(This + 20) = Return2X(TransFor2X(640) - (Width * 2));
	}

	x = TransFor2X((double)*(signed int *)(This + 20));
	y = TransForY((double)*(signed int *)(This + 24));

	RenderBitmap(71544, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	if ( *(DWORD *)(This + 16) )
	{
		int t = *(DWORD *)((*(DWORD *)(This + 16)) + 56) * RetangleInventory( 17 );
		*(DWORD *)((*(DWORD *)(This + 16)) + 40) = Return2X(x + (Width / 2) - TransFor2X(t / 2));
	}
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);

	//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1102));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v7, Return2X(Width), 0, (LPINT)3, 0);

	//-- Abrir Store
	pDrawPuntero(*(DWORD *)(This + 40) + 172, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(*(DWORD *)(This + 40) + 172), Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( CheckButtonPressed(Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(71535, Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1107));
	pDrawText(pTextThis(), Return2X(x + (Width / 2) - TransForX(64.5)), ReturnY(TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	
	//-- Cerrar Store
	pDrawPuntero(*(DWORD *)(This + 40) + 344, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(*(DWORD *)(This + 40) + 344), Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)));
	if( CheckButtonPressed(Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17))))
	{
		RenderBitmap(71535, Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(387)), Return2X(TransForX(43)), ReturnY(TransForY(17)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	ZeroMemory(v7, sizeof(v7));
	wsprintf(v7, pGetTextLine(pTextLineThis, 1108)); //-- Repair All
	pDrawText(pTextThis(), Return2X(x + (Width / 2) + TransForX(43/2)), ReturnY(y + TransForY(390)), v7, Return2X(TransForX(43)), 0,(LPINT) 3, 0);
	//-- Cerrar
	pDrawPuntero(*(DWORD *)(This + 40) + 0, 1, 51522, 0, 0, 0);
	
	ChangeButtonInfo((char *)(*(DWORD *)(This + 40) + 0), Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10)));
	
	if( CheckButtonPressed(Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10))) )
	{
		RenderBitmap(71529, Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10)), 0.0, 0.0, 0.6535385251, 0.1583384364, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71529, Return2X(x + TransForX(158)), ReturnY( y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(10)), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 1, 1, 0);
	}

	SetBoundInputField( *(DWORD *)(This + 44), Return2X(x + TransForX( 53 )), *(DWORD *)(This + 24) + 65 );

	gOffTrade.DrawOffTradeWindowEx700(x, y);

	return 1;
}

char WindowInfoCommand(int a1)
{
	int This; // [sp+2Ch] [bp-1Ch]@1
	char v10[255]; // ST24_4@1
	float y; // ST08_4@1
	float x; // ST04_4@1
	signed int i; // [sp+44h] [bp-4h]@1
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );
	int v33; // [sp+40h] [bp-8h]@8

	EnableAlphaTest(1);
	glColor4f(1.0, 1.0, 1.0, 1.0);
	This = *(DWORD *)(GetInstance() + 148);

	*(signed int *)(This + 16) = Return2X(TransFor2X(640) - Width);
	x = TransFor2X((double)*(signed int *)(This + 16));
	y = TransForY((double)*(signed int *)(This + 20));

	RenderBitmap(71526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

		//-- TitleName
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 938));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v10, Return2X(Width), 0, (LPINT)3, 0);
	//-- Cerrar
	pDrawPuntero(This + 1916, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 1916), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	if( CheckButtonPressed(Return2X(x + TransForX(158)), Return2X(y + TransForX(28)), Return2X(TransForX(11)), Return2X(TransForX(11))) )
	{
		RenderBitmap(71529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	else
	{
		RenderBitmap(71529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	//--
	int Button;
	for ( i = 0; i < 11; ++i )
	{
		Button = This + 172 * i + 24;
		*(DWORD *)(Button + 116) = (int)pFontNormal;
		if ( *(DWORD *)(This + 2088) != -1 )
		{
			*(DWORD *)(Button + 116) = (int)pFontBold;
		}
		ChangeButtonInfo((char *)(Button), Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30)));
		if( CheckButtonPressed( Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30))) )
		{
			RenderBitmap(71535, Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		else
		{
			RenderBitmap(71535, Return2X(x + TransForX((190 / 2) - (110 / 2))), ReturnY(y + TransForY(55 + (31*i))), Return2X(TransForX(110)), ReturnY(TransForY(30)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
		}
		pDrawPuntero(Button, 1, 51522, 0, 0, 0);
		sub_7798F0(Button, 0);
	}
	if ( *(DWORD *)(This + 2092) == 9 && *(BYTE *)(This + 2096) == 1 )
	{
		v33 = pGetPreviewStruct(pPreviewThis(), pViewAttackTargetID);

		if ( v33 )
		{
			if ( *(BYTE *)(v33 + 800) == 1
				&& v33 != *(DWORD *)0x7BC4F04
				&& (*(DWORD *)(v33 + 824) == 1163 || *(BYTE *)(v33 + 15)) )
			{
				RenderBitmap(31599, Return2X(TransFor2X((double)*(DWORD *)0x879340C + 5.0)), ReturnY(TransForY((double)*(DWORD *)0x8793410 + 5.0)), Return2X(TransForX(128)), ReturnY(TransForY(32)), 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
				pSetFont(pTextThis(), (int)pFontBigBold);
				if ( *(BYTE *)(This + 2097) )
				{
					pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				}
				else
				{
					pSetTextColor(pTextThis(), 0xFFu, 0, 0, 0xFFu);
				}
				pSetBackgroundTextColor(pTextThis(), 0x14u, 0x14u, 0x14u, 0);
				
				pDrawText(pTextThis(), Return2X(TransFor2X(*(DWORD *)0x879340C + 69)), ReturnY(TransForY((double)*(DWORD *)0x8793410 + 12)), (LPCTSTR)v33 + 56, 0, 0, (PINT)8, 0);
				pSetFont(pTextThis(), (int)pFontNormal);
			}
		}
	}
	pGLSwitch();
	return 1;
}


int WindowNPCJulia(int a1)
{
	int This; // ST2C_4@1
	float y; // ST10_4@1
	float x; // ST0C_4@1
	char v25[256]; // [sp+28h] [bp-108h]@1
	int Width = TransForX( 190 );
	int Heigth = TransForY( 429 );

	EnableAlphaTest(1);
	This = *(DWORD *)(GetInstance() + 292);

	*(signed int *)(This + 24) = Return2X(TransFor2X(640) - Width);
	x = TransFor2X((double)*(signed int *)(This + 24));
	y = TransForY((double)*(signed int *)(This + 28));

	RenderBitmap(71526, x, y, Width, Heigth, 0.0, 0.0, 0.6245000958, 0.6245000958, 0, 0, 0);

	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C58C);
	pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);
	//--Titulo
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v25, sizeof(v25));
	wsprintf(v25, pGetTextLine(pTextLineThis, 3000));
	pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(27)), v25, Return2X(Width), 0, (LPINT)3, 0);
	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	pSetFont(pTextThis(), (int)*(HGDIOBJ*)0xE8C588);
	//--
	if ( *(DWORD *)0xE61E18 == 79 )
	{
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3010));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(60)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3011));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(80)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3012));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(100)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3013));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(180)), v25, Return2X(Width), 0, (LPINT)3, 0);
	}
	else
	{
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3013));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(60)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3003));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(80)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3004));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(100)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3005));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(120)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3006));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(140)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3007));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(160)), v25, Return2X(Width), 0, (LPINT)3, 0);
		ZeroMemory(v25, sizeof(v25));
		wsprintf(v25, pGetTextLine(pTextLineThis, 3008));
		pDrawText(pTextThis(), Return2X(x), ReturnY(y + TransForY(180)), v25, Return2X(Width), 0, (LPINT)3, 0);
	}

	if ( *(DWORD *)(This + 380) == 1 )
	{
		(*(void (__thiscall **)(int))(*(DWORD *)(This + 32) + 4))(This + 32);

		sub_779740(This + 32, 0, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
		sub_779740(This + 32, 1, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
		sub_779740(This + 32, 2, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
		//sub_7853D0(This + 32, pMakeColor(0x64u, 0x64u, 0x64u, 0xFFu));
	}
	else
	{
		(*(void (__thiscall **)(int))(*(DWORD *)(This + 32) + 8))(This + 32);

		sub_779740(This + 32, 0, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		sub_779740(This + 32, 1, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		sub_779740(This + 32, 2, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
		//sub_7853D0(v39 + 32, pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
	}

	int Button = This + 204;
	pDrawPuntero(Button, 1, 51522, 0, 0, 0);
	ChangeButtonInfo((char *)(Button), Return2X(x + TransForX( 158 )), ReturnY(y + TransForY(28)), Return2X(TransForX(11)), ReturnY(TransForY(11)));
	if( CheckButtonPressed(Return2X(x + TransForX(158)), Return2X(y + TransForX(28)), Return2X(TransForX(11)), Return2X(TransForX(11))) )
	{
		RenderBitmap(71529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.0, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	else
	{
		RenderBitmap(71529, x + TransForX(158), y + TransForY(28), TransForX(11), TransForY(11), 0.0, 0.3306768537, 0.6535385251, 0.1583384364, 0, 0, 0);
	}
	sub_7798F0(Button, 0);

	Button = This + 32;
	ChangeButtonInfo((char *)(Button), Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22)));
	if( CheckButtonPressed( Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22))) )
	{
		RenderBitmap(71535, Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22)), 0.0, 0.2235384732, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	else
	{
		RenderBitmap(71535, Return2X(x + TransForX(63)), ReturnY(y + TransForY(220)), Return2X(TransForX(64)), ReturnY(TransForY(22)), 0.0, 0.0, 0.5035384717, 0.2215384692, 1, 1, 0);
	}
	pDrawPuntero(Button, 1, 51522, 0, 0, 0);
	sub_7798F0(Button, 0);

	pGLSwitch();
	return 1;
}


int PartyTitleName(int x, int y, LPCTSTR Text)
{
	char v10[255];

	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 190));
	
	return pDrawText(pTextThis(), x, y + 15, v10, 72, 0, (LPINT)3, 0);
}

int PartyTextTopic(int x, int y, LPCTSTR Text)
{
	char v10[255];

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 191));
	return pDrawText(pTextThis(), x, y, v10, 0, 0, (LPINT)3, 0);
}

int GuildTextTopic(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)
{
	char v10[255];

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 180));

	return pDrawColorText(v10, PosX, PosY + 15, Width, Arg5, eTextGuild, Arg7, Align);
}

int GuildMasterTextTopic(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)
{
	char v10[255];

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 180));

	return pDrawColorText(v10, PosX, PosY + 15, Width, Arg5, eTextGuild, Arg7, Align);
}

int GuildMasterTextTopic2(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)
{
	char v10[255];

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 181));

	return pDrawColorText(v10, PosX, PosY + 15, Width, Arg5, Color, Arg7, Align);
}

int GuildMasterNameGuildTopic(LPCTSTR Text, int PosX, int PosY, int Width, int Arg5, int Color, int Arg7, int Align)
{
	char v10[255];

	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	ZeroMemory(v10, sizeof(v10));
	wsprintf(v10, pGetTextLine(pTextLineThis, 182));

	return pDrawColorText(v10, PosX + 6, PosY, Width, Arg5, eTextGuild, Arg7, Align);
}

int GuildMasterTextScore(int X, int Y, LPCTSTR Text)
{
	return pDrawText(pTextThis(), X, Y + 8, Text, 120, 0, (LPINT)3, 0);
}

int GuildInfoTextTitle(int X, int Y, LPCTSTR Text)
{	
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	return pDrawText(pTextThis(), X, Y + 15, Text, 190, 0, (LPINT)3, 0);
}

int GuildInfoText(int X, int Y, LPCTSTR Text)
{	
	pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
	return pDrawText(pTextThis(), X, Y + 15, Text, 0, 0, (LPINT)1, 0);
}

void RenderButtonQuestTb(DWORD id, float x, float y, float w, float h)
{
	pDrawGUI(id,(double) x + 1,(double) y + 26, w, h);
}

__declspec(naked) void RenderText1Quest()
{
	static DWORD Addr_JMP = 0x0083F6D9;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText2Quest(){
	static DWORD Addr_JMP = 0x0083F731;
	_asm{
		MOV EDX,DWORD PTR SS:[EBP-0x4]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText3Quest()
{
	static DWORD Addr_JMP = 0x0083F81D;
	_asm{
		MOV EAX,DWORD PTR SS:[EBP-4]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText4Quest()
{
	static DWORD Addr_JMP = 0x0083F875;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-4]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText5Quest()
{
	static DWORD Addr_JMP = 0x0083F8AD;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-4]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText6Quest()
{
	static DWORD Addr_JMP = 0x0083F961;
	_asm
	{
		MOV EDX,DWORD PTR SS:[EBP-4]
		MOV EAX,DWORD PTR DS:[EDX+0x14]
		ADD EAX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText7Quest()
{
	static DWORD Addr_JMP = 0x0083F9B9;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-4]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText8Quest()
{
	static DWORD Addr_JMP = 0x0083F9F1;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-4]
		MOV EDX,DWORD PTR DS:[ECX+0x14]
		ADD EDX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderText9Quest()
{
	static DWORD Addr_JMP = 0x0083F769;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-4]
		MOV ECX,DWORD PTR DS:[EAX+0x14]
		ADD ECX,59
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderQuestTabPane1()
{
	static DWORD Addr_JMP = 0x0083F4F0;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-4]             ; |
		MOV EDX,DWORD PTR DS:[ECX+20]            ; |
		ADD EDX,53                               ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderQuestTabPane2()
{
	static DWORD Addr_JMP = 0x0083F51F;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-4]             ; |
		MOV ECX,DWORD PTR DS:[EAX+20]            ; |
		ADD ECX,53                               ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderQuestTabPane3()
{
	static DWORD Addr_JMP = 0x0083F555;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-4]             ; |
		MOV ECX,DWORD PTR DS:[EAX+20]            ; |
		ADD ECX,53                               ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderQuestTabPane4()
{
	static DWORD Addr_JMP = 0x0083F58B;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-4]             ; |
		MOV ECX,DWORD PTR DS:[EAX+20]            ; |
		ADD ECX,53                               ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderInfoQuest1()
{
	static DWORD Addr_JMP = 0x0083ED89;
	_asm
	{
		MOV ECX,DWORD PTR SS:[EBP-12]            ; |
		MOV EDX,DWORD PTR DS:[ECX+20]            ; |
		ADD EDX,80                               ; |
		JMP[Addr_JMP]
	}
}

__declspec(naked) void RenderInfoQuest2()
{
	static DWORD Addr_JMP = 0x0083EDE7;
	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP-0xC]
		MOV ECX,DWORD PTR DS:[EAX+20]
		ADD ECX,98
		JMP[Addr_JMP]
	}
}

void windowsquestPlayer(int This)
{
	float y; // ST08_4@1
	float x; // ST04_4@1
	y = (double)*(signed int *)(This + 20);
	x = (double)*(signed int *)(This + 16);
	nInterface.DrawWindowBG(x, y);
	gInterface.DrawFormat(eGold, x, y + 27, 190, 3, "Quest");
	if(nInterface.Drawbutton(CustomWindow.CloseWindowsUP, x + 158.8, y + 24, "")){
		gInterface.CloseWindow(Quest);
	}
	pDrawPuntero(This + 24, 1, 31295, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 24), x + 50000, y + 50000, 11, 12);
	pDrawPuntero(This + 196, 1, 61525, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 196), x + 50, y + 392, 43, 17);
	pDrawPuntero(This + 368, 1, 61525, 0, 0, 0);
	ChangeButtonInfo((char *)(This + 368), x + 94, y + 392, 43, 17);
}

__declspec(naked) void RenderWindowsQuest()
{
	static DWORD Addrs = 0x0083EB44;
	static DWORD RenderBits = 0x00790B50;
	static DWORD This;
	_asm
	{
		MOV DWORD PTR SS:[EBP-4],ECX
		MOV EDX,DWORD PTR SS:[EBP-4]
		MOV This, EDX
	}

	windowsquestPlayer(This);

	_asm
	{
		JMP[Addrs]
	}
}


int CastleSiegeNPCTextTitle00(int X, int Y, LPCTSTR Text)
{	
	pSetTextColor(pTextThis(), 0xFFu, 0xBDu, 0x19u, 0xFFu);
	return pDrawText(pTextThis(), X, Y + 15, Text, 160, 0, (LPINT)3, 0);
}

int CastleSiegeNPCTextTitle01(int X, int Y, LPCTSTR Text)
{	
	pSetTextColor(pTextThis(), 0xDCu, 0xDCu, 0xDCu, 0xFFu);
	return pDrawText(pTextThis(), X, Y + 6, Text, 190, 0, (LPINT)3, 0);
}

int ItemObjectClass;
int This_;

__declspec (naked) void RecvNumberStack()
{
	static DWORD main_addr = 0x007DC909;

	_asm
	{
		MOV ECX,DWORD PTR DS:[EAX]
		MOV DWORD PTR SS:[EBP-0x18],ECX
		MOV ItemObjectClass, ECX
		MOV EDX,DWORD PTR SS:[EBP-0x34]
		MOV This_, EDX
		JMP[main_addr]
	}
}

double JCRenderNumberEx(float a1, float a2, int a3, float a4, DWORD ModelID)
{
	double result; // st7@2
	float v5; // ST44_4@5
	float v6; // ST38_4@5
	signed int i; // [sp+38h] [bp-30h]@3
	float v8; // [sp+3Ch] [bp-2Ch]@3
	signed int v9; // [sp+44h] [bp-24h]@3
	char v10[32]; // [sp+48h] [bp-20h]@3
	float v11; // [sp+70h] [bp+8h]@3


	if ( a4 >= 0.300000011920929 )
	{
		v8 = (a4 - 0.4800000119209290) * 12.0;
		itoa(a3, v10, 10);
		v9 = strlen(v10);
		v11 = a1 - (double)v9 * v8 / 2.0;
		for ( i = 0; i < v9; ++i )
		{
			v6 = (double)(v10[i] - 48) * 12.0 / 128.0;
			v5 = (a4 - 0.400000011920929) * 16.0;
			RenderBitmap(ModelID, v11, a2, v8, v5, v6, 0.0, 0.09375, 0.875, 1, 1, 0.0);
			v11 = v8 * 0.800000011920929 + v11;
		}
		result = v11;
	}
	else
	{
		result = a1;
	}
	return result;
}


void JCNumberStack(float x, float y, int Number, float scale)
{
	float v23; // ST14_4@38
	float v24; // ST10_4@38
	float v29; // [sp+84h] [bp-1Ch]@3
	float v31; // [sp+8Ch] [bp-14h]@3
	float v32; // [sp+90h] [bp-10h]@3
	int v33; // [sp+94h] [bp-Ch]@3

	v33 = *(DWORD *)0x8128AC0 + 84 * *(WORD *)ItemObjectClass;
	v31 = (double)(RetangleInventory( 17 ) * *(BYTE *)(ItemObjectClass + 67) + *(DWORD *)(This_ + 40));
	v32 = (double)(17 * *(BYTE *)(ItemObjectClass + 68) + *(DWORD *)(This_ + 44));
	v29 = (double)(RetangleInventory( 17 ) * *(BYTE *)(v33 + 38));

	v23 = v32 + 1.0;
	v24 = v31 + v29 - Return2X(TransForX(6.0));
	JCRenderNumberEx(v24, v23, Number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);
}

int sub_895600(float x, float y, int number)
{
	int result; // eax@1

	pSetBlend( 1 );

	result = CRenderNumberEx(x, y, number, ( pWinWidthReal <= 1.6 ) ? 1.0 : 0.90, 31337);

	return result;
}

void CEx700::Init()
{
	//SetByte(0x00883A1E+1,65);
	//SetByte(0x00883A1C+1,26);
	SetDword(0x00883A0D+1,81536); // CS
	SetDword(0x00882CEA+1,(DWORD)"Interface\\GFx\\ex700\\newui_exit_00.tga");
	SetDword(0x00088424A+1,(DWORD)"Interface\\GFx\\ex700\\newui_exit_00.tga");


	SetCompleteHook(0xE9, 0x00895600, &sub_895600); //-- Number Stack
	SetCompleteHook(0xE9, 0x007DC904, &RecvNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DC9E6, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCA78, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCB05, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCB96, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCC16, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCCA8, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCD35, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCDB4, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCE51, &JCNumberStack); //-- Number Stack
	SetCompleteHook(0xE8, 0x007DCEE7, &JCNumberStack); //-- Number Stack

	SetRange((LPVOID)0x0083E6A0, 5, ASM::NOP);
    SetCompleteHook(0xE9, 0x0083ED80, &RenderInfoQuest1);
    SetCompleteHook(0xE9, 0x0083EDDE, &RenderInfoQuest2);
    SetCompleteHook(0xE9, 0x0083F760, &RenderText9Quest);
    SetCompleteHook(0xE9, 0x0083F9E8, &RenderText8Quest);
    SetCompleteHook(0xE9, 0x0083F9B0, &RenderText7Quest);
    SetCompleteHook(0xE9, 0x0083F958, &RenderText6Quest);
    SetCompleteHook(0xE9, 0x0083F8A4, &RenderText5Quest);
    SetCompleteHook(0xE9, 0x0083F86C, &RenderText4Quest);
    SetCompleteHook(0xE9, 0x0083F814, &RenderText3Quest);
    SetCompleteHook(0xE9, 0x0083F728, &RenderText2Quest);
    SetCompleteHook(0xE9, 0x0083F6D0, &RenderText1Quest);
    SetCompleteHook(0xE9, 0x0083F4E7, &RenderQuestTabPane1);
    SetCompleteHook(0xE9, 0x0083F516, &RenderQuestTabPane2);
    SetCompleteHook(0xE9, 0x0083F54C, &RenderQuestTabPane3);
    SetCompleteHook(0xE9, 0x0083F582, &RenderQuestTabPane4);
    SetCompleteHook(0xE8, 0x0083F618, &RenderButtonQuestTb);
    SetCompleteHook(0xE8, 0x0083F690, &RenderButtonQuestTb);
    SetCompleteHook(0xE8, 0x0083F7D4, &RenderButtonQuestTb);
    SetCompleteHook(0xE8, 0x0083F918, &RenderButtonQuestTb);
    SetCompleteHook(0xE9, 0x0083EA16, &RenderWindowsQuest);

	//SKILL INTERFACE S15
	SetCompleteHook(0xE8, 0x004F9477, &Render_SkillTooltip); //-- Tooltip Skill Raven
	SetCompleteHook(0xE8, 0x005C6680, &Render_SkillTooltip); //-- Tooltip Skill
	SetCompleteHook(0xE9, 0x008126C0, &CEx700::SkillMouseOver);
	SetCompleteHook(0xE9, 0x00813970, &CEx700::SkillSwitchBar);
//	SetCompleteHook(0xE9, 0x00813746, &CEx700::SkillSelectBar);

	//CHARACTER INFO INTERFACE S15
	SetCompleteHook(0xE8, 0x0077F7EE, &CharacterInfoWindow); // denis
	SetRange((LPVOID)0x0077E906, 5, 0x90); //-- Evento Button
	SetCompleteHook(0xE9, 0x0077F8CA, &InformationServer1); //-- Text
	SetCompleteHook(0xE9, 0x0077FA1C, &InformationServer2); //-- Text
	SetCompleteHook(0xE9, 0x0077FAA7, &InformationServer3); //-- Text
	SetRange((LPVOID)0x0077F822, 5, 0x90); //-- Información 1
	//-- Stadistica Str
	SetCompleteHook(0xE9, 0x007801D7, &InformationSTR1); //-- Text
	SetCompleteHook(0xE9, 0x00780215, &InformationSTR2); //-- Point
	SetCompleteHook(0xE9, 0x00781758, &InformationSTR3); //-- Dmg
	SetCompleteHook(0xE9, 0x00781805, &InformationSTR4); //-- Attack Rate
	//-- Stadistica Agi
	SetCompleteHook(0xE9, 0x0078190B, &InformationAGI1); //-- Text
	SetCompleteHook(0xE9, 0x0078194C, &InformationAGI2); //-- Point
	SetCompleteHook(0xE9, 0x00782854, &InformationAGI3); //-- Defense Rate
	SetCompleteHook(0xE9, 0x00782A30, &InformationAGI4); //-- AttackSpeed
	SetCompleteHook(0xE9, 0x00782B83, &InformationAGI5); //-- Defense
	//-- Stadistica Vit
	SetCompleteHook(0xE9, 0x00782D13, &InformationVIT1); //-- Text
	SetCompleteHook(0xE9, 0x00782D54, &InformationVIT2); //-- Point
	SetCompleteHook(0xE9, 0x00782F69, &InformationVIT3); //-- HP
	SetCompleteHook(0xE9, 0x00782FDF, &InformationVIT4); //-- Mele %
	//--Stadistica Ene
	SetCompleteHook(0xE9, 0x007830ED, &InformationENE1); //-- Text
	SetCompleteHook(0xE9, 0x0078312E, &InformationENE2); //-- Point
	SetCompleteHook(0xE9, 0x007832D5, &InformationENE3); //-- MANA
	SetCompleteHook(0xE9, 0x00784029, &InfoMagicDMG1); //-- magic
	SetCompleteHook(0xE9, 0x0078482D, &InfoMagicDMG2); //-- curse
	SetCompleteHook(0xE9, 0x007848A5, &InfoSkillDMG1); //-- Skill Dmg BK
	SetCompleteHook(0xE9, 0x00784904, &InfoSkillDMG2); //-- Skill Dmg MG
	SetCompleteHook(0xE9, 0x00784973, &InfoSkillDMG3); //-- Skill Dmg DL
	SetCompleteHook(0xE9, 0x007849E4, &InfoSkillDMG4); //-- Skill Dmg DL
	SetCompleteHook(0xE9, 0x00784A64, &InfoSkillDMG5); //-- Skill Dmg DL
	//--Stadistica Cmd
	SetCompleteHook(0xE9, 0x00784B6B, &InformationCMD1); //-- Text
	SetCompleteHook(0xE9, 0x00784BAC, &InformationCMD2); //-- Point

	//inventory
	SetCompleteHook(0xE8, 0x00836EF6, &LoadWindows);
	SetCompleteHook(0xE8, 0x00836F2A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836F67, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836FB0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00836FEF, &LoadWindowsNone);

	SetCompleteHook(0xE8, 0x007DB7B0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB812, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB874, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB8E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB959, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DB9A2, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DBA20, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007DBA69, &LoadWindowsNone);
	
	SetCompleteHook(0xE9, 0x0083BAF4, &RemoveButtonStore1);
	SetCompleteHook(0xE9, 0x0083BB94, &RemoveButtonStore2);

	SetCompleteHook(0xE9, 0x00835CB1, &InfoTooltipSocket); //-- Posicion Mostrar Tooltip de Equipamiento
	SetCompleteHook(0xE9, 0x00835C86, &InfoTooltipAncestral); //-- Posicion Mostrar Tooltip de Equipamiento
	//--
	SetCompleteHook(0xE9, 0x0083516F, &RemoveTextAncestral); //-- Text Ancient
	SetCompleteHook(0xE9, 0x008352B1, &RemoveTextSocket); //-- Text Socket
	//--
	SetCompleteHook(0xE8, 0x0083538A, &CheckMouseSocket); //-- InfoOption Socket Equip
	SetCompleteHook(0xE8, 0x00834C8D, &CheckMouseAncestral); //-- InfoOption Ancient Equip

	SetRange((LPVOID)0x00835116, 5, 0x90); //-- Titulo + ZEN
	SetRange((LPVOID)0x008337B0, 5, 0x90); //-- Equipamiento
	SetRange((LPVOID)0x0083443C, 5, 0x90); //-- Equipamiento
	SetRange((LPVOID)0x008337B8, 5, 0x90); //-- Button

	SetRange((LPVOID)0x007D4FA6, 5, 0x90); //-- Titulo
	SetCompleteHook(0xE8, 0x007D582D, &LoadWindowsNone);//-- parte del inventario extend
	SetCompleteHook(0xE8, 0x007D587C, &RenderInvExtSlot);
	//SetCompleteHook(0xE8, 0x007D58CF, &RenderInvExtNum);
	
	//-- Inventory Ext.
	SetCompleteHook(0xE8, 0x007D4F9E, &WindowsInfoInventoryExt);
	//-- Inventario
	SetCompleteHook(0xE8, 0x0083510E, &WindowsInfoInventory); //DENIS

	//-- Test SlotInventory
	SetCompleteHook(0xE8, 0x007DB4D8, &ItemSlotDurability);//--
	SetCompleteHook(0xE8, 0x007DBD3D, &ItemSlotDurability);
	SetCompleteHook(0xE8, 0x007DC197, &ItemSlotDurability);
	//--
	SetCompleteHook(0xE8, 0x007DB5D0, &ItemSlotEmpty);//--
	SetCompleteHook(0xE8, 0x007DB63E, &ItemSlotEmpty);
	SetCompleteHook(0xE8, 0x007DB6D2, &ItemSlotEmpty);
	SetCompleteHook(0xE8, 0x007DB737, &ItemSlotEmpty);

	SetCompleteHook(0xE9, 0x007DD4F3, &GetInfoModelSlot);
	SetCompleteHook(0xE8, 0x007DD5C0, &ObjectModelScaleSlot);

	SetCompleteHook(0xE9, 0x007DC4C9, &RenderMouseRECT);
	SetCompleteHook(0xE9, 0x007DB239, &RenderRect);
	//outras janelas ex803 
		
	//-- Window 1
	SetCompleteHook(0xE8, 0x007C1872, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C18AC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C18F5, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C1950, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C199B, &LoadWindowsNone);
	//-- Window 2
	SetCompleteHook(0xE8, 0x007C2676, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C26AA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C26EA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C273C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C2782, &LoadWindowsNone);
	//-- Window 3
	SetCompleteHook(0xE8, 0x007C46E6, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C471A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C4757, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C47A0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C47DF, &LoadWindowsNone);
	//-- Window 4
	SetCompleteHook(0xE8, 0x007C6BCC, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C6C06, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6C49, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6C98, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C6CDD, &LoadWindowsNone);
	//-- Window 5
	SetCompleteHook(0xE8, 0x007C7D0C, &LoadWindows);
	SetCompleteHook(0xE8, 0x007C7D46, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7D89, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7DD8, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007C7E1D, &LoadWindowsNone);
	//-- Window 6 Guild User
	SetCompleteHook(0xE8, 0x007CB6F6, &LoadWindows);
	SetCompleteHook(0xE8, 0x007CB72A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB767, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB7B0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007CB7EF, &LoadWindowsNone);

	//-- Window 7 Guild Maker
	SetCompleteHook(0xE8, 0x007D1786, &LoadWindows);
	SetCompleteHook(0xE8, 0x007D17BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D17F7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D1840, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007D187F, &LoadWindowsNone);

		//Windows Guild Info - Sem Guild
	SetCompleteHook(0xE8, 0x007CB8E5, &GuildInfoTextTitle);
	SetCompleteHook(0xE8, 0x007CB924, &GuildInfoText);
	SetCompleteHook(0xE8, 0x007CB959, &GuildInfoText);
	SetCompleteHook(0xE8, 0x007CB98E, &GuildInfoText);

	// Windows Guild Master - Criação de Guild
	SetDword(0x007D0889+1,71535); //Guild Buttons
	SetDword(0x007D084A+1,81535); //Guild Button
	SetCompleteHook(0xE8, 0x007D18D8, &GuildMasterTextTopic); // Guild Master (Line 180) CREANDO GUILD
	SetCompleteHook(0xE8, 0x007D1467, &GuildMasterTextTopic2); // Guild Master (Line 181) CREANDO GUILD
	SetCompleteHook(0xE8, 0x007D14ED, &GuildMasterNameGuildTopic); // Guild Master (Line 182) CREANDO GUILD

	//Windows Guild Info - Guild Criada
	SetCompleteHook(0xE8, 0x007CBABA, &GuildMasterTextTopic); // Guild Info (Line 180)
	SetCompleteHook(0xE8, 0x007CBB49, &GuildMasterTextScore); // Guild Info Score Text
	SetDword(0x007CA306+1,71535); //Guild Buttons
	//-- Window 8 Store
	//-- Window 9 MuHelper
	SetCompleteHook(0xE8, 0x007F65A6, &LoadWindows);
	SetCompleteHook(0xE8, 0x007F65E6, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F6638, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F66A2, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x007F66FA, &LoadWindowsNone);
	//-- Window 10 Config Helper
	SetCompleteHook(0xE8, 0x0080C848, &LoadWindows);
	SetCompleteHook(0xE8, 0x0080C87C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C8BC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C90E, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0080C954, &LoadWindowsNone);
	//-- Window 11 ChaosMachine
	SetCompleteHook(0xE8, 0x0082CA22, &WindowsChaosBox);
	SetCompleteHook(0xE8, 0x0082CB4B, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CB00, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CAA5, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0082CA5C, &LoadWindowsNone);
	//-- Window 13 Quest (T)
	SetCompleteHook(0xE8, 0x0083EA46, &LoadWindows);
	SetCompleteHook(0xE8, 0x0083EA7A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EAB7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EB00, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0083EB3F, &LoadWindowsNone);
	//-- Window 14
	SetCompleteHook(0xE8, 0x00841E49, &LoadWindows);
	SetCompleteHook(0xE8, 0x00841E7D, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841EBA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841F03, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00841F42, &LoadWindowsNone);
	//-- Window 15 Gens-Quest
	SetCompleteHook(0xE8, 0x00843826, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084385A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00843897, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008438E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084391F, &LoadWindowsNone);
	//-- Window 16
	SetCompleteHook(0xE8, 0x00845956, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084598A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008459C7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00845A10, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00845A4F, &LoadWindowsNone);
	//-- Window 17
	SetCompleteHook(0xE8, 0x008470A6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008470DA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00847117, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00847160, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084719F, &LoadWindowsNone);

	//-- Window 1
	SetCompleteHook(0xE8, 0x0077F209, &LoadWindows);
	SetCompleteHook(0xE8, 0x0077F23D, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0077F27A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0077F2C3, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0077F302, &LoadWindowsNone);
	//-- Window 1
	SetCompleteHook(0xE8, 0x00894226, &LoadWindows);
	SetCompleteHook(0xE8, 0x0089425A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00894297, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008942E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0089431F, &LoadWindowsNone);
	//-- Window 4
	SetCompleteHook(0xE8, 0x00850966, &LoadWindows);
	SetCompleteHook(0xE8, 0x0085099A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008509D7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00850A20, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00850A5F, &LoadWindowsNone);
	//-- Window 5
	SetCompleteHook(0xE8, 0x00852476, &LoadWindows);
	SetCompleteHook(0xE8, 0x008524AA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008524E7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00852530, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0085256F, &LoadWindowsNone);
	//-- Window 6
	SetCompleteHook(0xE8, 0x008540B6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008540EA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00854127, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00854170, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008541AF, &LoadWindowsNone);
	//-- Window 8
	SetCompleteHook(0xE8, 0x0087F886, &LoadWindows);
	SetCompleteHook(0xE8, 0x0087F8BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F8F7, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F940, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087F97F, &LoadWindowsNone);
	//-- Window 9 NPC CASTLE SIEGE
	SetCompleteHook(0xE8, 0x00882F52, &LoadWindows);
	SetCompleteHook(0xE8, 0x00882F8C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00882FD5, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00883030, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0088307B, &LoadWindowsNone);
	//-- Windows NPC Lugar
	SetCompleteHook(0xE8, 0x00893102, &LoadWindows);
	SetCompleteHook(0xE8, 0x0089313C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00893185, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008931E0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0089322B, &LoadWindowsNone);
	//-- Windows Guard NPC
	SetCompleteHook(0xE8, 0x008812A2, &LoadWindows);
	SetCompleteHook(0xE8, 0x008812DC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00881325, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00881380, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008813CB, &LoadWindowsNone);

	//-- Window 6 Guard NPC - SIEGE
	SetCompleteHook(0xE8, 0x00884512, &LoadWindows);
	SetCompleteHook(0xE8, 0x0088454C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00884595, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008845F0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0088463B, &LoadWindowsNone);
	

	
	SetCompleteHook(0xE8, 0x00884726, &CastleSiegeNPCTextTitle00);
	SetCompleteHook(0xE8, 0x008847E6, &CastleSiegeNPCTextTitle01);
	SetCompleteHook(0xE8, 0x00884882, &CastleSiegeNPCTextTitle01);

	//-- Windows NPC Senior
	SetCompleteHook(0xE8, 0x00879EE2, &LoadWindows);
	SetCompleteHook(0xE8, 0x00879F1C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00879F65, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00879FC0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087A00B, &LoadWindowsNone);
	//-- Windows BloodCastle
	SetCompleteHook(0xE8, 0x008747B6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008747F0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0087483C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008748A0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008748F2, &LoadWindowsNone);
	//-- Windows DevilSquare
	SetCompleteHook(0xE8, 0x008781BC, &LoadWindows);
	SetCompleteHook(0xE8, 0x008781F0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00878230, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00878282, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008782C8, &LoadWindowsNone);
	//-- Windows Pet
	SetCompleteHook(0xE8, 0x0084D01A, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084D05A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D0AC, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D116, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084D16E, &LoadWindowsNone);
	//-- Windows Party
	SetCompleteHook(0xE8, 0x0084A6AD, &PartyTitleName); //Title
	SetCompleteHook(0xE8, 0x0084A79D, &PartyTextTopic); //Texts

	SetCompleteHook(0xE8, 0x0084A546, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084A57A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A5BA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A60C, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084A652, &LoadWindowsNone);

	//-- Windows Baul
	SetRange((LPVOID)0x00858016, 0x5, 0x90); //-- Boton expaned
	SetRange((LPVOID)0x00857898, 0x5, 0x90); //-- Titulo
	SetCompleteHook(0xE8, 0x00857890, &WindowsInfoWareHouse); // ??

	//-- Windows Baul Ext.
	SetRange((LPVOID)0x00856776, 0x5, ASM::NOP); //-- Titulo
	SetCompleteHook(0xE8, 0x0085676E, &WindowsInfoWareHouseExt);

	//-- Windows Shop
	SetRange((LPVOID)0x00847046, 0x5, 0x90); //-- Zen
	SetRange((LPVOID)0x00847036, 0x5, 0x90); //-- Titulo
	SetCompleteHook(0xE8, 0x0084702E, &WindowsInfoShop);

		//-- Windows Trade
	SetCompleteHook(0xE8, 0x008643B6, &LoadWindows);
	SetCompleteHook(0xE8, 0x008643EA, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00864427, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x00864470, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x008644AF, &LoadWindowsNone);

	//-- Windows Store Other PJ
	SetCompleteHook(0xE8, 0x0084F406, &LoadWindows);
	SetCompleteHook(0xE8, 0x0084F43A, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F477, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F4C0, &LoadWindowsNone);
	SetCompleteHook(0xE8, 0x0084F4FF, &LoadWindowsNone);

	//-- Windows Store
	SetCompleteHook(0xE8, 0x00842460, &WindowsInfoStore);

	//-- Windows Command
	SetCompleteHook(0xE9, 0x0078E390, &WindowInfoCommand);

	//-- Windows NPC_Julia
	SetCompleteHook(0xE9, 0x008679D0, &WindowNPCJulia);

}