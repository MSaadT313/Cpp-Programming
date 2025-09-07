#include <iostream>
using namespace std;
class employee
{
public:
    string designation;
    string department;
    string name;
    float salary;
    employee(string name, string designation, string department, float salary)
    {
        this->name = name;
        this->designation = designation;
        this->department = department;
        this->salary = salary;
    }
    void verify(string name)
    {
        if (this->name == name)
        {
            cout << "Employee Found" << endl;
        }
        else
        {
            cout << "Employee Not Found" << endl;
        }
    }
};
int employee::sum()
{
    return salary;
}
class faculty : public employee, course
{
public:
    int working_hours;
    course *course_list;
    int assigned_course_count;

    void assigncourse(course courselist)
    {
        for (int i = 0; i < sizeof(courselist); i++)
        {
            if (courselist[i].assigned == false)
            {
                course_list[assigned_course_count] = courselist[i];
                courselist[i].assigned = true;
                assigned_course_count++;
            }
        }
    }
    faculty(string name, string designation, string department, float salary, int working_hours, int course_list) : employee(name, designation, department, salary)
    {
        this->working_hours = working_hours;
        this->course_list = course_list;
    }
    void salary()
    {
        cout << "Salary: " << salary << endl;
    }
    void Assign_course(course course_list[])
    {
        for (int i = 0; i < sizeof(course_list); i++)
        {
            if ((course_list+i)->get_code == this->(course_list+i)->get_code)
            {
                course_list[i].assigned = true;
                cout << "Course Assigned" << endl;
            }
        }
    }
};
class course
{

public:
    string course_name;
    string course_code;
    string coursecredit_hours;
    bool assigned;

    course(string course_name, string course_code, string coursecredit_hours)
    {
        this->course_name = course_name;
        this->course_code = course_code;
        this->coursecredit_hours = coursecredit_hours;
    }
    void get_course()
    {
        cout << "Course Name: " << course_name << endl;
        cout << "Course Code: " << course_code << endl;
        cout << "Credit Hours: " << coursecredit_hours << endl;
    }
    string get_name()
    {
        return course_name;
    }
    string get_code()
    {
        return course_code;
    }
};
class staff : public employee
{
public:
    int overtimehours;
    staff(string name, string designation, string department, float salary, int overtimehours) : employee(name, designation, department, salary)
    {
        this->overtimehours = overtimehours;
    }
    bool verify(string name)
    {
        if (this->name == name)
        {
            cout << "Employee Found" << endl;
            return true;
        }
        else
        {
            cout << "Employee Not Found" << endl;
            return false;
        }
    }
    bool verify(int overtimehours)
    {
        if (this->overtimehours == overtimehours)
        {
            cout << "Employee Found" << endl;
            return true;
        }
        else
        {
            cout << "Employee Not Found" << endl;
            return false;
        }
    }
};

int main()
{
    return 0;
}