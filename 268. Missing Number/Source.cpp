#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = (nums.size() + 1) * nums.size() / 2;
        for (auto i = 0; i < nums.size(); ++i) { sum -= nums[i]; }
        return sum;
    }
};

int main() {
    vector<int> nums = { 0, 1, 3 };
    Solution s;
    cout << s.missingNumber(nums) << endl;
    return 0;
}