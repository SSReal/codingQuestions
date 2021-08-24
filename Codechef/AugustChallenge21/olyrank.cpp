#include <bits/stdc++.h>
using namespace std;

int whoWins(int g1, int s1, int b1, int g2, int s2, int b2) {
    if(g1 + s1 + b1 > g2 + s2 + b2) {
        return 1;
    }
    else if(g2 + s2 + b2 > g1 + s1 + b1) {
        return 2;
    }
    else {
        //equal sum
        if(g1 > g2) {
            return 1;
        }
        else if(g2 > g1) {
            return 2;
        }
        else {
            //g1 == g2
            if(s1 > s2) {
                return 1;
            }
            else if(s2 > s1) {
                return 2;
            }
            else {
                //s1 == s2
                //it means all are equal
                //which is given to not be possible
                return 1; //error condition
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, g1, s1, b1, g2, s2, b2;
    cin >> t;
    while(t--) {
        cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;
        cout << whoWins(g1, s1, b1, g2, s2, b2) << endl;
    }
}