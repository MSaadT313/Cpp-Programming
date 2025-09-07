#include <iostream>
using namespace std;

class Car {
private:
    string driverName;
    int carNumber;
    static const int speedLimit = 80;
    int speed;

public:
    Car(string name, int number, int spd) {
        driverName = name;
        carNumber = number;
        speed = spd;
    }

    int getSpeed() {
        return speed;
    }

    string getDriverName() {
        return driverName;
    }

    void display() {
        cout << "Driver: " << driverName << ", Car Number: " << carNumber << ", Speed: " << speed << " KM/H" << endl;
    }
};

class Rally {
private:
    Car* cars[5];
    int numCars;

public:
    Rally() {
        numCars = 5;
        cars[0] = new Car("Ali", 1, 78);
        cars[1] = new Car("Ahmed", 2, 80);
        cars[2] = new Car("Sara", 3, 79);
        cars[3] = new Car("Zain", 4, 77);
        cars[4] = new Car("Fatima", 5, 80);
    }

    void displayWinner() {
        Car* winner = nullptr;
        for (int i = 0; i < numCars; i++) {
            if (cars[i]->getSpeed() <= 80) {
                if (!winner || cars[i]->getSpeed() > winner->getSpeed()) {
                    winner = cars[i];
                }
            }
        }
        cout << "Rally Winner:" << endl;
        if (winner) {
            winner->display();
        } else {
            cout << "No winner, all cars exceeded the speed limit!" << endl;
        }
    }

    ~Rally() {
        for (int i = 0; i < numCars; i++) {
            delete cars[i];
        }
    }
};

int main() {
    Rally rally;
    rally.displayWinner();
    return 0;
}