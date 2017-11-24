#include <vector>
#include <unordered_map>
#include <cmath>
class Solution {
public:
	bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
		std::unordered_map<int, int> detector;
		detector.clear();
		for (std::vector<int>::size_type i = 0; i < nums.size(); ++i) {
			std::unordered_map<int, int>::iterator ite = detector.find(nums.at(i));
			if (ite != detector.end() && abs((long long)(ite->second - i)) <= k) {
				return true;
			}
			else {
				detector[nums.at(i)] = i;
			}
		}
		return false;
	}
};