#include<iostream>
#include<string>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
    Node(string n, int s) : name(n), score(s), next(nullptr) {}
};

void addNode(Node* &head, string name, int score) {
    Node* n = new Node(name, score);
    n->next = head;
    head = n;
}

void print(Node* head) {
    while(head) {
        cout << head->name << " " << head->score << endl;
        head = head->next;
    }
}

int getMax(Node* head) {
    int mx = 0;
    while(head) {
        mx = max(mx, head->score);
        head = head->next;
    }
    return mx;
}

Node* countingSort(Node* head, int exp) {
    Node* arr[10000];
    int cnt[10] = {};
    Node* cur = head;
    int n = 0;
    while(cur) {
        cnt[(cur->score/exp)%10]++;
        cur = cur->next;
        n++;
    }
    for(int i=1;i<10;i++) cnt[i] += cnt[i-1];
    cur = head;
    Node* tmp[10000];
    int ix = n-1;
    while(cur) {
        int idx = (cur->score/exp)%10;
        arr[cnt[idx]-1] = cur;
        cnt[idx]--;
        cur = cur->next;
    }
    for(int i=0; i<n; i++) arr[i]->next = (i+1<n) ? arr[i+1] : nullptr;
    return n ? arr[0] : nullptr;
}

Node* radixSort(Node* head) {
    int mx = getMax(head);
    for(int exp=1; mx/exp>0; exp*=10)
        head = countingSort(head, exp);
    return head;
}

void deleteRecord(Node* &head, string name, int score) {
    Node* cur = head, *prev = nullptr;
    while(cur) {
        if(cur->name == name && cur->score == score) {
            if(prev) prev->next = cur->next;
            else head = cur->next;
            delete cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}

int main() {
    Node* head = nullptr;
    addNode(head, "Ayan", 90);
    addNode(head, "Zameer", 60);
    addNode(head, "Sara", 70);
    addNode(head, "Sohail", 30);
    addNode(head, "Ahmed", 20);
    head = radixSort(head);
    print(head);
    string n;
    int s;
    cin >> n >> s;
    deleteRecord(head, n, s);
    print(head);
    return 0;
}
