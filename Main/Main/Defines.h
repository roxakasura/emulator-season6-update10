#pragma once
// ----------------------------------------------------------------------------------------------
#define ITEM_INTER					1171
#define ITEM(x, y)					((x * 512) + y)
#define ITEM2(x, y)					((x * 512) + y + ITEM_INTER)
#define Color4f(r, b, g, o)			((o << 24) + (g << 16) + (b << 8) + r)
#define Naked(Function)				void __declspec(naked) Function()
#define _FC							__fastcall
#define _CD							__cdecl
#define IS_NEWWINGS(x)				((x < ITEM(12, 180)) ? FALSE : (x > ITEM(12, 215)) ? FALSE : TRUE)
#define CS_GET_WEAPON(x, y)			( y | (16 * (x & 0xF0)) )
#define CS_GET_HELM(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 7) & 1) + (y >> 4) )
#define CS_GET_ARMOR(x, y, z)		( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 6) & 1) + (y & 0xF) )
#define CS_GET_PANTS(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 5) & 1) + (y >> 4) )
#define CS_GET_GLOVES(x, y, z)		( (32 * ((z >> 4) & 0xF)) + 16 * ((x >> 4) & 1) + (y & 0xF) )
#define CS_GET_BOOTS(x, y, z)		( (32 * (z & 0xF)) + 16 * ((x >> 3) & 1) + (y >> 4) )
#define MAX_ITEMOPT_BIT				0x3F
#define GET_ITEMOPT_LEVEL(x)		((x >> 3) & 0xF)
#define SET_ITEMOPT_LEVEL(x)		(x << 3)
#define GET_ITEMOPT0(x)				(x & 3)
#define GET_ITEMOPT16(x)			(x & 0x40)
#define GET_ITEMOPT_SKILL(x)		(x >> 7)
#define GET_ITEMOPT_LUCK(x)			((x >> 2) & 1)
#define GET_ITEMOPT_0(x)			(x & 1)
#define GET_ITEMOPT_1(x)			(((x & MAX_ITEMOPT_BIT) >> 1) & 1)
#define GET_ITEMOPT_2(x)			(((x & MAX_ITEMOPT_BIT) >> 2) & 1)
#define GET_ITEMOPT_3(x)			(((x & MAX_ITEMOPT_BIT) >> 3) & 1)
#define GET_ITEMOPT_4(x)			(((x & MAX_ITEMOPT_BIT) >> 4) & 1)
#define GET_ITEMOPT_5(x)			(((x & MAX_ITEMOPT_BIT) >> 5) & 1)
#define MAX_ITEM	(16*512)

#define HDK_SET_ITEM_EFFECT 0x0057AD82 //0x0052B0DB
#define HDK_SET_COLOR_EFFECT 0x0057AEFA //0x0052B122
#define HDK_ITEM_EFFECT_ALLOW 0x0057AD8D //0x0052B0E7
#define HDK_ITEM_EFFECT_NOT_ALLOW 0x0057B73B //0x0052B9E0
#define HDK_NEXT_ITEM_COLOR 0x0057AF2E //0x0052B150
#define MAIN_LANGUAGE 0x00E8C5C4
#define VK_N 0x4E
#define VK_R 0x52
#define VK_O 0x4F
#define VK_W 0x57
#define VK_J 0x4A
#define VK_K 0x4B
// ----------------------------------------------------------------------------------------------

enum eObjectType	//-> Complete
{
	emPlayer	= 1,
	emMonster	= 2,
	emNPC		= 4,
	emNone		= 8,
};
// ----------------------------------------------------------------------------------------------

enum eClassNumber 
{
	CLASS_WIZARD	= 0,
	CLASS_KNIGHT	= 1,
	CLASS_ELF		= 2,
	CLASS_MAGUMSA	= 3,
	CLASS_DARKLORD	= 4,
	CLASS_SUMMONER	= 5,
	CLASS_MONK		= 6,
};
// ----------------------------------------------------------------------------------------------

enum eClassCode // -> Complete -> Season 5.2 JPN
{
	DarkWizard 		= 0,
	SoulMaster 		= 8,
	GrandMaster		= 24,
	// ----
	DarkKnight		= 1,
	BladeKnight		= 9,
	BladeMaster		= 25,
	// ----
	Elf				= 2,
	MuseElf			= 10,
	HightElf		= 26,
	// ----
	MagicGladiator	= 3,
	DuelMaster		= 19,
	// ----
	DarkLord		= 4,
	LordEmperor		= 20,
	// ----
	Summoner		= 5,
	BloodySummoner	= 13,
	DimensionMaster	= 29,
	// ----
	Monk			= 6,
	FirstMaster		= 16
};
// ----------------------------------------------------------------------------------------------

enum ObjState // -> Complete
{
	SelectServer	= 2,
	SwitchCharacter = 4,
	GameProcess		= 5,
};
// ----------------------------------------------------------------------------------------------

enum ObjWindow // -> Season 6.3
{
	FriendList		= 1,
	MoveList		= 2,
	Party			= 3,
	Quest			= 4,
	NPC_Devin		= 5,
	Guild			= 6,
	Trade			= 7,
	Warehouse		= 8,
	ChaosBox		= 9,
	CommandWindow	= 10,
	PetInfo			= 11,
	Shop			= 12,
	Inventory		= 13,
	Store			= 14,
	OtherStore		= 15,
	Character		= 16,
	DevilSquare		= 19,
	BloodCastle		= 20,
	CreateGuild		= 21,
	GuardNPC		= 22,
	SeniorNPC		= 23,
	GuardNPC2		= 24,
	CastleGateSwitch= 25,
	CatapultNPC		= 26,
	CrywolfGate		= 29,
	IllusionTemple	= 30,
	HeroList		= 32,
	ChatWindow		= 33,
	FastMenu		= 34,
	Options			= 35,
	Help			= 36,
	FastDial		= 39,
	SkillTree		= 57,
	GoldenArcher1	= 58,
	GoldenArcher2	= 59,
	LuckyCoin1		= 60,
	LuckyCoin2		= 61,
	NPC_Duel		= 62,
	NPC_Titus		= 63,
	CashShop		= 65,
	Lugard			= 66,
	QuestList1		= 68,
	QuestList2		= 69,
	Jerint			= 70,
	FullMap			= 72,
	NPC_Dialog		= 73,
	GensInfo		= 74,
	NPC_Julia		= 75,
	NPC_ChaosMix	= 76,
	ExpandInventory	= 77,
	ExpandWarehouse	= 78,
	MuHelper = 79,
};
// ----------------------------------------------------------------------------------------------

namespace ASM
{
	enum T
	{
		JMP			= 0xE9,
		JE			= 0x74,
		JNE			= 0x75,
		JGE			= 0x7D,
		NOP			= 0x90,
		CALL		= 0xE8,
		CALLD		= 0xFF,
		PUSH		= 0x68,
	};
};
// ----------------------------------------------------------------------------------------------

enum eTextColors	//-> Complete
{
	White			= 0x00,
	Blue			= 0x01,
	Red				= 0x02,
	Gold			= 0x03,
	Green			= 0x04,
	WhiteRed		= 0x05,
	Violet			= 0x06,
	WhiteBlue		= 0x07,
	WhiteBeige		= 0x08,
	GreenBlue		= 0x09,
	Gray			= 0x0A,
	DarkViolet		= 0x0B,
};
// ----------------------------------------------------------------------------------------------

enum eTextWeight	//-> Complete
{
	Bold			= 0x01,
	Normal			= 0x00,
};
// ----------------------------------------------------------------------------------------------

namespace eItemOption
{
	enum T
	{
		Damage			= 80,		//-> Additional Damage +<N>
		WizardryDamage	= 81,
		CurseSpell		= 82,
		Defense			= 84,		//-> Additional Defense +<N>
		Luck			= 85,		//-> Default: 0
		HPRecovery		= 86,
		// ----
		LifeIncrease	= 87,		//-> Increase Max HP +4%%
		ManaIncrease	= 88,		//-> Increase Max Mana +4%%
		DamageDecrease	= 89,		//-> Damage Decrease +4%%
		Reflect			= 90,		//-> Reflect Damage +5%%
		DefenseSuccess	= 91,		//-> Defense success rate +10%%
		IncreaseZen		= 92,		//-> Increases acquisition rate of Zen after hunting monsters +30%%
		// ----
		ExcellentDamage	= 93,		//-> Excellent Damage rate +10%%
		DamageByLevel	= 94,		//-> Increase Damage +level/20
		IncreaseDamage	= 95,		//-> Increase Damage +%d%%
		IncreaseWizardry= 96,		//-> Increase Wizardry Dmg +level/20
		IncreaseSpeed	= 98,		//-> Increase Attacking(Wizardry)speed +%d
		IgnorOpDefense	= 103,
		ReturnAttack	= 106,		//-> Return's the enemy's attack power in <N>%
		CompleteLife	= 107,		//-> Complete recovery of life in <N>% rate
		CompleteMana	= 108,		//-> Complete recovery of Mana in <N>% rate
		//================
		IncreaseWizardryDmg = 97,    //-> Increase Wizardry Dmg +2%
		LifePerMob        = 99,        //-> Increases acquisition rate of Life after hunting monsters +life/8
		ManaPerMob        = 100,        //-> Increases acquisition rate of Mana after hunting monsters +Mana/8
	};
};
// ----------------------------------------------------------------------------------------------

enum ColorMacro
{
	eTextShop		= Color4f( 0xFFu, 0xDCu, 0x96u, 0xFFu),
	eTextGuild		= Color4f( 0xFFu, 0xBDu, 0x19u, 0xFFu),
	eShinyGreen     = Color4f(172, 255, 56, 255),
	eShinyGreen100  = Color4f(172, 255, 56, 100),
	eGold           = Color4f(255, 189, 25, 255),
	eGold150        = Color4f(255, 189, 25, 150),
	eGold180        = Color4f(255, 189, 25, 180),
    eGold220        = Color4f(255, 189, 25, 220),
	eWhite          = Color4f(255, 255, 255, 255),
	eWhite150       = Color4f(255, 255, 255, 150),
	eWhite160       = Color4f(255, 255, 255, 160),
	eWhite170       = Color4f(255, 255, 255, 170),
	eWhite180       = Color4f(255, 255, 255, 180),
	eWhite190       = Color4f(255, 255, 255, 200),
	eOrange         = Color4f(255, 105, 25, 255),
	eGray100        = Color4f(211, 211, 211, 100),
	eGray150        = Color4f(50, 50, 50, 150),
	eGray190        = Color4f(50, 50, 50, 190),
	eBlowPink       = Color4f(220, 20, 60, 255),
	eBlack          = Color4f(0, 0, 0, 255),
	eRed            = Color4f(225, 0, 0, 255),
	eRed2           = Color4f(225, 95, 45, 255),
	eExcellent      = Color4f(0, 225, 139, 255),
	eAncient        = Color4f(1, 223, 119, 255),
	eSocket         = Color4f(153, 102, 204, 255),
	eBlue           = Color4f(36, 242, 252, 255),
	eBlue250        = Color4f(36, 242, 252, 250),
	eYellow         = Color4f(255, 255, 0, 255),
	eYellow170      = Color4f(255, 255, 0, 170),
	eBrown          = Color4f(69, 39, 18, 255),
	eColorAdvance	= Color4f(109, 25, 192, 255),
	eColorHealth	= Color4f(191, 191, 146, 255),
};
// ----------------------------------------------------------------------------------------------

enum eMapNumber
{
    Lorencia        = 0,
    Dungeon        = 1,
    Devias        = 2,
    Noria            = 3,
    LostTower        = 4,
    Exile            = 5,
    Stadium        = 6,
    Atlans        = 7,
    Tarkan        = 8,
    DevilSquaree    = 9,
    Icarus        = 10,
    BloodCastle1    = 11,
    BloodCastle2    = 12,
    BloodCastle3    = 13,
    BloodCastle4    = 14,
    BloodCastle5    = 15,
    BloodCastle6    = 16,
    BloodCastle7    = 17,
    ChaosCastle1    = 18,
    ChaosCastle2    = 19,
    ChaosCastle3    = 20,
    ChaosCastle4    = 21,
    ChaosCastle5    = 22,
    ChaosCastle6    = 23,
    Kalima1        = 24,
    Kalima2        = 25,
    Kalima3        = 26,
    Kalima4        = 27,
    Kalima5        = 28,
    Kalima6        = 29,
    Kalima7        = 36,
    Loren            = 30,
    Trials            = 31,
	DevilSquare6    = 32,
    Aida            = 33,
    Crywolf        = 34,
    Kanturu1        = 37,
    Kanturu3        = 38,
    Kanturu_Event    = 39,
    Silent        = 40,
    Barracks        = 41,
    Refuge        = 42,
    Illusion1        = 45,
    Illusion2        = 46,
    Illusion3        = 47,
    Illusion4        = 48,
    Illusion5        = 49,
    Illusion6        = 50,
    Elbeland        = 51,
    BloodCastle8    = 52,
    ChaosCastle7    = 53,
    Calmness        = 56,
    Raklion        = 57,
    RaklionBoss    = 58,
    SantaTown        = 62,
    Vulcanus        = 63,
    Collosseum        = 64,
    Karutan1        = 80,
    Karutan2        = 81,
};
// ----------------------------------------------------------------------------------------------

enum INVENTORY_SIZE
{
	INVENTORY_WEAR_SIZE = 12,
};

enum eSetItemColor
{
	TEXT_BLUE			=	1,
	TEXT_RED			=	2,
	TEXT_GOLD			=	3,
	TEXT_GREN			=	4,
	TEXT_WHITE_RED		=	5,
	TEXT_PINK			=	6,
	TEXT_WHITE_BLUE		=	7,
	TEXT_WHITE_YELLOW	=	8,
	TEXT_GREN_BLUE		=	9,
	TEXT_GRAY			=	10,
	TEXT_PINK2			=	11,
	TEXT_PURPLE			=	12,
	TEXT_ORANGE			=	13,
	TEXT_WHITE			=	14,
};
