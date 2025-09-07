#include<iostream>
#include<fstream>
using namespace std;
class DataFileHandler{
    ofstream ticketfile;

public:
    DataFileHandler() {
        ticketfile.open("tickets.txt",ios::app);
        if(!ticketfile){
            cerr<<"Error Loading the file."<<endl;
            exit(1);
        }
    }
    void saveLine(string message){
        if(ticketfile.is_open()){
        ticketfile<<message;
        }
        else{
            cerr<<
        }
    }

};
int main(){
 
return 0;
}