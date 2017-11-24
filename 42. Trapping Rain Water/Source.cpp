#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        if (!height.size()) {
            return 0;
        }
        int highest = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (height[i] > highest) {
                highest = height[i];
            }
        }
        int sum = 0;
        for (int flag = 0; flag < height.size(); ++flag) {
            sum += highest - height[flag];
        }
        for (int flag = 0; flag <= highest; ++flag) {
            for (int left = 0; height[left] < flag && left < height.size(); ++left) {
                --sum;
            }
            for (int right = height.size() - 1; height[right] < flag && right >= 0; --right) {
                --sum;
            }
        }
        return sum;
    }
};