/*
 * 51.cpp
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



class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<pair<int, int>> path;//Queens' coordinations
        backtracking(res, path, 0, n);
        return res;
    }

    void backtracking(vector<vector<string>>& res, vector<pair<int, int>>& path, int i, const int& n){
        if(i==n){
            res.push_back(generateAns(path, n));
            return ;
        }

        for(int j=0; j<n; j++){
            path.push_back({i,j});
            if(valid(path)){
                backtracking(res, path, i+1, n);
            }
            path.pop_back();
        }
    }

    bool valid(const vector<pair<int, int>>& path){
        for(int i=0; i<path.size(); i++){
            for(int j=0; j<path.size(); j++){
                if(abs(path[i].first-path[j].first)==abs(path[i].second-path[j].second)){
                    return false;
                }
                if(path[i].second==path[j].second){
                    return false;
                }
            }
        }

        return true;
    }

    vector<string> generateAns(const vector<pair<int, int>>& path, const int & n){
        vector<string> res(n, "");
        for(const pair<int, int> p:path){
            res[p.first]=generateStr(p.second, n);
        }
        return res;
    }

    string generateStr(int i, const int & n){
        string str(n, '.');
        str[i]='Q';
        return str;
    }
};





int main(){
    return 0;
}

