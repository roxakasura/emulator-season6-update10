#pragma once

#include "Item.h"
#include "User.h"
#include "Protocol.h"

#define MAX_LUCKYWHEEL_ITEM 12

enum eLuckyWhellState
{
	LUCKYWHEEL_STATE_BLANK = 0,
	LUCKYWHEEL_STATE_EMPTY = 1,
	LUCKYWHEEL_STATE_START = 2,
};

struct LUCKYWHEEL_INFO
{
	int Index;
	int ItemType;
	int ItemIndex;
	int Level;
	int Luck;
	int Skill;
	int Option;
	int Exc;
};

struct ITEM_WIN_SEND
{
	PSBMSG_HEAD header;
	int	number;
	int StartRoll;
};

struct LUCKYWHEEL_START_TIME
{
	int Year;
	int Month;
	int Day;
	int DayOfWeek;
	int Hour;
	int Minute;
	int Second;
};

struct PMSG_LUCKYWHEELACTIVE_SEND
{
	PSBMSG_HEAD	header;
	int Active;
};

class CLuckyWheel
{
public:
	CLuckyWheel();
	virtual ~CLuckyWheel();
	void Init();
	void Load(char* path);
	//
	void MainProc(); // OK
	void ProcState_BLANK();
	void ProcState_EMPTY();
	void ProcState_START();
	void SetState(int state);
	void SetState_BLANK();
	void SetState_EMPTY();
	void SetState_START();
	void CheckSync();
	void StartLucky();
	//
	void SetInfo(LUCKYWHEEL_INFO info);
	void State(LPOBJ lpObj);
	void Start(LPOBJ lpUser);
	int m_Active;
public:
	LUCKYWHEEL_INFO m_LuckyWheelInfo[MAX_LUCKYWHEEL_ITEM];
private:
	int m_State;
	int m_RemainTime;
	int m_TargetTime;
	int MinutesLeft;
	int m_WarningTime;
	int m_EventTime;
	int m_TickCount;
	std::vector<LUCKYWHEEL_START_TIME> m_LuckyWheelStartTime;
};

extern CLuckyWheel gLuckyWheel;
