#include "stdafx.h"
#include "RotateDamage.h"

RotateDamage	gRotateDamage;

/**
 * Calcula a rotação, na tela, do dano causado
 */
void RotateDamage::CalculateRotation(float& PositionX, float& PositionY, float PositionD)
{
	const float Radian = 0.01745329f;

	float Sine = sin(Radian * (*(float*) 0x87933D8));
	float Cosine = cos(Radian * (*(float*) 0x87933D8));

	PositionX += PositionD / 0.7071067f * Cosine / 2;
	PositionY -= PositionD / 0.7071067f * Sine / 2;
}
