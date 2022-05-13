
#include "stdafx.h"
#include "Util.h"
#include "User.h"
#include "CustomStartItem.h"
#include "CashShop.h"
#include "MemScript.h"
#include "DSProtocol.h"
#include "ItemManager.h"
#include "ServerInfo.h"
#include "Notice.h"
#include "Message.h"

CGift gGiftNew;

CGift::CGift() // OK
{
    this->Init();
}

CGift::~CGift() // OK
{

}

void CGift::Init() // OK
{
    this->m_GiftInfo.clear();
	this->m_BuffInfo.clear();
	this->m_StatsInfo.clear();
}

void CGift::Load(char* path) // OK
{
    CMemScript* lpMemScript = new CMemScript;

    if(lpMemScript == 0)
    {
        ErrorMessageBox(MEM_SCRIPT_ALLOC_ERROR,path);
        return;
    }

    if(lpMemScript->SetBuffer(path) == 0)
    {
        ErrorMessageBox(lpMemScript->GetLastError());
        delete lpMemScript;
        return;
    }

    this->Init();

    try
    {
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END)
			{
				break;
			}

			int section = lpMemScript->GetNumber();

			while(true)
			{
				if(section == 0)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					STATS_INFO info;

					info.Class = lpMemScript->GetNumber();

					info.Resets = lpMemScript->GetAsNumber();
					
					info.LevelUpPoints = lpMemScript->GetAsNumber();

					info.Zen = lpMemScript->GetAsNumber();

					this->m_StatsInfo.push_back(info);
				}

				else if(section == 1)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					GIFT_INFO info;

					info.Class = lpMemScript->GetNumber();
			
					info.Session = lpMemScript->GetAsNumber();

					info.ItemID = lpMemScript->GetAsNumber();

					info.Level = lpMemScript->GetAsNumber();

					info.Duration = lpMemScript->GetAsNumber();

					info.Skill = lpMemScript->GetAsNumber();

					info.Luck = lpMemScript->GetAsNumber();

					info.Option = lpMemScript->GetAsNumber();

					info.Excellent = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->m_GiftInfo.push_back(info);
				}
				else if(section == 2)
				{
					if(strcmp("end",lpMemScript->GetAsString()) == 0)
					{
						break;
					}

					BUFF_INFO info;

					info.Class = lpMemScript->GetNumber();

					info.EffectID = lpMemScript->GetAsNumber();

					info.Power1 = lpMemScript->GetAsNumber();

					info.Power2 = lpMemScript->GetAsNumber();

					info.Time = lpMemScript->GetAsNumber();

					this->m_BuffInfo.push_back(info);
				}
				else
				{
					break;
				}
			}
        }
    }
    catch(...)
    {
        ErrorMessageBox(lpMemScript->GetLastError());
    }

    delete lpMemScript;
}

void CGift::GiftItem(LPOBJ lpObj)
{
	if(gServerInfo.m_CustomItemStartSwitch[lpObj->AccountLevel] == 1)
	{
		if(lpObj->TheGift >= 1)
		{
			return;
		
		}
	
		lpObj->TheGift += 1;
		GDSaveTheGiftData(lpObj->Index);
		gNotice.GCNoticeSend(lpObj->Index,1,0,0,0,0,0,gMessage.GetMessage(37));

		for(std::vector<STATS_INFO>::iterator it=this->m_StatsInfo.begin();it != this->m_StatsInfo.end();it++)
		{
			if (it->Class != lpObj->Class)
			{
				continue;
			}

				lpObj->Reset += it->Resets;
				lpObj->LevelUpPoint += it->LevelUpPoints;

				GCMoneySend(lpObj->Index,lpObj->Money += it->Zen);
				
				GDResetInfoSaveSend(lpObj->Index,0,0,0);
				GCNewCharacterInfoSend(lpObj);
				GDCharacterInfoSaveSend(lpObj->Index);
		}

		for(std::vector<GIFT_INFO>::iterator it=this->m_GiftInfo.begin();it != this->m_GiftInfo.end();it++)
		{
			if (it->Class != lpObj->Class)
			{
				continue;
			}

			int Days = it->Time;
			time_t t = time(NULL);
			localtime(&t);
			DWORD iTime = (DWORD)t + Days * 86400;
			GDCreateItemSend(lpObj->Index,0xEB,0,0,GET_ITEM(it->Session,it->ItemID),it->Level,it->Duration,it->Skill,it->Luck,it->Option,-1,it->Excellent,0,0,0,0,0xFF,iTime);
		}

		for(std::vector<BUFF_INFO>::iterator it=this->m_BuffInfo.begin();it != this->m_BuffInfo.end();it++)
		{
			if (it->Class != lpObj->Class)
			{
				continue;
			}

			EFFECT_INFO* lpInfo = gEffectManager.GetInfo(it->EffectID);

			if(lpInfo == 0)
			{
				continue;
			}
			int Days = it->Time;
			time_t t = time(NULL);
			localtime(&t);
			DWORD iTime = (DWORD)t + Days * 86400;
			gEffectManager.AddEffect(lpObj,1,it->EffectID,iTime,it->Power1,it->Power2,0,0);
		}
	}
}


