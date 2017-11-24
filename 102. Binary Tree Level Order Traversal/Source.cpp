#include <iostream>
#include <vector>
#include <queue>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        int now = 1;
        int nxt = 0;
        std::vector<std::vector<int>> ans;
        ans.clear();
        std::vector<int> row;
        std::queue<TreeNode *> container;
        if (!root) {
            return ans;
        }
        container.push(root);
        while (now) {
            row.clear();
            while (now--) {
                TreeNode *top = container.front();
                row.push_back(top->val);
                container.pop();
                if (top->left) {
                    container.push(top->left);
                    ++nxt;
                }
                if (top->right) {
                    container.push(top->right);
                    ++nxt;
                }
            }
            ans.push_back(row);
            now = nxt;
            nxt = 0;
        }
        return ans;
    }
};