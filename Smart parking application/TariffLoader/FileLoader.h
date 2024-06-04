#pragma once
#include"TariffLoader.h"
#include<fstream>

using std::string;
using std::ifstream;

class FileLoader: public TariffLoader
{
private:
	string fileName;
public:
	FileLoader(string fileName);
	vector<Tariff> LOAD() override;
};

