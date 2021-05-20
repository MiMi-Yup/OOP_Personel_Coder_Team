#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <conio.h>

#include "Personel.cpp"
#include "Manager.cpp"
#include "Programmer.cpp"
#include "Designer.cpp"
#include "Tester.cpp"

using namespace std;

int kindOfPersonel = 4;
vector<string> property = { "Manager","Programmer","Designer","Tester" };
vector<string> SubProperty = { "","Overtime","Bonus","Error" };

void displayDatabase(vector<Personel*> personels) {
	for (int i = 0; i < personels.size(); i++) {
		personels[i]->display();
	}
}
double long getPayment(vector<Personel*> personels) {
	double long result = 0.0;
	for (int i = 0; i < personels.size(); i++) {
		result += personels[i]->getSalary();
	}
	return result;
}
void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	while (clock() < startClock + secondsAhead);
	return;
}
int find(vector<Personel*> personels, int id) {
	for (int i = 0; i < personels.size(); i++) {
		if (id == personels[i]->getID()) {
			return i;
		}
	}
	return -1;
}
int find(vector<int> value, int index) {
	int temp = 0;
	for (int i = 0; i < value.size(); i++) {
		temp += value[i];
		if (index <= temp - 1)return i;
	}
}
int main() {
	vector<int> value;
	cout << "----------------------INSERT DATABASE-------------------------------\n";
	for (int i = 0; i < kindOfPersonel; i++) {
		cout << "How many " << property[i] << " in your team? ";
		int temp = 0;
		cin >> temp;
		value.push_back(temp);
	}
	{
		cout << "Please insert formation!\n";
		cout << "Form insert for Manager:    ID, Name, Birth, Address, CS, dayWork\n";
		cout << "Form insert for Programmer: ID, Name, Birth, Address, CS, dayWork, Overtime\n";
		cout << "Form insert for Designer:   ID, Name, Birth, Address, CS, dayWork, bonus\n";
		cout << "Form insert for Tester:     ID, Name, Birth, Address, CS, dayWork, Error\n";
	}
	vector<Personel*> personels;
	for (int i = 0; i < kindOfPersonel; i++) {
		for (int j = 0; j < value[i]; j++) {
			int id;
			string name, birth, address, dayWork;
			double CS;
			cin >> id;
			cin.ignore();
			getline(cin, name);
			getline(cin, birth);
			getline(cin, address);
			cin >> CS;
			cin.ignore();
			getline(cin, dayWork);
			if (i == 0) {
				personels.push_back(new Manager(id, name, birth, address, CS, dayWork));
			}
			else if (i == 1) {
				int Overtime = 0;
				cin >> Overtime;
				personels.push_back(new Progammer(id, name, birth, address, CS, dayWork, Overtime));
			}
			else if (i == 2) {
				int bonus = 0;
				cin >> bonus;
				personels.push_back(new Designer(id, name, birth, address, CS, dayWork, bonus));
			}
			else {
				int Error = 0;
				cin >> Error;
				personels.push_back(new Tester(id, name, birth, address, CS, dayWork, Error));
			}
		}
	}
	cout << "------------------------INSERT DATABASE COMPLETE----------------------\n";
	sleep(2);
	{
		char mode = 0;
		do {
			system("cls");
			cout << "1. List personel\n";
			cout << "2. Get Salary\n";
			cout << "3. Get Payment\n";
			cout << "To exit, press q\n\n";
			cout << "Mode you choose: ";
			cin >> mode;
			if (mode == '1') {
				system("cls");
				displayDatabase(personels);
				cout << "Press Enter to back";
				while (!_kbhit());
			}
			else if (mode == '2') {
				char mode;
				do {
					system("cls");
					mode = 'n';
					int id;
					cout << "Insert ID: ";
					cin >> id;
					int index = find(personels, id);
					if (index != -1) {
						cout.precision(10);
						cout << "Salary of ID " << id << " : "; cout << personels[index]->getSalary();
					}
					else cout << "\nNo found ID: " << id;
					cout << "\nContinue?(y/n) ";
					cin >> mode;
				} while (mode == 'y');
			}
			else if (mode == '3') {
				system("cls");
				cout.precision(10);
				cout << "GetPayment: " << getPayment(personels);
				cout << "\nPress Enter to back";
				while (!_kbhit());
			}
		} while (mode != 'q' && mode != 'Q');
	}
	return (0);
}