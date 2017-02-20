#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
        std::queue<TreeNode*> q;
        std::vector<int> ans;
        TreeNode *ite = root;
        if (root != NULL) {
            while (ite->left != NULL) {
                s.push(ite);
                q.push(ite->right);

            }
        }
    }
};