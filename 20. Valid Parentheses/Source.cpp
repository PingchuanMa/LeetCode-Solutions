#include <stack>
#include <unordered_map>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> detector;
        std::unordered_map<char, char> brackets;
        brackets.insert(std::unordered_map<char, char>::value_type(')', '('));
        brackets.insert(std::unordered_map<char, char>::value_type(']', '['));
        brackets.insert(std::unordered_map<char, char>::value_type('}', '{'));
        for (std::string::iterator iter = s.begin(); iter != s.end(); ++iter) {
            if ('(' == *iter || '[' == *iter || '{' == *iter) {
                detector.push(*iter);
            }
            else if (detector.empty() || detector.top() != brackets.at(*iter)) {
                return false;
            }
            else {
                detector.pop();
            }
        }
        if (detector.empty() != true) {
            return false;
        }
        return true;
    }
};