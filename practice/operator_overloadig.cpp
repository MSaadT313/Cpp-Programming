#include <iostream>
using namespace std;
class manager{
    int num1, num2;
    public:
    manager(){
        num1 = 0;
        num2 = 0;
    }
    manager(int x,int y){
        num1 = x;
        num2 = y;
    }
    manager operator+(manager &m1){
        manager m3;
        m3.num1=this->num1+m1.num1;
        m3.num2=this->num2+m1.num2;
        return m3;
    }
    void display(){
        cout<<"Value of NUM1 = "<<num1<<endl;
        cout<<"Value of NUM2 = "<<num2<<endl; 
    }
    
};
int main()
{
    manager m1,m2(2,3),m3(4,6);
    m1 = m2 + m3;
    m1.display();


    

return 0;
}