#include <iostream>
using namespace std;
class BankAccount
{
    int balance = 0;

public:
    BankAccount()
    {
        cout << "The Balance is " << balance << "\n";
    }
    BankAccount(int value)
    {
        balance = value;
        cout << "The Balance is " << balance << "\n";
    }
    BankAccount(BankAccount &bank)
    {
        if (bank.balance >= 200)
        {
            bank.balance -= 200;
            cout << "The Balance in Account 3 is " << bank.balance << "\n";
        }
        else
        {
            cout << "Account Balance is isufficient.\nRemaining Balance is " << bank.balance;
        }
        cout << "The Balance in Account 2 is " << balance << "\n";
    }
};

int main()
{
    BankAccount Account1;
    BankAccount Account2(1000);
    BankAccount Account3(Account2);
    return 0;
}