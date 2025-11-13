#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    pair<int, int> ans;
    for (int i = 1; i < n; i++)
    {
         for (int j = 0; j < n; j++)
         {
            if(i*j == n){
                ans = {i,j};
                cout<<ans.first<<" "<<ans.second<<endl;
                break;
            }
        } 
    }
       
    
    
    return 0;
}