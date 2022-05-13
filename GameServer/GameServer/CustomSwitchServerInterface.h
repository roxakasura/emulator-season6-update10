#pragma once
#include "stdafx.h"
#include "Protocol.h"


struct ECCG_SWITCHSERVER_REQ
{
	PSBMSG_HEAD header; // C1:29:06
	WORD subcode;
};


class gSwitchServer
{
public:
	gSwitchServer();
	~gSwitchServer();

	void SwitchServerReq(ECCG_SWITCHSERVER_REQ*, int);

private:

};

extern gSwitchServer SwitchServer;