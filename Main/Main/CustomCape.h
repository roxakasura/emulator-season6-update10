#pragma once

class CCapeAnimation
{
public:
	CCapeAnimation();
	virtual ~CCapeAnimation();
	void Load();
	static void ModelEffectRender(DWORD ObjectPointer,DWORD ObjectModel, DWORD a3);
	static void DrawViewPort(DWORD ObjectPointer, DWORD ModelPointer, DWORD a3);
	
};

extern CCapeAnimation gCapeAnimation;