/*Create a circular link list and perform the mentioned tasks.
a. Insert a new node at the end of the list.
b. Insert a new node at the beginning of list.
c. Insert a new node at given position.
d. Delete any node.
e. Print the complete circular link list.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class CircularLinkedList {
public:
    Node* last;
    CircularLinkedList() : last(NULL) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
            last = newNode;
        }
    }

    void insertBeginning(int val) {
        Node* newNode = new Node(val);
        if (!last) {
            last = newNode;
            last->next = last;
        } else {
            newNode->next = last->next;
            last->next = newNode;
        }
    }

    void insertAtPosition(int val, int pos) {
        if (!last && pos != 1) {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1) {
            insertBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = last->next;
        for (int i = 1; i < pos - 1 && temp != last; i++) {
            temp = temp->next;
        }
        if (temp == last && pos > 2) {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if (temp == last) last = newNode;
    }

    void deleteNode(int val) {
        if (!last) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = last->next;
        Node* prev = last;
        do {
            if (temp->data == val) {
                if (temp == last && temp->next == last) {
                    delete temp;
                    last = NULL;
                    return;
                }
                if (temp == last) last = prev;
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != last->next);
        cout << "Value not found" << endl;
    }

    void display() {
        if (!last) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = last->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;
    cll.insertEnd(10);
    cll.insertEnd(20);
    cll.insertEnd(30);
    cll.display();

    cll.insertBeginning(5);
    cll.display();

    cll.insertAtPosition(15, 3);
    cll.display();

    cll.deleteNode(20);
    cll.display();

    cll.deleteNode(100);

    return 0;
}
