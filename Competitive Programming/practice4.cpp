#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> names(n),name2(n);
    for (int i = 0; i < n; i++)
    {
        cin>>names[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin>>name2[i];
    }
    bool partner = true;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
            if(names[i]==name2[j]){
                if (names[j]!=name2[i] || i==j)
                {
                    cout<<"bad";
                    partner = false;
                    break;
                }
            }
        
        if(!partner){
            break;
        }
    }
    
    if(partner)
    cout<<"Good";

    return 0;
}
