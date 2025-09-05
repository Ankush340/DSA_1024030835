#include <iostream>
#include <string>
using namespace std;
#define MAX 256
#define QMAX 1000
class Queue {
    char arr[QMAX];
    int front, rear, size;
public:
    Queue() { front = 0; rear = -1; size = 0; }
    bool isEmpty() { return (size == 0); }
    void enqueue(char c) {
        if (size == QMAX) return;
        rear = (rear + 1) % QMAX;
        arr[rear] = c;
        size++;
    }
    void dequeue() {
        if (isEmpty()) return;
        front = (front + 1) % QMAX;
        size--;
    }
    char peek() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};
void firstNonRepeating(string str) {
    int freq[MAX] = {0};
    Queue q;
    for (char c : str) {
        freq[(int)c]++;
        q.enqueue(c);
        while (!q.isEmpty() && freq[(int)q.peek()] > 1) {
            q.dequeue();
        }
        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.peek() << " ";
    }
    cout << endl;
}
int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;
    cout << "First non-repeating characters: ";
    firstNonRepeating(input);
    return 0;
}

