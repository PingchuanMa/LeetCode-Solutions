# 406. Queue Reconstruction by Height

## Description

Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers `(h, k)`, where h is the height of the person and `k` is the number of people in front of this person who have a height greater than or equal to `h`. Write an algorithm to reconstruct the queue.

**Note:**
The number of people is less than 1,100.

**Example**

```text
Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
```

## Solution

EXTREMELY FANTASTIC GREEDY PROBLEM. The intuitive idea is that if we count from the tallest ones, they should be just in order with their own second value (because there is not no one taller than them), so we put them in array. Then, the shorter guys will follow them except that their second value will be in order internally but be affected by taller guys. As a conclusion, **the short person will not have ANY affect to taller person**. So we sort them by their attitude descend but also keep their order ascent. Then we use `insert` and `begin` to rearrange them. A rare beautiful solution in `C++`!!!
