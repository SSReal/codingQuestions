#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

/* calculate the number of n tuples having bitwise & = 0 and are of m bits */

int modularExponent(int a, int x) {
    //calculates a^x % mod, using modular exponentiation
    long long res = 1;
    while(x > 0) {
        if((x & 1) != 0) {
            //this bit is one
            //multiply a
            res = (res * a) % mod;
        }
        x = x>>1;
        a = ((long long) a * a) % mod;
    }
    return (int) res % mod;
}

int main() {
    int t, m, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        //we have to calculate 
        //(2^n - 1)^m
        //first calculate 2^n
        long long a = 1;
        a = modularExponent(2, n);
        a = (a - 1 + mod) % mod;
        //now calculate a^m;
        long long b = modularExponent(a, m);
        printf("%ld\n", b);
    }
    
}