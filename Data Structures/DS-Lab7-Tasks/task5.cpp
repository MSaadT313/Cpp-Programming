#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(nullptr) {}
};

Node* getTail(Node* cur) {
    while(cur && cur->next) cur = cur->next;
    return cur;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot=end, *prev=nullptr, *cur=head, *tail=pivot;
    while(cur!=pivot) {
        if(cur->data < pivot->data) {
            if(!(*newHead)) *newHead = cur;
            prev = cur; cur = cur->next;
        } else {
            if(prev) prev->next = cur->next;
            Node* tmp = cur->next;
            cur->next = nullptr;
            tail->next = cur; tail = cur;
            cur = tmp;
        }
    }
    if(!(*newHead)) *newHead = pivot;
    *newEnd = tail;
    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if(!head || head==end)
        return head;
    Node *newHead=nullptr, *newEnd=nullptr;
    Node* pivot = partition(head,end,&newHead,&newEnd);
    if(newHead!=pivot) {
        Node* tmp=newHead;
        while(tmp->next!=pivot) tmp=tmp->next;
        tmp->next = nullptr;
        newHead = quickSortRecur(newHead,tmp);
        tmp = getTail(newHead); tmp->next = pivot;
    }
    pivot->next = quickSortRecur(pivot->next,newEnd);
    return newHead;
}

void print(Node* head) {
    while(head) {
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

int main() {
    int arr[] = {10,7,8,9,1,5,3};
    Node* head = nullptr;
    for(int i=6;i>=0;i--) {
        Node* n = new Node(arr[i]);
        n->next = head;
        head = n;
    }
    head = quickSortRecur(head,getTail(head));
    print(head);
    return 0;
}
