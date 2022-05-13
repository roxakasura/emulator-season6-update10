#pragma once

struct RenderTooltipBuff
{
	int Index;
	int IndexBuff;
	int Arg1;
	int Arg2;
	int Arg3;
	char NameBuff[128];
	int Arg4;
	int Arg5;
	int Arg6;
	char InfoBuff[128];
};

class CBuffIcon
{
public:
	CBuffIcon();
	virtual ~CBuffIcon();
	void Init();
	void Load(char* path, int Type);
public:
	RenderTooltipBuff m_TooltipENG [256];
	RenderTooltipBuff m_TooltipSPN [256];
	RenderTooltipBuff m_TooltipPOR [256];
}; extern CBuffIcon gCBuffIcon;