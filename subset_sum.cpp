#include <iostream>
#include <vector>
using namespace std;

bool rsolve(vector<vector<int>>& ret,int arr[], int n, int target, vector<int> curr, int i) {
    if(target == 0) {
        //push back the current set
        ret.push_back(curr);
        //return true for backtracking
        return true;
    }
    //still need at least one more element
    int c = curr.size();
    curr.push_back(-1); //sentinel
    bool flag = false;
    for(int j = i+1; j<n; j++) {
        curr[c] = arr[j];
        if(rsolve(ret, arr, n, target - arr[j], curr, j) && !flag) flag = true;
    }
    return flag;
}

vector<vector<int>> solve(int arr[], int n, int k) {
    vector<vector<int>> ret;
    vector<int> curr(1);
    for(int i = 0; i<n; i++) {
        //try to solve using arr[i] as the first element
        curr[0] = arr[i];
        rsolve(ret, arr, n, k - arr[i], curr, i);
    }
    return ret;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n,k;
    cin >> n >> k;
    int arr[n];
    for(int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> result = solve(arr, n, k);
    int x = result.size();
    int y;
    for(int i = 0; i<x; i++) {
        y = result[i].size();
        for(int j = 0; j<y; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}