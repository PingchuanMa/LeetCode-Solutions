#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <limits.h>
using namespace std;
class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        vector<int> days(flowers);
        ++k;
        for (int i = 0; i < flowers.size(); ++i) {
            days[flowers[i] - 1] = i;
        }
        int left = 0, right = k, ret = INT_MAX;
        while (right < days.size()) {
            bool finished = true;
            for (int i = left + 1; i < right; ++i) {
                if (days[i] < days[left] || days[i] < days[right]) {
                    left = i;
                    finished = false;
                    break;
                }
            }
            if (finished) {
                ret = min<int>(ret, max<int>(days[left], days[right]) + 1);
                left = right;
            }
            right = left + k;
        }
        return ret == INT_MAX ? -1 : ret;
    }
};
