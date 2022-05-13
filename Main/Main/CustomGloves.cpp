#include "stdafx.h"
#include "CustomGloves.h"
#include "Item.h"

cCustomGloves gCustomGloves;

cCustomGloves::cCustomGloves(){
	this->Init();
}

cCustomGloves::~cCustomGloves(){}

void cCustomGloves::Init(){
	for(int n=0;n < MAX_CUSTOM_GLOVES;n++){
		this->m_CustomGlovesInfo[n].Index = -1;
	}
}

void cCustomGloves::Load(CUSTOM_RF_GLOVES* info){
	for(int n=0;n < MAX_CUSTOM_GLOVES;n++){
		this->SetInfo(info[n]);
	}
}

void cCustomGloves::SetInfo(CUSTOM_RF_GLOVES info){
	if(info.Index < 0 || info.Index >= MAX_CUSTOM_GLOVES){
		return;
	}
	this->m_CustomGlovesInfo[info.Index] = info;
}

CUSTOM_RF_GLOVES* cCustomGloves::GetInfoByID(int index){
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++){
		if (this->m_CustomGlovesInfo[i].Index == -1){
			continue;
		}
		if (i == index){
			return &this->m_CustomGlovesInfo[i];
		}
	}
	return 0;
}

void cCustomGloves::AssocGloves(char* This){
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++){
		if (this->m_CustomGlovesInfo[i].Index == -1){
			continue;
		}
		sub_50D810_Addr((int)(This + 92), this->m_CustomGlovesInfo[i].ItemIndex+ITEM_BASE_MODEL, this->m_CustomGlovesInfo[i].TextureLeftIndex, this->m_CustomGlovesInfo[i].TextureRightIndex);
		void* v2 = sub_512D50_Addr(This + 92);
		char* v3 = sub_513C60_Addr(This, v2, (int)(This + 92));
		sub_5135F0_Addr((DWORD *)This + 15, (int)This, (int)v3);
		sub_512D60_Addr();
	}
}

bool cCustomGloves::CheckGloves(int ItemID){
	for (int i=0;i<MAX_CUSTOM_GLOVES; i++){
		if (this->m_CustomGlovesInfo[i].Index == -1){
			continue;
		}
		if (ItemID == this->m_CustomGlovesInfo[i].ItemIndex){
			return true;
		}
	}
	return false;
}

CUSTOM_RF_GLOVES* cCustomGloves::GetInfoByItem(int ItemIndex){
	for(int n=0;n < MAX_CUSTOM_GLOVES;n++){
		CUSTOM_RF_GLOVES* lpInfo = this->GetInfoByID(n);
		if(lpInfo == 0){
			continue;
		}
		if(lpInfo->ItemIndex == ItemIndex){
			return lpInfo;
		}
	}
	return 0;
}

