#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers, find a subarray with the given sum
If no subarray has this sum, return {-1}
*/

/*
Time: O(n)
Space: O(1)
*/

vector<int> subarrayWithGivenSum(vector<int>& nums, int target) {
    int n = nums.size();
    int j = 0, i, sum = nums[0];
    for(i = 1;i<n; i++) {
        while(sum > target && j<=i-1) {
            sum -= nums[j++];
        }
        if(sum == target) return {j, i-1};
        sum += nums[i];
    }
    return {-1};
}