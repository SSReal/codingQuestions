#include <bits/stdc++.h>
using namespace std;

int kadanesAlgorithm(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    int maxSum = INT_MIN;
    for(int i = 0; i<n; i++) {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        if(sum < 0) {
            sum = 0;
        }
    }
    return maxSum;
}

int main() {
    vector<int> arr = {-1,-2,-5,-3, 8};
    cout << kadanesAlgorithm(arr) << endl;
}