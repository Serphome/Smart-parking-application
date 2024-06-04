#include "Tariff.h"

Tariff::Tariff(int minut, int cost)
{
	this->minut = minut;
	this->cost = cost;
}

int Tariff::get_minut()
{
	return minut;
}

int Tariff::get_cost()
{
	return cost;
}
