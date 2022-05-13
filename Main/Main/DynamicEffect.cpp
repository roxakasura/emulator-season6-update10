#include "stdafx.h"
#include "CustomWing.h"
#include "DynamicEffect.h"

CDynamicWingEffect gDynamicWingEffect;

CDynamicWingEffect::CDynamicWingEffect()
{
	this->m_DynamicWingEffectInfo.clear();
}

CDynamicWingEffect::~CDynamicWingEffect()
{

}


void CDynamicWingEffect::Load(DYNAMIC_WING_EFFECT_INFO* info){
	for(int n=0;n < MAX_DYNAMIC_WING_EFFECT;n++){
		if(info[n].Index < 0 || info[n].Index >= MAX_DYNAMIC_WING_EFFECT){
			return;
		}
		this->m_DynamicWingEffectInfo.insert(std::pair<int,DYNAMIC_WING_EFFECT_INFO>(info[n].Index,info[n]));
	}
}