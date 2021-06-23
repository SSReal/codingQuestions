#include <bits/stdc++.h>
using namespace std;

/*
Given a non negative integer represented as an array of digits,
increment the number by one, and return the number as an array of digits again.
*/

/*
Made by Sajal Singhal (June 2021)
Time: O(n)
Space: O(1)
*/

vector<int> plusOne(vector<int>& num) {
    int n = num.size();
    int carry = 1;
    for(int i = n-1; i>=0; i--) {
        int x = num[i] + carry;
        num[i] = x%10;
        carry = x/10;
    }
    if(carry > 0) num.insert(num.begin(), carry);
    return num;
}
