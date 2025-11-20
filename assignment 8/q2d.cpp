#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node *left, *right;
    Node(int value) {
        data = value;
        left = right = NULL;
    }
};
Node* insertNode(Node* root, int value) {
    if(root == NULL)
        return new Node(value);
    if(value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);
    return root;
}
Node* inorderSuccessor(Node* root, int key) {
    Node* succ = NULL;
    while(root != NULL) {
        if(key < root->data) {
            succ = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return succ;
}
int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        root = insertNode(root, arr[i]);
    int key = 40;
    Node* result = inorderSuccessor(root, key);
    if(result)
        cout << "Successor of " << key << " = " << result->data;
    else
        cout << "No Successor";
    return 0;
}

