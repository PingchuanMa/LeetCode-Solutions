#include <iostream>
#include <vector>
#define middle(x, y) ((x + y) / 2)
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int high = nums.size() - 1;
        int low = 0;
        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.front() < nums[1] && nums.front() < nums.back()) {
            return nums.front();
        }
        if (nums.back() < nums[nums.size() - 2] && nums.back() < nums.front()) {
            return nums.back();
        }
        while (nums[middle(high, low) - 1] < nums[middle(high, low)] || nums[middle(high, low) + 1] < nums[middle(high, low)]) {
            if (nums[middle(high, low)] > nums[low]) {
                low = middle(high, low);
            }
            else {
                high = middle(high, low);
            }
        }
        return nums[middle(high, low)];
    }
};
int main()
{
    Solution solution;
    vector<int> line;
    line.push_back(3);
    line.push_back(1);
    line.push_back(2);
    cout << solution.findMin(line) << endl;
}