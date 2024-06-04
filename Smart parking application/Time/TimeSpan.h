#pragma once
class TimeSpan
{
private:
	int second;
public:
	TimeSpan(int second);
	double toMinut();
};