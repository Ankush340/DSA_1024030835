#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 100;
char stack[MAX];
int top = -1;
void push(char c) {
    if (top < MAX - 1)
        stack[++top] = c;
}
char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}
int main() {
    char str[MAX];
    cout << "Enter a string: ";
    cin >> str;
    int len = strlen(str);
    for (int i = 0; i < len; i++)
        push(str[i]);
    cout << "Reversed string: ";
    for (int i = 0; i < len; i++)
        cout << pop();
    cout << endl;
    return 0;
}

