#include <iostream>
#include <string>
using namespace std;

class Stops;

class Student {
private:
    int ID;
    string name;
    bool cardStatus;
    Stops *pickUpStop;
    Stops *dropOffStop;

public:
    Student(int id, string n) {
        ID = id;
        name = n;
        cardStatus = false;
        pickUpStop = nullptr;
        dropOffStop = nullptr;
    }

    void displayDetail() {
        cout << "ID: " << ID << endl;
        cout << "Name: " << name << endl;
        cout << "Card Status: " << (cardStatus ? "Active" : "Not Active") << endl;
    }

    void setPickUpStop(Stops *s) { pickUpStop = s; }
    void setDropOffStop(Stops *s) { dropOffStop = s; }

    void payFees() { cardStatus = true; }
    bool getCardStatus() { return cardStatus; }
    int getID() { return ID; }
    string getName() { return name; }
};

class Stops {
private:
    string name;
    Student *students[100];
    int studentCount;

public:
    Stops(string n) {
        name = n;
        studentCount = 0;
    }

    void addStudent(Student *s) {
        if (studentCount < 100) {
            students[studentCount++] = s;
            cout << "Student added to stop: " << name << endl;
        } else {
            cout << "Cannot add more students to stop: " << name << endl;
        }
    }

    void removeStudent(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == id) {
                for (int j = i; j < studentCount - 1; j++) {
                    students[j] = students[j + 1];
                }
                studentCount--;
                cout << "Student removed from stop: " << name << endl;
                return;
            }
        }
        cout << "Student not found in stop: " << name << endl;
    }

    string getName() { return name; }
};

class Bus {
private:
    int ID;
    Stops *stops[10];
    int stopCount;

public:
    Bus(int id) {
        ID = id;
        stopCount = 0;
    }

    void addStop(Stops *s) {
        if (stopCount < 10) {
            stops[stopCount++] = s;
            cout << "Stop added to bus: " << ID << endl;
        } else {
            cout << "Maximum number of stops reached for bus: " << ID << endl;
        }
    }

    void removeStop(string n) {
        for (int i = 0; i < stopCount; i++) {
            if (stops[i]->getName() == n) {
                for (int j = i; j < stopCount - 1; j++) {
                    stops[j] = stops[j + 1];
                }
                stopCount--;
                cout << "Stop removed from bus: " << ID << endl;
                return;
            }
        }
        cout << "Stop not found in bus: " << ID << endl;
    }

    void displayDetails() {
        cout << "Bus ID: " << ID << endl;
        if (stopCount == 0) {
            cout << "No stops assigned to this bus." << endl;
            return;
        }
        cout << "Stops: " << endl;
        for (int i = 0; i < stopCount; i++) {
            cout << stops[i]->getName() << endl;
        }
    }

    int getID() { return ID; }
};

class TransportSystem {
private:
    Student *students[100];
    Bus *buses[20];
    Stops *stops[100];
    int studentCount, busCount, stopCount;

public:
    TransportSystem() {
        studentCount = 0;
        busCount = 0;
        stopCount = 0;
    }

    ~TransportSystem() {
        for (int i = 0; i < studentCount; i++)
            delete students[i];
        for (int i = 0; i < busCount; i++)
            delete buses[i];
        for (int i = 0; i < stopCount; i++)
            delete stops[i];
    }

    void registerStudent(int id, string n) {
        if (studentCount < 100) {
            students[studentCount++] = new Student(id, n);
            cout << "Student registered: " << n << " (ID: " << id << ")" << endl;
        } else {
            cout << "Cannot register more students. Limit reached!" << endl;
        }
    }

    void addStop(string n) {
        if (stopCount < 100) {
            stops[stopCount++] = new Stops(n);
            cout << "Stop added: " << n << endl;
        } else {
            cout << "Cannot add more stops. Limit reached!" << endl;
        }
    }

    void addBus(int id) {
        if (busCount < 20) {
            buses[busCount++] = new Bus(id);
            cout << "Bus added: " << id << endl;
        } else {
            cout << "Cannot add more buses. Limit reached!" << endl;
        }
    }

    void addStopToBus(int busID, Stops *stop) {
        for (int i = 0; i < busCount; i++) {
            if (buses[i]->getID() == busID) {
                buses[i]->addStop(stop);
                return;
            }
        }
        cout << "Bus not found: " << busID << endl;
    }

    void assignPickUpStop(int id, string n) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == id) {
                for (int j = 0; j < stopCount; j++) {
                    if (stops[j]->getName() == n) {
                        students[i]->setPickUpStop(stops[j]);
                        stops[j]->addStudent(students[i]);
                        cout << "Pick-up stop assigned to student: " << students[i]->getName() << endl;
                        return;
                    }
                }
                cout << "Stop not found: " << n << endl;
                return;
            }
        }
        cout << "Student not found: " << id << endl;
    }

    void assignDropOffStop(int id, string n) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == id) {
                for (int j = 0; j < stopCount; j++) {
                    if (stops[j]->getName() == n) {
                        students[i]->setDropOffStop(stops[j]);
                        stops[j]->addStudent(students[i]);
                        cout << "Drop-off stop assigned to student: " << students[i]->getName() << endl;
                        return;
                    }
                }
                cout << "Stop not found: " << n << endl;
                return;
            }
        }
        cout << "Student not found: " << id << endl;
    }

    void attendence(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == id) {
                if (students[i]->getCardStatus()) {
                    cout << "Student " << students[i]->getName() << " is present." << endl;
                } else {
                    cout << "Student " << students[i]->getName() << "'s card is not active." << endl;
                }
                return;
            }
        }
        cout << "Student not found: " << id << endl;
    }

    void activeCard(int id) {
        for (int i = 0; i < studentCount; i++) {
            if (students[i]->getID() == id) {
                students[i]->payFees();
                cout << "Card activated for student: " << students[i]->getName() << endl;
                return;
            }
        }
        cout << "Student not found: " << id << endl;
    }

    void displayStudents() {
        if (studentCount == 0) {
            cout << "No students registered." << endl;
            return;
        }
        cout << "All Students:" << endl;
        for (int i = 0; i < studentCount; i++) {
            students[i]->displayDetail();
        }
    }

    void displayBuses() {
        if (busCount == 0) {
            cout << "No buses registered." << endl;
            return;
        }
        cout << "All Buses:" << endl;
        for (int i = 0; i < busCount; i++) {
            buses[i]->displayDetails();
        }
    }

    Stops *getStop(int index) {
        if (index >= 0 && index < stopCount)
            return stops[index];
        return nullptr;
    }
};

int main() {
    TransportSystem system;

    system.registerStudent(0, "Dawood");
    system.registerStudent(1, "Saad");

    system.addBus(1);
    system.addBus(2);

    system.addStop("Stop A");
    system.addStop("Stop B");
    system.addStopToBus(1, system.getStop(0));
    system.addStopToBus(2, system.getStop(1));

    system.assignPickUpStop(1, "Stop A");
    system.assignDropOffStop(1, "Stop B");
    system.assignPickUpStop(2, "Stop B");
    system.assignDropOffStop(2, "Stop A");

    system.activeCard(1);

    system.attendence(1);
    system.attendence(2);

    system.displayStudents();
    system.displayBuses();

    return 0;
}