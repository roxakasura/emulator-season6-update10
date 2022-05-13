#include "StdAfx.h"
#include "Util.h"
#include "NewUIPetInfoWindow.h"
#include "NewUISystem.h"
#include "Interface.h"
#include "Defines.h"

CNewUISystem g_pNewUISystem;

CNewUISystem::CNewUISystem()
{
}

CNewUISystem::~CNewUISystem()
{
}

bool CNewUISystem::IsVisible(DWORD dwKey)
{
	return CNewUISystem_IsVisible(GetInstance(), dwKey);
}

void CNewUISystem::Hide(DWORD dwKey)
{
	CNewUISystem_HideSystem(GetInstance(), dwKey);
}

void CNewUISystem::Show(DWORD dwKey)
{
	CNewUISystem_ShowSystem(GetInstance(), dwKey);
}

void CNewUISystem::ShowInterface(DWORD dwKey, bool bShow)
{
	CNewUIManager_ShowInterface(GetNewUIManager((void*)GetInstance()), dwKey, bShow);
}

void CNewUISystem::Toggle(DWORD dwKey)	//. Show <-> Hide
{
	CNewUISystem_ToggleSystem(GetInstance(), dwKey);
}

void CNewUISystem::HideAll()
{
	CNewUISystem_HideAll(GetInstance());
}

int CNewUISystem::GetUI_NewMyInventory()
{
	return CNewUISystem_GetUI_NewMyInventory(GetInstance());
}

int CNewUISystem::GetOwnerMyInventory()
{
	return CNewUISystem_GetInventoryCtrl((void*)*(DWORD*)(GetInstance() + 40), GetOwnerInventory(GetPickedItem()));
}

int CNewUISystem::GetTargetOwnerMyInventory()
{
	return CNewUISystem_GetTargetInventoryCtrl((void*)*(DWORD*)(GetInstance() + 40), (WORD**)GetPickedItem());
}

int CNewUISystem::GetOwnerShopInventory()
{
	return MyShop_pNewInventoryCtrl(*(DWORD*)(GetInstance() + 84));
}

int CNewUISystem::GetOwnerMixInventory()
{
	return MyMix_pNewInventoryCtrl(*(DWORD*)(GetInstance() + 52));
}

bool CNewUISystem::LoadMainSceneInterface(int* thisa)
{
	g_pMuunInventory.Create(*thisa);
	return CNewUISystem_LoadMainSceneInterface(thisa);
}

void HIdeallWindows(int thisa)
{
	if (GetNewUIManager((void*)GetInstance()))
	{
		if (g_pNewUISystem.IsVisible(110))
		{
			PickSelect = -1;
			PickTooltip = -1;
			SlotPickBackup = -1;
			IndexEffect = -1;
			g_pNewUISystem.Hide(110);
		}
		for (int i = 1; i < 109; i++)
		{
			if (IsImpossibleHideInterface(i) == false)
			{
				if (g_pNewUISystem.IsVisible(i) == true)
				{
					g_pNewUISystem.Hide(i);
				}
			}
		}
	}
}

bool OpenWindowKey(int iVirtKey)
{
	if (IsPress('Y'))
	{
		if (gInterface.CheckWindow(ChaosBox) 
		|| gInterface.CheckWindow(Warehouse) 
		|| gInterface.CheckWindow(Trade) 
		|| gInterface.CheckWindow(Shop)
		|| gInterface.CheckWindow(Store)
		|| gInterface.CheckWindow(OtherStore))
		{
			return false;
		}

		if (g_pNewUISystem.IsVisible(110))
		{
			PickSelect = -1;
			PickTooltip = -1;
			SlotPickBackup = -1;
			IndexEffect = -1;
		}
		g_pNewUISystem.Toggle(110);
		PlayBuffer(25, 0, 0);
	}
	return IsPress(VK_TAB);
}

void VerifyWindow()
{
	if (gInterface.CheckWindow(ChaosBox) 
	|| gInterface.CheckWindow(Warehouse) 
	|| gInterface.CheckWindow(Trade) 
	|| gInterface.CheckWindow(Shop)
	|| gInterface.CheckWindow(Store)
	|| gInterface.CheckWindow(OtherStore))
	{
		PickSelect = -1;
		PickTooltip = -1;
		SlotPickBackup = -1;
		IndexEffect = -1;
		g_pNewUISystem.Hide(110);
	}
}

void PopUpErrorCheckMsgBox(const char* szErrorMsg, bool bForceDestroy)
{
	MessageBox(NULL, szErrorMsg, NULL, MB_OK);
	SendMessage(NULL, WM_DESTROY, 0, 0);
}

void CNewUISystem::Init()
{
	SetCompleteHook(0xE8, 0x007D35A8, &OpenWindowKey);
	SetCompleteHook(0xE9, 0x008606B0, &HIdeallWindows);
	SetCompleteHook(0xE8, 0x00614AEF, &PopUpErrorCheckMsgBox);//-- open texture model
	SetCompleteHook(0xE8, 0x00772460, &PopUpErrorCheckMsgBox);//-- open texture
	//--
	SetCompleteHook(0xE8, 0x004D58A0, &CNewUISystem::LoadMainSceneInterface);
}