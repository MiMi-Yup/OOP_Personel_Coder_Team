#include "Personel.cpp"
#include <vector>
using namespace std;
class Manager :public Personel {
private:
	vector<Personel*> Junior;
public:
	Manager(){}
	Manager(int id, string name, string birth, string address, double CS, string dayWork) :Personel(id, name, birth, address, CS, dayWork) {}
	double getSalary() {
		return getCS() * getBS();
	}
	void setJuniorOfPersonel(Personel* personel) {
		this->Junior.push_back(personel);
	}
	void display() {
		cout << "Manager: \n";
		Personel::display();
		cout << "Salary: " << getSalary() << "\n\n";
	}
};