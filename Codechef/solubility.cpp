#include <iostream>

using namespace std;


int main() {
    int t, x, a, b;
    cin >> t;
    for(int i = 0; i<t; i++) {
        cin >> x >> a >> b;
        cout << 10 * (a + (100-x)*b) << endl;
    }
}