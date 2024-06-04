#include "ParkingManager.h"

ParkingManager::ParkingManager(int capacity, TariffLoader* loader)
{
	this->capacity = capacity;
	tariff = loader->LOAD();
}

int ParkingManager::generateTicket()
{
	int ticketNumber = 0;
	for (ParkingSession* data : activeSession)
	{
		if (data->get_ticketNumber() > ticketNumber)
		{
			ticketNumber = data->get_ticketNumber();
		}
	}
	return ticketNumber + 1;
}

ParkingSession* ParkingManager::enterParking(string carNumber)
{
	int ticketNumber = generateTicket();
	if (check_car(carNumber))
	{
		throw exception("This car staying on the parking right now.");
	}
	if (activeSession.size() == capacity)
	{
		return nullptr;
	}
	Date* now = ApplicationHelper::get_instance()->get_data();
	ParkingSession* data = new ParkingSession(now, ticketNumber, carNumber);
	activeSession.push_back(data);
	return data;
}

bool ParkingManager::check_car(string carNumber)
{
	for (ParkingSession* A : activeSession)
	{
		if (A->get_carNumber() == carNumber)
		{
			return true;
		}
	}
	return false;
}

bool ParkingManager::TryLeaveParkingWithTicket(int ticketNumber)
{
	int temp = findSession(ticketNumber);
	if (temp == -1)
	{
		throw exception("Car doesn't exist on the parking");
	}
	double minut1 = timeAfterPay(temp);
	int minTime = searchFreeTariff();
	if (minut1 > minTime)
	{
		return false;
	}
	else
	{
		Date* time_current = ApplicationHelper::get_instance()->get_data();
		activeSession[temp]->set_exit(time_current);
		endedSession.push_back(activeSession[temp]);
		activeSession.erase(activeSession.begin() + temp);
		return true;
	}
}

int ParkingManager::searchFreeTariff()
{
	for (Tariff A : tariff)
	{
		if (A.get_cost() == 0)
		{
			return A.get_minut();
		}
	}
	return 5;
}

int ParkingManager::findSession(int ticketNumber)
{
	for (int i = 0; i < activeSession.size(); i++)
	{
		if (activeSession[i]->get_ticketNumber() == ticketNumber)
		{
			return i;
		}
	}
	return -1;
}

int ParkingManager::GetRemainingCost(int ticketNumber)
{
	int temp = findSession(ticketNumber);
	if (temp == -1)
	{
		throw exception("Car doesn't exist on the parking");
	}
	double minut = timeAfterPay(temp);
	for (Tariff A : tariff)
	{
		if (A.get_minut() >= minut)
		{
			return A.get_cost();
		}
	}
	return tariff.back().get_cost();
}

double ParkingManager::timeAfterPay(int index)
{
	double minut1 = 0;
	Date* time_current = ApplicationHelper::get_instance()->get_data();
	if (activeSession[index]->get_pay() != nullptr)
	{
		Date* time_pay = activeSession[index]->get_pay();
		TimeSpan difference = time_current->get_substract(*time_pay);
		minut1 = difference.toMinut();
	}
	else
	{
		Date* time_entry = activeSession[index]->get_entry();
		TimeSpan difference = time_current->get_substract(*time_entry);
		minut1 = difference.toMinut();
	}
	return minut1;
}

void ParkingManager::PayForParking(int ticketNumber, int amount)
{
	int temp = findSession(ticketNumber);
	Date* time_current = ApplicationHelper::get_instance()->get_data();
	activeSession[temp]->set_cost(amount);
	activeSession[temp]->set_pay(time_current);
}
