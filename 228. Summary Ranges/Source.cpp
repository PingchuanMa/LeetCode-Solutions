class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        stringstream ss;
        if (nums.size() == 0) {
            return result;
        }
        nums.push_back(nums[nums.size() - 1] - 1);
        int bgn = nums[0], cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cur + 1 == nums[i]) {
                ++cur;
            } else {
                ss << bgn;
                if (cur != bgn) {
                    ss << "->" << cur;
                }
                result.push_back(ss.str());
                stringstream().swap(ss);
                bgn = cur = nums[i];
            }
        }
        return result;
    }
};
