#include "stdafx.h"
#include "Protocol.h"
#include "FlyingDragons.h"
#include "Util.h"
#include "Map.h"

cDragonMaps gDragonMaps;

void cDragonMaps::DeleteFlyingDragons () //Dragones verificar si alguno no se finalizó
{
	for (int n=0; n<MAX_MAP; n++){
		if (mapasDragones[n].EndTime<=time(0))
		{
			if (mapasDragones[n].index==1 || mapasDragones[n].index==3)
			{
				mapasDragones[n].Ok=0;
				mapasDragones[n].index=-1;
				//GCEventStateSendToAll(n, 0, 1);
				//GCEventStateSendToAll(n, 0, 3);
			}
		}
	}
}

void cDragonMaps::AddFlyingDragons(int mapa, int invasionTime, int index) //Dragones agregar al mapa y setearlos
{
	if (mapa == MAP_ATLANS) return; //Agregar esto si quieren que no salgan en Atlans

	if (mapasDragones[mapa].Ok==1 && mapasDragones[mapa].index==index)
	{
		if (mapasDragones[mapa].EndTime<(time(0)+invasionTime))
		{
			mapasDragones[mapa].EndTime=(time(0)+invasionTime);
		}
	} 
	else 
	{
		mapasDragones[mapa].Ok=1;
		mapasDragones[mapa].index=index;
		mapasDragones[mapa].EndTime=(time(0)+invasionTime);
	}
	//GCEventStateSendToAll(mapa, 1, index); //Dragones meter al iniciar una invasión
}

void cDragonMaps::FlyingDragonsBossDieProc(int mapa) //Quitar dragones al matar al boss
{
	for (int n=0; n<MAX_MAP; n++)
	{
		if (mapasDragones[n].index==mapasDragones[mapa].index)
		{
			mapasDragones[n].Ok=0;
			mapasDragones[n].index=-1;
			//Al hacerlo de esta manera, se soluciona cuando finaliza la invasión
			//GCEventStateSendToAll(n, 0, 1);
			//GCEventStateSendToAll(n, 0, 3);
		}
	}
}

void cDragonMaps::FlyingDragonsCheck(int mapa, int index) //Dragones verificar mapa para insertar
{
	return;
}