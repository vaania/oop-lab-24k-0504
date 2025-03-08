#include "iostream"
using namespace std;

class Account
{
private:
    int accountnum;
    float balance;

public:
    Account(int a, float b) : accountnum(a), balance(b) {}
    void display()
    {
        cout << "Account Number: " << accountnum << endl;
        cout << "Balance: $" << balance << endl;
    }
};
class SavingsAccount : public Account
{
private:
    float interestRate;

public:
    SavingsAccount(int a, float b, float r) : Account(a, b), interestRate(r) {}
    void display()
    {
        Account::display();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};
class CheckingAccount : public Account
{
private:
    float overdraftLimit;

public:
    CheckingAccount(int a, float b, float o) : Account(a, b), overdraftLimit(o) {}
    void display()
    {
        Account::display();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};
int main()
{
    SavingsAccount a1(12345, 40000.50, 7.5);
    CheckingAccount a2(678910, 32000.25, 100);
    a1.display();
    a2.display();
    return 0;
}