#include <iostream>
#include <cstring>
#include "Header.h"
#pragma warning(disable : 4996)

using namespace std;

struct Worker
{
	char* surname;
	char* name;
	char* number;
	double salary;
};

bool isValidNumber(const char* number) 
{
	for (int i = 0; number[i] != '\0'; i++)
	{
		if (number[i]<'0' || number[i]>'9')
		{
			return false;
		}
	}
	return true;
}

void addWorker(Worker& worker)
{
	char* surname = new char[255];
	cout << "Enter surname: ";
	cin >> surname;
	int size1 = strlen(surname);
	worker.surname = new char[size1 + 1];
	strcpy(worker.surname, surname);

	char* name = new char[255];
	cout << "Enter name: ";
	cin >> name;
	int size2 = strlen(name);
	worker.name = new char[size2 + 1];
	strcpy(worker.name, name);

	char* number = new char[255];
	cout << "Enter number in format 0000000000: ";
	cin >> number;

	while (!isValidNumber(number))
	{
		cout << "Invalid number. Enter number in format 0000000000: ";
		cin >> number;

	}

	int size3 = strlen(number);
	worker.number = new char[size3 + 1];
	strcpy(worker.number, number);

	cout << "Enter salary: ";
	cin >> worker.salary;

	delete[] surname;
	delete[] name;
	delete[] number;
}

void showWorker(Worker& worker)
{
	cout << "Surname: " << worker.surname << endl;
	cout << "Name: " << worker.name << endl;
	cout << "Number: " << worker.number << endl;
	cout << "Salary: " << worker.salary << endl;
}

void deleteWorker(Worker* listWorker, int& sum)
{
	char surname[225];
	char name[225];

	cout << "Enter worker that you want to delete: " << endl;
	cout << "Surname: ";
	cin >> surname;
	cout << "Name: ";
	cin >> name;

	for (int i = 0; i < sum; i++)
	{
		if (strcmp(listWorker[i].surname, surname) == 0 && strcmp(listWorker[i].name, name) == 0)
		{
			delete[] listWorker[i].surname;
			delete[] listWorker[i].name;
			delete[] listWorker[i].number;
			for (int j = i; j < sum - 1; j++)
			{
				listWorker[j] = listWorker[j + 1];
			}
			--sum;
			cout << "Worker delete." << endl;
			return;
		}
	}
	cout << "Worker not found." << endl;
}

void showAllWorkers(Worker* listWorker, int sum)
{
	for (int i = 0; i < sum; i++)
	{
		cout << "Worker " << i + 1 << ":" << endl;
		showWorker(listWorker[i]);
	}
}

Worker* searchBySurname(Worker* listWorker, int sum, char* findSurname)
{
	for (int i = 0; i < sum; i++)
	{
		if (strcmp(findSurname, listWorker[i].surname) == 0)
		{
			return &listWorker[i];
		}
	}
	return nullptr;
}

Worker* searchBySalary(Worker* listWorker, int sum)
{
	double salary;
	cout << "Enter salary to search: ";
	cin >> salary;

	bool found = false;
	for (int i = 0; i < sum; i++)
	{
		if (listWorker[i].salary == salary)
		{
			showWorker(listWorker[i]);
			found = true;
			return &listWorker[i];
		}
	}
	if (!found)
	{
		cout << "No worker found with salary " << salary << "." << endl;
	}
}

void sortBySurname(Worker* listWorker, int sum)
{
	for (int i = 0; i < sum - 1; i++)
	{
		for (int j = 0; j < sum - i - 1; j++)
		{
			if (strcmp(listWorker[j].surname, listWorker[j + 1].surname)>0)
			{
				Worker temp = listWorker[j];
				listWorker[j] = listWorker[j + 1];
				listWorker[j + 1] = temp;
			}
		}
	}
	showAllWorkers(listWorker, sum);
}

void writeToFile(Worker* listWorker, int sum) 
{
	const char* PATH_TO_FILE = "workers.txt";
	FILE* file = fopen(PATH_TO_FILE, "w");

	if (file != nullptr) 
	{
		for (int i = 0; i < sum; i++)
		{
			fprintf(file, "Surname: %s\n", listWorker[i].surname);
			fprintf(file, "Name: %s\n", listWorker[i].name);
			fprintf(file, "Number: %s\n", listWorker[i].number);
			fprintf(file, "Salary: %.2f\n", listWorker[i].salary);
			fprintf(file, "-----------------\n");
		}
		fclose(file);
		cout << "Information has been written to the file." << endl;
	}
	else 
	{
		cout << "Error opening file!" << endl;
	}
}


void readFromFile()
{
	const char* PATH_TO_FILE = "workers.txt";
	FILE* file = fopen(PATH_TO_FILE, "r");

	if (file != nullptr)
	{
		char buffer[255];

		while (fgets(buffer, sizeof(buffer), file) != nullptr)
		{
			cout << buffer;  
		}

		fclose(file);
		cout << "Information has been read from the file." << endl;
	}
	else
	{
		cout << "Error opening file!" << endl;
	}
}