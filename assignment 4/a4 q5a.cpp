#include <iostream>
#include <queue>
using namespace std;
class StackOneQ {
    queue<int> q;
public:
    void push(int x) {
        int size = q.size();
        q.push(x);
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() {
        if (q.empty()) {
            cout << "Stack is EMPTY!\n";
            return;
        }
        q.pop();
    }
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    bool isEmpty() {
        return q.empty();
    }
};
int main() {
    StackOneQ st;
    st.push(100);
    st.push(200);
    st.push(300);
    cout << "Top: " << st.top() << endl;
    st.pop();
    cout << "Top after pop: " << st.top() << endl;
    return 0;
}

