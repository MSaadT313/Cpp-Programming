#include <iostream>
using namespace std;
class class1{
    public:
    int a,b;
    class1(int a, int b){
        this->a = a;
        this->b = b;
        cout<<"Fuction 1 running"<<endl;
    }
};
class class2 : public class1
{
    public:
    int c,d;
    class2(int a,int b,int c,int d): class1(a, b){
        this->c = c;
        this->d = d;
        cout<<"Function 2 runnning"<<endl;
    }


};
class class3 : public class2{
    public:
    int e,f;
    class3(int a,int b,int c,int d, int e,int f):class2(a,b,c,d){
        this->e = e;
        this->f = f;
        cout<<"Function 3 running"<<endl;
    }
};
int main()
{
  class3 c1(1,2,3,4,5,6);
    return 0;
}