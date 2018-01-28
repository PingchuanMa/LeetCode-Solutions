#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        //2abc 3def 4ghi 5jkl 6mno 7 pqrs 8 tuv 9 wxyz
        vector<vector<string>> letters = {
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"},
        };
        vector<string> result;
        if (digits.length() == 0) {
            return result;
        }
        _letterCombinations(result, letters, digits, 0, "");
        return result;
    }
    void _letterCombinations(vector<string> &result, vector<vector<string>> &letters, string &digits, int cur, string s) {
        if (cur == digits.length()) {
            result.push_back(s);
            return;
        }
        for (string a : letters[digits[cur] - '0' - 2]) {
            _letterCombinations(result, letters, digits, cur + 1, s + a);
        }
    }
};
