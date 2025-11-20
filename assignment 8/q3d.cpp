#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int v){
    Node* n = new Node();
    n->data = v;
    n->left = n->right = NULL;
    return n;
}
Node* insertNode(Node* root, int v){
    if(root == NULL) return createNode(v);
    if(v < root->data)
        root->left = insertNode(root->left, v);
    else
        root->right = insertNode(root->right, v);
    return root;
}
int minDepth(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL) return 1 + minDepth(root->right);
    if(root->right == NULL) return 1 + minDepth(root->left);
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return 1 + (left < right ? left : right);
}
int main(){
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 70);
    cout << "Minimum Depth: " << minDepth(root);
    return 0;
}

