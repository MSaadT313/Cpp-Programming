#include <iostream>
using namespace std;
#define MAX 100
class Stack
{
    int top;
    char arr[MAX];
public:
    Stack()
    {
        top = -1;
    }
    bool push(char x)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow\n";
            return false;
        }
        arr[++top] = x;
        return true;
    }
    char pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow\n";
            return '\0';
        }
        return arr[top--];
    }
    bool isEmpty()
    {
        return (top < 0);
    }
};

int main()
{
    Stack s;
    string word = "BORROWROB";
    for (int i = 0; i < word.length(); i++)
    {
        s.push(word[i]);
    }
    string reversed = "";
    while (!s.isEmpty())
    {
        reversed += s.pop();
    }
    cout << "Original Word: " << word << endl;
    cout << "Reversed Word: " << reversed << endl;
    if (word == reversed)
        cout << "Result: The word is a PALINDROME." << endl;
    else
        cout << "Result: The word is NOT a palindrome." << endl;

    return 0;
}
