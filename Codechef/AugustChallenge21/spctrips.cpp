#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    //all pairs like (1, i, 1) are counted
    //for 2<=i<=n
    int cnt = 0;
    for(int i= 1; i<=n; i++) {
        for(int j = i; j<=n; j+=i) {
            cnt += (n-i)/j;
        }
    }
    return cnt;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << solve(n) << endl;
    }
}