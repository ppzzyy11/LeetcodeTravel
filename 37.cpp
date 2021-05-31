/*
 * 37.cpp
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
    unordered_set<int> mem;
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board, 0);
    }

    bool backtracking(vector<vector<char>>& board, int idx){
        //cout<<idx<<endl;
        int x=idx/9;
        int y=idx%9;
        if(x<0||x>board.size()||y<0||y>=board[0].size()){
            return true;
        }


        if(board[x][y]=='.'){
            for(char ch='1'; ch<='9'; ch++){
                board[x][y]=ch;
                if(verify(board, x, y)){

                    if(idx==80){
                        //!!!edge
                        return true;
                    }else if(backtracking(board, idx+1)){
                        return true;
                    }
                }

            }
            board[x][y]='.';
        }else {
            if(idx==80){
                return verify(board, x, y);
            }
            return backtracking(board, idx+1);
        }

        return false;

    }

    bool verify(const vector<vector<char>>& board, int x, int y){
        vector<int> cnt(10, 0);
        for(int i=0; i<9; i++){
            if(board[i][y]!='.'){
                cnt[board[i][y]-'0']++;
                if(cnt[board[i][y]-'0']>1){
                    return false;
                }
            }
         }


        for(int i=0; i<10; i++){
            cnt[i]=0;
        }

        for(int j=0; j<9; j++){
            if(board[x][j]!='.') {
                cnt[board[x][j]-'0']++;
                if(cnt[board[x][j]-'0']>1){
                    return false;
                }
            }
        }

        int cntx=x/3;
        int cnty=y/3;
        cntx*=3;
        cnty*=3;

        for(int i=0; i<10; i++){
            cnt[i]=0;
        }

        for(int i=cntx; i<=cntx+2; i++){
            for(int j=cnty; j<=cnty+2; j++){
                if(board[i][j]!='.') {
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
    vector<vector<char>> mar({{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}});
    Solution so;
    so.solveSudoku(mar);
    for(int i=0; i<mar.size(); i++){
        for(int j=0; j<mar[i].size(); j++){
            cout<<mar[i][j]<<'\t';
        }
        cout<<'\n';
    }

    return 0;
}

