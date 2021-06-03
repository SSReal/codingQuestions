#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct minMax {
    int min;
    int max;
};

minMax approach1(vector<int>& arr) {
    int comparisons = 0;
    //linear scan
    minMax result = {arr[0], arr[0]};
    int n = arr.size();
    for(int i = 1; i<n; i++) {
        if(arr[i] > result.max) {
            comparisons++;
            result.max = arr[i];
        }
        else if(arr[i] < result.min) {
            comparisons+=2;
            result.min = arr[i];
        }
    }
    cout << "1: " << comparisons << endl;
    return result;
    //does 2(n-1) comparisons in the worst case, and (n-1) in the best case
}

minMax tournament(vector<int>& arr, int st, int en, int& comparisons) {
    if(st > en) return {INT_MIN, INT_MAX};
    if(st == en - 1) {
        //simple case, only one element
        return {arr[st], arr[st]};
    }
    else if(en - st == 2) {
        //base case with two elements
        comparisons += 1;
        return {min(arr[st], arr[st+1]), max(arr[st], arr[st+1])};
    }
    int mid = st + (en-st)/2;
    minMax leftPart = tournament(arr, st, mid, comparisons);
    minMax rightPart = tournament(arr, mid+1, en, comparisons);
    minMax result;
    result.min = min(arr[mid], min(leftPart.min, rightPart.min));
    result.max = max(arr[mid], max(leftPart.max, rightPart.max));
    comparisons += 2;
    return result;
}

minMax approach2(vector<int>& arr) {
    //tournament method
    //recursively halve the array and find min and max
    //then compare the two subproblems' answers
    int comparisons = 0;
    minMax result = tournament(arr, 0, arr.size(), comparisons);
    cout << "2: " << comparisons << endl;
    return result;
    //T(n) = 2*T(n/2) + 2;
    //best case: n is a power of 2
    // makes 3n/2 - 2 comparisons in the best case
    // and more than that for other cases.
}

minMax approach3(vector<int>& arr) {
    //compare in pairs;
    int comparisons = 0;
    int n = arr.size();
    if(n == 1) {
        return {arr[0], arr[0]};
    }
    minMax result;
    if(arr[1] > arr[0]) {
        result = {arr[0], arr[1]};
        comparisons++;
    }
    else {
        result = {arr[1], arr[0]};
    }
    if(n==2) return result;
    //n > 2
    for(int i = 2; i<n; i+=2) {
        if(i==n-1) {
            //only one left
            comparisons++;
            result.max = max(arr[i], result.max);
            result.min = min(arr[i], result.min);
        }
        else {
            if(arr[i] > arr[i+1]) {
                result.max = max(arr[i], result.max);
                result.min = min(arr[i+1], result.min);
                comparisons+=2;
            }
            else {
                result.max = max(arr[i+1], result.max);
                result.min = min(arr[i], result.min);
                comparisons+=2;
            }
        }
    }
    cout << "3: " << comparisons << endl;
    return result;
}

int main() {
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i = 0; i<n; i++) {
	    cin >> arr[i];
	}
	minMax a1 = approach1(arr);
	minMax a2 = approach2(arr);
	minMax a3 = approach3(arr);
	cout << a1.min << " " << a1.max << endl;
    cout << a2.min << " " << a2.max << endl;
    cout << a3.min << " " << a3.max << endl;
	return 0;
}