#include <iostream>
#include <string>
using namespace std;


int main() {
    int t, n;
    string word;
    cin >> t;
    while(t--) {
        cin >> word;
        n = word.size();
        if(n > 10) {
            string newstring = word[0] + to_string(n-2) + word[n-1];
            cout << newstring << endl;
        }
        else {
            cout << word << endl;
        }
    }
}   