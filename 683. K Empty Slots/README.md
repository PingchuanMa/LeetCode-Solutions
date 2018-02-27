# 683. K Empty Slots

## Description

There is a garden with `N` slots. In each slot, there is a flower. The `N` flowers will bloom one by one in N days. In each day, there will be `exactly` one flower blooming and it will be in the status of blooming since then.

Given an array `flowers` consists of number from `1` to `N`. Each number in the array represents the place where the flower will open in that day.

For example, `flowers[i] = x` means that the unique flower that blooms at day `i` will be at position `x`, where `i` and `x` will be in the range from `1` to `N`.

Also given an integer `k`, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is `k` and these flowers are not blooming.

If there isn't such day, output -1.

**Example 1:**

```text
Input:
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become blooming.
```

**Example 2:**

```text
Input:
flowers: [1,2,3]
k: 1
Output: -1
```

**Note:**
1. The given array will be in the range [1, 20000].

## Solution

Firstly, since there will be *exactly* one flower blooming each day, we can reverse the array `flowers` logically, and the reversed array named `days` will represent for the blooming date of each flower. Intuitively, the interval which satisfies the requirements in the description has greater boundaries, i.e. all elements inside it are smaller than the double side of the interval. As a result, we use *sliding window* to solve it. We make the initial default window from `0` to `k`, then if we find that `i (wuch that 0 < i < k)` is smaller than either side, we set left boundary as `i` and set right boundary as `i + k + 1`. Otherwise, if the interval satisfies all requirements, we compare the construction day of this interval with previous answers and find the minimum answer since we may obtain multiple interval satisfying the requirements.

## Complexity

*Time:* O(n * k) *Space:* O(n)
