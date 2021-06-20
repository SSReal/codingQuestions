#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return an array of their factorials
modulus 10^9 + 7.
*/

/*
Made by Sajal Singhal (June 2021) 
Time: O(max(nums) + n)
Space: O(max(nums) + n)
*/

#define MOD 1000000007
vector<int> largeFactorial(vector<int>& nums) {
    int n = nums.size();
    int maxi = nums[0];
    for(int i = 0; i<n; i++) {
        maxi = max(nums[i], maxi);
    }
    vector<int> dp(maxi+1, 1);
    for(int i = 2; i<= maxi; i++) {
        dp[i] = (i * dp[i-1]) % MOD;
    }
    vector<int> answers(n);
    for(int i = 0; i<n; i++) {
        answers[i] = dp[nums[i]];
    }
    return answers;
}