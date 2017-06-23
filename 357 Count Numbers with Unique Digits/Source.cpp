class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n > 10) {
            return countNumbersWithUniqueDigits(10);
        }
        if (n <= 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int ans = 9;
        for (int i = 1; i < n; ans *= (10 - i++));
        return ans + countNumbersWithUniqueDigits(n - 1);
    }
};