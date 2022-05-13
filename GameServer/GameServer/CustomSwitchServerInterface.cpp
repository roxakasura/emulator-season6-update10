#include "stdafx.h"
#include "Protocol.h"
#include "CustomSwitchServerInterface.h"
#include "JSProtocol.h"
#include "Notice.h"

gSwitchServer SwitchServer;

gSwitchServer::gSwitchServer()
{
}

gSwitchServer::~gSwitchServer()
{
}

void gSwitchServer::SwitchServerReq(ECCG_SWITCHSERVER_REQ* data, int aIndex)
{
	LPOBJ lpObj = &gObj[aIndex];

	if (lpObj->Interface.type == INTERFACE_CHAOS_BOX 
		|| lpObj->Interface.type == INTERFACE_TRADE 
		|| lpObj->Interface.type == INTERFACE_PERSONAL_SHOP
		|| lpObj->Interface.type == INTERFACE_CASTLE_SIEGE_WEAPON_OFFENSE
		|| lpObj->Interface.type == INTERFACE_CASTLE_SIEGE_WEAPON_DEFENSE
		|| lpObj->Interface.type == INTERFACE_QUEST_WORLD
		|| lpObj->Interface.type == INTERFACE_SHOP
		|| lpObj->Interface.type == INTERFACE_CASH_SHOP
		|| lpObj->Interface.type == INTERFACE_WAREHOUSE)
	{
		return;
	}

	if (gObjIsConnectedGP(aIndex) == 0)
	{
		return;
	}
	GJMapServerMoveSend(lpObj->Index, data->subcode, 00, 125, 125);
}