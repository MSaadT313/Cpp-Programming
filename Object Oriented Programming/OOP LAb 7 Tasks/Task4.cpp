#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string n, string a, string p, string e) {
        name = n;
        address = a;
        phoneNumber = p;
        email = e;
    }
    
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;

public:
    Student(string n, string i, string a, string p, string e, vector<string> courses, double gpa, int year)
        : Person(n, i, a, p, e), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: ";
        for (string course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << endl;
        cout << "GPA: " << GPA << endl;
        cout << "Enrollment Year: " << enrollmentYear << endl;
    }

    void updateInfo(string n, string a, string p, string e, vector<string> courses, double gpa, int year) {
        Person::updateInfo(n, a, p, e);
        coursesEnrolled = courses;
        GPA = gpa;
        enrollmentYear = year;
    }

    string getName(){
        return name;
    }
};

class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string dept, vector<string> courses, double sal)
        : Person(n, i, a, p, e), department(dept), coursesTaught(courses), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Courses Taught: ";
        for (const string& course : coursesTaught) {
            cout << course << " ";
        }
        cout << endl;
        cout << "Salary: $" << salary << endl;
    }

    void updateInfo(string n, string a, string p, string e, string dept, vector<string> courses, double sal) {
        Person::updateInfo(n, a, p, e);
        department = dept;
        coursesTaught = courses;
        salary = sal;
    }
    string getName(){
        return name;
    };
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string a, string p, string e, string dept, string pos, double sal)
        : Person(n, i, a, p, e), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department: " << department << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: $" << salary << endl;
    }

    void updateInfo(string n, string a, string p, string e, string dept, string pos, double sal) {
        Person::updateInfo(n, a, p, e);
        department = dept;
        position = pos;
        salary = sal;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;

public:
    Course(string id, string name, int cred, Professor* prof, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(prof), schedule(sched) {}

    void registerStudent(Student& student) {
        cout << student.getName() << " has been registered for " << courseName << endl;
    }

    void calculateGrades() {
        cout << "Grades for " << courseName << " will be calculated based on the course criteria.\n";
    }

    void displayCourseInfo() {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
    }

    string getCourseName() {
        return courseName;
    }

    string getName() {
        return courseName;
    }
};

int main() {
    Professor prof("Dr. John Smith", "P001", "1234 Elm St", "555-1234", "john.smith@univ.edu", "Computer Science", {"CS101", "CS102"}, 70000);

    vector<string> studentCourses = {"CS101", "Math101"};
    Student student("Alice Johnson", "S001", "4567 Oak St", "555-5678", "alice.johnson@univ.edu", studentCourses, 3.8, 2022);

    Staff staff("Bob White", "STA001", "7890 Pine St", "555-9876", "bob.white@univ.edu", "Administration", "Registrar", 50000);

    cout << "Professor Info:\n";
    prof.displayInfo();
    cout << "\nStudent Info:\n";
    student.displayInfo();
    cout << "\nStaff Info:\n";
    staff.displayInfo();

    Course course("CS101", "Introduction to Programming", 3, &prof, "Mon-Wed-Fri 10:00 AM - 11:30 AM");
    course.registerStudent(student);

    return 0;
}
