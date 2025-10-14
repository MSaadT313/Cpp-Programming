#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderID;
    string itemName;
    int quantity;
};

class OrderQueue {
    int front, rear, size, count;
    Order* arr;

public:
    OrderQueue(int s) {
        size = s;
        arr = new Order[size];
        front = rear = -1;
        count = 0;
    }

    bool isFull() {
        return (rear + 1) % size == front;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(Order o) {
        if (isFull()) {
            cout << "\nQueue Overflow! Cannot add more orders.\n";
            return;
        }

        if (isEmpty()) front = 0;

        rear = (rear + 1) % size;
        arr[rear] = o;
        count++;

        cout << "Order " << o.orderID << " (" << o.itemName << " x" << o.quantity << ") added to queue.\n";
    }

    Order dequeue() {
        Order temp;

        if (isEmpty()) {
            cout << "\nQueue Underflow! No orders to process.\n";
            temp = {0, "None", 0};
            return temp;
        }

        temp = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;

        count--;
        cout << "Processing Order " << temp.orderID << " (" << temp.itemName << " x" << temp.quantity << ")\n";
        return temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nNo orders in the queue.\n";
            return;
        }

        cout << "\nAll Orders in Queue (FIFO):\n";
        int i = front;
        while (true) {
            cout << "OrderID: " << arr[i].orderID
                 << " | Item: " << arr[i].itemName
                 << " | Quantity: " << arr[i].quantity << endl;

            if (i == rear)
                break;

            i = (i + 1) % size;
        }
    }
};

int main() {
    OrderQueue queue(5);
    int choice, id = 1;

    while (true) {
        cout << "\n--- Restaurant Order Management ---\n";
        cout << "1. Add Order\n";
        cout << "2. Process Order\n";
        cout << "3. View All Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            Order o;
            o.orderID = id++;
            cout << "Enter item name: ";
            cin.ignore();
            getline(cin, o.itemName);
            cout << "Enter quantity: ";
            cin >> o.quantity;
            queue.enqueue(o);
        } 
        else if (choice == 2) {
            queue.dequeue();
        } 
        else if (choice == 3) {
            queue.display();
        } 
        else if (choice == 4) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
