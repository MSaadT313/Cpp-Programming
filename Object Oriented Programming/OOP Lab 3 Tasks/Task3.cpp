#include <iostream>
#include <string>

using namespace std;

class ATM
{
private:
    string debitCardNumber;
    string atmPin;
    double balance;

public:
    ATM(const string &cardNumber = "", const string &pin = "", double initialBalance = 0.0)
        : debitCardNumber(cardNumber), atmPin(pin), balance(initialBalance) {}

    void setDebitCardNumber(const string &cardNumber)
    {
        debitCardNumber = cardNumber;
    }

    void setATMPIN(const string &pin)
    {
        atmPin = pin;
    }

    void withdrawMoney(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << '\n';
        }
        else
        {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void balanceInquiry() const
    {
        cout << "Current balance: " << balance << '\n';
    }

    void billPayment(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Bill payment successful. New balance: " << balance << '\n';
        }
        else
        {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }
};

int main()
{
    ATM myATM("1234-5678-9012-3456", "1234", 10000.0);

    myATM.balanceInquiry();

    myATM.withdrawMoney(2500.0);

    myATM.billPayment(1500.0);

    myATM.balanceInquiry();

    return 0;
}
