/*
 * 212.cpp
 * Copyright (C) 2021-06-01 pzy <pzy@pzy-B250M-Wind>
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


//enum board
class Solution {
    const char NIL='-';
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> rec;
        for(const string& word: words){
            rec.insert(word);
        }
        vector<string> res;
        string path;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                path="";
                dfs(res, path,board, i, j,  rec );
            }
        }

        return res;
    }

    void dfs(vector<string>& res, string& path, vector<vector<char>>& board, int x, int y,unordered_set<string>& rec){
        //edge
        if(x<0||y<0||x>=board.size()||y>=board[0].size()){
            return ;
        }

        //being visited
        if(board[x][y]==NIL){
            return ;
        }

        char ch=board[x][y];
        board[x][y]=NIL;
        path+=ch;

        if(rec.count(path)!=0){
            res.push_back(path);
            rec.erase(rec.find(path));
        }
        if(path.size()<10){
           dfs(res, path, board, x-1, y, rec);
           dfs(res, path, board, x+1, y, rec);
           dfs(res, path, board, x, y-1, rec);
           dfs(res, path, board, x, y+1, rec);
        }


        path.pop_back();
        board[x][y]=ch;
        return ;
    }
};

class SolutionTLE {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<pair<int, int>>> xys(26);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                xys[board[i][j]-'a'].push_back({i,j});
            }
        }

        vector<string> res;
        for(const string& word: words){
            for(const pair<int, int>& xy: xys[word[0]-'a']){
                int x=xy.first;
                int y=xy.second;

                if(search(board, word, x, y)){
                    res.push_back(word);
                    break;
                }
            }
        }

        return res;
    }

    bool search(vector<vector<char>>& board, const string& word, int x, int y){
        if(x<0||y<0||x>=board.size()||y>=board[0].size()){
            return false;
        }


    }

    bool dfs(vector<vector<char>>& board, int x, int y, const string& word, int idx){
        if(idx==word.size()){
            return true;
        }
        if(x<0||y<0||x>=board.size()||y>=board[0].size()){
            return false;
        }

        //being dfs
        if(board[x][y]=='0'){
            return false;
        }

        //not equal
        if(board[x][y]!=word[idx]){
            return false;
        }

        //mark as being dfs
        char bk_ch=board[x][y];
        board[x][y]='0';

        bool res=false
            ||dfs(board, x-1, y, word, idx+1)
            ||dfs(board, x+1, y, word, idx+1)
            ||dfs(board, x, y-1, word, idx+1)
            ||dfs(board, x, y+1, word, idx+1);

        //reset back to ch
        board[x][y]=bk_ch;

        return res;
    }
};






int main(){
    return 0;
}

