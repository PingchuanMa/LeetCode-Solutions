#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();
        if (totalSize & 1) {
            return (findKthNum(nums1, nums2, 0, 0, totalSize / 2 + 1));
        }
        else {
            return (findKthNum(nums1, nums2, 0, 0, totalSize / 2) + findKthNum(nums1, nums2, 0, 0, totalSize / 2 + 1)) / 2.0;
        }
    }
    double findKthNum(vector<int>& nums1, vector<int>& nums2, int cap1, int cap2, int k) {
        if (nums1.size() - cap1 > nums2.size() - cap2) {
            return findKthNum(nums2, nums1, cap2, cap1, k);
        }
        if (nums1.size() == cap1) {
            return nums2[cap2 + k - 1];
        }
        if (1 == k) {
            return min(nums1[cap1], nums2[cap2]);
        }
        int delta1 = min((k / 2), (int)nums1.size() - cap1);
        int delta2 = k - delta1;
        if (nums1[cap1 + delta1 - 1] > nums2[cap2 + delta2 - 1]) {
            return findKthNum(nums1, nums2, cap1, cap2 + delta2, k - delta2);
        }
        else if (nums1[cap1 + delta1 - 1] < nums2[cap2 + delta2 - 1]) {
            return findKthNum(nums1, nums2, cap1 + delta1, cap2, k - delta1);
        }
        else {
            return nums1[cap1 + delta1 - 1];
        }
    }
};
int main() {
    vector<int> c = {1,3};
    vector<int> d = {2};
    Solution s;
    cout << s.findMedianSortedArrays(c, d) << endl;
    return 0;
}