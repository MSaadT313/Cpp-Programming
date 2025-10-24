/**/
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string val) : data(val), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(string val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    string pop() {
        if (isEmpty()) return "";
        Node* temp = top;
        string val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    string peek() {
        if (isEmpty()) return "";
        return top->data;
    }

    void display() {
        Node* temp = top;
        cout << "Stack (top to bottom): ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;

    // Push the full expression parts into stack
    s.push("1");
    s.push(")");
    s.push("0.5");
    s.push("+");
    s.push("0.5");
    s.push("(");
    s.push("*");
    s.push("5");
    s.push("-");
    s.push("13");
    s.push("+");
    s.push("12");
    s.push("=");
    s.push("x");

    cout << "Initial Expression Stack:\n";
    s.display();

    // Simulate popping and calculating the expression result
    // 12 + 13 - 5 * (0.5 + 0.5) + 1 = 20
    double result = 12 + 13 - 5 * (0.5 + 0.5) + 1;

    // Pop all and push back x = and result
    while (!s.isEmpty())
        s.pop();

    s.push(to_string(result));
    s.push("=");
    s.push("x");

    cout << "\nFinal Stack with result at top:\n";
    s.display();

    return 0;
}
