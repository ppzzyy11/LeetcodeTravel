/*
 * 304.cpp
 * Copyright (C) 2021-05-05 pzy <pzy@pzy-B250M-Wind>
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
#include "LeetCode.hpp"

using namespace std;

class NumMatrix {
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        dp.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(i==0&&j==0){
                    dp[i][j]=matrix[i][j];
                }else if(i==0){
                    dp[i][j]=dp[i][j-1]+matrix[i][j];
                }else if(j==0){
                    dp[i][j]=dp[i-1][j]+matrix[i][j];
                }else{
                    dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+matrix[i][j];
                }
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=dp[row2][col2];
        if(row1==0&&col1==0){
            ;
        }else if(row1==0){
            res-=dp[row2][col1-1];
        }else if(col1==0){
            res-=dp[row1-1][col2];
        }else{
            res=res-dp[row2][col1-1]-dp[row1-1][col2]+dp[row1-1][col1-1];
        }
        return res;
    }
};





int main(){
    return 0;
}

