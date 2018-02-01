#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int length = board.size();
        if (length == 0) {
            return;
        }
        int width = board[0].size();
        if (width == 0) {
            return;
        }
        const int LIVE = 0x2, MASK = 0x1;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                int cnt = 0;
                for (int k = -1; k < 2; ++k) {
                    for (int l = -1; l < 2; ++l) {
                        if (i + k >= 0 && i + k < length && j + l >= 0 && j + l < length) {
                            if (board[i + k][j + l] & MASK) {
                                ++cnt;
                            }
                        }
                    }
                }
                if (cnt == 3 || (cnt == 2 && board[i][j])) {
                    board[i][j] |= LIVE;
                }
            }
        }
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < width; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};
