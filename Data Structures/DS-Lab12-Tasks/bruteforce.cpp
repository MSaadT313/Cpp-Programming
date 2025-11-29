#include<iostream>
using namespace std;

void bruteforce(string text, string pattern){

    int m = pattern.length();
    int n = text.length();
    for (int i = 0; i < n-m; i++)
    {
        int j =0;
        while(j<m && text[i+j] == pattern[j]){
            j++;
        }
        if(j == m){      //if the size of pattern=searched string
            cout<<"Pattern Found"<<endl;
        }
    }
    
}
int main() {
    string text = "ABAAABCDBBABCDDEBCABC";
    string pattern = "ABC";
    bruteforce(text, pattern);
    return 0;
}