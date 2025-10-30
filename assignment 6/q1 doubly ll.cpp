#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int num) {
        data = num;
        next = NULL;
        prev = NULL;
    }
};
class DoublyLinkedList {
public:
    Node* head;
    DoublyLinkedList() {
        head = NULL;
    }
    void insertAtBeginning(int num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtEnd(int num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next)
            current = current->next;
        current->next = newNode;
        newNode->prev = current;
    }
    void insertAfter(int value, int num) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                Node* newNode = new Node(num);
                newNode->next = temp->next;
                newNode->prev = temp;
                if (temp->next)
                    temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        }
        cout << "Node " << value << " not found!\n";
    }
    void deleteNode(int value) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }

        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;

        if (!temp) {
            cout << "Node not found!\n";
            return;
        }

        if (temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next)
            temp->next->prev = temp->prev;

        delete temp;
        cout << "Node deleted!\n";
    }
    bool search(int value) {
        Node* current = head;
        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }
    void display() {
        Node* temp = head;
        cout << "List: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    DoublyLinkedList dll;
    int choice, val, key;

    while (true) {
        cout << "\n--- DOUBLY LINKED LIST MENU ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Delete a node\n";
        cout << "5. Search a node\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtBeginning(val);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> val;
            dll.insertAtEnd(val);
            break;
        case 3:
            cout << "Enter key (after which to insert): ";
            cin >> key;
            cout << "Enter value: ";
            cin >> val;
            dll.insertAfter(key, val);
            break;
        case 4:
            cout << "Enter value to delete: ";
            cin >> key;
            dll.deleteNode(key);
            break;
        case 5:
            cout << "Enter value to search: ";
            cin >> key;
            if (dll.search(key))
                cout << "Node found!\n";
            else
                cout << "Node not found!\n";
            break;
        case 6:
            dll.display();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

