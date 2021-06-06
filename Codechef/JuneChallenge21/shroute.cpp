#include <bits/stdc++.h>
using namespace std;

/*
N cities, each have a station.
M travellers at station 1
Given an array trains, with 
    trains[i] = 1 meaning there is a train from here that goes right
    trains[i] = 2 meaning there is a train from here that goes left
    and trains[i] = 0 meaning there is no train from here
and an array dest, with the destinations (1-indexed) of all the passengers,
return the minimum time taken by each passenger to reach their destination, 
provided, they can be teleported to any station with a train going out from it
and each train takes 1s to go from one station to the next (in order)
*/

int main() {
    int t,n,m;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &m);
        vector<int> trains(n);
        vector<int> dest(m);
        for(int i = 0; i<n; i++) {
            scanf("%d", &(trains[i]));
        }
        for(int i = 0; i<m; i++) {
            scanf("%d", &(dest[i]));
        }
        for(int i = 0; i<m; i++) {
            dest[i]--;
        }
        vector<int> time(n, -1);
        int incomingTrain = -1;
        for(int i = 0; i<n; i++) {
            if(trains[i] == 1) {
                //there is a train here
                //moving right
                incomingTrain = i;
            }
            if(incomingTrain > -1) {
                time[i] = i - incomingTrain;
            }
        }
        //try trains coming from the right
        incomingTrain = -1;
        for(int i = n-1; i>=0; i--) {
            if(trains[i] == 2) {
                //there is a train here
                //moving left
                incomingTrain = i;
            }
            if(incomingTrain > -1) {
                if(time[i] == -1) {
                    time[i] = incomingTrain - i;
                }
                else {
                    time[i] = min(time[i], incomingTrain - i);
                }
            }
        }
        time[0] = 0;
        for(int i = 0; i<m; i++) {
            printf("%d ", time[dest[i]]);
        }
        printf("\n");
    }
}