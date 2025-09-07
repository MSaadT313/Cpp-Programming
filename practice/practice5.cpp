#include <iostream>
using namespace std;
class Bankcard
{
public:
    int cardnumber;
    string card_holder_name;
    string expiry_date;
    float balance;

public:
    Bankcard()
    {
        cardnumber = 123456789;
        card_holder_name = "John Doe";
        expiry_date = "12/12/2022";
        balance = 1000;
    };
    Bankcard(Bankcard *obj)
    {
        cardnumber = obj->cardnumber;
        card_holder_name = obj->card_holder_name;
        expiry_date = obj->expiry_date;
        balance = obj->balance;
    }
    void checkbalance(float price)
    {
        if (balance < price)
        {
            cout << "Balance is less than price, transaction unsuccessful." << endl;
        }
        else
        {
            cout << "Transaction Successful" << endl;
        }
        balance = balance - price;
        cout << "Balance: " << balance << endl;
    }
    void printstatement()
    {
        cout << "Card number: " << cardnumber << endl;
        cout << "Card holder name: " << card_holder_name << endl;
        cout << "Expiry date: " << expiry_date << endl;
        cout << "Balance: " << balance << endl;
    }
};
class Credit_card : public Bankcard
{
    int credit_limit = 10000;

public:
    void printstatement()
    {
        cout << "Card number: " << cardnumber << endl;
        cout << "Card holder name: " << card_holder_name << endl;
        cout << "Expiry date: " << expiry_date << endl;
        cout << "Balance: " << balance << endl;
        cout << "Credit card" << endl;
    }
    void checkbalance(float price)
    {
        if (price > credit_limit)
        {
            cout << "Transaction Unsuccessfull." << endl;
            cout << "Price is greater than credit limit" << endl;
            cout << "Surplus: " << balance - credit_limit << endl;
        }
        else
        {
            cout << "Transaction Successful" << endl;
            balance = balance - price;
        }
        cout << "Remaining Balance: " << balance << endl;
    }
};
class Prepaid_card : public Bankcard
{
    int transaction;

public:
    void printstatement()
    {
        cout << "Card number: " << cardnumber << endl;
        cout << "Card holder name: " << card_holder_name << endl;
        cout << "Expiry date: " << expiry_date << endl;
        cout << "Balance: " << balance << endl;
        cout << "Prepaid card" << endl;
    }
    void checkbalance(float price)
    {
        if (balance < price)
        {
            cout << "Balance is less than price, transaction unsuccessful." << endl;
        }
        else
        {
            cout << "Transaction Successful" << endl;
        }
        balance = balance - price;
        cout << "Balance: " << balance << endl;
    }
};
class Debit_card : public Bankcard
{
public:
    void printstatement()
    {
        cout << "Card number: " << cardnumber << endl;
        cout << "Card holder name: " << card_holder_name << endl;
        cout << "Expiry date: " << expiry_date << endl;
        cout << "Balance: " << balance << endl;
        cout << "Debit card" << endl;
    }
    void checkbalance(float price)
    {
        if (balance < price)
        {
            cout << "Balance is less than price, transaction unsuccessful." << endl;
        }
        else
        {
            cout << "Transaction Successful" << endl;
        }
        balance = balance - price;
        cout << "Balance: " << balance << endl;
    }
};
class CardScanner
{
public:
    float price;
    Bankcard *bank_card;
    CardScanner(Bankcard *card)
    {
        bank_card = card;

        bank_card->printstatement();
    }
};
int main()
{
    Bankcard b1;
    int choice;
    float transaction;
    cout << "Enter transaction amount: ";
    cin >> transaction;
    cout << "Enter bank card type: " << endl;
    cout << "1. Credit card" << endl;
    cout << "2. Prepaid card" << endl;
    cout << "3. Debit card" << endl;
    cin >> choice;

    Credit_card c1;
    Prepaid_card p1;
    Debit_card d1;

    switch (choice)
    {
    case 1:
    {
        c1.checkbalance(transaction);
        CardScanner cs1(&c1);
        break;
    }
    case 2:
    {
        p1.checkbalance(transaction);
        CardScanner cs3(&p1);
        break;
    }
    case 3:
    {
        d1.checkbalance(transaction);
        CardScanner cs4(&d1);
        break;
    }
    default:
    {
        cout << "Invalid choice" << endl;
    }
    }
    return 0;
}