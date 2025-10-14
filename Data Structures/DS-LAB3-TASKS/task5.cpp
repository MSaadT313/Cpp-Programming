/*Solve the following problem using a Singly Linked List.
Given a Linked List of integers or string, write a function to check if the entirety of the linked list is a
palindrome or not*/

#include <iostream>
using namespace std;

struct Node {
    char data;  
    Node* next;
    Node(char val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
public:
    Node* head;
    SinglyLinkedList() : head(NULL) {}

    void insertAtEnd(char val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    Node* reverse(Node* node) {
        Node* prev = NULL;
        Node* curr = node;
        Node* next = NULL;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    bool isPalindrome() {
        if (!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* secondHalf = reverse(slow->next);

        Node* firstHalf = head;
        Node* checkHalf = secondHalf;
        bool palindrome = true;

        while (checkHalf) {
            if (firstHalf->data != checkHalf->data) {
                palindrome = false;
                break;
            }
            firstHalf = firstHalf->next;
            checkHalf = checkHalf->next;
        }

        slow->next = reverse(secondHalf);

        return palindrome;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << "->NULL" << endl;
    }
};

int main() {
    SinglyLinkedList list1;
    int arr1[] = {1, 0, 2, 0, 1};
    for (int x : arr1) list1.insertAtEnd(x + '0');

    cout << "Input: ";
    list1.display();
    if (list1.isPalindrome())
        cout << "Output: Linked List is a Palindrome\n";
    else
        cout << "Output: Linked List is NOT a Palindrome\n";

    SinglyLinkedList list2;
    string s = "BORROWORROB";
    for (char c : s) list2.insertAtEnd(c);

    cout << "\nInput: ";
    list2.display();
    if (list2.isPalindrome())
        cout << "Output: Linked List is a Palindrome\n";
    else
        cout << "Output: Linked List is NOT a Palindrome\n";

    return 0;
}
