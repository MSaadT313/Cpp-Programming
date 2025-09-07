/*write a simple airline ticket reservation program. The program should display a menu with the following options:
reserve a ticket, cancel a reservation, check whether a ticket is reserved for particular person, and display the
passengers. the information is maintained on a alphabetized linked list of names. in simple version of the
program, assume that tickets are reserved for only one flight. In a fuller version, place no limit on the number of
flights. create a linked list of flights with each node including a pointer to a linked list of passengers*/

#include <iostream>
#include <string>
using namespace std;

struct Passenger {
    string name;
    Passenger* next;
    Passenger(string n) : name(n), next(NULL) {}
};

class AirlineReservation {
    Passenger* head;
public:
    AirlineReservation() : head(NULL) {}

    void reserve(string name) {
        Passenger* newPassenger = new Passenger(name);
        if (!head || name < head->name) {
            newPassenger->next = head;
            head = newPassenger;
            return;
        }
        Passenger* temp = head;
        while (temp->next && temp->next->name < name) {
            temp = temp->next;
        }
        if (temp->name == name || (temp->next && temp->next->name == name)) {
            cout << "Ticket already reserved for " << name << endl;
            delete newPassenger;
            return;
        }
        newPassenger->next = temp->next;
        temp->next = newPassenger;
    }

    void cancel(string name) {
        if (!head) return;
        if (head->name == name) {
            Passenger* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Passenger* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next) {
            Passenger* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            cout << "No reservation found for " << name << endl;
        }
    }

    void check(string name) {
        Passenger* temp = head;
        while (temp) {
            if (temp->name == name) {
                cout << "Ticket reserved for " << name << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "No ticket reserved for " << name << endl;
    }

    void display() {
        Passenger* temp = head;
        if (!temp) {
            cout << "No passengers." << endl;
            return;
        }
        cout << "Passenger List: ";
        while (temp) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    AirlineReservation flight;
    int choice;
    string name;

    while (true) {
        cout << "\n--- Airline Ticket Reservation ---\n";
        cout << "1. Reserve a Ticket\n";
        cout << "2. Cancel a Reservation\n";
        cout << "3. Check Reservation\n";
        cout << "4. Display Passengers\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter passenger name: ";
            cin >> name;
            flight.reserve(name);
            break;
        case 2:
            cout << "Enter passenger name: ";
            cin >> name;
            flight.cancel(name);
            break;
        case 3:
            cout << "Enter passenger name: ";
            cin >> name;
            flight.check(name);
            break;
        case 4:
            flight.display();
            break;
        case 5:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
