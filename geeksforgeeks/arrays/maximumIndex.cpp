#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers,
find the maximum value of j-i
such that arr[i] <= arr[j]
*/

/*
Made by Sajal Singhal (June 2021)

Approach:
find the smallest from left and largest from right for 
each element of the array. Now narrow down the search 
area using this information.
Iterate from the starting of both these arrays, (i and j)
    * if ith element of left array is greater than jth element of right array,
        it means that our only hope is to go ahead with i, as all elements to 
        the left of ith element are greater than or equal to this.
    * if the ith element of left array is less than or equal to the jth
        element of right array, then this is a potential candidate for 
        our answer, so we record the maximum of j-i. Then we advance j,
        so that we can try to get more difference.

Time: O(n)
Space: O(n)
*/

int maxIndexDiff(vector<int>& nums) {
    int n = nums.size();
    vector<int> small(n), large(n);
    small[0] = nums[0];
    large[n-1] = nums[n-1];
    for(int i = 1; i<n; i++) {
        small[i] = min(small[i-1], nums[i]);
        large[n-i-1] = max(large[n-i], nums[n-i-1]);
    }

    int i = 0, j = 0, maxDiff = 0;
    while(i<n && j<n) {
        if(small[i] <= large[j]) {
            //potential candidate
            maxDiff = max(maxDiff, j -i);
            //explore more options
            j++;
        }
        else {
            //no match in 0...i
            i++;
        }
    }
    return maxDiff;
}