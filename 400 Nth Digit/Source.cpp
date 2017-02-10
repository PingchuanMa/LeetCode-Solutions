#include <cmath>
#include <iostream>
using namespace std;
class Solution {
public:
	int findNthDigit(int n) {
		long long range = 9;
		int digit = 1;
		long long amount = 9;
		int number = 1;
		while (n > range) {
			++digit;
			amount *= 10;
			number *= 10;
			range += amount * digit;
		}
		n -= (range - amount * digit + 1);
		number += (n / digit);
		n %= digit;
		number /= (int)pow(10, digit - 1 - n);
		number %= 10;
		return number;
	}
};
int main() {
	Solution s;
	cout << s.findNthDigit(1000000000) << endl;
	return 0;
}