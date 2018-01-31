#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        if (denominator == 0) {
            return "";
        }
        unordered_map<long, int> hash;
        long num = numerator;
        long den = denominator;
        stringstream result, ss;
        if ((num < 0) ^ (den < 0)) {
            result << '-';
        }
        num = abs(num);
        den = abs(den);
        long quo = num / den, rem = num % den;
        if (rem == 0) {
            result << quo;
            return result.str();
        }
        for (int i = 0; rem > 0; ++i) {
            if (hash.find(rem) != hash.end()) {
                ss << ')';
                string s = ss.str();
                s.insert(s.begin() + hash[rem], '(');
                ss.str(s);
                ss.clear();
                break;
            }
            hash[rem] = i;
            rem *= 10;
            ss << (rem / den);
            rem %= den;
        }
        result << quo << '.' << ss.str();
        return result.str();
    }
};
