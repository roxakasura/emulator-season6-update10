#include "StdAfx.h"
#include "ExpandedCharacters.h"
#include "SceneControl.h"
#include "Import.h"
#include "Offset.h"
#include "Util.h"
#include "Pet.h"
#include "Protect.h"
#include "User.h"
#include "InfoLog.h"

GCCharacterS13 JGetPlayer;

GCCharacterS13::GCCharacterS13( )
{
	this->lpInfoPlayer.clear( );
}

GCCharacterS13::~GCCharacterS13( )
{
}

//----- (00587380) --------------------------------------------------------
char CNewSkinChangeDB(WORD a1)
{
	BYTE result;

	if( 287 == a1 || 280 == a1)
	{
		return 32;
	}

	result = 16 * ((a1 >> 3) & 1) | (a1 >> 5) | 8 * ((a1 >> 4) & 1);

	return result;
}

//----- (00405230) --------------------------------------------------------
int CNewClassPacketRecv(BYTE a1)
{
	int result;

	if( a1 > 6 )
	{
		result = 109 + a1;
	}
	else
	{
		result = a1 & 7;
	}
	return result;
}

//----- (00405230) --------------------------------------------------------
int CNewClassPacket(BYTE a1)
{
	int result;

	if( a1 == 8 || a1 == 32)
	{
		result = a1 & 8;
	}
	else
	{
		result = a1 & 7;
	}

	return result;
}

int sub_402A80(int a1)
{
	if ( pPlayerState == 4 ) //Select Character
	{
		JGetPlayer.GCPlayerInfo( );
	}
	return 1;
}

void CharacterTeleportSeason13(int a1, float a2,float a3,float a4)
{
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{	
		int v5 = pGetPreviewStruct(pPreviewThis(),a1);
		int v8 = v5 + 776;	  
		if ( v5 )  
		{    
			*(float *)(v8 + 156) = 0.30000001;	
			*(float *)(v8 + 160) = 0.30000001;
			*(float *)(v8 + 164) = 0.30000001;
			*(float *)(v8 + 252) = a2;
			*(float *)(v8 + 256) = a3;
			*(float *)(v8 + 272) = a4;
		}
	}
}

void GetColorCTCode( BYTE CTLCODE )
{
	int v9; // [sp+4h] [bp-8h]@1

	if ( CTLCODE & 1 )
	{
		v9 = -256;
	}
	else if ( CTLCODE & 0x12 )
	{
		v9 = -14165505;
	}
	else if ( CTLCODE & 4 )
	{
		v9 = -1;
	}
	else if ( CTLCODE & 8 )
	{
		v9 = -16776961;
	}
	else if ( CTLCODE& 0x20 )
	{
		v9 = -16776961;
	}
	else
	{
		v9 = -1;
	}

	SetTextColorByHDC(pTextThis( ), v9);
}

int GetStatus( BYTE GuildStatus )
{
	if ( GuildStatus <= 64 )
	{
		if ( GuildStatus == 64 )
		{
			return 1301;
		}
		else if ( GuildStatus )
		{
			if ( GuildStatus != 32 )
				goto LABEL_29;
			return 1302;
		}
		else
		{
			return 1330;
		}
	}
	if ( GuildStatus == 128 )
	{
LABEL_29:
		return 1300;
	}
	else if ( GuildStatus == 255 )
	{
		return 488;
	}
	
	return 488;
}

void GCCharacterS13::JGPlayerHide( )
{
	int JCGetModelP;
	char Level[256];
	char Status[256];
	float x;
	float X;
	float y = 51;
	float w = 150;
	float h = 35;
	float currentx;
	int ActiveCreateChar = 0;

	if(TypeSelectChar == 2)
	{
		x = 447 + pWinWidth / pWinHeightReal - 640;

		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
		{
			EnableAlphaTest( 1 );
			glColor3f(1.0, 1.0, 1.0);

			for ( int i = 0 ; i < MAX_PLAYER_SLOT ; i ++ )
			{
				ZeroMemory(Level, sizeof(Level));

				y = ((h + 5) * i) + 51;

				JCGetModelP = pGetPreviewStruct(pPreviewThis(), i);

				if( SelectedHero == i )
				{
					currentx = (double)0.4489941001;
				}
				else
				{
					currentx = (double)0.0012999833;
				}

				if ( pCheckMouseOver((int) x,(int) y,(int) w,(int) h) )
				{
					currentx = (double)0.6719940305;

					if ( *(BYTE *)(JCGetModelP + 780) )
					{
						SelectedCharacter = i;
					}

					if ( *(BYTE*)0x8793386 )
					{
						currentx = (double)0.4489941001;
						PlayBuffer(25, 0, 0);

						if ( *(BYTE *)(JCGetModelP + 780) )
						{
							CharacterTeleportSeason13(i, 13629.0, 12339.0, 90.0);
							SelectedHero = i;
							*(BYTE*)0x8793386 = 0;
						}
						else
						{
							sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
						}
					}
				}

				if ( !*(BYTE *)(JCGetModelP + 780) )
				{
					RenderBitmap(98000, x, y, w, h, currentx, 0.9330000877, 0.2199999839, 0.05000000075, 1, 1, 0);

					pSetFont(pTextThis( ), (int)pFontBold);
					pSetTextColor(pTextThis(), 255, 255, 255, 180);
					pDrawText(pTextThis( ), x, y + 12, "Empty Character Slot", w, 0, (LPINT)3, 0);
					pSetFont(pTextThis( ), (int)pFontNormal);
				}
				else
				{
					RenderBitmap(98000, x, y, w, h, currentx, 0.9330000877, 0.2199999839, 0.05000000075, 1, 1, 0);
					pSetFont(pTextThis( ), (int)pFontNormal2);

					std::map<int, PMSG_CHARACTER_LIST>::iterator it = this->lpInfoPlayer.find( i );

					if(it != this->lpInfoPlayer.end())
					{
						pSetTextColor(pTextThis(), 255, 255, 255, 180);
						pDrawText(pTextThis(), x + 11, y + 7, (char *)GetClassnameIndex((unsigned __int8)CNewSkinChangeDB( it->second.CharSetClass )), 150, 0, (LPINT)0, 0);
		
						wsprintf(Status, "( %s )", pGetTextLine(pTextLineThis, GetStatus(it->second.GuildStatus)));
						pSetTextColor(pTextThis(), 255, 255, 255, 180);
						pDrawText(pTextThis(), x + 50, y + 7, Status, 90, 0, (LPINT)4, 0);

						//pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
						GetColorCTCode( it->second.CtlCode );
						pDrawText(pTextThis(), x + 35, y + 20, it->second.Name, 150, 0, (LPINT)1, 0);
						SetTextColorByHDC(pTextThis( ), -1);

						wsprintf(Level, "Level: %d", it->second.Level);
						pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
						pDrawText(pTextThis(), x - 50, y + 20, Level, 190, 0, (LPINT)4, 0);
					}
				}
			}
		}
	}
//}
}

void GCCharacterS13::GCPlayerInfo( )
{
	VAngle Angle; // [sp+30h] [bp-14h]@4
	// ---
	signed int v5; // ST14_4@4
	signed int v6; // eax@4
	int v48; // [sp+3Ch] [bp-8h]@4
	int v49; // [sp+40h] [bp-4h]@4
	char nameClass[254];

	for(int n = 0 ; n < MAX_PLAYER_SLOT; n++)
	{
		DWORD ViewportAddress = pGetPreviewStruct(pPreviewThis(), n);

		if(!ViewportAddress)
		{
			continue;
		}

		int index = *(WORD*)(ViewportAddress+0x7E);

		std::map<int, PMSG_CHARACTER_LIST>::iterator it = this->lpInfoPlayer.find( n );

		if( it != this->lpInfoPlayer.end( ) )
		{
			Angle.X = *(float*)(ViewportAddress + 1028);
			Angle.Y = *(float*)(ViewportAddress + 1032);
			Angle.Z = *(float*)(ViewportAddress + 1036) + *(float*)(ViewportAddress + 0x3E8) + 350.0f;

			pGetPosFromAngle(&Angle, &v48, &v49);

			pSetFont(pTextThis( ), (int)pFontBold);
			pSetBackgroundTextColor(pTextThis( ), 50, 50, 50, 200);
			GetColorCTCode( it->second.CtlCode );
			pDrawText(pTextThis( ), v48 - 10, v49, it->second.Name, 0, 0, (LPINT)1, 0);
			
			SetTextColorByHDC(pTextThis( ), -1);
			ZeroMemory(nameClass, sizeof(nameClass));
			wsprintf(nameClass, "%s %d", (char *)GetClassnameIndex((unsigned __int8)sub_587380( it->second.CharSet[0] )), it->second.Level);
			pDrawText(pTextThis( ), v48 - 25, v49 + 15, nameClass, 0, 0, (LPINT)1, 0);
		}
	}
}

//----- (004055D0) --------------------------------------------------------
int sub_4055D0(int TButton, signed int x, int y)
{
	JCSpiriteSetPosition(TButton + 400, TButton, -100, -100, 3);
	JCSpiriteSetPosition(TButton + 624, TButton, -100, -100, 3);
	JCSpiriteSetPosition(TButton + 232, TButton, -100, -100, 3);
	JCSpiriteSetPosition(TButton + 64, TButton, -100, -100, 3);
	JCSpiriteSetPosition(TButton + 1072, TButton, -100, -100, 3);
	return JCSpiriteSetPosition(TButton + 848, TButton, -100, -100, 3);
}

__declspec(naked) void JGetSelectCharButton( )
{
	static DWORD Addr_main = 0x004056D0;
	static DWORD TButton;
	static DWORD X;
	static DWORD Y;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP+0xC]
		MOV Y,EAX
		MOV ECX,DWORD PTR SS:[EBP+0x8]
		MOV X,ECX
		MOV ECX,DWORD PTR SS:[EBP-0xC]
		MOV TButton,ECX
	}

	sub_4055D0( TButton, X, Y );

	_asm
	{
		JMP[Addr_main]
	}
}

int GCCharacterS13::JPlayerAddList( PMSG_CHARACTER_CREATE_RECV * lpMsg )
{
	signed int result; // eax@10
	DWORD v10; // [sp+20h] [bp-10h]@8
	float v11; // [sp+1Ch] [bp-14h]@2
	float v12; // [sp+24h] [bp-Ch]@0
	float v13; // [sp+28h] [bp-8h]@0

	PMSG_CHARACTER_LIST * lpInfo;

	std::map<int, PMSG_CHARACTER_LIST>::iterator it;

	if ( lpMsg->result == 1 )
	{
		if( lpMsg->slot >= 0 && lpMsg->slot < MAX_PLAYER_SLOT)
		{
			lpInfo = new PMSG_CHARACTER_LIST;
			lpInfo->slot = lpMsg->slot;
			memcpy(lpInfo->Name, lpMsg->name,sizeof(lpInfo->Name));
			lpInfo->Level = lpMsg->level;
			lpInfo->GuildStatus = 255;
			lpInfo->CtlCode = 0;
			lpInfo->CharSet[0] = lpMsg->Class;

			for(int o = 1 ; o < 18 ; o++)
			{
				lpInfo->CharSet[o] = 0xFF;
			}

			it = this->lpInfoPlayer.find (lpMsg->slot);

			if(it != this->lpInfoPlayer.end())
			{
				this->lpInfoPlayer.erase ( it );
			}
			this->lpInfoPlayer.insert(std::pair<int, PMSG_CHARACTER_LIST >(lpMsg->slot, *(PMSG_CHARACTER_LIST*)lpInfo));
		}
	}
	return 1;
}

int GCCharacterS13::JPlayerList( PMSG_CHARACTER_LIST_RECV * lpMsg )
{
	int v4; // ST1C_4@11
	DWORD result; // eax@12
	int v10; // [sp+18h] [bp-1Ch]@5
	float v11; // [sp+1Ch] [bp-18h]@5
	float v12; // [sp+20h] [bp-14h]@0
	float v13; // [sp+24h] [bp-10h]@0
	int PlayerSlot;
	int PlayerSelect;

	sub_63CB40( );
	sub_4D5130( lpMsg->ClassCode );
	
	if ( pPlayerState == 4 )
		*(DWORD*)0xE61E18 = 74;

	this->lpInfoPlayer.clear( );
	PlayerSlot = 0;
	PlayerSelect = 10;
	
	for ( int n = 0 ; n < lpMsg->count ; n++ )
	{
		PMSG_CHARACTER_LIST * lpInfo = (PMSG_CHARACTER_LIST *) (((BYTE*)lpMsg) + sizeof(PMSG_CHARACTER_LIST_RECV) + (sizeof(PMSG_CHARACTER_LIST) * n));

		if(lpInfo->slot >= 0 && lpInfo->slot < MAX_PLAYER_SLOT)
		{
			this->lpInfoPlayer.insert(std::pair<int, PMSG_CHARACTER_LIST >(lpInfo->slot, *(PMSG_CHARACTER_LIST*)lpInfo));
		}

		v10 = (unsigned __int8)sub_587380(lpInfo->CharSetClass);

		v11 = 0.0;

		switch ( lpInfo->slot )
		{
			case 0:
				v12 = 8172.84083;
				v13 = 19265.57287;
				v11 = 90.0;
				break;
			case 1:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			case 2:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			case 3:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			case 4:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			default:
			break;
		}

		v4 = JCSetModelCoord(lpInfo->slot, v10, 0, v12, v13, v11);//-- Agrega Personaje con Coordenada

		*(WORD *)(v4 + 130) = lpInfo->Level;

		*(BYTE *)(v4 + 21) = lpInfo->CtlCode;

		sub_9CF1C0((char *)(v4 + 56), lpInfo->Name, sizeof(lpInfo->Name));

		*(BYTE *)(v4 + 66) = 0;

		gCustomPet.PreviewCharSet(lpInfo->slot, &lpInfo->CharSet[ 1 ], 0, 0);//-- Mostrar Equipamiento

		*(BYTE *)(v4 + 24) = lpInfo->GuildStatus;

		gInfoLog.Output(LOG_CHAT, "Slot: %d - Name: %s - Level: %d", lpInfo->slot, lpInfo->Name, lpInfo->Level);
	}

	*(DWORD*)0x87935A4 = 51;

	pWarehouseExSet(pWarehouseExThis(pWindowThis()), lpMsg->ExtWarehouse);

	result = GetTickCount();
	*(DWORD*)0xE8CB30 = result;
	return result;
}

signed int JGCreateCharRecv( int JCCHARACTER )
{
	signed int result; // eax@10
	DWORD v10; // [sp+20h] [bp-10h]@8
	float v11; // [sp+1Ch] [bp-14h]@2
	float v12; // [sp+24h] [bp-Ch]@0
	float v13; // [sp+28h] [bp-8h]@0
	BYTE Slot;


	if ( *(BYTE *)(JCCHARACTER + 4) == 1 )
	{
		v11 = 0.0;
		Slot = *(BYTE *)(JCCHARACTER + 15);
		switch ( Slot )
		{
			case 0:
				v12 = 8172.84083;
				v13 = 19265.57287;
				v11 = 90.0;
				break;
			case 1:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			case 2:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			case 3:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			case 4:
				v12 = 0.0;
				v13 = 0.0;
				v11 = 0.0;
				break;
			default:
			break;
		}

		sub_57D760(*(BYTE *)(JCCHARACTER + 15));
		JCSetModelCoord(*(BYTE *)(JCCHARACTER + 15), (unsigned __int8)*(BYTE*)0x7BD0483, *(BYTE*)0x7BD0484, v12, v13, v11);

		v10 = pGetPreviewStruct(pPreviewThis(), *(BYTE *)(JCCHARACTER + 15));

		if ( v10 )
		{
			*(WORD *)(v10 + 130) = *(WORD *)(JCCHARACTER + 16);
			*(BYTE *)(v10 + 19) = sub_587380(*(BYTE *)(JCCHARACTER + 18));
			sub_9CF1C0((char *)(v10 + 56), (const void *)(JCCHARACTER + 5), 0xAu);
			*(BYTE *)(v10 + 66) = 0;
		}

		*(DWORD*)0x87935A4 = 53;

		sub_668520((char *)sub_482B70( ));
		sub_4057B0((char *)sub_482B70( ) + 32632);
		result = sub_402AD0((char *)sub_482B70() + 36744);
	}
	else
	{
		result = *(BYTE *)(JCCHARACTER + 4);
		if ( *(BYTE *)(JCCHARACTER + 4) )
		{
			if ( *(BYTE *)(JCCHARACTER + 4) == 2 )
			{
				result = sub_484A10(sub_482B70( ), 55, 0);
			}
		}
		else
		{
			result = sub_484A10(sub_482B70(), 54, 0);
		}
	}
	return result;
}

//----- (0063D5E0) --------------------------------------------------------
int PushBackPlayer( int a4 )
{
	signed int v4; // ST04_4@5
	int v5; // eax@5
	int v6; // eax@5
	int result; // eax@4
	char v12; // [sp+0h] [bp-Ch]@1

	v12 = *(BYTE *)(a4 + 4);

	if ( v12 )
	{
		if ( v12 == 1 )
		{
			v6 = sub_96A4C0(sub_402BC0( ), *(DWORD*)0xE60B4C);
			sub_57D760(*(WORD *)(v6 + 126));

			std::map<int, PMSG_CHARACTER_LIST>::iterator it = JGetPlayer.lpInfoPlayer.find( *(DWORD*)0xE60B4C );

			if(it != JGetPlayer.lpInfoPlayer.end())
			{
				JGetPlayer.lpInfoPlayer.erase ( it );
			}

			result = sub_484A10(sub_482B70( ), 96, 0);
		}
		else if ( v12 == 3 )
		{
			result = sub_484A10(sub_482B70( ), 98, 0);
		}
		else
		{
			result = sub_484A10(sub_482B70( ), 137, 0);
		}
	}
	else
	{
		result = sub_484A10(sub_482B70( ), 146, 0);
	}
	return result;
}
// E60B4C: using guessed type int dword_E60B4C;

__declspec(naked) void EnsambladorRescate1( )
{
	static DWORD Addr_JMP = 0x00641C71;
	static int Main; // [sp+50h] [bp-24h]@3
	static int v20; // [sp+3Ch] [bp-38h]@12

	_asm
	{
		MOV EAX, DWORD PTR SS:[EBP-0x24]
		MOV Main, EAX
		MOV EDX,DWORD PTR SS:[EBP-0x38]
		MOV v20, EDX
	}

	*(BYTE *)(v20 + 19) = CNewSkinChangeDB(*(WORD*)(Main + 36));

	_asm
	{
		JMP[Addr_JMP]
	}
}

//----- (005875C0) --------------------------------------------------------
char CGetCharacterClass(unsigned __int8 a1)
{
	char v2; // [sp+7h] [bp-5h]@1
	char v3; // [sp+9h] [bp-3h]@1
	char v4; // [sp+Ah] [bp-2h]@1
	char v5; // [sp+Bh] [bp-1h]@1

	v2 = 0;
	v3 = ((signed int)a1 >> 3) & 1;
	v4 = ((signed int)a1 >> 4) & 1;

	v5 = (a1 == 8||a1 == 32) ? a1 & 8 : a1 & 7;

	switch ( v5 )
	{
	case 0:
		if ( v4 )
		{
			v2 = 11;
		}
		else if ( v3 )
		{
			v2 = 7;
		}
		else
		{
			v2 = 0;
		}
		break;
	case 1:
		if ( v4 )
		{
			v2 = 12;
		}
		else if ( v3 )
		{
			v2 = 8;
		}
		else
		{
			v2 = 1;
		}
		break;
	case 2:
		if ( v4 )
		{
			v2 = 13;
		}
		else if ( v3 )
		{
			v2 = 9;
		}
		else
		{
			v2 = 2;
		}
		break;
	case 3:
		if ( v4 )
			v2 = 14;
		else
			v2 = 3;
		break;
	case 4:
		if ( v4 )
			v2 = 15;
		else
			v2 = 4;
		break;
	case 5:
		if ( v4 )
		{
			v2 = 16;
		}
		else if ( v3 )
		{
			v2 = 10;
		}
		else
		{
			v2 = 5;
		}
		break;
	case 6:
		if ( v4 )
			v2 = 17;
		else
			v2 = 6;
		break;
	case 7:
		if ( v4 )
		{
			v2 = 22;
		}
		else
		{
			v2 = 20;
		}
		break;
	case 8:
		if ( v4 )
		{
			v2 = 25;
		}
		else
		{
			v2 = 23;
		}
	break;
	case 9:
		if ( v4 )
		{
			v2 = 29;
		}
		else
		{
			v2 = 25;
		}
	break;
	default:
		return v2;
	}

	return v2;
}

//----- (00587620) --------------------------------------------------------
int GetClassnameIndex (unsigned __int8 a4)
{
	int result; // eax@2
	char v5; // [sp+1h] [bp-1h]@1

	v5 = CGetCharacterClass( a4 );

	if ( v5 )
	{
		switch ( v5 )
		{
			case 1: //-- Dark Knight
				result = (int)pGetTextLine(pTextLineThis, 21);
				break;
			case 2: //-- Elf
				result = (int)pGetTextLine(pTextLineThis, 22);
				break;
			case 3: //-- Magic Gladiator
				result = (int)pGetTextLine(pTextLineThis, 23);
				break;
			case 4: //-- Dark Lord
				result = (int)pGetTextLine(pTextLineThis, 24);
				break;
			case 5: //-- Summoner
				result = (int)pGetTextLine(pTextLineThis, 1687);
				break;
			case 6: //-- Rage Fighter
				result = (int)pGetTextLine(pTextLineThis, 3150);
				break;
			case 7: //-- Soul Master
				result = (int)pGetTextLine(pTextLineThis, 25);
				break;
			case 8: //-- Blade Knight
				result = (int)pGetTextLine(pTextLineThis, 26);
				break;
			case 9: //-- Muse Elf
				result = (int)pGetTextLine(pTextLineThis, 27);
				break;
			case 10: //-- Bloody Summoner
				result = (int)pGetTextLine(pTextLineThis, 1688);
				break;
			case 11: //-- Grand Master
				result = (int)pGetTextLine(pTextLineThis, 1669);
				break;
			case 12: //-- Blade Master
				result = (int)pGetTextLine(pTextLineThis, 1668);
				break;
			case 13: //-- High Elf
				result = (int)pGetTextLine(pTextLineThis, 1670);
				break;
			case 14: //-- Dual Master
				result = (int)pGetTextLine(pTextLineThis, 1671);
				break;
			case 15: //-- Lord Emperor
				result = (int)pGetTextLine(pTextLineThis, 1672);
				break;
			case 16: //-- Dimension Master
				result = (int)pGetTextLine(pTextLineThis, 1689);
				break;
			case 17: //-- Fist Master
				result = (int)pGetTextLine(pTextLineThis, 3151);
				break;
			default: //-- Error Code :
				result = (int)pGetTextLine(pTextLineThis, 2305);
			break;
		}
	}
	else
	{
		//-- Dark Wizard
		result = (int)pGetTextLine(pTextLineThis, 20);
	}
	return result;
}


void GCCharacterS13::OpenCharacterScene()
{
	LoadBitmapA("Interface\\GFx\\CharacterSelect_I10.tga", 98000, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\GFx\\CharacterSelect_Button.tga", 51519, 0x2601, 0x2901, 1, 0);

	((void(__cdecl*)())0x006312E0)();
}

void GCCharacterS13::initCharacter( )
{
	//SetCompleteHook(0xE9, 0x00641C5B, &EnsambladorRescate1);
	//SetCompleteHook(0xE9, 0x006420D8, &EnsambladorRescate2);

	//SetCompleteHook(0xE8, 0x00586F37, &CNewClassPacketRecv);
	//SetCompleteHook(0xE8, 0x00586F52, &CNewClassPacketRecv);
	//SetCompleteHook(0xE8, 0x00586F6D, &CNewClassPacketRecv);
	//SetCompleteHook(0xE8, 0x00586F88, &CNewClassPacketRecv);
	//SetCompleteHook(0xE8, 0x00586FA3, &CNewClassPacketRecv);
	//
	//SetCompleteHook(0xE9, 0x00405230, &CNewClassPacket);
	
	//-- ampliar más personajes para crear 10 slots 100%
	//SetByte(0x004057E5, 10);
	//SetByte(0x00405881, 10);
	//SetByte(0x004D6F66, 10);
	//SetByte(0x004D7075, 9);
	//SetByte(0x004D70AA + 6, 9);
	//SetByte(0x004D71DD + 3, 10);
	//SetByte(0x004D72C4 + 3, 10);

	//-- Remover Dialog Info en personaje
	//SetByte(0x00402106, 0);
	//SetDouble(0xD25508, 1);
	//--
	//SetDword(0x004D6C2C, JSelectChar.RenderSelect.MapSelectChar);//Change MAPA
	//SetCompleteHook(0xE8, 0x004D712A, &CameraChar);//Render Camera SelectChar
	SetCompleteHook(0xE9, 0x0063D3D0, &JGCreateCharRecv);
	SetCompleteHook(0xE9, 0x0063D5E0, &PushBackPlayer);
	//-- Fix name pj
	SetCompleteHook(0xE9, 0x00587620, &GetClassnameIndex);
	SetCompleteHook(0xE9, 0x005875C0, &CGetCharacterClass);
	/*						PRO ROXEMULATOR PRECISA DESSA	 S13	*/

	//gInterface.BindObject(CharacterSelect_Button1, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button2, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button3, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button4, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button5, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button6, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button7, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button8, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button9, 51519, 150, 35, -1, -1);
	//gInterface.BindObject(CharacterSelect_Button10, 51519, 150, 35, -1, -1);
	//
	//SetCompleteHook(0xE8, 0x004D6C3E, this->OpenCharacterScene);
	//SetCompleteHook(0xE8, 0x004D5EE6, this->SelectChar);
	//SetCompleteHook(0xE9, 0x004D84E0, &SelectCharacterPosition);
	//SetDword(0x004D6C73, 0);
	//SetByte(0x00402106, 0);
}

__declspec(naked) void SelectCharacterPosition()
{
   CharacterSelect360S13();

	static DWORD Return_Adress = 0x004D84ED;

	_asm
	{
	 PUSH EBP                            
	 MOV EBP,ESP
	 SUB ESP,0x0D8
	 MOV BYTE PTR SS:[EBP-0x1],0x0
	jmp [Return_Adress]
	}
}

void CharacterCharacteristicsS13(int a1,float a2)
{
	char Level[256];
	char Status[256];
	float X = 471;
	float Y = 51;
	int This = (int)sub_482B70() + 36744;
	int Hero00 = This;
//
	std::map<int, PMSG_CHARACTER_LIST>::iterator it = JGetPlayer.lpInfoPlayer.find( a1 );

	gInterface.DrawFormat(eGold, X + 35, Y + 20 + a2, 190, 2, it->second.Name);

	gInterface.DrawFormat(eWhite180, X + 11, Y + 7 + a2, 190, 0, (char *)GetClassnameIndex((unsigned __int8)CNewSkinChangeDB( it->second.CharSetClass )));
	
	wsprintf(Status, "( %s )", pGetTextLine(pTextLineThis, GetStatus(it->second.GuildStatus)));
	gInterface.DrawFormat(eWhite180, X - 50, Y + 7 + a2, 190, 4, Status);

	wsprintf(Level, "Level: %d", it->second.Level);
	pSetTextColor(pTextThis(), 255, 189, 25, 0xFF);
	pDrawText(pTextThis(), X - 50, Y + 20 + a2, Level, 190, 0, (LPINT)4, 0);

}

void CharacterSelect360S13()
{
	if (*(DWORD*)(MAIN_SCREEN_STATE) == SwitchCharacter)
	{
		for (int i = 0; i < 10; i++)
		{	
			int v5 = pGetPreviewStruct(pPreviewThis(),i);
			int v8 = v5 + 776;
			if (gInterface.IsWorkZone(161) ||
				gInterface.IsWorkZone(162) ||
				gInterface.IsWorkZone(163) ||
				gInterface.IsWorkZone(164) ||
				gInterface.IsWorkZone(165) ||
				gInterface.IsWorkZone(166) ||
				gInterface.IsWorkZone(167) ||
				gInterface.IsWorkZone(168) ||
				gInterface.IsWorkZone(169) ||
				gInterface.IsWorkZone(170) )
			{	
				*(float *)(v8 + 272) = *(float *)(v8 + 272) + 5.0;  //AQUI É A VELOCIDADE DO GIRO DA 360
			}
			else
			{
				*(float *)(v8 + 272) = 70;
			}
		}
	}
}

void GCCharacterS13::SelectChar()
{
	gObjUser.Refresh();
	if(*(DWORD*)(MAIN_SCREEN_STATE) == ObjState::SwitchCharacter)
	{
		float X = 471;
		float Y = 51;
//
		if ( !*(BYTE *)((int)sub_482B70() + 33948) )
		{
//Create Select
//0
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button1, 471, 51, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, Y + 13, 210, 3, "Empty Character Slot");
			}
//1
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button2, 471, 88, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 88 + 13, 210, 3, "Empty Character Slot");
			}
//2
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button3, 471, 125, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 125 + 13, 210, 3, "Empty Character Slot");
			}

//3
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button4, 471, 162, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 162 +13, 210, 3, "Empty Character Slot");
			}
//4
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button5, 471, 199, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 199 + 13, 210, 3, "Empty Character Slot");
			}

//5
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),5) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button6))
				{
					if (gInterface.Data[CharacterSelect_Button6].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button6, 471, 236, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button6, 471, 236, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button6, 471, 236, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 236 + 13, 210, 3, "Empty Character Slot");
			}

//6
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),6) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button7))
				{
					if (gInterface.Data[CharacterSelect_Button7].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button7, 471, 273, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button7, 471, 273, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button7, 471, 273, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 273 + 13, 210, 3, "Empty Character Slot");
			}

//7
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),7) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button8))
				{
					if (gInterface.Data[CharacterSelect_Button8].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button8, 471, 310, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button8, 471, 310, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button8, 471, 310, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 310 + 13, 210, 3, "Empty Character Slot");
			}

//8
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),8) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button9))
				{
					if (gInterface.Data[CharacterSelect_Button9].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button9, 471, 347, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button9, 471, 347, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button9, 471, 347, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 347 + 13, 210, 3, "Empty Character Slot");
			}

//9
			if ( !*(BYTE *)(pGetPreviewStruct(pPreviewThis(),9) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button10))
				{
					if (gInterface.Data[CharacterSelect_Button10].OnClick)
					{
						gInterface.DrawButton(CharacterSelect_Button10, 471, 384, 0, 70);
						sub_483B20((int)sub_482B70(), (int)sub_482B70() + 33936);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button10, 471, 384, 0, 35);
					}
				}
				else
				{
					gInterface.DrawButton(CharacterSelect_Button10, 471, 384, 0, 0);
				}
				gInterface.DrawFormat(eWhite180, X-29, 384 + 13, 210, 3, "Empty Character Slot");
			}


//Character Select
//0
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),0) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button1))
				{
					
					if (gInterface.Data[CharacterSelect_Button1].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 0;

						CharacterTeleportSeason13(0, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
					}
					else
					{
						if(SelectedHero == 0)
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 35);
						}
					}

					if(SelectedHero == 0)
					{
						SelectedCharacter = 0;
					}
				}
				else
				{
					if(SelectedHero == 0)
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button1, 471, Y, 0, 0);
					}
				}
				CharacterCharacteristicsS13(0,0);
			}
//1
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),1) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button2))
				{
					
					if (gInterface.Data[CharacterSelect_Button2].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 1;

						CharacterTeleportSeason13(1, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button2, 471,  Y+37, 0, 70);
					}
					else
					{
						if(SelectedHero == 1)
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 35);
						}
					}
					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 1)
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button2, 471, Y + 37, 0, 0);
					}
				}
				CharacterCharacteristicsS13(1,37);				
			}
//2
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),2) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button3))
				{
					
					if (gInterface.Data[CharacterSelect_Button3].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 2;

						CharacterTeleportSeason13(2, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
					}
					else
					{
						if(SelectedHero == 2)
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 2)
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button3, 471,  Y + 74, 0, 0);
					}
				}
				CharacterCharacteristicsS13(2,74);
			}
//3
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),3) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button4))
				{
					
					if (gInterface.Data[CharacterSelect_Button4].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 3;

						CharacterTeleportSeason13(3, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
					}
					else
					{
						if(SelectedHero == 3)
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 35);
						}
					}
					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 3)
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button4, 471,  Y + 111, 0, 0);
					}
				}

				CharacterCharacteristicsS13(3,111);
			}
//4
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),4) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button5))
				{
					
					if (gInterface.Data[CharacterSelect_Button5].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 4;

						CharacterTeleportSeason13(4, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
					}
					else
					{
						if(SelectedHero == 4)
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 4)
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button5, 471,  Y + 148, 0, 0);
					}
				}

				CharacterCharacteristicsS13(4,148);
			}

//5
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),5) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button6))
				{
					
					if (gInterface.Data[CharacterSelect_Button6].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 5;

						CharacterTeleportSeason13(5, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 70);
					}
					else
					{
						if(SelectedHero ==5)
						{
							gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 5)
					{
						gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button6, 471,  Y + 185, 0, 0);
					}
				}

				CharacterCharacteristicsS13(5,185);
			}

//6
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),6) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button7))
				{
					
					if (gInterface.Data[CharacterSelect_Button7].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 6;

						CharacterTeleportSeason13(6, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button7, 471,  Y + 222, 0, 70);
					}
					else
					{
						if(SelectedHero == 6)
						{
							gInterface.DrawButton(CharacterSelect_Button7, 471,  Y + 222, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button7, 471,  Y + 222, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 6)
					{
						gInterface.DrawButton(CharacterSelect_Button7, 471,  Y + 222, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button7, 471,  Y + 222, 0, 0);
					}
				}

				CharacterCharacteristicsS13(6,222);
			}

//7
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),7) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button8))
				{
					
					if (gInterface.Data[CharacterSelect_Button8].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 7;

						CharacterTeleportSeason13(7, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button8, 471,  Y + 259, 0, 70);
					}
					else
					{
						if(SelectedHero == 7)
						{
							gInterface.DrawButton(CharacterSelect_Button8, 471,  Y + 259, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button8, 471,  Y + 259, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 7)
					{
						gInterface.DrawButton(CharacterSelect_Button8, 471,  Y + 259, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button8, 471,  Y + 259, 0, 0);
					}
				}

				CharacterCharacteristicsS13(7,259);
			}

//8
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),8) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button9))
				{
					
					if (gInterface.Data[CharacterSelect_Button9].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 8;

						CharacterTeleportSeason13(8, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(9, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button9, 471,  Y + 296, 0, 70);
					}
					else
					{
						if(SelectedHero == 8)
						{
							gInterface.DrawButton(CharacterSelect_Button9, 471,  Y + 296, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button9, 471,  Y + 296, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 8)
					{
						gInterface.DrawButton(CharacterSelect_Button9, 471,  Y + 296, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button9, 471,  Y + 296, 0, 0);
					}
				}

				CharacterCharacteristicsS13(8,296);
			}

//9
			if ( *(BYTE *)(pGetPreviewStruct(pPreviewThis(),9) + 780) )
			{
				if (gInterface.IsWorkZone(CharacterSelect_Button10))
				{
					
					if (gInterface.Data[CharacterSelect_Button10].OnClick)
					{
						PlayBuffer(25, 0, 0);
						SelectedHero = 9;

						CharacterTeleportSeason13(9, 8172.84083, 19265.57287, 90.0);
						CharacterTeleportSeason13(0, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(1, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(2, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(3, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(4, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(5, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(6, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(7, 0.0, 0.0, 0.0);
						CharacterTeleportSeason13(8, 0.0, 0.0, 0.0);

						gInterface.DrawButton(CharacterSelect_Button10, 471,  Y + 333, 0, 70);
					}
					else
					{
						if(SelectedHero == 9)
						{
							gInterface.DrawButton(CharacterSelect_Button10, 471,  Y + 333, 0, 70);
						}
						else
						{
							gInterface.DrawButton(CharacterSelect_Button10, 471,  Y + 333, 0, 35);
						}
					}

					SelectedCharacter = SelectedHero;
				}
				else
				{
					if(SelectedHero == 9)
					{
						gInterface.DrawButton(CharacterSelect_Button10, 471,  Y + 333, 0, 70);
					}
					else
					{
						gInterface.DrawButton(CharacterSelect_Button10, 471,  Y + 333, 0, 0);
					}
				}

				CharacterCharacteristicsS13(9,333);
			}
		}
	}
	((void(__cdecl*)())0x005BB0B0)();
}

void GCCharacterS13::SelectCharButton(DWORD Event)
{
	DWORD CurrentTick	= GetTickCount();
	// ----
	if(*(DWORD*)(MAIN_SCREEN_STATE) != ObjState::SwitchCharacter)
	{
		return;
	}
	// ----
	if( gInterface.IsWorkZone(CharacterSelect_Button1) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button1].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button1].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button1].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button1].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button2) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button2].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button2].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button2].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button2].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button3) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button3].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button3].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button3].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button3].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button4) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button4].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button4].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button4].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button4].EventTick = GetTickCount();
		// ----
		}
	else if( gInterface.IsWorkZone(CharacterSelect_Button5) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button5].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button5].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button5].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button5].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(CharacterSelect_Button6) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button6].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button6].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button6].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button6].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(CharacterSelect_Button7) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button7].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button7].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button7].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button7].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(CharacterSelect_Button8) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button8].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button8].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button8].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button8].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(CharacterSelect_Button9) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button9].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button9].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button9].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button9].EventTick = GetTickCount();
		// ----
	}
	else if( gInterface.IsWorkZone(CharacterSelect_Button10) )
	{
		DWORD Delay	= (CurrentTick - gInterface.Data[CharacterSelect_Button10].EventTick);
		// ----
		if( Event == WM_LBUTTONDOWN )
		{
			gInterface.Data[CharacterSelect_Button10].OnClick = true;
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button10].OnClick = false;
		// ----
		if( Delay < 500 )
		{
			return;
		}
		// ----
		gInterface.Data[CharacterSelect_Button10].EventTick = GetTickCount();
		// ----
	}

}