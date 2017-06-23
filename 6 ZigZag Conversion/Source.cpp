#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string ans(s);
        if (numRows == 1) {
            return ans;
        }
        const auto spacing = 2 * numRows - 2;
        auto index = 0;
        for (auto i = 0; i < numRows; ++i) {
            if (i == 0 || i == numRows - 1) {
                for (auto j = i; j < s.length(); j += spacing) {
                    ans[index++] = s[j];
                }
            }
            else {
                bool flag = false;
                for (auto j = i; j < s.length(); j += flag ? (spacing - 2 * i) : (2 * i)) {
                    ans[index++] = s[j];
                    flag = flag ? false : true;
                }
            }
        }
        return ans;
    }
};
int main() {
    string s = "PAYPALISHIRING";
    int numRows = 7;
    Solution solution;
    cout << solution.convert(s, numRows) << endl;
    return 0;
}