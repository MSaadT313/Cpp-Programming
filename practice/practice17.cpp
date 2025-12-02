#include <iostream>
using namespace std;

// Maximum number of flight codes
const int MAX_POSITIONS = 20;

// Node structure for chaining
struct Node {
    char code[10]; // store flight code manually (like "AA123")
    Node* next;
};

// Hash table of pointers
Node* table[MAX_POSITIONS];

// ---------------- Hash Function --------------------
int hashFunction(char airline1, char airline2) {
    int h = (airline1 - 'A') * 26 + (airline2 - 'A');
    return h % MAX_POSITIONS;
}

// ---------------- Insert Function -------------------
void insertFlight(char code[]) {
    char a = code[0];
    char b = code[1];
    int index = hashFunction(a, b);

    // Create new node
    Node* newNode = new Node;
    
    int i = 0;
    while (code[i] != '\0') {
         newNode->code[i] = code[i];
          i++; 
        }
    newNode->code[i] = '\0';

    newNode->next = table[index];
    table[index] = newNode;

    cout << "Inserted at bucket " << index << endl;
}

// ---------------- Delete Function -------------------
void deleteFlight(char code[]) {
    char a = code[0];
    char b = code[1];
    int index = hashFunction(a, b);

    Node* curr = table[index];
    Node* prev = NULL;

    while (curr != NULL) {
        int i = 0;
        bool match = true;
        while (code[i] != '\0' || curr->code[i] != '\0') {
            if (code[i] != curr->code[i]) { match = false; break; }
            i++;
        }

        if (match) {
            if (prev == NULL)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            cout << "Deleted from bucket " << index << endl;
            return;
        }

        prev = curr;
        curr = curr->next;
    }

    cout << "Flight code not found." << endl;
}

// ---------- Merge Sort for Linked List ---------------
Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    // Compare lexicographically
    int i = 0;
    while (a->code[i] != '\0' && b->code[i] != '\0' && a->code[i] == b->code[i])
        i++;

    if (a->code[i] <= b->code[i]) {
        a->next = mergeLists(a->next, b);
        return a;
    } else {
        b->next = mergeLists(a, b->next);
        return b;
    }
}

void splitList(Node* src, Node*& a, Node*& b) {
    Node* slow = src;
    Node* fast = src->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    a = src;
    b = slow->next;
    slow->next = NULL;
}

void mergeSort(Node*& head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* a;
    Node* b;

    splitList(head, a, b);

    mergeSort(a);
    mergeSort(b);

    head = mergeLists(a, b);
}

// ---------------- Sorting Each Bucket -------------------
void sortBuckets() {
    for (int i = 0; i < MAX_POSITIONS; i++) {
        mergeSort(table[i]);
    }
}

// ---------------- Display Function ----------------------
void displayAll() {
    cout << "\nAll flight codes (sorted inside buckets):\n";
    for (int i = 0; i < MAX_POSITIONS; i++) {
        cout << "Bucket " << i << ": ";
        Node* curr = table[i];
        while (curr != NULL) {
            cout << curr->code << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

// ---------------- Main -------------------
int main() {
    // Initialize table
    for (int i = 0; i < MAX_POSITIONS; i++)
        table[i] = NULL;

    // Example Usage
    insertFlight((char*)"AA100");
    insertFlight((char*)"AA200");
    insertFlight((char*)"BA150");
    insertFlight((char*)"CZ999");
    insertFlight((char*)"BA120");

    cout << "\nSorting buckets...\n";
    sortBuckets();

    displayAll();

    cout << "\nDeleting BA150...\n";
    deleteFlight((char*)"BA150");

    displayAll();

    return 0;
}
