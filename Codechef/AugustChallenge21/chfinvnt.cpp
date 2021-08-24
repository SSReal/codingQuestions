#include <bits/stdc++.h>
using namespace std;

int solve(int n, int p, int k) {
    if(k >= n || k == 1) return p;
    int m = p%k, x = p/k, y = (n-1)%k;
    int days = m;
    days += m*((n-1)/k);
    if(m-1 > y) days -= (m-y-1);
    days += (x+1);
    return days;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t = 0, n, p, k;
    cin >> t;
    while(t--) {
        cin >> n >> p >> k;
        cout << solve(n, p, k) << endl;
    }
}