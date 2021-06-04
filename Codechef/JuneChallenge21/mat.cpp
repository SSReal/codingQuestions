#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ull unsigned long long

ull solve(int r, int k, vector<ull>& a, vector<ull>& p) {
    
}

int main() {
    int r, k;
    cin >> r >> k;
    vector<ull> a(k);
    vector<ull> p(k);
    for(int i = 0; i<k; i++) {
        cin >> a[i];
    }
    for(int i = 0; i<k; i++) {
        cin >> p[i];
    }
    cout << solve(r, k, a, p);
}