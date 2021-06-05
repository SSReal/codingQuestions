#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool subarrayExists(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for(int i = 1; i<n; i++) {
            dp[i] = dp[i-1] + nums[i];
        }
        //dp array helps us to query subarray sums in O(1)
        unordered_set<int> sums;
        for(int i = 0; i<n; i++) {
            if(dp[i] == 0 || sums.find(dp[i]) != sums.end()) {
                return true;
            }
            else {
                sums.insert(dp[i]);
            }
        }
        return false;
    }
};