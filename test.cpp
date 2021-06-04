#include <bits/stdc++.h>
using namespace std;

bool valid(vector<int>& thash, string& s, int i, int j, int nt) {
    //checks if the substring of s from i to j
    //contains all the characters (inc. duplicates) of t
    if(i>j) return false;
    else if(j-i+1 < nt) return false;
    vector<int> shash(58,0);
    for(int k = i; k<=j; k++) {
        shash[s[k] - 'A']++;
    }
    //checking the hash values
    for(int k = 0; k<58; k++) {
        if(shash[k] < thash[k]) {
            return false;
        }
    }
    return true;
}

string minWindow(string s, string t) {
    int n = s.size();
    vector<int> thash(58, 0);
    int nt = t.size();
    if(nt > n) return "";
    else if(nt == n) {
        if(s == t) return s;
        else return "";
    }
    for(int i = 0; i<nt; i++) {
        thash[t[i]-'A']++;
    }
    int i = 0, j = n-1;
    int minSize = n;
    string minString = s;
    bool noChangei = false, noChangej = false;
    while(i<j) {
        if(!thash[s[i]]) {
            i++;
        }
        else if(!thash[s[j]]) {
            j--;
        }
        else {
            //what if we try to shorten it further?
            //try to increase i
            noChangei = false;
            i++;
            if(!valid(thash, s, i, j, nt)) {
                i--;
                noChangei = true;
            }
            j--;
            noChangej = false;
            if(!valid(thash, s, i, j, nt)) {
                j++;
                noChangej = true;
            }
            if(j-i+1 < minSize) {
                minSize = j-i+1;
                minString = s.substr(i, j-i+1);
            }
            if(noChangei && noChangej) {
                break;
            }
        }
    }
    return minString;
}


int main() {
    string s = "ADOBECODEBANC", t= "ABC";
    cout << minWindow(s, t);
}