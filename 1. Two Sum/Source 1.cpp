#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> outcome;
        for (int i = 0; i < nums.size() - 1; ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    outcome.push_back(i);
                    outcome.push_back(j);
                    break;
                }
            }
        }
        return outcome;
    }
};
int main()
{
    Solution solution;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<int> outcome = solution.twoSum(nums, 5);
    cout << outcome[0] << outcome[1];
}
