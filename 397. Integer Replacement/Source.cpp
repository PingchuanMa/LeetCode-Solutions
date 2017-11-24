#include <iostream>
#include <limits>
#define lowbit(x) (-(x) & (x))
class Solution {
public:
    int integerReplacement(int n) {
        int cnt = 0;
        if (n == INT_MAX) {
            return 32;
        }
        while (n != 1) {
            if (n == 3) { return cnt + 2; }
            if (n & 1) {
                // odd
                if (lowbit(n + 1) > lowbit(n - 1)) { ++n; }
                else { --n; }
            }
            else { n >>= 1; }
            ++cnt;
        }
        return cnt;
    }
};