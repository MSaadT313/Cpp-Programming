#include <iostream>
#include <string>
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
cout << "Product: " << name << ", Price: $"
<< price << endl;
}
};

int main() {
// Creating a 1D array of pointer objects
Product* products[3];

// Allocating objects dynamically
products[0] = new Product("Laptop",
    1200.50);
    products[1] = new Product("Smartphone",
    699.99);
    products[2] = new Product("Headphones",
    199.99);
    
    // Display products
    for (int i = 0; i < 3; i++) {
    products[i]->display();
    }
    
    // Free allocated memory
    for (int i = 0; i < 3; i++) {
    delete products[i];
    }
    
    return 0;
}