/*
 * CommunicationBus.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Sara
 */


#include"../Inc/includes.h"

void (*CCommunicationBus::pSendingMessage)(e_MESSAGE_TYPES eData, int iFromId, int iToId) = Read;
int CCommunicationBus::m_IdMaster = -1;

void CCommunicationBus::Write(e_MESSAGE_TYPES eData, int iFromId, int iToId)
{
	if(Processes[iFromId]->m_iAlive == 1)
	{
		pSendingMessage(eData, iFromId, iToId);
	}

}

void CCommunicationBus::Read(e_MESSAGE_TYPES eData, int iFromId, int iToId)
{
	Processes[iToId]->RecieveMessage(eData, iFromId);
}
