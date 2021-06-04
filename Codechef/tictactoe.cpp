#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int t, x_cnt, o_cnt;
    vector<vector<char>>grid(3, vector<char>(3, '_'));
    cin >> t;
    while(t--) {
        x_cnt = 0;
        o_cnt = 0;

        //taking the input
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                cin >> grid[i][j];
                if(grid[i][j] == 'X') x_cnt++;
                else if(grid[i][j] == 'O') o_cnt++;
            }
        }

        //taking transpose of grid to make column operations easy
        vector<vector<char>> grid_t = grid;
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                grid_t[i][j] = grid[j][i];
            }
        }

        bool x_win, o_win;

        //checking function
        const auto check = [&](char c) {
            bool answer = false;
            //checking rows
            for(auto row: grid) {
                if(count(row.begin(), row.end(), c) == 3) {
                    answer = true;
                }
            }
            //checking columns
            for(auto col: grid_t) {
                if(count(col.begin(), col.end(), c) == 3) {
                    answer = true;
                }
            }
            //checking diagonals
            if(grid[1][1] == c) {
                if(grid[0][0] == c && grid[2][2] == c) {
                    answer = true;
                }
                else if(grid[0][2] == c && grid[2][0] == c) {
                    answer = true;
                }
            }
            return answer;
        };
        
        x_win = check('X');
        o_win = check('O');

        int ans = 2;
        if(!(x_cnt == o_cnt || 
            x_cnt == o_cnt + 1) || 
            (x_win && x_cnt != o_cnt + 1) || 
            (o_win && o_cnt != x_cnt) || 
            (x_win && o_win)) {
                ans = 3;
        }
        else if ((x_cnt == o_cnt || 
            x_cnt == o_cnt + 1) && 
            ((x_win && x_cnt == o_cnt + 1) || 
            (o_win && o_cnt == x_cnt)) || 
            (x_cnt + o_cnt == 9)) {
                ans = 1;
        }
        cout << ans << endl;
    }
}