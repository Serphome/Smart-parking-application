#include "ParkingSession.h"
ParkingSession::ParkingSession(Date* entry, int ticketNumber, string carNumber)
{
	this->entry = entry;
	this->ticketNumber = ticketNumber;
	this->carNumber = carNumber;
	cost = 0;
	exit = nullptr;
	pay = nullptr;
}

Date* ParkingSession::get_entry()
{
	return entry;
}

Date* ParkingSession::get_exit()
{
	return exit;
}

void ParkingSession::set_exit(Date* temp)
{
	exit = temp;
}

Date* ParkingSession::get_pay()
{
	return pay;
}

void ParkingSession::set_pay(Date* temp)
{
	pay = temp;
}

int ParkingSession::get_cost()
{
	return cost;
}

void ParkingSession::set_cost(int temp)
{
	cost = temp;
}

int ParkingSession::get_ticketNumber()
{
	return ticketNumber;
}

string ParkingSession::get_carNumber()
{
	return carNumber;
}
