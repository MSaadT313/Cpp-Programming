/**/
#include <iostream>
using namespace std;

#define MAX 50

class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }

    void push(char c) {
        if (!isFull()) arr[++top] = c;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return '\0';
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return -1;
}

string infixToPostfix(string exp) {
    Stack st;
    string result = "";

    for (char ch : exp) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            result += ch;
        else if (ch == '(')
            st.push(ch);
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                result += st.pop();
            st.pop();
        }
        else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                if (ch == '^' && st.peek() == '^') break; // right-associative
                result += st.pop();
            }
            st.push(ch);
        }
    }

    while (!st.isEmpty())
        result += st.pop();

    return result;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
