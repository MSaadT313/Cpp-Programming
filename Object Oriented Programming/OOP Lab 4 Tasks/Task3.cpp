#include <iostream>
#include <string>
#include <random>
using namespace std;

class ProductManagement {
private:
    int productID;
    string productName;
    string description;
    float cost;
    string barCodeValue;

    string generateRandomString(int length) {
        const string chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribution(0, chars.size() - 1);

        string randomString;
        for (int i = 0; i < length; ++i) {
            randomString += chars[distribution(generator)];
        }
        return randomString;
    }

public:
    ProductManagement(int id, string name, string desc, float c, string barcode) {
        productID = id;
        productName = name;
        description = desc;
        cost = c;
        barCodeValue = barcode;
    }

    void DisplayProductInfo() {
        cout << "\n----- Product Information -----" << endl;
        cout << "Product ID: " << productID << endl;
        cout << "Product Name: " << productName << endl;
        cout << "Description: " << description << endl;
        cout << "Cost: $" << cost << endl;
        cout << "Barcode: " << barCodeValue << endl;
        cout << "----------------------------" << endl;
    }

    void UpdateCost(float newCost) {
        if (newCost >= 0) {
            cost = newCost;
            cout << "Cost updated successfully." << endl;
        } else {
            cout << "Error: Cost cannot be negative." << endl;
        }
    }

    void UpdateDescription(string newDescription) {
        description = newDescription;
        cout << "Description updated successfully." << endl;
    }

    void GenerateBarCode() {
        barCodeValue = generateRandomString(12);
        cout << "New barcode generated successfully: " << barCodeValue << endl;
    }
};

int main() {
    ProductManagement product(
        1001,
        "Smart Watch",
        "Premium smartwatch with health monitoring features",
        199.99,
        "ABC123456789"
    );

    cout << "Initial Product Information:" << endl;
    product.DisplayProductInfo();

    cout << "\nUpdating cost to $249.99..." << endl;
    product.UpdateCost(249.99);

    cout << "\nUpdating description..." << endl;
    product.UpdateDescription("Premium smartwatch with advanced health monitoring and GPS features");

    cout << "\nGenerating new barcode..." << endl;
    product.GenerateBarCode();

    cout << "\nUpdated Product Information:" << endl;
    product.DisplayProductInfo();

    cout << "\nTrying to update cost with negative value..." << endl;
    product.UpdateCost(-50.00);

    return 0;
}