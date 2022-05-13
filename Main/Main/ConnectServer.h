#pragma once
#define DelayGetServerList		10000
#define DelaySelfGetServerList  30000

struct ServerListStat
{
	WORD ServerCode;
	BYTE UserTotal;
	BYTE type;
};

class cConnectServer
{
public:
	cConnectServer();
	~cConnectServer();
	void Load();

	void ServerInfoRecv(BYTE* a1, bool a2 = false);
	void ServerListRecv(BYTE* a1, bool a2 = false);
	void ReqServerInfo(WORD subcode);
	void ReqServerList(bool a1 = false);
	BYTE getServerType(WORD subcode);
	int server_list_count;
	WORD	currently_subcode;
	bool	ServerOnline;
	ServerListStat	SrvStat[50];
	DWORD lastGetSrvList;
private:

};extern cConnectServer ConnectServer;