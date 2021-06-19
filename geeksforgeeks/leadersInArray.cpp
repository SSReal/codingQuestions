#include <bits/stdc++.h>
using namespace std;

/*
Given an array, find the leaders of that array,
in the order of appearance.
An element of an array is called a leader, if it
is greater than or equal to all the elements 
to the right of it in the array.
The last element is always a leader.
*/

/* 
Time: O(n)
Space :O(n)
*/

vector<int> leaders(vector<int>& nums) {
    int n = nums.size();
    vector<int> leads;
    leads.push_back(nums[n-1]); //last element is always a leader
    for(int i = n-2; i>=0; i--) {
        if(nums[i] > leads.back()) {
            leads.push_back(nums[i]);
        }
    }

    //this is the reverse order of appearance
    reverse(leads.begin(), leads.end());
    return leads;
}