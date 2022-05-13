#pragma once

#define MAX_RENDER_MESH	1000

#define RenderMesh				((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0)

#include <vector>

struct RENDER_MESH
{
	int Index;
	int ItemIndex;
	int EffectIndex;
	int EffectType;
	float ColorR;
	float ColorG;
	float ColorB;
};

class cRenderMesh{
public:
	cRenderMesh();
	virtual ~cRenderMesh();
	void Init();
	void Load(RENDER_MESH * info);
	void SetInfo(RENDER_MESH info);
public:
	std::vector<RENDER_MESH> m_RenderMeshPet;
}; extern cRenderMesh cRender;