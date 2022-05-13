#include "stdafx.h"
#include "CScene.h"
#include "Defines.h"
#include "TMemory.h"
#include "Util.h"
#include "Interface.h"
#include "zzzMathLib.h"
#include "Protect.h"
#include "SelectServerS2.h"
#include "SceneSystemS0.h"

void LoginScreenS0(int a1, DWORD *a2)
{
		if ( World == 94) /*Select Server*/
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

		if (SceneFlag == 4) /*Select Character*/
		{		  
            SetFloat((PVOID)(0x005DB53F), -2.014084447E38);
		    SetFloat((PVOID)(0x005DB55D), -2.70652875E38);
		    *(float*)0xE61E3C = 20000.0;
		    *(float*)0x87933D0 = -84.5;
		    *(float*)0x87933D4 = 0.0;
		    *(float*)0x87933D8 = -75.0;
		    *(float*)0x87933DC = 9758.9297;
		    *(float*)0x87933E0 = 18913.109;
		    *(float*)0x87933E4 = 675.0;
		    *(float*)0xE61E40 = 35.0;
		}
}

void RenderSSCObjectVisualS0(int a1, int a2){
	vec3_t Bone;
	vec3_t Color;
	vec3_t WorldPos;
    /*Select Server*/
	    if (World == 94)
		{  
		switch ( *(DWORD *)(a1 + 48) )   {
			case 1:{
				BeginRender(1.0);
				*(DWORD *)(a1 + 60) = -2;
				*(BYTE*)(a2 + 136) = 0;
				float v552 = 4000;
				float v551 = ((int) (v552 - timeGetTime() * 0.75f) % 4001) * 0.0002500000118743628;
				RenderMesh(a2,0,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),v551,-1);
				*(BYTE*)(a2 + 136) = -1;
				EndRender();
			}
			break;
			case 5:{
				BeginRender(1.0);
				*(BYTE*)(a2 + 136) = 0;
       	        *(float *)(a2 + 72) = 0.80000001;
       	        *(float *)(a2 + 76) = 0.69999999;
       		    *(float *)(a2 + 80) = 0.30000001;
				RenderMesh(a2,0,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,23,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
		    	RenderMesh(a2,23,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,24,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
		     	RenderMesh(a2,24,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
		    	RenderMesh(a2,25,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
			    RenderMesh(a2,25,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,26,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
 	    		RenderMesh(a2,26,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
		    	RenderMesh(a2,27,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
		        RenderMesh(a2,27,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    RenderMesh(a2,28,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),-1);
	    		RenderMesh(a2,28,68,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),*(float *)(a1 + 108),32042);
			    *(BYTE*)(a2 + 136) = -1;
			    EndRender();
			    float v409 = (double)(rand() % 10) / 20.0 + 1.399999976158142;
			    float v19 = v409 - 0.300000011920929;
			    Vector( 0.0, 0.0, 0.0, WorldPos);
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
			case 38:{
			    *(DWORD *)(a1 + 60) = -2;
			    if ( !(rand() % 6) )	{		
		    		Vector( 0.020, 0.020, 0.050, Color);			
			    	CreateParticle(32146, a1 + 252, a1 + 264, Color, 20,*(float *)(a1 + 96), a2);
				}
			}
			break;
			case 54:{
		    	*(DWORD *)(a1 + 60) = -2;
		    	if ( !(rand() % 2) )	{
	    			Vector( 0.22, 0.15000001, 0.15000001, Color);			
		    		CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;
			}
	}
    /*Select Character*/
	if (World == 76)
	{  
		switch ( *(DWORD *)(a1 + 48) )   {
			case 13:
			case 14:
			case 15:
			case 16:
			case 17:{
	    		*(DWORD *)(a1 + 60) = -2;
			}
			break;
			case 24:
			case 25:
			case 26:{
		    	BeginRender(1.0);
		    	*(DWORD *)(a1 + 60) = -2;
	    		*(BYTE*)(a2 + 136) = 0;
	    	    float v552 = 2000;
    		    float v551 = ((int)(v552 - timeGetTime()) % 2001) * 0.0005000000237487257;
    			RenderMesh(a2,0,66,*(float *)(a1 + 152),*(DWORD *)(a1 + 68),*(float *)(a1 + 100),*(float *)(a1 + 104),v551,-1);
			    *(BYTE*)(a2 + 136) = -1;
			    EndRender();
			}
			break;
			case 31:{
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
			case 38:{
		    	*(DWORD *)(a1 + 60) = -2;
		    	if ( !(rand() % 6) )	{
    				Vector( 0.02, 0.02, 0.050000001, Color);			
	    			CreateParticle(32146, a1 + 252, a1 + 264, Color, 20, *(float *)(a1 + 96), 0);
				}
			}
			break;
			case 39:{
	    		*(DWORD *)(a1 + 60) = -2;
		    	if ( !(rand() % 100) )	{
    				Vector( 0.0, 0.0, 0.0, WorldPos);
	    			TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
		    		Vector( 0.02, 0.02, 0.050000001, Color);			
			    	CreateEffect2(700, Bone, a1 + 264, Color, 0, a1, -1, 0, 0, 0, 0.0, -1);
				}
			}
			break;
			case 40:{
	    		*(DWORD *)(a1 + 60) = -2;
		    	if ( !(rand() % 200) )	{
    				Vector( 0.0, 0.0, 0.0, WorldPos);
	    			TransformPosition(a2, Joint(0), WorldPos, Bone, 0);
		    		Vector( 0.02, 0.02, 0.050000001, Color);			
			    	CreateEffect2(701, Bone, a1 + 264, Color, 1, a1, -1, 0, 0, 0, 0.0, -1);
				}
			}
			break;
			case 54:{
    			*(DWORD *)(a1 + 60) = -2;
	    		if ( !(rand() % 2) )	{
    				Vector( 1.0, 1.0, 1.0, Color);			
	    			CreateParticle(32287, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;
			case 55:{
	    		*(DWORD *)(a1 + 60) = -2;
	    		Vector( 1.0, 1.0, 1.0, Color);			
	    		CreateParticle(32289, a1 + 252, a1 + 264, Color, 14, *(float *)(a1 + 96) + *(float *)(a1 + 96), 0);
			}
			break;
			case 56:{
			    *(DWORD *)(a1 + 60) = -2;
    			Vector( 1.0, 1.0, 1.0, Color);	
	    		if ( !(rand() % 3) ){		
    				CreateParticle(32288, a1 + 252, a1 + 264, Color, 2, *(float *)(a1 + 96), 0);
				}
			}
			break;
			case 73:{
    			Vector( 0.0, 0.0, 0.0, WorldPos);
	    		TransformPosition(a2, Joint(1), WorldPos, Bone, 0);
		    	Vector( 0.5, 1.0, 0.98000002, Color);
	    		float v51 = ((int) timeGetTime() % 3600) * 0.1000000014901161;
	    		float v32 = -v51;
	    		float v50 = ((int) timeGetTime() % 30) / 90.0;
	    		float v33 = v50 + 1.200000047683716;
	    		CreateSprite(32114, Bone, v33, Color, a1, v32, 0);
    			CreateSprite(32779, Bone, 0.20, Color, a1, 0.0, 0);
    			if ( !((int) timeGetTime() % 3) ){
    	    		Vector( 1.0, 1.0, 1.0, Color);
	        		v50 = *(float *)(a1 + 96) * 1.799999952316284;
		        	float v34 = v50;
			        CreateParticle2(32284, Bone, a1 + 264, Color, 0, v34, 0);
			    }
			}
			break;
			case 80:{
	    		*(DWORD *)(a1 + 60) = -2;
	    		Vector( 0.98000002, 0.89999998, 0.89999998, Color);	
		    	if ( !(rand() % 8) ){		
		    		CreateParticle(32101, a1 + 252, a1 + 264, Color, 69, *(float *)(a1 + 96), 0);
				}
			}
			break;
		}
	}
	RenderCryingWolf2ndObjectVisual(a1, a2);
}

__declspec(naked) void SwitchCharacterViewS0()
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

__declspec(naked) void GameProcessViewS0()
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

DWORD PlayerIDS0_Offset = 0x005DB532;
void __declspec(naked) PlayerIDS0()
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
		jmp PlayerIDS0_Offset
	}
}

__declspec(naked) void SelectCharacterS0CordPJ1()
{
	static float D41DCC = 8008.0f; //8008.000
	static float D41DC8 = 18960.0f; //18885.00
	static float D27AE0 = 55.0f; //115.0000
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

__declspec(naked) void SelectCharacterS0CordPJ21()
{
	static float D41DCC = 8008.0f; //8008.000
	static float D41DC8 = 18960.0f; //18885.00
	static float D27AE0 = 55.0f; //115.0000
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

__declspec(naked) void SelectCharacterS0CordPJ2()
{
	static float D41DC4 = 7986.0f; //7986.000
	static float D41DC0 = 19160.0f; //19145.00
	static float D254C0 = 50.0f; //90.00000
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

__declspec(naked) void SelectCharacterS0CordPJ22()
{
	static float D41DC4 = 7986.0f; //7986.000
	static float D41DC0 = 19160.0f; //19145.00
	static float D254C0 = 50.0f; //90.00000
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

__declspec(naked) void SelectCharacterS0CordPJ3()
{
	static float D41DBC = 8046.0f; //8046.000
	static float D41DB8 = 19360.0f; //19400.00
	static float D2B954 = 75.0f; //75.00000
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

__declspec(naked) void SelectCharacterS0CordPJ23()
{
	static float D41DBC = 8046.0f; //8046.000
	static float D41DB8 = 19360.0f; //19400.00
	static float D2B954 = 75.0f; //75.00000
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

__declspec(naked) void SelectCharacterS0CordPJ4()
{
	static float D41DB4 = 8133.0f; //8133.000
	static float D41DB0 = 19560.0f; //19645.00
	static float D2577C = 100.0f; //60.00000
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

__declspec(naked) void SelectCharacterS0CordPJ24()
{
	static float D41DB4 = 8133.0f; //8133.000
	static float D41DB0 = 19560.0f; //19645.00
	static float D2577C = 100.0f; //60.00000
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

__declspec(naked) void SelectCharacterS0CordPJ5()
{
	static float D41DAC = 8153.0f; //8282.000
	static float D41DA8 = 19760.0f; //19845.00
	static float D27BFC = 110.0f; //35.00000
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

__declspec(naked) void SelectCharacterS0CordPJ25()
{
	static float D41DAC = 8153.0f; //8282.000
	static float D41DA8 = 19760.0f; //19845.00
	static float D27BFC = 110.0f; //35.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ1()
{
	static float D41DCC = 8172.84083f; //8008.000
	static float D41DC8 = 19265.57287f; //18885.00
	static float D27AE0 = 90.0f; //115.0000
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

__declspec(naked) void SelectCharacterS13S0CordPJ21()
{
	static float D41DCC = 8172.84083f; //8008.000
	static float D41DC8 = 19265.57287f; //18885.00
	static float D27AE0 = 90.0f; //115.0000
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

__declspec(naked) void SelectCharacterS13S0CordPJ2()
{
	static float D41DC4 = 38008.0f; //7986.000
	static float D41DC0 = 38008.0f; //19145.00
	static float D254C0 = 50.0f; //90.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ22()
{
	static float D41DC4 = 38008.0f; //7986.000
	static float D41DC0 = 38008.0f; //19145.00
	static float D254C0 = 50.0f; //90.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ3()
{
	static float D41DBC = 38008.0f; //8046.000
	static float D41DB8 = 38008.0f; //19400.00
	static float D2B954 = 75.0f; //75.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ23()
{
	static float D41DBC = 38008.0f; //8046.000
	static float D41DB8 = 38008.0f; //19400.00
	static float D2B954 = 75.0f; //75.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ4()
{
	static float D41DB4 = 38008.0f; //8133.000
	static float D41DB0 = 38008.0f; //19645.00
	static float D2577C = 100.0f; //60.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ24()
{
	static float D41DB4 = 38008.0f; //8133.000
	static float D41DB0 = 38008.0f; //19645.00
	static float D2577C = 100.0f; //60.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ5()
{
	static float D41DAC = 38008.0f; //8282.000
	static float D41DA8 = 38008.0f; //19845.00
	static float D27BFC = 110.0f; //35.00000
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

__declspec(naked) void SelectCharacterS13S0CordPJ25()
{
	static float D41DAC = 38008.0f; //8282.000
	static float D41DA8 = 38008.0f; //19845.00
	static float D27BFC = 110.0f; //35.00000
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

__declspec(naked) void SelectCharacterSize1S0()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F165;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[ECX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize2S0()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F154;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EAX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize3S0()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F176;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EDX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize4S0()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F143;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EDX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize5S0()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F187;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[EAX+0x368]
		JMP [Bufferx]

	}
}

__declspec(naked) void SelectCharacterSize6S0()
{
	static float D27AF0 = 1.7f;
	static DWORD Bufferx = 0x0057F198;
	_asm
	{
		FLD DWORD PTR DS:[D27AF0]
		FSTP DWORD PTR DS:[ECX+0x368]
		JMP [Bufferx]

	}
}
__declspec(naked) void SelectCharacterSize7S0()
{
	static float D2B994 = 1.85f;
	static DWORD Bufferx = 0x0057F198;
	_asm
	{
		FLD DWORD PTR DS:[D2B994]
		FSTP DWORD PTR DS:[EDX+0x368]
		JMP [Bufferx]

	}
}

void CSceneS0()
{
	MemorySet(0x005B993A,0x90,0x5);
	SetCompleteHook(0xE8, 0x005EDDA9,&RenderSSCObjectVisualS0);

	if(gProtect.m_MainInfo.SelectServerType == 1)
	{
	/*Select Server*/
		SetDword((LPVOID)0x004D75F0, 94);//Select Server
		SetCompleteHook(0xE8, 0x004D76FB, &LoginScreenS0);//Select Server
	    SetCompleteHook(0xE8, 0x004D79C3, &LoginScreenS0);//Select Server
		SetDword((PVOID)(0x004D7A0E), 480);//Select Server
	    SetByte((PVOID)(0x004D7A18), 0);//Select Server
	}
	
	if(gProtect.m_MainInfo.SelectCharacterType == 1)
	{
	/*Select Character*/
		SetDword((LPVOID)0x004D6C2C, 76);
		SetCompleteHook(0xE8, 0x004D712A, &LoginScreenS0);
		SetDword((PVOID)(0x004D7179), 480);
		SetByte((PVOID)(0x004D7183), 0);
		//-
		SetOp((LPVOID)0x004D87C8, (LPVOID)SwitchCharacterViewS0, ASM::JMP);
		SetOp((LPVOID)0x004D87FC, (LPVOID)GameProcessViewS0, ASM::JMP);
		SetOp((LPVOID)0x005DB52B, (LPVOID)PlayerIDS0, ASM::JMP);

		SetOp((LPVOID)0x0057F159, (LPVOID)SelectCharacterSize1S0, ASM::JMP);
		SetOp((LPVOID)0x0057F148, (LPVOID)SelectCharacterSize2S0, ASM::JMP);
		SetOp((LPVOID)0x0057F16A, (LPVOID)SelectCharacterSize3S0, ASM::JMP);
		SetOp((LPVOID)0x0057F137, (LPVOID)SelectCharacterSize4S0, ASM::JMP);
		SetOp((LPVOID)0x0057F17B, (LPVOID)SelectCharacterSize5S0, ASM::JMP);
		SetOp((LPVOID)0x0057F18C, (LPVOID)SelectCharacterSize6S0, ASM::JMP);
		SetOp((LPVOID)0x0057F19D, (LPVOID)SelectCharacterSize7S0, ASM::JMP);

		if(gProtect.m_MainInfo.SelectCharacterSystem == 0)
		{
			SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterS0CordPJ1, ASM::JMP);
			SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterS0CordPJ21, ASM::JMP);
	
			SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterS0CordPJ2, ASM::JMP);
			SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterS0CordPJ22, ASM::JMP);
	
			SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterS0CordPJ3, ASM::JMP);
			SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterS0CordPJ23, ASM::JMP);
	
			SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterS0CordPJ4, ASM::JMP);
			SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterS0CordPJ24, ASM::JMP);
	
			SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterS0CordPJ5, ASM::JMP);
			SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterS0CordPJ25, ASM::JMP);
		}
		else
		{
			SetRange((LPVOID)0x0063D1CE, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D1CE, (LPVOID)SelectCharacterS13S0CordPJ1, ASM::JMP);
			SetRange((LPVOID)0x0063D40F, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D40F, (LPVOID)SelectCharacterS13S0CordPJ21, ASM::JMP);
	
			SetRange((LPVOID)0x0063D1EB, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D1EB, (LPVOID)SelectCharacterS13S0CordPJ2, ASM::JMP);
			SetRange((LPVOID)0x0063D42C, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D42C, (LPVOID)SelectCharacterS13S0CordPJ22, ASM::JMP);
	
			SetRange((LPVOID)0x0063D208, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D208, (LPVOID)SelectCharacterS13S0CordPJ3, ASM::JMP);
			SetRange((LPVOID)0x0063D449, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D449, (LPVOID)SelectCharacterS13S0CordPJ23, ASM::JMP);
	
			SetRange((LPVOID)0x0063D225, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D225, (LPVOID)SelectCharacterS13S0CordPJ4, ASM::JMP);
			SetRange((LPVOID)0x0063D466, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D466, (LPVOID)SelectCharacterS13S0CordPJ24, ASM::JMP);
	
			SetRange((LPVOID)0x0063D242, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D242, (LPVOID)SelectCharacterS13S0CordPJ5, ASM::JMP);
			SetRange((LPVOID)0x0063D483, 5, ASM::NOP);
			SetOp((LPVOID)0x0063D483, (LPVOID)SelectCharacterS13S0CordPJ25, ASM::JMP);
		}
	}
}