#include <iostream>
using namespace std;
int main() {
    const int max = 4; 
    int i, j, k = 0;
    int a[10]; 
    int size = max * (max + 1) / 2;
    cout << "Enter elements row major: " << endl;
    for (i = 0; i < size; i++) {
        cin >> a[i];
    }
    cout << "The matrix is : " << endl;
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            if (j >= i) {
                cout << a[k++] << " ";
            } else {
                cout << a[(j*(2*max-j-1))/2+i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
