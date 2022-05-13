#include "stdafx.h"
#include "MiniMapInfo.h"
#include "MiniMap.h"
#include "Import.h"

cMiniMap gMiniMap;

cMiniMap::cMiniMap()
{

}

cMiniMap::~cMiniMap()
{

}

void cMiniMap::ClearPartyInfo()
{
	for (int i = 0; i < MAX_PLAYER_PARTY; i++)
	{
		memset(&this->gPartyInfo[i].name, 0, sizeof(this->gPartyInfo[i].name));
		this->gPartyInfo[i].map = -1;
		this->gPartyInfo[i].x = -1;
		this->gPartyInfo[i].y = -1;
	}
	this->ListsCount = 0;
}

void cMiniMap::RecvPartyInfo(MINIMAP_PARTY_INFO_RECV* lpMsg)
{
	this->ClearPartyInfo();

	for (int n = 0; n < lpMsg->count; n++)
	{
		MINIMAP_PARTY_INFO* lpInfo = (MINIMAP_PARTY_INFO*)(((BYTE*)lpMsg) + sizeof(MINIMAP_PARTY_INFO_RECV) + (sizeof(MINIMAP_PARTY_INFO)*n));
		this->InsertPartyInfo(lpInfo);
	}
}

void cMiniMap::InsertPartyInfo(MINIMAP_PARTY_INFO* lpInfo)
{
	memcpy(this->gPartyInfo[this->ListsCount].name, lpInfo->name, sizeof(this->gPartyInfo[this->ListsCount].name));
	this->gPartyInfo[this->ListsCount].map = lpInfo->map;
	this->gPartyInfo[this->ListsCount].x = lpInfo->x;
	this->gPartyInfo[this->ListsCount].y = lpInfo->y;
	this->ListsCount++;
}

bool cMiniMap::CheckButtonPressed(int x, int y, int w, int h)
{
	return pCheckMouseOver(x, y, w, h) && *(BYTE*)0x8793386;
}