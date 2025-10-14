#include <iostream>
#include <cstring>
using namespace std;

class Exam {
private:
    char* studentName;
    char* examDate;
    float score;

public:
    Exam() {
        studentName = nullptr;
        examDate = nullptr;
        score = 0.0;
    }
    void setDetails(const char* name, const char* date, float s) {

        studentName = new char[strlen(name) + 1];
        strcpy(studentName, name);

        examDate = new char[strlen(date) + 1];
        strcpy(examDate, date);

        score = s;
    }
    void display() const {
        cout << "Student Name: " << studentName << endl;
        cout << "Exam Date: " << examDate << endl;
        cout << "Score: " << score << endl;
    }
    ~Exam() {
        delete[] studentName;
        delete[] examDate;
    }
};

int main() {
    Exam e1;
    e1.setDetails("Ali", "2025-08-22", 95.5);

    cout << "Original Object (e1):" << endl;
    e1.display();

    Exam e2 = e1;  // Shallow copy occurs here

    cout << "\nCopied Object (e2):" << endl;
    e2.display();

    cout << "\nNow both objects share the same memory for studentName and examDate.\n";
    cout << "When main ends, destructor will run for both objects -> Double deletion occurs!\n";

    return 0;
}
