#pragma once

#define RenderBoolean									((void(__cdecl*)(int a1, int a2, char *a3)) 0x005985F0)
#define CreateGuildMark									((void(__cdecl*)(int a1, bool a2)) 0x005D30F0)
#define RenderBitmap									((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)

void PlayerGuildLogo(int a1, int a2, char *a3);
void PlayerLoad();
void GensLogoPlayer(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12);


extern int valor;