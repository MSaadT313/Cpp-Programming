#include <iostream>
using namespace std;

string formatPrice(float price) {
    int dollars = static_cast<int>(price);
    int cents = static_cast<int>((price - dollars) * 100 + 0.5); 
    string result = "$" + to_string(dollars) + ".";

    if (cents < 10)
        result += "0"; 

    result += to_string(cents);
    return result;
}

class Pizza {
protected:
    string pizzaType;
    float base_price;
    float total_price;

public:
    Pizza(string type, float price) : pizzaType(type), base_price(price), total_price(price) {}

    virtual void getDetails() = 0;

    float getBasePrice() const {
        return base_price;
    }

    float getTotalPrice() const {
        return total_price;
    }

    void setTotalPrice(float price) {
        total_price = price;
    }

    string getType() const {
        return pizzaType;
    }
};

class PepperoniPizza : public Pizza {
public:
    PepperoniPizza() : Pizza("Pepperoni Pizza", 12.99f) {}

    void getDetails() override {
        cout << "Includes pepperoni slices and extra cheese.\n";
    }
};

class DiscountMixin {
public:
    void applyDiscount(Pizza& pizza, float percent) {
        float discount = pizza.getBasePrice() * (percent / 100.0f);
        pizza.setTotalPrice(pizza.getBasePrice() - discount);
    }
};

class DeliveryMixin {
public:
    void addDeliveryCharge(Pizza& pizza, float deliveryCharge) {
        pizza.setTotalPrice(pizza.getTotalPrice() + deliveryCharge);
    }
};

class PizzaManagement : public DiscountMixin, public DeliveryMixin {
private:
    Pizza* pizza;
    string size;
    string toppings;
    float discountPercent;
    float deliveryCharge;

public:
    PizzaManagement(Pizza* p, string size, string toppings, float discount, float delivery)
        : pizza(p), size(size), toppings(toppings), discountPercent(discount), deliveryCharge(delivery) {}

    void processOrder() {
        applyDiscount(*pizza, discountPercent);
        addDeliveryCharge(*pizza, deliveryCharge);
    }

    void printSummary() {
        cout << "Order Summary:\n";
        cout << "--------------------------\n";
        cout << "Pizza Type: " << pizza->getType() << endl;
        cout << "Size: " << size << endl;
        cout << "Toppings: " << toppings << endl;
        cout << "Base Price: " << formatPrice(pizza->getBasePrice()) << endl;
        cout << "Discount Applied: " << static_cast<int>(discountPercent) << "%" << endl;
        cout << "Delivery Charge: " << formatPrice(deliveryCharge) << endl;
        cout << "Total Price: " << formatPrice(pizza->getTotalPrice()) << endl;
    }
};

int main() {
    PepperoniPizza pizza;
    PizzaManagement order(&pizza, "Large", "Extra Cheese", 10.0f, 3.00f);

    order.processOrder();
    order.printSummary();

    return 0;
}
