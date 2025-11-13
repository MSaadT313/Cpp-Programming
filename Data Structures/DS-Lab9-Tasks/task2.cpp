#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Node{
public:
    string name;
    int roll;
    int height = 1;
    Node* left;
    Node* right;
    Node(string n, int s){
        name = n;
        roll = s;
        left = NULL;
        right = NULL;
    }
};

int height(Node* node){
    if(node == NULL){
        return 0;
    }
    return node->height;
}

void update_height(Node* node){
    if(node == NULL){
        return;
    }
    node->height = 1 + max(height(node->left), height(node->right));
}

int getbalance(Node* node){
    if(node == NULL){
        return 0;
    }
    return (height(node->left) - height(node->right));
}

Node* rotate_right(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    update_height(y);
    update_height(x);
    return x;
}

Node* rotate_left(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    update_height(x);
    update_height(y);
    return y;
}

Node* balanceNode(Node* node){
    int balance = getbalance(node);
    if(balance > 1 && getbalance(node->left) >= 0){
        return rotate_right(node);
    }
    if(balance < -1 && getbalance(node->right) <= 0){
        return rotate_left(node);
    }
    if(balance > 1 && getbalance(node->left) < 0){
        node->left = rotate_left(node->left);
        return rotate_right(node);
    }
    if(balance < -1 && getbalance(node->right) > 0){
        node->right = rotate_right(node->right);
        return rotate_left(node);
    }
    return node;
}

Node* insertNode(Node* node, string n, int s){
    if(node == NULL){
        return new Node(n, s);
    }
    if(s < node->roll){
        node->left = insertNode(node->left, n, s);
    }
    else if(s > node->roll){
        node->right = insertNode(node->right, n, s);
    }
    else{
        return node;
    }
    update_height(node);
    return balanceNode(node);
}

void levelorder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* curr = q.front();
            q.pop();
            cout << " " << curr->name << "=" << curr->roll << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main(){
    Node* root = NULL;
    root = insertNode(root, "Student 1", 10);
    root = insertNode(root, "Student 2", 20);
    root = insertNode(root, "Student 3", 30);
    root = insertNode(root, "Student 4", 40);
    root = insertNode(root, "Student 5", 50);

    int h = height(root);
    cout << "<---Height before insertion--->" << endl;
    cout << h << endl;
    cout << "<---Tree Before Insertion--->" << endl;
    levelorder(root);
    cout << endl;

    root = insertNode(root, "New Student", 15);

    int nh = height(root);
    cout << "<---Height After insertion--->" << endl;
    cout << nh << endl;
    cout << "<---Tree After Insertion--->" << endl;
    levelorder(root);
    cout << endl;

    return 0;
}
