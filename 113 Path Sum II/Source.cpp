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
		if (node == NULL) {
			return;
		}
		path.push_back(node->val);
		sum += node->val;
		if (node->left == NULL && node->right == NULL) {
            if (sum == target) {
                ans.push_back(*(new std::vector<int>(path)));
            }
			path.pop_back();
			return;
        }
        match(node->left, sum, ans, path, target);
        match(node->right, sum, ans, path, target);
        path.pop_back();
    }
};