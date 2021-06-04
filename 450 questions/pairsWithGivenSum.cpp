#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getPairsCount(vector<int>& arr, int k) {
        //get the number of pairs in nums which add up to k
        int n = arr.size();
        unordered_map<int, int> hashmap;
        for(int i = 0; i<n; i++) {
            auto it = hashmap.find(arr[i]);
            if(it == hashmap.end()) {
                hashmap.insert({arr[i], 1});
            }
            else {
                it->second++;
            }
        }
        int num_pairs = 0;
        for(int i = 0; i<n; i++) {
            auto it1 = hashmap.find(arr[i]);
            if(it1 == hashmap.end()) {
                //already done
                continue;
            }
            if(k == arr[i] * 2) {
                num_pairs += ((it1->second) * (it1->second - 1))/2;
                hashmap.erase(arr[i]);
                continue;
            }
            auto it2 = hashmap.find(k - arr[i]);
            if(it2 != hashmap.end()) {
                num_pairs += it1->second * it2->second;
                hashmap.erase(it2);
                hashmap.erase(it1);
            }
        }
    }
};