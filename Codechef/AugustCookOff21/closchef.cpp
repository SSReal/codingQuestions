#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n) {
    //we only need to check if the array is closed under 
    //multiplication of all pairs
    unordered_set<int> st;
    for(int i = 0; i<n; i++) {
        st.insert(nums[i]);
    }
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            unsigned long long mult = 
                (unsigned long long) nums[i] * (unsigned long long) nums[j];
            if(st.find((int) mult) == st.end()) {
                return 0;
            }
        }
    }
    return 1;
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