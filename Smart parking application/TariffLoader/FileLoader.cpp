#include "FileLoader.h"

FileLoader::FileLoader(string fileName)
{
    this->fileName = fileName;
}

vector<Tariff> FileLoader::LOAD()
{
    ifstream file(fileName);
    vector<Tariff> res;
    while (!file.eof())
    {
        int cost, minut;
        file >> minut >> cost;
        Tariff t(minut, cost);
        res.push_back(t);
    }
    file.close();
    return res;
}