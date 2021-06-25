#include <bits/stdc++.h>
using namespace std;

/*
Given a string of words separated by dots (.),
reverse the string without reversing the individual
words themselves.
*/

/*
Made by Sajal Singhal (June 2021)

Approach:
Reverse the words, then reverse the string.

Time: O(n)
Space: O(1)
*/

string reverseWords(string& sentence) {
    int n = sentence.size();

    //reverse the individual words
    int i = 0, start = 0, end;
    while(i<n) {
        if(sentence[i] == '.') {
            end = i-1;
            reverse(sentence.begin() + start, sentence.begin() + end + 1);
            start = i+1;
        }
        i++;
    }
    end = i-1;
    reverse(sentence.begin() + start, sentence.begin() + end + 1);

    //reverse the whole string
    reverse(sentence.begin(), sentence.end());
    
    return sentence;
}