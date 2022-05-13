#include "stdafx.h"
#include "SocketItem.h"
#include "Util.h"
#include "TMemory.h"
#include "Defines.h"
#include "Import.h"
#include "Interface.h"
#include "Item.h"
#include "ReadScript.h"

CSocketItem gSocketItem;

CSocketItem::CSocketItem()
{
   this->m_SocketItemData.clear();
}

CSocketItem::~CSocketItem()
{
}

void CSocketItem::Load()
{
   //00953CFC - hook
   this->m_SocketItemData.clear();

   this->Read("Data/Local/SocketItem.bmd");
	SetCompleteHook(0xE9,0x00968180,&IsSocketItem);
}

void CSocketItem::Read(char* filename)
{
   SMDToken Token;

   SMDFile = fopen(filename, "r");

   if(!SMDFile)
   {
      return;
   }

   while(true)
   {
      Token = GetToken();

      if( Token == END || !strcmp(TokenString, "end") )
      {
         break;
      }

      SOCKETITEM_DATA list;

      list.SecIndex = TokenNumber;
	  
	  Token = GetToken();
	  list.ItemIndex = TokenNumber;

      this->m_SocketItemData.push_back(list);
   }

   fclose(SMDFile);
}

signed int __stdcall IsSocketItem(signed int iItemType)
{
	for(std::vector<SOCKETITEM_DATA>::iterator it = gSocketItem.m_SocketItemData.begin();it != gSocketItem.m_SocketItemData.end();it++)
	{
		if(iItemType == GET_ITEM(it->SecIndex,it->ItemIndex))
		{
			return TRUE;
		}
	}

	return false;
}