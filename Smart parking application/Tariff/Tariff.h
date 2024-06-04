#pragma once
class Tariff
{
private:
	int minut;
	int cost;
public:
	Tariff(int minut, int cost);
	int get_minut();
	int get_cost();
};

