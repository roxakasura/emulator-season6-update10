#include "stdafx.h"
#include "ChatSystem.h"
#include "TMemory.h"
#include "Util.h"
#include "Offset.h"
#include "Object.h"
#include "Import.h"
#include "ChatExpanded.h"
#include "Protect.h"

// ---------------------------------------------------------------------------------------------
CChatClassic gCChatClassic;
// ---------------------------------------------------------------------------------------------
static int chatX = 0;
static int Mude = 0;
static int Muda = 0;
int Open = 0;

void CChatClassic::RenderFrame(int This)
{
	pSetBlend(true);
	glColor4f((GLfloat)0.0, (GLfloat)0.0, (GLfloat)0.0, (float)1.0);
	pDrawBarForm(182.0, 407.5, 268.0, 20.0, 0.0f, 0);
	pGLSwitchBlend();
	glColor3f(1.0, 1.0, 1.0);
	pGLSwitch();
	pSetBlend(false);
	RenderBitmap(51530, 180.0, 407.5, 143.0, 29.0, 0, 0, 0.51953125, 0.90625, 1, 1, 0.0);
    RenderBitmap(51531, 322.0, 407.5, 142.0, 29.0, 0, 0, 0.51953125, 0.90625, 1, 1, 0.0);
}

__declspec(naked) void ChatPosicion()
{
	static DWORD ChatPosicion_buff = 0x0085A44D;
	static DWORD CALL01  = 0x00785870;
	_asm
	{	
	PUSH 384 //<<Y
	PUSH 186 //<<X
	MOV EDX,DWORD PTR SS:[EBP-0x270]
	MOV EAX,DWORD PTR DS:[EDX+0x10]
	PUSH EAX
	MOV ECX,DWORD PTR SS:[EBP-0x270]
	MOV EDX,DWORD PTR DS:[ECX]
	PUSH EDX
	MOV EAX,DWORD PTR SS:[EBP-0x270]
	MOV ECX,DWORD PTR DS:[EAX+0xC]
	CALL CALL01
	jmp [ChatPosicion_buff]
	}
}


__declspec(naked) void WhisperTextPosicion()
{
	static DWORD WhisperTextPosicion_buff = 0x00785A6D;
	static DWORD CALL01  = 0x00417EC0;
	_asm
	{	
	ADD EDX,32//<<Y
	PUSH EDX
	MOV EAX,DWORD PTR SS:[EBP-0x20]
	MOV ECX,DWORD PTR DS:[EAX+0x14]
	ADD ECX,195//<<X
	PUSH ECX
	MOV EDX,DWORD PTR SS:[EBP-0x20]
	MOV ECX,DWORD PTR DS:[EDX+0x28]
	CALL CALL01
	jmp [WhisperTextPosicion_buff]
	}
}

__declspec(naked) void ChatTextPosicion()
{
	static DWORD ChatTextPosicion_buff = 0x00785972;
	static DWORD CALL01  = 0x00417EC0;
	_asm
	{
		ADD EDX,32
		PUSH EDX                                 ; /Arg2
		MOV EAX,DWORD PTR SS:[EBP - 0x20]        ; |
		MOV ECX,DWORD PTR DS:[EAX + 0x14]        ; |
		//ADD ECX,5                                ; |
		PUSH ECX                                 ; |Arg1
		MOV EDX,DWORD PTR SS:[EBP - 0x20]        ; |
		MOV ECX,DWORD PTR DS:[EDX + 0x24]        ; |
		CALL CALL01                              ; \main1.00417EC0
		jmp [ChatTextPosicion_buff]
	}
}

//----- (007889B0) --------------------------------------------------------
char ChatWindowsDrawClasic(MUChat* This)
{
	This->WindowPosX = 0;

	//This->WindowWidth = 270;

	chatX = 0;

	if(gProtect.m_MainInfo.MessageChatRemakeType == 1)
	{
		if (gChatExpanded.m_separate == 0)
		{
			if (This->WindowHeight == 55)
			{
				This->WindowPosY = 95;
			}

			if (This->WindowHeight == 100)
			{
				This->WindowPosY = 95;
			}

			if (This->WindowHeight == 145)
			{
				This->WindowPosY = 95;
			}

			if (This->WindowHeight == 190)
			{
				This->WindowPosY = 95;
			}

			if (This->WindowHeight == 235)
			{
				This->WindowPosY = 95;
			}
		}
		else
		{
			This->WindowPosY = 95;
		}
	}
	else
	{
		if (gChatExpanded.m_separate == 0)
		{
			if (This->WindowHeight == 55)
			{
				This->WindowPosY = 95;
			}

			if (This->WindowHeight == 100)
			{
				This->WindowPosY = 140;
			}

			if (This->WindowHeight == 145)
			{
				This->WindowPosY = 185;
			}

			if (This->WindowHeight == 190)
			{
				This->WindowPosY = 235;
			}

			if (This->WindowHeight == 235)
			{
				This->WindowPosY = 280;
			}
		}
		else
		{
			This->WindowPosY = 378;
		}
	}
	//cuando se activa se pasa al centro
	if(This->WindowsActivo)
	{
		chatX = 3;

		if(gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(OtherStore)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Character)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(GoldenArcher1)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(GoldenArcher2)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(LuckyCoin1)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(LuckyCoin2)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(ExpandInventory)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Warehouse)
		|| gInterface.CheckWindow(Character) && gInterface.CheckWindow(PetInfo)
		|| gInterface.CheckWindow(Character) && gInterface.CheckWindow(Quest)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(NPC_ChaosMix)
		|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(ChaosBox)
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Trade))
		{
		This->WindowPosX = 0;
		This->WindowPosY = 405;
		}
		else
		{
		This->WindowPosX = 179;
		This->WindowPosY = 405;
		}

		//This->WindowPosX = 179;
		//This->WindowPosY = 429;
	}

	sub_7889B0(This);

	return 1;
}

//----- (00789110) --------------------------------------------------------
char RenderFrameChatClassic(MUChat* This)
{
	float v4; // ST30_4@5
	float v5; // ST2C_4@5
	float v6; // ST28_4@5
	float v7; // ST20_4@7
	float v8; // ST20_4@7
	float v9; // ST20_4@7
	float green; // ST08_4@8
	int i; // [sp+38h] [bp-Ch]@5
	float v16; // [sp+3Ch] [bp-8h]@2
	float v17; // [sp+40h] [bp-4h]@2
	static int A = 0;
	static int B = 0;
	static int C = 0;
	static int D = 0;
	static int E = 0;
	static int F = 0;

	if(pCursorX > 260 && pCursorX < 375 && pCursorY > 400 && pCursorY < 446)
	{
		if(gInterface.CheckWindow(ChatWindow))
		{

		}
		else
		{
			if (pCursorX > 296 && pCursorX < 312 && pCursorY > 413 && pCursorY < 429)
			{
				gInterface.DrawToolTip(273.0f, 400.0f, pGetTextLine(pTextLineThis, 122));
			
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					A = 1;
					B = 1;
					keybd_event(VK_F2, 0, 0, 0);
				}
				else
				{
					A = 0;
					B = 0;
					keybd_event(VK_F2, 0, KEYEVENTF_KEYUP, 0);
				}
			}
			else
			{
				A = 0;
				B = 0;
			}
			if (pCursorX > 313 && pCursorX < 329 && pCursorY > 413 && pCursorY < 429)
			{
				gInterface.DrawToolTip(289.0f, 400.0f, pGetTextLine(pTextLineThis, 123));

				if(This->WindowsActivo == 1)
				{
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						C = 1;
						D = 1;
						keybd_event(VK_F4, 0, 0, 0);
					}
					else
					{
						C = 0;
						D = 0;
						keybd_event(VK_F4, 0, KEYEVENTF_KEYUP, 0);
					}
				}
				else
				{
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						C = 1;
						D = 1;
						This->WindowsActivo = 1;
							if(gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Store)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(OtherStore)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Character)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(GoldenArcher1)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(GoldenArcher2)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(LuckyCoin1)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(LuckyCoin2)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(ExpandInventory)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(Warehouse)
							|| gInterface.CheckWindow(Character) && gInterface.CheckWindow(PetInfo)
							|| gInterface.CheckWindow(Character) && gInterface.CheckWindow(Quest)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(NPC_ChaosMix)
							|| gInterface.CheckWindow(Inventory) && gInterface.CheckWindow(ChaosBox)
							|| gInterface.CheckWindow(Shop)
							|| gInterface.CheckWindow(Trade))
							{
								This->WindowPosX = 0;
								This->WindowPosY = 405;
							}
							else
							{
								This->WindowPosX = 179;
								This->WindowPosY = 405;
							}
					}
					else
					{
						C = 0;
						D = 0;
					}
				}

			}
			else
			{
				C = 0;
				D = 0;
			}
			if (pCursorX > 330 && pCursorX < 346 && pCursorY > 413 && pCursorY < 429)
			{
				gInterface.DrawToolTip(308.0f, 400.0f, pGetTextLine(pTextLineThis, 124));

				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					if(Open == 0)
					{
						E = 1;
						F = 1;
						Open = 1;
						This->AlphaColor = (1.0, 1.0, 1.0, 0.7);
						keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
					}
					else if(Open == 1)
					{
						E = 1;
						F = 1;
						Open = 2;
						This->AlphaColor = (1.0, 1.0, 1.0, 0.5);
						keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
					}
					else if(Open == 2)
					{
						E = 1;
						F = 1;
						Open = 3;
						This->AlphaColor = (1.0, 1.0, 1.0, 0.3);
						keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
					}
					else if(Open == 3)
					{
						E = 1;
						F = 1;
						Open = 4;
						This->AlphaColor = (1.0, 1.0, 1.0, 0.0);
						keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
					}
					else if(Open == 4)
					{
						E = 1;
						F = 1;
						Open = 0;
						This->AlphaColor = (1.0, 1.0, 1.0, 1.0);
						keybd_event(VK_LBUTTON, 0, KEYEVENTF_KEYUP, 0);
					}
				}
				else
				{
					E = 0;
					F = 0;
				}
			}
			else
			{
				E = 0;
				F = 0;
			}

			gInterface.DrawGUI(eOrelhinha, 296.0f + A, 413.0f + B);
			gInterface.DrawGUI(eJanelinha, 313.0f + C, 413.0f + D);
			gInterface.DrawGUI(eLuizinha,  330.0f + E, 413.0f + F);
			pSetCursorFocus = true;
		}
	}
	else
	{
		pSetCursorFocus = false;
	}

	if(This->WindowsActivo){

		if(This->Unknown340 == 4)
		{
			glColor4f((GLfloat)0.69999999, (GLfloat)0.69999999, (GLfloat)0.69999999, 1.0);
		}
		else
		{
			glColor4f(1.0, 1.0, 1.0, 1.0);
		}
		v17 = (double)This->WindowPosX;
		v16 = (double)(This->WindowPosY - This->WindowHeight);
		v9 = This->WindowPosX + This->WindowWidth - 5;
		v4 = v16 - 5.0;
		pSetBlend(true);
		
		pDrawGUI(31275, v17, v4, 281.0f, 5.0f);

		pDrawGUI(51552, v9 - 24, v4 - 4, 22.0f, 12.0f);

		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);


		pSetBlend(true);
		glColor4f(1.0, 1.0, 1.0, 1.0);

		for ( int i = 0; i < This->WindowLineCount; ++i )
		{
			v8 = v16 - 3 + (double)(40 * i + 3);

			pDrawGUI(51551, v17, v8, 5.0, 40.0f);

			pDrawGUI(51551, v9, v8, 5.0, 40.0f);
		}

		for ( int i = 0; i < This->WindowLineCount; ++i )
		{
			v7 = v16 + 3 + (double)(15 * i + 3);
			pDrawGUI(51554, v9 - 20, v7, 15.0f, 15.0f);
		}

		pDrawGUI(51553, v9 - 20, v16 + 5, 15.0f, 14.0f);
		green = (double)(This->WindowPosY - 20);
		//-- scroll flecha abajo
		pDrawGUI(51555, v9 - 20, green + 3, 15.0f, 14.0f);

		pGLSwitchBlend();
		pGLSwitch();
		glColor3f(1.0, 1.0, 1.0);
		pSetBlend(false);
	}
	return 1;
}

__declspec(naked) void WarpMessageSystem()
{
	static DWORD ChangeMove = 4;
	static DWORD Buffer_warp = 0x007890ED;
	static DWORD CALL_MAIN1 = 0x0078C030;
	static DWORD CALL_MAIN2 = 0x00402880;
	static DWORD CALL_MAIN3 = 0x0041FE10;

	ChangeMove = chatX;

	if(gChatExpanded.m_separate == 0)
	{
		_asm
		{
			PUSH 0
			PUSH 1
			PUSH 0
			PUSH 0
			MOV ECX,DWORD PTR SS:[EBP-0x2C]
			CALL CALL_MAIN1
			MOV ECX,EAX
			CALL CALL_MAIN2
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x34]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP-0x38]
			ADD EDX,ChangeMove
			PUSH EDX
			CALL CALL_MAIN3
			MOV ECX,EAX                             ; |
			JMP [Buffer_warp]
		}
	}
	else
	{
			_asm
		{
			PUSH 0
			PUSH 1
			PUSH 0
			PUSH 0
			MOV ECX,DWORD PTR SS:[EBP-0x2C]
			CALL CALL_MAIN1
			MOV ECX,EAX
			CALL CALL_MAIN2
			PUSH EAX
			MOV ECX,DWORD PTR SS:[EBP-0x34]
			PUSH ECX
			MOV EDX,DWORD PTR SS:[EBP-0x38]
			MOV EDX,0x5
			PUSH EDX
			CALL CALL_MAIN3
			MOV ECX,EAX                             ; |
			JMP [Buffer_warp]
		}
	}
}

__declspec(naked) void WarpMessageChat()
{
	static DWORD ChangeMove = 4;
	static DWORD Buffer_warp = 0x007890A4;
	static DWORD CALL_MAIN1 = 0x00402880;
	static DWORD CALL_MAIN2 = 0x0041FE10;

	ChangeMove = chatX;

	_asm
	{
		PUSH 0
		PUSH 1
		PUSH 0
		PUSH 0
		LEA ECX,DWORD PTR SS:[EBP-0x54]
		CALL CALL_MAIN1
		PUSH EAX
		MOV EDX,DWORD PTR SS:[EBP-0x34]
		PUSH EDX
		MOV EAX,DWORD PTR SS:[EBP-0x38]
		ADD EAX,ChangeMove
		PUSH EAX
		CALL CALL_MAIN2
		MOV ECX,EAX                             ; |
		JMP [Buffer_warp]
	}
}

void CChatClassic::WhisperPosition() // ok
{
		float PosX		= 375.0;
		float PosY		= 411.0;
		pDrawBarForm(PosX, PosY, 64.0, 16.0, 0.0, 0);

}

void CChatClassic::WisperButtonOn(DWORD a1, float a2, float a3, float a4, float a5)
{	
	gInterface.DrawButton(ebtnWisper, 439.0f, 412.0f, 0.0, 0.0);
}

double SkillChatBarOne()
{
	return 2.0999999;
}

double SkillChatBarTwo()
{
	return 2.199999809;
}

void CChatClassic::Load()
{
	SetCompleteHook(0xE9, 0x00787BA0, &SkillChatBarTwo);
	SetCompleteHook(0xE9, 0x0078B0F0, &SkillChatBarOne);
	SetCompleteHook(0xE9,0x00789084,&WarpMessageChat);
	SetCompleteHook(0xE9,0x007890C6,&WarpMessageSystem);
	SetCompleteHook(0xE8,0x00787748,&WhisperPosition);
	SetCompleteHook(0xE8,0x00787847,&WisperButtonOn);
	SetDword(0x007856EA+1,(DWORD)"Custom\\InterfaceS2\\chat\\newui_chat_whisper_on.jpg");
	SetDword(0x0078566A+1,(DWORD)"Custom\\InterfaceS2\\chat\\newui_chat_back.tga"); //Change newui_chat_back.jpg

	//Local call from 00785B44
	//-- DrawBarForm F5 in character
	SetCompleteHook(0xE8,0x0078B09A,&ChatWindowsDrawClasic);
	SetCompleteHook(0xE9,0x007867A5, 0x007867B3); //F5 independente
	//-- Render FrameWindows Texture Chat
	SetCompleteHook(0xE8, 0x0078B0CF, &RenderFrameChatClassic);

	/*			NEW SYSTEM CHATBOX OPTIONS		*/
	SetDword((PVOID)(0x00788A2B+2),314);			//DIMENSIONAMENTO DA TELA PRETA DOWNGRADE (PARA O CHAT)
	MemorySet(0x00787960, 0x90, 0x23A); //mensagens que aparecem em cima do chat
	MemorySet(0x00787C7D,0x90,0x5); //F5 sempre ativo
//	MemorySet(0x007877B0, 0x90, 0x1A9); //imagens que aparecem ao ativar cada botão do chat
//	SetByte(0x007877B0, 0xC3); //Remove Botões acima do chat
//	SetByte(0x00786150, 0xC3); //Remove click dos botões acima do chat
	MemorySet(0x007863A8,0x90,0x5); //esse desativa o $
	MemorySet(0x0078641E,0x90,0x5); //Remove Button Off esse a nuvenzinha do lado do $
	MemorySet(0x007864B3,0x90,0x5); // Esse o controle de janela
	MemorySet(0x007862E2,0x90,0x5); //desativa ativações de Chat/Guild/Gens/Party
	MemorySet(0x0078653E,0x90,0x5); //Remove Button Off
	MemorySet(0x00786574,0x90,0x5); //Remove Button Off
	MemorySet(0x007877FE,0x90,0x5); //remove botton 1	
	MemorySet(0x00787893,0x90,0x5); //remove botton 2
	MemorySet(0x007878DE,0x90,0x5);
	MemorySet(0x00787931,0x90,0x5);
	MemorySet(0x00785C6A,0x90,0x5);
	MemorySet(0x00785CA7,0x90,0x5);	
	SetByte((PVOID)(0x00785965), 6);			// POSIÇÃO X DO TEXTO NO CHAT
	SetByte((PVOID)(0x00785959+2), 9);			// POSIÇÃO Y DO TEXTO NO CHAT
	/*			NEW SYSTEM CHATBOX OPTIONS		*/
}