#include <iostream>
#include <string>

using namespace std;

class Appointment {
private:
    string customerName;
    string appointmentDate;
    double cost;

    static int totalAppointments;
    static double totalEarnings;

public:
    Appointment(string name, string date, double appointmentCost)
        : customerName(name), appointmentDate(date), cost(appointmentCost) {
        totalAppointments++;
        totalEarnings += cost;
    }

    string getCustomerName() const { return customerName; }
    string getAppointmentDate() const { return appointmentDate; }
    double getCost() const { return cost; }

    static double calculateAverageCost() {
        return (totalAppointments == 0) ? 0 : totalEarnings / totalAppointments;
    }

    static int getTotalAppointments() { return totalAppointments; }

    static double getTotalEarnings() { return totalEarnings; }
};

int Appointment::totalAppointments = 0;
double Appointment::totalEarnings = 0.0;

int main() {
    Appointment a1("Alice", "2025-02-15", 50.0);
    Appointment a2("Bob", "2025-02-16", 70.0);
    Appointment a3("Charlie", "2025-02-17", 60.0);

    cout << "Total Appointments: " << Appointment::getTotalAppointments() << endl;
    cout << "Total Earnings: $" << Appointment::getTotalEarnings() << endl;
    cout << "Average Cost per Appointment: $" << Appointment::calculateAverageCost() << endl;

    return 0;
}
