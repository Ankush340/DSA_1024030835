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
int count_nodes() {
    int count = 0;
    for (Node* t = head; t; t = t->next) count++;
    return count;
}
void remove_duplicates() {
    for (Node* cur = head; cur; cur = cur->next) {
        Node* prev = cur;
        Node* temp = cur->next;
        while (temp) {
            if (temp->data == cur->data) {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
void display() {
    if (!head) { cout << "Empty list\n"; return; }
    for (Node* t = head; t; t = t->next) cout << t->data << " ";
    cout << "\n";
}
int main() {
    insert_end(10);
    insert_end(20);
    insert_end(30);
    insert_end(20);
    insert_end(10);
    insert_end(40);
    cout << "Original List: "; display();
    cout << "Total nodes = " << count_nodes() << "\n";
    cout << "Removing duplicates...\n";
    remove_duplicates();
    display();
    cout << "Total nodes after removing duplicates = " << count_nodes() << "\n";
    return 0;
}

