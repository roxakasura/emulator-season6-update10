#pragma once

typedef float vec_t;

typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec34_t[3][4];
typedef unsigned long dword;

#define Vector(a,b,c,d) {(d)[0]=a;(d)[1]=b;(d)[2]=c;}
#define VectorAvg(a) ( ( (a)[0] + (a)[1] + (a)[2] ) / 3 )
#define VectorSubtract(a,b,c) {(c)[0]=(a)[0]-(b)[0];(c)[1]=(a)[1]-(b)[1];(c)[2]=(a)[2]-(b)[2];}
#define VectorAdd(a,b,c) {(c)[0]=(a)[0]+(b)[0];(c)[1]=(a)[1]+(b)[1];(c)[2]=(a)[2]+(b)[2];}
#define VectorCopy(a,b) {(b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2];}
#define QuaternionCopy(a,b) {(b)[0]=(a)[0];(b)[1]=(a)[1];(b)[2]=(a)[2];(b)[3]=(a)[3];}
#define VectorScale(a,b,c) {(c)[0]=(b)*(a)[0];(c)[1]=(b)*(a)[1];(c)[2]=(b)*(a)[2];}
#define DotProduct(x,y) ((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define VectorFill(a,b) { (a)[0]=(b); (a)[1]=(b); (a)[2]=(b);}

#define assert(_Expression) (void)( (!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression), _CRT_WIDE(__FILE__), __LINE__), 0) )
_CRTIMP void __cdecl _wassert(_In_z_ const wchar_t* _Message, _In_z_ const wchar_t* _File, _In_ unsigned _Line);
#define	Q_PI         								3.14159265358979323846f

#define g_hWnd										*(HWND*)0xE8C578
#define WorldTime									*(float *)0x5EF5A1C
#define WaterMove									*(float *)0x82C6A94
#define TerrainFlag									*(DWORD*)0x8787AA0
#define SelectFlag									*(BYTE*)0x82C6650
#define TerrainGrassEnable							*(BYTE*)0xE61E00
#define IsDoppelGanger3								((bool(*)()) 0x008E3130)
#define RenderTerrainFrustrum						((void(__cdecl*)(bool EditFlag)) 0x5DC4D0)
#define pCheckInMouse								((bool(__cdecl*)(int x, int y, int w, int h)) 0x00790B10)
#define g_pNewUISystem2								((int(*)()) 0x861110)
#define	InitCollisionDetectLineToFace				((void(*)()) 0x639430)
#define IsVisible2									((bool(__thiscall*)(int thisa, int Code)) 0x0085EC20)
#define HideSystem									((int(__thiscall*)(int thisa, int Code)) 0x0085F9A0)
#define ShowSystem									((int(__thiscall*)(int thisa, int Code)) 0x0085EC50)
#define LoadBitmapA									((int(__cdecl*)(char * Folder, int Code, int Arg3, int Arg4, int Arg5, int Arg6)) 0x00772330)
#define SkillAttribute								*(DWORD*)0x008128ABC
#define CRenderBitmaps								((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, float Arg6, float Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, float ScaleAlpha)) 0x00637C60)
#define CGlobalBitmap								((void *(__thiscall*)(LPVOID Screen, int a1)) 0x0042CFE0)
#define WindowWidth									*(GLsizei*)0x00E61E58
#define WindowHeight								*(GLsizei*)0x00E61E5C
#define g_fScreenRate_x								*(float*)0x00E7C3D4
#define g_fScreenRate_y								*(float*)0x00E7C3D8
#define MouseX										*(DWORD*)0x00879340C
#define MouseY										*(DWORD*)0x008793410
#define BindTexture									((bool(__cdecl*)(int a1)) 0x00635CF0)
#define g_pRenderTextSetFont						((int(__thiscall*)(LPVOID This, int a2)) 0x420120)
#define glViewport2									((void(__cdecl*)(GLint x, int a2, GLsizei width, GLsizei height)) 0x006363D0)
#define GetOpenGLMatrix								((void(__cdecl*)(int a1)) 0x00635830)
#define gluPerspective2								((int(__cdecl*)(float a1, float a2, float a3, float a4)) 0x006358A0)
#define RenderItem3D								((int(__cdecl*)(float sx,float sy,float Width,float Height,int Type,int Level,int Option1,int ExtOption,bool PickUp)) 0x005CF310)
#define EnableAlphaTest								((void(__cdecl*)(BYTE Mode)) 0x00635FD0)
#define EnableDepthTest								((void(*)()) 0x00635DE0)
#define RenderPointers								((void(*)()) 0x00771230)
#define EnableCullFace								((void(*)()) 0x00635E80)
#define DisableDepthTest							((void(*)()) 0x00635E10)
#define EnableDepthMask								((void(*)()) 0x00635E40)
#define sub_637770									((void(*)( )) 0x00637770)
#define sub_636720									((int (*)( )) 0x00636720)
#define DisableAlphaBlend							((void(__cdecl*)( )) 0x00635F50)
#define EndRenderColor								((void(__cdecl*)())0x00637A30)
#define RenderColor									((void(__cdecl*)(float x,float y,float Width,float Height, float Alpha, int Flag)) 0x006378A0)
#define GetOpenWindow								((int(__thiscall*)(int This, int Code)) 0x0085EC50)
#define MAX_BITMAP_FILE_NAME 256
#define CRenderDrawImage							((void(__cdecl*)(int ModelID, float X, float Y, float W, float H, float CurrentX, float CurrentY)) 0x00790E40)
#define glClearColorBuffer							((void(__cdecl*)(int thisa )) 0x00635EE0)
#define RenderTipText								((void(__cdecl*)(int sx, int sy, LPCSTR Text)) 0x00597220)
#define RenderNumber								((float(__cdecl*)(float x, float y, int iNum, float fScale)) 0x00791000)
#define DeleteBitmap								((void(__cdecl*)(GLuint uiTextureIndex, bool bForce))0x007724E0)
#define Hero										*(DWORD*)0x007BC4F04
#define CharacterAttribute							*(DWORD*)0x008128AC8
//-- texto
#define GetInfoText									((LPVOID(__thiscall*)( )) 0x0041FE10)
#define CRenderTextSetFon							((int (__thiscall*)(int GetTxt, int font)) 0x00420120)
#define CRenderTextSetColor							((int (__thiscall*)(int GetTxt, int info)) 0x00420080)
#define CRenderTextSetBgColor						((int (__thiscall*)(int GetTxt, int info)) 0x004200F0)
#define pRenderText									((int(__thiscall*)(LPVOID thisa, int PosX, int PosY, LPCTSTR Text, int nCount, int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin)) 0x00420150)
#define GlobalText									((char*(__thiscall*)(LPVOID thisa, int LineNumber)) 0x00402320)
#define GlobalLine									(LPVOID)0x008128ADC
#define SeparateTextIntoLines						((int(__cdecl*)( const char *lpszText, char *lpszSeparated, int iMaxLine, int iLineSize)) 0x004D5A40)
#define MouseLButtonPush							(bool)(*(BYTE*)0x008793384)
#define MouseLButtonDBClick							(bool)(*(BYTE*)0x008793380)
#define playSound									((int(__cdecl*)(int BMD, int o, int a3))0x006D6C20)
#define g_isCharacterBuff							((bool(__thiscall*)(DWORD * thisa, int bufftype)) 0x004C8640)
#define RenderImageB								((void(__cdecl*)(GLuint uiImageType, float x, float y, float width, float height)) 0x00790B50)
#define CGetScreenWidth2							((int(*)()) 0x005C6E80)
#define GetAttributeLife							((void(__cdecl*)( )) 0x0080FA10)
#define GetAttributeSD								((void(__cdecl*)( )) 0x00810420)
#define GetAttributeAG								((void(__cdecl*)( )) 0x00810150)
#define CameraViewNear								*(float*)0xE61E38
#define CameraViewFar								*(float*)0xE61E3C
#define CameraFOV									*(float*)0xE61E40
#define CameraTopViewEnable							*(BYTE*)0x87933F8
#define FogEnable									*(BYTE*)0x87933F9
#define FogDensity									*(float*)0xE61E44
#define FogColor									(float*)0xE61E48
#define CameraMatrixF								(LPVOID)0x87933A0
#define GetOpenGLMatrixF							((void(__cdecl*)(LPVOID a1)) 0x00635830)
#define World										*(DWORD*)0xE61E18



class CSEASON_3B
{
public:
	CSEASON_3B();
	virtual ~CSEASON_3B();

	void CRenderBitmap(int Texture, float x, float y, float Width, float Height, float u = 0.f, float v = 0.f, float uWidth = 1.f, float vHeight = 1.f, bool Scale = true, bool StartScale = true, float Alpha = 0.f);
};

extern CSEASON_3B SEASON_3B;
