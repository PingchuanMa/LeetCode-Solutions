#include <vector>
#include <iostream>
class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::vector<int>::iterator iter = nums.begin();
        int cnt = 1;
        int ans = *iter;
        ++iter;
        while (iter != nums.end()) {
            if (*iter == ans) { ++cnt; }
            else {
                --cnt;
                if (cnt == 0) {
                    ans = *iter;
                    cnt = 1;
                }
            }
            ++iter;
        }
        return ans;
    }
};
int main() {
    std::vector<int> test = { 3, 2, 3 };
    Solution solution;
    std::cout << solution.majorityElement(test) << std::endl;
    return 0;
}