#include <bits/stdc++.h>
using namespace std;

void rotateClockWiseBy1(vector<int>& arr) {
    int n = arr.size();
    int prev = arr[0];
    arr[0] = arr[n-1];
    for(int i = 1; i<n; i++) {
        swap(prev, arr[i]);
    }
}

void rotateClockWise(vector<int>& arr, int k) {
    k = k%n; // no unnecessary rotations
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
}

int main() {

}