#include "ApplicationHelper.h"

ApplicationHelper* ApplicationHelper::instance = nullptr;

ApplicationHelper::ApplicationHelper()
{
    instance = nullptr;
    current = nullptr;
}

ApplicationHelper* ApplicationHelper::get_instance()
{
    if (instance == nullptr)
    {
        instance = new ApplicationHelper();
    }
    return instance;
}

Date* ApplicationHelper::get_data()
{
    if (current != nullptr)
    {
        return current;
    }
    return new Date();
}

void ApplicationHelper::set_data(Date* A)
{
    current = A;
}
