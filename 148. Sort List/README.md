# 148. Sort List

## Description

Sort a linked list in *O(n log n)* time using constant space complexity.

## Solution

Just use a merge sort in link list. To find the middle element, I used the fast-and-slow-pointers. Then find the smallest element in two branch, move the head one step forward, and merge them.
