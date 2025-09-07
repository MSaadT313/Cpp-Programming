#include <iostream>
using namespace std;
class Number;
class Calculator
{
    public:
    int divide(Number, Number);
};
class Number
{
    int x;
    int y;
    friend int Calculator ::divide(Number, Number);

public:
    void setnumber(int a, int b)
    {
        x = a;
        y = b;
    }
    void getNumber(void)
    {
        cout << "the Numbers are " << x << "and " << y << endl;
    }
};
int Calculator :: divide(Number o1, Number o2)
{
    return (o1.x * o2.x);
}

int main()
{
    Number o1, o2, sum;
    Calculator calc;
    o1.setnumber(1, 4);
    o2.setnumber(2, 3);
    int res = calc.divide(o1, o2);
    cout<<"the divide of real part is "<<res<<endl;
    return 0;
}