#include "stdafx.h"
#include "PartySystem.h"
#include "Import.h"
#include "Defines.h"
#include "Object.h"
#include "Offset.h"
#include "Util.h"
#include "TMemory.h"
#include "Inter803.h"

void LoadPartySystem()
{
	SetCompleteHook(0xE9, 0x0084BDB0, &RenderPartyBack);
	MemorySet(0x0084B943, 0x90,0x5); //remove click exit
	MemorySet(0x0084B85B, 0x90,0x5); //remove click exit

	//MemorySet(0x0080F865, 0x90, 0x5); //REMOVE A EXPERIENCIA IMAGEM TODA
}

//----- (0084BDB0) --------------------------------------------------------
char RenderPartyBack(DWORD a1)
{
  char result; // al@2
  HGDIOBJ alpha; // ST18_4@3
  void *v6; // eax@3
  void *v7; // eax@3
  void *v8; // eax@3
  float v9; // ST08_4@5
  float v10; // ST04_4@5
  float v11; // ST08_4@6
  float v12; // ST04_4@6
  signed int v13; // ST18_4@7
  int v14; // eax@7
  float v15; // ST08_4@9
  float v16; // ST04_4@9
  float v17; // ST08_4@12
  float v18; // ST04_4@12
  float green; // ST10_4@13
  float red; // ST0C_4@13
  float blue;
  int v21; // ST18_4@15
  void *v22; // eax@15
  int v23; // ST18_4@16
  void *v24; // eax@16
  float v25; // ST10_4@17
  float v26; // ST0C_4@17
  int v27; // ST0C_4@17
  int v28; // ST04_4@17
  int v29; // ST00_4@17
  void *v30; // eax@17
  int v31; // ST18_4@19
  void *v32; // eax@19
  int v33; // ST18_4@20
  void *v34; // eax@20
  int v35; // ST0C_4@21
  int v36; // ST04_4@21
  int v37; // ST00_4@21
  void *v38; // eax@21
  float v39; // ST64_4@25
  float v40; // ST10_4@25
  float v41; // ST0C_4@25
  signed int v42; // [sp+20h] [bp-50h]@23
  int v43; // [sp+54h] [bp-1Ch]@1
  int v44; // [sp+5Ch] [bp-14h]@7
  int v45; // [sp+68h] [bp-8h]@5
  int i; // [sp+6Ch] [bp-4h]@3

  v43 = a1;
  PartyList unk_81CB4E8;

  if ( *(BYTE *)(a1 + 917) )
  {
    pSetBlend(1);
    glColor4f(1.0, 1.0, 1.0, 1.0);
    alpha = pFontNormal;
	pSetFont(pTextThis(), (int)alpha);
    pSetTextColor(pTextThis(), 0xFFu, 0xFFu, 0xFFu, 0xFFu);
    pSetBackgroundTextColor(pTextThis(), 0, 0, 0, 0);

    for ( i = 0; i < pPartyMemberCount; ++i )
	{
	  v8 = (char *)&pPartyListStruct + 32 * i;
	  signed int PartyViewPort = *((DWORD *)v8 + 7);
      v45 = *(DWORD *)(v43 + 920) * i;

      glColor4f(0.0, 0.0, 0.0, 0.7);

      v9 = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 2);
      v10 = (double)(*(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 2);

      pDrawBarForm(v10, v9, 74.0, 24.0, 0.0, 0);

      EnableAlphaTest(1);

      if ( PartyViewPort == -1 )
      {
        glColor4f(0.30000001, 0.0, 0.0, 0.5);
        v11 = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 2);
        v12 = (double)(*(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 2);
        pDrawBarForm(v12, v11, 74.0, 24.0, 0.0, 0);
        EnableAlphaTest(1);
      }
      else
      {
        v44 = pGetPreviewStruct(pPreviewThis(), PartyViewPort);
        if ( v44 && pCheckEffectPlayer((DWORD *)(v44 + 1260), 2) == 1 )
        {
          glColor4f(0.2, 1.0, 0.2, 0.2);
          v15 = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 2);
          v16 = (double)(*(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 2);
          pDrawBarForm(v16, v15, 74.0, 24.0, 0.0, 0);
          EnableAlphaTest(1);
        }
        if ( *(DWORD *)(v43 + 924) != -1 && *(DWORD *)(v43 + 924) == i )
        {
          glColor4f(0.40000001, 0.40000001, 0.40000001, 0.69999999);
          v17 = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 2);
          v18 = (double)(*(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 2);
          pDrawBarForm(v18, v17, 74.0, 24.0, 0.0, 0);
          EnableAlphaTest(1);
        }
      }
      pGLSupremo();
	  //Background - Party
	  float PartyX = 0;
	  if(pPartyMemberCount == 1) { PartyX +=24; }
	  if(pPartyMemberCount == 2) { PartyX +=48; }
	  if(pPartyMemberCount == 3) { PartyX +=72; }
	  if(pPartyMemberCount == 4) { PartyX +=96; }
	  if(pPartyMemberCount == 5) { PartyX +=120; }

      green = (double)(v45 + *(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20));
      red = (double)(*(DWORD *)(v43 + 24) + *(DWORD *)(v43 + 16));
      blue = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20));
	  

	  pDrawGUI(79126, red, green + 4.5, 77.0, 23.0);
      pDrawGUI(79124, red + 1 , green + 2, 1.0, 24.0);						//Barra 1
      pDrawGUI(79124, red + 76, green + 2, 1.0, 24.0);						//Barra 2
      pDrawGUI(79125, red - 2 , blue - 3.0 , 80.0, 5.0);					//Tela Cima
	  pDrawGUI(79125, red - 2 , blue + PartyX + 2.5 , 80.0, 5.0);			//Tela Baixo

      if ( i )
      {
        if ( PartyViewPort == -1 )
        {
			SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
        }
        else
        {
			SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
        }
        v35 = *(DWORD *)(v43 + 932);
        v36 = *(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 4;
        v37 = *(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 4;
        pDrawText(pTextThis(), v37, v36 + 4, pGetStrutParty( i ).Name, v35, 0, (PINT)1, 0);
      }
      else
      {
        if ( PartyViewPort == -1 )
        {
			SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
        }
        else
        {
			SetTextColorByHDC(pTextThis(), pMakeColor(0xFFu, 0xFFu, 0xFFu, 0xFFu));
        }
		
		unk_81CB4E8 = *(PartyList*)0x81CB4E8;

        v27 = *(DWORD *)(v43 + 928);
        v28 = *(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 4;
        v29 = *(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 4;
        pDrawText(pTextThis(), v29, v28 + 4, unk_81CB4E8.Name, v27, 0, (PINT)1, 0);
      }
      if ( (signed int) pGetLifeMemberParty( i ) <= 10 )
        v42 = pGetLifeMemberParty( i );
      else
        v42 = 10;

      v39 = (double)v42 / 11.0 * 69.0;
      v40 = (double)(*(DWORD *)(v43 + 28) + *(DWORD *)(v43 + 20) + v45 + 16);
      v41 = (double)(*(DWORD *)(v43 + 16) + *(DWORD *)(v43 + 24) + 4);
      pDrawGUI(31558, v41, v40 + 4, v39, 3.0);

    }
    pGLSwitch();
    result = 1;
  }
  else
  {
    result = 1;
  }
  return result;
}