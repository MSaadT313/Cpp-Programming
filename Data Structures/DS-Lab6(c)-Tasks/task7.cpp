/*Consider a library where books are borrowed and returned by multiple patrons. The library
has a limited number of staff members to handle the book transactions. As patrons arrive with books
to borrow or return, they are added to a linear queue. Each book transaction can take a variable amount of time to complete, depending on factors such as the number of books being borrowed or returned,and the availability of the staff members. Once a book transaction is completed, the next patron in the queue is serviced.
Write a C++ program that simulates this library scenario using a linear queue data structure. The
program should allow patrons to add themselves to the queue, remove themselves from the queue
when their book transaction is completed, and display the current queue of patrons waiting for book
transactions to be serviced.*/
#include <iostream>
#include <string>
using namespace std;

#define MAX 10

class Queue {
    string arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    bool isFull() {
        return rear == MAX - 1;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full! Patron " << name << " cannot join right now.\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = name;
        cout << "Patron " << name << " joined the queue.\n";
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No patrons in queue.\n";
            return;
        }
        cout << "Patron " << arr[front] << " has completed their book transaction.\n";
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "No patrons are currently waiting.\n";
            return;
        }
        cout << "Patrons currently waiting: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue libraryQueue;
    int choice;
    string name;

    cout << "=== Library Book Transaction System ===\n";

    do {
        cout << "\n1. Add Patron to Queue (Borrow/Return Books)";
        cout << "\n2. Complete Transaction (Remove Patron)";
        cout << "\n3. Display Current Queue";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Patron Name: ";
            cin >> name;
            libraryQueue.enqueue(name);
            break;
        case 2:
            libraryQueue.dequeue();
            break;
        case 3:
            libraryQueue.display();
            break;
        case 4:
            cout << "Exiting the system.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
