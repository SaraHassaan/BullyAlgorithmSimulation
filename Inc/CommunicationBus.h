/*
 * CommunicationBus.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Sara
 */

#ifndef COMMUNICATIONBUS_H_
#define COMMUNICATIONBUS_H_

#include"../Inc/includes.h"

class CCommunicationBus
{
public:

	/***Members***/
	static int m_IdMaster;
	static void (*pSendingMessage)(e_MESSAGE_TYPES eData, int iFromId, int iToId);

	/***Methods****/
	static void Write(e_MESSAGE_TYPES eData, int iFromId, int iToId);
	static void Read(e_MESSAGE_TYPES eData, int iFromId, int iToId);

};

#endif /* COMMUNICATIONBUS_H_ */
