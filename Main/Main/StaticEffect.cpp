#include "stdafx.h"
#include "StaticEffect.h"
#include "CustomWing.h"
#include "DynamicEffect.h"

CCustomWingEffect gCustomWingEffect;

CCustomWingEffect::CCustomWingEffect(){
	this->m_CustomWingEffectInfo.clear();
}

CCustomWingEffect::~CCustomWingEffect(){

}

void CCustomWingEffect::Load(CUSTOM_WING_EFFECT_INFO* info){
	for(int n=0;n < MAX_DYNAMIC_WING_EFFECT;n++){
		if(info[n].Index < 0 || info[n].Index >= MAX_DYNAMIC_WING_EFFECT){
			return;
		}
		this->m_CustomWingEffectInfo.insert(std::pair<int,CUSTOM_WING_EFFECT_INFO>(info[n].Index,info[n]));
	}
}

BOOL CCustomWingEffect::SetWingEffect(int ItemIndex,DWORD a,DWORD b,DWORD c,DWORD d){
	int active = 0;
	float ItemColor1[3];
	float ItemColor2[3];
	for(int n = 0 ; n < MAX_DYNAMIC_WING_EFFECT ; n++)
	{
		active = 0;
		if (n > this->m_CustomWingEffectInfo.size() && n >  gDynamicWingEffect.m_DynamicWingEffectInfo.size()){
			return 0;
		}
		//-- Dinamic Effect
		if (n <=  gDynamicWingEffect.m_DynamicWingEffectInfo.size())
		{
			std::map<int, DYNAMIC_WING_EFFECT_INFO>::iterator it = gDynamicWingEffect.m_DynamicWingEffectInfo.find(n);
			if(it != gDynamicWingEffect.m_DynamicWingEffectInfo.end())
			{
				if(it->second.ItemIndex == ItemIndex)
				{
					ItemColor1[0] = it->second.ColorR;
					ItemColor1[1] = it->second.ColorG;
					ItemColor1[2] = it->second.ColorB;
					pAllowStaticEffect((void*)a,&b,c,it->second.EffectValue,it->second.EffectLevel);
					pPlayDynamicEffect(it->second.EffectIndex,&b,c,ItemColor1,it->second.Effect1,it->second.Effect,it->second.Effect2);
					active = 1;
				}
			}
		}
		//-- Static Effect
		if (n <= this->m_CustomWingEffectInfo.size()){
			std::map<int, CUSTOM_WING_EFFECT_INFO>::iterator it2 = this->m_CustomWingEffectInfo.find(n);
			if(it2 != this->m_CustomWingEffectInfo.end()){
				if(it2->second.ItemIndex == ItemIndex){
					ItemColor2[0] = it2->second.ColorR;
					ItemColor2[1] = it2->second.ColorG;
					ItemColor2[2] = it2->second.ColorB;
					pAllowStaticEffect((void*)a,&b,c,it2->second.EffectValue,it2->second.EffectLevel);
					pPlayStaticEffect(it2->second.EffectIndex,&b,it2->second.ColorSize,ItemColor2,d,it2->second.ColorMain,(DWORD)it2->second.ColorSide);
					active = 1;
				}
			}
		}
	}
	return active;
}