/*You are given the array (3 1 2, 5, 8) of size 5 print that array on screen. Then create singly linked list from
that array , Now add the 9 at the end , 11 pos 3, and 4 at the front and list. Now delete the 1, 2, and 5 then
print the linked list.*/

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

    void insertAtFront(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtPos(int val, int pos)
    {
        if (pos == 1)
        {
            insertAtFront(val);
            return;
        }
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp; i++)
            temp = temp->next;
        if (!temp)
            return;
        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(int val)
    {
        if (!head)
            return;
        if (head->data == val)
        {
            Node *toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }
        Node *temp = head;
        while (temp->next && temp->next->data != val)
            temp = temp->next;
        if (temp->next)
        {
            Node *toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
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
};

int main()
{
    int arr[5] = {3, 1, 2, 5, 8};
    for (int i = 0; i < 5; i++)
        cout << arr[i] << " ";
    cout << endl;

    SinglyLinkedList list;
    for (int i = 0; i < 5; i++)
        list.insertAtEnd(arr[i]);

    list.insertAtEnd(9);
    list.insertAtPos(11, 3);
    list.insertAtFront(4);
    list.deleteValue(1);
    list.deleteValue(2);
    list.deleteValue(5);
    list.display();
}
