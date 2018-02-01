#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    ++cnt;
                    _numIslands(grid, i, j);
                }
            }
        }
        return cnt;
    }
    void _numIslands(vector<vector<char>>& grid, int i, int j) {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') {
            return;
        }
        grid[i][j] = '2';
        _numIslands(grid, i + 1, j);
        _numIslands(grid, i - 1, j);
        _numIslands(grid, i, j + 1);
        _numIslands(grid, i, j - 1);
    }
};
