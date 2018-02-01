#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n, INT32_MAX);
        for (int i = 1; i <= n; ++i) {
            if ((int)sqrt<int>(i) * (int)sqrt<int>(i) == i) {
                dp[i - 1] = 1;
                continue;
            }
            for (int j = 1; j * j < i; ++j) {
                if (dp[i - j * j - 1] + 1 < dp[i - 1]) {
                    dp[i - 1] = dp[i - j * j - 1] - 1;
                }
            }
        }
        return dp[n - 1];
    }
};
