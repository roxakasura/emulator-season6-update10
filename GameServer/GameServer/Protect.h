// Protect.h: interface for the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
#include "stdafx.h"

#define PROTECT_START _asm _emit 0xEB _asm _emit 0x0E _asm _emit 0x14 _asm _emit 0x28 _asm _emit 0xCD _asm _emit 0xDB _asm _emit 0x50 _asm _emit 0x63 _asm _emit 0xAF _asm _emit 0x22 _asm _emit 0x75 _asm _emit 0xEE _asm _emit 0xB5 _asm _emit 0xD8 _asm _emit 0x43 _asm _emit 0x72
#define PROTECT_FINAL _asm _emit 0xEB _asm _emit 0x0E _asm _emit 0x37 _asm _emit 0xF2 _asm _emit 0xCD _asm _emit 0xDB _asm _emit 0x50 _asm _emit 0x63 _asm _emit 0xAF _asm _emit 0x22 _asm _emit 0x75 _asm _emit 0xEE _asm _emit 0xB5 _asm _emit 0xD8 _asm _emit 0x85 _asm _emit 0x61
#define CRASH_APPLICATION_MACRO _asm _emit 0xFF _asm _emit 0x25 _asm _emit 0x00 _asm _emit 0x00 _asm _emit 0x00 _asm _emit 0x00

enum eAuthServerType
{
	AUTH_SERVER_TYPE_NONE = 0,
	AUTH_SERVER_TYPE_S0_CONNECT_SERVER = 1,
	AUTH_SERVER_TYPE_S0_JOIN_SERVER = 2,
	AUTH_SERVER_TYPE_S0_DATA_SERVER = 3,
	AUTH_SERVER_TYPE_S0_GAME_SERVER = 4,
	AUTH_SERVER_TYPE_S1_CONNECT_SERVER = 5,
	AUTH_SERVER_TYPE_S1_JOIN_SERVER = 6,
	AUTH_SERVER_TYPE_S1_DATA_SERVER = 7,
	AUTH_SERVER_TYPE_S1_GAME_SERVER = 8,
	AUTH_SERVER_TYPE_S2_CONNECT_SERVER = 9,
	AUTH_SERVER_TYPE_S2_JOIN_SERVER = 10,
	AUTH_SERVER_TYPE_S2_DATA_SERVER = 11,
	AUTH_SERVER_TYPE_S2_GAME_SERVER = 12,
	AUTH_SERVER_TYPE_S3_CONNECT_SERVER = 13,
	AUTH_SERVER_TYPE_S3_JOIN_SERVER = 14,
	AUTH_SERVER_TYPE_S3_DATA_SERVER = 15,
	AUTH_SERVER_TYPE_S3_GAME_SERVER = 16,
	AUTH_SERVER_TYPE_S4_CONNECT_SERVER = 17,
	AUTH_SERVER_TYPE_S4_JOIN_SERVER = 18,
	AUTH_SERVER_TYPE_S4_DATA_SERVER = 19,
	AUTH_SERVER_TYPE_S4_GAME_SERVER = 20,
	AUTH_SERVER_TYPE_S6_CONNECT_SERVER = 21,
	AUTH_SERVER_TYPE_S6_JOIN_SERVER = 22,
	AUTH_SERVER_TYPE_S6_DATA_SERVER = 23,
	AUTH_SERVER_TYPE_S6_GAME_SERVER = 24,
	AUTH_SERVER_TYPE_S8_CONNECT_SERVER = 25,
	AUTH_SERVER_TYPE_S8_JOIN_SERVER = 26,
	AUTH_SERVER_TYPE_S8_DATA_SERVER = 27,
	AUTH_SERVER_TYPE_S8_GAME_SERVER = 28,
};

enum eAuthServerStatus
{
	AUTH_SERVER_STATUS_NONE = 0,
	AUTH_SERVER_STATUS_SUCCESS = 1,
	AUTH_SERVER_STATUS_INVALID_TOKEN = 2,
	AUTH_SERVER_STATUS_USER_NOT_FOUND = 3,
	AUTH_SERVER_STATUS_USER_INVALID_TOKEN = 4,
};

struct SDHP_AUTH_SERVER_DATA_RECV
{
	BYTE type; // C1:00
	BYTE size;
	BYTE head;
	BYTE EncKey;
	BYTE ServerType;
	BYTE Status;
	BYTE PackageType;
	BYTE PlanType;
	char Token[40];
	char CustomerName[32];
	char CustomerHardwareId[36];
};

struct SDHP_AUTH_SERVER_DATA_SEND
{
	BYTE type; // C1:00
	BYTE size;
	BYTE head;
	BYTE EncKey;
	BYTE ServerType;
	char Token[40];
	char CustomerName[32];
	char CustomerHardwareId[36];
};

class CProtect
{
public:
	CProtect();
	virtual ~CProtect();
	bool GetComputerHardwareId();
	bool ConnectToAuthServer(char* IpAddress,WORD port);
	bool AuthServerDataSend(eAuthServerType ServerType);
	void StartAuth(eAuthServerType ServerType);
	inline void ConnectionMessageError();
	inline void ServerTypeMessageError();
	inline void InvalidEncKeyMessageError();
	inline void InvalidTokenMessageError();
	inline void UserNotFoundMessageError();
	inline void UserInvalidTokenMessageError();
	inline void CustomerNameMessageError();
	inline void ComputerHardwareIdMessageError();
	inline void CustomerHardwareIdMessageError();
	inline void InvalidGameserverUpdateMessageError();
	inline void ErrorMessageBox(int Error);
	inline void SafeExitProcess();
	bool MACProtection();
	void ProtectBlock(DWORD size);
	void ReleaseBlock(DWORD size);
	void DecryptBlock(BYTE* data,int size);
	void EncryptBlock(BYTE* data,int size);
	inline void InsertMemoryMacro(BYTE* data,BYTE* info,int size);
	inline void RemoveMemoryMacro(BYTE* data,BYTE* info,int size);
	inline bool VerifyMemoryMacro(BYTE* data,BYTE* info,int size);
	bool GetInsertStartBlock(DWORD start_offset,DWORD final_offset,DWORD* start_block);
	bool GetInsertFinalBlock(DWORD start_offset,DWORD final_offset,DWORD* final_block);
	bool GetRemoveStartBlock(DWORD start_offset,DWORD final_offset,DWORD* start_block);
	bool GetRemoveFinalBlock(DWORD start_offset,DWORD final_offset,DWORD* final_block);
	char* GetEncryptedString(BYTE* string,int size);
	void SystemOut1();
	void SystemOut2();
	void SystemOut3();
public:
	SOCKET m_socket;
	char m_ComputerHardwareId[36];
	BYTE m_EncKey;
	BYTE m_EncKeyNew;
	SDHP_AUTH_SERVER_DATA_RECV m_AuthInfo;
};

extern CProtect gProtect;

static const BYTE gProtectTable[16] = {0xC8,0x9D,0x24,0xC2,0x10,0xDD,0xE1,0x66,0xF3,0x5D,0x35,0xD2,0xA8,0x96,0xC5,0x48};
static const BYTE gProtectInsertStart[16] = {0x74,0x91,0x8B,0xB7,0x52,0x44,0xCF,0xFC,0x30,0xBD,0xEA,0x71,0x2A,0x47,0xDC,0xED}; //{0xEB,0x0E,0x14,0x28,0xCD,0xDB,0x50,0x63,0xAF,0x22,0x75,0xEE,0xB5,0xD8,0x43,0x72}
static const BYTE gProtectInsertFinal[16] = {0x74,0x91,0xA8,0x6D,0x52,0x44,0xCF,0xFC,0x30,0xBD,0xEA,0x71,0x2A,0x47,0x1A,0xFE}; //{0xEB,0x0E,0x37,0xF2,0xCD,0xDB,0x50,0x63,0xAF,0x22,0x75,0xEE,0xB5,0xD8,0x85,0x61}
static const BYTE gProtectRemoveStart[16] = {0x5C,0x74,0x92,0xB7,0x52,0x44,0xCF,0xFC,0x30,0xBD,0xEA,0x71,0x2A,0x47,0xDC,0xED}; //{0xC3,0xEB,0x0D,0x28,0xCD,0xDB,0x50,0x63,0xAF,0x22,0x75,0xEE,0xB5,0xD8,0x43,0x72}
static const BYTE gProtectRemoveFinal[16] = {0x5C,0x74,0x92,0x6D,0x52,0x44,0xCF,0xFC,0x30,0xBD,0xEA,0x71,0x2A,0x47,0x1A,0xFE}; //{0xC3,0xEB,0x0D,0xF2,0xCD,0xDB,0x50,0x63,0xAF,0x22,0x75,0xEE,0xB5,0xD8,0x85,0x61}
static BYTE gProtectString1[04] = {0xF3,0x8A,0xEC,0xB0}; //"C:\\"
static BYTE gProtectString2[20] = {0x95,0x80,0x88,0xE8,0x9D,0x95,0x80,0x88,0xE8,0x9D,0x95,0x80,0x88,0xE8,0x9D,0x95,0x80,0x88,0xE8,0xB0}; //"%08X-%08X-%08X-%08X"
static BYTE gProtectString3[18] = {0xD1,0XC5,0XC4,0XD8,0x9E,0XDD,0XC5,0XD5,0XDD,0XC5,0x9E,0XD3,0XDF,0XDD,0x9E,0XD2,0XC2,0xB0}; //"auth.muemu.com.br"
static BYTE gProtectString4[35] = {0xF3,0xDF,0xC5,0xDC,0xD4,0x90,0xDE,0xDF,0xC4,0x90,0xD1,0xC5,0xC4,0xD8,0xD5,0xDE,0xC4,0xD9,0xD3,0xD1,0xC4,0xD5,0x90,0xC4,0xD8,0xD5,0x90,0xDD,0xD1,0xD3,0xD8,0xD9,0xDE,0xD5,0xB0}; //"Could not authenticate the machine"
static BYTE gProtectString5[06] = {0xF5,0xC2,0xC2,0xDF,0xC2,0xB0}; //"Error"
