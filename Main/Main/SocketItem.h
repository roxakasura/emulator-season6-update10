#pragma once

#include <vector>
 signed int __stdcall IsSocketItem(signed int iItemType);

struct SOCKETITEM_DATA
{
   int SecIndex;
   int ItemIndex;
};

class CSocketItem
{
public:
	CSocketItem();
	~CSocketItem();
   void Load();
   void Read(char* filename);
   std::vector<SOCKETITEM_DATA> m_SocketItemData;
};
extern CSocketItem gSocketItem;