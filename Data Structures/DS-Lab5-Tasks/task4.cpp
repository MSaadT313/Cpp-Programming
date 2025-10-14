#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v) : data(v), next(NULL) {}
};

class List {
    Node* head;
public:
    List() : head(NULL) {}
    void push(int v) {
        Node* n = new Node(v);
        n->next = head;
        head = n;
    }
    bool search(Node* p, int key) {
        if (!p) return false;
        if (search(p->next, key)) return true;
        return p->data == key;
    }
    bool find(int key) {
        return search(head, key);
    }
};

int main() {
    List l;
    l.push(5);
    l.push(10);
    l.push(15);
    l.push(20);
    int x;
    cin >> x;
    if (l.find(x)) cout << "Found\n";
    else cout << "Not Found\n";
}
