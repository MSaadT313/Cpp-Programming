#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n)
{
    if(n<2){
        return false;
    }
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0)
            return false;
        }
    return true;
}
int main(){
    int n=5;
    int value;
    int prod;
    int result=0;
    int count = 4;
    int array[4];
    cin>>value;
    cout<<isPrime(n);
 
    return 0;
}