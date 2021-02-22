#include "Personel.cpp"
using namespace std;
class Designer :public Personel {
private:
	int bonus = 0;
public:
	Designer() {}
	Designer(int id, string name, string birth, string address, double CS, string dayWork, int bonus) :Personel(id, name, birth, address, CS, dayWork) {
		if (bonus >= 0) {
			this->bonus = bonus;
		}
		else cout << "Bonus invalid!\n";
	}
	void setBonus(int bonus) {
		if (bonus >= 0) {
			this->bonus = bonus;
		}
		else cout << "Bonus invalid!\n";	
	}
	int getBonus() {
		return this->bonus;
	}
	double getSalary() {
		return getCS() * getBS() + bonus;
	}
	void display() {
		cout << "Designer: \n";
		Personel::display();
		cout << "Bonus: " << this->bonus << "\n";
		cout << "Salary: " << getSalary() << "\n\n";
	}
};