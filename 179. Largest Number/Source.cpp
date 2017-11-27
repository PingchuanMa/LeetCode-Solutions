#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        stringstream ss;
        sort(nums.begin(), nums.end(), comp);
        for (auto ite = nums.begin(); ite != nums.end(); ++ite) {
            ss << *ite;
        }
        return ss.str()[0] == "0" ? "0" : ss.str();
    }
    static bool comp(int a, int b) {
        stringstream ssa, ssb;
        ssa << a << b;
        ssb << b << a;
        return ssa.str() > ssb.str();
    }
};
int main() {
    vector<int> input = {1, 1, 1};
    cout << (new Solution)->largestNumber(input) << endl;
    return 0;
}