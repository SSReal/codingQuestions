#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int n) {
    int iter = 0;
    bool type = false;
    while(true) {
        int i = 0; 
        while(i<n-1 && nums[i] <= nums[i+1]) i++;
        if(i == n-1) return iter;
        iter++;
        type = !type;
        if(type) {
            //odd iteration;
            for(int j = 0; j<n-2; j+=2) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
        else {
            //even iteration;
            for(int j = 1; j<n-1; j+=2) {
                if(nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                }
            }
        }
    }
    return -1;
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