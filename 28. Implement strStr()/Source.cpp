#include <iostream>
#include <vector>
using namespace std;
// KMS algorithm
class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> next = this->make_next(needle);
        int idx = -1;  // index of haystack
        int len = -1;  // index of needle
        while (idx < (int)haystack.length()) {
            if (len == -1 || haystack[idx] == needle[len]) {
                if (len == needle.length() - 1) {
                    return idx - len;
                } else {
                    ++len;
                    ++idx;
                }
            } else {
                len = next[len];
            }
        }
        return -1;
    }
    vector<int> make_next(string str) {
        vector<int> next(str.length() + 1, -1);
        int len = -1;
        int idx = 0;
        while (idx < str.length()) {
            if (len == -1 || str[idx] == str[len]) {
                next[++idx] = ++len;
            } else {
                len = next[len];
            }
        }
        return next;
    }
};
int main() {
    string str1 = "laskdfja;slkdhfakjhdf";
    string str2 = "dfj";
    cout << (new Solution)->strStr(str1, str2) << endl;
    return 0;
}
