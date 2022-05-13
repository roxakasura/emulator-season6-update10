#pragma once
typedef struct //-- itemlist
{
	PSWMSG_HEAD  Header;
	BYTE         Value;
} HEADER_DEFAULT_SUBCODE_WORD, * LPHEADER_DEFAULT_SUBCODE_WORD;

typedef struct
{
	PSBMSG_HEAD		Header;
	WORD			wItemCode;
	WORD			wItemSlotIndex;
	long			lExpireDate;
}PMSG_PERIODITEMEX_ITEMLIST, *LPPMSG_PERIODITEMEX_ITEMLIST;

typedef struct //-- GetList Item
{
	BYTE          Index;
	BYTE          Item[12];
} RECEIVE_INVENTORY, * LPRECEIVE_INVENTORY;

namespace SEASON3B
{
	typedef void (*PUSHEVENT_CALLBACK)(int);

	void ResetEquipItem();
	void setStatusDetails(bool bShow);
	void SetPeriodItem(int iIndex, long lExpireDate);
	void SetEquipItem(int iIndex, BYTE* pbyItemPacket);
	void Init(int txt, PUSHEVENT_CALLBACK pCallback);

	class QuickCommandWindow
	{
	public:
		void szInit();
		QuickCommandWindow(void);
		virtual ~QuickCommandWindow(void);

		BOOL ReceiveInventory(BYTE *ReceiveBuffer);
		bool ReceivePeriodItemList(BYTE* ReceiveBuffer);
		static void SendRequestViewItem(int pSelectedCha);
	
	};
}



extern SEASON3B::QuickCommandWindow g_pQuickCommandWindow;