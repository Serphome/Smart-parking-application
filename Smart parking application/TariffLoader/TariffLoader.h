#pragma once
#include<vector>
#include"../Tariff/Tariff.h"

using std::vector;

class TariffLoader
{
public:
	virtual vector<Tariff> LOAD() = 0;
};

