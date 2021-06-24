#include <bits/stdc++.h>
using namespace std;

/*
Given an array of positive integers,
return the length of longest subsequence
which contains consecutive numbers.
The numbers themselves can be in different order
in the sequence
*/

/*
Made by Sajal Singhal (June 2021)

Approach:
Put all the elements in a hashmap. Then for each element,
search for all the consecutive elements before it, and 
then after it, while removing these from the hashmap, 
and add them to 1 to find the length of the longest 
subsequence of which this element is part.
Return the maximum of all these results.

Time: O(n)
Space: O(n)
*/

int longestConseqSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_map<int, int> hashmap;
    for(int i = 0; i<n; i++) {
        hashmap[arr[i]]++;
    }
    int maxLength = 0;
    for(int i = 0; i<n; i++) {
        if(!hashmap[arr[i]]) continue;
        int before = 0;
        while(arr[i] > before && hashmap[arr[i] - before - 1]) {
            hashmap[arr[i] - before - 1]--;
            if(hashmap[arr[i] - before - 1] == 0) {
                hashmap.erase(arr[i] - before - 1);
            }
            before++;
        }
        int after = 0;
        while(hashmap[arr[i] + after + 1]) {
            hashmap[arr[i] + after + 1]--;
            if(hashmap[arr[i] + after + 1] == 0) {
                hashmap.erase(arr[i] + after + 1);
            }
            after++;
        }
        maxLength = max(maxLength, before + 1 + after);
    }
    return maxLength;
}