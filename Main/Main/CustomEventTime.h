#pragma once

#include "Protocol.h"
#include "Interface.h"
#define pSetCursorFocus			*(DWORD*)0xE8CB3C

#define MAX_EVENTTIME 42

struct PMSG_CUSTOM_EVENTTIME_RECV
{
	PSWMSG_HEAD h;
	int count;
};

struct PMSG_CUSTOM_EVENTTIME_SEND
{
	PSBMSG_HEAD header; // C1:BF:51
};

struct CUSTOM_EVENTTIME_DATA
{
	int index;
	int time;
};

struct CUSTOM_EVENT_INFO
{
	int Index;
	char Name[40];
};


class CCustomEventTime
{
public:
	CCustomEventTime();
	void Init();
	void Load(CUSTOM_EVENT_INFO* info);
	void SetInfo(CUSTOM_EVENT_INFO info);
	void ClearCustomEventTime();
	void GCReqEventTime(PMSG_CUSTOM_EVENTTIME_RECV* lpMsg);	
	void DrawEventTimePanelWindow();
	bool EventEventTimeWindow_Close(DWORD Event);
	bool EventNext(DWORD Event);
	bool EventPrev(DWORD Event);


	bool Click;
	bool CheckTestWindow()
	{
		return gInterface.Data[eADDPOINT3_MAIN].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eADDPOINT3_MAIN].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eADDPOINT3_MAIN].OnShow = false; pSetCursorFocus = false;
	};
	DWORD OpenTestDelay;

private:
	CUSTOM_EVENT_INFO m_CustomEventInfo[MAX_EVENTTIME];
	int count;
	CUSTOM_EVENTTIME_DATA gCustomEventTime[MAX_EVENTTIME];
	int EventTimeLoad;
	int EventTimeEnable;
	int EventTimeTickCount;
	int Page;
	int Arena;

};
extern CCustomEventTime gCustomEventTime;



