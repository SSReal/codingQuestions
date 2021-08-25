#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b) {
    //given a games won by Alice and b games won by Borys
    //return the number of possible breaks in the serve
    set<int> ks;
    int ideal_first = (a + b + 1)/2;
    int ideal_second = (a + b)/2, iters = min(a,b);
    //case 1: starting with Alice
    int low = abs(a - ideal_first);
    ks.insert(low);
    low+=2;
    for(int i = 0; i<iters; i++, low+=2) {
        ks.insert(low);
    }
    //case 2: starting with Borys
    if(abs(b - ideal_first) != abs(a - ideal_first)) {
        low = abs(b - ideal_first);
        ks.insert(low);
        low+=2;
        for(int i = 0; i<iters; i++, low+=2) {
            ks.insert(low);
        }
    }
    cout << ks.size() << endl;
    for(auto i: ks) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t, a, b;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        solve(a, b);
    }
}