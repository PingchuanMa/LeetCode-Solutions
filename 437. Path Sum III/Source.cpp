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
        if (!root) {
            return 0;
        }
        return pathSumHelper(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int pathSumHelper(TreeNode *root, int res) {
        if (!root) {
            return 0;
        }
        int ret = pathSumHelper(root->left, res - root->val) +
                  pathSumHelper(root->right, res - root->val);
        if (res == root->val) {
            return ret + 1;
        }
        return ret;
    }
};
