#include <iostream>
using namespace std;
int main() {
    int A[5][3] = {
        {3, 3, 4},
        {0, 0, 2},
        {0, 2, 3},
        {1, 1, 4},
        {2, 0, 5}
    };
    int B[5][3] = {
        {3, 3, 4},   
        {0, 1, 6},
        {1, 2, 7},
        {2, 0, 8},
        {2, 2, 9}
    };
    int rowsA = A[0][0], colsA = A[0][1];
    int rowsB = B[0][0], colsB = B[0][1];
    if (colsA != rowsB) {
        cout << "Multiplication not possible!" << endl;
        return 0;
    }
    int result[10][10] = {0};
    for (int i = 1; i <= A[0][2]; i++) {
        for (int j = 1; j <= B[0][2]; j++) {
            if (A[i][1] == B[j][0]) {
                int r = A[i][0];
                int c = B[j][1];
                result[r][c] += A[i][2] * B[j][2];
            }
        }
    }
    cout << "Result of multiplication (normal matrix):\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

