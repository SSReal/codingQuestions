#include <bits/stdc++.h>
using namespace std;

//finds the union and intersection of two sorted arrays
//assumes that the arrays are sorted in non-decreasing order

vector<int> arrayUnion(vector<int>& arr1, vector<int>& arr2) {
    //no duplicates!
    vector<int> ret;
    int n= arr1.size(), m = arr2.size();
    ret.reserve(n + m);
    int i = 0, j = 0;
    while(i<n && j<m) {
        if(arr1[i] < arr2[j]) {
            ret.push_back(arr1[i]);
            int thisElement = arr1[i];
            while(i<n && arr1[i] == thisElement) i++;
        }
        else if(arr1[i] > arr2[j]) {
            ret.push_back(arr2[j]);
            int thisElement = arr2[j];
            while(j<m && arr2[j] == thisElement) j++;
        }
        else {
            ret.push_back(arr1[i]);
            int thisElement = arr1[i];
            while(i<n && arr1[i] == thisElement) i++;
            while(j<m && arr2[j] == thisElement) j++;
        }
    }
    while(i<n) {
        if(arr1[i] != arr2[m-1]) {
            ret.push_back(arr1[i]);
        }
        int thisElement = arr1[i];
        while(i<n && arr1[i] == thisElement) i++;
    }
    while(j<m) {
        if(arr2[j] != arr1[n-1]) {
            ret.push_back(arr2[j]);
        }
        int thisElement = arr2[j];
        while(j<m && arr2[j] == thisElement) j++;
    }
    return ret;
}

vector<int> arrayIntersection(vector<int>& arr1, vector<int>& arr2) {
    //no duplicates!
    vector<int> ret;
    int n = arr1.size(), m = arr2.size();
    int i = 0, j= 0;
    while(i<n && j<m) {
        if(arr1[i] < arr2[j]) {
            int thisElement = arr1[i];
            while(i<n && arr1[i] == thisElement) i++;
        }
        else if(arr1[i] > arr2[j]) {
            int thisElement = arr2[j];
            while(j<m && arr2[j] == thisElement) j++;
        }
        else {
            ret.push_back(arr1[i]);
            int thisElement = arr1[i];
            while(i<n && arr1[i] == thisElement) i++;
            while(j<m && arr2[j] == thisElement) j++;
        }
    }
    return ret;
}

int main() {
    vector<int> arr1 = {1,4,7,8,9};
    vector<int> arr2 = {1,2,3,5,7,8,10};
    vector<int> uni = arrayUnion(arr1, arr2);
    vector<int> inter = arrayIntersection(arr1, arr2);
    cout << "Input: "<<endl;
    cout << "Array 1: " << endl;
    for(auto i: arr1) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Array 2: " << endl;
    for(auto i: arr2) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Output: " << endl;
    cout << "Union: " << endl;
    for(auto i: uni) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Intersection: " << endl;
    for(auto i: inter) {
        cout << i << " ";
    }
    cout << endl;
}