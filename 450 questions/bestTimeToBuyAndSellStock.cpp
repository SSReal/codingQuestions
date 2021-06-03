#include <bits/stdc++.h>
using namespace std;

/*
Given an array of prices of a stock on various consecutive days, return the maximum profit
one can make by buying one stock on a particular day, and selling it on some day after that.
*/

/* Time : O(n)
    Space: O(1) */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //assume we buy the stock on the first day itself
        int minBuyingPrice = prices[0], profit = 0;
        //min profit is 0
        int n = prices.size();
        for(int i = 1; i<n; i++) {
            //try to sell the stock today
            profit = max(profit, prices[i] - minBuyingPrice);
            //what if we buy the stock today?
            minBuyingPrice = min(minBuyingPrice, prices[i]);
        }
        return profit;
    }
};