#pragma once

void MagoTeste();
void JCGetPartGlowObject_1();
void JCGetPartBrightnessObject_2();
void JCGetPartOptionObject_3();void CharInfoMov();

int __fastcall SelectServerBarPosition(int a1, int a2, signed int a3, signed int a4, char a5);

int TextTest(int X, int Y, LPCTSTR Text);
void DivineWeapon();
void DropColor();

#define DisplayInfoBarCharacter			((int(__fastcall*)(int a1, int a2, signed int a3, signed int a4, char a5)) 0x416640)