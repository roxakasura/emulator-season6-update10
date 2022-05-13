#pragma once

#define	InitCollisionDetectLineToFace				((void(*)()) 0x639430)
#define WorldTime									*(float *)0x5EF5A1C
#define WaterMove									*(float *)0x82C6A94
#define TerrainFlag									*(DWORD*)0x8787AA0
#define SelectFlag									*(BYTE*)0x82C6650
#define TerrainGrassEnable							*(BYTE*)0xE61E00
#define IsDoppelGanger3								((bool(*)()) 0x008E3130)
#define RenderTerrainFrustrum						((void(__cdecl*)(bool EditFlag)) 0x5DC4D0)
#define DisableAlphaBlend							((void(__cdecl*)( )) 0x00635F50)
#define SelectXF									*(float*)0x82C6A9C
#define SelectYF									*(float*)0x82C6A98
#define RenderTerrainTile							((bool(__cdecl*)(float xf, float yf, int xi, int yi, float lodf, int lodi, bool Flag))0x005DA250)
#define EnableAlphaTest								((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define EnableDepthTest								((void(*)()) 0x00635DE0)
#define RenderPointers								((void(*)()) 0x00771230)
#define EnableCullFace								((void(*)()) 0x00635E80)
#define DisableDepthTest							((void(*)()) 0x00635E10)

void InitTerrain();