/*
 * main.cpp
 *
 *  Created on: Feb 12, 2022
 *      Author: Sara
 */
#include"../Inc/includes.h"

vector<CProcess*>Processes;
int n = 5;

int main()
{

	for(int i = 0; i < n; ++i)
	{

		Processes.push_back(new CProcess());

	}

	//freopen("output.txt", "w", stdout);

	while(true)
	{
		int & iCurrentCoordinator = CCommunicationBus::m_IdMaster;

		for(int i = 0; i < n; ++i)
		{
			if(Processes[i]->m_iAlive == 1)
			{
				Processes[i]->CheckBusUpdates();
			}
		}

		if(iCurrentCoordinator != -1 && Processes[iCurrentCoordinator]->m_iAlive == 1)
		{
			Processes[iCurrentCoordinator]->SendCoordinatorMessage();
		}

		TakeAction(iCurrentCoordinator);


	}

	return 0;
}

void TakeAction(int  & iCurrentCoordinator)
{
	char cSelect;

	cout << "\n";
	if(iCurrentCoordinator != -1)
	{
		cout << "Shut Down Current Coordinator ID "<< iCurrentCoordinator << ": " << "Press Y/y" << "\n";
		cout << "Bring Up Dead Process : Enter Its ID" <<"\n";
		cout << "No : Press Any letter " << "\n";
	}
	else
	{
		cout << "Press Any letter " << "\n";
	}


	cin>>cSelect;

	if(cSelect == 'Y' || cSelect == 'y')
	{
		if(iCurrentCoordinator != -1)
		{
			Processes[iCurrentCoordinator]->m_iAlive = 0;
			iCurrentCoordinator = -1;
		}

	}
	else if(cSelect >= '0' && cSelect-'0' < n)
	{
		Processes[cSelect-'0']->m_iAlive = 1;
		Processes[cSelect-'0']->m_eProcessState = e_None;
	}

	cout << "ShutDownCoordinator():current coordinator "<<iCurrentCoordinator << "\n" << "\n";


}

