#include <iostream>
using namespace std;
#include <unordered_map>
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t, t2s;
        for (int i = 0; i < s.length(); ++i) {
            if (s2t.find(s[i]) == s2t.end()) {
                s2t[s[i]] = t[i];
            }
            else {
                if (s2t[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        for (int i = 0; i < t.length(); ++i) {
            if (t2s.find(t[i]) == t2s.end()) {
                t2s[t[i]] = s[i];
            }
            else {
                if (t2s[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    return 0;
}