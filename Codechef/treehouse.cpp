#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, x;
    int mod = 7 + (int) 1e9;
    cin >> t;

    while(t--) {
        cin >> n >> x;
        vector<pair<int,int>> tree(n-1);
        for(int i = 0; i<n-1; i++) {
            pair<int,int> curr;
            cin >> curr.first >> curr.second;
            tree.push_back(curr);
        }
        
    }
}