#include<iostream>
using namespace std;
struct Node{
    string data;
    Node* next;
    string key;
    Node(string k, string l){
        key = k;
        data = l;
        next = nullptr;
    }

};
class HashTable{
    Node** table;
    int table_size;
    public:
    HashTable(int size){
    table_size = size;
            table = new Node*[table_size];
            for (int i = 0; i < table_size; i++)
            {
                table[i] = nullptr;
            }
    }
    void insert(string key, string data){
        int index = int(key[0])%table_size;
        Node* newNode = new Node(key, data);
        newNode->next = table[index]; //already present value is shifted to the next of the new node and is replaced by it
        table[index] = newNode;
        cout << "Inserted (" << key << ", " << data << ") in bucket " << index << endl;
    }

};
int main(){
    HashTable hash1(10);
    hash1.insert("A","aaaaa");
    hash1.insert("B","bbbbb");
    hash1.insert("C","ccccc");
    hash1.insert("A","zzzzz");
    
    return 0;
}