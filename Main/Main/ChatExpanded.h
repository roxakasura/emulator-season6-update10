#pragma once
// ----------------------------------------------------
#include "Defines.h"
// ----------------------------------------------------
#define oNewCall				0x009D00C5
#define oFixSysMsg1_Hook		0x00789767
#define oFixSysMsg1_TRUE		0x00789824
#define oFixSysMsg2_Hook		0x00789A63
#define oFixSysMsg2_TRUE		0x00789B5A
#define oFixSysMsg3_Hook		0x00789DAC
#define oFixSysMsg3_TRUE		0x00789E6F
const int NewCall				= oNewCall;
const int FixSysMsg1_Hook		= oFixSysMsg1_Hook;   
const int FixSysMsg1_FALSE		= oFixSysMsg1_Hook+5; 
const int FixSysMsg1_TRUE		= oFixSysMsg1_TRUE;
const int FixSysMsg2_Hook		= oFixSysMsg2_Hook;
const int FixSysMsg2_FALSE		= oFixSysMsg2_Hook+5; 
const int FixSysMsg2_TRUE		= oFixSysMsg2_TRUE;
const int FixSysMsg3_Hook		= oFixSysMsg3_Hook;
const int FixSysMsg3_FALSE		= oFixSysMsg3_Hook+5; 
const int FixSysMsg3_TRUE		= oFixSysMsg3_TRUE; 
// ----------------------------------------------------
class ChatExpanded
{
public:
	static bool _FC ShowChatMessage(LPVOID This, LPVOID EDX);
	// ----
	void	Load();
	// ----
	void	SetInstance(LPVOID Instance);	
	void	Restore();
	void	Switch();
	// ----
	void	SetPosY(DWORD PosY)				{ *(DWORD*)((int)this->Instance + 296) = PosY; };
	DWORD	GetPosY()						{ return *(DWORD*)((int)this->Instance + 296); };
	void	SetHeight(DWORD Height)			{ *(DWORD*)((int)this->Instance + 312) = Height; };
	DWORD	GetHeight()						{ return *(DWORD*)((int)this->Instance + 312); };
	void	SetMessageCount(DWORD Count)	{ *(DWORD*)((int)this->Instance + 316) = Count; };
	DWORD	GetMessageCount()				{ return *(DWORD*)((int)this->Instance + 316); };
	void	SetMessageType(DWORD Type)		{ *(DWORD*)((int)this->Instance + 320) = Type; };
	DWORD	GetMessageType()				{ return *(DWORD*)((int)this->Instance + 320); };
	void	SetScrollPos(DWORD Pos)			{ *(DWORD*)((int)this->Instance + 328) = Pos; };
	DWORD	GetScrollPos()					{ return *(DWORD*)((int)this->Instance + 328); };
	// ----
public:
	LPVOID	Instance;
	DWORD	PosYBuff;
	DWORD	HeightBuff;
	DWORD	MessageCountBuff;
	DWORD	MessageTypeBuff;
	DWORD	ScrollPosBuff;
	int		m_separate;
	// ----
}; extern ChatExpanded gChatExpanded;
// ----------------------------------------------------------------------------------------------