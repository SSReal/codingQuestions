#include <bits/stdc++.h>
using namespace std;


int solve(int a1, int a2, int a3, int a4) {
    vector<int> a(4);
    a[0] = a1;
    a[1] = a2;
    a[2] = a3;
    a[3] = a4;
    int unique = 0;
    unordered_set<int> u;
    for(int i = 0; i<4; i++) {
        u.insert(a[i]);
    } 
    unique = u.size();
    switch(unique) {
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 2;
    }
    return 0;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, a1, a2, a3, a4;
    cin >> t;
    while(t--) {
        cin >> a1 >> a2 >> a3 >> a4;
        cout << solve(a1, a2, a3, a4) << endl;
    }
}