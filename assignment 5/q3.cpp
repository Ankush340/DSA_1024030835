#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;
void insert_end(int val) {
    Node* n = new Node;
    n->data = val;
    n->next = nullptr;
    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}
void find_middle() {
    if (!head) { cout << "List empty\n"; return; }
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "Middle element = " << slow->data << endl;
}
void display() {
    Node* t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << endl;
}
int main() {
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    insert_end(5);
    cout << "Linked List: ";
    display();
    find_middle();
    return 0;
}
