#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> scores(n);
    for(int i = 0; i<n; i++) {
        cin >> scores[i];
    }
    int extra = 0;
    int i = k;
    int positive = 0;
    int j = 0;
    while(j<k && scores[j] > 0) {
        positive++;
        j++;
    }
    if(scores[k-1] > 0) {
        while(i<n && scores[i] == scores[k-1]) {
            extra++;
            i++;
        }
    }
    cout << positive + extra << endl;
}