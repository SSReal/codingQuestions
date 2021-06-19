#include <bits/stdc++.h>
using namespace std;

/*
Given an array, find its first equilibrium point.
An equilibrium point is such that the sum of 
the elements to the left of it, is equal to 
the sum of elements to the right of it.
If no such element exists in the array, return -1;
*/

/*
Time: O(n)
Space : O(1)
*/

int equilibriumPoint(vector<int>& nums) {
    int n = nums.size();
    int leftSum = 0, sum = 0;

    //find the sum of the entire array
    for(int i = 0; i<n; i++) {
        sum += nums[i];
    }

    for(int i = 0; i<n; i++) {
        //here leftSum is the sum of elements to the left uptill now
        sum -= nums[i];
        //and sum is now the sum of elements to the right uptill now
        if(leftSum == sum) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1; //no index found
}