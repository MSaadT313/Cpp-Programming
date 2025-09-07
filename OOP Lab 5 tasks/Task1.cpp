#include <iostream>
using namespace std;
class Book_read{
    public:
    string name;
    int id;
    static int page_count;
    Book_read(int id,string name){
       this->id=id;
       this->name=name;
    }
    void display(){
        cout<<"Book Name:"<<name<<"\nBook id:"<<id<<endl;
        cout<<"Page number:"<<page_count<<endl;
    }
};
int Book_read::page_count = 3;
int main()
{
    Book_read b1(23,"saad quest");
    b1.display();

return 0;
}