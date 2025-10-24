/**/
#include <iostream>
using namespace std;

#define MAX 10

class Queue {
    int arr[MAX];
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

    void enqueue(int id) {
        if (isFull()) {
            cout << "Queue is full, cannot add customer " << id << endl;
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = id;
        cout << "Customer " << id << " joined the queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty, no customer to checkout." << endl;
            return;
        }
        cout << "Customer " << arr[front] << " checked out." << endl;
        front++;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = sizeof(customers) / sizeof(customers[0]);

    for (int i = 0; i < n; i++)
        q.enqueue(customers[i]);

    cout << endl;
    q.display();

    cout << "\nProcessing checkouts...\n";
    while (!q.isEmpty())
        q.dequeue();

    cout << "\nAll customers checked out.\n";
    return 0;
}
