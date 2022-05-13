// CustomItem.h: interface for the CCustomItem class.
//
//////////////////////////////////////////////////////////////////////

#pragma once

#define MAX_EVENTTIME 42

struct CUSTOM_EVENT_INFO
{
	int Index;
	char Name[40];
};

class CCustomEventTimeText
{
public:
	CCustomEventTimeText();
	virtual ~CCustomEventTimeText();
	void Init();
	void Load(char* path);
	void SetInfo(CUSTOM_EVENT_INFO info);
public:
	CUSTOM_EVENT_INFO m_CustomEventInfo[MAX_EVENTTIME];
};

extern CCustomEventTimeText gCustomEventTimeText;