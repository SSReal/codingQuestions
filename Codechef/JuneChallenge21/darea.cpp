#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    set<pair<int, int>> points;
    while(t--) {
        cin >> n;
        points.clear();
        for(int i = 0; i<n; i++) {
            pair<int, int> pt;
            cin >> pt.first >> pt.second;
            points.insert(pt);
        }
        if(points.size() < 3) {
            cout << 0 << endl;
            continue;
        }
        
    }
}