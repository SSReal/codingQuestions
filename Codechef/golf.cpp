#include <iostream>

using namespace std;

int main() {
    int t, n, x, k;
    scanf("%d", &t);
    for(int i = 0; i<t; i++) {
        scanf("%d %d %d", &n, &x, &k);
        if(x%k == 0 || (n+1-x)%k == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
}