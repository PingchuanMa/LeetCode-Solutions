#include <iostream>
using namespace std;
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        } else if (n == INT32_MIN) {
            x = 1.0 / (x * x);
            n = -(n + 1);
        } else if (n < 0) {
            x = 1.0 / x;
            n = -n;
        }
        double result = 1, temp = x;
        do {
            if (n & 1) {
                result *= temp;
            }
            temp *= temp;
        } while ((n >>= 1));
        return result;
    }
};
