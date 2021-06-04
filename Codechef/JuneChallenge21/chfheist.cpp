#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    unsigned long long D, d, P, Q;
    cin >> t;
    while(t--) {
        cin >> D >> d >> P >> Q;
        unsigned long long money = 0;
        money += P*D;
        unsigned long long n = D/d;
        money += (Q*d*n*(n-1))/(unsigned long long) 2;
        money += n * Q * (D%d);
        cout << money << endl;
    }
}