#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;  

public:
    Currency(double amt, string code, string symbol, double rate = 1.0) : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() = 0;  
    virtual void displayCurrency() = 0;  

    double convertTo(Currency& targetCurrency) {
        double baseAmount = convertToBase();
        double targetAmount = baseAmount / targetCurrency.exchangeRate;
        return targetAmount;
    }

    string getCurrencyCode() {
        return currencyCode;
    }

    string getCurrencySymbol() {
        return currencySymbol;
    }

    double getAmount() {
        return amount;
    }

    double getExchangeRate() {
        return exchangeRate;
    }

    void setAmount(double amt) {
        amount = amt;
    }

    void setExchangeRate(double rate) {
        exchangeRate = rate;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override {
        return amount;  
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 0.85) {}  

    double convertToBase() override {
        return amount * exchangeRate;  
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "Pkr", "Rs", 0.013) {}  

    double convertToBase() override {
        return amount * exchangeRate;  
    }

    void displayCurrency() override {
        cout << currencySymbol << amount << " (" << currencyCode << ")\n";
    }
};

int main() {
    
    Dollar usd(100);  
    Euro eur(100);    
    Rupee pkr(10000); 

    cout << "Currency Details:\n";
    usd.displayCurrency();
    eur.displayCurrency();
 pkr.displayCurrency();

    double convertedAmount = usd.convertTo(eur); 
    cout << "\n100 USD is equivalent to " << round(convertedAmount * 100.0) / 100.0 << " EUR.\n";

    convertedAmount = eur.convertTo(usd); 
    cout << "100 EUR is equivalent to " << round(convertedAmount * 100.0) / 100.0 << " USD.\n";

    convertedAmount = pkr.convertTo(usd); 
    cout << "10000 PKR is equivalent to " << round(convertedAmount * 100.0) / 100.0 << " USD.\n";

    return 0;
}
