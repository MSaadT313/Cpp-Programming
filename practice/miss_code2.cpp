#include <iostream>
using namespace std;

class Product {
public:
string name;
double price;

Product(string n, double p) {
name = n;
price = p;
}

void display() {
cout << "Product: " << name << ",Price: $" << price << endl;
}
};

int main() {
    // Array of product pointers
Product* products[3] = {
    new Product("Laptop", 1200.50),
    new Product("Smartphone",
    699.99),
    new Product("Tablet", 499.99)
    };
    
    // Display products
    for (int i = 0; i < 3; i++) {
    products[i]->display();
    }
    
    // Free memory
    for (int i = 0; i < 3; i++) {
    delete products[i];
    }
    
    return 0;
    }