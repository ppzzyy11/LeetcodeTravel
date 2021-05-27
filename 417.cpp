/*
 * 417.cpp
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
    vector<vector<int>> rec;

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        rec.resize(m, vector<int>(n, 0));

        vector<vector<int>> res;
        vector<int> tmp(2, 0);
        for(int i=0; i<m; i++){
            dfs(heights, i, 0, 1);
            dfs(heights, i, n-1, 2);
        }

        for(int j=0; j<n; j++){
            dfs(heights, 0, j, 1);
            dfs(heights, m-1, j, 2);
        }


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rec[i][j]==3){
                    tmp[0]=i;
                    tmp[1]=j;
                    res.push_back(tmp);
                }
            }
        }

        return res;

    }

    //0 not
    //1 Pacific
    //2 Atlantic
    //3 both
    void dfs(vector<vector<int>>& heights, int x, int y, int target){
        if(x<0||y<0||x>=heights.size()||y>=heights[x].size()){
            return ;
        }
        if((rec[x][y]&target)==target){
            return ;
        }
        rec[x][y]|=target;
        if(x-1>=0&&heights[x][y]<=heights[x-1][y]){
            dfs(heights, x-1, y, target);
        }
        if(x+1<heights.size()&&heights[x][y]<=heights[x+1][y]){
            dfs(heights, x+1, y, target);
        }
        if(y-1>=0&&heights[x][y]<=heights[x][y-1]){
            dfs(heights, x, y-1, target);
        }
        if(y+1<heights[0].size()&&heights[x][y]<=heights[x][y+1]){
            dfs(heights, x, y+1, target);
        }

        return ;
    }


};





int main(){
    return 0;
}

