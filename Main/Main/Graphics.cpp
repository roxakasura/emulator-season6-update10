#include "stdafx.h"
#include "Graphics.h"
//#include "Glow.h"
#include "Common.h"
#include "Offset.h"
#include "CustomFog.h"
#include <stdio.h>
#include <process.h>
#include "Defines.h"
#include "Import.h"
#include "Util.h"

Graphics gGraphics;

Graphics::Graphics()
{
	printf("Graphics::Graphics() Success.");
}

DWORD gTmpEax;
DWORD gTmpEcx;
DWORD gTmpEdx;
DWORD gTmpEbx;
DWORD gTmpEsp;
DWORD gTmpEbp; 
DWORD gTmpEsi;
DWORD gTmpEdi;
//

DWORD gSelectEnter = 0x0040AB4A;
DWORD gGraphicsEnter = 0x00777C8B;
DWORD gSelectASMJmp00 = gSelectEnter+6;
DWORD gGraphicsASM00Jmp00 = gGraphicsEnter+5;

Naked (gSelectASM00)
{
	_asm
	{
		MOV gTmpEax,EAX
		MOV gTmpEsi,ESI
		MOV gTmpEdi,EDI
		MOV gTmpEcx,ECX
		MOV gTmpEdx,EDX
		MOV gTmpEbx,EBX
		MOV gTmpEsp,ESP
		MOV gTmpEbp,EBP
	}
	//----
	//RenderScreenGlow();
	//----
	_asm
	{
		MOV EAX,gTmpEax
		MOV ESI,gTmpEsi
		MOV EDI,gTmpEdi
		MOV ECX,gTmpEcx
		MOV EDX,gTmpEdx
		MOV EBX,gTmpEbx
		MOV ESP,gTmpEsp
		MOV EBP,gTmpEbp
		ADD ECX,0x200
		//---
		JMP gSelectASMJmp00
	}
}

Naked (gGraphicsASM00)
{
	_asm
	{
		MOV gTmpEax,EAX
		MOV gTmpEsi,ESI
		MOV gTmpEdi,EDI
		MOV gTmpEcx,ECX
		MOV gTmpEdx,EDX
		MOV gTmpEbx,EBX
		MOV gTmpEsp,ESP
		MOV gTmpEbp,EBP
	}
	//----
	//RenderScreenGlow();
	//----
	_asm
	{
		MOV EAX,gTmpEax
		MOV ESI,gTmpEsi
		MOV EDI,gTmpEdi
		MOV ECX,gTmpEcx
		MOV EDX,gTmpEdx
		MOV EBX,gTmpEbx
		MOV ESP,gTmpEsp
		MOV EBP,gTmpEbp
		PUSH 0x0
		MOV ECX,DWORD PTR SS:[EBP-0x4]
		//---
		JMP gGraphicsASM00Jmp00
	}
}

void Graphics::Load()
{
	//SetCompleteHook(0xFF, oSelectDraw_Call, &this->SelectDraw);
	//---
	//SetCompleteHook(0xE9,gSelectEnter,&gSelectASM00);
	//---
	//SetCompleteHook(0xE9,gGraphicsEnter,&gGraphicsASM00);
	//---
	this->InitOGLHook();
	//---
	////console.Log(FUNC, "[Graphics]\t\tSuccessfully Loaded");
}


int Graphics::SelectDraw()
{
	//RenderScreenGlow();
	//---
	//printf("Graphics::SelectDraw() Success.\n");
	return pSelectDraw();	
}

//OGL Function Prototypes
void (WINAPI *glEnable_original)(GLenum cap) = glEnable;
void (WINAPI *glClearColor_original)(GLclampf r,GLclampf g,GLclampf b,GLclampf a) = glClearColor;
// ----------------------------------------------------------------------------------------------

void WINAPI glEnable_hook(GLenum mode)
{
	// ---
	if(Anisotropy != 0)
	{
		glGetIntegerv(0x84FF,&MaxAnisotropy);
		glTexParameteri(GL_TEXTURE_2D,0x84FE,MaxAnisotropy-0.1);
	}
	if(Linear != 0)
	{
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	}

	if (Fog == 1)
	{
		CUSTOM_FOG* lpFog = gFog.GetFogByMap(pMapNumber);

		if (lpFog != 0)
		{
			float rgba[4] = {lpFog->Red, lpFog->Green, lpFog->Blue, 1.0f}; gFog.toRGB(rgba);
					
			if (mode == GL_BLEND || mode == GL_TEXTURE_2D || mode == GL_DEPTH_TEST)
				glDisable(GL_FOG);

			glFogi(GL_FOG_MODE, GL_LINEAR);
			glFogf(GL_FOG_DENSITY, 0.25f);
			glFogfv(GL_FOG_COLOR, rgba);
			if(pMapNumber==74)
			{
				glFogf(GL_FOG_START, 4050);
				glFogf(GL_FOG_END, 4850);
			}
			else
			{
				glFogf(GL_FOG_START, 1650.0f);
				glFogf(GL_FOG_END, 2100.0f);
			}
			glHint(GL_FOG_HINT, GL_NICEST);
			 
			glEnable_original(GL_FOG);

			if (mode == GL_BLEND || mode == GL_TEXTURE_2D || mode == GL_DEPTH_TEST) 
				glDisable(GL_FOG); 

			if(!gFog.EnableFog)
			{
				glDisable(GL_FOG);
			}
		}
	}
	glEnable_original(mode);
}

void WINAPI glClearColor_hook(GLclampf r,GLclampf g,GLclampf b,GLclampf a)
{
	if(gFog.EnableFog && Fog && *(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
	{
		CUSTOM_FOG* lpFog = gFog.GetFogByMap(pMapNumber);
		if (lpFog != 0)
		{

			float rgba[4];
			rgba[0] = lpFog->Red;
			rgba[1] = lpFog->Green;
			rgba[2] = lpFog->Blue;
			rgba[3] = 1.0;	
			gFog.toRGB(rgba);

			glClearColor_original(rgba[0],rgba[1],rgba[2],rgba[3]);
		}
	}
}

void Graphics::InitOGLHook()
{
	//---- glEnable
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID &)glEnable_original,glEnable_hook);
	DetourTransactionCommit();

	//---- glClearColor
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID &)glClearColor_original,glClearColor_hook);
	DetourTransactionCommit();
}