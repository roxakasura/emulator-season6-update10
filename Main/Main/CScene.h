#define SceneFlag							*(int*)0x0E609E8
#define World								*(int*)0x0E61E18
#define BeginRender							((void(__thiscall*)(float a2)) 0x00546860)
#define RenderMesh							((int(__thiscall*)(int This, signed int a2, int a3, float a4, signed int a5, float a6, float a7, float a8, int a9)) 0x005468A0)
#define EndRender							((void(__cdecl*)()) 0x00546880)
#define TransformPosition					((int(__thiscall*)(int This, int a2, vec3_t WorldPos, vec3_t Bone1, bool a5)) 0x00545030)
#define Joint(x)							((0x30 * x) + 0x7BC08A0)
#define CreateSprite						((int(__cdecl*)(int a1, vec3_t Bone1, float size, vec3_t color, int ObjPos, float, int)) 0x00771310)
#define CreateParticle						((int(__cdecl*)(int a1, int a2, int a3, vec3_t color, int a5, float a6, int a7)) 0x0074CD30)
#define CreateParticle2						((int(__cdecl*)(int a1, vec3_t Bone1, int a3, vec3_t color, int a5, float size, int a7)) 0x0074CD30)
#define BoneTransform						*(int*)0x7BC09C0
#define CreateEffect2						((int(__cdecl*)(int a4, vec3_t Bone1, int a6, vec3_t color, int a8, int a9, __int16 a10, __int16 a11, __int16 a12, __int16 a13, float a14, __int16 a1)) 0x006D9070)
#define RenderCryingWolf2ndObjectVisual		((void(__cdecl*)(int a1, int a2)) 0x008D1C00)
#define RenderBitmap						((void(__cdecl*)(int ImageID, float PosX, float PosY, float Width, float Height, int Arg6, int Arg7, float ScaleX, float ScaleY, bool ScaleSize, bool ScalePosition, bool ScaleAlpha)) 0x637C60)
#define EnableAlphaBlend					((void(__cdecl*)()) 0x636070)
#define EnableAlphaTest						((void(__cdecl*)(BYTE Mode)) 0x635FD0)
#define RenderInfomationR					((int(*)()) 0x4D5EC0)

//SelectPJCord01
#define sub_63CB40			((int(*)(void)) 0x0063CB40)
#define sub_4D5130			((DWORD(__cdecl*)(char a1)) 0x004D5130)
#define sub_9CF1C0			((DWORD(__cdecl*)(DWORD, DWORD, DWORD)) 0x009CF1C0)
#define sub_57FD90			((void(__cdecl*)(signed int a1, int a2, int a3, int a4)) 0x0057FD90)
#define dword_87935A4		*(int*)0x87935A4
#define sub_861110			((int(__cdecl*)()) 0x00861110)
#define sub_861A80			((int(__thiscall*)(DWORD)) 0x00861A80)
#define sub_856BD0			((DWORD(__thiscall*)(char a1)) 0x00856BD0)
#define dword_E8CB30		*(int*)0xE8CB30
#define sub_57D760			((DWORD(__cdecl*)(DWORD)) 0x0057D760)
#define sub_668520			((int(__thiscall*)(char *a1)) 0x00668520)
#define sub_4057B0			((int(__thiscall*)(char *a1)) 0x004057B0)
#define sub_402AD0			((int(__thiscall*)(char *a1)) 0x00402AD0)
#define sub_484A10			((int(__thiscall*)(int This, int a2, char *a3)) 0x00484A10)

//SelectPJCord02
#define sub_586DA0			((int(__cdecl*)(int, int, char, float, float, float)) 0x586DA0)
#define sub_587380			((DWORD(__cdecl*)(char)) 0x587380)
#define sub_63D130			((DWORD(__cdecl*)(int a1)) 0x63D130)
#define sub_5977E0          ((int(*)(void)) 0x005977E0)
#define sub_482B70          ((int(*)()) 0x00482B70)
#define sub_4849A0			((int(__thiscall*)(DWORD)) 0x004849A0)
#define sub_5BB0B0          ((int(*)()) 0x005BB0B0)
#define sub_4D5C60          ((int(*)()) 0x004D5C60)
#define byte_7BD0483		*(BYTE*)0x7BD0483
#define byte_7BD0484		*(BYTE*)0x7BD0484

void CScene();
void CScene803();
void SScene803();
#define CustomSelectServerX700 1
#define CustomSelectCharS13 1