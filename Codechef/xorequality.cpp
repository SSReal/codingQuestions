#include <iostream>
#include <bits/stdc++.h>
#define MOD (int) 1000000007
using namespace std;

vector<int> precomputed(5 + 1e5);

void pre() {
    precomputed[1] = 1;
    for(int i = 2; i<5 + 1e5; i++) {
        precomputed[i] = (precomputed[i-1] * 2) % MOD;
    }
}

int main() {
    //the condition is true only for even x
    //there are 2 ^ (N-1) such x's in 
    // [0, 2^N - 1]

    pre(); // precompute powers of 2

    int t,n;
    cin >> t;

    while(t--) {
        cin >> n;
        cout << precomputed[n] << endl;
    }

}