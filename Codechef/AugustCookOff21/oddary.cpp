
//incomplete

#include <bits/stdc++.h>
using namespace std;

void solve(int n) {
    vector<int> arr(n);
    arr[0] = 1;
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    arr[1] = 2;
    if(n == 2) {
        cout << "1 2" << endl;
        return;
    }

    bool mp[1001] = {false};
    int active = 0;
    for(int i = 2; i<n; i++) {
        bool flag = false;
        for(int j = i; j>=0; j--) {
            mp[arr[j]] = !mp[arr[j]];
            if(mp[arr[j]]) active++;
            else active--;
            if(active == 0) {
                //a subarray with all even
                flag = true;
                break;
            }
        }
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        solve(n);
    }
}