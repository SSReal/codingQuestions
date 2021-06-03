//find the duplicate number in an array containing n+1 elements, where only one of them repeats

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> nums) {
    int hare, tortoise;
    hare = tortoise = 0;
    hare = nums[nums[hare]];
    tortoise = nums[tortoise];
    //finding the cycle
    while(hare != tortoise) {
        hare = nums[nums[hare]];
        tortoise = nums[tortoise];
    }
    //finding the entry point of the cycle
    tortoise = 0;
    while(hare!=tortoise) {
        hare = nums[hare];
        tortoise = nums[tortoise];
    }
    return hare;
}