#pragma once

#define MAX_FOG 150

struct CUSTOM_FOG
{
	int Index;
	int MapNumber;
	float Red;
	float Green;
	float Blue;
};

class cFog
{
public:
	cFog();
	virtual ~cFog();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_FOG info);
	// ----
	CUSTOM_FOG m_CustomFog[MAX_FOG];
}; extern cFog gFog;