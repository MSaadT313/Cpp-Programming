#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

void insertEnd(Node*& head, int val) {
    Node* n = new Node(val);
    if (!head) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteFront(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}

void deleteLast(Node*& head) {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPos(Node*& head, int pos) {
    if (!head || pos <= 0) return;
    if (pos == 1) {
        deleteFront(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; temp && i < pos; i++) temp = temp->next;
    if (!temp) return;
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    delete temp;
}

Node* reverseRecursive(Node* head) {
    if (!head) return nullptr;
    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    if (!head->prev) return head;
    return reverseRecursive(head->prev);
}

int main() {
    Node* head = nullptr;
    for (int i = 1; i <= 5; i++) insertEnd(head, i);
    display(head);
    deleteFront(head);
    display(head);
    deleteLast(head);
    display(head);
    deleteAtPos(head, 2);
    display(head);
    head = reverseRecursive(head);
    display(head);
}
