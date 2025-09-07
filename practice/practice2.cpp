#include <iostream>
using namespace std;
class parent
{
public:
    parent() {};
    void display1()
    {
        cout << "Parent class called" << endl;
    }
};
class child : public parent
{
public:
    child() {};
    void display2()
    {
        cout << "child class called" << endl;
    }
};
int main()
{
    return 0;
}