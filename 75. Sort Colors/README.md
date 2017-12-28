# 75. Sort Colors

## Description

Given an array with *n* objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

### Note

You are not suppose to use the library's sort function for this problem.

### Follow up

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?

## Solution

With the help of quick sort, we extend the conception of pivot. In this problem, we use number "0" to represent the pivot and compare each number with it from left to right and from right to left, respectively. When the left pointer meet "0", we swap it with the pivot. In "1" case, we keep it moving forward, and in "2" case we make it stop and wait. Similarly, the right pointer will do the opposite things until it meets "1". Then, they swap with each other and finally the array will be like 000111222.
