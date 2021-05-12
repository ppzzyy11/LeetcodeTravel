/*
 * 931.cpp
 * Copyright (C) 2021-05-12 pzy <pzy@pzy-B250M-Wind>
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int> > dp(m, vector<int>(n, INT_MAX));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0){
                    dp[i][j]=matrix[i][j];
                }else{
                    dp[i][j]=min(dp[i][j], dp[i-1][j]+matrix[i][j]);
                    if(j!=0){
                        dp[i][j]=min(dp[i][j], dp[i-1][j-1]+matrix[i][j]);
                    }
                    if(j!=n-1){
                        dp[i][j]=min(dp[i][j], dp[i-1][j+1]+matrix[i][j]);
                    }
                }
            }
        }

        int res=INT_MAX;
        for(int j=0; j<n; j++){
            res=min(res, dp[m-1][j]);
        }
        return res;
    }
};





int main(){
    return 0;
}

