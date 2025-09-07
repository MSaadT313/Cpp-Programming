// #include <iostream>
// #include <string.h>
// using namespace std;
// template<typename Z>
// class Student{
//     Z saad;
//     Z tahir;
//     public:
//     Student(Z s,Z t): saad(s), tahir(t){
//     Z combined = saad + tahir;
//     cout<<combined<<endl;
//     }
// };
// int main()
// {
//     string saad="saad";
//     string tahir="tahir";
//     Student<char*> name(&saad, &tahir);
//     cout << "Hello world";
//     return 0;
// }
// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;
// template <typename T>
// class Student
// {
//     T saad;
//     T ali;

// public:
//     Student(T s, T a) : saad(s), ali(a)
//     {
//         T combined = saad + " " + ali;
//         cout << combined << endl;
//     }
// };
// template <>
// class Student<char *>
// {
// public:
//     char combined[50];
//     Student(char *s1, char *s2)
//     {
//         strcpy(combined, s1);
//         strcat(combined, " ");
//         strcat(combined, s2);
//         cout << combined << endl;
//     }
// };
// int main()
// {
//     Student<char *> name((char *)"ahmed", (char *)"khan");
//     return 0;
// }
#include<iostream>
#include "header.h"
using namespace std;

int main(){
    int a=10;
    int b=30;
    int sum;
    sum = sumoftwonumbers(a,b);
    cout<<sum;
 
return 0;
}