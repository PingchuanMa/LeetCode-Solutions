#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, unsigned int> map;
        vector<vector<string>> result;
        map.clear();
        result.clear();
        for (unsigned int i = 0; i < strs.size(); ++i) {
            string key = "";
            for (unsigned int j = 0; j < 26; ++j) {
                key += char(0);
            }
            for (unsigned int j = 0; j < strs[i].size(); ++j) {
                ++key[strs[i][j] - 'a'];
            }
            if (map.find(key) != map.end()) {
                result[map[key]].push_back(strs[i]);
            }
            else {
                vector<string> newVector;
                newVector.clear();
                newVector.push_back(strs[i]);
                result.push_back(newVector);
                map[key] = result.size() - 1;
            }
        }
        return result;
    }
};
int main()
{
    vector<string> a;
    a.push_back("");
    a.push_back("");
    Solution s;
    s.groupAnagrams(a);
}