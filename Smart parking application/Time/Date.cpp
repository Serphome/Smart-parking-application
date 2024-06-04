#include "Date.h"

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

Date::Date(int day, int month, int year, int second, int minut, int hour)
{
	this->day = day;
	this->month = month;
	this->year = year;
	this->second = second;
	this->minut = minut;
	this->hour = hour;
}

Date::Date()
{
	time_t t = std::time(0);
	tm* now = localtime(&t);
	this->day = now->tm_mday;
	this->month = now->tm_mon + 1;
	this->year = now->tm_year + 1900;
	this->second = now->tm_sec;
	this->minut = now->tm_min;
	this->hour = now->tm_hour;
}

TimeSpan Date::get_substract(Date next)
{
	tm tm1 = make_tm(year, month, day, second, minut, hour);
	tm tm2 = make_tm(next.year, next.month, next.day, next.second, next.minut, next.hour);
	time_t time1 = mktime(&tm1);
	time_t time2 = mktime(&tm2);
	const int seconds_per_day = 60 * 60 * 24;
	time_t difference = (time1 - time2) / seconds_per_day;
	double portable_difference = difftime(time1, time2);
	return TimeSpan((int)portable_difference);
}

tm Date::make_tm(int year, int month, int day, int second, int minut, int hour)
{
	tm tm = { 0 };
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;
	tm.tm_sec = second;
	tm.tm_min = minut;
	tm.tm_hour = hour;
	return tm;
}
