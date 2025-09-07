#include <iostream>
using namespace std;
class Box{
    int b;
    public:
    Box(int l):b(l){}
    friend istream& operator>>(istream& andar, Box& b);
    friend ostream& operator<<(ostream& bahir,Box& b);
};
istream& operator>>(istream& andar, Box& b){
    andar>>b.b;
    return andar;
}
ostream& operator<<(ostream& bahir, Box& a){
    bahir<<"Lenght is "<<a.b;
    return bahir;
}

int main()
{
    Box b1(5);
    cout<<b1;
    cin>>b1;
    return 0;
}