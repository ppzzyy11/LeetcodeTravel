/*
 * 348.cpp
 * Copyright (C) 2021-06-02 pzy <pzy@pzy-B250M-Wind>
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



class TicTacToe {
    vector<vector<int>> mat;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        mat.resize(n, vector<int>(n, 0));
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        mat[row][col]=player;

        return win(row, col)?player:0;

    }

    bool win(int row, int col){
        int cnt=0;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][col]==mat[row][col]){
                cnt++;
            }
        }
        if(cnt==mat.size()){
            return true;
        }

        cnt=0;
        for(int j=0; j<mat.size(); j++){
            if(mat[row][j]==mat[row][col]){
                cnt++;
            }
        }
        if(cnt==mat.size()){
            return true;
        }

        cnt=1;
        for(int len=1; row-len>=0||row+len<mat.size()||col-len>=0||col+len<mat.size(); len++){
            if(row-len>=0&&col-len>=0&&mat[row-len][col-len]==mat[row][col]){
                cnt++;
            }
            if(row+len<mat.size()&&col+len<mat.size()&&mat[row+len][col+len]==mat[row][col]){
                cnt++;
            }
        }
        if(cnt==mat.size()){
            return true;
        }

        cnt=1;
        for(int len=1; row-len>=0||row+len<mat.size()||col-len>=0||col+len<mat.size(); len++){
            if(row-len>=0&&col+len<mat.size()&&mat[row-len][col+len]==mat[row][col]){
                cnt++;
            }
            if(row+len<mat.size()&&col-len>=0&&mat[row+len][col-len]==mat[row][col]){
                cnt++;
            }
        }
        if(cnt==mat.size()){
            return true;
        }
        return false;

    }
};





int main(){
    return 0;
}

