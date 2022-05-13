#include "stdafx.h"
#include "CScene.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "Protect.h"
#include "zzzMathLib.h"

void LoginScreenSS801(int a1, DWORD *a2)
{
	if ( World == 93) //Select Server
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 33000.0;
		*(float*)0x87933D0 = -84.0;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -45.0;
		*(float*)0x87933DC = 24475.79687;
		*(float*)0x87933E0 = 7581.581055;
		*(float*)0x87933E4 = 1834.539917;	
		*(float*)0xE61E40 = 35.0;
	}
}

void LoginScreenSC801(int a1, DWORD *a2)
{
	if ( SceneFlag == 4) //Select Character
	{
		SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		*(float*)0xE61E3C = 20000.0;
		*(float*)0x87933D0 = -84.5;
		*(float*)0x87933D4 = 0.0;
		*(float*)0x87933D8 = -80.0;
		*(float*)0x87933DC = 15215.08887;
		*(float*)0x87933E0 = 12186.53613;
		*(float*)0x87933E4 = 495.500061;	
		*(float*)0xE61E40 = 35.0;	  
	}
}

void RenderSSCObjectVisual801(int a1, int a2)
{
vec3_t Bone;
vec3_t Color;
vec3_t WorldPos;

//Select Server
	if (World == 93)
	{  
		switch ( *(DWORD *)(a1 + 48) )   
		{
			case 1:
			{
			BeginRender(1.0);
			*(DWORD *)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
			float v552 = 4000;
			float v551 = ((int) (v552 - *(float*)0x5EF5A1C * 0.75f) % 4001) * 0.0002500000118743628;
			RenderMesh(a2,
			  0,
			  66,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  v551,
			  -1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
			}
			break;

			case 5:
			{
			BeginRender(1.0);
			*(BYTE*)(a2 + 136) = 0;
            *(float *)(a2 + 72) = 0.44705882352;
            *(float *)(a2 + 76) = 0.44705882352;
            *(float *)(a2 + 80) = 0.22745098039;
			RenderMesh(a2,
			  0,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  23,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  23,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  24,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  25,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  26,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  27,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			RenderMesh(a2,
			  28,
			  68,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  *(float *)(a1 + 108),
			  32042);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
			float v409 = (double)(rand() % 10) / 20.0 + 1.399999976158142;
			float v19 = v409 - 0.300000011920929;
			Vector( 0.0, 0.0, 0.0, WorldPos);
			//TransformPosition(a2, (int)&BoneTransform + 0x5D0, WorldPos, Bone, 0);
			TransformPosition(a2, Joint(37), WorldPos, Bone, 0);
			Vector( 1.0, 0.30000001, 0.0, Color);		
			CreateSprite(32114, Bone, v409, Color, a1, 0.0, 0);
            CreateSprite(32114, Bone, v19, Color, a1, 0.0, 0);
			v409 = (double)(rand() % 10) / 20.0 + 1.0;
			float v20 = v409 + 0.300000011920929;
			CreateSprite(32002, Bone, v20, Color, a1, 0.0, 0);
			v409 = (double)(rand() % 8) / 20.0 + 0.4000000059604645;
			CreateSprite(32114, Bone, v409, Color, a1, 0.0, 0);
			float v21 = v409 - 0.2000000029802322;
            CreateSprite(32114, Bone, v21, Color, a1, 0.0, 0);
			}
			break;
			
			case 38:
			{
			*(DWORD *)(a1 + 60) = -2;
			Vector( 0.020, 0.020, 0.050, Color);
			CreateParticle(32146, a1 + 252, a1 + 264, Color, 1,*(float *)(a1 + 96), a2);
			}
			break;
			
			case 54:
			{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 2) )	
				{
				Vector( 1.0, 1.0, 1.0, Color);			
				CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;
			}
		}

//Select Character
	if (World == 91 || World == 92)
	{  
		switch ( *(DWORD *)(a1 + 48) )   
		{
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:
			{
			*(DWORD *)(a1 + 60) = -2;
			}
			break;

			case 24:
			case 25:
			case 26:
			{
			BeginRender(1.0);
			*(DWORD *)(a1 + 60) = -2;
			*(BYTE*)(a2 + 136) = 0;
		    float v552 = 2000;
		    float v551 = ((int)(v552 - timeGetTime()) % 2001) * 0.0005000000237487257;
			RenderMesh(a2,
			  0,
			  66,
			  *(float *)(a1 + 152),
			  *(DWORD *)(a1 + 68),
			  *(float *)(a1 + 100),
			  *(float *)(a1 + 104),
			  v551,
			  -1);
			*(BYTE*)(a2 + 136) = -1;
			EndRender();
			}
			break;

			case 31:
			{
			Vector( 0.0, 0.0, 0.0, WorldPos);
            TransformPosition(a2, (int)&BoneTransform, WorldPos, Bone, 0);
			Vector( 0.98000002, 0.94, 0.94, Color);
            CreateSprite(32604, Bone, 1.0, Color, a1, 0.0, 0);
			Vector( 0.77999997, 0.44, 0.75, Color);
			TransformPosition(a2, (int)&BoneTransform + 0x30, WorldPos, Bone, 0);
            CreateSprite(32604, Bone, 1.2, Color, a1, 0.0, 0);	
			Vector( 0.57999998, 0.07, 0.56, Color);
			TransformPosition(a2, (int)&BoneTransform + 0x60, WorldPos, Bone, 0);
            CreateSprite(32604, Bone, 0.80000001, Color, a1, 0.0, 0);
			}
			break;

			case 38:
			{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 6) )	
				{
				Vector( 0.02, 0.02, 0.050000001, Color);			
				CreateParticle(32146, a1 + 252, a1 + 264, Color, 20, *(float *)(a1 + 96), 0);
				}
			}
			break;

			case 39:
			{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 100) )	
				{
				Vector( 0.0, 0.0, 0.0, WorldPos);
				TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
				Vector( 0.02, 0.02, 0.050000001, Color);			
				CreateEffect2(700, Bone, a1 + 264, Color, 0, a1, -1, 0, 0, 0, 0.0, -1);
				}
			}
			break;

			case 40:
			{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 200) )	
				{
				Vector( 0.0, 0.0, 0.0, WorldPos);
				TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
				Vector( 0.02, 0.02, 0.050000001, Color);			
				CreateEffect2(701, Bone, a1 + 264, Color, 1, a1, -1, 0, 0, 0, 0.0, -1);
				}
			}
			break;

			case 54:
			{
			*(DWORD *)(a1 + 60) = -2;
			if ( !(rand() % 2) )	
				{
				Vector( 1.0, 1.0, 1.0, Color);			
				CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;

			case 55:
			{
			*(DWORD *)(a1 + 60) = -2;
			Vector( 1.0, 1.0, 1.0, Color);			
			CreateParticle(32289, a1 + 252, a1 + 264, Color, 14, *(float *)(a1 + 96) + *(float *)(a1 + 96), 0);
			}
			break;

			case 56:
			{
			*(DWORD *)(a1 + 60) = -2;
			Vector( 1.0, 1.0, 1.0, Color);	
			if ( !(rand() % 3) )
				{		
				CreateParticle(32288, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;

			case 73:
			{
			Vector( 0.0, 0.0, 0.0, WorldPos);
			TransformPosition(a2, Joint(1), WorldPos, Bone, 0);
			Vector( 0.5, 1.0, 0.98000002, Color);
			float v51 = ((int) timeGetTime() % 3600) * 0.1000000014901161;
			float v32 = -v51;
			float v50 = ((int) timeGetTime() % 30) / 90.0;
			float v33 = v50 + 1.200000047683716;
			CreateSprite(32114, Bone, v33, Color, a1, v32, 0);
			CreateSprite(32779, Bone, 0.20, Color, a1, 0.0, 0);
			if ( !((int) timeGetTime() % 3) )
			{
			Vector( 1.0, 1.0, 1.0, Color);
			v50 = *(float *)(a1 + 96) * 1.799999952316284;
			float v34 = v50;
			CreateParticle2(32284, Bone, a1 + 264, Color, 0, v34, 0);
			}
			}
			break;

			case 80:
			{
			*(DWORD *)(a1 + 60) = -2;
			Vector( 0.98000002, 0.89999998, 0.89999998, Color);	
			if ( !(rand() % 8) )
				{		
				CreateParticle(32101, a1 + 252, a1 + 264, Color, 69, *(float *)(a1 + 96), 0);
				}
			}
			break;

			}
		}
//
	RenderCryingWolf2ndObjectVisual(a1, a2);
}

__declspec(naked) void SwitchCharacterView801()
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

__declspec(naked) void GameProcessView801()
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

DWORD PlayerID_Offset801 = 0x005DB532; 
void __declspec(naked) PlayerID801()
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
		jmp PlayerID_Offset801
	}
}

void LogoMUm801()
{
  if ( SceneFlag == 2 )
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

void RenderInfomation801(int a1)
{
	LogoMUm801();	
	RenderInfomationR();
}

void SelectPjCord01801(int a1)
{
  int v1; // ST1C_4@11
  char v2; // ST14_1@12
  int v3; // eax@12
  DWORD result; // eax@12
  int v5; // [sp+14h] [bp-20h]@5
  int v6; // [sp+18h] [bp-1Ch]@5
  float v7; // [sp+1Ch] [bp-18h]@5
  float v8; // [sp+20h] [bp-14h]@0
  float v9; // [sp+24h] [bp-10h]@0
  signed int i; // [sp+28h] [bp-Ch]@3
  signed int v11; // [sp+30h] [bp-4h]@3

  sub_63CB40();
  sub_4D5130(*(BYTE *)(a1 + 4));
  if ( SceneFlag == 4 )
  World = 92;
  v11 = 8;
  for ( i = 0; i < *(BYTE *)(a1 + 6); ++i )
  {
    v5 = v11 + a1;
    v6 = (unsigned __int8)sub_587380(*(BYTE *)(v11 + a1 + 15));
    v7 = 0.0;
    switch ( *(BYTE *)(v11 + a1) )
    {		
      case 0:
        v8 = 13379.0;
        v9 = 11958.0;
        v7 = 115.0;
        break;
      case 1:
        v8 = 13367.0;
        v9 = 12229.0;
        v7 = 90.0;
        break;
      case 2:
        v8 = 13384.0;
        v9 = 12503.0;
        v7 = 75.0;
        break;
      case 3:
        v8 = 13468.0;
        v9 = 12764.0;
        v7 = 60.0;
        break;
      case 4:
        v8 = 13566.0;
        v9 = 13018.0;
        v7 = 35.0;
        break;
      default:
        break;
    }
    v1 = sub_586DA0(*(BYTE *)v5, v6, 0, v8, v9, v7);
    *(WORD *)(v1 + 130) = *(WORD *)(v5 + 12);
    *(BYTE *)(v1 + 21) = *(BYTE *)(v5 + 14);
    sub_9CF1C0_sub(v1 + 56, v5 + 1, 10);
    *(BYTE *)(v1 + 66) = 0;
    sub_57FD90(*(BYTE *)v5, v5 + 16, 0, 0);
    *(BYTE *)(v1 + 24) = *(BYTE *)(v5 + 33);
    v11 += 34;
  }
  dword_87935A4 = 51;
  pWarehouseExSet(pWarehouseExThis(pWindowThis()),*(BYTE *)(a1 + 7));
  result = GetTickCount();
  dword_E8CB30 = result;
  return;
}

void SelectPjCord02801(int a1)
{
  float v1; // ST14_4@8
  int v2; // eax@8
  char *v3; // ST24_4@10
  int result; // eax@10
  float v5; // [sp+1Ch] [bp-14h]@2
  int v6; // [sp+20h] [bp-10h]@8
  float v7; // [sp+24h] [bp-Ch]@0
  float v8; // [sp+28h] [bp-8h]@0

  if ( *(BYTE *)(a1 + 4) == 1 )
  {
    v5 = 0.0;
    switch ( *(BYTE *)(a1 + 15) )
    {
      case 0:
        v7 = 13379.0;
        v8 = 11958.0;
        v5 = 115.0;
        break;
      case 1:
        v7 = 13367.0;
        v8 = 12229.0;
        v5 = 90.0;
        break;
      case 2:
        v7 = 13384.0;
        v8 = 12503.0;
        v5 = 75.0;
        break;
      case 3:
        v7 = 13468.0;
        v8 = 12764.0;
        v5 = 60.0;
        break;
      case 4:
        v7 = 13566.0;
        v8 = 13018.0;
        v5 = 35.0;
        break;
      default:
        break;
    }
    sub_57D760(*(BYTE *)(a1 + 15));
    sub_586DA0(*(BYTE *)(a1 + 15), (unsigned __int8)byte_7BD0483, byte_7BD0484, v7, v8, v5);
    v1 = *(BYTE *)(a1 + 15);
    v6 = pGetPreviewStruct(pPreviewThis(), v1);
    if ( v6 )
    {
      *(WORD *)(v6 + 130) = *(WORD *)(a1 + 16);
      *(BYTE *)(v6 + 19) = sub_587380(*(BYTE *)(a1 + 18));
      sub_9CF1C0_sub(v6 + 56, a1 + 5, 10);
      *(BYTE *)(v6 + 66) = 0;
    }
    dword_87935A4 = 53;
    v3 = (char *)sub_482B70();
    sub_668520(v3);
    sub_4057B0(v3 + 32632);
    result = sub_402AD0(v3 + 36744);
  }
  else
  {
    result = *(BYTE *)(a1 + 4);
    if ( *(BYTE *)(a1 + 4) )
    {
      if ( *(BYTE *)(a1 + 4) == 2 )
      {
        result = sub_484A10(sub_482B70(), 55, 0);
      }
    }
    else
    {
      result = sub_484A10(sub_482B70(), 54, 0);
    }
  }
  return;
}

void CScene803()
{
	SetDword((LPVOID)0x004D75F0, 93);//Select Server

	SetCompleteHook(0xE8, 0x004D76FB, &LoginScreenSS801);//Select Server
	SetCompleteHook(0xE8, 0x004D79C3, &LoginScreenSS801);//Select Server

	SetDword((PVOID)(0x004D7A0E), 480);//Select Server
	SetByte((PVOID)(0x004D7A18), 0);//Select Server

	SetCompleteHook(0xE8, 0x005EDDA9,&RenderSSCObjectVisual801);

	SetCompleteHook(0xE8, 0x004D7EB1,&RenderInfomation801);

}
__declspec(naked) void CSelectCharacterCordPJ1()
{
	static float D41DCC = 13629.000f; //8008.000
	static float D41DC8 = 12339.000f; //18885.00
	static float D27AE0 = 90.000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void CSelectCharacterCordPJ21()
{
	static float D41DCC = 13629.000f; //8008.000
	static float D41DC8 = 12339.00f; //18885.00
	static float D27AE0 = 90.0000f; //115.0000
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ1SS()
{
	static float D41DCC = 13379.0f;
	static float D41DC8 = 11958.0f;
	static float D27AE0 = 115.0f;
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D1E9;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ21SS()
{
	static float D41DCC = 13379.0f;
	static float D41DC8 = 11958.0f;
	static float D27AE0 = 115.0f;
	static DWORD SelectCharacterCordPJ1_buff = 0x0063D42A;
	_asm
	{
	FLD DWORD PTR DS:[D41DCC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27AE0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ1_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ2SS()
{
	static float D41DC4 = 13367.0f;
	static float D41DC0 = 12229.0f;
	static float D254C0 = 90.0f;
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D206;
	_asm
	{
	FLD DWORD PTR DS:[D41DC4]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DC0]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D254C0]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ22SS()
{
	static float D41DC4 = 13367.0f;
	static float D41DC0 = 12229.0f;
	static float D254C0 = 90.0f;
	static DWORD SelectCharacterCordPJ2_buff = 0x0063D447;
	_asm
	{
	FLD DWORD PTR DS:[D41DC4]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DC0]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D254C0]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ2_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ3SS()
{
	static float D41DBC = 13384.0f;
	static float D41DB8 = 12503.0f;
	static float D2B954 = 75.0f;
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D223;
	_asm
	{
	FLD DWORD PTR DS:[D41DBC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DB8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D2B954]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ23SS()
{
	static float D41DBC = 13384.0f;
	static float D41DB8 = 12503.0f;
	static float D2B954 = 75.0f;
	static DWORD SelectCharacterCordPJ3_buff = 0x0063D464;
	_asm
	{
	FLD DWORD PTR DS:[D41DBC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DB8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D2B954]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ3_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ4SS()
{
	static float D41DB4 = 13468.0f;
	static float D41DB0 = 12764.0f;
	static float D2577C = 60.0f;
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D240;
	_asm
	{
	FLD DWORD PTR DS:[D41DB4]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DB0]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D2577C]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ24SS()
{
	static float D41DB4 = 13468.0f;
	static float D41DB0 = 12764.0f;
	static float D2577C = 60.0f;
	static DWORD SelectCharacterCordPJ4_buff = 0x0063D481;
	_asm
	{
	FLD DWORD PTR DS:[D41DB4]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DB0]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D2577C]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ4_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ5SS()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 35.0f;
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D25D;
	_asm
	{
	FLD DWORD PTR DS:[D41DAC]
	FSTP DWORD PTR SS:[EBP-0x14]
	FLD DWORD PTR DS:[D41DA8]
	FSTP DWORD PTR SS:[EBP-0x10]
	FLD DWORD PTR DS:[D27BFC]
	FSTP DWORD PTR SS:[EBP-0x18]
	jmp [SelectCharacterCordPJ5_buff]
	}
}

__declspec(naked) void SelectCharacterCordPJ25SS()
{
	static float D41DAC = 13566.0f;
	static float D41DA8 = 13018.0f;
	static float D27BFC = 35.0f;
	static DWORD SelectCharacterCordPJ5_buff = 0x0063D49E;
	_asm
	{
	FLD DWORD PTR DS:[D41DAC]
	FSTP DWORD PTR SS:[EBP-0xC]
	FLD DWORD PTR DS:[D41DA8]
	FSTP DWORD PTR SS:[EBP-0x8]
	FLD DWORD PTR DS:[D27BFC]
	FSTP DWORD PTR SS:[EBP-0x14]
	jmp [SelectCharacterCordPJ5_buff]
	}
}

void SScene803()
{
	if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
	{
		SetDword((LPVOID)0x004D6C2C, 92);//Select Character
		SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterCordPJ1SS, ASM::JMP);
		SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterCordPJ21SS, ASM::JMP);
	
		SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterCordPJ2SS, ASM::JMP);
		SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterCordPJ22SS, ASM::JMP);
	
		SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterCordPJ3SS, ASM::JMP);
		SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterCordPJ23SS, ASM::JMP);
	
		SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterCordPJ4SS, ASM::JMP);
		SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterCordPJ24SS, ASM::JMP);
	
		SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterCordPJ5SS, ASM::JMP);
		SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
		SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterCordPJ25SS, ASM::JMP);
	}
	else
	{
		SetDword((LPVOID)0x004D6C2C, 91);//Select Character s13
		SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
        SetOp((LPVOID)0x0063D1CE, (LPVOID)CSelectCharacterCordPJ1, ASM::JMP);
	    SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
        SetOp((LPVOID)0x0063D40F, (LPVOID)CSelectCharacterCordPJ21, ASM::JMP);
	}

	SetCompleteHook(0xE8, 0x004D712A, &LoginScreenSC801);//Select Character
	SetDword((PVOID)(0x004D7179), 480);//Select Character
	SetByte((PVOID)(0x004D7183), 0);//Select Character

	SetCompleteHook(0xE8, 0x005EDDA9,&RenderSSCObjectVisual801);

	SetOp((LPVOID)0x004D87C8, (LPVOID)SwitchCharacterView801, ASM::JMP);
	SetOp((LPVOID)0x004D87FC, (LPVOID)GameProcessView801, ASM::JMP);
	SetOp((LPVOID)0x005DB52B, (LPVOID)PlayerID801, ASM::JMP);
}