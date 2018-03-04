# 4. Median of Two Sorted Arrays

## Description

There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

**Example 1:**

```text
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

**Example 2:**

```text
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```

## Solution

We can simply convert this problem to another, *find kth greatest element in two sorted array*. Consider two given sorted array, if `A[k / 2] < B[k / 2]`, clearly we can find that the first k / 2 in A is not possible to be the kth element. After multiple times of filtering, we can strikingly reduce the complexity of this problem. Consequently, we can just replace `k` with what we want, so we can get it.
