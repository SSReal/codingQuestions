#include <bits/stdc++.h>
using namespace std;

/*
Given a sorted array and an integer k
find the index at which k is in the array.
If it isn't in the array, then return the
position at which it must be inserted to
maintain the sorted condition
*/

/*
Made by Sajal Singhal (June 2021)
Time: O(logn)
Space: O(1)
*/

int insertPosition(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = n, mid;
    
    //do the normal binary search operation
    while(l<r) {
        mid = (l+r)/2;
        if(nums[mid] == k) {
            //found it
            return mid;
        }
        else if(nums[mid] < k) {
            //go right
            l = mid + 1;
        }
        else {
            //go left
            r = mid;
        }
    }

    //what if we don't find it?
    //Then the current value of r gives
    //the position to insert the element at
    
    return r;
}