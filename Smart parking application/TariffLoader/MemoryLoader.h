#pragma once
#include"TariffLoader.h"
class MemoryLoader: public TariffLoader
{
public:
	vector<Tariff> LOAD() override;
};

