#pragma once
#define MAX_ITEM_INFO			12
#define MAX_BONES				200
#define MAX_MESH				50
#define MAX_VERTICES			15000
#define SERVER_LIST_SCENE		0
#define	NON_SCENE				0
#define WEBZEN_SCENE			1
#define LOG_IN_SCENE			2
#define LOADING_SCENE			3
#define CHARACTER_SCENE			4
#define MAIN_SCENE				5
#define RENDER_COLOR			0x00000001
#define RENDER_TEXTURE			0x00000002
#define RENDER_CHROME			0x00000004
#define RENDER_METAL			0x00000008
#define RENDER_LIGHTMAP			0x00000010
#define RENDER_SHADOWMAP		0x00000020

#define RENDER_BRIGHT			0x00000040
#define RENDER_DARK				0x00000080

#define RENDER_EXTRA			0x00000100
#define RENDER_CHROME2			0x00000200
#define RENDER_WAVE				0x00000400
#define RENDER_CHROME3			0x00000800
#define RENDER_CHROME4			0x00001000
#define RENDER_NODEPTH			0x00002000
#define RENDER_CHROME5			0x00004000
#define RENDER_OIL				0x00008000
#define RENDER_CHROME6			0x00010000
#define RENDER_CHROME7			0x00020000
#ifdef YDG_ADD_DOPPELGANGER_MONSTER
#define RENDER_DOPPELGANGER        0x00040000
#endif	// YDG_ADD_DOPPELGANGER_MONSTER

#define RENDER_CHROME8			0x00080000

#define MODEL_BODY_NUM								32
#define MODEL_BODY_HELM								9689 //-- 9389
#define MODEL_BODY_ARMOR							MODEL_BODY_HELM+MODEL_BODY_NUM //-- 9413
#define MODEL_BODY_PANTS							MODEL_BODY_ARMOR+MODEL_BODY_NUM //-- 9437
#define MODEL_BODY_GLOVES							MODEL_BODY_PANTS+MODEL_BODY_NUM //-- 9461
#define MODEL_BODY_BOOTS							MODEL_BODY_GLOVES+MODEL_BODY_NUM //-- 9485
#define EQUIP_BODY_HELM								278 //-- 9389
#define EQUIP_BODY_ARMOR							304 //-- 9389
#define EQUIP_BODY_PANTS							340 //-- 9389
#define EQUIP_BODY_GLOVES							376 //-- 9389
#define EQUIP_BODY_BOOTS							412 //-- 9389

#define RENDER_WAVE_EXT			0x10000000
#define RENDER_BYSCRIPT			0x80000000
#define SOCKET_EMPTY			0xFF
#define RNDEXT_WAVE				1
#define RNDEXT_OIL				2
#define RNDEXT_RISE				4
#define MAX_MONSTER_SOUND		10//5
#define MODEL_ITEM				1171
#define MAX_ITEM_INDEX			512
#define ITEM_SWORD(x)			(0 + x)   //pal,etc
#define ITEM_AXE(x)				(1 * MAX_ITEM_INDEX + x)  //ran,dru
#define ITEM_MACE(x)			(2 * MAX_ITEM_INDEX + x)  //ran,nec
#define ITEM_SPEAR(x)			(3 * MAX_ITEM_INDEX + x)  //ama
#define ITEM_BOW(x)				(4 * MAX_ITEM_INDEX + x)  //ama
#define ITEM_STAFF(x)			(5 * MAX_ITEM_INDEX + x)  //soc
#define ITEM_SHIELD(x)			(6 * MAX_ITEM_INDEX + x) 
#define ITEM_HELM(x)			(7 * MAX_ITEM_INDEX + x)
#define ITEM_ARMOR(x)			(8 * MAX_ITEM_INDEX + x)
#define ITEM_PANTS(x)			(9 * MAX_ITEM_INDEX + x)
#define ITEM_GLOVES(x)			(10 * MAX_ITEM_INDEX + x)
#define ITEM_BOOTS(x)			(11 * MAX_ITEM_INDEX + x)
#define ITEM_WING(x)			(12 * MAX_ITEM_INDEX + x)
#define ITEM_HELPER(x)			(13 * MAX_ITEM_INDEX + x)
#define ITEM_POTION(x)			(14 * MAX_ITEM_INDEX + x)
#define ITEM_ETC(x)				(15 * MAX_ITEM_INDEX + x)
#define MAX_SOCKETS				5
#define MAX_ITEM_SPECIAL		8
#define MAX_CLASS				8
#define MAX_RESISTANCE			7

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec34_t[3][4];

typedef struct
{
	vec3_t StartPos;
	vec3_t XAxis;
	vec3_t YAxis;
	vec3_t ZAxis;
} OBB_t_ok;

struct OBJECT
{
	BYTE arg[4];
	/*+4*/	bool          Live;
	/*+5*/	bool          bBillBoard;
	/*+6*/	bool          m_bCollisionCheck;		//  충돌 체크 할까?
	/*+7*/	bool          m_bRenderShadow;			//  그림자를 찍을까? 말까?
	/*+8*/	bool          EnableShadow;
	/*+9*/	bool		  LightEnable;
	/*+10*/	bool		  m_bActionStart;
	/*+11*/	bool		  m_bRenderAfterCharacter;
	/*+12*/	bool	      Visible;
	/*+13*/	bool	      AlphaEnable;
	/*+14*/	bool          EnableBoneMatrix;
	/*+15*/	bool		  ContrastEnable;
	/*+16*/	bool          ChromeEnable;
	/*+17*/	unsigned char AI;
	/*+18*/	unsigned short CurrentAction;
	/*+19*/	unsigned short PriorAction;
	/*+20*/		BYTE          ExtState;
	/*+21*/		BYTE          Teleport;
	/*+22*/		BYTE          Kind;
	/*+23*/		WORD		Skill;
	/*+24*/		BYTE		  m_byNumCloth;				// 천 개수
	/*+25*/		BYTE		  m_byHurtByOneToOne;
	/*+26*/		BYTE          WeaponLevel;
	/*+27*/		BYTE          DamageTime;				//  공격을 받은 충격 시간.
	/*+28*/		BYTE          m_byBuildTime;
	/*+29*/		BYTE		  m_bySkillCount;
	/*+30*/		BYTE		  m_bySkillSerialNum;
	/*+31*/		BYTE		  Block;
	/*+32*/	void* m_pCloth;	// 천 붙이기
	/*+40*/	short         ScreenX;
	/*+42*/	short         ScreenY;
	/*+44*/	short         PKKey;
	/*+46*/	short         Weapon;
	/*+48*/	int			  Type;
	/*+52*/	int           SubType;
	/*+56*/	int			  m_iAnimation;				// 펜릴 발바닥 관련 에니메이션 키값
	/*+60*/	int           HiddenMesh;
	/*+64*/	int           LifeTime;
	/*+68*/	int           BlendMesh;
	int           AttackPoint[2];
	int           RenderType;
	int			  InitialSceneFrame;
	int           LinkBone;
	/*92*/		DWORD		  m_dwTime;
	/*+96*/		float         Scale;
	/*+100*/	float         BlendMeshLight;
	/*+104*/	float         BlendMeshTexCoordU;
	/*+108*/	float         BlendMeshTexCoordV;
	/*+112*/	float         Timer;
	/*+116*/	float         m_fEdgeScale;				//  외곽선 스케일.	
	/*+120*/	float         Velocity;
	/*+124*/	float		  CollisionRange;
	/*+128*/	float         ShadowScale;
	/*+132*/	float         Gravity;
	/*+136*/	float         Distance;
	/*+140*/	float         AnimationFrame;
	/*+144*/	float         PriorAnimationFrame;
	/*+148*/	float	      AlphaTarget;
	/*+152*/	float         Alpha;
	vec3_t        Light;
	vec3_t        Direction;
	vec3_t		  m_vPosSword;				// 칼끝 위치
	vec3_t		  StartPosition;			// bullet
	vec3_t        BoundingBoxMin;
	vec3_t        BoundingBoxMax;
	vec3_t		  m_vDownAngle;
	vec3_t		  m_vDeadPosition;
	/*+252*/	vec3_t        Position;
	/*+264*/	vec3_t	 	  Angle;
	/*+276*/	vec3_t	 	  HeadAngle;
	/*+288*/	vec3_t	   	  HeadTargetAngle;
	/*+300*/	vec3_t  	  EyeLeft;
	/*+312*/	vec3_t  	  EyeRight;
	/*+324*/	vec3_t		  EyeLeft2;
	/*+336*/	vec3_t		  EyeRight2;
	/*+348*/	vec3_t		  EyeLeft3;
	/*+360*/	vec3_t		  EyeRight3;
	/*+372*/	vec34_t	 	  Matrix;
	vec34_t* BoneTrans;
	OBB_t_ok		  OBB;
	OBJECT* Owner;
	OBJECT* Prior;
	OBJECT* Next;
	BYTE		  m_BuffMap[134];
	short int	  m_sTargetIndex;
	BOOL		  m_bpcroom;
	vec3_t		  m_v3PrePos1;
	vec3_t		  m_v3PrePos2;
};

#pragma pack(push, 1)
typedef struct tagITEM	//-> Complete (size: 107)
{
	/*+0*/		WORD	Type;
	/*+2*/		int		Level;
	/*+6*/		BYTE	Part;
	/*+7*/		BYTE	Class;
	/*+8*/		bool	TwoHand;
	/*+9*/		WORD	DamageMin;
	/*+11*/		WORD	DamageMax;
	/*+13*/		BYTE	SuccessfulBlocking;
	/*+14*/		WORD	Defense;
	/*+16*/		WORD	MagicDefense;
	/*+18*/		BYTE	MagicPower;
	/*+19*/		BYTE	WeaponSpeed;
	/*+20*/		WORD	WalkSpeed;
	/*+22*/		BYTE	Durability;
	/*+23*/		BYTE	Option1;
	/*+24*/		BYTE	ExtOption;
	/*+25*/		WORD	RequireStrength;
	/*+27*/		WORD	RequireDexterity;
	/*+29*/		WORD	RequireEnergy;
	/*+31*/		WORD	RequireVitality;
	/*+33*/		WORD	RequireCharisma;
	/*+35*/		WORD	RequireLevel;
	/*+37*/		BYTE	SpecialNum;
	/*+38*/		WORD	Special[MAX_ITEM_SPECIAL];
	/*+54*/		BYTE	SpecialValue[MAX_ITEM_SPECIAL];
	/*+62*/		DWORD	Key;
	/*+66*/		BYTE	bySelectedSlotIndex;
	/*+67*/		BYTE	x;
	/*+68*/		BYTE	y;
	/*+69*/		WORD	Jewel_Of_Harmony_Option;
	/*+71*/		WORD	Jewel_Of_Harmony_OptionLevel;
	/*+73*/		bool	option_380;
	/*+74*/		BYTE	bySocketOption[MAX_SOCKETS];
	/*+79*/		BYTE	SocketCount;
	/*+80*/		BYTE	SocketSeedID[MAX_SOCKETS];
	/*+85*/		BYTE	SocketSphereLv[MAX_SOCKETS];
	/*+90*/		BYTE	SocketSeedSetOption;
	int		Number;
	BYTE	Color;
	/*+96*/		BYTE	byColorState;
	/*+97*/		bool	PeriodItem;
	/*+98*/		bool	ExpiredItem;
	/*+99*/		int		lExpireTime;
	/*+103*/	int		RefCount;
} ITEM;
#pragma pack(pop)

typedef std::map<int, ITEM*> type_vec_item;

enum TOOLTIP_TYPE
{
	UNKNOWN_TOOLTIP_TYPE = 0,
	TOOLTIP_TYPE_INVENTORY,
	TOOLTIP_TYPE_REPAIR,
	TOOLTIP_TYPE_NPC_SHOP,
	TOOLTIP_TYPE_MY_SHOP,
	TOOLTIP_TYPE_PURCHASE_SHOP,
};
enum EVENT_STATE
{
	EVENT_NONE = 0,
	EVENT_HOVER,
	EVENT_PICKING,
};

typedef struct _PART_t
{
	short Type;
	BYTE  Level;
	BYTE  Option1;
	BYTE  ExtOption;
	BYTE  LinkBone;
	BYTE  CurrentAction;
	unsigned short  PriorAction;
	float AnimationFrame;
	float PriorAnimationFrame;
	float PlaySpeed;
	BYTE m_byNumCloth;
	void* m_pCloth[2];

	_PART_t()
	{
		Type = 0;
		Level = 0;
		Option1 = 0;
		ExtOption = 0;
		LinkBone = 0;
		CurrentAction = 0;
		PriorAction = 0;
		AnimationFrame = 0;
		PriorAnimationFrame = 0;
		PlaySpeed = 0;
		m_byNumCloth = 0;
		m_pCloth[0] = NULL;
		m_pCloth[1] = NULL;
	}

} PART_t;

typedef struct //-> InDev (size: 1432)
{
	BYTE		byClass[5];
	bool        Blood;
	bool        Ride;
	bool        SkillSuccess;
	BOOL        m_bFixForm;
	bool        Foot[2];
	/*+14*/		bool	SafeZone;
	/*+15*/		bool	Change;
	/*+16*/		bool	HideShadow;
	/*+17*/		bool	m_bIsSelected;
	/*+18*/		bool	Decoy;
	/*+19*/		BYTE	Class;
	/*+20*/		BYTE	Skin;
	/*+21*/		BYTE	CtlCode;	//Bit decomposit (0x10)
	/*+22*/		BYTE	ExtendState;
	/*+23*/		BYTE	EtcPart;
	/*+24*/		BYTE	GuildStatus;
	/*+25*/		BYTE	GuildType;
	/*+26*/		BYTE	GuildRelationShip;
	/*+27*/		BYTE	GuildSkill;
	/*+28*/		BYTE	GuildMasterKillCount;
	/*+29*/		BYTE	BackupCurrentSkill;
	/*+30*/		BYTE	GuildTeam;
	/*+31*/		BYTE	m_byGensInfluence;	//0 - None, 1 - D, 2 - V
	/*+32*/		BYTE	PK;
	/*+33*/		char	PKPartyLevel;
	/*+34*/		BYTE	AttackFlag;
	/*+35*/		BYTE	AttackTime;
	/*+36*/		BYTE	TargetAngle;	//Personal Shop
	/*+37*/		BYTE	Dead;
	/*+40*/		WORD	Skill;
	/*+41*/		BYTE	SwordCount;
	/*+42*/		BYTE	byExtensionSkill;
	BYTE	m_byDieType;			//	죽는 형식.
	BYTE	StormTime;
	BYTE	JumpTime;
	/*+45*/		BYTE	RespawnPosX;
	/*+46*/		BYTE	RespawnPosY;
	BYTE    Appear;
	/*+50*/		BYTE	CurrentSkill;
	BYTE    CastRenderTime;
	BYTE    m_byFriend;
	WORD    MonsterSkill;
	/*+56*/		char    Name[32];	//need check size
	char 		Movement;
	BYTE gap06[30];
	/*+120*/	BYTE	Unknown120;
	/*+121*/	BYTE	Unknown121;
	BYTE gap07[2];
	/*+124*/	WORD	Unknown124;
	/*+126*/	WORD	aIndex;
	/*+128*/	WORD	Unknown128;
	/*+130*/	WORD	Decolorate;
	/*+132*/	WORD	ID;
	/*+134*/	WORD	Unknown134;
	/*+136*/	//maybe word
	BYTE gap09[36];
	/*+172*/	int		PositionX;
	/*+176*/	int		PositionY;
	BYTE gap10[8];
	/*+188*/	float	Unknown188;
	BYTE gap11[32];
	float	ProtectGuildMarkWorldTime;
	float	AttackRange;
	float	Freeze;
	float   Duplication;
	float	Rot;
	vec3_t  TargetPosition;
	vec3_t  Light;
	//--
	/*+268*/	short	Helm_Type;
	/*+270*/	BYTE	HelmLevel;
	/*+271*/	BYTE	HelmExcellent;
	/*+272*/	BYTE	HelmAncient;
	BYTE gap12[31];
	/*+304*/	short	Armor_Type;
	/*+306*/	BYTE	ArmorLevel;
	/*+307*/	BYTE	ArmorExcellent;
	/*+308*/	BYTE	ArmorAncient;
	BYTE gap13[31];
	/*+340*/	short	Pants_Type;
	/*+342*/	BYTE	PantsLevel;
	/*+343*/	BYTE	PantsExcellent;
	/*+344*/	BYTE	PantsAncient;
	BYTE gap14[31];
	/*+376*/	short	Gloves_Type;
	/*+378*/	BYTE	GlovesLevel;
	/*+379*/	BYTE	GlovesExcellent;
	/*+380*/	BYTE	GlovesAncient;
	BYTE gap15[31];
	/*+412*/	short	Boots_Type;
	/*+414*/	BYTE	BootsLevel;
	/*+415*/	BYTE	BootsExcellent;
	/*+416*/	BYTE	BootsAncient;
	BYTE gap16[31];
	/*+448*/	short	WeaponFirst_Type;
	/*+450*/	BYTE	WeaponFirstLevel;
	/*+451*/	BYTE	WeaponFirstExcellent;
	/*+452*/	BYTE	WeaponFirstAncient;
	BYTE gap17[31];
	/*+484*/	short	WeaponSecond_Type;
	/*+486*/	BYTE	WeaponSecondLevel;
	/*+487*/	BYTE	WeaponSecondExcellent;
	/*+488*/	BYTE	WeaponSecondAncient;
	BYTE gap18[31];
	/*+520*/	short	Wing_Type;
	/*+522*/	BYTE	Wing_Level;
	/*+523*/	BYTE	Wing_Option1;
	/*+524*/	BYTE	Wing_ExtOption;
	BYTE gap19[31];
	/*+556*/	short	Helper_Type;
	/*+558*/	BYTE	Helper_Level;
	/*+559*/	BYTE	Helper_Option1;
	/*+560*/	BYTE	Helper_ExtOption;
	BYTE	Helper_LinkBone;
	BYTE	Helper_CurrentAction;
	BYTE gap20[109];
	/*+672*/	DWORD	Unknown672;
	/*+676*/	DWORD	Unknown676;
	/*+680*/	DWORD	RavenSlot;
	BYTE gap21[80];
	/*+764*/	DWORD	Unknown764;
	BYTE gap22[8];
	/*+776*/	OBJECT	Object;
	/*+1424*/	BYTE	m_byRankIndex;	//maybe gens rank
	BYTE gap23[3];
	/*+1428*/	DWORD	Unknown1428;	//-> end
} CHARACTER_PRE, * CHARACTER;

typedef struct
{
	char Name[30];
	/*+30*/	bool TwoHand;
	/*+32*/	WORD Level;
	/*+34*/	BYTE m_byItemSlot;
	/*+36*/	WORD m_wSkillIndex;
	/*+38*/	BYTE Width;
	/*+39*/	BYTE Height;
	/*+40*/	short DamageMin;
	/*+41*/	short DamageMax;
	/*+42*/	BYTE SuccessfulBlocking;
	/*+43*/	short Defense;
	/*+44*/	BYTE MagicDefense;
	/*+45*/	BYTE WeaponSpeed;
	/*+46*/	BYTE WalkSpeed;
	/*+47*/	BYTE Durability;
	/*+48*/	BYTE MagicDur;
	/*+49*/	BYTE MagicPower;
	/*+50*/	WORD RequireStrength;
	/*+52*/	WORD RequireDexterity;
	/*+54*/	WORD RequireEnergy;
	/*+56*/	WORD  RequireVitality;
	/*+58*/	WORD RequireCharisma;
	/*+60*/	WORD RequireLevel;
	/*+62*/	BYTE Value;
	/*+64*/	int  iZen;
	/*+68*/	BYTE  AttType;
	/*+69*/	BYTE RequireClass[MAX_CLASS];
	/*+77*/	BYTE Resistance[MAX_RESISTANCE];
} ITEM_ATTRIBUTE;

typedef struct
{
	/*+00*/	char Name[32];
	/*+32*/	WORD Level;
	/*+34*/	WORD Damage;
	/*+36*/	WORD Mana;
	/*+38*/	WORD AbilityGuage;
	/*+40*/	DWORD Distance;
	/*+44*/	int Delay;
	/*+48*/	int Energy;
	/*+52*/	WORD Charisma;
	/*+54*/	BYTE MasteryType;
	/*+55*/	BYTE SkillUseType;
	/*+56*/	DWORD SkillBrand;
	/*+60*/	BYTE KillCount;
	/*+61*/	BYTE RequireDutyClass[3];
	/*+64*/	BYTE RequireClass[8];
	/*+71*/	BYTE SkillRank;
	/*+72*/	WORD Magic_Icon;
	/*+74*/	BYTE TypeSkill;
	/*+75*/	BYTE gap_4B;
	/*+76*/	int Strength;
	/*+80*/	int Dexterity;
	/*+84*/	BYTE ItemSkill;
	/*+85*/	BYTE IsDamage;
	/*+86*/	WORD Effect;
} SKILL_ATTRIBUTE;

extern ITEM_ATTRIBUTE* ItemAttribute;
extern SKILL_ATTRIBUTE* pSkillAttribute;

#define BLOODCASTLE_NUM 8
#define HELLAS_NUM      7
#define CHAOS_NUM       6

enum ENUM_WORLD
{
	WD_0LORENCIA = 0,	// 0    로랜시아.
	WD_1DUNGEON,					// 1    던전.
	WD_2DEVIAS,						// 2    데비아스.
	WD_3NORIA,						// 3    노리아.
	WD_4LOSTTOWER,					// 4    로스트타워.
	WD_5UNKNOWN,					// 5    
	WD_6STADIUM,					// 6    배틀싸커 경기장.
	WD_7ATLANSE,					// 7    아틀란스.
	WD_8TARKAN,						// 8    타르칸.
	WD_9DEVILSQUARE,				// 9    악마의 광장.
	WD_10HEAVEN,					// 10   천공.
	WD_11BLOODCASTLE1,				// 11   블러드 1캐슬.
	WD_11BLOODCASTLE_END = WD_11BLOODCASTLE1 + 6,// 11 + 6   블러드 7캐슬.
	WD_18CHAOS_CASTLE,				//  18  카오스캐슬.
	WD_18CHAOS_CASTLE_END = WD_18CHAOS_CASTLE + (CHAOS_NUM - 1),
	WD_24HELLAS,					//  24  헬라스.
	WD_24HELLAS_END = WD_24HELLAS + (HELLAS_NUM - 2),	//6칼리마까지
	WD_30BATTLECASTLE,
	WD_31HUNTING_GROUND = 31,	// 31 공성전 사냥터
	WD_33AIDA = 33,	// 33 아이다
	WD_34CRYWOLF_1ST = 34,	// 34 크라이울프 MVP
	WD_35CRYWOLF_2ND = 35,	// 35 크라이울프 2차에 쓰일뻔함(현재 안씀 : 이번호 딴걸로 써도됨)
	WD_24HELLAS_7 = 36,	// 36 히든 칼리마
	WD_37KANTURU_1ST = 37,	// 37 칸투르 1차
	WD_38KANTURU_2ND = 38,	// 38 칸투르 2차
	WD_39KANTURU_3RD = 39,	// 39 칸투르 3차
	WD_40AREA_FOR_GM = 40,	// GM 소환 지역
	WD_41CHANGEUP3RD_1ST = 41,	// 41 발가스의 병영
	WD_42CHANGEUP3RD_2ND = 42,	// 42 발가스의 안식처
	WD_45CURSEDTEMPLE_LV1 = 45,	// The event map for the capture the flag
	WD_45CURSEDTEMPLE_LV2,			// The event map for the capture the flag
	WD_45CURSEDTEMPLE_LV3,			// The event map for the capture the flag
	WD_45CURSEDTEMPLE_LV4,			// The event map for the capture the flag
	WD_45CURSEDTEMPLE_LV5,			// The event map for the capture the flag
	WD_45CURSEDTEMPLE_LV6,			// The event map for the capture the flag
	WD_51HOME_6TH_CHAR = 51,	// 51 신캐릭터 시작맵
	WD_52BLOODCASTLE_MASTER_LEVEL = 52,
	WD_53CAOSCASTLE_MASTER_LEVEL = 53,
	WD_54CHARACTERSCENE = 54,			// 54 새로운 케릭터 씬
	WD_55LOGINSCENE = 55,			// 55 새로운 로그인 씬
	WD_56MAP_SWAMP_OF_QUIET = 56,		// 56 평온의 늪
	WD_57ICECITY = 57,		// 57 얼음도시
	WD_58ICECITY_BOSS = 58,		// 58 얼음도시 보스맵
	WD_62SANTA_TOWN = 62,		// 62 산타마을
	WD_63PK_FIELD = 63,		// 63 PK필드
	WD_64DUELARENA = 64,		// 64 결투장
	WD_65DOPPLEGANGER1 = 65,		// 65 도플갱어 이벤트 맵 1 (57라클리온베이스)
	WD_66DOPPLEGANGER2 = 66,		// 66 도플갱어 이벤트 맵 2 (63불카누스베이스)
	WD_67DOPPLEGANGER3 = 67,		// 67 도플갱어 이벤트 맵 3 ( 7아틀란스베이스)
	WD_68DOPPLEGANGER4 = 68,		// 68 도플갱어 이벤트 맵 4 (37칸투르1차베이스)
	WD_69EMPIREGUARDIAN1 = 69,		// 69 제국 수호군 맵 1 (월, 목 평일맵)
	WD_70EMPIREGUARDIAN2 = 70,		// 70 제국 수호군 맵 2 (화, 금 평일맵)
	WD_71EMPIREGUARDIAN3 = 71,		// 71 제국 수호군 맵 3 (수, 토 평일맵)
	WD_72EMPIREGUARDIAN4 = 72,		// 72 제국 수호군 맵 4 (일     주말맵)
	WD_73NEW_LOGIN_SCENE = 73,	// 74 기본 제국수호군4 맵으로 제작
	WD_74NEW_CHARACTER_SCENE = 74,	// 75 기본 제국수호군4 맵으로 제작
	WD_77NEW_LOGIN_SCENE = 77,	// 77 더 새로운 서버 선택씬
	WD_78NEW_CHARACTER_SCENE = 78,	// 78 더 새로운 캐릭터 선택씬
	WD_79UNITEDMARKETPLACE = 79,	// 79 통합 시장 서버 (로렌시장)
	WD_80KARUTAN1 = 80,		// 80 칼루탄 1
	WD_81KARUTAN2 = 81,		// 81 칼루탄 2
	NUM_WD
};


#define ConvertItemType								((int   (__cdecl*)(BYTE* Item)) 0x0058AA80)
#define CreateBug                 ((void  (__cdecl*)(int Type, vec3_t Position, OBJECT *Owner, int SubType, int LinkBone)) 0x00501700)