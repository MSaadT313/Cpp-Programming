#include <iostream>
using namespace std;

class Student_Marks
{
private:
    string name;
    int marks;

public:
    Student_Marks(string student_name = "", int student_marks = 0)
    {
        name = student_name;
        marks = student_marks;
    }
    void display()
    {
        cout << name << " = " << marks << endl;
    }
};

int main()
{

    string student_names[] = {"Mujtaba", "Amna", "Khadija", "Saad", "Emad"};
    int num_students = sizeof(student_names) / sizeof(student_names[0]);

    Student_Marks students[num_students];
    for (int i = 0; i < num_students; i++)
    {
        students[i] = Student_Marks("Student_" + to_string(i + 1) + "_" + student_names[i], 50 + i);
    }

    for (int i = 0; i < num_students; i++)
    {
        students[i].display();
    }

    return 0;
}
