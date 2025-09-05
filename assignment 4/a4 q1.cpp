#include <iostream>
using namespace std;
#define MAX 5
class Queue {
    int arr[MAX];
    int front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return (rear == MAX - 1);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        arr[++rear] = x;
        cout << x << " inserted.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << arr[front] << " removed.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
    void peek() {
        if (isEmpty())
            cout << "Queue is EMPTY!\n";
        else
            cout << "Front element = " << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    Queue q;
    int choice, value;
    cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n";
        cout << "5. Check Empty\n6. Check Full\n7. Exit\n";
    do {
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.isEmpty() ? "Queue is EMPTY\n" : "Queue is NOT EMPTY\n");
            break;
        case 6:
            cout << (q.isFull() ? "Queue is FULL\n" : "Queue is NOT FULL\n");
            break;
        case 7:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 7);
    return 0;
}

