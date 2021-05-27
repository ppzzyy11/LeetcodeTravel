/*
 * 329.cpp
 * Copyright (C) 2021-05-27 pzy <pzy@pzy-B250M-Wind>
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
    vector<vector<int>> rec;//length of the longest increasing path starting from [i][j]
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        rec.resize(m, vector<int>(n, 0));

        int len=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                len=max(len, dfs(matrix, i, j, INT_MIN));
            }
        }

        return len;
    }


    //dfs with memorization
    int dfs(vector<vector<int>>& matrix, int x, int y, int pre){
        if(x<0||y<0||x>=matrix.size()||y>=matrix[0].size()){
            return 0;
        }

        if(matrix[x][y]<=pre){
            return 0;
        }
        if(rec[x][y]!=0){
            return rec[x][y];
        }
        int dot=matrix[x][y];
        //mark being visited
        matrix[x][y]=-1;

        int len=0;
        len=max(len, dfs(matrix, x+1, y, dot));
        len=max(len, dfs(matrix, x, y+1, dot));
        len=max(len, dfs(matrix, x-1, y, dot));
        len=max(len, dfs(matrix, x, y-1, dot));


        matrix[x][y]=dot;
        return rec[x][y]=len+1;

    }
};





int main(){
    return 0;
}

