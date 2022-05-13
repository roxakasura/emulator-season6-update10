#pragma once
#define MAX_NOGLOW			200

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
	void Load(char * Path);
public:
	JCItemnoGlow m_JCRemoveGlow[ MAX_NOGLOW ];
};

extern JCRemoveGLow JCRemoveGlow;