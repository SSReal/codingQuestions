#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, xa, xb, Xa, Xb;
    cin >> t;
    while(t--) {
        cin >> xa >> xb >> Xa >> Xb;
        cout << Xa/xa + Xb/xb << endl;
    }
}