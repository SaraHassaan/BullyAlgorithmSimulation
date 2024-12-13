/*
 * process.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Sara
 */
#include"../Inc/includes.h"

#ifndef PROCESS_H_
#define PROCESS_H_

class CProcess
{
	/**Private Members***/
	int m_iProcessId;
	int m_iStartTime;
	e_MESSAGE_TYPES m_eMessageType;
	void(*pWritingOnBus)(e_MESSAGE_TYPES e_MessageType, int iFromId, int iToId);
	static int iCnt;

public:

	int m_iAlive;
	e_PROCESS_STATE m_eProcessState;

	/**Public Methods**/
public:

	CProcess();
	void CheckBusUpdates();
	void SendCoordinatorMessage();
	void RecieveMessage(e_MESSAGE_TYPES eMessageType, int iIdFrom);

	/**Private Methods**/
private:

	bool CheckCoordinatorControl();
	void SendElectionMessage();
	void SendOkResponseMessage(int iIdTo);

	void HandleRecievedMessage(int iIdFrom);

};



#endif /* PROCESS_H_ */
