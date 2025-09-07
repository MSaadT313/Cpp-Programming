#include <iostream>
#include <string>
using namespace std;
int calculateHash(const string &password)
{
    int hash = 5381;
    for (char c : password)
    {
        hash = hash * 33 + c;
    }
    return hash;
}
class User{
protected:
    string name;
    string id;
    string email;
    int hashedPassword;
    string *permissions;
    int permissionCount;

public:
    User(string n, string i, string e, string pwd, string *perms, int count) : name(n), id(i), email(e), permissionCount(count)
    {
        hashedPassword = calculateHash(pwd);
        permissions = new string[count];
        for (int i = 0; i < count; i++)
        {
            permissions[i] = perms[i];
        }
    }

    virtual ~User()
    {
        delete[] permissions;
    }

    bool authenticate(string pwd)
    {
        return calculateHash(pwd) == hashedPassword;
    }

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Email: " << email << endl;
        cout << "Permissions: ";
        for (int i = 0; i < permissionCount; i++)
        {
            cout << permissions[i] << " ";
        }
        cout << endl;
    }
    bool hasPermission(string action)
    {
        for (int i = 0; i < permissionCount; i++)
        {
            if (permissions[i] == action)
            {
                return true;
            }
        }
        return false;
    }

    void accessLab()
    {
        if (hasPermission("full_lab_access") || hasPermission("view_projects") || hasPermission("submit_assignment"))
        {
            cout << name << " has lab access" << endl;
        }
        else
        {
            cout << name << " has NO lab access" << endl;
        }
    }

    string getName() { return name; }
};

class Student : public User{
protected:
    int *assignments;
    int assignmentCount;
public:
    Student(string n, string i, string e, string pwd, int count) : User(n, i, e, pwd, new string[1]{"submit_assignment"}, 1), assignmentCount(count)
    {
        assignments = new int[count]{0};
    }
    ~Student()
    {
        delete[] assignments;
    }
    void display() override
    {
        User::display();
        cout << "Assignments: ";
        for (int i = 0; i < assignmentCount; i++)
        {
            cout << "A" << i + 1 << ":" << (assignments[i] ? "Submitted" : "Pending") << " ";
        }
    }
    void submitAssignment(int index)
    {
        if (index >= 0 && index < assignmentCount)
        {
            assignments[index] = 1;
            cout << name << " submitted assignment " << index + 1 << endl;
        }
    }
};

class TA : public Student{
protected:
    string *students;
    int studentCount;
    string *projects;
    int projectCount;
public:
    TA(string n, string i, string e, string pwd, int assignCount) : Student(n, i, e, pwd, assignCount), studentCount(0), projectCount(0)
    {
        delete[] permissions;
        permissions = new string[2]{"view_projects", "manage_students"};
        permissionCount = 2;
        students = new string[10];
        projects = new string[2];
    }
    ~TA()
    {
        delete[] students;
        delete[] projects;
    }
    void display() override
    {
        Student::display();
        cout << "Managed Students: ";
        for (int i = 0; i < studentCount; i++)
        {
            cout << students[i] << " ";
        }
        cout << endl
             << "Projects: ";
        for (int i = 0; i < projectCount; i++)
        {
            cout << projects[i] << " ";
        }
        cout << endl;
    }
    bool addStudent(string studentName)
    {
        if (studentCount < 10)
        {
            students[studentCount++] = studentName;
            cout << "Added student " << studentName << endl;
            return true;
        }
        cout << "Cannot add more students (limit 10)" << endl;
        return false;
    }
    bool addProject(string projectName)
    {
        if (projectCount < 2)
        {
            projects[projectCount++] = projectName;
            cout << "Added project " << projectName << endl;
            return true;
        }
        cout << "Cannot add more projects (limit 2)" << endl;
        return false;
    }
};

class Professor : public User{
public:
    Professor(string n, string i, string e, string pwd) : User(n, i, e, pwd, new string[2]{"assign_projects", "full_lab_access"}, 2) {}
    void display() override
    {
        User::display();
        cout << "Role: Professor" << endl;
    }
    void assignProject(TA &ta, string projectName)
    {
        if (ta.addProject(projectName))
        {
            cout << name << " assigned project " << projectName << " to TA " << ta.getName() << endl;
        }
    }
};
void authenticateAndPerformAction(User *user, string action)
{
    string password;
    cout << "Enter password for " << user->getName() << ": ";
    cin >> password;

    if (user->authenticate(password))
    {
        if (user->hasPermission(action))
        {
            cout << "Action '" << action << "' performed successfully" << endl;
        }
        else
        {
            cout << "Permission denied for this action" << endl;
        }
    }
    else
    {
        cout << "Authentication failed!" << endl;
    }
}
int main()
{
    Student student("Ali", "S001", "ali@nu.edu.pk", "student123", 3);
    TA ta("Ahmed", "T001", "ahmed@nu.edu.pk", "ta456", 2);
    Professor prof("Dr. Khan", "P001", "khan@nu.edu.pk", "prof789");

    student.display();
    student.submitAssignment(0);
    student.submitAssignment(1);
    student.accessLab();

    ta.display();
    ta.addStudent("Ali");
    ta.addProject("Lab Management System");
    ta.accessLab();

    prof.display();
    prof.assignProject(ta, "New Research Project");
    prof.accessLab();

    authenticateAndPerformAction(&student, "submit_assignment");
    authenticateAndPerformAction(&ta, "manage_students");
    authenticateAndPerformAction(&prof, "assign_projects");
    return 0;
}