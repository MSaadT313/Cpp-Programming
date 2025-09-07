// Write Code that take input from user student-id , student-age , student-name and print all information.
#include<iostream>
using namespace std;
class Student{
    int id;
    int age;
    string name;
    void read_name(){
        cout<<"Enter the student id:";
        cin>>id;
        cout<<"Enter the student age:";
        cin>>age;
        cout<<"Enter the student name:";
        cin>>name;
    }
    public:
    void display(){
        read_name();
        cout<<"Student id:"<<id<<endl;
        cout<<"Student age:"<<age<<endl;
        cout<<"Student name:"<<name<<endl;
    }
    
};
int main(){
    Student name;
    name.display();
    return 0;
}