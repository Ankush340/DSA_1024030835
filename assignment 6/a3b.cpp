#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
	Node(int value){
		data=value;
		next = NULL;
	}
};
class CircularLinkedList{
		Node* head;
	public:
		CircularLinkedList(){
			head=NULL;
		}
    void insert(int value){
    	Node* newNode = new Node(value);
    	if(head==NULL){
    		head=newNode;
    		head->next=head;
    		return;
		}
		Node* temp=head;
		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->next=head;
	}
	int countsize(){
		if(head==NULL){
			return 0;
		}
		int count=0;
		Node* temp=head;
		do{
			count++;
			temp=temp->next;
		}while(temp!=head);
		return count;
	}
};
int main()
{
	CircularLinkedList list;
	list.insert(30);
	list.insert(10);
	list.insert(20);
	list.insert(100);
	cout<<list.countsize()<<endl;
}

