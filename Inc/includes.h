/*
 * includes.h
 *
 *  Created on: Feb 12, 2022
 *      Author: Sara
 */

#ifndef INCLUDES_H_
#define INCLUDES_H_

#include<iostream>
#include<string>
#include<ctime>
#include<list>
#include<vector>

 enum e_PROCESS_STATE
{
	e_None,
	e_Waiting_For_Ok_Response,
	e_Waiting_For_Coordinator_Response,
	e_Master

};

 enum e_MESSAGE_TYPES
{
	e_Empty,
	e_Ok,
	e_Coordinator,
	e_Election

};


#include"../Inc/process.h"
#include"../Inc/CommunicationBus.h"

using namespace std;

extern vector<CProcess*>Processes;

void TakeAction(int & iCurrentCoordinator);







#endif /* INCLUDES_H_ */
