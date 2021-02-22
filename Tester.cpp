#include "Personel.cpp"
using namespace std;
class Tester :public Personel {
private:
	int Error = 0;
	const int ErrorUnit = 200000;
public:
	Tester(){}
	Tester(int id, string name, string birth, string address, double CS, string dayWork, int Error) :Personel(id, name, birth, address, CS, dayWork) {
		if (Error >= 0) {
			this->Error = Error;
		}
		else cout << "Error found invaild!\n";
	}
	void setError(int Error) {
		if (Error >= 0) {
			this->Error = Error;
		}
		else cout << "Error found invaild!\n";
	}
	int getError() {
		return this->Error;
	}
	int getErrorSalary() {
		return this->ErrorUnit * this->Error;
	}
	double getSalary() {
		return getCS() * getBS() + getErrorSalary();
	}
	void display() {
		cout << "Tester: \n";
		Personel::display();
		cout << "Error Found: " << this->Error << "\n";
		cout << "Salary: " << getSalary() << "\n\n";
	}
};