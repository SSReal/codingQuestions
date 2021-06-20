#include <bits/stdc++.h>
using namespace std;

/*
Given an array in which each element represents the maximum length of jump
from that element, check whether we can reach the last index from the first index
by performing such jumps.
*/

/*
Made by Sajal Singhal (June 2021)
Time: O(n)
Space: O(1)
*/

bool canReach(vector<int>& nums) {
    int n = nums.size();
    int maxReach = 0;
    for(int i = 0; i<=maxReach; i++) {
        maxReach = max(maxReach, min(i + nums[i], n-1));
    }
    return maxReach == n-1;
}