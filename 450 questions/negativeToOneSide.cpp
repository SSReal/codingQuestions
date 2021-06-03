//move all the negative elements of the array to one side
#include <bits/stdc++.h>
using namespace std;

void moveNegativeToOneSide(vector<int>& arr) {
    int n=  arr.size();
    int i = 0;
    while(i<n && arr[i] < 0) {
        i++;
    }
    for(int j = i+1; j<n; j++) {
        if(arr[j] < 0) {
            //swap with first non-zero element
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    moveNegativeToOneSide(arr);
    for(auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
}