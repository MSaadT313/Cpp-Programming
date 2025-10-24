/**/
#include <iostream>
using namespace std;

#define MAX 5

class Stack {
    string arr[MAX];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX - 1;
    }

    void push(string item) {
        if (!isFull()) arr[++top] = item;
        else cout << "Stack full\n";
    }

    void pop() {
        if (!isEmpty()) top--;
        else cout << "Stack empty\n";
    }

    string peek() {
        if (!isEmpty()) return arr[top];
        else return "No task";
    }
};

int main() {
    Stack todo;
    todo.push("Finish report");
    todo.push("Call client");
    todo.push("Book meeting");

    if (!todo.isEmpty()) {
        cout << "Next task: " << todo.peek() << endl;
        todo.pop();
    }

    return 0;
}
