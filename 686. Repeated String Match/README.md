# 686. Repeated String Match

## Description

Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.

For example, with A = "abcd" and B = "cdabcdab".

Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").

**Note:**
The length of `A` and `B` will be between 1 and 10000.

## Solution

We can just set up different begin pointer and compare each character one by one, And `A` would be iterate again and again. A wiser implementation is that we could directly double `A` into `A2`. Then, using `A2.find(B.substr(0, A.length()))` to directly find `begin` which we need, and we can iteratively match each character until we fail or we win.
