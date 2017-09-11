#include <string>
#include <sstream>
#include <iostream>
class Solution {
public:
    std::string countAndSay(int n) {
        std::string pre = "1";
        std::stringstream cur;
        for (auto i = 1; i < n; ++i) {
            for (auto j = 0; j < pre.length(); ++j) {
                auto cnt = 1;
                auto curChar = pre[j];
                while (j < pre.length() - 1 && pre[j] == pre[j+1]) {
                    ++cnt;
                    ++j;
                }
                cur << cnt << curChar;
            }
            pre = cur.str();
            cur.str("");
        }
        return pre;
    }
};

int main() {
    Solution s;
    std::cout << s.countAndSay(5) << std::endl;
    return 0;
}