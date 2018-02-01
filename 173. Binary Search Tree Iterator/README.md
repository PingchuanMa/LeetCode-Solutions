# 173. Binary Search Tree Iterator

## Description

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling `next()` will return the next smallest number in the BST.

Note: `next()` and `hasNext()` should run in average O(1) time and uses O(*h*) memory, where *h* is the height of the tree.

## Solution

Resemble to mid-order iteration. Keep the top of stack as the next smallest node. Every time the node was read, we pop it out (middle element) and push its right child into stack and go deeper from its left child until the end. However, if the right child does not exist, we just keep going on, since this branch is all read (right element).
