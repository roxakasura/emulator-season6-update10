#pragma once

#define MAX_POSITION_ITEM 1000

struct CUSTOM_POSITION_INFO
{
	int		Index;
	int		ItemIndex;
	float	translationX;
	float	translationY;
	float	RotationX;
	float	RotationY;
	float	RotationZ;
	float	Scale;
};

class cCustomPosition
{
public:
	cCustomPosition();
	virtual ~cCustomPosition();
	void Init();
	void Load(CUSTOM_POSITION_INFO* info);
	void SetInfo(CUSTOM_POSITION_INFO info);
	CUSTOM_POSITION_INFO* GetInfo(int index);
	CUSTOM_POSITION_INFO* GetInfoByItem(int ItemIndex);
	bool CheckPosition(int ItemIndex);
public:
	CUSTOM_POSITION_INFO m_CustomPositionInfo[MAX_POSITION_ITEM];
};

extern cCustomPosition gCustomPosition;