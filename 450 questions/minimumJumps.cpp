//minimum jumps to reach the end of the array, when each element of the array gives
//the maximum length of a jump made from that element

#include <bits/stdc++.h>
using namespace std;

int minimumJumps(vector<int>& arr) {
    //greedy approach
    int n = arr.size();
    if(n <= 1) return 0;
    else if(arr[0] == 0) return -1;
    int l = 0, r = 0, jumps = 0;
    while(r < n-1) {
        int far = 0;
        for(int i = l; i<=r; i++) {
            far = max(far, i + arr[i]);
        }
        l = r+1;
        jumps++;
        r = far;
    }
    return jumps;
}