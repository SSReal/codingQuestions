#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        int x = roundl((double)n/3);
        cout << n - 2*x << " " << x << endl;
    }
}