#include "stdafx.h"
#include "Protocol.h"

enum eOffTradeType
{
	eOFF_ZEN,
	eOFF_WCOINP,
	eOFF_WCOINC,
	eOFF_CHAOS,
	eOFF_BLESS,
	eOFF_SOUL,
};

struct PMSG_OFFTRADE_SEND
{
	PSBMSG_HEAD header;
	int Type;
};

struct PMSG_OFFTRADE_RECV
{
	PSBMSG_HEAD header;
	int Type;
};

struct PMSG_SHOPACTIVE_RECV
{
	PSBMSG_HEAD header;
	int Active;
	int Type;
};


// ----------------------------------------------------------------------------------------------

class cOffTrade
{
public:
	cOffTrade();
	virtual ~cOffTrade();
	void Init();
	void RecvPShop(PMSG_OFFTRADE_RECV* Data);

	static void ShowPrice(DWORD a1, const char *a2, char *Price);
	static void ShowTwoString(DWORD a1, const char *a2);
	void		DrawOffTradeWindow();
	bool		EventOffTradeWindow_Main(DWORD Event);
	void		CGSendOffTrade(int Type);
	bool		EventCloseTradeWindow_Main(DWORD Event);
	void		PShopActiveRecv(PMSG_SHOPACTIVE_RECV *Data);
	void		DrawOffTradeWindowEx700(float x, float y);
public:
	int m_OfftradeType;
	int TypeShop;
	int ShopActive;
	int ShopList;
};
extern cOffTrade gOffTrade;

void ChangePSValueColor();