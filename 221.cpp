/*
 * 221.cpp
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

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0||j==0){
                    dp[i][j]=matrix[i][j]-'0';
                    res=max(res, dp[i][j]);
                    continue;
                }
                dp[i][j]=( matrix[i][j]=='1'? (min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1):0);
                res=max(res, dp[i][j]);
            }
        }
        return res*res;
    }
};





int main(){
    return 0;
}

