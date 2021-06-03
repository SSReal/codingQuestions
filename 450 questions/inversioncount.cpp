#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mergeAndCountInversions(vector<int>& nums, vector<int>& temp, int l, int mid, int r) {
        int inversions = 0;
        int k = l, i = l, j = mid;
        while(i<mid && j<=r) {
            if(nums[i] <= nums[j]) {
                //no inversions
                temp[k++] = nums[i++];
            }
            else {
                //inversions
                // this element and all after it will contribute to inversions
                inversions += mid - i;
                temp[k++] = nums[j++];
            }
        }
        while(i<mid) {
            temp[k++] = nums[i++];
        }
        while(j<=r) {
            temp[k++] = nums[j++];
        }

        //copy back to the array
        for(int i = l; i<=r; i++) {
            nums[i] = temp[i];
        }

        return inversions;
    }
    int mergeSortAndCountInversions(vector<int>& nums, vector<int>& temp, int l, int r) {
        int inversions = 0, mid;
        if(r > l) {
            mid = l + (r-l)/2;
            inversions += mergeSortAndCountInversions(nums, temp, l, mid);
            inversions += mergeSortAndCountInversions(nums, temp, mid+1, r);
            inversions += mergeAndCountInversions(nums, temp, l, mid, r);
        }
        return inversions;
    }
    int inversionCount(vector<int>& nums) {
        vector<int> temp = nums;
        return mergeSortAndCountInversions(nums, temp, 0, nums.size() - 1);
    }
};


//Driver Code
int main() {
    Solution sol = Solution();
    vector<int> nums = {1,4,5,3,2,6,7};
    cout << sol.inversionCount(nums) << endl;
}