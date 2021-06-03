#include <bits/stdc++.h>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
    int i = 0;
    bool firstFinished = false;
    for(int j = 0; j<m; j++) {
        //for each element in the second array
        //try to insert it into the first one
        if(!firstFinished) {
            while(i < n  && arr1[i] < arr2[j]) i++;
            if(i == n) {
                //first array finished
                firstFinished = true;
                i = 0;
                while(i<j && arr2[i] < arr2[j]) i++;
                if(i==j) {
                    //no need to change the position
                    continue;
                }
            }
        }
        else {
            while(i<j && arr2[i] < arr2[j]) i++;
            if(i==j) {
                //no need to change the position
                continue;
            }
        }
        int prev;
        if(!firstFinished) {
            prev = arr1[i];
            arr1[i] = arr2[j];
        }
        else {
            prev = arr2[i];
            arr2[i] = arr2[j];
        }
        //replace all subsequent elements until j
        i++;
        int k = i;
        if(!firstFinished) {
            while(k<n) {
                swap(prev, arr1[k]);
                k++;
            }
            k = 0;
        }
        while(k<=j) {
            swap(prev, arr2[k]);
            k++;
        }
    }
}

void merge2(int arr1[], int arr2[], int n, int m) {
    //how to store two numbers in one place?
    //store one of them as remainder and one as quotient
    //of division with a number bigger than both
    //a + n*b => Quotient = b, Remainder = a;

    //finding the maximal element in the whole arrays
    int maxi = max(arr1[n-1], arr2[m-1]) + 1; // + 1 to prevent collision with 0
    //this is our n
    int i = 0, j = 0, k = 0;
    while(i<n && j<m) {
        int a = arr1[i] % maxi, b = arr2[j] % maxi; //get the old elements
        if(k < n) {
            arr1[k] += min(a, b) * maxi;
        }
        else {
            arr2[k-n] += min(a,b) * maxi;
        }
        k++;
        if(a <= b) {
            i++;
        }
        else {
            j++;
        }
    }
    while(i<n && k < n+m) {
        if(k < n) {
            arr1[k] += (arr1[i] % maxi) * maxi;
        }
        else {
            arr2[k-n] += (arr1[i] % maxi) * maxi;
        }
        i++;
        k++;
    }
    while(j<m && k < n+m) {
        if(k<n) {
            arr1[k] += (arr2[j] % maxi) * maxi;
        }
        else {
            arr2[k-n] += (arr2[j] % maxi) * maxi;
        }
        j++;
        k++;
    }
    //wipe the old elements off by performing floor division by maxi
    for(int i = 0; i<n; i++) {
        arr1[i]/=maxi;
    }
    for(int j = 0; j<m; j++) {
        arr2[j]/=maxi;
    }
}