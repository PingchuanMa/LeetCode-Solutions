# 374. Guess Number Higher or Lower

## Descriptio

We are playing the Guess Game. The game is as follows:

I pick a number from **1** to ***n***. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API `guess(int num)` which returns 3 possible results (`-1`, `1`, or `0`):

```text
-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!
```

**Example:**

```text
n = 10, I pick 6.

Return 6.
```

## Solution

Binary Search. A good problem to get familiar with binary search. Here, to avoid integer overflow, we use `l + (r - l) / 2` instead of `(l + r) / 2`.
