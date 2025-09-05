#include <iostream>
#include <string>
using namespace std;
#define MAX 100
class Stack {
    char arr[MAX];
    int top;
public:
    Stack() { top = -1; }
    bool isEmpty() { 
	return (top == -1); 
	}
    bool isFull() { 
	return (top == MAX - 1); 
	}
    void push(char x) {
        if (!isFull())
            arr[++top] = x;
    }
    char pop() {
        if (!isEmpty())
            return arr[top--];
        return '\0';
    }
    char peek() {
        if (!isEmpty())
            return arr[top];
        return '\0';
    }
};
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";
    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
                postfix += s.pop();
            s.push(c);
        }
    }
    while (!s.isEmpty())
        postfix += s.pop();
    return postfix;
}
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}

