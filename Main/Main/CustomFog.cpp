#include "stdafx.h"
#include "Common.h"
#include "CustomFog.h"
#include "Defines.h"
#include "Import.h"
#include "Offset.h"
#include "TMemory.h"

cFog gFog;

cFog::cFog()
{
	//this->Init();
		this->EnableFog = true;
	for (int n = 0; n < MAX_FOG; n++)
	{
		this->m_CustomFog[n].Index = -1;
	}
}

cFog::~cFog()
{

}

void cFog::Load(CUSTOM_FOG* info)
{
	for(int n=0;n < MAX_FOG;n++)
	{
		this->SetInfo(info[n]);
	}
}

void cFog::SetInfo(CUSTOM_FOG info)
{
	if(info.Index < 0 || info.Index >= MAX_FOG)
	{
		return;
	}
	this->m_CustomFog[info.Index] = info;
}

CUSTOM_FOG* cFog::GetFogByMap(int MapNumber)
{
	for(int n=0;n < MAX_FOG;n++)
	{
		CUSTOM_FOG* lpInfo = this->GetFogByIndex(n);

		if(lpInfo == 0)
		{
			continue;
		}

		if(lpInfo->MapNumber == MapNumber)
		{
			return lpInfo;
		}
	}

	return 0;
}

CUSTOM_FOG* cFog::GetFogByIndex(int index)
{
	if(index < 0 || index >= MAX_FOG)
	{
		return 0;
	}

	if(this->m_CustomFog[index].Index != index)
	{
		return 0;
	}

	return &this->m_CustomFog[index];
}

float *cFog::toRGB(float *rgba)
{
	rgba[0] /= 255.0;
	rgba[1] /= 255.0;
	rgba[2] /= 255.0;

	return rgba;
}

////OGL Function Prototypes
//void (WINAPI *glEnable_original)(GLenum cap) = glEnable;
//void (WINAPI *glClearColor_original)(GLclampf r,GLclampf g,GLclampf b,GLclampf a) = glClearColor;
//
//void WINAPI glEnable_hook(GLenum mode)
//{
//	MessageBox(0,"1","Error",MB_OK | MB_ICONERROR);
//	// ---
//	if(Anisotropy != 0)
//	{
//		glGetIntegerv(0x84FF,&MaxAnisotropy);
//		glTexParameteri(GL_TEXTURE_2D,0x84FE,MaxAnisotropy-0.1);
//	}
//	if(Linear != 0)
//	{
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//	}
//
//	if (Fog == 1)
//	{
//		CUSTOM_FOG* lpFog = gFog.GetFogByMap(pMapNumber);
//
//		if (lpFog != 0)
//		{
//			float rgba[4] = {lpFog->Red, lpFog->Green, lpFog->Blue, 1.0f}; gFog.toRGB(rgba);
//					
//			if (mode == GL_BLEND || mode == GL_TEXTURE_2D || mode == GL_DEPTH_TEST)
//				glDisable(GL_FOG);
//
//			glFogi(GL_FOG_MODE, GL_LINEAR);
//			glFogf(GL_FOG_DENSITY, 0.25f);
//			glFogfv(GL_FOG_COLOR, rgba);
//			if(pMapNumber==74)
//			{
//				glFogf(GL_FOG_START, 4050);
//				glFogf(GL_FOG_END, 4850);
//			}
//			else
//			{
//				glFogf(GL_FOG_START, 1650.0f);
//				glFogf(GL_FOG_END, 2100.0f);
//			}
//			glHint(GL_FOG_HINT, GL_NICEST);
//			 
//			glEnable_original(GL_FOG);
//
//			if (mode == GL_BLEND || mode == GL_TEXTURE_2D || mode == GL_DEPTH_TEST) 
//				glDisable(GL_FOG); 
//
//			if(!gFog.EnableFog)
//			{
//				glDisable(GL_FOG);
//			}
//		}
//	}
//	glEnable_original(mode);
//	
//}
//
//void WINAPI glClearColor_hook(GLclampf r,GLclampf g,GLclampf b,GLclampf a)
//{
//	if(gFog.EnableFog && Fog && *(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
//	{
//		CUSTOM_FOG* lpFog = gFog.GetFogByMap(pMapNumber);
//		if (lpFog != 0)
//		{
//
//			float rgba[4];
//			rgba[0] = lpFog->Red;
//			rgba[1] = lpFog->Green;
//			rgba[2] = lpFog->Blue;
//			rgba[3] = 1.0;	
//			gFog.toRGB(rgba);
//
//			glClearColor_original(rgba[0],rgba[1],rgba[2],rgba[3]);
//		}
//	}
//}
//
//void cFog::InitOGLHook()
//{
//
//	//---- glEnable
//	DetourTransactionBegin();
//	DetourUpdateThread(GetCurrentThread());
//	DetourAttach(&(PVOID &)glEnable_original,glEnable_hook);
//	DetourTransactionCommit();
//
//	//---- glClearColor
//	//DetourTransactionBegin();
//	//DetourUpdateThread(GetCurrentThread());
//	//DetourAttach(&(PVOID &)glClearColor_original,glClearColor_hook);
//	//DetourTransactionCommit();
//}

bool cFog::CheckBlackMaps()
{
    switch(pMapNumber)
    {
        case eMapNumber::Dungeon:
        case eMapNumber::LostTower:
		case eMapNumber::DevilSquaree:
        case eMapNumber::ChaosCastle1:
        case eMapNumber::ChaosCastle2:
        case eMapNumber::ChaosCastle3:
        case eMapNumber::ChaosCastle4:
        case eMapNumber::ChaosCastle5:
        case eMapNumber::ChaosCastle6:
        case eMapNumber::ChaosCastle7:
        case eMapNumber::BloodCastle1:
        case eMapNumber::BloodCastle2:
        case eMapNumber::BloodCastle3:
        case eMapNumber::BloodCastle4:
        case eMapNumber::BloodCastle5:
        case eMapNumber::BloodCastle6:
        case eMapNumber::BloodCastle7:
        case eMapNumber::BloodCastle8:
        case eMapNumber::DevilSquare6:
        {
            return true;
        }
        break;
        // ----
        default:
        {
            return false;
        }
        break;
    }
    return false;
}


bool cFog::CheckEventMaps()
{
    switch(pMapNumber)
    {
        case eMapNumber::Icarus:
        case eMapNumber::DevilSquaree:
        case eMapNumber::ChaosCastle1:
        case eMapNumber::ChaosCastle2:
        case eMapNumber::ChaosCastle3:
        case eMapNumber::ChaosCastle4:
        case eMapNumber::ChaosCastle5:
        case eMapNumber::ChaosCastle6:
        case eMapNumber::ChaosCastle7:
        case eMapNumber::BloodCastle1:
        case eMapNumber::BloodCastle2:
        case eMapNumber::BloodCastle3:
        case eMapNumber::BloodCastle4:
        case eMapNumber::BloodCastle5:
        case eMapNumber::BloodCastle6:
        case eMapNumber::BloodCastle7:
        case eMapNumber::BloodCastle8:
        case eMapNumber::DevilSquare6:
        {
            return true;
        }
        break;
        // ----
        default:
        {
            return false;
        }
        break;
    }
    return false;
}


bool cFog::glAllowedFog(GLenum cap)
{
    if (cap != GL_TEXTURE_2D || cap != GL_DEPTH_TEST || cap != GL_ALPHA || cap != GL_2D || cap != GL_RGB || cap != GL_ALPHA_SCALE || cap != GL_RGBA)
    {
        return true;
    }
    else
    {
        return false;
    }
}


void cFog::glMainEnable(GLenum cap)
{
	
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

    if(*(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
    {
        if (gFog.CheckEventMaps() != true)
        {
            if (gFog.CheckBlackMaps() == true)
            {
                if (gFog.glAllowedFog(cap) == true)
                {
                    GLfloat params[4] = { 0.f,0.f,0.f,0.f };
                    // ----
					GLfloat StartCoords[1] = { (floorf(oCam_RotZ - 45.0f) * 360.0f) + 3000.0f };
                    // ----
                    glEnable(GL_FOG);
                    glFogfv(GL_FOG_COLOR,params);
                    glFogf(GL_FOG_DENSITY,0.25f);
                    glFogf(GL_FOG_MODE,GL_LINEAR);
                    glFogf(GL_FOG_START,1650.0f);
                    glFogfv(GL_FOG_END,StartCoords);

					
					

                }
            }
            else
            {
                if (gFog.glAllowedFog(cap) == true)
                {
					if (Fog == 1)
					{
						CUSTOM_FOG* lpFog = gFog.GetFogByMap(pMapNumber);

						if (lpFog != 0)
						{
							float rgba[3] = {lpFog->Red, lpFog->Green, lpFog->Blue}; gFog.toRGB(rgba);

							GLfloat params[4] = { rgba[0],rgba[1],rgba[2],1.0f };
							GLfloat StartCoords[1] = { 2100.0f };
							// ----
							glEnable(GL_FOG);
							glFogfv(GL_FOG_COLOR,params);
							glFogf(GL_FOG_DENSITY,0.25f);
							glFogf(GL_FOG_MODE,GL_LINEAR);
							glFogf(GL_FOG_START,1650.0f);
							glFogfv(GL_FOG_END,StartCoords);

							

							//glHint(GL_FOG_HINT, GL_NICEST);
						}
					}
                }
            }
        }
        else
        {
            gFog.glMainDisable();
        }
    }

}


void cFog::glMainDisable()
{
    if(*(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
    {
        glDisable(GL_FOG);
    }
}

void cFog::glClearColor(GLclampf r,GLclampf g,GLclampf b,GLclampf a)
{
	if(gFog.EnableFog && Fog && *(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
	{
		CUSTOM_FOG* lpFog = gFog.GetFogByMap(pMapNumber);

		if (lpFog != 0)
		{
			float rgba[3] = {lpFog->Red, lpFog->Green, lpFog->Blue}; gFog.toRGB(rgba);
			glClearColor(rgba[0],rgba[1],rgba[2],1.0);
		}
	}
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

	if (Fog == 1 && *(DWORD*)(MAIN_SCREEN_STATE) == GameProcess)
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
			return;
		}
	}
	glClearColor_original(r,g,b,a);

}


void cFog::Init()
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(&(PVOID &)glEnable_original,glEnable_hook);
	DetourAttach(&(PVOID &)glClearColor_original,glClearColor_hook);
	DetourTransactionCommit();
}



void cFog::MainFogAllowed()
{
    SetRange((LPVOID)0x004D9938,2, ASM::NOP);
    SetRange((LPVOID)0x004D9954,2, ASM::NOP);
	SetByte((LPVOID)0x004D87EC, 0x0E);
}