#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array, rearrange the elements such that
the elements are arranged alternately
i.e first maximum, then minimum, then second maximum, then second minimum, etc.
*/

/*
Time: O(n)
Space: O(1)
*/

void rearrangeArrayAlternately(vector<int>& nums) {
    int n = nums.size();
    //the array is sorted, so the maximum element is at the last
    int modulus = nums[n-1] + 1;
    int i = 0, j = n-1, k = 0;
    while(k<n) {
        nums[k++] += (nums[j--] % modulus) * modulus;
        if(k == n) break;
        nums[k++] += (nums[i++] % modulus) * modulus;
    }
    
    //remove the trickery
    for(int i = 0; i<n; i++) {
        nums[i] /= modulus;
    }
}