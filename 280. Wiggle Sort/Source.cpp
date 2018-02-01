#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        if (nums.size() == 0) {
            return;
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if ((i % 2 == 0) == (nums[i] > nums[i + 1])) {
                swap<int>(nums[i], nums[i + 1]);
            }
        }
    }
};
