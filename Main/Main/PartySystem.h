#pragma once

void LoadPartySystem();
char RenderPartyBack(DWORD This);

//-- Recovery Info User
#define pGetUserCoorX				*(DWORD *)(*(DWORD *)0x7BC4F04 + 0xAC)
#define pGetUserCoorY				*(DWORD *)(*(DWORD *)0x7BC4F04 + 0xB0)
#define pGetUserName				(const char *)(*(DWORD *)0x7BC4F04 + 56)
#define pGetStrutParty( x )			(*(PartyList*)(0x81CB4E8 + 32 * x))
#define pGetLifeMemberParty( x )	((unsigned __int8)((BYTE*) 0x81CB500)[32 * x])
#define sub_7798F0					((char(__thiscall*)(int This, char a9))0x007798F0)
