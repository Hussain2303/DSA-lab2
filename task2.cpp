#include<iostream>
#include<string.h>
using namespace std;
class employee{
public:
	void virtual calculate_salary() = 0;
};
class full_time_employee :public employee{
	int salary;
public:
	full_time_employee(int s = 0) :salary(s){}
	void calculate_salary() override{
		cout << "Salary Of a full time Employee is" << salary << endl;
	}
	
};
class part_time_employee :public employee{
	int hours;
	int rate;
public:
	part_time_employee(int h = 0, int r = 0) :hours(h), rate(r){}
	void calculate_salary() override {
		cout << "Salary of a part time employee is" << hours*rate << endl;
	}
};


int main()
{
	employee* employee1;
	employee *employee2;
	int salary, hours, rate ,key;
	bool loop = true;
	while (loop){
		cout << "Enter 1 for the salary of full time Employee  and Enter 2 for the salary of Part time Employee andpress 3 for Exit " << endl;
		cin >> key;
		if (key == 1){
			cout << "Enter the salary of Full time employee" << endl;
			cin >> salary;
			employee1 = new full_time_employee(salary);
			employee1->calculate_salary();
		}
		else if (key == 2)
		{
			cout << "Enter the hours of part Time Employee" << endl;
			cin >> hours;
			cout << "Enter the rate of per hour" << endl;
			cin >> rate;
			employee2 = new part_time_employee(hours, rate);
			employee2->calculate_salary();
		}
		else if (key == 3)
		{
			loop = false;
		}
		else{
			cout << "invalid choice" << endl;
		}
	}
	return 0;
}