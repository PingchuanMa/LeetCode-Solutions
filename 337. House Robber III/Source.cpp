#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int rob(TreeNode* root) {
        return _rob(root, true);
    }
    int _rob(TreeNode *node, bool addable) {
        if (node == nullptr) {
            return 0;
        }
        if (addable) {
            int added = _rob(node->left, false) + _rob(node->right, false) + node->val;
            int not_added = _rob(node->left, true) + _rob(node->right, true);
            return max<int>(added, not_added);
        }
        return _rob(node->left, true) + _rob(node->right, true);
    }
};
