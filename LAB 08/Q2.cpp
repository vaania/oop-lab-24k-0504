#include <iostream>
using namespace std;

class Account;

class Manager
{
public:
    void deposit(Account &acc, double amount);
    void withdraw(Account &acc, double amount);
    void displayAccount(const Account &acc);
};

void transferFunds(Account &from, Account &to, double amount);

class Account
{
private:
    int accountNumber;
    double balance;

public:
    Account(int accNo, double bal = 0.0) : accountNumber(accNo), balance(bal) {}

    friend class Manager;

    friend void transferFunds(Account &from, Account &to, double amount);
};

void Manager::deposit(Account &acc, double amount)
{
    if (amount > 0)
    {
        acc.balance += amount;
        cout << "Deposited $" << amount << " to account " << acc.accountNumber << endl;
    }
    else
    {
        cout << "Invalid deposit amount.\n";
    }
}

void Manager::withdraw(Account &acc, double amount)
{
    if (amount > 0 && acc.balance >= amount)
    {
        acc.balance -= amount;
        cout << "Withdrew $" << amount << " from account " << acc.accountNumber << endl;
    }
    else
    {
        cout << "Withdrawal failed. Insufficient balance or invalid amount.\n";
    }
}

void Manager::displayAccount(const Account &acc)
{
    cout << "Account Number: " << acc.accountNumber << ", Balance: $" << acc.balance << endl;
}

void transferFunds(Account &from, Account &to, double amount)
{
    if (amount > 0 && from.balance >= amount)
    {
        from.balance -= amount;
        to.balance += amount;
        cout << "Transferred $" << amount << " from account " << from.accountNumber
             << " to account " << to.accountNumber << endl;
    }
    else
    {
        cout << "Transfer failed. Insufficient balance or invalid amount.\n";
    }
}

int main()
{
    Account a1(1001, 500.0);
    Account a2(1002, 300.0);

    Manager manager;

    cout << "Initial Account States:\n";
    manager.displayAccount(a1);
    manager.displayAccount(a2);

    cout << "\nPerforming Deposit and Withdrawal:\n";
    manager.deposit(a1, 200);
    manager.withdraw(a2, 100);

    cout << "\nAccounts after Deposit and Withdrawal:\n";
    manager.displayAccount(a1);
    manager.displayAccount(a2);

    cout << "\nTransferring Funds:\n";
    transferFunds(a1, a2, 250);

    cout << "\nFinal Account States:\n";
    manager.displayAccount(a1);
    manager.displayAccount(a2);

    return 0;
}
