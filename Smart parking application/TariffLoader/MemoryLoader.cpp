#include "MemoryLoader.h"

vector<Tariff> MemoryLoader::LOAD()
{
    Tariff t1(15, 0);
    Tariff t2(60, 50);
    Tariff t3(120, 100);
    Tariff t4(180, 140);
    Tariff t5(240, 180);
    Tariff t6(600, 350);
    vector<Tariff> res {t1, t2, t3, t4, t5, t6};
    return res;
}
