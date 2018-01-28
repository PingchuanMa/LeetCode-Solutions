#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// sort it every single time.
class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (--i >= 0) {
            if (nums[i] < nums[i + 1]) {
                int j = nums.size();
                while (nums[--j] <= nums[i]);
                swap(nums[i], nums[j]);
                sort(nums.begin() + i + 1, nums.end());
                break;
            }
        }
        if (i < 0) {
            sort(nums.begin(), nums.end());
        }
    }
};
