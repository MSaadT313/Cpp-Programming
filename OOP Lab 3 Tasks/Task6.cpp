#include <iostream>
#include "Employees.h"

using namespace std;

Emp_Data::Emp_Data(string name, int date_of_joining, int salary)
    : name(name), date_of_joining(date_of_joining), salary(salary) {}

void Emp_Data::print() const {
    cout << "Name: " << name << ", Salary: " << salary << endl;
}

int main() {
    Emp_Data emp1("Saad Tahir", 20210101, 50000);
    Emp_Data emp2("Ali Khan", 20210315, 60000);
    emp1.print();
    emp2.print();

    return 0;
}
