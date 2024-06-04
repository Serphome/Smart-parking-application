#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<iostream>
#include"TimeSpan.h"

using std::tm;

class Date
{
private:
	int day, month, year;
	int second, minut, hour;
public:
	Date(int day, int month, int year);
	Date(int day, int month, int year, int second, int minut, int hour);
	Date();
	TimeSpan get_substract(Date next);
	tm make_tm(int year, int month, int day, int second, int minut, int hour);
};