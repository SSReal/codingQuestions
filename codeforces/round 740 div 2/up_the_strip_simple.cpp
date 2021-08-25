//incomplete

#include <bits/stdc++.h>
using namespace std;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector<int> dp(n, 0);
    dp[n-1] = 1;
    int total = 1;
    for(int i = n-2; i>=0; i--) {
        int x = i + 1;
        //subtraction case
        dp[i] += total;
        //floored division case

    }
}