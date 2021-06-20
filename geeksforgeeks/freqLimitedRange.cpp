#include <bits/stdc++.h>
using namespace std;

/*
Given an array of n integers containing integers in the range [1,p], replace the array in place
to reflect the frequency of each element from 1 to n, according to their indices (0, n-1)
Expected Complexity:
    Time: O(nlogn)
    Space: O(1)
*/

/*
Made by Sajal Singhal (June 2021)
Time: O(nlogn)
Space: O(1)
*/

void freqLimitedRange(vector<int>& nums, int p) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int x = 1;
    int i = 0;
    while(x<=n) {
        int cnt = 0;
        while(i<n && (nums[i])%(p+1) == x) {
            cnt++;
            i++;
        }
        nums[i] += (p+1)*x;
        x++;
    }
}