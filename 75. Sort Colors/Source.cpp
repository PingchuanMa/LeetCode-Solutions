class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() < 2) return;
        int zero = 0, one = 0, two = nums.size() - 1;
        while (one <= two) {
            for (zero < nums.size() && nums[zero] == 0; ++zero);
            if (one < zero) one = zero;
            for (; one < nums.size() && nums[one] == 1; ++one);
            for (; two >= 0 && nums[two] == 2; --two);
            if (one > two) break;
            if (nums[one] == 0) {
                swap(nums[zero++], nums[one]);
                continue;
            }
            if (nums[two] == 0) {
                swap(nums[zero++], nums[two]);
                continue;
            }
            swap(nums[one++], nums[two--]);
        }
    }
    void swap(int& a, int& b) {
        int c = a;
        a = b;
        b = c;
    }
};
