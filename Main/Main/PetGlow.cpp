#include "stdafx.h"
#include "PetGlow.h"

cRenderMesh cRender;

cRenderMesh::cRenderMesh(){
	this->m_RenderMeshPet.clear();
}
cRenderMesh::~cRenderMesh(){
}

void cRenderMesh::Load(RENDER_MESH * info){
	for( int n = 0; n < MAX_RENDER_MESH; n++){
		if(info[n].Index < 0 || info[n].Index >= MAX_RENDER_MESH){
			return;
		}
		this->m_RenderMeshPet.push_back(info[n]);
	}
}