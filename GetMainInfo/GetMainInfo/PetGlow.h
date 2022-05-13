#pragma once

#define MAX_RENDER_MESH	1000

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

class cRenderMesh
{
public:
	cRenderMesh();
	virtual ~cRenderMesh();
	void Init();
	void Load(char* path);
	void SetInfo(RENDER_MESH info);

public:
	RENDER_MESH m_RenderMeshPet[MAX_RENDER_MESH];

}; extern cRenderMesh cRender;