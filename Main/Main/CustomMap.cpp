#include "stdafx.h"
#include "CustomMap.h"
#include "Defines.h"
#include "TMemory.h"
#include "Import.h"
#include "Util.h"
#include "Interface.h"

CCustomMap gCustomMap;

// ----------------------------------------------------------------------------------------------
char * Map82 = "NewMap1.tga";
char * Map83 = "NewMap2.tga";
char * Map84 = "NewMap3.tga";
char * Map85 = "NewMap4.tga";
char * Map86 = "NewMap5.tga";
char * Map87 = "NewMap6.tga";
char * Map88 = "NewMap7.tga";
char * Map89 = "NewMap8.tga";
char * Map90 = "NewMap9.tga";
char * Map91 = "NewMap10.tga";
char * Map92 = "NewMap11.tga";
char * Map93 = "NewMap12.tga";
char * Map94 = "NewMap13.tga";
char * Map95 = "NewMap14.tga";
char * Map96 = "NewMap15.tga";
char * Map97 = "NewMap16.tga";
char * Map98 = "NewMap17.tga";
char * Map99 = "NewMap18.tga";
char * Map100 = "NewMap19.tga";

char* LoadMapName(signed int MapNumber)
{
	if (MapNumber >= 84 && MapNumber <= 100)
	{
		return pGetTextLine(pTextLineThis, (3669 + MapNumber - 84));
	}
	return pMapName(MapNumber);
}

Naked(LoadInterfaceMapName)
{
	_asm
	{
			MOV DWORD PTR SS : [EBP - 0x848], 0x51
			PUSH 0x00D25498
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x54		// 84 Arkania Custom Map
			PUSH Map82								// Interface Name
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			//----
			MOV DWORD PTR SS : [EBP - 0x848], 0x55		// 85 Arkania Custom Map
			PUSH Map83								// Interface Name
			LEA EAX, DWORD PTR SS : [EBP - 0x28]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP, 0x0C
			MOV DWORD PTR SS : [EBP - 0xA74], EAX
			MOV EDX, DWORD PTR SS : [EBP - 0xA74]
			MOV DWORD PTR SS : [EBP - 0xA78], EDX
			MOV BYTE PTR SS : [EBP - 0x4], 0x43
			MOV EAX, DWORD PTR SS : [EBP - 0xA78]
			PUSH EAX
			LEA ECX, DWORD PTR SS : [EBP - 0x848]
			PUSH ECX
			MOV ECX, DWORD PTR SS : [EBP - 0x868]
			ADD ECX, 0x4
			CALL InterfaceLoad2
			MOV ECX, EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS : [EBP - 0x4], 0x2
			LEA ECX, DWORD PTR SS : [EBP - 0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS : [EBP - 0x4], -0x1
			LEA ECX, DWORD PTR SS : [EBP - 0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x56		// 86 Arkania Custom Map
			PUSH Map84								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x57		// 87 Arkania Custom Map
			PUSH Map85								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x58		// 88 Arkania Custom Map
			PUSH Map86								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x59		// 89 Arkania Custom Map
			PUSH Map87								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5A		// 90 Arkania Custom Map
			PUSH Map88								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5B		// 91 Arkania Custom Map
			PUSH Map89								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x5F		// 95 Arkania Custom Map
			PUSH Map90								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x60		// 96 Arkania Custom Map
			PUSH Map91								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x62		// 98 Arkania Custom Map
			PUSH Map92								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x63		// 99 Arkania Custom Map
			PUSH Map93								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]
			//----
			MOV DWORD PTR SS:[EBP-0x848],0x64		// 100 Arkania Custom Map
			PUSH Map94								// Interface Name 
			LEA EAX,DWORD PTR SS:[EBP-0x28]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			PUSH ECX
			CALL InterfaceLoad1
			ADD ESP,0x0C
			MOV DWORD PTR SS:[EBP-0xA74],EAX
			MOV EDX,DWORD PTR SS:[EBP-0xA74]
			MOV DWORD PTR SS:[EBP-0xA78],EDX
			MOV BYTE PTR SS:[EBP-0x4],0x43
			MOV EAX,DWORD PTR SS:[EBP-0xA78]
			PUSH EAX
			LEA ECX,DWORD PTR SS:[EBP-0x848]
			PUSH ECX
			MOV ECX,DWORD PTR SS:[EBP-0x868]
			ADD ECX,0x4
			CALL InterfaceLoad2
			MOV ECX,EAX
			CALL InterfaceLoad3
			MOV BYTE PTR SS:[EBP-0x4],0x2
			LEA ECX,DWORD PTR SS:[EBP-0x864]
			CALL InterfaceLoad4
			MOV DWORD PTR SS:[EBP-0x4],-0x1
			LEA ECX,DWORD PTR SS:[EBP-0x28]

		CALL InterfaceLoad4
		MOV ECX, DWORD PTR SS : [EBP - 0xC]
		MOV DWORD PTR FS : [0x0], ECX

		MOV EDI, 0x0047FD08
			JMP EDI

		InterfaceLoad1 :
		MOV EDI, 0x0047C220
			JMP EDI

		InterfaceLoad2 :
		MOV EDI, 0x00480160
			JMP EDI

		InterfaceLoad3 :
		MOV EDI, 0x00409AF0
			JMP EDI

		InterfaceLoad4 :
		MOV EDI, 0x00409AD0
			JMP EDI

			MOV ESP, EBP
			POP EBP
			RETN
		}
}

void LoadMapMusic(HDC Arg1)
{
	static PCHAR MusicID;
 // ----
	if(pPlayerState == 5)
	{
		switch(pMapNumber)
		{
			case 84:
			{
				MusicID = "Data\\Music\\Map84.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 85:
			{
				MusicID = "Data\\Music\\Map85.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 86:
			{
				MusicID = "Data\\Music\\Map86.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 87:
			{
				MusicID = "Data\\Music\\Map87.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 88:
			{
				MusicID = "Data\\Music\\Map88.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 89:
			{
				MusicID = "Data\\Music\\Map89.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 90:
			{
				MusicID = "Data\\Music\\Map90.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 95:
			{
				MusicID = "Data\\Music\\Map95.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 96:
			{
				MusicID = "Data\\Music\\Map96.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 97:
			{
				MusicID = "Data\\Music\\Map97.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 98:
			{
				MusicID = "Data\\Music\\Map98.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 99:
			{
				MusicID = "Data\\Music\\Map99.mp3";
				pWzAudioPlay(MusicID,0);
			}
			break;
			case 100:
			{
				MusicID = "Data\\Music\\Map100.mp3";
				pWzAudioPlay(MusicID,0);
			}
		}
	}
	pLoadGameStuffs(Arg1);
}

Naked ( CustomEffectMap ) 
{
	static DWORD IsMap = 0;
    static DWORD IsEffectTrue = 0x008C4984; // 1.04E ENG
    static DWORD Next = 0x008C4986; // 1.04E ENG

    //
    _asm {
        mov ecx, dword ptr ds : [0x0E61E18]
        mov dword ptr ds : [0x0E61E18], ecx
        mov IsMap, ecx
    }
    // ---
    if ( IsMap == 0x36 ) 
	{
        _asm {jmp IsEffectTrue}
    }
	else if ( IsMap >= 0x64 ) 
	{
        _asm {jmp IsEffectTrue}
    }
    else 
	{
        _asm {jmp Next}
    }

}

void __declspec(naked) CSetPlayerSwimStop()
{
	static DWORD CReturn = 0x0054EE7F;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],84//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) CSetPlayerSwimWalk()
{
	static DWORD CReturn = 0x0054FFBE;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],84//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) CRenderCharacterBackItem_Swim()
{
	static DWORD CReturn = 0x005880B4;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],84//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void __declspec(naked) CPlayWalkSound_Swim()
{
	static DWORD CReturn = 0x00560CED;
	_asm
	{
			CMP DWORD PTR DS:[0xE61E18],7
			je ReturnLoad
			CMP DWORD PTR DS:[0xE61E18],84//ID del Mapa
			je ReturnLoad
			// ---
		ReturnLoad :
		// ---
		jmp CReturn
	}
}

void CCustomMap::Load()
{
	SetOp((LPVOID)0x00520ECF, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x00520F1F, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x0063E743, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x00640EB2, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x007D2DD9, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x007E6C0F, (LPVOID)LoadMapName, ASM::CALL);
	SetOp((LPVOID)0x0084AEF7, (LPVOID)LoadMapName, ASM::CALL);

	SetRange((LPVOID)0x0047FC85, 131, ASM::NOP);
	SetOp((LPVOID)0x0047FC85, (LPVOID)LoadInterfaceMapName, ASM::JMP);

	//Bypass in terrains files
	SetByte((LPVOID)0x0062EBF8,0xEB);
	SetByte((LPVOID)0x0062EBFE,0xEB);
	SetByte((LPVOID)0x0062EE42,0xEB);
	SetByte((LPVOID)0x0062EE48,0xEB);
	SetByte((LPVOID)0x0062EEE5,0xEB);
	SetByte((LPVOID)0x0062EEEB,0xEB);
	
	//Increase terrains amount
	SetByte((LPVOID)0x0062EBF7,0x69);
	SetByte((LPVOID)0x0062EE41,0x69);
	SetByte((LPVOID)0x0062EEE4,0x69);

	//Set Music
	SetOp((LPVOID)0x004DADA4,(LPVOID)LoadMapMusic,ASM::CALL);

	SetCompleteHook(0xE9, 0x0054EE78, &CSetPlayerSwimStop);
	SetCompleteHook(0xE9, 0x0054FFB7, &CSetPlayerSwimWalk);
	SetCompleteHook(0xE9, 0x005880AD, &CRenderCharacterBackItem_Swim);
	SetCompleteHook(0xE9, 0x00560CE6, &CPlayWalkSound_Swim);

	//SetRange((LPVOID)0x008C497D, 5, ASM::NOP);
	//SetOp((LPVOID)0x008C497D, (LPVOID)CustomEffectMap, ASM::JMP);
}