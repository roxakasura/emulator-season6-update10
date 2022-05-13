#include "stdafx.h"
#include "ConnectServer.h"
#include "Protocol.h"
#include "Import.h"
#include "Defines.h"
#include "Connection.h"
#include "Protect.h"
#include "Reconnect.h"
//#include "NewInterface.h"
//#include "CMacroUIEx.h"
cConnectServer ConnectServer;

cConnectServer::cConnectServer(){

}

cConnectServer::~cConnectServer(){

}


void ConnectServerProtocolCore(BYTE head, BYTE* lpMsg, int size){
	BYTE cHead = 0, cSub = 0;
	if (lpMsg[0] == 0xC1){
		cHead = lpMsg[2];
		cSub = lpMsg[3];
	}else{
		cHead = lpMsg[3];
		cSub = lpMsg[4];
	}
	switch (cHead){
	case 0xF4:
		switch (cSub){
		case 0x3:
			ConnectServer.ServerInfoRecv(lpMsg, true);
			break;
		case 0x6:
			ConnectServer.ServerListRecv(lpMsg, true);
			break;
		}
		break;
	}
}

void cConnectServer::Load()
{
	this->lastGetSrvList = 0;
	this->currently_subcode = 1;
	if (gConnection.Init(ConnectServerProtocolCore) == 0)
	{
		MessageBox(0, "O servidor encontra-se offline. Entre em contato com a Administração.", "Servidor Offline", 1);
		ExitProcess(0);
		this->ServerOnline = false;
	}
	if (gConnection.Connect(gProtect.m_MainInfo.IpAddress, gProtect.m_MainInfo.IpAddressPort) == 0)
	{
		MessageBox(0, "O servidor encontra-se offline. Entre em contato com a Administração.", "Servidor Offline", 1);
		ExitProcess(0);
		this->ServerOnline = false;
	}
	else
	{
		this->ServerOnline = true;
	}
}


void cConnectServer::ServerInfoRecv(BYTE* a1, bool a2)
{
	PMSG_SERVER_INFO_SEND *Data = (PMSG_SERVER_INFO_SEND*)a1;
}

void cConnectServer::ServerListRecv(BYTE* a1, bool a2)
{
	PMSG_SERVER_LIST_SEND *Data = (PMSG_SERVER_LIST_SEND*)a1;
	this->server_list_count = MAKE_NUMBERW(Data->count[0], Data->count[1]);
	for (char i = 0; i < this->server_list_count; i++)
	{
		this->SrvStat[i].ServerCode = a1[7 + 4 * i];
		this->SrvStat[i].type = a1[10 + 4 * i];
		this->SrvStat[i].UserTotal = a1[9 + 4 * i];
	}
}

BYTE cConnectServer::getServerType(WORD subcode)
{
	for (char i = 0; i < this->server_list_count; i++){
		if (this->SrvStat[i].ServerCode == subcode)
			return this->SrvStat[i].type;
	}
	return 0;
}
void cConnectServer::ReqServerInfo(WORD subcode)
{
	PMSG_SERVER_INFO_RECV pMsg;
	pMsg.header.set(0xF4, 0x03, sizeof(pMsg));
	pMsg.ServerCode = subcode;
	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
}

void cConnectServer::ReqServerList(bool a1)
{
	if (this->lastGetSrvList + (a1 ? DelayGetServerList : DelaySelfGetServerList) >= GetTickCount())
	{
		return;
	}
	PMSG_SERVER_LIST_RECV pMsg;
	pMsg.header.set(0xF4, 0x06, sizeof(pMsg));
	gConnection.DataSend((BYTE*)&pMsg, pMsg.header.size);
	this->lastGetSrvList = GetTickCount();
}