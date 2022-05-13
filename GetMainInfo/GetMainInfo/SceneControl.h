#pragma once

#define MAX_WORLD_SETTINGS 1
#define MAX_WORLD_SELECT_CHAR 5
#define MAX_PJ_SELECT_CHAR 7


struct ButtonRenderChar
{
	DWORD ID;
	float x;
	float y;
	float w;
	float h;
	bool Event;
};

struct Coord
{
	float CoordX;
	float CoordY;
	float Rotate;
};

struct Personaje
{
	int Index;
	Coord Coordenada1;
	Coord Coordenada2;
	ButtonRenderChar BT;
};

struct ScaleOption
{
	float CoordA;
	float CoordB;
};

struct ScaleChar
{
	int Index;
	ScaleOption Option1;
	ScaleOption Option2;
};

struct SelectChar
{
	int Index;
	int MapChar;
	float flt_87933D0;
	float flt_87933D4;
	float flt_87933D8;
	float flt_87933DC;
	float flt_87933E0;
	float flt_87933E4;
	Personaje PJ[MAX_WORLD_SELECT_CHAR];
	ScaleChar Size[MAX_PJ_SELECT_CHAR];
};

struct SelectSrv
{
	int Index;
	int MapServ;
	float flt_87933D0; //CameraAngleX
	float flt_87933D4; //CameraAngleY
	float flt_87933D8; //CameraAngleZ
	float flt_87933DC; //CameraPosX
	float flt_87933E0; //CameraPosY
	float flt_87933E4; //CameraPosZ
};

class MultiSelect
{
public:
	//MultiSelect();
	//virtual ~MultiSelect();
	void Load(char* path);
	void SetInfo(SelectChar info);
	void SetInfoSrv(SelectSrv lpInfo);
public:
	SelectChar RenderSelect[MAX_WORLD_SETTINGS];
	SelectSrv RenderSelectSrv[MAX_WORLD_SETTINGS];
};
extern MultiSelect gSelectCharRamdon;