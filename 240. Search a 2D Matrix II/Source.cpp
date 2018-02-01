class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int length = matrix.size();
        if (length == 0) {
            return false;
        }
        int width = matrix[0].size();
        if (width == 0) {
            return false;
        }
        int i = length - 1, j = 0;
        while (true) {
            if (i < 0 || j >= width) {
                return false;
            }
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                ++j;
            } else {
                --i;
            }
        }
    }
};
