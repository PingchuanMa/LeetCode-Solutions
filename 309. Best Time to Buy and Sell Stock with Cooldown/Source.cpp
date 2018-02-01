#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int size = prices.size();
        if (size == 0) {
            return 0;
        }
        vector<int> state(size), profit(size);
        const int BUY = 0, SELL = 1, COOL = 2;
        for (int i = 0; i < size; ++i) {
            
        }
    }
};
