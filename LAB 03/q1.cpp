#include <iostream>
#include <string>
using namespace std;

class Wallet
{
public:
    string ownerName;

private:
    int totalBalance;
    int amount;
    int withdrawAmnt;

public:
    void setValues(string name, int balance)
    {
        ownerName = name;
        totalBalance = balance;
    }

    int getBalance()
    {
        return totalBalance;
    }

    void addMoney()
    {
        cout << "Enter the amount you want to deposit (enter 0 if you don't want to): ";
        cin >> amount;

        if (amount < 0)
        {
            cout << "Invalid amount! Amount cannot be negative." << endl;
            return;
        }

        totalBalance += amount;
        cout << "Deposited Rs " << amount << ". New balance: Rs " << totalBalance << endl;
    }

    void spendMoney()
    {
        cout << "Enter the amount you want to withdraw (enter 0 if you don't want to): ";
        cin >> withdrawAmnt;

        if (withdrawAmnt < 0)
        {
            cout << "Invalid amount! Amount cannot be negative." << endl;
            return;
        }

        if (withdrawAmnt > totalBalance)
        {
            cout << "Low balance! Cannot withdraw Rs " << withdrawAmnt << endl;
        }
        else
        {
            totalBalance -= withdrawAmnt;
            cout << "Withdrawn Rs " << withdrawAmnt << ". New balance: Rs " << totalBalance << endl;
        }
    }

    void getHistory()
    {
        cout << "Balance after depositing Rs " << amount << " is Rs " << totalBalance << endl;
        cout << "Balance after withdrawing Rs " << withdrawAmnt << " is Rs " << totalBalance << endl;
    }
};

int main()
{
    Wallet money;
    string name;
    int initialBalance;

    cout << "Enter owner's name: ";
    getline(cin, name);

    cout << "Enter initial balance: ";
    cin >> initialBalance;

    money.setValues(name, initialBalance);

    money.addMoney();
    money.spendMoney();

    money.getHistory();

    return 0;
}