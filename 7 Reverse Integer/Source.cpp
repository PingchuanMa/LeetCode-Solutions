#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        if (x == 0) { return 0; }
        bool isPositive = true;
        if (x < 0) {
            isPositive = false;
            x = -x;
        }
        int ans = 0;
        bool begin = false;
        while (x > 0) {
            int tail = x % 10;
            if (tail > 0 || begin) {
                ans *= 10;
                ans += tail;
                begin = true;
            }
            x /= 10;
            if (ans >= 214748364 || x % 10 > 7) {
                return 0;
            }
        }
        if (isPositive) { return ans; }
        else { return -ans; }
    }
};
int main() {
    Solution s;
    cout << s.reverse(90000) << endl;
}