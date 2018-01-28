#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n > 0) {
            _generateParenthesis(result, n, 0, "");
        }
        return result;
    }
    void _generateParenthesis(vector<string> &result, int l, int r, string s) {
        // there are still `l' left parenthesis
        // there are `r' unmatched left parenthesis
        if (r > 0) {
            _generateParenthesis(result, l, r - 1, s + ")");
        }
        if (l > 0) {
            _generateParenthesis(result, l - 1, r + 1, s + "(");
        } else {
            if (r == 0) {
                result.push_back(s);
            }
        }
    }
};
