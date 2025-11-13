#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height = 1;
    Node(int val){
        data = val;
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

Node* rotate_left(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    update_height(x);
    update_height(y);
    return y;
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

Node* insertNode(Node* node, int data){
    if(node == NULL){
        return new Node(data);
    }
    if(data < node->data){
        node->left = insertNode(node->left, data);
    }
    else if(data > node->data){
        node->right = insertNode(node->right, data);
    }
    else {
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
            cout << " " << curr->data << " ";
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main(){
    Node* rootA = NULL;
    Node* rootB = NULL;

    rootA = insertNode(rootA, 10);
    rootA = insertNode(rootA, 6);
    rootA = insertNode(rootA, 4);
    rootA = insertNode(rootA, 8);
    cout << "<---BFS TRAVERSAL OF AVL TREE (A)--->" << endl;
    levelorder(rootA);
    cout << endl;

    rootB = insertNode(rootB, 10);
    rootB = insertNode(rootB, 16);
    rootB = insertNode(rootB, 12);
    rootB = insertNode(rootB, 18);
    cout << "<---BFS TRAVERSAL OF AVL TREE (B)--->" << endl;
    levelorder(rootB);
    cout << endl;

    return 0;
}
