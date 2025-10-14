#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Transaction {
    int id;
    double amount;
    string description;
    int flag;
};

struct Node {
    Transaction data;
    Node* next;
    Node(Transaction t) : data(t), next(NULL) {}
};

class TransactionStack {
    Node* top;
    int count;
public:
    TransactionStack() { top = NULL; count = 0; }

    void push(Transaction t) {
        t.id = ++count;

        if (t.description.length() > 20)
            t.description = t.description.substr(0, 20) + "...";

        if (t.amount >= 0) {
            if (t.amount >= 1500)
                t.amount -= t.amount * 0.30;
            else if (t.amount >= 1000)
                t.amount -= t.amount * 0.15;
            else if (t.amount >= 500)
                t.amount -= t.amount * 0.05;
            t.flag = 1;
        } else {
            t.flag = 0;
        }

        Node* newNode = new Node(t);
        newNode->next = top;
        top = newNode;
    }

    Transaction pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            Transaction dummy = {0, 0, "None", -1};
            return dummy;
        }
        Node* temp = top;
        Transaction t = top->data;
        top = top->next;
        delete temp;

        t.amount *= -1;
        t.description += " [REVERSED]";
        t.flag = 2;
        return t;
    }

    void display() {
        if (top == NULL) {
            cout << "Stack is empty.\n";
            return;
        }
        Node* curr = top;
        cout << "Top → ";
        while (curr != NULL) {
            cout << "[id=" << curr->data.id
                 << ", amt=" << curr->data.amount
                 << ", desc=\"" << curr->data.description
                 << "\", flag=" << curr->data.flag << "]";
            curr = curr->next;
            if (curr) cout << endl;
        }
        cout << endl;
    }
};

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') return a / b;
    return 0;
}

string infixToPostfix(string expr) {
    char stack[100];
    int top = -1;
    string postfix = "";

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == ' ') continue;

        if ((c >= '0' && c <= '9') || c == '.') {
            postfix += c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            postfix += ' ';
            while (top >= 0 && stack[top] != '(') {
                postfix += stack[top--];
                postfix += ' ';
            }
            top--;
        } else {
            postfix += ' ';
            while (top >= 0 && precedence(stack[top]) >= precedence(c)) {
                postfix += stack[top--];
                postfix += ' ';
            }
            stack[++top] = c;
        }
    }

    while (top >= 0) {
        postfix += ' ';
        postfix += stack[top--];
    }

    return postfix;
}

double evaluatePostfix(string expr) {
    double stack[100];
    int top = -1;
    string num = "";

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];
        if (c == ' ') {
            if (!num.empty()) {
                stack[++top] = atof(num.c_str());
                num = "";
            }
        } else if ((c >= '0' && c <= '9') || c == '.') {
            num += c;
        } else {
            double b = stack[top--];
            double a = stack[top--];
            stack[++top] = applyOp(a, b, c);
        }
    }

    return stack[top];
}

int main() {
    srand(time(0));

    Transaction list[7] = {
        {0, 1200, "Sale: Blue Jacket", 0},
        {0, 450, "Sale: Cotton Socks", 0},
        {0, -300, "Refund: Defective Shirt", 0},
        {0, 1700, "Sale: Leather Jacket", 0},
        {0, 800, "Sale: Jeans", 0},
        {0, -150, "Refund: Wrong Size", 0},
        {0, 600, "Sale: Hat", 0}
    };

    TransactionStack stack;

    for (int i = 0; i < 4; i++) {
        int index = rand() % 7;
        stack.push(list[index]);
    }

    cout << "Pushed Transactions:\n";
    stack.display();

    string infix = "(100 + 20) * 0.9 - 5";
    string postfix = infixToPostfix(infix);
    double result = evaluatePostfix(postfix);

    cout << "\nIntermediate Expression Calculation:\n";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;
    cout << "Evaluated Result: " << result << endl;

    cout << "\nPop (remove) one transaction:\n";
    Transaction popped = stack.pop();
    cout << "Popped Transaction: " << popped.description << endl;
    cout << "Amount changed to " << popped.amount << endl;
    cout << "Flag updated to " << popped.flag << endl;

    cout << "\nFinal Stack Output:\n";
    stack.display();

    return 0;
}
