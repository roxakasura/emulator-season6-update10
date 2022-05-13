#include "Stdafx.h"
#include <stdio.h>
#include "Console.h"
#include "procesos.h"

DOSConsole Console;


int DOSConsole::Write(char* Message, BOOL ShowHour, int Color)
{

	DWORD dwBytesWritten;
	char FullMsg[1024] = { 0 };


	if (ShowHour == TRUE)
	{
		SYSTEMTIME st;
		GetLocalTime(&st);
		wsprintf(FullMsg, "%02d:%02d:%02d %s\n", st.wHour, st.wMinute, st.wSecond, Message);
	}
	else
	{
		wsprintf(FullMsg, "%s\n", Message);
		//strcpy(FullMsg,Message);
	}

	switch (Color)
	{
	case 1: //Red
	{
		SetConsoleTextAttribute(Console.Handle(FALSE), FOREGROUND_RED | FOREGROUND_INTENSITY);
	}break;

	case 2: //Green
	{
		SetConsoleTextAttribute(Console.Handle(FALSE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}break;

	case 3: //Blue
	{
		SetConsoleTextAttribute(Console.Handle(FALSE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}break;

	case 4: //Cyan
	{
		SetConsoleTextAttribute(Console.Handle(FALSE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	}break;

	case 5: //Yellow
	{
		SetConsoleTextAttribute(Console.Handle(FALSE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}break;

	case 6: //Magenta
	{
		SetConsoleTextAttribute(Console.Handle(FALSE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	}break;
	}


	WriteFile(Handle(FALSE), FullMsg, strlen(FullMsg), &dwBytesWritten, NULL);
	//return dwBytesWritten;


	//WriteConsole(Handle(FALSE), FullMsg, (DWORD)strlen(FullMsg), &dwBytesWritten, NULL);
	SetConsoleTextAttribute(Handle(FALSE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return dwBytesWritten;
}

int DOSConsole::StdIn(char* Buffer)
{
	char inText[1024];
	memset(inText, 0x00, 1024);
	memset(Buffer, 0x00, 1024);
	DWORD dwBytesWritten;
	ReadFile(Handle(TRUE), inText, 1024, &dwBytesWritten, NULL);
	strncpy(Buffer, inText, strlen(inText) - 2);
	return dwBytesWritten;
}

HANDLE DOSConsole::Handle(BOOL Input)
{
	if (Input == TRUE)
	{
		return GetStdHandle(STD_INPUT_HANDLE);
	}
	else
	{

		return GetStdHandle(STD_OUTPUT_HANDLE);
	}
}

void DOSConsole::ChatCore(char* Input)
{
	char Temp[1024] = { 0 };

}



//void __stdcall Console__Start(PVOID pVoid)
void Console__Start(void * lpParam)
{
	char Temp[1024];
	char sBuff[255] = { 0 };
	AllocConsole();
	SetConsoleTitleA("RoxGaming Debug Console");
	while (true)
	{
		Console.StdIn(Temp);
		Console.ChatCore(Temp);
		Sleep(100);
	}
	_endthread();
}

void DOSConsole::SetName()
{
	SetConsoleTitleA("RoxGaming Debug Console");
}

void DOSConsole::Init()
{
	DWORD hTh;
	_beginthread(Console__Start, 0, NULL);
	Console.SpyChat = 0;
}