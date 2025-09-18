#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
};
Node *head = nullptr;
void insert_begin(int val) {
    Node *n = new Node{val, head};
    head = n;
}
void insert_end(int val) {
    Node *n = new Node{val, nullptr};
    if (head == nullptr) head = n;
    else {
        Node *t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}
void insert_before_after(int key, int val, bool before) {
    if (head == nullptr) { cout << "List empty\n"; return; }
    Node *n = new Node{val, nullptr};
    if (before) {
        if (head->data == key) { n->next = head; head = n; return; }
        Node *t = head;
        while (t->next && t->next->data != key) t = t->next;
        if (t->next == nullptr) { cout << "Key not found\n"; delete n; return; }
        n->next = t->next; t->next = n;
    } else {     
        Node *t = head;
        while (t && t->data != key) t = t->next;
        if (t == nullptr) { cout << "Key not found\n"; delete n; return; }
        n->next = t->next; t->next = n;
    }
}
void delete_begin() {
    if (head == nullptr) { cout << "Empty list\n"; return; }
    Node *t = head; head = head->next; delete t;
}
void delete_end() {
    if (head == nullptr) { cout << "Empty list\n"; return; }
    if (head->next == nullptr) { delete head; head = nullptr; return; }
    Node *t = head;
    while (t->next->next) t = t->next;
    delete t->next; t->next = nullptr;
}
void delete_value(int key) {
   if (head == nullptr) { cout << "Empty list\n"; return; }
    if (head->data == key) { Node *t = head; head = head->next; delete t; return; }
    Node *t = head;
    while (t->next && t->next->data != key) t = t->next;
    if (t->next == nullptr) { cout << "Not found\n"; return; }
    Node *d = t->next; t->next = d->next; delete d;
}
void search(int key) {
    int pos = 1; Node *t = head;
    while (t) {
        if (t->data == key) { cout << key << " found at position " << pos << "\n"; return; }
        t = t->next; pos++;
    }
    cout << "Not found\n";
}
void display() {
    if (head == nullptr) { cout << "Empty list\n"; return; }
    Node *t = head;
    while (t) { cout << t->data << " "; t = t->next; }
    cout << "\n";
}
int main() {
    int ch, val, key, opt;
    while (1) {
        cout << "\n1.Insert Begin 2.Insert End 3.Insert Before/After";
        cout << "\n4.Delete Begin 5.Delete End 6.Delete Value";
        cout << "\n7.Search 8.Display 9.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Value: "; cin >> val; insert_begin(val); break;
            case 2: cout << "Value: "; cin >> val; insert_end(val); break;
            case 3: cout << "Key: "; cin >> key;
                    cout << "Value: "; cin >> val;
                    cout << "1.Before 2.After: "; cin >> opt;
                    insert_before_after(key, val, opt == 1); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: cout << "Value: "; cin >> key; delete_value(key); break;
            case 7: cout << "Value: "; cin >> key; search(key); break;
            case 8: display(); break;
            case 9: return 0;
            default: cout << "Invalid\n";
        }
    }
}

