#include <iostream>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    TreeNode *root = nullptr;
    stack<TreeNode *> *s = nullptr;

  public:
    BSTIterator(TreeNode *root) : root(root), s(new stack<TreeNode *>()) {
        if (root) {
            s->push(root);
            while (s->top()->left) {
                s->push(s->top()->left);
            }
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !s->empty(); }

    /** @return the next smallest number */
    int next() {
        int result = s->top()->val;
        TreeNode *t = s->top();
        s->pop();
        if (t->right) {
            s->push(t->right);
            while (s->top()->left) {
                s->push(s->top()->left);
            }
        }
        return result;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
