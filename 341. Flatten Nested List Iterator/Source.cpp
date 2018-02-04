#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<vector<NestedInteger>> s;
    stack<int> idx;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        if (nestedList.empty()) {
            return;
        }
        s.push(nestedList);
        idx.push(0);
        vector<NestedInteger> &t = nestedList;
        while (!t[0].isInteger()) {
            s.push(t[0].getList());
            idx.push(0);
            t = s.top();
        }
    }

    int next() {
        int ret = s.top()[idx.top()].getInteger();
        vector<NestedInteger> &t = s.top();
        while (++idx.top() >= t.size()) {
            s.pop();
            idx.pop();
            if (s.empty()) {
                return ret;
            }
            t = s.top();
        }
        while (!t[idx.top()].isInteger()) {
            s.push(t[idx.top()].getList());
            idx.push(0);
            t = s.top();
        }
        return ret;
    }

    bool hasNext() {
        return !s.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
