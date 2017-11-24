#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (std::vector<int>::iterator ite = nums.begin(); ite != nums.end(); ++ite) {
            if (set.find(*ite) == set.end()) { set.insert(*ite); }
            else { return true; }
        }
        return false;
    }
};