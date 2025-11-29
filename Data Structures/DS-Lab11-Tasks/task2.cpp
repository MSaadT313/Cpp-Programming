#include<iostream>
using namespace std;
const int table_size = 100;
struct Node{
    string data;
    Node* next;
    Node(string value){
        data = value; 
        next = nullptr;
    }
};
class HashTable{
    Node** table;
    public:
    HashTable(){
        table = new Node*[table_size];
        for (int i = 0; i < table_size; i++)
        {
            table[i] = nullptr;
        }
    }
    void Add_Record(string value){
        int n = calculate_mod(value);
        Node* newNode = new Node(value);
        newNode->next = table[n];
        table[n] = newNode;
    }

    int calculate_mod(string value){
        int sum = 0;
        for (int i = 0; i < value.length(); i++)
        {
            int k = int(value[i]);
            sum += k;
        }
        sum = sum % table_size;
        return sum;
    }
    
    void Word_Search(string value){
        int index = calculate_mod(value);
        if(table[index] == nullptr){
            cout<<"String Not found"<<endl;
            return;
        }
        Node* temp = table[index];
        while(temp != nullptr)
        {
        if(temp->data == value){
            cout<<"String "<<value<<" found"<<" at Index "<<index<<endl;
            return;
        }
        temp = temp->next;
        }
        cout<<"String Not found"<<endl;
    }


    void Print_Dictionary(){
        for (int i = 0; i < table_size; i++)
        {
            Node * temp = table[i];
            while(temp != nullptr){
                cout<<"Index: "<<i<<"\t Value: "<<temp->data<<".\n";
                temp = temp->next;
            }
        }
    }
    bool delete_Record(string value){
        int index = calculate_mod(value);
        
        Node*temp = table[index];
        Node * prev = nullptr;

        while(temp != nullptr){
            if (temp->data == value)
            {
                if(prev == nullptr){
                    table[index] = temp ->next;

                }
                else{
                    prev->next = temp->next;
                }
                 delete temp;
                 cout<<"Value "<<value<<" deleted Successfully"<<endl;
                 return true;
                }
            prev = temp;
            temp = temp->next;
        }
        cout << "key " << value << " not found!" << endl;
        return false;  
    }

};
int main() {
    HashTable myhash;

    myhash.Add_Record("AB");
    myhash.Add_Record("FASTNU");
    myhash.Add_Record("CD");
    myhash.Add_Record("CS");
    myhash.Add_Record("EF");

    myhash.Word_Search("AB");

    myhash.delete_Record("EF");
    myhash.Print_Dictionary();

    return 0;
}
