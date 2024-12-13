/*
 * process.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Sara
 */

#include"../Inc/includes.h"

int CProcess::iCnt = 0;

CProcess::CProcess()
{
	m_iProcessId = iCnt;
	++iCnt;

	m_iAlive = 1;
	m_iStartTime = time(0);
	m_eProcessState = e_None;

	pWritingOnBus = CCommunicationBus::Write;

}

void CProcess::CheckBusUpdates()
{

	int iCurrentTime = time(0);

	if(iCurrentTime - m_iStartTime > 1)
	{
		if(CheckCoordinatorControl())return;

		cout << "Time Interval For Process Id " << m_iProcessId << " : " <<iCurrentTime - m_iStartTime<< "\n";
		switch(m_eProcessState)
		{
		case e_None:

			SendElectionMessage();
			break;
		case e_Waiting_For_Ok_Response:
		case e_Waiting_For_Coordinator_Response:

			SendCoordinatorMessage();
			break;
		}
	}

}

bool CProcess::CheckCoordinatorControl()
{

	if(m_eMessageType == e_Coordinator)
	{
		m_iStartTime = time(0);
		m_eMessageType = e_Empty;
		return true;
	}


	return false;
}

void CProcess::SendElectionMessage()
{
	m_eProcessState = e_Waiting_For_Ok_Response;

	for(int i = m_iProcessId+1; i < (int)Processes.size(); ++i)
	{
		pWritingOnBus(e_Election, m_iProcessId, i);
	}

}

void CProcess::SendCoordinatorMessage()
{
	m_eProcessState = e_Master;

	CCommunicationBus::m_IdMaster = m_iProcessId;

	for(int i = m_iProcessId-1; i >= 0; --i)
	{
		pWritingOnBus(e_Coordinator, m_iProcessId, i);
	}

}

void CProcess::SendOkResponseMessage(int iIdTo)
{
	pWritingOnBus(e_Ok, m_iProcessId, iIdTo);

}


void CProcess::RecieveMessage(e_MESSAGE_TYPES eMessageType, int iIdFrom)
{
	m_eMessageType = eMessageType;

	HandleRecievedMessage(iIdFrom);
}

void CProcess::HandleRecievedMessage(int iIdFrom)
{
	switch(m_eMessageType)
	{
	case e_Election:

		cout<< "election from Process ID " << iIdFrom << " to " << m_iProcessId << "\n";
		Processes[iIdFrom]->m_eProcessState = e_Waiting_For_Ok_Response;
		m_iStartTime = time(0);
		SendOkResponseMessage(iIdFrom);
		break;
	case e_Ok:

		cout<< "OK from Process ID " << iIdFrom << " to " << m_iProcessId << "\n";
		m_eProcessState = e_Waiting_For_Coordinator_Response;
		m_iStartTime = time(0);
		break;
	case e_Coordinator:

		cout<< "coordinator from Process ID " << iIdFrom << " to " << m_iProcessId << "\n";
		m_eProcessState = e_None;
		m_iStartTime = time(0);
		break;

	}

}

