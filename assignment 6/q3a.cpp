#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node* next;
		Node* prev;
	Node(int value){
		data=value;
		next = NULL;
		prev=NULL;
	}
};
class DoublyLinkedList{
		Node* head;
	public:
		DoublyLinkedList(){
			head=NULL;
		}
    void insert(int value){
    	Node* newNode = new Node(value);
    	if(head==NULL){
    		head=newNode;
    		return;
		}
		Node* temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
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
		}while(temp!=NULL);
		return count;
	}
};
int main()
{
	DoublyLinkedList list;
	list.insert(30);
	list.insert(10);
	list.insert(20);
	list.insert(100);
	cout<<list.countsize()<<endl;
}

