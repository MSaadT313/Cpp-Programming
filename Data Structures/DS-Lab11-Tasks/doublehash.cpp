#include <iostream>
using namespace std;

// Maximum table size
const int TABLE_SIZE = 100;

// Node structure for separate chaining
struct Node {
    char key[50];      // the input word
    char meaning[50];  // meaning or value
    Node* next;
};

// Our hash table (array of pointers)
Node* HashTable[TABLE_SIZE];

// ----------------------------------------------------
// Helper: Copy strings manually (since no string library allowed)
// ----------------------------------------------------
void copyString(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// ----------------------------------------------------
// Helper: Compare two strings manually
// ----------------------------------------------------
bool equalString(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' || b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return true;
}

// ----------------------------------------------------
// Hash Function: SUM of ASCII values mod 100
// ----------------------------------------------------
int hashFunction(const char word[]) {
    int sum = 0;
    int i = 0;

    while (word[i] != '\0') {
        sum += word[i];   // add ASCII value
        i++;
    }

    return sum % TABLE_SIZE;
}

// ----------------------------------------------------
// Add_Record() – Insert string into hash table
// ----------------------------------------------------
void Add_Record(const char key[], const char meaning[]) {
    int index = hashFunction(key);

    // Create new node
    Node* newNode = new Node;
    copyString(newNode->key, key);
    copyString(newNode->meaning, meaning);
    newNode->next = NULL;

    // Insert at head of chain
    if (HashTable[index] == NULL) {
        HashTable[index] = newNode;
    } else {
        newNode->next = HashTable[index];
        HashTable[index] = newNode;
    }

    cout << "Record (" << key << ", " << meaning << ") added at index " << index << "!" << endl;
}

// ----------------------------------------------------
// Word_Search() – return meaning or error
// ----------------------------------------------------
void Word_Search(const char key[]) {
    int index = hashFunction(key);

    Node* temp = HashTable[index];
    while (temp != NULL) {
        if (equalString(temp->key, key)) {
            cout << "search key " << key << ": " << temp->meaning << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Error: Word '" << key << "' not found!" << endl;
}

// ----------------------------------------------------
// Delete record
// ----------------------------------------------------
void Delete_Record(const char key[]) {
    int index = hashFunction(key);

    Node* curr = HashTable[index];
    Node* prev = NULL;

    while (curr != NULL) {
        if (equalString(curr->key, key)) {
            if (prev == NULL)
                HashTable[index] = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            cout << "key " << key << " deleted successfully !" << endl;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Error: key '" << key << "' not found!" << endl;
}

// ----------------------------------------------------
// Print_Dictionary() – Print full table
// ----------------------------------------------------
void Print_Dictionary() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (HashTable[i] != NULL) {
            cout << "index " << i << ": ";

            Node* temp = HashTable[i];
            while (temp != NULL) {
                cout << "(" << temp->key << ", " << temp->meaning << ") ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
}

// ----------------------------------------------------
// MAIN FUNCTION (Example Demonstration)
// ----------------------------------------------------
int main() {
    // Initialize table
    for (int i = 0; i < TABLE_SIZE; i++)
        HashTable[i] = NULL;

    // Adding records
    Add_Record("AB", "FASTNU");
    Add_Record("CD", "CS");
    Add_Record("EF", "STUDENT");

    // Searching
    Word_Search("AB");

    // Deleting
    Delete_Record("EF");

    // Display
    Print_Dictionary();

    return 0;
}
