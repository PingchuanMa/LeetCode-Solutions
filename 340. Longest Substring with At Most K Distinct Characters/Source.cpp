#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> cnt;
        int begin = 0, maxLength = 0;
        for (int end = 0; end < s.length(); ++end) {
            if (cnt.find(s[end]) == cnt.end()) {
                cnt[s[end]] = 1;
                if (cnt.size() > k) {
                    while (--cnt[s[begin++]] > 0);
                    cnt.erase(s[begin - 1]);
                }
            } else {
                cnt[s[end]]++;
            }
            if (end - begin + 1 > maxLength) {
                maxLength = end - begin + 1;
            }
        }
        return maxLength;
    }
};
