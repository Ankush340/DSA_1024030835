#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
class CircularList {
    Node* head;
public:
    CircularList() {
        head = NULL;
    }
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    void insertAfter(int key, int val) {
        if (head == NULL) return;
        Node* temp = head;
        do {
            if (temp->data == key) {
                Node* newNode = new Node(val);
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }
    void deleteNode(int key) {
        if (head == NULL) return;
        Node *curr = head, *prev = NULL;
        if (head->data == key) {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            if (head->next == head)
                head = NULL;
            else {
                temp->next = head->next;
                head = head->next;
            }
            delete curr;
            return;
        }
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);
        cout << "Node not found!\n";
    }
    void searchNode(int key) {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }
        Node* temp = head;
        do {
            if (temp->data == key) {
                cout << "Node found!\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Node not found!\n";
    }
    void display() {
        if (head == NULL) {
            cout << "List empty!\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};
int main() {
    CircularList cl;
    int choice, val, key;
    do {
        cout << "\n--- Circular Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert After\n";
        cout << "4. Delete Node\n5. Search Node\n6. Display\n7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: "; cin >> val;
            cl.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: "; cin >> val;
            cl.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key and value: "; cin >> key >> val;
            cl.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter value to delete: "; cin >> val;
            cl.deleteNode(val);
            break;
        case 5:
            cout << "Enter value to search: "; cin >> val;
            cl.searchNode(val);
            break;
        case 6:
            cl.display();
            break;
        }
    } while (choice != 7);
    return 0;
}

