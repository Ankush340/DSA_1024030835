#include <iostream>
using namespace std;
class PriorityQueue {
private:
    int heap[100];
    int size;
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                int temp = heap[parent];
                heap[parent] = heap[index];
                heap[index] = temp;
                index = parent;
            }
            else break;
        }
    }
    void heapifyDown(int index) {
        int left, right, largest;
        while (true) {
            left = 2 * index + 1;
            right = 2 * index + 2;
            largest = index;

            if (left < size && heap[left] > heap[largest])
                largest = left;

            if (right < size && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            }
            else break;
        }
    }
public:
    PriorityQueue() {
        size = 0;
    }
    void insert(int value) {
        heap[size] = value;
        heapifyUp(size);
        size++;
        cout << "Inserted: " << value << endl;
    }
    void remove() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        cout << "Removed: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }
    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty!" << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};
int main() {
    PriorityQueue pq;
    int choice, value;
    while (true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert (Enqueue)\n";
        cout << "2. Remove Max Priority (Dequeue)\n";
        cout << "3. Display Priority Queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.remove();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}

