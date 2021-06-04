#include <iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    cout << (m * (n/2)) + ((m/2) * (n%2)) << endl;
}