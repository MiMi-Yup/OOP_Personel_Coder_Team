#include "Personel.cpp"
using namespace std;
class Progammer :public Personel {
private:
	int Overtime = 0;
public:
	Progammer() {}
	Progammer(int id, string name, string birth, string address, double CS, string dayWork, int Overtime) :Personel(id, name, birth, address, CS, dayWork) {
		this->Overtime = Overtime;
	}
	void setOvertime(int Overtime) {
		if (Overtime >= 0) {
			this->Overtime = Overtime;
		}
		else cout << "Overtime invalid!";
	}
	int getOvertime() {
		return this->Overtime;
	}
	double getSalary() {
		return getCS() * getBS() + this->Overtime;
	}
	void display() {
		cout << "Programmer: \n";
		Personel::display();
		cout << "Overtime: " << this->Overtime << "\n";
		cout << "Salary: " << getSalary() << "\n\n";
	}
};