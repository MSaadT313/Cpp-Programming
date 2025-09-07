```cpp
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>
#include <stdexcept>
#include <limits> // Required for numeric_limits

using namespace std;

// Forward declarations
class route;
class transporter;
class vehicle;
class user;
class driver;
class booking;

// Management template class (defined later)
template <typename T>
class Management;

class user {
protected:
    string name;
    int id;
    string type;

public:
    string pickup_address;
    string CNIC;
    bool payment_status;
    int phone_number; // Changed to int as per original code, consider string for robustness
    int monthly_bookings; // Counter for bookings in the current month
    time_t last_booking_date; // Timestamp of the last booking

public:
    user() : id(0), payment_status(false), monthly_bookings(0), last_booking_date(0), phone_number(0) {} // Initialize phone_number

    user(string n, int i, string t, string p, string c, int ph)
        : name(n), id(i), type(t), pickup_address(p), CNIC(c), phone_number(ph),
          payment_status(false), monthly_bookings(0), last_booking_date(0) {}

    virtual ~user() = default; // Virtual destructor for polymorphism

    string getType() const {
        return type;
    }

    // Check if the user can book a seat
    bool can_book() {
        time_t now = time(nullptr);
        tm* current_time = localtime(&now);
        tm* last_booking_time = localtime(&last_booking_date);

        // Reset monthly bookings if the month has changed
        if (last_booking_date == 0 || current_time->tm_mon != last_booking_time->tm_mon) {
            monthly_bookings = 0;
        }

        return monthly_bookings < 1; // Limit to 1 booking per month
    }

    // Increment the booking count
    void increment_booking_count() {
        if (!can_book()) {
            throw runtime_error("Monthly booking limit reached!");
        }
        monthly_bookings++;
        last_booking_date = time(nullptr); // Update the last booking date
    }

    void make_payment() {
        payment_status = true;
        cout << "Payment completed for user: " << name << endl;
    }

    bool has_paid() const {
        return payment_status;
    }

    virtual void get_user_details() const {
        cout << "Name: " << name << ", ID: " << id << ", Type: " << type << endl;
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }

    // Need a forward declaration or full definition of vehicle to calculate fare
    int calculate_user_fare(int base_fare, const vehicle& v) const;

    void validate_user_data() const {
        if (name.empty() || CNIC.empty() || phone_number <= 0) {
            throw runtime_error("Invalid user data!");
        }
    }

    virtual void save_to_file(ofstream& out) const = 0; // Make it pure virtual

    virtual void load_from_file(ifstream& in) {
        string line;
        if (getline(in, line)) {
            stringstream ss(line);
            getline(ss, type, ',');
            getline(ss, name, ',');
            ss >> id;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            getline(ss, pickup_address, ',');
            getline(ss, CNIC, ',');
            ss >> phone_number;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> monthly_bookings;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> last_booking_date;
        }
    }
};

class Student : public user {
    int roll_number;
    string email_address;

public:
    Student() : roll_number(0), email_address("") {
        type = "Student";
    }

    void save_to_file(ofstream& out) const override {
        out << "Student," << name << "," << id << "," << pickup_address << "," << CNIC << ","
            << phone_number << "," << monthly_bookings << "," << last_booking_date << ","
            << roll_number << "," << email_address << endl;
    }

    void load_from_file(ifstream& in) override {
        user::load_from_file(in); // Load base class members
        string line;
        // Need to re-read the line or pass the stringstream from the base class
        // For simplicity, let's assume the base class reads up to last_booking_date
        // and the derived class reads the rest of the line.
        // A better approach would be to pass the stringstream.
        // Assuming the file format is consistent:
        ifstream temp_in(in.tellg()); // Create a temporary stream to read the rest of the line
        string rest_of_line;
        if (getline(temp_in, rest_of_line)) {
             stringstream ss(rest_of_line);
             // Skip the parts read by the base class
             string dummy;
             getline(ss, dummy, ','); // Type
             getline(ss, dummy, ','); // Name
             getline(ss, dummy, ','); // ID
             getline(ss, dummy, ','); // pickup_address
             getline(ss, dummy, ','); // CNIC
             getline(ss, dummy, ','); // phone_number
             getline(ss, dummy, ','); // monthly_bookings
             getline(ss, dummy, ','); // last_booking_date

             ss >> roll_number;
             ss.ignore(numeric_limits<streamsize>::max(), ',');
             getline(ss, email_address); // Read till end of line
        }
    }

    void add_student() {
        cout << "Enter the name of the student: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, name);
        cout << "Enter the ID of the student: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Enter the pickup address of the student: ";
        getline(cin, pickup_address);
        cout << "Enter CNIC of the student: ";
        getline(cin, CNIC);
        cout << "Enter phone number of the student: ";
        cin >> phone_number;
        cout << "Enter the roll number of the student: ";
        cin >> roll_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Enter the email address of the student: ";
        getline(cin, email_address);
        type = "Student";
        cout << "Student details entered." << endl;
    }

    void show_student_details() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Pickup Address: " << pickup_address << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Roll Number: " << roll_number << endl;
        cout << "Email Address: " << email_address << endl;
    }

    int get_roll_number() const {
        return roll_number;
    }

    void set_roll_number(int roll) {
        roll_number = roll;
    }

    string get_email_address() const {
        return email_address;
    }

    void set_email_address(const string& email) {
        email_address = email;
    }

    void displayDetails() const override { // Override displayDetails
        show_student_details();
    }
};

class Faculty : public user {
public:
    string department;
    string designation;

    Faculty() : department(""), designation("") {
        type = "Faculty";
    }

    void save_to_file(ofstream& out) const override {
        out << "Faculty," << name << "," << id << "," << pickup_address << "," << CNIC << ","
            << phone_number << "," << monthly_bookings << "," << last_booking_date << ","
            << department << "," << designation << endl;
    }

    void load_from_file(ifstream& in) override {
        user::load_from_file(in); // Load base class members
        string line;
         ifstream temp_in(in.tellg()); // Create a temporary stream to read the rest of the line
        string rest_of_line;
        if (getline(temp_in, rest_of_line)) {
             stringstream ss(rest_of_line);
             // Skip the parts read by the base class
             string dummy;
             getline(ss, dummy, ','); // Type
             getline(ss, dummy, ','); // Name
             getline(ss, dummy, ','); // ID
             getline(ss, dummy, ','); // pickup_address
             getline(ss, dummy, ','); // CNIC
             getline(ss, dummy, ','); // phone_number
             getline(ss, dummy, ','); // monthly_bookings
             getline(ss, dummy, ','); // last_booking_date

             getline(ss, department, ',');
             getline(ss, designation); // Read till end of line
        }
    }

    void add_faculty() {
        cout << "Enter the name of the faculty: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, name);
        cout << "Enter the ID of the faculty: ";
        cin >> id;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Enter the pickup address of the faculty: ";
        getline(cin, pickup_address);
        cout << "Enter CNIC of the faculty: ";
        getline(cin, CNIC);
        cout << "Enter phone number of the faculty: ";
        cin >> phone_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Enter the department of the faculty: ";
        getline(cin, department);
        cout << "Enter the designation of the faculty: ";
        getline(cin, designation);
        type = "Faculty";
        cout << "Faculty details entered." << endl;
    }

    void show_faculty_details() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Pickup Address: " << pickup_address << endl;
        cout << "CNIC: " << CNIC << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Department: " << department << endl;
        cout << "Designation: " << designation << endl;
    }

    string get_department() const {
        return department;
    }

    string get_designation() const {
        return designation;
    }

    void displayDetails() const override { // Override displayDetails
        show_faculty_details();
    }
};

class driver : public user {
    transporter* assigned_transporter; // Aggregation
    vehicle* assigned_vehicle; // Aggregation
    route* assigned_route; // Aggregation
    bool valid_lisense;

public:
    driver() : valid_lisense(false), assigned_transporter(nullptr), assigned_vehicle(nullptr), assigned_route(nullptr) {
        type = "Driver";
    }

    driver(string n, int i, string p, string c, int ph, bool lisense)
        : user(n, i, "Driver", p, c, ph), valid_lisense(lisense), assigned_transporter(nullptr), assigned_vehicle(nullptr), assigned_route(nullptr) {}

    driver(const driver& d) : user(d), valid_lisense(d.valid_lisense), assigned_transporter(d.assigned_transporter), assigned_vehicle(d.assigned_vehicle), assigned_route(d.assigned_route) {}

    void save_to_file(ofstream& out) const override {
        out << "Driver," << name << "," << id << "," << pickup_address << "," << CNIC << ","
            << phone_number << "," << monthly_bookings << "," << last_booking_date << ","
            << valid_lisense << endl;
    }

    void load_from_file(ifstream& in) override {
        user::load_from_file(in); // Load base class members
        string line;
         ifstream temp_in(in.tellg()); // Create a temporary stream to read the rest of the line
        string rest_of_line;
        if (getline(temp_in, rest_of_line)) {
             stringstream ss(rest_of_line);
             // Skip the parts read by the base class
             string dummy;
             getline(ss, dummy, ','); // Type
             getline(ss, dummy, ','); // Name
             getline(ss, dummy, ','); // ID
             getline(ss, dummy, ','); // pickup_address
             getline(ss, dummy, ','); // CNIC
             getline(ss, dummy, ','); // phone_number
             getline(ss, dummy, ','); // monthly_bookings
             getline(ss, dummy, ','); // last_booking_date

             ss >> valid_lisense;
        }
    }

    // Method to add driver details
    void add_details() {
        cout << "Enter the name of the driver: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, name);
        cout << "Enter the ID of the driver: ";
        cin >> id;
        cout << "Enter phone number of the driver: ";
        cin >> phone_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Enter CNIC of the driver: ";
        getline(cin, CNIC);
        cout << "Enter license status of the driver (1 for valid, 0 for invalid): ";
        cin >> valid_lisense;
        type = "Driver";
        cout << "Driver details entered." << endl;
    }

    // Method to display driver details
    void show_details() const {
        cout << "Name of the driver: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone number of the driver: " << phone_number << endl;
        cout << "CNIC of the driver: " << CNIC << endl;
        cout << "License status of the driver: " << (valid_lisense ? "Valid" : "Invalid") << endl;
    }

    void displayDetails() const override { // Override displayDetails
        show_details();
    }
};

class vehicle {
protected:
    string vehicle_number;
    string vehicle_type;
    int capacity;
    bool is_ac;
    driver* assigned_driver; // Aggregation
    route* assigned_route; // Aggregation
    vector<string> seats; // Use vector instead of fixed-size array

public:
    vehicle(string vnum, string vtype, int cap, bool ac)
        : vehicle_number(vnum), vehicle_type(vtype), capacity(cap), is_ac(ac),
          assigned_driver(nullptr), assigned_route(nullptr), seats(cap, "") {
    }

    virtual ~vehicle() = default;

    string getId() const {
        return vehicle_number; // Use vehicle_number as the unique identifier
    }

    virtual int calculateFare() const = 0; // Abstract method for fare calculation

    // Book a seat for a specific user type
    bool book_seat(int seat_number, const string& userType) {
        if (seat_number < 0 || seat_number >= capacity) {
            throw runtime_error("Invalid seat number!");
        }
        if (!seats[seat_number].empty()) {
            throw runtime_error("Seat is already occupied!");
        }

        // Enforce role-based seat allocation
        if (userType == "Student" && seat_number >= capacity / 2) {
            throw runtime_error("Students can only book seats in the first half of the vehicle!");
        }
        if (userType == "Faculty" && seat_number < capacity / 2) {
            throw runtime_error("Faculty can only book seats in the second half of the vehicle!");
        }

        // Mark the seat as occupied with the user type
        seats[seat_number] = userType;
        cout << "Seat " << seat_number + 1 << " successfully booked for " << userType << "." << endl;
        return true;
    }

    // Cancel a seat booking
    void cancel_seat(int seat_number) {
        if (seat_number < 0 || seat_number >= capacity) {
            throw runtime_error("Invalid seat number!");
        }
        if (seats[seat_number].empty()) {
            throw runtime_error("Seat is not currently booked!");
        }

        // Mark the seat as available
        seats[seat_number] = "";
        cout << "Seat " << seat_number + 1 << " booking canceled." << endl;
    }

    // Display the seat map
    void displaySeatMap() const {
        cout << "Seat Map for Vehicle " << vehicle_number << ":" << endl;
        for (int i = 0; i < capacity; i++) {
            cout << "Seat " << i + 1 << ": "
                 << (seats[i].empty() ? "Available" : seats[i]) << endl;
        }
    }

    // Assign a driver to the vehicle
    void assign_driver(driver* d) {
        assigned_driver = d;
        cout << "Driver assigned to vehicle: " << vehicle_number << endl;
    }

    // Assign a route to the vehicle
    void assign_route(route* r) {
        assigned_route = r;
        cout << "Route assigned to vehicle: " << vehicle_number << endl;
    }

    // Get the assigned route
    route* getAssignedRoute() const {
        return assigned_route;
    }

    int getAssignedDriverId() const {
        return assigned_driver ? assigned_driver->getId() : -1;
    }

    int getAssignedRouteId() const {
        return assigned_route ? assigned_route->getId() : -1;
    }

    virtual void save_to_file(ofstream& out) {
        out << vehicle_type << "," << vehicle_number << "," << capacity << "," << is_ac << ","
            << getAssignedDriverId() << ","
            << getAssignedRouteId() << endl;
    }

    virtual void load_from_file(ifstream& in) {
        string line;
        if (getline(in, line)) {
            stringstream ss(line);
            getline(ss, vehicle_type, ',');
            getline(ss, vehicle_number, ',');
            ss >> capacity;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> is_ac;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            int driverId, routeId;
            ss >> driverId;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> routeId;
            setAssignedDriverId(driverId);
            setAssignedRouteId(routeId);
            seats.resize(capacity, ""); // Resize seats after loading capacity
        }
    }

    void setAssignedDriverId(int driverId) {
        // This method needs access to the driver management system to find and assign the driver object
        // For now, it's a placeholder. The actual assignment will happen in connectRelationships.
        cout << "Assigned driver ID: " << driverId << " to vehicle " << vehicle_number << " (needs connecting)" << endl;
    }

    void setAssignedRouteId(int routeId) {
        // This method needs access to the route management system to find and assign the route object
        // For now, it's a placeholder. The actual assignment will happen in connectRelationships.
        cout << "Assigned route ID: " << routeId << " to vehicle " << vehicle_number << " (needs connecting)" << endl;
    }

    void displayDetails() const {
        cout << "Vehicle Number: " << vehicle_number << endl;
        cout << "Vehicle Type: " << vehicle_type << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "AC: " << (is_ac ? "Yes" : "No") << endl;
        if (assigned_driver) {
            cout << "Assigned Driver ID: " << assigned_driver->getId() << endl;
        }
        if (assigned_route) {
            cout << "Assigned Route ID: " << assigned_route->getId() << endl;
        }
        displaySeatMap();
    }
};

class bus : public vehicle {
public:
    // Constructor for bus, initializing the base class with 52 seats
    bus(string vnum, bool ac) : vehicle(vnum, "Bus", 52, ac) {}

    bus() : vehicle("", "Bus", 52, false) {} // Default constructor for loading

    // Override the fare calculation for buses
    int calculateFare() const override {
        int baseFare = 3000; // Base fare for buses
        return baseFare + (is_ac ? 2000 : 0); // Add AC charge if applicable
    }

    void save_to_file(ofstream& out) override {
        vehicle::save_to_file(out);
    }

    void load_from_file(ifstream& in) override {
        vehicle::load_from_file(in);
    }
};

class coaster : public vehicle {
public:
    // Constructor for coaster, initializing the base class with 32 seats
    coaster(string vnum, bool ac) : vehicle(vnum, "Coaster", 32, ac) {}

    coaster() : vehicle("", "Coaster", 32, false) {} // Default constructor for loading

    // Override the fare calculation for coasters
    int calculateFare() const override {
        int baseFare = 2000; // Base fare for coasters
        return baseFare + (is_ac ? 1500 : 0); // Add AC charge if applicable
    }

    void save_to_file(ofstream& out) override {
        vehicle::save_to_file(out);
    }

    void load_from_file(ifstream& in) override {
        vehicle::load_from_file(in);
    }
};

// Implementation of user::calculate_user_fare after vehicle is defined
int user::calculate_user_fare(int base_fare, const vehicle& v) const {
    int fare = v.calculateFare();
    if (type == "Faculty") {
        fare -= 5000; // Faculty discount
    }
    return fare;
}


class route {
    string start_location;
    string end_location;
    int distance;
    bool is_long_distance;
    int id; // Unique identifier for the route

public:
    route(string start, string end, int dist, int route_id)
        : start_location(start), end_location(end), distance(dist), id(route_id) {
        is_long_distance = (distance > 40); // Threshold for long distance
    }

    route() : start_location(""), end_location(""), distance(0), is_long_distance(false), id(0) {} // Default constructor for loading

    int getId() const { return id; } // Getter for the route ID

    // Method to display route details
    void get_route_details() const {
        cout << "Route Details (ID: " << id << "):" << endl;
        cout << "Start Location: " << start_location << endl;
        cout << "End Location: " << end_location << endl;
        cout << "Distance: " << distance << " km" << endl;
        cout << "Route Type: " << (is_long_distance ? "Long Distance" : "Short Distance") << endl;
    }

    // Getter methods for route attributes
    string get_start_location() const { return start_location; }
    string get_end_location() const { return end_location; }
    int get_distance() const { return distance; }
    bool get_is_long_distance() const { return is_long_distance; }

    void save_to_file(ofstream& out) {
        out << id << "," << start_location << "," << end_location << "," << distance << endl;
    }

    void load_from_file(ifstream& in) {
        string line;
        if (getline(in, line)) {
            stringstream ss(line);
            ss >> id;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            getline(ss, start_location, ',');
            getline(ss, end_location, ',');
            ss >> distance;
            is_long_distance = (distance > 40);
        }
    }

    void displayDetails() const {
        get_route_details();
    }
};

class transporter : public user {
    string password;
    // Consider removing number_of_bus, number_of_coaster, number_of_driver
    // as this information should be managed by the TransportSystem or Management classes
    int number_of_bus;
    int number_of_coaster;
    int number_of_driver;

public:
    transporter() : password(""), number_of_bus(0), number_of_coaster(0), number_of_driver(0) {
        type = "Transporter";
    }

    void save_to_file(ofstream& out) const override {
        out << "Transporter," << name << "," << id << "," << pickup_address << "," << CNIC << ","
            << phone_number << "," << monthly_bookings << "," << last_booking_date << ","
            << password << "," << number_of_bus << "," << number_of_coaster << "," << number_of_driver << endl;
    }

    void load_from_file(ifstream& in) override {
        user::load_from_file(in); // Load base class members
        string line;
         ifstream temp_in(in.tellg()); // Create a temporary stream to read the rest of the line
        string rest_of_line;
        if (getline(temp_in, rest_of_line)) {
             stringstream ss(rest_of_line);
             // Skip the parts read by the base class
             string dummy;
             getline(ss, dummy, ','); // Type
             getline(ss, dummy, ','); // Name
             getline(ss, dummy, ','); // ID
             getline(ss, dummy, ','); // pickup_address
             getline(ss, dummy, ','); // CNIC
             getline(ss, dummy, ','); // phone_number
             getline(ss, dummy, ','); // monthly_bookings
             getline(ss, dummy, ','); // last_booking_date

             getline(ss, password, ',');
             ss >> number_of_bus;
             ss.ignore(numeric_limits<streamsize>::max(), ',');
             ss >> number_of_coaster;
             ss.ignore(numeric_limits<streamsize>::max(), ',');
             ss >> number_of_driver;
        }
    }

    void add_driver() {
        cout << "Enter the number of drivers to add: ";
        cin >> number_of_driver;

        // This method should ideally use the Management system to add drivers
        // and not directly write to a file here to maintain consistency.
        // Placeholder for the logic to interact with the driver management system.
        cout << "Adding " << number_of_driver << " drivers (implementation needed)." << endl;
    }

    void displayDetails() const override { // Override displayDetails
        get_user_details();
        cout << "Password: " << password << endl;
        cout << "Number of Buses: " << number_of_bus << endl;
        cout << "Number of Coasters: " << number_of_coaster << endl;
        cout << "Number of Drivers: " << number_of_driver << endl;
    }
};

class booking {
    user* booked_user; // Aggregation
    vehicle* booked_vehicle; // Aggregation
    route* booked_route; // Aggregation
    int seat_number;
    int fare;
    time_t booking_date;
    int booking_id; // Unique identifier for the booking

public:
    booking(user* u, vehicle* v, route* r, int seat, int base_fare, int id)
        : booked_user(u), booked_vehicle(v), booked_route(r), seat_number(seat), booking_id(id) {
        booking_date = time(nullptr); // Store the current date

        // Check if the user can book
        if (!u->can_book()) {
            throw runtime_error("User has reached the monthly booking limit!");
        }
         if (!u->has_paid()) {
            throw runtime_error("User has not made payment!");
        }

        // Book the seat
        if (!v->book_seat(seat, u->getType())) {
            throw runtime_error("Seat booking failed!");
        }

        // Calculate fare and increment booking count
        fare = u->calculate_user_fare(base_fare, *v);
        u->increment_booking_count();
        cout << "Booking successful for user: " << u->getName() << endl;
    }

    booking() : booked_user(nullptr), booked_vehicle(nullptr), booked_route(nullptr), seat_number(0), fare(0), booking_date(0), booking_id(0) {} // Default constructor for loading

    int getId() const { return booking_id; }

    void cancel_booking() {
        if (booked_vehicle) {
            booked_vehicle->cancel_seat(seat_number);
            cout << "Booking canceled for seat " << seat_number + 1 << "." << endl;
        } else {
            throw runtime_error("No vehicle associated with this booking!");
        }
    }

    // Save booking data to file
    void save_to_file(ofstream& out) {
        out << booking_id << "," << (booked_user ? booked_user->getId() : -1) << ","
            << (booked_vehicle ? booked_vehicle->getId() : "") << ","
            << (booked_route ? booked_route->getId() : -1) << ","
            << seat_number << "," << fare << "," << booking_date << endl;
    }

    // Load booking data from file
    void load_from_file(ifstream& in) {
        string line;
        if (getline(in, line)) {
            stringstream ss(line);
            int userId, routeId;
            string vehicleId_str;

            ss >> booking_id;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> userId;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            getline(ss, vehicleId_str, ',');
            ss >> routeId;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> seat_number;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> fare;
            ss.ignore(numeric_limits<streamsize>::max(), ',');
            ss >> booking_date;

            set_user_id(userId);
            set_vehicle_id_str(vehicleId_str);
            set_route_id(routeId);
        }
    }

    void set_user_id(int userId) {
        // Placeholder for setting the user ID
        // The actual user object will be linked in connectRelationships
        cout << "User ID set to: " << userId << " for booking " << booking_id << " (needs connecting)" << endl;
    }

    void set_vehicle_id_str(const string& vehicleId_str) {
        // Placeholder for setting the vehicle ID string
        // The actual vehicle object will be linked in connectRelationships
        cout << "Vehicle ID string set to: " << vehicleId_str << " for booking " << booking_id << " (needs connecting)" << endl;
    }

    void set_route_id(int routeId) {
        // Placeholder for setting the route ID
        // The actual route object will be linked in connectRelationships
        cout << "Route ID set to: " << routeId << " for booking " << booking_id << " (needs connecting)" << endl;
    }

    int getUserId() const { return booked_user ? booked_user->getId() : -1; }
    string getVehicleId() const { return booked_vehicle ? booked_vehicle->getId() : ""; }
    int getRouteId() const { return booked_route ? booked_route->getId() : -1; }

    void setRelationships(user* u, vehicle* v, route* r) {
        booked_user = u;
        booked_vehicle = v;
        booked_route = r;
    }

    void displayDetails() const {
        cout << "Booking ID: " << booking_id << endl;
        if (booked_user) {
            cout << "Booked User: " << booked_user->getName() << " (ID: " << booked_user->getId() << ")" << endl;
        }
        if (booked_vehicle) {
            cout << "Booked Vehicle: " << booked_vehicle->getId() << endl;
        }
        if (booked_route) {
            cout << "Booked Route: " << booked_route->getId() << endl;
        }
        cout << "Seat Number: " << seat_number + 1 << endl;
        cout << "Fare: " << fare << endl;
        cout << "Booking Date: " << ctime(&booking_date);
    }
};


template <typename T>
class Management {
private:
    vector<T*> items;
    int nextId = 1; // For generating unique IDs if the type T doesn't have one

    // Helper to get the ID, assuming T has a getId() or similar
    // This requires specialization or concepts if getId() is not universal
    auto getItemId(T* item) const {
        // Default implementation, assumes T has getId()
        return item->getId();
    }

public:
    // Add an item to the management system
    void addItem(T* item) {
        // If the item needs an ID assigned, assign it here.
        // This depends on whether T manages its own ID or if the Management system should.
        // For simplicity, assuming T has an ID and it's set before adding.
        items.push_back(item);
        cout << "Item added to management." << endl;
    }

    // Get all items in the management system
    const vector<T*>& getItems() const {
        return items;
    }

    // Find an item by integer ID
    T* findItem(int id) {
        for (auto item : items) {
            // Check if the item has an integer ID
            if constexpr (is_integral_v<decltype(getItemId(item))>) {
                if (getItemId(item) == id) {
                    return item;
                }
            }
        }
        // Consider returning nullptr or a unique_ptr for better error handling
        throw runtime_error("Item with ID " + to_string(id) + " not found!");
    }

    // Find an item by string ID (for vehicles)
    T* findItem(const string& id) {
        for (auto item : items) {
            // Check if the item has a string ID
             if constexpr (is_same_v<string, decltype(getItemId(item))>) {
                if (getItemId(item) == id) {
                    return item;
                }
            }
        }
        throw runtime_error("Item with ID " + id + " not found!");
    }


    // Remove an item by ID
    void removeItem(int id) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (getItemId(*it) == id) {
                delete *it; // Free the memory
                items.erase(it); // Remove the item from the vector
                cout << "Item with ID " << id << " removed successfully!" << endl;
                return;
            }
        }
        throw runtime_error("Item with ID " + to_string(id) + " not found!");
    }

    // Display all items
    void displayAll() const {
        if (items.empty()) {
            cout << "No items to display." << endl;
            return;
        }

        for (const auto& item : items) {
            item->displayDetails(); // Assuming T has a displayDetails() method
            cout << "--------------------" << endl;
        }
    }

    // Save all items to a file
    void saveToFile(const string& filename) const {
        ofstream out(filename);
        if (!out.is_open()) {
            throw runtime_error("Failed to open file for saving: " + filename);
        }

        for (const auto& item : items) {
            item->save_to_file(out); // Assuming T has a save_to_file(ofstream&) method
        }

        out.close();
        cout << "Data saved to " << filename << " successfully!" << endl;
    }

    // Load all items from a file
    void loadFromFile(const string& filename) {
        ifstream in(filename);
        if (!in.is_open()) {
            cerr << "Warning: Failed to open file for loading: " << filename << ". Starting with empty data." << endl;
            return; // Don't throw if the file doesn't exist on first run
        }

        // Clear existing items before loading
        for (auto item : items) {
            delete item;
        }
        items.clear();

        string line;
        while (getline(in, line)) {
            stringstream ss(line);
            string type;
            getline(ss, type, ',');

            T* item = nullptr;

            // This part requires specific handling based on the type T
            if constexpr (is_same_v<T, user>) {
                if (type == "Student") item = new Student();
                else if (type == "Faculty") item = new Faculty();
                else if (type == "Transporter") item = new transporter();
                else if (type == "Driver") item = new driver();
            } else if constexpr (is_same_v<T, vehicle>) {
                if (type == "Bus") item = new bus();
                else if (type == "Coaster") item = new coaster();
            } else if constexpr (is_same_v<T, route>) {
                 item = new route();
            } else if constexpr (is_same_v<T, driver>) {
                 item = new driver();
            } else if constexpr (is_same_v<T, booking>) {
                 item = new booking();
            }


            if (item) {
                 // Reset the stringstream to read the full line again for the item's load function
                 ss.clear();
                 ss.seekg(0);
                 item->load_from_file(in); // Assuming load_from_file takes an ifstream
                 items.push_back(item);
            } else {
                cerr << "Unknown type encountered during loading: " << type << " in file " << filename << endl;
            }
        }

        in.close();
        cout << "Data loaded from " << filename << " successfully!" << endl;
    }


    // Destructor to clean up dynamically allocated memory
    ~Management() {
        for (auto item : items) {
            delete item;
        }
    }
};


class TransportSystem {
private:
    Management<user> userManager;
    Management<vehicle> vehicleManager;
    Management<driver> driverManager;
    Management<route> routeManager;
    Management<booking> bookingManager;
    int nextRouteId = 1; // To generate unique route IDs
    int nextBookingId = 1; // To generate unique booking IDs

    // Helper function to establish relationships after loading
    void connectRelationships() {
        // Assign drivers to vehicles
        for (auto vehicle : vehicleManager.getItems()) {
            int driverId = vehicle->getAssignedDriverId();
            if (driverId != -1) {
                try {
                    driver* d = driverManager.findItem(driverId);
                    vehicle->assign_driver(d);
                } catch (const runtime_error& e) {
                    cerr << "Warning: Could not find driver with ID " << driverId << " for vehicle " << vehicle->getId() << endl;
                }
            }
        }

        // Assign routes to vehicles
        for (auto vehicle : vehicleManager.getItems()) {
            int routeId = vehicle->getAssignedRouteId();
            if (routeId != -1) {
                try {
                    route* r = routeManager.findItem(routeId);
                    vehicle->assign_route(r);
                } catch (const runtime_error& e) {
                    cerr << "Warning: Could not find route with ID " << routeId << " for vehicle " << vehicle->getId() << endl;
                }
            }
        }

        // Associate bookings with users, vehicles, and routes
        for (auto booking : bookingManager.getItems()) {
            user* u = nullptr;
            vehicle* v = nullptr;
            route* r = nullptr;

            try {
                u = userManager.findItem(booking->getUserId());
            } catch (const runtime_error& e) {
                 cerr << "Warning: Could not find user with ID " << booking->getUserId() << " for booking " << booking->getId() << endl;
            }

            try {
                 v = vehicleManager.findItem(booking->getVehicleId());
            } catch (const runtime_error& e) {
                 cerr << "Warning: Could not find vehicle with ID " << booking->getVehicleId() << " for booking " << booking->getId() << endl;
            }

            try {
                 r = routeManager.findItem(booking->getRouteId());
            } catch (const runtime_error& e) {
                 cerr << "Warning: Could not find route with ID " << booking->getRouteId() << " for booking " << booking->getId() << endl;
            }

            booking->setRelationships(u, v, r);
        }
         // Update next IDs after loading
        if (!routeManager.getItems().empty()) {
            nextRouteId = routeManager.getItems().back()->getId() + 1;
        }
         if (!bookingManager.getItems().empty()) {
            nextBookingId = bookingManager.getItems().back()->getId() + 1;
        }
    }

public:
    // Load all data from files
    void loadAllData() {
        try {
            userManager.loadFromFile("users.csv");
            vehicleManager.loadFromFile("vehicles.csv");
            driverManager.loadFromFile("drivers.csv");
            routeManager.loadFromFile("routes.csv");
            bookingManager.loadFromFile("bookings.csv");

            connectRelationships(); // Establish relationships after loading

            cout << "All data loaded successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error loading data: " << e.what() << endl;
        }
    }

    // Save all data to files
    void saveAllData() {
        try {
            userManager.saveToFile("users.csv");
            vehicleManager.saveToFile("vehicles.csv");
            driverManager.saveToFile("drivers.csv");
            routeManager.saveToFile("routes.csv");
            bookingManager.saveToFile("bookings.csv");

            cout << "All data saved successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error saving data: " << e.what() << endl;
        }
    }

    // Main menu system
    void run() {
        int choice;
        do {
            display_menu();
            cout << "Enter your choice: ";
            cin >> choice;

            try {
                switch (choice) {
                    case 1:
                        addUser();
                        break;
                    case 2:
                        addVehicle();
                        break;
                    case 3:
                        addDriver();
                        break;
                    case 4:
                        addRoute();
                        break;
                    case 5:
                        assignDriverToVehicle();
                        break;
                    case 6:
                        assignRouteToVehicle();
                        break;
                    case 7:
                        displayAllDrivers();
                        break;
                    case 8:
                        displayAllRoutes();
                        break;
                    case 9:
                        bookSeat();
                        break;
                    case 10:
                        cancelBooking();
                        break;
                    case 11:
                        displayAllBookings();
                        break;
                    case 12:
                        displayAllUsers();
                        break;
                    case 13:
                        displayAllVehicles();
                        break;
                     case 14: {
                        int userId;
                        cout << "Enter user ID to make payment: ";
                        cin >> userId;
                        user* u = userManager.findItem(userId);
                        u->make_payment();
                        break;
                     }
                    case 0:
                        cout << "Exiting system..." << endl;
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        } while (choice != 0);
    }

    // Menu option implementations
    void addUser() {
        string userType;
        cout << "Enter user type (Student/Faculty/Transporter): ";
        cin >> userType;

        if (userType == "Student") {
            Student* s = new Student();
            s->add_student();
            userManager.addItem(s);
        } else if (userType == "Faculty") {
            Faculty* f = new Faculty();
            f->add_faculty();
            userManager.addItem(f);
        } else if (userType == "Transporter") {
             transporter* t = new transporter();
             // Add transporter details here
             userManager.addItem(t);
        }
        else {
            throw runtime_error("Invalid user type!");
        }
    }

    void addVehicle() {
        string vehicleType, vehicleNumber;
        bool isAC;
        cout << "Enter vehicle type (Bus/Coaster): ";
        cin >> vehicleType;
        cout << "Enter vehicle number: ";
        cin >> vehicleNumber;
        cout << "Is the vehicle AC? (1 for Yes, 0 for No): ";
        cin >> isAC;

        if (vehicleType == "Bus") {
            bus* b = new bus(vehicleNumber, isAC);
            vehicleManager.addItem(b);
        } else if (vehicleType == "Coaster") {
            coaster* c = new coaster(vehicleNumber, isAC);
            vehicleManager.addItem(c);
        } else {
            throw runtime_error("Invalid vehicle type!");
        }
    }

    void bookSeat() {
        try {
            int userId, seatNumber, baseFare;
            string vehicleId;

            cout << "Enter user ID: ";
            cin >> userId;
            cout << "Enter vehicle ID: ";
            cin >> vehicleId;
            cout << "Enter seat number (1-based): ";
            cin >> seatNumber;
            cout << "Enter base fare: ";
            cin >> baseFare;

            user* u = userManager.findItem(userId);
            vehicle* v = vehicleManager.findItem(vehicleId);
            route* r = v->getAssignedRoute(); // Assuming vehicles have assigned routes

            if (!r) {
                throw runtime_error("Vehicle does not have an assigned route!");
            }

            // Create a new booking
            booking* b = new booking(u, v, r, seatNumber - 1, baseFare, nextBookingId++); // Use seatNumber - 1 for 0-based index
            bookingManager.addItem(b);
            cout << "Seat booked successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error booking seat: " << e.what() << endl;
        }
    }

    void cancelBooking() {
        try {
            int bookingId;
            cout << "Enter booking ID to cancel: ";
            cin >> bookingId;

            booking* b = bookingManager.findItem(bookingId);
            b->cancel_booking();
            bookingManager.removeItem(bookingId);
            cout << "Booking canceled successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error canceling booking: " << e.what() << endl;
        }
    }

    void displayAllBookings() {
        cout << "Displaying all bookings:" << endl;
        bookingManager.displayAll();
    }

    void assignDriverToVehicle() {
        try {
            int driverId;
            string vehicleId;
            cout << "Enter driver ID: ";
            cin >> driverId;
            cout << "Enter vehicle ID: ";
            cin >> vehicleId;

            driver* d = driverManager.findItem(driverId);
            vehicle* v = vehicleManager.findItem(vehicleId);
            v->assign_driver(d);
            cout << "Driver assigned to vehicle successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error assigning driver to vehicle: " << e.what() << endl;
        }
    }

    void assignRouteToVehicle() {
        try {
            int routeId;
            string vehicleId;
            cout << "Enter route ID: ";
            cin >> routeId;
            cout << "Enter vehicle ID: ";
            cin >> vehicleId;

            route* r = routeManager.findItem(routeId);
            vehicle* v = vehicleManager.findItem(vehicleId);
            v->assign_route(r);
            cout << "Route assigned to vehicle successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error assigning route to vehicle: " << e.what() << endl;
        }
    }

    void addDriver() {
        try {
            driver* d = new driver();
            d->add_details(); // Assuming `add_details` prompts the user for driver details and sets the ID
            driverManager.addItem(d);
            cout << "Driver added successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error adding driver: " << e.what() << endl;
        }
    }

    void addRoute() {
        try {
            string start, end;
            int distance;
            cout << "Enter start location: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
            getline(cin, start);
            cout << "Enter end location: ";
            getline(cin, end);
            cout << "Enter distance (in km): ";
            cin >> distance;

            route* r = new route(start, end, distance, nextRouteId++); // Assign a unique ID
            routeManager.addItem(r);
            cout << "Route added successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error adding route: " << e.what() << endl;
        }
    }

    void displayAllDrivers() {
        cout << "Displaying all drivers:" << endl;
        driverManager.displayAll(); // Assuming `displayAll` calls `show_details` for each driver
    }

    void displayAllRoutes() {
        cout << "Displaying all routes:" << endl;
        routeManager.displayAll(); // Assuming `displayAll` calls `get_route_details` for each route
    }

    void displayAllUsers() {
        cout << "Displaying all users:" << endl;
        userManager.displayAll();
    }

    void displayAllVehicles() {
        cout << "Displaying all vehicles:" << endl;
        vehicleManager.displayAll();
    }
};

void display_menu() {
    cout << "\n--- Transport System Menu ---" << endl;
    cout << "1. Add User" << endl;
    cout << "2. Add Vehicle" << endl;
    cout << "3. Add Driver" << endl;
    cout << "4. Add Route" << endl;
    cout << "5. Assign Driver to Vehicle" << endl;
    cout << "6. Assign Route to Vehicle" << endl;
    cout << "7. Display All Drivers" << endl;
    cout << "8. Display All Routes" << endl;
    cout << "9. Book Seat" << endl;
    cout << "10. Cancel Booking" << endl;
    cout << "11. Display All Bookings" << endl;
    cout << "12. Display All Users" << endl;
    cout << "13. Display All Vehicles" << endl;
    cout << "14. Make Payment" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------" << endl;
}

int main() {
    TransportSystem system;
    system.loadAllData();

    try {
        system.run();
    } catch (const exception& e) {
        cerr << "System error: " << e.what() << endl;
    }

    system.saveAllData();
    return 0;
}
```