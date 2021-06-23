#include <bits/stdc++.h>
using namespace std;

/* 
Given an array nums and an integer d, rotate the array anti-clockwise d times
*/

/*
Time: O(n)
Space: O(1)
*/

void rotateArray(vector<int>& nums, int d) {
    int n = nums.size();
    d %= n; //remove excess rotations;
    int j = d;
    int modulus = nums[0];
    for(int i = 1; i<n; i++) {
        modulus = max(modulus, nums[i]);
    }
    modulus++;
    //this modulus is used for our clever trick

    for(int i = 0; i<n; i++) {
        nums[i] += (nums[j] % modulus) * modulus;
        j = (j+1)%n;
    }

    for(int i = 0; i<n; i++) {
        nums[i] /= modulus;
    }
}