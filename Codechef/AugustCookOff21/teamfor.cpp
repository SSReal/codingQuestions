#include <bits/stdc++.h>
using namespace std;

int solve(int n, string& s, string& t) {
    int both = 0, onlyP = 0, onlyE = 0, noSkill = 0;
    for(int i = 0; i<n; i++) {
        if(s[i] == '1') {
            if(t[i] == '1') {
                both++;
            }
            else {
                onlyP++;
            }
        }
        else {
            if(t[i] == '1') {
                onlyE++;
            }
            else {
                noSkill++;
            }
        }
    }
    int teams = 0;

    //one person for each skill
    teams += min(onlyE, onlyP);
    onlyE -= min(onlyE, onlyP);
    onlyP -= min(onlyE, onlyP);

    //remaining people can go with both skilled person
    int oneSkill = max(onlyE, onlyP);
    teams += min(both, oneSkill);
    both -= min(both, oneSkill);
    oneSkill -= min(both, oneSkill);

    //the unskilled people can only go with both skilled person
    teams += min(both, noSkill);
    both -= min(both, noSkill);
    noSkill -= min(both, noSkill);

    return teams;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int q, n;
    string s, t;
    cin >> q;
    while(q--) {
        cin >> n;
        cin >> s;
        cin >> t;
        cout << solve(n, s, t) << endl;
    }
}