#include "stdafx.h"
#include "TerrainSystem.h"
#include "CMacroUIEx.h"
#include "Antilag.h"
#include "Util.h"

void RenderTerrainFunction(bool EditFlag)
{
    if( !EditFlag )
    {
        if(World == 8)
		{
            WaterMove = (float)((int)(WorldTime)%40000)*0.000025f;
		}
		else if(World == 42)
		{
			int iWorldTime = (int)WorldTime;
			int iRemainder = iWorldTime % 50000;
			WaterMove = (float)iRemainder * 0.00002f;
		}
        else
		{
            WaterMove = (float)((int)(WorldTime)%20000)*0.00005f;
		}
    }

	if(!EditFlag)
	{
     	DisableAlphaBlend();
	}
	else
	{
     	SelectFlag = false;
		InitCollisionDetectLineToFace();
	}
	
	if(gAntiLagSystem.testFunctionInvItem9 == 0)
	{
		TerrainFlag = 0; // Commenting this disable Terrain Render (Terrain Render Disable)
	}
	else
	{

	}

    RenderTerrainFrustrum ( EditFlag );

	if ( EditFlag && SelectFlag )
	{
		RenderTerrainTile ( SelectXF, SelectYF, (int)SelectXF, (int)SelectYF, 1.f, 1, EditFlag ); 
	}
	if ( !EditFlag )
	{
		if(gAntiLagSystem.testFunctionInvItem9 == 0)
		{
			EnableAlphaTest(1); // Commenting this disable Terrain Grass (Terrain Grass Disable)
		}
		else
		{

		}

		if ( TerrainGrassEnable && World != 7 && !IsDoppelGanger3())
		{
			TerrainFlag = 2;
			RenderTerrainFrustrum ( EditFlag );
		}
		DisableDepthTest();
		EnableCullFace();
		RenderPointers();
		EnableDepthTest();
	}
}

void InitTerrain()
{
	SetCompleteHook(0xE9,0x5DC820,&RenderTerrainFunction); //Função responsável pela renderização dos mapas
}