#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& caves, int n) {
    vector<pair<int, int>> caveScores(n);
    int min_cave = 0;
    for(int i = 0; i<n; i++) {
        int k = caves[i].size();
        int min_score = 0;
        for(int j = 0; j<k; j++) {
            min_score = max(min_score, caves[i][j] - j + 1);
        }
        caveScores[i] = {min_score, i};
    }
    sort(caveScores.begin(), caveScores.end());
    int total = 0;
    for(int i = 0; i<n; i++) {
        min_cave = max(min_cave, caveScores[i].first - total);
        total += caves[caveScores[i].second].size();
    }
    return min_cave;
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
        vector<vector<int>> caves(n, vector<int>());
        for(int i = 0; i<n; i++) {
            int k;
            cin >> k;
            caves[i] = vector<int>(k);
            for(int j = 0; j<k; j++) {
                cin >> caves[i][j];
            }
        }
        cout << solve(caves, n) << endl;
    }
}