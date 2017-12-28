# 56. Merge Intervals

## Description

Given a collection of intervals, merge all overlapping intervals.

For example,
Given `[1,3],[2,6],[8,10],[15,18]`,
return `[1,6],[8,10],[15,18]`.

## Solution

Firstly, we sort the whole vector by its first value (start). Then, we record two vars - `start` and `end`, which are initialized with the earliest interval. If the next interval's start is later than `end`, then they are not overlapped and we insert `start` and `end` as a merged interval. If not, but the next interval's end is later than `end`, they are overlapped and we should now extend `end` to the new end. When the loop is over, we should insert the left `start` and `end` to the result.
