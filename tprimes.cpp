#include <iostream>
#include <vector>
using namespace std;

bool isprime[1000000];

void makeSieve() {
    //initial condition
    for(long long i = 0; i<1e6; i++) {
        isprime[i] = true;
    }
    for(long long i = 2; i<=1e6; i++) {
        if(isprime[i-1]) {
            for(long long j = i*i; j<= 1e6; j+=i) {
                if(j%i == 0) {
                    //j is a multiple of i
                    isprime[j-1] = false;
                }
            }
        }
    }
}

bool solve(long long x) {
    return isprime[x-1];
}

int main() {
    int n;
    long long x;
    cin >> n;
    makeSieve();
    while(n--) {
        cin >> x;
        if(solve(x)) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
}