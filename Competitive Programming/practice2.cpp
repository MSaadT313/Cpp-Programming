#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
    int a,b;
    cin>>a>>b;                          //22    //23
    if(a==b){
        cout<<t;
    }
    if(a<b){
        if(a%2==0 && b%2 == 0){
            cout<<"2";
            break;
        }
        if(a%2 != 0 && b%2 == 0){
            cout<<"1";
        }
        if(a%2 == 0 && b%2 != 0){
            cout<<"1";
        }
        if(a%2 != 0 && b%2 != 0){
            cout<<"1";
        }
    }
    else  if(a<b){
        if(a%2==0 && b%2 == 0){
            cout<<"2";
            break;
        }
        if(a%2 != 0 && b%2 == 0){
            cout<<"1";
        }
        if(a%2 == 0 && b%2 != 0){
            cout<<"1";
        }
        if(a%2 != 0 && b%2 != 0){
            cout<<"1";
        }
    }
    
    return 0;
}