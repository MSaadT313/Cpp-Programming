#include <iostream>
#include <string>
using namespace std;

class User {
private:
    string name;
    int age;
    string licenseType;
    string contactInfo;
    int userID;

public:
    User(string n, int a, string lt, string ci, int id) {
        name = n;
        age = a;
        licenseType = lt;
        contactInfo = ci;
        userID = id;
    }

    void updateDetails(string n, int a, string lt, string ci) {
        name = n;
        age = a;
        licenseType = lt;
        contactInfo = ci;
    }

    string getLicenseType() { return licenseType; }
    string getName() { return name; }
    int getUserID() { return userID; }

    void displayDetails() {
        cout << "User ID: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "License Type: " << licenseType << endl;
        cout << "Contact Info: " << contactInfo << endl;
    }
};

class Vehicle {
private:
    string model;
    double rentalPrice;
    string requiredLicense;

public:
    Vehicle(string m, double rp, string rl) {
        model = m;
        rentalPrice = rp;
        requiredLicense = rl;
    }

    string getModel() { return model; }
    double getRentalPrice() { return rentalPrice; }
    string getRequiredLicense() { return requiredLicense; }

    void displayDetails() {
        cout << "Model: " << model << endl;
        cout << "Rental Price: $" << rentalPrice << " per day" << endl;
        cout << "Required License: " << requiredLicense << endl;
    }
};

class RentalSystem {
private:
    User *currentUser;
    Vehicle **vehicles;
    int vehicleCount;

public:
    RentalSystem() {
        currentUser = nullptr;
        vehicles = new Vehicle*[10]; // Dynamic array of pointers
        vehicleCount = 0;
    }

    ~RentalSystem() {
        for (int i = 0; i < vehicleCount; i++) {
            delete vehicles[i];
        }
        delete[] vehicles;
    }

    void registerUser(string name, int age, string licenseType, string contactInfo, int userID) {
        currentUser = new User(name, age, licenseType, contactInfo, userID);
        cout << "User registered successfully!" << endl;
    }

    void updateUserDetails(string name, int age, string licenseType, string contactInfo) {
        if (currentUser) {
            currentUser->updateDetails(name, age, licenseType, contactInfo);
            cout << "User details updated successfully!" << endl;
        } else {
            cout << "No user registered!" << endl;
        }
    }

    void addVehicle(string model, double rentalPrice, string requiredLicense) {
        if (vehicleCount < 10) {
            vehicles[vehicleCount] = new Vehicle(model, rentalPrice, requiredLicense);
            vehicleCount++;
            cout << "Vehicle added successfully!" << endl;
        } else {
            cout << "Cannot add more vehicles. Limit reached!" << endl;
        }
    }

    void displayAvailableVehicles() {
        cout << "Available Vehicles:" << endl;
        for (int i = 0; i < vehicleCount; i++) {
            cout << "Vehicle " << i + 1 << ":" << endl;
            vehicles[i]->displayDetails();
            cout << "---------------------" << endl;
        }
    }

    void rentVehicle(int vehicleIndex) {
        if (!currentUser) {
            cout << "No user registered!" << endl;
            return;
        }

        if (vehicleIndex < 0 || vehicleIndex >= vehicleCount) {
            cout << "Invalid vehicle selection!" << endl;
            return;
        }

        Vehicle *selectedVehicle = vehicles[vehicleIndex];
        if (currentUser->getLicenseType() == selectedVehicle->getRequiredLicense()) {
            cout << "Rental successful!" << endl;
            cout << "Vehicle rented: " << selectedVehicle->getModel() << endl;
            cout << "Rental price: $" << selectedVehicle->getRentalPrice() << " per day" << endl;
        } else {
            cout << "You are not eligible to rent this vehicle!" << endl;
        }
    }
};

int main() {
    RentalSystem system;
    int choice;

    do {
        cout << "\nVehicle Rental System Menu:" << endl;
        cout << "1. Register User" << endl;
        cout << "2. Update User Details" << endl;
        cout << "3. Add Vehicle" << endl;
        cout << "4. Display Available Vehicles" << endl;
        cout << "5. Rent Vehicle" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, licenseType, contactInfo;
                int age, userID;
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter license type (Learner/Intermediate/Full): ";
                cin >> licenseType;
                cout << "Enter contact info: ";
                cin >> contactInfo;
                cout << "Enter user ID: ";
                cin >> userID;
                system.registerUser(name, age, licenseType, contactInfo, userID);
                break;
            }
            case 2: {
                string name, licenseType, contactInfo;
                int age;
                cout << "Enter new name: ";
                cin >> name;
                cout << "Enter new age: ";
                cin >> age;
                cout << "Enter new license type (Learner/Intermediate/Full): ";
                cin >> licenseType;
                cout << "Enter new contact info: ";
                cin >> contactInfo;
                system.updateUserDetails(name, age, licenseType, contactInfo);
                break;
            }
            case 3: {
                string model, requiredLicense;
                double rentalPrice;
                cout << "Enter vehicle model: ";
                cin >> model;
                cout << "Enter rental price per day: ";
                cin >> rentalPrice;
                cout << "Enter required license type (Learner/Intermediate/Full): ";
                cin >> requiredLicense;
                system.addVehicle(model, rentalPrice, requiredLicense);
                break;
            }
            case 4: {
                system.displayAvailableVehicles();
                break;
            }
            case 5: {
                int vehicleIndex;
                cout << "Enter the index of the vehicle you want to rent: ";
                cin >> vehicleIndex;
                system.rentVehicle(vehicleIndex - 1);
                break;
            }
            case 6: {
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            }
            default: {
                cout << "Invalid choice! Please try again." << endl;
                break;
            }
        }
    } while (choice != 6);

    return 0;
}