// Protect.cpp: implementation of the CProtect class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Protect.h"
#include "..\\..\\Util\\CCRC32.H"
#include "Util.h"

CProtect gProtect;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProtect::CProtect() // OK
{

}

CProtect::~CProtect() // OK
{

}

bool CProtect::ReadMainFile(char* name) // OK
{
	CCRC32 CRC32;

	if(CRC32.FileCRC(name,&this->m_ClientFileCRC,1024) == 0)
	{
		return 0;
	}

	HANDLE file = CreateFile(name,GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,FILE_ATTRIBUTE_ARCHIVE,0);

	if(file == INVALID_HANDLE_VALUE)
	{
		return 0;
	}

	if(GetFileSize(file,0) != sizeof(MAIN_FILE_INFO))
	{
		CloseHandle(file);
		return 0;
	}

	DWORD OutSize = 0;

	if(ReadFile(file,&this->m_MainInfo,sizeof(MAIN_FILE_INFO),&OutSize,0) == 0)
	{
		CloseHandle(file);
		return 0;
	}

	for(int n=0;n < sizeof(MAIN_FILE_INFO);n++)
	{
		((BYTE*)&this->m_MainInfo)[n] += (BYTE)(0x95^HIBYTE(n));
		((BYTE*)&this->m_MainInfo)[n] ^= (BYTE)(0xDA^LOBYTE(n));
	}

	CloseHandle(file);
	return 1;
}

void CProtect::CheckLauncher() // OK
{
	if((this->m_MainInfo.LauncherType & 1) == 0)
	{
		return;
	}

	if (FindWindow(0, gProtect.m_MainInfo.LauncherName) == 0)
	{
		ExitProcess(0);
	}
	//if(OpenMutex(MUTEX_ALL_ACCESS,0,gProtect.m_MainInfo.LauncherName) == 0)
	//{
	//	ExitProcess(0);
	//}
}

void CProtect::CheckInstance() // OK
{
	if((this->m_MainInfo.LauncherType & 2) == 0)
	{
		return;
	}

	char buff[256];

	wsprintf(buff,"XTEAM_MAIN_10405_%s",this->m_MainInfo.IpAddress);

	if(OpenMutex(MUTEX_ALL_ACCESS,0,buff) == 0)
	{
		CreateMutex(0,0,buff);
	}
	else
	{
		ExitProcess(0);
	}
}

void CProtect::CheckClientFile() // OK
{
	if (this->m_MainInfo.ClientCRC32 == 0)
	{
		return;
	}
	if (this->m_MainInfo.gMaxGameInstances == 0)
	{
		return;
	}

	char name[MAX_PATH] = { 0 };

	if (GetModuleFileName(0, name, sizeof(name)) == 0)
	{
		ExitProcess(0);
	}

	if (_stricmp(ConvertModuleFileName(name), this->m_MainInfo.ClientName) != 0)
	{
		ExitProcess(0);
	}
	//if (this->IsProcessRunning(gProtect.m_MainInfo.ClientName, this->m_MainInfo.gMaxGameInstances))
	//{
	//	ExitProcess(1);
	//}

	CCRC32 CRC32;

	DWORD ClientCRC32;

	if (CRC32.FileCRC(this->m_MainInfo.ClientName, &ClientCRC32, 1024) == 0)
	{
		MessageBox(0, "Main.exe CRC error!", "Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if (this->m_MainInfo.ClientCRC32 != ClientCRC32)
	{
		MessageBox(0, "Main.exe CRC error!", "Error", MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}
}

bool CProtect::IsProcessRunning(const char *ProcessName, int maxProcess)
{
	//PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
	//HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	//int Temp = 0;
	//if (Process32First(hSnapshot, &pe32))
	//{
	//	do
	//	{
	//		if (_tcsicmp(pe32.szExeFile, ProcessName) == 0)
	//		{
	//			Temp++;
	//			//gLog.Output(LOG_DEBUG, "CheckMaxGameInstances: %d: %d", Temp, maxProcess);
	//			if (Temp > maxProcess)
	//			{
	//				CloseHandle(hSnapshot);
	//				return true;
	//			}
	//		}
	//	} while (Process32Next(hSnapshot, &pe32));
	//}

	//CloseHandle(hSnapshot);
	return false;
}


void CProtect::CheckPlugin1File() // OK
{
	if(this->m_MainInfo.Plugin1CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin1CRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName1,&Plugin1CRC32,1024) == 0)
	{
		MessageBox(0,"Plugin 1 CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin1CRC32 != Plugin1CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName1);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin2File() // OK
{
	if(this->m_MainInfo.Plugin2CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin2CRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName2,&Plugin2CRC32,1024) == 0)
	{
		MessageBox(0,"Plugin 2 CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin2CRC32 != Plugin2CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName2);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin3File() // OK
{
	if(this->m_MainInfo.Plugin3CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin3CRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName3,&Plugin3CRC32,1024) == 0)
	{
		MessageBox(0,"Plugin 3 CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin3CRC32 != Plugin3CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName3);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin4File() // OK
{
	if(this->m_MainInfo.Plugin4CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin4CRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName4,&Plugin4CRC32,1024) == 0)
	{
		MessageBox(0,"Plugin 4 CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin4CRC32 != Plugin4CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName4);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckPlugin5File() // OK
{
	if(this->m_MainInfo.Plugin5CRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD Plugin5CRC32;

	if(CRC32.FileCRC(this->m_MainInfo.PluginName5,&Plugin5CRC32,1024) == 0)
	{
		MessageBox(0,"Plugin 5 CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.Plugin5CRC32 != Plugin5CRC32)
	{
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.PluginName5);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}

void CProtect::CheckCameraFile() // OK
{
	if(this->m_MainInfo.CameraCRC32 == 0)
	{
		return;
	}

	CCRC32 CRC32;

	DWORD CameraCRC32;

	if(CRC32.FileCRC(this->m_MainInfo.CameraName,&CameraCRC32,1024) == 0)
	{
		MessageBox(0,"Camera CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	if(this->m_MainInfo.CameraCRC32 != CameraCRC32)
	{
		MessageBox(0,"Camera CRC error!","Error",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	HMODULE module = LoadLibrary(this->m_MainInfo.CameraName);

	if(module == 0)
	{
		ExitProcess(0);
	}

	void (*EntryProc)() = (void(*)())GetProcAddress(module,"EntryProc");

	if(EntryProc != 0)
	{
		EntryProc();
	}
}
