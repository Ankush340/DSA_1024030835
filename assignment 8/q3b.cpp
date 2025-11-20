#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->left = node->right = NULL;
    return node;
}
Node* insertNode(Node* root, int value) {
    if(root == NULL)
        return createNode(value);
    if(value < root->data)
        root->left = insertNode(root->left, value);
    else if(value > root->data)
        root->right = insertNode(root->right, value);
    return root;
}
Node* findMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}
Node* deleteNode(Node* root, int value) {
    if(root == NULL) 
	    return root;
    if(value < root->data)
        root->left = deleteNode(root->left, value);
    else if(value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
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
    insertNode(root, 40);
    cout << "Before Delete: ";
    inorder(root);
    root = deleteNode(root, 30);
    cout << "\nAfter Delete: ";
    inorder(root);
    return 0;
}
