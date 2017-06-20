#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        subsetsHelper(0, nums, *(new vector<int>), ans);
        return ans;
    }

    void subsetsHelper(const int& pos, const vector<int>& data, vector<int>& path, vector<vector<int> >& ans) {
        for (auto i = pos; i < data.size(); ++i) {
            path.push_back(data[i]);
            ans.push_back(path);
            while (i < data.size() - 1 && data[i] == data[i + 1]) { ++i; }
            subsetsHelper(i + 1, data, path, ans);
            path.pop_back();
        }
    }
};