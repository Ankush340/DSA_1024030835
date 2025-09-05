#include <iostream>
using namespace std;
#define MAX 100
class Queue {
    int arr[MAX];
    int front, rear, size;
public:
    Queue() {
        front = 0;
        rear = -1;
        size = 0;
    }
    bool isEmpty() {
        return (size == 0);
    }
    bool isFull() {
        return (size == MAX);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is FULL!\n";
            return;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = x;
        size++;
    }
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is EMPTY!\n";
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % MAX;
        size--;
        return x;
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    int getSize() {
        return size;
    }
};
void interleaveQueue(Queue &q) {
    int n = q.getSize();
    int half = n / 2;
    Queue firstHalf;
    for (int i = 0; i < half; i++) {
        firstHalf.enqueue(q.dequeue());
    }
    while (!firstHalf.isEmpty()) {
        q.enqueue(firstHalf.dequeue());
        q.enqueue(q.dequeue());
    }
}
int main() {
    Queue q;
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }
    interleaveQueue(q);
    cout << "Interleaved Queue: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}

