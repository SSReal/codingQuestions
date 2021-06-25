#include <bits/stdc++.h>
using namespace std;

/*
Given a Roman Number in string format,
return the associated number as an int.
The Roman Numeral can consist of I, V, X, L, C, D and M.
*/

/*
Made by Sajal Singhal (June 2021)

Approach:
Iterate from last and add the numbers which are bigger than the 
previous max, and update the max, and subtract the numbers which are
smaller than the previous max.
The values of the various symbols is given by an if else block.

Time: O(n)
Space: O(1)
*/

int value(char c) {
    if(c == 'I') return 1;
    else if(c == 'V') return 5;
    else if(c == 'X') return 10;
    else if(c == 'L') return 50;
    else if(c == 'C') return 100;
    else if(c == 'D') return 500;
    else if(c == 'M') return 1000;
    else {
        //error
        return -1;
    }
}

int romanToInteger(string& roman) {
    int n = roman.size(), num = 0, prev = 0;
    for(int i = n-1; i>=0; i--) {
        int x = value(roman[i]);
        if(x >= prev) {
            num += x;
            prev = x;
        }
        else {
            num -= x;
        }
    }
    return num;
}