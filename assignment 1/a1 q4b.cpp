#include <iostream>
using namespace std;

class ARRAY {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2;

public:
    void create() {
        cout << "Enter rows and columns for first matrix: ";
        cin >> r1 >> c1;
        cout << "Enter elements of first matrix:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c1; j++) {
                cin >> a[i][j];
            }
        }
        cout << "Enter rows and columns for second matrix: ";
        cin >> r2 >> c2;
        cout << "Enter elements of second matrix:\n";
        for (int i = 0; i < r2; i++) {
            for (int j = 0; j < c2; j++) {
                cin >> b[i][j];
            }
        }
    }
    void multiply() {
        if (c1 != r2) {
            cout << "Matrix multiplication not possible! (c1 must equal r2)" << endl;
            return;
        }
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                c[i][j] = 0;
                for (int k = 0; k < c1; k++) {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
    }
    void display() {
        cout << "Resultant Matrix:\n";
        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                cout << c[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    ARRAY obj;
    obj.create();
    obj.multiply();
    obj.display();
    return 0;
}

