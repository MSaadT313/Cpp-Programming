#include <iostream>
using namespace std;

struct Node {
    int price;
    Node* left;
    Node* right;
};

// BST search for a value
bool search(Node* root, int key, Node* skip) {
    if (!root) return false;
    if (root != skip && root->price == key) return true;
    if (key < root->price) return search(root->left, key, skip);
    else return search(root->right, key, skip);
}

// Inorder traversal: check pairs
int countPairs(Node* root, Node* node, int target) {
    if (!node) return 0;
    int count = 0;

    // Check left subtree
    count += countPairs(root, node->left, target);

    // Check current node
    int complement = target - node->price;
    if (complement > node->price) { // ensure distinct and count once
        if (search(root, complement, node)) {
            count++;
        }
    }

    // Check right subtree
    count += countPairs(root, node->right, target);

    return count;
}

int main() {
    // Manually create AVL tree (example)
    Node* root = new Node{6, nullptr, nullptr};
    root->left = new Node{3, nullptr, nullptr};
    root->right = new Node{8, nullptr, nullptr};
    root->left->left = new Node{2, nullptr, nullptr};
    root->left->right = new Node{4, nullptr, nullptr};

    int result = countPairs(root, root, root->price);

    cout << "Number of valid pairs = " << result << endl;

    return 0;
}
