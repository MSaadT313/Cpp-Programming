#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Product {
    string name;
    double price;
    int stock;
public:
    Product(string n, double p, int s) : name(n), price(p), stock(s) {}
    void applyDiscount(double discountPercent) {
        price -= price * (discountPercent / 100.0);
    }
    void display() const {
        cout << "Product: " << name << ", Price: $" << price << ", Stock: " << stock << endl;
    }
};

class Bundle {
    vector<Product*> products;
    double discount;
    bool isDeep;
public:
    Bundle(double d = 0.0, bool deep = false) : discount(d), isDeep(deep) {}
    void addProduct(Product* p) {
        products.push_back(p);
    }
    void applyDiscount() {
        for (auto p : products) p->applyDiscount(discount);
    }
    void display() const {
        cout << "Bundle with Discount: " << discount << "%" << endl;
        for (auto p : products) p->display();
    }
    Bundle(const Bundle& other, bool shallow) {
        discount = other.discount;
        isDeep = !shallow;
        if (shallow) {
            products = other.products;
        } else {
            for (auto p : other.products) {
                products.push_back(new Product(*p));
            }
        }
    }
    ~Bundle() {
        if (isDeep) {
            for (auto p : products) delete p;
        }
    }
};

int main() {
    Product* p1 = new Product("Laptop", 1000, 10);
    Product* p2 = new Product("Headphones", 100, 50);
    Product* p3 = new Product("Mouse", 50, 100);

    Bundle original(10);
    original.addProduct(p1);
    original.addProduct(p2);
    original.addProduct(p3);

    cout << "Original Bundle:" << endl;
    original.display();

    Bundle shallowCopy(original, true);
    Bundle deepCopy(original, false);

    cout << "\nApplying discount to Original Bundle..." << endl;
    original.applyDiscount();

    cout << "\nOriginal Bundle after discount:" << endl;
    original.display();

    cout << "\nShallow Copy Bundle after original changes:" << endl;
    shallowCopy.display();

    cout << "\nDeep Copy Bundle (unchanged):" << endl;
    deepCopy.display();

    delete p1;
    delete p2;
    delete p3;

    return 0;
}
