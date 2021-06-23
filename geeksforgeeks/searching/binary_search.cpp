#include <bits/stdc++.h>
using namespace std;

/* 
Given an array and a number k, find if the number 
is in the array in O(logn) time
*/

/*
Made by Sajal Singhal (June 2021)
Simple Binary Search
Time: O(logn)
Space: O(1) (iterative)
*/

int binarySearch(vector<int>& nums, int k) {
    int n = nums.size();
    int l = 0, r = n, mid;
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
    return -1; //not found
}