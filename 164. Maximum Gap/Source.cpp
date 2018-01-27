#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
  public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        int max = nums[0], min = nums[0];
        for (int num : nums) {
            if (num < min) {
                min = num;
            } else if (num > max) {
                max = num;
            }
        }
        if (max == min) {
            return 0;
        }
        int delta = ceil(1.0 * (max - min) / (nums.size() - 1));
        vector<pair<int, int> *> buckets((max - min) / delta + 1, nullptr);
        for (int num : nums) {
            int i = (num - min) / delta;
            if (buckets[i] == nullptr) {
                buckets[i] = new pair<int, int>(num, num);
            } else if (num < buckets[i]->first) {
                buckets[i]->first = num;
            } else if (buckets[i]->second < num) {
                buckets[i]->second = num;
            }
        }
        int gap = 0;
        int i = 0, j = 0;
        while (i < buckets.size() - 1) {
            for (j = i + 1; buckets[j] == nullptr && j < buckets.size(); ++j);
            if (buckets[j]->first - buckets[i]->second > gap) {
                gap = buckets[j]->first - buckets[i]->second;
            }
            i = j;
        }
        return gap;
    }
};

int main() {
    Solution s;
    vector<int> v({1, 1, 1, 2, 1, 1});
    cout << s.maximumGap(v) << endl;
    return 0;
}
