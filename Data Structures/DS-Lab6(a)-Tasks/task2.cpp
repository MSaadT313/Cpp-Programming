#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
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
}

void display(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* temp = head;
        while (temp->next) {
            if (temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while (swapped);
}

void mergeAlternate(Node*& head1, Node*& head2) {
    Node* curr1 = head1;
    Node* curr2 = head2;
    while (curr1 && curr2) {
        Node* next1 = curr1->next;
        Node* next2 = curr2->next;
        curr1->next = curr2;
        curr2->next = next1;
        curr1 = next1;
        curr2 = next2;
    }
    head2 = curr2;
}

int main() {
    Node* head = nullptr;
    insertEnd(head, 5);
    insertEnd(head, 3);
    insertEnd(head, 8);
    insertEnd(head, 1);
    insertEnd(head, 4);
    display(head);
    bubbleSort(head);
    display(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;
    insertEnd(head1, 1);
    insertEnd(head1, 2);
    insertEnd(head1, 3);
    insertEnd(head2, 4);
    insertEnd(head2, 5);
    insertEnd(head2, 6);
    insertEnd(head2, 7);
    insertEnd(head2, 8);
    display(head1);
    display(head2);
    mergeAlternate(head1, head2);
    display(head1);
    display(head2);
}
