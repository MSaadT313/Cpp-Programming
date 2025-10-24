/**/
#include <iostream>
using namespace std;

#define MAX 10

struct Node {
    string url;
    Node* next;
    Node(string u) : url(u), next(nullptr) {}
};

class Stack {
    string arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(string item) {
        if (!isFull()) arr[++top] = item;
    }

    void pop() {
        if (!isEmpty()) top--;
    }

    string peek() {
        if (!isEmpty()) return arr[top];
        return "No page";
    }
};

class BrowserHistory {
    Node* head;
    Stack history;
public:
    BrowserHistory() { head = nullptr; }

    void visit(string site) {
        Node* newNode = new Node(site);
        newNode->next = head;
        head = newNode;
        history.push(site);
    }

    void back(int steps) {
        while (steps-- && head != nullptr && !history.isEmpty()) {
            history.pop();
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void showCurrentPage() {
        if (head) cout << "Current page: " << head->url << endl;
        else cout << "No pages in history" << endl;
    }
};

int main() {
    BrowserHistory bh;
    bh.visit("Google");
    bh.visit("Facebook");
    bh.visit("Twitter");
    bh.visit("LinkedIn");
    bh.visit("Instagram");

    bh.back(2);
    bh.showCurrentPage();
    return 0;
}
