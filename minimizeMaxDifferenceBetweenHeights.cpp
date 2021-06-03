#include <bits/stdc++.h>
using namespace std;

int minimizeMaximumDifference(vector<int>& arr) {
    int n = arr.size();
    //sort the array, so that the best candidates are arranged side by side
    sort(arr.begin(), arr.end());
    int ans = arr[n-1] - arr[0];
    int mini, maxi;
    for(int i = 1; i<n; i++) {
        if(arr[i] > 0) {
            maxi = max(arr[n-1] - k, arr[i-1] + k);
            mini = min(arr[i] - k, arr[0] + k);
            ans = min(ans, maxi-mini);
        }
    }
    return ans;
}