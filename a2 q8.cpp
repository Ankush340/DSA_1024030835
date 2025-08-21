#include <iostream>
using namespace std;
int main() {
    int arr[] = {1,1,2,3,3,3,4,6,7,7,5,3,2,1,7};
    int a = sizeof(arr) / sizeof(arr[0]); // correct length (15)
    int i, j, k;

    for (i = 0; i < a; i++) {
        for (j = i + 1; j < a; j++) {
            if (arr[i] == arr[j]) {
                // shift left
                for (k = j; k < a - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                a--;
                j--;
            }
        }
    }

    cout << "Distinct elements: " << a << endl;

    cout << "Array after removing duplicates: ";
    for (i = 0; i < a; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

