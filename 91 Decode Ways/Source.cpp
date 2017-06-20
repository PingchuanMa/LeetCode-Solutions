#include <string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) { return 0; }
        int pre = 0, cur = 1;
        for (size_t i = 0; i < s.length(); ++i) {
            if (s[i] == '0') { cur = 0; }
            if (i < 1 || !(s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6'))) { pre = 0; }
            int tmp = cur;
            cur = pre + cur;
            pre = tmp;
        }
        return cur;
    }
};