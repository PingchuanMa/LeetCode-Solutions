#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int length = grid.size();
        if (!length) {
            return 0;
        }
        int width = grid[0].size();
        if (!width) {
            return 0;
        }
        int land = 0, overlap = 0;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if (grid[i][j]) {
                    ++land;
                }
                if (i + 1 < length && grid[i + 1][j]) {
                    ++overlap;
                }
                if (j + 1 < width && grid[i][j + 1]) {
                    ++overlap;
                }
            }
        }
        return 4 * land - 2 * overlap;
    }
};
