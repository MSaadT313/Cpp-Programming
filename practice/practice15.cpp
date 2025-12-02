#include<iostream>
using namespace std;
int main(){
    int n;
    string text;
    cout<<"Enter the string: ";cin>>text;
    n = text.length();
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '(')
        {
            if (end<1)
            {
                start++;
            }
            else{
                cout<<"Wrong string inputted"<<endl;
                return -1;
            }
        }
        else if (text[i] == ')')
        {
            if (start>0)
            {
                end++;
            }
            else{
                cout<<"Wrong string inputted"<<endl;
                return -1;
            }
        }
    }
    if(start != end){
        cout<<"Wrong string inputted"<<endl;
        return -1;
    }
    cout<<"Stirng is Correct "<<endl;
    
return 0;
}