#pragma once

class CSCustomMenuD{
public:
	CSCustomMenuD();
	void Bind();
	void DrawD();
	bool Button(DWORD Event);
	float m_PosX;
	float m_PosY;
};

extern CSCustomMenuD gCustomMenuD;
