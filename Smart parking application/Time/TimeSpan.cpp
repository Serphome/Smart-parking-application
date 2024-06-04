#include "TimeSpan.h"
TimeSpan::TimeSpan(int second)
{
	this->second = second;
}

double TimeSpan::toMinut()
{
	return (double)second / 60;
}
