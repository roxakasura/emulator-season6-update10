// Original
//#define ItemId(x, y)            ((x * 512) + y)
//#define pPreviewPetThis            *(DWORD*)0x007BC4F04
//#define LODWORD(h)                ((DWORD)(__int64(h) & __int64(0xffffffff)))


// Fix
#define ItemId(x, y)            ((x * 512) + y)
#define MAX_ITEM_INFO 350
#define pGetViewportByIndex		((signed int(__cdecl*)(int a1)) 0x57D9A0)
#define sub_6D9070_Addr1		((int(__cdecl*)(int Type, VAngle* Position, VAngle* Angle, vec3_t Light, int SubType, ObjectModel* Owner, __int16 PKKey, __int16 Skill, __int16 Scale, __int16 SkillSerial, float SkillAngle, __int16 SkillHotKey)) 0x6D9070)
#define  pGCItemChangeRecv		((int(__cdecl*)(PMSG_ITEM_CHANGE_RECV *lpMsg)) 0x6411A0)


namespace eBugType
{
	enum T
	{
		NewPet = 7972,
	};
};

// Fix
struct PMSG_ITEM_CHANGE_RECV
{
	PBMSG_HEAD header; // C1:25
	BYTE index[2];
	BYTE ItemInfo[MAX_ITEM_INFO];
};

typedef void(__thiscall *ObjCreatePet)(int ItemId);
extern ObjCreatePet gObjCreatePet;

typedef int(__cdecl *ObjCreateBug)(int BugId, int Arg2, int Arg3, int Arg4, int Arg5);
extern ObjCreateBug gObjCreateBug;

void gObjCreatePetExHook();