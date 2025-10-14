#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(string accNum, double bal, string accHolder, string accType = "General")
        : accountNumber(accNum), balance(bal), accountHolderName(accHolder), accountType(accType) {}

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited: $" << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (amount > balance) {
            cout << "Error: Insufficient funds" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "Interest calculation is not defined for this account type" << endl;
    }

    virtual void printStatement() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
    }

    void getAccountInfo() {
        printStatement();
    }

    double getBalance() {
        return balance;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(string accNum, double bal, string accHolder, double rate, double minBal)
        : Account(accNum, bal, accHolder, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void deposit(double amount) override {
        Account::deposit(amount);
        if (balance < minimumBalance) {
            cout << "Warning: Balance below minimum required balance of $" << minimumBalance << endl;
        }
    }

    void withdraw(double amount) override {
        if (balance - amount < minimumBalance) {
            cout << "Error: Cannot withdraw, balance would go below minimum required balance" << endl;
        } else {
            Account::withdraw(amount);
        }
    }

    void calculateInterest() override {
        double interest = (balance * interestRate) / 100;
        cout << "Interest for this savings account: $" << interest << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: $" << minimumBalance << endl;
    }
};
class CheckingAccount : public Account {
private:
    double transactionFee;
public:
    CheckingAccount(string accNum, double bal, string accHolder, double fee)
        : Account(accNum, bal, accHolder, "Checking"), transactionFee(fee) {}
    void deposit(double amount) override {
        Account::deposit(amount);
        cout << "Transaction fee of $" << transactionFee << " will be deducted for deposits." << endl;
        balance -= transactionFee;
    }

    void withdraw(double amount) override {
        if (amount + transactionFee > balance) {
            cout << "Error: Insufficient funds for withdrawal and transaction fee" << endl;
        } else {
            Account::withdraw(amount + transactionFee);
            cout << "Transaction fee of $" << transactionFee << " has been deducted" << endl;
        }
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Transaction Fee: $" << transactionFee << endl;
    }
};

// Derived class: FixedDepositAccount
class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;

public:
    FixedDepositAccount(string accNum, double bal, string accHolder, double rate, string maturity)
        : Account(accNum, bal, accHolder, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override {
        double interest = (balance * fixedInterestRate) / 100;
        cout << "Interest for fixed deposit: $" << interest << endl;
    }

    void printStatement() override {
        Account::printStatement();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main() {

    SavingsAccount sa("SA001", 1000.0, "John Doe", 4.5, 500.0);
    CheckingAccount ca("CA001", 2000.0, "Jane Doe", 2.5);
    FixedDepositAccount fda("FDA001", 5000.0, "Sam Smith", 6.0, "2025-05-01");


    cout << "----- Savings Account -----" << endl;
    sa.deposit(500.0);
    sa.withdraw(200.0);
    sa.calculateInterest();
    sa.printStatement();
    cout << endl;

    cout << "----- Checking Account -----" << endl;
    ca.deposit(1000.0);
    ca.withdraw(500.0);
    ca.printStatement();
    cout << endl;

    cout << "----- Fixed Deposit Account -----" << endl;
    fda.calculateInterest();
    fda.printStatement();
    cout << endl;

    return 0;
}
