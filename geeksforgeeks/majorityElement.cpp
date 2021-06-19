#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the majority element in them.
The majority element is the element having occurence more than n/2 in the array
*/

/*
Moore's Voting Algorithm
Time: O(n)
Space: O(1)
*/

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    int maj_idx = 0;
    int votes = 1;
    for(int i = 1; i<n; i++) {
        if(nums[i] == nums[maj_idx]) votes++;
        else votes--;
        if(votes == 0) {
            //change the candidate
            votes = 1;
            maj_idx = i;
        }
    }

    //check if the candidate is actually in majority
    int cnt = 0;
    for(int i = 0; i<n; i++) {
        if(nums[i] == nums[maj_idx]) cnt++;
    }
    if(cnt > n/2) return nums[maj_idx];
    else return -1;
}