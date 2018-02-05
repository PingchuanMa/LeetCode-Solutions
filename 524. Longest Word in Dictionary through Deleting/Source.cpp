#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), [](const string &a, const string &b) {
            return a.length() > b.length() ||
                   (a.length() == b.length() && a < b);
        });
        for (string tmp : d) {
            int j = 0;
            for (int i = 0; i < s.length() && j < tmp.length(); ++i) {
                if (s[i] == tmp[j]) {
                    ++j;
                }
            }
            if (j == tmp.length()) {
                return tmp;
            }
        }
        return string();
    }
};
