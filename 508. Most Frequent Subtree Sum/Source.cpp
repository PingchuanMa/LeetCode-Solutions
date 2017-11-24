#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> frequency;
        vector<int> ans;
        int max_frequency = INT_MIN;
        sum_tree(root, frequency);
        for (auto it = frequency.begin(); it != frequency.end(); ++it) {
            if (it->second > max_frequency) {
                ans.clear();
                max_frequency = it->second;
                ans.push_back(it->first);
            }
            else if (it->second == max_frequency) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }

    int sum_tree(TreeNode* theNode, unordered_map<int, int>& frequency) {
        if (theNode == nullptr) {
            return 0;
        }
        int value = sum_tree(theNode->left, frequency) + sum_tree(theNode->right, frequency);
        if (frequency.find(value) == frequency.end()) {
            frequency[value] = 1;
        }
        else {
            ++frequency[value];
        }
        return value;
    }
};