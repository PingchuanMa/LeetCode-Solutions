# 421. Maximum XOR of Two Numbers in an Array

## Description

Given a **non-empty** array of numbers, $a_0$, $a_1$, $a_2$, … , $a_n-1$, where 0 ≤ $a_i$ < 231.

Find the maximum result of $a_i$ XOR $a_j$, where 0 ≤ *i*, *j* < n.

Could you do this in O(*n*) runtime?

**Example:**

```text
Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.
```

## Solution

Firstly, we iterate all numbers we are given and find if there are two numbers `a` and `b` satisfied that `a ^ b` filled the 31 bit in an integer with `1`. Given `a ^ b = c`, we have `a ^ c = b` and `b ^ c = a`. So after we get all prefixes from numbers, we assume that it will append one bit after the max result, and treat it as `a`. So we search for a prefix `b` from all prefixes which satisfied that `b ^ a = c`, where `c` is also a prefix. If we got it, we set this bit as `1` and break from loop, otherwise we just leave this bit `0`.
