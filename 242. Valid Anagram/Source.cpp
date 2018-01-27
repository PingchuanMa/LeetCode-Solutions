#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for (auto chr : s) {
            if (map.find(chr) == map.end()) {
                map[chr] = 1;
            } else {
                map[chr]++;
            }
        }
        for (auto chr : t) {
            if (map.find(chr) == map.end()) {
                return false;
            } else {
                map[chr]--;
            }
        }
        for (auto cnt : map) {
            if (cnt.second != 0) {
                return false;
            }
        }
        return true;
    }
};
