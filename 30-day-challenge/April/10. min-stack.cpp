#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> st;
    stack<int> min;

   public:
    /** initialize your data structure here. */
    MinStack() {
        st = stack<int>();
        min = stack<int>();
    }

    void push(int x) {
        st.push(x);
        if (min.empty() || x <= min.top())
            min.push(x);
    }

    void pop() {
        if (!st.empty()) {
            if (st.top() == min.top()) {
                min.pop();
            }
            st.pop();
        } else
            cout << "No element in stack.";
    }

    int top() {
        if (!st.empty())
            return st.top();
        cout << "No element in stack.";
        return -1;
    }

    int getMin() {
        if (!min.empty())
            return min.top();
        cout << "No element in stack.";
        return -1;
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(-3 == minStack.getMin());
    minStack.pop();
    assert(0 == minStack.top());
    assert(-2 == minStack.getMin());
    return 0;
}