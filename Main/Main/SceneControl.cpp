#include "stdafx.h"
#include "SceneControl.h"
#include "Import.h"
#include "Pet.h"
#include "Protect.h"
#include "TMemory.h"
#include "Util.h"

MultiSelect gSelectCharRamdon;

void MultiSelect::LoadMultiChar(SelectChar * info)
{
	for(int n = 0 ; n < MAX_WORLD_SETTINGS; n ++)
	{
		if(info[n].Index < 0 || info[n].Index >= MAX_WORLD_SETTINGS)
		{
			return;
		}
		gSelectCharRamdon.RenderSelect = info[n];
	}
}

void MultiSelect::LoadMultiSrv(SelectSrv * linfo)
{
	for(int n = 0 ; n < MAX_WORLD_SETTINGS; n ++)
	{
		if(linfo[n].Index < 0 || linfo[n].Index >= MAX_WORLD_SETTINGS)
		{
			return;
		}
		gSelectCharRamdon.RenderSelectSrv = linfo[n];
	}
}

DWORD SelectCharacterCord(int a4)
{
	int v4; // ST1C_4@11
	char v5; // ST14_1@12
	void *v6; // eax@12
	int v7; // eax@12
	DWORD result; // eax@12
	int v9; // [sp+14h] [bp-20h]@5
	int v10; // [sp+18h] [bp-1Ch]@5
	float v11; // [sp+1Ch] [bp-18h]@5
	float v12; // [sp+20h] [bp-14h]@0
	float v13; // [sp+24h] [bp-10h]@0
	signed int i; // [sp+28h] [bp-Ch]@3
	signed int v15; // [sp+30h] [bp-4h]@3

	sub_63CB40();
	sub_4D5130(*(BYTE *)(a4 + 4));

	if ( pPlayerState == 4 )
		World = gSelectCharRamdon.RenderSelect.MapChar;
	v15 = 8;

	for ( i = 0; i < *(BYTE *)(a4 + 6); ++i )
	{
		v9 = v15 + a4;
		v10 = (unsigned __int8)sub_587380(*(BYTE *)(v15 + a4 + 15));
		v11 = 0.0;

		if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
		{
			switch ( *(BYTE *)(v15 + a4) )
			{
				case 0:
					v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX;// 8008.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY;// 18885.0;
					v11 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate;// 115.0;
				break;
				case 1:
					v12 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX;// 7986.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY;// 19145.0;
					v11 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate;// 90.0;
				break;
				case 2:
					v12 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX;// 8046.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY;// 19400.0;
					v11 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate;// 75.0;
				break;
				case 3:
					v12 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX;// 8133.000;
					v13 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY;// 19645.0;
					v11 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate;// 60.0;
				break;
				case 4:
					v12 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY;// 19845.0;
					v11 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate;// 35.0;
				break;
				default:
				break;
			}
		}
		else
		{
			switch ( *(BYTE *)(v15 + a4) )
			{
				case 0:
					v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX;// 8008.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY;// 18885.0;
					v11 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate;// 115.0;
				break;
				case 1:
					v12 = 0.0f;// 7986.0;
					v13 = 0.0f;// 19145.0;
					v11 = 0.0f;// 90.0;
				break;
				case 2:
					v12 = 0.0f;// 7986.0;
					v13 = 0.0f;// 19145.0;
					v11 = 0.0f;// 90.0;
				break;
				case 3:
					v12 = 0.0f;// 7986.0;
					v13 = 0.0f;// 19145.0;
					v11 = 0.0f;// 90.0;
				break;
				case 4:
					v12 = 0.0f;// 7986.0;
					v13 = 0.0f;// 19145.0;
					v11 = 0.0f;// 90.0;
				break;
				default:
				break;
			}
		}
		//gInfoLog.Output(LOG_CHAT,"[%d] [%d]",v9,v10);
		v4 = sub_586DA0(*(BYTE *)v9, v10, 0, v12, v13, v11);//-- Agrega Personaje con Coordenada

		*(WORD *)(v4 + 130) = *(WORD *)(v9 + 12);

		*(BYTE *)(v4 + 21) = *(BYTE *)(v9 + 14);

		sub_9CF1C0((char *)(v4 + 56), (const void *)(v9 + 1), 0xAu);

		*(BYTE *)(v4 + 66) = 0;

		gCustomPet.PreviewCharSet(*(BYTE *)v9, (BYTE *)( v9 + 16), 0, 0);//-- Mostrar Equipamiento

		*(BYTE *)(v4 + 24) = *(BYTE *)(v9 + 33);

		v15 += 34;
	}

	*(DWORD*)0x87935A4 = 51;

	pWarehouseExSet(pWarehouseExThis(pWindowThis()), *(BYTE *)(a4 + 7));

	result = GetTickCount();
	*(DWORD*)0xE8CB30 = result;
	return result;
}

signed int SelectCreateCharCoord(int a4)
{
	double v1; // ST14_4@8
	float v4; // ST14_4@8
	int v5; // eax@8
	void *v6; // ST24_4@10
	signed int result; // eax@10
	void *v8; // eax@12
	void *v9; // eax@14
	float v10; // [sp+1Ch] [bp-14h]@2
	DWORD v11; // [sp+20h] [bp-10h]@8
	float v12; // [sp+24h] [bp-Ch]@0
	float v13; // [sp+28h] [bp-8h]@0

	if ( *(BYTE *)(a4 + 4) == 1 )
	{
		v10 = 0.0;

		if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
		{
			switch ( *(BYTE *)(a4 + 15) )
			{
				case 0:
					v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY;// 19845.0;
					v10 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate;// 35.0;
				break;
				case 1:
					v12 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.CoordY;// 19845.0;
					v10 = gSelectCharRamdon.RenderSelect.PJ[1].Coordenada1.Rotate;// 35.0;
				break;
				case 2:
					v12 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.CoordY;// 19845.0;
					v10 = gSelectCharRamdon.RenderSelect.PJ[2].Coordenada1.Rotate;// 35.0;
				break;
				case 3:
					v12 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.CoordY;// 19845.0;
					v10 = gSelectCharRamdon.RenderSelect.PJ[3].Coordenada1.Rotate;// 35.0;
				break;
				case 4:
					v12 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.CoordY;// 19845.0;
					v10 = gSelectCharRamdon.RenderSelect.PJ[4].Coordenada1.Rotate;// 35.0;
				break;
				default:
				break;
			}
		}
		else
		{
			switch ( *(BYTE *)(a4 + 15) )
			{
				case 0:
					v12 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordX;// 8282.0;
					v13 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.CoordY;// 19845.0;
					v10 = gSelectCharRamdon.RenderSelect.PJ[0].Coordenada1.Rotate;// 35.0;
				break;
				case 1:
					v12 = 0.0f;// 8282.0;
					v13 = 0.0f;// 19845.0;
					v10 = 0.0f;// 35.0;
				break;
				case 2:
					v12 = 0.0f;// 8282.0;
					v13 = 0.0f;// 19845.0;
					v10 = 0.0f;// 35.0;
				break;
				case 3:
					v12 = 0.0f;// 8282.0;
					v13 = 0.0f;// 19845.0;
					v10 = 0.0f;// 35.0;
				break;
				case 4:
					v12 = 0.0f;// 8282.0;
					v13 = 0.0f;// 19845.0;
					v10 = 0.0f;// 35.0;
				break;
				default:
				break;
			}
		}
		sub_57D760(*(BYTE *)(a4 + 15));
		sub_586DA0(*(BYTE *)(a4 + 15), (unsigned __int8)*(BYTE*)0x7BD0483, *(BYTE*)0x7BD0484, v12, v13, v10);
		//v1 = *(BYTE *)(a4 + 15);
		v11 = pGetPreviewStruct(pPreviewThis(), *(BYTE *)(a4 + 15));
		if ( v11 )
		{
			*(WORD *)(v11 + 130) = *(WORD *)(a4 + 16);
			*(BYTE *)(v11 + 19) = sub_587380(*(BYTE *)(a4 + 18));
			sub_9CF1C0((char *)(v11 + 56), (const void *)(a4 + 5), 0xAu);
			*(BYTE *)(v11 + 66) = 0;
		}
		*(DWORD*)0x87935A4 = 53;
		v6 = (char *)sub_482B70();
		sub_668520((char *)sub_482B70());
		sub_4057B0((char *)sub_482B70() + 32632);
		result = sub_402AD0((char *)sub_482B70() + 36744);
	}
	else
	{
		result = *(BYTE *)(a4 + 4);
		if ( *(BYTE *)(a4 + 4) )
		{
			if ( *(BYTE *)(a4 + 4) == 2 )
			{
				result = sub_484A10(sub_482B70(), 55, 0);
			}
		}
		else
		{
			result = sub_484A10(sub_482B70(), 54, 0);
		}
	}
	return result;
}

void CameraChar(int a1, DWORD *a2)
{
	if ( pPlayerState == 4) //Select Character
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38f);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38f);
		*(float*)0xE61E3C = 20000.0f;
		//--
		*(float*)0x87933D0 = gSelectCharRamdon.RenderSelect.flt_87933D0;  		 //CameraAngleX
		*(float*)0x87933D4 = gSelectCharRamdon.RenderSelect.flt_87933D4;		 //CameraAngleY
		*(float*)0x87933D8 = gSelectCharRamdon.RenderSelect.flt_87933D8;		 //CameraAngleZ
		*(float*)0x87933DC = gSelectCharRamdon.RenderSelect.flt_87933DC;		 //CameraPosX
		*(float*)0x87933E0 = gSelectCharRamdon.RenderSelect.flt_87933E0;		 //CameraPosY
		*(float*)0x87933E4 = gSelectCharRamdon.RenderSelect.flt_87933E4;		 //CameraPosZ
		//--
		*(float*)0xE61E40 = 35.0f;
	}
}

void LoginScreenSS803(int a1, DWORD *a2)
{
	if ( pPlayerState == 2) //Select Server
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 33000.0;
		//--
		*(float*)0x87933D0 = gSelectCharRamdon.RenderSelectSrv.flt_87933D0;
		*(float*)0x87933D4 = gSelectCharRamdon.RenderSelectSrv.flt_87933D4;
		*(float*)0x87933D8 = gSelectCharRamdon.RenderSelectSrv.flt_87933D8;
		*(float*)0x87933DC = gSelectCharRamdon.RenderSelectSrv.flt_87933DC;
		*(float*)0x87933E0 = gSelectCharRamdon.RenderSelectSrv.flt_87933E0;
		*(float*)0x87933E4 = gSelectCharRamdon.RenderSelectSrv.flt_87933E4;
		//--
		*(float*)0xE61E40 = 35.0;
	}
}

void LogoMUm803()
{
	if ( pPlayerState == 2 )
	{
		glColor3f(1.0f, 1.0f, 1.0f);
		*(float*)0xE8CB18 = *(float*)0xE8CB18 + 0.01999999955296516;
		if ( *(float*)0xE8CB18 > 10.0 )
		*(float*)0xE8CB18 = 10.0;
		EnableAlphaBlend();
		float v25 = *(float*)0xE8CB18 - 0.300000011920929;
		float v24 = *(float*)0xE8CB18 - 0.300000011920929;
		float v23 = *(float*)0xE8CB18 - 0.300000011920929;
		float v22 = *(float*)0xE8CB18 - 0.300000011920929;
		glColor4f(v22, v23, v24, v25);
		RenderBitmap(531019, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		EnableAlphaTest(1);
		glColor4f(*(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18, *(float*)0xE8CB18);
		RenderBitmap(531018, 217.60001, 25.0, 204.8, 102.4, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
		//
		glColor4f(1.0, 1.0, 1.0, 1.0);
		glEnable(GL_TEXTURE_2D);
	}
}

void RenderInfomation803(int a1)
{
	LogoMUm803();	
	RenderInfomationR();
}


__declspec(naked) void SwitchCharacterView803()
{
	static float View = 33000.0f;
	static DWORD SwitchCharacter_buff = 0x004D87D4;
	_asm
	{
		FLD DWORD PTR DS:[View]
		FSTP DWORD PTR DS:[View]
		jmp [SwitchCharacter_buff]
	}
}

__declspec(naked) void GameProcessView803()
{
	static float View = 20000.0f;
	static DWORD GameProcess_buff = 0x004D8808;
	_asm
	{
		FLD DWORD PTR DS:[View]
		FSTP DWORD PTR DS:[View]
		jmp [GameProcess_buff]
	}
}

DWORD PlayerID_Offset803 = 0x005DB532; 
void __declspec(naked) PlayerID803()
{
	_asm
	{
		CMP DWORD PTR DS:[0xE609E8],0x2
		je ReturnLoad
		CMP DWORD PTR DS:[0xE609E8],0x4
		je ReturnLoad
		// ---
		ReturnLoad :
		// ---
		jmp PlayerID_Offset803
	}
}

int __cdecl RenderModelScale(int a1)
{
	int result; // eax@1
	float RenderSize; // eax@2
	float RenderMonk; // eax@3

	result = a1;

	if ( !*(BYTE *)(a1 + 15) )
	{
		if ( *(WORD *)(a1 + 268) != 4755
			&& *(WORD *)(a1 + 268) != 4757
			&& *(WORD *)(a1 + 268) != 4818
			&& *(WORD *)(a1 + 268) != 4823
			&& *(WORD *)(a1 + 268) != 4820
			&& *(WORD *)(a1 + 268) != 4825
			&& ((signed int)*(WORD *)(a1 + 268) < 4765 || (signed int)*(WORD *)(a1 + 268) > 4768) )
		{
			*(WORD *)(a1 + 232) = -1;
		}
		else
		{
			*(WORD *)(a1 + 232) = (unsigned __int8) sub_587500(*(BYTE *)(a1 + 19)) + 9389;
		}
		if ( pPlayerState == 4 )
		{
			if ( *(BYTE *)(a1 + 20) )
			{
				result = sub_405230(*(BYTE *)(a1 + 19));
				switch ( result )
				{
					case CLASS_WIZARD:
						result = a1;
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[0].Option1.CoordA;
					break;
					case CLASS_KNIGHT:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[1].Option1.CoordA;
					break;
					case CLASS_ELF:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[2].Option1.CoordA;
					break;
					case CLASS_MAGUMSA:
						result = a1;
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[3].Option1.CoordA;
					break;
					case CLASS_DARKLORD:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[4].Option1.CoordA;
					break;
					case CLASS_SUMMONER:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[5].Option1.CoordA;
					break;
					case CLASS_MONK:
						result = a1;
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[6].Option1.CoordA;
					break;
					default:
					return result;
				}
			}
			else
			{
				result = sub_405230(*(BYTE *)(a1 + 19));
				switch ( result )
				{
					case CLASS_WIZARD:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[0].Option1.CoordA;
					break;
					case CLASS_KNIGHT:
						result = a1;
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[1].Option1.CoordA;
					break;
					case CLASS_ELF:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[2].Option1.CoordA;
					break;
					case CLASS_MAGUMSA:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[3].Option1.CoordA;
					break;
					case CLASS_DARKLORD:
						result = a1;
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[4].Option1.CoordA;
					break;
					case CLASS_SUMMONER:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[5].Option1.CoordA;
					break;
					case CLASS_MONK:
						*(float *)(a1 + 872) = gSelectCharRamdon.RenderSelect.Size[6].Option1.CoordA;
					break;
					default:
					return result;
				}
			}
		}
		else if ( *(BYTE *)(a1 + 20) )
		{
			result = sub_405230(*(BYTE *)(a1 + 19));
			switch ( result )
			{
				case 0:
					*(float *)(a1 + 872) = 0.93000001;
					break;
				case 1:
					*(float *)(a1 + 872) = 0.93000001;
					break;
				case 2:
					result = a1;
					*(float *)(a1 + 872) = 0.86000001;
					break;
				case 3:
					*(float *)(a1 + 872) = 0.94999999;
					break;
				case 4:
					*(float *)(a1 + 872) = 0.92000002;
					break;
				case 5:
					result = a1;
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 6:
					*(float *)(a1 + 872) = 1.03;
					break;
				default:
					return result;
			}
		}
		else
		{
			result = sub_405230(*(BYTE *)(a1 + 19));
			switch ( result )
			{
				case 0:
					result = a1;
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 1:
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 2:
					*(float *)(a1 + 872) = 0.88;
					break;
				case 3:
					result = a1;
					*(float *)(a1 + 872) = 0.94999999;
					break;
				case 4:
					*(float *)(a1 + 872) = 0.92000002;
					break;
				case 5:
					*(float *)(a1 + 872) = 0.89999998;
					break;
				case 6:
					result = a1;
					*(float *)(a1 + 872) = 1.03;
					break;
				default:
					return result;
			}
		}
	}
	return result;
}

void MultiSelect::InitMultiChar()
{
	if(gProtect.m_MainInfo.SelectCharacterType == 5)
	{
		SetDword((LPVOID)0x004D6C2C, gSelectCharRamdon.RenderSelect.MapChar);		//Select Character ID MAPA
		SetCompleteHook(0xE9, 0x0063D130, &SelectCharacterCord);					//Coordenadas do Personagem
		SetCompleteHook(0xE9, 0x0063D3D0, &SelectCreateCharCoord);					//Coordenadas do Personagem
		SetCompleteHook(0xE8, 0x004D712A, &CameraChar);								//Posições do Cenário SelectChar
		SetCompleteHook(0xE9, 0x0057F020, &RenderModelScale);						//Tamanho do Personagem
		
		SetOp((LPVOID)0x004D87C8, (LPVOID)SwitchCharacterView803, ASM::JMP);
		SetOp((LPVOID)0x004D87FC, (LPVOID)GameProcessView803, ASM::JMP);
		SetOp((LPVOID)0x005DB52B, (LPVOID)PlayerID803, ASM::JMP);
	}
	
	if(gProtect.m_MainInfo.SelectServerType == 5)
	{
		SetDword((LPVOID)0x004D75F0, gSelectCharRamdon.RenderSelectSrv.MapServ);	//Select Server ID MAPA
		SetCompleteHook(0xE8, 0x004D76FB, &LoginScreenSS803);						//Posições do Cenário Select Server
		SetCompleteHook(0xE8, 0x004D79C3, &LoginScreenSS803);						//Posições do Cenário Select Server
	
		SetCompleteHook(0xE8, 0x004D7EB1,&RenderInfomation803);						//Refeito a logo no servidor
	}
}