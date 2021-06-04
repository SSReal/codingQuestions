#include <iostream>

using namespace std;

int main() {
    int t,w,h,n;
    cin>>t;
    while(t--) {
        cin>>w>>h>>n;
        int i = 1;
        while(w%2==0 || h%2==0 && i < n) {
            i+=i;
            if(w%2==0) {
                w/=2;
            }
            else if(h%2==0) {
                h/=2;
            }
        }
        if(i<n) cout<< "NO" <<endl;
        else cout<<"YES"<<endl;
    }
}
