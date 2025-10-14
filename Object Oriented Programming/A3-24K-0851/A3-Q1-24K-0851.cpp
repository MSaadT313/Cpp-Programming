#include <iostream>
#include <fstream>

using namespace std;

class TransportService;
class Driver
{
    string name;
    int age;
    string licenseNumber;

public:
    Driver() {}
    Driver(string n, int a, string l) : name(n), age(a), licenseNumber(l) {}

    void display()
    {
        cout << "Driver: " << name << "\n Age: " << age << "\n License: " << licenseNumber << endl;
    }

    void saveToFile(ofstream &out)
    {
        out << name << " " << age << " " << licenseNumber << endl;
    }

    void loadFromFile(ifstream &in)
    {
        in >> name >> age >> licenseNumber;
    }
};

class Route
{
    string start, end;
    float distance;
    bool longDistance;

public:
    Route() {}
    Route(string s, string e, float d) : start(s), end(e), distance(d)
    {
        if (distance > 30)
            longDistance = true;
        else
            longDistance = false;
    }
   
    void display()
    {
        cout << "Start point: " << start <<endl;
        cout << "End point: " << end <<endl;
        cout << "Distance: " << distance << endl;
        cout << (longDistance ? " (Long)" : " (Short)") << endl;
    }

    void saveToFile(ofstream &out)
    {
        out << start << " " << end << " " << distance << endl;
    }

    void loadFromFile(ifstream &in)
    {
        in >> start >> end >> distance;
        if (distance > 30)
            longDistance = true;
        else
            longDistance = false;
    }
};

class Vehicle
{
protected:
    int totalSeats;
    int studentSeats, facultySeats;
    int studentAvailable, facultyAvailable;
    bool isAC;
    Driver driver;
    Route *route;
    TransportService *transportService;

public:
    Vehicle() {}

    Vehicle(int t, int ss, int fs, bool ac, Driver d, Route *r,TransportService *ts) : totalSeats(t), studentSeats(ss), facultySeats(fs),
                                                                   studentAvailable(ss), facultyAvailable(fs), isAC(ac), driver(d), route(r),transportService(ts) {}

    virtual void display()
    {
        cout << "AC: " << (isAC ? "Yes" : "No") << endl;
        cout << "Total Seats: " << totalSeats << endl;
        cout << "Student Seats: " << studentSeats << " (Available: " << studentAvailable << ")" << endl;
        cout << "Faculty Seats: " << facultySeats << " (Available: " << facultyAvailable << ")" << endl;
        driver.display();
        route->display();
    }

    void setDriver(Driver d)
    {
        driver = d;
    }

    bool bookSeat(string userType)
    {
        if (userType == "student" && studentAvailable > 0)
        {
            studentAvailable--;
            return true;
        }
        else if (userType == "faculty" && facultyAvailable > 0)
        {
            facultyAvailable--;
            return true;
        }
        return false;
    }

    bool getACStatus()
    {
        return isAC;
    }

    void saveToFile(ofstream &out)
    {
        out << totalSeats << " " << studentSeats << " " << facultySeats << " ";
        out << studentAvailable << " " << facultyAvailable << " " << isAC << endl;
        driver.saveToFile(out);
        route->saveToFile(out);
    }

    void loadFromFile(ifstream &in)
    {
        int ac;
        in >> totalSeats >> studentSeats >> facultySeats >> studentAvailable >> facultyAvailable >> ac;
        isAC = ac;
        driver.loadFromFile(in);
        route->loadFromFile(in);
    }
};

class Bus : public Vehicle
{
public:
    Bus() {}
    Bus(bool ac, Driver d, Route *r,TransportService *ts) : Vehicle(52, 40, 12, ac, d, r,ts) {}
};

class Coaster : public Vehicle
{
public:
    Coaster() {}
    Coaster(bool ac, Driver d, Route *r ,TransportService *ts) : Vehicle(32, 26, 6, ac, d, r,ts) {}
};

class User
{
protected:
    int id;
    string name;
    bool paid;
    bool hasBooked;

public:
    User() {}
    User(int i, string n, bool p) : id(i), name(n), paid(p), hasBooked(false) {}

    virtual void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout <<"Payment: " << (paid ? "Done" : "Pending") << endl;
    }

    virtual int calculateFare(bool ac) = 0;
    virtual string getType() = 0;

    bool canBook()
    {
        return paid && !hasBooked;
    }

    void markBooked()
    {
        hasBooked = true;
    }

    int getId()
    {
        return id;
    }

    void saveToFile(ofstream &out)
    {
        out << id << " " << name << " " << paid << " " << hasBooked << endl;
    }

    void loadFromFile(ifstream &in)
    {
        in >> id >> name >> paid >> hasBooked;
    }
};

class Student : public User
{
public:
    Student() {}
    Student(int i, string n, bool p) : User(i, n, p) {}

    int calculateFare(bool ac)
    {
        int base = 1000;
        if (ac)
            base += 2000;
        return base;
    }

    string getType()
    {
        return "student";
    }
};

class Faculty : public User
{
public:
    Faculty() {}
    Faculty(int i, string n, bool p) : User(i, n, p) {}

    int calculateFare(bool ac)
    {
        int base = 2000;
        if (ac)
            base += 2000;
        return base;
    }

    string getType()
    {
        return "faculty";
    }
};

class Booking
{
public:
    static void makeBooking(User *user, Vehicle *vehicle)
    {
        if (!user->canBook())
        {
            throw string("Booking failed: Payment not completed or already booked.");
        }

        bool success = vehicle->bookSeat(user->getType());
        if (!success)
        {
            throw string("Booking failed: No seat available for this role.");
        }

        int fare = user->calculateFare(vehicle->getACStatus());
        cout << "Booking confirmed. Fare: " << fare << endl;
        user->markBooked();
    }
};

class TransportService
{
    Vehicle *vehicles[10];
    User *users[10];
    int vehicleCount;
    int userCount;

public:
    TransportService()
    {
        vehicleCount = 0;
        userCount = 0;
    }

    void addVehicle(Vehicle *v)
    {
        if (vehicleCount < 10)
        {
            vehicles[vehicleCount++] = v;
        }
        else{
            cout << "Vehicle limit reached." << endl;
        }
    }

    void registerUser(User *u)
    {
        if (userCount < 10)
        {
            users[userCount++] = u;
        }
        else{
            cout << "User limit reached." << endl;
        }
    }

    User *findUser(int id)
    {
        for (int i = 0; i < userCount; i++)
        {
            if (users[i]->getId() == id)
                return users[i];
        }
        throw string("User not found.");
    }

    Vehicle *getVehicle(int index)
    {
        if (index >= 0 && index < vehicleCount)
            return vehicles[index];
        throw string("Invalid vehicle index.");
    }

    void saveData()
    {
        ofstream out("vehicles.txt");
        out << vehicleCount << endl;
        for (int i = 0; i < vehicleCount; i++)
        {
            vehicles[i]->saveToFile(out);
        }
        out.close();

        ofstream uout("users.txt");
        uout << userCount << endl;
        for (int i = 0; i < userCount; i++)
        {
            users[i]->saveToFile(uout);
        }
        uout.close();
    }

    void loadData()
    {
        ifstream in("vehicles.txt");
        if (in)
        {
            in >> vehicleCount;
            for (int i = 0; i < vehicleCount; i++)
            {
                Bus *b = new Bus();
                b->loadFromFile(in);
                vehicles[i] = b;
            }
            in.close();
        }

        ifstream uin("users.txt");
        if (uin)
        {
            uin >> userCount;
            for (int i = 0; i < userCount; i++)
            {
                int id;
                string name;
                bool paid, booked;
                uin >> id >> name >> paid >> booked;
                if (id < 1000)
                    users[i] = new Student(id, name, paid);
                else
                    users[i] = new Faculty(id, name, paid);
            }
            uin.close();
        }
    }

    void displayAll()
    {
        cout << "    Vehicles " << endl;
        for (int i = 0; i < vehicleCount; i++)
        {
            vehicles[i]->display();
            cout << "\n\n" << endl;
        }

        cout << "    Users" << endl;
        for (int i = 0; i < userCount; i++)
        {
            users[i]->display();
        }
    }
};

int main()
{
    cout << "Muhammad Saad Tahir" << endl;
    cout << "24K-0851" << endl;
    TransportService ts;

    Driver d1("Ali", 40, "L123");
    Driver d2("Ahmed", 35, "L456");
    Route r1("Gulshan", "FAST", 35);
    Vehicle *v1 = new Bus(true, d1, &r1, &ts);
    v1->setDriver(d2);
    ts.addVehicle(v1);

    User *s1 = new Student(1, "Ahmed", true);
    User *f1 = new Faculty(1001, "Dr. Khan", true);

    ts.registerUser(s1);
    ts.registerUser(f1);

    try
    {
        Booking::makeBooking(s1, v1);
        Booking::makeBooking(f1, v1);
    }
    catch (string e)
    {
        cout << e << endl;
    }

    ts.displayAll();
    ts.saveData();

    return 0;
}
