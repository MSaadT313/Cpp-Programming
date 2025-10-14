#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;

public:
    BankAccount(int id, double initialBalance, int* transactions, int numTrans) {
        accountId = id;
        balance = initialBalance;
        numTransactions = numTrans;
        transactionHistory = new int[numTransactions];
        for(int i = 0; i < numTransactions; i++) {
            transactionHistory[i] = transactions[i];
        }
        cout << "Account created successfully!" << endl;
    }
    
    BankAccount(const BankAccount& other) {
        accountId = other.accountId;
        balance = other.balance;
        numTransactions = other.numTransactions;
        transactionHistory = new int[numTransactions];
        for(int i = 0; i < numTransactions; i++) {
            transactionHistory[i] = other.transactionHistory[i];
        }
        cout << "Account copied successfully!" << endl;
    }
    
    ~BankAccount() {
        delete[] transactionHistory;
        cout << "Memory deallocated for account " << accountId << endl;
    }
    
    void display() {
        cout << "\n====== Account Details ======" << endl;
        cout << "Account ID: " << accountId << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "\nTransaction History:" << endl;
        cout << "Number of transactions: " << numTransactions << endl;
        for(int i = 0; i < numTransactions; i++) {
            cout << "Transaction " << i + 1 << ": $" << transactionHistory[i] << endl;
        }
        cout << "==========================" << endl;
    }
    
    void updateTransactionHistory(int* newTransactions, int newNumTransactions) {
        delete[] transactionHistory;
        numTransactions = newNumTransactions;
        transactionHistory = new int[numTransactions];
        for(int i = 0; i < numTransactions; i++) {
            transactionHistory[i] = newTransactions[i];
        }
        cout << "\nTransaction history updated successfully!" << endl;
    }
};

int main() {
    cout << "Banking System Demo\n" << endl;
    
    int initialTransactions[] = {500, -200, 1000, -50};
    int initialNumTransactions = 4;
    
    cout << "Creating original account..." << endl;
    BankAccount originalAccount(1001, 2000.0, initialTransactions, initialNumTransactions);
    
    cout << "\nCreating copy of the account..." << endl;
    BankAccount copiedAccount = originalAccount;
    
    cout << "\nDisplaying original account details:" << endl;
    originalAccount.display();
    
    cout << "\nDisplaying copied account details:" << endl;
    copiedAccount.display();
    
    int newTransactions[] = {1000, -500, 750, -250, 2000};
    int newNumTransactions = 5;
    
    cout << "\nUpdating transaction history of original account..." << endl;
    originalAccount.updateTransactionHistory(newTransactions, newNumTransactions);
    
    cout << "\nDisplaying original account after update:" << endl;
    originalAccount.display();
    
    cout << "\nDisplaying copied account (should remain unchanged):" << endl;
    copiedAccount.display();
    
    return 0;
}