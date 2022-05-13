#include "stdafx.h"
#include "Util.h"
#include "CustomPet.h"
#include "NewUIPetInfoWindow.h"
#include "Defines.h"
#include "UIControl.h"
#include "NewUISystem.h"
#include "NewUIButton.h"
//#include "MuunOption.h"

CNewUIPetInfoWindow g_pMuunInventory;
//--
int bPicked = -1;
//--
int PickSelect = -1;
int PickTooltip = -1;
int SlotPickBackup = -1;
int IndexEffect = -1;
//--
int m_byTypeSend = -1;
int m_bySendSlot = -1;
int m_byTypeRecv = -1;

CNewUIPetInfoWindow::CNewUIPetInfoWindow()
{
	this->m_pNewPetInfoWindow = NULL;
	this->Wnd_Pag = 0;
	this->m_iMixEffectTimer = NULL;
	this->m_pdwItemCheckBox = new DWORD[62];
	this->m_vecItem.clear();
	memset(this->m_pdwItemCheckBox, 0, sizeof(DWORD) * 62);
}

CNewUIPetInfoWindow::~CNewUIPetInfoWindow()
{
}

void CNewUIPetInfoWindow::CreateEquippingEffect(ITEM* pItem)
{
	OBJECT* o = &*(OBJECT*)(Hero + 776);

	g_DeleteMuunBug(o, *(WORD*)(Hero + 556));

	GOBoid_CreateBug(pItem->Type + MODEL_ITEM, o->Position, o, 0, 0);
}

void CNewUIPetInfoWindow::DeleteEquippingEffect(ITEM* pItem)
{	
	OBJECT* pHeroObject = &*(OBJECT*)(Hero + 776);

	DelectIndexPetBug(pHeroObject, pItem->Type + 1171);
}

void  DelectPetBug(OBJECT* Owner)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];

		int type = gCustomPet2.GetInfoPetType(o->Type - 1171);

		if (o->Owner == Owner)
		{
			if (type == 4 && type > -1)
				continue;
			else
				o->Live = false;
		}
	}
}

void DelectExetPetBug(OBJECT* Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];
		int type = gCustomPet2.GetInfoPetType(o->Type - 1171);

		if (o->Owner == Owner &&
			(o->Type != Index &&
			o->Type != MODEL_FENRIR_BLACK &&
			o->Type != MODEL_FENRIR_RED &&
			o->Type != MODEL_FENRIR_BLUE &&
			o->Type != MODEL_FENRIR_GOLD &&
			o->Type != MODEL_DARK_HORSE &&
			o->Type != MODEL_PEGASUS &&
			o->Type != MODEL_UNICON &&
			o->Type != MODEL_BUTTERFLY01 &&
			(type == 4 && type > -1)))
		{
			o->Live = false;
		}
	}
}

void DelectIndexPetBug(OBJECT* Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];
		if (o->Live)
		{
			if (o->Owner == Owner && o->Type == Index)
			{
				o->Live = false;
				break;
			}
		}
	}
}


void g_DeleteMuunBug(OBJECT *Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];
		int type = gCustomPet2.GetInfoPetType(o->Type - 1171);

		if (o->Owner == Owner &&
			(o->Type != Index &&
			o->Type != MODEL_FENRIR_BLACK &&
			o->Type != MODEL_FENRIR_RED &&
			o->Type != MODEL_FENRIR_BLUE &&
			o->Type != MODEL_FENRIR_GOLD &&
			o->Type != MODEL_DARK_HORSE &&
			o->Type != MODEL_PEGASUS &&
			o->Type != MODEL_UNICON &&
			o->Type != MODEL_BUTTERFLY01 &&
			(type == 4 && type > -1)))
		{
			o->Live = false;
		}
	}
}

bool g_CheckBugLive(OBJECT *Owner, int Index)
{
	BYTE * Butterfles = (BYTE*)0x8791550;

	for (int i = 0; i < 10; i++)
	{
		OBJECT *o = (OBJECT*)&Butterfles[648 * i];

		if (o->Owner == Owner && o->Type == Index)
		{
			if (o->Live)
			{
				return true;
			}
		}
	}
	return false;
}

void CNewUIPetInfoWindow::ItemChangeRecv(PMSG_MUUN_ITEM_CHANGE_RECV *lpMsg)
{
	int TempEquip; // [sp+1Dh] [bp-3h]@2
	int IndexUser;
	int g_HeroPlayer;

	IndexUser = FindCharacterIndex(lpMsg->index[1] + (lpMsg->index[0] << 8));

	g_HeroPlayer = CharactersClient(CList(), IndexUser);

	if (g_HeroPlayer)
	{
		OBJECT* pHeroObject = &*(OBJECT*)(g_HeroPlayer + 776);

		TempEquip = sub_58AA80((DWORD)lpMsg->ItemInfo);
		switch ((signed int)lpMsg->ItemInfo[1] >> 4)
		{

		if (InChaosCastle(World) == true)
		{	
			return;
		}
		
		case 0:
			if (TempEquip == 0x1FFF)
			{
				g_DeleteMuunBug(pHeroObject, *(WORD*)(g_HeroPlayer + 556));
			}
			else
			{
				if (!g_CheckBugLive(pHeroObject, TempEquip + 1171))
				{
					CreateBug(TempEquip + 1171, pHeroObject->Position, pHeroObject, 0, 0);
				}
			}
			break;
		}
	}
}

bool CNewUIPetInfoWindow::InsertItem(BYTE iIndex, ITEM* pbyItemPacket)
{
	if (iIndex < 0 || iIndex > 62) { return false; }

	std::map<int, ITEM*>::iterator nodeHandler = this->m_vecItem.find(iIndex);

	if (nodeHandler != this->m_vecItem.end())
	{
		this->m_pdwItemCheckBox[iIndex] = NULL;
		this->m_vecItem.erase(nodeHandler);
	}

	this->m_pdwItemCheckBox[iIndex] = pbyItemPacket->Key;
	this->m_vecItem.insert(std::pair<int, ITEM*>((int)iIndex, pbyItemPacket));
	if (iIndex == 0)
	{
		g_pMuunInventory.CreateEquippingEffect(pbyItemPacket);
	}
	return true;
}

void CNewUIPetInfoWindow::DeleteItem(int iIndex)
{
	if (iIndex < 0 || iIndex > 62) { return; }

	type_vec_item::iterator li = this->m_vecItem.find(iIndex);
	if (li != this->m_vecItem.end())
	{
		if (iIndex == 0)
		{

			g_pMuunInventory.DeleteEquippingEffect(li->second);
		}
		this->m_pdwItemCheckBox[iIndex] = NULL;
		this->m_vecItem.erase(li);
	}
}

ITEM* CNewUIPetInfoWindow::FindbySlot(int iIndex)
{
	if (iIndex >= 0 && iIndex < 62)
	{
		type_vec_item::iterator li = g_pMuunInventory.m_vecItem.find(iIndex);

		if (li != g_pMuunInventory.m_vecItem.end())
		{
			return li->second;
		}
	}
	return NULL;
}

int CNewUIPetInfoWindow::FindbySlotEmpty(int ExiIndex)
{
	if (ExiIndex < 2)
	{
		for (int i = 2; i < 62; i++)
		{
			if (m_pdwItemCheckBox[i] == NULL)
			{
				return i;
			}
		}
	}
	else
	{
		if (m_pdwItemCheckBox[0] == NULL)
		{
			return 0;
		}
		if (m_pdwItemCheckBox[1] == NULL)
		{
			return 1;
		}
	}
	return -1;
}

void CNewUIPetInfoWindow::ReceiveGetItem(BYTE* ReceiveBuffer)
{
	LPPRECEIVE_GET_ITEM Data = (LPPRECEIVE_GET_ITEM)ReceiveBuffer;
	if (Data->Result != 0xFF)
	{
		ITEM* pNewItem = CreateItemConvertByte(*(DWORD*)(GetInstance() + 36), Data->Item);

		if (pNewItem)
		{
			this->InsertItem(Data->Result, pNewItem);
			PlayBuffer(29, (int)(Hero + 776), 0);
		}
	}
	SendGetItem = -1;
}

void CNewUIPetInfoWindow::ReceiveInventory(BYTE* ReceiveBuffer)
{
	this->m_vecItem.clear();
	memset(this->m_pdwItemCheckBox, 0, sizeof(DWORD) * 62);

	LPPHEADER_DEFAULT_SUBCODE_WORD DataRecv = (LPPHEADER_DEFAULT_SUBCODE_WORD)ReceiveBuffer;
	int Offset = sizeof(PHEADER_DEFAULT_SUBCODE_WORD);

	for (int i = 0; i < DataRecv->Value; i++)
	{
		LPPRECEIVE_INVENTORY Data = (LPPRECEIVE_INVENTORY)(ReceiveBuffer + Offset);

		ITEM* pNewItem = CreateItemConvertByte(*(DWORD*)(GetInstance() + 36), Data->Item);

		if (pNewItem)
		{
			this->InsertItem(Data->Index, pNewItem);
		}
		Offset += sizeof(PRECEIVE_INVENTORY);
	}
}

void CNewUIPetInfoWindow::ReceiveDurability(BYTE* ReceiveBuffer)
{
	LPPHEADER_DEFAULT_VALUE_DUR Data = (LPPHEADER_DEFAULT_VALUE_DUR)ReceiveBuffer;
	if (Data->Key != 0xFF)
	{
		int iItemIndex = Data->Key;
		ITEM* pItem = g_pMuunInventory.FindbySlot(iItemIndex);
		if (pItem)
		{
			pItem->Durability = Data->Value;
		}
	}
}

void CNewUIPetInfoWindow::ReceiveModifyItem(BYTE* ReceiveBuffer)
{
	LPPHEADER_DEFAULT_SUBCODE_ITEM Data = (LPPHEADER_DEFAULT_SUBCODE_ITEM)ReceiveBuffer;

	if (Data->Index != 0xFF)
	{
		ITEM* pNewItem = CreateItemConvertByte(*(DWORD*)(GetInstance() + 36), Data->Item);

		if (pNewItem)
		{
			this->InsertItem(Data->Index, pNewItem);
			PlayBuffer(69, 0, 0);
			IndexEffect = Data->Index;
		}
	}
}

void CNewUIPetInfoWindow::ReceiveDropItem(BYTE* ReceiveBuffer)
{
	LPPHEADER_DEFAULT_KEY Data = (LPPHEADER_DEFAULT_KEY)ReceiveBuffer;
	if (Data->KeyH)
	{
		if (SlotPickBackup == Data->KeyL && ms_pPickedItem)
		{
			DeletePickedItem();
			SlotPickBackup = -1;
			return;
		}
		this->DeleteItem(Data->KeyL);
	}
	SendDropItem = -1;
}

void CNewUIPetInfoWindow::ReceiveUseStateItem(BYTE* ReceiveBuffer)
{
	LPPHEADER_DEFAULT_SUBCODE Data = (LPPHEADER_DEFAULT_SUBCODE)ReceiveBuffer;
	if (Data->SubCode == 0)
	{
		if (Data->Value == 2)
		{
			g_pMuunInventory.m_iMixEffectTimer = 50;
			PlayBuffer(87, 0, 0);
		}
		else if (Data->Value == 3)
		{
			PlayBuffer(69, 0, 0);
		}
		else if (Data->Value == 1)
		{
			PlayBuffer(87, 0, 0);
		}
	}
}

void CNewUIPetInfoWindow::ReceiveDeleteInventory(BYTE* ReceiveBuffer)
{
	LPPHEADER_DEFAULT_SUBCODE Data = (LPPHEADER_DEFAULT_SUBCODE)ReceiveBuffer;

	if (Data->SubCode != 0xff)
	{
		if (SlotPickBackup == Data->SubCode && ms_pPickedItem)
		{
			DeletePickedItem();
			SlotPickBackup = -1;
			return;
		}
		this->DeleteItem(Data->SubCode);
	}

	if (Data->Value)
	{
		//EnableUse = 0;
	}
}

BOOL ReceiveEquipmentItem(BYTE* ReceiveBuffer, BOOL bEncrypted)
{
	EquipmentItem = false;
	LPPHEADER_SUBCODE_ITEM Data = (LPPHEADER_SUBCODE_ITEM)ReceiveBuffer;

	if (GetMixInventoryEquipmentIndex(g_MixRecipeMgr) == m_byTypeSend)
	{
		int Machine = pGetUIChaosMachine(GetInstance());
		ITEM* iTemp = InventoryCtrl_FindItem(*(DWORD*)(Machine + 16), m_bySendSlot);
		InventoryCtrl_RemoveItem(*(DWORD*)(Machine + 16), iTemp);

		PlayBuffer(29, 0, 0);
		m_byTypeSend = -1;
		m_bySendSlot = -1;
		m_byTypeRecv = -1;
	}
	else if (GetMixInventoryEquipmentIndex(g_MixRecipeMgr) == Data->SubCode && m_bySendSlot >= 0 && m_byTypeSend == 0)
	{
		RemoveItemForSlot(g_pNewUISystem.GetUI_NewMyInventory(), m_bySendSlot - 12);
		PlayBuffer(29, 0, 0);
		m_byTypeSend = -1;
		m_bySendSlot = -1;
		m_byTypeRecv = -1;
	}
	else if (Data->SubCode == m_byTypeRecv && m_bySendSlot >= 0 && m_byTypeSend == 0)
	{
		if (m_bySendSlot < 12)
		{
			UnequipItem((void*)g_pNewUISystem.GetUI_NewMyInventory(), m_bySendSlot);
		}
		else
		{
			RemoveItemForSlot(g_pNewUISystem.GetUI_NewMyInventory(), m_bySendSlot - 12);
		}
		PlayBuffer(29, 0, 0);
		m_byTypeSend = -1;
		m_bySendSlot = -1;
		m_byTypeRecv = -1;
	}

	if (Data->SubCode == 0 && bPicked != -1)
	{
		bPicked = -1;
	}
	if (Data->SubCode == 0 && SlotPickBackup != -1)
	{
		SlotPickBackup = -1;
	}
	else if (Data->SubCode == 22)
	{
		int itemindex = Data->Index;
		ITEM* iTemp = CreateItemConvertByte(*(DWORD*)(GetInstance() + 36), Data->Item);
		g_pMuunInventory.InsertItem(Data->Index, iTemp);
		PlayBuffer(29, (int)(Hero + 776), 0);
		SlotPickBackup = -1;
		DeletePickedItem();
		if (m_byTypeSend == 22 && m_byTypeRecv == 22)
		{
			g_pMuunInventory.DeleteItem(m_bySendSlot);
			m_byTypeSend = -1;
			m_bySendSlot = -1;
			m_byTypeRecv = -1;
		}
		return TRUE;
	}
	else if (Data->SubCode == 255)
	{
		if (m_byTypeSend != -1)
		{
			m_byTypeSend = -1;
			m_bySendSlot = -1;
			m_byTypeRecv = -1;
		}
		if (SlotPickBackup != -1)
		{
			ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));
			g_pMuunInventory.InsertItem(SlotPickBackup, iTemp);
			PlayBuffer(29, (int)(Hero + 776), 0);
			SlotPickBackup = -1;
			DeletePickedItem();
			return TRUE;
		}
	}

	return CReceiveEquipmentItem(ReceiveBuffer, bEncrypted);
}

void SendRequestUsedItem(BYTE SourceSlot, BYTE TargetSlot, BYTE type)
{
	PMSG_MUUN_ITEM_USE_SEND Send;
	Send.header.set(0x4E, 0x08, sizeof(Send));
	Send.SourceSlot = SourceSlot;
	Send.TargetSlot = TargetSlot;
	Send.type = type;
	DataSend((LPBYTE)&Send, Send.header.size);
}

void SendRequestDropItem(BYTE SlotPick, BYTE tx, BYTE ty)
{
	PMSG_MUUN_ITEM_DROP_SEND Send;
	Send.header.set(0x4E, 0x01, sizeof(Send));
	Send.slot = SlotPick;
	Send.x = tx;
	Send.y = ty;
	DataSend((LPBYTE)&Send, Send.header.size);
}

void CreateEquipMuun(int TempEquip, OBJECT* o, CHARACTER c, int OpcExc)
{
	if (TempEquip == 65535)
	{
		DelectExetPetBug(o, c->Helper_Type);
	}
	else
	{
		int TypeModel = TempEquip + MODEL_ITEM;
		if (gCustomPet2.GetInfoPetType(TempEquip) == 4)
		{
			GOBoid_CreateBug(TypeModel, o->Position, o, 0, 0);
		}
	}
}

#include "Console.h"

void ReceiveCreatePlayerViewport(BYTE* ReceiveBuffer)
{
	CreatePlayerViewport(ReceiveBuffer);
	LPPWHEADER_DEFAULT_WORD Data = (LPPWHEADER_DEFAULT_WORD)ReceiveBuffer;
	int Offset = sizeof(PWHEADER_DEFAULT_WORD);

	for (int i = 0; i < Data->Value; i++)
	{
		LPPCREATE_CHARACTER Data2 = (LPPCREATE_CHARACTER)(ReceiveBuffer + Offset);
		WORD Key = ((WORD)(Data2->KeyH) << 8) + Data2->KeyL;
		Key &= 0x7FFF;

		int iIndex = FindCharacterIndex(Key);
		CHARACTER pCha = (CHARACTER)CharactersClient(CList(), iIndex);
		//--
		if (pCha)
		{
		//	OBJECT* o = &pCha->Object;
		//	int Type = MAKE_NUMBERW(Data2->MuunItem[0], Data2->MuunItem[1]);
		//	*(WORD*)(pCha + 592) = Type + 1171;
		//	CreateEquipMuun(Type, o, pCha, 0);
		//
		//	char Testando[200];
		//	wsprintf(Testando,"char: %s / v1 %d",(char*)(*(DWORD*)(0x08128AC8)+0x00), Type);
		//	Console.Write(Testando, 0, 0);
		}

		Offset += (sizeof(PCREATE_CHARACTER) - (sizeof(BYTE) * (MAX_BUFF_SLOT_INDEX - Data2->s_BuffCount)));
	}
}

void ReceiveCreateTransformViewport(BYTE* ReceiveBuffer)
{
	CreateTransformViewport(ReceiveBuffer);
	LPPWHEADER_DEFAULT_WORD Data = (LPPWHEADER_DEFAULT_WORD)ReceiveBuffer;
	int Offset = sizeof(PWHEADER_DEFAULT_WORD);

	for (int i = 0; i < Data->Value; i++)
	{
		LPPCREATE_TRANSFORM Data2 = (LPPCREATE_TRANSFORM)(ReceiveBuffer + Offset);
		WORD Key = ((WORD)(Data2->KeyH) << 8) + Data2->KeyL;
		Key &= 0x7FFF;

		int iIndex = FindCharacterIndex(Key);
		CHARACTER pCha = (CHARACTER)CharactersClient(CList(), iIndex);
		//--
		if (pCha)
		{
		//	OBJECT* o = &pCha->Object;
		//	int Type = MAKE_NUMBERW(Data2->MuunItem[0], Data2->MuunItem[1]);
		//	CreateEquipMuun(Type, o, pCha, 0);
		//	char Testand2o[200];
		//	wsprintf(Testand2o,"char: %s / v2 %d",(char*)(*(DWORD*)(0x08128AC8)+0x00), Type);
		//	Console.Write(Testand2o, 0, 0);
		}
		Offset += (sizeof(PCREATE_CHARACTER) - (sizeof(BYTE) * (MAX_BUFF_SLOT_INDEX - Data2->s_BuffCount)));
	}
}

bool CNewUIPetInfoWindow::Create(int pNewUIMng)
{
	this->m_pNewPetInfoWindow = CNewUIPartyInfoWindow_New((char*)new_Class(0x428u));

	bool result = false; // al@2
	if (!pNewUIMng)
		return result;

	if (this->m_pNewPetInfoWindow != NULL)
	{
		SetByte(0x0084A05E + 1, 110);
		result = CNewUIPartyInfoWindow_Create(this->m_pNewPetInfoWindow, pNewUIMng, 70, 0);
		SetByte(0x0084A05E + 1, 3);
	}
	return result;
}

void RenderWindowsParty(PartyInfoWindow* thisa)
{
	EnableAlphaTest(true);
	glColor4f(1.f, 1.f, 1.f, 1.f);

	g_pRenderText.SetFont(g_hFont);
	g_pRenderText.SetTextColor(0xFFFFFFFF);

	DWORD dwPreBGColor = g_pRenderText.GetBgColor();
	g_pRenderText.SetBgColor(RGBA(0, 0, 0, 0));
	// Base Window
	RenderImageB(31322, (float)thisa->m_Pos.x, (float)thisa->m_Pos.y, 190.f, 429.f);
	RenderImageB(31353, (float)thisa->m_Pos.x, (float)thisa->m_Pos.y, 190.f, 64.f);
	RenderImageB(31355, (float)thisa->m_Pos.x, (float)thisa->m_Pos.y + 64.f, 21.f, 320.f);
	RenderImageB(31356, (float)thisa->m_Pos.x + 169.f, (float)thisa->m_Pos.y + 64.f, 21.f, 320.f);
	RenderImageB(31357, (float)thisa->m_Pos.x, (float)thisa->m_Pos.y + 384.f, 190.f, 45.f);

	Button_Render(thisa->m_BtnExit, 0);

	g_pRenderText.SetFont(g_hFontBold);
	g_pRenderText.RenderText(thisa->m_Pos.x + 60, thisa->m_Pos.y + 12, GlobalText(GlobalLine, 190), 72, 0, RT3_SORT_CENTER);
	g_pRenderText.SetFont(g_hFont);

	if (thisa->m_bParty)
	{
		PARTY_t* Party = (PARTY_t*)0x81CB4E8;

		for (int i = 0; i < *(DWORD*)0x81F6B6C; i++)
		{
			PARTY_t* pMember = &Party[i];

			bool bExitBtnRender = false;

			if (!StrCmp((BYTE*)Party[0].Name, (BYTE*)(Hero + 56)) || !StrCmp((BYTE*)Party[i].Name, (BYTE*)(Hero + 56)))
			{
				bExitBtnRender = true;
			}
			RenderMemberStatue(thisa, i, pMember, bExitBtnRender);
		}
	}
	else
	{
		int iStartHeight = 60;
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight, GlobalText(GlobalLine, 191), 0, 0, RT3_SORT_CENTER);
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight + 15, GlobalText(GlobalLine, 192), 0, 0, RT3_SORT_CENTER);
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight + 30, GlobalText(GlobalLine, 193), 0, 0, RT3_SORT_CENTER);
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight + 50, GlobalText(GlobalLine, 194), 0, 0, RT3_SORT_CENTER);
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight + 65, GlobalText(GlobalLine, 195), 0, 0, RT3_SORT_CENTER);
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight + 80, GlobalText(GlobalLine, 196), 0, 0, RT3_SORT_CENTER);
		g_pRenderText.RenderText(thisa->m_Pos.x + 20, thisa->m_Pos.y + iStartHeight + 95, GlobalText(GlobalLine, 197), 0, 0, RT3_SORT_CENTER);
	}
	g_pRenderText.SetBgColor(dwPreBGColor);
	DisableAlphaBlend();
}

void CNewUIPetInfoWindow::LoadImages()
{
	((void(__cdecl*)())0x0084B260)();
	//--
	LoadBitmapA("Interface\\GFx\\PetInventoryFrame_I6.tga", 71618, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\InGameShop\\ingame_Bt_page_L.tga", 32342, GL_LINEAR, GL_CLAMP, 1, 0);
	LoadBitmapA("Interface\\InGameShop\\ingame_Bt_page_R.tga", 32343, GL_LINEAR, GL_CLAMP, 1, 0);
}

void CNewUIPetInfoWindow::InitButtons(PartyInfoWindow* thisa)
{
	if (g_pMuunInventory.m_pNewPetInfoWindow != (char*)thisa)
	{
		CNewUIPartyInfoWindow_InitButtons(thisa);
		return;
	}
	Button_ChangeButtonImgState(thisa->m_BtnPartyExit[0], 1, 32342, 1, 0, 0);
	Button_ChangeButtonInfo(thisa->m_BtnPartyExit[0], thisa->m_Pos.x + 60, thisa->m_Pos.y + 392, 20, 23);
	//--
	Button_ChangeButtonImgState(thisa->m_BtnPartyExit[1], 1, 32343, 1, 0, 0);
	Button_ChangeButtonInfo(thisa->m_BtnPartyExit[1], thisa->m_Pos.x + 110, thisa->m_Pos.y + 392, 20, 23);
	//--
	Button_ChangeButtonImgState(thisa->m_BtnExit, 1, 31370, 0, 0, 0);
	Button_ChangeButtonInfo(thisa->m_BtnExit, thisa->m_Pos.x + 13, thisa->m_Pos.y + 392, 36, 29);
	int std_String[7];
	ChartoString(&std_String, GlobalText(GlobalLine, 241));
	ButtonSetTooltip(thisa->m_BtnExit, std_String[0], std_String[1], std_String[2], std_String[3], std_String[4], std_String[5], std_String[6], 1);
}

bool CNewUIPetInfoWindow::BtnProcess(PartyInfoWindow* thisa)
{
	if (g_pMuunInventory.m_pNewPetInfoWindow != (char*)thisa)
	{
		return CNewUIPartyInfoWindow_BtnProcess(thisa);
	}
	POINT ptExitBtn1 = { thisa->m_Pos.x + 169, thisa->m_Pos.y + 7 };

	if (IsPress(VK_LBUTTON) && pCheckInMouse(ptExitBtn1.x, ptExitBtn1.y, 13, 12))
	{
		PickSelect = -1;
		PickTooltip = -1;
		SlotPickBackup = -1;
		IndexEffect = -1;
		PlayBuffer(25, 0, 0);
		MouseUpdateTime = 0;
		MouseUpdateTimeMax = 6;
		g_pNewUISystem.Hide(110);
		return true;
	}

	if (IsPress(VK_LBUTTON) && pCheckInMouse(thisa->m_Pos.x, thisa->m_Pos.y, 190, 27))
	{
		g_pMuunInventory.m_ptPos.x = MouseX - thisa->m_Pos.x;
		g_pMuunInventory.m_ptPos.y = MouseY - thisa->m_Pos.y;
		return true;
	}

	if (Button_UpdateMouseEvent(thisa->m_BtnExit) == true)
	{
		PickSelect = -1;
		PickTooltip = -1;
		SlotPickBackup = -1;
		IndexEffect = -1;
		PlayBuffer(25, 0, 0);
		g_pNewUISystem.Hide(110);
		return true;
	}
	if (Button_UpdateMouseEvent(thisa->m_BtnPartyExit[0]) == true)
	{
		if (g_pMuunInventory.Wnd_Pag > 0) { g_pMuunInventory.Wnd_Pag--; }
		PlayBuffer(25, 0, 0);
		return true;
	}
	if (Button_UpdateMouseEvent(thisa->m_BtnPartyExit[1]) == true)
	{
		if (g_pMuunInventory.Wnd_Pag < 2) { g_pMuunInventory.Wnd_Pag++; }
		PlayBuffer(25, 0, 0);
		return true;
	}

	if (IsPress(VK_LBUTTON))
	{
		if (pCheckInMouse(thisa->m_Pos.x, thisa->m_Pos.y, 190, 429))
		{
			int v4;
			ITEM* iTemp = NULL;
			if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetMouseItem(v4)) == 0))
			{
				if (PickTooltip != -1)
				{
					if (SetPickItem(0, g_pMuunInventory.byItem))
					{
						SlotPickBackup = PickTooltip;
						g_pMuunInventory.DeleteItem(PickTooltip);
						return true;
					}
				}
			}
			else if (PickSelect != -1 && SlotPickBackup != -1)
			{
				if (ms_pPickedItem)
				{
					ITEM* pickTemp = GetMouseItem(GetPickedItem());

					if (PickTooltip != -1)
					{
						if (pickTemp->Type == ITEM(13, 211))
						{
							SendRequestUsedItem(SlotPickBackup, PickSelect, 2);
						}
						else
						{
							SendRequestUsedItem(SlotPickBackup, PickSelect, 1);
						}
					}
					else
					{
						if (SlotPickBackup == PickSelect)
						{
							ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));
							g_pMuunInventory.InsertItem(SlotPickBackup, iTemp);
							PlayBuffer(29, (int)(Hero + 776), 0);
							SlotPickBackup = -1;
							DeletePickedItem();
							return true;
						}
						else
						{
							SendRequestEquipmentItem(22, SlotPickBackup, pickTemp, 22, PickSelect);
						}
					}
				}
			}
			else if (SlotPickBackup == -1)
			{
				ITEM* pickTemp = GetMouseItem(GetPickedItem());
				int InOwoner = g_pNewUISystem.GetOwnerMyInventory();
				if (InOwoner != -1)
				{
					int sourceSlot = GetInventSourceLinealPos(GetSourceLinealPos(GetPickedItem()), InOwoner) + 12;

					if (pickTemp->Type == ITEM(14, 16) && PickTooltip != -1)
					{
						SendRequestUsedItem(sourceSlot, PickTooltip, 3);
					}
					else if (PickTooltip == -1 && PickSelect != -1)
					{
						SendRequestEquipmentItem(0, sourceSlot, pickTemp, 22, PickSelect);
					}
					return true;
				}
				else if (GetOwnerInventory(GetPickedItem()) == g_pNewUISystem.GetOwnerShopInventory() && PickSelect != -1)
				{
					SendRequestEquipmentItem(4, GetSourceLinealPos(GetPickedItem()) + 204, pickTemp, 22, PickSelect);
					return true;
				}
			}
		}
		else if (SlotPickBackup != -1)
		{
			if (pCheckInMouse(0, 0, CGetScreenWidth2(), 429))
			{
				RenderTerrain(true);
				if (RenderTerrainTile(SelectXF, SelectYF, (int)SelectXF, (int)SelectYF, 1.f, 1, true))
				{
					int tx = (int)(CollisionPosition_1 / TERRAIN_SCALE);
					int ty = (int)(CollisionPosition_2 / TERRAIN_SCALE);

					if (ms_pPickedItem)
					{
						ITEM* iTemp = CreateItemPick(GetMouseItem(GetPickedItem()));
						if (iTemp)
						{
							SendRequestDropItem(SlotPickBackup, tx, ty);
							MouseUpdateTime = 0;
							MouseUpdateTimeMax = 6;
							ResetMouseLButton();
							return true;
						}
					}
				}
			}
		}
	}
	else if (IsPress(VK_RBUTTON))
	{
		int v4;
		ITEM* iTemp = NULL;
		if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetMouseItem(v4)) == 0))
		{
			if (PickTooltip != -1)
			{
				int iTarget = g_pMuunInventory.FindbySlotEmpty(PickTooltip);

				if (iTarget == -1)
				{
					return true;
				}
				m_bySendSlot = PickTooltip;
				m_byTypeRecv = 22;
				m_byTypeSend = 22;
				iTemp = g_pMuunInventory.FindbySlot(PickTooltip);

				SendRequestEquipmentItem(22, PickTooltip, iTemp, 22, iTarget);
				return true;
			}
		}
	}
	return false;
}

void MoveWindows(PartyInfoWindow* thisa)
{
	if (pCheckInMouse(thisa->m_Pos.x, thisa->m_Pos.y, 190, 27) && MouseLButton)
	{
		g_pMuunInventory.m_byState = 1;
	}
	else
	{
		g_pMuunInventory.m_byState = 0;
	}

	if (g_pMuunInventory.m_byState == 1)
	{
		int cx = MouseX - g_pMuunInventory.m_ptPos.x;
		int cy = MouseY - g_pMuunInventory.m_ptPos.y;

		thisa->m_Pos.x = (cx < 0) ? 0 : cx;
		thisa->m_Pos.y = (cy < 0) ? 0 : cy;

		Button_ChangeButtonInfo(thisa->m_BtnPartyExit[0], thisa->m_Pos.x + 60, thisa->m_Pos.y + 392, 20, 23);
		Button_ChangeButtonInfo(thisa->m_BtnPartyExit[1], thisa->m_Pos.x + 110, thisa->m_Pos.y + 392, 20, 23);
		Button_ChangeButtonInfo(thisa->m_BtnExit, thisa->m_Pos.x + 13, thisa->m_Pos.y + 392, 36, 29);
	}
}

void RenderWindowsPetMuun(PartyInfoWindow* thisa)
{
	MoveWindows(thisa);
	float x = (float)thisa->m_Pos.x;
	float y = (float)thisa->m_Pos.y;

	g_pRenderText.SetFont(g_hFont);
	g_pRenderText.SetTextColor(0xFFFFFFFF);
	DWORD dwPreBGColor = g_pRenderText.GetBgColor();
	g_pRenderText.SetBgColor(RGBA(0, 0, 0, 0));
	// Base Window
	RenderImageB(31322, x, y, 190.f, 429.f);
	RenderImageB(31353, x, y, 190.f, 64.f);
	RenderImageB(31355, x, y + 64.f, 21.f, 320.f);
	RenderImageB(31356, x + 169.f, y + 64.f, 21.f, 320.f);
	RenderImageB(31357, x, y + 384.f, 190.f, 45.f);

	Button_Render(thisa->m_BtnExit, 0);
	Button_Render(thisa->m_BtnPartyExit[0], 0);
	Button_Render(thisa->m_BtnPartyExit[1], 0);

	g_pRenderText.SetFont(g_hFontBold);
	g_pRenderText.RenderText(thisa->m_Pos.x + 60, thisa->m_Pos.y + 12, "Muun Inventory", 72, 0, RT3_SORT_CENTER);
	//--
	CRenderBitmaps(71618, x + 10.f, y + 150.f, 170, 7, 0.0, 134.f / 512.f, 281.f / 512.f, 11.f / 512.f, true, true, 0.0);
	CRenderBitmaps(71618, x + 10.f, y + (31 * 7.0) + 157.f, 170.f, 7.f, 0.0, 108.f / 512.f, 281.f / 512.f, 10.f / 512.f, true, true, 0.0);
	for (int i = 0; i < 31; i++)
	{
		CRenderBitmaps(71618, x + 10.f, y + (i * 7.0) + 157.f, 170.f, 7.f, 0.0, 120.f / 512.f, 281.f / 512.f, 11.f / 512.f, true, true, 0.0);
	}
	char pag[10];
	sprintf_s(pag, "%d / 3", (g_pMuunInventory.Wnd_Pag + 1));
	g_pRenderText.RenderText(thisa->m_Pos.x + 80, thisa->m_Pos.y + 398, pag, 30, 0, RT3_SORT_CENTER);
}

void RenderEquipSlot(float x, float y)
{
	CRenderBitmaps(71618, x + 11.f, y + 50.f, 168, 68, 0.0, 0.0, 262.f / 512.f, 106.f / 512.f, true, true, 0.0);
	g_pRenderText.RenderText((int)x + 30, (int)y + 58, "Main");
	g_pRenderText.RenderText((int)x + 125, (int)y + 58, "Sub");
	g_pRenderText.SetFont(g_hFont);

	float dx, dy = y + 70.f;
	for (int i = 0; i < 2; i++)
	{
		dx = x + (i * 95) + 27;
		if (pCheckInMouse((int)dx, (int)dy, 40, 42))
		{
			if (g_pMuunInventory.m_pdwItemCheckBox[i] != NULL) { PickTooltip = i; }
			PickSelect = i;
		}
		if (i == 0)
		{
			CRenderBitmaps(71618, dx, dy, 40, 42, 2.f / 512.f, 147.f / 512.f, 64.f / 512.f, 66.f / 512.f, true, true, 0.0);
		}
		else
		{
			CRenderBitmaps(71618, dx, dy, 40, 42, 76.f / 512.f, 147.f / 512.f, 64.f / 512.f, 66.f / 512.f, true, true, 0.0);
		}

		if (ms_pPickedItem)
		{
			bool pickitemvisible = (*(bool(__thiscall**)(int))(*(DWORD*)ms_pPickedItem + 4))(ms_pPickedItem);
			if (pCheckInMouse((int)dx, (int)dy, 40, 42) && pickitemvisible)
			{
				ITEM* iTemp = GetMouseItem(GetPickedItem());
				if ((iTemp->Type == ITEM(14, 16) || iTemp->Type == ITEM(13, 211)) && g_pMuunInventory.m_pdwItemCheckBox[i] != NULL)
				{
					CRenderBitmaps(71618, dx + 1, dy + 1, 38, 40, 172.f / 512.f, 180.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
				}
				else if (g_pMuunInventory.m_pdwItemCheckBox[i] != NULL)
				{
					CRenderBitmaps(71618, dx + 1, dy + 1, 38, 40, 144.f / 512.f, 148.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
				}
				else
				{
					CRenderBitmaps(71618, dx + 1, dy + 1, 38, 40, 198.f / 512.f, 148.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
				}
			}
		}
		if (g_pMuunInventory.m_pdwItemCheckBox[i] != NULL)
		{
			CRenderBitmaps(71618, dx + 2, dy + 2, 36, 38, 252.f / 512.f, 148.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
		}
	}
}

void RenderInventoryCtrl(float x, float y)
{
	float dx, dy;

	int dwKey = 2 + (20 * g_pMuunInventory.Wnd_Pag);

	for (int n = 0; n < 5; n++)
	{
		dy = (float)y + (44 * n) + 156.f;
		for (int m = 0; m < 4; m++)
		{
			dx = (float)x + (40.5 * m) + 14.5f;
			if (pCheckInMouse((int)dx, (int)dy, 40, 42))
			{
				if (g_pMuunInventory.m_pdwItemCheckBox[dwKey] != NULL) { PickTooltip = dwKey; }
				PickSelect = dwKey;
			}

			CRenderBitmaps(71618, dx, dy, 40, 42, 76.f / 512.f, 147.f / 512.f, 64.f / 512.f, 66.f / 512.f, true, true, 0.0);
			if (ms_pPickedItem)
			{
				bool pickitemvisible = (*(bool(__thiscall**)(int))(*(DWORD*)ms_pPickedItem + 4))(ms_pPickedItem);
				if (pCheckInMouse((int)dx, (int)dy, 40, 42) && pickitemvisible)
				{
					ITEM* iTemp = GetMouseItem(GetPickedItem());
					if ((iTemp->Type == ITEM(14, 16) || iTemp->Type == ITEM(13, 211)) && g_pMuunInventory.m_pdwItemCheckBox[dwKey] != NULL)
					{
						CRenderBitmaps(71618, dx + 1, dy + 1, 38, 40, 172.f / 512.f, 180.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
					}
					else if (g_pMuunInventory.m_pdwItemCheckBox[dwKey] != NULL)
					{
						CRenderBitmaps(71618, dx + 1, dy + 1, 38, 40, 144.f / 512.f, 148.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
					}
					else
					{
						CRenderBitmaps(71618, dx + 1, dy + 1, 38, 40, 198.f / 512.f, 148.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
					}
					goto LABEL_119;
				}
			}
			if (g_pMuunInventory.m_pdwItemCheckBox[dwKey] != NULL)
			{
				CRenderBitmaps(71618, dx + 2, dy + 2, 36, 38, 252.f / 512.f, 148.f / 512.f, 26.f / 512.f, 26.f / 512.f, true, true, 0.0);
			}
		LABEL_119:
			dwKey++;
		}
	}
}

void RenderModel3D(float x, float y)
{
	glMatrixMode(0x1701);
	glPushMatrix();
	glLoadIdentity();
	glViewport2(0, 0, *(GLsizei*)g_WindowWidth, *(GLsizei*)g_WindowHeight);
	float v2 = *(float*)g_WindowWidth / *(float*)g_WindowHeight;
	gluPerspective_2(1.f, v2, CameraViewNear, CameraViewFar);
	glMatrixMode(0x1700);
	glPushMatrix();
	glLoadIdentity();
	GetOpenGLMatrixF(CameraMatrixF);
	EnableDepthTestF();
	EnableDepthMaskF();
	glClear(0x100u);

	float sx, sy;
	int iColumnX, iRowY, iLinealPos;

	int iLinealMin = (20 * g_pMuunInventory.Wnd_Pag);
	int iLinealMax = iLinealMin + 20;

	type_vec_item::iterator li = g_pMuunInventory.m_vecItem.begin();
	for (; li != g_pMuunInventory.m_vecItem.end(); li++)
	{
		if (li->first == 0 || li->first == 1)
		{
			sy = y + 70.f;
			sx = x + (li->first * 95.f) + 27.f;
			CRenderItem3D(sx, sy, 40.f, 42.f, li->second->Type, 0, 0, 0, 0);
			continue;
		}

		iLinealPos = li->first - 2;
		if (iLinealPos < iLinealMin || iLinealPos >= iLinealMax)
		{
			continue;
		}
		int iLinealSlot = iLinealPos - iLinealMin;

		iColumnX = iLinealSlot % 4;
		iRowY = iLinealSlot / 4;

		sx = x + (40.5 * iColumnX) + 14.5f;
		sy = y + (44 * iRowY) + 156.f;

		li->second->x = iColumnX;
		li->second->y = iRowY;
		CRenderItem3D(sx, sy, 40.f, 42.f, li->second->Type, 0, 0, 0, 0);
	}
	EndBitmap();
	glColor4f(1.f, 1.f, 1.f, 1.f);
	EnableAlphaTest(true);
}

bool CNewUIPetInfoWindow::Render(PartyInfoWindow* thisa)
{
	if (g_pMuunInventory.m_pNewPetInfoWindow != (char*)thisa)
	{
		RenderWindowsParty(thisa);
		return true;
	}
	EnableAlphaTest(true);
	glColor4f(1.f, 1.f, 1.f, 1.f);
	glAlphaFunc(GL_GREATER, 0.0f);
	//--
	PickSelect = -1;
	PickTooltip = -1;
	g_pMuunInventory.byItem = NULL;
	RenderWindowsPetMuun(thisa);
	//--
	RenderEquipSlot((float)thisa->m_Pos.x, (float)thisa->m_Pos.y);
	RenderInventoryCtrl((float)thisa->m_Pos.x, (float)thisa->m_Pos.y);
	RenderModel3D((float)thisa->m_Pos.x, (float)thisa->m_Pos.y);
	//--
	DisableAlphaBlend();
	glAlphaFunc(GL_GREATER, 0.25f);
	return true;
}

void CNewUIPetInfoWindow::UI_2DEffectCallback(bool dwParamA)
{
	if (g_pNewUISystem.IsVisible(110))
	{
		if (g_pMuunInventory.m_iMixEffectTimer > 0)
		{
			--g_pMuunInventory.m_iMixEffectTimer;

			int iLinealMin = (20 * g_pMuunInventory.Wnd_Pag);
			int iLinealMax = iLinealMin + 20;
			int iLinealPos = IndexEffect - 2;

			if (iLinealPos >= iLinealMin && iLinealPos < iLinealMax)
			{
				EnableAlphaBlend();
				PartyInfoWindow* thisa = (PartyInfoWindow*)g_pMuunInventory.m_pNewPetInfoWindow;
				int iLinealSlot = iLinealPos - iLinealMin;

				int iColumnX = iLinealSlot % 4;
				int iRowY = iLinealSlot / 4;

				for (int h = 0; h < 1; ++h)
				{
					for (int w = 0; w < 1; ++w)
					{
						glColor3f((float)(rand() % 6 + 6) * 0.1f, (float)(rand() % 4 + 4) * 0.1f, 0.2f);

						float Rotate = (float)((int)(WorldTime) % 100) * 20.f;
						float Scale = 5.f + (rand() % 10);

						float x = thisa->m_Pos.x + (iColumnX * 42) + (rand() % 42) + 14.5f;
						float y = thisa->m_Pos.y + (iRowY * 44) + (rand() % 44) + 156.f;

						RenderBitmapRotate(32113, x, y, Scale, Scale, 0, 0.0, 0.0, 1.0, 1.0);
						RenderBitmapRotate(32113, x, y, Scale, Scale, Rotate, 0.0, 0.0, 1.0, 1.0);
						RenderBitmapRotate(32114, x, y, Scale * 3.f, Scale * 3.f, Rotate, 0.0, 0.0, 1.0, 1.0);
						RenderBitmapRotate(32002, x, y, Scale * 6.f, Scale * 6.f, 0, 0.0, 0.0, 1.0, 1.0);
					}
				}
				DisableAlphaBlend();
			}
		}

		if (PickTooltip != -1)
		{
			int v4; ITEM* iTemp = NULL;
			if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetMouseItem(v4)) == 0))
			{
				g_pMuunInventory.byItem = g_pMuunInventory.FindbySlot(PickTooltip);

				if (g_pMuunInventory.byItem)
				{
					PartyInfoWindow* thisa = (PartyInfoWindow*)g_pMuunInventory.m_pNewPetInfoWindow;

					if (PickTooltip > 1)
					{
						int iLinealMin = (20 * g_pMuunInventory.Wnd_Pag);
						int iLinealSlot = PickTooltip - 2 - iLinealMin;

						int iColumnX = iLinealSlot % 4;
						int iRowY = iLinealSlot / 4;

						float sx = thisa->m_Pos.x + (40 * iColumnX) + 14.f;
						float sy = thisa->m_Pos.y + (44 * iRowY) + 156.f;

						int iTargetX = sx + 20.f;
						int iTargetY = sy + 20.f;

						RenderItemInfo(GetUI3D(GetInstance()), iTargetX, iTargetY, g_pMuunInventory.byItem, false, 0, false);
					}
					else if (PickTooltip == 0 || PickTooltip == 1)
					{
						float sy = thisa->m_Pos.y + 70.f;
						float sx = thisa->m_Pos.x + (PickTooltip * 95.f) + 27.f;
						int iTargetX = sx + 20.f;
						int iTargetY = sy + 20.f;
						RenderItemInfo(GetUI3D(GetInstance()), iTargetX, iTargetY, g_pMuunInventory.byItem, false, 0, false);
					}
				}
			}
		}
		DisableAlphaBlend();
	}
	EnableAlphaTest(true);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}


bool CNewUIPetInfoWindow::CheckOpenWindows(int thisa, DWORD dwKey)
{
	return CNewUISystem_IsVisible(thisa, dwKey) || CNewUISystem_IsVisible(thisa, 110);
}

void CNewUIPetInfoWindow::HideWindows(int thisa, DWORD dwKey)
{
	CNewUISystem_HideSystem(thisa, dwKey);
	CNewUISystem_HideSystem(thisa, 110);
	PickSelect = -1;
	PickTooltip = -1;
	SlotPickBackup = -1;
	IndexEffect = -1;
}

BYTE CNewUIPetInfoWindow::RenderEquipedMuunLife(int sx, int sy, int Slot)
{
	BYTE t = 0;
	ITEM* pNewItem = g_pMuunInventory.FindbySlot(Slot);

	if (pNewItem != NULL)
	{
		ITEM_ATTRIBUTE Attribute = *(ITEM_ATTRIBUTE*)(pItem_Attribute + 84 * pNewItem->Type);

		CreateBarHP(sx, sy, Attribute.Name, pNewItem->Durability, 255, 0);
		t = 1;
	}
	return t;
}

BYTE CNewUIPetInfoWindow::PetEquipedHPBar(int iX, int iY)
{
	char result;
	int PetSlot = *(WORD*)(Hero + 556);
	int type = gCustomPet2.GetInfoPetType(PetSlot - 1171);

	if ((PetSlot < 7827 || PetSlot > 7831)
		&& PetSlot != 7891
		&& PetSlot != 7892
		&& PetSlot != 7894
		&& PetSlot != 7907
		&& PetSlot != 7933
		&& PetSlot != 7950
		&& PetSlot != 7864
		&& (type == 4 || type == -1))
	{
		result = 0;
	}
	else
	{
		int PetHP;
		ITEM_ATTRIBUTE Attribute = *(ITEM_ATTRIBUTE*)(pItem_Attribute + 84 * (*(WORD *)(Hero + 556) - 1171));
		char PetName[255] = { 0, };
		switch (PetSlot)
		{
		case 7827:
			wsprintf(PetName, GlobalText(GlobalLine, 353));
			break;
		case 7828:
			wsprintf(PetName, Attribute.Name);//(char *)oUserTextObject + 84 * (*(WORD *)(oUserPreviewStruct + 556) - 1171));
			break;
		case 7829:
			wsprintf(PetName, GlobalText(GlobalLine, 355));
			break;
		case 7830:
			wsprintf(PetName, GlobalText(GlobalLine, 354));
			break;
		case 7831:
			wsprintf(PetName, GlobalText(GlobalLine, 1187));
			break;
		case 7864:
			wsprintf(PetName, GlobalText(GlobalLine, 1916));
			break;
		case 7891:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7892:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7894:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7907:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7933:
			wsprintf(PetName, Attribute.Name);
			break;
		case 7950:
			wsprintf(PetName, Attribute.Name);
			break;
		default:
			wsprintf(PetName, Attribute.Name);
			break;
		}
		PetHP = *(BYTE*)(*(DWORD*)0x8128AC4 + 5550);
		CreateBarHP(iX, iY, PetName, PetHP, 255, 0);
		result = 1;
	}
	return result;
}

void CNewUIPetInfoWindow::RenderInterfaceLeft(int thisa)
{
	POINT g_dir = { *(DWORD*)(thisa + 16), *(DWORD*)(thisa + 20) }; // eax@9

	if (GetBaseClass(*(BYTE*)(Hero + 19)) == 2 && RenderNumArrow(thisa, g_dir.x, g_dir.y))
	{
		g_dir.y += 9;
	}
	if (g_pMuunInventory.PetEquipedHPBar(g_dir.x, g_dir.y))
	{
		g_dir.y += 23;
	}
	if (GetBaseClass(*(BYTE*)(Hero + 19)) == 4 && RenderEquipedPetLife(thisa, g_dir.x, g_dir.y))
	{
		g_dir.y += 22;
	}
	if (g_pMuunInventory.RenderEquipedMuunLife(g_dir.x, g_dir.y, 0))
	{
		g_dir.y += 22;
	}
	if (g_pMuunInventory.RenderEquipedMuunLife(g_dir.x, g_dir.y, 1))
	{
		g_dir.y += 22;
	}
	if (GetBaseClass(*(BYTE*)(Hero + 19)) == 2)
	{
		if (RenderSummonMonsterLife(thisa, g_dir.x, g_dir.y)) { g_dir.y += 22; }
	}
}

int IsEquipable(ITEM* pItemObj, int m_iPointedSlot)
{
	ITEM* iTemp = &*(ITEM*)(CharacterMachine + 107 * m_iPointedSlot + 4672);

	if (iTemp->Type != 65535 && (m_iPointedSlot == 0 || m_iPointedSlot == 10))
	{
		m_iPointedSlot++;
		iTemp = &*(ITEM*)(CharacterMachine + 107 * m_iPointedSlot + 4672);
	}

	if (CheckEquipItem(m_iPointedSlot, pItemObj) && iTemp->Type == 65535)
	{
		return m_iPointedSlot;
	}

	return -1;
}

bool MoveFromInventory(int thisa, BYTE TargetFlag, BYTE TargetSlot, bool SendEquip)
{
	int v259 = -1;

	ITEM* pNewItem = InvCtrl_FindItemAtPt((void*)thisa, MouseX, MouseY, &v259);

	if (pNewItem)
	{
		if (pNewItem->Type == ITEM(13, 121)
			|| IsInvenItem(pNewItem->Type)
			|| pNewItem->Type == ITEM(12, 21)
			|| pNewItem->Type == ITEM(12, 22)
			|| pNewItem->Type == ITEM(12, 23)
			|| pNewItem->Type == ITEM(12, 24))
		{
			return false;
		}
		int SourceSlot = GetSlotIndexAtPt(pNewItem->x, pNewItem->y, v259);

		if (SourceSlot != 0xFF)
		{
			if (SendEquip)
			{
				if (pNewItem->Type >= ITEM(14, 0))
				{
					return false;
				}//-- perfect!

				ITEM_ATTRIBUTE* Attribute = (ITEM_ATTRIBUTE*)&ItemAttribute[pNewItem->Type];

				if (Attribute->m_byItemSlot == 0xFF || Attribute->m_byItemSlot == -1)
				{
					return false;
				}

				if (Attribute->m_byItemSlot >= 0 && Attribute->m_byItemSlot < 12)
				{
					TargetSlot = IsEquipable(pNewItem, Attribute->m_byItemSlot);

					if (TargetSlot > -1 && TargetSlot != 0xFF)
					{
						m_bySendSlot = SourceSlot + 12;
						m_byTypeRecv = 0;
						m_byTypeSend = 0;
						SendRequestEquipmentItem(0, SourceSlot + 12, pNewItem, 0, TargetSlot);
						return true;
					}
				}
				return false;
			}
			else if (GetMixInventoryEquipmentIndex(g_MixRecipeMgr) == TargetFlag)
			{
				int Machine = pGetUIChaosMachine(GetInstance());

				ITEM_ATTRIBUTE Attribute = ItemAttribute[pNewItem->Type];

				TargetSlot = InventoryCtrl_FindEmptySlot((void*)*(DWORD*)(Machine + 16), Attribute.Width, Attribute.Height);

				if (TargetSlot != -1)
				{
					m_bySendSlot = SourceSlot + 12;
					m_byTypeSend = 0;
					m_byTypeRecv = TargetFlag;
					SendRequestEquipmentItem(0, SourceSlot + 12, pNewItem, TargetFlag, TargetSlot);
					return true;
				}
			}
		}
	}
	return false;
}

int CheckUnEquip(int slot)
{
	int v61 = 1; // [sp+7Bh] [bp-1071h]@44

	if (World == 10)
	{
		if (slot == 8 || slot == 7)
		{
			if (slot != 8 || sub_587C00())
			{
				if (slot == 7 && CharacterMachineEquip(8) != 6659
					&& CharacterMachineEquip(8) != 6660 && CharacterMachineEquip(8) != 6693)
				{
					v61 = 0;
				}
			}
			else
			{
				v61 = 0;
			}
		}
	}
	return v61;
}

bool CNewUIPetInfoWindow::InventoryProcess(int thisa)
{
	//--
	int v4; ITEM* iTemp = NULL;
	if (!GetPickedItem() || (v4 = GetPickedItem(), (iTemp = GetMouseItem(v4)) == 0))
	{
		//if (IsPress(VK_RBUTTON))
		//{
		//	if (*(DWORD*)(thisa + 284) != -1)
		//	{
		//		iTemp = &*(ITEM*)(CharacterMachine + 107 * *(DWORD*)(thisa + 284) + 4672);

		//		if (iTemp && iTemp->Type != 65535)
		//		{
		//			BYTE TargetSlot = InvCtrl_FindEmptySlot(thisa, iTemp, 0);

		//			if (TargetSlot == 0xFF || CheckUnEquip(*(DWORD*)(thisa + 284)) == 0)
		//			{
		//				goto LABEL_45;
		//			}
		//			m_bySendSlot = *(DWORD*)(thisa + 284);
		//			m_byTypeRecv = 0;
		//			m_byTypeSend = 0;
		//			SendRequestEquipmentItem(0, *(DWORD*)(thisa + 284), iTemp, 0, TargetSlot + 12);
		//			return true;
		//		}
		//	}
		//	else if (g_pNewUISystem.IsVisible(8) || g_pNewUISystem.IsVisible(7)) //-- bauls
		//	{
		//		goto LABEL_45;
		//	}
		//	else if (g_pNewUISystem.IsVisible(9)) //-- chaos machine
		//	{
		//		int Machine = pGetUIChaosMachine(GetInstance());
		//		int MixRecipe = GetMixInventoryEquipmentIndex(g_MixRecipeMgr);

		//		if (pCheckInMouse(*(DWORD*)(Machine + 20), *(DWORD*)(Machine + 24), 190, 429))
		//		{
		//			ITEM* iTemp = InventoryCtrl_FindItemAtPt((void*)*(DWORD**)(Machine + 16), MouseX, MouseY);

		//			if (iTemp)
		//			{
		//				BYTE TargetSlot = InvCtrl_FindEmptySlot(thisa, iTemp, 0);
		//				BYTE SourceSlot = iTemp->x + iTemp->y * 8;

		//				m_byTypeSend = MixRecipe;
		//				m_byTypeRecv = 0;
		//				m_bySendSlot = SourceSlot;
		//				SendRequestEquipmentItem(MixRecipe, SourceSlot, iTemp, 0, TargetSlot + 12);
		//				return true;
		//			}
		//		}
		//		else
		//		{
		//			if (MoveFromInventory(thisa, MixRecipe, -1, false)) { return true; }
		//		}
		//	}
		//	else
		//	{

		//		if (MoveFromInventory(thisa, 0, 0, true)) { return true; }
		//	}
		//}
	}
LABEL_45:
	return CInventoryProcess(thisa);
}

float GetLayerDepthPet()
{
	if (g_pNewUISystem.IsVisible(SEASON6B::INTERFACE_MYSHOP_INVENTORY))
	{
		int MyShopInventory = *(DWORD*)(GetInstance() + 84);
		if (pCheckInMouse(*(DWORD*)(MyShopInventory + 20), *(DWORD*)(MyShopInventory + 24), 190, 429))
		{
			return 2.4f;
		}
	}

	return 6.15f;
}

int CNewUIPetInfoWindow::Storage_GetSourceLinePos(int thisa)
{
	if (SlotPickBackup != -1)
	{
		SetByte(0x007AFD0B + 1, 8);
		return SlotPickBackup;
	}
	SetByte(0x007AFD0B + 1, 1);
	return GetSourceLinealPos(thisa);
}

bool Storage_SendRequestEquipmentItem(BYTE SourceFlag, BYTE SourceSlot, ITEM* pItem, BYTE TargetFlag, BYTE TargetSlot)
{
	if (SlotPickBackup != -1)
	{
		SourceFlag = 22;
		SourceSlot = SlotPickBackup;
	}
	return SendRequestEquipmentItem(SourceFlag, SlotPickBackup, pItem, TargetFlag, TargetSlot);
}

void CNewUIPetInfoWindow::Init()
{
	SetCompleteHook(0xE9, 0x0084B240, &GetLayerDepthPet);
	//--
	SetCompleteHook(0xE8, 0x0084A438, &CNewUIPetInfoWindow::HideWindows);
	SetCompleteHook(0xE8, 0x0084A410, &CNewUIPetInfoWindow::CheckOpenWindows);
	//--
	SetCompleteHook(0xE9, 0x0084A4A0, &CNewUIPetInfoWindow::Render);
	SetCompleteHook(0xE8, 0x0084A07E, &CNewUIPetInfoWindow::LoadImages);
	SetCompleteHook(0xE8, 0x0084A3BA, &CNewUIPetInfoWindow::BtnProcess);
	SetCompleteHook(0xE8, 0x0084A086, &CNewUIPetInfoWindow::InitButtons);
	//--

	SetCompleteHook(0xE8, 0x0080F83A, &CNewUIPetInfoWindow::UI_2DEffectCallback);
	SetCompleteHook(0xE8, 0x007DF83E, &CNewUIPetInfoWindow::RenderInterfaceLeft);
	//--
	SetCompleteHook(0xE8, 0x007AFD7D, &Storage_SendRequestEquipmentItem);
	SetCompleteHook(0xE8, 0x007AFB96, &CNewUIPetInfoWindow::Storage_GetSourceLinePos);
	//-- ReceiveCreatePlayerViewport
	//SetByte(0x006420AB + 3, 0x26); //-- buffList
	//SetByte(0x00642098 + 3, 0x26); //-- buffList
	//SetByte(0x00642083 + 3, 0x25); //-- buffcount
	//SetByte(0x006420DB + 3, 0x25); //-- buffcount
	//SetDword(0x006420E6 + 1, 0x36); //-- 56
	//SetCompleteHook(0xE8, 0x0066419E, &ReceiveCreatePlayerViewport);
	////--
	//SetByte(0x006423B9 + 3, 0x26); //-- buffList
	//SetByte(0x006423CC + 3, 0x26); //-- buffList
	//SetByte(0x006423A4 + 3, 0x27); //-- buffcount
	//SetByte(0x006425A3 + 3, 0x27); //-- buffcount
	//SetDword(0x006425AE + 1, 0x36); //-- 56
	//SetCompleteHook(0xE8, 0x006641D1, &ReceiveCreateTransformViewport);
	//--
	SetCompleteHook(0xE9, 0x005012D0, &DelectPetBug);
	SetCompleteHook(0xE8, 0x0066424B, &ReceiveEquipmentItem);
	SetCompleteHook(0xE8, 0x0083469C, &CNewUIPetInfoWindow::InventoryProcess);
}