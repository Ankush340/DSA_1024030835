#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node* left;
		Node* right;
	Node(int val){
		data = val;
		left=right=NULL;
	}
};
void preorder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
void inorder(Node* root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node* root){
	if(root==NULL){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main(){
	Node* root=new Node(10);
	root->left=new Node(2);
	root->left->left=new Node(1);
	root->left->right=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	
	cout<<"preorder ..."<<endl;
	preorder(root);
	cout<<endl;
	cout<<"inorder ..."<<endl;
	inorder(root);
	cout<<endl;
	cout<<"postorder ..."<<endl;
	postorder(root);
}
