#include <iostream>
#include <string>
using namespace std;
class Stops;
class Passengers
{
protected:
    int ID;
    string name;
    bool cardStatus;
    Stops *pickUpStop;
    Stops *dropOffStop;

public:
    Passengers(int id, string n) : ID(id), name(n), cardStatus(false), pickUpStop(nullptr), dropOffStop(nullptr) {}

    virtual void displayDetail() = 0;
    virtual void payFees() = 0;

    void setPickUpStop(Stops *s) { pickUpStop = s; }
    void setDropOffStop(Stops *s) { dropOffStop = s; }
    int getID() const { return ID; }
    string getName() const { return name; }
    bool getCardStatus() const { return cardStatus; }

    virtual ~Passengers() {}
    friend ostream &operator<<(ostream &os, const Passengers &user)
    {
        os << "ID: " << user.ID << ", Name: " << user.name;
        return os;
    }
};

class Student : public Passengers
{
private:
    int semester;
    bool semesterfees[8];

public:
    Student(int id, string n, int sem) : Passengers(id, n), semester(sem)
    {
        for (int i = 0; i < 8; i++)
            semesterfees[i] = false;
    }
    void payFees() override
    {
        semesterfees[semester] = true;
        cardStatus = true;
    }
    void displayDetail() override
    {
        cout << "Student - ID: " << ID << ", Name: " << name
             << ", Semester: " << semester
             << ", Fee Paid: " << (semesterfees[semester] ? "Yes" : "No")
             << ", Card: " << (cardStatus ? "Active" : "Not Active") << endl;
    }
};

class Teacher : public Passengers
{
private:
    int num_month;
    bool paidmonths[12];

public:
    Teacher(int id, string n, int month) : Passengers(id, n), num_month(month)
    {
        for (int i = 0; i < 12; i++)
            paidmonths[i] = false;
    }
    void payFees() override
    {
        paidmonths[num_month] = true;
        cardStatus = true;
    }
    void displayDetail() override
    {
        cout << "Teacher - ID: " << ID << ", Name: " << name
             << ", Month: " << num_month
             << ", Fee Paid: " << (paidmonths[num_month] ? "Yes" : "No")
             << ", Card: " << (cardStatus ? "Active" : "Not Active") << endl;
    }
};
class StaffMember : public Passengers
{
private:
    int num_month;
    bool paidmonths[12];

public:
    StaffMember(int id, string n, int month) : Passengers(id, n), num_month(month)
    {
        for (int i = 0; i < 12; i++)
            paidmonths[i] = false;
    }
    void payFees() override
    {
        paidmonths[num_month] = true;
        cardStatus = true;
    }
    void displayDetail() override
    {
        cout << "StaffID: " << ID << ", Name: " << name
             << ", Month: " << num_month
             << ", Fee Paid: " << (paidmonths[num_month] ? "Yes" : "No")
             << ", Card: " << (cardStatus ? "Active" : "Not Active") << endl;
    }
};

class Stops
{
private:
    string name;

public:
    Stops(string n) : name(n) {}
    string getName() { return name; }
};

class TransportSystem
{
private:
    Passengers *users[100];
    Stops *stops[100];
    int usercount, stopcount;

public:
    TransportSystem() : usercount(0), stopcount(0) {}

    ~TransportSystem()
    {
        for (int i = 0; i < usercount; i++)
            delete users[i];
        for (int i = 0; i < stopcount; i++)
            delete stops[i];
    }

    void registerstudent(int id, string n, int semester)
    {
        if (usercount < 100)
        {
            users[usercount++] = new Student(id, n, semester);
            cout << "Student registered: " << n << ", ID: " << id << endl;
        }
    }

    void registerTeacher(int id, string n, int month)
    {
        if (usercount < 100)
        {
            users[usercount++] = new Teacher(id, n, month);
            cout << "Teacher registered: " << n << ", ID: " << id << endl;
        }
    }

    void registerStaff(int id, string n, int month)
    {
        if (usercount < 100)
        {
            users[usercount++] = new StaffMember(id, n, month);
            cout << "Staff member registered: " << n << ", ID: " << id << endl;
        }
    }

    void addStop(string n)
    {
        if (stopcount < 100)
        {
            stops[stopcount++] = new Stops(n);
            cout << "Stop added: " << n << endl;
        }
    }

    void activateCard(int id)
    {
        for (int i = 0; i < usercount; i++)
        {
            if (users[i]->getID() == id)
            {
                users[i]->payFees();
                cout << "Card activated for: " << users[i]->getName() << endl;
                return;
            }
        }
        cout << "User not found: " << id << endl;
    }

    void attendance(int id)
    {
        for (int i = 0; i < usercount; i++)
        {
            if (users[i]->getID() == id)
            {
                if (users[i]->getCardStatus())
                {
                    cout << users[i]->getName() << " is present." << endl;
                }
                else
                {
                    cout << users[i]->getName() << "'s card is not active." << endl;
                }
                return;
            }
        }
        cout << "User not found: " << id << endl;
    }

    void displayUsers()
    {
        if (usercount == 0)
        {
            cout << "No users registered." << endl;
            return;
        }
        for (int i = 0; i < usercount; i++)
        {
            users[i]->displayDetail();
        }
    }
};
int main()
{
    TransportSystem system;
    system.registerstudent(1, "Ali", 2);
    system.registerTeacher(2, "Sir Ahmed", 3);
    system.registerStaff(3, "Mr.Usman", 3);

    system.addStop("karsaz");
    system.activateCard(1);
    system.activateCard(2);
    system.activateCard(3);

    system.attendance(1);
    system.attendance(2);
    system.attendance(3);

    system.displayUsers();
    return 0;
}