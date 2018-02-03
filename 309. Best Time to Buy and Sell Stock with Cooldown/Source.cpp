#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();
        if (size <= 1) {
            return 0;
        }
        // recording the last action it took
        vector<int> sell(size + 2, 0), buy(size + 2, INT32_MIN);
        for (int i = 0; i < size; ++i) {
            buy[i + 2] = max<int>(buy[i + 1], sell[i] - prices[i]);
            sell[i + 2] = max<int>(sell[i + 1], buy[i + 1] + prices[i]);
        }
        return sell[size + 1];
    }
};
