#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> ans(rowIndex + 1);
        long upper = rowIndex;
        long lower = 1;
        long temp = 1;
        for (int i = 0; i <= rowIndex / 2; ++i) {
            ans[i] = ans[rowIndex - i] = temp;
            temp = temp * upper-- / lower++;
        }
        return ans;
    }
};