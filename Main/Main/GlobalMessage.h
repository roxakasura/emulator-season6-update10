#pragma once

#define NoticeInverse               (int)0x81C0418
#define GetInstance					            ((int(__cdecl*)()) 0x00861110)
int RenderNotices();
void GlobalMessagem();
void InitNotices();