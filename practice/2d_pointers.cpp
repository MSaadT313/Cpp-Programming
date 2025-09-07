#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string n, double p)
    {
        name = n;
        price = p;
    }
    void display()
    {
        cout << "Product: " << name << ", Price: $"
             << price << endl;
    }
};
int main()
{
    // Creating a 2D array of pointer objects (3categories, 2 products each)
    Product *products[3][2];

    // Allocating objects dynamically
    products[0][0] = new Product("Laptop", 1200.50);
    products[0][1] = new Product("Smartphone",
                                 699.99);
    products[1][0] = new Product("Headphones",
                                 199.99);
    products[1][1] = new Product("Tablet",
                                 499.99);
    products[2][0] = new Product("Monitor",
                                 299.99);
    products[2][1] = new Product("Keyboard",
                                 99.99);

    // Displaying products category-wise
    for (int i = 0; i < 3; i++)
    {
        cout << "Category " << i + 1 << ":" << endl;
        for (int j = 0; j < 2; j++)
        {
            products[i][j]->display();
        }
        cout << endl;
    }
    // Free allocated memory
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            delete products[i][j];
        }
    }
    return 0;
}
