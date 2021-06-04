#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(b == 0) return a;
    if(a<b) {
        return gcd(b,a);
    }
    return gcd(b, a-b);
}

int square(int a) {
    return a*a;
}

int main() {
    int t,k;
    cin >> t;
    while(t--) {
        cin >> k;
        int sum = 0;
        int addend = 1;
        for(int i = 0; i<2*k; i++) {
            sum += gcd(k+(addend+=2), k+(addend));
        }
        cout << sum << endl;
    }
}