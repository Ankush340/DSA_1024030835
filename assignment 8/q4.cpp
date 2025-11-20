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
Node* createTree() {
    int value;
    cout << "Enter value (-1 for no node): ";
    cin >> value;
    if (value == -1)
        return NULL;
    Node* root = createNode(value);
    cout << "Enter left child of " << value << endl;
    root->left = createTree();
    cout << "Enter right child of " << value << endl;
    root->right = createTree();
    return root;
}
void inorder(Node* root, int arr[], int &index) {
    if (root == NULL)
        return;
    inorder(root->left, arr, index);
    arr[index++] = root->data;
    inorder(root->right, arr, index);
}
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1])
            return false;
    }
    return true;
}
int main() {
    cout << "Create Binary Tree:\n";
    Node* root = createTree();
    int arr[100];
    int index = 0;
    inorder(root, arr, index);
    if (isSorted(arr, index))
        cout << "\nThe Binary Tree is a BST.\n";
    else
        cout << "\nThe Binary Tree is NOT a BST.\n";
    return 0;
}

