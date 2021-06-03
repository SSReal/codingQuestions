#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while(i>0 && nums[i] <= nums[i-1]) i--;
        if(i==0) {
            //last permutation, so now revert to ascending order
            reverse(nums.begin(), nums.end());
            return;
        }
        i--;
        //swap nums[i] with next greater element
        int j = n-1;
        while(j>0 && nums[j] <= nums[i]) j--;
        if(j>i) swap(nums[i], nums[j]);
        //reverse the whole descending subarray
        reverse(nums.begin() + i + 1, nums.end());
    }
};