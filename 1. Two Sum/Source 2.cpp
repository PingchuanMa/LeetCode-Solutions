#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            num_map[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            const int margin = target - nums[i];
            if (num_map.find(margin) != num_map.end() && i < num_map[margin]) {
                result.push_back(i);
                result.push_back(num_map[margin]);
                break;
            }
        }
        return result;
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