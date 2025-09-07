#include <iostream>
#include <string>
#include <fstream>
#include<sstream>
#include <ctime>
using namespace std;
class route;
class transporter;
class vehicle; // Forward declaration for vehicle class
class vehicle; // Forward declaration for vehicle class

class Student : public user {
    int roll_number;
    string email_address;

public:
    void save_to_file(ofstream& out) const override {
        out << "Student," << name << "," << id << "," << pickup_address << "," << CNIC << "," 
            << phone_number << "," << roll_number << "," << email_address << endl;
    }

public:
    Student() : roll_number(0), email_address("") {}

    void add_student() {
        ofstream studentFile("students.txt", ios::app);
        if (!studentFile.is_open()) {
            cerr << "Failed to open students.txt file." << endl;
            return;
        }

        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the ID of the student: ";
        cin >> id;
        cout << "Enter the pickup address of the student: ";
        cin >> pickup_address;
        cout << "Enter CNIC of the student: ";
        cin >> CNIC;
        cout << "Enter phone number of the student: ";
        cin >> phone_number;
        cout << "Enter the roll number of the student: ";
        cin >> roll_number;
        cout << "Enter the email address of the student: ";
        cin >> email_address;

        studentFile << name << "," << id << "," << pickup_address << "," << CNIC << "," << phone_number << "," << roll_number << "," << email_address << endl;
        cout << "Student details added successfully!" << endl;

        studentFile.close();
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
};

class Faculty; // Forward declaration for Faculty class

class vehicle { // Full definition of the vehicle class
protected:
    string vehicle_number;
    string vehicle_type;
    int capacity;
    bool is_ac;

public:
    virtual int calculateFare() const = 0; // Abstract method for fare calculation
};

class user {
protected:
    string name;
    int id;
        string type;
    
    public:
        string getType() const {
            return type;
        }
    string pickup_address;
    string CNIC;
    bool payment_status;
    int phone_number;
    int monthly_bookings; // Counter for bookings in the current month
    time_t last_booking_date; // Timestamp of the last booking

public:
    user() : payment_status(false), monthly_bookings(0), last_booking_date(0) {}

    user(string n, int i, string t, string p, string c, int ph)
        : name(n), id(i), type(t), pickup_address(p), CNIC(c), phone_number(ph), 
          payment_status(false), monthly_bookings(0), last_booking_date(0) {}

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

    int calculate_user_fare(int base_fare, const vehicle& v) const {
        int fare = v.calculateFare();
        if (type == "Faculty") {
            fare -= 5000; 
        }
        return fare;
    }

    void validate_user_data() const {
        if (name.empty() || CNIC.empty() || phone_number <= 0) {
            throw runtime_error("Invalid user data!");
        }
    }

    virtual void save_to_file(ofstream& out) const = 0; // Make it pure virtual
        // Removed invalid statement. Ensure this logic is implemented in a valid function if needed.

    void load_from_file(ifstream& in){ // Make it pure virtual
        string line;
        getline(in, line);
        stringstream ss(line);
        getline(ss, type, ',');
        getline(ss, name, ',');
        ss >> id;
        ss.ignore();
        getline(ss, pickup_address, ',');
        getline(ss, CNIC, ',');
        ss >> phone_number;
        ss.ignore();
        ss >> monthly_bookings;
        ss.ignore();
        ss >> last_booking_date;

        if (type == "Student") {
            Student* s = new Student();
            ss.ignore();
            int roll_number;
            ss >> roll_number;
            s->set_roll_number(roll_number);
            ss.ignore();
            {
                string email;
                getline(ss, email, ',');
                s->set_email_address(email);
            }
            *this = *s;
        } else if (type == "Faculty") {
            Faculty* f = new Faculty();
            ss.ignore();
            getline(ss, f->department, ',');
            getline(ss, f->designation, ',');
            *this = *f;
        }
    }
};

class Student : public user {
    int roll_number;
    string email_address;

public:
    void save_to_file(ofstream& out) const override {
        out << "Student," << name << "," << id << "," << pickup_address << "," << CNIC << "," 
            << phone_number << "," << roll_number << "," << email_address << endl;
    }

public:
    Student() : roll_number(0), email_address("") {}

    void add_student() {
        ofstream studentFile("students.txt", ios::app);
        if (!studentFile.is_open()) {
            cerr << "Failed to open students.txt file." << endl;
            return;
        }

        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the ID of the student: ";
        cin >> id;
        cout << "Enter the pickup address of the student: ";
        cin >> pickup_address;
        cout << "Enter CNIC of the student: ";
        cin >> CNIC;
        cout << "Enter phone number of the student: ";
        cin >> phone_number;
        cout << "Enter the roll number of the student: ";
        cin >> roll_number;
        cout << "Enter the email address of the student: ";
        cin >> email_address;

        studentFile << name << "," << id << "," << pickup_address << "," << CNIC << "," << phone_number << "," << roll_number << "," << email_address << endl;
        cout << "Student details added successfully!" << endl;

        studentFile.close();
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

    string get_email_address() const {
        return email_address;
    }
};

class Faculty : public user {
public:
    string department;
    string designation;
    Faculty() : department(""), designation("") {}

    void save_to_file(ofstream& out) const override {
        out << "Faculty," << name << "," << id << "," << pickup_address << "," << CNIC << "," 
            << phone_number << "," << department << "," << designation << endl;
    }

    void add_faculty() {
        ofstream facultyFile("faculty.txt", ios::app);
        if (!facultyFile.is_open()) {
            cerr << "Failed to open faculty.txt file." << endl;
            return;
        }

        cout << "Enter the name of the faculty: ";
        cin >> name;
        cout << "Enter the ID of the faculty: ";
        cin >> id;
        cout << "Enter the pickup address of the faculty: ";
        cin >> pickup_address;
        cout << "Enter CNIC of the faculty: ";
        cin >> CNIC;
        cout << "Enter phone number of the faculty: ";
        cin >> phone_number;
        cout << "Enter the department of the faculty: ";
        cin >> department;
        cout << "Enter the designation of the faculty: ";
        cin >> designation;

        facultyFile << name << "," << id << "," << pickup_address << "," << CNIC << "," << phone_number << "," << department << "," << designation << endl;
        cout << "Faculty details added successfully!" << endl;

        facultyFile.close();
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
};

class driver : public user {
    transporter* assigned_transporter;
    vehicle* assigned_vehicle;
    route* assigned_route;
    bool valid_lisense;

public:
    int getId() const { return id; } // Add this method to return the driver's ID

public:
    driver() : valid_lisense(false) {}

    driver(string n, int i, string p, string c, int ph, bool lisense)
        : user(n, i, "", p, c, ph), valid_lisense(lisense) {}

    driver(const driver& d) : user(d), valid_lisense(d.valid_lisense) {}

    // Method to add driver details
    void add_details() {
        cout << "Enter the name of the driver: ";
        cin >> name;
        cout << "Enter phone number of the driver: ";
        cin >> phone_number;
        cout << "Enter CNIC of the driver: ";
        cin >> CNIC;
        cout << "Enter license status of the driver (1 for valid, 0 for invalid): ";
        cin >> valid_lisense;

        ofstream outFile("drivers.txt", ios::app);
        if (!outFile.is_open()) {
            cerr << "Failed to open drivers.txt file." << endl;
            return;
        }
        save_to_file(outFile); // Save driver details to file
        outFile.close();
    }

    // Method to display driver details
    void show_details() const {
        cout << "Name of the driver: " << name << endl;
        cout << "Phone number of the driver: " << phone_number << endl;
        cout << "CNIC of the driver: " << CNIC << endl;
        cout << "License status of the driver: " << (valid_lisense ? "Valid" : "Invalid") << endl;
    }

    // Save driver details to a file
    void save_to_file(ofstream& out) const override {
        ofstream driverFile("drivers.txt", ios::app);
        if (!driverFile.is_open()) {
            cerr << "Failed to open drivers.txt file." << endl;
            return;
        }
        driverFile << name << "," << phone_number << "," << CNIC << "," << valid_lisense << endl;
        driverFile.close();
        cout << "Driver details saved successfully!" << endl;
    }

    // Load driver details from a file
    void load_from_file(ifstream& in){
        string line;
        getline(in, line);
        stringstream ss(line);
        getline(ss, name, ',');
        ss >> id;
        ss.ignore();
        getline(ss, CNIC, ',');
        ss >> phone_number;
        ss.ignore();
        ss >> valid_lisense;
    }

    // Overloaded operators for file handling
    friend ofstream& operator<<(ofstream& out, const driver& d) {
        out << d.name << "," << d.phone_number << "," << d.CNIC << "," << d.valid_lisense << endl;
        return out;
    }

    friend ifstream& operator>>(ifstream& in, driver& d) {
        in >> d.name >> d.phone_number >> d.CNIC >> d.valid_lisense;
        return in;
    }
};
class vehicle {
protected:
    string vehicle_number;
    string vehicle_type;
    int capacity;
    bool is_ac;
    driver* assigned_driver;
    route* assigned_route;
    string seats[52]; // Array to store seat occupant type ("Student", "Faculty", or empty)

public:
    string getId() const {
        return vehicle_number; // Use vehicle_number as the unique identifier
    }

public:
    vehicle(string vnum, string vtype, int cap, bool ac)
        : vehicle_number(vnum), vehicle_type(vtype), capacity(cap), is_ac(ac) {
        for (int i = 0; i < capacity; i++) {
            seats[i] = ""; // Initialize all seats as empty
        }
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

    void save_to_file(ofstream& out){
        out << vehicle_type << "," << vehicle_number << "," << capacity << "," << is_ac << ","
            << (assigned_driver ? assigned_driver->getId() : -1) << ","
            << (assigned_route ? assigned_route->getId() : -1) << endl;
    }

    void setAssignedDriverId(int driverId) {
        // Placeholder for setting the assigned driver ID
        // This method can be expanded to find and assign the driver object if needed
        cout << "Assigned driver ID: " << driverId << " to vehicle " << vehicle_number << endl;
    }

    void setAssignedRouteId(int routeId) {
        // Placeholder for setting the assigned route ID
        // This method can be expanded to find and assign the route object if needed
        cout << "Assigned route ID: " << routeId << " to vehicle " << vehicle_number << endl;
    }

    void load_from_file(ifstream& in) {
        string line;
        getline(in, line);
        stringstream ss(line);
        getline(ss, vehicle_type, ',');
        getline(ss, vehicle_number, ',');
        ss >> capacity;
        ss.ignore();
        ss >> is_ac;
        ss.ignore();
        int driverId, routeId;
        ss >> driverId;
        ss.ignore();
        ss >> routeId;
        setAssignedDriverId(driverId);
        setAssignedRouteId(routeId);
    }
};
class bus : public vehicle {
public:
    // Constructor for bus, initializing the base class with 52 seats
    bus(string vnum, bool ac) : vehicle(vnum, "Bus", 52, ac) {}

    // Override the fare calculation for buses
    int calculateFare() const override {
        int baseFare = 3000; // Base fare for buses
        return baseFare + (is_ac ? 2000 : 0); // Add AC charge if applicable
    }
};

class coaster : public vehicle {
public:
    // Constructor for coaster, initializing the base class with 32 seats
    coaster(string vnum, bool ac) : vehicle(vnum, "Coaster", 32, ac) {}

    // Override the fare calculation for coasters
    int calculateFare() const override {
        int baseFare = 2000; // Base fare for coasters
        return baseFare + (is_ac ? 1500 : 0); // Add AC charge if applicable
    }
};
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

    int getId() const { return id; } // Getter for the route ID

public:
    // Constructor to initialize route details
    route(string start, string end, int dist)
        : start_location(start), end_location(end), distance(dist) {
        is_long_distance = (distance > 40); // Threshold for long distance
    }

    // Method to display route details
    void get_route_details() const {
        cout << "Route Details:" << endl;
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
        out << start_location << "," << end_location << "," << distance << endl;
    }

    void load_from_file(ifstream& in) {
        string line;
        getline(in, line);
        stringstream ss(line);
        getline(ss, start_location, ',');
        getline(ss, end_location, ',');
        ss >> distance;
    }
};
class transporter : public user {
    string password;
    int number_of_bus;
    int number_of_coaster;
    int number_of_driver;

public:
    transporter() : password(""), number_of_bus(0), number_of_coaster(0), number_of_driver(0) {}

    void add_driver() {
        ofstream driverFile("drivers.txt", ios::app);
        if (!driverFile.is_open()) {
            cerr << "Failed to open drivers.txt file." << endl;
            return;
        }

        cout << "Enter the number of drivers to add: ";
        cin >> number_of_driver;

        for (int i = 0; i < number_of_driver; i++) {
            string driver_name, driver_CNIC;
            int driver_phone;
            bool valid_license;

            cout << "Enter the name of driver " << i + 1 << ": ";
            cin >> driver_name;
            cout << "Enter the CNIC of driver " << i + 1 << ": ";
            cin >> driver_CNIC;
            cout << "Enter the phone number of driver " << i + 1 << ": ";
            cin >> driver_phone;
            cout << "Is the license valid (1 for Yes, 0 for No): ";
            cin >> valid_license;

            driverFile << driver_name << "," << driver_CNIC << "," << driver_phone << "," << valid_license << endl;
        }

        cout << "Driver details added successfully!" << endl;
        driverFile.close();
    }
};
class booking {
    user* booked_user;
    vehicle* booked_vehicle;
    route* booked_route;
    int seat_number;
    int fare;
    time_t booking_date;

public:
    void cancel_booking() {
        if (booked_vehicle) {
            booked_vehicle->cancel_seat(seat_number);
            cout << "Booking canceled for seat " << seat_number + 1 << "." << endl;
        } else {
            throw runtime_error("No vehicle associated with this booking!");
        }
    }

public:
    booking(user* u, vehicle* v, route* r, int seat, int base_fare)
        : booked_user(u), booked_vehicle(v), booked_route(r), seat_number(seat) {
        booking_date = time(nullptr); // Store the current date

        // Check if the user can book
        if (!v->book_seat(seat, u->getType())) {
            throw runtime_error("User has reached the monthly booking limit!");
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

    // Save booking data to file
    void save_to_file(ofstream& out){
        out << booked_user->getId() << "," << booked_vehicle->getId() << "," << booked_route->getId() << ","
            << seat_number << "," << fare << "," << booking_date << endl;
    }

    // Load booking data from file
    void load_from_file(ifstream& in){
        string line;
        getline(in, line);
        stringstream ss(line);
        int userId, vehicleId, routeId;
        ss >> userId;
        ss.ignore();
        ss >> vehicleId;
        ss.ignore();
        ss >> routeId;
        ss.ignore();
        ss >> seat_number;
        ss.ignore();
        ss >> fare;
        ss.ignore();
        ss >> booking_date;
        set_user_id(userId);
        set_vehicle_id(vehicleId);
        set_route_id(routeId);
    }

    void set_user_id(int userId) {
        // Placeholder for setting the user ID
        cout << "User ID set to: " << userId << endl;
    }

    void set_vehicle_id(int vehicleId) {
        // Placeholder for setting the vehicle ID
        cout << "Vehicle ID set to: " << vehicleId << endl;
    }

    void set_route_id(int routeId) {
        // Placeholder for setting the route ID
        cout << "Route ID set to: " << routeId << endl;
    }
};
template <typename T>
class Management {
private:
    vector<T*> items;

public:
    // Add an item to the management system
    void addItem(T* item) {
        items.push_back(item);
    }

    // Get all items in the management system
    const vector<T*>& getItems() const {
        return items;
    }

    // Find an item by ID
    T* findItem(int id) {
        for (auto item : items) {
            if (item->getId() == id) { // Assuming T has a getId() method
                return item;
            }
        }
        throw runtime_error("Item not found!");
    }

    // Remove an item by ID
    void removeItem(int id) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if ((*it)->getId() == id) { // Assuming T has a getId() method
                delete *it; // Free the memory
                items.erase(it); // Remove the item from the vector
                cout << "Item with ID " << id << " removed successfully!" << endl;
                return;
            }
        }
        throw runtime_error("Item not found!");
    }

    // Display all items
    void displayAll() const {
        if (items.empty()) {
            cout << "No items to display." << endl;
            return;
        }

        for (const auto& item : items) {
            item->displayDetails(); // Assuming T has a displayDetails() method
        }
    }

    // Save all items to a file
    void saveToFile(const string& filename) const {
        ofstream out(filename);
        if (!out.is_open()) {
            throw runtime_error("Failed to open file: " + filename);
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
            throw runtime_error("Failed to open file: " + filename);
        }

        while (!in.eof()) {
            T* item = new T(); // Assuming T has a default constructor
            item->load_from_file(in); // Assuming T has a load_from_file(ifstream&) method
            if (in) { // Ensure the item was successfully loaded
                items.push_back(item);
            } else {
                delete item; // Clean up if loading failed
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

    // Helper function to establish relationships after loading
    void connectRelationships() {
        // Assign drivers to vehicles
        for (auto vehicle : vehicleManager.getItems()) { // Assuming getItems() returns the vector of items
            if (vehicle->getAssignedDriverId() != -1) { // Assuming vehicles store assigned driver IDs
                driver* d = driverManager.findItem(vehicle->getAssignedDriverId());
                vehicle->assign_driver(d);
            }
        }

        // Assign routes to vehicles
        for (auto vehicle : vehicleManager.getItems()) {
            if (vehicle->getAssignedRouteId() != -1) { // Assuming vehicles store assigned route IDs
                route* r = routeManager.findItem(vehicle->getAssignedRouteId());
                vehicle->assign_route(r);
            }
        }

        // Associate bookings with users, vehicles, and routes
        for (auto booking : bookingManager.getItems()) {
            user* u = userManager.findItem(booking->getUserId());
            vehicle* v = vehicleManager.findItem(booking->getVehicleId());
            route* r = routeManager.findItem(booking->getRouteId());
            booking->setRelationships(u, v, r); // Assuming booking has a method to set relationships
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
                        cout << "Exiting system..." << endl;
                        break;
                    default:
                        cout << "Invalid choice! Please try again." << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        } while (choice != 9);
    }

    // Menu option implementations
    void addUser() {
        string userType;
        cout << "Enter user type (Student/Faculty): ";
        cin >> userType;

        if (userType == "Student") {
            Student* s = new Student();
            s->add_student();
            userManager.addItem(s);
        } else if (userType == "Faculty") {
            Faculty* f = new Faculty();
            f->add_faculty();
            userManager.addItem(f);
        } else {
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
            int userId, vehicleId, seatNumber, baseFare;
            cout << "Enter user ID: ";
            cin >> userId;
            cout << "Enter vehicle ID: ";
            cin >> vehicleId;
            cout << "Enter seat number: ";
            cin >> seatNumber;
            cout << "Enter base fare: ";
            cin >> baseFare;

            user* u = userManager.findItem(userId);
            vehicle* v = vehicleManager.findItem(vehicleId);
            route* r = v->getAssignedRoute(); // Assuming vehicles have assigned routes

            // Create a new booking
            booking* b = new booking(u, v, r, seatNumber, baseFare);
            bookingManager.addItem(b);
            cout << "Seat booked successfully!" << endl;
        } catch (const exception& e) {
            cerr << "Error booking seat: " << e.what() << endl;
        }
    }

    void cancelBooking() {
        int bookingId;
        cout << "Enter booking ID: ";
        cin >> bookingId;

        booking* b = bookingManager.findItem(bookingId);
        b->cancel_booking();
        bookingManager.removeItem(bookingId);
    }

    void displayAllBookings() {
        bookingManager.displayAll();
    }

    void assignDriverToVehicle() {
        int driverId, vehicleId;
        cout << "Enter driver ID: ";
        cin >> driverId;
        cout << "Enter vehicle ID: ";
        cin >> vehicleId;

        driver* d = driverManager.findItem(driverId);
        vehicle* v = vehicleManager.findItem(vehicleId);
        v->assign_driver(d);
    }

    void assignRouteToVehicle() {
        int routeId, vehicleId;
        cout << "Enter route ID: ";
        cin >> routeId;
        cout << "Enter vehicle ID: ";
        cin >> vehicleId;

        route* r = routeManager.findItem(routeId);
        vehicle* v = vehicleManager.findItem(vehicleId);
        v->assign_route(r);
    }

    void addDriver() {
        try {
            driver* d = new driver();
            d->add_details(); // Assuming `add_details` prompts the user for driver details
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
            cin >> start;
            cout << "Enter end location: ";
            cin >> end;
            cout << "Enter distance (in km): ";
            cin >> distance;

            route* r = new route(start, end, distance);
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
};

void display_menu() {
    cout << "1. Add User" << endl;
    cout << "2. Add Vehicle" << endl;
    cout << "3. Add Driver" << endl;
    cout << "4. Add Route" << endl;
    cout << "5. Assign Driver to Vehicle" << endl;
    cout << "6. Assign Route to Vehicle" << endl;
    cout << "7. Display All Drivers" << endl;
    cout << "8. Display All Routes" << endl;
    cout << "9. Exit" << endl;
}

user* search_user(const string& name, const Management<user>& userManager) {
    for (const auto& u : userManager.getItems()) {
        if (u->getName() == name) {
            return u;
        }
    }
    throw runtime_error("User not found!");
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