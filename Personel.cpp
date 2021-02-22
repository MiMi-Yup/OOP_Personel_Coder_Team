#pragma once
#include <iostream>
using namespace std;
class Personel {
private:
	int id = -1, BS = 2150000;
	string name, birth, address, dayWork;
	double CS = 0;
public:
	Personel() {}
	Personel(int id, string name, string birth, string address, double CS, string dayWork) {
		this->name = name;
		this->birth = birth;
		this->address = address;
		this->dayWork = dayWork;
		if (id >= 0 && CS >= 0) {
			this->id = id;
			this->CS = CS;
		}
		else cout << "Insert invalid!\n";
	}
	void setName(string name) {
		this->name = name;
	}
	void setBirth(string birth) {
		this->birth = birth;
	}
	void setAddress(string address) {
		this->address = address;
	}
	void setDayWork(string dayWork) {
		this->dayWork = dayWork;
	}
	void setCS(double CS) {
		this->CS = CS;
	}
	int getBS() {
		return this->BS;
	}
	int getID() {
		return this->id;
	}
	string getName() {
		return this->name;
	}
	string getBirth() {
		return this->birth;
	}
	string getAddress() {
		return this->address;
	}
	string getDayWork() {
		return this->dayWork;
	}
	double getCS() {
		return this->CS;
	}
	virtual double getSalary() = 0;
	virtual void display() {
		cout.precision(10);
		cout << "ID: " << this->id << "\n";
		cout << "Name: " << this->name << "\n";
		cout << "Birth: " << this->birth << "\n"; 
		cout << "Address: " << this->address << "\n";
		cout << "He so luong: " << this->CS << "\n";
		cout << "Ngay bat dau lam: " << this->dayWork << "\n";
	}
};