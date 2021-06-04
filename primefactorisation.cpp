#include <iostream>
#include <vector>
using namespace std;

int spf[1000001];

void precalc_spf() {
    spf[0] = 0;
    spf[1] = 1;
    for(int i = 2; i<=1000001; i++) {
        spf[i] = INT_MAX;
    }
    for(int i = 2; i<=1000001; i++) {
        if(spf[i] == INT_MAX) {
            spf[i] = i;
            //it is prime
            for(int j = i*i; j<=1e6; j+=i) {
                if(j%i==0) {
                    spf[j] = min(spf[j], i);
                }
            }
        }
    }
}

void prime_factors(int x) {
    int i = x;
    while(spf[i] != i) {
        cout << spf[i] << " ";
        i/=spf[i];
    }
    cout << i << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,x;
    cin >> n;
    precalc_spf();
    while(n--) {
        cin >> x;
        prime_factors(x);
    }
}