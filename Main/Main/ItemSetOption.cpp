
// SItemOption.cpp: implementation of the CSItemOption class.
//
//////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "ItemSetOption.h"
#include "CustomMessage.h"
#include "Offset.h"
#include "Util.h"
#include "Defines.h"
#include "Import.h"
#include "User.h"
#include "CustomGloves.h"
#include "TMemory.h"
#include "Protect.h"
#include "ItemTooltip.h"


CSItemOption gCItemSetOption;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSItemOption::CSItemOption()
{

}

CSItemOption::~CSItemOption()
{

}
int nuevaL1;
int nuevaL2;

void WzXor(BYTE *Buffer, int Size)
{
	BYTE Key[3] = { 0xFC, 0xCF, 0xAB };

	for (int i = 0; i < Size; ++i)
	{
		Buffer[i] ^= Key[i % 3];
	}
}

bool CSItemOption::LoadSetType(char * path)
{
	char ErrorBuff[255] = { 0 };

	FILE * hFile = fopen(path, "rb");

	if (hFile)
	{
		DWORD Checksum = 0;

		BYTE * Buffer = new BYTE[sizeof(this->m_ItemSetType)];

		fread(Buffer, sizeof(this->m_ItemSetType), 1, hFile);

		fread(&Checksum, 4, 1, hFile);

		fclose(hFile);

		BYTE * FixBuffer = Buffer;

		int BlockSize = sizeof(ITEM_SETTYPE_INFO);

		for (int i = 0; i < MAX_ITEM; ++i)
		{
			WzXor(FixBuffer, BlockSize);
			memcpy(&this->m_ItemSetType[i], FixBuffer, BlockSize);
			FixBuffer += BlockSize;
		}
		delete[] Buffer;
	}
	else
	{
		sprintf(ErrorBuff, "%s - File not exist.", path);
		MessageBoxA(*(HWND*)0x00E8C578, ErrorBuff, 0, 0);
		SendMessageA(*(HWND*)0x00E8C578, 2u, 0, 0);
	}

	return 1;
}

bool CSItemOption::LoadSetOption(char * path)
{
	char ErrorBuff[255] = { 0 };

	FILE * hFile = fopen(path, "rb");

	memset(gCItemSetOption.AccPlus, 0, sizeof(gCItemSetOption.AccPlus));

	if (hFile)
	{
		DWORD Checksum = 0;

		BYTE * Buffer = new BYTE[sizeof(gCItemSetOption.AccPlus)];

		fread(Buffer, sizeof(gCItemSetOption.AccPlus), 1, hFile);

		fread(&Checksum, 4, 1, hFile);

		fclose(hFile);

		BYTE * FixBuffer = Buffer;

		int BlockSize = sizeof(ITEM_SETOPTION_INFO);

		for (int i = 0; i < MAX_ITEM_SETOPTION; ++i)
		{
			WzXor(FixBuffer, BlockSize);
			memcpy(&gCItemSetOption.AccPlus[i], FixBuffer, BlockSize);
			FixBuffer += BlockSize;
		}

		delete[] Buffer;
	}
	else
	{
		sprintf(ErrorBuff, "%s - File not exist.", path);
		MessageBoxA(*(HWND*)0x00E8C578, ErrorBuff, 0, 0);
		SendMessageA(*(HWND*)0x00E8C578, 2u, 0, 0);
	}
	return 1;
}

bool CSItemOption::InitSetOptionName(char * Buffer, int ItemID, int AncientOption)
{
	int SetType = AncientOption % 4;

	if (SetType <= 0)
		return 0;

	BYTE SetIndex = this->GetSetIndexbyItem(ItemID, SetType);

	if (SetIndex >= 255 || SetIndex <= 0)
	{
		return 0;
	}

	memcpy(Buffer, this->GetSetOptionInfo(SetIndex)->name, 32);

	Buffer[strlen(Buffer)] = 32;
	Buffer[strlen(Buffer) + 1] = 0;

	return 1;
}

bool validarTabla(int SetCountEquipado, int OptionNumber)
{
	bool result; // eax@2

	if(SetCountEquipado == 2 && (OptionNumber == 0 || OptionNumber == 1))
	{
		result = true;
	}
	else if(SetCountEquipado == 3 && OptionNumber < 4)
	{
		result = true;
	}
	else if(SetCountEquipado == 4 && OptionNumber < 6)
	{
		result = true;
	}
	else if(SetCountEquipado == 5 && OptionNumber < 8)
	{
		result = true;
	}
	else if(SetCountEquipado == 6 && OptionNumber < 10)
	{
		result = true;
	}
	else if(SetCountEquipado == 7 && OptionNumber < 12)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}

int GItemIndex;

__declspec (naked) void GLItemIndex()
{
	static DWORD Main_Addrs = 0x005BFF75;

	_asm
	{
		MOV EAX,DWORD PTR SS:[EBP + 0x10]
		MOVSX ECX,WORD PTR DS:[EAX]
		MOV GItemIndex, ECX
	}

	if( GItemIndex == -1) 
		Main_Addrs = 0x007E3E65;
	else 
		Main_Addrs = 0x007E3E6C;

	_asm { JMP [Main_Addrs] }
}

__declspec (naked) void TextColorExeS15()
{
	static float colorR = 0.1372549019607843f;	//35
	static float colorG = 0.7607843137254902f;	//194
	static float colorB = 0.1137254901960784f;	//29
	static DWORD Addrs_JMP = 0x005BFF75;

	_asm
	{
		PUSH ECX
		FLD DWORD PTR DS:[colorB]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[colorG]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[colorR]
		FSTP DWORD PTR SS:[ESP]
		CALL DWORD PTR DS:[0x00D224F0]
		JMP [Addrs_JMP]
	}
}

__declspec (naked) void TextColorAccS15()
{
	//eExcellentS15   = Color4f(67, 204, 65),
	static float colorR = 0.1372549019607843f;	//35
	static float colorG = 0.7607843137254902f;	//194
	static float colorB = 0.1137254901960784f;	//29
	static DWORD Addrs_JMP = 0x005BFF75;

	_asm
	{
		PUSH ECX
		FLD DWORD PTR DS:[colorB]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[colorG]
		FSTP DWORD PTR SS:[ESP]
		PUSH ECX
		FLD DWORD PTR DS:[colorR]
		FSTP DWORD PTR SS:[ESP]
		CALL DWORD PTR DS:[0x00D224F0]//DS:[00D224F0]=6A9471E0 (OPENGL32.glColor3f)
		JMP [Addrs_JMP]
	}
}

__declspec (naked) void RemoveBackgroundAcc()
{
	static DWORD ThisText = 0x0041FE10;
	static DWORD TextRender = 0x004200B0;
	static DWORD TextRenderColor = 0x00420040;
	static DWORD Addrs_JMP = 0x005C0044;

	_asm
	{
		JMP [Addrs_JMP]
	}
}

__declspec (naked) void Desbordamiento()
{
	static DWORD Addrs_JMP = 0x005BFC77;

	_asm
	{
		JMP [Addrs_JMP]
	}
}

int getWidthSell()
{
	int t = 0;

	if (gInterface.item_post_ && pCursorX < 180)
	{
		if(gObjUser.PostItemID == ITEM(0,0) 
			|| (gObjUser.PostItemID >= ITEM(7,0) && gObjUser.PostItemID < ITEM(8,0)) 
			|| (gObjUser.PostItemID == ITEM(4,15) || gObjUser.PostItemID == ITEM(4,7))
			|| (gObjUser.PostItemID >= ITEM(12, 7) && gObjUser.PostItemID < ITEM(12, 36)) 
			|| (gObjUser.PostItemID >= ITEM(12, 44) && gObjUser.PostItemID <= ITEM(12, 143))
			|| (gObjUser.PostItemID >= ITEM(13, 0) && gObjUser.PostItemID != ITEM(13, 30)))
		{
			t = 40;
		}
		else if( gObjUser.PostItemID >= ITEM(9,0) && gObjUser.PostItemID < ITEM(12,0))
		{
			t = 50;
		}
		else if( gObjUser.PostItemID >= ITEM(0,1) && gObjUser.PostItemID < ITEM(1,0)|| gObjUser.PostItemID >= ITEM(3,0) && gObjUser.PostItemID < ITEM(5,0))
		{
			t = 80;
		}
		else
		{
			t = 60;
		}
	}
	return t;
}

void CSItemOption::ItemTooltipS15(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6)
{
	glColor4f(0.0, 0.0, 0.0, 0.80000001);
	pDrawBarForm(PosX, PosY, Width, Height, Arg5, Arg6); //central

	if(gProtect.m_MainInfo.HelperUpgradeSystem == 0)
	{
		glEnable(0xDE1u);
		glColor4f(0.0, 0.0, 0.0, 1.00000001);
		pDrawBarForm(PosX, PosY, 2, Height, Arg5, Arg6); //central
		pDrawBarForm(PosX + Width - 2, PosY, 2, Height, Arg5, Arg6); //central
		pDrawBarForm(PosX, PosY, Width, 2, Arg5, Arg6); //central
		pDrawBarForm(PosX, PosY + Height - 2, Width, 2, Arg5, Arg6); //central
		glEnable(0xDE1u);
		return;
	}

	float RightX = PosX - 1.0f;
	float LeftX = (PosX + Width) - 7.0f;
	float TopY = PosY - 1.0f;
	float DownY = (PosY + Height) - 7.0f;
	bool horizontal = true;
	bool vertical = true;
	//--
	float IniciarX = PosX - 1.0f;
	float w = 8.0f;
	//--
	float IniciarY = PosY - 1.0f;
	float H = 8.0f;

	pSetBlend(true);
	glColor3f(1.0, 1.0, 1.0);

	while(vertical || horizontal)
	{
		if(vertical)
		{
			IniciarX += 8.0f;

			if((IniciarX + w) > LeftX)
			{
				vertical = false;
				w = LeftX - IniciarX;
			}
			pDrawGUI(61512, IniciarX, TopY, w, 8.0f); //arriba

			pDrawGUI(61517, IniciarX, DownY, w, 8.0f); //abajo
		}
		//-- abajo
		if(horizontal)
		{
			IniciarY += 8.0f;

			if((IniciarY + H) > DownY)
			{
				horizontal = false;
				H = DownY - IniciarY;
			}

			pDrawGUI(61514, RightX, IniciarY, 8.0f, H); // Lado Izquierdo

			pDrawGUI(61515, LeftX, IniciarY, 8.0f, H); //Lado Derecho
		}
	}

	pDrawGUI(61511, RightX, TopY, 8.0f, 8.0f); //esquina arriba izquierda

	pDrawGUI(61513, LeftX, TopY, 8.0f, 8.0f); //esquina arriba derecha

	pDrawGUI(61516, RightX, DownY, 8.0f, 8.0f);  //esquina abajo izquierda

	pDrawGUI(61518, LeftX, DownY, 8.0f, 8.0f);  //esquina abajo derecha

	glEnable(0xDE1u);
}

void CSItemOption::RenderColor( int ColorTexto )
{
	SetTextColorByHDC(pTextThis(),-1);

	if(gProtect.m_MainInfo.HelperUpgradeSystem == 0)
	{
		switch ( ColorTexto )
		{
			case 0:
			case TEXT_WHITE:
			case TEXT_WHITE_RED:
			case TEXT_WHITE_BLUE:
			case TEXT_WHITE_YELLOW:
				glColor3f(1.0, 1.0, 1.0);
				break;
			case TEXT_BLUE:
				glColor3f(0.5f, 0.69999999f, 1.0);
				break;
			case TEXT_GRAY:
				glColor3f(0.40000001f, 0.40000001f, 0.40000001f);
				break;
			case TEXT_GREN_BLUE:
				glColor3f(1.0, 1.0, 1.0);
				break;
			case TEXT_RED:
				glColor3f(1.0, 0.2f, 0.1);
				break;
			case TEXT_GOLD:
				glColor3f(1.0, 0.80000001f, 0.1);
				break;
			case TEXT_GREN:
				glColor3f(0.1, 1.0, 0.5f);
				break;
			case TEXT_PINK:
				glColor3f(1.0, 0.1, 1.0);
				break;
			case TEXT_PINK2:
				glColor3f(0.80000001f, 0.5, 0.80000001f);
				break;
			case TEXT_PURPLE:
				glColor3f(0.69999999f, 0.40000001f, 1.0);
				break;
			case TEXT_ORANGE:
				glColor3f(0.89999998f, 0.41999999f, 0.039999999f);
				break;
			default:
				break;
		}

		switch ( ColorTexto )
		{
			case TEXT_WHITE_RED:
				pSetBackgroundTextColor(pTextThis(), 0xA0u, 0, 0, 0xFFu);
				break;
			case TEXT_WHITE_BLUE:
				pSetBackgroundTextColor(pTextThis(), 0, 0, 0xA0u, 0xFFu);
				break;
			case TEXT_WHITE_YELLOW:
				pSetBackgroundTextColor(pTextThis(), 0xA0u, 0x66u, 0, 0xFFu);
				break;
			case TEXT_GREN_BLUE:
				pSetBackgroundTextColor(pTextThis(), 0x3Cu, 0x3Cu, 0xC8u, 0xFFu);
				pSetTextColor(pTextThis(), 0, 0xFFu, 0, 0xFFu);
				break;
			case 15: //-- DeepPink1
				pSetBackgroundTextColor(pTextThis(), 255, 20, 147, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 16: //-- RoyalBlue1
				pSetBackgroundTextColor(pTextThis(), 72, 118, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 17: //-- SlateBlue1
				pSetBackgroundTextColor(pTextThis(), 131, 111, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 18: //-- Azure2
				pSetBackgroundTextColor(pTextThis(), 224, 238, 238, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 19: //-- DarkSlateGray1
				pSetBackgroundTextColor(pTextThis(), 151, 255, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0, 0, 0, 0xFFu);
				break;
			case 20: //-- SlateGray1
				pSetBackgroundTextColor(pTextThis(), 198, 226, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 21: //-- MistyRose1
				pSetBackgroundTextColor(pTextThis(), 255, 228, 225, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 22: //-- LightSlateBlue
				pSetBackgroundTextColor(pTextThis(), 132, 112, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 23: //-- DeepSkyBlue1
				pSetBackgroundTextColor(pTextThis(), 0, 191, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			case 24: //-- Turquoise1
				pSetBackgroundTextColor(pTextThis(), 0, 245, 255, 0xFFu);
				pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
				break;
			default:
				sub_4200F0_Addr(pTextThis(), 0);
				break;
		}
		return;
	}

	switch ( ColorTexto )
	{
		case 0:
		//case 5:
		case 7:
		case 8:
			glColor3f(1.0, 1.0, 1.0);
			break;
		case 1:
			glColor3f(0.5, 0.69999999, 1.0);
			break;
		case 10:
			glColor3f(0.40000001, 0.40000001, 0.40000001);
			break;
		case 9:
			glColor3f(0.13725490, 0.76078431, 0.11372549);
			break;
		case 2:
			glColor3f(1.0, 0.2, 0.1);
			break;
		case 3:
			glColor3f(1.0, 0.80000001, 0.1);
			break;
		case 4:
			glColor3f(0.13725490, 0.76078431, 0.11372549);
			break;
		case 5:
			glColor3f(0.82745098, 0.0, 0.0);
			//pSetBackgroundTextColor(pTextThis(), 0xA0u, 0, 0, 0xFFu);
			break;
		case 6:
			glColor3f(1.0, 0.1, 1.0);
			break;
		case 11:
			glColor3f(0.80000001, 0.5, 0.80000001);
			break;
		case 12:
			glColor3f(0.69999999, 0.40000001, 1.0);
			break;
		case 13:
			glColor3f(0.89999998, 0.41999999, 0.039999999);
			break;
		default:
			break;
	}

	switch ( ColorTexto )
	{
		/*case 5:
			//pSetBackgroundTextColor(pTextThis(), 0xA0u, 0, 0, 0xFFu);
			break;*/
		case 7:
			pSetBackgroundTextColor(pTextThis(), 0, 0, 0xA0u, 0xFFu);
			break;
		case 8:
			pSetBackgroundTextColor(pTextThis(), 0xA0u, 0x66u, 0, 0xFFu);
			break;
		default:
			sub_4200F0_Addr(pTextThis(), 0);
			break;
	}
}

void ItemTooltipRender(int x, int y, int nCount, int witd, int height,int type, int Align)
{
	tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
	int * ColorTexto = (int*)NewAddressData1;
	int * LineWeight = (int*)NewAddressData2;
	
	HDC hDC = GetDC(*(HWND*)(0x00E8C578));
	HGDIOBJ font = pFontNormal;
	//--
	SIZE psizl; // [sp+90h] [bp-1Ch]@1
	int counter1; // [sp+88h] [bp-24h]@1
	int counter2; // [sp+A8h] [bp-4h]@1
	float cRenderW; // [sp+8Ch] [bp-20h]@1
	float cRenderH; // [sp+98h] [bp-14h]@1
	float cRenderX; // [sp+A0h] [bp-Ch]@22
	float cRenderY; // [sp+9Ch] [bp-10h]@26
	//--
	SIZE psizl2; // [sp+90h] [bp-1Ch]@1
	int rCounter1; // [sp+88h] [bp-24h]@1
	int rCounter2; // [sp+A8h] [bp-4h]@1
	float cRender2W; // [sp+8Ch] [bp-20h]@1
	float cRender2X; // [sp+A0h] [bp-Ch]@22
	float SaltoLine;
	//--
	float v64; // [sp+68h] [bp-44h]@53
	float v71; // [sp+84h] [bp-28h]@1
	float v76; // [sp+9Ch] [bp-10h]@26

	float SellItem = getWidthSell();

	if ( gInterface.item_post_ && pCursorX < 180 )
	{
		y = y - SellItem;
	}

	nCount = GInfo.nInformationOP(nCount, GItemIndex);

	v71 = (( pCheckWindow(pWindowThis(), 57) == true ) ? 1.3 : 1.1 );
	
	rCounter1 = 0;
	rCounter2 = 0;
	cRender2X = (double) (signed int) x;
	cRender2W = 0.0;
	psizl2.cx = 0;
	psizl2.cy = 0;
	//-- principal
	counter1 = 0;
	counter2 = 0;
	cRenderX = (double) (signed int) x;
	cRenderW = 0.0;
	cRenderH = 0.0;
	psizl.cx = 0;
	psizl.cy = 0;
	
	for(int n = 0; n < nCount; ++n)
	{
		if((n >= nuevaL1  && n < nuevaL2) && (nuevaL1 != -1 && nuevaL2 != -1)) 
		{ 
			if(!TooltipLine[n]) 
			{ 
				nuevaL2 = n;
				continue;
			}

			if( LineWeight[n] == 1 )
				font = pFontBold;
			else
				font = pFontNormal;

			SelectObject(hDC, font);
		
			GetTextExtentPoint32(hDC, TooltipLine[n], strlen(TooltipLine[n]), &psizl2);

			if ( cRender2W < (double)(signed int)psizl2.cx )
				cRender2W = (double)(signed int)psizl2.cx;

			if ( lstrlenA(TooltipLine[n]) < 2 )
				++rCounter2;
			else
				++rCounter1;
			continue; 
		}

		if(!TooltipLine[n]) { nCount = n; break; }

		if( LineWeight[n] == 1 )
			font = pFontBold;
		else
			font = pFontNormal;

		SelectObject(hDC, font);
		
		GetTextExtentPoint32(hDC, TooltipLine[n], strlen(TooltipLine[n]), &psizl);

		if ( cRenderW < (double)(signed int)psizl.cx )
			cRenderW = (double)(signed int)psizl.cx;
		if (lstrlenA(TooltipLine[n]) < 2 )
			++counter2;
		else
			++counter1;
	}

	if( nuevaL1 > 0 )
	{
		y = ( y + (double) (rCounter1 * psizl2.cy) + (double)(signed int) psizl2.cy / 2.0 * (double)rCounter2 )  / ( pWinHeightReal / v71 );

		cRender2W = (double) (( witd > 0 ) ? ((double) witd / pWinWidthReal + (double) witd / pWinWidthReal ) : (( cRender2W / pWinWidthReal ) + 4.0 ));

		cRender2X = (double) cRender2X - cRender2W / 2.0;

		if ( (double) pWinWidth / pWinWidthReal < (double) cRender2X + cRender2W )
			cRender2X = (double)pWinWidth / pWinWidthReal - cRender2W - 1.0;
	}

	cRenderY = (double) (signed int) ( (y < 0 ) ? 10 : y );

	cRenderH = (double)(counter1 * psizl.cy) + (double)(signed int)psizl.cy / 2.0 * (double)counter2;
	
	cRenderH = ( (gInterface.item_post_ && pCursorX < 180) ? ( SellItem + ( cRenderH / ( pWinHeightReal / v71 ))) : ( cRenderH / ( pWinHeightReal / v71 )));

	pSetBlend(true);

	cRenderW = (double) (( witd > 0 ) ? ( (double)witd / pWinWidthReal + (double)witd / pWinWidthReal ) : ( ( cRenderW / pWinWidthReal ) + 4.0 ));

	cRenderX = (double) (( nuevaL1 > 0 ) ? ( cRender2X - cRenderW - 2.8 ) : ( cRenderX - cRenderW / 2.0 ));

	cRenderX = (( cRenderX < 0 ) ? 1.0 : cRenderX);

	cRender2X = (( cRenderX == 1.0 ) ? ( cRenderX + cRenderW + 2.8) : cRender2X);

	cRenderX = (((double) pWinWidth / pWinWidthReal < (double) cRenderX + cRenderW ) ? ((double) pWinWidth / pWinWidthReal - cRenderW - 1.0 ) : cRenderX );

	v76 = (double) (( type == 8 ) ? ( cRenderY - cRenderH) : cRenderY );
	SaltoLine = (double) (( type == 8 ) ? ( cRenderY - cRenderH) : cRenderY );

	if ( Align == 1 && nCount > 0 )
	{
		if( nuevaL1 > 0 ) { gCItemSetOption.ItemTooltipS15(cRender2X, cRenderY, cRender2W, cRenderH, 0.0, 0); }

		gCItemSetOption.ItemTooltipS15(cRenderX, cRenderY, cRenderW, cRenderH, 0.0, 0);

		if ( gInterface.item_post_ && pCursorX < 180 )
		{
			gInterface.DrawItemIMG(cRenderX + ( cRenderW / 2 ) - ( (SellItem - 20) / 2 ) , cRenderY, SellItem - 20, SellItem - 20 , gObjUser.PostItemID,gObjUser.PostItemLV, gObjUser.PostItemExc, gObjUser.PostItemExc, 0);
		}
	}
	//-- Escritura
	for( int k = 0; k < nCount; ++k )
	{
		//-- Texto Secundario Ancestral
		if ( k >= nuevaL1 && k < nuevaL2 ) 
		{ 
			if(LineWeight[k])
				font = pFontBold;
			else
				font = pFontNormal;

			pSetFont(pTextThis(), (int)font);

			v64 = 0.0;

			if( ((DWORD) TooltipLine[k] != 10 && (DWORD) TooltipLine[k] != 32 || (DWORD) TooltipLine[k]) && lstrlenA( TooltipLine[k]) > 2 )
			{
				gCItemSetOption.RenderColor( ColorTexto[k] );
				pDrawText( pTextThis(), (double)(cRender2X + 1), SaltoLine, TooltipLine[k], ( cRender2W - 1.0f), 0, (LPINT) height, 0 );
				
				SelectObject(hDC, font);
				GetTextExtentPoint32(hDC, TooltipLine[k], strlen( TooltipLine[k]), &psizl2 );

				v64 = (double)(signed int)psizl2.cy / pWinHeightReal / 1.0;
				
			}
			else
			{
				SelectObject(hDC, font);
				GetTextExtentPoint32(hDC, TooltipLine[k], strlen( TooltipLine[k]), &psizl2 );

				if ( lstrlenA(TooltipLine[k]) > 2 )
					v64 = (double)(signed int)psizl2.cy / pWinHeightReal / 1.0;
				else
					v64 = (double)(signed int)psizl2.cy / pWinHeightReal / 2.0;
			}
			SaltoLine = v64 * v71 + SaltoLine;
			continue; 
		}
		//-- Texto Principal
		if( LineWeight[k] )
			font = pFontBold;
		else
			font = pFontNormal;

		pSetFont(pTextThis(), (int)font);
		
		v64 = 0.0;
		if( ((DWORD) TooltipLine[k] != 10 && ( DWORD) TooltipLine[k] != 32 || (DWORD) TooltipLine[k] ) && lstrlenA(TooltipLine[k]) > 2 )
		{
			gCItemSetOption.RenderColor( ColorTexto[k] );

			if( ( k > 0 ) && ( gInterface.item_post_ && pCursorX < 180 ) )
			{
				pDrawText( pTextThis(), (double)(cRenderX + 1), v76 + SellItem, TooltipLine[k], (cRenderW - 1.0f), 0, (LPINT)height, 0 );
			}
			else
			{
				pDrawText( pTextThis(), (double)(cRenderX + 1), v76, TooltipLine[k], ( cRenderW - 1.0f ), 0, (LPINT)height, 0 );
			}
			SelectObject(hDC, font);
			GetTextExtentPoint32(hDC, TooltipLine[k], strlen(TooltipLine[k]), &psizl);
			v64 = (double)(signed int)psizl.cy / pWinHeightReal / 1.0;
		}
		else
		{
			SelectObject(hDC, font);
			GetTextExtentPoint32(hDC, TooltipLine[k], strlen(TooltipLine[k]), &psizl);

			if ( lstrlenA(TooltipLine[k]) > 2 )
				v64 = (double)(signed int)psizl.cy / pWinHeightReal / 1.0;
			else
				v64 = (double)(signed int)psizl.cy / pWinHeightReal / 2.0;
		}

		v76 = v64 * v71 + v76;
	}

	glColor4f(1.0, 1.0, 1.0, 1.0);
	pGLSwitch();
}

bool CSItemOption::isEquiped(lpCharObj lpObj, int id, BYTE Ancien)
{
	BYTE AncientOption;

	for (int n = 0; n < INVENTORY_WEAR_SIZE; n++)
	{
		lpItemObj lpEquipment = &lpObj->pEquipment[n];

		if (lpEquipment->ItemID == id)
		{
			AncientOption = lpEquipment->AncientOption % 4;

			if( AncientOption == 1 || AncientOption == 2)
			{
				if (this->m_ItemSetType[id].set[AncientOption - 1] == Ancien)
				{
					return true;
				}
			}
			return false;
		}
	}
	return false;
}

int CSItemOption::InitSetOptionsTooltip(ObjectItem * lpItem, int CurrentLine, char a4)
{
	tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
	int * ColorTexto = (int*)NewAddressData1;
	int * LineWeight = (int*)NewAddressData2;
	int NextLine = CurrentLine;
	int ItemSetEquipado = 0;
	bool ItemEquipado = false;

	BYTE Ancien = lpItem->AncientOption % 4;

	if (Ancien != 1 && Ancien != 2)
	{
		nuevaL1 = -1;
		nuevaL2 = -1;
		return CurrentLine;
	}

	BYTE SetIndex = this->GetSetIndexbyItem(lpItem->ItemID, Ancien);

	ITEM_SETOPTION_INFO* lpInfo = this->GetSetOptionInfo(SetIndex);
	
	lpCharObj lpObj = &*(ObjectCharacter*)(*(DWORD*)MAIN_CHARACTER_STRUCT);
	
	if ((lpInfo == 0 || lpObj == 0) || this->m_ItemSetType[lpItem->ItemID].set[0] == 0 && this->m_ItemSetType[lpItem->ItemID].set[1] == 0)
	{
		nuevaL1 = -1;
		nuevaL2 = -1;
		return CurrentLine;
	}

	char SaveName[128] = { 0 };
	
	memcpy(SaveName, TooltipLine[0], 100);

	for (int n = 0; n < INVENTORY_WEAR_SIZE; n++)
	{
		lpItemObj lpEquipment = &lpObj->pEquipment[n];
	
		if (lpEquipment == lpItem)
			ItemEquipado = true;
		
		if (lpEquipment->ItemID != -1)
		{
			BYTE AncientOption = lpEquipment->AncientOption % 4;

			if ( this->m_ItemSetType[lpEquipment->ItemID].set[AncientOption -1] == SetIndex )
			{
				ItemSetEquipado++;
			}
		}
	}

	wsprintf(TooltipLine[NextLine++], "\n");
	wsprintf(TooltipLine[NextLine], "%s", pGetTextLine(pTextLineThis, 878));
	ColorTexto[NextLine] = TEXT_GOLD;
	LineWeight[NextLine++] = 1;
	
	wsprintf(TooltipLine[NextLine++], "\n");

	wsprintf(TooltipLine[NextLine], "%s Set", lpInfo->name);
	ColorTexto[NextLine] = TEXT_GREN;
	LineWeight[NextLine++] = 0;

	int SetCount = 0;

	for (int n = 0; n < MAX_ITEM; n++)
	{
		if (this->m_ItemSetType[n].set[0] == SetIndex || this->m_ItemSetType[n].set[1] == SetIndex)
		{
			ItemBmdStruct* ItemInfo = pGetItemBmdStruct(n);

			SetCount++;

			wsprintf(TooltipLine[NextLine], "%s %s", lpInfo->name,ItemInfo->Name);

			if( isEquiped(lpObj, n, SetIndex) )
			{
				if(ItemEquipado)
				{
					ColorTexto[NextLine] = TEXT_GREN;
				}
				else
				{
					ColorTexto[NextLine] = TEXT_GRAY;
				}
			}
			else
			{
				ColorTexto[NextLine] = TEXT_GRAY;
			}
		
			LineWeight[NextLine++] = 0;
		}
	}

	wsprintf(TooltipLine[NextLine++], "\n");
	
	nuevaL1 = NextLine;
	//--
	wsprintf(TooltipLine[NextLine], "%s", pGetTextLine(pTextLineThis, 159));
	ColorTexto[NextLine] = TEXT_GOLD;
	LineWeight[NextLine++] = 1;
	//--
	wsprintf(TooltipLine[NextLine++], "\n");
	//--
	int imprimirTag[6] = {-1,-1,-1,-1,-1,-1};

	for (int n = 0; n < MAX_SET_ITEM_OPTION_TABLE; n++)
	{
		if (lpInfo->option[n] != -1 && lpInfo->value[n] != -1)
		{
			if( (n == 0 || n == 1) && imprimirTag[0] == -1)
			{
				imprimirTag[0] = 1;
				wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, 877), 2);
				ColorTexto[NextLine] = TEXT_GREN;
				LineWeight[NextLine++] = 0;
			}
			else if( (n == 2 || n == 3) && imprimirTag[1] == -1)
			{
				imprimirTag[1] = 1;
				wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, 877), 3);
				ColorTexto[NextLine] = TEXT_GREN;
				LineWeight[NextLine++] = 0;
			}
			else if( (n == 4 || n == 5) && imprimirTag[2] == -1)
			{
				imprimirTag[2] = 1;
				wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, 877), 4);
				ColorTexto[NextLine] = TEXT_GREN;
				LineWeight[NextLine++] = 0;
			}
			else if( (n == 6 || n == 7) && imprimirTag[3] == -1)
			{
				imprimirTag[3] = 1;
				wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, 877), 5);
				ColorTexto[NextLine] = TEXT_GREN;
				LineWeight[NextLine++] = 0;
			}
			else if( (n == 8 || n == 9) && imprimirTag[4] == -1)
			{
				imprimirTag[4] = 1;
				wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, 877), 6);
				ColorTexto[NextLine] = TEXT_GREN;
				LineWeight[NextLine++] = 0;
			}
			else if( (n == 10 || n == 11) && imprimirTag[5] == -1)
			{
				imprimirTag[5] = 1;
				wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, 877), 7);
				ColorTexto[NextLine] = TEXT_GREN;
				LineWeight[NextLine++] = 0;
			}

			wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis, this->GetAncientTextIndex(lpInfo->option[n])), (unsigned char) lpInfo->value[n]);

			if ( validarTabla(ItemSetEquipado, n))
			{
				if(ItemEquipado)
				{
					ColorTexto[NextLine] = TEXT_BLUE;
				}
				else
				{
					ColorTexto[NextLine] = TEXT_GRAY;
				}
			}
			else
			{
				ColorTexto[NextLine] = TEXT_GRAY;
			}
			LineWeight[NextLine++] = 0;
		}
	}

	for (int n = 0; n < MAX_SET_ITEM_FULL_OPTION_TABLE; n++)
	{
		if (lpInfo->fulloption[n] != -1 && lpInfo->fullvalue[n] != -1)
		{
			wsprintf(TooltipLine[NextLine], pGetTextLine(pTextLineThis,this->GetAncientTextIndex(lpInfo->fulloption[n])), (unsigned char)lpInfo->fullvalue[n]);

			if (ItemSetEquipado >= n && ItemSetEquipado >= SetCount)
			{
				if( ItemEquipado )
					ColorTexto[NextLine] = TEXT_BLUE;
				else
					ColorTexto[NextLine] = TEXT_GRAY;
			}
			else
			{
				ColorTexto[NextLine] = TEXT_GRAY;
			}
			LineWeight[NextLine++] = 0;
		}
	}

	nuevaL2 = NextLine;
	//--
	if (NextLine > 28)
	{
		memcpy(TooltipLine[0], SaveName, 100);
		ColorTexto[0] = TEXT_GREN_BLUE;
	}

	return NextLine;
}

void CSItemOption::RemoveDuplicatesUnsorted(int arr[][3], int Length)
{
	for (int i = 0; i < Length; i++)
	{
		for (int j = i + 1; j < Length;)
		{
			if (arr[i][1] == arr[j][1])
			{
				for (int k = j; k < Length; k++)
				{
					arr[k][0] = arr[k + 1][0];
					arr[k][1] = arr[k + 1][1];
					arr[k][2] = arr[k + 1][2];
				}
				Length--;
			}
			else
			{
				j++;
			}
		}
	}
}

void CSItemOption::InitInfoTooltip(int PosX, int PosY)
{
	if (this->unknow39812 && (this->unknow39816[144] > 0 || this->unknow39816[145] > 0))
	{
		tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
		int * ColorTexto = (int*)NewAddressData1;
		int * LineWeight = (int*)NewAddressData2;

		int Line = 1;

		wsprintf(TooltipLine[0], "\n");
		ColorTexto[0] = 0;
		LineWeight[0] = 0;

		wsprintf(TooltipLine[1], "\n");
		ColorTexto[1] = 0;
		LineWeight[Line++] = 0;

		wsprintf(TooltipLine[Line], "\n");
		ColorTexto[Line] = 0;
		LineWeight[Line++] = 0;
		
		lpCharObj lpObj = &*(ObjectCharacter*)(*(DWORD*)MAIN_CHARACTER_STRUCT);

		int CheckItemTable[INVENTORY_WEAR_SIZE][3] = { {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1},{-1,-1,-1},{-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1}, {-1,-1,-1} };
		int UsedPath[INVENTORY_WEAR_SIZE] = { 0,0,0,0,0,0,0,0,0,0,0,0 };

		for (int n = 0; n < INVENTORY_WEAR_SIZE; n++)
		{
			lpItemObj lpEquipment = &lpObj->pEquipment[n];

			if ((lpEquipment->AncientOption % 4) == 1 || (lpEquipment->AncientOption % 4) == 2)
			{
				BYTE SetIndex = this->GetSetIndexbyItem(lpEquipment->ItemID, lpEquipment->AncientOption % 4);

				if (SetIndex != CheckItemTable[n][1])
				{
					CheckItemTable[n][0] = lpEquipment->ItemID;
					CheckItemTable[n][1] = SetIndex;
					CheckItemTable[n][2] = (lpEquipment->AncientOption % 4);
				}
			}
		}

		this->RemoveDuplicatesUnsorted(CheckItemTable, INVENTORY_WEAR_SIZE);

		for (int o = 0; o < 3; o++)
		{
			int TempChecked[INVENTORY_WEAR_SIZE] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

			for (int n = 0; n < INVENTORY_WEAR_SIZE; n++)
			{
				lpItemObj lpEquipment = &lpObj->pEquipment[n];

				bool Checked = false;

				for (int i = 0; i < INVENTORY_WEAR_SIZE; i++)
				{
					if (lpEquipment->ItemID == TempChecked[i])
					{
						Checked = true;
						break;
					}
				}

				if (Checked != true)
				{
					if (this->GetSetIndexbyItem(lpEquipment->ItemID, lpEquipment->AncientOption % 4) == CheckItemTable[o][1])
					{
						TempChecked[n] = lpEquipment->ItemID;
						UsedPath[o]++;
					}
				}
			}
		}		

		for (int o = 0; o < 3; o++)
		{
			if (CheckItemTable[o][1] <= 0 || CheckItemTable[o][1] >= 255)
			{
				continue;
			}

			ITEM_SETOPTION_INFO* lpInfo = this->GetSetOptionInfo(CheckItemTable[o][1]);

			lpCharObj lpObj = &*(ObjectCharacter*)(*(DWORD*)MAIN_CHARACTER_STRUCT);

			if (lpInfo == 0 )
			{
				continue;
			}

			int SetCount = this->GetCountSetPath(CheckItemTable[o][0], CheckItemTable[o][2]);

			if (UsedPath[o] < 2)
			{
				continue;
			}

			wsprintf(TooltipLine[Line], "%s - %s", lpInfo->name, gCustomMessage.GetMessageB(159));
			ColorTexto[Line] = TEXT_GOLD;
			LineWeight[Line++] = 1;

			for (int n = 0; n < 12; n++)
			{
				if (lpInfo->option[n] != -1 && lpInfo->value[n] != -1)
				{
					if ( validarTabla(UsedPath[o], n))
					{
						wsprintf(TooltipLine[Line], gCustomMessage.GetMessageB(this->GetAncientTextIndex(lpInfo->option[n])), (unsigned char)lpInfo->value[n]);
						ColorTexto[Line] = TEXT_GREN;
						LineWeight[Line++] = 0;
					}
				}
			}
			for (int n = 0; n < 5; n++)
			{
				if (lpInfo->fulloption[n] != -1 && lpInfo->fullvalue[n] != -1)
				{			
					if (UsedPath[o] >= n && UsedPath[o] >= SetCount)
					{
						wsprintf(TooltipLine[Line], gCustomMessage.GetMessageB(this->GetAncientTextIndex(lpInfo->fulloption[n])), (unsigned char)lpInfo->fullvalue[n]);
						ColorTexto[Line] = TEXT_GREN;
						LineWeight[Line++] = 0;
					}
				}
			}
			wsprintf(TooltipLine[Line++], "\n");
		}
		pMultiLineTooltip(PosX + 95, PosY + 40, Line, 0, 3, 0, 1);
	}
}

BYTE CSItemOption::GetSetIndexbyItem(int itemindex, int type)
{
	if (itemindex < 0 || itemindex >= MAX_ITEM)
	{
		return 0;
	}

	int origin = (type - 1);

	if (origin < 0 || origin >= 2)
	{
		return 0;
	}

	return this->m_ItemSetType[itemindex].set[origin];
}

int CSItemOption::GetCountSetPath(int itemindex, int type)
{
	if (itemindex < 0 || itemindex >= MAX_ITEM)
	{
		return 0;
	}

	int origin = (type - 1);

	if (origin < 0 || origin >= 2)
	{
		return 0;
	}

	int Count = 0;

	int Type1 = this->GetSetIndexbyItem(itemindex, type);

	for (int n = 0; n < MAX_ITEM; n++)
	{
		if (this->m_ItemSetType[n].set[origin] == Type1)
		{
			Count++;
		}
	}

	return Count;
}

ITEM_SETOPTION_INFO* CSItemOption::GetSetOptionInfo(int index)
{
	if (index < 1 || index > MAX_ITEM_SETOPTION)
	{
		return 0;
	}
	return &gCItemSetOption.AccPlus[index];
}

int CSItemOption::GetAncientTextIndex(BYTE OptionIndex)
{
	int Index = OptionIndex + 168;

	switch (OptionIndex)
	{
		case SET_ITEM_OPTION_ADD_STRENGTH:
		case SET_ITEM_OPTION_ADD_DEXTERITY:
		case SET_ITEM_OPTION_ADD_ENERGY:
		case SET_ITEM_OPTION_ADD_VITALITY:
		case SET_ITEM_OPTION_ADD_LEADERSHIP:
		case SET_ITEM_OPTION_ADD_MIN_PHYSI_DAMAGE:
		case SET_ITEM_OPTION_ADD_MAX_PHYSI_DAMAGE:
			Index = OptionIndex + 950;
			break;
		case SET_ITEM_OPTION_MUL_MAGIC_DAMAGE:
			Index = 632;
			break;
		case SET_ITEM_OPTION_ADD_PHYSI_DAMAGE:
		case SET_ITEM_OPTION_MUL_ATTACK_SUCCESS_RATE:
		case SET_ITEM_OPTION_ADD_DEFENSE:
		case SET_ITEM_OPTION_ADD_MAX_LIFE:
		case SET_ITEM_OPTION_ADD_MAX_MANA:
		case SET_ITEM_OPTION_ADD_MAX_BP:
		case SET_ITEM_OPTION_ADD_BP_RECOVERY:
		case SET_ITEM_OPTION_ADD_CRITICAL_DAMAGE_RATE:
		case SET_ITEM_OPTION_ADD_CRITICAL_DAMAGE:
		case SET_ITEM_OPTION_ADD_EXCELLENT_DAMAGE_RATE:
		case SET_ITEM_OPTION_ADD_EXCELLENT_DAMAGE:
		case SET_ITEM_OPTION_ADD_SKILL_DAMAGE:
		case SET_ITEM_OPTION_ADD_DOUBLE_DAMAGE_RATE:
			Index = OptionIndex + 949;
			break;
		case SET_ITEM_OPTION_ADD_IGNORE_DEFENSE_RATE:
			Index = 970;
			break;
		case SET_ITEM_OPTION_MUL_SHIELD_DEFENSE:
			Index = 984;
			break;
		case SET_ITEM_OPTION_MUL_TWO_HAND_PHYSI_DAMAGE:
			Index = 983;
			break;
		case SET_ITEM_OPTION_ADD_PHYSI_DAMAGE_BY_STRENGTH:
		case SET_ITEM_OPTION_ADD_PHYSI_DAMAGE_BY_DEXTERITY:
		case SET_ITEM_OPTION_ADD_DEFENSE_BY_DEXTERITY:
		case SET_ITEM_OPTION_ADD_DEFENSE_BY_VITALITY:
		case SET_ITEM_OPTION_ADD_MAGIC_DAMAGE_BY_ENERGY:
		case SET_ITEM_OPTION_ADD_ICE_DAMAGE:
		case SET_ITEM_OPTION_ADD_POISON_DAMAGE:
		case SET_ITEM_OPTION_ADD_LIGHTNING_DAMAGE:
		case SET_ITEM_OPTION_ADD_FIRE_DAMAGE:
		case SET_ITEM_OPTION_ADD_EARTH_DAMAGE:
		case SET_ITEM_OPTION_ADD_WIND_DAMAGE:
		case SET_ITEM_OPTION_ADD_WATER_DAMAGE:
			Index = OptionIndex + 947;
			break;
		default:
			return Index;
	}

	return Index;
}
// ----------------------------------------------------------------------------------------------
bool CSItemOption::BMDLoad(char * path)
{
	char ErrorBuff[255] = { 0 };

	int File = pFileOpen(path, "rb");

	if (File)
	{
		int iTemp = 0;
		int iSize = 0;
		int iLenCount = MAX_SETOPT_LINE;

		pFileRead((int)&gCItemSetOption.m_SetOptionData[iSize], MAX_BSETOPT_SIZE, 1, File);
		pFileRead((int)&iTemp, 4, 1, File);
		pFileClose(File);
		pFileCRC((int)&gCItemSetOption.m_SetOptionData[iSize], iLenCount << 6, 0xA2F1);
		{
			for (int i = 0; i < MAX_SETOPT_COUNT; i++)
			{
				pFileDec((int)&gCItemSetOption.m_SetOptionData[iSize], iLenCount);
				iSize += iLenCount;
			}
		}
	}
	else
	{
		sprintf(ErrorBuff, "%s - File not exist.", path);
		MessageBox(0,ErrorBuff,"MuOnline WARNING.!!!",MB_OK | MB_ICONERROR);
		ExitProcess(0);
	}

	gCItemSetOption.LoadSetOption(path);

	return true;
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent1()
{
	_asm
	{
		MOV ECX, gCItemSetOption.m_dwSetOptionAddress
			LEA EDX, [EAX + ECX]
			JMP gCItemSetOption.m_dwJmpReturn1
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent2()
{
	_asm
	{
		MOV ECX, gCItemSetOption.m_dwSetOptionAddress

			LEA EDX, [EAX + ECX]
			JMP gCItemSetOption.m_dwJmpReturn2
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent3()
{
	_asm
	{
		MOV EDX, gCItemSetOption.m_dwSetOptionAddress
			LEA EAX, [ECX + EDX]
			JMP gCItemSetOption.m_dwJmpReturn3
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent4()
{
	_asm
	{
		MOV EAX, gCItemSetOption.m_dwSetOptionAddress
			LEA ECX, [EDX + EAX]
			JMP gCItemSetOption.m_dwJmpReturn4
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent5()
{
	_asm
	{
		MOV EAX, gCItemSetOption.m_dwSetOptionAddress
			LEA ECX, [EDX + EAX]
			JMP gCItemSetOption.m_dwJmpReturn5
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent6()
{
	_asm
	{
		MOV EDX, gCItemSetOption.m_dwSetOptionAddress
			LEA EAX, [ECX + EDX]
			JMP gCItemSetOption.m_dwJmpReturn6
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent7()
{
	_asm
	{
		MOV EAX, gCItemSetOption.m_dwSetOptionAddress
			LEA ECX, [EDX + EAX]
			JMP gCItemSetOption.m_dwJmpReturn7
	}
}
// ----------------------------------------------------------------------------------------------
void __declspec(naked) CSItemOption::AsmAncent8()
{
	_asm
	{
		MOV ECX, gCItemSetOption.m_dwSetOptionAddress
			LEA EDX, [EAX + ECX]
			JMP gCItemSetOption.m_dwJmpReturn8
	}
}

void AncestralRenderName(int Line)
{
	static tooltiparray * TooltipLine = (tooltiparray*)NewAddressData3;
	static int * ColorTexto = (int*)NewAddressData1;
	static int * LineWeight = (int*)NewAddressData2;

	ColorTexto[Line] = 4;
	LineWeight[Line++] = 1;
	wsprintf(TooltipLine[Line++], "\n");
}

__declspec(naked) void InfonameAncestral()
{
	static DWORD Addr_JMP = 0x004EBC24;
	static DWORD v27; // [sp+56h] [bp-12h]@4

	_asm
	{
		MOVZX ECX,BYTE PTR SS:[EBP-0x12]
		MOV v27, ECX
	}

	AncestralRenderName(v27);

	_asm
	{
		MOV AL,BYTE PTR SS:[EBP-0x12]
		ADD AL,1
		MOV BYTE PTR SS:[EBP-0x12],AL
		JMP[Addr_JMP]
	}
}

void CSItemOption::Load()
{
	SetCompleteHook(0xE9, 0x007E3E5A, &GLItemIndex);

	SetCompleteHook(0xE9, 0x004E8B80, &this->BMDLoad);
	//--
	SetCompleteHook(0xE9, 0x004E8990,  &CSItemOption::LoadSetType);

	memset(this->m_SetOptionData, 0, sizeof(this->m_SetOptionData));

	this->m_dwSetOptionAddress = (DWORD)&this->m_SetOptionData;

	this->m_dwJmpReturn1 = oItemSetOptionAsm1 + 13;
	SetRange((LPVOID)oItemSetOptionAsm1, 13, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm1, (LPVOID)this->AsmAncent1, ASM::JMP);

	this->m_dwJmpReturn2 = oItemSetOptionAsm2 + 10;
	SetRange((LPVOID)oItemSetOptionAsm2, 10, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm2, (LPVOID)this->AsmAncent2, ASM::JMP);

	//-- tooltip acc S15
	SetCompleteHook(0xE9, 0x005BFAD8, &Desbordamiento);

	SetCompleteHook(0xE8, 0x007E5CB6, &ItemTooltipRender);

	SetCompleteHook(0xE8, 0x005BFC9B, &CSItemOption::ItemTooltipS15);

	if(gProtect.m_MainInfo.HelperUpgradeSystem == 0)
	{
		//-- Tooltip Acc Normal
		this->m_dwJmpReturn3 = oItemSetOptionAsm3 + 10;
		SetRange((LPVOID)oItemSetOptionAsm3, 10, ASM::NOP);
		SetOp((LPVOID)oItemSetOptionAsm3, (LPVOID)this->AsmAncent3, ASM::JMP);
	}
	else
	{
		SetCompleteHook(0xE9, 0x004EBC06, &InfonameAncestral);

		SetCompleteHook(0xE9, 0x005BFEC6, &TextColorExeS15);

		SetCompleteHook(0xE9, 0x005BFE5F, &TextColorAccS15);

		SetCompleteHook(0xE9, 0x005C0000, &RemoveBackgroundAcc);

		SetCompleteHook(0xE9, 0x004EC410, &CSItemOption::InitSetOptionsTooltip);
	}
	//--
	this->m_dwJmpReturn4 = oItemSetOptionAsm4 + 10;
	SetRange((LPVOID)oItemSetOptionAsm4, 10, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm4, (LPVOID)this->AsmAncent4, ASM::JMP);

	this->m_dwJmpReturn5 = oItemSetOptionAsm5 + 10;
	SetRange((LPVOID)oItemSetOptionAsm5, 10, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm5, (LPVOID)this->AsmAncent5, ASM::JMP);

	this->m_dwJmpReturn6 = oItemSetOptionAsm6 + 13;
	SetRange((LPVOID)oItemSetOptionAsm6, 13, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm6, (LPVOID)this->AsmAncent6, ASM::JMP);

	this->m_dwJmpReturn7 = oItemSetOptionAsm7 + 10;
	SetRange((LPVOID)oItemSetOptionAsm7, 10, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm7, (LPVOID)this->AsmAncent7, ASM::JMP);

	this->m_dwJmpReturn8 = oItemSetOptionAsm8 + 10;
	SetRange((LPVOID)oItemSetOptionAsm8, 10, ASM::NOP);
	SetOp((LPVOID)oItemSetOptionAsm8, (LPVOID)this->AsmAncent8, ASM::JMP);
}