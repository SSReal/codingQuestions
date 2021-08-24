#include <bits/stdc++.h>
using namespace std;

vector<long double> solve(vector<pair<int, int>> coordinates, vector<pair<int, int>> queries, int n, int q) {
    
}

int main() {
    int t, n, q;
    cin >> t;
    vector<pair<int, int>> coordinates, queries;
    while(t--) {
        cin >> n >> q;
        for(int i = 0; i<n; i++) {
            int x,y;
            cin >> x >> y;
            coordinates.push_back({x, y});
        }
        for(int i = 0; i<q; i++) {
            int v,t;
            cin >> v >> t;
            queries.push_back({v, t});
        }
        vector<long double> ans = solve(coordinates, queries, n, q);
        for(auto l: ans) {
            cout << l << endl;
        }
    }
}