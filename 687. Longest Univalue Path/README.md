# 687. Longest Univalue Path

## Description

Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

**Note:** The length of path between two nodes is represented by the number of edges between them.

**Example 1:**

Input:

```text
              5
             / \
            4   5
           / \   \
          1   1   5
```

Output:

```text
2
```

**Example 2:**

Input:

```text
              1
             / \
            4   5
           / \   \
          4   4   5
```

Output:

```text
2
```

**Note:** The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.

## Solution

The clue is that we can assume that the longest path through node A is one plus the sum of the longest paths starting from its children. So we can always keep a external integer to record the maximum value, and the recursive function returns the longest path starting from it self (instead of through itself).
