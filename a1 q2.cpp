#include <iostream>
using namespace std;

class duplicates {
public: 
    void removeDuplicates(int arr[], int &n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++ ) {
                if (arr[i] == arr[j]) {
                    for (int k = j; k < n - 1; k++) {
                        arr[k] = arr[k + 1];
                    }
                    n--; 
                } 
            }
        }
    }

    void displayArray(int arr[], int n) {
        cout << "Array without duplicates: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main() {
    duplicates d;
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    d.removeDuplicates(arr, n);
    d.displayArray(arr, n);

    return 0;
}

