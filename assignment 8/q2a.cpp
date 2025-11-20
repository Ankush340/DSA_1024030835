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
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) 
	return root;
    if (key < root->data) 
	return searchRec(root->left, key);
    return searchRec(root->right, key);
}
Node* searchNonRec(Node* root, int key) {
    while (root && root->data != key) {
        if (key < root->data) 
		root = root->left;
        else 
		root = root->right;
    }
    return root;
}
int main() {
    Node* root = NULL;
    int arr[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++){
    root = insert(root, arr[i]);}
    int key = 140;
    if (searchRec(root, key))
        cout << "Found (Recursive)\n";
    else
        cout << "Not Found\n";
        
    if (searchNonRec(root, key))
        cout << "Found (Non-Recursive)\n";
    else
        cout << "Not Found\n";
    return 0;
}

