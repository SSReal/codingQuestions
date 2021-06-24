#include <bits/stdc++.h>
using namespace std;

/*
Given an array representing prices of a stock on
consecutive days, return an array of pairs
(starti, endi) such that you buy the stock at starti
index and sell it at endi, for each of the pairs,
so as to maximise the profit.
You can hold only one stock at a time, but you can
buy and sell the stock any number of times.
*/


/*
Made by Sajal Singhal (June 2021) 

Approach:
find the next local minima(if any), buy here, then find the next local
maxima(if any) and sell there, if both are found, add the pair{i,j} to 
the answer

Time: O(n)
Space: O(1), disregarding the space required for the answer
*/

vector<pair<int, int>> stockBuyAndSell(vector<int>& prices) {
    int n = prices.size();
    vector<pair<int, int>> ret;
    int i = 0;
    while(i<n-1) {
        while(i<n-1 && prices[i] > prices[i+1]) i++;
        if(i == n-1) break;
        //found the local minima  
        //buy here
        int j = i;
        while(i<n-1 && prices[i] < prices[i+1]) i++;
        //found the local maxima
        //sell here
        ret.push_back({j,i});
    }
    return ret;
}