#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),
             [](const pair<int, int> &a, const pair<int, int> &b) {
                 return a.first > b.first ||
                        (a.first == b.first && a.second < b.second);
             });
        vector<pair<int, int>> ret;
        for (auto &p : people) {
            ret.insert(ret.begin() + p.second, p);
        }
        return ret;
    }
};
