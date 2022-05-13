#include "Stdafx.h"
#include "BattleGloves.h"
#include "TMemory.h"
#include "Import.h"
#include "Defines.h"
#include "Util.h"
#include "Item.h"

void __declspec ( naked ) BattleGloveLoad() {
    static DWORD BattleGloveModel   = 0x00614D10;
    static DWORD BattleGloveReturn  = 0x0050DE83;
    static PCHAR PhoenixSoulModel    = "Sword36";
    static PCHAR PhoenixSoulLeft     = "Sword36L";
    static PCHAR PhoenixSoulRight    = "Sword36R";
	LoadItemModel(GET_ITEM_MODEL ( 0, 90 ),"Item\\","Sword41",-1);
	LoadItemModel(0x610,"Item\\","Sword41_L",-1);
	LoadItemModel(0x611,"Item\\","Sword41_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 91 ),"Item\\","Sword42",-1);
	LoadItemModel(0x612,"Item\\","Sword42_L",-1);
	LoadItemModel(0x613,"Item\\","Sword42_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 92 ),"Item\\","Sword43",-1);
	LoadItemModel(0x614,"Item\\","Sword43_L",-1);
	LoadItemModel(0x615,"Item\\","Sword43_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 93 ),"Item\\","Sword44",-1);
	LoadItemModel(0x616,"Item\\","Sword44_L",-1);
	LoadItemModel(0x617,"Item\\","Sword44_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 94 ),"Item\\","Sword45",-1);
	LoadItemModel(0x618,"Item\\","Sword45_L",-1);
	LoadItemModel(0x619,"Item\\","Sword45_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 95 ),"Item\\","Sword46",-1);
	LoadItemModel(0x61A,"Item\\","Sword46_L",-1);
	LoadItemModel(0x61B,"Item\\","Sword46_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 96 ),"Item\\","Sword47",-1);
	LoadItemModel(0x61C,"Item\\","Sword47_L",-1);
	LoadItemModel(0x61D,"Item\\","Sword47_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 97 ),"Item\\","Sword48",-1);
	LoadItemModel(0x61E,"Item\\","Sword48_L",-1);
	LoadItemModel(0x61F,"Item\\","Sword48_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 98 ),"Item\\","Sword49",-1);
	LoadItemModel(0x620,"Item\\","Sword49_L",-1);
	LoadItemModel(0x621,"Item\\","Sword49_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 99 ),"Item\\","Sword50",-1);
	LoadItemModel(0x622,"Item\\","Sword50_L",-1);
	LoadItemModel(0x623,"Item\\","Sword50_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 100 ),"Item\\","Sword51",-1);
	LoadItemModel(0x622,"Item\\","Sword54_L",-1);
	LoadItemModel(0x623,"Item\\","Sword51_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 101 ),"Item\\","Sword52",-1);
	LoadItemModel(0x622,"Item\\","Sword52_L",-1);
	LoadItemModel(0x623,"Item\\","Sword52_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 102 ),"Item\\","Sword53",-1);
	LoadItemModel(0x622,"Item\\","Sword50_L",-1);
	LoadItemModel(0x623,"Item\\","Sword50_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 103 ),"Item\\","Sword54",-1);
	LoadItemModel(0x622,"Item\\","Sword54_L",-1);
	LoadItemModel(0x623,"Item\\","Sword54_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 104 ),"Item\\","Sword55",-1);
	LoadItemModel(0x622,"Item\\","Sword55_L",-1);
	LoadItemModel(0x623,"Item\\","Sword55_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 105 ),"Item\\","Sword56",-1);
	LoadItemModel(0x622,"Item\\","Sword56_L",-1);
	LoadItemModel(0x623,"Item\\","Sword56_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 106 ),"Item\\","Sword57",-1);
	LoadItemModel(0x622,"Item\\","Sword57_L",-1);
	LoadItemModel(0x623,"Item\\","Sword57_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 107 ),"Item\\","Sword58",-1);
	LoadItemModel(0x622,"Item\\","Sword58_L",-1);
	LoadItemModel(0x623,"Item\\","Sword58_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 108 ),"Item\\","Sword59",-1);
	LoadItemModel(0x622,"Item\\","Sword59_L",-1);
	LoadItemModel(0x623,"Item\\","Sword59_R",-1);
	LoadItemModel(GET_ITEM_MODEL ( 0, 109 ),"Item\\","Sword60",-1);
	LoadItemModel(0x622,"Item\\","Sword60_L",-1);
	LoadItemModel(0x623,"Item\\","Sword60_R",-1);
    _asm {
        PUSH -1
        PUSH 0x00D28B88
        PUSH 0x00D28B90
        PUSH 0x4B6
        CALL BattleGloveModel
        ADD ESP, 0x10
        PUSH -1
        PUSH 0x00D28B9C
        PUSH 0x00D28BA8
        PUSH 0x268
        CALL BattleGloveModel
        ADD ESP, 0x10
        PUSH -1
        PUSH 0x00D28BB4
        PUSH 0x00D28BC0
        PUSH 0x269
        CALL BattleGloveModel
        ADD ESP, 0x10
        // ----
        JMP BattleGloveReturn
    }
}


void __declspec ( naked ) BattleGloveAssoc() {
    static DWORD BattleGloveCall1   = 0x0050D810;
    static DWORD BattleGloveCall2   = 0x00512D50;
    static DWORD BattleGloveCall3   = 0x00513C60;
    static DWORD BattleGloveCall4   = 0x005135F0;
    static DWORD BattleGloveCall5   = 0x00512D60;
    static DWORD BattleGloveJump    = 0x0050DCB0;
    _asm {
        PUSH 0x269                                        //; /Arg3 = 269
        PUSH 0x268                                        //; |Arg2 = 268
        PUSH 0x4B6                                        //; |Arg1 = 4B6
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX                                          //; /Arg2 => ARG.ECX+5C
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall2                             //; |
        PUSH EAX                                          //; |Arg1
        LEA ECX, [EBP-0x70]                               //; |
        CALL BattleGloveCall3                             //; \Main.00513C60
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 1   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX                                          //; /Arg2 => [LOCAL.46]
        LEA EAX, [EBP-0x7C]                               //; |
        PUSH EAX                                          //; |Arg1 => OFFSET LOCAL.31
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x3C                                     //; |
        CALL BattleGloveCall4                             //; \Main.005135F0
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5                             //; [Main.00512D60
        // ----Gloves1
        PUSH 0x611                                        //; /Arg3 = 611 -> Right
        PUSH 0x610                                        //; |Arg2 = 610 -> Left
        PUSH 0x4ED                                        //; |Arg1 = 4BF -> ITEM2(0,41)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 1   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
        // ----Gloves2
        PUSH 0x613                                        //; /Arg3 = 613 -> Right
        PUSH 0x612                                        //; |Arg2 = 612 -> Left
        PUSH 0x4EE                                        //; |Arg1 = 4BD -> ITEM2(0,42)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 2  // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
        // ----Gloves3
        PUSH 0x615                                        //; /Arg3 = 615 -> Right
        PUSH 0x614                                        //; |Arg2 = 614 -> Left
        PUSH 0x4EF                                        //; |Arg1 = 4BE -> ITEM2(0,43)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 3   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----Gloves4
        PUSH 0x617                                        //; /Arg3 = 617 -> Right
        PUSH 0x616                                        //; |Arg2 = 616 -> Left
        PUSH 0x4F0                                        //; |Arg1 = 4C1 -> ITEM2(0,44)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 4   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----Gloves5
        PUSH 0x619                                        //; /Arg3 = 619 -> Right
        PUSH 0x618                                        //; |Arg2 = 618 -> Left
        PUSH 0x4F1//0x4C5                                        //; |Arg1 = 4C6 -> ITEM2(0,45)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 5  // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----Gloves6
        PUSH 0x61B//0x621                                        //; /Arg3 = 62B -> Right
        PUSH 0x61A//0x620                                        //; |Arg2 = 61A -> Left
        PUSH 0x4F2//0x4C8                                        //; |Arg1 = 4C1 -> ITEM2(0,46)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 6   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
        // ----Gloves7
        PUSH 0x61D                                        //; /Arg3 = 62D -> Right
        PUSH 0x61C                                        //; |Arg2 = 61C -> Left
        PUSH 0x4F3                                        //; |Arg1 = 4C2 -> ITEM2(0,47)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 7   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----Gloves8
        PUSH 0x61F                                        //; /Arg3 = 62F -> Right
        PUSH 0x61E                                        //; |Arg2 = 61E -> Left
        PUSH 0x4F4                                        //; |Arg1 = 4C3 -> ITEM2(0,48)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 8   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----Gloves9
        PUSH 0x621                                        //; /Arg3 = 621 -> Right
        PUSH 0x620                                        //; |Arg2 = 620 -> Left
        PUSH 0x4F5                                        //; |Arg1 = 4C4 -> ITEM2(0,49)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 9   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----Gloves10
        PUSH 0x623                                        //; /Arg3 = 623 -> Right
        PUSH 0x622                                        //; |Arg2 = 623 -> Left
        PUSH 0x4F6                                        //; |Arg1 = 4C5 -> ITEM2(0,50)
        MOV ECX, DWORD PTR SS:[EBP-0x9C]                  //; |
        ADD ECX, 0x5C                                     //; |
        CALL BattleGloveCall1                             //; \Main.0050D810
        MOV EAX, DWORD PTR SS:[EBP-0x9C]
        ADD EAX, 0x5C
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x5C
        CALL BattleGloveCall2
        PUSH EAX
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall3
        MOV DWORD PTR SS:[EBP-0xB8], EAX
        MOV ECX, DWORD PTR SS:[EBP-0xB8]
        MOV DWORD PTR SS:[EBP-0xBC], ECX
        MOV DWORD PTR SS:[EBP-0x4], 10   // -> Battle Glove Number
        MOV EDX, DWORD PTR SS:[EBP-0xBC]
        PUSH EDX
        LEA EAX, [EBP-0x7C]
        PUSH EAX
        MOV ECX, DWORD PTR SS:[EBP-0x9C]
        ADD ECX, 0x3C
        CALL BattleGloveCall4
        MOV DWORD PTR SS:[EBP-0x4], -1
        LEA ECX, [EBP-0x70]
        CALL BattleGloveCall5
		// ----
        JMP BattleGloveJump
    }
}




void __declspec ( naked ) BattleGloveTexture() {
    static DWORD BattleGloveTexCall = 0x00614710;
    static DWORD BattleGloveTexJump = 0x0050E09D;
	LoadItemTexture(GET_ITEM_MODEL ( 0, 90 ),"Item\\","Sword41",-1);
	LoadItemTexture(0x610,"Item\\","Sword41_L",-1);
	LoadItemTexture(0x611,"Item\\","Sword41_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 91 ),"Item\\","Sword42",-1);
	LoadItemTexture(0x612,"Item\\","Sword42_L",-1);
	LoadItemTexture(0x613,"Item\\","Sword42_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 92 ),"Item\\","Sword43",-1);
	LoadItemTexture(0x614,"Item\\","Sword43_L",-1);
	LoadItemTexture(0x615,"Item\\","Sword43_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 93 ),"Item\\","Sword44",-1);
	LoadItemTexture(0x616,"Item\\","Sword44_L",-1);
	LoadItemTexture(0x617,"Item\\","Sword44_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 94 ),"Item\\","Sword45",-1);
	LoadItemTexture(0x618,"Item\\","Sword45_L",-1);
	LoadItemTexture(0x619,"Item\\","Sword45_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 95 ),"Item\\","Sword46",-1);
	LoadItemTexture(0x61A,"Item\\","Sword46_L",-1);
	LoadItemTexture(0x61B,"Item\\","Sword46_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 96 ),"Item\\","Sword47",-1);
	LoadItemTexture(0x61C,"Item\\","Sword47_L",-1);
	LoadItemTexture(0x61D,"Item\\","Sword47_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 97 ),"Item\\","Sword48",-1);
	LoadItemTexture(0x61E,"Item\\","Sword48_L",-1);
	LoadItemTexture(0x61F,"Item\\","Sword48_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 98 ),"Item\\","Sword49",-1);
	LoadItemTexture(0x620,"Item\\","Sword49_L",-1);
	LoadItemTexture(0x621,"Item\\","Sword49_R",-1);
	LoadItemTexture(GET_ITEM_MODEL ( 0, 99 ),"Item\\","Sword50",-1);
	LoadItemTexture(0x622,"Item\\","Sword50_L",-1);
	LoadItemTexture(0x623,"Item\\","Sword50_R",-1);
    _asm {
        PUSH 1
        PUSH GL_NEAREST
        PUSH GL_REPEAT
        PUSH 0x00D28CC8
        PUSH 0x4B6
        CALL BattleGloveTexCall
        ADD ESP, 0x14
        PUSH 1
        PUSH GL_NEAREST
        PUSH GL_REPEAT
        PUSH 0x00D28CD0
        PUSH 0x268
        CALL BattleGloveTexCall
        ADD ESP, 0x14
        PUSH 1
        PUSH GL_NEAREST
        PUSH GL_REPEAT
        PUSH 0x00D28CD8
        PUSH 0x269
        CALL BattleGloveTexCall
        ADD ESP, 0x14
       
        // ----
        JMP BattleGloveTexJump
    }
}

void __declspec ( naked ) BattleGloveProp4() {
    static DWORD BattleGloveProp4_Return    = 0x005CD454;
    static DWORD BattleGloveProp4_Jump      = 0x005CD491;
    _asm {
        CMP DWORD PTR SS:[EBP+0x8], 0x4B6
        JNZ BattleGloveProp4_LabelReturn
        FLD DWORD PTR SS:[EBP-0x4C]
        FSUB QWORD PTR DS:[0x0D27CA8]                     //FLOAT 0.004999999888241291
        FSTP DWORD PTR SS:[EBP-0x4C]
        FLD DWORD PTR SS:[EBP-0x48]
        FADD QWORD PTR DS:[0x0D254B8]                     //FLOAT 0.01499999966472387
        FSTP DWORD PTR SS:[EBP-0x48]
        FLDZ
        FSTP DWORD PTR DS:[0x82C6320]                     //FLOAT 0.0
        FLDZ
        FSTP DWORD PTR DS:[0x82C6324]                     //FLOAT 0.0
        FLDZ
        FSTP DWORD PTR DS:[0x82C6328]                     //FLOAT 0.0
        JMP BattleGloveProp4_Jump
        // ----
        BattleGloveProp4_LabelReturn:
        // ----
        JMP BattleGloveProp4_Return
    }
}

void __declspec ( naked ) BattleGloveProp5() {
    static DWORD BattleGloveProp5_Return    = 0x005CEFFB;
    static DWORD BattleGloveProp5_Jump      = 0x005CF01C;
    _asm {
        CMP DWORD PTR SS:[EBP+0x8], ITEM2 ( 0, 35 )
        JNZ NextBattleGlove1
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003000000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
        // ----Gloves1
        NextBattleGlove1:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 90 )
        JNZ NextBattleGlove2
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
		// ----Gloves2
        NextBattleGlove2:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 91 )
        JNZ NextBattleGlove3
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
		// ----Gloves3
        NextBattleGlove3:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 92 )
        JNZ NextBattleGlove4
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
		// ----Gloves4
		NextBattleGlove4:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 93 )
        JNZ NextBattleGlove5
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
		// ----Gloves5
		NextBattleGlove5:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 94 )
        JNZ NextBattleGlove6
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
		// ----Gloves6
		NextBattleGlove6:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 95 )
        JNZ NextBattleGlove7
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
			// ----Gloves7
		NextBattleGlove7:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 96 )
        JNZ NextBattleGlove8
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
			// ----Gloves8
		NextBattleGlove8:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 97 )
        JNZ NextBattleGlove9
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
			// ----Gloves9
		NextBattleGlove9:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 98 )
        JNZ NextBattleGlove10
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
			// ----Gloves10
		NextBattleGlove10:
        // ----
        CMP DWORD PTR SS: [EBP + 0x8], ITEM2 ( 0, 99 )
        JNZ ReturnBattleGlove_Load
        FLD DWORD PTR DS: [0x0D2C618]                       //FLOAT 0.003800000
        FSTP DWORD PTR SS: [EBP - 0x2C]
        JMP BattleGloveProp5_Jump
		//
        ReturnBattleGlove_Load:
        // ----
        JMP BattleGloveProp5_Return
    }
}

static BOOL bBattleGlovesGlow_Switcher;
void __declspec ( naked ) BattleGloveGlow() {
    static DWORD dwBattleGlovesGlow_Pointer;
    static DWORD dwBattleGlovesGlow_Buffer;
    static DWORD dwBattleGlovesNewGlow_Buffer;
    static DWORD dwBattleGlovesGlow_Jump = 0x005F94E8;
    bBattleGlovesGlow_Switcher = FALSE;
    _asm {
        MOV dwBattleGlovesGlow_Pointer, EAX
    }
    if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 35 ) ) {
        bBattleGlovesGlow_Switcher = TRUE;
    }
	//---- Gloves1
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 90 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x26
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves2
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 91 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves3
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 92 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//--Gloves4
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 93 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves5
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 94 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves6
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 95 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves7
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 96 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves8
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 97 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves9
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 98 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
	//---Gloves10
    else if ( dwBattleGlovesGlow_Pointer == ITEM2 ( 0, 99 ) ) {
        bBattleGlovesGlow_Switcher = FALSE;
        _asm {
            MOV DWORD PTR SS:[EBP-0x4], 0x2C
            JMP dwBattleGlovesGlow_Jump
        }
    }
    if ( bBattleGlovesGlow_Switcher == TRUE ) {
        _asm {
            MOV dwBattleGlovesGlow_Buffer, 0x005F91C9
            JMP dwBattleGlovesGlow_Buffer
        }
    }else {
        _asm {
            MOV dwBattleGlovesGlow_Buffer, 0x005F91D5
            JMP dwBattleGlovesGlow_Buffer
        }
    }
}


Naked(cRFAddInventoryPos) {
	static DWORD IsRFItem = 0;
	static DWORD RFPosition = 0x005CD084; // 1.04D ENG
	static DWORD NextRFPosition = 0x005CD086; // 1.04D ENG
	static DWORD BattleGloveProp4_Jump      = 0x005CD491;
	static double a1 = 0.05;
	static double a2 = 0.1;
    _asm {
        mov ecx, dword ptr ss : [ebp + 0x8]
        mov dword ptr ss : [ebp + 0x8], ecx
        mov IsRFItem, ecx
    }
    if ( IsRFItem == 0x04B3 ) {
        _asm {jmp RFPosition}
    }else if ( IsRFItem == ITEM2 ( 0, 90 ) ) { //Gloves1
        _asm {
			 FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 91 ) ) { //Gloves2
        _asm {
			 FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 92 ) ) { //Gloves3
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 93 ) ) { //Gloves4
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 94 ) ) { //Gloves5
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 95 ) ) { //Gloves6
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 96 ) ) { //Gloves7
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 97 ) ) { //Gloves8
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 98 ) ) { //Gloves9
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }else if ( IsRFItem == ITEM2 ( 0, 99 ) ) { //Gloves10
        _asm {
			FLD DWORD PTR SS:[EBP-0x4c]
			FSUB QWORD PTR DS:[a1]/*0x0D27CA8]*/ //D28D58                     //FLOAT 0.004999999888241291
			FSTP DWORD PTR SS:[EBP-0x4c]
			FLD DWORD PTR SS:[EBP-0x48]
			FADD QWORD PTR DS:[a2]/*0x0D254B8]*/ //D28D58                     //FLOAT 0.01499999966472387
			FSTP DWORD PTR SS:[EBP-0x48]
			jmp RFPosition
		}
    }
    else {
        _asm {jmp NextRFPosition}
    }
}

void InitBattleGloves() 
{
	MemorySet(oBattleGlove_Load,0x90,0x4B);
	SetCompleteHook(0xE9,oBattleGlove_Load,&BattleGloveLoad);
	MemorySet(oBattleGlove_Hook,0x90,0x7F);
	SetCompleteHook(0xE9,oBattleGlove_Hook,&BattleGloveAssoc);
	MemorySet(oBattleGlove_Texture,0x90,0x5A);
	SetCompleteHook(0xE9,oBattleGlove_Texture,&BattleGloveTexture);
	MemorySet(oBattleGloveProp4_Hook,0x90,0x3B);
	SetCompleteHook(0xE9,oBattleGloveProp4_Hook,&BattleGloveProp4);
	MemorySet(oBattleGloveProp5_Hook,0x90,0x14);
	SetCompleteHook(0xE9,oBattleGloveProp5_Hook,&BattleGloveProp5);
	SetCompleteHook(0xE9,oBattleGloveGlow_Hook,&BattleGloveGlow);
	SetRange ( ( LPVOID ) 0x005CD07D, 7, ASM::NOP );
    SetJmp ( ( LPVOID ) 0x005CD07D, cRFAddInventoryPos );
}