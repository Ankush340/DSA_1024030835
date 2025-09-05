#include <iostream>
#include <queue>
using namespace std;
class StackTwoQ {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    void pop() {
        if (q1.empty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }
        q1.pop();
    }
    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }
    bool isEmpty() {
        return q1.empty();
    }
};
int main() {
    StackTwoQ st;
    st.push(10);
    st.push(20);
    st.push(30);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}

