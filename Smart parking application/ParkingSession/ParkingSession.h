#pragma once
#include"../Time/Date.h"
#include<string>

using std::string;

class ParkingSession
{
private:
	Date* entry;
	Date* exit;
	Date* pay;
	int cost;
	int ticketNumber;
	string carNumber;
public:
	ParkingSession(Date* entry, int ticketNumber, string carNumber);
	Date* get_entry();
	Date* get_exit();
	void set_exit(Date* temp);
	Date* get_pay();
	void set_pay(Date* temp);
	int get_cost();
	void set_cost(int temp);
	int get_ticketNumber();
	string get_carNumber();
};

