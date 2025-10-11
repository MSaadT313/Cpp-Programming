#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int lengthTailRec(Node* head, int count = 0) {
    if (head == nullptr) return count;
    return lengthTailRec(head->next, count + 1);
}

int main() {
    Node* head = new Node{1, new Node{2, new Node{3, nullptr}}};
    cout << "Length of linked list: " << lengthTailRec(head) << endl;
    return 0;
}
