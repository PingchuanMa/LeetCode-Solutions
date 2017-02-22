#include <vector>
class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> ans;
        if (rowIndex == 0) { return ans; }
        long upper = 1;
        long lowerL = 1;
        for (int i = 1; i < rowIndex; upper *= ++i);
        long lowerR = upper;
        for (int i = 1; i < rowIndex / 2; ++i) {

        }
    }
};