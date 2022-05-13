#pragma once
#include <windows.h>

#define oSelectDraw_Call		0x00405A32//00407436
#define pSelectDraw	((int(__cdecl*)()) 0x0041FE10)//00420BD4)
//

//#define pWinWidth				*(GLsizei*)0x0E61E58
//#define pWinHeight				*(GLsizei*)0x0E61E5C

class Graphics
{
public:
	Graphics();
	// ----
	void		Load();
	static void	InterfaceDraw();
	static int  SelectDraw();
	void InitOGLHook();
}; 
extern Graphics gGraphics;