#include <iostream>
#include <string.h>
using namespace std;
class Vehicle{
protected: 
    string vehicleID;
    float maxWeight;
    float speed;
    int battery;
    friend bool checkEfficiency(Vehicle &a, Vehicle &b);
public:
    Vehicle(string id, float w, float s) : vehicleID(id), maxWeight(w), speed(s), battery(100)
    {
        totalDeliveries++;
    }

    static int totalDeliveries;

    virtual void calculateRoute()
    {
        cout << "Normal route is " << endl;
    }

    virtual void deliveryTime(float distance)
    {
        cout<< "Time: " <<distance /speed << " hours" << endl;
    }

    float getSpeed() {return speed; }
    float getWeight() {return maxWeight; }
    int getBattery() {return battery; }
};

int Vehicle::totalDeliveries = 0;

class TimeShip :public Vehicle
{
public:
    TimeShip(string id,float w,float s) : Vehicle(id, w, s) {}

    void calculateRoute() override
    {
        cout<<"Checking history before time jump  "<<endl;
    }

    void deliveryTime(float distance) override
    {
        cout<<"Time travel takes " << distance / (getSpeed() * 2) << " hours" << endl;
    }
};
class Drone : public Vehicle {
    public:
        Drone(string id, float w, float s) : Vehicle(id,w,s) {}
    
        void calculateRoute() override {
            cout << "Finding shortest air path..." << endl;
        }
    
        void deliveryTime(float distance) override {
            cout << "Drone will take " << distance/(getSpeed()*1.5) << " hours" << endl; 
        }
    };

class HyperPod : public Vehicle
{
public:
    HyperPod(string id, float w, float s) : Vehicle(id, w, s) {}

    void calculateRoute() override
    {
        cout << "Mapping underground tunnels..." << endl;
    }
};

bool checkEfficiency(Vehicle &a, Vehicle &b)
{
    float scoreA = a.speed * 0.6 + a.maxWeight * 0.4;
    float scoreB = b.speed * 0.6 + b.maxWeight * 0.4;
    return scoreA > scoreB;
}

bool operator==(Vehicle &a, Vehicle &b)
{
    return a.getSpeed() == b.getSpeed() && a.getWeight() == b.getWeight();
}

void command(string cmd, int packageID)
{
    cout << "Processing package " << packageID << endl;
}

void command(string cmd, int packageID, string urgency)
{
    if (urgency == "Sehri")
    {
        cout << "URGENT! Sehri package " << packageID << endl;
    }
    else if (urgency == "Iftar")
    {
        cout << "URGENT! Iftar package " << packageID << endl;
    }
    else
    {
        cout << "Normal delivery for package " << packageID << endl;
    }
}

int main()
{
    TimeShip ts("TS-1", 50.5, 300.0);
    Drone drone("DR-1", 10.2, 150.0);
    HyperPod pod("HP-1", 200.0, 500.0);

    ts.calculateRoute();
    drone.deliveryTime(120.5);
    pod.calculateRoute();

    command("Deliver", 101);
    command("Deliver", 102, "Sehri");
    command("Deliver", 103, "Iftar");

    if (checkEfficiency(ts, drone))
    {
        cout << "TimeShip is better for this delivery" << endl;
    }
    else
    {
        cout << "Drone is better for this delivery" << endl;
    }

    cout << "Total deliveries today: " << Vehicle::totalDeliveries << endl;

    return 0;
}