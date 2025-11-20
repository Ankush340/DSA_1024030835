#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insertNode(Node* root, int value) {
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insertNode(root->left, value);
    else if(value > root->data)
        root->right = insertNode(root->right, value);
    else
        cout << "Duplicate value not allowed!\n";
    return root;
}
void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
int main() {
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 30);
    cout << "BST Inorder: ";
    inorder(root);
    return 0;
}
