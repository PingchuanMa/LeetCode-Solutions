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
    int pathSum(TreeNode* root, int sum) {
        int total = 0;
        _pathSum(root, 0, sum, total);
        return total;
    }
    void _pathSum(TreeNode *node, int sum, int target, int &total) {
        if (!node) {
            return;
        }
        if (sum + node->val == target) {
            ++total;
        }
        _pathSum(node->left, sum + node->val, target, total);
        _pathSum(node->left, 0, target, total);
        _pathSum(node->right, sum + node->val, target, total);
        _pathSum(node->right, 0, target, total);
    }
};
