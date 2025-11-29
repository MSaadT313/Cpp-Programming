#include<iostream>
using namespace std;

int bruteforce(string text, string pattern){

    int m = pattern.length();
    int n = text.length();
    int k = 0;
    for (int i = 0; i < n-m; i++)
    {
        int j =0;
        while(j<m && text[i+j] == pattern[j]){
            j++;
        }
        if(j == m){      //if the size of pattern=searched string
            k++;
            cout<<"Pattern Found"<<endl;
        }
    }
    return k;
    
}
int main() {
    string text = "the quick brown fox jumps over the lazy dog";
    string pattern = "the";
    int n = bruteforce(text, pattern);
    if (n==0)
    {
        cout<<"No pattern Found"<<endl;
    }
    else{
        cout<<n<<" indexes found."<<endl;
    }
    return 0;
}