/*Delete a value from any position (not the first one only) from the singly linked list if it’s present in the
list otherwise show a message to the user that the value is not present in the list.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(NULL) {}

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val) {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        } else {
            cout << "Value not found in list" << endl;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    list.display();

    list.deleteValue(30);
    list.display();

    list.deleteValue(50);

    return 0;
}
