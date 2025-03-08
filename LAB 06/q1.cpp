#include "iostream"
using namespace std;

class Employee
{
protected:
    string name;
    float salary;

public:
    Employee(string name, float salary) : name(name), salary(salary) {}
    void display()
    {
        cout << "Name: " << name << " Salary: " << salary << endl;
    }
};
class Manager : public Employee
{
protected:
    float bonus;

public:
    Manager(string name, float salary, float bonus) : Employee(name, salary), bonus(bonus) {}
    void display()
    {
        Employee::display();
        cout << "Bonus: " << bonus << endl;
    }
};

int main()
{
    Manager m1("Vaania", 50.7, 20);
    m1.display();
    return 0;
}