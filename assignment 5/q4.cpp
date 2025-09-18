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
void reverse_list() {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
void display() {
    Node* t = head;
    while (t) {
        cout << t->data << "->";
        t = t->next;
    }
    cout << "NULL" << endl;
}
int main() {
    insert_end(1);
    insert_end(2);
    insert_end(3);
    insert_end(4);
    cout << "Original List: ";
    display();
    reverse_list();
    cout << "Reversed List: ";
    display();
    return 0;
}
