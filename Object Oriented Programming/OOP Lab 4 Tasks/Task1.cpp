#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    string description;
    double cost;
    string barcode;
    int itemsSold;
    int totalStock;

public:
    Product() {
        name = "Unknown";
        description = "No description available";
        cost = 0.0;
        barcode = "000000";
        itemsSold = 0;
        totalStock = 100;  
    }

    // Setters
    void setName(string n) {
        name = n;
    }

    void setDescription(string desc) {
        description = desc;
    }

    void setCost(double c) {
        if (c >= 0) {
            cost = c;
        } else {
            cout << "Error: Cost cannot be negative" << endl;
        }
    }

    void setBarcode(string code) {
        barcode = code;
    }

    void setTotalStock(int stock) {
        if (stock >= 0) {
            totalStock = stock;
        } else {
            cout << "Error: Stock cannot be negative" << endl;
        }
    }

    void updateItemsSold(int quantity) {
        if (quantity <= 0) {
            cout << "Error: Invalid quantity" << endl;
            return;
        }

        if (itemsSold + quantity > totalStock) {
            cout << "Error: Cannot sell more than total stock" << endl;
            return;
        }

        itemsSold += quantity;
        
        if (itemsSold == totalStock) {
            cout << "Alert: Product is now sold out!" << endl;
        } else {
            cout << "Successfully sold " << quantity << " items" << endl;
            cout << "Remaining stock: " << totalStock - itemsSold << endl;
        }
    }

    void showProductInfo() {
        cout << "\n----- Product Information -----" << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Barcode: " << barcode << endl;
        cout << "Items Sold: " << itemsSold << endl;
        cout << "Total Stock: " << totalStock << endl;
        cout << "Available Stock: " << totalStock - itemsSold << endl;
        cout << "---------------------------" << endl;
    }
};

int main() {
    Product laptop;

    laptop.setName("Gaming Laptop");
    laptop.setDescription("High-performance gaming laptop with RGB keyboard");
    laptop.setCost(1299.99);
    laptop.setBarcode("LAP123456");
    laptop.setTotalStock(50);

    laptop.showProductInfo();

    cout << "\nTesting sales:" << endl;
    laptop.updateItemsSold(20);  
    laptop.showProductInfo();

    laptop.updateItemsSold(25);  
    laptop.showProductInfo();

    laptop.updateItemsSold(10);  
    
    return 0;
}