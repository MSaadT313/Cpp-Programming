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

class Category
{
public:
    string categoryName;
    Product *products[2];

    Category(string name, Product *p1, Product *p2)
    {
        categoryName = name;
        products[0] = p1;
        products[1] = p2;
    }

    void display()
    {
        cout << "Category: " << categoryName << endl;
        for (int i = 0; i < 2; i++)
        {
            products[i]->display();
        }
    }
};

int main()
{
    // Creating products
    Product *products[6] = {
        new Product("Laptop", 1200.50),
        new Product("Smartphone", 699.99),
        new Product("Headphones", 199.99),
        new Product("Tablet", 499.99),
        new Product("Monitor", 299.99),
        new Product("Keyboard", 99.99)};

    // Creating categories
    Category *categories[3] = {
        new Category("Electronics", products[0],
                     products[1]),
        new Category("Accessories", products[2],
                     products[3]),
        new Category("Peripherals", products[4],
                     products[5])};

    // Display categories and products
    for (int i = 0; i < 3; i++)
    {
        categories[i]->display();
        cout << endl;
    }

    // Deallocate memory for categories and products
    for (int i = 0; i < 3; i++)
    {
        delete categories[i];
    }

    // Deallocate memory for products
    for (int i = 0; i < 6; i++)
    {
        delete products[i];
    }

    return 0;
}