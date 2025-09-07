/*Given a linked list, you have to perform the following task:
1. Extract the alternative nodes starting from second node.
2. Reverse the extracted list.
3. Append the extracted list at the end of the original list.*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(NULL) {}

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void rearrange() {
        if (!head || !head->next) return;

        Node* odd = head;
        Node* even = head->next;
        Node* evenHead = even;

        while (odd->next && even->next) {
            odd->next = even->next;
            odd = odd->next;
            if (odd->next) {
                even->next = odd->next;
                even = even->next;
            } else break;
        }
        even->next = NULL;

        Node* prev = NULL;
        Node* curr = evenHead;
        Node* nxt = NULL;
        while (curr) {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        odd->next = prev;
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
    LinkedList list;
    list.insertEnd(10);
    list.insertEnd(4);
    list.insertEnd(9);
    list.insertEnd(1);
    list.insertEnd(3);
    list.insertEnd(5);
    list.insertEnd(9);
    list.insertEnd(4);

    cout << "Original List: ";
    list.display();

    list.rearrange();

    cout << "Modified List: ";
    list.display();
}
