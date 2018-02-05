#include <iostream>
using namespace std;
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        for (int begin = 0; begin < A.length(); ++begin) {
            int i = begin, j = 0, cnt = 1;
            while (j < B.length()) {
                if (i == A.length()) {
                    ++cnt;
                    i = 0;
                }
                if (A[i] != B[j]) {
                    break;
                }
                ++i;
                ++j;
            }
            if (j == B.length()) {
                return cnt;
            }
        }
        return -1;
    }
};
