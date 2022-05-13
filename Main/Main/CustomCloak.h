#pragma once
// -------------------------------------------------------------------------------
// -------------------------------------------------------------------------------

#define MAX_CUSTOMCLOAK		20

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
// -------------------------------------------------------------------------------

class cCustomCloak
{
public:
	cCustomCloak();
	virtual ~cCustomCloak();
	// ----
	void	Init();
	void	Load(CUSTOMCLOAK_DATA* info);
	void	SetInfo(CUSTOMCLOAK_DATA info);
	CUSTOMCLOAK_DATA* GetInfo(int index);
	CUSTOMCLOAK_DATA* GetInfoByItem(int ItemIndex);
	void	LoadTexture();
	bool	isCloak(int ItemIndex);
	bool	isCloakStrip(int ItemIndex);
	int		code;
	DWORD		getCodeCape(int ItemIndex); // OK

	// ----
	// ----
public:
	CUSTOMCLOAK_DATA m_Cloak[MAX_CUSTOMCLOAK];


}; extern cCustomCloak gCloak;
// -------------------------------------------------------------------------------