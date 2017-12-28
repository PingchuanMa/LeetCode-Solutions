# 179. Largest Number

## Description

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given `[3, 30, 34, 5, 9]`, the largest formed number is `9534330`.

Note: The result may be very large, so you need to return a string instead of an integer.

## Solution

To see whether it is better to put a number in front of another, we can simply concatenate them in order and compare them (either with the format of "string" or number).
