/*Write a program that prompts the user to enter a number indicating how many elements to move to the
end of a linked list. The program should then move that exact number of elements from the beginning of
the linked list to the end.
Example: given list: 5, 3 1 8 6 4 2
Enter the number: 2
After rotation: 1 8 6 4 2 5 3*/

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList
{
public:
    Node *head;
    SinglyLinkedList() : head(NULL) {}

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void rotate(int k)
    {
        if (!head || k == 0)
            return;

        Node *temp = head;
        int length = 1;
        while (temp->next)
        {
            temp = temp->next;
            length++;
        }
        temp->next = head;

        k = k % length;
        int steps = length - k;
        Node *newTail = head;
        for (int i = 1; i < steps; i++)
            newTail = newTail->next;

        head = newTail->next;
        newTail->next = NULL;
    }
};

int main()
{
    SinglyLinkedList list;
    int arr[] = {5, 3, 1, 8, 6, 4, 2};
    for (int val : arr)
        list.insertAtEnd(val);

    cout << "Original list: ";
    list.display();

    int k;
    cout << "Enter the number: ";
    cin >> k;

    list.rotate(k);

    cout << "After rotation: ";
    list.display();
}
