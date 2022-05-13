#include "StdAfx.h"
#include "Util.h"
#include "MuunOption.h"
#include "UIControl.h"
#include "NewUISystem.h"
#include "NewUIPetInfoWindow.h"
#include "Defines.h"


MuunOption g_Option;

MuunOption::MuunOption( )
{
}

MuunOption::~MuunOption( )
{
}

void HookColorFont(int TextListColor)
{
	g_pRenderText.SetTextColor(0xffffffff);
	switch(TextListColor)
	{
	case g_Option.TEXT_COLOR_WHITE:
	case g_Option.TEXT_COLOR_DARKRED:
	case g_Option.TEXT_COLOR_DARKBLUE:
	case g_Option.TEXT_COLOR_DARKYELLOW:
		glColor3f(1.f,1.f,1.f);
		break;
	case g_Option.TEXT_COLOR_BLUE:
		glColor3f(0.5f,0.7f,1.f);
		break;
	case g_Option.TEXT_COLOR_GRAY:
		glColor3f(0.4f,0.4f,0.4f);
		break;
	case g_Option.TEXT_COLOR_GREEN_BLUE:
		glColor3f(0.13f, 0.76f, 0.11f);
		break;
	case g_Option.TEXT_COLOR_RED:
		glColor3f(1.f,0.2f,0.1f);
		break;
	case g_Option.TEXT_COLOR_YELLOW:
		glColor3f(1.f,0.8f,0.1f);
		break;
	case g_Option.TEXT_COLOR_GREEN:
		glColor3f(0.13f, 0.76f, 0.11f);
		break;
	case g_Option.TEXT_COLOR_PURPLE:
		glColor3f(1.f,0.1f,1.f);
		break;
	case g_Option.TEXT_COLOR_REDPURPLE:
		glColor3f(0.8f,0.5f,0.8f);
		break;
	case g_Option.TEXT_COLOR_VIOLET:
		glColor3f(0.7f,0.4f,1.0f);
		break;
	case g_Option.TEXT_COLOR_ORANGE:
		glColor3f(0.9f, 0.42f, 0.04f );
		break;
	}
	if ( g_Option.TEXT_COLOR_DARKRED == TextListColor)
	{
		g_pRenderText.SetBgColor(160, 0, 0, 255);
	}
	else if ( g_Option.TEXT_COLOR_DARKBLUE == TextListColor)
	{
		g_pRenderText.SetBgColor(0, 0, 160, 255);
	}
	else if ( g_Option.TEXT_COLOR_DARKYELLOW == TextListColor)
	{
		g_pRenderText.SetBgColor(160, 102, 0, 255);
	}
	else
	{
		g_pRenderText.SetBgColor(0);
	}
}

void MuunOption::ScreenItem3D(float x, float y, float Width, float Height, int ItemID, int Level, int Excl, int Anc, bool OnMouse) // code hien thi item
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	glViewport2(0, 0, *(GLsizei*)g_WindowWidth, *(GLsizei*)g_WindowHeight);
	float v2 = *(float*)g_WindowWidth / *(float*)g_WindowHeight;
	gluPerspective_2(1.f, v2, CameraViewNear, CameraViewFar);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	GetOpenGLMatrixF(CameraMatrixF);
	EnableDepthTestF();
	EnableDepthMaskF();
	glClear(0x100u);
	CRenderItem3D(x, y, Width, Height, ItemID, Level, Excl, Anc, OnMouse);
	EndBitmap();
	glColor3f(1, 1, 1);
	EnableAlphaTest(true);
}

void MuunOption::OpenMuunOptScript(char *FileName)
{
	FILE *fp = fopen(FileName,"rb");
	if(fp != NULL)
	{
		int LineBlock = sizeof(MUUN_OPTION);
		int size_t = LineBlock * MAX_MUUN_DATA;

		BYTE *Buffer = new BYTE [size_t];
		fread(Buffer, size_t, 1,fp);
		DWORD dwCheckSum;
		fread(&dwCheckSum, sizeof(DWORD), 1, fp);
		fclose(fp);

		if ( dwCheckSum != GenerateCheckSum2( Buffer, size_t, OPEN_MUUN_SCRIPT))
		{
			char Text[256];
			sprintf(Text,"%s - File corrupted.",FileName);
			MessageBox(g_hWnd, Text, NULL, MB_OK);
			SendMessage(g_hWnd, WM_DESTROY, 0, 0);
		}
		else
		{
			BYTE *pSeek = Buffer;
			for(int i = 0 ; i < MAX_MUUN_DATA ; i++)
			{
				BuxConvert(pSeek, LineBlock);
				memcpy((BYTE*)&g_Option.MuunOPT[i], pSeek, LineBlock);
				pSeek += LineBlock;
			}
		}
		delete [] Buffer;
	}
	else
	{
		char Text[256];
		sprintf(Text,"%s - File not exist.",FileName);
		MessageBox(g_hWnd, Text, NULL, MB_OK);
		SendMessage(g_hWnd, WM_DESTROY, 0, 0);
	}
}

void MuunOption::OpenMuunScript(char *FileName)
{
	FILE *fp = fopen(FileName,"rb");
	if(fp != NULL)
	{
		int LineBlock = sizeof(MUUN_ATTRIBUTE);
		int size_t = LineBlock * MAX_MUUN_DATA;

		BYTE *Buffer = new BYTE [size_t];
		fread(Buffer, size_t, 1,fp);
		DWORD dwCheckSum;
		fread(&dwCheckSum, sizeof(DWORD), 1, fp);
		fclose(fp);

		if ( dwCheckSum != GenerateCheckSum2( Buffer, size_t, OPEN_MUUN_SCRIPT))
		{
			char Text[256];
			sprintf(Text,"%s - File corrupted.",FileName);
			MessageBox(g_hWnd, Text, NULL, MB_OK);
			SendMessage(g_hWnd, WM_DESTROY, 0, 0);
		}
		else
		{
			BYTE *pSeek = Buffer;
			for(int i = 0 ; i < MAX_MUUN_DATA ; i++)
			{
				BuxConvert(pSeek, LineBlock);
				memcpy((BYTE*)&g_Option.MuunAttribute[i], pSeek, LineBlock);
				pSeek += LineBlock;
			}
		}
		delete [] Buffer;
	}
	else
	{
		char Text[256];
		sprintf(Text,"%s - File not exist.",FileName);
		MessageBox(g_hWnd, Text, NULL, MB_OK);
		SendMessage(g_hWnd, WM_DESTROY, 0, 0);
	}
}

void MuunOption::OpenMuunTextScript(char *FileName)
{
	FILE *fp = fopen(FileName,"rb");
	if(fp != NULL)
	{
		int LineBlock = sizeof(MUUN_TOOLTIP_TEXT);
		int size_t = LineBlock * MAX_MUUN_DATA;

		BYTE *Buffer = new BYTE [size_t];
		fread(Buffer, size_t, 1,fp);
		DWORD dwCheckSum;
		fread(&dwCheckSum, sizeof(DWORD), 1, fp);
		fclose(fp);

		if ( dwCheckSum != GenerateCheckSum2( Buffer, size_t, OPEN_MUUN_SCRIPT))
		{
			char Text[256];
			sprintf(Text,"%s - File corrupted.",FileName);
			MessageBox(g_hWnd, Text, NULL, MB_OK);
			SendMessage(g_hWnd, WM_DESTROY, 0, 0);
		}
		else
		{
			BYTE *pSeek = Buffer;
			for(int i = 0 ; i < MAX_MUUN_DATA ; i++)
			{
				BuxConvert(pSeek, LineBlock);
				memcpy((BYTE*)&g_Option.MuunText[i], pSeek, LineBlock);
				pSeek += LineBlock;
			}
		}
		delete [] Buffer;
	}
	else
	{
		char Text[256];
		sprintf(Text,"%s - File not exist.",FileName);
		MessageBox(g_hWnd, Text, NULL, MB_OK);
		SendMessage(g_hWnd, WM_DESTROY, 0, 0);
	}
}

void MuunOption::OpenPetProcess(int thisa)
{
	char chFileName[200];

	PetProcessData(thisa);
	g_Option.OpenMuunScript("Data\\Local\\MuunData.bmd");
	g_Option.OpenMuunOptScript("Data\\Local\\MuunOption.bmd");
	sprintf_s(chFileName, "Data\\Local\\MuunTooltipText.bmd");
	g_Option.OpenMuunTextScript(chFileName);
}

int AddOptionLine(int TextColor, int font, int TextNum, int salto, LPCSTR Buff, ...)
{
	//va_list args;
	int * TextBold = (int*)NewAddressData2;
	int * TextListColor = (int*)NewAddressData1;
	textlist * TextList = (textlist*)NewAddressData3;
	char textOption[254];
	int BuffLen	= sizeof(textOption)-1;
	ZeroMemory(textOption, BuffLen);
	
	va_list args;
	va_start(args, Buff);
	vsprintf_s(textOption, BuffLen, Buff, args);
	va_end(args);

	TextListColor[TextNum] = TextColor;
	TextBold[TextNum] = font;
	wsprintf(TextList[TextNum++], textOption);

	for (int u = 0; u < salto; u++ )
	{
		wsprintf(TextList[TextNum++], "\n");
	}

	return TextNum;
}

int TypeScreen = -1;

int MuunOption::AttachToolTipForSocketItem(LPVOID thisa, ITEM* Temp, int TextNum)
{	

	if(Temp->Type >= 6856 && Temp->Type < 7168)
	{
		TypeScreen = Temp->Type;
		TextNum = g_Option.AttachToolTipForMuun(Temp, TextNum);
	}
	else
	{
		g_Option.ITEM_SELECT = NULL;
	}

	TextNum = ForSocketItem(thisa, Temp, TextNum);

	return TextNum;
	//return 
}

void MuunOption::RenderTipTextList(int sx, int sy, int TextNum, int Tab, int iSort, int iRenderPoint, BOOL bUseBG)
{
	int * TextListColor = (int*)NewAddressData1;
	int * TextBold      = (int*)NewAddressData2;
	textlist * TextList = (textlist*)NewAddressData3;
	//--
	SIZE TextSize = { 0, 0 };
	int TextLine = 0; int EmptyLine = 0;
	float fWidth = 0; float fHeight = 0;

	for (int i = 0; i < TextNum; ++i)
	{
		if (TextList[i][0] == '\0') { TextNum = i; break; }

		if (TextBold[i])
			g_pRenderText.SetFont(g_hFontBold);
		else
			g_pRenderText.SetFont(g_hFont);

		g_TextExtentPoint32W(GetPoint32(), g_pRenderText.GetFontHDC(), TextList[i], lstrlen(TextList[i]), &TextSize);

		if (fWidth < TextSize.cx) { fWidth = TextSize.cx; }

		if (TextList[i][0] == '\n')
			++EmptyLine;
		else
			++TextLine;
	}

	fHeight = TextSize.cy * TextLine + TextSize.cy / 2.0f * EmptyLine;
	fHeight /= g_fScreenRate_y / 1.1f;
	EnableAlphaTest(true);

	fWidth /= g_fScreenRate_x;
	if (Tab > 0)
		fWidth = (Tab / g_fScreenRate_x) * 2;
	fWidth += 4;

	if (PickTooltip != -1)
	{
		fHeight += 90;
		if (fWidth < 80) { fWidth += 80; }
	}

	int iPos_x = sx - fWidth / 2.f;

	if (iPos_x < 0) { iPos_x = 1.f; }

	if ((*(GLsizei*)g_WindowWidth) / g_fScreenRate_x < (iPos_x + fWidth))
	{
		iPos_x = ((float)*(GLsizei*)g_WindowWidth / g_fScreenRate_x) - fWidth - 1;
	}

	float fsx = iPos_x + 1;
	float fsy = 0.f;

	switch (iRenderPoint)
	{
	case 8:
		{
		fsy = sy - fHeight;
		}
	break;
	default:
		{
		fsy = sy;
		}
	break;
	}

	if (fsy < 10.f) { fsy = 10.f; }

	if (bUseBG == TRUE && TextNum > 0)
	{
		glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
		RenderColor((float)iPos_x, fsy, (float)fWidth, (float)fHeight, 0.0, 0);
		glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
		RenderColor((float)iPos_x - 1, fsy - 1, (float)fWidth + 1, (float)1, 0.0, 0);
		RenderColor((float)iPos_x - 1, fsy - 1, (float)1, (float)fHeight + 1, 0.0, 0);
		RenderColor((float)iPos_x - 1 + fWidth + 1, (float)fsy - 1, (float)1, (float)fHeight + 1, 0.0, 0);
		RenderColor((float)iPos_x - 1, fsy - 1 + fHeight + 1, (float)fWidth + 2, (float)1, 0.0, 0);
		glEnable(GL_TEXTURE_2D);
	}

	if (PickTooltip != -1)
	{
		float cx = iPos_x + (fWidth / 2) - 40;
		float cy = fsy + 5;
		ScreenItem3D(cx, cy, 80, 80, TypeScreen, 0, 0, 0, true);
		fsy += 90;
	}

	for (int i = 0; i < TextNum; i++)
	{
		if (TextBold[i])
			g_pRenderText.SetFont(g_hFontBold);
		else
			g_pRenderText.SetFont(g_hFont);

		float fHeight = 0;
		if (TextList[i][0] == 0x0a || (TextList[i][0] == ' ' && TextList[i][1] == 0x00))
		{
			g_TextExtentPoint32W(GetPoint32(), g_pRenderText.GetFontHDC(), TextList[i], lstrlen(TextList[i]), &TextSize);
			fHeight = (float)TextSize.cy / g_fScreenRate_y / (TextList[i][0] == 0x0a ? 2.0f : 1.0f);
		}
		else
		{
			HookColorFont(TextListColor[i]);
			g_pRenderText.RenderText(fsx, fsy, TextList[i], (fWidth - 2), 0, iSort, &TextSize);
			fHeight = TextSize.cy;
		}
		fsy += fHeight * 1.1f;
	}
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	DisableAlphaBlend();
}

MUUN_ATTRIBUTE * MuunOption::GetAttribute(WORD Index)
{
	int df = Index - 6856;

	if(df >= 0 && df < MAX_MUUN_DATA)
	{
		if(g_Option.MuunAttribute[df].Type < ITEM(13,0))
		{
			return NULL;
		}
		return &g_Option.MuunAttribute[df];
	}

	return NULL;
}

MUUN_OPTION * MuunOption::GetMuunInfo(WORD Index)
{
	if(Index >= 0 && Index < MAX_MUUN_DATA)
	{
		return &g_Option.MuunOPT[Index];
	}

	return NULL;
}

char* MuunOption::GetGlobalMuunText(int Line)
{
	if(g_Option.MuunText[Line].text[0] != '\0')
	{
		return g_Option.MuunText[Line].text;
	}
	else
	{
		char text[50];

		sprintf_s(text, "description not found: %d", Line);
		return text;
	}
}

int MuunOption::AttachToolTipForMuun(ITEM* Temp, int TextNum)
{
	MUUN_ATTRIBUTE * Muun = g_Option.GetAttribute(Temp->Type);

	if(Muun != NULL)
	{
		TextNum = 0;
		int Level = (Temp->Level>>3)&15;

		TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 0,"\n");
		TextNum = AddOptionLine(g_Option.TEXT_COLOR_YELLOW, g_Option.Font_Bold, TextNum, 1, ItemAttribute[Temp->Type].Name);

		switch(Muun->Rank)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_BLUE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(25 + Muun->Rank));
			break;
		default:
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_BLUE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(29));
			break;
		}

		if(Level >= (Muun->Rank+1))
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_GREEN , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(30));
		else
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_GREEN , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(31), Level, Muun->Rank+1);

		switch(Muun->MuunType)
		{
		case g_Option.TypeNormal:
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(32));
			break;
		case g_Option.TypeUtil:
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(33));
			break;
		case g_Option.TypeMount:
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(34));
			break;
		default:
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(32));
			break;
		}
		TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 2, g_Option.GetGlobalMuunText(35), Temp->Durability);

		TextNum = AddOptionLine(g_Option.TEXT_COLOR_VIOLET, g_Option.Font_Normal, TextNum, 2, g_Option.GetGlobalMuunText(36));

		MUUN_OPTION * info = g_Option.GetMuunInfo(Muun->OptionIndex);

		if(info)
		{
			int valTem;
			for(int t = 0; t < MAX_OPT_MUUN ; t++)
			{
				if(info->Optio[t] > 0)
				{
					switch(info->Optio[t])
					{
					case ADD_MP:
					case ADD_HP:
						valTem = info->Val[t] + Level *100;
						break;
					case DMG_RATE:
					case INC_EXP_RATE:
					case REFLECT_RATE:
					case DOUBLE_DMG_RATE:
					case TRIPLE_DMG_RATE:
						valTem = info->Val[t] + Level;
						break;
					default:
						valTem = info->Val[t];
						break;
					}

					TextNum = AddOptionLine(g_Option.TEXT_COLOR_BLUE , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(info->Optio[t]), valTem);
				}
			}

			if(info->Specialval > 0)
			{
				TextNum = AddOptionLine(g_Option.TEXT_COLOR_WHITE , g_Option.Font_Normal, TextNum, 0,"\n");
				TextNum = AddOptionLine(g_Option.TEXT_COLOR_YELLOW , g_Option.Font_Normal, TextNum, 2, g_Option.GetGlobalMuunText(info->Specialval), info->Specialval);

				if(info->MinLvl > -1 && info->MaxLvl > -1)
				{
					TextNum = AddOptionLine(g_Option.TEXT_COLOR_YELLOW , g_Option.Font_Normal, TextNum, 0, g_Option.GetGlobalMuunText(16), info->MinLvl, info->MaxLvl);
				}
				if(info->DayOfWeek >= 0 && info->DayOfWeek < 7)
				{
					char text1[50], text2[50];

					sprintf_s(text1, g_Option.GetGlobalMuunText(17), g_Option.GetGlobalMuunText(18 + info->DayOfWeek));
					sprintf_s(text2, g_Option.GetGlobalMuunText(15), info->MinHor, info->MaxHor);
					TextNum = AddOptionLine(g_Option.TEXT_COLOR_YELLOW , g_Option.Font_Normal, TextNum, 0, "%s %s", text1, text2);
				}
			}
			TextNum = AddOptionLine(g_Option.TEXT_COLOR_RED   , g_Option.Font_Normal, TextNum, 0, "You cannot equip more than one premium muun");
		}
	}
	return TextNum;
}

void MuunOption::Init( )
{
	SetCompleteHook(0xE8, 0x00924C8B, &MuunOption::OpenPetProcess);
	SetCompleteHook(0xE8, 0x007E5CB6, &MuunOption::RenderTipTextList);
	SetCompleteHook(0xE8, 0x007E5B70, &MuunOption::AttachToolTipForSocketItem);
}