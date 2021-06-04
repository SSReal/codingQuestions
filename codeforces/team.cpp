#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a;
    vector<int> can_solve(n, 0);
    for(int i = 0; i<n; i++) {
        for(int j = 0; j<3; j++) {
            cin >> a;
            if(a==1) {
                can_solve[i]++;
            }
        }
    }
    int n_probs = 0;
    for(int i = 0; i<n; i++) {
        if(can_solve[i] >= 2) {
            n_probs++;
        }
    }
    cout << n_probs << endl;
}