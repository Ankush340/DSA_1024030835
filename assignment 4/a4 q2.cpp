#include <iostream>
using namespace std;
#define MAX 5
class CircularQueue {
    int arr[MAX];
    int front, rear;
public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return (front == -1);
    }
    bool isFull() {
        return ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL!\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = x;
        cout << x << " inserted.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return;
        }
        cout << arr[front] << " removed.\n";
        if (front == rear) {
            front = rear = -1; // queue becomes empty
        } else {
            front = (front + 1) % MAX;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main() {
    CircularQueue q;
    int choice, value;
         cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n";
        cout << "5. Check Empty\n6. Check Full\n7. Exit\n";
    do {
        cout << "Enter choice: ";
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

