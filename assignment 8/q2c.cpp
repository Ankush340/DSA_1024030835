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
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) 
	root->left = insert(root->left, value);
    else 
	root->right = insert(root->right, value);
    return root;
}
int maxElement(Node* root) {
    if(root == NULL) return -1;
    while(root->left != NULL)
        root = root->left;
    return root->data;
}
int main() {
    Node* root = NULL;
    int arr[] = {10, 5, 20, 15, 30};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i = 0; i < n; i++)
    root = insert(root, arr[i]);
    cout << "Maximum Element = " << maxElement(root);
    return 0;
}
