# 463. Island Perimeter

## Description

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

**Example:**

```text
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Answer: 16
```

## Solution

Each single island has four neighbor, as a result, each island piece can contribute at most 4 perimeter. However, there are overlaps. So, each piece we count its right and down (if it exists and there is a neighbor there). The result should be `4 * island - 2 * neighbor`.
