#pragma once

// System Include
#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#ifndef GAMESERVER_PREMIUM
#define GAMESERVER_PREMIUM 1
#endif

#if(GAMESERVER_PREMIUM==1)
#define MAX_CUSTOM_WING 100
#define MAX_DYNAMIC_WING_EFFECT 3000
#define MAX_CUSTOM_WING_EFFECT 3000
#else
#define MAX_CUSTOM_WING 20
#define MAX_DYNAMIC_WING_EFFECT 50
#define MAX_CUSTOM_WING_EFFECT 300
#endif