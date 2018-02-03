# 309. Best Time to Buy and Sell Stock with Cooldown

## Description

Say you have an array for which the *i*th element is the price of a given stock on day *i*.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

- You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
- After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

**Example:**

``` text
prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
```

## Solution

Above all, this is a DP problem obviously. We can create two arrays to record the max profit we could make if our last action is SELL or BUY. If the last action is BUY, we will either do nothing and inherent from last BUY profit, or buy the stock and minus nowadays price from SELL profit two days ago (to avoid cooldown time). Moreover, if the last action is SELL, we will either no nothing and inherent from last SELL profit, or sell the stock and add nowadays price to BUY profit yesterday. 
