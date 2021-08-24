#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n) {
    unordered_map<int, int> counts;
    if(n <= 2) return 0;
    for(int i= 0; i<n; i++) {
        counts[nums[i]]++;
    }
    int maxCnt = 2;
    for(auto i: counts) {
        maxCnt = max(maxCnt, i.second);
    }
    return n-maxCnt;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i<n; i++) {
            cin >> nums[i];
        }
        cout << solve(nums, n) << endl;
    }
}