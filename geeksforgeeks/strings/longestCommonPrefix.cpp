#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strings, return the longest
common prefix of all the strings in the array.
If there is none, return an empty string.
*/

/*
Made by Sajal Singhal (June 2021)

Approach:
Check all the strings for a particular index starting from 0.
After the first unmatching index, return the substring before it.
If the first index doesn't match, return ""

Time: O(n*min(|a[i]|))
Space: O(min(|a[i]|)) (for the result string)
*/

string longestCommonPrefix(vector<string>& strings) {
    int n = strings.size();

    //finding the minimum length
    int minLength = INT_MAX;
    for(int i = 0; i<n; i++) {
        minLength = min(minLength, (int) strings[i].size());
    }

    //checking each index from starting
    for(int i = 0; i<minLength; i++) {
        int j = 1;
        while(j<n && strings[j-1][i] == strings[j][i]) j++;
        if(j<n) {
            return strings[0].substr(0, i);
        }
    }

    //base case
    return strings[0].substr(0, minLength);
}

