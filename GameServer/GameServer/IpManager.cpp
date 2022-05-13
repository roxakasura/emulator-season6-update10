// IpManager.cpp: implementation of the CIpManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IpManager.h"
#include "ServerInfo.h"
#include "Log.h"
#include "Util.h"

CIpManager gIpManager;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIpManager::CIpManager() // OK
{

}

CIpManager::~CIpManager() // OK
{

}

bool CIpManager::CheckIpAddress(char* IpAddress) // OK
{
	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));


	if(it == this->m_IpAddressInfo.end())
	{
		return ((gServerInfo.m_MaxIpConnection==0)?0:1);
	}
	//guarda o tempo entre cada conexão recebida
	if(it->second.IpTime != 0)
	{
		it->second.IpTime2 = it->second.IpTime;
		it->second.IpTime = GetTickCount();
	}
	//bloqueia se você receber 2 conexões em menos de 0.5 segundos, com sede de sangue
	if(abs((int)((it->second.IpTime - it->second.IpTime2)) < 500))
	{
		it->second.IpBlocked = 1;
		it->second.IpBlockedTime = GetTickCount();
		gLog.Output(LOG_HACK,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		LogAdd(LOG_RED,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		return 0;
	}	
	//função para desbanir o ip
	if(it->second.IpBlockedTime != 0 && abs((int)((GetTickCount()-it->second.IpBlockedTime))) > 600000) // 600000 tiempo de bloqueo del ip
	{
		gLog.Output(LOG_HACK,"IP IS UNBAN: %s", IpAddress);
		LogAdd(LOG_RED,"IP IS UNBAN: %s", IpAddress);
		it->second.IpBlocked = 0;
		it->second.IpBlockedTime = 0;
	}
	//função para rejeitar ip bloqueado
	if(it->second.IpBlocked > 0)
	{
		return 0;
	}
	//Detecta se você recebeu mais de X tentativas de conexão que já excederam o limite de conexão máxima em menos de 1 minuto.
	if(it->second.IpFloodAttemps > 0 && (abs((int)((GetTickCount()-it->second.IpFloodLastTime))) < 60000))
	{
		it->second.IpBlocked = 1;
		it->second.IpBlockedTime = GetTickCount();
		gLog.Output(LOG_HACK,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		LogAdd(LOG_RED,"FLOOD ATTEMPT DETECTED - BAN IP: %s", IpAddress);
		return 0;
	}	
	else
	{
		if(it->second.IpAddressCount>=gServerInfo.m_MaxIpConnection)
		{
			//guarda tentativas de conexão superando maxipconnection
			it->second.IpFloodAttemps++;
			it->second.IpFloodLastTime = GetTickCount();
			return 0;
		}
		return 1;
	}

}

void CIpManager::InsertIpAddress(char* IpAddress) // OK
{
	IP_ADDRESS_INFO info;

	strcpy_s(info.IpAddress,IpAddress);

	info.IpAddressCount = 1;
	info.IpFloodAttemps = 0;
	info.IpBlocked = 0;
	info.IpTime = GetTickCount();
	info.IpBlockedTime = 0;
	info.IpFloodLastTime = 0;
	info.IpTime2 = 0;

	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));

	if(it == this->m_IpAddressInfo.end())
	{
		this->m_IpAddressInfo.insert(std::pair<std::string,IP_ADDRESS_INFO>(std::string(IpAddress),info));
	}
	else
	{
		it->second.IpAddressCount++;
	}
}

void CIpManager::RemoveIpAddress(char* IpAddress) // OK
{
	std::map<std::string,IP_ADDRESS_INFO>::iterator it = this->m_IpAddressInfo.find(std::string(IpAddress));

	if(it != this->m_IpAddressInfo.end())
	{
		//solo borra la ip si no se encuentra bloqueada.
		if((--it->second.IpAddressCount) == 0 && it->second.IpBlocked == 0)
		{
			this->m_IpAddressInfo.erase(it);
		}
	}
}
