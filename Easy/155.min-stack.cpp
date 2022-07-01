/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

#include <iostream>
#include <stack>
#include <cassert>
using namespace std;

// @lc code=start
class MinStack {
    stack<int> normalSt;
    stack<int> minSt;
public:
    
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        normalSt.push(x);
        if (minSt.empty() == true)
            minSt.push(x);
        else
            if (x <= minSt.top())
                minSt.push(x);
    }
    
    void pop() {
        if (normalSt.empty() == true || minSt.empty() == true)
            cout << "Empty Stack";
        if (normalSt.top() == minSt.top())
            minSt.pop();
        normalSt.pop();
    }
    
    int top() {
        if (normalSt.empty() == true)
            return INT_MIN;
        return normalSt.top();
    }
    
    int getMin() {
        if (minSt.empty() == true)
            return INT_MIN;
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

int main() {
    MinStack minStack = MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(-3 == minStack.getMin());//   --> Returns -3.
    minStack.pop();
    assert(0 == minStack.top());//      --> Returns 0.
    assert(-2 == minStack.getMin());//   --> Returns -2.
    return 0;
}