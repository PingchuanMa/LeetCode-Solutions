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
    int longestUnivaluePath(TreeNode* root) {
        int ret = 0;
        _longestUnivaluePath(root, ret);
        return ret;
    }
    int _longestUnivaluePath(TreeNode *node, int &ret) {
        if (!node) {
            return 0;
        }
        int left_max = _longestUnivaluePath(node->left, ret);
        int right_max = _longestUnivaluePath(node->right, ret);
        int left = 0, right = 0;
        if (node->left && node->left->val == node->val) {
            left = 1 + left_max;
        }
        if (node->right && node->right->val == node->val) {
            right = 1 + right_max;
        }
        if (ret < left + right) {
            ret = left + right;
        }
        return max<int>(left, right);
    }
};
