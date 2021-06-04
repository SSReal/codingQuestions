#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, n;
    cin>>t;
    while (t--) {
        cin>>n;
        vector<int> weights(n);
        int n1=0, n2=0;
        for(int i = 0; i<n; i++) {
            cin>>weights[i];
            if(weights[i] == 1) n1++;
            else n2++;
        }
        if(n1%2==0 && (n1!=0 || n2%2==0)) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
}