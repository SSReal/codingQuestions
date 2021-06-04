#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> factors(500001);

void pre() {
    for(int i = 1; i<500001; i++) {
        for(int j = i; j<500001; j+=i) {
            factors[j].push_back(i);
        }
    }
}

int main() {
    pre();
    int t, n, m;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        long long int ans = 0;
        //get the factors of m - m%b less than b
        for(int b = 2; b<=n; b++) {
            if(b > m) {
                ans += b-1;
                continue;
            }
            int x = m - m%b;
            ans += lower_bound(factors[x].begin(), factors[x].end(), b) - factors[x].begin();
        }
        cout << ans << endl;
    }
}


/*
Explanation:

We are given that a < b, so in the term (M mod a) mod b, the mod b is useless
so we have

M mod a = (M mod b) mod a
hence, (M - M mod b) mod a = 0

thus we need the factors of M - M mod b which are less than b
for all possible b

Now, for b > M, M mod b = M, and hence M - M mod b = 0, thus the total number of 
a's for that case will be b - 1( since a < b)

otherwise, the answer for that b will be lower bound of b in the list of divisors of x,
where x = M - M mod b

*/