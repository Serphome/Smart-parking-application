#include"ParkingManager/ParkingManager.h"
#include"TariffLoader/MemoryLoader.h"
#include"TariffLoader/FileLoader.h"

using std::cout;
using std::cin;
using std::endl;

Date* create_date()
{
	int day, month, year, second, minut, hour;
	/*cout << "������� ����" << endl;
	cin >> day;
	cout << "������� �����" << endl;
	cin >> month;
	cout << "������� ���" << endl;
	cin >> year;*/
	day = 13;
	month = 5;
	year = 2024;
	cout << "������� �������" << endl;
	cin >> second;
	cout << "������� ������" << endl;
	cin >> minut;
	cout << "������� ���" << endl;
	cin >> hour;
	return new Date(day, month, year, second, minut, hour);
}

int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� ���������� ���� �� ��������" << endl;
	int capacity;
	cin >> capacity;
	ParkingManager* manager = new ParkingManager(capacity, new FileLoader("tarifs.txt"));
	while (true)
	{
		cout << "�������� ��������:" << endl;
		cout << "1.������� �� ��������." << endl;
		cout << "2.�������� ��������." << endl;
		cout << "3.������� � ��������." << endl;
		cout << "4.�����" << endl;
		int move;
		cin >> move;
		if (move == 1)
		{
			try
			{
				Date* data = create_date();
				string carNumber;
				cout << "������� ����� ������" << endl;
				cin >> carNumber;
				ApplicationHelper::get_instance()->set_data(data);
				ParkingSession* session = manager->enterParking(carNumber);
				if (session == nullptr)
				{
					cout << "�������� ������������, ������� ������." << endl;
				}
				else {
					cout << "���� ������ �������, ����� ������ - " << session->get_ticketNumber() << endl;
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
			cout << "������� ����� ������������ ������." << endl;
			int ticketNumber;
			cin >> ticketNumber;
			int cost = manager->GetRemainingCost(ticketNumber);
			cout << "��������� �������� - " << cost << endl;
			manager->PayForParking(ticketNumber, cost);
		}
		else if (move == 3)
		{
			try
			{
				Date* data = create_date();
				ApplicationHelper::get_instance()->set_data(data);
				cout << "������� ����� ������������ ������." << endl;
				int ticketNumber;
				cin >> ticketNumber;
				bool flag = manager->TryLeaveParkingWithTicket(ticketNumber);
				if (flag == true)
				{
					cout << "�� ������� � ��������." << endl;
				}
				else
				{
					cout << "� ��� ����� �������������, ����� ����������." << endl;
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
			cout << "����� �������� �� ����������. ���������� ������ ���������� ����� ������." << endl;
		}
	}
}