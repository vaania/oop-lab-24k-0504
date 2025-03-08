#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    string designation;

public:
    Employee(string name, string desig) : name(name), designation(desig) {}

    void display() const {
        cout << "Employee Name: " << name << ", Designation: " << designation << endl;
    }

    string getName() const { return name; }
    string getDesignation() const { return designation; }
};

class Project {
private:
    string projName;
    int empCount;
    Employee* employees[10];

public:
    Project(string name) : projName(name), empCount(0) {}

    void addEmployee(Employee* emp) {
        if (empCount < 10) {
            employees[empCount++] = emp;
        } else {
            cout << "Project is full, cannot add more employees." << endl;
        }
    }

    void displayDetails() const {
        cout << "Project: " << projName << endl;
        cout << "Assigned Employees:" << endl;
        for (int i = 0; i < empCount; i++) {
            cout << "- " << employees[i]->getName() << " (" << employees[i]->getDesignation() << ")" << endl;
        }
        cout << endl;
    }
};

int main() {
    Employee e1("Anwar", "Software Engineer");
    Employee e2("Sara", "Project Manager");

    Project p1("AI Development");

    p1.addEmployee(&e1);
    p1.addEmployee(&e2);

    p1.displayDetails();

    return 0;
}
