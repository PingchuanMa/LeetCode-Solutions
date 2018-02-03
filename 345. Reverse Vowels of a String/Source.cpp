#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) {
        unordered_map<char, bool> vowels;
        vowels['a'] = true;
        vowels['e'] = true;
        vowels['i'] = true;
        vowels['o'] = true;
        vowels['u'] = true;
        vowels['A'] = true;
        vowels['E'] = true;
        vowels['I'] = true;
        vowels['O'] = true;
        vowels['U'] = true;
        int left = 0, right = s.length() - 1;
        while (true) {
            while (left < s.length() && vowels.find(s[left]) == vowels.end()) {
                ++left;
            }
            while (0 <= right && vowels.find(s[right]) == vowels.end()) {
                --right;
            }
            if (left < right) {
                swap<char>(s[left++], s[right--]);
            } else {
                break;
            }
        }
        return s;
    }
};
