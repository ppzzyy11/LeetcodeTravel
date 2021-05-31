/*
 * 36.cpp
 * Copyright (C) 2021-05-31 pzy <pzy@pzy-B250M-Wind>
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
    bool isValidSudoku(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0; i<m; i++){
            vector<int> cnt(10, 0);
            for(int j=0; j<9; j++){
                if(board[i][j]!='.'){
                    cnt[board[i][j]-'1']++;
                    if(cnt[board[i][j]-'1']>1){
                        return false;
                    }
                }
            }
        }

        for(int j=0; j<n; j++){
            vector<int> cnt(10, 0);
            for(int i=0; i<9; i++){
                if(board[i][j]!='.'){
                    cnt[board[i][j]-'0']++;
                    if(cnt[board[i][j]-'0']>1){
                        return false;
                    }
                }
            }
        }

        return  1&&
            valid(board, 0, 0)&&
            valid(board, 0, 3)&&
            valid(board, 0, 6)&&

            valid(board, 3, 0)&&
            valid(board, 3, 3)&&
            valid(board, 3, 6)&&

            valid(board, 6, 0)&&
            valid(board, 6, 3)&&
            valid(board, 6, 6);
    }

    bool valid(const vector<vector<char>>& board, int x, int y){
        vector<int> cnt(10, 0);
        for(int i=x; i<=x+2; i++){
            for(int j=y; j<=y+2; j++){
                if(board[i][j]!='.'){
                    cnt[board[i][j]-'0']++;
                    if(cnt[board[i][j]-'0']>1){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};





int main(){
    return 0;
}

