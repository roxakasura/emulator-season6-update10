#define pWzAudioPlay  ((void(__cdecl*)(PCHAR MusicId,int Arg2))0x004CF050)
#define pWzAudioStop  ((void(__cdecl*)(PCHAR MusicId,int Arg2))0x004CF000)
#define pLoadGameStuffs  ((void(__cdecl*)(HDC Arg1))0x004D9CF0)

class CCustomMap
{
public:
	// ----
	//void	Init();
	//void	ReadList(char * File);
	void	Load();
	//void	LoadMaps();
	// ----
}; extern CCustomMap gCustomMap;