/*
 * 130.cpp
 * Copyright (C) 2021-05-26 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 * Description:
 *
 *      To implement:
 *      How:
 */
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include "LeetCode.hpp"

using namespace std;



class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0; i<m; i++){
            dfs(board, i, 0, 'O', '0');
            dfs(board, i, n-1, 'O', '0');
        }
        for(int j=0; j<n; j++){
            dfs(board, 0, j, 'O', '0');
            dfs(board, m-1, j, 'O', '0');
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='0'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }

    }

    void dfs(vector<vector<char>>& b, int x, int y,char f, char t){
        if(x<0||y<0||x>=b.size()||y>=b[x].size()){
            return ;
        }
        if(b[x][y]!=f){
            return;
        }
        b[x][y]=t;
        x++;
        dfs(b, x, y, f, t);
        x--;
        x--;
        dfs(b, x, y, f, t);
        x++;
        y--;
        dfs(b, x, y, f, t);
        y++;
        y++;
        dfs(b, x, y, f, t);

    }
};





int main(){
    return 0;
}

