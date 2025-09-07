/*Solve the following problem using a Singly Linked List.
Given a Linked List of integers, write a function to modify the linked list such that all even numbers appear
before all the odd numbers in the modified linked list. Also, keep the order of even and odd numbers same.*/

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

    void rearrangeEvenOdd() {
        if (!head || !head->next) return;

        Node* evenHead = NULL, *evenTail = NULL;
        Node* oddHead = NULL, *oddTail = NULL;
        Node* curr = head;

        while (curr) {
            if (curr->data % 2 == 0) {
                if (!evenHead) {
                    evenHead = curr;
                    evenTail = curr;
                } else {
                    evenTail->next = curr;
                    evenTail = evenTail->next;
                }
            } else {
                if (!oddHead) {
                    oddHead = curr;
                    oddTail = curr;
                } else {
                    oddTail->next = curr;
                    oddTail = oddTail->next;
                }
            }
            curr = curr->next;
        }

        if (!evenHead || !oddHead) return;

        evenTail->next = oddHead;
        oddTail->next = NULL;
        head = evenHead;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int arr[] = {17, 15, 8, 12, 10, 5, 4, 1, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) list.insertAtEnd(arr[i]);

    cout << "Input: ";
    list.display();

    list.rearrangeEvenOdd();

    cout << "Output: ";
    list.display();

    return 0;
}
