#pragma once

#include "macro.h"

SERIALIZED_OBJECT_ON
struct MuObjectItemData {  //-> Complete (size: 107)
  public:
    unsigned char level() {
        return ( Level >> 3 ) & 0x0F;
    }

  public:
    /*+00*/  short            ItemID;
    /*+02*/  int              Level;
    /*+06*/  char             Unknown6;
    /*+07*/  char             Unknown7;
    /*+08*/  char             Unknown8;
    /*+09*/  short            DamageMin;
    /*+11*/  short            DamageMax;
    /*+13*/  char             Unknown13;
    /*+14*/  short            Unknown14;
    /*+16*/  short            Unknown16;
    /*+18*/  char             Unknown18;
    /*+19*/  char             Unknown19;
    /*+20*/  short            Unknown20;
    /*+22*/  char             Durability;
    /*+23*/  char             ExcellentOption;
    /*+24*/  char             AncientOption;
    /*+25*/  short            ReqStrenght;
    /*+27*/  short            ReqDextirity;
    /*+29*/  short            ReqEnergy;
    /*+31*/  short            ReqVitality;
    /*+33*/  short            ReqCommand;
    /*+35*/  short            ReqLevel;
    /*+37*/  char             SpecialCount;
    /*+38*/  WORD			  SpecialType[8];
    /*+54*/  BYTE			  SpecialValue[8];
    /*+62*/  int              UniqueID;
    /*+66*/  char             CurrentActiveSlotIndex;
    /*+67*/  char             PosX;
    /*+68*/  char             PosY;
    /*+69*/  WORD		      HarmonyType;
    /*+71*/  short            HarmonyValue;
    /*+73*/  char             Is380Item;
    /*+74*/  char             SocketOption[5];
    /*+79*/  char             Unknown79;
    /*+80*/  char             SocketSeedIndex[5];
    /*+85*/  char             SocketSphereLevel[5];
    /*+90*/  char             SocketSet;
    /*+91*/  BYTE		      gap01[5];
    /*+96*/  char             DurabilityState;
    /*+97*/  char             PeriodItem;
    /*+98*/  char             ExpiredItem;
    /*+99*/  int              ExpireDateConvert;
    /*+103*/ int              MaybeRefCount;
};
SERIALIZED_OBJECT_OFF