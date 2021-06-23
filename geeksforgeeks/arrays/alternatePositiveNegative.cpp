#include <bits/stdc++.h>
using namespace std;

/*
Given an array containing positive and negative integers,
rearrange the elements so that they are alternating
positive and negative elements, starting with positive.
The remaining elements are just added to the end.
*/

/*
Made by Sajal Singhal (June 2021)
Time: O(n)
Space: O(n)
*/

void alternatePositiveNegative(vector<int>& nums) {
    int n = nums.size();
    vector<int> positives, negatives;
    for(int i = 0; i<n; i++) {
        if(nums[i] >= 0) {
            positives.push_back(nums[i]);
        }
        else {
            negatives.push_back(nums[i]);
        }
    }

    int i = 0, j = 0, po = positives.size(), ne = negatives.size();
    int k = 0;
    while(i<po && j<ne) {
        nums[k++] = positives[i++];
        if(k==n) break;
        nums[k++] = negatives[j++];
    }
    while(i<po) {
        nums[k++] = positives[i++];
    }
    while(j<ne) {
        nums[k++] = negatives[j++];
    }
}