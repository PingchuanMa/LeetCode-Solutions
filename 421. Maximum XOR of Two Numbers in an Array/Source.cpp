#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            unordered_set<int> s;
            for (int n : nums) {
                s.insert(n & mask);
            }
            int tmp = max | (1 << i);
            for (int prefix : s) {
                if (s.find(tmp ^ prefix) != s.end()) {
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};
