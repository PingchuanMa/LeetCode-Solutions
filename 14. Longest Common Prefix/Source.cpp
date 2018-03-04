#include <iostream>
#include <vector>
#include <string>
#include <exception>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        bool isEnd = 0;
        int length = strs[0].length();
        string result;
        for (int i = 0; i < strs.size(); ++i) {
            if (length > strs[i].length()) {
                length = strs[i].length();
            }
        }
        for (int i = 0; isEnd != 1 && i < length; ++i) {
            for (int j = 0; j < strs.size() - 1; ++j) {
                if (strs[j][i] != strs[j + 1][i]) {
                    isEnd = 1;
                    break;
                }
            }
            if (isEnd != 1) {
                result += strs[0][i];
            }
        }
        return result;
    }
};
