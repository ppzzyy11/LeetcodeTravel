/*
 * 289.cpp
 * Copyright (C) 2021-04-19 pzy <pzy@pzy-B250M-Wind>
 *
 * Distributed under terms of the MIT license.
 *
 * Description:
 *
 *      To implement:
 *
 *      How:
 *
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
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                int cnt =0
                    +getNeighbor(board, i-1, j-1)
                    +getNeighbor(board, i, j-1)
                    +getNeighbor(board, i+1, j-1)
                    +getNeighbor(board, i-1, j)
                    +getNeighbor(board, i+1, j)
                    +getNeighbor(board, i-1, j+1)
                    +getNeighbor(board, i, j+1)
                    +getNeighbor(board, i+1, j+1);
                if(((board[i][j]&1)&&(cnt==2||cnt==3))||!(board[i][j]&1)&&cnt==3) {
                    board[i][j]|=2;
                }
            }
        }

        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                board[i][j]=board[i][j]>>1;
            }
        }

        return ;

    }

    int getNeighbor(const vector<vector<int>>& mat, int i, int j){
        if(i<0||j<0||i>=mat.size()||j>=mat[i].size()){
            return 0;
        }
        return mat[i][j]&1==1;
    }
    //Solution 1: copy a matrix to record statues
    //Solution 2: because all elements are integer type, so using a bigger bit instead.
};





int main(){
    return 0;
}

