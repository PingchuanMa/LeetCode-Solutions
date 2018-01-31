#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        dataStack = new stack<int>();
        minStack = new stack<int>();
    }

    void push(int x) {
        if (dataStack->empty()) {
            dataStack->push(x);
            minStack->push(x);
        } else {
            dataStack->push(x);
            if (x <= minStack->top()) {
                minStack->push(x);
            }
        }
    }

    void pop() {
        if (dataStack->empty()) {
            return;
        }
        if (dataStack->top() > minStack->top()) {
            dataStack->pop();
        } else {
            dataStack->pop();
            minStack->pop();
        }
    }

    int top() {
        if (dataStack->empty()) {
            return 0;
        }
        return dataStack->top();
    }

    int getMin() {
        if (dataStack->empty()) {
            return 0;
        }
        return minStack->top();
    }
private:
    stack<int> *dataStack, *minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
