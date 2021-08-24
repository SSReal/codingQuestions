#include <bits/stdc++.h>
using namespace std;

class scheduleUnit {
public:
    int idx;
    int l;
    int r;
    scheduleUnit() {
        idx = -1;
        l = 0;
        r = 0;
    }
};

struct passenger {
    int a, t;
    passenger() {
        a = 0;
        t = 0;
    }
};

bool passengerCmp(passenger& l, passenger& r) {
    return l.a < r.a || (l.a == r.a && l.t > r.t);
}

vector<scheduleUnit> solve(vector<passenger>& p, int n) {
    //subtask 1:
    //ti's are equal
    
    //sort according to their departure time
    sort(p.begin(), p.end(), passengerCmp);

    //service those in hurry first
    int i = 0;
    int satisfied = 0, total_time = 0;
    while(i<n && total_time < p[i].a) {
        if(p[i].a > p[i].t) {
            continue;
        }
        if(total_time + p[i].a <= p[i].t) {
            total_time += p[i].a;
            satisfied++;
        }
    }

}

int main() {
    int q, n;
    cin >> q;
    while(q--) {
        cin >> n;
        vector<passenger> p(n);
        for(int i = 0; i<n; i++) {
            cin >> p[i].a;
        }
        for(int i = 0; i<n; i++) {
            cin >> p[i].t;
        }
        vector<scheduleUnit> ans = solve(p, n);
        cout << (int) ans.size() << endl;
        for(scheduleUnit s: ans) {
            cout << s.idx << " " << s.l << " " << s.r << endl;
        }
    }
}