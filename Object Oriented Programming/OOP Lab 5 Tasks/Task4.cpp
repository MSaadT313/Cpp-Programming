#include <iostream>
using namespace std;

class Airport {
private:
    string name;
    string location;

public:
    Airport(string n, string loc) {
        name = n;
        location = loc;
    }

    string getName() {
        return name;
    }

    string getLocation() {
        return location;
    }
};

class Flight {
private:
    string flightNumber;
    Airport* departure;
    Airport* destination;
    Airport* currentLocation;
    string status;

public:
    Flight(string fNum, Airport* dep, Airport* dest) {
        flightNumber = fNum;
        departure = dep;
        destination = dest;
        currentLocation = dep;
        status = "On Schedule";
    }

    void hijack(Airport* emergencyLanding) {
        currentLocation = emergencyLanding;
        status = "Hijacked - Emergency Landing in " + emergencyLanding->getLocation();
    }

    void displayStatus() {
        cout << "Flight " << flightNumber << " Status: " << status << endl;
        cout << "Currently at: " << currentLocation->getName() << " (" << currentLocation->getLocation() << ")" << endl;
    }
};

int main() {
    Airport karachi("Karachi Airport", "Karachi");
    Airport england("England Airport", "England");
    Airport islamabad("Islamabad Airport", "Islamabad");

    Flight flight("A-347", &karachi, &england);
    flight.displayStatus();

    flight.hijack(&islamabad);
    flight.displayStatus();
    
    return 0;
}