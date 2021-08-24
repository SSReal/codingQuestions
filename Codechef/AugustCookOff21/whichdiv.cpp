#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, r;
    cin >> t;
    while(t--) {
        cin >> r;
        if(r < 1600) {
            cout << 3 << endl;
        }
        else if(r < 2000) {
            cout << 2 << endl;
        }
        else if(r >= 2000) {
            cout << 1 << endl;
        }
    }
}