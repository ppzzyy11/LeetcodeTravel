/*
 * 723.cpp
 * Copyright (C) 2021-04-26 pzy <pzy@pzy-B250M-Wind>
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
#include <utility>

using namespace std;


class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {

        while(1){
            if(!preCursh(board))
                return board;
            crush(board);
            postCrush(board);
        }
        return board;
    }


    //Need to be test
    //return need crushed or not? And mark coordinate which need to be crushed as negative integer.
    bool preCursh(vector<vector<int>>& board){
        bool changed=false;
        for(int i=0; i<board.size(); i++){
            int pre=INT_MIN, cnt=0;
            for(int j=0; j<board[i].size(); j++){
                if(j==0){
                    pre=abs(board[i][j]);
                    cnt=1;
                    continue;
                }

                if(abs(board[i][j])==abs(pre)){
                    cnt++;
                }else{
                    pre=abs(board[i][j]);
                    cnt=1;
                }
                if(cnt==3){
                    //in case all zero
                    if(pre!=0)
                        changed=true;
                    for(int k=0; k<cnt; k++){
                        board[i][j-k]=-abs(board[i][j-k]);
                    }
                }else if(cnt>3){
                    board[i][j]=-abs(board[i][j]);
                }

            }
        }

        for(int j=0; j<board[0].size(); j++){
            int pre=INT_MIN, cnt=0;
            for(int i=0; i<board.size(); i++){
                if(i==0){
                    pre=abs(board[i][j]);
                    cnt=1;
                    continue;
                }

                if(abs(pre)==abs(board[i][j])){
                    cnt++;
                }else{
                    pre=abs(board[i][j]);
                    cnt=1;
                }

                if(cnt==3){
                    if(pre!=0)
                        changed=true;
                    for(int k=0; k<cnt; k++){
                        board[i-k][j]=-abs(board[i-k][j]);
                    }
                }else if(cnt>3){
                    board[i][j]=-abs(board[i][j]);
                }
            }
        }
        return changed;

    }

    //set the crushed grid into 0
    bool crush(vector<vector<int>>& board){
        for(int i=0;i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]<0){
                    board[i][j]=0;
                }
            }
        }
        return true;
    }

    //drop
    bool postCrush(vector<vector<int>>& board){
        for(int j=0; j<board[0].size(); j++){
            int k=board.size()-1;
            for(int i=board.size()-1; i>=0; i--){
                board[k][j]=board[i][j];
                if(board[i][j]!=0)
                    k--;
                if(i!=k+1){
                    board[i][j]=0;
                }
            }
        }
        return true;
    }
};





int main(){
    return 0;
}

