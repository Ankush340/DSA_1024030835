#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    int isEmpty() { return (top == -1); }
    int isFull() { return (top == MAX - 1); }
    void push(char x) {
        if (isFull())
            cout << "OVERFLOW\n";
        else
            arr[++top] = x;
    }
    void pop() {
        if (isEmpty())
            cout << "UNDERFLOW\n";
        else
            top--;
    }
    char peek() {
        if (isEmpty())
            return '\0';
        else
            return arr[top];
    }
    void display() {
        for (int i = top; i >= 0; i--)
            cout << arr[i];
        cout << endl;
    }
};
int main() {
    Stack s;
    string str;
    cout << "Enter expression: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s.push(str[i]);
        }
        else if (str[i] == '}' || str[i] == ']' || str[i] == ')') {
            if ((str[i] == ')' && s.peek() == '(') ||
                (str[i] == '}' && s.peek() == '{') ||
                (str[i] == ']' && s.peek() == '[')) {
                s.pop();
            } else {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }
    if (s.isEmpty())
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}

