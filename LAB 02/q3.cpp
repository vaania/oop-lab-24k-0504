#include <iostream>
#include <string>
using namespace std;

struct employee
{
    string employeename;
    float hours;
    float rate;
};

int main()
{
    int n;
    cout << "Enter the number of employees you want to enter: ";
    cin >> n;
    
    cin.ignore();
    employee *employees = new employee[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Employee " << i + 1 << " name: ";
        getline(cin, employees[i].employeename);
    
        cout << "Enter the Employee " << i + 1 << " Hours worked: ";
        cin >> employees[i].hours;
    
        cout << "Enter the Employee " << i + 1 << " Hourly rate: ";
        cin >> employees[i].rate;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "Salary of employee " << employees[i].employeename << ": " << employees[i].rate * employees[i].hours << endl;
    }
    
    delete[] employees;
    
    return 0;
}