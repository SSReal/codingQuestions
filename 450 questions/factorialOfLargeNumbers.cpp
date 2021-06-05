/*
Find the factorial of a large number, using a vector<int> to represent its digits.
The factorial of the given number may not fit in any of the integer data types
*/

#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

class Solution {
    void multiply(vector<int>& A, int b) {
        ull x, carry = 0;
        int n = A.size();
        for(int i = n-1; i>=0; i--) {
            x = (ull)A[i] * b + carry;
            A[i] = x % 10;
            carry = x/10;
        }
        //if more digits are left to be added
        while(carry > 0) {
            A.insert(A.begin(), carry%10);
            carry/=10;
        }
    }
public:
    vector<int> factorial(int n) {
        vector<int> answer = {1};
        for(int i = 2; i<=n; i++) {
            multiply(answer, i);
        }
        return answer;
    }
};

/* Complexity
Time : O(n)
Space : O(1), if stack space is not counted
the content of multiply function can be expanded
in the body of the for loop only, then it will be O(1),
but it won't be that readable and maintainable
*/

/*
//driver code
int main() {
    Solution s = Solution();
    vector<int> nums = s.factorial(10);
    for(auto i: nums) {
        cout << i ;
    }
    cout << endl;
}
*/