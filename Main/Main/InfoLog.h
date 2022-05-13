#pragma once

#define MAX_LOG 3

enum eLogType
{
	LOG_CHAT = 0,
	LOG_KILLERS = 1,
	LOG_POSTITEM = 2,
};

struct LOG_INFO
{
	BOOL Active;
	char Directory[256];
	int Day;
	int Month;
	int Year;
	char Filename[256];
	HANDLE File;
};

class cInfoLog
{
public:
	cInfoLog();
	virtual ~cInfoLog();
	void Load();
	void AddLog(BOOL active,char* directory);
	void Output(eLogType type,char* text,...);
private:
	LOG_INFO m_LogInfo[MAX_LOG];
	int m_count;
}; extern cInfoLog gInfoLog;