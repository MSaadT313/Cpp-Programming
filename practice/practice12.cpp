#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class Student{
int id;
string name;
public:
Student(int n, string s):id(n),name(s){}
void write_to_file(){
    ofstream out("file.txt",ios::app);
    if(out.is_open()){
    out<<id<<","<<name<<endl;
    out.close();
    }
    else{
        cout<<"Error opening the file."<<endl;
    }
}
void append_to_file(string line){
    fstream append("file.txt",ios::app);
    if(!append.is_open()){
    cout<<"Error in opening the file"<<endl;
    return ;
    }
    append<<line;
    append.close();
}
void read_to_file(){
    ifstream in("file.txt");
    if(in.is_open()){
        string line;
        while(getline(in, line)){
            stringstream ss(line);
            string id;
            string name;
            getline(ss,id,',');
            getline(ss,name);
          cout<<id<<", "<<name<<"."<<endl;
        }
    }
    else{
        cout<<"error in opening the file.";

    }
}
};
int main(){
    Student s1(23,"Muhammad Saad Tahir");
    Student s2(23,"John wick");
    Student s3(21,"UMER na");
    s1.write_to_file();
    s2.write_to_file();
    s3.write_to_file();
    s1.append_to_file("Hello Brother");
    s1.read_to_file();

}
// #include <iostream>
// #include <fstream>
// using namespace std;

// int main()
// {
//     ifstream openFile("file.txt");

//     if (!openFile.is_open())
//     {
//         cout << "error in opening the file";
//         return 1;
//     }
//     char ch;
//     while (openFile.eof())
//     { // get one character
//         openFile.get(ch);
//         cout << ch;
//     }
//     openFile.close();
//     return 0;
// }
