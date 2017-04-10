#include <iostream>
#include <vector>
using namespace std;
#define m(x, y) ((x + y) / 2)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        if (nums[0] != 0) { return 0; }
        while (l != r) {
            if (m(l, r) != nums[m(l, r)]) { r = m(l, r); }
            else { l = m(l, r) + 1; }
        }
        return l;
    }
};

int main() {
    vector<int> nums = { 0, 2 };
    Solution s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}