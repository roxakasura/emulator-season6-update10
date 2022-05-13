#pragma once

#include "Protocol.h"
#include "Interface.h"

#define MAX_ITEM_LUCKY 12

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

class CLuckyWheel
{
public:
	CLuckyWheel();
	virtual ~CLuckyWheel();
	void Init();
	void Bind();
	void Load(LUCKYWHEEL_INFO* info);
	void SetInfo(LUCKYWHEEL_INFO info);
	void Start(int aIndex);
	void LoadImages();
	bool EventDrawClose_LuckyWheelKG(DWORD Event);
	void		DrawLuckyWheel();
	void		DrawLuckyWheel803();
	void		EventLuckyWheel_Main(DWORD Event);
	void		LuckyWheelState(){(gInterface.Data[eLuckyWheelMain].OnShow == true)? gInterface.Data[eLuckyWheelMain].Close():gInterface.Data[eLuckyWheelMain].Open();};
	void		LuckyWheelStateclose() { gInterface.Data[eLuckyWheelMain].OnShow = false; pSetCursorFocus = false; };

	bool CheckTestWindow()
	{
		return gInterface.Data[eLuckyWheelMain].OnShow;
	};

	void	OpenTestWindow()
	{
		gInterface.Data[eLuckyWheelMain].OnShow = true; pSetCursorFocus = true;
	};

	void    CloseTestWindow()
	{
		gInterface.Data[eLuckyWheelMain].OnShow = false; pSetCursorFocus = false;
	};

	int			LuckyWheelNumber;
	DWORD		LuckyWheelTime;
	int			StartRoll;
	DWORD		OpenTestDelay;
	int			LuckyWheelActive;
public:
	LUCKYWHEEL_INFO m_LuckyWheelInfo[MAX_ITEM_LUCKY];
};

extern CLuckyWheel gLuckyWheel;
