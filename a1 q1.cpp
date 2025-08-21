#include <iostream>
using namespace std;
class ArrayOperations {
private:
    int arr[20];
    int size;

public:

    void create() {
        cout << "Enter number of elements: ";
        cin >> size;
        cout << "Enter elements:\n";
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }

    void insert() {
        int pos, element;
        cout << "Enter position : ";
        cin >> pos;
        cout << "Enter element to insert: ";
        cin >> element;

        for (int i = size; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = element;
        size++;
        cout << "Element inserted successfully.\n";
    }

    void deleteElement() {
        int pos;
        cout << "Enter position to delete : ";
        cin >> pos;
        for (int i = pos; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        cout << "Element deleted successfully.\n";
    }

    void linearSearch() {
        int key, found = 0;
        cout << "Enter element to search: ";
        cin >> key;

        for (int i = 0; i < size; i++) {
            if (arr[i] == key) {
                cout << "Element found at position: " << i << "\n";
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "Element not found.\n";
        }
    }
};

int main() {
    ArrayOperations obj;
    obj.create();
    obj.display();
    obj.insert();
    obj.display();
    obj.deleteElement();
    obj.display();
    obj.linearSearch();
    return 0;
}
