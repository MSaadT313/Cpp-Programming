#include <iostream>
#include <string>
using namespace std;

const int MAX_COURSES = 20;

class Course;

class University {
public:
    virtual void showInfo() = 0; 
};

class Course {
public:
    string name;
    int id;
    float marksRequired;

    Course(string name = "", int id = 0, float marksRequired = 50.0f)
        : name(name), id(id), marksRequired(marksRequired) {}
};

class Professor : public University {
public:
    string name;
    int id;
    float salary = 100000;
    Course* courses[MAX_COURSES];
    int courseCount = 0;

    Professor(string name, int id) : name(name), id(id) {
        for (int i = 0; i < MAX_COURSES; ++i) courses[i] = nullptr;
    }

    void assignCourse(Course* course) {
        if (courseCount < MAX_COURSES) {
            courses[courseCount++] = course;
            if (courseCount % 12 == 0) {
                salary += salary * 0.05; // 5% increment
                cout << "Salary incremented by 5%! New salary: " << salary << endl;
            }
        } else {
            cout << "Course limit reached for professor.\n";
        }
    }

    void showInfo() override {
        cout << "Professor Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }
};

class Student : public University {
public:
    struct StudyPlan {
        Course* course;
        float marks;
        char grade;
    };

    string name;
    int id;
    Course* enrolledCourses[MAX_COURSES];
    StudyPlan studyPlans[MAX_COURSES];
    int enrolledCount = 0;
    int studyPlanCount = 0;

    Student(string name, int id) : name(name), id(id) {
        for (int i = 0; i < MAX_COURSES; ++i) {
            enrolledCourses[i] = nullptr;
            studyPlans[i] = { nullptr, 0.0f, 'F' };
        }
    }

    bool hasPassed(Course* prereq) {
        for (int i = 0; i < studyPlanCount; ++i) {
            if (studyPlans[i].course == prereq && studyPlans[i].marks >= prereq->marksRequired)
                return true;
        }
        return false;
    }

    void addToStudyPlan(Course* course, float marks, char grade) {
        if (studyPlanCount < MAX_COURSES) {
            studyPlans[studyPlanCount++] = { course, marks, grade };
        }
    }

    void enrollCourse(Course* course, Course* prereq = nullptr) {
        if (enrolledCount >= MAX_COURSES) {
            cout << "Course enrollment limit reached." << endl;
            return;
        }

        if (prereq != nullptr && !hasPassed(prereq)) {
            cout << "Cannot enroll in " << course->name << ". Prerequisite not passed.\n";
            return;
        }

        enrolledCourses[enrolledCount++] = course;
        cout << "Enrolled in course: " << course->name << endl;
    }

    void showInfo() override {
        cout << "Student Name: " << name << ", ID: " << id << endl;
        cout << "Enrolled Courses:\n";
        for (int i = 0; i < enrolledCount; ++i) {
            cout << "- " << enrolledCourses[i]->name << endl;
        }

        cout << "Study Plan:\n";
        for (int i = 0; i < studyPlanCount; ++i) {
            cout << "- " << studyPlans[i].course->name << ": Marks = " << studyPlans[i].marks
                 << ", Grade = " << studyPlans[i].grade << endl;
        }
    }
};

int main() {
    // Create courses
    Course c1("Intro to Programming", 101, 50);
    Course c2("Data Structures", 102, 60);

    // Create professor
    Professor p1("Dr. Smith", 201);
    p1.assignCourse(&c1);
    p1.assignCourse(&c2);
    p1.showInfo();

    // Create student
    Student s1("Alice", 301);
    s1.enrollCourse(&c1); // No prerequisite
    s1.addToStudyPlan(&c1, 75.0f, 'A'); // Passed c1
    s1.enrollCourse(&c2, &c1); // Requires c1
    s1.showInfo();

    return 0;
}
