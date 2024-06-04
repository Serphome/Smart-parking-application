#pragma once
#include"../Time/Date.h"
class ApplicationHelper
{
private:
	static ApplicationHelper* instance;
	Date* current;
	ApplicationHelper();
public:
	static ApplicationHelper* get_instance();
	Date* get_data();
	void set_data(Date* A);
};

