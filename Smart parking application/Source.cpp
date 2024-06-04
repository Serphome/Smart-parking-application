#include"ParkingManager/ParkingManager.h"
#include"TariffLoader/MemoryLoader.h"
#include"TariffLoader/FileLoader.h"

using std::cout;
using std::cin;
using std::endl;

Date* create_date()
{
	int day, month, year, second, minut, hour;
	/*cout << "Введите день" << endl;
	cin >> day;
	cout << "Введите месяц" << endl;
	cin >> month;
	cout << "Введите год" << endl;
	cin >> year;*/
	day = 13;
	month = 5;
	year = 2024;
	cout << "Введите секунды" << endl;
	cin >> second;
	cout << "Введите минуты" << endl;
	cin >> minut;
	cout << "Введите час" << endl;
	cin >> hour;
	return new Date(day, month, year, second, minut, hour);
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Введите количество мест на парковке" << endl;
	int capacity;
	cin >> capacity;
	ParkingManager* manager = new ParkingManager(capacity, new FileLoader("tarifs.txt"));
	while (true)
	{
		cout << "Выберите действие:" << endl;
		cout << "1.Въехать на парковку." << endl;
		cout << "2.Оплатить парковку." << endl;
		cout << "3.Выехать с парковки." << endl;
		cout << "4.Выйти" << endl;
		int move;
		cin >> move;
		if (move == 1)
		{
			try
			{
				Date* data = create_date();
				string carNumber;
				cout << "Введите номер машины" << endl;
				cin >> carNumber;
				ApplicationHelper::get_instance()->set_data(data);
				ParkingSession* session = manager->enterParking(carNumber);
				if (session == nullptr)
				{
					cout << "Парковка переполненна, заехать нельзя." << endl;
				}
				else {
					cout << "Ваша машина въехала, номер билеты - " << session->get_ticketNumber() << endl;
				}
			}
			catch (const std::exception& warning)
			{
				cout << warning.what() << endl;
			}
		}
		else if (move == 2)
		{
			Date* data = create_date();
			ApplicationHelper::get_instance()->set_data(data);
			cout << "Введите номер парковочного билета." << endl;
			int ticketNumber;
			cin >> ticketNumber;
			int cost = manager->GetRemainingCost(ticketNumber);
			cout << "Стоимость парковки - " << cost << endl;
			manager->PayForParking(ticketNumber, cost);
		}
		else if (move == 3)
		{
			try
			{
				Date* data = create_date();
				ApplicationHelper::get_instance()->set_data(data);
				cout << "Введите номер парковочного билета." << endl;
				int ticketNumber;
				cin >> ticketNumber;
				bool flag = manager->TryLeaveParkingWithTicket(ticketNumber);
				if (flag == true)
				{
					cout << "Вы выехали с парковки." << endl;
				}
				else
				{
					cout << "У вас висит задолженность, выезд невозможен." << endl;
				}
			}
			catch (const std::exception& warning)
			{
				cout << warning.what() << endl;
			}
		}
		else if (move == 4)
		{
			break;
		}
		else
		{
			cout << "Такой операции не существует. Попробуйте ввести правильный номер услуги." << endl;
		}
	}
}