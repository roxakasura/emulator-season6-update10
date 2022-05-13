#pragma once

#include <vector>

#define MAX_NOGLOW			200

#define sub_608200	((void(__cdecl*)(int a4, int a5, int a6, float a7, int a8, float a9, int a10, int a11)) 0x00608200)

struct JCItemnoGlow
{
	int ItemIndex;
	int IndexTexture;
};

class JCRemoveGLow
{
public:
	JCRemoveGLow();
	~JCRemoveGLow();
	void Load(JCItemnoGlow * Info);
	int GetInfoType(int ItemIndex); // OK
	void Init( );
public:
	std::map<int, JCItemnoGlow> m_JCRemoveGlow;
};

extern JCRemoveGLow JCRemoveGlow;