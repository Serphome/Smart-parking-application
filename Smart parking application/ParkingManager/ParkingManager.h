#pragma once
#include"../ParkingSession/ParkingSession.h"
#include"../Tariff/Tariff.h"
#include"../TariffLoader/TariffLoader.h"
#include"../Singleton/ApplicationHelper.h"
#include<iostream>
#include<vector>

using std::vector;
using std::exception;

class ParkingManager
{
private:
	int capacity;
	vector<ParkingSession*> activeSession;
	vector<ParkingSession*> endedSession;
	vector<Tariff> tariff;
public:
	ParkingManager(int capacity, TariffLoader* loader);
	int generateTicket();
	ParkingSession* enterParking(string carNumber);
	bool check_car(string carNumber);
	bool TryLeaveParkingWithTicket(int ticketNumber);
	int searchFreeTariff();
	int findSession(int ticketNumber);
	int GetRemainingCost(int ticketNumber);
	double timeAfterPay(int index);
	void PayForParking(int ticketNumber, int amount);
};

