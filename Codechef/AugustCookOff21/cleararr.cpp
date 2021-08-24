#include <bits/stdc++.h>
using namespace std;

vector<vector<unsigned long long>> dp;
unsigned long long solve(vector<int>& nums, int n, int k ,int x, int st, int en) {
    if(dp[st][en] != 0) {
        return dp[st][en];
    }
    else if(st == en) {
        return dp[st][en] = nums[st];
    }
    else if(st > en) {
        return 0;
    }
    
    if(nums[st] <= nums[en]) {
        dp[st][en] = nums[st] + solve(nums, n, k, x, st+1, en);
    }
    else {
        dp[st][en] = nums[en] + solve(nums, n, k, x, st, en-1);
    }

    //third choice
    //remove both
    unsigned long long ans;
    if(k > 0) {
        ans = x + solve(nums, n, k-1, x, st+1, en-1);
        dp[st][en] = min(ans, dp[st][en]);
    }
    return dp[st][en];
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, n, k, x;
    cin >> t;
    while(t--) {
        cin >> n >> k >> x;
        dp = vector<vector<unsigned long long>>(n, vector<unsigned long long>(n, 0));
        vector<int> nums(n);
        for(int i = 0; i<n; i++) {
            cin >> nums[i];
        }
        cout << solve(nums, n, k, x, 0, n-1) << endl;
    }
}