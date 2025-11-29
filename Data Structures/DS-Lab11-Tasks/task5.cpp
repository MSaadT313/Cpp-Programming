#include<iostream>
using namespace std;

const int table_size = 15;

class Hashtable {
    bool occupied[table_size];
    int Roll[table_size];
    string name[table_size];

public:
    Hashtable() {
        for (int i = 0; i < table_size; i++) {
            occupied[i] = false;
            Roll[i] = 0;
            name[i] = "";
        }
    }

    void insert(int num, string data) {
        int index;
        for (int i = 0; i < table_size; i++) {
            index = (num + i*i) % table_size;

            if (!occupied[index]) {        
                occupied[index] = true;
                Roll[index] = num;
                name[index] = data;
                return;
            }
        }
        cout << "Hash table full, cannot insert!\n";
    }

    void Search(int num) {
        int index;
        for (int i = 0; i < table_size; i++) {
            index = (num + i*i) % table_size;

            if (!occupied[index]) {       
                cout << "No Student Found\n";
                return;
            }

            if (occupied[index] && Roll[index] == num) {
                cout << "Student Found: " << name[index] 
                     << " at index " << index << endl;
                return;
            }
        }
        cout << "No Student Found\n"; 
    }
};

int main() {
    Hashtable hash;
    hash.insert(213, "saad");
    hash.insert(22, "shayan");
    hash.insert(2143, "sfff");
    hash.insert(213, "duplicate?");

    hash.Search(213);
    hash.Search(22);
    hash.Search(2143);
    hash.Search(999);

    return 0;
}
