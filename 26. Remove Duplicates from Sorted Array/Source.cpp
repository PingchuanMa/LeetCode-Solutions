#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int ans = 0;
        std::vector<int>::size_type i = 0, j = 0;
        while (++j < nums.size()) {
            if (nums[j] != nums[i]) {
                i = j;
                nums[++ans] = nums[i];
            }
        }
        return ++ans;
    }
};