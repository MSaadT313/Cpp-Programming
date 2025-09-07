#include <iostream>
using namespace std;

class Mentor;
class Skill;

class Sport
{
private:
    int sportID;
    string name;
    string description;
    string requiredSkill[5];
    int skillCount;

public:
    Sport(int ID, string n, string d)
    {
        sportID = ID;
        name = n;
        description = d;
        skillCount = 0;
    }

    void addSkill(Skill *s);
    void removeSkill(Skill *s);

    string getName() { return name; }
};

class Student
{
private:
    int studentID;
    string name;
    int age;
    string sportsInterest[5];
    int sportCount;
    Mentor *mentorAssigned;

public:
    Student(int ID, string n, int a)
    {
        studentID = ID;
        name = n;
        age = a;
        sportCount = 0;
        mentorAssigned = nullptr;
    }

    string getname() { return name; }

    void registerForMentorShip(Mentor *m);
    void viewMentorDetails();
    void addSportsInterest(Sport *s);
    void removeSportsInterest(Sport *s);
};

class Mentor
{
private:
    int mentorID;
    string name;
    int age;
    string sportsExpertise[5];
    int sportsCount;
    int maxLearner;
    Student *assignedLearner[5];
    int learnerCount;

public:
    Mentor(int id, string n, int a, int maxl)
    {
        mentorID = id;
        name = n;
        age = a;
        maxLearner = maxl;
        learnerCount = 0;
        sportsCount = 0;
        for (int i = 0; i < maxLearner; i++)
        {
            assignedLearner[i] = nullptr;
        }
    }

    void assignLearner(Student *s)
    {
        if (learnerCount < maxLearner)
        {
            assignedLearner[learnerCount++] = s;
            cout << s->getname() << " has been assigned to mentor " << name << endl;
        }
    }

    void removeLearner(Student *s)
    {
        for (int i = 0; i < learnerCount; i++)
        {
            if (assignedLearner[i] == s)
            {
                for (int j = i; j < learnerCount - 1; j++)
                {
                    assignedLearner[j] = assignedLearner[j + 1];
                }
                learnerCount--;
                cout << s->getname() << " is no longer assigned to mentor " << name << endl;
                assignedLearner[learnerCount] = nullptr;
            }
        }
    }

    void viewLearner()
    {
        cout << "Students of " << name << ":" << endl;
        if (learnerCount == 0)
        {
            cout << "No learners currently" << endl;
        }
        for (int i = 0; i < learnerCount; i++)
        {
            cout << assignedLearner[i]->getname() << endl;
        }
    }

    void provideGuidance()
    {
        cout << "Mentor: " << name << " is providing guidance" << endl;
    }

    void addSportsExpertise(Sport *s)
    {
        if (sportsCount >= 5)
        {
            cout << "Cannot add more sports expertise" << endl;
            return;
        }
        sportsExpertise[sportsCount++] = s->getName();
        cout << "Added " << s->getName() << " as sports expertise" << endl;
    }

    void removeSportsExpertise(Sport *s)
    {
        for (int i = 0; i < sportsCount; i++)
        {
            if (sportsExpertise[i] == s->getName())
            {
                for (int j = i; j < sportsCount - 1; j++)
                {
                    sportsExpertise[j] = sportsExpertise[j + 1];
                }
                sportsCount--;
                cout << "Sport has been removed from sports expertise" << endl;
            }
        }
    }

    int getLearnerCount() { return learnerCount; }
    int getMaxLearner() { return maxLearner; }
    string getname() { return name; }
    int getID() { return mentorID; }
    int getage() { return age; }
    int getSportsCount() { return sportsCount; }

    void getSportsExpertise(string copy[])
    {
        for (int i = 0; i < 5; i++)
        {
            copy[i] = "";
        }
        for (int i = 0; i < sportsCount; i++)
        {
            copy[i] = sportsExpertise[i];
        }
    }
};

class Skill
{
private:
    int skillID;
    string name;
    string description;

public:
    Skill(int id, string n, string d)
    {
        skillID = id;
        name = n;
        description = d;
    }

    void showSkillDetail()
    {
        cout << "Skill ID: " << skillID << endl;
        cout << "Skill name: " << name << endl;
        cout << "Skill description: " << description << endl;
    }

    void updateSkillDescription(string n_description)
    {
        description = n_description;
    }

    string getName() { return name; }
};

void Student::registerForMentorShip(Mentor *m)
{
    if (m->getLearnerCount() < m->getMaxLearner())
    {
        mentorAssigned = m;
        m->assignLearner(this);
    }
    else
    {
        mentorAssigned = nullptr;
        cout << "Mentor: " << m->getname() << " has the maximum number of learners" << endl;
    }
}

void Sport::addSkill(Skill *s)
{
    if (skillCount >= 5)
    {
        cout << "Cannot add more skills" << endl;
        return;
    }
    requiredSkill[skillCount] = s->getName();
    cout << "Added " << requiredSkill[skillCount] << endl;
    skillCount++;
}

void Sport::removeSkill(Skill *s)
{
    for (int i = 0; i < skillCount; i++)
    {
        if (requiredSkill[i] == s->getName())
        {
            for (int j = i; j < skillCount - 1; j++)
            {
                requiredSkill[j] = requiredSkill[j + 1];
            }
            skillCount--;
            cout << "Skill has been removed from Sport" << endl;
        }
    }
}

void Student::viewMentorDetails()
{
    if (mentorAssigned == nullptr)
    {
        cout << "Mentor not assigned" << endl;
        return;
    }
    cout << "Mentor ID: " << mentorAssigned->getID() << endl;
    cout << "Mentor name: " << mentorAssigned->getname() << endl;
    cout << "Mentor age: " << mentorAssigned->getage() << endl;
    string sports[5];
    mentorAssigned->getSportsExpertise(sports);
    cout << "Sports expertise:" << endl;
    if (mentorAssigned->getSportsCount() == 0)
    {
        cout << "No sports expertise" << endl;
        return;
    }
    for (int i = 0; i < mentorAssigned->getSportsCount(); i++)
    {
        cout << sports[i] << endl;
    }
}

void Student::addSportsInterest(Sport *s)
{
    if (sportCount >= 5)
    {
        cout << "Cannot add more sports" << endl;
        return;
    }
    sportsInterest[sportCount] = s->getName();
    cout << "Successfully Added: " << sportsInterest[sportCount] << " as a sport interest" << endl;
    sportCount++;
}

void Student::removeSportsInterest(Sport *s)
{
    for (int i = 0; i < sportCount; i++)
    {
        if (sportsInterest[i] == s->getName())
        {
            for (int j = i; j < sportCount - 1; j++)
            {
                sportsInterest[j] = sportsInterest[j + 1];
            }
            sportCount--;
            cout << "Sport has been successfully removed as a sport interest" << endl;
            sportsInterest[sportCount] = "";
        }
    }
}

int main()
{
    cout << "Muhammad Saad Tahir \n24K-0851" << endl;
    Mentor Artur(1, "Artur Beterbiev", 40, 3);
    Student Bivol(2, "Dimitry Bivol", 20);
    Sport Boxing(1, "Boxing", "1v1 match in which each person has to knockout the other within 12 rounds.");
    Skill Jabbing(1, "Jabbing", "Punching with a quick, short hand.");

    Bivol.registerForMentorShip(&Artur);
    Bivol.viewMentorDetails();
    Boxing.addSkill(&Jabbing);
    Jabbing.showSkillDetail();
    Boxing.removeSkill(&Jabbing);

    return 0;
}