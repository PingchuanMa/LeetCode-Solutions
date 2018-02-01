# 279. Perfect Squares

## Description

Given a positive integer *n*, find the least number of perfect square numbers (for example, `1, 4, 9, 16, ...`) which sum to *n*.

For example, given *n* = `12`, return `3` because `12 = 4 + 4 + 4`; given *n* = `13`, return `2` because `13 = 4 + 9`.

## Solution

Each number is a summary of a perfect number and another. So, DP matrix should be updated by `dp[number] = min(dp[number - i * i] + 1)`.
