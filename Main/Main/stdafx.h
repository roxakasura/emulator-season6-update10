#pragma once

typedef unsigned __int64 QWORD;

#define WIN32_LEAN_AND_MEAN

#define _WIN32_WINNT _WIN32_WINNT_WINXP

// System Include
#include <windows.h>
#include <iostream>
#include <map>
#include <math.h>
#include <stdlib.h>
#include <winsock2.h>
#include <Mmsystem.h>
#include <time.h>
#include <gl\GL.h>
#include <tlhelp32.h>
#include <tchar.h>
#include "detours.h"
#include "direct.h"

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib,"Winmm.lib")
#pragma comment(lib,"Opengl32.lib")
#pragma comment(lib,"detours.lib")
#pragma comment(lib,"wzMUQuiz.lib") //soiitem

#ifndef GAMESERVER_PREMIUM
#define GAMESERVER_PREMIUM 1
#endif

#define MAIN_UPDATE 10

#if(GAMESERVER_PREMIUM==1)
#define MAX_CUSTOM_WING 100
#define MAX_DYNAMIC_WING_EFFECT 3000
#define MAX_CUSTOM_WING_EFFECT 3000
#else
#define MAX_CUSTOM_WING 20
#define MAX_DYNAMIC_WING_EFFECT 50
#define MAX_CUSTOM_WING_EFFECT 300
#endif

#define MAIN_VERSION_S8 1
#define BRUNO_97D 1

typedef char textlist[100];