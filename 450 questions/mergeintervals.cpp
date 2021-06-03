#include <bits/stdc++.h>
using namespace std;

bool startPtCmp(const vector<int>& l, const vector<int>& r) {
    return l[0] < r[0];
}

class Solution {
public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), startPtCmp);
        vector<vector<int>>::iterator i = intervals.begin();
        while(i!= intervals.end()) {
            int endPt = (*i)[1];
            auto j = i;
            j++;
            while(j!= intervals.end() && (*j)[0] <= endPt) {
                endPt = max(endPt, (*j)[1]);
            }
            intervals.erase(i+1, j);
            (*i)[1] = endPt;
            i++;
        }
        return intervals;
    }
};