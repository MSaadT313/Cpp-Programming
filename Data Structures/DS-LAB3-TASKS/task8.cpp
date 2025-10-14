/*Give an efficient algorithm for concatenating two doubly linked lists L and M, with head and tail preserved
nodes, into a single list that contains all the nodes of L followed by all the nodes of M.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(NULL), tail(NULL) {}
    
    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
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

DoublyLinkedList concatenate(DoublyLinkedList& L, DoublyLinkedList& M) {
    if (!L.head) return M;
    if (!M.head) return L;
    L.tail->next = M.head;
    M.head->prev = L.tail;
    L.tail = M.tail;
    return L;
}

int main() {
    DoublyLinkedList L, M;
    L.insertEnd(1);
    L.insertEnd(2);
    L.insertEnd(3);
    M.insertEnd(4);
    M.insertEnd(5);
    M.insertEnd(6);

    cout << "List L: "; L.display();
    cout << "List M: "; M.display();

    DoublyLinkedList result = concatenate(L, M);
    cout << "Concatenated List: "; result.display();
}
