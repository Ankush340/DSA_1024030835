#include <iostream>
using namespace std;
int main() {
    int arr1[5][3] = { 
        {0, 0, 4},
        {1, 1, 13},
        {2, 1, 17},
        {3, 2, 78},
        {3, 0, 90}  
    };
    int arr2[5][3] = {
        {0, 0, 2},
        {1, 1, 5},
        {2, 1, 8},
        {2, 2, 3},
        {2, 3, 6}
    };

    int add[4][4] = {0}; 
    int size1 = 5; 
    int size2 = 5; 
    for (int i = 0; i < size1; i++) {
        int row = arr1[i][0];
        int col = arr1[i][1];
        int val = arr1[i][2];
        add[row][col] += val;
    }
    for (int i = 0; i < size2; i++) {
        int row = arr2[i][0];
        int col = arr2[i][1];
        int val = arr2[i][2];
        add[row][col] += val;
    }
    cout << "Resulting 4x4 Matrix after Addition:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << add[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
