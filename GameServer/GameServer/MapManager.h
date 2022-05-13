// MapManager.h: interface for the CMapManager class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

struct MAP_MANAGER_INFO
{
	int Index;
	int NonPK;
	int ViewRange;
	int ExperienceRate;
	int ItemDropRate;
	int ExcItemDropRate;
	int SetItemDropRate;
	int SocketItemDrop;
	int HelperEnable;
	int GensBattle;
	int DisableCustomAttack;
	int CustomStore;
	int CustomPick;
	int CommandHelp;
	int CommandOffPvP;
	int PkDropItem;
	int AllowTrade;
	int DeathGate;
	char Name[32];
};

class CMapManager
{
public:
	CMapManager();
	virtual ~CMapManager();
	void Load(char* path);
	int IsValidMap(int index);
	int GetMapNonPK(int index);
	int GetMapNonOutlaw(int index);
	int GetMapViewRange(int index);
	int GetMapExperienceRate(int index);
	int GetMapMasterExperienceRate(int index);
	int GetMapItemDropRate(int index);
	int GetMapExcItemDropRate(int index);
	int GetMapSetItemDropRate(int index);
	int GetMapSocketItemDrop(int index);
	int GetMapHelperEnable(int index);
	int GetMapGensBattle(int index);
	int GetMapDisableCustomAttack(int index);
	int GetMapCustomStore(int index);
	int GetMapCustomPick(int index);
	int GetMapCommandHelp(int index);
	int GetMapCommandOffPvP(int index);
	int GetMapPkDropItem(int index);
	int GetMapAllowTrade(int index);
	int GetMapDeathGate(int index);
	char* GetMapName(int index);
public:
	std::map<int,MAP_MANAGER_INFO> m_MapManagerInfo;
};

extern CMapManager gMapManager;
