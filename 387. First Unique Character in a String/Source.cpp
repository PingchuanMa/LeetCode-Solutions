#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        for (char &c : s) {
            auto &freq = m[c];
            if (freq) {
                ++freq;
            } else {
                freq = 1;
            }
        }
        for (int i = 0; i < m.size(); ++i) {
            if (m[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};
