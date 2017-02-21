#include <iostream>
#include <vector>
#include <stack>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> s;
        std::vector<int> ans;
        TreeNode *ite = root;
        while (ite != NULL) {
            s.push(ite);
            ite = ite->left;
        }
        while (s.empty() != true) {
            ite = s.top();
            ans.push_back(ite->val);
            s.pop();
            ite = ite->right;
            while (ite != NULL) {
                s.push(ite);
                ite = ite->left;
            }
        }
        return ans;
    }
};