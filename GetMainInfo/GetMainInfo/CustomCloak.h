#pragma once
// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------

#define MAX_CUSTOMCLOAK 20

struct CUSTOMCLOAK_DATA
{
	int		Index;
	int		ItemIndex;
	int		Mode;
	int		IndexCloak;
	char	CloakName[100];
	int		IndexStrip;
	char	StripName[100];
};

class cCustomCloak
{
public:
	cCustomCloak();
	virtual ~cCustomCloak();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOMCLOAK_DATA info);
public:
	CUSTOMCLOAK_DATA m_Cloak[MAX_CUSTOMCLOAK];
}; extern cCustomCloak gCloak;