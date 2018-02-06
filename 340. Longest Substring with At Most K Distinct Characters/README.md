# 340. Longest Substring with At Most K Distinct Characters

## Description

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = `“eceba”` and k = 2,

T is "ece" which its length is 3.

## Solution

Using sliding window where it contains at most `k` distinct characters all the time. As a result, each time we found that there are more than `k` ones, we just push our begin pointer forward until one of characters in sliding window turns to 0, and we erase this character. Always keep in mind that **corner conditions** in this problem is super annoying.

## Complexity

- Time: `O(s.length())`
- Space: `O(k)`
