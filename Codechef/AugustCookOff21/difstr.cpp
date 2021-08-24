#include <bits/stdc++.h>
using namespace std;

string solve(vector<string>& strs, int n) {
    string ans = strs[0];
    for(int i = 0; i<n; i++) {
        for(int j = 1; j<n; j++) {
            if(strs[j][i] == ans[i]) {
                if(ans[i] == '1') ans[i] = '0';
                else ans[i] = '1';
            }
        }
    }
    return ans;
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
        vector<string> strs(n);
        for(int i= 0; i<n; i++) {
            cin >> strs[i];
        }
        cout << solve(strs, n) << endl;
    }
}