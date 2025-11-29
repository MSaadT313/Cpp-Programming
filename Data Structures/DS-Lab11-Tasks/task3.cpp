#include <iostream>
#include <list>
#include <string>

using namespace std;

const int TABLE_SIZE = 100;

class Hash {
private:
    list<string> table[TABLE_SIZE]; 

public:
    int hashFunction(const string& key) {
        int sum = 0;
        for (char ch : key) sum += int(ch);
        return sum % TABLE_SIZE;
    }

    void insert(const string& key) {
        int index = hashFunction(key);
        table[index].push_back(key);
        cout << "Inserted \"" << key << "\" at index " << index << endl;
    }

    void remove(const string& key) {
        int index = hashFunction(key);
        table[index].remove(key);  
        cout << "Deleted \"" << key << "\" from index " << index << endl;
    }

    void search(const string& key) {
        int index = hashFunction(key);
        for (auto &item : table[index]) {
            if (item == key) {
                cout << "String \"" << key << "\" found at index " << index << endl;
                return;
            }
        }
        cout << "String \"" << key << "\" not found!" << endl;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (!table[i].empty()) {
                cout << "Index " << i << ": ";
                for (auto &item : table[i]) cout << "(" << item << ") ";
                cout << endl;
            }
        }
    }
};

int main() {
    Hash h;

    h.insert("AB");
    h.insert("FASTNU");
    h.insert("CD");
    h.insert("CS");
    h.insert("EF");

    cout << endl;

    h.search("AB");
    h.remove("EF");

    cout << endl << "Dictionary:" << endl;
    h.display();

    return 0;
}
