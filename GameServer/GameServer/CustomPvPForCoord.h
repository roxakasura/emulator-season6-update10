#pragma once

#include "stdafx.h"
#include <vector>

struct MOVE_PVPCOORD_INFO
{
	int Map;
	int X;
	int Y;
	int TX;
	int TY;
	int Mode;
};

class cCPvPCoord
{
public:
	cCPvPCoord();
	virtual ~cCPvPCoord();
	void Load(char* path);
	bool CheckPvPCoord(int map,int x,int y, int Mode);
private:
	std::vector<MOVE_PVPCOORD_INFO> m_PvPCoordInfo;
};

extern cCPvPCoord gPvPCoord;