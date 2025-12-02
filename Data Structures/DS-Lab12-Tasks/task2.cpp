#include<iostream>
#include<string>
using namespace std;
#define d 256
void RKAlogo(string text, string pattern, int q){
    int n =  text.length();
    int m = pattern.length();
    int p = 0;
    int t = 0;
    int h = 1;

    if (m>n || m==0)
    {
        cout<<"Invalid String inputted"<<endl;
        return;
    }

    for (int i = 0; i < m-1; i++)      //it give us the value that is then used to remove the old character from the new hash value
    {
        h = (h * d)% q;
    }
    for (int i = 0; i < m; i++)
    {
        p = (d * p + pattern[i])% q;
        t = (d * t + text[i])%q;
    }
    
    for (int i = 0; i <= n-m; i++)
    {
        if(p == t){
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (text[i+j] != pattern[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Value found at index "<<i<<endl;
            }
        }

        if(i < n-m){
            t = (d * ( t - text[i]*h)+text[i+m])%q;
            if(t<0){
                t = t +q;
            }
        }
    }
    
    

}





int main(){
     string text = "Data structures and algorithms are fun. Algorithms make tasks easier.";
    string pattern = "Algorithms";

    int q = 101; // a prime number

    RKAlogo(text, pattern, q);






    return 0;
}