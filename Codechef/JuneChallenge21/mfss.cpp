#include <bits/stdc++.h>
using namespace std;

long long solve(vector<long long>& nums) {
    int n = nums.size();

    //preprocess subarray sums
    vector<long long> dp(n);
    dp[0] = nums[0];
    for(int i = 1; i<n; i++) {
        dp[i] = dp[i-1] + nums[i];
    }

    map<vector<long long>, pair<long long, long long>> subarrays;
    for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {
            if(i == 0) {
                vector<long long> subarr = vector<long long>(nums.begin() + i, nums.begin() + j + 1);
                auto it = subarrays.find(subarr);
                if(it == subarrays.end()) {
                    subarrays.insert({subarr, {dp[j], 1}});
                }
                else {
                    it->second.second++;
                }
            }
            else {
                vector<long long> subarr = vector<long long>(nums.begin() + i, nums.begin() + j + 1);
                auto it = subarrays.find(subarr);
                if(it == subarrays.end()) {
                    subarrays.insert({subarr, {dp[j] - dp[i-1], 1}});
                }
                else {
                    it->second.second++;
                }
            }
        }
    }

    //choose one with the most score
    long long score = 0;
    long long maxScore = INT_MIN;
    for(auto it: subarrays) {
        score = (it.second.first) * (it.second.second);
        maxScore = max(maxScore, score);
    }
    return maxScore;
}

int main() {
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<long long> nums(n);
        for(int i = 0; i<n; i++) {
            cin >> nums[i];
        }
        cout << solve(nums) << endl;
    }
}


// AC on subtask 0
// TLE on both others
