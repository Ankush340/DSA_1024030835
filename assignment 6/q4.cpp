#include <iostream>
using namespace std;
class Node {
public:
    char data;
    Node* next;
    Node* prev;
    Node(char ch) {
        data = ch;
        next = prev = NULL;
    }
};
class DoublyList {
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = tail = NULL;
    }
    void insert(char ch) {
        Node* newNode = new Node(ch);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    bool isPalindrome() {
        if (head == NULL) return true;
        Node* left = head;
        Node* right = tail;
        while (left != right && right->next != left) {
            if (left->data != right->data)
                return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    DoublyList dl;
    int n;
    char ch;
    cout << "Enter number of characters: ";
    cin >> n;
    cout << "Enter characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        dl.insert(ch);
    }
    cout << "List: ";
    dl.display();
    if (dl.isPalindrome())
        cout << "It is a palindrome.\n";
    else
        cout << "It is not a palindrome.\n";

    return 0;
}

