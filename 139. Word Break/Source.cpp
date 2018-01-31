#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        const int len = s.length();
        vector<vector<bool>> breakable(len, vector<bool>(len, false));
        for (int cnt = 1; cnt <= len; ++cnt) {
            for (int bgn = 0; bgn + cnt <= len; ++bgn) {
                if (find(wordDict.begin(), wordDict.end(), s.substr(bgn, cnt)) != wordDict.end()) {
                    breakable[bgn][cnt - 1] = true;
                    continue;
                }
                for (int off = 1; off < cnt; ++off) {
                    if (breakable[bgn][off - 1] && breakable[bgn + off][cnt - off - 1]) {
                        breakable[bgn][cnt - 1] = true;
                        break;
                    }
                }
            }
        }
        return breakable[0][len - 1];
    }
};
