#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // [l,r)
        int l = 0, r = nums.size(), m;
        while (true) {
            if (r - l == 2) {
                if (nums[l] < nums[l + 1]) {
                    return r - 1;
                } else {
                    return l;
                }
            }
            m = (l + r) / 2;
            if (m == 0) {
                return 0;
            }
            if (m == nums.size() - 1) {
                return nums.size() - 1;
            }
            if (nums[m - 1] < nums[m]) {
                if (nums[m] < nums[m + 1]) {
                    l = m + 1;
                } else {
                    return m;
                }
            } else {
                if (nums[m] < nums[m + 1]) {
                    l = m + 1;
                } else {
                    r = m;
                }
            }
        }
        return 0;
    }
};
