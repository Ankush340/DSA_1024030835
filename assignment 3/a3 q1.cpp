#include <iostream>
using namespace std;
const int MAX = 100;
int stack[MAX], top = -1;
void push(int value) {
    if (top == MAX - 1)
        cout << "Stack Overflow\n";
    else
        stack[++top] = value;
}
void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else
        cout << stack[top--] << " popped\n";
}
void peek() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Top element: " << stack[top] << endl;
}
void display() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else {
        cout << "Stack: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}
void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty\n";
    else
        cout << "Stack is Not Empty\n";
}
void isFull() {
    if (top == MAX - 1)
        cout << "Stack is Full\n";
    else
        cout << "Stack is Not Full\n";
}
int main() {
    int choice, value;
    do {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  5.isEmpty  6.isFull  7.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1: cin >> value; push(value); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: isEmpty(); break;
            case 6: isFull(); break;
            case 7: cout << "Exit\n"; break;
            default: cout << "Invalid Choice\n";
        }
    } while (choice != 7);
    return 0;
}

