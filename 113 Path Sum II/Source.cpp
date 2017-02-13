#include <iostream>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    std::vector<std::vector<int> > pathSum(TreeNode *root, int sum) {
        std::vector<std::vector<int> > ans;
        std::vector<int> path;
        match(root, 0, ans, path, sum);
        return ans;
    }
    void match(TreeNode *node, int sum, std::vector<std::vector<int> > &ans, std::vector<int> &path, int target) {
        if (sum > target) {
            return \;
        }
        if (node == NULL) {
            if (sum == target) {
                ans.push_back(*(new std::vector<int>(path)));
                path.pop_back();
                return;
            }
            else {
                return;
            }
        }
        path.push_back(node->val);
        match(node->left, sum + node->val, ans, path, target);
        match(node->right, sum + node->val, ans, path, target);
        path.pop_back();
    }
};