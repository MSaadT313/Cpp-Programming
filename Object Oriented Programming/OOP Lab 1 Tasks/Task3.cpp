#include <iostream>
using namespace std;
class Complex
{
    int a;
    int b;

public:
    
    void setData(int a1, int b1)
    {
        a = a1;
        b = b1;
    }
    void display(void)
    {
        cout << "The complex number is" << a << "+" << b << "i" << endl;
    }
    void setDatabySum(Complex x, Complex y)
    {
        a = x.a + y.a;
        b = x.b + y.b;
    }
};

int main()
{
    Complex x, y, z;
    x.setData(1, 3);
    x.display();
    y.setData(2, 6);
    y.display();
    z.setDatabySum(x, y);
    z.display();
    return 0;
}