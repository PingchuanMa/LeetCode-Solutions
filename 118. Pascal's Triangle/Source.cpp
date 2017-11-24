#include <vector>
#include <iostream>
class Solution {
public:
    std::vector<std::vector<int> > generate(int numRows) {
        std::vector<std::vector<int> > ans;
        for (int theRow = 0; theRow < numRows; ++theRow) {
            std::vector<int> row(theRow + 1);
            row[0] = 1; row[theRow] = 1;
            for (int theCol = 1; theCol < theRow; ++theCol) {
                row[theCol] = ans[theRow - 1][theCol - 1] + ans[theRow - 1][theCol];
            }
            ans.push_back(row);
        }
        return ans;
    }
};