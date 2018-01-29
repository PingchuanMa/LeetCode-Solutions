#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int length = matrix.size();
        if (length == 0) {
            return result;
        }
        int width = matrix[0].size();
        if (width == 0) {
            return result;
        }
        result.reserve(length * width);
        int lWall = 0, rWall = 0, uWall = 1, dWall = 0;
        int i = 0, j = -1;
        bool moving = false;
        while (result.size() < length * width) {
            while (j < width - rWall - 1) {
                result.push_back(matrix[i][++j]);
            }
            ++rWall;
            while (i < length - dWall - 1) {
                result.push_back(matrix[++i][j]);
            }
            ++dWall;
            while (j > lWall) {
                result.push_back(matrix[i][--j]);
            }
            ++lWall;
            while (i > uWall) {
                result.push_back(matrix[--i][j]);
            }
            ++uWall;
        }
        return result;
    }
};
