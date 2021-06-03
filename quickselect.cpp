#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int lo, int hi, int mid) {
    int i = lo, j = hi;
    int pivot = arr[mid];
    while(i<j) {
        while(j>i && arr[j] > pivot) j--;
        while(i<j && arr[i] < pivot) i++;
        if(i!=j) {
            swap(arr[i] ,arr[j]);
        }
    }
    return j;
}

int quickSelect(vector<int>& arr, int lo, int hi, int k){
    if(lo == hi) return arr[lo];
    while(lo <= hi) {
        int mid = (lo + hi)/2;
        int partition_index = partition(arr, lo, hi, mid);
        if(partition_index == k-1) {
            return arr[partition_index];
        }
        else if(partition_index < k-1) {
            lo = partition_index+1;
        }
        else {
            hi = partition_index-1;
        }
    }
    return arr[lo];
}

int main() {
    int n;
    vector<int> arr;
    cin >> n;
    arr = vector<int>(n);
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << quickSelect(arr, 0, n-1, k) << endl;
}