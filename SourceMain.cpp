#include <iostream>
#include <cstring>
#include "Header.h"
#define INTEGER
#pragma warning(disable : 4996)

using namespace std;

struct Worker
{
	char* surname;
	char* name;
	char* number;
	double salary;
};

int main()
{
	cout << "How many workers do you want to add: ";
	int sum;
	cin >> sum;

	Worker* listWorker = new Worker[sum];

	for (int i = 0; i < sum; i++)
	{
		cout << "Enter worker " << i + 1 << ":" << endl;
		addWorker(listWorker[i]);
	}

	const int maxSize = 100;

	while (true)
	{
		cout << "Options: " << endl;
		cout << "1. Add new worker." << endl;
		cout << "2. Delete worker." << endl;
		cout << "3. Show all workers." << endl;
		cout << "4. Search by surname." << endl;
		cout << "5. Search by salary." << endl;
		cout << "6. Sort by surname." << endl;
		cout << "7. Write information to file." << endl;
		cout << "8. Read information from file." << endl;
		cout << "9. Exit." << endl;
		cout << "Choose option: ";

		int option;
		cin >> option;

		switch (option)
		{
		case 1:
		{
			if (sum < maxSize)
			{
				Worker* temp = new Worker[sum + 1];
				for (int i = 0; i < sum; i++)
				{
					temp[i] = listWorker[i];
				}
				delete[] listWorker;
				listWorker = temp;
				cout << "Enter new worker:" << endl;
				addWorker(listWorker[sum]);
				++sum;
			}
			else
			{
				cout << "Max size of workers." << endl;
			}
		}
		break;
		case 2:
			deleteWorker(listWorker, sum);
			break;
		case 3:
			showAllWorkers(listWorker, sum);
			break;
		case 4:
		{
			char findSurname[225];
			cout << "Enter surname for search: ";
			cin >> findSurname;
			Worker* worker = searchBySurname(listWorker, sum, findSurname);
			if (worker != nullptr)
			{
				showWorker(*worker);
			}
			else
			{
				cout << "Worker not found." << endl;
			}
		}
		break;
		case 5:
			searchBySalary(listWorker, sum);
			break;
		case 6:
			cout << "Sorted by surname: " << endl;
			sortBySurname(listWorker, sum);
			break;
		case 7:
			writeToFile(listWorker, sum);
			break;
		case 8:
			readFromFile();
			break;
		case 9:
		{


			cout << "Exiting program." << endl;
			for (int i = 0; i < sum; i++)
			{
				delete[] listWorker[i].surname;
				delete[] listWorker[i].name;
				delete[] listWorker[i].number;
			}
			delete[] listWorker;
			return 0;
		}
		default:
			cout << "Invalid option. Please try again." << endl;
			break;

		}
	}
	return 0;
}