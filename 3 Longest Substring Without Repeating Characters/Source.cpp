#include <string>
#include <iostream>
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> detector;
        int left = 0, right = 0;
        int ans = 0;
        while (right < s.length()) {
            if (detector.find(s[right]) == detector.end()) { detector[s[right]] = right; ++right; }
            else {
                if (right - left > ans) { ans = right - left; }
                left = detector[s[right]] + 1;
                right = left;
                detector.clear();
            }
        }
        if (right - left > ans) { ans = right - left; }
        return ans;
    }
};