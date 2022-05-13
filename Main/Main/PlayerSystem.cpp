#include "stdafx.h"
#include "Util.h"
#include "PlayerSystem.h"
#include "Protect.h"
#include "User.h"

int valor = 0;

void PlayerLoad()
{
	if (gProtect.m_MainInfo.PlayerShowGuildLogo == 1)
	{
		SetCompleteHook(0xE8, 0x005BAFAB, &PlayerGuildLogo);

		SetCompleteHook(0xE8, 0x007C5DB0, &GensLogoPlayer);
	}

	if (gProtect.m_MainInfo.PlayerShowName == 1)
	{
		SetByte(0x81C03FA, 0x01);
	}
}

void GensLogoPlayer(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)
{
	gObjUser.Refresh();
	RenderBitmap(a1, a2 - valor, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}

void PlayerGuildLogo(int a1, int a2, char *a3)
{
	int guild = 1;

	if (*(BYTE *)(*(DWORD *)(a3 + 668) + 24) == 255) //Verificação de guild (nesse caso verifica se o usuário não tem guild)
	{
		guild = 0;
	}

	if (guild == 0) // valor de posição X da Gens original caso não tenha guild
	{
		valor = 0.0;
	}
	else // resultado final + valor de posição X da Gens original caso tenha guild
	{
		valor = 15.0;
		CreateGuildMark(*(WORD *)(*(DWORD *)(a3 + 668) + 124), 1);
		RenderBitmap(31740, a1 - 18, a2 + 2, 16.0, 16.0, 0.0, 0.0, 1.0, 1.0, 1, 1, 0.0);
	}

	RenderBoolean(a1, a2, a3);
}