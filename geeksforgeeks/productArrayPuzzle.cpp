#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, return another array, where the ith element
is equal to the product of all the other elements of the array except the ith element.
*/

/*
Made by Sajal Singhal (June 2021) 
Time: O(n)
Space: O(n)
*/

vector<long long> productExceptSelf(vector<long long>& nums) {
    int n = nums.size();
    long long leftProduct = 1, rightProduct = 1;
    vector<long long> answers(n, 1);
    for(int i = 0; i<n; i++) {
        answers[i] *= leftProduct;
        answers[n-i-1] *= rightProduct;
        leftProduct *= nums[i];
        rightProduct *= nums[n-i-1];
    }
    return answers;
}