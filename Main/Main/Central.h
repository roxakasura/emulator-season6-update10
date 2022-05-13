#define sub_4DB0E0					((BOOL(__cdecl*)(int a1))0x004DB0E0)
#define sub_59A8B0					((bool(__stdcall*)())0x0059A8B0)
//-- Cursor
#define sub_637E80					((void(__cdecl*)(int x, float y, float w, float h, float giro, float a9, float a10, float a11, float a12, float a13))0x00637E80)
#define sub_4F6170					((void(__cdecl*)(float a1))0x004F6170)
#define sub_83C310					((char(__thiscall*)(DWORD * This))0x0083C310)
#define sub_861260					((int(__thiscall*)(int This))0x00861260)
#define getWindowConfig_35			((int(__thiscall*)(int This))0x00861620)

#define sub_78ECE0					((int(__thiscall*)(int This))0x0078ECE0)
#define sub_8615E0					((int(__thiscall*)(int This))0x008615E0)
#define sub_861280					((int(__thiscall*)(int This))0x00861280)
#define sub_834550					((int(__thiscall*)(int This))0x00834550)
#define sub_847EF0					((int(__thiscall*)(int This))0x00847EF0)

#define CursorX					*(DWORD*)0x879340C
#define CursorY					*(DWORD*)0x8793410
#define ItemTarget					*(DWORD*)0xE61728
#define NpcTarget					*(DWORD*)0xE6172C
#define PlayerTarget				*(DWORD*)0xE61730
//--
#define RenderBitmap		((void(__cdecl*)(int a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, char a10, char a11, float a12)) 0x00637C60)

//--
#define sub_861A60					((int(__thiscall*)(int This))0x00861A60)
#define sub_7D6270					((int(__thiscall*)(int This, int a5))0x007D6270)
//--
class Centralizado
{
public:
	Centralizado();
	virtual ~Centralizado();
	void PrintDropBox(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6);
	void PrintDropBoxTest(float PosX, float PosY, float Width, float Height, float Arg5, int Arg6);
	void InitCentral();
	static signed int MoveRenderCameraDefault();
}; extern Centralizado gCentral;