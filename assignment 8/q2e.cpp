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
Node* inorderPredecessor(Node* root, int key) {
    Node* pred = NULL;
    while(root != NULL) {
        if(key > root->data) {
            pred = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
    return pred;
}
int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
        root = insertNode(root, arr[i]);
    int key = 70;
    Node* result = inorderPredecessor(root, key);
    if(result)
        cout << "Predecessor of " << key << " = " << result->data;
    else
        cout << "No Predecessor";
    return 0;
}

