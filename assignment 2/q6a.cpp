#include <iostream>
using namespace std;
int main() {
    int arr1[5][3] = { 
        {4, 4, 6},
        {0, 0, 13},
        {0, 1, 17},
        {1, 3, 78},
        {2, 0, 90}
    };
    int a = 4;
    int trans1[100][3]; 
    int k1 = 0;
    for(int i = 1; i < a + 1; i++) { 
        int row = arr1[i][0];
        int col = arr1[i][1];
        int val = arr1[i][2];
        trans1[k1][0] = col; 
        trans1[k1][1] = row; 
        trans1[k1][2] = val; 
        k1++;
    }
    cout << "\nTranspose of first matrix (arr1):" << endl;
    for(int i = 0; i < k1; i++) {
        cout << trans1[i][0] << " " << trans1[i][1] << " " << trans1[i][2] << endl;
    }
    return 0;
}
