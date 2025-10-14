#include <iostream>
#include <string>
using namespace std;

class Office {
private:
    string location;
    int seatingCapacity;
    string* furniture;  
    int furnitureSize; 

public:
    Office(string loc, int capacity, int furSize) {
        location = loc;
        seatingCapacity = capacity;
        furnitureSize = furSize;
        
        furniture = new string[furnitureSize];
        
        for(int i = 0; i < furnitureSize; i++) {
            furniture[i] = "Empty";
        }
    }
    
    ~Office() {
        delete[] furniture;
    }
    
    void setFurniture(int index, string item) {
        if(index >= 0 && index < furnitureSize) {
            furniture[index] = item;
        } else {
            cout << "Invalid index for furniture array" << endl;
        }
    }
    
    void displayOfficeInfo() {
        cout << "\n----- Office Information -----" << endl;
        cout << "Location: " << location << endl;
        cout << "Seating Capacity: " << seatingCapacity << endl;
        cout << "\nFurniture Items:" << endl;
        for(int i = 0; i < furnitureSize; i++) {
            cout << i + 1 << ". " << furniture[i] << endl;
        }
        cout << "----------------------------" << endl;
    }
};

int main() {
    Office* myOffice = new Office("Downtown Business Center", 50, 5);
    
    myOffice->setFurniture(0, "Desk");
    myOffice->setFurniture(1, "Chair");
    myOffice->setFurniture(2, "Filing Cabinet");
    myOffice->setFurniture(3, "Bookshelf");
    myOffice->setFurniture(4, "Conference Table");
    
    myOffice->displayOfficeInfo();
    
    delete myOffice;
    
    return 0;
}