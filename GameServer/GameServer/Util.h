#pragma once

#include "ServerDisplayer.h"
#include "User.h"

int SafeGetItem(int index);
flt GetRoundValue(float value);
BYTE GetNewOptionCount(BYTE NewOption);
BYTE GetSocketOptionCount(BYTE SocketOption[5]);
BYTE GetPathPacketDirPos(int px,int py);
void PacketArgumentDecrypt(char* out_buff,char* in_buff,int size);
void ErrorMessageBox(char* message,...);
void LogAdd(eLogColor color,char* text,...);
void LogAddConnect(eLogColor color,char* text,...);
bool DataSend(int aIndex,BYTE* lpMsg,DWORD size);
void DataSendAll(BYTE* lpMsg,int size);
bool DataSendSocket(SOCKET socket,BYTE* lpMsg,DWORD size);
void MsgSendV2(LPOBJ lpObj,BYTE* lpMsg,int size);
void CloseClient(int aIndex);
void PostMessage1(char* name,char* message,char* text);
void PostMessage2(char* name,char* message,char* text);
void PostMessage3(char* name,char* message,char* text);
void PostMessage4(char* name,char* message,char* text);
void PostMessagePK(char* name,char* message,char* text);
void PostMessageUserON(char* name,char* message);
void PostMessageNew(char* name,char* message,char* text);
void SetLargeRand();
long GetLargeRand();
char *mystristr(char *haystack, const char *needle);
void MakeBarMsg(DWORD PlayerID, LPCTSTR szText, BYTE RGB1, BYTE RGB2, BYTE RGB3);
bool IsValidMonster(int index);

extern short RoadPathTable[MAX_ROAD_PATH_TABLE];
